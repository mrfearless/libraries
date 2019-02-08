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
; ConsoleSetTitle
;**************************************************************************
ConsoleSetTitle PROC lpszConTitle:DWORD
    Invoke SetConsoleTitle, lpszConTitle
    ret
ConsoleSetTitle ENDP


END




