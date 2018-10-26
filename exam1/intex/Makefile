
all: intex.elf

intex.o: intex.s
	avr-as -mmcu=atmega1280 -o intex.o intex.s

intex.elf: intex.o
	avr-ld -mavr51 -o intex.elf intex.o

install: intex.elf
	avrprog2 -matmega1280 --flash w:intex.elf

clean:
	rm -rf intex.elf intex.o

