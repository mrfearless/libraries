; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл


comment * -----------------------------------------------
        copied length minus terminator is returned in RAX
        ----------------------------------------------- *
align 8

szCopy proc FRAME USES RBX RCX RDX RSI src:QWORD,dst:QWORD

    mov rdx, src
    mov rbx, dst
    mov rax, -1
    mov rsi, 1

  @@:
    add rax, rsi
    movzx rcx, BYTE PTR [rdx+rax]
    mov [rbx+rax], cl
    test rcx, rcx
    jnz @B

    ret

szCopy endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end