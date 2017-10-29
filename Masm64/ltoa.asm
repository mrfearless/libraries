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

include windows.inc
includelib user32.lib

.code

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

ltoa proc FRAME lValue:QWORD, lpBuffer:QWORD

comment * -------------------------------------------------------
        convert signed 32 bit integer "lValue" to zero terminated
        string and store string at address in "lpBuffer"
        ------------------------------------------------------- *

    jmp @F
    fMtStrinG db "%ld",0
  @@:

    invoke wsprintf,lpBuffer,ADDR fMtStrinG,lValue
    cmp eax, 3
    jge @F
    xor eax, eax    ; zero EAX on fail
  @@:               ; else EAX contain count of bytes written

    ret

ltoa endp

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

end