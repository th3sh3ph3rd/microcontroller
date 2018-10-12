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
.equ help1, 0x13
.equ port_state, 0x14
.section .text

.global main
.org 0x0000
    rjmp    main
.org OC1Aaddr*2
    rjmp    tmrisr

.text

update_port: ; port_state contains current port value at return
    push    YH
    push    YL
    push    ZH
    push    ZL
    push    temp

    ; point Z to the SP
    in      YH, SPH
    in      YL, SPL

    ; point Z to the argument
    adiw    YL, 5 + 2 + 2

    ld      ZL, Y
    ld      ZH, -Y

    ld      port_state, Z
    lsl     port_state
    cpse    state, help1 ; TODO maybe beautify this smh
    inc     port_state
    st      Z, port_state

    pop     temp
    pop     ZL
    pop     ZH
    pop     YL
    pop     YH
 
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
    sts     PORTA, temp
    sts     PORTB, temp
    sts     PORTC, temp
    sts     PORTD, temp
    sts     PORTE, temp
    sts     PORTF, temp
    sts     PORTG, temp
    
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
    ldi     port, PORTA
    ldi     state, 0x00
    ldi     help1, 1

    ; enable interrupts
    sei

loop:
    sleep
    rjmp    loop

tmrisr:
    push    port
    clr     temp
    push    temp
    rcall   update_port
    pop     temp
    pop     temp
    
    cpi     port, PORTA
    brne    next_port
    cpi     port_state, 0x00
    breq    reset_state
    cpi     port_state, 0xff
    breq    set_state
    rjmp    next_port
reset_state:
    ldi     state, 0x00
    rjmp    next_port
set_state:
    ldi     state, 0x01
next_port:
    cpi     port, PORTF
    breq    rst_port
    subi    port, -3
    reti
rst_port:
    ldi     port, PORTA
    reti

