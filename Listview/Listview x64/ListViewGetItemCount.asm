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
; Gets column count and returns it in eax
;**************************************************************************	

ListViewGetItemCount PROC FRAME  hListview:QWORD
    Invoke SendMessage, hListview, LVM_GETITEMCOUNT, 0, 0
    ret
ListViewGetItemCount ENDP

end
