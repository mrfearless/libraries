.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    include M:\Masm32\include\debug32.inc
ENDIF

include windows.inc

include user32.inc
includelib user32.lib

include kernel32.inc
includelib kernel32.lib

include VirtualStack.inc

IFNDEF STACK
STACK                       STRUCT
    StackMaxHeight          DD 0
    StackPointer            DD 0
    StackNoItems            DD 0
    StackData               DD 0
STACK                       ENDS
ENDIF

.CODE

;-----------------------------------------------------------------------------------------
; VirtualStackCreate. Returns hVirtualStack in eax if succesful or NULL if failed. 
; dwStackSize is the size (max amount of stack items) to create on the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackCreate PROC USES EBX dwStackSize:DWORD
    LOCAL nSize:DWORD
    LOCAL hStack:DWORD
    LOCAL hStackData:DWORD
    
    ; Create virtual stack
    Invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, SIZEOF STACK
    .IF eax == NULL
        ret
    .ENDIF
    mov hStack, eax

    ; Assign max height to virtual stack and calc space required for stack data size
    .IF dwStackSize == NULL
        mov ebx, VIRTUALSTACK_SIZE_MEDIUM
    .ELSE
        mov ebx, dwStackSize
    .ENDIF
    mov [eax].STACK.StackMaxHeight, ebx    
    mov eax, SIZEOF DWORD
    mul ebx
    mov nSize, eax
    
    ; Alloc space for stack data size
    Invoke GlobalAlloc, GMEM_FIXED+GMEM_ZEROINIT, nSize
    .IF eax == NULL
        Invoke GlobalFree, hStack
        mov eax, NULL
        ret
    .ENDIF
    mov hStackData, eax
    
    ; Store information into virtual stack header struct
    mov ebx, hStack
    mov [ebx].STACK.StackData, eax
    mov [ebx].STACK.StackPointer, -1
    mov [ebx].STACK.StackNoItems, 0
    
    mov eax, hStack 

    ret
VirtualStackCreate ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackDelete. Deletes a virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackDelete PROC USES EBX hVirtualStack:DWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackData
    .IF eax != NULL
        Invoke GlobalFree, eax
    .ENDIF
    mov eax, hVirtualStack
    Invoke GlobalFree, eax
    mov eax, TRUE
    ret

VirtualStackDelete endp


;-----------------------------------------------------------------------------------------
; VirtualStackPush. eax returns TRUE if succesful or FALSE otherwise. dwPushValue is the 
; value to 'push' onto the virtual stack
;-----------------------------------------------------------------------------------------
VirtualStackPush PROC USES EBX hVirtualStack:DWORD, dwPushValue:DWORD
    LOCAL hStackData:DWORD
    LOCAL nStackNoItems:DWORD
    LOCAL nStackMaxHeight:DWORD
    LOCAL nStackPointer:DWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    
    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackData
    mov hStackData, eax
    mov eax, [ebx].STACK.StackPointer
    mov nStackPointer, eax    
    mov eax, [ebx].STACK.StackMaxHeight
    mov nStackMaxHeight, eax
    mov eax, [ebx].STACK.StackNoItems
    inc eax
    mov nStackNoItems, eax
    .IF eax >= nStackMaxHeight
        mov eax, VIRTUALSTACK_STACKFULL
        ret
    .ENDIF
    
    inc nStackPointer
    mov eax, nStackPointer
    mov ebx, hStackData
    lea eax, [ebx+eax*4] ; current stack item address in eax
    mov ebx, eax
    mov eax, dwPushValue
    mov [ebx], eax ; save value to stack item address
    
    ; save pointer and item count back to stack header
    mov ebx, hVirtualStack
    mov eax, nStackPointer 
    mov [ebx].STACK.StackPointer, eax
    mov eax, nStackNoItems   
    mov [ebx].STACK.StackNoItems, eax

    mov eax, TRUE

    ret
VirtualStackPush ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackPop. eax returns TRUE if succesful and lpdwPopValue contains the 'popped'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then eax returns -1
;-----------------------------------------------------------------------------------------
VirtualStackPop PROC USES EBX hVirtualStack:DWORD, lpdwPopValue:DWORD
    LOCAL hStackData:DWORD
    LOCAL nStackNoItems:DWORD
    LOCAL nStackPointer:DWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpdwPopValue == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackData
    mov hStackData, eax
    mov eax, [ebx].STACK.StackPointer
    mov nStackPointer, eax    
    mov eax, [ebx].STACK.StackNoItems
    mov nStackNoItems, eax
    
    .IF nStackNoItems == 0
        mov eax, -1 ; stack empty    
        ret
    .ENDIF

    mov eax, nStackPointer
    mov ebx, hStackData
    mov eax, [ebx+eax*4] ; current stack item value in eax
    mov ebx, lpdwPopValue
    mov [ebx], eax ; save current stack item value to pop address variable
    
    ; save pointer and item count back to stack header
    dec nStackPointer
    dec nStackNoItems
    mov ebx, hVirtualStack
    mov eax, nStackPointer 
    mov [ebx].STACK.StackPointer, eax
    mov eax, nStackNoItems   
    mov [ebx].STACK.StackNoItems, eax

    mov eax, TRUE
    
    ret
VirtualStackPop ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackPeek. eax returns TRUE if succesful and lpdwPeekValue contains the 'peeked'
; value from the virtual stack, or FALSE otherwise. If stack is empty (no more items on it)
; then eax returns -1
;-----------------------------------------------------------------------------------------
VirtualStackPeek PROC USES EBX hVirtualStack:DWORD, lpdwPeekValue:DWORD
    LOCAL hStackData:DWORD
    LOCAL nStackNoItems:DWORD
    LOCAL nStackPointer:DWORD
    
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    .IF lpdwPeekValue == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF

    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackData
    mov hStackData, eax
    mov eax, [ebx].STACK.StackPointer
    mov nStackPointer, eax    
    mov eax, [ebx].STACK.StackNoItems
    mov nStackNoItems, eax
    
    .IF nStackNoItems == 0
        mov eax, -1 ; stack empty    
        ret
    .ENDIF

    mov eax, nStackPointer
    mov ebx, hStackData
    mov eax, [ebx+eax*4] ; current stack item value in eax
    mov ebx, lpdwPeekValue
    mov [ebx], eax ; save current stack item value to pop address variable

    mov eax, TRUE

    ret

VirtualStackPeek endp


;-----------------------------------------------------------------------------------------
; VirtualStackCount. eax returns number of items on the stack
;-----------------------------------------------------------------------------------------
VirtualStackCount PROC USES EBX hVirtualStack:DWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackNoItems
    ret
VirtualStackCount ENDP


;-----------------------------------------------------------------------------------------
; VirtualStackCount. eax returns size of virtual stack (max number of items) on the stack
;-----------------------------------------------------------------------------------------
VirtualStackSize PROC USES EBX hVirtualStack:DWORD
    .IF hVirtualStack == NULL
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov ebx, hVirtualStack
    mov eax, [ebx].STACK.StackMaxHeight
    ret
VirtualStackSize ENDP






END
