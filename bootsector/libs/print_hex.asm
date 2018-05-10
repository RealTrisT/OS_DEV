
		;dx - value to print
print_hex_rm16:
	mov bx, dx				; bx - temp value
	shr bx, 12				; bx >>= 12
	add bx, 0x30			; bx += 0x30
	mov [HEX_OUT+2], bl		; printstring[2] = (char)bx
	mov bx, dx				; bx - temp value
	shr bx, 8				; bx >>= 8
	and bx, 0xf 			; bx &= 0xf
	add bx, 0x30			; bx += 0x30
	mov [HEX_OUT+3], bl		; printstring[3] = (char)bx
	mov bx, dx				; bx - temp value
	shr bx, 4				; bx >>= 4
	and bx, 0xf 			; bx &= 0xf
	add bx, 0x30			; bx += 0x30
	mov [HEX_OUT+4], bl		; printstring[4] = (char)bx
	mov bx, dx				; bx - temp value
	and bx, 0xf 			; bx &= 0xf
	add bx, 0x30			; bx += 0x30
	mov [HEX_OUT+5], bl		; printstring[5] = (char)bx

	cmp BYTE [HEX_OUT+2], 0x3A
	jl .index3
	add BYTE [HEX_OUT+2], 0x27
	.index3:
	cmp BYTE [HEX_OUT+3], 0x3A
	jl .index4
	add BYTE [HEX_OUT+3], 0x27
	.index4:
	cmp BYTE [HEX_OUT+4], 0x3A
	jl .index5
	add BYTE [HEX_OUT+4], 0x27
	.index5:
	cmp BYTE [HEX_OUT+5], 0x3A
	jl .finne
	add BYTE [HEX_OUT+5], 0x27
	.finne:

	mov si, HEX_OUT
	call print_string_rm16

	ret
	HEX_OUT db '0x0000', 0x0