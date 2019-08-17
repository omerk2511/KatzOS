C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

OBJ = ${C_SOURCES:.c=.o}

all: katzos-image

run: all
	qemu-system-i386 katzos-image

katzos-image: bootloader/boot_sector.bin kernel.bin
	cat $^ > $@

kernel.bin: kernel/kernel_entry.o ${OBJ}
	ld -o $@ -Ttext 0x1000 $^ --oformat binary -m elf_i386

%.o: %.c ${HEADERS}
	gcc -m32 -ffreestanding -fno-pie -c $< -o $@

%.o: %.asm
	nasm -f elf32 $< -o $@

%.bin: %.asm
	nasm -f bin $< -o $@

clean:
	rm -rf *.bin *.o katzos-image
	rm -rf bootloader/*.bin kernel/*.o drivers/*.o
