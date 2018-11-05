#
# Makefile for the "Falling Down Ball" - game
# Author: Jan Nausner <e01614835@student.tuwien.ac.at>
# 
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
ADD_OBJECTS = adc/adc.o gameui/gameui.o hal_wt41_fc_uart/hal_wt41_fc_uart.o rand/rand.o
OBJECTS     = main.o

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -std=gnu99 -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -funsigned-char -funsigned-bitfields -fshort-enums -fpack-struct -I. -Iadc/ -Igameui/ -Ihalwt41_fc_uart/ -Ilibglcd/ -Irand/
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf -lprintf_min -Llibglcd -lglcd

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(ADD_OBJECTS)
	$(CCLD) -o $@ $(OBJECTS) $(ADD_OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS) $(ADD_OBJECTS)

