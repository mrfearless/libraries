.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewGetItemImage PROC PUBLIC hTreeview:DWORD, hItem:DWORD
    LOCAL TVI:TV_ITEM
    mov TVI._mask, TVIF_IMAGE ;or TVIF_SELECTEDIMAGE	
    mov eax, hItem
    mov TVI.hItem, eax
    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
    .IF eax == TRUE
        mov eax, TVI.iImage
    .ELSE
        mov eax, NULL
    .ENDIF
    ret
TreeViewGetItemImage ENDP

end