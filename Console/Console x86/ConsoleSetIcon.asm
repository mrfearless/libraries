.686
.MMX
.XMM
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include user32.inc
includelib user32.lib

include Console.inc

ConsoleAnimateIconProc  PROTO :DWORD, :DWORD
;ConsoleAnimateIconInit  PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; IcoResIDStart, IcoResIDFinish, dwTime, dwTimeIconStep
;ConsoleAnimateIconExit  PROTO   
;ConsoleAnimateIconStart PROTO 
;ConsoleAnimateIconStop  PROTO  


.DATA
szSetConsoleIconProc    db "SetConsoleIcon", 0
szConKernel32Proc       db "kernel32.dll",0
pSetConsoleIcon         DD NULL
hQueueAnimateIcon       DD NULL
hTimerAnimateIcon       DD NULL
dwTimeAnimateIcon       DD 0
AnimateIconHandles      DD 0
dwAnimateIconTotalIcons DD 0
dwCurrentIcon           DD 0

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
    ;.IF IcoResID != 0
        Invoke LoadImage, hMod, IcoResID, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
        ;Invoke LoadIcon, hMod, IcoResID
    ;.ELSE
    ;    mov eax, 0
    ;.ENDIF
    mov hConIcon, eax
        
    .IF pSetConsoleIcon == NULL
        Invoke GetModuleHandle, Addr szConKernel32Proc
        mov hModKernel32, eax
        Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
        mov pSetConsoleIcon, eax
    .ELSE
        mov eax, pSetConsoleIcon
    .ENDIF
    push hConIcon
    call eax ; call SetConsoleIcon with one parameter: handle of icon to set
    ret
ConsoleSetIcon endp


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconStart (was ConsoleAnimateIconInit) 
; IcoResIDStart - resource of icon to start animation from
; IcoResIDFinish - resource of icon to end animation on
; dwTime - time interval to animate
; if dwTimeIconStep != 0 then used to sleep between multiple calls to paint icons
; which can be useful if you have a series of icons to display in a sequence
; for example dwTime = 5000 (every 5secs) do a blinking eye animation
; with dwTimeIconStep the pause between each sequence icon: open, open, open, half open, close
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconStart PROC USES EBX IcoResIDStart:DWORD, IcoResIDFinish:DWORD, dwTime:DWORD, dwTimeIconStep:DWORD
    LOCAL hMod:DWORD
    LOCAL hModKernel32:DWORD    
    LOCAL dwSize:DWORD
    LOCAL nCurrentIcon:DWORD
    LOCAL ResCurrentIcon:DWORD
    LOCAL ptrAnimateIconEntry:DWORD
    
;    .IF hQueueAnimateIcon != NULL
;        mov eax, FALSE
;        ret
;    .ENDIF

    .IF hQueueAnimateIcon != NULL
        mov dwCurrentIcon, 0
        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, dwTimeAnimateIcon, dwTimeAnimateIcon
    .ELSE

        .IF IcoResIDStart == 0 || IcoResIDFinish == 0
            mov eax, FALSE
            ret
        .ENDIF
        
        mov ebx, IcoResIDStart
        mov eax, IcoResIDFinish
        inc eax
        sub eax, ebx
        .IF sdword ptr eax < 1
            mov eax, FALSE
            ret
        .ENDIF
        mov dwAnimateIconTotalIcons, eax    
        mov dwCurrentIcon, 0
        
        .IF dwTime == 0
            mov ebx, 100
            mov eax, dwAnimateIconTotalIcons
            mul ebx
            add eax, 5000
        .ELSE
            mov eax, dwTime
        .ENDIF
        mov dwTimeAnimateIcon, eax
    
        .IF pSetConsoleIcon == NULL
            Invoke GetModuleHandle, Addr szConKernel32Proc
            mov hModKernel32, eax
            Invoke GetProcAddress, hModKernel32, Addr szSetConsoleIconProc
            mov pSetConsoleIcon, eax
        .ENDIF
    
        Invoke CreateTimerQueue
        .IF eax != NULL
            mov hQueueAnimateIcon, eax
            
            mov eax, dwAnimateIconTotalIcons
            mov ebx, SIZEOF DWORD
            mul ebx
            mov dwSize, eax
            Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, dwSize
            .IF eax == NULL
                Invoke DeleteTimerQueueEx, hQueueAnimateIcon, FALSE
                mov hQueueAnimateIcon, NULL
                mov hTimerAnimateIcon, NULL        
                mov eax, FALSE
                ret
            .ENDIF
            mov AnimateIconHandles, eax
            
            ; loop, load icons, store handles in AnimateIconHandles
            Invoke GetModuleHandle, 0
            mov hMod, eax
            mov eax, AnimateIconHandles
            mov ptrAnimateIconEntry, eax
            mov eax, IcoResIDStart
            mov ResCurrentIcon, eax
            mov nCurrentIcon, 0
            mov eax, 0
            .WHILE eax < dwAnimateIconTotalIcons
                Invoke LoadImage, hMod, ResCurrentIcon, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
                mov ebx, ptrAnimateIconEntry
                mov [ebx], eax
                add ptrAnimateIconEntry, SIZEOF DWORD
                inc ResCurrentIcon
                inc nCurrentIcon
                mov eax, nCurrentIcon
            .ENDW
            
            Invoke CreateTimerQueueTimer, Addr hTimerAnimateIcon, hQueueAnimateIcon, Addr ConsoleAnimateIconProc, dwTimeIconStep, dwTimeAnimateIcon, dwTimeAnimateIcon, 0
            .IF eax == 0
                Invoke DeleteTimerQueueEx, hQueueAnimateIcon, FALSE
                mov hQueueAnimateIcon, NULL
                mov hTimerAnimateIcon, NULL            
                Invoke GlobalFree, AnimateIconHandles
                mov AnimateIconHandles, NULL
                mov eax, FALSE
            .ELSE
                mov eax, TRUE
            .ENDIF
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ENDIF
    
    ret
