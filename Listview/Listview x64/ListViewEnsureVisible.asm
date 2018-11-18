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
; Ensures item is visible in listview
;**************************************************************************	
ListViewEnsureVisible PROC FRAME hListview:QWORD, nItemIndex:QWORD
    
    Invoke SendMessage, hListview, LVM_ENSUREVISIBLE, nItemIndex, FALSE
    ret

ListViewEnsureVisible ENDP


end