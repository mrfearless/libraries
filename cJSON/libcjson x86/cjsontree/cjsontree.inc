include windows.inc
include user32.inc
include kernel32.inc
include gdi32.inc
include shell32.inc
include comctl32.inc
include comdlg32.inc
include masm32.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib shell32.lib
includelib comctl32.lib
includelib comdlg32.lib
includelib masm32.lib

include TreeView.inc
includelib TreeView.lib

include libcjson.inc
includelib libcjson.lib

include VirtualStack.inc
includelib VirtualStack.lib

;-----------------------------------------------------------------------------------------
; cjsontree Prototypes
;-----------------------------------------------------------------------------------------
WinMain                     PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc                     PROTO :DWORD,:DWORD,:DWORD,:DWORD

ProcessCmdLine              PROTO
CmdLineOpenFile             PROTO :DWORD

InitGUI                     PROTO :DWORD
InitMenus                   PROTO :DWORD
InitJSONStatusbar           PROTO :DWORD
InitJSONTreeview            PROTO :DWORD
UpdateMenus                 PROTO :DWORD, :DWORD
ShowAddSubmenu              PROTO :DWORD
ShowRightClickMenu          PROTO :DWORD

PasteJSON                   PROTO :DWORD
CopyToClipboard             PROTO :DWORD, :DWORD
CopyBranchToClipboard       PROTO :DWORD

BrowseJSONFile              PROTO :DWORD
OpenJSONFile                PROTO :DWORD, :DWORD
CloseJSONFile               PROTO
ProcessJSONData             PROTO :DWORD, :DWORD, :DWORD


AddJSONItem                 PROTO :DWORD, :DWORD
DelJSONItem                 PROTO :DWORD
EditJSONItem                PROTO :DWORD
NewJSON                     PROTO :DWORD

CreateJSONStackItem         PROTO :DWORD
FreeJSONStackItem           PROTO :DWORD
GetJSONStackItemCount       PROTO :DWORD
SetJSONStackItemCount       PROTO :DWORD, :DWORD
IncJSONStackItemCount       PROTO :DWORD
CreateJSONArrayIteratorName PROTO :DWORD, :DWORD
DeleteStackItemsCallback    PROTO :DWORD, :DWORD

;-----------------------------------------------------------------------------------------
; cjsontree Structures
;-----------------------------------------------------------------------------------------
JSONSTACKITEM                   STRUCT
    szItemName                  DB 64 DUP (?) 
    dwItemCount                 DD ?
JSONSTACKITEM                   ENDS




.CONST
;-----------------------------------------------------------------------------------------
; cjsontree Constants
;-----------------------------------------------------------------------------------------

ACCTABLE                        EQU 300
ACC_FILE_OPEN					EQU 301
ACC_FILE_CLOSE					EQU 302
ACC_FILE_NEW					EQU 303
ACC_EDIT_COPY_BRANCH            EQU 304


; Icon Resource IDs
ICO_MAIN                EQU 100
ICO_JSON_STRING         EQU 103
ICO_JSON_INTEGER        EQU 104
ICO_JSON_NUMBER         EQU ICO_JSON_INTEGER
ICO_JSON_FLOAT          EQU 105
ICO_JSON_CUSTOM         EQU 106
ICO_JSON_TRUE           EQU 107
ICO_JSON_FALSE          EQU 108
ICO_JSON_ARRAY          EQU 109
ICO_JSON_OBJECT         EQU 110
ICO_JSON_NULL           EQU 111
ICO_JSON_INVALID        EQU 112
ICO_JSON_LOGICAL        EQU 113



; Image list index to icons
IL_ICO_MAIN              EQU 0
IL_ICO_JSON_STRING       EQU 1
IL_ICO_JSON_INTEGER      EQU 2
IL_ICO_JSON_NUMBER       EQU IL_ICO_JSON_INTEGER
IL_ICO_JSON_FLOAT        EQU 3
IL_ICO_JSON_CUSTOM       EQU 4
IL_ICO_JSON_TRUE         EQU 5
IL_ICO_JSON_FALSE        EQU 6
IL_ICO_JSON_ARRAY        EQU 7
IL_ICO_JSON_OBJECT       EQU 8
IL_ICO_JSON_NULL         EQU 9
IL_ICO_JSON_INVALID      EQU 10
IL_ICO_JSON_LOGICAL      EQU 11   


; Menu bitmaps
IMG_CMD_COLLAPSE_BRANCH     EQU 201
IMG_CMD_EXPAND_BRANCH       EQU 202
IMG_CMD_COLLAPSE_CHILDREN   EQU 203
IMG_CMD_EXPAND_CHILDREN     EQU 204
IMG_CMD_COPY                EQU 205
IMG_CMD_COPY_VALUE          EQU 206
IMG_CMD_COPY_BRANCH         EQU 207
IMG_CMD_PASTE_JSON          EQU 208
IMG_CMD_ADD_ITEM            EQU 209
IMG_CMD_DEL_ITEM            EQU 210
IMG_CMD_ADD_ITEM_STRING     EQU 211
IMG_CMD_ADD_ITEM_NUMBER     EQU 212
IMG_CMD_ADD_ITEM_TRUE       EQU 213
IMG_CMD_ADD_ITEM_FALSE      EQU 214
IMG_CMD_ADD_ITEM_ARRAY      EQU 215
IMG_CMD_ADD_ITEM_OBJECT     EQU 216
IMG_CMD_OPEN_JSON_FILE      EQU 217
IMG_CMD_CLOSE_JSON_FILE     EQU 218
IMG_CMD_EDIT_ITEM           EQU 219
IMG_CMD_NEW_JSON_FILE       EQU 220
IMG_CMD_EXIT                EQU 221

