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
; Returns total count of items in treeview
;**************************************************************************
TreeViewCountItems PROC FRAME hTreeview:QWORD
    Invoke SendMessage, hTreeview, TVM_GETCOUNT, 0, 0
    ret
TreeViewCountItems ENDP


END