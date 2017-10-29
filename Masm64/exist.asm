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

include windows.inc
includelib kernel32.lib

.code

; #########################################################################

exist proc FRAME lpszFileName:QWORD

    LOCAL wfd:WIN32_FIND_DATA

    invoke FindFirstFile,lpszFileName,ADDR wfd
    .if rax == INVALID_HANDLE_VALUE
      mov rax, 0                    ; 0 = NOT exist
    .else
      invoke FindClose, rax
      mov rax, 1                    ; 1 = exist
    .endif

    ret

exist endp

; #########################################################################

end