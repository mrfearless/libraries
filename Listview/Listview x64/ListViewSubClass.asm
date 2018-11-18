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
; Subclass listview procedure
;
; handle to listview to subclass (hListview)
; offset to procedure to subclass to (lpdwLVSubClassProc) LONG_PTR
;
; Returns in eax, pointer to older proc required for subclass to use
; NULL if failure
;**************************************************************************
ListViewSubClassProc PROC FRAME hListview:QWORD, lpdqLVSubClassProc:QWORD
	.IF lpdqLVSubClassProc != NULL
	    Invoke SetWindowLongPtr, hListview, GWLP_WNDPROC, lpdqLVSubClassProc
	.ELSE
	    mov rax, NULL
	.ENDIF    
	ret
ListViewSubClassProc ENDP


;**************************************************************************	
; Subclass listview Data
;
; handle to listview to subclass (hListview)
; offset to procedure to subclass to (lpdwLVSubClassProc)
;
; Returns in eax, pointer to older proc required for subclass to use
; NULL if failure
;**************************************************************************
ListViewSubClassData PROC FRAME hListview:QWORD, lpdqLVSubClassData:QWORD
	.IF lpdqLVSubClassData != NULL
        Invoke SetWindowLongPtr, hListview, GWLP_USERDATA, lpdqLVSubClassData
    .ELSE
        mov rax, NULL
    .ENDIF
    ret
ListViewSubClassData ENDP

end	