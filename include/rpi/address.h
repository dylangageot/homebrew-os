#ifndef RPI_ADDRESS_H
#define RPI_ADDRESS_H

/* GPIO base address */
#define GPIO_BASE 0x3F200000UL

/* GPIO Function Select index */
#define GPIO_GPFSEL0 0
#define GPIO_GPFSEL1 1
#define GPIO_GPFSEL2 2
#define GPIO_GPFSEL3 3
#define GPIO_GPFSEL4 4
#define GPIO_GPFSEL5 5

/* GPIO Set index */
#define GPIO_GPSET0 7
#define GPIO_GPSET1 8

/* GPIO Clear index */
#define GPIO_GPCLR0 10
#define GPIO_GPCLR1 11

/* ACT LED GPIO */
#define LED_GPFSEL GPIO_GPFSEL4
#define LED_GPFBIT 21
#define LED_GPSET GPIO_GPSET1
#define LED_GPCLR GPIO_GPCLR1
#define LED_GPSBIT 15

/* System Timer base address */
#define TIMER_BASE_ADDR 0x3F003000UL

#endif /* RPI_ADDRESS_H */
