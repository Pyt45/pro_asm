
            section             .text
            global              _ft_list_sort

_ft_list_sort:
			push				rbx
            push                r12
            cmp                 rdi, 0
            jz                  end
            mov                 r12, [rdi]
            cmp                 rsi, 0
            jz                  return
			jmp					comp_1

increment_loop:
			mov					rcx, [rdi]
			mov					rbx, [rcx + 8]
			mov					[rdi], rbx

comp_1:
			cmp					QWORD [rdi], 0
			jz					return
			mov					rcx, [rdi]
			mov					rbx, [rcx + 8]

comp_2:
			cmp					rbx, 0
			jz					increment_loop 

compare:
			push				rdi
			push				rsi
			mov					rax, rsi
			mov					rcx, [rdi]
			mov					rdi, [rcx]
			mov					rsi, [rbx]
			call				rax
			pop					rsi
			pop					rdi
			cmp					rax, 0
			jge					swap_data

increment_main:
			mov					rcx, [rbx + 8]
			mov					rbx, rcx
			jmp					comp_2

swap_data:
			mov					r8, [rdi]
			mov					rcx, [r8]
			mov					rax, [rbx]
			mov					[r8], rax
			mov					[rbx], rcx
			jmp					increment_main

return:
			mov					[rdi], r12

end:
            pop                 r12
			pop					rbx
            ret
