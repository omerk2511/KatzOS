#include "screen.h"

unsigned char *video_memory = (unsigned char *) 0xb8000;

void clear_screen()
{
	for(int i = 0; i < 80 * 25 * 2; i += 2) {
		video_memory[i] = ' ';
		video_memory[i + 1] = DEFAULT_COLOR;
	}
}
