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
include commctrl.inc
;include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewChildItemsCollapse PROC FRAME hTreeview:QWORD, hItem:QWORD
    Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_COLLAPSE, hItem  
    ret
TreeViewChildItemsCollapse endp

end

