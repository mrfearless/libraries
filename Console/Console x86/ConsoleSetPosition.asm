.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;-----------------------------------------------------------------------------------------
; ConsoleSetPos - taken from masm32 lib
;-----------------------------------------------------------------------------------------
ConsoleSetPos PROC USES EBX dwXpos:DWORD, dwYpos:DWORD
    LOCAL hConOutput:DWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    ; make both co-ordinates into a DWORD
    mov ebx, dwXpos
    mov eax, dwYpos
    shl eax, 16
    mov ax, bx

    Invoke SetConsoleCursorPosition, hConOutput, eax
    ret
ConsoleSetPos ENDP


END







