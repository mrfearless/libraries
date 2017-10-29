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
; Delete all data from listview
;**************************************************************************	
ListViewDeleteItem PROC FRAME  hListview:QWORD, nItemIndex:QWORD
	Invoke SendMessage, hListview, LVM_DELETEITEM, nItemIndex, 0 ; Clear all list items
	ret
ListViewDeleteItem ENDP

end

