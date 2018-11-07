
all: wiimoteuarttest.elf

wiimoteuarttest.elf: mac.o hal_wt41_fc_uart.o libwiimoteuarttest.a 
	avr-gcc -mmcu=atmega1280 -o wiimoteuarttest.elf -L. -Ltimer -lwiimoteuarttest mac.o hal_wt41_fc_uart.o timer/timer.o

mac.o: mac.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -c -o mac.o mac.c

hal_wt41_fc_uart.o: hal_wt41_fc_uart.c
	avr-gcc -mmcu=atmega1280 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -I. -Itimer -std=c99 -DF_CPU=16000000UL -c -o hal_wt41_fc_uart.o hal_wt41_fc_uart.c

install: all
	avrprog2 --flash w:wiimoteuarttest.elf -v

clean:
	rm -f *.elf *.o
