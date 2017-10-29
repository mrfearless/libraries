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

szappend proc FRAME USES RCX RDX RDI RSI string:QWORD,buffer:QWORD,location:QWORD

  ; ------------------------------------------------------
  ; string      the main buffer to append extra data to.
  ; buffer      the byte data to append to the main buffer
  ; location    current location pointer
  ; ------------------------------------------------------

    mov rdi, 1

    mov rax, -1
    mov rsi, string         ; string
    mov rcx, buffer         ; buffer
    add rsi, location       ; location ; add offset pointer to source address

  @@:
    add rax, rdi
    movzx rdx, BYTE PTR [rcx+rax]
    mov [rsi+rax], dl
    test rdx, rdx
    jnz @B                  ; exit on written terminator

    add rax, location       ; location ; return updated offset pointer

    ret

szappend endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end
