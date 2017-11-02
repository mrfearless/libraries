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
;include user32.inc
includelib user32.lib

include TreeView.inc

;**************************************************************************
; MOD Macro
;**************************************************************************
_mod MACRO val1:REQ, val2:REQ
    push ecx
    mov  eax,val1
    mov  ecx,val2
    xor  edx,edx
    div  ecx  
    pop ecx
    exitm <edx>
endm

.code

;**************************************************************************	
; Alt Colors for rows in listview.
; place in NM_CUSTOMDRAW of WM_NOTIFY
; !!!! - IMPORTANT - !!!! - after calling this function you must use a RET

;		    .IF rax == NM_CUSTOMDRAW
;		        Invoke ListViewAltRowColor, lParam, 00FFF3F2h
;		        ret
		        
;**************************************************************************	
TreeViewDrawSelectedItem PROC FRAME lParam:QWORD;, dwSelColor:QWORD
    
    mov rcx, lParam
    xor rax, rax
    mov eax, (NMTVCUSTOMDRAW ptr[rcx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        mov eax, CDRF_NOTIFYITEMDRAW
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov eax, CDRF_NOTIFYSUBITEMDRAW
        ret
        
    .ELSEIF eax == CDDS_ITEMPREPAINT or CDDS_SUBITEM
        mov rcx, lParam
        mov eax, (NMTVCUSTOMDRAW ptr[rcx]).nmcd.uItemState
        
    	.IF eax == CDIS_SELECTED                                ; Calc mod of item to see if the background should be applied
    	    Invoke GetSysColor, COLOR_HIGHLIGHT
    	    ;mov rax, dwAltRowColor
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrTextBk, eax;       ; selected highlight color
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrText, 0FFFFFFh     ; text color = white
    	.ELSE
    	    mov eax, CDRF_DODEFAULT
            ret
    		;mov (NMTVCUSTOMDRAW ptr[ecx]).clrTextBk,0FFFFFFh    ; Background color = white
    		;mov (NMTVCUSTOMDRAW ptr[ecx]).clrText,00h           ; text color = black
    	.ENDIF    	            
        mov eax, CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
        ret
        
    .ELSE
        mov eax, CDRF_DODEFAULT
        ret
    .ENDIF    
    
    ret

TreeViewDrawSelectedItem ENDP


end




