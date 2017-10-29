.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; Links specified treeview with an imagelist
;
; TVSIL_NORMAL    equ 0
; TVSIL_SMALL     equ 1
; TVSIL_STATE     equ 2
;
;
;**************************************************************************
TreeViewLinkImageList PROC PUBLIC hTreeview:DWORD, hImagelist:DWORD, ImagelistType:DWORD
    .IF hImagelist != NULL && hTreeview != NULL
        invoke SendMessage, hTreeview, TVM_SETIMAGELIST, ImagelistType, hImagelist
    .ENDIF
    ret
TreeViewLinkImageList ENDP


end