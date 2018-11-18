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
; Get the item and subitem clicked.
; Returns true if an item and/or sub item have been clicked or false otherwise
; if true the buffers pointed to by lpqwItem and lpqwSubItem will contain
; the item and subitem clicked, otherwise they will contain -1
;
; Uses LVM_SUBITEMHITTEST to determine iItem and iSubItem.
; To fake NM_CLICK calls use ListViewGetItemClicked instead
; As that will use the NMITEMACTIVATE structure of NM_CLICK to retrieve
; the iItem and iSubItem values.
;**************************************************************************	
ListViewGetSubItemClicked PROC FRAME USES RBX hListview:QWORD, lpqwItem:QWORD, lpqwSubItem:QWORD
    LOCAL lvhi:LVHITTESTINFO
    

	Invoke GetCursorPos, Addr lvhi.pt
	Invoke ScreenToClient, hListview, addr lvhi.pt
	invoke SendMessage, hListview, LVM_SUBITEMHITTEST, 0, Addr lvhi ; returns the column and item that was clicked in lvhi
		
	Invoke SendMessage, hListview, LVM_GETITEMCOUNT, 0, 0
	.IF eax > lvhi.iItem ;0		
	    mov eax, lvhi.iItem
        mov rbx, lpqwItem
        .IF rbx != NULL
            mov [rbx], rax
        .ENDIF	 
	    mov eax, lvhi.iSubItem
        mov rbx, lpqwSubItem
        .IF rbx != NULL
            mov [rbx], rax
        .ENDIF	    
	    mov rax, TRUE
    .ELSE
        mov rax, -1
        mov rbx, lpqwItem
        .IF rbx != NULL
            mov [rbx], rax
        .ENDIF
        mov rbx, lpqwSubItem
        .IF rbx != NULL
            mov [rbx], rax
        .ENDIF
        mov rax, FALSE
    .ENDIF
    ret

ListViewGetSubItemClicked ENDP


end