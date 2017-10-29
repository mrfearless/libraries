; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««

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

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

align 8

szRemove proc FRAME USES RBX RCX RDX RDI RSI src:QWORD,dst:QWORD,remv:QWORD

    mov rdx, remv
    mov bl, [rdx]               ; 1st remv char in AH

    mov rsi, src
    mov rdi, dst
    sub rsi, 1

  ; --------------------------------------------------------

  prescan:
    add rsi, 1
  scanloop:
    cmp [rsi], bl               ; test for "remv" start char
    je presub
  backin:
    movzx rax, BYTE PTR [rsi]
    mov [rdi], al
    cmp BYTE PTR [rdi], 0       ; exit when zero terminator
    je szrOut                   ; has been written
    add rdi, 1
    jmp prescan

  align 8
  presub:
    xor rcx, rcx
  subloop:
  REPEAT 3
    movzx rax, BYTE PTR [rsi+rcx]
    cmp al, [rdx+rcx]
    jne backin                  ; jump back on mismatch
    add rcx, 1
    cmp BYTE PTR [rdx+rcx], 0   ; test if next byte is zero
    je @F
  ENDM

    movzx rax, BYTE PTR [rsi+rcx]
    cmp al, [rdx+rcx]
    jne backin                  ; jump back on mismatch
    add rcx, 1
    cmp BYTE PTR [rdx+rcx], 0   ; test if next byte is zero
    jne subloop

  @@:
    add rsi, rcx
    jmp scanloop

  ; --------------------------------------------------------

  szrOut:

    mov rax, dst         ; return the destination address

    ret

szRemove endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

    end