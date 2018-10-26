/*
simple sdcardlib
Copyright (C) 2011 Andreas Hagmann, Embedded Computing Systems group - TU Wien
thanks for infos and hints go to
 - http://elm-chan.org/docs/mmc/sdinit.png
 - Chris Hinger
 - CC Dharmani (http://www.dharmanitech.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "sdcard.h"
#include <stdlib.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

//#define DEBUG
#define MMC_SUPPORT
//#define IGNORE_SPI_SPEED

#ifdef DEBUG
#include "printf.h"
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...) do{}while(0);
#endif

#define READ_TIMEOUT	10000UL
#define COMMAND_LEN	6

typedef union {
	struct {
		bool idle			: 1;
		bool erase			: 1;
		bool illegal		: 1;
		bool crcError		: 1;
		bool eraseError		: 1;
		bool addressError	: 1;
		bool parameterError	: 1;
		bool invalidResponse: 1;
		uint32_t r7			: 32;
	} r;
	uint8_t v;
	uint8_t a[5];
} response_t;

typedef enum {
	READ			= 0x40 | 17,
	GO_IDLE_STATE	= 0x40 | 0,
	APP				= 0x40 | 55,
	SEND_OP_COND	= 0x40 | 1,
	SET_BLOCK_LEN	= 0x40 | 16,
	SEND_IF_COND	= 0x40 | 8,
} command_t;

static response_t command(const command_t command, const uint32_t argument, uint8_t crc, uint8_t responseLen);
static response_t singleCommand(const command_t command, const uint32_t argument, uint8_t crc, uint8_t responseLen);
static response_t appCommand(const command_t command, const uint32_t argument, uint8_t crc, uint8_t responseLen);
static inline void csEnable(void);
static inline void csDisable(void);

void csEnable() {
	SDCARD_PORT &= ~((1<<SDCARD_CS));
}

void csDisable() {
	SDCARD_PORT |= ((1<<SDCARD_CS));
}

error_t sdcardInit() {
	uint8_t i;
	response_t response;
	error_t err = SUCCESS;
	uint32_t timeout;

	SDCARD_DDR = (SDCARD_DDR & ~(1<<SDCARD_CD)) | (1<<SDCARD_CS);
	SDCARD_PORT |= (1<<SDCARD_CS);

#ifndef IGNORE_SPI_SPEED
	spiSetPrescaler(SPI_PRESCALER_128);
#endif

	if (sdcardAvailable() == false) {
		return E_NOCARD;
	}

	for (i = 0; i<200; i++) {													// sending dummy-packets
		spiSend(0xFF);
	}

	response = singleCommand(GO_IDLE_STATE, 0, 0x95, 1);						// reset card
	if (response.v != 0x01) {
		debug("reset failed %x\n", response.v);
		err = ERROR;
		goto error;
	}

	timeout = READ_TIMEOUT;
	response = singleCommand(SEND_IF_COND, 0x000001AA, 0x87, 5);				// use this to check card type
	if (response.v != 0x01) {													// found sdc version 1 or mmc
		debug("found sdc 1\n");
		do {
			response = appCommand(SEND_OP_COND, 0, 0, 1);						// activate card
			debug("activate sdc1 %x\n", response.v);
			if (response.v == 0x01) {
				// idle, try again
			}
			else if (response.v == SUCCESS) {									// found sdc version 1
				break;
			}
			else {																// found mmc
#ifdef MMC_SUPPORT
				timeout = 0;
				break;
#else
				debug("sendOpCond failed %x\n", response.v);
				err = E_UNKNOWN_CARD;
				goto error;
#endif
			}
			timeout--;
		} while (timeout > 0);

#ifdef MMC_SUPPORT
		if (timeout == 0) {														// init MMC
			timeout = READ_TIMEOUT;
			debug("found mmc\n");
			response = singleCommand(GO_IDLE_STATE, 0, 0x95, 1);				// reset card
			if (response.v != 0x01) {
				debug("reset failed %x\n", response.v);
				err = ERROR;
				goto error;
			}
			do {
				response = singleCommand(SEND_OP_COND, 0, 0, 1);
				debug("activate mmc %x\n", response.v);
				if (response.v == 0x01) {
					// idle, try again
				}
				else if (response.v == SUCCESS) {
					break;
				}
				else {
					debug("sendOpCond failed %x\n", response.v);
					err = E_UNKNOWN_CARD;
					goto error;
				}
				timeout--;
			} while (timeout > 0);
		}
#endif
	}
	else if ((response.r.r7>>16) != 0xaa01) {									// found sdc version 2
		debug("sd Version 2, unsupported card %x\n", response.v);
		err = E_UNKNOWN_CARD;
		goto error;
	}
	else {																		// found sdc version 2
		debug("found sdc 2\n");
		do {
			response = appCommand(SEND_OP_COND, 0x40000000, 0, 1);				// activate card
			debug("activate sdc2 %x\n", response.v);
			if (response.v == 0x01) {
				// idle, try again
			}
			else if (response.v == SUCCESS) {
				break;
			}
			else {
				debug("sendOpCond failed %x\n", response.v);
				err = E_UNKNOWN_CARD;
				goto error;
			}
			timeout--;
		} while (timeout > 0);
	}

	if (timeout == 0) {
		debug("init failed\n");
		err = E_TIMEOUT;
		goto error;
	}

	response = singleCommand(SET_BLOCK_LEN, BLOCK_SIZE, 0, 1);
	if (response.v != SUCCESS) {
		debug("setBlocklen failed\n");
		err = ERROR;
	}

#ifndef IGNORE_SPI_SPEED
	spiSetPrescaler(SPI_PRESCALER_4);
#endif

error:
	return err;
}

bool sdcardAvailable() {
	return ((SDCARD_PIN & (1<<SDCARD_CD)) != 0) ? false : true;
}

error_t sdcardReadBlock(uint32_t byteAddress, sdcard_block_t buffer) {
	uint16_t i;
	response_t response;
	uint32_t timeout;
	error_t err = SUCCESS;

	//spiReceive();	// extra 8 clock cycles, why ???

	csEnable();

	// send address
	response = command(READ, byteAddress, 0xff, 1);
	if (response.v != SUCCESS) {
		debug("read failed %x\n", response.v);
		err = ERROR;
		goto error;
	}

	// wait for data
	timeout = READ_TIMEOUT;
	do {
		response.v = spiReceive();
		timeout--;
	} while ((response.v != 254) && (timeout > 0));

	if (response.v != 254) {
		debug("wait on data failed\n");
		err = E_TIMEOUT;
		goto error;
	}

	for (i=0; i<sizeof(sdcard_block_t); i++) {
		buffer[i] = spiReceive();
	}

	spiReceive();	// read crc
	spiReceive();

error:
	csDisable();
	spiReceive();	// extra 8 clock cycles

	return err;
}

response_t appCommand(const command_t command, const uint32_t argument, uint8_t crc, uint8_t responseLen) {
	response_t response;

	response = singleCommand(APP, 0, 0, 1);
	if (response.v & ~0x01) {
		debug("app failed %x\n", response.v);
		response.v = 0xff;
		goto error;
	}

	response = singleCommand(command, argument, crc, responseLen);

error:
	return response;
}

response_t singleCommand(const command_t _command, const uint32_t argument, uint8_t crc, uint8_t responseLen) {
	response_t response;

	spiReceive();			// extra 8 clock cycles, why ???
	csEnable();
	response = command (_command, argument, crc, responseLen);
	csDisable();
	spiReceive();			// additional 8 clock cycles

	return response;
}

response_t command(const command_t command, const uint32_t argument, uint8_t crc, uint8_t responseLen) {
	response_t response;
	uint32_t timeout;
	uint8_t buffer[COMMAND_LEN];

	buffer[0] = command;
	buffer[4] = argument;
	buffer[3] = (argument >> 8);
	buffer[2] = (argument >> 16);
	buffer[1] = (argument >> 24);
	buffer[5] = crc;

	for(uint8_t i=0; i<COMMAND_LEN; i++) {
		spiSend(buffer[i]);
	}

	timeout = 100;
	do {
		response.v = spiReceive();
		timeout--;
	} while ((response.r.invalidResponse == true) && (timeout > 0));

	for(uint8_t i=1; i<responseLen; i++) {
		response.a[i] = spiReceive();
	}

	if (timeout == 0) {
		response.v = 0xff;
	}

	return response;
}
