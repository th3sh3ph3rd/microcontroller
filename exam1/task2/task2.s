
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp, 0x10

.section .text
.global main

.org 0x00
    rjmp main

.org INT7addr*2
    rjmp    isr

isr:

main:
    ; setup LEDs
    ldi      temp, 0x00
    out      PORTB, temp
    ldi      temp, 0x0f
    out      DDRB, temp

    ; setup INT7

infinite_loop:
    rjmp    infinite_loop

