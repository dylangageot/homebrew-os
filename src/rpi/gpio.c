#include "rpi/gpio.h"
#include <stdint.h>

volatile uint32_t* gpio = (uint32_t*) RPI_GPIO_BASE;

void rpi_act_led_init(void) {
	gpio[RPI_LED_GPFSEL] = (1 << RPI_LED_GPFBIT);	
}

void rpi_act_led_on(void) {
	gpio[RPI_LED_GPSET] = (1 << RPI_LED_GPSBIT);	
}

void rpi_act_led_off(void) {
	gpio[RPI_LED_GPCLR] = (1 << RPI_LED_GPSBIT);	
}
