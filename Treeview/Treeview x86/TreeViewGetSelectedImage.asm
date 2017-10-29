.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

EXTERNDEF TreeViewGetItemImage :PROTO :DWORD, :DWORD

.code

;**************************************************************************
; Gets image index (of imagelist) for currently selected treeview item and 
; returns it in EAX 
;
; Example:
;
;	.ELSEIF eax == WM_NOTIFY
;		mov ecx, lParam				; lParam is a pointer to a NMHDR Struct
;		mov eax, (NMHDR PTR [ecx]).code
;		mov ebx, (NMHDR PTR [ecx]).hwndFrom
;		.IF eax == TVN_SELCHANGED
;		    Invoke TreeViewGetSelectedImage, hTV
;		    Invoke ImageList_GetIcon, hIL, eax, ILD_TRANSPARENT
;		    mov hIcon, eax
;		    Invoke SendMessage, hImageHolder, STM_SETICON, hIcon, 0
;		    .IF eax != NULL
;		        Invoke DeleteObject, eax ; to stop memory leaks
;		    .ENDIF
;        .ENDIF
;      
;**************************************************************************
TreeViewGetSelectedImage PROC PUBLIC hTreeview:DWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:DWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, eax
    Invoke TreeViewGetItemImage, hTreeview, Selected
    
;    mov TVI.hItem, eax
;    mov TVI._mask, TVIF_IMAGE
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF eax == TRUE
;        mov eax, TVI.iImage
;    .ELSE
;        mov eax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedImage ENDP

end