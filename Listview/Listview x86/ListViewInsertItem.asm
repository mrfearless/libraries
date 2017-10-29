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
; Inserts an item into the listbox. Start with 0 as 0 based index for items
; Returns the index of the new item if successful or -1 otherwise
;**************************************************************************
ListViewInsertItem PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, lpszItemText:DWORD, nImageListIndex:DWORD
	LOCAL LVItem:LV_ITEM
	
	.IF nImageListIndex != 0
    	mov LVItem.imask, LVIF_TEXT or LVIF_IMAGE
	.ELSE
	    mov LVItem.imask, LVIF_TEXT        
	.ENDIF
	mov eax, nItemIndex
	mov LVItem.iItem, eax	
	mov LVItem.iSubItem, 0
	mov LVItem.state, LVIS_FOCUSED
	mov LVItem.stateMask, 0
	mov eax, lpszItemText
	mov LVItem.pszText, eax
	Invoke lstrlen, lpszItemText
	mov LVItem.cchTextMax, eax
    mov eax, nImageListIndex
    mov LVItem.iImage, eax
	mov LVItem.lParam, 0
	invoke SendMessage, hListview, LVM_INSERTITEM, 0, Addr LVItem
	mov eax, LVItem.iItem
	ret
ListViewInsertItem ENDP

end