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

szLeft proc FRAME USES RBX RCX RDX src:QWORD,dst:QWORD,ln:QWORD

    mov rdx, ln     ; ln
    mov rax, src    ; src
    mov rcx, dst    ; dst

    add rax, rdx
    add rcx, rdx
    neg rdx

    ;push rbx

  align 4
  @@:
    movzx rbx, BYTE PTR [rax+rdx]
    mov [rcx+rdx], bl
    add rdx, 1
    jnz @B

    mov BYTE PTR [rcx+rdx], 0

    ;pop rbx

    mov rax, dst    ; return the destination address in EAX

    ret

szLeft endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end

