/**
 * @file address.h
 * @brief Define for base address of the BCM2836.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef BCM2836_ADDRESS_H
#define BCM2836_ADDRESS_H

/* Peripheral base address */
#define BCM2836_PERIPHERAL_BASE     0x3F000000UL

/* System Timer base address */
#define BCM2836_TIMER_BASE          (BCM2836_PERIPHERAL_BASE + 0x3000UL)

#endif /* BCM2836_ADDRESS_H */
