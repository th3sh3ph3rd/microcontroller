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
#define E_BAND_LIMIT 1
const char text_bandLimit[] PROGMEM = "Out of band limits!";
#define E_LIST_FULL 2
const char text_listFull[] PROGMEM = "Channel list full!";

#endif

