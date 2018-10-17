; demo: lcd usage

.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp,       16
.equ    busycnt,    17
.equ    counter0,   28
.equ    counter1,   29

.equ    param1,     24
.equ    param2,     25
.equ    param3,     26

.section .text
.org 0x00
    rjmp   main

.section .text
Hello:
    .asciz    "Hello World"   ; be aware here, always use an odd number of characters

busy_wait:
    ldi     busycnt, 10
redo:
    call    busy_wait_0
    dec     busycnt
    tst     busycnt
    brne    redo
    ret
busy_wait_0:
    push    temp
    ldi     temp, 0x00
busy_wait_1:
    nop
    nop
    nop
    nop
    dec     temp
    brne    busy_wait_1
    pop     temp
    dec     temp
    brne    busy_wait_0
    ret

; This is the main program.
main:
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ldi     temp, 0xFF
    out     DDRA, temp
    out     PORTA, temp
    
    call    initLCD
    
    ldi     counter0, 0x00
    ldi     counter1, 0x00
    
infinite_loop:
    adiw    counter0, 1
    out     PORTA, counter0
    
    call    clearScreen
    
    ; prepare function call
    ldi     param1, (1<<7)          ; x | (y<<7) position
    ldi     ZL, lo8(Hello)          ; lower address of string
    ldi     ZH, hi8(Hello)          ; higher address of string
    call    dispStrPMEM             ; display string
    
    ; prepare function call
    ldi     param1, 15 | (1<<7)     ; x | (y<<7) position
    mov     param2, counter0        ; character to display
    call    dispChar                ; display character
    
    ; prepare function call
    ldi     param1, 3               ; x | (y<<7) position
    mov     param2, counter0        ; lo(value) to display
    mov     param3, counter1        ; hi(value) to display
    call    dispUint16              ; display number
    
    call    busy_wait
    call    busy_wait
    
    jmp     infinite_loop

