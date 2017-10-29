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
; Set an Listitem checkbox state. nItem is the 0 based index to specify.
;
; LVCB_UNCHECKED              EQU 0 
; LVCB_CHECKED                EQU 1
;
;**************************************************************************
ListViewSetCheckbox	PROC FRAME hListview:QWORD, nItemIndex:QWORD, dwCheckedState:QWORD
	LOCAL LVItem:LV_ITEM
	mov rax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0
	mov LVItem.mask_, LVIF_STATE
	mov LVItem.stateMask, LVIS_STATEIMAGEMASK
	xor eax, eax
	.IF dwCheckedState == 1
	    mov eax, 2      ; set check
	.ELSE               ; 0 
	    mov eax, 1      ; set uncheck
	.ENDIF        
	shl eax,12	
	mov LVItem.state, eax
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem
	ret
ListViewSetCheckbox ENDP

end
