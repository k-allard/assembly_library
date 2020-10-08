global _ft_strlen

_ft_strlen:						 ; rdi == char *str
	mov		rax, rdi
while:
	cmp		[rax], byte 0
	je		end
	inc		rax
	jmp		while
end:
	sub		rax, rdi
	ret
