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

szCmp proc FRAME USES RBX RCX RDX RSI str1:QWORD, str2:QWORD

  ; --------------------------------------
  ; scan zero terminated string for match
  ; --------------------------------------
    mov rcx, str1
    mov rdx, str2

    mov rax, -1
    mov rsi, 1

  align 4
  cmst:
  REPEAT 3
    add rax, rsi
    movzx rbx, BYTE PTR [rcx+rax]
    cmp bl, [rdx+rax]
    jne no_match
    test rbx, rbx       ; check for terminator
    je retlen
  ENDM

    add rax, rsi
    movzx rbx, BYTE PTR [rcx+rax]
    cmp bl, [rdx+rax]
    jne no_match
    test rbx, rbx       ; check for terminator
    jne cmst

  retlen:               ; length is in EAX
    ret

  no_match:
    xor rax, rax        ; return zero on no match
    ret

szCmp endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end