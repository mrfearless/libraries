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
includelib user32.lib

include Console.inc


.DATA
szSetConsoleIconProc    db "SetConsoleIcon", 0
szConKernel32Proc       db "kernel32.dll",0


.CODE


;-----------------------------------------------------------------------------------------
; ConsoleSetIcon
;-----------------------------------------------------------------------------------------
ConsoleSetIcon PROC FRAME IcoResID:QWORD
    LOCAL hMod:QWORD
    LOCAL hModKernel32:QWORD
    LOCAL hConIcon:QWORD
    
    .IF IcoResID == 0
        ret
    .ENDIF
    
    Invoke GetModuleHandle, 0
    mov hMod, rax
    Invoke LoadIcon, hMod, IcoResID
    mov hConIcon, rax
   
    Invoke GetModuleHandle, Addr szConKernel32Proc
    mov hModKernel32, rax
   
    Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
    mov rcx, hConIcon
    ;push hConIcon
    call rax ; call SetConsoleIcon with one parameter: handle of icon to set
    ret
ConsoleSetIcon endp






END
