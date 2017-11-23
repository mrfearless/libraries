.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

TreeViewWalkBranch          PROTO :DWORD, :DWORD, :DWORD, :DWORD
TreeViewWalkCallbackCall    PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD


.DATA
TreeViewWalkLevel           DD 0
TreeViewWalkTotalItems      DD 0
TreeViewWalkItemNo          DD 0

.CODE


;**************************************************************************
; 
;**************************************************************************
TreeViewWalk PROC PUBLIC hTreeview:DWORD, hItem:DWORD, lpTreeViewWalkCallback:DWORD, lpCustomData:DWORD
    LOCAL hCurrentItem:DWORD
    
    .IF lpTreeViewWalkCallback == 0
        ret
    .ENDIF
    
    mov TreeViewWalkLevel, 0
    mov TreeViewWalkItemNo, -1
    ;Invoke SendMessage, hTreeview, TVM_GETCOUNT, 0, 0
    Invoke TreeViewCountChildren, hTreeview, hItem, TRUE
    mov TreeViewWalkTotalItems, eax
    
    .IF hItem == 0
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, 0 
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax

    .IF eax == 0
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
TreeViewWalkBranch PROC PRIVATE hTreeview:DWORD, hItem:DWORD, lpTreeViewWalkCallback:DWORD, lpCustomData:DWORD
    LOCAL hCurrentItem:DWORD
    mov eax, hItem
    mov hCurrentItem, eax
    
    inc TreeViewWalkItemNo
    
    ;Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    ;.IF eax != NULL
    ;    Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_START
    ;.ENDIF
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .IF eax != NULL
        .WHILE eax != NULL
            mov hCurrentItem, eax
            
            inc TreeViewWalkLevel
            
            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
            .IF eax != NULL
                Invoke TreeViewWalkCallbackCall, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData, TREEVIEWWALK_ITEM_START
            .ENDIF
            
            
            Invoke TreeViewWalkBranch, hTreeview, hCurrentItem, lpTreeViewWalkCallback, lpCustomData
            

            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
            .IF eax != NULL
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
; 
;**************************************************************************
TreeViewWalkCallbackCall PROC PRIVATE hTreeview:DWORD, hItem:DWORD, lpTreeViewWalkCallback:DWORD, lpCustomData:DWORD, dwStatus:DWORD
    push lpCustomData
    push TreeViewWalkLevel
    push TreeViewWalkItemNo
    push TreeViewWalkTotalItems
    push dwStatus
    push hItem
    push hTreeview
    mov eax, lpTreeViewWalkCallback
    call eax
    ret
TreeViewWalkCallbackCall ENDP








end

