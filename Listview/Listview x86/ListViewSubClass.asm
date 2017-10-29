.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Subclass listview procedure
;
; handle to listview to subclass (hListview)
; offset to procedure to subclass to (lpdwLVSubClassProc)
;
; Returns in eax, pointer to older proc required for subclass to use
; NULL if failure
;**************************************************************************
ListViewSubClassProc PROC PUBLIC hListview:DWORD, lpdwLVSubClassProc:DWORD
	.IF lpdwLVSubClassProc != NULL
	    Invoke SetWindowLong, hListview, GWL_WNDPROC, lpdwLVSubClassProc
	.ELSE
	    mov eax, NULL
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
ListViewSubClassData PROC PUBLIC hListview:DWORD, lpdwLVSubClassData:DWORD
	.IF lpdwLVSubClassData != NULL
        Invoke SetWindowLong, hListview, GWL_USERDATA, lpdwLVSubClassData
    .ELSE
        mov eax, NULL
    .ENDIF
    ret
ListViewSubClassData ENDP

end	