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

ConsoleXYtoRowCol           PROTO :QWORD, :QWORD
ConsoleRowColtoXY           PROTO :QWORD, :QWORD, :QWORD
ConsoleSpinnerProc          PROTO :QWORD, :QWORD


IFNDEF COORD
COORD STRUCT
  x  SWORD      ?
  y  SWORD      ?
COORD ENDS
ENDIF


.DATA
hQueueSpinner               DQ NULL
hTimerSpinner               DQ NULL
qwCurrentSpinStep           DQ 0
qwTimeSpinStep              DQ 150
qwSpinRowCol                DQ 0
szConSpinStep1              DB '|',0
szConSpinStep2              DB '/',0
szConSpinStep3              DB '-',0
szConSpinStep4              DB '\',0
szConSpinBuffer             DB 4 DUP (0)


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
    movzx rax, word ptr [rbx].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition
    mov qwXpos, rax
    movzx rax, word ptr [rbx+2].CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition
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


;-----------------------------------------------------------------------------------------
; ConsoleSetPosition - taken from masm32 lib
;-----------------------------------------------------------------------------------------
ConsoleSetPosition PROC FRAME USES RBX qwXpos:QWORD, qwYpos:QWORD
    LOCAL hConOutput:QWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    ; make both co-ordinates into a QWORD
    mov rbx, qwXpos
    mov rax, qwYpos
    shl rax, 16
    mov ax, bx

    Invoke SetConsoleCursorPosition, hConOutput, eax
    ret
ConsoleSetPosition ENDP


;-----------------------------------------------------------------------------------------
; Convert X Y QWORD coord variables to QWORD RowCol value returned in rax 
;-----------------------------------------------------------------------------------------
ConsoleXYtoRowCol PROC FRAME USES RBX qwXpos:QWORD, qwYpos:QWORD
    mov rbx, qwXpos
    mov rax, qwYpos
    shl rax, 16
    mov ax, bx
    ret
ConsoleXYtoRowCol ENDP


;-----------------------------------------------------------------------------------------
; Convert QWORD qwRowCol parameter to seperate X Y QWORD coord variables
;-----------------------------------------------------------------------------------------
ConsoleRowColtoXY PROC USES RBX qwRowCol:QWORD, lpqwXpos:QWORD, lpqwYpos:QWORD
    LOCAL qwXpos:QWORD
    LOCAL qwYpos:QWORD
    
    mov rax, qwRowCol
    shr rax, 16
    mov qwYpos, rax
    mov rbx, lpqwYpos
    mov [rbx], rax
    mov rax, qwRowCol
    and rax, 0FFFFh
    mov qwXpos, rax
    mov rbx, lpqwXpos
    mov [rbx], rax
    mov rax, qwRowCol
    ret
ConsoleRowColtoXY ENDP


;-----------------------------------------------------------------------------------------
; Start a cmd line spinner at x y position. if x y is 0 then set a current location
;-----------------------------------------------------------------------------------------
ConsoleSpinnerStart PROC FRAME USES RBX qwXpos:QWORD, qwYpos:QWORD, qwXoffset:QWORD, qwYoffset:QWORD
    LOCAL qwX:QWORD
    LOCAL qwY:QWORD
    LOCAL hConOutput:QWORD
    LOCAL qwBytesRead:QWORD

    .IF qwXpos == 0 && qwYpos == 0
        Invoke ConsoleGetPosition, Addr qwX, Addr qwY
    .ELSE
        mov rax, qwXpos
        mov qwX, rax
        mov rax, qwYpos
        mov qwY, rax
    .ENDIF
    mov rax, qwX
    mov rbx, qwXoffset
    add rax, rbx
    mov qwX, rax
    
    mov rax, qwY
    mov rbx, qwYoffset
    add rax, rbx
    mov qwY, rax

    .IF hQueueSpinner == NULL
        Invoke CreateTimerQueue
        .IF rax != NULL
            mov hQueueSpinner, rax
            Invoke ConsoleXYtoRowCol, qwX, qwY
            mov qwSpinRowCol, rax
            
            ; Read original value for later
            Invoke GetStdHandle, STD_OUTPUT_HANDLE
            mov hConOutput, rax               
            Invoke ReadConsoleOutputCharacter, hConOutput, Addr szConSpinBuffer, 1, dword ptr qwSpinRowCol, Addr qwBytesRead
            
            Invoke CreateTimerQueueTimer, Addr hTimerSpinner, hQueueSpinner, Addr ConsoleSpinnerProc, qwSpinRowCol, dword ptr qwTimeSpinStep, dword ptr qwTimeSpinStep, 0
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ELSE
        Invoke ChangeTimerQueueTimer, hQueueSpinner, hTimerSpinner, dword ptr qwTimeSpinStep, dword ptr qwTimeSpinStep
    .ENDIF
    ret
ConsoleSpinnerStart ENDP


;-----------------------------------------------------------------------------------------
; stops spinner
;-----------------------------------------------------------------------------------------
ConsoleSpinnerStop PROC FRAME
    LOCAL hConOutput:QWORD
    LOCAL qwBytesWritten:QWORD
    LOCAL qwX:QWORD
    LOCAL qwY:QWORD
    LOCAL qwRowCol:QWORD
    
    .IF hQueueSpinner != NULL
        Invoke ChangeTimerQueueTimer, hQueueSpinner, hTimerSpinner, 0FFFFFFEh, 0
        
        ; reset value back to what it was before
        Invoke ConsoleGetPosition, Addr qwX, Addr qwY
        Invoke ConsoleXYtoRowCol, qwX, qwY
        mov qwRowCol, rax        
        Invoke GetStdHandle, STD_OUTPUT_HANDLE
        mov hConOutput, rax    
        Invoke SetConsoleCursorPosition, hConOutput, dword ptr qwSpinRowCol
        Invoke WriteFile, hConOutput, Addr szConSpinBuffer, 1, Addr qwBytesWritten, NULL
        Invoke SetConsoleCursorPosition, hConOutput, dword ptr qwRowCol
    .ELSE
        mov rax, FALSE
    .ENDIF  
    ret
ConsoleSpinnerStop ENDP


;-----------------------------------------------------------------------------------------
; Spinner proc to write | / - \ to console output
;-----------------------------------------------------------------------------------------
ConsoleSpinnerProc PROC FRAME lpParam:QWORD, TimerOrWaitFired:QWORD
    LOCAL qwXpos:QWORD
    LOCAL qwYpos:QWORD
    LOCAL hConOutput:QWORD
    LOCAL qwBytesWritten:QWORD
    LOCAL lpszConText:QWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax    
    
    Invoke SetConsoleCursorPosition, hConOutput, dword ptr qwSpinRowCol

    mov rax, qwCurrentSpinStep
    .IF rax == 0
        lea rax, szConSpinStep1
    .ELSEIF rax == 1
        lea rax, szConSpinStep2
    .ELSEIF rax == 2
        lea rax, szConSpinStep3
    .ELSEIF rax == 3
        lea rax, szConSpinStep4
    .ENDIF
    mov lpszConText, rax
    
    Invoke WriteFile, hConOutput, lpszConText, 1, Addr qwBytesWritten, NULL
    ;Invoke WriteConsoleOutput, hConOutput, rax, SIZEOF szConSpinStep1, lpParam, NULL
    
    inc qwCurrentSpinStep
    mov rax, qwCurrentSpinStep
    .IF rax == 4
        mov qwCurrentSpinStep, 0
    .ENDIF
    ret

ConsoleSpinnerProc ENDP


END
