extern entryPoint
section .asm_stuff
global asm_start

				INIT_STACK_PTR equ 0x90000

;--------------------------------------------------->
asm_start:						;first thing in the binary, bootsector code jumps here
	[bits 16]					;---------------------------------------------> 16 bit real mode


	call BootLoad16 			; do the boot load routine in 16-bit real mode


	call switch_to_pm			; switches to protected mode -----------------> switching
	[bits 32]					;---------------------------------------------> 32 bit protected mode
	BEGIN_PM:					; switch_to_pm jumps to BEGIN_PM
	call BootLoad32 			; do the boot load routine in 32-bit protected mode
	mov ebp, INIT_STACK_PTR		; make ebp the stack we want
    mov esp, ebp				; make the stack pointer ebp aka the stack we want, it's the stack we want! xd
    call entryPoint				; jump to the entry point of the bootloader
    jmp $ 
;---------------------------------------------------<

hellomessage db "fuck off", 0xa, 0xd, 0
goodbmessage db "BITCHASS", 0xa, 0xd, 0

[bits 16]
%include "bootloader_asm/libs/print_string.asmi"
%include "bootloader_asm/libs/print_hex.asmi"
%include "bootloader_asm/libs/rm16_to_pm32.asmi"
%include "bootloader_asm/bootloader16.asmi"
[bits 32]
%include "bootloader_asm/bootloader32.asmi"