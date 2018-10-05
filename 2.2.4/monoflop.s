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
    ldi     temp0, 0x00

    ; set A-L as input 
    out     DDRA, temp0
    out     DDRB, temp0
    out     DDRC, temp0  
    out     DDRD, temp0
    out     DDRE, temp0
    out     DDRF, temp0
    out     DDRG, temp0
    sts     DDRH, temp0
    sts     DDRJ, temp0
    sts     DDRK, temp0
    sts     DDRL, temp0

    ; disable pull-ups for inputs
    out     PORTA, temp0
    out     PORTB, temp0
    out     PORTC, temp0  
    out     PORTD, temp0
    out     PORTE, temp0
    out     PORTF, temp0
    out     PORTG, temp0
    sts     PORTH, temp0
    sts     PORTJ, temp0
    sts     PORTK, temp0
    sts     PORTL, temp0

loop:
    ; display PORTA on PORTB
    ldi     temp0, PORTA
    out     PORTB, temp0
    ; display PINA on PORTC
    ldi     temp0, PINA
    out     PORTC, temp0

    rjmp    loop

