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


;-----------------------------------------------------------------------------------------
; LTLI Listview Structures
;-----------------------------------------------------------------------------------------

ListViewSelectAll		    PROTO :QWORD
ListViewDeselectAll         PROTO :QWORD

ListViewClearAll		    PROTO :QWORD
ListViewDeleteAll           EQU ListViewClearAll

ListViewDeleteItem          PROTO :QWORD, :QWORD

ListViewInsertItem		    PROTO :QWORD, :QWORD, :QWORD, :QWORD
ListViewInsertSubItem	    PROTO :QWORD, :QWORD, :QWORD, :QWORD

ListViewCheckboxSet		    PROTO :QWORD, :QWORD, :QWORD
ListViewCheckboxToggle      PROTO :QWORD, :QWORD
    
ListViewSetSelected	        PROTO :QWORD, :QWORD
ListViewGetSelected	        PROTO :QWORD
ListViewSetFocused          PROTO :QWORD, :QWORD

ListViewGetItemText		    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
ListViewSetItemText		    PROTO :QWORD, :QWORD, :QWORD, :QWORD

ListViewSetItemImage		PROTO :QWORD, :QWORD, :QWORD
ListViewGetItemImage		PROTO :QWORD, :QWORD

ListViewSetItemParam	    PROTO :QWORD, :QWORD, :QWORD
ListViewGetItemParam	    PROTO :QWORD, :QWORD

ListViewGetItemState        PROTO :QWORD, :QWORD, :QWORD
ListViewSetItemState        PROTO :QWORD, :QWORD, :QWORD, :QWORD

ListViewGetItemRect         PROTO :QWORD, :QWORD, :QWORD

ListViewGetItemSelectedState PROTO :QWORD, :QWORD

ListViewAltRowColor         PROTO :QWORD, :QWORD
ListViewAltRowColorDlg      PROTO :QWORD, :QWORD, :QWORD
ListViewARCBoldItem         PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
ListViewARCBoldItemDlg      PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD

ListViewSubClassProc        PROTO :QWORD, :QWORD
ListViewSubClassData        PROTO :QWORD, :QWORD

ListViewStyleGridlines		PROTO :QWORD
ListViewStyleCheckboxes		PROTO :QWORD
ListViewStyleFullRowSelect  PROTO :QWORD
ListViewStyleSubItemImages  PROTO :QWORD
ListViewStyleHdrDragDrop    PROTO :QWORD
ListViewStyleBorderSelect   PROTO :QWORD
ListViewStyleDoubleBuffer   PROTO :QWORD
ListViewStyleNoColumnResize PROTO :QWORD
ListViewStyleToggle         PROTO :QWORD, :QWORD

ListViewLinkImagelist       PROTO :QWORD, :QWORD, :QWORD

ListViewGetColumnCount      PROTO :QWORD
ListViewGetItemCount        PROTO :QWORD

ListViewInsertColumn        PROTO :QWORD, :QWORD, :QWORD, :QWORD
ListViewInsertColumnImage   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
ListViewSetColumnText       PROTO :QWORD, :QWORD, :QWORD


ListViewIsRowSelected       PROTO :QWORD, :QWORD
ListViewIsRowHighlighted    PROTO :QWORD, :QWORD
ListViewEnableHighlighting  PROTO :QWORD, :QWORD
ListViewDisableHighlighting PROTO :QWORD, :QWORD


ListViewShowItemContextMenu PROTO :QWORD, :QWORD, :QWORD

; For ListViewCheckboxSet
LVCB_UNCHECKED              EQU 0 
LVCB_CHECKED                EQU 1





















