.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Deselect all items in listview
;**************************************************************************	
ListViewDeselectAll PROC PUBLIC USES EAX hListview:DWORD, bFocused:DWORD
	LOCAL LVItem:LV_ITEM
    .IF bFocused == TRUE
	    mov LVItem.stateMask, LVIS_SELECTED or LVIS_FOCUSED
	.ELSE
	    mov LVItem.stateMask, LVIS_SELECTED
	.ENDIF
	mov LVItem.state, NULL
	invoke SendMessage, hListview, LVM_SETITEMSTATE, -1, ADDR LVItem    ; Deselect everything

	ret
ListViewDeselectAll ENDP

end