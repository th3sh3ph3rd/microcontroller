#
# Makefile for the UART module
# Author: Jan Nausner <e01614835@student.tuwien.ac.at>
# 
# Targets:
#   all         generates flash file
#

FILENAME    = hal_wt41_fc_uart

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -std=gnu99 -Wall -Wextra -Wstrict-prototypes -frename-registers -fshort-enums -fpack-struct -I.
LDFLAGS     = -mmcu=$(MCU)

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).o

$(FILENAME).o: $(FILENAME).c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(FILENAME).o

