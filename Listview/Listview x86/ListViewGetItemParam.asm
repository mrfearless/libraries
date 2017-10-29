.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the lParam of the specified index. ParamValue is a 32bit dword value
; Returns the value in eax.
;**************************************************************************
ListViewGetItemParam PROC PUBLIC hListview:DWORD, nItemIndex:DWORD
    LOCAL LVItem:LV_ITEM
	mov LVItem.imask,LVIF_PARAM
	mov eax, nItemIndex
	mov LVItem.iItem, eax
	mov LVItem.iSubItem,0 
	invoke SendMessage, hListview, LVM_GETITEM, nItemIndex, Addr LVItem
	.iF eax == TRUE
		mov eax, LVItem.lParam
	.ELSE
		mov eax, -1
	.ENDIF
	ret
ListViewGetItemParam ENDP

end