/**
 * @file interrupt.h
 * @brief Define and prototype for using BCM2836 interrupt.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "address.h"
#include <stdint.h>

/* Interrupt base address */
#define RPI_IRQ_CONTROLLER_BASE		(RPI_PERIPHERAL_BASE + 0xB200UL)

#define RPI_BASIC_ARM_TIMER_IRQ         (1 << 0)
#define RPI_BASIC_ARM_MAILBOX_IRQ       (1 << 1)
#define RPI_BASIC_ARM_DOORBELL_0_IRQ    (1 << 2)
#define RPI_BASIC_ARM_DOORBELL_1_IRQ    (1 << 3)
#define RPI_BASIC_GPU_0_HALTED_IRQ      (1 << 4)
#define RPI_BASIC_GPU_1_HALTED_IRQ      (1 << 5)
#define RPI_BASIC_ACCESS_ERROR_1_IRQ    (1 << 6)
#define RPI_BASIC_ACCESS_ERROR_0_IRQ    (1 << 7)

/**
 * @brief Register structure of the interrupt controller.
 */
typedef struct {
	volatile uint32_t IRQ_Basic_Pending;
	volatile uint32_t IRQ_Pending[2];
	volatile uint32_t FIQ_Control;
	volatile uint32_t IRQ_Enable[2];
	volatile uint32_t IRQ_Basic_Enable;
	volatile uint32_t IRQ_Disable[2];
	volatile uint32_t IRQ_Basic_Disable;
} rpi_irq_controller_t;

/**
 * @brief Get the IRQ controller sctructure.
 *
 * @return Pointer to the IRQ controller structure.
 */
rpi_irq_controller_t* rpi_get_irq_controller(void);


/**
 * @brief Enable interrupts.
 */
void _enable_interrupts(void);

#endif /* INTERRUPT_H */
