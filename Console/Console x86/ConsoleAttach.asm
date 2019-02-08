.686
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc


.CODE

;**************************************************************************
; ConsoleAttach
;**************************************************************************
ConsoleAttach PROC
    Invoke AttachConsole, ATTACH_PARENT_PROCESS
    ret
ConsoleAttach ENDP


;**************************************************************************
; ConsoleAttachProcess
;**************************************************************************
ConsoleAttachProcess PROC dwProcessID:DWORD
    .IF dwProcessID == NULL
        Invoke GetCurrentProcessId
    .ELSE
        mov eax, dwProcessID
    .ENDIF
    Invoke AttachConsole, eax
    ret
ConsoleAttachProcess ENDP


END




