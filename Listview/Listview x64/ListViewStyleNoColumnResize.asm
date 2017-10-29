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

ListViewHeaderProc          PROTO :HWND, :UINT, :WPARAM, :LPARAM

.data
pListviewHeaderOldProc      DQ 0 ; for disabling resize of listview columns - calls default proc from subclass proc

.code

;**************************************************************************	
; For subclassing listview header. Used with ListViewHeaderProc
;**************************************************************************	
ListViewStyleNoColumnResize PROC FRAME hListview:QWORD
    invoke GetWindow, hListview, GW_CHILD
    Invoke SetWindowLong, rax, GWL_WNDPROC, Addr ListViewHeaderProc ;OFFSET
    ;invoke SetWindowLong, hListview, GWL_USERDATA, eax
    mov pListviewHeaderOldProc, rax
    ret

ListViewStyleNoColumnResize endp


;**************************************************************************	
; To disable listview column resizing
;**************************************************************************	
ListViewHeaderProc PROC FRAME  hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

    .if uMsg==WM_LBUTTONDOWN
	    ;invoke GetWindowLong, hWin, GWL_USERDATA
	    ;invoke CallWindowProc, eax, hWin, NULL, NULL, NULL   
        invoke CallWindowProc, pListviewHeaderOldProc, hWin, NULL, NULL, NULL
        ret
    .elseif uMsg==WM_SETCURSOR
	    ;invoke GetWindowLong, hWin, GWL_USERDATA
	    ;invoke CallWindowProc, eax, hWin, NULL, NULL, NULL       
        invoke CallWindowProc, pListviewHeaderOldProc, hWin, NULL, NULL, NULL
        ret
    .else
	    ;invoke GetWindowLong, hWin, GWL_USERDATA
	    ;invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam     
        invoke CallWindowProc, pListviewHeaderOldProc, hWin, uMsg, wParam, lParam
        ret
    .endif
    ret
ListViewHeaderProc ENDP

end