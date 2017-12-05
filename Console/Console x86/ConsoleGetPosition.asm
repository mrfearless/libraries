.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;-----------------------------------------------------------------------------------------
; ConsoleGetPosition
;-----------------------------------------------------------------------------------------
ConsoleGetPosition PROC USES EBX lpdwXpos:DWORD, lpdwYpos:DWORD
    LOCAL hConOutput:DWORD
    LOCAL csbi:CONSOLE_SCREEN_BUFFER_INFO
    LOCAL dwXpos:DWORD
    LOCAL dwYpos:DWORD
    
    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    Invoke GetConsoleScreenBufferInfo, hConOutput, Addr csbi
    .IF eax == 0
        ret
    .ENDIF

    lea ebx, csbi
    movzx eax, word ptr [ebx].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition.x
    mov dwXpos, eax
    movzx eax, word ptr [ebx].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition.y
    mov dwYpos, eax
    
    mov ebx, lpdwXpos
    mov eax, dwXpos
    mov [ebx], eax
    
    mov ebx, lpdwYpos
    mov eax, dwYpos
    mov [ebx], eax
    
    mov eax, TRUE
    ret
ConsoleGetPosition ENDP


END







