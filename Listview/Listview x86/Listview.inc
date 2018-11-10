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

ListViewSelectAll		    PROTO :DWORD                                                    ; hListview
ListViewDeselectAll         PROTO :DWORD,:DWORD                                             ; hListview, bFocused

ListViewClearAll		    PROTO :DWORD                                                    ; hListview
ListViewDeleteAll           EQU ListViewClearAll

ListViewDeleteItem          PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex

ListViewInsertItem		    PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, nItemIndex, lpszItemText, nImageListIndex
ListViewInsertSubItem	    PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, nItemIndex, nSubItemIndex, lpszSubItemText

ListViewCheckboxSet		    PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, dwCheckedState
ListViewCheckboxToggle      PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex
    
ListViewSetSelected	        PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, bFocused
ListViewGetSelected	        PROTO :DWORD,:DWORD                                             ; hListview, bFocused
ListViewSetFocused          PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex
ListViewGetFocused          PROTO :DWORD                                                    ; hListview

ListViewGetItemText		    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; hListview, nItemIndex, nSubItemIndex, lpszItemText, lpszItemTextSize
ListViewSetItemText		    PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, nItemIndex, nSubItemIndex, lpszItemText

ListViewSetItemImage		PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, nImageListIndex
ListViewGetItemImage		PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex

ListViewSetItemParam	    PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, dwParamValue
ListViewGetItemParam	    PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex

ListViewGetItemState        PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, dwState
ListViewSetItemState        PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, nItemIndex, dwStateMask, dwState
ListViewGetItemSelectedState PROTO :DWORD,:DWORD                                            ; hListview, nItemIndex

ListViewGetItemRect         PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, dwPtrRect
ListViewGetSubItemRect      PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nItemIndex, dwPtrRect

ListViewAltRowColor         PROTO :DWORD,:DWORD                                             ; lParam, dwAltRowColor
ListViewAltRowColorDlg      PROTO :DWORD,:DWORD,:DWORD                                      ; hWin, lParam, dwAltRowColor
ListViewARCBoldItem         PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; lParam, dwAltRowColor, nBoldItem, hBoldFont, hNormalFont
ListViewARCBoldItemDlg      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                 ; hWin, lParam, dwAltRowColor, nBoldItem, hBoldFont, hNormalFont

ListViewSubClassProc        PROTO :DWORD,:DWORD                                             ; hListview, lpdwLVSubClassProc
ListViewSubClassData        PROTO :DWORD,:DWORD                                             ; hListview, lpdwLVSubClassData

ListViewStyleGridlines		PROTO :DWORD                                                    ; hListview
ListViewStyleCheckboxes		PROTO :DWORD                                                    ; hListview
ListViewStyleFullRowSelect  PROTO :DWORD                                                    ; hListview
ListViewStyleSubItemImages  PROTO :DWORD                                                    ; hListview
ListViewStyleHdrDragDrop    PROTO :DWORD                                                    ; hListview
ListViewStyleBorderSelect   PROTO :DWORD                                                    ; hListview
ListViewStyleDoubleBuffer   PROTO :DWORD                                                    ; hListview
ListViewStyleNoColumnResize PROTO :DWORD                                                    ; hListview
ListViewStyleToggle         PROTO :DWORD,:DWORD                                             ; hListview, dwExStyle

ListViewLinkImagelist       PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, hImagelist, ImagelistType

ListViewGetColumnCount      PROTO :DWORD                                                    ; hListview
ListViewGetColumnWidth      PROTO :DWORD,:DWORD                                             ; hListview, nCol
ListViewGetColumnFormat     PROTO :DWORD,:DWORD                                             ; hListview, nCol
ListViewGetItemCount        PROTO :DWORD                                                    ; hListview

ListViewInsertColumn        PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, dwFormat, dwWidth, lpszColumnText
ListViewInsertColumnImage   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; hListview, dwFormat, dwWidth, lpszColumnText, nImageListIndex
ListViewSetColumnText       PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, nColumnIndex, lpszColumnText

ListViewIsRowSelected       PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex
ListViewIsRowHighlighted    PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex
ListViewEnableHighlighting  PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex
ListViewDisableHighlighting PROTO :DWORD,:DWORD                                             ; hListview, nItemIndex

ListViewShowItemContextMenu PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hWin, hListview, hRightClickMenu, dwRequiresSelection
ListViewEnsureVisible       PROTO :DWORD,:DWORD
ListViewEnsureSubItemVisible PROTO :DWORD,:DWORD                                            ; hListview, dwSubItem
ListViewFindItem            PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; hListview, lpszFindString, dwStartItem, dwStartSubItem, dwStartCol, dwEndCol, bShowFoundItem, bCaseSensitive 

ListViewGetItemClicked      PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hListview, lParam, lpdwItem, lpdwSubItem
ListViewGetSubItemClicked   PROTO :DWORD,:DWORD,:DWORD                                      ; hListview, lpdwItem, lpdwSubItem


; For ListViewCheckboxSet
LVCB_UNCHECKED              EQU 0 
LVCB_CHECKED                EQU 1

IFNDEF NMLVDISPINFOA
NMLVDISPINFOA               STRUCT
    hdr                     NMHDR <>
    item                    LVITEM <>
NMLVDISPINFOA               ENDS
ENDIF






