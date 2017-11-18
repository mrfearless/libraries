InitMenus                   PROTO :DWORD
InitMainMenu                PROTO :DWORD
InitRightClickMenu          PROTO :DWORD
InitRightClickAddSubmenu    PROTO :DWORD
InitRightClickCopySubmenu   PROTO :DWORD
InitRightClickPasteSubmenu  PROTO :DWORD
InitRightClickExportSubmenu PROTO :DWORD

UpdateMenus                 PROTO :DWORD, :DWORD
UpdateMainMenu              PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
UpdateRightClickMenu        PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
UpdateRightClickAddSubmenu  PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
UpdateRightClickCopySubmenu PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
UpdateRightClickPasteSubmenu PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
UpdateRightClickExportSubmenu PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

ShowRightClickMenu          PROTO :DWORD
ShowRightClickAddSubmenu    PROTO :DWORD

ResetMenus                  PROTO :DWORD
SaveMenuState               PROTO :DWORD, :DWORD


.CONST
BMP_ABOUT_LETTHELIGHTIN     EQU 101

; Main menu bitmaps: File
BMP_FILE_OPEN				EQU 201
BMP_FILE_CLOSE				EQU 202
BMP_FILE_NEW				EQU 203
BMP_FILE_SAVE				EQU 204
BMP_FILE_SAVEAS				EQU 205
BMP_FILE_EXPORT				EQU 206
BMP_FILE_EXPORT_CLIP		EQU 207
BMP_FILE_EXPORT_DISK		EQU 208
BMP_FILE_EXIT				EQU 209

; Main menu bitmaps: Edit
BMP_EDIT_COPY_TEXT			EQU 221
BMP_EDIT_COPY_VALUE			EQU 222
BMP_EDIT_COPY_ITEM			EQU 223
BMP_EDIT_COPY_BRANCH		EQU 224
BMP_EDIT_PASTE_TEXT			EQU 225
BMP_EDIT_PASTE_ITEM			EQU 226
BMP_EDIT_PASTE_BRANCH		EQU 227
BMP_EDIT_PASTE_JSON			EQU 228
BMP_EDIT_CUT_ITEM           EQU 0
BMP_EDIT_CUT_BRANCH         EQU 0
BMP_EDIT_FIND               EQU 229

; Right click menu bitmaps:
BMP_CMD_EDIT_ITEM 			EQU 250
BMP_CMD_ADD_ITEM 			EQU 251
BMP_CMD_DEL_ITEM 			EQU 252
BMP_CMD_COPY 				EQU 253
BMP_CMD_PASTE			    EQU 254
BMP_CMD_EXPAND_BRANCH		EQU 255
BMP_CMD_EXPAND_ALL		    EQU 256
BMP_CMD_COLLAPSE_BRANCH		EQU 257
BMP_CMD_COLLAPSE_ALL	    EQU 258
BMP_CMD_EXPORT				EQU 259
BMP_CMD_FIND				EQU BMP_EDIT_FIND

; Right click 'Add' submenu bitmaps:
BMP_CMD_ADD_ITEM_STRING		EQU 270
BMP_CMD_ADD_ITEM_NUMBER		EQU 271
BMP_CMD_ADD_ITEM_TRUE		EQU 272
BMP_CMD_ADD_ITEM_FALSE		EQU 273
BMP_CMD_ADD_ITEM_ARRAY		EQU 274
BMP_CMD_ADD_ITEM_OBJECT		EQU 275

; Right click 'Copy' submenu bitmaps:
BMP_CMD_COPY_TEXT           EQU BMP_EDIT_COPY_TEXT
BMP_CMD_COPY_VALUE          EQU BMP_EDIT_COPY_VALUE
BMP_CMD_COPY_ITEM           EQU BMP_EDIT_COPY_ITEM
BMP_CMD_COPY_BRANCH         EQU BMP_EDIT_COPY_BRANCH
BMP_CMD_CUT_ITEM            EQU BMP_EDIT_CUT_ITEM
BMP_CMD_CUT_BRANCH          EQU BMP_EDIT_CUT_BRANCH

; Right click 'Paste' submenu bitmaps:
BMP_CMD_PASTE_JSON          EQU BMP_EDIT_PASTE_JSON
BMP_CMD_PASTE_ITEM          EQU BMP_EDIT_PASTE_ITEM
BMP_CMD_PASTE_BRANCH        EQU BMP_EDIT_PASTE_BRANCH