; Main Dialog
IDD_DIALOG              EQU 1000
IDC_TV                  equ 1001
IDC_SB                  equ 1002

; Main Menu 
IDM_MENU                EQU 10000
IDM_FILE_EXIT           EQU 10001
IDM_FILE_OPEN           EQU 10002
IDM_FILE_CLOSE          EQU 10003
IDM_FILE_NEW            EQU 10004
IDM_EDIT_COPY			equ 10204
IDM_EDIT_COPY_VALUE		equ 10205
IDM_EDIT_COPY_BRANCH	equ 10206
IDM_EDIT_PASTE_JSON     EQU 10201
IDM_HELP_ABOUT          EQU 10101

; Treeview Right Click Menu
IDM_CMD_COLLAPSE_BRANCH EQU 11000
IDM_CMD_EXPAND_BRANCH   EQU 11001
IDM_CMD_COLLAPSE_CHILDREN EQU 11002
IDM_CMD_EXPAND_CHILDREN EQU 11003
IDM_CMD_COPY            EQU 11004
IDM_CMD_COPY_VALUE      EQU 11005
IDM_CMD_COPY_BRANCH     EQU 11006
IDM_CMD_PASTE_JSON      EQU 11007
IDM_CMD_ADD_ITEM        EQU 11008
IDM_CMD_DEL_ITEM        EQU 11009
IDM_CMD_EDIT_ITEM       EQU 11010


IDM_CMD_ADD_ITEM_STRING EQU 11050
IDM_CMD_ADD_ITEM_NUMBER EQU 11051
IDM_CMD_ADD_ITEM_TRUE   EQU 11052
IDM_CMD_ADD_ITEM_FALSE  EQU 11053
IDM_CMD_ADD_ITEM_ARRAY  EQU 11054
IDM_CMD_ADD_ITEM_OBJECT EQU 11055


.DATA
;-----------------------------------------------------------------------------------------
; cjsontree Initialized Data
;-----------------------------------------------------------------------------------------
ClassName                   DB 'DLGCLASS',0
AppName                     DB 'LTLI Dialog',0
AboutMsg                    DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2017',0

; JSON Types
szObject                    DB 'Object',0
szTrue                      DB 'True',0
szFalse                     DB 'False',0
szArray                     DB 'Array',0
szNull                      DB 'Null',0
szInvalid                   DB 'Invalid',0
szNullString                DB 0,0;'<String>',0
szNullStringQuotes          DB '""',0
szNullInteger               DB 0,0;'<Number>',0
szNullLogical               DB 0,0;'<Logical>',0
szNullArray                 DB '<Array>',0
szNullNull                  DB 0,0;'<Null>',0
szNullInvalid               DB '<Invalid>',0
szJSONClipboard             DB 'JSON source from clipboard',0
szNewItem                   DB 'New Item: ',0
szNewTrue                   DB 'New item: true',0
szNewFalse                  DB 'New item: false',0
szNewNumber                 DB 'New item: 0',0


; JSON pointers
lpszItemString              DD 0
lpszItemStringValue         DD 0
dwItemIntValue              DD 0 
LenItemString               DD 0
LenItemStringValue          DD 0

; JSON Text Buffers
szItemIntValue              DB 64 DUP (0)
szItemText                  DB 2048 DUP (0)
szItemTextValue             DB 1024 DUP (0)
szItemTextArrayName         DB 64 DUP (0)
szSelectedTreeviewText      DB 1024 DUP (0)

; JSON Error messages
szJSONLoadingFile           DB 'Loading JSON File: ',0
szJSONErrorClipData         DB 'Clipboard data does not contain valid JSON data',0
szJSONErrorLoadingFile      DB 'Error loading JSON File: ',0
szJSONErrorMappingFile      DB 'Error mapping JSON File: ',0
szJSONErrorReadingFile      DB 'Error reading JSON File: ',0
szJSONLoadedFile            DB 'Loaded JSON File: ',0
szJSONLoadedClipData        DB 'Loaded JSON data from clipboard',0
szJSONCreatedNewData        DB 'New JSON data started',0
szJSONNewData               DB 'JSON data',0
szJSONErrorEmptyFile        DB 'JSON file is empty: ',0
szJSONErrorEmptyClipData    DB 'JSON clipboard data is empty',0
szJSONCopiedDataToClipboard DB 'Copied data to clipboard',0
szJSONErrorMessage          DB 512 dup (0)

