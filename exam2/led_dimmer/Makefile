#
# Makefile for the C demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = led_dimmer
OBJECTS     = $(FILENAME).o

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -fshort-enums -fpack-struct
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf -lprintf_min

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS)
	$(CCLD) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS)

