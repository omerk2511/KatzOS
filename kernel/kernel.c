#include "../drivers/screen.h"

void main()
{
	clear_screen();

	char *kernel_message = "Started the kernel successfully!\n";
	puts(kernel_message);
}
