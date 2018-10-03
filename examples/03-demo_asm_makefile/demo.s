; demo: bouncing leds (busy wait)

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; DDR and PORT for the LEDs
.equ LED1_DDR,   DDRA
.equ LED1_PORT,  PORTA
.equ LED2_DDR,   DDRB
.equ LED2_PORT,  PORTB
.equ LED3_DDR,   DDRC
.equ LED3_PORT,  PORTC
.equ LED4_DDR,   DDRD
.equ LED4_PORT,  PORTD
.equ LED5_DDR,   DDRE
.equ LED5_PORT,  PORTE
.equ LED6_DDR,   DDRF
.equ LED6_PORT,  PORTF
.equ LED7_DDR,   DDRG
.equ LED7_PORT,  PORTG

; Temp registers
.equ temp,  0x10
.equ leds,  0x11
.equ state, 0x12

; Flash memory
.section .text

.global main
.org 0x0000
    rjmp   main

; Delay loop subroutine.
; For simplicity (!), we use a simple busy wait loop for the delay.
; NB: If this were an actual program (like one of your lab exercises),
; we would of course use one of the AVR's timers.
busy_wait:
    ldi    temp, 0x00
    rcall  busy_wait_0
    rcall  busy_wait_0
    rcall  busy_wait_0
    ret
    
busy_wait_0:
    push   temp
    ldi    temp, 0x00
busy_wait_1:
    nop
    nop
    nop
    nop
    dec    temp
    brne   busy_wait_1
    pop    temp
    dec    temp
    brne   busy_wait_0
    ret


; This is the main program.
main:
    ; initialize stack pointer
    ldi    temp, lo8(RAMEND)
    out    SPL, temp
    ldi    temp, hi8(RAMEND)
    out    SPH, temp
    
    ldi    state, 0x00
    
    ldi    temp, 0x00
    out    LED1_PORT, temp
    out    LED2_PORT, temp
    out    LED3_PORT, temp
    out    LED4_PORT, temp
    out    LED5_PORT, temp
    out    LED6_PORT, temp
    out    LED7_PORT, temp
    
    ldi    temp, 0xff
    out    LED1_DDR, temp
    out    LED2_DDR, temp
    out    LED3_DDR, temp
    out    LED4_DDR, temp
    out    LED5_DDR, temp
    out    LED6_DDR, temp
    out    LED7_DDR, temp

    ; activate LED0 (high-active LEDs)
    rjmp   state0

infinite_loop:
    out    LED1_PORT, leds
    out    LED2_PORT, leds
    out    LED3_PORT, leds
    out    LED4_PORT, leds
    out    LED5_PORT, leds
    out    LED6_PORT, leds
    out    LED7_PORT, leds

    rcall  busy_wait

    clc

rotate:
    sbrs   state, 0
        rol    leds
    sbrc   state, 0
        ror    leds
    
    cp     leds, 0
    breq   next

    rjmp   infinite_loop

next:
    sbrc   state, 0
        rjmp   state1
    
state0:
    ldi    leds, 1<<PC7
    
    ldi    state, 0x01
    rjmp   rotate

state1:
    ldi    leds, 1<<PC0
    
    ldi    state, 0x00
    rjmp   rotate


