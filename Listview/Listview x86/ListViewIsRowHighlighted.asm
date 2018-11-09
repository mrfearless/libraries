.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

EXTERNDEF ListViewGetItemState :PROTO :DWORD, :DWORD, :DWORD
EXTERNDEF ListViewSetItemState :PROTO :DWORD, :DWORD, :DWORD, :DWORD

.code

;**************************************************************************	
; Checks if row specified is selected
;**************************************************************************	
ListViewIsRowSelected PROC hListview:DWORD, nItemIndex:DWORD
    Invoke ListViewGetItemState, hListview, nItemIndex, LVIS_SELECTED
    .IF eax != 0
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ;return ListView_GetItemState(hWnd, row, LVIS_SELECTED) != 0;
    ret
ListViewIsRowSelected ENDP


;**************************************************************************	
; Checks if row specified is highlighted
;**************************************************************************	
ListViewIsRowHighlighted PROC hListview:DWORD, nItemIndex:DWORD
;  // We check if row is selected.
;  // We also check if window has focus. This was because the original listview
;  //  control I created did not have style LVS_SHOWSELALWAYS. So if the listview
;  //  does not have focus, then there is no highlighting.
;  return IsRowSelected(hWnd, row) && (::GetFocus(hWnd) == hWnd)
    Invoke ListViewIsRowSelected, hListview, nItemIndex
    .IF eax == TRUE
        Invoke GetFocus
        .IF eax == hListview
            mov eax, TRUE
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
ListViewIsRowHighlighted ENDP


;**************************************************************************	
; Enables row highlighting
;**************************************************************************	
ListViewEnableHighlighting PROC hListview:DWORD, nItemIndex:DWORD
    
    Invoke ListViewSetItemState, hListview, nItemIndex, LVIS_SELECTED, LVIS_SELECTED
    ret

ListViewEnableHighlighting endp


;**************************************************************************	
; Disables row highlighting
;**************************************************************************	
ListViewDisableHighlighting PROC hListview:DWORD, nItemIndex:DWORD
    
    Invoke ListViewSetItemState, hListview, nItemIndex, LVIS_SELECTED, 0
    ret

ListViewDisableHighlighting endp





end






