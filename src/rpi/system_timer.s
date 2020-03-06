/*
 * Author: Dylan Gageot
 * Description:
 * 	This module provide basic functions to use the system timer.
 */

// Codes section.
.section ".text"

// Symbol declarations.
.global udelay

// Constant defintions.
.equ TIMER_BASE_ADDR, 0x3F003000

/* Wait for a given number of microseconds.
 * void udelay(unsigned int us);
 */
udelay:
	// Load Timer Base Address into r1.
	ldr 	r1, 	=TIMER_BASE_ADDR
	// Initial counter value loaded into r2.
	ldr 	r2,	[r1, #4]

	// Comparaison loop.
__delay_loop:
	// Load actual counter value into r3.
	ldr	r3,	[r1, #4]
	// Substract it with inital value.
	sub	r3,	r3,	r2
	// Compare to the amount of microseconds needed.
	cmp	r3,	r0
	// Branch if negative.
	bmi	__delay_loop
	
	// Return to calling program.
	mov	pc,	lr
