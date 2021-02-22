section .text
        global  _ft_list_remove_if
		extern	___error
        extern  _free

; rdi = lista, rsi = data, rdx = cmp, rcx = free
_ft_list_remove_if:
                        cmp     rdi, 0
                        je      error
                        cmp     rsi, 0
                        je      error
						cmp		rdx, 0
						je		error
						cmp		rcx, 0 ;;
						je		error
                        mov		r10, [rdi]			; rcx = temp
						cmp		r10, 0
						je		return
						jmp		rm_first

rm_first:
				cmp		r10, 0
				je		return
				push	rdi
				push	rsi
				push	rdx
				push	rcx ;;
				push	r10
				mov		rdi, rsi
				mov		rsi, [r10]
				xor		rax, rax					; perche mettiamo un int in una memoria piu grande, e si azzera solo quel punto mentre il resto puo essere casuale
				call	rdx
				pop		r10
				pop		rcx	;;
				pop		rdx
				pop		rsi
				pop		rdi
				cmp		eax, 0
				je		apply_rm_first
				mov		r11, [r10 + 8]				; r11 = tmp next
				jmp		rm_other

apply_rm_first:
				mov		r12, [r10 + 8]
				mov		[rdi], r12
				push	rdi
				push	rsi
				push	rdx
				push	rcx ;;
				push	r10
				mov		rdi, [r10]
				call	rcx ;;
				pop		r10
				push	r10
				mov		rdi, r10
				call	_free
				pop		r10
				pop		rcx ;;
				pop		rdx
				pop		rsi
				pop		rdi
				mov		r10, [rdi]
				;mov		rcx, [rcx + 8]
				jmp		rm_first
				
rm_other:
				cmp		r11, 0
				je		return
				push	rdi
				push	rsi
				push	rcx
				push	rdx
				push	r10
				push	r11
				mov		rdi, rsi
				mov		rsi, [r11]
				xor		rax, rax
				call	rdx
				pop		r11
				pop		r10
				pop		rdx
				pop		rcx
				pop		rsi
				pop		rdi
				cmp		rax, 0
				je		apply_rm_other
				mov		r10, r11
				mov		r11, [r11 + 8]
				jmp		rm_other


apply_rm_other:
				mov		r12, [r11 + 8]
				mov		[r10 + 8], r12
				push	rdi
				push	rsi
				push	rcx
				push	rdx
				push	r10
				push	r12
				push	r11
				mov		rdi, [r11]
				call	rcx
				pop		r11
				push	r11
				mov		rdi, r11
				call	_free
				pop		r11
				pop		r12
				pop		r10
				pop		rdx
				pop		rcx
				pop		rsi
				pop		rdi
				mov		r11, [r10 + 8]
				jmp 	rm_other	

return:
				ret

error:
				call	___error
				mov		r10, 22
				mov		[rax], r10
				mov		rax, 0
				ret