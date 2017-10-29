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
TreeViewSetItemParam PROC PUBLIC hTreeview:DWORD, hItem:DWORD, dwParam:DWORD
    LOCAL TVI:TV_ITEM
    mov TVI._mask, TVIF_PARAM or TVIF_HANDLE
    mov eax, hItem
    mov TVI.hItem, eax
    mov eax, dwParam
    mov TVI.lParam, eax
    Invoke SendMessage, hTreeview, TVM_SETITEM, 0, Addr TVI
    ret
TreeViewSetItemParam ENDP

end