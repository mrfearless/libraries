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
includelib user32.lib

include Listview.inc

EXTERNDEF ListViewGetItemState :PROTO :QWORD, :QWORD, :QWORD
EXTERNDEF ListViewSetItemState :PROTO :QWORD, :QWORD, :QWORD, :QWORD

.code

;**************************************************************************	
; Checks if row specified is selected
;**************************************************************************	
ListViewIsRowSelected PROC FRAME  hListview:QWORD, nItemIndex:QWORD
    Invoke ListViewGetItemState, hListview, nItemIndex, LVIS_SELECTED
    .IF rax != 0
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ;return ListView_GetItemState(hWnd, row, LVIS_SELECTED) != 0;
    ret
ListViewIsRowSelected ENDP


;**************************************************************************	
; Checks if row specified is highlighted
;**************************************************************************	
ListViewIsRowHighlighted PROC FRAME  hListview:QWORD, nItemIndex:QWORD
;  // We check if row is selected.
;  // We also check if window has focus. This was because the original listview
;  //  control I created did not have style LVS_SHOWSELALWAYS. So if the listview
;  //  does not have focus, then there is no highlighting.
;  return IsRowSelected(hWnd, row) && (::GetFocus(hWnd) == hWnd)
    Invoke ListViewIsRowSelected, hListview, nItemIndex
    .IF rax == TRUE
        Invoke GetFocus
        .IF rax == hListview
            mov rax, TRUE
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
ListViewIsRowHighlighted ENDP


;**************************************************************************	
; Enables row highlighting
;**************************************************************************	
ListViewEnableHighlighting PROC FRAME  hListview:QWORD, nItemIndex:QWORD
    
    Invoke ListViewSetItemState, hListview, nItemIndex, LVIS_SELECTED, LVIS_SELECTED
    ret

ListViewEnableHighlighting endp


;**************************************************************************	
; Enables row highlighting
;**************************************************************************	
ListViewDisableHighlighting PROC FRAME  hListview:QWORD, nItemIndex:QWORD
    
    Invoke ListViewSetItemState, hListview, nItemIndex, LVIS_SELECTED, 0
    ret

ListViewDisableHighlighting endp





end