; Punctuation
szComma                     DB ',',0
szSpace                     DB ' ',0
szColon                     DB ':',0
szLeftBracket               DB '{',0
szRightBracket              DB '}',0
szBackslash                 DB '\',0
szLeftSquareBracket         DB '[',0
szRightSquareBracket        DB ']',0
szQuote                     DB '"',0

; Treeview right click menu
szTVRCMenuCollapseBranch    DB 'Collapse Branch',0
szTVRCMenuExpandBranch      DB 'Expand Branch',0
szTVRCMenuCollapseChildren  DB 'Collapse Children',0
szTVRCMenuExpandChildren    DB 'Expand Children',0
szTVRCMenuCopy              DB 'Copy',0
szTVRCMenuCopyValue         DB 'Copy Value',0
szTVRCMenuCopyBranch        DB 'Copy Branch',0
szTVRCMenuPasteJSON         DB 'Paste JSON',0
szTVRCMenuAddItem           DB 'Add Item',0
szTVRCMenuDelItem           DB 'Delete Item',0
szTVRCMenuEditItem          DB 'Edit Item',0
szTVRCMenuAddItemString     DB 'Add String',0
szTVRCMenuAddItemNumber     DB 'Add Number',0
szTVRCMenuAddItemTrue       DB 'Add True',0
szTVRCMenuAddItemFalse      DB 'Add False',0
szTVRCMenuAddItemArray      DB 'Add Array',0
szTVRCMenuAddItemObject     DB 'Add Object',0

; Command line processing stuff
szCmdLineFilenameDoesNotExist   DB 'The filename specified on the command line does not exist: ',0
CmdLineFilename                 DB 256 DUP (0)
CmdLineFullPathFilename         DB 512 DUP (0)
CmdLineProcessFileFlag          DD 0 ; 0 = no file to process (normal operation), 1 = file to open
g_fShown                        DD FALSE


g_ShowJsonType              DD FALSE ;TRUE ; shows ': Object' or ': Array' after object / array iterator items 

nStackDepth                 DD 0
nUniqueCount                DD 0

; JSON Export / Copy
szJSONExportStart           DB '{',13,10,0
szJSONExportEnd             DB '}',13,10,0
szJSONExportObjectStart     DB '{',13,10,0
szJSONExportObjectEnd       DB '}',13,10,0
szJSONExportObjectCommaEnd  DB '},',13,10,0
szJSONExportArrayStart      DB '[',13,10,0
szJSONExportArrayEnd        DB ']',13,10,0
szJSONExportArrayEmpty      DB '[]',13,10,0
szJSONExportCRLF            DB 13,10,0
szJSONExportCommaCRLF       DB ',',13,10,0
szJSONExportMiddleString    DB '": "',0
szJSONExportMiddleOther     DB '": ',0
szJSONExportIndentSpaces    DB 32 DUP (32d)
szJSONExportSpacesBuffer    DB 32 DUP (0)

;------------------------------------------------------------------------
; Browse To Open Json File
;------------------------------------------------------------------------
BrowseFile                      OPENFILENAME {}
JsonBrowseFilename              db  MAX_PATH dup (0)
JsonBrowseFilter                db  "JSON Files (*.json)",0,"*.json",0
                                db  "All Files (*.*)",0,"*.*",0,0
JsonBrowseFileTitle             db  "Open JSON File...",0
JsonDefExt                      db  "json",0
hTestItem               TV_ITEM <>

.DATA?
;-----------------------------------------------------------------------------------------
; cjsontree Uninitialized Data
;-----------------------------------------------------------------------------------------
icc                     INITCOMMONCONTROLSEX <>
hInstance               DD ?
CommandLine             DD ?
hWnd                    DD ?
hAcc                    DD ?
hWhiteBrush             DD ?
hDrop                   DD ?
hTVMenu                 DD ?
hTVAddMenu              DD ?
TVRCMenuPoint           POINT <?>
hTV                     DD ?
hSB                     DD ?
hIL                     DD ?
hICO_MAIN               DD ?
hICO_JSON_STRING        DD ?
hICO_JSON_INTEGER       DD ?
hICO_JSON_FLOAT         DD ?
hICO_JSON_CUSTOM        DD ?
hICO_JSON_TRUE          DD ?
hICO_JSON_FALSE         DD ?
hICO_JSON_ARRAY         DD ?
hICO_JSON_OBJECT        DD ?
hICO_JSON_NULL          DD ?
hICO_JSON_INVALID       DD ?
hICO_JSON_LOGICAL       DD ?
hTVRoot                 DD ?
hTVNode                 DD ?
hTVCurrentNode          DD ?
hJSONFile               DD ?
JSONMemMapHandle        DD ?
JSONMemMapPtr           DD ?
hJSONTreeRoot           DD ?
hJSON_Object_Root       DD ?
dwClientHeight          DD ?
dwClientWidth           DD ?
hVirtualStack           DD ?
VSValue                 DD ?
hArray                  DD ?
hCurrentArray           DD ?
pStackData              DD ?
pArrayName              DD ?











