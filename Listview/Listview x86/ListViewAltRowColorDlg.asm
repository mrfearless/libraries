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

.data
LVARCDSelectedItem      DD -1

.code

;**************************************************************************	
; Alt Colors for rows in listview when used in a dialog
; requires SetWindowLong.
; After call always include a ret instruction
; place in NM_CUSTOMDRAW of WM_NOTIFY
;
; Example:
;
;    .ELSEIF eax == WM_NOTIFY
;		mov ecx, lParam
;		mov eax, ( [ecx].NMHDR.code)
;		mov ebx, ( [ecx].NMHDR.hwndFrom)
;        .IF ebx == hMyListview ; handle to your listview control
;		    .IF eax == NM_CUSTOMDRAW
;		        Invoke ListViewAltRowColorDlg, hWin, lParam, 00F9F9F9h ; hWin as passed to main msg handler, lParam as passed to main msg handler, dwAltRowColor
;		    .ENDIF
;		.ENDIF    
;
;**************************************************************************	
ListViewAltRowColorDlg PROC PUBLIC hWin:DWORD, lParam:DWORD, dwAltRowColor:DWORD
    LOCAL nSubItem:DWORD
    LOCAL nItem:DWORD
    
    mov ecx, lParam
    mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwDrawStage
    .IF eax == CDDS_PREPAINT
        mov eax, CDRF_NOTIFYITEMDRAW
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov eax, TRUE        
        ret
         
    .ELSEIF eax == CDDS_ITEMPREPAINT
        mov eax, CDRF_NOTIFYSUBITEMDRAW
        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
        mov eax, TRUE        
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

ListViewAltRowColorDlg ENDP


