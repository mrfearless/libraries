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
ListViewSetSelected PROC PUBLIC USES EAX hListview:DWORD, nItemIndex:DWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.imask, LVIF_STATE
	mov LVItem.state, 0
	mov LVItem.stateMask, LVIS_SELECTED ;+ LVIS_FOCUSED
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, addr LVItem            ; Release current focus, deselects all
	mov LVItem.state, LVIS_SELECTED
	mov LVItem.stateMask, LVIS_SELECTED 
	invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem    ; Set current focus
	ret
ListViewSetSelected endp

end