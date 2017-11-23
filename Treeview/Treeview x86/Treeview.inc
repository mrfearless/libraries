;=========================================================================================
;
; LICENSE
;
; LTLI TreeView Library v1.0.0.0
;
; Copyright (c) 2014 by KSR aka fearless
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

TreeViewClearAll		    PROTO :DWORD                                                    ; hTreeview
TreeViewDeleteAll           EQU TreeViewClearAll                                            ; hTreeview

TreeViewGetSelectedImage    PROTO :DWORD                                                    ; hTreeview, hItem
TreeViewGetSelectedItem     PROTO :DWORD                                                    ; hTreeview, hItem
TreeViewGetSelectedParam    PROTO :DWORD                                                    ; hTreeview, hItem
TreeViewGetSelectedText     PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem
TreeViewSetSelectedItem     PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem, bEnsureVisible

TreeViewGetItemText         PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hTreeview, hItem
TreeViewGetItemImage        PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewGetItemParam        PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewSetItemText         PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem
TreeViewSetItemImage        PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem
TreeViewSetItemParam        PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem

TreeViewItemDelete          PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewItemHasChildren     PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewItemInsert          PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; hTreeview, hNodeParent, lpszNodeText, nNodeIndex, NodePosition, nImage, nImageSelected, dwParam
TreeViewItemToggle          PROTO :DWORD,:DWORD                                             ; hTreeview, hItem

TreeViewSubClassProc        PROTO :DWORD,:DWORD                                             ; hTreeview, lpdwTVSubClassProc
TreeViewSubClassData        PROTO :DWORD,:DWORD                                             ; hTreeview, lpdwTVSubClassData

TreeViewLinkImageList       PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview

TreeViewDrawSelectedItem    PROTO :DWORD                                                    ; hTreeview
TreeViewDrawSelectedItemDlg PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                 ; hWin, lParam, dwBackColor, dwTextColor, dwSelBackColor, dwSelTextColor

TreeViewCountItems          PROTO :DWORD                                                    ; hTreeview
TreeViewCountChildren       PROTO :DWORD,:DWORD,:DWORD                                      ; hTreeview, hItem, bRecurse

TreeViewFindItem            PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hTreeview, hItem, lpszFindText, bCaseSensitive

TreeViewRootCollapse        PROTO :DWORD                                                    ; hTreeview
TreeViewRootExpand          PROTO :DWORD                                                    ; hTreeview
TreeViewBranchCollapse      PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewBranchExpand        PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewItemCollapse        PROTO :DWORD,:DWORD                                             ; hTreeview, hItem
TreeViewItemExpand          PROTO :DWORD,:DWORD                                             ; hTreeview, hItem

TreeViewBranchDepth         PROTO :DWORD, :DWORD                                            ; hTreeview, hItem

TreeViewWalk                PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; hTreeview, hItem, lpTreeViewWalkCallback, lpCustomData
;TreeViewWalkCallback       PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD          ; hTreeview, hItem, dwStatus, dwTotalItems, dwItemNo, dwLevel, dwCustomData


;-----------------------------------------------------------------------------------------
; LTLI TreeView LIB Constants
;-----------------------------------------------------------------------------------------
.CONST
; TreeView Walk Callback Status (dwStatus):
TREEVIEWWALK_NULL              EQU 0
TREEVIEWWALK_ITEM              EQU 1
TREEVIEWWALK_ITEM_START        EQU 2
TREEVIEWWALK_ITEM_FINISH       EQU 3
TREEVIEWWALK_ROOT_START        EQU 4
TREEVIEWWALK_ROOT_FINISH       EQU 5






















