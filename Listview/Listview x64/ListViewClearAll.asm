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
ListViewClearAll PROC FRAME  hListview:QWORD
    Invoke SendMessage, hListview, WM_SETREDRAW, FALSE, 0
	Invoke SendMessage, hListview, LVM_DELETEALLITEMS, 0, 0 ; Clear all list items
	Invoke SendMessage, hListview, WM_SETREDRAW, TRUE, 0
	ret
ListViewClearAll ENDP

end