;char	*ft_strdup(char *src)
;{
;	char *dst;
;
;	dst = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
;	if (!dst)
;		return (0);
;	ft_strcpy(dst, src);
;	return (dst);
;}

section .text
		global	_ft_strdup
		extern	___error
		extern	_malloc
		extern	_ft_strlen
		extern	_ft_strcpy

_ft_strdup:
		cmp		rdi, 0
		je		end
		call	_ft_strlen
		push	rdi
		mov		rdi, rax
		inc		rdi
		call	_malloc
		cmp		rax, 0
		je		error
		mov		rdi, rax
		pop		rsi
		call	_ft_strcpy
		ret

end:
		mov		rax, 0
		ret

error:
		call	___error	; error mette in rax l'indirizzo di errno
		mov		r10, 12
		mov		[rax], r10 	; ENOMEM
		mov 	rax, 0
		ret