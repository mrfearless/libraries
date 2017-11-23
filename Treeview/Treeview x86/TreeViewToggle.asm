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
TreeViewChildItemsToggle PROC PUBLIC hTreeview:DWORD, hItem:DWORD
    LOCAL hCurrentItem:DWORD
    
    .IF hItem == 0
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, 0 
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax
    
    .IF eax == 0
        ret
    .ENDIF
    
    Invoke SendMessage, hTreeview, WM_SETREDRAW, FALSE, 0
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE eax != NULL
        mov hCurrentItem, eax      
        Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_TOGGLE, hCurrentItem
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, hItem
    Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hItem
    Invoke SendMessage, hTreeview, WM_SETREDRAW, TRUE, 0    
    ret
TreeViewChildItemsToggle ENDP

end

