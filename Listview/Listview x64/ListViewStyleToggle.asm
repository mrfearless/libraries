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
; Toggles Extended Listview Style  On/Off
;**************************************************************************
ListViewStyleToggle	PROC FRAME  USES RAX hListview:QWORD, dqExStyle:QWORD

    Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	AND rax, dqExStyle                                          ; Checkboxes
	.IF rax == dqExStyle
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, dqExStyle, 0 ;eax ; Do It
	.ELSE
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, dqExStyle, dqExStyle ;eax ; Do It
	.ENDIF

	; Get current extended styles like gridlines
	;Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0	
	;mov ebx, dwExStyle; like LVS_EX_CHECKBOXES for Checkboxes etc
	;xor eax, ebx ; Toggle checkboxes on/off
	;Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, eax ; Do It	
	ret
ListViewStyleToggle endp	



end