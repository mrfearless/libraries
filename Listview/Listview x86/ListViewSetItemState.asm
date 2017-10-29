.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the text of the specified index. 
;**************************************************************************
ListViewSetItemState PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, dwStateMask:DWORD, dwState:DWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.imask,LVIF_STATE
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	mov eax, dwState
	;push eax
	mov LVItem.state, eax
	mov eax, dwStateMask
	mov LVItem.stateMask, eax
	invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, Addr LVItem
	ret
ListViewSetItemState ENDP

end