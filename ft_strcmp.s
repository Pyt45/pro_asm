		section			.text
		global			_ft_strcmp

_ft_strcmp:
		mov				rcx, -1
		xor				rax, rax
		xor				rdx, rdx

increment:
		inc				rcx

ft_strcmp_cmp:
		mov				al, byte [rdi + rcx]
		cmp				rax, 0
		je				end
		mov				dl, byte [rsi + rcx]
		sub				rax, rdx
		cmp				rax, 0
		je				increment
		jl				return_l
		jg				return_g

end:
		cmp				byte [rsi + rcx], 0
		jne				return_l
		xor				rax, rax
		ret

return_l:
		mov				rax, -1
		ret
return_g:
		mov				rax, 1
		ret
