.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp,       19
.equ    temp2,      20

.equ    param1,     24
.equ    param2,     25
.equ    param3,     26

.text
.org 0x00
    jmp     main

.text
    
main:
    ; Initialize stack pointer
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    ldi     temp, 0x00

    call    initKeypad
    call    initLCD
    
    ldi     param1, 0
    ldi     param2, 0
    ldi     param3, 0
    call    dispUint16
    
infinite_loop:
    call    getKey
    
    cp      temp, param1
    mov     temp, param1
    
    breq    infinite_loop
    
    call    keyToNum
    mov     param2, param1
    
    ldi     param1, 0
    ldi     param3, 0
    call    dispUint16
    
    mov     param1, temp
    call    keyToChar
    mov     param2, param1
    
    ldi     param1, (1<<7)
    call    dispChar
    
    rjmp    infinite_loop


