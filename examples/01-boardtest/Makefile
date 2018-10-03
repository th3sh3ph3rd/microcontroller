#
# Makefile for the assembler demo
#
# Targets:
#   install     downloads elf file to mcu
#   verify      verifies the flashed file
#

FILENAME    = boardtest

MCU         = atmega1280
PROG        = avrprog2
PRFLAGS     = -m$(MCU)

all:

install: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash w:$<

verify: $(FILENAME).elf
	$(PROG) $(PRFLAGS) --flash v:$<

