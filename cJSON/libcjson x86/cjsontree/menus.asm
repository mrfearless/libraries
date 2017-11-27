MenusInit                   PROTO :DWORD                                    ; Initialize Main Menu and Right Click (RC) shortcut menu and submenus
MenusReset                  PROTO :DWORD                                    ; Reset all menu items on Main Menu and Right Click (RC) shortcut menu back to default state
MenusUpdate                 PROTO :DWORD, :DWORD                            ; Update Main Menu and Right Click (RC) shortcute menu and submenus

MenuMainInit                PROTO :DWORD                                    ; Initialize main menu, load bitmaps, set initial state
MenuMainUpdate              PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update menus based on edit state, selected item, selected branch etc

MenuRCInit                  PROTO :DWORD                                    ; Initialize Right Click (RC) shortcut menu (called from MenusInit)
MenuRCUpdate                PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update Right Click (RC) shortcut menu (called from MenusUpdate)
MenuRCAddInit               PROTO :DWORD                                    ; Initialize 'RC->Add Item' submenu (called from MenuRCInit)
MenuRCAddUpdate             PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update 'RC->Add Item' submenu (called from MenuRCUpdate)
MenuRCCopyInit              PROTO :DWORD                                    ; Initialize 'RC->Copy' submenu (called from MenuRCInit)
MenuRCCopyUpdate            PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update 'RC->Copy' submenu (called from MenuRCUpdate)
MenuRCPasteInit             PROTO :DWORD                                    ; Initialize 'RC->Paste' submenu (called from MenuRCInit)
MenuRCPasteUpdate           PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update 'RC->Paste' submenu (called from MenuRCUpdate)
MenuRCExportInit            PROTO :DWORD                                    ; Initialize 'RC->Export' submenu (called from MenuRCInit)
MenuRCExportUpdate          PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD    ; Update 'RC->Export' submenu (called from MenuRCUpdate)

MenuOptionsUpdate           PROTO :DWORD                                    ; Update 'File->Otions' menu items
MenuSaveEnable              PROTO :DWORD, :DWORD                            ; Enable/Disable 'File->Save' menu item
MenuSaveAsEnable            PROTO :DWORD, :DWORD                            ; Enable/Disable 'File->Save As' menu item

MenuRCShow                  PROTO :DWORD                                    ; Show Right Click (RC) shortcut menu
MenuRCAddShow               PROTO :DWORD                                    ; Show 'RC->Add Item' submenu. Just the 'Add Item' submenu

IniMRULoadListToMenu        PROTO :DWORD                                    ; Loads Most Recently Used (MRU) file list to the Main Menu under the File menu
IniMRUReloadListToMenu      PROTO :DWORD                                    ; Reloads the MRU list and updates the list under the File menu
IniMRUEntrySaveFilename     PROTO :DWORD, :DWORD                            ; Saves a new MRU entry name (full filepath to file)
IniMRUEntryDeleteFilename   PROTO :DWORD, :DWORD                            ; Deletes a new MRU entry name (full filepath to file)
IniMRUEntryOpenFile         PROTO :DWORD, :DWORD                            ; Opens a file (if it exists) based on the MRU entry name (full filepath to file) 


.CONST
BMP_ABOUT_LETTHELIGHTIN     EQU 101

; Main menu bitmaps: File
BMP_FILE_MRU                EQU 200
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
IDM_EDIT_CUT_ITEM	        EQU 10203
IDM_EDIT_CUT_BRANCH	        EQU 10204
IDM_EDIT_COPY_ITEM	        EQU 10205
IDM_EDIT_COPY_BRANCH	    EQU 10206
IDM_EDIT_PASTE_ITEM         EQU 10207
IDM_EDIT_PASTE_BRANCH       EQU 10208
IDM_EDIT_PASTE_JSON         EQU 10209
IDM_EDIT_FIND               EQU 10210
IDM_OPTIONS_EXPANDALL		EQU 10301
IDM_OPTIONS_CASESEARCH		EQU 10302
IDM_HELP_ABOUT              EQU 10101