; Right click 'Export' submenu bitmaps:
BMP_CMD_EXPORT_TREE_CLIP    EQU 290
BMP_CMD_EXPORT_BRANCH_CLIP  EQU BMP_CMD_EXPORT_TREE_CLIP
BMP_CMD_EXPORT_TREE_FILE    EQU 291
BMP_CMD_EXPORT_BRANCH_FILE  EQU BMP_CMD_EXPORT_TREE_FILE


; Main Menu IDs:
IDM_MENU                    EQU 10000
IDM_FILE_EXIT               EQU 10001
IDM_FILE_OPEN               EQU 10002
IDM_FILE_CLOSE              EQU 10003
IDM_FILE_NEW                EQU 10004
IDM_FILE_SAVE               EQU 10005
IDM_FILE_SAVEAS             EQU 10006
IDM_EDIT_COPY_TEXT	        EQU 10201
IDM_EDIT_COPY_VALUE		    EQU 10202
IDM_EDIT_CUT_ITEM	        EQU 0
IDM_EDIT_CUT_BRANCH	        EQU 0
IDM_EDIT_COPY_ITEM	        EQU 10203
IDM_EDIT_COPY_BRANCH	    EQU 10204
IDM_EDIT_PASTE_ITEM         EQU 10205
IDM_EDIT_PASTE_BRANCH       EQU 10206
IDM_EDIT_PASTE_JSON         EQU 10207
IDM_EDIT_FIND               EQU 10208
IDM_HELP_ABOUT              EQU 10101

; Right click menu IDs:
IDM_CMD_COLLAPSE_BRANCH     EQU 11000
IDM_CMD_EXPAND_BRANCH       EQU 11001
IDM_CMD_COLLAPSE_ALL        EQU 11002
IDM_CMD_EXPAND_ALL          EQU 11003
IDM_CMD_ADD_ITEM            EQU 11004
IDM_CMD_DEL_ITEM            EQU 11005
IDM_CMD_EDIT_ITEM           EQU 11006
IDM_CMD_COPY                EQU 11007
IDM_CMD_PASTE               EQU 11008
IDM_CMD_EXPORT              EQU 11009
IDM_CMD_FIND                EQU 11010

; Right click 'Add' submenu IDs:
IDM_CMD_ADD_ITEM_STRING     EQU 11020
IDM_CMD_ADD_ITEM_NUMBER     EQU 11021
IDM_CMD_ADD_ITEM_TRUE       EQU 11022
IDM_CMD_ADD_ITEM_FALSE      EQU 11023
IDM_CMD_ADD_ITEM_ARRAY      EQU 11024
IDM_CMD_ADD_ITEM_OBJECT     EQU 11025

; Right click 'Copy' submenu IDs:
IDM_CMD_COPY_TEXT           EQU 11030
IDM_CMD_COPY_VALUE          EQU 11031
IDM_CMD_CUT_ITEM            EQU 0
IDM_CMD_CUT_BRANCH          EQU 0
IDM_CMD_COPY_ITEM           EQU 11032
IDM_CMD_COPY_BRANCH         EQU 11033

; Right click 'Paste' submenu IDs:
IDM_CMD_PASTE_ITEM          EQU 11040
IDM_CMD_PASTE_BRANCH        EQU 11041
IDM_CMD_PASTE_JSON          EQU 11042

; Right click 'Export' submenu IDs:
IDM_CMD_EXPORT_TREE_CLIP    EQU 11050
IDM_CMD_EXPORT_BRANCH_CLIP  EQU 11051
IDM_CMD_EXPORT_TREE_FILE    EQU 11052
IDM_CMD_EXPORT_BRANCH_FILE  EQU 11053


.DATA
; Right click menu strings:
szTVRCMenuCollapseBranch    DB 'Collapse Branch',0
szTVRCMenuExpandBranch      DB 'Expand Branch',0
szTVRCMenuCollapseAll       DB 'Collapse All',0
szTVRCMenuExpandAll         DB 'Expand All',0
szTVRCMenuCopy              DB 'Copy',0
szTVRCMenuAddItem           DB 'Add Item',0
szTVRCMenuDelItem           DB 'Delete Item',0
szTVRCMenuEditItem          DB 'Edit Item',0
szTVRCMenuExport            DB 'Export',0
szTVRCMenuPaste             DB 'Paste',0
szTVRCMenuFindText          DB 'Find...',0

