
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ temp, 0x10

.global main
.org 0x0000
    rjmp main

main:
    
    ldi     temp, 0x00
    out     DDRB, temp
    ldi     temp, 0xff
    out     PORTB, temp

    ldi     temp, 0x00
    sts     PORTH, temp
    ldi     temp, (1<<PH0)|(1<<PH1)|(1<<PH3)
    sts     DDRH, temp

loop:
    sbis    PINB, PB1
    rjmp    case0
    sbis    PINB, PB2
    rjmp    case1
    sbis    PINB, PB3
    rjmp    case2
case3:
    ldi     temp, (1<<PH3)
    rjmp    set_leds
case2:
    ldi     temp, (1<<PH0)|(1<<PH1)
    rjmp    set_leds
case1:
    ldi     temp, (1<<PH1)
    rjmp    set_leds
case0:
    ldi     temp, (1<<PH0)
set_leds:
    sts     PORTH, temp

    rjmp    loop

