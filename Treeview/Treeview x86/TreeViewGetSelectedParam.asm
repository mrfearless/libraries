.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

EXTERNDEF TreeViewGetItemParam :PROTO :DWORD, :DWORD

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewGetSelectedParam PROC PUBLIC hTreeview:DWORD
    LOCAL TVI:TV_ITEM
    LOCAL Selected:DWORD
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CARET, NULL
    mov Selected, eax
    Invoke TreeViewGetItemParam, hTreeview, Selected
    
;    mov TVI.hItem, eax
;    mov TVI._mask, TVIF_PARAM
;    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
;    .IF eax == TRUE
;        mov eax, TVI.lParam
;    .ELSE
;        mov eax, NULL
;    .ENDIF        
    ret
TreeViewGetSelectedParam ENDP

end