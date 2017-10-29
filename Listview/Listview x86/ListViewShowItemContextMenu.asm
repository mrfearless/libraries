.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; call from WM_NOTIFY - NM_RCLICK, example:
;	
;	.ELSEIF eax==WM_NOTIFY
;		mov ecx, lParam				; lParam is a pointer to a NMHDR Struct
;		mov eax, (NMHDR PTR [ecx]).code
;		mov ebx, (NMHDR PTR [ecx]).hwndFrom
;		.IF ebx == hMyListview
;	        .IF eax == NM_RCLICK ; right click popup
;	            Invoke ListViewShowItemContextMenu, hWin, hMyListview, hLVRCMenu ; if no item is selected in listview, no menu is shown
;	            
;**************************************************************************
ListViewShowItemContextMenu PROC PUBLIC hWin:DWORD, hListview:DWORD, hRightClickMenu:DWORD, dwRequiresSelection:DWORD
	LOCAL LVMenuPoint:POINT

    .IF dwRequiresSelection == TRUE
        Invoke SendMessage, hListview , LVM_GETNEXTITEM, -1, LVNI_FOCUSED+LVNI_SELECTED
        .IF eax == -1
            ret ; no need to show menu as nothing selected
        .ENDIF
    .ENDIF
	
	Invoke GetCursorPos, Addr LVMenuPoint 
	; Focus Main Window - ; Fix for shortcut menu not popping up right
	Invoke SetForegroundWindow, hWin
	Invoke TrackPopupMenu, hRightClickMenu, TPM_LEFTALIGN + TPM_LEFTBUTTON + TPM_RIGHTBUTTON, LVMenuPoint.x, LVMenuPoint.y, NULL, hWin, NULL
	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right
	ret
ListViewShowItemContextMenu ENDP

end