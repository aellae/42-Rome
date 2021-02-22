
section	.text							; segna il punto dove inizio il programma
		global _ft_strlen						; global e' una direttiva, collega la funzione al programma

_ft_strlen:
			cmp		rdi, 0
			je		error
			mov		rax, 0 				; mette in rax il valore 0, rax e' il return della funzione
			jmp		count				; passa alla funzione count
		
count:
			cmp		BYTE [rdi + rax], 0	; BYTE serve per il deferenziamento (con byte e' rdi[rax], invece di *rdi + rax)
			je		return				; je = if (true) cmp precedente, jmp ad una funzione
			inc		rax					; = rax++
			jmp		count
return:
			ret							;  return (rax)

error:
			mov		rax, 0
			ret