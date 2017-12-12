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

ConsoleAnimateIconProc  PROTO :QWORD, :QWORD


.DATA
szSetConsoleIconProc    DB "SetConsoleIcon", 0
szConKernel32Proc       DB "kernel32.dll",0
pSetConsoleIcon         DQ NULL
hQueueAnimateIcon       DQ NULL
hTimerAnimateIcon       DQ NULL
qwTimeAnimateIcon       DQ 0
AnimateIconHandles      DQ 0
qwAnimateIconTotalIcons DQ 0
qwCurrentIcon           DQ 0

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
    ;Invoke LoadIcon, hMod, IcoResID
    Invoke LoadImage, hMod, IcoResID, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
    mov hConIcon, rax
   
    .IF pSetConsoleIcon == NULL    
        Invoke GetModuleHandle, Addr szConKernel32Proc
        mov hModKernel32, rax
        Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
        mov pSetConsoleIcon, rax
    .ELSE
        mov rax, pSetConsoleIcon
    .ENDIF    
    
    mov rcx, hConIcon
    ;push hConIcon
    call rax ; call SetConsoleIcon with one parameter: handle of icon to set
    ret
ConsoleSetIcon endp


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconStart (was ConsoleAnimateIconInit) 
; IcoResIDStart - resource of icon to start animation from
; IcoResIDFinish - resource of icon to end animation on
; qwTime - time interval to animate
; if qwTimeIconStep != 0 then used to sleep between multiple calls to paint icons
; which can be useful if you have a series of icons to display in a sequence
; for example qwTime = 5000 (every 5secs) do a blinking eye animation
; with qwTimeIconStep the pause between each sequence icon: open, open, open, half open, close
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconStart PROC FRAME USES RBX IcoResIDStart:QWORD, IcoResIDFinish:QWORD, qwTime:QWORD, qwTimeIconStep:QWORD
    LOCAL hMod:QWORD
    LOCAL hModKernel32:QWORD    
    LOCAL qwSize:QWORD
    LOCAL nCurrentIcon:QWORD
    LOCAL ResCurrentIcon:QWORD
    LOCAL ptrAnimateIconEntry:QWORD

    .IF hQueueAnimateIcon != NULL
        mov qwCurrentIcon, 0
        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, dword ptr qwTimeAnimateIcon, dword ptr qwTimeAnimateIcon
    .ELSE

        .IF IcoResIDStart == 0 || IcoResIDFinish == 0
            mov rax, FALSE
            ret
        .ENDIF
        
        mov rbx, IcoResIDStart
        mov rax, IcoResIDFinish
        inc rax
        sub rax, rbx
        .IF sqword ptr rax < 1
            mov rax, FALSE
            ret
        .ENDIF
        mov qwAnimateIconTotalIcons, rax    
        mov qwCurrentIcon, 0
        
        .IF qwTime == 0
            mov rbx, 100
            mov rax, qwAnimateIconTotalIcons
            mul rbx
            add rax, 5000
        .ELSE
            mov rax, qwTime
        .ENDIF
        mov qwTimeAnimateIcon, rax
    
        .IF pSetConsoleIcon == NULL
            Invoke GetModuleHandle, Addr szConKernel32Proc
            mov hModKernel32, rax
            Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
            mov pSetConsoleIcon, rax
        .ENDIF
    
        Invoke CreateTimerQueue
        .IF rax != NULL
            mov hQueueAnimateIcon, rax
            
            mov rax, qwAnimateIconTotalIcons
            mov rbx, SIZEOF QWORD
            mul rbx
            mov qwSize, rax
            Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, qwSize
            .IF rax == NULL
                Invoke DeleteTimerQueueEx, hQueueAnimateIcon, FALSE
                mov hQueueAnimateIcon, NULL
                mov hTimerAnimateIcon, NULL        
                mov rax, FALSE
                ret
            .ENDIF
            mov AnimateIconHandles, rax
            
            ; loop, load icons, store handles in AnimateIconHandles
            Invoke GetModuleHandle, 0
            mov hMod, rax
            mov rax, AnimateIconHandles
            mov ptrAnimateIconEntry, rax
            mov rax, IcoResIDStart
            mov ResCurrentIcon, rax
            mov nCurrentIcon, 0
            mov rax, 0
            .WHILE rax < qwAnimateIconTotalIcons
                Invoke LoadImage, hMod, ResCurrentIcon, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
                mov rbx, ptrAnimateIconEntry
                mov [rbx], rax
                add ptrAnimateIconEntry, SIZEOF QWORD
                inc ResCurrentIcon
                inc nCurrentIcon
                mov rax, nCurrentIcon
            .ENDW
            
            Invoke CreateTimerQueueTimer, Addr hTimerAnimateIcon, hQueueAnimateIcon, Addr ConsoleAnimateIconProc, qwTimeIconStep, dword ptr qwTimeAnimateIcon, dword ptr qwTimeAnimateIcon, 0
            .IF rax == 0
                Invoke DeleteTimerQueueEx, hQueueAnimateIcon, FALSE
                mov hQueueAnimateIcon, NULL
                mov hTimerAnimateIcon, NULL            
                Invoke GlobalFree, AnimateIconHandles
                mov AnimateIconHandles, NULL
                mov rax, FALSE
            .ELSE
                mov rax, TRUE
            .ENDIF
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ENDIF
    
    ret