; Right click 'Add' submenu strings:
szTVRCMenuAddItemString     DB 'Add String',0
szTVRCMenuAddItemNumber     DB 'Add Number',0
szTVRCMenuAddItemTrue       DB 'Add True',0
szTVRCMenuAddItemFalse      DB 'Add False',0
szTVRCMenuAddItemArray      DB 'Add Array',0
szTVRCMenuAddItemObject     DB 'Add Object',0

; Right click 'Copy' submenu strings:
szTVRCMenuCopyText          DB 'Copy Text',0
szTVRCMenuCopyValue         DB 'Copy Value',0
szTVRCMenuCopyItem          DB 'Copy Item',0
szTVRCMenuCopyBranch        DB 'Copy Branch',0

; Right click 'Paste' submenu strings:
szTVRCMenuPasteItem         DB 'Paste Item',0
szTVRCMenuPasteBranch       DB 'Paste Branch',0
szTVRCMenuPasteJSON         DB 'Paste JSON',0
szTVRCMenuPasteInsert       DB 'Paste JSON (Insert)',0

; Right click 'Export' submenu strings:
szTVRCMenuExportTreeClip    DB 'Export tree to clipboard',0
szTVRCMenuExportBranchClip  DB 'Export branch to clipboard',0
szTVRCMenuExportTreeFile    DB 'Export tree to file',0
szTVRCMenuExportBranchFile  DB 'Export branch to file',0


.DATA
hTVMenu                     DD ? ; Right click menu
hTVAddMenu                  DD ? ; 'Add' submenu


.CODE


;-------------------------------------------------------------------------------------
; InitMenus - Initialize menus
;-------------------------------------------------------------------------------------
InitMenus PROC hWin:DWORD

    Invoke InitMainMenu, hWin
    Invoke InitRightClickMenu, hWin

    ret
InitMenus ENDP


;-------------------------------------------------------------------------------------
; InitMainMenu - Initialize main program menu
;-------------------------------------------------------------------------------------
InitMainMenu PROC hWin:DWORD
    LOCAL hMainMenu:DWORD
    LOCAL hBitmap:DWORD
    LOCAL mi:MENUITEMINFO
    
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_GRAYED
    
    Invoke GetMenu, hWin
    mov hMainMenu, eax
   
    ; Load bitmaps for main menu: File
    Invoke LoadBitmap, hInstance, BMP_FILE_OPEN
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_OPEN, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_FILE_CLOSE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_CLOSE, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_FILE_NEW
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_NEW, MF_BYCOMMAND, hBitmap, 0   
    
    Invoke LoadBitmap, hInstance, BMP_FILE_SAVE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_SAVE, MF_BYCOMMAND, hBitmap, 0       
    Invoke LoadBitmap, hInstance, BMP_FILE_SAVEAS
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_SAVEAS, MF_BYCOMMAND, hBitmap, 0       

    Invoke LoadBitmap, hInstance, BMP_FILE_EXIT
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_FILE_EXIT, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_ABOUT_LETTHELIGHTIN
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_HELP_ABOUT, MF_BYCOMMAND, hBitmap, 0
    
    ; Load bitmaps for main menu: Edit
    Invoke LoadBitmap, hInstance, BMP_EDIT_COPY_TEXT
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_COPY_TEXT, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_EDIT_COPY_VALUE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_COPY_VALUE, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_EDIT_COPY_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_COPY_ITEM, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_EDIT_COPY_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_COPY_BRANCH, MF_BYCOMMAND, hBitmap, 0

    Invoke LoadBitmap, hInstance, BMP_EDIT_PASTE_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_PASTE_ITEM, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_EDIT_PASTE_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_PASTE_BRANCH, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_EDIT_PASTE_JSON
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_PASTE_JSON, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_EDIT_FIND
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hMainMenu, IDM_EDIT_FIND, MF_BYCOMMAND, hBitmap, 0    
    
    ; Set initial state of some of the menu items
    mov mi.fState, MFS_ENABLED
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_NEW, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_OPEN, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_CLOSE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_EXIT, FALSE, Addr mi
    mov mi.fState, MFS_GRAYED
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_TEXT, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_BRANCH, FALSE, Addr mi
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_JSON, FALSE, Addr mi    

    xor eax, eax
    ret
InitMainMenu ENDP


