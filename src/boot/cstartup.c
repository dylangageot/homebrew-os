/**
 * Author: Dylan Gageot
 * Description:
 * 	Initialize .bss.
 */

// Import symbol of start/end of .bss.
extern int __bss_start__;
extern int __bss_end__;

// Import symbol of the main function to call.
extern int main(void);

void _cstartup(void) {

	int *bss = &__bss_start__;
	int *bss_end = &__bss_end__;

	// Initialize to zero the whole .bss section.
	while (bss < bss_end)
		*(bss++) = 0;

	// Start the application.
	main();

	// Endless loop in case of main returns.
	while(1);
}
