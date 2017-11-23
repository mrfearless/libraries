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

TreeViewCollapseBranch      PROTO :QWORD, :QWORD


.code


;**************************************************************************
; 
;**************************************************************************
TreeViewRootCollapse PROC FRAME hTreeview:QWORD
    LOCAL hRoot:QWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, 0
    .IF rax == 0
        ret
    .ENDIF
    mov hRoot, rax
    Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_COLLAPSE, hRoot
    Invoke TreeViewBranchCollapse, hTreeview, hRoot
    ret
TreeViewRootCollapse ENDP


;**************************************************************************
; 
;**************************************************************************
TreeViewBranchCollapse PROC FRAME hTreeview:QWORD, hItem:QWORD
    LOCAL hCurrentItem:QWORD
    
    .IF hItem == 0
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, 0 
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentItem, rax

    .IF rax == 0
        ret
    .ENDIF
    
    Invoke SendMessage, hTreeview, WM_SETREDRAW, FALSE, 0
    Invoke TreeViewCollapseBranch, hTreeview, hCurrentItem
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, hCurrentItem
    Invoke SendMessage, hTreeview, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, hCurrentItem
    Invoke SendMessage, hTreeview, WM_SETREDRAW, TRUE, 0
    ret
TreeViewBranchCollapse ENDP


;**************************************************************************
; TreeViewCollapseBranch
;**************************************************************************
TreeViewCollapseBranch PROC FRAME hTreeview:QWORD, hItem:QWORD
    LOCAL hCurrentItem:QWORD
    mov rax, hItem
    mov hCurrentItem, rax
    Invoke SendMessage, hTreeview, TVM_EXPAND, TVE_COLLAPSE, hCurrentItem
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE rax != NULL
        mov hCurrentItem, rax
        Invoke TreeViewCollapseBranch, hTreeview, hCurrentItem
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    ret
TreeViewCollapseBranch ENDP




end



