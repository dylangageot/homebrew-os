/**
 * @file interrupt.h
 * @brief Define and prototype for using BCM2836 interrupt.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef BCM2836_INTERRUPT_H
#define BCM2836_INTERRUPT_H

#include "address.h"
#include <stdint.h>

/* Interrupt base address */
#define BCM2836_IRQ_CONTROLLER_BASE		    (BCM2836_PERIPHERAL_BASE + 0xB200UL)

#define BCM2836_BASIC_ARM_TIMER_IRQ         (1UL << 0UL)
#define BCM2836_BASIC_ARM_MAILBOX_IRQ       (1UL << 1UL)
#define BCM2836_BASIC_ARM_DOORBELL_0_IRQ    (1UL << 2UL)
#define BCM2836_BASIC_ARM_DOORBELL_1_IRQ    (1UL << 3UL)
#define BCM2836_BASIC_GPU_0_HALTED_IRQ      (1UL << 4UL)
#define BCM2836_BASIC_GPU_1_HALTED_IRQ      (1UL << 5UL)
#define BCM2836_BASIC_ACCESS_ERROR_1_IRQ    (1UL << 6UL)
#define BCM2836_BASIC_ACCESS_ERROR_0_IRQ    (1UL << 7UL)

/**
 * IRQ Controller structure.
 */
typedef struct {
	volatile uint32_t IRQ_Basic_Pending;
	volatile uint32_t IRQ_Pending[2];
	volatile uint32_t FIQ_Control;
	volatile uint32_t IRQ_Enable[2];
	volatile uint32_t IRQ_Basic_Enable;
	volatile uint32_t IRQ_Disable[2];
	volatile uint32_t IRQ_Basic_Disable;
} bcm2836_irq_controller_t;

/**
 * @return IRQ controller structure pointer.
 */
bcm2836_irq_controller_t* bcm2836_get_irq_controller(void);

/**
 * Enables interrupts.
 */
void bcm2836_irq_enable(void);

#endif /* BCM2836_INTERRUPT_H */
