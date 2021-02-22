
section .text
		global	_ft_atoi_base
		extern	___error
		extern 	_ft_strlen

_ft_atoi_base:
				push	rdi
				mov		rdi, rsi
				call	_ft_strlen
				cmp		rax, 2
				jl		base_error
				mov		r10, rax
				xor		rax, rax
				jmp		control_double

loop_double:
				mov		r11b, [rdi]
				cmp		[rcx], r11b
				je		base_error
				add		rcx, 1
				mov		r11b, 0
				cmp		[rcx], r11b
				jne		loop_double
				jmp		inc_rdi

inc_rdi:
				add		rdi, 1
				mov		r11b, 0
				cmp		[rdi], r11b
				je		restore_rdi
				jmp		control_double

control_double:
				mov		rcx, rdi
				add		rcx, 1
				mov		r11b, 0
				cmp		[rcx], r11b
				jne		loop_double

restore_rdi:
				mov		rdi, rsi
				xor		rcx, rcx
				jmp		loop_char

loop_char:
				cmp		BYTE[rdi + rcx], 33
				jl		base_error
				cmp		BYTE[rdi + rcx], 126
				jg		base_error
				cmp		BYTE[rdi + rcx], 43
				je		base_error
				cmp		BYTE[rdi + rcx], 45
				je		base_error
				inc 	rcx
				cmp		BYTE[rdi + rcx], 0
				jne		loop_char
				jmp		read_str		
ret1:
				pop	rcx
				mov		rax, r11
				ret
control_char:
				xor		rcx,rcx
				jmp		loop_char

read_str:
				pop		rdi
				xor		rcx, rcx
				mov		rcx, -1
				jmp		skip_spaces

skip_spaces:
				inc		rcx
				cmp		BYTE[rdi + rcx], 13
				je		skip_spaces
				cmp		BYTE[rdi + rcx], 12
				je		skip_spaces
				cmp		BYTE[rdi + rcx], 11
				je		skip_spaces
				cmp		BYTE[rdi + rcx], 10
				je		skip_spaces
				cmp		BYTE[rdi + rcx], 9
				je		skip_spaces
				cmp		BYTE[rdi + rcx], 32
				je		skip_spaces
				dec		rcx
				mov		r9, 1					;
				jmp		skip_sign

skip_sign:
				inc		rcx
				cmp		BYTE[rdi + rcx], 43
				je		skip_sign
				cmp		BYTE[rdi + rcx], 45
				jne		decr
				neg		r9
				jmp		skip_sign

decr:
				dec		rcx
				xor		r11, r11
				jmp		check_str_base

check_str_base:
				inc		rcx
				mov		r11, -1
				mov		r12b, BYTE[rdi + rcx]			;str[i]
				cmp		r12b, 0							;str[i] == 0
				je		return
				jmp		check_char
				
				
check_char:
				inc		r11
				cmp		BYTE[rsi + r11], 0
				je		return
				cmp		r12b, BYTE[rsi + r11]			;str[i] == base[i]
				je		save_nbr
				jmp		check_char

save_nbr:
				mul		r10
				add		rax, r11
				jmp		check_str_base

return:
				imul	r9
				ret

base_error:
				pop		r9
				call	___error
				mov		rcx, 22
				mov		[rax], rcx
				mov		rax, 0
				ret