section	.text
	global	_ft_strcpy

_ft_strcpy:							; dst = rdi, src = rsi
	xor		rcx, rcx				; i = 0
	cmp		rsi, 0					; src = 0
	jz		return
	jmp		copy
copy:
	mov		dl, BYTE [rsi + rcx]	; tmp = src[i]
	mov		BYTE [rdi + rcx], dl	; dst[i] = tmp
	cmp		dl, 0					; tmp = 0
	jz		return
	inc		rcx						; i++
	jmp		copy
return:
	mov		rax, rdi				; return dst
	ret
