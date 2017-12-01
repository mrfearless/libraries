.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include user32.inc
includelib user32.lib

include Console.inc


.DATA
szSetConsoleIconProc    db "SetConsoleIcon", 0
szConKernel32Proc       db "kernel32.dll",0


.CODE


;-----------------------------------------------------------------------------------------
; ConsoleSetIcon
;-----------------------------------------------------------------------------------------
ConsoleSetIcon PROC IcoResID:DWORD
    LOCAL hMod:DWORD
    LOCAL hModKernel32:DWORD
    LOCAL hConIcon:DWORD
    
    .IF IcoResID == 0
        ret
    .ENDIF
    
    Invoke GetModuleHandle, 0
    mov hMod, eax
    Invoke LoadIcon, hMod, IcoResID
    mov hConIcon, eax
   
    Invoke GetModuleHandle, Addr szConKernel32Proc
    mov hModKernel32, eax
   
    Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
    push hConIcon
    call eax ; call SetConsoleIcon with one parameter: handle of icon to set
    ret
ConsoleSetIcon endp


END