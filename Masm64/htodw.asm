; #########################################################################

  ; ---------------------------------------------------------------
  ;      This procedure was written by Alexander Yackubtchik 
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

; #########################################################################

htodw PROC FRAME USES RBX RDI RSI String:QWORD

  ; -----------------------------------
  ; Convert hex string into dword value
  ; Return value in rax
  ; -----------------------------------



    mov rdi, String
    mov rsi, String 

     ALIGN 4

  again:  
    mov al,[rdi]
    inc rdi
    or  al,al
    jnz again
    sub rsi,rdi
    xor rbx,rbx
    add rdi,rsi
    xor rdx,rdx
    not rsi             ;esi = lenth

  .while rsi != 0
    mov al, [rdi]
    cmp al,'A'
    jb figure
    sub al,'a'-10
    adc dl,0
    shl dl,5            ;if cf set we get it bl 20h else - 0
    add al,dl
    jmp next
  figure: 
    sub al,'0'
  next:  
    lea rcx,[rsi-1]
    and rax, 0Fh
    shl rcx,2           ;mul ecx by log 16(2)
    shl rax,cl          ;eax * 2^ecx
    add rbx, rax
    inc rdi
    dec rsi
  .endw

    mov rax,rbx


    ret

htodw endp

; #########################################################################

end