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
; TreeViewCountChildren - count child items under current item,
; if bRecurse is TRUE then it will count all grandchildren etc as well
;**************************************************************************
TreeViewCountChildren PROC FRAME USES RBX hTreeview:QWORD, hItem:QWORD, bRecurse:QWORD
    LOCAL hCurrentChild:QWORD
    LOCAL qwChildrenCount:QWORD
    
    mov qwChildrenCount, 0
    
    .IF hItem == NULL
        Invoke TreeViewGetSelectedItem, hTreeview
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentChild, rax
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentChild
    .WHILE rax != NULL
        mov hCurrentChild, rax
        inc qwChildrenCount
        .IF bRecurse == TRUE
            Invoke TreeViewCountChildren, hTreeview, hCurrentChild, bRecurse
            mov rbx, qwChildrenCount
            add rax, rbx
            mov qwChildrenCount, rax
        .ENDIF
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentChild
    .ENDW
    mov rax, qwChildrenCount
    ret

TreeViewCountChildren ENDP

end