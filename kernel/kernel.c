void main()
{
	char *video_memory = (char *) 0xb8000;
	
	// Screen clearing
	for(int i = 0; i < 80 * 25 * 2; i += 2) {
		video_memory[i] = ' ';
		video_memory[i + 1] = 0x07;
	}

	// Basic message displaying
	char *kernel_message = "Started the kernel successfully!";
	
	for(int i = 0; kernel_message[i] != '\0'; i++) {
		video_memory[i * 2] = kernel_message[i];
	}
}
