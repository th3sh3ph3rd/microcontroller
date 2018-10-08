#
# Makefile for the calling conventions server
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

FILENAME    = calling_conv_client
OBJECTS     = main.o increment.o

MCU         = atmega1280
ARCH        = avr51

LD          = avr-ld
LDFLAGS     = -m$(ARCH)

AS          = avr-as
ASFLAGS     = -mmcu=$(MCU)

PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

$(FILENAME).elf: $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(OBJECTS)

