.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Get the currently focused item
;**************************************************************************	
ListViewGetFocused PROC PUBLIC hListview:DWORD
	Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_FOCUSED
	ret
ListViewGetFocused endp

end