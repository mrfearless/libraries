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
; Select all items in listview
;**************************************************************************	
ListViewSelectAll PROC FRAME  USES RAX hListview:QWORD
	LOCAL LVItem:LV_ITEM

	mov LVItem.stateMask, LVIS_SELECTED
	mov LVItem.state, NULL
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, ADDR LVItem    ; Deselect everything first
	mov LVItem.stateMask, LVIS_SELECTED
	mov LVItem.state, LVIS_SELECTED
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, ADDR LVItem    ; Select everything
	ret
ListViewSelectAll ENDP

end