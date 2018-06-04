global __getSegmentCS
__getSegmentCS:
	mov eax, 0
	mov ax, cs
	ret