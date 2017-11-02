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

EXTERNDEF TreeViewGetItemParam :PROTO :QWORD, :QWORD

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewGetSelectedParam PROC FRAME hTreeview:QWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:QWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, rax
    Invoke TreeViewGetItemParam, hTreeview, Selected
    
;    mov TVI.hItem, rax
;    mov TVI._mask, TVIF_PARAM
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF rax == TRUE
;        mov rax, TVI.lParam
;    .ELSE
;        mov rax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedParam ENDP

end