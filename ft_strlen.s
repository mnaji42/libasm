section	.text
	global	_ft_strlen

_ft_strlen:
	xor		rax, rax			; i = 0

compare:
	cmp		BYTE [rdi + rax], 0	; str[i] == 0
	je		done
	inc		rax					; i++
	jmp		compare
done:
	ret							; return i
