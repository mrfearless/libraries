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
; Sets the lParam of the specified index. ParamValue is a 64bit qword value
;**************************************************************************
ListViewSetItemParam PROC FRAME  hListview:QWORD, nItemIndex:QWORD, ParamValue:QWORD
	LOCAL LVItem:LV_ITEM
	mov LVItem.mask_,LVIF_PARAM
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	mov rax, ParamValue
	mov LVItem.lParam, rax
	invoke SendMessage, hListview, LVM_SETITEM, 0, Addr LVItem
	ret
ListViewSetItemParam ENDP

end