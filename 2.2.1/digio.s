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
    ; disable pull-up for inputs and set outputs low
    ldi     temp0, 0x00
    out     PORT, temp0
    
    ; set 0-3 as input, 4-7 as output
    ldi     temp0, 0xf0
    out     DDR, temp0

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
    cbi     PORT, LED0

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
    cbi     PORT, LED1

led2:
    ; LED2 := PA1 ^ PA2
    ldi     temp0, PIN
    bst     temp0, PINA2
    bld     temp1, LED2
    bst     temp0, PINA1
    bld     temp0, LED2
    eor     temp0, temp1
    andi    temp0, (1<<LED2)
    ldi     temp1, PORT
    or      temp0, temp1
    out     PORT, temp0

led3:
    ; LED3 := PA1 = PA2
    ldi     temp0, PIN
    bst     temp0, PINA2
    bld     temp1, LED2
    bst     temp0, PINA1
    bld     temp0, LED2
    eor     temp0, temp1
    com     temp0
    andi    temp0, (1<<LED2)
    ldi     temp1, PORT
    or      temp0, temp1
    out     PORT, temp0

    rjmp led0

; alternative implementation with less instructions
alt:
    ldi     temp1, 0x00
    ldi     temp2, 0x00
    ldi     temp0, PIN 
    ; LED0 := (PA1 & PA2) | PA3
    bst     temp0, PINA1
    bld     temp1, LED0
    bst     temp0, PINA2
    bld     temp2, LED0
    and     temp1, temp2
    bst     temp0, PINA3
    bld     temp2, LED0
    or      temp1, temp2
    ; LED1 := (PA1 | ~PA2) & PA3
    bst     temp0, PINA1
    bld     temp1, LED1
    ldi     temp2, 0x00 ; neutral init for or
    bst     temp0, PINA2
    bld     temp2, LED1
    eor     temp2, (1<<LED2) ; toggle bit
    or      temp1, temp2
    ldi     temp2, 0xff ; neutral init for and
    bst     temp0, PINA3
    bld     temp2, LED1
    and     temp1, temp2
    ; LED2 := PA1 ^ PA2
    bst     temp0, PINA1
    bld     temp1, LED2
    bst     temp0, PINA2
    bst     temp2, LED2
    ldi     temp2, 0x00 ; neutral init for xor
    eor     temp1, temp2
    ; LED3 := PA1 = PA2
    bst     temp1, LED2
    bld     temp1, LED3
    eor     temp1, (1<<LED3) ; just toggle the xor result
    ; write to the output register
    ldi     temp0, PORT
    or      temp0, temp1
    out     PORT, temp0

    rjmp    alt
