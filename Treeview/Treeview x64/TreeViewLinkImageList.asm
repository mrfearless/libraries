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
; Links specified treeview with an imagelist
;
; TVSIL_NORMAL    equ 0
; TVSIL_SMALL     equ 1
; TVSIL_STATE     equ 2
;
;
;**************************************************************************
TreeViewLinkImageList PROC FRAME hTreeview:QWORD, hImagelist:QWORD, ImagelistType:QWORD
    .IF hImagelist != NULL && hTreeview != NULL
        invoke SendMessage, hTreeview, TVM_SETIMAGELIST, ImagelistType, hImagelist
    .ENDIF
    ret
TreeViewLinkImageList ENDP


end