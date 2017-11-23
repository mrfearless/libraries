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

.DATA
TreeViewBranchDepthCount    DQ 0
TreeViewBranchDepthLevel    DQ 0


.CODE

;**************************************************************************
; TreeViewCountChildren - count child items under current item,
; if bRecurse is TRUE then it will count all grandchildren etc as well
;**************************************************************************
TreeViewBranchDepth PROC FRAME hTreeview:QWORD, hItem:QWORD
    LOCAL hCurrentItem:QWORD
    
    .IF hItem == NULL
        Invoke TreeViewGetSelectedItem, hTreeview
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentItem, rax
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE rax != NULL
        mov hCurrentItem, rax
        inc TreeViewBranchDepthLevel
        mov rax, TreeViewBranchDepthLevel
        .IF rax > TreeViewBranchDepthCount
            mov TreeViewBranchDepthCount, rax
        .ENDIF
        Invoke TreeViewBranchDepth, hTreeview, hCurrentItem
        dec TreeViewBranchDepthLevel
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    mov rax, TreeViewBranchDepthCount
    ret

TreeViewBranchDepth ENDP

end








