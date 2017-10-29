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

; note doesnt work, use lstrlen instead for the moment

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

align 8

szLen proc FRAME src:QWORD

  ; rcx = address of string

    mov rax, src
    sub rax, 1
  lbl:
  REPEAT 3
    add rax, 1
    movzx r10, BYTE PTR [rax]
    test r10, r10
    jz lbl1
  ENDM

    add rax, 1
    movzx r10, BYTE PTR [rax]
    test r10, r10
    jnz lbl

  lbl1:
    sub rax, src

    ret

szLen endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end