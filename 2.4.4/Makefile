
all: fib_lcd.elf

fib_lcd.o: fib_lcd.s
	avr-as -mmcu=atmega1280 -o fib_lcd.o fib_lcd.s

fib_lcd.elf: fib_lcd.o lcd.o
	avr-ld -mavr51 -o fib_lcd.elf fib_lcd.o lcd.o

install: fib_lcd.elf
	avrprog2 -matmega1280 --flash w:fib_lcd.elf

clean:
	rm -rf fib_lcd.o fib_lcd.elf
