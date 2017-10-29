.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

ListViewHeaderProc          PROTO :DWORD, :DWORD, :DWORD, :DWORD

.data
pListviewHeaderOldProc      DD 0 ; for disabling resize of listview columns - calls default proc from subclass proc

.code

;**************************************************************************	
; For subclassing listview header. Used with ListViewHeaderProc
;**************************************************************************	
ListViewStyleNoColumnResize PROC PUBLIC hListview:DWORD
    
    invoke GetWindow, hListview, GW_CHILD
    Invoke SetWindowLong, eax, GWL_WNDPROC, OFFSET ListViewHeaderProc
    ;invoke SetWindowLong, hListview, GWL_USERDATA, eax
    mov pListviewHeaderOldProc, eax
    ret

ListViewStyleNoColumnResize endp


;**************************************************************************	
; To disable listview column resizing
;**************************************************************************	
ListViewHeaderProc PROC PRIVATE hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

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