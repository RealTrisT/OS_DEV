OUTPUT_FORMAT("binary")
ENTRY(asm_start)
SECTIONS
{
    . = 0x8000;

    .boot :
    {
        *(.asm_stuff)
    }
    .text :
    {
        sections_text = .;
        *(.text)
        sections_text_end = .;
    }

    .data :
    {
        sections_data = .;
        *(.data)
        *(.rodata)
        sections_data_end = .;
    }

    .bss :
    {
        sections_bss = .;
        *(COMMON)
        *(.bss)
        sections_bss_end = .;
    }
}