ConsoleAnimateIconStart ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconProc
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconProc PROC FRAME USES RBX lpParam:QWORD, TimerOrWaitFired:QWORD
    LOCAL nCurrentIcon:QWORD
    LOCAL ptrAnimateIconEntry:QWORD
    
    mov rax, AnimateIconHandles
    .IF rax == 0
        ret
    .ENDIF
    
    .IF lpParam != 0
        mov rax, AnimateIconHandles
        mov ptrAnimateIconEntry, rax
        mov rax, 0
        mov nCurrentIcon, 0
        .WHILE rax < qwAnimateIconTotalIcons
            mov rbx, ptrAnimateIconEntry
            mov rax, [rbx]
             .IF pSetConsoleIcon != NULL
                mov rcx, rax ;hConIcon; push rax
                mov rax, pSetConsoleIcon
                call rax
                Invoke SleepEx, dword ptr lpParam, FALSE
            .ENDIF
            add ptrAnimateIconEntry, SIZEOF QWORD
            inc nCurrentIcon
            mov rax, nCurrentIcon
        .ENDW
    
    .ELSE
    
        mov rax, SIZEOF QWORD
        mov rbx, qwCurrentIcon
        mul rbx
        add rax, AnimateIconHandles
        mov rbx, rax
        ;mov ptrAnimateIconEntry, rax
        ;mov rbx, ptrAnimateIconEntry
        mov rax, [rbx]
        .IF pSetConsoleIcon != NULL
            mov rcx, rax ;hConIcon; push rax
            mov rax, pSetConsoleIcon
            call rax
        .ENDIF
        
        inc qwCurrentIcon
        mov rax, qwCurrentIcon
        .IF rax == qwAnimateIconTotalIcons
            mov qwCurrentIcon, 0
        .ENDIF
    .ENDIF
    
    ret
ConsoleAnimateIconProc ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconStop
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconStop PROC FRAME USES RBX
    LOCAL RetVal:QWORD
    .IF hQueueAnimateIcon != NULL
        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, 0FFFFFFEh, 0
        mov qwCurrentIcon, 0
        mov RetVal, rax ; push rax
        ; reset icon to first one
        .IF pSetConsoleIcon != NULL
            mov rbx, AnimateIconHandles
            mov rax, [rbx]
            mov rcx, rax ;hConIcon ; push rax
            mov rax, pSetConsoleIcon
            call rax
        .ENDIF        
        mov rax, RetVal ;pop rax
    .ELSE
        mov rax, FALSE
    .ENDIF    
    ret
ConsoleAnimateIconStop ENDP




END
