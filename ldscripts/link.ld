/* Author: Dylan Gageot (dgageot@insa-rennes.fr)
 * Description: 
 * 	Linker script for bare metal programming onto a Raspberry Pi 2.
 */

/* CONSTANTS _______________________________________________________________ */

/* Default stack size equal 32K. If more space is needed, the stack need to be 
 * moved elsewhere because the stack is followed by the entry point. */
__stack_size__ = 32K;

/* _________________________________________________________________________ */

ENTRY(_start)

MEMORY {
	/* 1GB RAM (on-board DDR) */
	ram : ORIGIN = 0x00000000, LENGTH = 0x40000000
}

SECTIONS {

	/* The stack is placed at the origin of RAM. */
	__stack_start__ = .;
	.stack 0x0 (NOLOAD) : {
		. = __stack_size__;
	} >ram
	__stack_end__ = .;

	/* Executable codes are placed at address 0x00008000. */
	.text 0x8000 : { 
		/* Place .text.start at the beginning to set up the C-Runtime. */
		*(.text.start)
		*(.text*) 
	} >ram

	/* Data are placed behind executable codes. */
	.data : { 
		*(.data*) 
	} >ram
	
	/* Read-only data */
	.rodata : {
		*(.rodata*)
	} >ram

	/* Zeroed data are place behind casual data. */
	__bss_start__ = .;
	.bss (NOLOAD) : { 
		*(.bss*) *(COMMON) 
	} >ram
	__bss_end__ = .;

	/* Discard every other sections */
	/DISCARD/ : { *(*) }
}
