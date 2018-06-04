global __loadIDT
__loadIDT:
	push eax
	mov eax, [esp+8]
	lidt[eax]
	pop eax
	ret

global __stiEnable
__stiEnable:
	sti
	ret

