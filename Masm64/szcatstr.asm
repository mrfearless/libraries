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

szLen PROTO :QWORD

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл


align 8

szCatStr proc FRAME USES RCX RDX RDI lpszSource:QWORD, lpszAdd:QWORD

    invoke szLen, lpszSource        ; get source length
    mov rdi, lpszSource
    mov rcx, lpszAdd
    add rdi, rax                    ; set write starting position
    xor rdx, rdx                    ; zero index

  @@:
    movzx rax, BYTE PTR [rcx+rdx]   ; write append string to end of source
    mov [rdi+rdx], al
    add rdx, 1
    test rax, rax                   ; exit when terminator is written
    jne @B


    mov rax, lpszSource             ; return start address of source

    ret

szCatStr endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end

