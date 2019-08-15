[bits 16]

; Switches the system from 16-bit real mode
; to 32-bit protected mode
switch_to_pm:
	cli

	lgdt [gdt_descriptor]

	mov eax, cr0
	or eax, 0x01
	mov cr0, eax

	jmp CODE_SEG:init_pm


[bits 32]

init_pm:
	mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov gs, ax
	mov fs, ax
	
	mov ebp, 0x90000
	mov esp, ebp

	call begin_pm
