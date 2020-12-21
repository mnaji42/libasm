section	.text
	global	_ft_strdup
	extern	_malloc

_ft_strdup:									; rdi = src
	cmp		rdi, 0
	jz		error					; src is NULL
	xor		rcx, rcx				; i = 0
len_increment:
	cmp		BYTE [rdi + rcx], 0		; str[i] == 0
	je		malloc_start
	inc		rcx						; len++
	jne		len_increment
malloc_start:
	inc		rcx						; len++
	push	rdi						; save src
	mov		rdi, rcx
	call	_malloc					; rax = _malloc(len)
	pop		rdi						; restore src
	cmp		rax, 0					; malloc return NULL
	jz		error
	xor		rcx, rcx				; i = 0
copy:
	mov		dl, BYTE [rdi + rcx]	; tmp = str[i]
	mov		BYTE [rax + rcx], dl	; dst[i] = tmp
	cmp		dl, 0					; tmp = 0
	jz		return
	inc		rcx						; i++
	jmp		copy
error:
	xor		rax, rax				; return NULL
return:
	ret