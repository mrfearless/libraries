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

include Console.inc


.CODE

;**************************************************************************
; ConsoleStdOut - taken from masm32 lib
;**************************************************************************
ConsoleStdOut PROC FRAME lpszConText:QWORD
    LOCAL hConOutput:QWORD
    LOCAL qwBytesWritten:QWORD
    LOCAL qwLenConText:QWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    Invoke lstrlen, lpszConText
    mov qwLenConText, rax

    Invoke WriteFile, hConOutput, lpszConText, dword ptr qwLenConText, Addr qwBytesWritten, NULL

    mov rax, qwBytesWritten
    ret
ConsoleStdOut ENDP




END
