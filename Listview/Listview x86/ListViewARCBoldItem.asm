.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include gdi32.inc
includelib gdi32.lib

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
; Alt Colors for rows in listview and bold specified item
; place in NM_CUSTOMDRAW of WM_NOTIFY
;**************************************************************************	
ListViewARCBoldItem PROC PUBLIC USES EBX ECX lParam:DWORD, dwAltRowColor:DWORD, nBoldItem:DWORD, hBoldFont:DWORD, hNormalFont:DWORD
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
        
    	.IF  _mod(nItem,2) == 0                                 ; Calc mod of item to see if the background should be applied
    	    mov eax, dwAltRowColor
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax;       00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText,00000000h     ; text color = red
    	.ELSE
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk,0FFFFFFh    ;Background text = white
    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText,00h           ; text color = black
    		
    	.ENDIF    
    	
        mov ebx, nItem
    	.IF nBoldItem == ebx ; if item matches our specified item to bold
    	    mov ecx, lParam
    	    mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdc
    	    Invoke SelectObject, eax, hBoldFont
    	.ELSE
    	    mov ecx, lParam
    	    mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdc
    	    Invoke SelectObject, eax, hNormalFont
    	.ENDIF    	
    		            
        mov eax, CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
        ret
        
    .ELSE
        mov eax, CDRF_DODEFAULT
        ret
    .ENDIF    
    
    ret

ListViewARCBoldItem ENDP

end