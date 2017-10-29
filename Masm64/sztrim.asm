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

szTrim proc FRAME USES RCX RDX RDI RSI src:QWORD

    mov rsi, src
    mov rdi, src
    xor rcx, rcx

    sub rsi, 1
  @@:
    add rsi, 1
    cmp BYTE PTR [rsi], 32  ; strip space
    je @B
    cmp BYTE PTR [rsi], 9   ; strip tab
    je @B
    cmp BYTE PTR [rsi], 0   ; test for zero after tabs and spaces
    jne @F
    xor rax, rax            ; set EAX to zero on 0 length result
    mov BYTE PTR [rdi], 0   ; set string length to zero
    jmp tsOut               ; and exit

  @@:
    mov al, [rsi+rcx]       ; copy bytes from src to dst
    mov [rdi+rcx], al
    add rcx, 1
    test al, al
    je @F                   ; exit on zero
    cmp al, 33              ; don't store positions lower than 33 (32 + 9)
    jb @B
    mov rdx, rcx            ; store count if asc 33 or greater
    jmp @B

  @@:
    mov BYTE PTR [rdi+rdx], 0

    mov rax, rdx        ; return trimmed string length
    mov rcx, src

  tsOut:

    ret

szTrim endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    end