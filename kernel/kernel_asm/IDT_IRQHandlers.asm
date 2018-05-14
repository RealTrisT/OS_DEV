extern IRQ_Interrupt_Handler

__execute:
	call IRQ_Interrupt_Handler
	add esp, 4
    popad
    iret

__IRQ_Interrupt_Handler0:
	pushad
    push 0
    jmp __execute

__IRQ_Interrupt_Handler1:
	pushad
    push 1
    jmp __execute

__IRQ_Interrupt_Handler2:
	pushad
    push 2
    jmp __execute

__IRQ_Interrupt_Handler3:
	pushad
    push 3
    jmp __execute

__IRQ_Interrupt_Handler4:
	pushad
    push 4
    jmp __execute

__IRQ_Interrupt_Handler5:
	pushad
    push 5
    jmp __execute

__IRQ_Interrupt_Handler6:
	pushad
    push 6
    jmp __execute

__IRQ_Interrupt_Handler7:
	pushad
    push 7
    jmp __execute

__IRQ_Interrupt_Handler8:
	pushad
    push 8
    jmp __execute

__IRQ_Interrupt_Handler9:
	pushad
    push 9
    jmp __execute

__IRQ_Interrupt_Handler10:
	pushad
    push 10
    jmp __execute

__IRQ_Interrupt_Handler11:
	pushad
    push 11
    jmp __execute

__IRQ_Interrupt_Handler12:
	pushad
    push 12
    jmp __execute

__IRQ_Interrupt_Handler13:
	pushad
    push 13
    jmp __execute

__IRQ_Interrupt_Handler14:
	pushad
    push 14
    jmp __execute

__IRQ_Interrupt_Handler15:
	pushad
    push 15
    jmp __execute


section .data
__IRQ_Interrupt_Handler_Array dd __IRQ_Interrupt_Handler0, __IRQ_Interrupt_Handler1, __IRQ_Interrupt_Handler2, __IRQ_Interrupt_Handler3, __IRQ_Interrupt_Handler4, __IRQ_Interrupt_Handler5, __IRQ_Interrupt_Handler6, __IRQ_Interrupt_Handler7, __IRQ_Interrupt_Handler8, __IRQ_Interrupt_Handler9, __IRQ_Interrupt_Handler10, __IRQ_Interrupt_Handler11, __IRQ_Interrupt_Handler12, __IRQ_Interrupt_Handler13, __IRQ_Interrupt_Handler14, __IRQ_Interrupt_Handler15


global __IRQ_Interrupt_Handlers
__IRQ_Interrupt_Handlers dd __IRQ_Interrupt_Handler_Array