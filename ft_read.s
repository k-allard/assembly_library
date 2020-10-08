extern ___error
global _ft_read

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		error
	ret
error:
	mov		rbx, rax
	call	___error
	mov		[rax], rbx
	mov		rax, -1
	ret
