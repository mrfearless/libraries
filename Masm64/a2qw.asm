; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

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

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

align 8

a2qw proc FRAME USES RCX RDX String:QWORD

  ; ------------------------------------------------
  ; Convert decimal string into UNSIGNED DWORD value
  ; ------------------------------------------------

    mov rdx, String
    xor rcx, rcx
    movzx rax, BYTE PTR [rdx]
    test rax, rax
    jz quit

  lpst:
    add rdx, 1
    lea rcx, [rcx+rcx*4]            ; mul ecx * 5
    lea rcx, [rax+rcx*2-48]
    movzx rax, BYTE PTR [rdx]
    test rax, rax
    jz quit

    add rdx, 1
    lea rcx, [rcx+rcx*4]            ; mul ecx * 5
    lea rcx, [rax+rcx*2-48]
    movzx rax, BYTE PTR [rdx]
    test rax, rax
    jnz lpst

  quit:
    lea rax, [rcx]

    ret

a2qw endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end
