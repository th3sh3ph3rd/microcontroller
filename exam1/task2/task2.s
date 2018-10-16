
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp, 0x10
.equ    state, 0x11
.equ    save, 0x12

.section .text
.global main

.org 0x00
    rjmp main

.org INT6addr*2
    rjmp    isr

isr:
    in      save, SREG
    push    temp

    in      temp, PORTB
    cpi     state, 1
    breq    sr
sl:
    lsl     temp
    out     PORTB, temp
    cpi     temp, (1<<PE3)
    brne    end
    ldi     state, 1
    ldi     temp, (1<<ISC71)|(1<<ISC70)
    sts     EICRB, temp
    rjmp    end
sr:
    lsr     temp
    out     PORTB, temp
    cpi     temp, (1<<PE0)
    brne    end
    ldi     state, 0
    ldi     temp, (1<<ISC71)
    sts     EICRB, temp

end:
    pop     temp
    out     SREG, save
    reti

main:
    ; setup LEDs
    ldi      temp, 0x00
    out      PORTB, temp
    ldi      temp, 0x0f
    out      DDRB, temp

    ; setup INT7
    ; enable pullup for INT7
    ldi     temp, (1<<PE7)
    out     PORTE, temp
    ; set falling edge
    ldi     temp, (1<<ISC71)
    sts     EICRB, temp
    ; enable INT7
    ldi     temp, (1<<INT7)
    out     EIMSK, temp

    ; init state
    ldi     state, 0
    ldi     temp, 0x01
    out     PORTB, temp

    ; enable interrupts
    sei

infinite_loop:
    rjmp    infinite_loop

