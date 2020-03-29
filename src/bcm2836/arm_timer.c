/**
 * @file arm_timer.c
 * @brief Source module for the ARM Timer of the BCM2836.
 * @author Dylan Gageot
 * @version 1.0
 * @date 2020-03-07
 */

#include "bcm2836/arm_timer.h"

static bcm2836_arm_timer_t* arm_timer = (bcm2836_arm_timer_t*) BCM2836_ARMTIMER_BASE;

bcm2836_arm_timer_t* bcm2836_get_arm_timer(void) {
	return arm_timer;
}