; Main Menu MRU files:
IDM_MRU_1					EQU 19991 ; Menu MRU File 1
IDM_MRU_2					EQU 19992 ; Menu MRU File 2
IDM_MRU_3					EQU 19993 ; Menu MRU File 3
IDM_MRU_4					EQU 19994 ; Menu MRU File 4
IDM_MRU_5					EQU 19995 ; Menu MRU File 5
IDM_MRU_6					EQU 19996 ; Menu MRU File 6
IDM_MRU_7					EQU 19997 ; Menu MRU File 7
IDM_MRU_8					EQU 19998 ; Menu MRU File 8
IDM_MRU_9					EQU 19999 ; Menu MRU File 9
IDM_MRU_SEP                 EQU 19990

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
IDM_CMD_CUT_ITEM            EQU 11032
IDM_CMD_CUT_BRANCH          EQU 11033
IDM_CMD_COPY_ITEM           EQU 11034
IDM_CMD_COPY_BRANCH         EQU 11035

; Right click 'Paste' submenu IDs:
IDM_CMD_PASTE_ITEM          EQU 11040
IDM_CMD_PASTE_BRANCH        EQU 11041
IDM_CMD_PASTE_JSON          EQU 11042

; Right click 'Export' submenu IDs:
IDM_CMD_EXPORT_ROOT_CLIP    EQU 11050
IDM_CMD_EXPORT_BRANCH_CLIP  EQU 11051
IDM_CMD_EXPORT_ROOT_FILE    EQU 11052
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

; Options
szOptionsCaseSensitive      DB '&Case Sensitive Search',0
szOptionsCaseInsensitive    DB '&Case Insensitive Search',0

hBmpFileMRU                 DD 0

szMRUErrorFileNotExist      DB "File does not exist: ",0
szMRUErrorMessage           DB 512 dup (0)

.DATA
hTVMenu                     DD ? ; Right click menu
hTVAddMenu                  DD ? ; 'Add' submenu


.CODE


;-------------------------------------------------------------------------------------
; MenusInit - Initialize menus
;-------------------------------------------------------------------------------------
MenusInit PROC hWin:DWORD

    Invoke MenuMainInit, hWin
    Invoke MenuRCInit, hWin

    ret
MenusInit ENDP


;-------------------------------------------------------------------------------------
; MenuMainInit - Initialize main program menu
;-------------------------------------------------------------------------------------
MenuMainInit PROC hWin:DWORD
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

    ;mov mi.fMask, MIIM_CHECKMARKS	
    ;mov mi.fState, MFS_CHECKED ; MFS_UNCHECKED	
    .IF g_ExpandAllOnLoad == TRUE
        ;mov mi.fState, MFS_CHECKED
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_EXPANDALL, MF_BYCOMMAND or MF_CHECKED
    .ELSE
        ;mov mi.fState, MFS_UNCHECKED
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_EXPANDALL, MF_BYCOMMAND or MF_UNCHECKED
    .ENDIF
    ;Invoke SetMenuItemInfo, hMainMenu, IDM_OPTIONS_EXPANDALL, FALSE, Addr mi
    .IF g_CaseSensitiveSearch == TRUE
        ;mov mi.fState, MFS_CHECKED
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_CASESEARCH, MF_BYCOMMAND or MF_CHECKED
    .ELSE
        ;mov mi.fState, MFS_UNCHECKED
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_CASESEARCH, MF_BYCOMMAND or MF_UNCHECKED
    .ENDIF
    ;Invoke SetMenuItemInfo, hMainMenu, IDM_OPTIONS_CASESEARCH, FALSE, Addr mi
    
    ;Invoke DrawMenuBar, hWin
    
    xor eax, eax
    ret
MenuMainInit ENDP


