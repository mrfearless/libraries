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

;**************************************************************************
; ConsoleStdIn - taken from masm32 lib
;**************************************************************************
ConsoleStdIn PROC FRAME USES RBX lpszConInputBuffer:QWORD, qwSizeConInputBuffer:QWORD
    LOCAL hConInput:QWORD
    LOCAL qwBytesRead:QWORD

    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, rax

    Invoke SetConsoleMode, hConInput, ENABLE_LINE_INPUT or ENABLE_ECHO_INPUT or ENABLE_PROCESSED_INPUT
    Invoke ReadFile, hConInput, lpszConInputBuffer, dword ptr qwSizeConInputBuffer, Addr qwBytesRead, NULL

    ; strip the CR LF from the result
    mov rbx, lpszConInputBuffer
    sub rbx, 1
  @@:
    add rbx, 1
    cmp BYTE PTR [rbx], 0
    je @F
    cmp BYTE PTR [rbx], 13
    jne @B
    mov BYTE PTR [rbx], 0
  @@:

    mov rax, qwBytesRead
    sub rax, 2
    ret
ConsoleStdIn ENDP


;**************************************************************************
; ConsoleStdInW - taken from masm32 lib
;**************************************************************************
ConsoleStdInW PROC FRAME USES RBX lpszWideConInputBuffer:QWORD, qwSizeWideConInputBuffer:QWORD
    LOCAL hConInput:QWORD
    LOCAL qwBytesRead:QWORD

    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, rax

    Invoke SetConsoleMode, hConInput, ENABLE_LINE_INPUT or ENABLE_ECHO_INPUT or ENABLE_PROCESSED_INPUT
    Invoke ReadFile, hConInput, lpszWideConInputBuffer, dword ptr qwSizeWideConInputBuffer, Addr qwBytesRead, NULL

    ; strip the CR LF from the result
    mov rbx, lpszWideConInputBuffer
    sub rbx, 2
  @@:
    add rbx, 2
    cmp WORD PTR [rbx], 0
    je @F
    cmp WORD PTR [rbx], 13
    jne @B
    mov WORD PTR [rbx], 0
  @@:

    mov rax, qwBytesRead
    sub rax, 2
    ret
ConsoleStdInW ENDP




END
