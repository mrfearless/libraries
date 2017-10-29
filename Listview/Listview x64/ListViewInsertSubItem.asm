.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

include windows.inc
include commctrl.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Inserts an Sub-item into the listbox. Start with 1 as 1 based index for sub items
; Returns the index of the current item
;**************************************************************************
ListViewInsertSubItem PROC FRAME  hListview:QWORD, nItemIndex:QWORD, nSubItemIndex:QWORD, lpszSubItemText:QWORD
    LOCAL LVItem:LV_ITEM
	mov LVItem.mask_, LVIF_TEXT
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov rax, nSubItemIndex
	mov LVItem.iSubItem, eax
    mov rax, lpszSubItemText
	mov LVItem.pszText, rax
	invoke SendMessage, hListview, LVM_SETITEM, 0, addr LVItem
	mov eax, LVItem.iItem	
	ret
ListViewInsertSubItem ENDP

end