[bits 16]

; Prints a NULL-terminated strings that starts
; in the address mentioned in bx
print_string:
	pusha

	mov ah, 0x0e

print_string_loop:
	mov al, byte [bx]
	int 0x10

	inc bx

	cmp byte [bx], 0
	jne print_string_loop

	popa
	ret
