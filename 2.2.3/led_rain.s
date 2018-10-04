; demo: bouncing leds (busy wait)

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; Temp registers
.equ temp,  0x10
.equ temp1, 0x11
.equ cnt0,  0x12
.equ cnt1,  0x13

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
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ldi     temp, 0x00
    out     PORTA, temp
    out     PORTB, temp
    out     PORTC, temp
    out     PORTD, temp
    out     PORTE, temp
    out     PORTF, temp
    out     PORTG, temp
    
    ldi     temp, 0xff
    out     DDRA, temp
    out     DDRB, temp
    out     DDRC, temp
    out     DDRD, temp
    out     DDRE, temp
    out     DDRF, temp
    out     DDRG, temp

    ldi     cnt0, 0x00
    ldi     cnt1, 0x00

infinite_loop:
    mov     temp, cnt0
    eor     temp, cnt1
    out     PORTA, temp
    
    mov     temp, cnt0
    com     temp
    add     temp, cnt1
    out     PORTB, temp

    mov     temp, cnt0
    sub     temp, cnt1
    out     PORTC, temp

    mov     temp, cnt1
    neg     temp
    and     temp, cnt0
    out     PORTD, temp

    mul     cnt0, cnt1
    movw    temp, r0
    andi    temp, 0xff
    out     PORTE, temp

    mov     temp, cnt0
    lsr     temp
    or      temp, cnt1
    out     PORTF, temp

    mov     temp, cnt0
    swap    temp
    andi    temp, 0x0f
    mov     temp1, cnt1
    andi    temp1, 0x0f
    or      temp, temp1
    out     PORTG, temp

    rcall   busy_wait

    inc     cnt0
    subi    cnt1, 3

    rjmp    infinite_loop

