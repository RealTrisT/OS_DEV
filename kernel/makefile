CC:=i386-elf-gcc
AC:=nasm
LINKR:=i386-elf-ld
LINKRSC:=linkerscript.ld
ASM:=bootloader_asm
SRC:=kernel_code
LIBS:=libs
OBJ:=obj

#SOURCES:=$(wildcard $(SRC)/*.c)
SOURCES:=$(shell find $(SRC)/ -type f -name '*.c')
LIBSRCS:=$(shell find $(LIBS)/ -type f -name '*.c')
ASMSRCS:=$(shell find $(ASM)/ -type f -name '*.asm')
OBJECTS:=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES)) $(patsubst $(LIBS)/%.c, $(OBJ)/%.o, $(LIBSRCS)) $(patsubst $(ASM)/%.asm, $(OBJ)/%.o, $(ASMSRCS))
OBJDIRS:=$(dir $(OBJECTS))
DUMMY:=$(shell mkdir --parents $(OBJDIRS))

$(OBJ)/%.o:$(ASM)/%.asm
	$(AC) -felf32 -o $@ $<

$(OBJ)/%.o:$(LIBS)/%.c
	$(CC) -ffreestanding -c $< -o $@

$(OBJ)/%.o:$(SRC)/%.c
	$(CC) -ffreestanding -c $< -o $@

kernel:$(OBJECTS)
	$(LINKR) -o $@ -T$(LINKRSC)$(OBJECTS)

