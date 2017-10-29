.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Inserts an Sub-item into the listbox. Start with 1 as 1 based index for sub items
; Returns the index of the current item
;**************************************************************************
ListViewInsertSubItem PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, nSubItemIndex:DWORD, lpszSubItemText:DWORD
    LOCAL LVItem:LV_ITEM
	mov LVItem.imask, LVIF_TEXT
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov eax, nSubItemIndex
	mov LVItem.iSubItem, eax
    mov eax, lpszSubItemText
	mov LVItem.pszText, eax
	invoke SendMessage, hListview, LVM_SETITEM, 0, addr LVItem
	mov eax, LVItem.iItem	
	ret
ListViewInsertSubItem ENDP

end