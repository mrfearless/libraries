.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code
;**************************************************************************	
; Get the item and subitem clicked.
; Returns true if an item and/or sub item have been clicked or false otherwise
; if true the buffers pointed to by lpdwItem and lpdwSubItem will contain
; the item and subitem clicked, otherwise they will contain -1
;
; Uses LVM_SUBITEMHITTEST to determine iItem and iSubItem.
; To fake NM_CLICK calls use ListViewGetItemClicked instead
; As that will use the NMITEMACTIVATE structure of NM_CLICK to retrieve
; the iItem and iSubItem values.
;**************************************************************************	
ListViewGetSubItemClicked PROC USES EBX hListview:DWORD, lpdwItem:DWORD, lpdwSubItem:DWORD
    LOCAL lvhi:LVHITTESTINFO
    

	Invoke GetCursorPos, Addr lvhi.pt
	Invoke ScreenToClient, hListview, addr lvhi.pt
	invoke SendMessage, hListview, LVM_SUBITEMHITTEST, 0, Addr lvhi ; returns the column and item that was clicked in lvhi
		
	Invoke SendMessage, hListview, LVM_GETITEMCOUNT, 0, 0
	.IF eax > lvhi.iItem ;0		
	    mov eax, lvhi.iItem
        mov ebx, lpdwItem
        .IF ebx != NULL
            mov [ebx], eax
        .ENDIF	 
	    mov eax, lvhi.iSubItem
        mov ebx, lpdwSubItem
        .IF ebx != NULL
            mov [ebx], eax
        .ENDIF	    
	    mov eax, TRUE
    .ELSE
        mov eax, -1
        mov ebx, lpdwItem
        .IF ebx != NULL
            mov [ebx], eax
        .ENDIF
        mov ebx, lpdwSubItem
        .IF ebx != NULL
            mov [ebx], eax
        .ENDIF
        mov eax, FALSE
    .ENDIF
    ret

ListViewGetSubItemClicked ENDP



end