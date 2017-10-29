.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the text of the specified index. 
;**************************************************************************
ListViewGetItemSelectedState PROC PUBLIC hListview:DWORD, nItemIndex:DWORD
	invoke SendMessage, hListview, LVM_GETITEMSTATE, nItemIndex, LVIS_SELECTED
	ret
ListViewGetItemSelectedState ENDP

end