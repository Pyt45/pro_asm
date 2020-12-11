        global      _ft_strcpy
        section     .text
    
_ft_strcpy:
        xor         rcx, rcx
        jmp         cpy

increment:
        inc         rcx

cpy:
        mov         dl, byte[rsi + rcx]
        mov         byte[rdi + rcx], dl
        cmp         byte[rsi + rcx], 0
        jne         increment

return:
        mov          rax, rdi
        ret
