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
; Gets the icon of the specified index and returns it in eax or -1 if fail
;**************************************************************************
ListViewGetItemImage PROC FRAME  hListview:QWORD, nItemIndex:QWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.mask_, LVIF_IMAGE
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0	
	invoke SendMessage, hListview, LVM_GETITEM, 0, Addr LVItem
	.IF rax == TRUE
	    mov eax, LVItem.iImage
	.ELSE
	    mov rax, -1
	.ENDIF        
	ret
ListViewGetItemImage ENDP

end