#
# Makefile for the assembler demo
#
# Targets:
#   all         generates flash file
#   install     downloads elf file to mcu
#

# we assume the extension .s for assembler files
FILENAME    = demo

MCU         = atmega1280
ARCH        = avr51

AS          = avr-as
LD          = avr-ld
PROG        = avrprog2

ASFLAGS     = -mmcu=$(MCU)
LDFLAGS     = -m$(ARCH)
PRFLAGS     = -m$(MCU)

all: $(FILENAME).elf

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.elf: %.o
	$(LD) $(LDFLAGS) -o $@ $<

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

clean:
	rm -f $(FILENAME).elf $(FILENAME).o

