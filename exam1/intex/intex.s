
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp, 0x10
.equ    state, 0x11

.section .text

.global main
.org 0x0000
    rjmp main
.org INT0addr*2
    rjmp intisr
.org OC1Aaddr*2
    rjmp tmrisr

intisr:
    ldi     temp, 1
    eor     state, temp
    reti

tmrisr:
    in      temp, PORTA
    cpi     state, 1
    breq    sr
sl:
    sei
    cpi     temp, 0x80
    breq    sl_rst
    lsl     temp
    rjmp    end
sl_rst:
    ldi     temp, 0x01
    rjmp    end
sr:
    sei
    cpi     temp, 0x01
    breq    sr_rst
    lsr     temp
    rjmp    end
sr_rst:
    ldi     temp, 0x80
end:
    out     PORTA, temp
    reti

main:
    
    ldi     temp, 0x00
    out     PORTA, temp
    ldi     temp, 0xff
    out     DDRA, temp

    ldi     temp, (1<<PD0)
    out     PORTD, temp

    ldi     temp, (1<<ISC01)
    sts     EICRA, temp
    ldi     temp, (1<<INT0)
    out     EIMSK, temp

    ldi     temp, hi8(7812)
    sts     OCR1AH, temp
    ldi     temp, lo8(7812)
    sts     OCR1AL, temp

    ldi     temp, 0
    sts     TCNT1H, temp
    sts     TCNT1L, temp

    ldi     temp, (1<<WGM12)|(1<<CS12)|(1<<CS10)
    sts     TCCR1B, temp

    ldi     temp, (1<<OCIE1A)
    sts     TIMSK1, temp

    ldi     state, 0

    ldi     temp, 0x01
    out     PORTA, temp

    sei

loop:
    sleep
    rjmp    loop
    

