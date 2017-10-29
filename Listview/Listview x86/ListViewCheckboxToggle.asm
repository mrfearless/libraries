.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Toggles the Listitem checkbox. nItem is the 0 based index to specify.
;**************************************************************************	
ListViewCheckboxToggle PROC PUBLIC USES EAX hListview:DWORD, nItemIndex:DWORD
	LOCAL LVItem:LV_ITEM
	mov eax, nItemIndex
	mov LVItem.iItem, eax	
	mov LVItem.iSubItem, 0
	mov LVItem.imask, LVIF_STATE
	mov LVItem.stateMask, LVIS_STATEIMAGEMASK
	xor eax, eax
	mov LVItem.state, eax
	Invoke SendMessage, hListview, LVM_GETITEMSTATE, nItemIndex, addr LVItem
    and eax, (3 SHL 12)
    .if(eax==(2 SHL 12))        ; If checked item 
	    xor eax, eax
	    mov eax,1               ; unset check
	    shl eax,12	
	    mov LVItem.state, eax
	.ELSE
    	xor eax, eax
    	mov eax,2               ; set check
    	shl eax,12	
    	mov LVItem.state, eax    
    .ENDIF    
	Invoke SendMessage, hListview, LVM_SETITEMSTATE, nItemIndex, addr LVItem
    ret
ListViewCheckboxToggle ENDP

end