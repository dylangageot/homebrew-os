/**
 * @file arm_timer.c
 * @brief Source module for the ARM Timer of the BCM2836.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */

#include "rpi/arm_timer.h"

static rpi_arm_timer_t* rpi_arm_timer = (rpi_arm_timer_t*) RPI_ARMTIMER_BASE;

rpi_arm_timer_t* rpi_get_arm_timer(void) {
	return rpi_arm_timer;
}

