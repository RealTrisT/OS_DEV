gcc -ffreestanding -c code/stub.c -o kernel.o
objcopy -j .text -O binary kernel.o ../storage/KERNEL.bin
pause