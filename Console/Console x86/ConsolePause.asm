.686
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc

EXTERNDEF ConsoleStdOut :PROTO :DWORD

.DATA
szConMsgPressAnyKeyCont       DB "Press any key to continue...",0
szConMsgPressAnyKeyExit       DB "Press any key to exit...",0

.CODE

;**************************************************************************
; ConsolePause
;**************************************************************************
ConsolePause PROC PUBLIC USES EBX dwConMsgType:DWORD
    LOCAL hConInput:DWORD
    LOCAL lpNumberOfEventsRead:DWORD
    LOCAL ConInputBuffer:INPUT_RECORD
    
    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, eax

    mov eax, dwConMsgType
    .IF eax == CON_PAUSE_ANY_KEY_CONTINUE
        Invoke ConsoleStdOut, Addr szConMsgPressAnyKeyCont
    .ELSEIF eax == CON_PAUSE_ANY_KEY_EXIT
        Invoke ConsoleStdOut, Addr szConMsgPressAnyKeyExit
    .ENDIF

again:  

    Invoke ReadConsoleInput, hConInput, Addr ConInputBuffer, 1, Addr lpNumberOfEventsRead
    lea ebx, ConInputBuffer
    movzx eax, word ptr [ebx].INPUT_RECORD.EventType
    .IF eax != KEY_EVENT
        jmp again
    .ENDIF
    ;cmp ConsoleInputBuffer.EventType, KEY_EVENT
    ;jnz again
    
    lea ebx, ConInputBuffer
    mov eax, [ebx].INPUT_RECORD.KeyEvent.bKeyDown
    .IF eax == 0
        jmp again
    .ENDIF
    ;cmp ConsoleInputBuffer.KeyEvent.bKeyDown, 0
    ;jz again
    
    ret


ConsolePause ENDP


END