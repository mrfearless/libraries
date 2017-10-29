.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Toggles Checkbox Column  On/Off
;**************************************************************************
ListViewStyleCheckboxes PROC PUBLIC USES EAX hListview:DWORD
	Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0	; Get current extended styles like gridlines
	AND eax, LVS_EX_CHECKBOXES                                          ; Checkboxes
	.IF eax == LVS_EX_CHECKBOXES
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