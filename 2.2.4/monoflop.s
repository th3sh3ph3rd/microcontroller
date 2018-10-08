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

    ldi     temp1, 0xff

porta:
    in      temp0, PINA
    out     PORTA, temp0
    out     DDRA, temp0
    cpse    temp0, temp1
    rjmp    portb
    ldi     temp0, 0x00
    out     DDRA, temp0
    out     PORTA, temp0

portb:
    in      temp0, PINB
    out     PORTB, temp0
    out     DDRB, temp0
    cpse    temp0, temp1
    rjmp    portc
    ldi     temp0, 0x00
    out     DDRB, temp0
    out     PORTB, temp0

portc:
    in      temp0, PINC
    out     PORTC, temp0
    out     DDRC, temp0
    cpse    temp0, temp1
    rjmp    portd
    ldi     temp0, 0x00
    out     DDRC, temp0
    out     PORTC, temp0

portd:
    in      temp0, PIND
    out     PORTD, temp0
    out     DDRD, temp0
    cpse    temp0, temp1
    rjmp    porte
    ldi     temp0, 0x00
    out     DDRD, temp0
    out     PORTD, temp0

porte:
    in      temp0, PINE
    in      PINE, temp0
    out     PORTE, temp0
    out     DDRE, temp0
    cpse    temp0, temp1
    rjmp    portf
    ldi     temp0, 0x00
    out     DDRE, temp0
    out     PORTE, temp0
    
portf:
    in      temp0, PINF
    out     PORTF, temp0
    out     DDRF, temp0
    cpse    temp0, temp1
    rjmp    portg
    ldi     temp0, 0x00
    out     DDRF, temp0
    out     PORTF, temp0
    
portg:
    in      temp0, PING
    out     DDRG, temp0
    cpse    temp0, temp1
    rjmp    porth
    ldi     temp0, 0x00
    out     DDRG, temp0
    out     PORTG, temp0
    
porth:
    lds     temp0, PINH
    sts     PORTH, temp0
    sts     DDRH, temp0
    cpse    temp0, temp1
    rjmp    portj
    ldi     temp0, 0x00
    sts     DDRH, temp0
    sts     PORTH, temp0

portj:
    lds     temp0, PINJ
    sts     PORTJ, temp0
    sts     DDRJ, temp0
    cpse    temp0, temp1
    rjmp    portk
    ldi     temp0, 0x00
    sts     DDRJ, temp0
    sts     PORTJ, temp0

portk:
    lds     temp0, PINK
    sts     PORTK, temp0
    sts     DDRK, temp0
    cpse    temp0, temp1
    rjmp    portl
    ldi     temp0, 0x00
    sts     DDRK, temp0
    sts     PORTK, temp0

portl:
    lds     temp0, PINL
    sts     PORTL, temp0
    sts     DDRL, temp0
    cpse    temp0, temp1
    rjmp    porta
    ldi     temp0, 0x00
    sts     DDRL, temp0
    sts     PORTL, temp0

    rjmp    porta

