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
; Get the currently focused item
;**************************************************************************	
ListViewGetFocused PROC FRAME hListview:QWORD
	Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_FOCUSED
	ret
ListViewGetFocused endp


end