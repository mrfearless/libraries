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
TreeViewSetItemImage PROC FRAME hTreeview:QWORD, hItem:QWORD, nImageListIndex:QWORD
    LOCAL TVI:TV_ITEM
    mov TVI.mask_, TVIF_IMAGE ;or TVIF_SELECTEDIMAGE	
    mov rax, hItem
    mov TVI.hItem, rax
    mov rax, nImageListIndex
    mov TVI.iImage, eax
    Invoke SendMessage, hTreeview, TVM_SETITEM, 0, Addr TVI
    ret
TreeViewSetItemImage ENDP

end