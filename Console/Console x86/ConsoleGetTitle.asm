.686
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;**************************************************************************
; ConsoleGetTitle - returns length of chars in buffer or 0
;**************************************************************************
ConsoleGetTitle PROC lpszConTitle:DWORD, dwSizeConTitle:DWORD
    .IF lpszConTitle == 0 || dwSizeConTitle == 0
        xor eax, eax
        ret
    .ENDIF
    Invoke GetConsoleTitle, lpszConTitle, dwSizeConTitle
    ret
ConsoleGetTitle ENDP


END




