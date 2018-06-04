[bits 16]
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


[bits 32]
    ; Define some constants
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f
    ; prints a null - terminated string pointed to by EDX
print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY+160           ; Set edx to the start of (second line) vid mem.

print_string_pm_loop:
    mov al, [ ebx ]                 ; Store the char at EBX in AL
    mov ah, WHITE_ON_BLACK          ; Store the attributes in AH
    cmp al, 0                       ; if (al == 0) , at end of string , so
    je print_string_pm_done         ; jump to done
    mov [edx], ax                   ; Store char and attributes at current
                                    ; character cell.
    add ebx, 1                      ; Increment EBX to the next char in string.
    add edx, 2                      ; Move to next character cell in vid mem.
    jmp print_string_pm_loop        ; loop around to print the next char.

print_string_pm_done:
    popa
    ret                             ; Return from the function

[bits 16]