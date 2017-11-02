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

;include user32.inc
includelib user32.lib
include commctrl.inc
;include kernel32.inc
includelib kernel32.lib

include TreeView.inc

.code

;**************************************************************************
; retruns in rax length of text copied to lpszTextBuffer, or 0 otherwise
;**************************************************************************
TreeViewGetItemText PROC FRAME hTreeview:QWORD, hItem:QWORD, lpszTextBuffer:QWORD, dqSizeTextBuffer:QWORD
    LOCAL TVI:TV_ITEM
    mov eax, TVIF_TEXT
    mov TVI.mask_, eax
    mov rax, hItem
    mov TVI.hItem, rax
    mov rax, dqSizeTextBuffer
    mov TVI.cchTextMax, eax
    mov rax, lpszTextBuffer
    mov TVI.pszText, rax
    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
    .IF rax == TRUE
        xor rax, rax
        mov eax, TVI.cchTextMax
    .ELSE
        mov rax, 0
    .ENDIF
    ret
TreeViewGetItemText ENDP

end