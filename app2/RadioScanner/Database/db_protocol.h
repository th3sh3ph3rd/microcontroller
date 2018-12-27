/**
 *
 * @file db_protocol.h
 * @author Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date 2018-12-27
 *
 * Database proDatabase protocol commands and parameters stored in PROGMEMM.
 *
 */

#ifndef __DB_PROTOCOL__
#define __DB_PROTOCOL__

#include <avr/pgmspace.h>

/* Database protocol commands */
const char db_cmd_add[] PROGMEM = "add";
const char db_cmd_update[] PROGMEM = "update";
const char db_cmd_delete[] PROGMEM = "delete";
const char db_cmd_list[] PROGMEM = "list";
const char db_cmd_get[] PROGMEM = "get";
const char db_cmd_purgeall[] PROGMEM = "purgeall";

/* Database protocol arguments */
const char db_arg_id[] PROGMEM = "id";
const char db_arg_name[] PROGMEM = "name";
const char db_arg_qdial[] PROGMEM = "qdial";
const char db_arg_freq[] PROGMEM = "freq";
const char db_arg_picode[] PROGMEM = "picode";
const char db_arg_note[] PROGMEM = "note";

#endif
