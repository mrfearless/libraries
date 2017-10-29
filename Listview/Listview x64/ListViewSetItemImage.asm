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
; Sets the icon of the specified index. 
;**************************************************************************
ListViewSetItemImage PROC FRAME  hListview:QWORD, nItemIndex:QWORD, nImageListIndex:QWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.mask_, LVIF_IMAGE
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0	
	mov rax, nImageListIndex
	mov LVItem.iImage, eax
	invoke SendMessage, hListview, LVM_SETITEM, 0, Addr LVItem
	ret
ListViewSetItemImage ENDP

end