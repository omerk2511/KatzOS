gdt_start:

gdt_null:
	dd 0x0 				; 4 NULL bytes
	dd 0x0 				; 4 NULL bytes

gdt_code:
	dw 0xffff 			; segment limit (bits 0-15)
	dw 0x0000 			; segment base (bit 0-15)
	db 0x00 			; segment base (bit 16-23)
	db 10011010b 			; Present = 1, DPL = 00, Type = 1,
					; Code = 1, Conforming = 0,
					; Readable = 1, Accessed = 0
	db 11001111b			; Granularity = 1, 32-bits = 1,
					; segment limit (bits 16-19) = 0x0f
	db 0x00 			; segment base (bits 24-31)

gdt_data:
	dw 0xffff 			; segment limit (bits 0-15)
	dw 0x0000 			; segment base (bit 0-15)
	db 0x00 			; segment base (bit 16-23)
	db 10010010b 			; Present = 1, DPL = 00, Type = 1,
					; Code = 0, Conforming = 0,
					; Readable = 1, Accessed = 0
	db 11001111b			; Granularity = 1, 32-bits = 1,
					; segment limit (bits 16-19) = 0x0f
	db 0x00 			; segment base (bits 24-31)

gdt_end:


gdt_descriptor:
	dw gdt_end - gdt_start - 1	; gdt size
	dd gdt_start			; gdt address


CODE_SEG equ gdt_code - gdt_start 	; code segment index (0x08)
DATA_SEG equ gdt_data - gdt_start 	; data segmnet index (0x10)
