
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
 
; ?????????????????????????????????????????????????????????????????????????

.data

align 8
abntbl \
      db 2,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 1,0,3,0,0,0,0,0,0,0,0,0,1,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
      db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

    ; 0 = OK char
    ; 1 = delimiting characters   tab LF CR space ","
    ;
    ; 2 = ASCII zero    This should not be changed in the table
    ; 3 = quotation     This should not be changed in the table

.code

; ?????????????????????????????????????????????????????????????????????????

align 8

ArgByNumber PROC FRAME USES RBX RCX RDX RDI RSI src:QWORD,dst:QWORD,num:QWORD,npos:QWORD

; -----------------------------------------------

;        Return values in EAX
;        --------------------
;        >0 = there is a higher number argument available
;        0  = end of command line has been found
;        -1 = a non matching quotation error occurred
;
;        conditions of 0 or greater can have argument
;        content which can be tested as follows.
;
;        Test Argument for content
;        -------------------------
;        If the argument is empty, the first BYTE in the
;        destination buffer is set to zero
;
;        mov eax, destbuffer     ; load destination buffer
;        cmp BYTE PTR [eax], 0   ; test its first BYTE
;        je no_arg               ; branch to no arg handler
;        print destbuffer,13,10  ; display the argument
;
;        NOTE : A pair of empty quotes "" returns ascii 0
;               in the destination buffer

; ----------------------------------------------- *

    mov rsi, src
    add rsi, npos
    mov rdi, dst

    mov BYTE PTR [rdi], 0           ; set destination buffer to zero length
    
    xor rbx, rbx

  ; *********
  ; scan args
  ; *********
  bcscan:
    movzx rax, BYTE PTR [rsi]
    add rsi, 1
    lea rcx, abntbl
    cmp BYTE PTR [rcx+rax], 1    ; delimiting character
    je bcscan
    cmp BYTE PTR [rcx+rax], 2    ; ASCII zero
    je quit

    sub rsi, 1
    add rbx, 1
    cmp rbx, num                    ; copy next argument if number matches
    je cparg

  gcscan:
    movzx rax, BYTE PTR [rsi]
    add rsi, 1
    lea rcx, abntbl
    cmp BYTE PTR [rcx+rax], 0    ; OK character
    je gcscan
    cmp BYTE PTR [rcx+rax], 2    ; ASCII zero
    je quit
    cmp BYTE PTR [rcx+rax], 3    ; quotation
    je dblquote
    jmp bcscan                      ; return to delimiters

  dblquote:
    add rsi, 1
    cmp BYTE PTR [rsi], 0
    je qterror
    cmp BYTE PTR [rsi], 34
    jne dblquote
    add rsi, 1
    jmp bcscan                      ; return to delimiters

  ; ********
  ; copy arg
  ; ********
  cparg:
    xor rax, rax
    xor rdx, rdx
    cmp BYTE PTR [rsi+rdx], 34      ; if 1st char is a quote
    je cpquote                      ; jump to quote copy
  @@:
    mov al, [rsi+rdx]               ; copy normal argument to buffer
    mov [rdi+rdx], al
    test rax, rax
    jz quit
    add rdx, 1
    lea rcx, abntbl
    cmp BYTE PTR [rcx+rax], 1
    jl @B
    mov BYTE PTR [rdi+rdx-1], 0     ; append terminator
    jmp next_read

  ; ********************
  ; copy quoted argument
  ; ********************
  cpquote:
    add rsi, 1
  @@:
    mov al, [rsi+rdx]               ; strip quotes and copy contents to buffer
    test al, al
    jz qterror
    cmp al, 34
    je write_zero
    mov [rdi+rdx], al
    add rdx, 1
    jmp @B

  write_zero:
    add rdx, 1                      ; correct EDX for final exit position
    mov BYTE PTR [rdi+rdx-1], 0     ; append terminator

    jmp next_read                    ; jump to next read setup
  ; *****************
  ; set return values
  ; *****************
  qterror:
    mov rax, -1                     ; quotation error
    jmp rstack

  quit:
    xor rax, rax                    ; set EAX to zero for end of source buffer
    jmp rstack

  next_read:
    mov rax, rsi
    add rax, rdx
    sub rax, src

  rstack:

    ret

ArgByNumber endp

; ?????????????????????????????????????????????????????????????????????????

end
