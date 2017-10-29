.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
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
ListViewGetSubItemRect PROC PUBLIC USES EBX hListview:DWORD, nItemIndex:DWORD, dwPtrRect:DWORD
;    mov ebx, dwPtrRect
;    mov eax, nItemIndex
;    mov [ebx].RECT.top, eax
;    mov eax, LVIR_BOUNDS
;    mov [ebx].RECT.left, eax
	invoke SendMessage, hListview, LVM_GETSUBITEMRECT, nItemIndex, dwPtrRect
	ret
ListViewGetSubItemRect ENDP

end