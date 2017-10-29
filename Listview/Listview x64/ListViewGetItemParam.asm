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
; Gets the lParam of the specified index. ParamValue is a 32bit dword value
; Returns the value in eax.
;**************************************************************************
ListViewGetItemParam PROC FRAME  hListview:QWORD, nItemIndex:QWORD
    LOCAL LVItem:LV_ITEM
	mov LVItem.mask_,LVIF_PARAM
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	invoke SendMessage, hListview, LVM_GETITEM, nItemIndex, Addr LVItem
	.iF rax == TRUE
		mov rax, LVItem.lParam
	.ELSE
		mov rax, -1
	.ENDIF
	ret
ListViewGetItemParam ENDP

end