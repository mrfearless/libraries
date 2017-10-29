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

szMid proc FRAME USES RBX RCX RDX src:QWORD,dst:QWORD,stp:QWORD,ln:QWORD

    mov rcx, ln             ; ln        length in ECX
    mov rdx, src            ; src       source address
    add rdx, rcx            ; add required length
    add rdx, stp            ; stp       add starting position
    mov rax, dst            ; dst       destination address
    add rax, rcx            ; add length and set terminator position
    neg rcx                 ; invert sign

    ;push ebx

  @@:
    movzx rbx, BYTE PTR [rdx+rcx]
    mov [rax+rcx], bl
    add rcx, 1
    jnz @B

    ;pop ebx

    mov BYTE PTR [rax], 0   ; write terminator

    ret

szMid endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end