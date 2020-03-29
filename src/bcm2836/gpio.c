#include "bcm2836/gpio.h"

static bcm2836_gpio_t* gpio = (bcm2836_gpio_t*) BCM2836_GPIO_BASE;

bcm2836_gpio_t* bcm2836_get_gpio(void) {
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
