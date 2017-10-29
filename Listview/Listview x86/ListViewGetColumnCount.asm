.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Gets column count and returns it in eax
;**************************************************************************	
ListViewGetColumnCount PROC PUBLIC hListview:DWORD
    Invoke SendMessage, hListview, LVM_GETHEADER, NULL, NULL
    Invoke SendMessage, eax, HDM_GETITEMCOUNT, NULL, NULL
    ret
ListViewGetColumnCount ENDP

end