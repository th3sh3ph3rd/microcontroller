; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; DDR and PORT for the LEDs
.equ DDR,   DDRA
.equ PORT,  PORTA
.equ PIN,   PINA
.equ LED0,  PA7
.equ LED1,  PA6
.equ LED2,  PA5
.equ LED3,  PA4

; Temp registers
.equ temp,  0x10
.equ leds,  0x11

; Flash memory
.section .text

.global main
.org 0x0000

rjmp   main

; This is the main program.
main: 
    ; set 0-3 as input, 4-7 as output
    ldi     temp, 0xf0
    out     DDR, temp

    ; disable pull-up for inputs and set outputs low
    ldi     temp, 0x00
    out     PORT, temp
    
led0:
    ; LED0 := (PA1 & PA2) | PA3
    sbic    PIN, PINA3
    rjmp set_led0
    sbis    PIN, PINA1
    rjmp clear_led0
    sbis    PIN, PINA2
    rjmp clear_led0
set_led0:
    sbi PORT, LED0
    rjmp led1
clear_led0:
    cbi PORT, LED0

led1:
    ; LED1 := (PA1 | ~PA2) & PA3
    sbis PIN, PINA3
    rjmp clear_led1
    sbic PIN, PINA1
    rjmp set_led1
    sbic PIN, PINA2
    rjmp clear_led1
set_led1:
    sbi PORT, LED1
    rjmp led2
clear_led1:
    cbi PORT, LED1

led2:
    ; LED1 := PA1 ^ PA2

    rjmp led0

