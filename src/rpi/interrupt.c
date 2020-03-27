#include "rpi/interrupt.h"

static rpi_irq_controller_t* irq = (rpi_irq_controller_t*) RPI_IRQ_CONTROLLER_BASE;

rpi_irq_controller_t* rpi_get_irq_controller(void) {
	return irq;
}
