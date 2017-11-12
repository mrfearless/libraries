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
TreeViewChildItemsExpand PROC FRAME hTreeview:QWORD, hItem:QWORD
    LOCAL hCurrentChild:QWORD
    mov rax, hItem
    mov hCurrentChild, rax
    
    Invoke SendMessage, hTreeview, WM_SETREDRAW, FALSE, 0
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentChild
    .WHILE rax != NULL
        mov hCurrentChild, rax      
        Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_EXPAND, hCurrentChild
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentChild
    .ENDW
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, hItem
    Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hItem
    Invoke SendMessage, hTreeview, WM_SETREDRAW, TRUE, 0
    ret
TreeViewChildItemsExpand endp

end

