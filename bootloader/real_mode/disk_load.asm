[bits 16]

; Loads dh sectors from drive dl to es:bx
disk_load:
	push dx

	mov ah, 0x02	; interrupt code
	mov al, dh	; amount of sectors to read
	mov ch, 0x0	; cylinder 0
	mov dh, 0x0	; head 0
	mov cl, 0x2	; sector 2 and after

	int 0x13

	jc disk_error

	pop dx

	cmp dh, al
	jne disk_error

	ret

disk_error:
	mov bx, DISK_ERROR_MSG
	call print_string

	jmp $

DISK_ERROR_MSG:
	db 'Disk read error!', 0
