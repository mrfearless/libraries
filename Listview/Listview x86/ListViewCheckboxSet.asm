.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
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
ListViewCheckboxSet	PROC PUBLIC USES EAX hListview:DWORD, nItemIndex:DWORD, dwCheckedState:DWORD
	LOCAL LVItem:LV_ITEM
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem, 0
	mov LVItem.imask, LVIF_STATE
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
ListViewCheckboxSet ENDP

end
