#
# Makefile for the C GLCD demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = main
OBJECTS     = main.o

MCU         = atmega1280

CCLD        = avr-gcc
CCFLAGS     = -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -frename-registers
CCFLAGS    += -fshort-enums -fpack-struct -Idrivers/libglcd/
LDFLAGS     = -mmcu=$(MCU) -Wl,-u,vfprintf -lprintf_min -Ldrivers/libglcd/ -lglcd

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(ADD_OBJECTS)
	$(CCLD) $(OBJECTS) $(ADD_OBJECTS) $(LDFLAGS) -o $@ 

%.o: %.c
	$(CCLD) $(CCFLAGS) -c -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS)

