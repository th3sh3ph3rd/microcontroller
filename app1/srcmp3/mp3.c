/*
mp3lib for VS1011E
Copyright (C) 2011 Andreas Hagmann, Embedded Computing Systems group - TU Wien

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

#include "mp3.h"

#include <spi.h>

#include <util/delay.h>
#include <avr/interrupt.h>

// internal definitions
#define mp3CSLow()	MP3_PORT &= ~(1<<MP3_CS)
#define mp3CSHigh()	MP3_PORT |= (1<<MP3_CS)
#define bsyncLow()	MP3_PORT &= ~(1<<BSYNC)
#define bsyncHigh()	MP3_PORT |= (1<<BSYNC)
#define clearINT0Flag()	GIFR = (1<<INTF0)

static uint16_t sciRead(uint8_t addr);
static void sciWrite(uint8_t addr, uint16_t data);
static void mp3WaitBusy(void);
static void (*dataRequest)(void);

static uint8_t vs_version = 0;

typedef enum {
	OP_WRITE= 0x02,
	OP_READ	= 0x03,
} opcode_t;

typedef enum {
	MODE	= 0x00,
	STATUS	= 0x01,
	BASS	= 0x02,
	CLOCKF	= 0x03,
	DECODE_TIME	= 0x04,
	VOL		= 0x0b,
} register_t;

bool mp3Busy() {
	if ((INT_PIN & (1<<DREQ)) == 0) {
		return true;
	}
	return false;
}

void mp3WaitBusy() {
	while (mp3Busy() == true);
}

void sciWrite(uint8_t addr, uint16_t data) {
	mp3WaitBusy();

	mp3CSLow();
	spiSend(OP_WRITE);
	spiSend(addr);
	spiSend((uint8_t)((data>>8) & 0xff));
	spiSend((uint8_t)((data>>0) & 0xff));
	mp3CSHigh();
}

uint16_t sciRead(uint8_t addr) {
	uint16_t value;

	mp3WaitBusy();

	mp3CSLow();
	spiSend(OP_READ);
	spiSend(addr);
	value = spiReceive() << 8;
	value |= spiReceive();
	mp3CSHigh();

	return value;
}

void mp3Init(void (*dataRequestCallback)(void)) {
	dataRequest = dataRequestCallback;

	// init ports
	MP3_DDR |= (1<<MP3_CS) | (1<<MP3_RST) | (1<<BSYNC);
	INT_PORT |= 1<<DREQ;
	INT_DDR &= ~(1<<DREQ);

	// hardware reset
	MP3_PORT &= ~(1<<MP3_RST);
	_delay_ms(1);

	bsyncHigh();
	mp3CSHigh();
	MP3_PORT |= (1<<MP3_RST);
	mp3WaitBusy();

	// ensure we are not to fast, else we or board get many bit errors
	spiSetPrescaler(SPI_PRESCALER_128);

	sciWrite(MODE, (1<<11)|(1<<2));	// native mode
	_delay_us(100);

	uint16_t vs_status = sciRead(STATUS);
	vs_version = (vs_status >> 4) & 0x0F;

	// set clock freq
	if (vs_version == 2) { // rev 1.10, vs1011e
		// (25 MHz / 2 KHz) see vs1011e datasheet 8.6.4 CLOCKF
		sciWrite(CLOCKF, 12500L);

	} else if (vs_version == 4) { // rev 1.21, vs1053b
		// tell PLL to multiple by 2.5, helps a bit with SCLK sampling
		sciWrite(CLOCKF, 0x4000);
	}

	sciWrite(BASS, 0x7A00);	// get some bass
	sciWrite(VOL, 0x3000);

	spiSetPrescaler(SPI_PRESCALER_4);

	// init external INT0
	EICRA |= (1<<ISC01) | (1<<ISC00);
	EIMSK |= (1<<INT0);
}

void mp3SetVolume(uint8_t vol) {
	uint8_t temp;

	temp = 0xff - vol;

	mp3WaitBusy();
	sciWrite(VOL, temp | (temp<<8));
}

void mp3StartSineTest() {
	sciWrite(MODE, (1<<11)|(1<<5));

	mp3WaitBusy();

	spiSetPrescaler(SPI_PRESCALER_16);
	bsyncLow();
	spiSend(0x53);
	spiSend(0xef);
	spiSend(0x6e);
	spiSend(0xcc);
	spiSend(0x00);
	spiSend(0x00);
	spiSend(0x00);
	spiSend(0x00);
	bsyncHigh();
	spiSetPrescaler(SPI_PRESCALER_4);
}

void mp3SendMusic(uint8_t *buffer) {
	uint8_t i;

	mp3WaitBusy();		// during normal operation, this is no busy wait loop, only during initialisation

	// TODO: this should return the current (old) prescaler so that we can reset
	// to the correct actual value below
	spiSetPrescaler(SPI_PRESCALER_16);
	bsyncLow();
	for (i=0; i<32; i++) {
		spiSend(buffer[i]);
	}
	bsyncHigh();
	spiSetPrescaler(SPI_PRESCALER_4);
}

uint8_t mp3GetVS10xxVersion(void) {
	spiSetPrescaler(SPI_PRESCALER_16);
	uint16_t vs_status = sciRead(STATUS);
	spiSetPrescaler(SPI_PRESCALER_4);

	vs_version = (vs_status >> 4) & 0x0F;

	return vs_version;
}

ISR (INT0_vect) {
	if (dataRequest != NULL) {
		dataRequest();
	}
}

