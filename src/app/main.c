#include "bcm2836/uart.h"
#include "bcm2836/gpio.h"
#include "bcm2836/delay.h"
#include "bcm2836/interrupt.h"
#include "bcm2836/arm_timer.h"

int main(void) {

    rpi_act_led_init();
    rpi_act_led_off();

    // Enable the timer IRQ
    bcm2836_get_irq_controller()->IRQ_Basic_Enable = BCM2836_BASIC_ARM_TIMER_IRQ;

    /* Setup the system timer interrupt */
    /* Timer frequency = Clk/256 * 0x400 */
    bcm2836_get_arm_timer()->Load = 0x400;

    /* Setup the ARM Timer */
    bcm2836_get_arm_timer()->Control =
            BCM2836_ARMTIMER_CTRL_23BIT |
            BCM2836_ARMTIMER_CTRL_ENABLE |
            BCM2836_ARMTIMER_CTRL_INT_ENABLE |
            BCM2836_ARMTIMER_CTRL_PRESCALE_256;

    bcm2836_irq_enable();

    rpi_act_led_off();

    bcm2836_uart_init();

    char i = 0;
    char buffer[30];
    for (i = (char) 'a'; i <= (char) 'z'; ++i) {
        buffer[i - 'a'] = i;
    }

    bcm2836_uart_send_bytes((uint8_t*) buffer, 'z' - 'a' + 1);

    bcm2836_uart_send_hex_uint32(0xABCDEF79);

    while (1) {
        bcm2836_uart_send_byte('-');
        bcm2836_system_timer_wait((uint32_t) 1e6);
    }

	return 0;
}
