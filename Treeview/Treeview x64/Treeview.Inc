;=========================================================================================
;
; LICENSE
;
; LTLI TreeView x64 Library v1.0.0.0
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
; original copyright notices intact and not mispresent the origin of the software.
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
; LTLI TreeView LIB Prototypes
;-----------------------------------------------------------------------------------------

TreeViewClearAll		    PROTO :QWORD
TreeViewDeleteAll           EQU TreeViewClearAll

TreeViewInsertItem          PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD

TreeViewGetSelectedImage    PROTO :QWORD
TreeViewGetSelectedItem     PROTO :QWORD
TreeViewGetSelectedParam    PROTO :QWORD
TreeViewGetSelectedText     PROTO :QWORD, :QWORD, :QWORD

TreeViewGetItemText         PROTO :QWORD, :QWORD, :QWORD, :QWORD
TreeViewGetItemImage        PROTO :QWORD, :QWORD
TreeViewGetItemParam        PROTO :QWORD, :QWORD

TreeViewSetItemText         PROTO :QWORD, :QWORD, :QWORD
TreeViewSetItemImage        PROTO :QWORD, :QWORD, :QWORD
TreeViewSetItemParam        PROTO :QWORD, :QWORD, :QWORD

TreeViewChildItemsExpand    PROTO :QWORD, :QWORD
TreeViewChildItemsCollapse  PROTO :QWORD, :QWORD
TreeViewChildItemsToggle    PROTO :QWORD, :QWORD

TreeViewSetSelectedItem     PROTO :QWORD, :QWORD

TreeViewSubClassProc        PROTO :QWORD, :QWORD
TreeViewSubClassData        PROTO :QWORD, :QWORD

TreeViewLinkImageList       PROTO :QWORD, :QWORD, :QWORD

TreeViewDrawSelectedItem    PROTO :QWORD
TreeViewDrawSelectedItemDlg PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD















