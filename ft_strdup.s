global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:
	call	_ft_strlen
	add		rax, 1
	push	rdi
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
    je		error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret
error:
	mov		rax, 0
    ret