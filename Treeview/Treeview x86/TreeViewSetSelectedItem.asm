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
TreeViewSetSelectedItem PROC PUBLIC hTreeview:DWORD, hItem:DWORD, bVisible:DWORD
    Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_CARET, hItem
    .IF bVisible == TRUE
        Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hItem
    .ENDIF
    ret
TreeViewSetSelectedItem ENDP

end