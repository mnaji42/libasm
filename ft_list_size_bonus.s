section	.text
	global	_ft_list_size

_ft_list_size:				; rdi = begin
	mov		rsi, rdi
	xor		rax, rax
count:
	cmp		rdi, 0			; begin == NULL
	jz		return
	mov		rdi, [rdi + 8]	; begin = begin.next
	inc		rax				; total = 0
	jmp		count
return:
	mov		rdi, rsi
	ret