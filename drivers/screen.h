#ifndef _screen_h
#define _screen_h

#define DEFAULT_COLOR 0x07

#define CTRL_PORT 0x3d4
#define DATA_PORT 0x3d5

void clear_screen();
void putc(char c);
void puts(char *s);
void update_cursor();

#endif
