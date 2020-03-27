#include "rpi/gpio.h"

static uint32_t* gpio = (uint32_t*) RPI_GPIO_BASE;

uint32_t* rpi_gpio_get(void) {
    return gpio;
}

void rpi_act_led_init(void) {
    gpio[RPI_ACT_LED_GPFSEL] = 1UL << RPI_ACT_LED_GPFBIT;
}

void rpi_act_led_on(void) {
	gpio[RPI_ACT_LED_GPSET] = 1UL << RPI_ACT_LED_GPSBIT;
}

void rpi_act_led_off(void) {
	gpio[RPI_ACT_LED_GPCLR] = 1UL << RPI_ACT_LED_GPSBIT;
}
