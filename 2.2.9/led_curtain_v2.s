; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; make lower i/o fit for lds/sts
.equ PORTA, PORTA+0x20
.equ PORTB, PORTB+0x20
.equ PORTC, PORTC+0x20
.equ PORTD, PORTD+0x20
.equ PORTE, PORTE+0x20
.equ PORTF, PORTF+0x20
.equ PORTG, PORTG+0x20

; Temp registers
.equ temp, 0x10
.equ port, 0x11
.equ state, 0x12
.equ help0, 0x13
.equ help1, 0x14

;.macro update_port
;    in      @0, @2
;    lsl     @0
;    cpse    @1, 0x01
;    inc     @0
;    out     @2, @0
;.endm

.section .text

.global main
.org 0x0000
    rjmp    main
.org OC1Aaddr*2
    rjmp    tmrisr

.text

update_port:
    push    ZH
    push    ZL
    push    temp

    ; point Z to the SP
    in      ZH, SPH
    in      ZL, SPL

    ; point Z to the argument
    adiw    ZL, 3 + 2 + 2

    ld      temp, Z
    lsl     temp
    cpse    state, help1 ; TODO maybe beautify this smh
    inc     temp
    st      Z, temp
    
    pop     temp
    pop     ZL
    pop     ZH
    
    ret

; This is the main program.
; TODO change in/out to lds/sts
main: 
    ; init stack pointer
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ; put leds in initial state
    ldi     temp, 0x00
    out     PORTA, temp
    out     PORTB, temp
    out     PORTC, temp
    out     PORTD, temp
    out     PORTE, temp
    out     PORTF, temp
    out     PORTG, temp
    
    ; set A-G as output
    ldi     temp, 0xff
    out     DDRA, temp
    out     DDRB, temp
    out     DDRC, temp
    out     DDRD, temp
    out     DDRE, temp
    out     DDRF, temp
    out     DDRG, temp

    ; configure timer 1
    ; set to ctc mode
    ;ldi     temp, (1<<WGM12)
    ;sts     TCCR1B, temp
    ; set output compare register A
    ldi     temp, lo8(1250)
    sts     OCR1AL, temp
    ldi     temp, hi8(1250)
    sts     OCR1AH, temp
    ; init timer counter register
    ldi     temp, 0x00
    sts     TCNT1L, temp
    sts     TCNT1H, temp
    ; enable output compare interrupt A
    lds     temp, TIMSK1
    ori     temp, (1<<OCIE1A)
    sts     TIMSK1, temp
    ; set to ctc mode and start clock with 256 prescaler
    lds     temp, TCCR1B
    ori     temp, (1<<WGM12)|(1<<CS12)
    sts     TCCR1B, temp

    ; init variables
    ldi     port, 0
    ldi     state, 0x00

    ;ldi     temp, 0xff
    ;out     PORTA, temp

    ldi     help0, 0
    ldi     help1, 1

    ; enable interrupts
    sei

loop:
    sleep
    rjmp    loop

isr:
    in      PORTA, temp
    com     temp
    out     PORTA, temp
    reti

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
    in      temp, PORTA
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTA, temp
    cpi     temp, 0x00
    breq    reset_state
    cpi     temp, 0xff
    breq    set_state
    rjmp    next_port
reset_state:
    ldi     state, 0x00
    rjmp    next_port
set_state:
    ldi     state, 0x01
    rjmp    next_port
portb:
    in      temp, PORTB
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTB, temp
    rjmp    next_port
portc:
    in      temp, PORTC
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTC, temp
    rjmp    next_port
portd:
    in      temp, PORTD
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTD, temp
    rjmp    next_port
porte:
    in      temp, PORTE
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTE, temp
    rjmp    next_port
portf:
    in      temp, PORTF
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTF, temp
    rjmp    next_port
portg:
    in      temp, PORTG
    lsl     temp
    cpse    state, help1
    inc     temp
    out     PORTG, temp
next_port:
    cpi     port, 6
    breq    reset_port
    inc     port
    reti
reset_port:
    ldi     port, 0x00
    reti


