FILENAME = led_curtain

MCU = atmega1280
ARCH = avr51

AS = avr-as
LD = avr-ld
PROG = avrprog2

ASFLAGS = -mmcu=$(MCU)
LDFLAGS = -m$(ARCH)
PROGFLAGS = -m$(MCU) --flash

.PHONY: clean

all: $(FILENAME).elf

$(FILENAME).elf: $(FILENAME).s
	$(AS) $(ASFLAGS) -o $(<:.s=.o) $<
	$(LD) $(LDFLAGS) -o $@ $(@:.elf=.o)

install: $(FILENAME).elf
	$(PROG) $(PROGFLAGS) w:$<

clean:
	rm -rf $(FILENAME).o $(FILENAME).elf

