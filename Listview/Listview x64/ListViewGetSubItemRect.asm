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
; Gets the bounding rect of the specified subitem. 
;
; The left member of the rect must be set before calling, to one of these:
;
; LVIR_BOUNDS       Returns the bounding rectangle of the entire item, 
;                   including the icon and label.
; LVIR_ICON         Returns the bounding rectangle of the icon / smallicon
; LVIR_LABEL        Returns the bounding rectangle of the item text.
; LVIR_SELECTBOUNDS Returns the union of the LVIR_ICON and LVIR_LABEL 
;                   rectangles, but excludes columns in report view.
;
;**************************************************************************
ListViewGetSubItemRect PROC FRAME hListview:QWORD, nItemIndex:QWORD, qwPtrRect:QWORD
	invoke SendMessage, hListview, LVM_GETSUBITEMRECT, nItemIndex, qwPtrRect
	ret
ListViewGetSubItemRect ENDP


end