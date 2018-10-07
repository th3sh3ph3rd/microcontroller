; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; Temp registers
.equ temp, 0x10
.equ port, 0x11
.equ state, 0x12

.org 0x0000
    rjmp    main
.org OC1Aaddr*2
    rjmp    tmrisr

; This is the main program.
main: 
    ; init stack pointer
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ; set A-G as output
    ldi     temp, 0xff
    out     DDRA, temp
    out     DDRB, temp
    out     DDRC, temp
    out     DDRD, temp
    out     DDRE, temp
    out     DDRF, temp
    out     DDRG, temp

    ; put leds in initial state
    ldi     temp, 0x00
    out     PORTA, temp
    out     PORTB, temp
    out     PORTC, temp
    out     PORTD, temp
    out     PORTE, temp
    out     PORTF, temp
    out     PORTG, temp

    ; configure timer 1
    ; set to ctc mode
    ldi     temp, (1<<WGM12)
    sts     TCCR1B, temp
    ; set output compare register A
    ldi     temp, lo8(1250)
    sts     OCR1AL, temp
    ldi     temp, hi8(1250)
    sts     OCR1AH, temp
    ; init timer counter register
    ldi     temp, 0x00
    sts     TCNT1L, temp
    sts     TCNT1H, temp
    ; enable output compare interrupt
    ldi     temp, (1<<OCIE1A)
    sts     TIMSK1, temp
    ; start clock with 256 prescaler
    ldi     temp, (1<<CS12)
    sts     TCCR1B, temp

    ; init variables
    ldi     port, 0x00
    ldi     state, 0x00

    ; enable interrupts
    sei

loop:
    sleep
    rjmp    loop

tmrisr:
    cpi     port, 6
    breq    portg
    cpi     port, 5
    breq    portf
    cpi     port, 4
    breq    porte
    cpi     port, 3
    breq    portd
    cpi     port, 2
    breq    portc
    cpi     port, 1
    breq    portb
porta:
    in      PORTA, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTA, temp
    cpi     temp, 0x00
    breq    reset_state
    cpi     temp, 0xff
    breq    set_state
    rjmp    update_port
reset_state:
    ldi     state, 0x00
    rjmp    update_port
set_state:
    ldi     state, 0x01
    rjmp    update_port
portb:
    in      PORTB, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTB, temp
    rjmp    update_port
portc:
    in      PORTC, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTC, temp
    rjmp    update_port
portd:
    in      PORTD, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTD, temp
    rjmp    update_port
porte:
    in      PORTE, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTE, temp
    rjmp    update_port
portf:
    in      PORTF, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTF, temp
    rjmp    update_port
portg:
    in      PORTG, temp
    lsl     temp
    cpse    state, 0x01
    inc     temp
    out     PORTG, temp
update_port:
    cpi     port, 6
    breq    reset_port
    inc     port
    reti
reset_port:
    ldi     port, 0x00
    reti

