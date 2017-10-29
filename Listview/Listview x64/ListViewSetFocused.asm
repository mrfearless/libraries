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
; Set the currently selected item to a specified index
;**************************************************************************	
ListViewSetFocused PROC FRAME  USES RAX hListview:QWORD, nItemIndex:QWORD
	LOCAL LVItem:LV_ITEM
	
	mov LVItem.mask_, LVIF_STATE
	mov LVItem.state, LVIS_FOCUSED
	mov LVItem.stateMask, LVIS_FOCUSED 
	invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem    ; Set current focus
	ret
ListViewSetFocused endp

end