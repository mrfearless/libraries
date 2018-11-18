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
ListViewGetItemClicked PROC FRAME USES RBX RCX hListview:QWORD, lParam:QWORD, lpqwItem:QWORD, lpqwSubItem:QWORD
    LOCAL iItem:QWORD
    LOCAL iSubItem:QWORD
    
    mov rcx, lParam
    mov rbx, [rcx].NMHDR.hwndFrom
    mov eax, [rcx].NMHDR.code
        
    .IF rbx != hListview
        jmp ExitFalse
    .ENDIF
	.IF eax != NM_CLICK
	    jmp ExitFalse
	.ENDIF

	mov eax, (NMITEMACTIVATE ptr [rcx]).iItem
	mov iItem, rax
	mov eax, (NMITEMACTIVATE ptr [rcx]).iSubItem
	mov iSubItem, rax

ExitTrue:


    .IF rax == -1
        jmp ExitFalse
    .ENDIF
    mov rax, iItem
    mov rbx, lpqwItem
    .IF rbx != NULL
        mov [rbx], rax
    .ENDIF
    mov rax, iSubItem
    mov rbx, lpqwSubItem
    .IF rbx != NULL
        mov [rbx], rax
    .ENDIF
    
    mov rax, TRUE
    jmp Exit

ExitFalse:

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

Exit:    
    
    ret

ListViewGetItemClicked ENDP


end