;-------------------------------------------------------------------------------------
; InitRightClickMenu - Initialize treeview right click menu
;-------------------------------------------------------------------------------------
InitRightClickMenu PROC hWin:DWORD
    LOCAL hBitmap:DWORD
    LOCAL hSubMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_GRAYED

    ; Create right click treeview menu
    Invoke CreatePopupMenu
    mov hTVMenu, eax

    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_EDIT_ITEM, Addr szTVRCMenuEditItem
    
    ; Add submenu 'Add' to rght click menu
    Invoke InitRightClickAddSubmenu, hWin
    mov hSubMenu, eax
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_SUBMENU + MIIM_STRING + MIIM_ID
    mov mi.wID, IDM_CMD_ADD_ITEM
    mov eax, hSubMenu
    mov mi.hSubMenu, eax
    lea eax, szTVRCMenuAddItem
    mov mi.dwTypeData, eax
    Invoke InsertMenuItem, hTVMenu, IDM_CMD_ADD_ITEM, FALSE, Addr mi
    mov mi.fMask, MIIM_STATE
    mov mi.wID, 0
    mov mi.hSubMenu, 0
    mov mi.dwTypeData, 0
    
    ; Strings for right click menu
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_DEL_ITEM, Addr szTVRCMenuDelItem    
    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    
    ; Add submenu 'Copy' to right click menu
    Invoke InitRightClickCopySubmenu, hWin
    mov hSubMenu, eax
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_SUBMENU + MIIM_STRING + MIIM_ID
    mov mi.wID, IDM_CMD_COPY
    mov eax, hSubMenu
    mov mi.hSubMenu, eax
    lea eax, szTVRCMenuCopy
    mov mi.dwTypeData, eax
    Invoke InsertMenuItem, hTVMenu, IDM_CMD_COPY, FALSE, Addr mi
    mov mi.fMask, MIIM_STATE
    mov mi.wID, 0
    mov mi.hSubMenu, 0
    mov mi.dwTypeData, 0
    
    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    
    ; Add submenu 'Paste' to right click menu
    Invoke InitRightClickPasteSubmenu, hWin
    mov hSubMenu, eax
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_SUBMENU + MIIM_STRING + MIIM_ID
    mov mi.wID, IDM_CMD_PASTE
    mov eax, hSubMenu
    mov mi.hSubMenu, eax
    lea eax, szTVRCMenuPaste
    mov mi.dwTypeData, eax
    Invoke InsertMenuItem, hTVMenu, IDM_CMD_PASTE, FALSE, Addr mi
    mov mi.fMask, MIIM_STATE
    mov mi.wID, 0
    mov mi.hSubMenu, 0
    mov mi.dwTypeData, 0    
    
    
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COPY_TEXT, Addr szTVRCMenuCopyText
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COPY_VALUE, Addr szTVRCMenuCopyValue
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COPY_BRANCH, Addr szTVRCMenuCopyBranch
    ;Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    ;Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_PASTE_JSON, Addr szTVRCMenuPasteJSON
    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    
;    ; Add submenu 'Export' to rght click menu
;    Invoke InitRightClickExportSubmenu, hWin
;    mov hSubMenu, eax
;    mov mi.cbSize, SIZEOF MENUITEMINFO
;    mov mi.fMask, MIIM_SUBMENU + MIIM_STRING + MIIM_ID
;    mov mi.wID, IDM_CMD_EXPORT
;    mov eax, hSubMenu
;    mov mi.hSubMenu, eax
;    lea eax, szTVRCMenuExport
;    mov mi.dwTypeData, eax
;    Invoke InsertMenuItem, hTVMenu, IDM_CMD_EXPORT, FALSE, Addr mi
;    mov mi.fMask, MIIM_STATE
;    mov mi.wID, 0
;    mov mi.hSubMenu, 0
;    mov mi.dwTypeData, 0    
    
    
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_FIND, Addr szTVRCMenuFindText 
;    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COLLAPSE_BRANCH, Addr szTVRCMenuCollapseBranch
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_EXPAND_BRANCH, Addr szTVRCMenuExpandBranch
;    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COLLAPSE_ALL, Addr szTVRCMenuCollapseAll
;    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_EXPAND_ALL, Addr szTVRCMenuExpandAll

    ; Load bitmaps for right click menu
    Invoke LoadBitmap, hInstance, BMP_CMD_FIND
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_FIND, MF_BYCOMMAND, hBitmap, 0

