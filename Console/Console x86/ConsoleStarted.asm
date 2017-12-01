.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;**************************************************************************
; ConsoleStarted - Return TRUE if initialized via a console or FALSE if
; started from GUI (explorer)
;**************************************************************************
ConsoleStarted PROC
    Invoke ConsoleAttach, ATTACH_PARENT_PROCESS
    .IF eax == TRUE
        ;PrintText 'CON'
        Invoke ConsoleFree ;FreeConsole
        mov eax, TRUE
    .ELSE    
        ;PrintText 'GUI'
    .ENDIF
    ret
ConsoleStarted ENDP

END    