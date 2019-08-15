[bits 16]
[org 0x7c00]

	mov bp, 0x9000
	mov sp, bp

	mov bx, REAL_MODE_MSG
	call print_string

	call switch_to_pm

%include "real_mode/print_string.asm"
%include "protected_mode/switch_to_pm.asm"
%include "protected_mode/gdt.asm"

[bits 32]

begin_pm:
	jmp $


REAL_MODE_MSG:
	db 'Started in 16-bit Real Mode', 0

times 510-($-$$) db 0
dw 0xaa55
