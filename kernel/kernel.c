#include "../drivers/screen.h"

void main()
{
	clear_screen();

	char *kernel_message = "Started the kernel successfully!\n";

	for(int i = 1; i <= 30; i++) {
		putc('[');
		putc((i / 10) + '0');
		putc((i % 10) + '0');
		puts("] ");
		puts(kernel_message);
	}
}
