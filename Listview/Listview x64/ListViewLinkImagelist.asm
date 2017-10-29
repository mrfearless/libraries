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
; Links specified listview with an imagelist
;
; LVSIL_NORMAL    equ 0
; LVSIL_SMALL     equ 1
; LVSIL_STATE     equ 2
;
;
;**************************************************************************
ListViewLinkImagelist PROC FRAME  hListview:QWORD, hImagelist:QWORD, ImagelistType:QWORD
    .IF hImagelist != NULL && hListview != NULL
        invoke SendMessage, hListview, LVM_SETIMAGELIST, ImagelistType, hImagelist
    .ENDIF
    ret
ListViewLinkImagelist ENDP

end