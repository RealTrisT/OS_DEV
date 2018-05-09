
        ;16-bit real mode
print_string_rm16:       ; Expects null terminated message in si
    mov al,[si]
    or al,al
    jz  .end
    inc si
    call print_char_rm16
    jmp print_string_rm16
.end:
    retn

        ;16-bit real mode
print_char_rm16:
    mov ah,0x0E         ; Specifies that we want to write a character to the screen
    mov bl,0x07         ; Specifies output text color.  Not required, but useful to know
    mov bh,0x00         ; Page number.  Leave this alone.
    int 0x10            ; Signal video interrupt to BIOS
    retn