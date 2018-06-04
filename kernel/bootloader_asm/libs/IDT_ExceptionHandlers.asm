extern Exception_Interrupt_Handler

__execute:
	call Exception_Interrupt_Handler
	add esp, 4
    popad
    iret


__Exception_Interrupt_0_Handler:
    pushad
    push 0
    jmp __execute


__Exception_Interrupt_1_Handler:
    pushad
    push 1
    jmp __execute


__Exception_Interrupt_2_Handler:
    pushad
    push 2
    jmp __execute


__Exception_Interrupt_3_Handler:
    pushad
    push 3
    jmp __execute


__Exception_Interrupt_4_Handler:
    pushad
    push 4
    jmp __execute


__Exception_Interrupt_5_Handler:
    pushad
    push 5
    jmp __execute


__Exception_Interrupt_6_Handler:
    pushad
    push 6
    jmp __execute


__Exception_Interrupt_7_Handler:
    pushad
    push 7
    jmp __execute


__Exception_Interrupt_8_Handler:
    pushad
    push 8
    jmp __execute


__Exception_Interrupt_9_Handler:
    pushad
    push 9
    jmp __execute


__Exception_Interrupt_10_Handler:
    pushad
    push 10
    jmp __execute


__Exception_Interrupt_11_Handler:
    pushad
    push 11
    jmp __execute


__Exception_Interrupt_12_Handler:
    pushad
    push 12
    jmp __execute


__Exception_Interrupt_13_Handler:
    pushad
    push 13
    jmp __execute


__Exception_Interrupt_14_Handler:
    pushad
    push 14
    jmp __execute


__Exception_Interrupt_15_Handler:
    pushad
    push 15
    jmp __execute


__Exception_Interrupt_16_Handler:
    pushad
    push 16
    jmp __execute


__Exception_Interrupt_17_Handler:
    pushad
    push 17
    jmp __execute


__Exception_Interrupt_18_Handler:
    pushad
    push 18
    jmp __execute


__Exception_Interrupt_19_Handler:
    pushad
    push 19
    jmp __execute


__Exception_Interrupt_20_Handler:
    pushad
    push 20
    jmp __execute


__Exception_Interrupt_21_Handler:
    pushad
    push 21
    jmp __execute


__Exception_Interrupt_22_Handler:
    pushad
    push 22
    jmp __execute


__Exception_Interrupt_23_Handler:
    pushad
    push 23
    jmp __execute


__Exception_Interrupt_24_Handler:
    pushad
    push 24
    jmp __execute


__Exception_Interrupt_25_Handler:
    pushad
    push 25
    jmp __execute


__Exception_Interrupt_26_Handler:
    pushad
    push 26
    jmp __execute


__Exception_Interrupt_27_Handler:
    pushad
    push 27
    jmp __execute


__Exception_Interrupt_28_Handler:
    pushad
    push 28
    jmp __execute


__Exception_Interrupt_29_Handler:
    pushad
    push 29
    jmp __execute


__Exception_Interrupt_30_Handler:
    pushad
    push 30
    jmp __execute


__Exception_Interrupt_31_Handler:
    pushad
    push 31
    jmp __execute


section .data
__Exception_Interrupt_Handler_Array dd __Exception_Interrupt_0_Handler, __Exception_Interrupt_1_Handler, __Exception_Interrupt_2_Handler, __Exception_Interrupt_3_Handler,  __Exception_Interrupt_4_Handler,  __Exception_Interrupt_5_Handler, __Exception_Interrupt_6_Handler,  __Exception_Interrupt_7_Handler,  __Exception_Interrupt_8_Handler, __Exception_Interrupt_9_Handler,  __Exception_Interrupt_10_Handler, __Exception_Interrupt_11_Handler, __Exception_Interrupt_12_Handler, __Exception_Interrupt_13_Handler, __Exception_Interrupt_14_Handler, __Exception_Interrupt_15_Handler, __Exception_Interrupt_16_Handler, __Exception_Interrupt_17_Handler, __Exception_Interrupt_18_Handler, __Exception_Interrupt_19_Handler, __Exception_Interrupt_20_Handler, __Exception_Interrupt_21_Handler, __Exception_Interrupt_22_Handler, __Exception_Interrupt_23_Handler, __Exception_Interrupt_24_Handler, __Exception_Interrupt_25_Handler, __Exception_Interrupt_26_Handler, __Exception_Interrupt_27_Handler, __Exception_Interrupt_28_Handler, __Exception_Interrupt_29_Handler, __Exception_Interrupt_30_Handler, __Exception_Interrupt_31_Handler

global __Exception_Interrupt_Handlers
__Exception_Interrupt_Handlers dd __Exception_Interrupt_Handler_Array