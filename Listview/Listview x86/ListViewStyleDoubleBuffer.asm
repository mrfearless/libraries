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
ListViewStyleDoubleBuffer PROC PUBLIC USES EAX hListview:DWORD

    Invoke SendMessage, hListview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0   ; Get current extended styles 
	AND eax, LVS_EX_DOUBLEBUFFER                                          ; Checkboxes
	.IF eax == LVS_EX_DOUBLEBUFFER
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
