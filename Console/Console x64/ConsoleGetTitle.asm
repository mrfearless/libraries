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
; Console
;**************************************************************************
ConsoleGetTitle PROC FRAME lpszConTitle:QWORD, qwSizeConTitle:QWORD
    .IF lpszConTitle == 0 || qwSizeConTitle == 0
        xor eax, eax
        ret
    .ENDIF
    Invoke GetConsoleTitle, lpszConTitle, dword ptr qwSizeConTitle
    ret
ConsoleGetTitle ENDP












END
