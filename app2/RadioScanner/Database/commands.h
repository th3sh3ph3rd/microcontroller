/**
 *
 * @file    commands.h
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2019-01-15
 *
 * Database commands saved in PROGMEM.
 *
**/

#ifndef __COMAMNDS__
#define __COMMANDS__

#include <avr/pgmspace.h>

#define CMD_OK_LEN 2
const char cmd_ok[] PROGMEM = "ok";
#define CMD_MSG_LEN 3
const char cmd_msg[] PROGMEM = "msg";
#define CMD_DBFULL_LEN 15
const char cmd_dbFull[] PROGMEM = "Channel DB Full";
#define CMD_ID_LEN 2
const char cmd_id[] PROGMEM = "id";
#define CMD_FREQ_LEN 4
const char cmd_freq[] PROGMEM = "freq";
#define CMD_PICODE_LEN 6
const char cmd_picode[] PROGMEM = "picode";
#define CMD_QDIAL_LEN 5
const char cmd_qdial[] PROGMEM = "qdial";
#define CMD_NAME_LEN 4
const char cmd_name[] PROGMEM = "name";
#define CMD_NOTE_LEN 4
const char cmd_note[] PROGMEM = "note";

#endif

