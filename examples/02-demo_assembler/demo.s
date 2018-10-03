; demo: rotating leds (busy wait)

; include register definitions for ATmega1280 , but do not put into LST-file
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; DDR and PORT for the LEDs
.equ LED_DDR,   DDRA
.equ LED_PORT,  PORTA

; Name the registers we are using.
.equ temp, 0x10
.equ leds, 0x11

; Program code belongs into text-segment = FLASH
.section .text

.global main

; Program should be placed at the start of FLASH memory address space.
; (This is redundant, as the start address of the current segment is the default)
.org 0x0000

; Jump to start of program.
; At the beginning of its address space, the AVR controller expects the
; reset/interrupt vector table - a sequence of jump instructions. The first
; is the reset vector, which means that upon reset, the controller executes
; this instruction.
; In this example we do not use any interrupts; still, we implement the jump
; for demonstration purposes.
    rjmp   main    ; External Pin/Power-on/Brown-out/Watchdog/JTAG Reset
;  ... Here, normally jumps to other interrupt service routines would follow.


; Delay loop subroutine.
; For simplicity (!), we use a simple busy wait loop for the delay.
; NB: If this were an actual program (like one of your lab exercises),
; we would of course use one of the AVR's timers.
busy_wait:
    push   temp
    ldi    temp, 0x00
busy_wait_inner1:
    push   temp
    ldi    temp, 0x00
busy_wait_inner2:
    nop
    nop
    nop
    nop
    dec    temp
    brne   busy_wait_inner2
    pop    temp
    dec    temp
    brne   busy_wait_inner1
    pop    temp
    ret


; This is the main program.
main:
    ; initialize stack pointer
    ldi    temp, lo8(RAMEND)
    out    SPL, temp
    ldi    temp, hi8(RAMEND)
    out    SPH, temp
    
    ; initialize port (all bits as output)
    ldi    temp, 0x00
    out    LED_PORT, temp
    ldi    temp, 0xff
    opt    LED_DDR, temp

    ; activate LED0 (high-active LEDs)
    ldi    leds, 1<<PA0

infinite_loop:
    out    LED_PORT, leds

    ldi    temp, 0x00
    rcall  busy_wait
    rcall  busy_wait
    rcall  busy_wait

    clc
rotate:
    rol    leds
    brcs   rotate    ; skip state where no LED is active

    rjmp   infinite_loop