;    Invoke LoadBitmap, hInstance, BMP_CMD_COLLAPSE_BRANCH
;    mov hBitmap, eax
;    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, MF_BYCOMMAND, hBitmap, 0
;    Invoke LoadBitmap, hInstance, BMP_CMD_EXPAND_BRANCH
;    mov hBitmap, eax
;    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_EXPAND_BRANCH, MF_BYCOMMAND, hBitmap, 0
;    Invoke LoadBitmap, hInstance, BMP_CMD_COLLAPSE_ALL
;    mov hBitmap, eax
;    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_COLLAPSE_ALL, MF_BYCOMMAND, hBitmap, 0
;    Invoke LoadBitmap, hInstance, BMP_CMD_EXPAND_ALL
;    mov hBitmap, eax
;    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_EXPAND_ALL, MF_BYCOMMAND, hBitmap, 0
    
    Invoke LoadBitmap, hInstance, BMP_CMD_COPY
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_COPY, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_PASTE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_PASTE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_ADD_ITEM, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EDIT_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_EDIT_ITEM, MF_BYCOMMAND, hBitmap, 0    
    Invoke LoadBitmap, hInstance, BMP_CMD_DEL_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_DEL_ITEM, MF_BYCOMMAND, hBitmap, 0

    ; Set inital state for some menu items
    mov mi.fState, MFS_GRAYED
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_TEXT, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EDIT_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_DEL_ITEM, FALSE, Addr mi
    ;Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, FALSE, Addr mi
    ;Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_BRANCH, FALSE, Addr mi
    ;Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_ALL, FALSE, Addr mi
    ;Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_ALL, FALSE, Addr mi
    
    
    ;Invoke IsClipboardFormatAvailable, CF_TEXT
    ;.IF eax == TRUE
    ;    mov mi.fState, MFS_ENABLED
    ;.ENDIF
    ;Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE_JSON, FALSE, Addr mi

    ret
InitRightClickMenu ENDP


;-------------------------------------------------------------------------------------
; InitRightClickAddSubmenu - Initialize treeview right click 'Add' submenu
;-------------------------------------------------------------------------------------
InitRightClickAddSubmenu PROC hWin:DWORD
    LOCAL hBitmap:DWORD
    LOCAL hSubMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_ENABLED

    ; Create 'Add Item' submenu items   
    Invoke CreatePopupMenu
    mov hSubMenu, eax
    mov hTVAddMenu, eax
    
    ; Strings for 'Add' submenu
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_STRING, Addr szTVRCMenuAddItemString
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_NUMBER, Addr szTVRCMenuAddItemNumber
    Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_TRUE, Addr szTVRCMenuAddItemTrue
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_FALSE, Addr szTVRCMenuAddItemFalse
    Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_ARRAY, Addr szTVRCMenuAddItemArray
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_ADD_ITEM_OBJECT, Addr szTVRCMenuAddItemObject

    ; Load bitmaps for 'Add Item' submenu
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_STRING
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_STRING, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_NUMBER
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_NUMBER, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_TRUE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_TRUE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_FALSE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_FALSE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_ARRAY
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_ARRAY, MF_BYCOMMAND, hBitmap, 0    
    Invoke LoadBitmap, hInstance, BMP_CMD_ADD_ITEM_OBJECT
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_ADD_ITEM_OBJECT, MF_BYCOMMAND, hBitmap, 0    
    
    mov eax, hSubMenu ; return handle to submenu
    ret
InitRightClickAddSubmenu ENDP


;-------------------------------------------------------------------------------------
; InitRightClickCopySubmenu - Initialize treeview right click 'Copy' submenu
;-------------------------------------------------------------------------------------
InitRightClickCopySubmenu PROC hWin:DWORD
    LOCAL hBitmap:DWORD
    LOCAL hSubMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_GRAYED ;MFS_ENABLED

    ; Create 'Copy' submenu items   
    Invoke CreatePopupMenu
    mov hSubMenu, eax
    
    ; Strings for 'Copy' submenu
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_COPY_TEXT, Addr szTVRCMenuCopyText
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_COPY_VALUE, Addr szTVRCMenuCopyValue
    Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_COPY_ITEM, Addr szTVRCMenuCopyItem
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_COPY_BRANCH, Addr szTVRCMenuCopyBranch
    
    ; Load bitmaps for 'Copy' submenu
    Invoke LoadBitmap, hInstance, BMP_CMD_COPY_TEXT
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_COPY_TEXT, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_COPY_VALUE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_COPY_VALUE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_COPY_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_COPY_ITEM, MF_BYCOMMAND, hBitmap, 0    
    Invoke LoadBitmap, hInstance, BMP_CMD_COPY_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_COPY_BRANCH, MF_BYCOMMAND, hBitmap, 0
    
    mov eax, hSubMenu ; return handle to submenu
    ret
