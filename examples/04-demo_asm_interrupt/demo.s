.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp,       19

.text
.org 0x00
    jmp     main
.org INT6addr*2
    jmp     int6    ; PE6
.org INT7addr*2
    jmp     int7    ; PE7

.text
    
main:
    ; Initialize stack pointer
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ; Initialize ports
    ldi     temp, 0x00
    out     DDRE, temp
    out     PORTA, temp
    
    ldi     temp, 0xFF
    out     DDRA, temp
    
    ; Enable pull-up for interrupts
    ldi     temp, (1<<PE6) | (1<<PE7)
    out     PORTE, temp
    
    ; Enable external interrupt 6 & 7
    lds     temp, EICRB
    ori     temp, (1<<ISC61) | (1<<ISC71)
	sts     EICRB, temp
    
    in      temp, EIMSK
    ori     temp, (1<<INT6) | (1<<INT7)
    out     EIMSK, temp
    
    ; Load PORTA with a beautiful pattern
    ldi     temp, 0x55
    out     PORTA, temp
    
    ; Enable sleep mode
    ldi     temp, (1<<SE)
    out     SMCR, temp
    
    ; Enable interrupts
    sei
    
infinite_loop:
    ; Sleep a while
    sleep
    rjmp    infinite_loop

int6:
    ; Load PORTA with pattern 1
    ldi     temp, 0x0F
    out     PORTA, temp
    reti

int7:
    ; Load PORTA with pattern 2
    ldi     temp, 0xF0
    out     PORTA, temp
    reti

