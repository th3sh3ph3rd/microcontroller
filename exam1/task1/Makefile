
all: task1.elf

task1.o: task1.s
	avr-as -mmcu=atmega1280 -o task1.o task1.s

task1.elf: task1.o
	avr-ld -mavr51 -o task1.elf task1.o

install: task1.elf
	avrprog2 -matmega1280 --flash w:task1.elf

clean:
	rm -rf task1.elf task1.o
