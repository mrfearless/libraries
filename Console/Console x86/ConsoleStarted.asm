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
; ConsoleStarted - Return TRUE if initialized via GUI (explorer)or FALSE if
; started from console
;**************************************************************************
ConsoleStarted PROC
    LOCAL pidbuffer:DWORD
    Invoke GetConsoleProcessList, Addr pidbuffer, 2
    ;PrintDec eax
    .IF eax == 2
        ;PrintText 'CON'
        mov eax, TRUE
    .ELSE    
        ;PrintText 'CON'
        mov eax, FALSE
    .ENDIF
    ret
ConsoleStarted ENDP

END    