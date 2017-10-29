.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

include windows.inc
include commctrl.inc
includelib user32.lib

include Listview.inc

EXTERNDEF ListViewGetColumnCount :PROTO :QWORD

.code

;**************************************************************************	
; Set listview column text
;**************************************************************************	
ListViewSetColumnText PROC FRAME  hListview:QWORD, nColumnIndex:QWORD, lpszColumnText:QWORD 
    LOCAL LVC:LV_COLUMN
    
    Invoke ListViewGetColumnCount, hListview
    .IF rax <= nColumnIndex
        mov rax, FALSE
        ret
    .ENDIF
	mov LVC.mask_, LVCF_TEXT
    mov rax, lpszColumnText	
	mov LVC.pszText, rax
	Invoke SendMessage, hListview, LVM_SETCOLUMN, nColumnIndex, Addr LVC
	ret  
ListViewSetColumnText ENDP

end	
	