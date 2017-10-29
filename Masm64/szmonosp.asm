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

szMonoSpace proc FRAME USES RBX RCX RDX RDI RSI RBP src:QWORD

  ; -------------------------------------------------------
  ; trim tabs and spaces from each end of "src" and replace
  ; any duplicate tabs and spaces with a single space. The
  ; result is written back to the source string address.
  ; -------------------------------------------------------

    mov rsi, 1
    mov rdi, 32
    mov bl, 32
    mov rbp, 9

    mov rcx, src
    xor rax, rax
    sub rcx, rsi
    mov rdx, src
    jmp ftrim                       ; trim the start of the string

  wspace:
    mov BYTE PTR [rdx], bl          ; always write a space
    add rdx, rsi

  ftrim:
    add rcx, rsi
    movzx rax, BYTE PTR [rcx]
    cmp rax, rdi                    ; throw away space
    je ftrim
    cmp rax, rbp                    ; throw away tab
    je ftrim
    sub rcx, rsi

  stlp:
    add rcx, rsi
    movzx rax, BYTE PTR [rcx]
    cmp rax, rdi                    ; loop back on space
    je wspace
    cmp rax, rbp                    ; loop back on tab
    je wspace
    mov [rdx], al                   ; write the non space character
    add rdx, rsi
    test rax, rax                   ; if its not zero, loop back
    jne stlp

    cmp BYTE PTR [rdx-2], bl        ; test for a single trailing space
    jne quit
    mov BYTE PTR [rdx-2], 0         ; overwrite it with zero if it is

  quit:
    mov rax, src

    ret

szMonoSpace endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
