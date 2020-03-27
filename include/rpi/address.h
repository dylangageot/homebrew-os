/**
 * @file address.h
 * @brief Define for base address of the BCM2836.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef RPI_ADDRESS_H
#define RPI_ADDRESS_H

/* Peripheral base address */
#define RPI_PERIPHERAL_BASE     0x3F000000UL

/* System Timer base address */
#define RPI_TIMER_BASE          (PERIPHERAL_BASE + 0x3000UL)

#endif /* RPI_ADDRESS_H */
