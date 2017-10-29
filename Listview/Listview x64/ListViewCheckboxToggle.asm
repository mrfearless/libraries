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
; Toggles the Listitem checkbox. nItem is the 0 based index to specify.
;**************************************************************************	
ListViewCheckboxToggle PROC  USES RAX hListview:QWORD, nItemIndex:QWORD
	LOCAL LVItem:LV_ITEM
	mov rax, nItemIndex
	mov LVItem.iItem, eax	
	mov LVItem.iSubItem, 0
	mov LVItem.mask_, LVIF_STATE
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