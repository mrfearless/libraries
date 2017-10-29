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
ListViewGetItemState PROC FRAME  hListview:QWORD, nItemIndex:QWORD, dqState:QWORD
	invoke SendMessage, hListview, LVM_GETITEMSTATE, nItemIndex, dqState
	ret
ListViewGetItemState ENDP

end