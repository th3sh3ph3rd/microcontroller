; digio: basic digital I/O

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

; LED
.equ LED0,  PA7

; Temp registers
.equ temp0, 0x10
.equ temp1, 0x11
.equ temp2, 0x12
.equ temp3, 0x13
.equ state, 0x14

.text

.org 0x0000
    rjmp    main
.org INT6addr*2
    rjmp    isr

.text

; This is the main program.
main: 
    ; init stack pointer
    ldi     temp0, lo8(RAMEND)
    out     SPL, temp0
    ldi     temp0, hi8(RAMEND)
    out     SPH, temp0
   
    ; disable pull-up for inputs and set outputs low
    ldi     temp0, 0x00
    out     DDRE, temp0 ; set E as input 
    out     PORTA, temp0
    
    ; set 0-3 as input, 4-7 as output
    ldi     temp0, 0xf0
    out     DDRA, temp0

    ; enable pull-up for interrupt
    ldi     temp0, (1<<PE6)
    out     PORTE, temp0

    ; set falling edge on interrupt 6
    lds     temp0, EICRB
    ori     temp0, (1<<ISC61)
    sts     EICRB, temp0

    ; enable interrupt 6
    in      temp0, EIMSK
    ori     temp0, (1<<INT6)
    out     EIMSK, temp0

    ; init state
    ldi     state, 0x00

    ; enable interrupts
    sei

loop:
    ldi     temp1, 0x00
    ldi     temp2, 0x00
    in      temp0, PINA

    cpi     state, 0x03
    breq    state3
    cpi     state, 0x02
    breq    state2
    cpi     state, 0x01
    breq    state1

state0:                     ; LED0 := (PA1 & PA2) | PA3
    bst     temp0, PINA1
    bld     temp1, LED0
    bst     temp0, PINA2
    bld     temp2, LED0
    and     temp1, temp2
    bst     temp0, PINA3
    bld     temp2, LED0
    or      temp1, temp2
    rjmp    output

state1:                     ; LED0 := (PA1 | ~PA2) & PA3
    bst     temp0, PINA1
    bld     temp1, LED0
    ldi     temp2, 0x00     ; neutral init for or
    bst     temp0, PINA2
    bld     temp2, LED0
    ldi     temp3, (1<<LED0)
    eor     temp2, temp3    ; toggle bit
    or      temp1, temp2
    ldi     temp2, 0xff     ; neutral init for and
    bst     temp0, PINA3
    bld     temp2, LED0
    and     temp1, temp2
    rjmp    output

state2:                     ; LED0 := PA1 ^ PA2
    bst     temp0, PINA1
    bld     temp1, LED0
    ldi     temp2, 0x00     ; neutral init for xor
    bst     temp0, PINA2
    bst     temp2, LED0
    eor     temp1, temp2
    rjmp    output

state3:                     ; LED3 := PA1 = PA2
    ldi     temp2, (1<<LED0)
    eor     temp1, temp2    ; just toggle the xor result
    
output:                     ; write to the output register
    ldi     temp0, PORTA
    or      temp0, temp1
    out     PORTA, temp0

    rjmp    loop

isr:
    cpi     state, 0x03
    breq    rst
    inc     state
    reti
rst:
    ldi     state, 0x00
    reti

