global __getSegmentCS
__getSegmentCS:
	mov eax, 0
	mov ax, cs
	ret

global __loadIDT
__loadIDT:
	push eax
	mov eax, [esp+8]
	lidt[eax]
	pop eax
	ret

extern DivByZero_Interrupt_Handler
global __DivByZero_Interrupt_Handler
__DivByZero_Interrupt_Handler:
    pushad
	call DivByZero_Interrupt_Handler
    popad
    iret