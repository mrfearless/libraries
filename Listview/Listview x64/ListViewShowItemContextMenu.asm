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
ListViewShowItemContextMenu PROC FRAME  hWin:QWORD, hListview:QWORD, hRightClickMenu:QWORD
	LOCAL LVMenuPoint:POINT

    Invoke SendMessage, hListview , LVM_GETNEXTITEM, -1, LVNI_FOCUSED+LVNI_SELECTED
    .IF eax == -1
        ret ; no need to show menu as nothing selected
    .ENDIF
	
	Invoke GetCursorPos, Addr LVMenuPoint 
	; Focus Main Window - ; Fix for shortcut menu not popping up right
	Invoke SetForegroundWindow, hWin
	Invoke TrackPopupMenu, hRightClickMenu, TPM_LEFTALIGN + TPM_LEFTBUTTON + TPM_RIGHTBUTTON, LVMenuPoint.x, LVMenuPoint.y, NULL, hWin, NULL
	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right
	ret
ListViewShowItemContextMenu ENDP

end