/**
 * @file gpio.h
 * @brief Define and prototype for using BCM2836 GPIO.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef BCM2836_GPIO_H
#define BCM2836_GPIO_H

#include "address.h"
#include <stdint.h>

/**
 * GPIO structure.
 */
typedef struct {
    volatile uint32_t GPFSEL[6];
    volatile uint32_t _reserved1;
    volatile uint32_t GPSET[2];
    volatile uint32_t _reserved2;
    volatile uint32_t GPCLR[2];
    volatile uint32_t _reserved;
    volatile uint32_t GPLEV[2];
    volatile uint32_t _reserved3;
    volatile uint32_t GPEDS[2];
    volatile uint32_t _reserved4;
    volatile uint32_t GPREN[2];
    volatile uint32_t _reserved5;
    volatile uint32_t GPFEN[2];
    volatile uint32_t _reserved6;
    volatile uint32_t GPHEN[2];
    volatile uint32_t _reserved7;
    volatile uint32_t GPLEN[2];
    volatile uint32_t _reserved8;
    volatile uint32_t GPAREN[2];
    volatile uint32_t _reserved9;
    volatile uint32_t GPAFEN[2];
    volatile uint32_t _reserved10;
    volatile uint32_t GPPUD;
    volatile uint32_t GPPUDCLK[2];
} bcm2836_gpio_t;

/* GPIO base address */
#define BCM2836_GPIO_BASE           (BCM2836_PERIPHERAL_BASE + 0x200000UL)

/* Function Select values */
#define BCM2836_GPIO_GPFSEL_SIZE    3UL
#define BCM2836_GPIO_GPFSEL_IN      0UL
#define BCM2836_GPIO_GPFSEL_OUT     1UL
#define BCM2836_GPIO_GPFSEL_AF0     4UL
#define BCM2836_GPIO_GPFSEL_AF1     5UL
#define BCM2836_GPIO_GPFSEL_AF2     6UL
#define BCM2836_GPIO_GPFSEL_AF3     7UL
#define BCM2836_GPIO_GPFSEL_AF4     3UL
#define BCM2836_GPIO_GPFSEL_AF5     2UL

/* Pull-up/down values */
#define BCM2836_GPIO_GPPUD_SIZE     2UL
#define BCM2836_GPIO_GPPUD_OFF      0UL
#define BCM2836_GPIO_GPPUD_DW       1UL
#define BCM2836_GPIO_GPPUD_UP       2UL

/* ACT LED */
#define RPI_ACT_LED_GPFSEL          4
#define RPI_ACT_LED_GPFBIT          21UL
#define RPI_ACT_LED_GPSET           1
#define RPI_ACT_LED_GPCLR           1
#define RPI_ACT_LED_GPSBIT          15UL

/**
 * @return GPIO structure pointer.
 */
bcm2836_gpio_t* bcm2836_get_gpio(void);

/**
 * Initializes GPIO for the ACT LED.
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

#endif /* BCM2836_GPIO_H */