;-------------------------------------------------------------------------------------
; MenuRCInit - Initialize treeview right click menu
;-------------------------------------------------------------------------------------
MenuRCInit PROC hWin:DWORD
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
    Invoke MenuRCAddInit, hWin
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
    Invoke MenuRCCopyInit, hWin
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
    Invoke MenuRCPasteInit, hWin
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
;    Invoke MenuRCExportInit, hWin
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
    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COLLAPSE_BRANCH, Addr szTVRCMenuCollapseBranch
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_EXPAND_BRANCH, Addr szTVRCMenuExpandBranch
    Invoke AppendMenu, hTVMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_COLLAPSE_ALL, Addr szTVRCMenuCollapseAll
    Invoke AppendMenu, hTVMenu, MF_STRING, IDM_CMD_EXPAND_ALL, Addr szTVRCMenuExpandAll

    ; Load bitmaps for right click menu
    Invoke LoadBitmap, hInstance, BMP_CMD_FIND
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_FIND, MF_BYCOMMAND, hBitmap, 0

    Invoke LoadBitmap, hInstance, BMP_CMD_COLLAPSE_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPAND_BRANCH
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_EXPAND_BRANCH, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_COLLAPSE_ALL
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_COLLAPSE_ALL, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPAND_ALL
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hTVMenu, IDM_CMD_EXPAND_ALL, MF_BYCOMMAND, hBitmap, 0
    
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
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_ALL, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_ALL, FALSE, Addr mi


    ret
MenuRCInit ENDP


;-------------------------------------------------------------------------------------
; MenuRCAddInit - Initialize treeview right click 'Add' submenu
;-------------------------------------------------------------------------------------
MenuRCAddInit PROC hWin:DWORD
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
MenuRCAddInit ENDP


;-------------------------------------------------------------------------------------
; MenuRCCopyInit - Initialize treeview right click 'Copy' submenu
;-------------------------------------------------------------------------------------
MenuRCCopyInit PROC hWin:DWORD
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
MenuRCCopyInit ENDP


;-------------------------------------------------------------------------------------
; MenuRCPasteInit - Initialize treeview right click 'Paste' submenu
;-------------------------------------------------------------------------------------
MenuRCPasteInit PROC hWin:DWORD
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
MenuRCPasteInit ENDP


;-------------------------------------------------------------------------------------
; MenuRCExportInit - Initialize treeview right click 'Export' submenu
;-------------------------------------------------------------------------------------
MenuRCExportInit PROC hWin:DWORD
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
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_ROOT_CLIP, Addr szTVRCMenuExportTreeClip
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_BRANCH_CLIP, Addr szTVRCMenuExportBranchClip
    Invoke AppendMenu, hSubMenu, MF_SEPARATOR, 0, 0
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_ROOT_FILE, Addr szTVRCMenuExportTreeFile
    Invoke AppendMenu, hSubMenu, MF_STRING, IDM_CMD_EXPORT_BRANCH_FILE, Addr szTVRCMenuExportBranchFile

    ; Load bitmaps for 'Export' submenu
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_TREE_CLIP
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_ROOT_CLIP, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_BRANCH_CLIP
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_BRANCH_CLIP, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_TREE_FILE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_ROOT_FILE, MF_BYCOMMAND, hBitmap, 0
    Invoke LoadBitmap, hInstance, BMP_CMD_EXPORT_BRANCH_FILE
    mov hBitmap, eax
    Invoke SetMenuItemBitmaps, hSubMenu, IDM_CMD_EXPORT_BRANCH_FILE, MF_BYCOMMAND, hBitmap, 0

    mov eax, hSubMenu ; return handle to submenu
    ret
MenuRCExportInit ENDP


;-------------------------------------------------------------------------------------
; MenusUpdate - Initialize menus
;-------------------------------------------------------------------------------------
MenusUpdate PROC USES EBX hWin:DWORD, hItem:DWORD
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
    
    Invoke MenuMainUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke MenuRCUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot

    ret
