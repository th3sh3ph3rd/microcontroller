#
# Makefile for the assembler keypad demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = demo
OBJECTS     = demo.o
ADD_OBJECTS = lcd.o keypad.o

MCU         = atmega1280
ARCH        = avr51

LD          = avr-ld
LDFLAGS     = -m$(ARCH)

AS          = avr-as
ASFLAGS     = -mmcu=$(MCU)

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS) $(ADD_OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS) $(ADD_OBJECTS)

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(OBJECTS) $(FILENAME).elf

