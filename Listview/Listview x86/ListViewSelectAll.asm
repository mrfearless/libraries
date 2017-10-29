.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Select all items in listview
;**************************************************************************	
ListViewSelectAll PROC PUBLIC USES EAX hListview:DWORD
	LOCAL LVItem:LV_ITEM

	mov LVItem.stateMask, LVIS_SELECTED
	mov LVItem.state, NULL
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, ADDR LVItem    ; Deselect everything first
	mov LVItem.stateMask, LVIS_SELECTED
	mov LVItem.state, LVIS_SELECTED
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, ADDR LVItem    ; Select everything
	ret
ListViewSelectAll ENDP

end