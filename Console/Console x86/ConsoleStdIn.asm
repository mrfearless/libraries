.686
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;**************************************************************************
; ConsoleStdIn - taken from masm32 lib
;**************************************************************************
ConsoleStdIn PROC USES EBX lpszConInputBuffer:DWORD, dwSizeConInputBuffer:DWORD
    LOCAL hConInput:DWORD
    LOCAL dwBytesRead:DWORD
    LOCAL hConOutput:DWORD

    Invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov hConOutput, eax
    
    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, eax

    Invoke SetConsoleMode, hConInput, ENABLE_LINE_INPUT or ENABLE_ECHO_INPUT or ENABLE_PROCESSED_INPUT
    Invoke ReadFile, hConInput, lpszConInputBuffer, dwSizeConInputBuffer, Addr dwBytesRead, NULL
    Invoke SetConsoleMode, hConOutput, ENABLE_PROCESSED_OUTPUT or ENABLE_WRAP_AT_EOL_OUTPUT	
    ; strip the CR LF from the result
    mov ebx, lpszConInputBuffer
    sub ebx, 1
  @@:
    add ebx, 1
    cmp BYTE PTR [ebx], 0
    je @F
    cmp BYTE PTR [ebx], 13
    jne @B
    mov BYTE PTR [ebx], 0
  @@:

    mov eax, dwBytesRead
    sub eax, 2
    ret
ConsoleStdIn ENDP


;**************************************************************************
; ConsoleStdInW - taken from masm32 lib
;**************************************************************************
ConsoleStdInW PROC USES EBX lpszWideConInputBuffer:DWORD, dwSizeWideConInputBuffer:DWORD
    LOCAL hConInput:DWORD
    LOCAL dwBytesRead:DWORD

    Invoke GetStdHandle, STD_INPUT_HANDLE
    mov hConInput, eax

    Invoke SetConsoleMode, hConInput, ENABLE_LINE_INPUT or ENABLE_ECHO_INPUT or ENABLE_PROCESSED_INPUT
    Invoke ReadFile, hConInput, lpszWideConInputBuffer, dwSizeWideConInputBuffer, Addr dwBytesRead, NULL

    ; strip the CR LF from the result
    mov ebx, lpszWideConInputBuffer
    sub ebx, 2
  @@:
    add ebx, 2
    cmp WORD PTR [ebx], 0
    je @F
    cmp WORD PTR [ebx], 13
    jne @B
    mov WORD PTR [ebx], 0
  @@:

    mov eax, dwBytesRead
    sub eax, 2
    ret
ConsoleStdInW ENDP


END