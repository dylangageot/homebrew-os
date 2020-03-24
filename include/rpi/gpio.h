/**
 * @file gpio.h
 * @brief Define and prototype for using BCM2836 GPIO.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef RPI_GPIO_H
#define RPI_GPIO_H

#include "address.h"

/* GPIO base address */
#define RPI_GPIO_BASE (RPI_PERIPHERAL_BASE + 0x200000UL)

/* GPIO Function Select index */
#define RPI_GPIO_GPFSEL0 0
#define RPI_GPIO_GPFSEL1 1
#define RPI_GPIO_GPFSEL2 2
#define RPI_GPIO_GPFSEL3 3
#define RPI_GPIO_GPFSEL4 4
#define RPI_GPIO_GPFSEL5 5

/* GPIO Set index */
#define RPI_GPIO_GPSET0 7
#define RPI_GPIO_GPSET1 8

/* GPIO Clear index */
#define RPI_GPIO_GPCLR0 10
#define RPI_GPIO_GPCLR1 11

/* ACT LED GPIO */
#define RPI_LED_GPFSEL RPI_GPIO_GPFSEL4
#define RPI_LED_GPFBIT 21
#define RPI_LED_GPSET RPI_GPIO_GPSET1
#define RPI_LED_GPCLR RPI_GPIO_GPCLR1
#define RPI_LED_GPSBIT 15

/**
 * @brief Init GPIO for the ACT LED.
 */
void rpi_act_led_init(void);
/**
 * @brief Lights on the ACT LED.
 */
void rpi_act_led_on(void);

/**
 * @brief Lights off the ACT LED.
 */
void rpi_act_led_off(void);

#endif /* RPI_GPIO_H */
