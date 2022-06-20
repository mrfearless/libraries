;==============================================================================
;
; VirtualStack Library x64
;
; Copyright (c) 2022 by fearless
;
; All Rights Reserved
;
; http://github.com/mrfearless
;
;
; This software is provided 'as-is', without any express or implied warranty. 
; In no event will the author be held liable for any damages arising from the 
; use of this software.
;
; Permission is granted to anyone to use this software for any non-commercial 
; program. If you use the library in an application, an acknowledgement in the
; application or documentation is appreciated but not required. 
;
; You are allowed to make modifications to the source code, but you must leave
; the original copyright notices intact and not misrepresent the origin of the
; software. It is not allowed to claim you wrote the original software. 
; Modified files must have a clear notice that the files are modified, and not
; in the original state. This includes the name of the person(s) who modified 
; the code. 
;
; If you want to distribute or redistribute any portion of this package, you 
; will need to include the full package in it's original state, including this
; license and all the copyrights.  
;
; While distributing this package (in it's original state) is allowed, it is 
; not allowed to charge anything for this. You may not sell or include the 
; package in any commercial package without having permission of the author. 
; Neither is it allowed to redistribute any of the package's components with 
; commercial applications.
;
;==============================================================================
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

;DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \UASM\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
    include \UASM\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF

include VirtualStack.inc

;------------------------------------------------------------------------------
; Prototypes for internal use
;------------------------------------------------------------------------------
_VirtualStackAddToUniqueList        PROTO :QWORD, :QWORD

;------------------------------------------------------------------------------
; Structures for internal use
;------------------------------------------------------------------------------
IFNDEF STACK
STACK                       STRUCT
    StackMaxHeight          DQ 0    ; Max size of entire stack.
    StackMaxDepth           DQ 0    ; Max depth (max items ever on stack)
    StackPointer            DQ 0    ; Current stack item pointer
    StackNoItems            DQ 0    ; Number of items currently in the stack
    StackData               DQ 0    ; ptr to stack data
    StackUniqueMaxHeight    DQ 0    ; Max size of entire unique stack. (size auto grows)
    StackUniqueNoItems      DQ 0    ; Number of unique items currently in the stack
    StackUniqueData         DQ 0    ; ptr to unique stack data
STACK                       ENDS
ENDIF


.CODE

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackCreate. Returns hVirtualStack in rax if succesful or NULL if 
; failed. qwStackSize is the size (max amount of stack items) to create on the 
; virtual stack
;------------------------------------------------------------------------------
VirtualStackCreate PROC FRAME USES RBX qwStackSize:QWORD, qwStackOptions:QWORD
    LOCAL nSize:QWORD
    LOCAL hStack:QWORD
    LOCAL hStackData:QWORD
    
    ; Create virtual stack
    Invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, SIZEOF STACK
    .IF rax == NULL
        ret
    .ENDIF
    mov hStack, rax

    ; Assign max height to virtual stack and calc space required for stack data size
    .IF qwStackSize == NULL
        mov rbx, VIRTUALSTACK_SIZE_MEDIUM
    .ELSE
        mov rbx, qwStackSize
    .ENDIF
    mov [rax].STACK.StackMaxHeight, rbx    
    mov rax, SIZEOF QWORD
    mul rbx
    mov nSize, rax
    
    ; Alloc space for stack data size
    Invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, nSize
    .IF rax == NULL
        Invoke GlobalFree, hStack
        mov rax, NULL
        ret
    .ENDIF
    mov hStackData, rax
    
    ; Store information into virtual stack header struct
    mov rbx, hStack
    mov [rbx].STACK.StackData, rax
    mov [rbx].STACK.StackPointer, -1
    mov [rbx].STACK.StackNoItems, 0
    mov [rbx].STACK.StackMaxDepth, 0
    mov [rbx].STACK.StackUniqueMaxHeight, 0 ; use StackUniqueSize to check if user specified this option later in VirtualStackPush (>0)

    ; Create unique list of stack items if option is specified
    mov rax, qwStackOptions
    .IF rax == VIRTUALSTACK_OPTION_UNIQUE
        mov rax, nSize
        shl rax, 4d ; x16
        ;mov rbx, 2d ; set size of unique list to 2 x existing virtual stack size
        ;mul rbx
        mov nSize, rax
        Invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, nSize
        .IF rax != NULL
            mov rbx, hStack
            mov [rbx].STACK.StackUniqueData, rax
            ;mov eax, nSize
            mov rax, [rbx].STACK.StackMaxHeight
            shl rax, 4d ; x16
            mov [rbx].STACK.StackUniqueMaxHeight, rax
        .ENDIF
    .ENDIF
    
    mov rax, hStack 
    ret
VirtualStackCreate ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackDelete. Deletes a virtual stack
;
; lpdwVirtualDeleteCallbackProc is address of callback (optional) Callback is 
; defined as having following parameters:
;
; <VirtualDeleteCallbackProc> hVirtualStack:DWORD, ptrStackItem:DWORD
;
; Consider the callback experimental for the moment.
; Calls VirtualDeleteCallbackProc with only unique items in stack so user can 
; free up resources allocated
;------------------------------------------------------------------------------
VirtualStackDelete PROC FRAME USES RBX RCX RDX hVirtualStack:QWORD, lpqwVirtualDeleteCallbackProc:QWORD
    LOCAL nStackMaxDepth:QWORD
    LOCAL hStackData:QWORD
    LOCAL hStackUniqueData:QWORD
    LOCAL nStackUniqueNoItems:QWORD
    LOCAL hStackUniqueItem:QWORD
    LOCAL nStackUniqueItem:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    .IF lpqwVirtualDeleteCallbackProc != NULL
        ; load up unique list if its not 0 and loop through items
        mov rbx, hVirtualStack
        mov rax, [rbx].STACK.StackUniqueNoItems
        .IF sqword ptr rax > 0 ; if there is unique stack items to process
            mov nStackUniqueNoItems, rax
            mov rax, [rbx].STACK.StackUniqueData
            mov hStackUniqueData, rax        
            mov nStackUniqueItem, 0
            mov rax, 0
            .WHILE rax < nStackUniqueNoItems
                mov rax, nStackUniqueItem
                mov rbx, hStackUniqueData
                mov rax, [rbx+rax*8]
                .IF rax != NULL
                    mov rdx, rax
                    mov rcx, hVirtualStack
                    mov rax, lpqwVirtualDeleteCallbackProc
                    call rax                     
                .ENDIF
                inc nStackUniqueItem
                mov rax, nStackUniqueItem
            .ENDW
        .ENDIF
    .ENDIF
    
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    .IF rax != NULL
        Invoke GlobalFree, rax
    .ENDIF
    mov rax, [rbx].STACK.StackUniqueData
    .IF rax != NULL
        Invoke GlobalFree, rax
    .ENDIF
    mov rax, hVirtualStack
    Invoke GlobalFree, rax

    mov rax, TRUE
    ret
VirtualStackDelete ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackPush. rax returns TRUE if succesful or FALSE otherwise. 
; qwPushValue is the value to 'push' onto the virtual stack
;------------------------------------------------------------------------------
VirtualStackPush PROC FRAME USES RBX hVirtualStack:QWORD, qwPushValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackMaxHeight:QWORD
    LOCAL nStackMaxDepth:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    mov hStackData, rax
    mov rax, [rbx].STACK.StackPointer
    mov nStackPointer, rax    
    mov rax, [rbx].STACK.StackMaxHeight
    mov nStackMaxHeight, rax
    mov rax, [rbx].STACK.StackMaxDepth
    mov nStackMaxDepth, rax    
    mov rax, [rbx].STACK.StackNoItems
    inc rax
    mov nStackNoItems, rax
    .IF rax > nStackMaxHeight
        mov rax, VIRTUALSTACK_STACKFULL
        ret
    .ENDIF
    
    inc nStackPointer
    mov rax, nStackPointer
    mov rbx, hStackData
    lea rax, [rbx+rax*8] ; current stack item address in eax
    mov rbx, rax
    mov rax, qwPushValue
    mov [rbx], rax ; save value to stack item address

    ; Add value to unique list
    Invoke _VirtualStackAddToUniqueList, hVirtualStack, qwPushValue
    .IF rax == VIRTUALSTACK_UNIQUEFULL
        mov rax, VIRTUALSTACK_UNIQUEFULL
        ret
    .ENDIF
    
    ; save pointer and item count back to stack header
    mov rbx, hVirtualStack
    mov rax, nStackPointer 
    mov [rbx].STACK.StackPointer, rax
    mov rax, nStackNoItems   
    mov [rbx].STACK.StackNoItems, rax
    .IF rax > nStackMaxDepth
        mov [rbx].STACK.StackMaxDepth, rax
    .ENDIF
    mov rax, TRUE
    ret
VirtualStackPush ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackPop. rax returns TRUE if succesful and lpqwPopValue contains the 
; 'popped' value from the virtual stack, or FALSE otherwise. If stack is empty 
; (no more items on it) then rax returns -1
;------------------------------------------------------------------------------
VirtualStackPop PROC FRAME USES RBX hVirtualStack:QWORD, lpqwPopValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

;    .IF lpqwPopValue == NULL
;        xor eax, eax ; FALSE
;        ret
;    .ENDIF

    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    mov hStackData, rax
    mov rax, [rbx].STACK.StackPointer
    mov nStackPointer, rax    
    mov rax, [rbx].STACK.StackNoItems
    mov nStackNoItems, rax
    
    .IF nStackNoItems == 0
        mov rax, VIRTUALSTACK_STACKEMPTY ; stack empty 
        ret
    .ENDIF

    .IF lpqwPopValue != NULL ; in case user wants to pop stack and not care about value ?
        mov rax, nStackPointer
        mov rbx, hStackData
        mov rax, [rbx+rax*8] ; current stack item value in eax
        mov rbx, lpqwPopValue
        mov [rbx], rax ; save current stack item value to pop address variable
    .ENDIF
    
    ; save pointer and item count back to stack header
    dec nStackPointer
    dec nStackNoItems
    mov rbx, hVirtualStack
    mov rax, nStackPointer 
    mov [rbx].STACK.StackPointer, rax
    mov rax, nStackNoItems   
    mov [rbx].STACK.StackNoItems, rax

    mov rax, TRUE
    ret
VirtualStackPop ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackPeek. rax returns TRUE if succesful and lpqwPeekValue contains 
; the 'peeked' value from the virtual stack, or FALSE otherwise. If stack is 
; empty (no more items on it) then rax returns -1
;------------------------------------------------------------------------------
VirtualStackPeek PROC FRAME USES RBX hVirtualStack:QWORD, lpqwPeekValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpqwPeekValue == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    mov hStackData, rax
    mov rax, [rbx].STACK.StackPointer
    mov nStackPointer, rax    
    mov rax, [rbx].STACK.StackNoItems
    mov nStackNoItems, rax
    
    .IF nStackNoItems == 0
        mov rax, VIRTUALSTACK_STACKEMPTY ; stack empty   
        ret
    .ENDIF

    mov rax, nStackPointer
    mov rbx, hStackData
    mov rax, [rbx+rax*8] ; current stack item value in eax
    mov rbx, lpqwPeekValue
    mov [rbx], rax ; save current stack item value to pop address variable

    mov rax, TRUE
    ret
VirtualStackPeek ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackPeer. rax returns TRUE if succesful and lpqwPeerValue contains 
; the 'peered' value (peek +1 stack item), from the virtual stack, or FALSE 
; otherwise. If stack is empty (no more items on it) then rax returns -1
;------------------------------------------------------------------------------
VirtualStackPeer PROC FRAME USES RBX hVirtualStack:QWORD, lpqwPeerValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    LOCAL nStackMaxHeight:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpqwPeerValue == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    mov hStackData, rax
    mov rax, [rbx].STACK.StackPointer
    mov nStackPointer, rax
    mov rax, [rbx].STACK.StackMaxHeight
    mov nStackMaxHeight, rax
    mov rax, [rbx].STACK.StackNoItems
    mov nStackNoItems, rax
    
    .IF nStackNoItems == 0
        mov rax, VIRTUALSTACK_STACKEMPTY ; stack empty    
        ret
    .ELSE
        mov rax, nStackNoItems
        inc rax
        .IF rax > nStackMaxHeight
            mov rax, VIRTUALSTACK_STACKFULL
            ret
        .ENDIF        
    .ENDIF

;    mov eax, nStackPointer
;    mov rbx, SIZEOF DWORD
;    mul rbx
;    mov rbx, hStackData
;    add rbx, eax    
;    mov eax, [rbx]
;    mov rbx, lpdwPeerValue
;    mov [rbx], eax ; save current stack item value to pop address variable
    
    mov rax, nStackPointer
    inc rax ; peer = peek plus one
    mov rbx, hStackData
    mov rax, [rbx+rax*8] ; current stack item value in eax
    mov rbx, lpqwPeerValue
    mov [rbx], rax ; save current stack item value to pop address variable

    mov rax, TRUE
    ret
VirtualStackPeer endp

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackPeep. rax returns TRUE if succesful and lpqwPeepValue contains 
; the 'peeped' value (peek +N stack item), from the virtual stack, or FALSE 
; otherwise. If stack is empty (no more items on it) then rax returns -1
;------------------------------------------------------------------------------
VirtualStackPeep PROC FRAME USES RBX hVirtualStack:QWORD, lpqwPeepValue:QWORD, qwStackIndex:QWORD 
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    LOCAL nStackMaxHeight:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpqwPeepValue == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    mov hStackData, rax
    mov rax, [rbx].STACK.StackPointer
    mov nStackPointer, rax
    mov rax, [rbx].STACK.StackMaxHeight
    mov nStackMaxHeight, rax
    mov rax, [rbx].STACK.StackNoItems
    mov nStackNoItems, rax
    
    .IF nStackNoItems == 0
        mov rax, VIRTUALSTACK_STACKEMPTY ; stack empty    
        ret
    .ELSE
        mov rax, nStackNoItems
        add rax, qwStackIndex
        .IF rax > nStackMaxHeight
            mov rax, VIRTUALSTACK_STACKFULL
            ret
        .ENDIF        
    .ENDIF

    mov rax, nStackPointer
    add rax, qwStackIndex ; peep = peek + n
    mov rbx, hStackData
    mov rax, [rbx+rax*8] ; current stack item value in eax
    mov rbx, lpqwPeepValue
    mov [rbx], rax ; save current stack item value to pop address variable

    mov eax, TRUE
    ret
VirtualStackPeep ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackZero. Zeros the entire stack and resets it back to 0, clearing 
; all data
;------------------------------------------------------------------------------
VirtualStackZero PROC FRAME USES RBX hVirtualStack:QWORD
    LOCAL nSize:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackNoItems
    .IF rax == 0 ; nStackNoItems
        mov rax, TRUE ; stack already empty
        ret
    .ENDIF

    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackMaxHeight 
    .IF sqword ptr rax > 0
        mov rbx, SIZEOF QWORD
        mul rbx
        mov nSize, rax
        
        mov rbx, hVirtualStack
        mov rax, [rbx].STACK.StackData
        
        .IF nSize != 0 && rax != NULL
            Invoke RtlZeroMemory, rax, nSize
        .ENDIF
    .ENDIF

    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackUniqueMaxHeight
    .IF sqword ptr rax > 0
        mov rbx, SIZEOF DWORD
        mul rbx
        mov nSize, rax
        
        mov rbx, hVirtualStack
        mov rax, [rbx].STACK.StackUniqueData

        .IF nSize != 0 && rax != NULL
            Invoke RtlZeroMemory, rax, nSize
        .ENDIF        
    .ENDIF
    
    mov rbx, hVirtualStack
    mov [rbx].STACK.StackPointer, -1
    mov [rbx].STACK.StackNoItems, 0
    mov [rbx].STACK.StackMaxDepth, 0
    mov [rbx].STACK.StackUniqueNoItems, 0
    
    mov rax, TRUE
    ret
VirtualStackZero ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackCount. rax returns number of items on the stack
;------------------------------------------------------------------------------
VirtualStackCount PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackNoItems
    ret
VirtualStackCount ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackUniqueCount. rax returns number of unique items on the stack
;------------------------------------------------------------------------------
VirtualStackUniqueCount PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; 0
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackUniqueNoItems
    dec rax ; as unique is
    ret
VirtualStackUniqueCount ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackSize. rax returns size of virtual stack (max number of items) 
; on the stack
;------------------------------------------------------------------------------
VirtualStackSize PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackMaxHeight
    ret
VirtualStackSize ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackDepth. rax returns max depth of virtual stack (max number of 
; items ever) on the stack
;------------------------------------------------------------------------------
VirtualStackDepth PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackMaxDepth
    ret
VirtualStackDepth ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; VirtualStackData. rax returns pointer to StackData
;------------------------------------------------------------------------------
VirtualStackData PROC FRAME USES RBX hVirtualStack:QWORD
    LOCAL hStackData:DWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    ret
VirtualStackData ENDP

VIRTUALSTACK_ALIGN
;------------------------------------------------------------------------------
; _VirtualStackAddToUniqueList. True if unique, False if not unique, or eax 
; contains VIRTUALSTACK_UNIQUEFULL if GlobalRealloc failed and unique list is 
; at max capacity now
;------------------------------------------------------------------------------
_VirtualStackAddToUniqueList PROC FRAME USES RBX hVirtualStack:QWORD, qwUniqueValue:QWORD
    LOCAL hStackUniqueData:QWORD
    LOCAL nStackUniqueMaxHeight:QWORD
    LOCAL nStackUniqueNoItems:QWORD
    LOCAL nStackUniqueItem:QWORD
    LOCAL bUnique:QWORD
    LOCAL nSize:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackUniqueMaxHeight
    .IF sqword ptr rax > 0
        mov nStackUniqueMaxHeight, rax
        mov rax, [rbx].STACK.StackUniqueData
        mov hStackUniqueData, rax
        mov rax, [rbx].STACK.StackUniqueNoItems
        mov nStackUniqueNoItems, rax
        
        ; check if dwUniqueValue is actually unique and hasnt been stored before in list
        mov bUnique, TRUE
        mov nStackUniqueItem, 0
        mov rax, 0
        .WHILE rax < nStackUniqueNoItems
            
            mov rax, nStackUniqueItem
            mov rbx, hStackUniqueData
            mov rax, [rbx+rax*8] ; current stack item value in eax
            .IF rax == qwUniqueValue || qwUniqueValue == NULL
                mov bUnique, FALSE
                .BREAK
            .ENDIF
            
            inc nStackUniqueItem
            mov rax, nStackUniqueItem
        .ENDW
        
        ; if unique we then add it to our list
        .IF bUnique == TRUE
            
            mov rax, nStackUniqueNoItems
            .IF rax == nStackUniqueMaxHeight ; realloc memory if we are at max of list
                
                mov rbx, hVirtualStack
                mov rax, [rbx].STACK.StackMaxHeight
                shl rax, 4d ; x16
                .IF nStackUniqueMaxHeight > rax
                    Invoke GlobalUnlock, hStackUniqueData
                .ENDIF
                mov rax, nStackUniqueMaxHeight
                add rax, nStackUniqueMaxHeight
                mov nStackUniqueMaxHeight, rax
                mov rbx, SIZEOF DWORD
                mul rbx
                mov nSize, rax
                
                Invoke GlobalReAlloc, hStackUniqueData, nSize, GMEM_ZEROINIT + GMEM_MOVEABLE ; resize memory for structure
                .IF rax == NULL
                    mov rax, VIRTUALSTACK_UNIQUEFULL
                    ret
                .ENDIF
                
                ; save realloc data and updated max height back
                Invoke GlobalLock, rax
                mov hStackUniqueData, rax
                mov rbx, hVirtualStack
                mov [rbx].STACK.StackUniqueData, rax
                mov rax, nStackUniqueMaxHeight
                mov [rbx].STACK.StackUniqueMaxHeight, rax
            .ENDIF
            
            ; save data to list
            mov rax, nStackUniqueNoItems
            mov rbx, hStackUniqueData
            lea rax, [rbx+rax*8] ; current stack item address in eax
            mov rbx, rax
            mov rax, qwUniqueValue
            mov [rbx], rax ; save value to stack item address        
            
            ; Update unique items count
            inc nStackUniqueNoItems
            mov rbx, hVirtualStack
            mov rax, nStackUniqueNoItems
            mov [rbx].STACK.StackUniqueNoItems, rax
            
            mov rax, TRUE
            ret
            
        .ELSE
            xor eax, eax ; FALSE
            ret
        .ENDIF
        
    .ELSE
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    ret

_VirtualStackAddToUniqueList ENDP



end
