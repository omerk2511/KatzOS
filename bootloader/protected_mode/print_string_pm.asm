[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

; Prints a NULL-terminated string that starts in the address
; written in ebx, in the top left corner of the screen
print_string_pm:
	pusha

	mov edx, VIDEO_MEMORY

print_string_pm_loop:
	mov al, byte [ebx]
	mov ah, WHITE_ON_BLACK

	mov word [edx], ax

	inc ebx
	add edx, 2

	cmp byte [ebx], 0
	jne print_string_pm_loop

	popa
	ret
