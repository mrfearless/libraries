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

EXTERNDEF TreeViewGetItemImage :PROTO :QWORD, :QWORD

.code

;**************************************************************************
; Gets image index (of imagelist) for currently selected treeview item and 
; returns it in rax 
;
; Example:
;
;	.ELSEIF rax == WM_NOTIFY
;		mov ecx, lParam				; lParam is a pointer to a NMHDR Struct
;		mov rax, (NMHDR PTR [ecx]).code
;		mov ebx, (NMHDR PTR [ecx]).hwndFrom
;		.IF rax == TVN_SELCHANGED
;		    Invoke TreeViewGetSelectedImage, hTV
;		    Invoke ImageList_GetIcon, hIL, rax, ILD_TRANSPARENT
;		    mov hIcon, rax
;		    Invoke SendMessage, hImageHolder, STM_SETICON, hIcon, 0
;		    .IF rax != NULL
;		        Invoke DeleteObject, rax ; to stop memory leaks
;		    .ENDIF
;        .ENDIF
;      
;**************************************************************************
TreeViewGetSelectedImage PROC FRAME hTreeview:QWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:QWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, rax
    Invoke TreeViewGetItemImage, hTreeview, Selected
    
;    mov TVI.hItem, rax
;    mov TVI._mask, TVIF_IMAGE
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF rax == TRUE
;        mov rax, TVI.iImage
;    .ELSE
;        mov rax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedImage ENDP

end