#include "../libs/TextModeConsole.h" 
#include "../libs/InterruptDescriptorTable.h"
#include "../libs/PIC.h"
#include "../libs/kernel_panic.h"
#include "../libs/inoutwait.h"

extern void __stiEnable();

void DivByZero_InterruptHandler(uint32_t EFLAGS, uint32_t CS, uint32_t EIP, uint32_t errcode){
	Print("KERNEL PANIC: Division By Zero Exception At "); PrintHex(EIP); Print("\n");
	Hang();
}

void KeyboardIRQ(){
	Print("KB IRQ\n");
	while(inb(0x64) & 1){
		Print(":");
		PrintHex(inb(0x60));
		Print(":");
	}Print("\n-------\n");
}

void entryPoint(){
	conState.xmax = 80;
	conState.ymax = 25;
	Clear();

	Print("Booted\n");

	InitIDT();
	SetExceptionInterruptHandler(0, DivByZero_InterruptHandler);

	Print("IDT Initialized and Exception Interrupts Set\n");

	PIC_remap(32, 40);

	Print("PIC Remapped\n");

	SetIRQInterruptHandler(1, KeyboardIRQ);
	__stiEnable();


	//int i = 3/0;
	return;
}