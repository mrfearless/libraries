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
; ConsoleStarted - Return TRUE if initialized via a console or FALSE if
; started from GUI (explorer)
;**************************************************************************
ConsoleStarted PROC FRAME
    Invoke ConsoleAttach, ATTACH_PARENT_PROCESS
    .IF rax == TRUE
        ;PrintText 'CON'
        Invoke ConsoleFree ;FreeConsole
        mov rax, TRUE
    .ELSE    
        ;PrintText 'GUI'
    .ENDIF
    ret
ConsoleStarted ENDP












END
