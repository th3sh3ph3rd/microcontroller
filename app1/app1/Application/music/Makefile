#
# Makefile for the music module
# Author: Jan Nausner <e01614835@student.tuwien.ac.at>
# 
# Targets:
#   all         generates flash file
#

FILENAME    = music

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -std=gnu99 -Wall -Wextra -Wstrict-prototypes -frename-registers -fshort-enums -fpack-struct
CCFLAGS    += -I. -I../ -I../libmp3 -I../libsdcard -I../spi
LDFLAGS     = -mmcu=$(MCU)

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).o

$(FILENAME).o: $(FILENAME).c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(FILENAME).o

