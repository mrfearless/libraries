.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include kernel32.inc
includelib kernel32.lib

include TreeView.inc

.code

;**************************************************************************
; retruns in eax length of text copied to lpszTextBuffer, or 0 otherwise
;**************************************************************************
TreeViewGetItemText PROC PUBLIC USES EBX hTreeview:DWORD, hItem:DWORD, lpszTextBuffer:DWORD, dwSizeTextBuffer:DWORD
    LOCAL TVI:TV_ITEM
    mov TVI._mask, TVIF_TEXT
    mov eax, hItem
    mov TVI.hItem, eax
    mov eax, dwSizeTextBuffer
    mov TVI.cchTextMax, eax
    mov eax, lpszTextBuffer
    mov TVI.pszText, eax
    Invoke SendMessage, hTreeview, TVM_GETITEM, 0, Addr TVI
    .IF eax == TRUE
         mov eax, TVI.cchTextMax
    .ELSE
        mov eax, 0
    .ENDIF
    ret
TreeViewGetItemText ENDP

end