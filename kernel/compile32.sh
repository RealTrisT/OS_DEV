#!/bin/bash

i386-elf-gcc -ffreestanding -c code/kernelstart.c -o kernel.o
i386-elf-ld -m elf_i386 -o ../storage/KERNEL.bin -Tlinkerscript.ld