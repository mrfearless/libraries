.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.DATA
TreeViewBranchDepthCount    DD 0
TreeViewBranchDepthLevel    DD 0


.CODE

;**************************************************************************
; TreeViewCountChildren - count child items under current item,
; if bRecurse is TRUE then it will count all grandchildren etc as well
;**************************************************************************
TreeViewBranchDepth PROC PUBLIC hTreeview:DWORD, hItem:DWORD
    LOCAL hCurrentItem:DWORD
    
    .IF hItem == NULL
        Invoke TreeViewGetSelectedItem, hTreeview
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE eax != NULL
        mov hCurrentItem, eax
        inc TreeViewBranchDepthLevel
        mov eax, TreeViewBranchDepthLevel
        .IF eax > TreeViewBranchDepthCount
            mov TreeViewBranchDepthCount, eax
        .ENDIF
        Invoke TreeViewBranchDepth, hTreeview, hCurrentItem
        dec TreeViewBranchDepthLevel
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    mov eax, TreeViewBranchDepthCount
    ret

TreeViewBranchDepth ENDP

end








