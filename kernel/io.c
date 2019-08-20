// Recieves byte-long data from a specific I/O port
unsigned char port_byte_in(unsigned short port)
{
	unsigned char res = 0;

	__asm__("in %%dx, %%al" : "=a" (res) : "d" (port));

	return res;
}

// Outputs byte-long data to a specific I/O port
void port_byte_out(unsigned short port, unsigned char data)
{
	__asm__("out %%al, %%dx" : :"a" (data), "d" (port));
}
