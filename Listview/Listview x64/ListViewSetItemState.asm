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
ListViewSetItemState PROC FRAME  hListview:QWORD, nItemIndex:QWORD, dqStateMask:QWORD, dqState:QWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.mask_,LVIF_STATE
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	mov rax, dqState
	mov LVItem.state, eax
	mov rax, dqStateMask
	mov LVItem.stateMask, eax
	invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, Addr LVItem
	ret
ListViewSetItemState ENDP

end