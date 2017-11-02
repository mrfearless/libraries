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
TreeViewGetItemParam PROC FRAME hTreeview:QWORD, hItem:QWORD
    LOCAL TVI:TV_ITEM
    mov TVI.mask_, TVIF_PARAM or TVIF_HANDLE
    mov rax, hItem
    mov TVI.hItem, rax
    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
    .IF rax == TRUE
        mov rax, TVI.lParam
    .ELSE
        mov rax, NULL
    .ENDIF
    ret
TreeViewGetItemParam ENDP

end