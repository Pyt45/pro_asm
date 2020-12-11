		global			_ft_list_push_front
		section			.text
		extern			_malloc

_ft_list_push_front:
		push			rsp
		push			rsi
		push			rdi
		mov				rdi, 16
		xor				rax, rax
		call			_malloc
		pop				rdi
		pop				rsi
		cmp				rax, 0
		je				_return
		mov				[rax], rsi
		mov				rcx, [rdi]
		mov				[rax + 8], rcx
		mov				[rdi], rax

_return:
		pop				rsp
		ret
