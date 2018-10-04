; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; Temp registers
.equ temp0, 0x10
.equ temp1, 0x11
.equ temp2, 0x12
.equ temp3, 0x13

; Flash memory
.section .text

.global main
.org 0x0000

rjmp   main

; This is the main program.
main: 
    ; set outputs low
    ldi     temp0, 0x00
    out     PORTB, temp0
    out     PORTC, temp0  
    ; set PORTA as input
    out     DDRA, temp0
    ; disable pull-ups for input
    out     PORTA, temp0
    ; set PORTB and PORTC as output
    ldi     temp0, 0xff
    out     DDRB, temp0
    out     DDRC, temp0

loop:
    ; display PORTA on PORTB
    ldi     temp0, PORTA
    out     PORTB, temp0
    ; display PINA on PORTC
    ldi     temp0, PINA
    out     PORTC, temp0

    rjmp    loop

