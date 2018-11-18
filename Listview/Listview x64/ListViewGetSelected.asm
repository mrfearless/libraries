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
; Get Index of Currently Selected Item in Listview. Returns it in RAX
;**************************************************************************	
ListViewGetSelected PROC FRAME hListview:QWORD, bFocused:QWORD
    .IF bFocused == TRUE
	    Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_SELECTED or LVNI_FOCUSED
	.ELSE
	    Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_SELECTED
	.ENDIF	
	ret
ListViewGetSelected ENDP

end