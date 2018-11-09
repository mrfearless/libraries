.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Sets the lParam of the specified index. ParamValue is a 32bit dword value
;**************************************************************************
ListViewSetItemParam PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, dwParamValue:DWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.imask,LVIF_PARAM
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	mov eax, dwParamValue
	push eax
	pop LVItem.lParam
	invoke SendMessage, hListview, LVM_SETITEM, 0, Addr LVItem
	ret
ListViewSetItemParam ENDP

end