		section			.text
		global			_ft_list_size

_ft_list_size:
		mov				r12, rdi
		xor				rcx, rcx

next:
		cmp				r12, 0
		je				exit
		inc				rcx
		mov				r12, [r12 + 8]
		jmp				next

exit:
		mov				rax, rcx
		ret
