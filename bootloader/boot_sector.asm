[bits 16]
[org 0x7c00]

	mov bx, REAL_MODE_MSG
	call print_string

	jmp $

%include "real_mode/print_string.asm"

REAL_MODE_MSG:
	db 'Started in 16-bit Real Mode', 0

times 510-($-$$) db 0
dw 0xaa55
