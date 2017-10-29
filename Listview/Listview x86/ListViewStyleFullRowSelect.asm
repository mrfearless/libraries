.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Toggles Listview Gridlines On/Off
;**************************************************************************	
ListViewStyleFullRowSelect PROC PUBLIC USES EAX hListview:DWORD
    Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	AND eax, LVS_EX_FULLROWSELECT                                          ; Checkboxes
	.IF eax == LVS_EX_FULLROWSELECT
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, 0 ;eax ; Do It
	.ELSE
	    Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_FULLROWSELECT, LVS_EX_FULLROWSELECT ;eax ; Do It
	.ENDIF
	;Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	;mov edx, LVS_EX_FULLROWSELECT                                       
	;xor eax, edx                                                        ; 
	;Invoke SendMessage, hListview, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT ;eax ; Do It
	ret
ListViewStyleFullRowSelect ENDP

end
