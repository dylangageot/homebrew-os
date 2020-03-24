#include "rpi/gpio.h"
#include "rpi/delay.h"
#include "rpi/interrupt.h"
#include "rpi/arm_timer.h"

int main(void) {

	rpi_act_led_init();

	// Enable the timer IRQ
	rpi_get_irq_controller()->IRQ_Basic_Enable = RPI_BASIC_ARM_TIMER_IRQ;

	/* Setup the system timer interrupt */
	/* Timer frequency = Clk/256 * 0x400 */
	rpi_get_arm_timer()->Load = 0x4000;

	/* Setup the ARM Timer */
	rpi_get_arm_timer()->Control =
		RPI_ARMTIMER_CTRL_23BIT |
		RPI_ARMTIMER_CTRL_ENABLE |
		RPI_ARMTIMER_CTRL_INT_ENABLE |
		RPI_ARMTIMER_CTRL_PRESCALE_256;

	_enable_interrupts();

	while (1) {
		rpi_act_led_on();
		udelay(1e6);
		rpi_act_led_off();
		udelay(1e6);
	}

	return 0;
}
