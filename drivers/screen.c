#include "screen.h"
#include "../kernel/io.h"

unsigned char *video_memory = (unsigned char *) 0xb8000;
int row = 0, col = 0;

void clear_screen()
{
	for(int i = 0; i < 80 * 25 * 2; i += 2) {
		video_memory[i] = ' ';
		video_memory[i + 1] = DEFAULT_COLOR;
	}

	row = 0;
	col = 0;

	update_cursor();
}

void putc(char c)
{
	if(c >= 0x20 && c < 0x7f) {
		video_memory[(row * 80 + col) * 2] = c;
		video_memory[(row * 80 + col) * 2 + 1] = DEFAULT_COLOR;

		col++;

		if(col == 80) {
			col = 0;
			row++;
		}
	} else {
		switch(c) {
			case 0x0a: // '\n'
				col = 0;
				row++;				

				break;

			case 0x0d: // '\r'
				col = 0;
				break;
			
			case 0x09: // '\t'
				col += 4;

				if(col >= 80) {
					col = col % 80;
					row++;
				}

				break;

			case 0x08: // '\b'
				if(col > 0) {
					col--;
				} else if(row > 0) {
					col = 79;
					row--;
				}

				video_memory[(row * 80 + col) * 2] = ' ';

				break;
		}
	}

	// if(row == 25) screen scroll
	update_cursor();
}

void puts(char *s)
{
	for(int i = 0; s[i] != '\0'; i++) {
		putc(s[i]);
	}
}

void update_cursor()
{
	unsigned short offset = row * 80 + col;

	port_byte_out(CTRL_PORT, 0x0f); // lower byte of the offset
	port_byte_out(DATA_PORT, (unsigned char) (offset & 0xff));

	port_byte_out(CTRL_PORT, 0x0e); // higher byte of the offset
	port_byte_out(DATA_PORT, (unsigned char) (offset >> 8));
}
