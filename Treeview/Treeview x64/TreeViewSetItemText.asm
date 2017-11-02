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

;include kernel32.inc
includelib kernel32.lib

include TreeView.inc

.code

;**************************************************************************
; retruns in rax length of text copied to lpszTextBuffer, or 0 otherwise
;**************************************************************************
TreeViewSetItemText PROC FRAME hTreeview:QWORD, hItem:QWORD, lpszTextBuffer:QWORD
    LOCAL TVI:TV_ITEM
    mov eax, TVIF_TEXT
    mov TVI.mask_, eax
    mov rax, hItem
    mov TVI.hItem, rax
    ;invoke lstrlen, lpszTextBuffer
    ;mov TVI.cchTextMax, rax
    mov rax, lpszTextBuffer
    mov TVI.pszText, rax
    Invoke SendMessage, hTreeview, TVM_SETITEM, 0, Addr TVI

    ret
TreeViewSetItemText ENDP

end