MenusUpdate ENDP


;-------------------------------------------------------------------------------------
; Update main menu
;-------------------------------------------------------------------------------------
MenuMainUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
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
    ;Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi 
    
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
MenuMainUpdate ENDP


;-------------------------------------------------------------------------------------
; Update options menu
;-------------------------------------------------------------------------------------
MenuOptionsUpdate PROC hWin:DWORD
    LOCAL hMainMenu:DWORD

    Invoke GetMenu, hWin
    mov hMainMenu, eax
    .IF g_ExpandAllOnLoad == TRUE
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_EXPANDALL, MF_BYCOMMAND or MF_CHECKED
    .ELSE
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_EXPANDALL, MF_BYCOMMAND or MF_UNCHECKED
    .ENDIF

    .IF g_CaseSensitiveSearch == TRUE
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_CASESEARCH, MF_BYCOMMAND or MF_CHECKED
    .ELSE
        Invoke CheckMenuItem, hMainMenu, IDM_OPTIONS_CASESEARCH, MF_BYCOMMAND or MF_UNCHECKED
    .ENDIF
    
    Invoke DrawMenuBar, hWin
    
    ret
MenuOptionsUpdate ENDP


;-------------------------------------------------------------------------------------
; Update right click menu
;-------------------------------------------------------------------------------------
MenuRCUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO
    
    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
    Invoke TreeViewCountItems, hTV
    .IF sdword ptr eax > 0 
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_ALL, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_ALL, FALSE, Addr mi

    .IF bInTV == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EDIT_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_DEL_ITEM, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COPY, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_PASTE, FALSE, Addr mi    

    .IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_COLLAPSE_BRANCH, FALSE, Addr mi
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_EXPAND_BRANCH, FALSE, Addr mi


    .IF bInTV == TRUE && bObjectOrArray == TRUE
        mov mi.fState, MFS_ENABLED
    .ELSE
        mov mi.fState, MFS_GRAYED
    .ENDIF
    Invoke SetMenuItemInfo, hTVMenu, IDM_CMD_ADD_ITEM, FALSE, Addr mi

    Invoke MenuRCAddUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke MenuRCCopyUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke MenuRCPasteUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    Invoke MenuRCExportUpdate, hWin, bInTV, bHasChildren, bObjectOrArray, bRoot
    
    ret
MenuRCUpdate ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Add' submenu
;-------------------------------------------------------------------------------------
MenuRCAddUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
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
MenuRCAddUpdate ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Copy' submenu
;-------------------------------------------------------------------------------------
MenuRCCopyUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
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
MenuRCCopyUpdate ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Paste' submenu
;-------------------------------------------------------------------------------------
MenuRCPasteUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
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
MenuRCPasteUpdate ENDP


;-------------------------------------------------------------------------------------
; Update right click menu 'Export' submenu
;-------------------------------------------------------------------------------------
MenuRCExportUpdate PROC hWin:DWORD, bInTV:DWORD, bHasChildren:DWORD, bObjectOrArray:DWORD, bRoot:DWORD
    LOCAL mi:MENUITEMINFO

    mov mi.cbSize, SIZEOF MENUITEMINFO
    mov mi.fMask, MIIM_STATE
    
    ret
MenuRCExportUpdate ENDP


;-------------------------------------------------------------------------------------
; MenuRCShow - shows treeview right click menu
;-------------------------------------------------------------------------------------
MenuRCShow PROC hWin:DWORD
	Invoke GetCursorPos, addr TVRCMenuPoint
	; Focus Main Window - ; Fix for shortcut menu not popping up right
	Invoke SetForegroundWindow, hWin
	Invoke TrackPopupMenu, hTVMenu, TPM_LEFTALIGN+TPM_LEFTBUTTON, TVRCMenuPoint.x, TVRCMenuPoint.y, NULL, hWin, NULL
	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right  
    ret
MenuRCShow ENDP


