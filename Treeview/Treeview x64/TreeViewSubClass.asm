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
;include user32.inc
includelib user32.lib

include TreeView.inc

.code

;**************************************************************************
; 
;**************************************************************************
TreeViewSubClassProc PROC FRAME hTreeview:QWORD, lpdwTVSubClassProc:QWORD
	.IF lpdwTVSubClassProc != NULL
	    Invoke SetWindowLongPtr, hTreeview, GWL_WNDPROC, lpdwTVSubClassProc
	.ELSE
	    mov rax, NULL
	.ENDIF    
    ret
TreeViewSubClassProc endp

;**************************************************************************
; 
;**************************************************************************
TreeViewSubClassData PROC FRAME hTreeview:QWORD, lpdwTVSubClassData:QWORD
	.IF lpdwTVSubClassData != NULL
	    Invoke SetWindowLongPtr, hTreeview, GWL_USERDATA, lpdwTVSubClassData
	.ELSE
	    mov rax, NULL
	.ENDIF    
    ret
TreeViewSubClassData endp

end
