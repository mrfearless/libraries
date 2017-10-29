.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Gets the bounding rect of the specified item. 
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
ListViewGetItemRect PROC PUBLIC hListview:DWORD, nItemIndex:DWORD, dwPtrRect:DWORD
	invoke SendMessage, hListview, LVM_GETITEMRECT, nItemIndex, dwPtrRect
	ret
ListViewGetItemRect ENDP

end