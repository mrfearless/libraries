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

;-----------------------------------------------------------------------------------------
; ConsoleShowCursor
;-----------------------------------------------------------------------------------------
ConsoleShowCursor PROC FRAME
    LOCAL hConOutput:QWORD
    LOCAL cci:CONSOLE_CURSOR_INFO  
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    mov cci.dwSize, SIZEOF cci
    mov cci.bVisible, TRUE
    Invoke SetConsoleCursorInfo, hConOutput, Addr cci
    ret
ConsoleShowCursor ENDP


;-----------------------------------------------------------------------------------------
; ConsoleHideCursor
;-----------------------------------------------------------------------------------------
ConsoleHideCursor PROC FRAME
    LOCAL hConOutput:QWORD
    LOCAL cci:CONSOLE_CURSOR_INFO
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    mov cci.dwSize, SIZEOF cci
    mov cci.bVisible, FALSE
    Invoke SetConsoleCursorInfo, hConOutput, Addr cci
    ret
ConsoleHideCursor ENDP












END
