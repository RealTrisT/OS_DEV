#include "kernel_panic.h"
#include "TextModeConsole.h"

void Hang(){
	for (;;);
}

void KernelPanic(void (*printfunc)(void*), void* param){
	Print("KERNEL PANIC: ");
	if(printfunc)printfunc(param);
	Hang();
}