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
#include <stdint.h>

/* GPIO base address */
#define RPI_GPIO_BASE       (RPI_PERIPHERAL_BASE + 0x200000UL)

/* GPIO Function Select index */
#define RPI_GPIO_GPFSEL0    0UL
#define RPI_GPIO_GPFSEL1    1UL
#define RPI_GPIO_GPFSEL2    2UL
#define RPI_GPIO_GPFSEL3    3UL
#define RPI_GPIO_GPFSEL4    4UL
#define RPI_GPIO_GPFSEL5    5UL

/* GPIO Set index */
#define RPI_GPIO_GPSET0     7UL
#define RPI_GPIO_GPSET1     8UL

/* GPIO Clear index */
#define RPI_GPIO_GPCLR0     10UL
#define RPI_GPIO_GPCLR1     11UL

/* GPIO Pin Level index */
#define RPI_GPIO_GPLEV0     13UL
#define RPI_GPIO_GPLEV1     14UL

/* GPIO Pin Event Detect Status index */
#define RPI_GPIO_GPEDS0     16UL
#define RPI_GPIO_GPEDS1     17UL

/* GPIO Pin Rising Edge Detect Enable index */
#define RPI_GPIO_GPREN0     19UL
#define RPI_GPIO_GPREN1     20UL

/* GPIO Pin Falling Edge Detect Enable index */
#define RPI_GPIO_GPFEN0     22UL
#define RPI_GPIO_GPFEN1     23UL

/* GPIO Pin High Detect Enable index */
#define RPI_GPIO_GPHEN0     25UL
#define RPI_GPIO_GPHEN1     26UL

/* GPIO Pin High Detect Enable index */
#define RPI_GPIO_GPLEN0     28UL
#define RPI_GPIO_GPLEN1     29UL

/* GPIO Pin Async Rising Edge Detect index */
#define RPI_GPIO_GPAREN0    31UL
#define RPI_GPIO_GPAREN1    32UL

/* GPIO Pin Async Rising Edge Detect index */
#define RPI_GPIO_GPAFEN0    34UL
#define RPI_GPIO_GPAFEN1    35UL

/* GPIO Pin Pull-up/down Enable index */
#define RPI_GPIO_GPPUD      37UL

/* GPIO Pin Pull-up/down Enable Clock index */
#define RPI_GPIO_GPPUDCLK0  38UL
#define RPI_GPIO_GPPUDCLK1  39UL

/* Function Select values */
#define RPI_GPIO_GPFSEL_IN   0UL
#define RPI_GPIO_GPFSEL_OUT  1UL
#define RPI_GPIO_GPFSEL_AF0  4UL
#define RPI_GPIO_GPFSEL_AF1  5UL
#define RPI_GPIO_GPFSEL_AF2  6UL
#define RPI_GPIO_GPFSEL_AF3  7UL
#define RPI_GPIO_GPFSEL_AF4  3UL
#define RPI_GPIO_GPFSEL_AF5  2UL

/* Pull-up/down values */
#define RPI_GPIO_GPPUD_OFF   0UL
#define RPI_GPIO_GPPUD_DW    1UL
#define RPI_GPIO_GPPUD_UP    2UL

/* ACT LED */
#define RPI_ACT_LED_GPFSEL   RPI_GPIO_GPFSEL4
#define RPI_ACT_LED_GPFBIT   21UL
#define RPI_ACT_LED_GPSET    RPI_GPIO_GPSET1
#define RPI_ACT_LED_GPCLR    RPI_GPIO_GPCLR1
#define RPI_ACT_LED_GPSBIT   15UL

/**
 * @return GPIO base address
 */
uint32_t* rpi_gpio_get(void);

/**
 * Init GPIO for the ACT LED.
 */
void rpi_act_led_init(void);
/**
 * Lights on the ACT LED.
 */
void rpi_act_led_on(void);

/**
 * Lights off the ACT LED.
 */
void rpi_act_led_off(void);

#endif /* RPI_GPIO_H */
