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

;include masm64.inc
;includelib masm64.lib

include VirtualStack.inc


IFNDEF STACK
STACK                       STRUCT
    StackMaxHeight          DQ 0
    StackPointer            DQ 0
    StackNoItems            DQ 0
    StackData               DQ 0
STACK                       ENDS
ENDIF


.DATA



.CODE

;-----------------------------------------------------------------------------------------
; VirtualStackCreate. Returns hVirtualStack in rax if succesful or NULL if failed. 
; dqStackSize is the size (max amount of stack items) to create on the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackCreate PROC FRAME USES RBX dqStackSize:QWORD
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
    .IF dqStackSize == NULL
        mov rbx, VIRTUALSTACK_SIZE_MEDIUM
    .ELSE
        mov rbx, dqStackSize
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

VirtualStackDelete endp


;-----------------------------------------------------------------------------------------
; VirtualStackPush. rax returns TRUE if succesful or FALSE otherwise. dqPushValue is the 
; value to 'push' onto the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackPush PROC FRAME USES RBX hVirtualStack:QWORD, dqPushValue:QWORD
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
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    inc nStackPointer
    mov rax, nStackPointer
    mov rbx, hStackData
    lea rax, [ebx+eax*8] ; current stack item address in eax
    mov rbx, rax
    mov rax, dqPushValue
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
; VirtualStackPop. rax returns TRUE if succesful and lpsqPopValue contains the 'popped'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then rax returns -1
;-----------------------------------------------------------------------------------------
VirtualStackPop PROC FRAME USES RBX hVirtualStack:QWORD, lpdqPopValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpdqPopValue == NULL
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
    mov rbx, lpdqPopValue
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
; VirtualStackPeek. rax returns TRUE if succesful and lpsqPeekValue contains the 'peeked'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then rax returns -1
;-----------------------------------------------------------------------------------------
VirtualStackPeek PROC FRAME USES RBX hVirtualStack:QWORD, lpdqPeekValue:QWORD
    LOCAL hStackData:QWORD
    LOCAL nStackNoItems:QWORD
    LOCAL nStackPointer:QWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpdqPeekValue == NULL
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
    mov rbx, lpdqPeekValue
    mov [rbx], rax ; save current stack item value to pop address variable

    mov rax, TRUE

    ret

VirtualStackPeek endp


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