InitRightClickCopySubmenu ENDP


;-------------------------------------------------------------------------------------
; InitRightClickPasteSubmenu - Initialize treeview right click 'Paste' submenu
;-------------------------------------------------------------------------------------
InitRightClickPasteSubmenu PROC hWin:DWORD
    LOCAL hBitmap:DWORD
    LOCAL hSubMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_GRAYED ;MFS_ENABLED

    ; Create 'Paste' submenu items   
    Invoke CreatePopupMenu
    mov hSubMenu, eax

    ; Strings for 'Paste' submenu
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_PASTE_ITEM, Addr szTVRCMenuPasteItem
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_PASTE_BRANCH, Addr szTVRCMenuPasteBranch
    ;Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_PASTE_JSON, Addr szTVRCMenuPasteJSON
    
    ; Load bitmaps for 'Paste' submenu
    Invoke LoadBitmap, hInstance, BMP_CMD_PASTE_ITEM
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_PASTE_ITEM, MF_BYCOMMAND, hBitmap, 0    
    Invoke LoadBitmap, hInstance, BMP_CMD_PASTE_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_PASTE_BRANCH, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_PASTE_JSON ; BMP_EDIT_PASTE_JSON
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_PASTE_JSON, MF_BYCOMMAND, hBitmap, 0

    ; Set inital state for some menu items
    mov mi.fState, MFS_GRAYED
    Invoke SetMenuItemInfo, hSubMenu, IDM_CMD_PASTE_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hSubMenu, IDM_CMD_PASTE_BRANCH, FALSE, Addr mi
        
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ENDIF
    Invoke SetMenuItemInfo, hSubMenu, IDM_CMD_PASTE_JSON, FALSE, Addr mi
    
    mov eax, hSubMenu ; return handle to submenu
    ret
InitRightClickPasteSubmenu ENDP


;-------------------------------------------------------------------------------------
; InitRightClickExportSubmenu - Initialize treeview right click 'Export' submenu
;-------------------------------------------------------------------------------------
InitRightClickExportSubmenu PROC hWin:DWORD
    LOCAL hBitmap:DWORD
    LOCAL hSubMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    mov mi.fState, MFS_GRAYED ;MFS_ENABLED

    ; Create 'Export' submenu items   
    Invoke CreatePopupMenu
    mov hSubMenu, eax
    
    ; Strings for 'Export' submenu
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_TREE_CLIP, Addr szTVRCMenuExportTreeClip
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_BRANCH_CLIP, Addr szTVRCMenuExportBranchClip
    Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_TREE_FILE, Addr szTVRCMenuExportTreeFile
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_BRANCH_FILE, Addr szTVRCMenuExportBranchFile

    ; Load bitmaps for 'Export' submenu
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_TREE_CLIP
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_TREE_CLIP, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_BRANCH_CLIP
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_BRANCH_CLIP, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_TREE_FILE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_TREE_FILE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_BRANCH_FILE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_BRANCH_FILE, MF_BYCOMMAND, hBitmap, 0

    mov eax, hSubMenu ; return handle to submenu
    ret
InitRightClickExportSubmenu ENDP


