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
includelib Kernel32.Lib

include Listview.inc

.code

;**************************************************************************
; Inserts an item into the listbox. Start with 0 as 0 based index for items
; Returns the index of the new item if successful or -1 otherwise
;**************************************************************************
ListViewInsertItem PROC FRAME  hListview:QWORD, nItemIndex:QWORD, lpszItemText:QWORD, nImageListIndex:QWORD
	LOCAL LVItem:LV_ITEM
	
	.IF nImageListIndex != 0
    	mov LVItem.mask_, LVIF_TEXT or LVIF_IMAGE
	.ELSE
	    mov LVItem.mask_, LVIF_TEXT        
	.ENDIF
	mov rax, nItemIndex
	mov LVItem.iItem, eax	
	mov LVItem.iSubItem, 0
	mov LVItem.state, LVIS_FOCUSED
	mov LVItem.stateMask, 0
	mov rax, lpszItemText
	mov LVItem.pszText, rax
	Invoke lstrlen, lpszItemText
	mov LVItem.cchTextMax, eax
    mov rax, nImageListIndex
    mov LVItem.iImage, eax
	mov LVItem.lParam, 0
	invoke SendMessage, hListview, LVM_INSERTITEM, 0, Addr LVItem
	mov eax, LVItem.iItem
	ret
ListViewInsertItem ENDP

end