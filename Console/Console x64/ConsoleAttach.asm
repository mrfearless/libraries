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

.CONST
IFNDEF ATTACH_PARENT_PROCESS
ATTACH_PARENT_PROCESS            equ -1
ENDIF

.CODE

;**************************************************************************
; ConsoleAttach
;**************************************************************************
ConsoleAttach PROC FRAME
    Invoke AttachConsole, ATTACH_PARENT_PROCESS
    ret
ConsoleAttach ENDP












END
