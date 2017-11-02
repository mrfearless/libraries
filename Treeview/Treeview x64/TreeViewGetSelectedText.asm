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

EXTERNDEF TreeViewGetItemText :PROTO :QWORD, :QWORD, :QWORD, :QWORD

.code

;**************************************************************************
; Gets text for currently selected treeview item and returns it into the 
; buffer specified.
;
; Example:
;
;	.ELSEIF rax == WM_NOTIFY
;		mov ecx, lParam				; lParam is a pointer to a NMHDR Struct
;		mov rax, (NMHDR PTR [ecx]).code
;		mov ebx, (NMHDR PTR [ecx]).hwndFrom
;		.IF rax == TVN_SELCHANGED
;		    Invoke TreeViewGetSelectedText, hTV, Addr SelectedItem, SIZEOF SelectedItem
;		    Invoke SetWindowText, hTxtSelected, Addr SelectedItem		
;        .ENDIF
;      
;**************************************************************************
TreeViewGetSelectedText PROC FRAME hTreeview:QWORD, lpszTextBuffer:QWORD, dwSizeTextBuffer:QWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:QWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, rax
    Invoke TreeViewGetItemText, hTreeview, Selected, lpszTextBuffer, dwSizeTextBuffer
;    
;    mov TVI.hItem, rax
;    mov TVI._mask, TVIF_PARAM
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF rax == TRUE
;        mov rax, TVI.lParam
;    .ELSE
;        mov rax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedText ENDP

end