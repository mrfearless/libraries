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

.code

;**************************************************************************
; Gets the format of a colum.

; Returns one of the following in rax: 

; LVCFMT_CENTER	Text is centered.
; LVCFMT_LEFT	Text is left-aligned.
; LVCFMT_RIGHT	Text is right-aligned.
; or -1 if invalid
; nCol is 0 based column index
;**************************************************************************
ListViewGetColumnFormat PROC FRAME hListview:QWORD, nCol:QWORD
    LOCAL LVC:LV_COLUMN

	mov LVC.mask_, LVCF_FMT
	Invoke SendMessage, hListview, LVM_GETCOLUMN, nCol, Addr LVC
	.IF rax == TRUE
        mov eax, LVC.fmt
    .ELSE
        mov eax, -1
	.ENDIF
	ret  
ListViewGetColumnFormat ENDP


end