;ListViewAltRowColorDlg PROC hWin:DWORD, lParam:DWORD, dwAltRowBackColor:DWORD, dwAltRowTextColor:DWORD, dwBackColor:DWORD, dwTextColor:DWORD, dwSelBackColor:DWORD, dwSelTextColor:DWORD, dwCurrentSelection:DWORD
;    LOCAL nSubItem:DWORD
;    LOCAL nItem:DWORD
;    LOCAL hLV:DWORD
;	LOCAL rect:RECT
;	LOCAL hdc:HDC
;	LOCAL hBrush:DWORD
;    
;    mov ecx, lParam
;    mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwDrawStage
;    .IF eax == CDDS_PREPAINT
;        mov eax, CDRF_NOTIFYITEMDRAW ;or CDRF_DOERASE
;        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;        mov eax, TRUE
;        ret
;         
;    .ELSEIF eax == CDDS_ITEMPREPAINT
;        mov ecx, lParam
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).iSubItem
;        mov nSubItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwItemSpec      ; item
;        mov nItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdr.hwndFrom
;        mov hLV, eax
;    	mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdc                 ; Get hdc for listview for filling in small rect with the selection bar color
;    	mov hdc, eax        
;        
;        mov eax, dwCurrentSelection
;        .IF eax == nItem
;            ;PrintDec dwCurrentSelection
;            Invoke ListViewSetItemState, hLV, nItem, LVIS_SELECTED, 0
;            mov ecx, lParam
;    	    mov eax, dwSelBackColor
;    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax        ;00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
;    		mov eax, dwSelTextColor
;    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00000000h     ;
;            
;            ;mov rect.left, LVIR_BOUNDS
;            ;Invoke ListViewGetItemRect, hLV, nItem, Addr rect
;            ;Invoke CreateSolidBrush,dwSelBackColor
;            ;mov hBrush, eax
;            ;Invoke FillRect, hdc, Addr rect, hBrush
;            ;Invoke DeleteObject, hBrush
;            
;            ;mov eax, CDRF_NOTIFYPOSTPAINT ;or CDRF_DOERASE
;            mov eax, CDRF_NOTIFYSUBITEMDRAW
;        .ELSE
;;       	    .IF _mod(nItem,2) == 1                                 ; Calc mod of item to see if the background should be applied
;;        	    mov eax, dwAltRowBackColor
;;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax        ;00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
;;        		mov eax, dwAltRowTextColor
;;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00000000h     ; text color = red
;;        	.ELSE
;;        	    mov eax, dwBackColor
;;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax ;0FFFFFFh    ;Background color = white
;;        		mov eax, dwTextColor
;;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00h           ; text color = black        
;;            .ENDIF
;            
;            mov eax, CDRF_NOTIFYSUBITEMDRAW ;or CDRF_DOERASE
;        .ENDIF
;        ;    mov eax, CDRF_NOTIFYPOSTPAINT        
;        ;.ELSE
;            ;Invoke ListViewGetItemState, hLV, nItem, LVIS_SELECTED ;+ LVIS_FOCUSED
;        	;.IF eax == LVIS_SELECTED || eax == LVIS_SELECTED ;+ LVIS_FOCUSED ;|| eax == LVIS_FOCUSED || eax == LVIS_SELECTED + LVIS_FOCUSED
;        	    ;Invoke ListViewGetSelected, hLV    
;            ;    mov eax, nItem
;            ;    mov ecx, lpCurrentSelection
;            ;    ;mov LVARCDSelectedItem, eax
;            ;    mov [ecx], eax
;            ;    Invoke ListViewSetItemState, hLV, nItem, LVIS_SELECTED, 0
;            ;    mov eax, CDRF_NOTIFYPOSTPAINT
;            ;.ELSE
;            ;    mov eax, CDRF_NOTIFYSUBITEMDRAW    
;            ;.ENDIF
;        ;.ENDIF
;         ;or CDRF_NOTIFYPOSTPAINT or CDRF_DOERASE
;        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;        mov eax, TRUE
;        ret
;
;    .ELSEIF eax == CDRF_NOTIFYPOSTPAINT
;        mov ecx, lParam
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).iSubItem
;        mov nSubItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwItemSpec      ; item
;        mov nItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdr.hwndFrom
;        mov hLV, eax
;        
;        mov eax, dwCurrentSelection
;    	.IF eax == nItem
;            Invoke ListViewSetItemState, hLV, nItem, LVIS_SELECTED, LVIS_SELECTED
;        .ENDIF
;        mov eax, CDRF_DODEFAULT 
;        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;        mov eax, TRUE
;        ret
;        
;        
;    .ELSEIF eax == CDDS_ITEMPREPAINT or CDDS_SUBITEM
;        mov ecx, lParam
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).iSubItem
;        mov nSubItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.dwItemSpec      ; item
;        mov nItem, eax
;        mov eax, (NMLVCUSTOMDRAW ptr[ecx]).nmcd.hdr.hwndFrom
;        mov hLV, eax
;        
;        mov eax, dwCurrentSelection
;        .IF eax == nItem
;        ;Invoke ListViewGetItemState, hLV, nItem, LVIS_SELECTED + LVIS_FOCUSED
;    	;.IF eax == LVIS_SELECTED || eax == LVIS_FOCUSED || eax == LVIS_SELECTED + LVIS_FOCUSED;CDIS_SELECTED  || eax == (CDIS_SELECTED + CDIS_FOCUS)         
;    	    mov eax, dwSelBackColor
;    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax        ;00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
;    		mov eax, dwSelTextColor
;    		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00000000h     ;
;  		    ;mov eax, CDRF_NEWFONT or CDRF_NOTIFYSUBITEMDRAW or CDRF_NOTIFYPOSTPAINT or CDDS_ITEMPOSTPAINT
;            ;invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;            ;mov eax, TRUE    	    
;            ;ret    		
;        .ELSE
;            
;        	.IF  _mod(nItem,2) == 1                                 ; Calc mod of item to see if the background should be applied
;        	    mov eax, dwAltRowBackColor
;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax        ;00F9F9F9h; 00F9F9F9h ; Light Grey | 00FFF3F2h Light Blue | 00FFF0E6h; 00FFE4D0h ; 00A6F7F0h ;Background text = light yellow
;        		mov eax, dwAltRowTextColor
;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00000000h     ; text color = red
;        	.ELSE
;        	    mov eax, dwBackColor
;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrTextBk, eax ;0FFFFFFh    ;Background color = white
;        		mov eax, dwTextColor
;        		mov (NMLVCUSTOMDRAW ptr[ecx]).clrText, eax ;00h           ; text color = black
;        		
;        	.ENDIF
;        .ENDIF
;        mov eax, CDRF_NOTIFYSUBITEMDRAW or CDRF_NOTIFYPOSTPAINT or CDDS_ITEMPOSTPAINT ;or CDRF_DOERASE;CDRF_NOTIFYSUBITEMDRAW ;CDRF_DODEFAULT
;        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;        mov eax, TRUE	            
;        ret
;        
;    .ELSE
;        mov eax, CDRF_DODEFAULT
;        invoke SetWindowLong,hWin,DWL_MSGRESULT,eax
;        mov eax, TRUE
;        ret
;    .ENDIF    
;    
;    ret
;
;ListViewAltRowColorDlg ENDP

end