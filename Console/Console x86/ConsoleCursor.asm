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


;-----------------------------------------------------------------------------------------
; ConsoleShowCursor
;-----------------------------------------------------------------------------------------
ConsoleShowCursor PROC
    LOCAL hConOutput:DWORD
    LOCAL cci:CONSOLE_CURSOR_INFO  
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    mov cci.dwSize, SIZEOF cci
    mov cci.bVisible, TRUE
    Invoke SetConsoleCursorInfo, hConOutput, Addr cci
    ret
ConsoleShowCursor ENDP


;-----------------------------------------------------------------------------------------
; ConsoleHideCursor
;-----------------------------------------------------------------------------------------
ConsoleHideCursor PROC
    LOCAL hConOutput:DWORD
    LOCAL cci:CONSOLE_CURSOR_INFO
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    mov cci.dwSize, SIZEOF cci
    mov cci.bVisible, FALSE
    Invoke SetConsoleCursorInfo, hConOutput, Addr cci
    ret
ConsoleHideCursor ENDP

END