/**
 * author:	Thomas lamprecht
 * date:	27.11.2018
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>

#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include "channel_info.h"

#define BUF_SIZE 255
#define MAX_CMD 16

static int verbose;
#define VPRINT(...) do { if (verbose > 0) { printf(__VA_ARGS__); }} while(0)
#define VVPRINT(...) do { if (verbose > 1) { printf(__VA_ARGS__); }} while(0)

static channel_info_t *db[NUMBER_OF_ENTRIES];

static FILE *db_file = NULL;

static char *progname = NULL;

void usage() {
	fprintf(stderr, "Usage: %s [-v] [-f DBFILE] PORT\n", progname);

	exit(1);
}

void init_empty_db(void) {
    for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
        if (db[i] != NULL) {
            free(db[i]);
        }
        db[i] = NULL;
    }
}


int get_empty_index(void) {
    for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
        if (db[i] == NULL) {
            return i;
        }
    }
    return -1;
}

// only for trivial params, which should not contain any problematic sequences
int get_id_from_simple_param(char *line) {
    char *p;
    if ((p = strstr(line, "id=")) != NULL) {
        int id = strtol(p+3, NULL, 10);
        if (id >= 0 && id < 16) {
            return id;
        }
    }
    return -1;
}

// FIXME: differ between reading the DB file and :w
bool db_parse_line(char *line, channel_info_t *channel, bool fail) {
    char *k, *v;
    char *sp1;
    char working_buf[BUF_SIZE];

    printf("saving line: %s\n", line);
    memcpy(working_buf, line, BUF_SIZE);

    k = strtok_r(working_buf, "=", &sp1);
    if (k == NULL) return false;

    while (k != NULL) {

        VVPRINT("db_parse: process k: '%s' \n", k);
        v = sp1; // contains _all_ of remainining string

        if (strcmp("id", k) == 0) {
            int id = strtol(v, NULL, 10);
            if (fail && (id < 0 || id > 15)) {
                ERR("id '%d' out of range!\n", id);
                return false;
            }
            channel->id = id;
        } else if (strcmp("freq", k) == 0) {
            int freq = strtol(v, NULL, 10);
            if (!channel_set_frequency(channel, freq, fail)) {
                return false;
            }
        } else if (strcmp("picode", k) == 0) {
            int picode = strtol(v, NULL, 10);
            if (!channel_set_pi_code(channel, picode, fail)) {
                return false;
            }
        } else if (strcmp("qdial", k) == 0) {
            int qdial = strtol(v, NULL, 10);
            if (!channel_set_quick_dial(channel, qdial, fail)) {
//TODO fetch channel list on init - values are not fetched correctly smh
                return false;
            }
        } else if (strcmp("name", k) == 0) {
            channel_set_name(channel, v);
            sp1 += 8;
            if (*sp1 == '\0') {
                return true; // EOL
            } else if (*sp1 != ',') {
                // to long or padding missing!
                ERR("name property is not 8 character wide\n");
            }
            sp1++;
            goto manual_advance;
        } else if (strcmp("note", k) == 0) {
            // we specified that the note field MUST come last, so just read it
            // in and return then...
            return channel_set_note(channel, v);
        }

        v = strchr(sp1, ',');
        if (v == NULL) return true; // finished or invalid
        sp1 = v + 1;
manual_advance:
        k = strtok_r(NULL, "=", &sp1);
    }

    return true;
}

bool read_db(char *filename) {
	char buffer[BUF_SIZE];
	//char *endptr;

	VPRINT("Loading channels...\n");

    // int fd = open(filename, O_CREAT | O_NOATIME | O_NOFOLLOW, S_IRWXU | S_IRGRP)
	//FILE *db_file = fdopen(fd, "r+");
	db_file = fopen(filename, "r");
	if (db_file == NULL) {
		ERR("Could not open database '%s' for reading, try (re)creating it...", filename);
        db_file = fopen(filename, "w");
        if (db_file == NULL) {
            ERR("error\nCould not (re)create DB file '%s'\n", filename);
            return false;
        }
        ERR("ok\n");
        return true;
	}

    init_empty_db();

    channel_info_t *current_channel = channel_alloc();
    int line_no = 0;
	while (fgets(buffer, BUF_SIZE, db_file) != NULL) {
        line_no++;
        if (buffer[0] == '#') continue;

		size_t line_length = strlen(buffer);
		if (buffer[line_length - 1] == '\n') {
            buffer[line_length - 1] = 0;
        }

        if (current_channel == NULL) {
            current_channel = channel_alloc();
        }

        if (db_parse_line(buffer, current_channel, false)) {
            int idx = current_channel->id;

            if (db[idx] != NULL || idx == 0xFF) {
                if (db[idx] != NULL) {
                    ERR("line %d: double use of id %d, trying to find a new id...\n", line_no, idx);
                }
                idx = get_empty_index();
                if (idx == -1) {
                    ERR("line %d: DB full, ignore remaining entries..\n", line_no);
                    return true;
                }
            }

            VPRINT("line %d: add channel with id '%d' and name '%-8s'\n", line_no, idx, current_channel->name);
            db[idx] = current_channel;
            current_channel = NULL;
        } else {
            channel_reset(current_channel);
        }
	}

    if (current_channel != NULL) {
        free(current_channel);
    }

	return true;
}

void write_db(void) {
	if (db_file == NULL) {
        ERR("No DB file open/set, cannot write database\n");
        return;
	}

    VPRINT("Saving highscore...\n");

    db_file = freopen(NULL, "w+", db_file); // truncate file

    for (uint8_t id = 0; id < NUMBER_OF_ENTRIES; id++) {
        if (db[id] == NULL) {
            continue;
        }
        fprintf(
            db_file,
            "id=%" PRIu8 ",freq=%" PRIu16 ",name=%8s,qdial=%" PRIu8 ",picode=%" PRIu16 ",note=%s\n",
            id,
            db[id]->frequency,
            db[id]->name,
            db[id]->quickDial,
            db[id]->pi_code,
            db[id]->note
        );
    }

    fflush(db_file);
}

void release_resources() {
	if (db_file != NULL) {
		fclose(db_file);
        db_file = NULL;
	}
}

bool prepare_command(char *buf, char **param_start) {
    uint8_t len = strlen(buf);

    if (buf[len - 1] != '\n') {
        return false;
    }
    buf[len - 1] = '\0';

    char *param_del = strchr(buf, '\r');
    if (param_del != NULL) {
        *param_del = '\0';
        *param_start = (char *) (param_del + 1);
    } else {
        // normal we need \r and \n, but for things like "ping" allow no \r too
        // missing, non-optional, params should get cought later one.
        *param_start = &buf[len - 1];
    }

    return true;
}

// unsafe, string must be nul-termindated
void verbose_print_received(char *p) {
    if (!verbose) return;

    fputs("received: '", stdout);
    for (; *p != '\0'; p++) {
        if (*p == '\r') {
            fputs("\\r", stdout);
        } else if (*p == '\n') {
            fputs("\\n", stdout);
        } else {
            putc(*p, stdout);
        }
    }
    puts("'");
}

void release_resources_signal(int signal) {
	// atexit handler will be called
	exit(EXIT_SUCCESS);
}

// only valid inside the main's control loop!
#define RESPOND(...) \
    sprintf(buffer, __VA_ARGS__); \
    sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

int main(int argc, char **argv) {
	int sock, n;
	char *db_fn = "channel.db";
	socklen_t len;
	const int y = 1;
	struct sockaddr_in client_addr, server_addr;
	char *buffer = NULL;
	int port = 0;

    progname = argv[0];

	atexit(release_resources);
	signal(SIGINT,  release_resources_signal);
	signal(SIGQUIT, release_resources_signal);
	signal(SIGTERM, release_resources_signal);

	if (argc > 4) {
		usage(argv[0]);
    }
    int opt;
    while ((opt = getopt(argc, argv, "vf:")) != EOF) {
        switch(opt) {
            case 'v':
                verbose++;
                break;
            case 'f':
                db_fn = optarg;
                break;
            default:
                usage(argv[0]);
                break;
        }
    }
    if (optind < argc) {
        port = strtol(argv[optind], NULL, 10);
        if ((port < 1024) || (port > 65535)) {
            fprintf(stderr, "%s: Invalid port (must be: 1024 <= PORT <= 65535)\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        usage(argv[0]);
    }

	if (!read_db(db_fn)) {
		fprintf(stderr, "ERROR: Could not load channel database\n");

		exit(EXIT_FAILURE);
	}

    // in linux malloc never fails, it's all virtual and on-demand paging, we'd
    // just get into issues with huge amounts - where the overhead becomes to
    // large, or if the system is really out of memory - in which case malloc
    // doesn't falls either but once we write to the reserved memory the OOM
    // Killer triggers, and may just kill us, see
    // https://duckduckgo.com/?q=linux+malloc+never+fails
	buffer = malloc(BUF_SIZE * sizeof(char));

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		fprintf(stderr, "ERROR: Could not open socket ... (%s)\n", strerror(errno));

		exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(port);
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));
	n = bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(n < 0) {
		fprintf(stderr, "ERROR: Could not bind to port ... (%s)\n", strerror(errno));

		exit(EXIT_SUCCESS);
	}

	printf("Waiting for messages from client on port '%d'...\n", port);

	char *ptr;
	char *cmd, *param_start;

	while(true) {
		memset(buffer, 0, BUF_SIZE);

		len = sizeof(client_addr);

        VPRINT("\n");

		n = recvfrom(sock, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &len);
		if (n < 0) {
			fprintf(stderr, "ERROR: Cannot receive data\n");
			continue;
		}

        buffer[BUF_SIZE - 1] = '\0';

        verbose_print_received(buffer);

        ptr = buffer;
        cmd = buffer;
        if (!prepare_command(buffer, &param_start)) {
			printf("Received invalid command: %s\n", ptr);
            continue;
        }

		if (strncmp(cmd, "add\0", 4) == 0) {
			int id = get_empty_index();
            if (id == -1) {
                VPRINT("Err, no free index found\n");
                RESPOND("err\rcmd=add,msg=Channel DB Full\n");
                continue;
            }
            VPRINT("OK, found free index: %i\n", id);

            if (*param_start == '\0') {
                VPRINT("Err, refuse to add channel without any info\n");
                RESPOND("err\rmsg=No channel info,cmd=add\n");
                continue;
            }

            db[id] = channel_alloc();
            if (!db_parse_line(param_start, db[id], true)) {
                RESPOND("err\rmsg=invalid parameters,cmd=add\n");
                free(db[id]);
                db[id] = NULL;
                continue;
            }
            // TODO: mark dirty, so that it gets flushed to disk?
            write_db();

            RESPOND("ok\rid=%i\n", id);
		} else if(strncmp(ptr, "update\0", 7) == 0) {

            if (*param_start == '\0') {
                VPRINT("Err, refuse to update channel without any info\n");
                RESPOND("err\rcmd=update,msg=No channel info\n");
                continue;
            }

            channel_info_t *tmp_channel = channel_alloc();

            if (!db_parse_line(param_start, tmp_channel, true)) {
                RESPOND("err\rcmd=update,msg=invalid parameters\n");
                goto err_update_cleanup;
            }

			int id = tmp_channel->id;
            if (id < 0 || db[id] == NULL) {
                RESPOND("err\rmsg=invalid ID,cmd=update\n");
                goto err_update_cleanup;
            }

            memcpy(tmp_channel, db[id], sizeof(channel_info_t));

            VPRINT("OK, update channel %i info\n", id);
            // shouldn't really fail, we just checked!
            if (!db_parse_line(param_start, db[id], true)) {
                RESPOND("err\rcmd=update,msg=invalid parameters\n");
                // roll back!
                memcpy(db[id], tmp_channel, sizeof(channel_info_t));
                goto err_update_cleanup;
            }
            write_db();

            RESPOND("ok\rid=%i\n", id);
err_update_cleanup:
            if (tmp_channel != NULL) {
                free(tmp_channel);
            }
            tmp_channel = NULL;

            continue;
		} else if(strncmp(ptr, "get\0", 7) == 0) {

            if (*param_start == '\0') {
                VPRINT("Err, cannot get channel info without any id\n");
                RESPOND("err\rmsg=no params,cmd=get\n");
                continue;
            }
			int id = get_id_from_simple_param(param_start);
            if (id < 0 || db[id] == NULL) {
                VPRINT("Err, no or invalid ID '%d'!\n", id);
                RESPOND("err\rcmd=get,msg=invalid ID\n");
                continue;
            }

            VPRINT("OK, retrieving channel %i info\n", id);
            // shouldn't really fail, we just checked!
            RESPOND("ok\rid=%" PRIu8 ",freq=%" PRIu16 ",name=%-8s,qdial=%" PRIu8 ",picode=%" PRIu16 ",note=%s\n",
                id,
                db[id]->frequency,
                db[id]->name,
                db[id]->quickDial,
                db[id]->pi_code,
                db[id]->note
            );
            continue;
		} else if(strncmp(ptr, "delete\0", 7) == 0) {

            if (*param_start == '\0') {
                VPRINT("Err, cannot delete channel without any id\n");
                RESPOND("err\rmsg=no params,cmd=delete\n");
                continue;
            }
			int id = get_id_from_simple_param(param_start);
            if (id < 0 || db[id] == NULL) {
                VPRINT("Err, no or invalid ID '%d'!\n", id);
                RESPOND("err\rmsg=cmd=delete,invalid ID\n");
                continue;
            }

            free (db[id]);
            db[id] = NULL;
            write_db();

            VPRINT("OK, deleting channel '%i'\n", id);
            RESPOND("ok\rid=%" PRIu8 "\n", id);
            continue;
		} else if(strncmp(ptr, "purgeall\0", 7) == 0) {

            if (*param_start != '\0') {
                VPRINT("Err, purgeall expects no params!\n");
                RESPOND("err\rmsg=to many params,cmd=purgeall\n");
                continue;
            }

            init_empty_db();
            write_db();

            VPRINT("OK, purging all channels\n");
            RESPOND("ok\r\n");
            continue;
		} else if(strncmp(ptr, "list\0", 5) == 0) {
            sprintf(buffer, "ok\r");
            char *tmp = buffer + 3;
            for (uint8_t id = 0; id < NUMBER_OF_ENTRIES; id ++) {
                if (db[id] == NULL) continue;
                int printed = sprintf(tmp, "%d,", id);
                tmp += printed;
            }
            tmp--;
            *tmp++ = '\n';
            *tmp = '\0';
            sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
		} else if(strncmp(ptr, "ping", 4) == 0) {
            VPRINT("pong\n");
			RESPOND("pong");
		} else if(strncmp(ptr, "pong", 4) == 0) {
            VPRINT("ping\n");
			RESPOND("ping");
		} else {
			printf("Received unknown command: %s\n", ptr);
			RESPOND("err");
		}
	}

	exit(EXIT_SUCCESS);
}
