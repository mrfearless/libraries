.686
.MMX
.XMM
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc

ConsoleXYtoRowCol           PROTO :DWORD, :DWORD
ConsoleRowColtoXY           PROTO :DWORD, :DWORD, :DWORD
ConsoleSpinnerProc          PROTO :DWORD, :DWORD


.DATA
hQueueSpinner               DD NULL
hTimerSpinner               DD NULL
dwCurrentSpinStep           DD 0
dwTimeSpinStep              DD 150
dwSpinRowCol                DD 0
szConSpinStep1              DB '|',0
szConSpinStep2              DB '/',0
szConSpinStep3              DB '-',0
szConSpinStep4              DB '\',0
szConSpinBuffer             DB 4 DUP (0)


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


;-----------------------------------------------------------------------------------------
; ConsoleSetPosition - taken from masm32 lib
;-----------------------------------------------------------------------------------------
ConsoleSetPosition PROC USES EBX dwXpos:DWORD, dwYpos:DWORD
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
ConsoleSetPosition ENDP


;-----------------------------------------------------------------------------------------
; Convert X Y DWORD coord variables to DWORD RowCol value returned in eax 
;-----------------------------------------------------------------------------------------
ConsoleXYtoRowCol PROC USES EBX dwXpos:DWORD, dwYpos:DWORD
    mov ebx, dwXpos
    mov eax, dwYpos
    shl eax, 16
    mov ax, bx
    ret
ConsoleXYtoRowCol ENDP


;-----------------------------------------------------------------------------------------
; Convert DWORD dwRowCol parameter to seperate X Y DWORD coord variables
;-----------------------------------------------------------------------------------------
ConsoleRowColtoXY PROC USES EBX dwRowCol:DWORD, lpdwXpos:DWORD, lpdwYpos:DWORD
    LOCAL dwXpos:DWORD
    LOCAL dwYpos:DWORD
    
    mov eax, dwRowCol
    shr eax, 16
    mov dwYpos, eax
    mov ebx, lpdwYpos
    mov [ebx], eax
    mov eax, dwRowCol
    and eax, 0FFFFh
    mov dwXpos, eax
    mov ebx, lpdwXpos
    mov [ebx], eax
    mov eax, dwRowCol
    ret
ConsoleRowColtoXY ENDP


;-----------------------------------------------------------------------------------------
; Start a cmd line spinner at x y position. if x y is 0 then set a current location
;-----------------------------------------------------------------------------------------
ConsoleSpinnerStart PROC USES EBX dwXpos:DWORD, dwYpos:DWORD, dwXoffset:DWORD, dwYoffset:DWORD
    LOCAL dwX:DWORD
    LOCAL dwY:DWORD
    LOCAL hConOutput:DWORD
    LOCAL dwBytesRead:DWORD

    .IF dwXpos == 0 && dwYpos == 0
        Invoke ConsoleGetPosition, Addr dwX, Addr dwY
    .ELSE
        mov eax, dwXpos
        mov dwX, eax
        mov eax, dwYpos
        mov dwY, eax
    .ENDIF
    mov eax, dwX
    mov ebx, dwXoffset
    add eax, ebx
    mov dwX, eax
    
    mov eax, dwY
    mov ebx, dwYoffset
    add eax, ebx
    mov dwY, eax

    .IF hQueueSpinner == NULL
        Invoke CreateTimerQueue
        .IF eax != NULL
            mov hQueueSpinner, eax
            Invoke ConsoleXYtoRowCol, dwX, dwY
            mov dwSpinRowCol, eax
            
            ; Read original value for later
            Invoke GetStdHandle, STD_OUTPUT_HANDLE
            mov hConOutput, eax               
            Invoke ReadConsoleOutputCharacter, hConOutput, Addr szConSpinBuffer, 1, dwSpinRowCol, Addr dwBytesRead
            
            Invoke CreateTimerQueueTimer, Addr hTimerSpinner, hQueueSpinner, Addr ConsoleSpinnerProc, dwSpinRowCol, dwTimeSpinStep, dwTimeSpinStep, 0
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ELSE
        Invoke ChangeTimerQueueTimer, hQueueSpinner, hTimerSpinner, dwTimeSpinStep, dwTimeSpinStep
    .ENDIF
    ret
ConsoleSpinnerStart ENDP


;-----------------------------------------------------------------------------------------
; stops spinner
;-----------------------------------------------------------------------------------------
ConsoleSpinnerStop PROC
    LOCAL hConOutput:DWORD
    LOCAL dwBytesWritten:DWORD
    LOCAL dwX:DWORD
    LOCAL dwY:DWORD
    LOCAL dwRowCol:DWORD
    
    .IF hQueueSpinner != NULL
        Invoke ChangeTimerQueueTimer, hQueueSpinner, hTimerSpinner, 0FFFFFFEh, 0
        
        ; reset value back to what it was before
        Invoke ConsoleGetPosition, Addr dwX, Addr dwY
        Invoke ConsoleXYtoRowCol, dwX, dwY
        mov dwRowCol, eax        
        Invoke GetStdHandle, STD_OUTPUT_HANDLE
        mov hConOutput, eax    
        Invoke SetConsoleCursorPosition, hConOutput, dwSpinRowCol
        Invoke WriteFile, hConOutput, Addr szConSpinBuffer, 1, Addr dwBytesWritten, NULL
        Invoke SetConsoleCursorPosition, hConOutput, dwRowCol
    .ELSE
        mov eax, FALSE
    .ENDIF  
    ret
ConsoleSpinnerStop ENDP


;-----------------------------------------------------------------------------------------
; Spinner proc to write | / - \ to console output
;-----------------------------------------------------------------------------------------
ConsoleSpinnerProc PROC lpParam:DWORD, TimerOrWaitFired:DWORD
    LOCAL dwXpos:DWORD
    LOCAL dwYpos:DWORD
    LOCAL hConOutput:DWORD
    LOCAL dwBytesWritten:DWORD
    LOCAL lpszConText:DWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax    
    
    Invoke SetConsoleCursorPosition, hConOutput, dwSpinRowCol

    mov eax, dwCurrentSpinStep
    .IF eax == 0
        lea eax, szConSpinStep1
    .ELSEIF eax == 1
        lea eax, szConSpinStep2
    .ELSEIF eax == 2
        lea eax, szConSpinStep3
    .ELSEIF eax == 3
        lea eax, szConSpinStep4
    .ENDIF
    mov lpszConText, eax
    
    Invoke WriteFile, hConOutput, lpszConText, 1, Addr dwBytesWritten, NULL
    ;Invoke WriteConsoleOutput, hConOutput, eax, SIZEOF szConSpinStep1, lpParam, NULL
    
    inc dwCurrentSpinStep
    mov eax, dwCurrentSpinStep
    .IF eax == 4
        mov dwCurrentSpinStep, 0
    .ENDIF
    ret

ConsoleSpinnerProc ENDP


END







