        global      _ft_strlen
        section     .text

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
