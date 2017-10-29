.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the text of the specified item and subitem. 
;**************************************************************************
ListViewGetItemText PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, nSubItemIndex:DWORD, lpszItemText:DWORD, lpszItemTextSize:DWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.imask, LVIF_TEXT
	mov eax, nItemIndex
	mov LVItem.iItem, eax	
	mov eax, nSubItemIndex
	mov LVItem.iSubItem, eax
    mov eax, lpszItemText
	mov LVItem.pszText, eax	
	mov eax, lpszItemTextSize
	mov LVItem.cchTextMax, eax	
	invoke SendMessage, hListview, LVM_GETITEMTEXT, nItemIndex, Addr LVItem
	ret
ListViewGetItemText ENDP

end