; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; LED
.equ LED0,  PA7

; Temp registers
.equ temp0, 0x10
.equ leden, 0x11

.text

.org 0x0000
    rjmp    main
.org INT0addr*2
    rjmp    isrint0
.org INT1addr*2
    rjmp    isrint1

.text

; This is the main program.
main: 
    ; init stack pointer
    ldi     temp0, lo8(RAMEND)
    out     SPL, temp0
    ldi     temp0, hi8(RAMEND)
    out     SPH, temp0
    
    ; set A,B,C as output
    ldi     temp0, 0xff
    out     DDRA, temp0
    out     DDRB, temp0
    out     DDRC, temp0

    ; enable pull-up for interrupts 0 and 1
    ldi     temp0, (1<<PD0)|(1<<PD1)
    out     PORTD, temp0

    ; set falling edge on interrupt 0 and 1
    lds     temp0, EICRA
    ori     temp0, (1<<ISC01)|(1<<ISC11)
    sts     EICRA, temp0

    ; enable interrupt 0 and 1
    in      temp0, EIMSK
    ori     temp0, (1<<INT0)|(1<<IN1)
    out     EIMSK, temp0

    ; put leds in initial state
    ldi     leden, 0x01
    out     PORTA, leden
    out     PORTB, leden
    out     PORTC, leden

    ; enable interrupts
    sei

loop:
    ; TODO modify to use sleep
    out     PORTA, leden
    out     PORTB, leden
    out     PORTC, leden
    rjmp    loop


isrint0:
    cpi     leden, 0x08
    breq    rst0
    lsl     leden
    reti
rst0:
    ldi     state, 0x01
    reti

isrint1:
    cpi     leden, 0x01
    breq    rst1
    lsr     leden
    reti
rst1:
    ldi     state, 0x08
    reti
    

