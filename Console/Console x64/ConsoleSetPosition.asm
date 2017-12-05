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
; ConsoleSetPos - taken from masm32 lib
;-----------------------------------------------------------------------------------------
ConsoleSetPosition PROC FRAME USES RBX qwXpos:QWORD, qwYpos:QWORD
    LOCAL hConOutput:QWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    ; make both co-ordinates into a DWORD
    mov rbx, qwXpos
    mov rax, qwYpos
    shl rax, 16
    mov ax, bx

    Invoke SetConsoleCursorPosition, hConOutput, eax
    ret
ConsoleSetPosition ENDP












END
