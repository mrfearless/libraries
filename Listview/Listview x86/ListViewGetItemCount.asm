.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Gets the item count (total rows) and returns it in eax
;**************************************************************************	
ListViewGetItemCount PROC PUBLIC hListview:DWORD
    Invoke SendMessage, hListview, LVM_GETITEMCOUNT, 0, 0
    ret
ListViewGetItemCount ENDP

end
