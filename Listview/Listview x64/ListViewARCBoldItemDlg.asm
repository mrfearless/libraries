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
includelib gdi32.lib

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
; Alt Colors for rows in listview used in a dialog and bold specified item
; place in NM_CUSTOMDRAW of WM_NOTIFY
;**************************************************************************	
ListViewARCBoldItemDlg PROC FRAME USES RBX RCX hWin:QWORD, lParam:QWORD, dqAltRowColor:QWORD, nBoldItem:QWORD, hBoldFont:QWORD, hNormalFont:QWORD
    LOCAL nSubItem:DWORD
    LOCAL nItem:DWORD
    
    mov rcx, lParam
    mov eax, (NMLVCUSTOMDRAW ptr[rcx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        mov rax, CDRF_NOTIFYITEMDRAW
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov rax, TRUE
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov rax, CDRF_NOTIFYSUBITEMDRAW
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov rax, TRUE
        ret
        
    .ELSEIF eax == CDDS_ITEMPREPAINT or CDDS_SUBITEM
        mov rcx, lParam
        mov eax, (NMLVCUSTOMDRAW ptr[rcx]).iSubItem
        mov nSubItem, eax
        mov eax, dword ptr (NMLVCUSTOMDRAW ptr[rcx]).nmcd.dwItemSpec      ; item
        mov nItem, eax
        
    	.IF  _mod(rax,2) == 1                                 ; Calc mod of item to see if the background should be applied
    	    mov rax, dqAltRowColor
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrTextBk, eax        ;00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrText,00000000h     ; text color = red
    	.ELSE
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrTextBk,0FFFFFFh    ;Background text = white
    		mov (NMLVCUSTOMDRAW ptr[rcx]).clrText,00h           ; text color = black
    		
    	.ENDIF
    		            
        mov ebx, nItem
    	.IF nBoldItem == rbx ; if item matches our specified item to bold
    	    mov rcx, lParam
    	    mov rax, (NMLVCUSTOMDRAW ptr[rcx]).nmcd.hdc
    	    Invoke SelectObject, rax, hBoldFont
    	.ELSE
    	    mov rcx, lParam
    	    mov rax, (NMLVCUSTOMDRAW ptr[rcx]).nmcd.hdc
    	    Invoke SelectObject, rax, hNormalFont
    	.ENDIF
    		            
        mov rax, CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov rax, TRUE	            
        ret
        
    .ELSE
        mov rax, CDRF_DODEFAULT
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov rax, TRUE
        ret
    .ENDIF    
    
    ret

ListViewARCBoldItemDlg ENDP

end