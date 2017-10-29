.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Sets the text of the specified item and subitem. 
;**************************************************************************
ListViewSetItemText PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, nSubItemIndex:DWORD, lpszItemText:DWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.imask, LVIF_TEXT
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov eax, nSubItemIndex
	mov LVItem.iSubItem, eax
    mov eax, lpszItemText
	mov LVItem.pszText, eax
	Invoke lstrlen, lpszItemText
	mov LVItem.cchTextMax, eax	
	mov LVItem.lParam, 0	
	invoke SendMessage, hListview, LVM_SETITEMTEXT, nItemIndex, Addr LVItem
	ret
ListViewSetItemText ENDP

end