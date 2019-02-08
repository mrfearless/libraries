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


ConsoleCls PROC
    Invoke ConsoleClearScreen
    ret
ConsoleCls ENDP


;-----------------------------------------------------------------------------------------
; ClearConsoleScreen - taken from masm32 lib
;
; This procedure reads the column and row count, multiplies them together to get the 
; number of characters that will fit onto the screen, writes that number of blank spaces 
; to the screen, set the screen buffer attributes and reposition the prompt at position 0,0.
;
;-----------------------------------------------------------------------------------------
ConsoleClearScreen PROC USES EBX
    LOCAL hConOutput:DWORD
    LOCAL noc:DWORD
    LOCAL cnt:DWORD
    LOCAL sbi:CONSOLE_SCREEN_BUFFER_INFO

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax

    Invoke GetConsoleScreenBufferInfo, hConOutput, Addr sbi
    mov eax, sbi.dwSize ; 2 word values returned for screen size

    ; extract the 2 values and multiply them together
    mov ebx, eax
    shr eax, 16
    mul bx
    mov cnt, eax

    Invoke FillConsoleOutputCharacter, hConOutput, 32, cnt, NULL, Addr noc
    movzx ebx, sbi.wAttributes
    Invoke FillConsoleOutputAttribute, hConOutput, ebx, cnt, NULL, Addr noc
    Invoke SetConsoleCursorPosition, hConOutput, NULL
    ret
ConsoleClearScreen ENDP

END



