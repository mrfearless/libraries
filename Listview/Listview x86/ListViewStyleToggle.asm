.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code



;**************************************************************************	
; Toggles Extended Listview Style  On/Off
;**************************************************************************
ListViewStyleToggle	PROC PUBLIC USES EBX hListview:DWORD, dwExStyle:DWORD

    Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	AND eax, dwExStyle                                          ; Checkboxes
	.IF eax == dwExStyle
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, dwExStyle, 0 ;eax ; Do It
	.ELSE
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, dwExStyle, dwExStyle ;eax ; Do It
	.ENDIF

	; Get current extended styles like gridlines
	;Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0	
	;mov ebx, dwExStyle; like LVS_EX_CHECKBOXES for Checkboxes etc
	;xor eax, ebx ; Toggle checkboxes on/off
	;Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, eax ; Do It	
	ret
ListViewStyleToggle endp	



end