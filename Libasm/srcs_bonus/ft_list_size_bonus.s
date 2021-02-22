
section .text
		global	_ft_list_size
		extern	___error

_ft_list_size:
				mov		rax, 0
				cmp		rdi, 0
				je		error
				jmp		loop

loop:			
				inc		rax
				mov		rdi, [rdi + 8]
				cmp		rdi, 0
				jne		loop
				ret	

error:
				call	___error
				mov		rcx, 22
				mov		[rax], rcx
				mov		rax, 0
				ret