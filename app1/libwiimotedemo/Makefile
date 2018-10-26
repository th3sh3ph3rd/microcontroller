
all: wiimotedemo.elf

wiimotedemo.elf: mac.o libwiimotedemo.a
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -o wiimotedemo.elf -L. -lwiimotedemo mac.o

mac.o: mac.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -c -o mac.o mac.c

install: all
	avrprog2 --flash w:wiimotedemo.elf -v

clean:
	rm -f *.elf *.o
