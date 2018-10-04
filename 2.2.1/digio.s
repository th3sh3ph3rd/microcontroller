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
.equ temp0,  0x10
.equ temp1,  0x11

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
<<<<<<< HEAD
    sbic    PIN, PIN3
    rjump   set_led0
    sbis    PIN, PIN1
    rjump   clear_led0
    sbis    PIN, PIN2
    rjump   clear_led0
set_led0:
    sbi PORT, LED0
    rjump   led1
=======
    sbic    PIN, PINA3
    rjmp set_led0
    sbis    PIN, PINA1
    rjmp clear_led0
    sbis    PIN, PINA2
    rjmp clear_led0
set_led0:
    sbi PORT, LED0
    rjmp led1
>>>>>>> 28307a0acdfbd740e9ae1303dcdc7b5bc243880d
clear_led0:
    cbi     PORT, LED0

led1:
    ; LED1 := (PA1 | ~PA2) & PA3
<<<<<<< HEAD
    sbis    PIN, PIN3
    rjump   clear_led1
    sbic    PIN, PIN1
    rjump   set_led1
    sbic    PIN, PIN2
    rjump   clear_led1
set_led1:
    sbi     PORT, LED1
    rjump   led2
=======
    sbis PIN, PINA3
    rjmp clear_led1
    sbic PIN, PINA1
    rjmp set_led1
    sbic PIN, PINA2
    rjmp clear_led1
set_led1:
    sbi PORT, LED1
    rjmp led2
>>>>>>> 28307a0acdfbd740e9ae1303dcdc7b5bc243880d
clear_led1:
    cbi     PORT, LED1

led2:
<<<<<<< HEAD
    ; LED2 := PA1 ^ PA2
    ldi     temp0, PIN
    bst     temp0, PIN2
    bld     temp1, LED2
    bst     temp0, PIN1
    bld     temp0, LED2
    andi    temp0, (1<<LED2)
    andi    temp1, (1<<LED2)
    eor     temp0, temp1
    ldi     temp1, PORT
    or      temp0, temp1
    out     PORT, temp0

    rjump led0
=======
    ; LED1 := PA1 ^ PA2

    rjmp led0
>>>>>>> 28307a0acdfbd740e9ae1303dcdc7b5bc243880d

