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
; ConsoleStdErr - taken from masm32 lib
;**************************************************************************
ConsoleStdErr PROC FRAME lpszErrText:QWORD
    LOCAL hConOutput:QWORD
    LOCAL qwBytesWritten:QWORD
    LOCAL qwLenConText:QWORD

    Invoke GetStdHandle, STD_ERROR_HANDLE
    mov hConOutput, rax

    Invoke lstrlen, lpszErrText
    mov qwLenConText, rax

    Invoke WriteFile, hConOutput, lpszErrText, dword ptr qwLenConText, Addr qwBytesWritten, NULL

    mov rax, qwBytesWritten
    ret
ConsoleStdErr ENDP












END
