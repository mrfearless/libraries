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
; Returns the width of the specified column in rax, or 0 otherwise
;**************************************************************************
ListViewGetColumnWidth PROC FRAME hListview:QWORD, nCol:QWORD
	invoke SendMessage, hListview, LVM_GETCOLUMNWIDTH, nCol, 0
	ret
ListViewGetColumnWidth ENDP


end