#include "Types.h"

#define IDT_INT_GATE_INTERRUPT_32 0xE
#define IDT_INT_GATE_INTERRUPT_16 0x6
typedef struct __attribute__((packed)){
	ushort offset_1;			//lower part of handler offset
	ushort segment_selector;	//should be zero: CS
	uchar  reserved : 5,		//always zero
		   zero     : 3;		//always zero
	uchar  sizeof_gate : 5,		//INT_GATE
		   desc_prev   : 2,		//previledge level for the descriptor
		   present     : 1;		//if is active, should be 1
	ushort offset_2;			//higher part of offset
} IDT_Interrupt_Gate;

typedef struct __attribute__((packed)){
	ushort size;
	uint addr;
} IDT_Descriptor_Block;

extern void __loadIDT(IDT_Descriptor_Block*);
extern void __DivByZero_Interrupt_Handler();
extern ushort __getSegmentCS();

IDT_Interrupt_Gate IDT[256];
IDT_Descriptor_Block IDT_Descriptor;

void DivByZero_Interrupt_Handler(uint EFLAGS, uint CS, uint EIP, uint errcode);

void SetupHandlers();