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
; This is different than the ListViewGetSubItemClicked function, which uses
; LVM_SUBITEMHITTEST to determine iItem and iSubItem.
;
; This function uses the NMITEMACTIVATE structure of NM_CLICK to retrieve
; the iItem and iSubItem values.
; Thus allowing us to fake NM_CLICK calls if required (tab, shift-tab
; in listview to go forward, backward to next/prev subitem)
;
; It requires you pass the lParam value for it to work.
;
;**************************************************************************	
ListViewGetItemClicked PROC USES EBX ECX hListview:DWORD, lParam:DWORD, lpdwItem:DWORD, lpdwSubItem:DWORD
    LOCAL iItem:DWORD
    LOCAL iSubItem:DWORD
    
    mov ecx, lParam
    mov ebx, [ecx].NMHDR.hwndFrom
    mov eax, [ecx].NMHDR.code
        
    .IF ebx != hListview
        jmp ExitFalse
    .ENDIF
	.IF eax != NM_CLICK
	    jmp ExitFalse
	.ENDIF

	mov eax, (NMITEMACTIVATE ptr [ecx]).iItem
	mov iItem, eax
	mov eax, (NMITEMACTIVATE ptr [ecx]).iSubItem
	mov iSubItem, eax

ExitTrue:


    .IF eax == -1
        jmp ExitFalse
    .ENDIF
    mov eax, iItem
    mov ebx, lpdwItem
    .IF ebx != NULL
        mov [ebx], eax
    .ENDIF
    mov eax, iSubItem
    mov ebx, lpdwSubItem
    .IF ebx != NULL
        mov [ebx], eax
    .ENDIF
    
    mov eax, TRUE
    jmp Exit

ExitFalse:

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

Exit:    
    
    ret

ListViewGetItemClicked ENDP




end