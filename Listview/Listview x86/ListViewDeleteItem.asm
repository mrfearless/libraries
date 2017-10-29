.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Delete all data from listview
;**************************************************************************	
ListViewDeleteItem PROC PUBLIC hListview:DWORD, nItemIndex:DWORD
	Invoke SendMessage, hListview, LVM_DELETEITEM, nItemIndex, 0 ; Clear all list items
	ret
ListViewDeleteItem ENDP

end

