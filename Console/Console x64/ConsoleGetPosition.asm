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

IFNDEF COORD
COORD STRUCT
  x  SWORD      ?
  y  SWORD      ?
COORD ENDS
ENDIF

.CODE

;-----------------------------------------------------------------------------------------
; ConsoleGetPosition
;-----------------------------------------------------------------------------------------
ConsoleGetPosition PROC FRAME USES RBX lpqwXpos:QWORD, lpqwYpos:QWORD
    LOCAL hConOutput:QWORD
    LOCAL csbi:CONSOLE_SCREEN_BUFFER_INFO
    LOCAL qwXpos:QWORD
    LOCAL qwYpos:QWORD
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    Invoke GetConsoleScreenBufferInfo, hConOutput, Addr csbi
    .IF rax == 0
        ret
    .ENDIF

    lea rbx, csbi
    movzx eax, word ptr [rbx].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition
    mov qwXpos, rax
    movzx eax, word ptr [rbx+2].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition
    mov qwYpos, rax
    
    mov rbx, lpqwXpos
    mov rax, qwXpos
    mov [rbx], rax
    
    mov rbx, lpqwYpos
    mov rax, qwYpos
    mov [rbx], rax
    
    mov rax, TRUE
    ret
ConsoleGetPosition ENDP












END