;-------------------------------------------------------------------------------------
; UpdateMenus - Initialize menus
;-------------------------------------------------------------------------------------
UpdateMenus PROC USES EBX hWin:DWORD, hItem:DWORD
    LOCAL tvhi:TV_HITTESTINFO
    LOCAL hCurrentItem:DWORD
    LOCAL bInTV:DWORD
    LOCAL bHasChildren:DWORD
    LOCAL bObjectOrArray:DWORD
    LOCAL bRoot:DWORD
    
    mov bInTV, FALSE
    mov bHasChildren, FALSE
    mov bObjectOrArray, FALSE
    mov bRoot, FALSE
    
    .IF hItem == NULL
        Invoke GetCursorPos, Addr tvhi.pt
        Invoke ScreenToClient, hTV, addr tvhi.pt
        Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi
        .IF tvhi.flags == TVHT_ONITEMLABEL
            mov bInTV, TRUE
        .ENDIF
        Invoke SendMessage, hTV, TVM_SELECTITEM, TVGN_CARET, tvhi.hItem
        mov eax, tvhi.hItem
    .ELSE
        mov bInTV, TRUE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax
    .IF eax != 0 ;&& tvhi.flags == TVHT_ONITEMLABEL
        Invoke TreeViewItemHasChildren, hTV, hCurrentItem
        mov bHasChildren, eax
        
        Invoke TreeViewGetItemParam, hTV, hCurrentItem
        .IF eax != NULL ; eax = hJSON
            mov ebx, eax
            mov eax, [ebx].cJSON.itemtype
            .IF eax == cJSON_Object || eax == cJSON_Array
                mov bObjectOrArray, TRUE
            .ENDIF 
        .ENDIF
    .ENDIF

    ; check node is not root
    mov eax, hCurrentItem
    .IF eax == hTVRoot && eax != 0
        mov bRoot, TRUE
    .ENDIF
    
    Invoke UpdateMainMenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke UpdateRightClickMenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot

    ret
UpdateMenus ENDP


;-------------------------------------------------------------------------------------
; Update main menu
;-------------------------------------------------------------------------------------
UpdateMainMenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL hMainMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE

    Invoke GetMenu, hWin
    mov hMainMenu, eax
    
    ; Save / SaveAs menu items
    .IF g_Edit == TRUE 
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi 
    
    .IF bInTV == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_TEXT, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_ITEM, FALSE, Addr mi
    
    .IF g_hCutCopyNode != NULL && (bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE))
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_ITEM, FALSE, Addr mi

    .IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_BRANCH, FALSE, Addr mi
    
    .IF g_hCutCopyBranchNode != NULL && (bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE))
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_BRANCH, FALSE, Addr mi

    ; Enabled if clipload has data and format text is available
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_JSON, FALSE, Addr mi

    ret
UpdateMainMenu ENDP


;-------------------------------------------------------------------------------------
; Update right click menu
;-------------------------------------------------------------------------------------
UpdateRightClickMenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO
    
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
;    Invoke TreeViewCountItems, hTV
;    .IF sdword ptr eax > 0 
;        mov mi.fState, MFS_ENABLED
;    .ELSE
;        mov mi.fState, MFS_GRAYED
;    .ENDIF
;    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_ALL, FALSE, Addr mi
;    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_ALL, FALSE, Addr mi

    .IF bInTV == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EDIT_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_DEL_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE, FALSE, Addr mi    

;    .IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
;        mov mi.fState, MFS_ENABLED
;    .ELSE
;        mov mi.fState, MFS_GRAYED
;    .ENDIF
;    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, FALSE, Addr mi
;    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_BRANCH, FALSE, Addr mi


    .IF bInTV == TRUE && bObjectOrArray == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM, FALSE, Addr mi

    Invoke UpdateRightClickAddSubmenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke UpdateRightClickCopySubmenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke UpdateRightClickPasteSubmenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke UpdateRightClickExportSubmenu, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    
    ret
UpdateRightClickMenu ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Add' submenu
;-------------------------------------------------------------------------------------
UpdateRightClickAddSubmenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
    .IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_STRING, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_NUMBER, FALSE, Addr mi 
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_TRUE, FALSE, Addr mi 
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_FALSE, FALSE, Addr mi 
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_ARRAY, FALSE, Addr mi 
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM_OBJECT, FALSE, Addr mi     
 
    ret
UpdateRightClickAddSubmenu ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Copy' submenu
;-------------------------------------------------------------------------------------
UpdateRightClickCopySubmenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE

    .IF bInTV == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_TEXT, FALSE, Addr mi
    
    .IF bInTV == TRUE && bRoot == FALSE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF    
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_ITEM, FALSE, Addr mi

    .IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE) && bRoot == FALSE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_BRANCH, FALSE, Addr mi
    
    ret
UpdateRightClickCopySubmenu ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Paste' submenu
;-------------------------------------------------------------------------------------
UpdateRightClickPasteSubmenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE

    .IF g_hCutCopyNode != NULL && bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE_ITEM, FALSE, Addr mi

    .IF g_hCutCopyBranchNode != NULL && bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE); && bRoot == FALSE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE_BRANCH, FALSE, Addr mi

    ; Enabled if clipload has data and format text is available
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE_JSON, FALSE, Addr mi
    
    ret
