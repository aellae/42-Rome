;char	*ft_strcpy(char *dest, char *src)
;{
;	int iterator;
;
;	iterator = 0;
;	while (*(src + iterator) != 0)
;	{
;		*(dest + iterator) = *(src + iterator);
;		iterator++;
;	}
;	*(dest + iterator) = 0;
;	return (dest);
;}


section .text
global	_ft_strcpy

_ft_strcpy:
			mov	r10, 0
			cmp	rdi, 0
			je	error
			cmp	rsi, 0
			je	error
			jmp	while
while:			
			cmp BYTE[rsi + r10], 0			
			je	return
			mov	r11b,BYTE[rsi + r10]
			mov	BYTE[rdi +r10], r11b
			inc	r10
			jmp	while
			mov	BYTE[rdi + r10], 0
			mov	rax, rdi
			jmp	return

return:
			mov	BYTE[rdi + r10], 0
			mov	rax, rdi
			ret

error:
			mov	rax, 0
			ret
