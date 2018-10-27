	.file	"rand.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.data
	.type	lfsr, @object
	.size	lfsr, 2
lfsr:
	.word	1
	.text
.global	rand_shift
	.type	rand_shift, @function
rand_shift:
	push r28
	push r29
	rcall .
	rcall .
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 4 */
/* stack size = 6 */
.L__stack_usage = 6
	std Y+4,r24
	std Y+1,__zero_reg__
	ldi r24,lo8(-29)
	ldi r25,lo8(-128)
	std Y+3,r25
	std Y+2,r24
	lds r18,lfsr
	lds r19,lfsr+1
	ldd r21,Y+4
	ldd r24,Y+2
	ldd r25,Y+3
	ldd r20,Y+1
/* #APP */
 ;  30 "rand.c" 1
	in     __tmp_reg__, __SREG__
	cli
	bst    r18, 0
	bld    r20, 0
	lsr    r19
	ror    r18
	bst    r21, 0
	bld    r19, 7
	out    __SREG__, __tmp_reg__
	sbrs   r20, 0
	rjmp   L_end17
	eor    r18, r24
	eor    r19, r25
	L_end17:
	
 ;  0 "" 2
/* #NOAPP */
	std Y+1,r20
	ldd r24,Y+1
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	rand_shift, .-rand_shift
.global	rand_feed
	.type	rand_feed, @function
rand_feed:
	push r28
	push r29
	push __zero_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 1 */
/* stack size = 3 */
.L__stack_usage = 3
	std Y+1,r24
	ldd r24,Y+1
	rcall rand_shift
	nop
/* epilogue start */
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	rand_feed, .-rand_feed
.global	rand1
	.type	rand1, @function
rand1:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	ldi r24,0
	rcall rand_shift
/* epilogue start */
	pop r29
	pop r28
	ret
	.size	rand1, .-rand1
.global	rand16
	.type	rand16, @function
rand16:
	push r28
	push r29
	rcall .
	push __zero_reg__
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 3 */
/* stack size = 5 */
.L__stack_usage = 5
	std Y+2,__zero_reg__
	std Y+1,__zero_reg__
	std Y+3,__zero_reg__
	rjmp .L7
.L8:
	rcall rand1
	mov r24,r24
	ldi r25,0
	ldd r18,Y+3
	mov r18,r18
	ldi r19,0
	rjmp 2f
	1:
	lsl r24
	rol r25
	2:
	dec r18
	brpl 1b
	mov r18,r24
	mov r19,r25
	ldd r24,Y+1
	ldd r25,Y+2
	or r24,r18
	or r25,r19
	std Y+2,r25
	std Y+1,r24
	ldd r24,Y+3
	subi r24,lo8(-(1))
	std Y+3,r24
.L7:
	ldd r24,Y+3
	cpi r24,lo8(16)
	brlo .L8
	ldd r24,Y+1
	ldd r25,Y+2
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	rand16, .-rand16
	.ident	"GCC: (GNU) 5.4.0"
.global __do_copy_data
