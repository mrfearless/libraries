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


IFNDEF STACK
STACK                       STRUCT
    StackMaxHeight          DQ 0
    StackPointer            DQ 0
    StackNoItems            DQ 0
    StackData               DQ 0
STACK                       ENDS
ENDIF


.CODE


;-----------------------------------------------------------------------------------------
; VirtualStackCreate. Returns hVirtualStack in rax if succesful or NULL if failed. 
; dqStackSize is the size (max amount of stack items) to create on the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackCreate PROC FRAME USES RBX qwStackSize:QWORD
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
    
    mov rax, hStack 
    ret
VirtualStackCreate ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackDelete. Deletes a virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackDelete PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackData
    .IF rax != NULL
        Invoke GlobalFree, rax
    .ENDIF
    mov rax, hVirtualStack
    Invoke GlobalFree, rax
    
    mov rax, TRUE
    ret
VirtualStackDelete ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackPush. rax returns TRUE if succesful or FALSE otherwise. qwPushValue is the 
; value to 'push' onto the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackPush PROC FRAME USES RBX hVirtualStack:QWORD, qwPushValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackMaxHeight:QWORD
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
    mov rax, [rbx].STACK.StackNoItems
    inc rax
    mov nStackNoItems, rax
    .IF rax >= nStackMaxHeight
        mov rax, VIRTUALSTACK_STACKFULL
        ret
    .ENDIF
    
    inc nStackPointer
    mov rax, nStackPointer
    mov rbx, hStackData
    lea rax, [ebx+eax*8] ; current stack item address in eax
    mov rbx, rax
    mov rax, qwPushValue
    mov [rbx], rax ; save value to stack item address
    
    ; save pointer and item count back to stack header
    mov rbx, hVirtualStack
    mov rax, nStackPointer 
    mov [rbx].STACK.StackPointer, rax
    mov rax, nStackNoItems   
    mov [rbx].STACK.StackNoItems, rax

    mov rax, TRUE
    ret
VirtualStackPush ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackPop. rax returns TRUE if succesful and lpqwPopValue contains the 'popped'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then rax returns -1
;-----------------------------------------------------------------------------------------
VirtualStackPop PROC FRAME USES RBX hVirtualStack:QWORD, lpqwPopValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpqwPopValue == NULL
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
        mov rax, -1 ; stack empty    
        ret
    .ENDIF

    mov rax, nStackPointer
    mov rbx, hStackData
    mov rax, [ebx+eax*8] ; current stack item value in eax
    mov rbx, lpqwPopValue
    mov [rbx], rax ; save current stack item value to pop address variable
    
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


;-----------------------------------------------------------------------------------------
; VirtualStackPeek. rax returns TRUE if succesful and lpqwPeekValue contains the 'peeked'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then rax returns -1
;-----------------------------------------------------------------------------------------
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
        mov rax, -1 ; stack empty    
        ret
    .ENDIF

    mov rax, nStackPointer
    mov rbx, hStackData
    mov rax, [ebx+eax*8] ; current stack item value in eax
    mov rbx, lpqwPeekValue
    mov [rbx], rax ; save current stack item value to pop address variable

    mov rax, TRUE
    ret
VirtualStackPeek ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackCount. rax returns number of items on the stack
;-----------------------------------------------------------------------------------------
VirtualStackCount PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackNoItems
    ret
VirtualStackCount ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackCount. rax returns size of virtual stack (max number of items) on the stack
;-----------------------------------------------------------------------------------------
VirtualStackSize PROC FRAME USES RBX hVirtualStack:QWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov rbx, hVirtualStack
    mov rax, [rbx].STACK.StackMaxHeight
    ret
VirtualStackSize ENDP





end
