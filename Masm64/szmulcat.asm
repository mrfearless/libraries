; #########################################################################

;       -------------------------------------------------------------
;       This original algorithm was designed by Alexander Yackubtchik
;                     It was re-written in August 2006
;       -------------------------------------------------------------

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

szMultiCat proc C FRAME USES RBX RCX RDX RDI RSI RBP pcount:QWORD,lpBuffer:QWORD,args:VARARG

    mov rbx, 1

    mov rbp, pcount

    mov rdi, lpBuffer           ; lpBuffer
    xor rcx, rcx
    lea rdx, args           ; args
    sub rdi, rbx
  align 4
  @@:
    add rdi, rbx
    movzx rax, BYTE PTR [rdi]   ; unroll by 2
    test rax, rax
    je nxtstr

    add rdi, rbx
    movzx rax, BYTE PTR [rdi]
    test rax, rax
    jne @B
  nxtstr:
    sub rdi, rbx
    mov rsi, [rdx+rcx*8]
  @@:
    add rdi, rbx
    movzx rax, BYTE PTR [rsi]   ; unroll by 2
    mov [rdi], al
    add rsi, rbx
    test rax, rax
    jz @F

    add rdi, rbx
    movzx rax, BYTE PTR [rsi]
    mov [rdi], al
    add rsi, rbx
    test rax, rax
    jne @B

  @@:
    add rcx, rbx
    cmp rcx, rbp                ; pcount
    jne nxtstr

    mov rax, lpBuffer           ; lpBuffer

    ret

szMultiCat endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end