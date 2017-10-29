.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Ensures item is visible in listview
;**************************************************************************	

ListViewEnsureVisible PROC hListview:DWORD, nItemIndex:DWORD
    
    Invoke SendMessage, hListview, LVM_ENSUREVISIBLE, nItemIndex, FALSE
    ret

ListViewEnsureVisible ENDP


end




