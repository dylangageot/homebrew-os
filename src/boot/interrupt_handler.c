#include "rpi/arm_timer.h"
#include "rpi/gpio.h"
#include "rpi/delay.h"

void __attribute__((interrupt("UNDEF"))) undefined_instruction_vector(void) {
	rpi_act_led_off();
	while (1) {};
}

void __attribute__((interrupt("SWI"))) software_interrupt_vector(void) {
	rpi_act_led_off();
	while (1) {};
}

void __attribute__((interrupt("ABORT"))) prefetch_abort_vector(void) {
	rpi_act_led_off();
	while (1) {};
}

void __attribute__((interrupt("IRQ")))  interrupt_vector(void) {
	while (1) {
		rpi_act_led_on();
		udelay(5e5);
		rpi_act_led_off();
		udelay(5e5);
	}
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void) {
	rpi_act_led_off();
	while (1) {};
}
