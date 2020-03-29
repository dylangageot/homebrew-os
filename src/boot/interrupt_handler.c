#include <bcm2836/arm_timer.h>
#include <bcm2836/uart.h>

void __attribute__((interrupt("UNDEF"))) undefined_instruction_vector(void) {

	while (1) {};
}

void __attribute__((interrupt("SWI"))) software_interrupt_vector(void) {

	while (1) {};
}

void __attribute__((interrupt("ABORT"))) prefetch_abort_vector(void) {

	while (1) {};
}

void __attribute__((interrupt("IRQ")))  interrupt_vector(void) {
    // Clear IRQ
	bcm2836_get_arm_timer()->IRQClear = 1;
	bcm2836_uart_send_byte('.');
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void) {

	while (1) {};
}
