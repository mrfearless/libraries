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
include wincon.inc

includelib kernel32.lib

include Console.inc


EXTERNDEF ConsoleStdOut :PROTO :QWORD



.DATA
szConMsgPressAnyKeyCont       DB "Press any key to continue...",0
szConMsgPressAnyKeyExit       DB "Press any key to exit...",0

.CODE

;**************************************************************************
; ConsolePause
;**************************************************************************
ConsolePause PROC FRAME USES RBX qwConMsgType:QWORD
    LOCAL hConInput:QWORD
    LOCAL lpNumberOfEventsRead:QWORD
    LOCAL ConInputBuffer:INPUT_RECORD
    
    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, rax

    mov rax, qwConMsgType
    .IF rax == CON_PAUSE_ANY_KEY_CONTINUE
        Invoke ConsoleStdOut, Addr szConMsgPressAnyKeyCont
    .ELSEIF rax == CON_PAUSE_ANY_KEY_EXIT
        Invoke ConsoleStdOut, Addr szConMsgPressAnyKeyExit
    .ENDIF

again:  

    Invoke ReadConsoleInput, hConInput, Addr ConInputBuffer, 1, Addr lpNumberOfEventsRead
    lea rbx, ConInputBuffer
    movzx rax, word ptr [rbx].INPUT_RECORD.EventType
    .IF rax != KEY_EVENT
        jmp again
    .ENDIF
    ;cmp ConsoleInputBuffer.EventType, KEY_EVENT
    ;jnz again
    
    lea rbx, ConInputBuffer
    mov eax, [rbx].INPUT_RECORD.Event.KeyEvent.bKeyDown
    .IF rax == 0
        jmp again
    .ENDIF
    ;cmp ConsoleInputBuffer.KeyEvent.bKeyDown, 0
    ;jz again
    
    ret
ConsolePause ENDP






END
