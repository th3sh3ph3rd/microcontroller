#
# Makefile for the "Falling Down Ball" - game
# Author: Jan Nausner <e01614835@student.tuwien.ac.at>
# 
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
OBJECTS     = $(FILENAME).o
OBJECTS	   += adc/adc.o Standard5x7/Standard5x7.o game/game.o glcd/glcd.o glcd/hal_glcd.o hal_wt41_fc_uart/hal_wt41_fc_uart.o music/music.o rand/rand.o spi/spi.o timer/timer.o

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -std=gnu99 -Wall -Wextra -Wstrict-prototypes -frename-registers
CCFLAGS	   += -fshort-enums -fpack-struct -I. -Iadc -IStandard5x7 -Igame -Iglcd -Ihal_wt41_fc_uart -Imusic -Ilibmp3 -Ilibwiimote -Irand -Ilibsdcard -Ispi -Itimer
LDFLAGS     = -mmcu=$(MCU) -Llibmp3 -Llibsdcard -Llibwiimote -lmp3 -lsdcard -lwiimote

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS)
	$(CCLD) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS)

