#include "bcm2836/interrupt.h"

static bcm2836_irq_controller_t* irq = (bcm2836_irq_controller_t*) BCM2836_IRQ_CONTROLLER_BASE;

bcm2836_irq_controller_t* bcm2836_get_irq_controller(void) {
	return irq;
}