;-------------------------------------------------------------------------------------
; MenuRCAddShow - Show Add Submenu if INSERT key is pressed and conditions are satisfied
;-------------------------------------------------------------------------------------
MenuRCAddShow PROC hWin:DWORD
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

MenuRCAddShow ENDP


;-------------------------------------------------------------------------------------
; Reset menus when user closes file
;-------------------------------------------------------------------------------------
MenusReset PROC hWin:DWORD
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
MenusReset ENDP


;-------------------------------------------------------------------------------------
; Sets the state of save menu items
;-------------------------------------------------------------------------------------
MenuSaveEnable PROC hWin:DWORD, bEnable:DWORD
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
    ret
MenuSaveEnable ENDP


;-------------------------------------------------------------------------------------
; Sets the state of save as menu items
;-------------------------------------------------------------------------------------
MenuSaveAsEnable PROC hWin:DWORD, bEnable:DWORD
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
    Invoke SetMenuItemInfo, hMainMenu, IDM_FILE_SAVEAS, FALSE, Addr mi 
    ret
MenuSaveAsEnable ENDP

;--------------------------------------------------------------------------------------
; IniMRULoadListToMenu - Loads MRU file information from the ini file into file menu
;--------------------------------------------------------------------------------------
IniMRULoadListToMenu PROC hWin:DWORD
	LOCAL szProfile[8]:BYTE
	LOCAL nProfile:DWORD	
	LOCAL nTotalMRUs:DWORD
	LOCAL nMenuID:DWORD
	LOCAL hMainMenu:DWORD

	Invoke GetMenu, hWin
	.IF eax == NULL
		mov eax, FALSE
		ret 
	.endif
	mov hMainMenu, eax

    .IF hBmpFileMRU == 0
        Invoke LoadBitmap, hInstance, BMP_FILE_MRU
        mov hBmpFileMRU, eax
    .ENDIF
    
	mov nMenuID, 19991
	mov nProfile, 1
	mov nTotalMRUs, 0
	
	ReadMRUProfiles:
	mov eax, nProfile
	.IF eax < 10 ; 9 MRUs max
		Invoke dwtoa, nProfile, Addr szProfile
		Invoke GetPrivateProfileString, Addr szMRUSection, Addr szProfile, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
		.IF eax !=0
			Invoke szCmp, Addr szMRUFilename, Addr szColon
			.IF eax == 0		
				Invoke InsertMenu, hMainMenu, IDM_FILE_EXIT, MF_STRING+MF_BYCOMMAND, nMenuID, Addr szMRUFilename
				Invoke SetMenuItemBitmaps, hMainMenu, nMenuID, MF_BYCOMMAND, hBmpFileMRU, 0
				inc nTotalMRUs
			.ENDIF
		.ENDIF		
		inc nMenuID
		inc nProfile
		mov eax, nProfile
		jmp ReadMRUProfiles
	.ENDIF	

	.IF nTotalMRUs > 0
		Invoke InsertMenu, hMainMenu, IDM_FILE_EXIT, MF_SEPARATOR+MF_BYCOMMAND, IDM_MRU_SEP, NULL
	.ENDIF

	Invoke DrawMenuBar, hMainMenu
	
	mov eax, TRUE
	ret
IniMRULoadListToMenu ENDP


;--------------------------------------------------------------------------------------
; IniMRUReloadListToMenu - RELoads MRU file information from the ini file into file menu
;--------------------------------------------------------------------------------------
IniMRUReloadListToMenu PROC hWin:DWORD
	LOCAL nMenuID:DWORD
	LOCAL hMainMenu:DWORD
    LOCAL nProfile:DWORD
	
	Invoke GetMenu, hWin
	.IF eax == NULL
		mov eax, FALSE
		ret 
	.endif
	mov hMainMenu, eax
	mov nMenuID, 19991
    mov nProfile, 1
    
    RemoveMRUProfiles:
    mov eax, nProfile
    .IF eax < 10 ; 9 MRUs max
        Invoke RemoveMenu, hMainMenu, nMenuID, MF_BYCOMMAND
		inc nMenuID
		inc nProfile
		mov eax, nProfile    
		jmp RemoveMRUProfiles
	.ENDIF
	Invoke RemoveMenu, hMainMenu, IDM_MRU_SEP, MF_BYCOMMAND
	Invoke DrawMenuBar, hMainMenu
    Invoke IniMRULoadListToMenu, hWin
    ret
