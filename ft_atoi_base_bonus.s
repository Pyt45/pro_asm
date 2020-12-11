		section				.text
		global				_ft_atoi_base

_ft_atoi_base:
		cmp					rdi, 0
		je					exit_null
		cmp					rsi, 0
		je					exit_null
		push				rbx
		push				r14
		push				r15

		mov					r15, 1
		cmp					[rdi], byte 45
		je					set_sign
		jmp					next_inst

inc_rsi:
		inc					rdi
		jmp					ft_atoi_base_next

set_sign:
		mov					r15, -1

next_inst:
		cmp					[rdi], byte 43
		je					inc_rsi
		cmp					[rdi], byte 45
		je					inc_rsi

ft_atoi_base_next:
		push				rdi
		push				rsi
		mov					r8, rdi
		mov					rdi, rsi
		mov					rsi, r8
		call				_check_base
		mov		        	rbx, rax
		mov					r14, 0
		pop					rsi
		pop					rdi
		cmp					rax, 0
		je					exit_end
		mov					rcx, 0
		jmp					ft_atoi_base_do

do_opr:
        imul				r14, rbx
        add					r14, rax

increment2:
		inc					rcx

ft_atoi_base_do:
		cmp					byte [rdi + rcx], 0
		je					exit_end
        push				rdi
        push				rsi
		push				rcx

		mov					r8, rsi
        mov					sil, byte [rdi + rcx]
        mov					rdi, r8
        call				find_char_base
		pop					rcx
        pop					rsi
        pop					rdi
        cmp					rax, 0
        jge					do_opr
		jmp					increment2

_check_base:
		push				rdi
		push				rsi
		call				_ft_strlen
		pop					rsi
		pop					rdi
		mov					rdx, rax
		sub					rax, 1
		cmp					rax, 0
		je					exit
		mov					rcx, 0
		jmp					next

increment:
		inc					rcx

next:
        cmp					byte[rsi + rcx], 0
		je					check
		push				rdi
		push				rsi
		push				rcx
		mov					r8, rsi
		mov					rdi, rdi
		mov					sil ,byte[r8 + rcx]
		call				find_char_base
		pop					rcx
		pop					rsi
		pop					rdi
		cmp					rax, 0
		jl					exit
		jmp					increment

check:
		mov					rcx, 0
		jmp					next_check

increment1:
		inc					rcx

next_check:
		cmp					byte [rdi + rcx], 0
		je					exit_ret
		cmp					byte [rdi + rcx], 43
		je					exit
		cmp					byte [rdi + rcx], 45
		je					exit
		push				rdi
		push				rsi
		push				rcx
		mov					sil, byte [rdi + rcx]
		add					rdi, rcx
		inc					rdi
		call				find_char_base
		pop					rcx
		pop					rsi
		pop					rdi
		cmp					rax,  0
		jge					exit
		jmp					increment1

exit_ret:
		mov					rax, rdx
		ret

exit:
		mov					rax, 0
		ret

find_char_base:
        mov					rcx, -1

find_loop:
        inc					rcx
        mov					al, byte [rdi + rcx]
        sub					al,  sil
        cmp					al, byte 0
        je					find_index
        cmp					[rdi + rcx], byte 0
        jne					find_loop

find_exit:
		mov		        	rax, -1
		ret

find_index:
        mov					rax, rcx
        ret

_ft_strlen:
		mov			rcx, -1
		inc			rcx

_ft_strlen_loop:
		cmp			byte [rdi + rcx], 0
		je			return
		inc			rcx
		jmp			_ft_strlen_loop

return:
		mov			rax, rcx
		ret

exit_end:
        mov                     rax, r14
		imul					rax, r15
        pop            	        r15           
        pop            	        r14
        pop            	        rbx
        ret

exit_null:
		xor						rax, rax
		ret
