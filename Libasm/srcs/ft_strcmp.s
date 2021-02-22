;int		ft_strcmp(char *s1, char *s2)
;{
;	int index;
;
;	index = 0;
;	while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0')
;	{
;		index++;
;	}
;	return (s1[index] - s2[index]);
;}

section .text
		global	_ft_strcmp

_ft_strcmp:
			mov rax, 0
			mov	r10, 0
			cmp	rdi, 0
			je	error1
			cmp	rsi, 0
			je	error2
			jmp	while

while:
			cmp	BYTE[rdi + r10], 0
			je	return
			cmp	BYTE[rsi + r10], 0
			je	return
			mov	r11b, BYTE[rdi + r10]
			cmp	BYTE[rsi + r10], r11b
			jne	return
			inc	r10
			jmp	while

return:
			mov	r9b, BYTE[rsi + r10]
			mov r11b, BYTE[rdi + r10]
			sub		r11, r9
			mov	rax, r11
			ret
error1:			
			cmp	rsi, 0
			je	error3
			mov	r11, -1
			mov	rax, r11
			ret

error2:
			cmp	rdi, 0
			je	error3
			mov	r11, 1
			mov	rax, r11
			ret
error3:
			mov rax, 0
			ret