ConsoleAnimateIconStart ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconExit
;-----------------------------------------------------------------------------------------
;ConsoleAnimateIconExit PROC
;    .IF AnimateIconHandles != NULL
;        Invoke GlobalFree, AnimateIconHandles
;        mov AnimateIconHandles, NULL
;    .ENDIF
;    .IF hQueueAnimateIcon != NULL
;        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, 0FFFFFFEh, 0
;        Invoke DeleteTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, FALSE
;        Invoke DeleteTimerQueueEx, hQueueAnimateIcon, FALSE
;        mov hQueueAnimateIcon, NULL
;        mov hTimerAnimateIcon, NULL
;    .ENDIF
;    ret
;ConsoleAnimateIconExit ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconProc
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconProc PROC USES EBX lpParam:DWORD, TimerOrWaitFired:DWORD
    LOCAL nCurrentIcon:DWORD
    LOCAL ptrAnimateIconEntry:DWORD
    
    mov eax, AnimateIconHandles
    .IF eax == 0
        ret
    .ENDIF
    
    .IF lpParam != 0
        mov eax, AnimateIconHandles
        mov ptrAnimateIconEntry, eax
        mov eax, 0
        mov nCurrentIcon, 0
        .WHILE eax < dwAnimateIconTotalIcons
            mov ebx, ptrAnimateIconEntry
            mov eax, [ebx]
             .IF pSetConsoleIcon != NULL
                push eax
                mov eax, pSetConsoleIcon
                call eax
                Invoke SleepEx, lpParam, FALSE
            .ENDIF
            add ptrAnimateIconEntry, SIZEOF DWORD
            inc nCurrentIcon
            mov eax, nCurrentIcon
        .ENDW
    
    .ELSE
    
        mov eax, SIZEOF DWORD
        mov ebx, dwCurrentIcon
        mul ebx
        add eax, AnimateIconHandles
        mov ebx, eax
        ;mov ptrAnimateIconEntry, eax
        ;mov ebx, ptrAnimateIconEntry
        mov eax, [ebx]
        .IF pSetConsoleIcon != NULL
            push eax
            mov eax, pSetConsoleIcon
            call eax
        .ENDIF
        
        inc dwCurrentIcon
        mov eax, dwCurrentIcon
        .IF eax == dwAnimateIconTotalIcons
            mov dwCurrentIcon, 0
        .ENDIF
    .ENDIF
    
    ret
ConsoleAnimateIconProc ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconStart
;-----------------------------------------------------------------------------------------
;ConsoleAnimateIconStart PROC
;    .IF hQueueAnimateIcon != NULL
;        mov dwCurrentIcon, 0
;        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, dwTimeAnimateIcon, dwTimeAnimateIcon
;    .ELSE
;        mov eax, FALSE
;    .ENDIF
;    ret
;ConsoleAnimateIconStart ENDP


;-----------------------------------------------------------------------------------------
; ConsoleAnimateIconStop
;-----------------------------------------------------------------------------------------
ConsoleAnimateIconStop PROC USES EBX
    .IF hQueueAnimateIcon != NULL
        Invoke ChangeTimerQueueTimer, hQueueAnimateIcon, hTimerAnimateIcon, 0FFFFFFEh, 0
        mov dwCurrentIcon, 0
        push eax
        ; reset icon to first one
        .IF pSetConsoleIcon != NULL
            mov ebx, AnimateIconHandles
            mov eax, [ebx]
            push eax
            mov eax, pSetConsoleIcon
            call eax
        .ENDIF        
        pop eax
    .ELSE
        mov eax, FALSE
    .ENDIF    
    ret
ConsoleAnimateIconStop ENDP


END




