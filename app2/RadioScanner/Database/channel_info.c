/**
 * author:	Thomas Lamprecht
 * date:	27.11.2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "channel_info.h"


channel_info_t *channel_alloc(void) {
    channel_info_t *channel;

    channel = malloc(sizeof(channel_info_t));

    channel_reset(channel);

	return channel;
}

void channel_reset(channel_info_t *channel) {
    if (channel == NULL) return;

	channel->id = 0xFF;
	channel->frequency = 0;
	channel->pi_code = 0;
	channel->quickDial = 0;
	channel->name[0] = 0;
	channel->note[0] = 0;
}

bool channel_set_kv(channel_info_t *channel, char *k, char *v) {
    if (strcmp("id", k) == 0) {
        int id = strtol(v, NULL, 10);
        if (id < 0 || id > 15) {
            ERR("id '%d' out of range!\n", id);
            return false;
        }
        channel->id = id;
    } else if (strcmp("freq", k) == 0) {
        int freq = strtol(v, NULL, 10);
        channel_set_frequency(channel, freq, false);
    } else if (strcmp("picode", k) == 0) {
        int picode = strtol(v, NULL, 10);
        channel_set_pi_code(channel, picode, false);
    } else if (strcmp("qdial", k) == 0) {
        int qdial = strtol(v, NULL, 10);
        channel_set_quick_dial(channel, qdial, false);
    } else if (strcmp("name", k) == 0) {
        return channel_set_name(channel, v);
    } else if (strcmp("note", k) == 0) {
        return channel_set_note(channel, v);
    } else {
        ERR("unkown key '%s'!\n", k);
        return false;
    }
    return true;
}

bool channel_set_pi_code(channel_info_t *channel, uint16_t pi_code, bool fail) {
	if (channel == NULL) return false;

    if (fail && (pi_code < 1 || pi_code > ((1<<16) - 1))) {
        ERR("picode '%d' out of range!\n", pi_code);
        return false;
    }
	channel->pi_code = pi_code;
	return true;
}

bool channel_set_quick_dial(channel_info_t *channel, uint8_t qdial, bool fail) {
	if (channel == NULL) return false;

    if (fail && (qdial < 1 || qdial > 9)) {
        ERR("qdial '%d' out of range!\n", qdial);
        return false;
    }

	channel->quickDial = qdial;
	return true;
}

bool channel_set_frequency(channel_info_t *channel, uint16_t frequency, bool fail) {
	if (channel == NULL) return false;

    if (fail && ((frequency < 875 || frequency > 1080) && frequency != 0)) {
        ERR("frequency '%d' out of range!\n", frequency);
        return false;
    }

	channel->frequency = frequency;
	return true;
}

bool channel_set_name(channel_info_t *channel, char *name) {
	if (channel == NULL) return false;

	//strncpy(channel->name, name, 8);
	snprintf(channel->name, 9, "%-8s", name);
	channel->name[8] = 0;
	return true;
}

bool channel_set_note(channel_info_t *channel, char *note) {
	if (channel == NULL) return false;

	strncpy(channel->note, note, 40);
	channel->name[40] = 0;
	return true;
}
