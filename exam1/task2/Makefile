
all: task2.elf

task2.o: task2.s
	avr-as -mmcu=atmega1280 -o task2.o task2.s

task2.elf: task2.o
	avr-ld -mavr51 -o task2.elf task2.o

install: task2.elf
	avrprog2 -matmega1280 --flash w:task2.elf

clean:
	rm -rf task2.elf task2.o
