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
; ConsoleFree
;**************************************************************************
ConsoleFree PROC FRAME
    Invoke FreeConsole
    ret
ConsoleFree ENDP












END
