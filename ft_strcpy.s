global	_ft_strcpy

_ft_strcpy:							; rdi == char *dest rsi == char *src
	push	rbp
	mov		rbp, rsp
	xor		rcx, rcx				; i = 0
while:
	cmp		[rsi + rcx], byte 0
	je		end
	mov		dl, [rsi + rcx]
	mov		[rdi + rcx], dl
	inc		rcx
	jmp		while
end:
	mov		[rdi + rcx], byte 0
	mov		rax, rdi
	pop		rbp
	ret
