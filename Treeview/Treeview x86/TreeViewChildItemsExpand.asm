.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewChildItemsExpand PROC PUBLIC hTreeview:DWORD, hItem:DWORD
    LOCAL hCurrentChild:DWORD
    mov eax, hItem
    mov hCurrentChild, eax
    
    Invoke SendMessage, hTreeview, WM_SETREDRAW, FALSE, 0
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentChild
    .WHILE eax != NULL
        mov hCurrentChild, eax      
        Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_EXPAND, hCurrentChild
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentChild
    .ENDW
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, hItem
    Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hItem
    Invoke SendMessage, hTreeview, WM_SETREDRAW, TRUE, 0
    ret
TreeViewChildItemsExpand endp

end

