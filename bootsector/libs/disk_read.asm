	; load DH sectors to ES:BX from drive DL
	; al returns number of sectors read
disk_load :
	push dx 					; Store DX on stack so later we can recall
								; how many sectors were request to be read ,
								; even if it is altered in the meantime
	mov ah , 0x02 				; BIOS read sector function
	mov al , dh 				; Read DH sectors
	mov ch , 0x00 				; Select cylinder 0
	mov dh , 0x00 				; Select head 0
	mov cl , 0x02 				; Start reading from second sector ( i.e.
								; after the boot sector )
	int 0x13 					; BIOS interrupt
	jc disk_fail 				; Jump if error ( i.e. carry flag set )
	pop dx 						; Restore DX from the stack
	cmp dh , al 				; if AL ( sectors read ) != DH ( sectors expected )
	jne disk_error2				; display error message
	ret
disk_fail:						; if it failed
	pop dx
	cmp dh , al 				; and they're not the same
	je disk_error 				; prob means that there was no more to read
	cmp al, 0					; if no sectors were read
	je disk_error 				; big time fuckup
	ret 						; so it's fine, return

disk_error :					; if it was the same
	mov si , DISK_ERROR_MSG
	jmp disk_errorp				
disk_error2:
	mov si , DISK_ERROR_MS2
disk_errorp:
	call print_string_rm16
	jmp $


		; Variables
DISK_ERROR_MSG db "Disk read error!" , 0
DISK_ERROR_MS2 db "Disk read short!" , 0