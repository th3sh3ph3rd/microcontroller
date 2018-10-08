; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; Temp registers
.equ temp0, 0x10
.equ temp1, 0x11
.equ temp2, 0x12

; Flash memory
.section .text

.global main
.org 0x0000
    rjmp   main

; This is the main program.
main: 
    ldi     temp0, 0x04
    out     DDRA, temp0
    out     DDRB, temp0
    out     DDRC, temp0
    out     DDRD, temp0

    sbi     PORTA, 3
    in      temp0, PINA
    in      temp1, PINA
    in      temp2, PINA

    out     PORTB, temp0
    out     PORTC, temp1
    out     PORTD, temp2

loop:
    rjmp    loop
