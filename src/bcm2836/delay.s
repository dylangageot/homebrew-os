/*
 * Author: Dylan Gageot
 * Description:
 * 	This module provide basic functions to use the system timer.
 */

// Code section.
.section ".text"

// Symbol declarations.
.global bcm2836_system_timer_wait

// Constant defintions.
.equ TIMER_BASE, 0x3F003000

/* Wait for a given number of microseconds.
 * void bcm2836_system_timer_wait(unsigned int us);
 */
bcm2836_system_timer_wait:
	// Load Timer Base Address into r1.
	ldr r1, =TIMER_BASE
	// Initial counter value loaded into r2.
	ldr r2,	[r1, #4]

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
