
section .text
		global	_ft_list_push_front
		extern	___error
		extern	_malloc

_ft_list_push_front:
						cmp		rdi, 0
						je		error
						push	rdi
						push	rsi
						mov		rdi, 16
						call	_malloc
						cmp		rax, 0
						je		errorm
						pop		rsi
						mov		[rax], rsi
						mov		r11, 0
						mov		[rax + 8], r11
						pop		rdi
						mov		rcx, [rdi]
						mov		[rax + 8], rcx
						mov		[rdi], rax
						ret
error:				
				call	___error
				mov		rcx, 22
				mov		[rax], rcx
				mov		rax, 0
				ret
errorm:
				pop		rdi
				pop		rsi
				call	___error
				mov		rcx, 12
				mov		[rax], rcx
				mov		rax, 0
				ret