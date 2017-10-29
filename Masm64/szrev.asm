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

szRev proc FRAME USES RCX RDX RDI RSI src:QWORD,dst:QWORD

  ; ------------------------------------
  ; this version will reverses a string
  ; in a single memory buffer so it can
  ; accept the same address as both src
  ; and dst.
  ; ------------------------------------

    mov rsi, src
    mov rdi, dst
    xor rax, rax            ; use EAX as a counter

  ; ---------------------------------------
  ; first loop gets the buffer length and
  ; copies the first buffer into the second
  ; ---------------------------------------
  @@:
    mov dl, [rsi+rax]       ; copy source to dest
    mov [rdi+rax], dl
    add rax, 1              ; get the length in ECX
    test dl, dl
    jne @B

    mov rsi, dst            ; put dest address in ESI
    mov rdi, dst            ; same in EDI
    sub rax, 1              ; correct for exit from 1st loop
    lea rdi, [rdi+rax-1]    ; end address in edi
    shr rax, 1              ; int divide length by 2
    neg rax                 ; invert sign
    sub rsi, rax            ; sub half len from ESI

  ; ------------------------------------------
  ; second loop swaps end pairs of bytes until
  ; it reaches the middle of the buffer
  ; ------------------------------------------
  @@:
    mov cl, [rsi+rax]       ; load end pairs
    mov dl, [rdi]
    mov [rsi+rax], dl       ; swap end pairs
    mov [rdi], cl
    sub rdi, 1
    add rax, 1
    jnz @B                  ; exit on half length

    mov rax, dst            ; return destination address

    ret

szRev endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end