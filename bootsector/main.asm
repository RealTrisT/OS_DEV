[BITS 16]
[org 0x7C00]

start:
    mov [BOOT_DRIVE], dl
    mov bp, 0x8000
    mov sp, bp

                        ; read
    mov dh, 0x19         ; 19 sectors    (10kb total with the stub)
    ;mov es, 0           ; no segment
    mov bx, BOOTLOADER_ADDR ; to the defined kernel address
    mov dl, [BOOT_DRIVE]; from this drive
    call disk_load

    jmp BOOTLOADER_ADDR               ; Note that we never return from here.

%include "libs/disk_read.asm"
%include "libs/print_string.asm"

;data
    BOOTLOADER_ADDR equ 0x8000

    global BOOT_DRIVE
    BOOT_DRIVE db 0x0


TIMES 510 - ($ - $$) db 0
DW 0xAA55