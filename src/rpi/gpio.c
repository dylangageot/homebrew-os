#include "rpi/gpio.h"

static rpi_gpio_t* gpio = (rpi_gpio_t*) RPI_GPIO_BASE;

rpi_gpio_t* rpi_get_gpio(void) {
    return gpio;
}

void rpi_act_led_init(void) {
    gpio->GPFSEL[RPI_ACT_LED_GPFSEL] = 1UL << RPI_ACT_LED_GPFBIT;
}

void rpi_act_led_on(void) {
    gpio->GPSET[RPI_ACT_LED_GPSET] = 1UL << RPI_ACT_LED_GPSBIT;
}

void rpi_act_led_off(void) {
    gpio->GPCLR[RPI_ACT_LED_GPCLR] = 1UL << RPI_ACT_LED_GPSBIT;
}
