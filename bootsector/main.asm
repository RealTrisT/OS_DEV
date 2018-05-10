[BITS 16]
[org 0x7C00]

start:
    mov [BOOT_DRIVE], dl
    mov bp, 0x8000
    mov sp, bp

                        ; read
    mov dh, 0x5         ; 5 sectors    (4kb)
    ;mov es, 0           ; no segment
    mov bx, KERNEL_ADDR ; to the defined kernel address
    mov dl, [BOOT_DRIVE]; from this drive
    call disk_load

    mov si,MSG_booted
    call print_string_rm16

    mov bp, 0x9000                  ; Set the stack.
    mov sp, bp


    call switch_to_pm               ; Note that we never return from here.

    jmp $

%include "libs/disk_read.asm"
%include "libs/print_string.asm"
%include "libs/print_hex.asm"
%include "libs/rm16_to_pm32.asm"

[bits 32]

BEGIN_PM :
    mov ebx , MSG_32Prot
    call print_string_pm            ; Use our 32 - bit print routine.

    mov ebp, INIT_STACK_PTR
    mov esp, ebp

    call KERNEL_ADDR                 ; go to our C kernel

    mov ebx , MSG_finish
    call print_string_pm            ; Use our 32 - bit print routine.

    jmp $                           ; Hang.

;data
    INIT_STACK_PTR equ 0x90000
    KERNEL_ADDR equ 0x8000

    MSG_booted db 'Booted',0x0D,0x0A,0
    MSG_32Prot db '32-BIT PROTECTED M0D3 BITCH', 0
    MSG_finish db 'Finished Running', 0
    BOOT_DRIVE db 0x0


TIMES 510 - ($ - $$) db 0
DW 0xAA55


;times 256 dw 0xdada
;times 256 dw 0xface