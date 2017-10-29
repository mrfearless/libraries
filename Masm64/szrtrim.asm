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

szRtrim proc FRAME USES RCX RDX RDI RSI src:QWORD,dst:QWORD

    mov rsi, src
    mov rdi, dst
    sub rsi, 1
  @@:
    add rsi, 1
    cmp BYTE PTR [rsi], 32
    je @B
    cmp BYTE PTR [rsi], 9
    je @B
    cmp BYTE PTR [rsi], 0
    jne @F
    xor rax, rax            ; return zero on empty string
    mov BYTE PTR [rdi], 0   ; set string length to zero
    jmp szLout

  @@:
    mov rsi, src
    xor rcx, rdx
    xor rcx, rcx        ; ECX as index and location counter

  @@:
    mov al, [rsi+rcx]   ; copy bytes from src to dst
    mov [rdi+rcx], al
    add rcx, 1
    test al, al
    je @F               ; exit on zero
    cmp al, 33
    jb @B
    mov rdx, rcx        ; store count if asc 33 or greater
    jmp @B

  @@:
    mov BYTE PTR [rdi+rdx], 0

    mov rax, rdx        ; return length of trimmed string
    mov rcx, dst

  szLout:

    ret

szRtrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end