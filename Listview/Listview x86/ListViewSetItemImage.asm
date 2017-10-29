.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Sets the icon of the specified index. 
;**************************************************************************
ListViewSetItemImage PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, nImageListIndex:DWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.imask, LVIF_IMAGE
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0	
	mov eax, nImageListIndex
	mov LVItem.iImage, eax
	invoke SendMessage, hListview, LVM_SETITEM, 0, Addr LVItem
	ret
ListViewSetItemImage ENDP

end