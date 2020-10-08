global	_ft_strcmp

_ft_strcmp:								; rdi == char *s1 rsi == char *s2
	push	rbp
	mov		rbp, rsp
	xor		rcx, rcx					; i = 0
while:
	mov		dl, [rdi + rcx]				; dl = s1[i]
	mov		dh, [rsi + rcx]				; dh = s2[i]
	cmp		dl, 0
	je		end
	cmp		dh, 0
	je		end
	cmp		dh, dl
	jne		end
	inc		rcx
	jmp		while
end:
	movzx	eax, dl
	movzx	ecx, dh
	sub		eax, ecx
	pop		rbp
	ret
