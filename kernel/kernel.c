#include "../drivers/screen.h"

void main()
{
	clear_screen();

	char *kernel_message = "Started the kernel successfully!";
	// puts(kernel_message);

	putc('H');
	putc('e');
	putc('l');
	putc('l');
	putc('o');
	putc('\n');

	putc('W');
	putc('o');
	putc('r');
	putc('l');
	putc('d');
	putc('!');
}
