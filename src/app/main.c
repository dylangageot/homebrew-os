#include "rpi/uart.h"
#include "rpi/gpio.h"
#include "rpi/delay.h"
#include "rpi/interrupt.h"
#include "rpi/arm_timer.h"

int main(void) {

    rpi_act_led_init();
    rpi_act_led_off();

//    // Enable the timer IRQ
//    rpi_get_irq_controller()->IRQ_Basic_Enable = RPI_BASIC_ARM_TIMER_IRQ;
//
//    /* Setup the system timer interrupt */
//    /* Timer frequency = Clk/256 * 0x400 */
//    rpi_get_arm_timer()->Load = 0x4000000;
//
//    /* Setup the ARM Timer */
//    rpi_get_arm_timer()->Control =
//            RPI_ARMTIMER_CTRL_23BIT |
//            RPI_ARMTIMER_CTRL_ENABLE |
//            RPI_ARMTIMER_CTRL_INT_ENABLE |
//            RPI_ARMTIMER_CTRL_PRESCALE_256;
//
//    rpi_irq_enable();


    rpi_act_led_off();

    rpi_uart_init();

    char i = 0;
    char buffer[30];
    for (i = (char) 'a'; i <= (char) 'z'; ++i) {
        buffer[i - 'a'] = i;
    }

    rpi_uart_send_bytes((uint8_t*) buffer, 'z' - 'a' + 1);

    rpi_uart_send_hex_uint32(0xABCDEF79);

	return 0;
}
