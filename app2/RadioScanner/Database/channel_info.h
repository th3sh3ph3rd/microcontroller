/**
 * author:	Thomas lamprecht
 * date:	27.11.2018
 */

#ifndef _CHANNEL_INFO_H_
#define _CHANNEL_INFO_H_

#include <stdint.h>
#include <stdbool.h>

#define NUMBER_OF_ENTRIES 15

#define ERR(...) fprintf(stderr, __VA_ARGS__)

typedef struct {
    uint8_t id;
        // The quick dial key [1..9], pass 0 for no/deleting quick dial
    uint8_t quickDial;

    // The channels's frequency in multiplies of 100kHZ, for example, 99.9MHZ =
    // 999 * 100kHz => 999
    uint16_t frequency;

    // The RDS PI Program Idenfitifaction code
    uint16_t pi_code;

    // The channel name, length maximal 9 characters, normally the RDS PS field
    char name[9];

    // optional notes of the channel (length maximal 40 characters) pass NUL
    // (\0) to delete exisiting notes or set none on new entries
    char note[41];
} channel_info_t;

channel_info_t *channel_alloc(void);

void channel_reset(channel_info_t *channel);

bool channel_set_pi_code(channel_info_t *channel, uint16_t pi_code, bool fail);

bool channel_set_quick_dial(channel_info_t *channel, uint8_t qdial, bool fail);

bool channel_set_frequency(channel_info_t *channel, uint16_t frequency, bool fail);

bool channel_set_name(channel_info_t *channel, char *name);

bool channel_set_note(channel_info_t *channel, char *note);

bool channel_set_kv(channel_info_t *channel, char *k, char *v);

#endif //GAME_INFO_H
