.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; Returns total count of items in treeview
;**************************************************************************
TreeViewCountItems PROC PUBLIC hTreeview:DWORD
    Invoke SendMessage, hTreeview, TVM_GETCOUNT, 0, 0
    ret
TreeViewCountItems ENDP


END


