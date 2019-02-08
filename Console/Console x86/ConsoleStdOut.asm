.686
.MMX
.XMM
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE


;**************************************************************************
; ConsoleText - alias for ConsoleStdOut
;**************************************************************************
ConsoleText PROC lpszConText:DWORD
    Invoke ConsoleStdOut, lpszConText
ConsoleText ENDP


;**************************************************************************
; ConsoleStdOut - taken from masm32 lib
;**************************************************************************
ConsoleStdOut PROC lpszConText:DWORD
    LOCAL hConOutput:DWORD
    LOCAL dwBytesWritten:DWORD
    LOCAL dwLenConText:DWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    Invoke lstrlen, lpszConText
    mov dwLenConText, eax

    Invoke WriteFile, hConOutput, lpszConText, dwLenConText, Addr dwBytesWritten, NULL

    mov eax, dwBytesWritten
    ret
ConsoleStdOut ENDP


END