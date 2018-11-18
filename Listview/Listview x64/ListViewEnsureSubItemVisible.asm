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
; Ensures sub item is visible in listview
;**************************************************************************	
ListViewEnsureSubItemVisible PROC FRAME hListview:QWORD, nSubItemIndex:QWORD
    LOCAL rectlv:RECT
    LOCAL rectsubitem:RECT

    Invoke GetWindowLongPtr, hListview, GWL_STYLE
    and rax, WS_HSCROLL
    .IF rax != WS_HSCROLL ; no scrollbar should mean we dont have to adjust anything for subitem
        ret
    .ENDIF

    ; Get area to put our editbox in
 	.IF nSubItemIndex == 0 ; LVM_GETSUBITEMRECT doesnt work with iSubItem == 0 so we calc it another way
	    mov rectsubitem.left, LVIR_BOUNDS
	    Invoke ListViewGetItemRect, hListview, 0, Addr rectsubitem
	    Invoke ListViewGetColumnWidth, hListview, 0
	    mov rectsubitem.right, eax
	.ELSE
    	mov rax, nSubItemIndex
    	mov rectsubitem.top, eax
    	mov rectsubitem.left, LVIR_BOUNDS
    	Invoke ListViewGetSubItemRect, hListview, 0, Addr rectsubitem
    .ENDIF

    Invoke GetClientRect, hListview, Addr rectlv
    
    mov eax, rectsubitem.right
    .IF eax > rectlv.right ;truerectlvright ;rectlv.right
        ;PrintText 'Need to move scrollbar right'
        mov eax, rectsubitem.right
        sub eax, rectlv.right
        Invoke SendMessage, hListview, LVM_SCROLL, rax, 0
    .ELSE
        .IF sdword ptr rectsubitem.left < 0
            ;PrintText 'Need to move scrollbar left'
            mov eax, rectsubitem.left
            sub eax, rectsubitem.right
            Invoke SendMessage, hListview, LVM_SCROLL, rax, 0
        .ENDIF
    .ENDIF
    ret
ListViewEnsureSubItemVisible ENDP


end