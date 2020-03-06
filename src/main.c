#include "rpi/address.h"
#include "rpi/delay.h"
#include <stdlib.h>

volatile unsigned int* gpio = (unsigned int*) GPIO_BASE;

volatile unsigned int tim;

void LED_Set(char set);

int main(void) {

	// Init GPIO pin
	gpio[LED_GPFSEL] = (1 << LED_GPFBIT);


	while (1) {


		// Toggle LED on
		LED_Set(1);

		// Delay
		udelay(1000000);

		// Toggle LED off
		LED_Set(0);

		// Delay
		udelay(1000000);
	}

	return 0;
}

void LED_Set(char set) {
	if (set)
		gpio[LED_GPSET] = (1 << LED_GPSBIT);	
	else
		gpio[LED_GPCLR] = (1 << LED_GPSBIT);	
}
