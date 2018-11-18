;=========================================================================================
;
; LICENSE
;
; LTLI Listview Library x64 v1.0.0.0
;
; Copyright (c) 2017 by KSR aka fearless
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
; LTLI Listview Prototypes
;-----------------------------------------------------------------------------------------

ListViewSelectAll		    PROTO :QWORD                                                    ; hListview
ListViewDeselectAll         PROTO :QWORD,:QWORD                                             ; hListview, bFocused

ListViewClearAll		    PROTO :QWORD                                                    ; hListview
ListViewDeleteAll           EQU ListViewClearAll

ListViewDeleteItem          PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex

ListViewInsertItem		    PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, nItemIndex, lpszItemText, nImageListIndex
ListViewInsertSubItem	    PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, nItemIndex, nSubItemIndex, lpszSubItemText

ListViewCheckboxSet		    PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, qwCheckedState
ListViewCheckboxToggle      PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex
    
ListViewSetSelected	        PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, bFocused
ListViewGetSelected	        PROTO :QWORD,:QWORD                                             ; hListview, bFocused
ListViewSetFocused          PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex
ListViewGetFocused          PROTO :QWORD                                                    ; hListview

ListViewGetItemText		    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD                        ; hListview, nItemIndex, nSubItemIndex, lpszItemText, lpszItemTextSize
ListViewSetItemText		    PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, nItemIndex, nSubItemIndex, lpszItemText

ListViewSetItemImage		PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, nImageListIndex
ListViewGetItemImage		PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex

ListViewSetItemParam	    PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, qwParamValue
ListViewGetItemParam	    PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex

ListViewGetItemState        PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, qwState
ListViewSetItemState        PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, nItemIndex, qwStateMask, qwState
ListViewGetItemSelectedState PROTO :QWORD,:QWORD                                            ; hListview, nItemIndex

ListViewGetItemRect         PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, qwPtrRect
ListViewGetSubItemRect      PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nItemIndex, qwPtrRect

ListViewAltRowColor         PROTO :QWORD,:QWORD                                             ; lParam, qwAltRowColor
ListViewAltRowColorDlg      PROTO :QWORD,:QWORD,:QWORD                                      ; hWin, lParam, qwAltRowColor
ListViewARCBoldItem         PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD                        ; lParam, qwAltRowColor, nBoldItem, hBoldFont, hNormalFont
ListViewARCBoldItemDlg      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD                 ; hWin, lParam, qwAltRowColor, nBoldItem, hBoldFont, hNormalFont

ListViewSubClassProc        PROTO :QWORD,:QWORD                                             ; hListview, lpqwLVSubClassProc
ListViewSubClassData        PROTO :QWORD,:QWORD                                             ; hListview, lpqwLVSubClassData

ListViewStyleGridlines		PROTO :QWORD                                                    ; hListview
ListViewStyleCheckboxes		PROTO :QWORD                                                    ; hListview
ListViewStyleFullRowSelect  PROTO :QWORD                                                    ; hListview
ListViewStyleSubItemImages  PROTO :QWORD                                                    ; hListview
ListViewStyleHdrDragDrop    PROTO :QWORD                                                    ; hListview
ListViewStyleBorderSelect   PROTO :QWORD                                                    ; hListview
ListViewStyleDoubleBuffer   PROTO :QWORD                                                    ; hListview
ListViewStyleNoColumnResize PROTO :QWORD                                                    ; hListview
ListViewStyleToggle         PROTO :QWORD,:QWORD                                             ; hListview, qwExStyle

ListViewLinkImagelist       PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, hImagelist, ImagelistType

ListViewGetColumnCount      PROTO :QWORD                                                    ; hListview
ListViewGetColumnWidth      PROTO :QWORD,:QWORD                                             ; hListview, nCol
ListViewGetColumnFormat     PROTO :QWORD,:QWORD                                             ; hListview, nCol
ListViewGetItemCount        PROTO :QWORD                                                    ; hListview

ListViewInsertColumn        PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, qwFormat, qwWidth, lpszColumnText
ListViewInsertColumnImage   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD                        ; hListview, qwFormat, qwWidth, lpszColumnText, nImageListIndex
ListViewSetColumnText       PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, nColumnIndex, lpszColumnText

ListViewIsRowSelected       PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex
ListViewIsRowHighlighted    PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex
ListViewEnableHighlighting  PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex
ListViewDisableHighlighting PROTO :QWORD,:QWORD                                             ; hListview, nItemIndex

ListViewShowItemContextMenu PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hWin, hListview, hRightClickMenu, qwRequiresSelection
ListViewEnsureVisible       PROTO :QWORD,:QWORD
ListViewEnsureSubItemVisible PROTO :QWORD,:QWORD                                            ; hListview, qwSubItem
ListViewFindItem            PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD   ; hListview, lpszFindString, qwStartItem, qwStartSubItem, qwStartCol, qwEndCol, bShowFoundItem, bCaseSensitive 

ListViewGetItemClicked      PROTO :QWORD,:QWORD,:QWORD,:QWORD                               ; hListview, lParam, lpqwItem, lpqwSubItem
ListViewGetSubItemClicked   PROTO :QWORD,:QWORD,:QWORD                                      ; hListview, lpqwItem, lpqwSubItem


; For ListViewCheckboxSet
LVCB_UNCHECKED              EQU 0 
LVCB_CHECKED                EQU 1





















