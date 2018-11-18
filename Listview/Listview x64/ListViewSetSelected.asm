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
ListViewSetSelected PROC FRAME hListview:QWORD, nItemIndex:QWORD, bFocused:QWORD
	LOCAL LVItem:LV_ITEM
	; Release current focus, deselects all
	mov LVItem.mask_, LVIF_STATE
	mov LVItem.state, 0
	.IF bFocused == TRUE
	    mov LVItem.stateMask, LVIS_SELECTED or LVIS_FOCUSED
	.ELSE
	    mov LVItem.stateMask, LVIS_SELECTED
	.ENDIF
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, addr LVItem
	
	; Set current focus
	.IF bFocused == TRUE
	    mov LVItem.state, LVIS_SELECTED or LVIS_FOCUSED
	    mov LVItem.stateMask, LVIS_SELECTED or LVIS_FOCUSED
	.ELSE
	    mov LVItem.state, LVIS_SELECTED
	    mov LVItem.stateMask, LVIS_SELECTED
	.ENDIF	
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem
	ret
ListViewSetSelected endp

end