.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

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

;		    .IF eax == NM_CUSTOMDRAW
;		        Invoke ListViewAltRowColor, lParam, 00FFF3F2h
;		        ret
		        
;**************************************************************************	
ListViewAltRowColor PROC PUBLIC lParam:DWORD, dwAltRowColor:DWORD
    LOCAL nSubItem:DWORD
    LOCAL nItem:DWORD
    
    mov ecx, lParam
    mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        mov eax, CDRF_NOTIFYITEMDRAW
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov eax, CDRF_NOTIFYSUBITEMDRAW
        ret
        
    .ELSEIF eax == CDDS_ITEMPREPAINT or CDDS_SUBITEM
        mov ecx, lParam
        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).iSubItem
        mov nSubItem, eax
        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwItemSpec      ; item
        mov nItem, eax
        
    	.IF  _mod(nItem,2) == 1                                ; Calc mod of item to see if the background should be applied
    	    mov eax, dwAltRowColor
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax;       00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText,00000000h     ; text color = red
    	.ELSE
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk,0FFFFFFh    ;Background text = white
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText,00h           ; text color = black
    		
    	.ENDIF    	            
        mov eax, CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
        ret
        
    .ELSE
        mov eax, CDRF_DODEFAULT
        ret
    .ENDIF    
    
    ret

ListViewAltRowColor ENDP


end




