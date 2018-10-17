.NOLIST
.INCLUDE "m1280def.inc"
.LIST

.equ    temp,       16
.equ    cntLow,     17
.equ    cntHigh,    18

.text
.org 0x00
    rjmp    main
.org OC1Aaddr*2
    rjmp    timer

.text
    
main:
    ; Initialize stack pointer
    ldi     temp, lo8(RAMEND)
    out     SPL, temp
    ldi     temp, hi8(RAMEND)
    out     SPH, temp
    
    ; Initialize port
    ldi     temp, 0x00
    out     PORTA, temp
    out     PORTB, temp
    
    ldi     temp, 0xFF
    out     DDRA, temp
    out     DDRB, temp
    
    ; Initialize counter
    ldi     cntLow, 0x00
    ldi     cntHigh, 0x00
    
    ; Configure timer
    lds     temp, TCCR1B
    andi    temp, lo8(~(1<<(ICNC1) | 1<<(WGM13) | 1<<(ICES1) | 1<<(CS12) | 1<<(CS11) | 1<<(CS10)))
    sts     TCCR1B, temp
    
    lds     temp, TCCR1A
    andi    temp, lo8(~(1<<(COM1A1) | 1<<(COM1A0) | 1<<(COM1B1) | 1<<(COM1B0) | 1<<(COM1C1) | 1<<(COM1C0) | 1<<(WGM11) | 1<<(WGM10)))
    sts     TCCR1A, temp
    
    ldi     temp, hi8(((1000 * 16000000) / (1024 * 10000)) - 1)
    sts     OCR1AH, temp
    ldi     temp, lo8(((1000 * 16000000) / (1024 * 10000)) - 1)
    sts     OCR1AL, temp
    
    lds     temp, TIMSK1
    ori     temp, 1<<(OCIE1A)
    sts     TIMSK1, temp
    
    lds     temp, TCCR1B
    ori     temp, 1<<(CS12) | 1<<(CS10) | 1<<(WGM12)
    sts     TCCR1B, temp
    
    ; Enable sleep mode
    ldi     temp, (1<<SE)
    out     SMCR, temp
    
    ; Enable interrupts
    sei
    
infinite_loop:
    ; Sleep a while
    sleep
    rjmp    infinite_loop

timer:
    ; Function call
    push    cntHigh
    push    cntLow
    call    incrementU16
    pop     cntLow
    pop     cntHigh
    
    out     PORTA, cntLow
    out     PORTB, cntHigh
    
    reti

