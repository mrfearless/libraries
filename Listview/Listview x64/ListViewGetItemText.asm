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
; Gets the text of the specified index. 
;**************************************************************************
ListViewGetItemText PROC FRAME  hListview:QWORD, nItemIndex:QWORD, nSubItemIndex:QWORD, lpszItemText:QWORD, lpszItemTextSize:QWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.mask_, LVIF_TEXT
	mov rax, nItemIndex
	mov LVItem.iItem, eax	
	mov rax, nSubItemIndex
	mov LVItem.iSubItem, eax
    mov rax, lpszItemText
	mov LVItem.pszText, rax	
	mov rax, lpszItemTextSize
	mov LVItem.cchTextMax, eax	
	invoke SendMessage, hListview, LVM_GETITEMTEXT, nItemIndex, Addr LVItem
	ret
ListViewGetItemText ENDP

end