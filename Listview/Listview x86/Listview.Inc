;=========================================================================================
;
; LICENSE
;
; LTLI Listview Library v1.0.0.10
;
; Copyright (c) 2014 by KSR aka -[Nwo]- ƒearless
;
; All Rights Reserved
;
; http://www.LetTheLight.in
;
;
; This software is provided 'as-is', without any express or implied warranty. In no
; event will the author be held liable for any damages arising from the use of this
; software.
;
; Permission is granted to anyone to use this software for any non-commercial program.
; If you use the library in an application, an acknowledgement in the application or
; documentation is appreciated but not required. 
;
; You are allowed to make modifications to the source code, but you must leave the
; original copyright notices intact and not misrepresent the origin of the software.
; It is not allowed to claim you wrote the original software. Modified files must have
; a clear notice that the files are modified, and not in the original state. This includes
; the name of the person(s) who modified the code. 
;
; If you want to distribute or redistribute any portion of this package, you will need
; to include the full package in it's original state, including this license and all
; the copyrights. 
;
; While distributing this package (in it's original state) is allowed, it is not allowed
; to charge anything for this. You may not sell or include the package in any commercial
; package without having permission of the author. Neither is it allowed to redistribute
; any of the package's components with commercial applications.
;
;=========================================================================================

;-----------------------------------------------------------------------------------------
; LTLI Listview LIB Prototypes
;-----------------------------------------------------------------------------------------

ListViewSelectAll		    PROTO :DWORD
ListViewDeselectAll         PROTO :DWORD

ListViewClearAll		    PROTO :DWORD
ListViewDeleteAll           EQU ListViewClearAll

ListViewDeleteItem          PROTO :DWORD, :DWORD

ListViewInsertItem		    PROTO :DWORD, :DWORD, :DWORD, :DWORD
ListViewInsertSubItem	    PROTO :DWORD, :DWORD, :DWORD, :DWORD

ListViewCheckboxSet		    PROTO :DWORD, :DWORD, :DWORD
ListViewCheckboxToggle      PROTO :DWORD, :DWORD
    
ListViewSetSelected	        PROTO :DWORD, :DWORD
ListViewGetSelected	        PROTO :DWORD
ListViewSetFocused          PROTO :DWORD, :DWORD

ListViewGetItemText		    PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ListViewSetItemText		    PROTO :DWORD, :DWORD, :DWORD, :DWORD

ListViewSetItemImage		PROTO :DWORD, :DWORD, :DWORD
ListViewGetItemImage		PROTO :DWORD, :DWORD

ListViewSetItemParam	    PROTO :DWORD, :DWORD, :DWORD
ListViewGetItemParam	    PROTO :DWORD, :DWORD

ListViewGetItemState        PROTO :DWORD, :DWORD, :DWORD
ListViewSetItemState        PROTO :DWORD, :DWORD, :DWORD, :DWORD

ListViewGetItemRect         PROTO :DWORD, :DWORD, :DWORD
ListViewGetSubItemRect      PROTO :DWORD, :DWORD, :DWORD
ListViewGetItemSelectedState PROTO :DWORD, :DWORD

ListViewAltRowColor         PROTO :DWORD, :DWORD
ListViewAltRowColorDlg      PROTO :DWORD, :DWORD, :DWORD ;, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ListViewARCBoldItem         PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ListViewARCBoldItemDlg      PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

ListViewSubClassProc        PROTO :DWORD, :DWORD
ListViewSubClassData        PROTO :DWORD, :DWORD

ListViewStyleGridlines		PROTO :DWORD
ListViewStyleCheckboxes		PROTO :DWORD
ListViewStyleFullRowSelect  PROTO :DWORD
ListViewStyleSubItemImages  PROTO :DWORD
ListViewStyleHdrDragDrop    PROTO :DWORD
ListViewStyleBorderSelect   PROTO :DWORD
ListViewStyleDoubleBuffer   PROTO :DWORD
ListViewStyleNoColumnResize PROTO :DWORD
ListViewStyleToggle         PROTO :DWORD, :DWORD

ListViewLinkImagelist       PROTO :DWORD, :DWORD, :DWORD

ListViewGetColumnCount      PROTO :DWORD
ListViewGetColumnWidth      PROTO :DWORD, :DWORD
ListViewGetColumnFormat     PROTO :DWORD, :DWORD
ListViewGetItemCount        PROTO :DWORD

ListViewInsertColumn        PROTO :DWORD, :DWORD, :DWORD, :DWORD
ListViewInsertColumnImage   PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ListViewSetColumnText       PROTO :DWORD, :DWORD, :DWORD


ListViewIsRowSelected       PROTO :DWORD, :DWORD
ListViewIsRowHighlighted    PROTO :DWORD, :DWORD
ListViewEnableHighlighting  PROTO :DWORD, :DWORD
ListViewDisableHighlighting PROTO :DWORD, :DWORD


ListViewShowItemContextMenu PROTO :DWORD, :DWORD, :DWORD, :DWORD                    ; hWin:DWORD, hListview:DWORD, hRightClickMenu:DWORD, dwRequiresSelection
ListViewEnsureVisible       PROTO :DWORD, :DWORD
ListViewEnsureSubItemVisible PROTO :DWORD, :DWORD                                   ; hListview:DWORD, dwSubItem:DWORD
ListViewFindItem            PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

ListViewGetItemClicked      PROTO :DWORD, :DWORD, :DWORD, :DWORD                    ; hListview:DWORD, lParam:DWORD, lpdwItem:DWORD, lpdwSubItem:DWORD
ListViewGetSubItemClicked   PROTO :DWORD, :DWORD, :DWORD                            ; hListview:DWORD, lpdwItem:DWORD, lpdwSubItem:DWORD


; For ListViewCheckboxSet
LVCB_UNCHECKED              EQU 0 
LVCB_CHECKED                EQU 1

IFNDEF NMLVDISPINFOA
NMLVDISPINFOA               STRUCT
    hdr                     NMHDR <>
    item                    LVITEM <>
NMLVDISPINFOA               ENDS
ENDIF






