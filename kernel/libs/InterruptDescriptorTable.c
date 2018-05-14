#include "InterruptDescriptorTable.h"
#include "TextModeConsole.h"
#include "kernel_panic.h"
#include "inoutwait.h"
#include "PIC.h"

extern void __loadIDT(IDT_Descriptor_Block*);
extern uint16_t __getSegmentCS();

//assembly handlers for the exception interrupts themselves, iret and everything
extern void (**__Exception_Interrupt_Handlers)();

//assembly handlers for the IRQ interrupts themselves, iret and everything
extern void (**__IRQ_Interrupt_Handlers)();

//C handlers
void (*Exception_Interrupt_Handlers[32])(uint32_t, uint32_t, uint32_t, uint32_t) = {0};
void (*IRQ_Interrupt_Handlers[16])() = {0};

IDT_Interrupt_Gate IDT[256] = {0};
IDT_Descriptor_Block IDT_Descriptor = (IDT_Descriptor_Block){
		((char*)IDT + sizeof(IDT_Interrupt_Gate)*256) - (char*)IDT - 1, (uint32_t)IDT
	};


//--------------------------------------------------------------------------------------
//------------------------------------------ SET FUNCTIONS -----------------------------
//--------------------------------------------------------------------------------------
char SetExceptionInterruptHandler(uint32_t index, void (*Handler)(uint32_t, uint32_t, uint32_t, uint32_t)){
	if(index >= 32 || !Handler)return 0;
	Exception_Interrupt_Handlers[index] = Handler;
	return 1;
}

char SetIRQInterruptHandler(uint32_t index, void (*Handler)()){
	if(index >= 16 || !Handler)return 0;
	IRQ_Interrupt_Handlers[index] = Handler;
	return 1;
}


//-----------------------------------------------------------------------------------------
//------------------------------------------ ASM CALLED FUNCS -----------------------------
//-----------------------------------------------------------------------------------------
void IRQ_Interrupt_Handler(uint32_t IRQ){
	if(IRQ_Interrupt_Handlers[IRQ])(IRQ_Interrupt_Handlers[IRQ])();

	if(IRQ >= 8)outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
}

void Exception_Interrupt_Handler(uint32_t exception, uint32_t EFLAGS, uint32_t CS, uint32_t EIP, uint32_t errcode){
	if(Exception_Interrupt_Handlers[exception])(Exception_Interrupt_Handlers[exception])(EFLAGS, CS, EIP, errcode);
}



void SetupExceptionHandlers(){
	for (int i = 0; i < 32; ++i){
		IDT[i] = (IDT_Interrupt_Gate){
			(uint16_t)(uint32_t)__Exception_Interrupt_Handlers[i],
			__getSegmentCS(),
			0, 0,
			IDT_INT_GATE_INTERRUPT_32,
			0, 1,
			(uint16_t)((uint32_t)__Exception_Interrupt_Handlers[i]>>16)
		};
	}
}

void SetupIRQHandlers(){
	for (int i = 0; i < 16; ++i){
		IDT[32+i] = (IDT_Interrupt_Gate){
			(uint16_t)(uint32_t)__IRQ_Interrupt_Handlers[i],
			__getSegmentCS(),
			0, 0,
			IDT_INT_GATE_INTERRUPT_32,
			0, 1,
			(uint16_t)((uint32_t)__IRQ_Interrupt_Handlers[i]>>16)
		};
	}
}

void InitIDT(){
	SetupExceptionHandlers();
	SetupIRQHandlers();
	__loadIDT(&IDT_Descriptor);
}