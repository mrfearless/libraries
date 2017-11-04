; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

  ; ---------------------------------------------------------------
  ; dwtoa procedure was written by Tim Roberts
  ; dwtoa minor fix by Jibz, December 2004
  ; Adapted from dwtoa to qwtoa for 64bit assembler by fearless 2017
  ; ---------------------------------------------------------------

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

qwtoa proc FRAME USES RCX RBX RCX RDX RDI RSI dqValue:QWORD, lpBuffer:QWORD

    ; -------------------------------------------------------------
    ; convert DWORD to ascii string
    ; dwValue is value to be converted
    ; lpBuffer is the address of the receiving buffer
    ; EXAMPLE:
    ; invoke dwtoa,edx,ADDR buffer
    ;
    ; Uses: eax, ecx, edx.
    ; -------------------------------------------------------------
    xor rax, rax
    mov rax, dqValue
    mov rdi, [lpBuffer]

    test rax,rax
    jnz sign

  zero:
    mov word ptr [rdi],30h
    jmp dtaexit

  sign:
    jns pos
    mov byte ptr [rdi],'-'
    neg rax
    add rdi, 1

  pos:
    mov rcx, 0CCCCCCCCCCCCCCCDh ;3435973837 ; unsigned magic no divide by 10 (0CCCCCCCDh - 32bit) 0CCCCCCCCCCCCCCCDh - 64bit
    mov rsi, rdi

    .while (rax > 0)
      mov rbx,rax
      mul rcx
      shr rdx, 3
      mov rax,rdx
      lea rdx,[rdx*4+rdx]
      add rdx,rdx
      sub rbx,rdx
      add bl,'0'
      mov [rdi],bl
      add rdi, 1
    .endw

    mov byte ptr [rdi], 0       ; terminate the string

    ; We now have all the digits, but in reverse order.

    .while (rsi < rdi)
      sub rdi, 1
      mov al, [rsi]
      mov ah, [rdi]
      mov [rdi], al
      mov [rsi], ah
      add rsi, 1
    .endw

  dtaexit:

    ret

qwtoa endp

end