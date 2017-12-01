.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;**************************************************************************
; ConsoleStdErr - taken from masm32 lib
;**************************************************************************
ConsoleStdErr PROC lpszErrText:DWORD
    LOCAL hConOutput:DWORD
    LOCAL dwBytesWritten:DWORD
    LOCAL dwLenConText:DWORD

    Invoke GetStdHandle, STD_ERROR_HANDLE
    mov hConOutput, eax

    Invoke lstrlen, lpszErrText
    mov dwLenConText, eax

    Invoke WriteFile, hConOutput, lpszErrText, dwLenConText, Addr dwBytesWritten, NULL

    mov eax, dwBytesWritten
    ret
ConsoleStdErr ENDP


END