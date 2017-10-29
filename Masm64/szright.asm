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

szRight proc FRAME USES RBX RCX RDX src:QWORD,dst:QWORD,ln:QWORD

    invoke szLen, src               ; get source length
    sub rax, ln                     ; sub required length from it
    mov rdx, src                    ; source address in RDX
    add rdx, rax                    ; add difference to source address
    or rcx, -1                      ; index to minus one
    mov rax, dst                    ; destination address in RAX

    ;push ebx

  @@:
    add rcx, 1
    movzx rbx, BYTE PTR [rdx+rcx]   ; copy bytes
    mov [rax+rcx], bl
    test rbx, rbx                   ; exit after zero written
    jne @B

    ;pop ebx

    mov rax, dst

    ret

szRight endp


; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end