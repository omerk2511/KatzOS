[bits 16]
[org 0x7c00]

KERNEL_OFFSET equ 0x1000

	mov [BOOT_DRIVE], dl

	mov bp, 0x9000
	mov sp, bp

	mov bx, REAL_MODE_MSG
	call print_string

	call load_kernel

	call switch_to_pm

%include "bootloader/real_mode/print_string.asm"
%include "bootloader/real_mode/disk_load.asm"
%include "bootloader/protected_mode/switch_to_pm.asm"
%include "bootloader/protected_mode/gdt.asm"
%include "bootloader/protected_mode/print_string_pm.asm"

[bits 16]

load_kernel:
	mov bx, LOAD_KERNEL_MSG
	call print_string

	mov bx, KERNEL_OFFSET
	mov dh, 1
	mov dl, [BOOT_DRIVE]

	call disk_load

	ret


[bits 32]

begin_pm:
	mov ebx, PROT_MODE_MSG
	call print_string_pm

	call KERNEL_OFFSET

	jmp $


BOOT_DRIVE:
	db 0

REAL_MODE_MSG:
	db 'Started in 16-bit Real Mode', 13, 10, 0

LOAD_KERNEL_MSG:
	db 'Loading kernel into memory', 13, 10, 0

PROT_MODE_MSG:
	db 'Successfully landed in 32-bit Protected Mode', 0

times 510-($-$$) db 0
dw 0xaa55
