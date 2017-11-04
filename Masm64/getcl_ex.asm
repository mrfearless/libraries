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

include windows.inc
includelib kernel32.lib

EXTERNDEF ArgByNumber :PROTO :QWORD, :QWORD, :QWORD, :QWORD

.code

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

align 8

getcl_ex proc FRAME num:QWORD, pbuf:QWORD

 ; 1 = successful operation
 ; 2 = no argument exists at specified arg number
 ; 3 = non matching quotation marks

    add num, 1
    Invoke GetCommandLine
    invoke ArgByNumber, rax, pbuf, num, 0

    .if rax >= 0
      mov rcx, pbuf
      .if BYTE PTR [rcx] != 0
        mov rax, 1                      ; successful operation
      .else
        mov rax, 2                      ; no argument at specified number
      .endif
    .elseif rax == -1
      mov rax, 3                        ; non matching quotation marks
    .endif

    ret

getcl_ex endp

; いいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいいい

end