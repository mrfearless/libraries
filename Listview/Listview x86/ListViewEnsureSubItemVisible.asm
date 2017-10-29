.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************	
; Ensures sub item is visible in listview
;**************************************************************************	
ListViewEnsureSubItemVisible PROC hListview:DWORD, nSubItemIndex:DWORD
    LOCAL rectlv:RECT
    LOCAL rectsubitem:RECT

    Invoke GetWindowLong, hListview, GWL_STYLE
    and eax, WS_HSCROLL
    .IF eax != WS_HSCROLL ; no scrollbar should mean we dont have to adjust anything for subitem
        ret
    .ENDIF

    ; Get area to put our editbox in
 	.IF nSubItemIndex == 0 ; LVM_GETSUBITEMRECT doesnt work with iSubItem == 0 so we calc it another way
	    mov rectsubitem.left, LVIR_BOUNDS
	    Invoke ListViewGetItemRect, hListview, 0, Addr rectsubitem
	    Invoke ListViewGetColumnWidth, hListview, 0
	    mov rectsubitem.right, eax
	.ELSE
    	mov eax, nSubItemIndex
    	mov rectsubitem.top, eax
    	mov rectsubitem.left, LVIR_BOUNDS
    	Invoke ListViewGetSubItemRect, hListview, 0, Addr rectsubitem
    .ENDIF

    Invoke GetClientRect, hListview, Addr rectlv
    
    mov eax, rectsubitem.right
    .IF eax > rectlv.right ;truerectlvright ;rectlv.right
        ;PrintText 'Need to move scrollbar right'
        mov eax, rectsubitem.right
        mov ebx, rectlv.right
        sub eax, ebx
        Invoke SendMessage, hListview, LVM_SCROLL, eax, 0
    .ELSE
        .IF sdword ptr rectsubitem.left < 0
            ;PrintText 'Need to move scrollbar left'
            mov eax, rectsubitem.left
            mov ebx, rectsubitem.right
            sub eax, ebx
            Invoke SendMessage, hListview, LVM_SCROLL, eax, 0
        .ENDIF
    .ENDIF
    ret

ListViewEnsureSubItemVisible ENDP


end




