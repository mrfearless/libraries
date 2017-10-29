.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

EXTERNDEF ListViewGetColumnCount :PROTO :DWORD

.code

;**************************************************************************	
; Set listview column text
;**************************************************************************	
ListViewSetColumnText PROC PUBLIC hListview:DWORD, nColumnIndex:DWORD, lpszColumnText:DWORD 
    LOCAL LVC:LV_COLUMN
    
    Invoke ListViewGetColumnCount, hListview
    .IF eax <= nColumnIndex
        mov eax, FALSE
        ret
    .ENDIF
	mov LVC.imask, LVCF_TEXT
    mov eax, lpszColumnText	
	mov LVC.pszText, eax
	Invoke SendMessage, hListview, LVM_SETCOLUMN, nColumnIndex, Addr LVC
	ret  
ListViewSetColumnText ENDP

end	
	