UpdateRightClickPasteSubmenu ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Export' submenu
;-------------------------------------------------------------------------------------
UpdateRightClickExportSubmenu PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
    ret
UpdateRightClickExportSubmenu ENDP


;-------------------------------------------------------------------------------------
; ShowRightClickMenu - shows treeview right click menu
;-------------------------------------------------------------------------------------
ShowRightClickMenu PROC hWin:DWORD
	Invoke GetCursorPos, addr TVRCMenuPoint
	; Focus Main Window - ; Fix for shortcut menu not popping up right
	Invoke SetForegroundWindow, hWin
	Invoke TrackPopupMenu, hTVMenu, TPM_LEFTALIGN+TPM_LEFTBUTTON, TVRCMenuPoint.x, TVRCMenuPoint.y, NULL, hWin, NULL
	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right  
    ret
ShowRightClickMenu ENDP


;-------------------------------------------------------------------------------------
; ShowRightClickAddSubmenu - Show Add Submenu if INSERT key is pressed and conditions are satisfied
;-------------------------------------------------------------------------------------
ShowRightClickAddSubmenu PROC hWin:DWORD
    LOCAL tvhi:TV_HITTESTINFO
    LOCAL bShowSubmenu:DWORD
    LOCAL hItem:DWORD
    
    mov bShowSubmenu, FALSE

    Invoke GetCursorPos, Addr tvhi.pt
    Invoke ScreenToClient, hTV, addr tvhi.pt
    Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi
    Invoke SendMessage, hTV, TVM_SELECTITEM, TVGN_CARET, tvhi.hItem
    mov eax, tvhi.hItem
    mov hItem, eax
    .IF eax != 0 && tvhi.flags == TVHT_ONITEMLABEL
        mov hItem, eax
        Invoke TreeViewItemHasChildren, hTV, hItem
        mov bShowSubmenu, eax
        .IF eax == FALSE
            Invoke TreeViewGetSelectedParam, hTV
            .IF eax != NULL ; eax = hJSON
                mov ebx, eax
                mov eax, [ebx].cJSON.itemtype
                .IF eax == cJSON_Object || eax == cJSON_Array
                    mov bShowSubmenu, TRUE
                .ENDIF 
            .ENDIF
        .ENDIF
    .ENDIF
    
    .IF bShowSubmenu == TRUE
    	Invoke GetCursorPos, addr TVRCMenuPoint
    	; Focus Main Window - ; Fix for shortcut menu not popping up right
    	Invoke SetForegroundWindow, hWin
    	Invoke TrackPopupMenu, hTVAddMenu, TPM_LEFTALIGN+TPM_LEFTBUTTON, TVRCMenuPoint.x, TVRCMenuPoint.y, NULL, hWin, NULL
    	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right   
    .ENDIF
    ret

ShowRightClickAddSubmenu ENDP


;-------------------------------------------------------------------------------------
; Reset menus when user closes file
;-------------------------------------------------------------------------------------
ResetMenus PROC hWin:DWORD
    LOCAL hMainMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
    Invoke GetMenu, hWin
    mov hMainMenu, eax    
    
    ; Main menu: File, Edit
    mov mi.fState, MFS_ENABLED
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_NEW, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_OPEN, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_CLOSE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_EXIT, FALSE, Addr mi
    mov mi.fState, MFS_GRAYED
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi    
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_TEXT, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_COPY_BRANCH, FALSE, Addr mi
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_EDIT_PASTE_JSON, FALSE, Addr mi
    
    ; Right click menus
    mov mi.fState, MFS_GRAYED
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_TEXT, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_VALUE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EDIT_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_DEL_ITEM, FALSE, Addr mi
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == TRUE
        mov mi.fState, MFS_ENABLED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE_JSON, FALSE, Addr mi
    
    ret
ResetMenus ENDP


;-------------------------------------------------------------------------------------
; Sets the state of save, save as menu items
;-------------------------------------------------------------------------------------
SaveMenuState PROC hWin:DWORD, bEnable:DWORD
    LOCAL hMainMenu:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE

    Invoke GetMenu, hWin
    mov hMainMenu, eax
    
    .IF bEnable == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVE, FALSE, Addr mi
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi 
    ret
SaveMenuState ENDP



















