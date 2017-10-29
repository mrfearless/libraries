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

;**************************************************************************
; MOD Macro
;**************************************************************************
_mod MACRO val1:REQ, val2:REQ
    push rcx
    mov  rax,val1
    mov  rcx,val2
    xor  rdx,rdx
    div  rcx  
    pop rcx
    exitm <rdx>
endm

.code

;**************************************************************************	
; Alt Colors for rows in listview.
; place in NM_CUSTOMDRAW of WM_NOTIFY
; !!!! - IMPORTANT - !!!! - after calling this function you must use a RET

;		    .IF eax == NM_CUSTOMDRAW
;		        Invoke ListViewAltRowColor, lParam, 00FFF3F2h
;		        ret
		        
;**************************************************************************	
ListViewAltRowColor PROC FRAME USES RCX lParam:QWORD, dqAltRowColor:QWORD
    LOCAL nSubItem:DWORD
    LOCAL nItem:DWORD
    
    mov rcx, lParam
    mov eax, (NMLVCUSTOMDRAW ptr[rcx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        mov rax, CDRF_NOTIFYITEMDRAW
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov rax, CDRF_NOTIFYSUBITEMDRAW
        ret
        
    .ELSEIF eax == CDDS_ITEMPREPAINT or CDDS_SUBITEM
        mov rcx, lParam
        mov eax, (NMLVCUSTOMDRAW ptr[rcx]).iSubItem
        mov nSubItem, eax
        mov eax, dword ptr (NMLVCUSTOMDRAW ptr[rcx]).nmcd.dwItemSpec      ; item
        mov nItem, eax
        
    	.IF  _mod(rax,2) == 1                                ; Calc mod of item to see if the background should be applied
    	    mov rax, dqAltRowColor
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrTextBk, eax;       00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrText,00000000h     ; text color = red
    	.ELSE
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrTextBk,0FFFFFFh    ;Background text = white
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrText,00h           ; text color = black
    		
    	.ENDIF    	            
        mov rax, CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
        ret
        
    .ELSE
        mov rax, CDRF_DODEFAULT
        ret
    .ENDIF    
    
    ret

ListViewAltRowColor ENDP


end




