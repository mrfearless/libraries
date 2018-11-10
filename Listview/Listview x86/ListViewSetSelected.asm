.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Set the currently selected item to a specified index
;**************************************************************************	
ListViewSetSelected PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, bFocused:DWORD
	LOCAL LVItem:LV_ITEM
	
	; Release current focus, deselects all
	mov LVItem.imask, LVIF_STATE
	mov LVItem.state, 0
	.IF bFocused == TRUE
	    mov LVItem.stateMask, LVIS_SELECTED or LVIS_FOCUSED
	.ELSE
	    mov LVItem.stateMask, LVIS_SELECTED
	.ENDIF
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, addr LVItem
	
	; Set current focus
	.IF bFocused == TRUE
	    mov LVItem.state, LVIS_SELECTED or LVIS_FOCUSED
	    mov LVItem.stateMask, LVIS_SELECTED or LVIS_FOCUSED
	.ELSE
	    mov LVItem.state, LVIS_SELECTED
	    mov LVItem.stateMask, LVIS_SELECTED
	.ENDIF	
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem
	ret
ListViewSetSelected endp

end