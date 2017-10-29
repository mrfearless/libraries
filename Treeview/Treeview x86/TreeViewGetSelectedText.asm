.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

EXTERNDEF TreeViewGetItemText :PROTO :DWORD, :DWORD, :DWORD, :DWORD

.code

;**************************************************************************
; Gets text for currently selected treeview item and returns it into the 
; buffer specified.
;
; Example:
;
;	.ELSEIF eax == WM_NOTIFY
;		mov ecx, lParam				; lParam is a pointer to a NMHDR Struct
;		mov eax, (NMHDR PTR [ecx]).code
;		mov ebx, (NMHDR PTR [ecx]).hwndFrom
;		.IF eax == TVN_SELCHANGED
;		    Invoke TreeViewGetSelectedText, hTV, Addr SelectedItem, SIZEOF SelectedItem
;		    Invoke SetWindowText, hTxtSelected, Addr SelectedItem		
;        .ENDIF
;      
;**************************************************************************
TreeViewGetSelectedText PROC PUBLIC hTreeview:DWORD, lpszTextBuffer:DWORD, dwSizeTextBuffer:DWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:DWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, eax
    Invoke TreeViewGetItemText, hTreeview, Selected, lpszTextBuffer, dwSizeTextBuffer
;    
;    mov TVI.hItem, eax
;    mov TVI._mask, TVIF_PARAM
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF eax == TRUE
;        mov eax, TVI.lParam
;    .ELSE
;        mov eax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedText ENDP

end