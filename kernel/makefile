CC:=i386-elf-gcc
AC:=nasm
LINKR:=i386-elf-ld
LINKRSC:=linkerscript.ld
ASM:=kernel_asm
SRC:=kernel_code
LIBS:=libs
OBJ:=obj

SOURCES:=$(wildcard $(SRC)/*.c)
LIBSRCS:=$(wildcard $(LIBS)/*.c)
ASMSRCS:=$(wildcard $(ASM)/*.asm)
OBJECTS:=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES)) $(patsubst $(LIBS)/%.c, $(OBJ)/%.o, $(LIBSRCS)) $(patsubst $(ASM)/%.asm, $(OBJ)/%.o, $(ASMSRCS))

$(OBJ)/%.o:$(ASM)/%.asm
	$(AC) -felf32 -o $@ $<

$(OBJ)/%.o:$(LIBS)/%.c
	$(CC) -ffreestanding -c $< -o $@

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -ffreestanding -c $< -o $@

kernel:$(OBJECTS)
	$(LINKR) -o $@ -T$(LINKRSC)$(OBJECTS)

