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
; Toggles Listview Gridlines On/Off
;**************************************************************************	
ListViewStyleDoubleBuffer PROC FRAME hListview:QWORD

    Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	AND rax, LVS_EX_DOUBLEBUFFER                                          ; Checkboxes
	.IF rax == LVS_EX_DOUBLEBUFFER
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_DOUBLEBUFFER, 0 ;eax ; Do It
	.ELSE
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_DOUBLEBUFFER, LVS_EX_DOUBLEBUFFER ;eax ; Do It
	.ENDIF

	;Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles like gridlines
	;mov edx, LVS_EX_GRIDLINES                                           ; gridlines
	;xor eax, edx                                                        ; Toggle gridlines on/off
	;Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_DOUBLEBUFFER ;eax ; Do It
	ret
ListViewStyleDoubleBuffer  ENDP

end
