.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Returns the width of the specified column in eax, or 0 otherwise
;**************************************************************************
ListViewGetColumnWidth PROC PUBLIC hListview:DWORD, nCol:DWORD
	invoke SendMessage, hListview, LVM_GETCOLUMNWIDTH, nCol, 0
	ret
ListViewGetColumnWidth ENDP

end


















