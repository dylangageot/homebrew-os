extern int __bss_start__;
extern int __bss_end__;

extern int main(void);

void _cstartup(void) {

	int *bss = &__bss_start__;
	int *bss_end = &__bss_end__;

	while (bss < bss_end)
		*(bss++) = 0;

	main();

	while(1);
}
