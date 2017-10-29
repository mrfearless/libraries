.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the icon of the specified index and returns it in eax or -1 if fail
;**************************************************************************
ListViewGetItemImage PROC PUBLIC hListview:DWORD, nItemIndex:DWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.imask, LVIF_IMAGE
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0	
	invoke SendMessage, hListview, LVM_GETITEM, 0, Addr LVItem
	.IF eax == TRUE
	    mov eax, LVItem.iImage
	.ELSE
	    mov eax, -1
	.ENDIF        
	ret
ListViewGetItemImage ENDP

end