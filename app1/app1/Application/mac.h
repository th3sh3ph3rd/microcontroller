#include <avr/pgmspace.h>
#include <stdint.h>

#ifndef __MAC__
#define __MAC__

const uint8_t mac_address[6] PROGMEM = { 0x58, 0xbd, 0xa3, 0x54, 0xfb, 0xaa };

#endif