IniMRUReloadListToMenu ENDP


;--------------------------------------------------------------------------------------
; IniMRUEntrySaveFilename - Saves a filename to the MRU list 
;--------------------------------------------------------------------------------------
IniMRUEntrySaveFilename PROC hWin:DWORD, lpszFilename:DWORD
	LOCAL nMRUFrom:DWORD
	LOCAL nMRUTo:DWORD
	LOCAL szMRUFrom[8]:BYTE
	LOCAL szMRUTo[8]:BYTE

	; if filename in MRU list already we delete it
	mov nMRUFrom, 1
	mov eax, nMRUFrom
	; Start Loop
	;====================
	ScanMRUProfiles:
	;====================
	mov eax, nMRUFrom
	.WHILE eax < 10 ; 9 MRUs
		Invoke dwtoa, nMRUFrom, Addr szMRUFrom
		Invoke GetPrivateProfileString, Addr szMRUSection, Addr szMRUFrom, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
		.IF eax !=0
			Invoke szCmp, Addr szMRUFilename, Addr szColon
			.IF eax == 0		
				Invoke szCmp, Addr szMRUFilename, lpszFilename
				.IF eax != 0
					; Loop onwards and fetch and write data
					mov eax, nMRUFrom
					mov nMRUTo, eax
					inc nMRUFrom
					mov eax, nMRUFrom
					.WHILE eax <= 10
						Invoke dwtoa, nMRUFrom, Addr szMRUFrom
						Invoke dwtoa, nMRUTo, Addr szMRUTo
						Invoke GetPrivateProfileString, Addr szMRUSection, Addr szMRUFrom, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
						.IF eax !=0
							Invoke szCmp, Addr szMRUFilename, Addr szColon
							.IF eax == 0
								Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, Addr szMRUFilename, Addr szIniFilename	
							.ELSE
								Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, NULL, Addr szIniFilename
							.ENDIF
						.ELSE
							Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, NULL, Addr szIniFilename
						.ENDIF	
						inc nMRUTo
						inc nMRUFrom	
						mov eax, nMRUFrom
					.ENDW
					.BREAK
				.ENDIF
			.ENDIF
		.ENDIF
		inc nMRUFrom
		mov eax, nMRUFrom
		jmp ScanMRUProfiles
	.ENDW		

	mov nMRUFrom, 8
	mov nMRUTo, 9
	; Start Loop
	;====================
	ReadMRUProfiles:
	;====================
	mov eax, nMRUTo
	.WHILE eax > 0 ; 9 MRUs
		Invoke dwtoa, nMRUFrom, Addr szMRUFrom
		Invoke dwtoa, nMRUTo, Addr szMRUTo
		Invoke GetPrivateProfileString, Addr szMRUSection, Addr szMRUFrom, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
		.IF eax !=0
			Invoke szCmp, Addr szMRUFilename, Addr szColon
			.IF eax == 0
				Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, Addr szMRUFilename, Addr szIniFilename
				Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUFrom, NULL, Addr szIniFilename
			.ENDIF
		.ENDIF		
		dec nMRUFrom
		dec nMRUTo	
		mov eax, nMRUTo
		jmp ReadMRUProfiles
	.ENDW	
	Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, lpszFilename, Addr szIniFilename
	ret
IniMRUEntrySaveFilename ENDP


