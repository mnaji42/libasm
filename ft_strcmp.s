section	.text
	global	_ft_strcmp

_ft_strcmp:									; s1 = rdi, s2 = rsi
	xor		rcx, rcx				; i = 0
	cmp		rdi, 0					; s1 = 0
	jz		check_0
	cmp		rsi, 0					; s2 = 0
	jz		check_0
	jmp		check
check_0:
	cmp		rdi, rsi
	jz		equal					; s1 == s2 (NULL)
	jg		superior				; s1 == NULL
	jmp		inferior				; s2 == NULL
check:
	cmp		BYTE [rdi + rcx], 0		; s1[i] = 0
	je		compare
	cmp		BYTE [rsi + rcx], 0		; s2[i] = 0
	je		compare
	mov		dl, BYTE [rsi + rcx]	; tmp = s2[i]
	cmp		BYTE [rdi + rcx], dl	; s1[i] == tmp
	jne		compare
	inc		rcx						; i++
	jmp		check
compare:
	mov		dl, BYTE [rdi + rcx]	; tmp = s1[i]
	sub		dl, BYTE [rsi + rcx]	; tmp -= s2[i]
	cmp		dl, 0					; tmp == 0
	jz		equal
	jl		inferior
superior:
	mov		rax, 1
	ret
inferior:
	mov		rax, -1
	ret
equal:
	mov		rax, 0
	ret