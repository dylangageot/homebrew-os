.section ".text.start"

.global _start

_start:
	mov	sp,	#0x8000
	b	_cstartup

_inf_loop:
	b	_inf_loop
