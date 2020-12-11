        global			_ft_list_remove_if
        section			.text
    	extern			_free

_ft_list_remove_if:
		push			rsp
		push			rbx
		push			r12
		push			r13
		cmp				rdi, 0
		je				end
		mov				r12, [rdi]
		cmp				rsi, 0
		je				end
		cmp				rdx, 0
		je				end
		xor				rbx, rbx
		xor				r13, r13
		jmp				big_loop

free_elt:
		mov				rbx, r12
		mov				r12, [r12 + 8]
		push			rdi
		push			rsi
		push			rdx
		mov				rdi, rbx
		call			_free
		pop				rdx
		pop				rsi
		pop				rdi
		jmp				big_loop


give_it_add:
		mov				r8, [r12 + 8]
		mov				[rdi], r8
		jmp				free_elt

remove_elt:
		mov				rcx, [rdi]
		mov				r8, r12
		sub				r8, rcx
		cmp				r8, 0
		je				give_it_add
		mov				r8, [r12 + 8]
		mov				[r13 + 8], r8
		jmp				free_elt


increment:
		mov				r13, r12
		mov				r12, [r12 + 8]

big_loop:
		cmp				qword r12, 0
		je				end
		push			rdi
		push			rsi
		push			rdx
		mov				rdi, [r12]
		call			rdx
		pop				rdx
		pop				rsi
		pop				rdi
		cmp				rax, 0
		jne				increment
		jmp				remove_elt

end:
		pop				r13
		pop				r12
		pop				rbx
		pop				rsp
		ret
