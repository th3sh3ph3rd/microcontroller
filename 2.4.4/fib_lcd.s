
.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp, 16
.equ    cntLo, 17
.equ    cntHi, 18
.equ    fibLo, 19
.equ    fibHi, 20

.equ    fcntLo, 21
.equ    fcntHi, 22
.equ    f0Lo, 23
.equ    f0Hi, 24
.equ    f1Lo, 25
.equ    f1Hi, 26
.equ    tempLo, 27
.equ    tempHi, 28

.equ    param1, 24
.equ    param2, 25
.equ    param3, 26

.section .text
.org 0x00
    rjmp    main
.org INT0addr*2
    rjmp    isr
.section .text

isr:
    in      temp, SREG
    
    call    fib
    
    ldi     param1, 11
    mov     param2, fibLo
    mov     param3, fibHi
    call    dispUint16
    
    ldi     temp, 1
    add     cntLo, temp
    clr     temp
    adc     cntHi, temp

    out     SREG, temp  
    reti

fib:
    ldi     fcntLo, 0
    ldi     fcntHi, 0
    ldi     f0Lo, 1
    ldi     f0Hi, 0
    ldi     f1Lo, 1
    ldi     f1Hi, 0

fib_loop:
    cp      fcntLo, cntLo
    cpc     fcntHi, cntHi
    breq    end_loop

calc_fib:
    mov     tempLo, f1Lo
    mov     tempHi, f1Hi

    add     f1Lo, f0Lo
    adc     f1Hi, f0Hi

    mov     f0Lo, tempLo
    mov     f0Hi, tempHi

    ldi     temp, 1
    add     fcntLo, temp
    clr     temp
    adc     fcntHi, temp

    rjmp    fib_loop

end_loop:
    mov     fibLo, f1Lo
    mov     fibHi, f1Hi
    ret
    
main:
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp

    ldi     temp, (1<<PD0)
    out     PORTD, temp

    ldi     temp, (1<<ISC00)
    sts     EICRA, temp
    ldi     temp, (1<<INT0)
    out     EIMSK, temp

    call    initLCD

    ldi     cntLo, 0
    ldi     cntHi, 0
    ldi     fibLo, 0
    ldi     fibHi, 0

    sei

; TODO change from busy waiting to timer
main_loop:
    sleep
    rjmp main_loop

