/**
 * Author: Dylan Gageot
 * Description:
 * 	First code to be executed once loaded in RAM.
 *	Initialize interrupt vector, call _reset_, set stack pointer and 
 *	call _cstartup.
 */

// Code section.
.section ".text.start"

// Symbol declaration.
.global _start

_start:
	ldr	pc, reset_h
	ldr	pc, undefined_instruction_h
	ldr	pc, software_interrupt_h
	ldr	pc, prefetch_abort_h
	ldr	pc, data_abort_h
	ldr	pc, unused_h
	ldr	pc, interrupt_h
	ldr	pc, fast_interrupt_h

reset_h:			.word  	_reset
undefined_instruction_h: 	.word 	undefined_instruction_vector
software_interrupt_h: 		.word 	software_interrupt_vector
prefetch_abort_h: 		.word 	prefetch_abort_vector
data_abort_h: 			.word 	_reset
unused_h: 			.word 	_reset
interrupt_h: 			.word 	interrupt_vector
fast_interrupt_h: 		.word 	fast_interrupt_vector

_reset:
	mov 	r0,	#0x8000
	mcr	p15, 	4,	r0,	c12,	c0,	0
_stack_init:
	// Initialize the stack pointer to 0x8000 (32kB of memory avalaible)
	mov	sp,	#0x8000
	b	_cstartup

_inf_loop:
	b	_inf_loop

