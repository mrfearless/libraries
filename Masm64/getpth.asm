; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

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

GetPathOnly proc FRAME USES RCX RDX RDI RSI src:QWORD, dst:QWORD

    xor rcx, rcx    ; zero counter
    mov rsi, src
    mov rdi, dst
    xor rdx, rdx    ; zero backslash location

  @@:
    mov al, [rsi]   ; read byte from address in esi
    inc rsi
    inc rcx         ; increment counter
    cmp al, 0       ; test for zero
    je gfpOut       ; exit loop on zero
    cmp al, "\"     ; test for "\"
    jne nxt1        ; jump over if not
    mov rdx, rcx    ; store counter in ecx = last "\" offset in ecx
  nxt1:
    mov [rdi], al   ; write byte to address in edi
    inc rdi
    jmp @B
    
  gfpOut:
    add rdx, dst    ; add destination address to offset of last "\"
    mov [rdx], al   ; write terminator to destination

    ret

GetPathOnly endp

; ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤

end