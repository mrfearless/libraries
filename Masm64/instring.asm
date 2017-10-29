; #########################################################################

;       The subloop code for this algorithm was redesigned by EKO to
;       perform the comparison in reverse which reduced the number
;       of instructions required to set up the branch comparison.

; #########################################################################

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

; ########################################################################

InString proc FRAME USES RBX RCX RDX RDI RSI startpos:QWORD,lpSource:QWORD,lpPattern:QWORD

  ; ------------------------------------------------------------------
  ; InString searches for a substring in a larger string and if it is
  ; found, it returns its position in eax. 
  ;
  ; It uses a one (1) based character index (1st character is 1,
  ; 2nd is 2 etc...) for both the "StartPos" parameter and the returned
  ; character position.
  ;
  ; Return Values.
  ; If the function succeeds, it returns the 1 based index of the start
  ; of the substring.
  ;  0 = no match found
  ; -1 = substring same length or longer than main string
  ; -2 = "StartPos" parameter out of range (less than 1 or longer than
  ; main string)
  ; ------------------------------------------------------------------

    LOCAL sLen:QWORD
    LOCAL pLen:QWORD


    invoke szLen,lpSource
    mov sLen, rax           ; source length
    invoke szLen,lpPattern
    mov pLen, rax           ; pattern length

    cmp startpos, 1
    jge @F
    mov rax, -2
    jmp isOut               ; exit if startpos not 1 or greater
  @@:

    dec startpos            ; correct from 1 to 0 based index

    cmp  rax, sLen
    jl @F
    mov rax, -1
    jmp isOut               ; exit if pattern longer than source
  @@:

    sub sLen, rax           ; don't read past string end
    inc sLen

    mov rcx, sLen
    cmp rcx, startpos
    jg @F
    mov rax, -2
    jmp isOut               ; exit if startpos is past end
  @@:

  ; ----------------
  ; setup loop code
  ; ----------------
    mov rsi, lpSource
    mov rdi, lpPattern
    mov al, [rdi]           ; get 1st char in pattern

    add rsi, rcx            ; add source length
    neg rcx                 ; invert sign
    add rcx, startpos       ; add starting offset

    jmp Scan_Loop

    align 16

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Pre_Scan:
    inc rcx                 ; start on next byte

  Scan_Loop:
    cmp al, [rsi+rcx]       ; scan for 1st byte of pattern
    je Pre_Match            ; test if it matches
    inc rcx
    js Scan_Loop            ; exit on sign inversion

    jmp No_Match

  Pre_Match:
    lea rbx, [rsi+rcx]      ; put current scan address in EBX
    mov rdx, pLen           ; put pattern length into EDX

  Test_Match:
    mov ah, [rbx+rdx-1]     ; load last byte of pattern length in main string
    cmp ah, [rdi+rdx-1]     ; compare it with last byte in pattern
    jne Pre_Scan            ; jump back on mismatch
    dec rdx
    jnz Test_Match          ; 0 = match, fall through on match

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Match:
    add rcx, sLen
    mov rax, rcx
    inc rax
    jmp isOut
    
  No_Match:
    xor rax, rax

  isOut:

    ret

InString endp

; ########################################################################

    end