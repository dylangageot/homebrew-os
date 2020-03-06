/**
 * Author: Dylan Gageot
 * Description:
 * 	First code to be executed once loaded in RAM.
 *	Initialize stack pointer and call _cstartup.
 */

// Code section.
.section ".text.start"

// Symbol declaration.
.global _start

_start:
	// Initialize the stack pointer to 0x8000 (32kB of memory avalaible)
	mov	sp,	#0x8000
	b	_cstartup

_inf_loop:
	b	_inf_loop
