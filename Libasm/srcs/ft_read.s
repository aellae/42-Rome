section .text
		global	_ft_read
		extern	___error

_ft_read:
		mov			rax, 0x02000003
		syscall
		jc			error		; se ci sono errori la carry flag viene settata ad 1
		ret


error:
		push		rax			; mi salvo rax, che cambiera' una volta chiamato error
		call		___error	; error mette in rax l'indirizzo di errno
		pop			r10
		mov			[rax], r10 	; inserisce dentro errno il valore dell'errore
		mov 		rax, -1
		ret