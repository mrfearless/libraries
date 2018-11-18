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
; Toggles Checkbox Column  On/Off
;**************************************************************************
ListViewStyleCheckboxes PROC FRAME hListview:QWORD
	Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0	; Get current extended styles like gridlines
	AND rax, LVS_EX_CHECKBOXES                                          ; Checkboxes
	.IF rax == LVS_EX_CHECKBOXES
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_CHECKBOXES, 0 ;eax ; Do It
	.ELSE
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_CHECKBOXES, LVS_EX_CHECKBOXES ;eax ; Do It
	.ENDIF
	;mov edx, LVS_EX_CHECKBOXES                                          ; Checkboxes
	;xor eax, edx                                                        ; Toggle checkboxes on/off
	;Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_CHECKBOXES ;eax ; Do It
	ret
ListViewStyleCheckboxes ENDP

end	