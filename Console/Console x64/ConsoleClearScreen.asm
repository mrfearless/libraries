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
; ClearConsoleScreen - taken from masm32 lib
;
; This procedure reads the column and row count, multiplies them together to get the 
; number of characters that will fit onto the screen, writes that number of blank spaces 
; to the screen, set the screen buffer attributes and reposition the prompt at position 0,0.
;
;-----------------------------------------------------------------------------------------
ConsoleClearScreen PROC FRAME USES RBX
    LOCAL hConOutput:QWORD
    LOCAL noc:QWORD
    LOCAL cnt:DWORD
    LOCAL csbi:CONSOLE_SCREEN_BUFFER_INFO

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, rax

    Invoke GetConsoleScreenBufferInfo, hConOutput, Addr csbi
    xor rax, rax
    mov eax, csbi.dwSize ; 2 word values returned for screen size

    ; extract the 2 values and multiply them together
    mov rbx, rax
    shr rax, 16
    mul bx
    mov cnt, eax

    Invoke FillConsoleOutputCharacter, hConOutput, 32, cnt, NULL, Addr noc
    movzx ebx, csbi.wAttributes
    Invoke FillConsoleOutputAttribute, hConOutput, bx, cnt, NULL, Addr noc
    Invoke SetConsoleCursorPosition, hConOutput, NULL
    ret
ConsoleClearScreen ENDP


END




