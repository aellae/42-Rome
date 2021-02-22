section .text
		global	_ft_list_sort
		extern	___error
		extern	_malloc

_ft_list_sort:
				cmp		rdi, 0
				je		error
				mov		r10, [rdi]
				jmp		sort

inc_ptr:
				mov		r10, [r10 + 8]
				jmp		sort

sort:
				cmp		r10, 0				;ptr
				je		return
				mov		r11, [r10 + 8]		;ptr->next
				cmp		r11, 0
				jne		compare
				jmp		inc_ptr
compare:
				cmp		r11, 0
				je		inc_ptr
				;push	rdi
				push	rsi
				mov		rdi, [r10]
				mov		rsi, [r11]
				pop		r9
				;push	r11
				;push	r10
				;push	r9
				call	r9
				;pop		r9
				;pop		r10
				;pop		r11
				mov		rsi,r9
				;pop		rdi
				cmp		eax, 0
				jg		order
				mov		r11, [r11 + 8]
				cmp		r11, 0
				jne		compare
				jmp		inc_ptr

order:
				mov		r12, [r10]			;tmp = ptr->data
				mov		rcx, [r11]
				mov		[r10], rcx
				mov		[r11], r12
				mov		r11, [r11 + 8]
				jmp		compare



return:
				ret

error:
				call	___error
				mov		rcx, 22
				mov		[rax], rcx
				mov		rax, 0
				ret
