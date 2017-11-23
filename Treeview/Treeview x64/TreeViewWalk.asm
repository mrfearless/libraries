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

TreeViewWalkBranch          PROTO :QWORD, :QWORD, :QWORD, :QWORD
TreeViewWalkCallbackCall    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD


.DATA
TreeViewWalkLevel           DQ 0
TreeViewWalkTotalItems      DQ 0
TreeViewWalkItemNo          DQ 0

.CODE


;**************************************************************************
; 
;**************************************************************************
TreeViewWalk PROC FRAME hTreeview:QWORD, hItem:QWORD, lpTreeViewWalkCallback:QWORD, lpCustomData:QWORD
    LOCAL hCurrentItem:QWORD
    
    .IF lpTreeViewWalkCallback == 0
        ret
    .ENDIF
    
    mov TreeViewWalkLevel, 0
    mov TreeViewWalkItemNo, -1
    ;Invoke SendMessage, hTreeview, TVM_GETCOUNT, 0, 0
    Invoke TreeViewCountChildren, hTreeview, hItem, TRUE
    mov TreeViewWalkTotalItems, rax
    
    .IF hItem == 0
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, 0 
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentItem, rax

    .IF rax == 0
        ret
    .ENDIF
    
    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ROOT_START
    ;inc TreeViewWalkLevel
    
    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_START
    
    ;inc TreeViewWalkLevel
    Invoke TreeViewWalkBranch, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData
    ;dec TreeViewWalkLevel

    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_FINISH
    ;dec TreeViewWalkLevel
    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ROOT_FINISH
    
    ret
TreeViewWalk endp


;**************************************************************************
; 
;**************************************************************************
TreeViewWalkBranch PROC FRAME hTreeview:QWORD, hItem:QWORD, lpTreeViewWalkCallback:QWORD, lpCustomData:QWORD
    LOCAL hCurrentItem:QWORD
    mov rax, hItem
    mov hCurrentItem, rax
    
    inc TreeViewWalkItemNo
    
    ;Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    ;.IF rax != NULL
    ;    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_START
    ;.ENDIF
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .IF rax != NULL
        .WHILE rax != NULL
            mov hCurrentItem, rax
            
            inc TreeViewWalkLevel
            
            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
            .IF rax != NULL
                Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_START
            .ENDIF
            
            
            Invoke TreeViewWalkBranch, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData
            

            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
            .IF rax != NULL
                Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_FINISH
            .ENDIF            
            
            dec TreeViewWalkLevel
            
            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
        .ENDW
    .ELSE
        Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM
    .ENDIF
    
    
    ret
TreeViewWalkBranch ENDP


;**************************************************************************
; hTreeview, hItem, qwStatus, qwTotalItems, qwItemNo, qwLevel, qwCustomData ; rcx, rdx, r8, r9
;**************************************************************************
TreeViewWalkCallbackCall PROC FRAME hTreeview:QWORD, hItem:QWORD, lpTreeViewWalkCallback:QWORD, lpCustomData:QWORD, qwStatus:QWORD
    sub rsp, 56d                    ; 7 arg space
    mov rax, lpCustomData
    mov qword ptr [rsp+48d], rax    ; parameter 7
    mov rax, TreeViewWalkLevel
    mov qword ptr [rsp+40d], rax    ; parameter 6
    mov rax, TreeViewWalkItemNo
    mov qword ptr [rsp+32d], rax    ; parameter 5
    mov r9, TreeViewWalkTotalItems  ; parameter 4
    mov r8, qwStatus                ; parameter 3
    mov rdx, hItem                  ; parameter 2
    mov rcx, hTreeview              ; parameter 1    
    mov rax, lpTreeViewWalkCallback
    call rax
    ret
TreeViewWalkCallbackCall ENDP








end

