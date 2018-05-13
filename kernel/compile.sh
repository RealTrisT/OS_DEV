#!/bin/bash

gcc -m32 -ffreestanding -c code/kernel.c -o kernel.o
ld -m elf_i386 -o ../storage/KERNEL.bin -Tlinkerscript.ld