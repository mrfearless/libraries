.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewSubClassProc PROC PUBLIC hTreeview:DWORD, lpdwTVSubClassProc:DWORD
	.IF lpdwTVSubClassProc != NULL
	    Invoke SetWindowLong, hTreeview, GWL_WNDPROC, lpdwTVSubClassProc
	.ELSE
	    mov eax, NULL
	.ENDIF    
    ret
TreeViewSubClassProc endp

;**************************************************************************
; 
;**************************************************************************
TreeViewSubClassData PROC PUBLIC hTreeview:DWORD, lpdwTVSubClassData:DWORD
	.IF lpdwTVSubClassData != NULL
	    Invoke SetWindowLong, hTreeview, GWL_USERDATA, lpdwTVSubClassData
	.ELSE
	    mov eax, NULL
	.ENDIF    
    ret
TreeViewSubClassData endp

end
