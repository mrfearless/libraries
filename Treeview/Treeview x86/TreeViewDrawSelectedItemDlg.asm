.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive


;.686
;.MMX
;.XMM
;.model flat,stdcall
;option casemap:none
;include \masm32\macros\macros.asm
;
;DEBUG32 EQU 1
;
;IFDEF DEBUG32
;    PRESERVEXMMREGS equ 1
;    includelib M:\Masm32\lib\Debug32.lib
;    DBG32LIB equ 1
;    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
;    include M:\Masm32\include\debug32.inc
;ENDIF


include windows.inc

include user32.inc
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

;		    .IF eax == NM_CUSTOMDRAW
;		        Invoke ListViewAltRowColor, lParam, 00FFF3F2h
;		        ret
		        
;**************************************************************************	
TreeViewDrawSelectedItemDlg PROC PUBLIC hWin:DWORD, lParam:DWORD, dwBackColor:DWORD, dwTextColor:DWORD, dwSelBackColor:DWORD, dwSelTextColor:DWORD
    
    mov ecx, lParam
    mov eax, (NMTVCUSTOMDRAW ptr[ecx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        ;PrintText 'CDDS_PREPAINT'
        mov eax, CDRF_NOTIFYITEMDRAW
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov eax, TRUE        
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov ecx, lParam
        mov eax, (NMTVCUSTOMDRAW ptr[ecx]).nmcd.uItemState
        ;PrintDec eax
    	.IF eax == CDIS_SELECTED  || eax == (CDIS_SELECTED + CDIS_FOCUS) ;|| eax == CDIS_FOCUS                               ; Calc mod of item to see if the background should be applied
    	    ;PrintText 'Selected'
    	    ;Invoke GetSysColor, COLOR_HIGHLIGHT
    	    ;mov eax, 00FFF3F2h
    	    ;mov eax, dwAltRowColor
    		mov eax, dwSelBackColor
    		mov (NMTVCUSTOMDRAW ptr[ecx]).clrTextBk, eax;       ; selected highlight color
    		mov eax, dwSelTextColor
    		mov (NMTVCUSTOMDRAW ptr[ecx]).clrText, eax ;0FFFFFFh     ; text color = white
    	.ELSE
            mov eax, dwBackColor
    		mov (NMTVCUSTOMDRAW ptr[ecx]).clrTextBk, eax ;0FFFFFFh    ; Background color = white
    		mov eax, dwTextColor
    		mov (NMTVCUSTOMDRAW ptr[ecx]).clrText, eax ;00h           ; text color = black
    	.ENDIF
  		mov eax, CDRF_NEWFONT
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov eax, TRUE    	    
        ret

        
    .ELSE
        mov eax, CDRF_DODEFAULT
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov eax, TRUE        
        ret
    .ENDIF    
    
    ret

TreeViewDrawSelectedItemDlg ENDP


end




