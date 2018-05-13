#include "InterruptDescriptorTable.h"
#include "TextModeConsole.h"

uint testvar = 0;

IDT_Interrupt_Gate IDT[256] = {0};
IDT_Descriptor_Block IDT_Descriptor = (IDT_Descriptor_Block){
		((char*)IDT + sizeof(IDT_Interrupt_Gate)*256) - (char*)IDT - 1, (uint)IDT
	};

void DivByZero_Interrupt_Handler(uint EFLAGS, uint CS, uint EIP, uint errcode){
	Puts(0, 20, "DivisionByZero at ");
	PrintHex(18, 20, EIP);
	PrintHex(18, 21, CS);
	PrintHex(18, 22, EFLAGS);
	PrintHex(18, 23, errcode);
	PrintHex(18, 24, testvar++);
	return;
}

void SetupHandlers(){
	IDT[0] = (IDT_Interrupt_Gate){
		(ushort)(uint)__DivByZero_Interrupt_Handler,
		__getSegmentCS(),
		0, 0,
		IDT_INT_GATE_INTERRUPT_32,
		0, 1,
		(ushort)((uint)__DivByZero_Interrupt_Handler>>16)
	};
	PrintHex(0, 0, IDT[0].segment_selector);
	__loadIDT(&IDT_Descriptor);
}