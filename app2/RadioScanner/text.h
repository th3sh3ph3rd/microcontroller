/**
 *
 * @file text.h
 * @author  Jan Nausner <e01614835@student.tuwien.ac.at>
 * @date    2019-01-13
 *
 * Display text for the main application, stored in PROGMEM.
 *
**/

#ifndef __TEXT__
#define __TEXT__

#include <avr/pgmspace.h>

#define CHARS_PER_LINE  21

/* Application messages */

const char text_channelInput[] PROGMEM = "Enter Channel:";
const char text_channel[] PROGMEM = "Channel: ";
const char text_MHz[] PROGMEM = "MHz";
const char text_volume[] PROGMEM = "Volume:";

/* Error messages */
const char text_error[] PROGMEM = "Error:";
const char text_unknownError[] PROGMEM = "Unknown error!";
#define E_FMCLICK_INIT 0
const char text_FMClickInitFail[] PROGMEM = "FMClick init failed!";
#define E_CHAN_INVAL 1
const char text_chanInval[] PROGMEM = "Invalid channel!";
#define E_LIST_FULL 2
const char text_listFull[] PROGMEM = "Channel list full!";
#define E_FAVS_FULL 3
const char text_favsFull[] PROGMEM = "Favourites full!";
#define E_DB_FULL 4
const char text_dbFull[] PROGMEM = "DB full!";
#define E_DB_ERR 5
const char text_dbErr[] PROGMEM = "DB error!";
#define E_BAND_LIMIT 6
const char text_bandLimit[] PROGMEM = "Band limit reached!";

#endif

