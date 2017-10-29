.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code


;**************************************************************************
; Gets the format of a colum.

; Returns one of the following in eax: 

; LVCFMT_CENTER	Text is centered.
; LVCFMT_LEFT	Text is left-aligned.
; LVCFMT_RIGHT	Text is right-aligned.
; or -1 if invalid
; nCol is 0 based column index
;**************************************************************************
ListViewGetColumnFormat PROC PUBLIC hListview:DWORD, nCol:DWORD
    LOCAL LVC:LV_COLUMN

	mov LVC.imask, LVCF_FMT
	Invoke SendMessage, hListview, LVM_GETCOLUMN, nCol, Addr LVC
	.IF eax == TRUE
        mov eax, LVC.fmt
    .ELSE
        mov eax, -1
	.ENDIF
	ret  
ListViewGetColumnFormat ENDP

end