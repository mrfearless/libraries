.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include user32.inc
includelib user32.lib

include Listview.inc

.code

;**************************************************************************
; Links specified listview with an imagelist
;
; LVSIL_NORMAL    equ 0
; LVSIL_SMALL     equ 1
; LVSIL_STATE     equ 2
;
;
;**************************************************************************
ListViewLinkImagelist PROC PUBLIC hListview:DWORD, hImagelist:DWORD, ImagelistType:DWORD
    .IF hImagelist != NULL && hListview != NULL
        invoke SendMessage, hListview, LVM_SETIMAGELIST, ImagelistType, hImagelist
    .ENDIF
    ret
ListViewLinkImagelist ENDP

end