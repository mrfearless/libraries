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
ListViewClearAll PROC PUBLIC hListview:DWORD
    Invoke SendMessage, hListview, WM_SETREDRAW, FALSE, 0
	Invoke SendMessage, hListview, LVM_DELETEALLITEMS, 0, 0 ; Clear all list items
	Invoke SendMessage, hListview, WM_SETREDRAW, TRUE, 0
	ret
ListViewClearAll ENDP

end