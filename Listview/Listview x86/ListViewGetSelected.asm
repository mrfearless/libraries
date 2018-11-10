.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code
;**************************************************************************	
; Get Index of Currently Selected Item in Listview. Returns it in EAX
;**************************************************************************	
ListViewGetSelected PROC PUBLIC hListview:DWORD, bFocused:DWORD
    .IF bFocused == TRUE
	    Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_SELECTED or LVNI_FOCUSED
	.ELSE
	    Invoke SendMessage, hListview, LVM_GETNEXTITEM, -1, LVNI_SELECTED
	.ENDIF
	ret
ListViewGetSelected ENDP

end