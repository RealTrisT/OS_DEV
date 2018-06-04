#include "Types.h"

#define IDT_INT_GATE_INTERRUPT_32 0xE
#define IDT_INT_GATE_INTERRUPT_16 0x6
#define IDT_INT_GATE_ACTIVE 1
#define IDT_INT_GATE_INACTIVE 0
typedef struct __attribute__((packed)){
	uint16_t offset_1;			//lower part of handler offset
	uint16_t segment_selector;	//should be zero: CS
	uint8_t  reserved : 5,		//always zero
		   	 zero     : 3;		//always zero
	uint8_t  sizeof_gate : 5,	//INT_GATE
		   	 desc_prev   : 2,	//previledge level for the descriptor
		   	 present     : 1;	//if is active, should be 1
	uint16_t offset_2;			//higher part of offset
} IDT_Interrupt_Gate;

typedef struct __attribute__((packed)){
	uint16_t size;
	uint32_t addr;
} IDT_Descriptor_Block;

IDT_Interrupt_Gate IDT[256];
IDT_Descriptor_Block IDT_Descriptor;

void InitIDT();
char SetExceptionInterruptHandler(uint32_t index, void (*Handler)(uint32_t, uint32_t, uint32_t, uint32_t));
char SetIRQInterruptHandler(uint32_t index, void (*Handler)());
char UnsetExceptionInterruptHandler(uint32_t index);
char UnsetIRQInterruptHandler(uint32_t index);