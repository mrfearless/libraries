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
include commctrl.inc
;include user32.inc
includelib user32.lib

include TreeView.inc

;**************************************************************************
; MOD Macro
;**************************************************************************
_mod MACRO val1:REQ, val2:REQ
    push ecx
    mov  rax,val1
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
TreeViewDrawSelectedItemDlg PROC FRAME hWin:QWORD, lParam:QWORD, dqBackColor:QWORD, dqTextColor:QWORD, dqSelBackColor:QWORD, dqSelTextColor:QWORD
    
    mov rcx, lParam
    xor rax, rax
    mov eax, (NMTVCUSTOMDRAW ptr[rcx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        ;PrintText 'CDDS_PREPAINT'
        mov rax, CDRF_NOTIFYITEMDRAW
        invoke SetWindowLongPtr, hWin, DWL_MSGRESULT, eax
        mov eax, TRUE        
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov rcx, lParam
        mov eax, (NMTVCUSTOMDRAW ptr[rcx]).nmcd.uItemState
        ;PrintDec rax
    	.IF eax == CDIS_SELECTED  || eax == (CDIS_SELECTED + CDIS_FOCUS) ;|| rax == CDIS_FOCUS                               ; Calc mod of item to see if the background should be applied
    	    ;PrintText 'Selected'
    	    ;Invoke GetSysColor, COLOR_HIGHLIGHT
    	    ;mov rax, 00FFF3F2h
    	    ;mov rax, dwAltRowColor
    		mov rax, dqSelBackColor
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrTextBk, eax;       ; selected highlight color
    		mov rax, dqSelTextColor
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrText, eax ;0FFFFFFh     ; text color = white
    	.ELSE
            mov rax, dqBackColor
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrTextBk, eax ;0FFFFFFh    ; Background color = white
    		mov rax, dqTextColor
    		mov (NMTVCUSTOMDRAW ptr[rcx]).clrText, eax ;00h           ; text color = black
    	.ENDIF
  		mov eax, CDRF_NEWFONT
        invoke SetWindowLongPtr, hWin, DWL_MSGRESULT, eax
        mov eax, TRUE    	    
        ret

        
    .ELSE
        mov eax, CDRF_DODEFAULT
        invoke SetWindowLongPtr, hWin, DWL_MSGRESULT, eax
        mov eax, TRUE        
        ret
    .ENDIF    
    
    ret

TreeViewDrawSelectedItemDlg ENDP


end