;--------------------------------------------------------------------------------------
; IniMRUEntryDeleteFilename - Deletes an entry from the MRU file list - missing file for example
;--------------------------------------------------------------------------------------
IniMRUEntryDeleteFilename PROC hWin:DWORD, lpszFilename:DWORD
	LOCAL nMRUFrom:DWORD
	LOCAL nMRUTo:DWORD
	LOCAL szMRUFrom[8]:BYTE
	LOCAL szMRUTo[8]:BYTE
	
	mov nMRUFrom, 1
	mov eax, nMRUFrom
	; Start Loop
	;====================
	ScanMRUProfiles:
	;====================
	mov eax, nMRUFrom
	.WHILE eax < 10 ; 9 MRUs
		Invoke dwtoa, nMRUFrom, Addr szMRUFrom
		Invoke GetPrivateProfileString, Addr szMRUSection, Addr szMRUFrom, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
		.IF eax !=0
			Invoke szCmp, Addr szMRUFilename, Addr szColon
			.IF eax == 0		
				Invoke szCmp, Addr szMRUFilename, lpszFilename
				.IF eax != 0
					; Loop onwards and fetch and write data
					mov eax, nMRUFrom
					mov nMRUTo, eax
					inc nMRUFrom
					mov eax, nMRUFrom
					.WHILE eax <= 10
						Invoke dwtoa, nMRUFrom, Addr szMRUFrom
						Invoke dwtoa, nMRUTo, Addr szMRUTo
						
						Invoke GetPrivateProfileString, Addr szMRUSection, Addr szMRUFrom, Addr szColon, Addr szMRUFilename, SIZEOF szMRUFilename, Addr szIniFilename
						.IF eax !=0
							Invoke szCmp, Addr szMRUFilename, Addr szColon
							.IF eax == 0
								Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, Addr szMRUFilename, Addr szIniFilename	
							.ELSE
								Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, NULL, Addr szIniFilename
							.ENDIF
						.ELSE
							Invoke WritePrivateProfileString, Addr szMRUSection, Addr szMRUTo, NULL, Addr szIniFilename
						.ENDIF	
						inc nMRUTo
						inc nMRUFrom	
						mov eax, nMRUFrom
					.ENDW
					.BREAK
				.ENDIF
			.ENDIF
		.ENDIF
		inc nMRUFrom
		mov eax, nMRUFrom
		jmp ScanMRUProfiles
	.ENDW			
	ret
IniMRUEntryDeleteFilename ENDP


;--------------------------------------------------------------------------------------
; IniMRUEntryOpenFile - Opens a file from the MRU file list 
;--------------------------------------------------------------------------------------
IniMRUEntryOpenFile	PROC hWin:DWORD, lpszFilename:DWORD
	
	Invoke exist, lpszFilename
	.IF eax == 0
        Invoke szCopy, Addr szMRUErrorFileNotExist, Addr szMRUErrorMessage
        Invoke szCatStr, Addr szMRUErrorMessage, lpszFilename
        Invoke StatusBarSetPanelText, 2, Addr szMRUErrorMessage    		
		Invoke IniMRUEntryDeleteFilename, hWin, lpszFilename
		Invoke MessageBox, hWin, Addr szMRUErrorMessage, Addr AppName, MB_OK
		ret
	.ENDIF
    
    .IF lpszFilename == 0
        ;PrintText 'IniMRUEntryOpenFile no string'
        ret
    .ENDIF
    
	Invoke szCopy, lpszFilename, Addr JsonOpenedFilename
    Invoke JSONFileOpen, hWin, Addr JsonOpenedFilename
    .IF eax == TRUE
        ; Start processing JSON file
        Invoke JSONDataProcess, hWin, Addr JsonOpenedFilename, NULL
    .ENDIF
    
    ;Invoke IniMRUEntrySaveFilename, hWin, Addr JsonOpenedFilename
    ;Invoke IniMRUReloadListToMenu, hWin

	ret
IniMRUEntryOpenFile ENDP




















