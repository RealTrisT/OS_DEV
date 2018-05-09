[BITS 16]
[org 0x7C00]

start:
    mov [BOOT_DRIVE], dl
    mov bp, 0x8000
    mov sp, bp

    mov si,MSG_booted
    call print_string_rm16

                        ; read
    mov dh, 0x5         ; 5 sectors
    ;mov es, 0           ; no segment
    mov bx, 0x9000      ; to 0x9000
    mov dl, [BOOT_DRIVE]; from this drive
    call disk_load

    mov si, MSG_firstsect
    call print_string_rm16
    mov dx, [0x9000]    ; print
    call print_hex_rm16 ; first word of second sector

    mov si, MSG_secndsect
    call print_string_rm16
    mov dx, [0x9200]    ; print
    call print_hex_rm16 ; first word of third sector


    jmp $

%include "libs/disk_read.asm"
%include "libs/print_string.asm"
%include "libs/print_hex.asm"

;data
    MSG_firstsect db 'First word from second section: ', 0x0
    MSG_secndsect db 0x0D, 0x0A, 'First word from third section: ', 0x0

    MSG_booted db 'Booted',0x0D,0x0A,0

    BOOT_DRIVE db 0x0


TIMES 510 - ($ - $$) db 0
DW 0xAA55


times 256 dw 0xdada
times 256 dw 0xface