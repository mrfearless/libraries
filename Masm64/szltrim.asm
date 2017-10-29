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

align 8

szLtrim proc FRAME USES RCX RDX RDI src:QWORD,dst:QWORD

    xor rcx, rcx
    mov rdx, src
    mov rdi, dst
    sub rdx, 1

  @@:
    add rdx, 1
    cmp BYTE PTR [rdx], 32
    je @B
    cmp BYTE PTR [rdx], 9
    je @B
    cmp BYTE PTR [rdx], 0
    jne @F
    xor rax, rax            ; return zero on empty string
    mov BYTE PTR [rdi], 0   ; set string length to zero
    jmp szlOut
  @@:
    mov al, [rdx+rcx]
    mov [rdi+rcx], al
    add rcx, 1
    test al, al
    jne @B

    mov rax, rcx
    sub rax, 1              ; don't count ascii zero
                            ; return length of remaining string

    mov rcx, dst

  szlOut:


    ret

szLtrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end