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
ListViewGetItemRect PROC FRAME  hListview:QWORD, nItemIndex:QWORD, dqPtrRect:QWORD
	invoke SendMessage, hListview, LVM_GETITEMRECT, nItemIndex, dqPtrRect
	ret
ListViewGetItemRect ENDP

end