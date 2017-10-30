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

;-----------------------------------------------------------------------------------------
; cjsontree Prototypes
;-----------------------------------------------------------------------------------------
WinMain                 PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc                 PROTO :DWORD,:DWORD,:DWORD,:DWORD
InitGUI                 PROTO :DWORD
InitJSONStatusbar       PROTO :DWORD
InitJSONTreeview        PROTO :DWORD
OpenJSONFile            PROTO :DWORD
CloseJSONFile           PROTO
ProcessJSONFile         PROTO :DWORD, :DWORD

IFNDEF BROWSEFILEINFO
BROWSEFILEINFO struct 
    lStructSize     DD      ?
    hwndOwner       HWND        ?
    hInstance       HINSTANCE   ?
    lpstrFilter     DD      ?
    lpstrCustomFilter   DD      ?
    nMaxCustFilter  DD      ?
    nFilterIndex        DD      ?
    lpstrFile       DD      ?
    nMaxFile        DD      ?
    lpstrFileTitle  DD      ?
    nMaxFileTitle       DD      ?
    lpstrInitialDir DD      ?
    lpstrTitle      DD      ?
    Flags           DD      ?
    nFileOffset     DW      ?
    nFileExtension  DW      ?
    lpstrDefExt     DD      ?
    lCustData       DD      ?
    lpfnHook        DD      ?
    lpTemplateName  DD      ?
BROWSEFILEINFO  ends
ENDIF

.CONST
;-----------------------------------------------------------------------------------------
; cjsontree Constants
;-----------------------------------------------------------------------------------------

; Icon Resource IDs
ICO_MAIN                EQU 100
ICO_JSON_ELEMENT        EQU 101
ICO_JSON_ATTRIBUTE      EQU 102
ICO_JSON_STRING         EQU 103
ICO_JSON_INTEGER        EQU 104
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
IL_ICO_JSON_ELEMENT      EQU 1
IL_ICO_JSON_ATTRIBUTE    EQU 2
IL_ICO_JSON_STRING       EQU 3
IL_ICO_JSON_INTEGER      EQU 4
IL_ICO_JSON_FLOAT        EQU 5
IL_ICO_JSON_CUSTOM       EQU 6
IL_ICO_JSON_TRUE         EQU 7
IL_ICO_JSON_FALSE        EQU 8
IL_ICO_JSON_ARRAY        EQU 9
IL_ICO_JSON_OBJECT       EQU 10
IL_ICO_JSON_NULL         EQU 11
IL_ICO_JSON_INVALID      EQU 12
IL_ICO_JSON_LOGICAL      EQU 13   

; Main Dialog
IDD_DIALOG              EQU 1000
IDC_TV                  equ 1001
IDC_SB                  equ 1002

; Main Menu 
IDM_MENU                EQU 10000
IDM_FILE_EXIT           EQU 10001
IDM_FILE_OPEN           EQU 10002
IDM_HELP_ABOUT          EQU 10101


.DATA
;-----------------------------------------------------------------------------------------
; cjsontree Initialized Data
;-----------------------------------------------------------------------------------------
ClassName                   DB 'DLGCLASS',0
AppName                     DB 'LTLI Dialog',0
AboutMsg                    DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2017',0


szObject                    DB 'Object',0
szTrue                      DB 'True',0
szFalse                     DB 'False',0
szArray                     DB 'Array',0
szNull                      DB 'Null',0
szInvalid                   DB 'Invalid',0
szNullString                DB '<String>',0
szNullStringQuotes          DB '""',0
szNullInteger               DB '<Number>',0
szNullLogical               DB '<Logical>',0
szNullArray                 DB '<Array>',0
szNullNull                  DB '<Null>',0
szNullInvalid               DB '<Invalid>',0

lpszItemString              DD 0
lpszItemStringValue         DD 0
dwItemIntValue              DD 0 
LenItemString               DD 0
LenItemStringValue          DD 0

szItemIntValue              DB 64 DUP (0)
szItemText                  DB 2048 DUP (0)

szJSONLoadingFile           DB 'Loading JSON File...',0
szJSONErrorLoadingFile      DB 'Error loading JSON File: ',0
szJSONErrorMappingFile      DB 'Error mapping JSON File: ',0
szJSONErrorReadingFile      DB 'Error reading JSON File: ',0
szJSONLoadedFile            DB 'Loaded JSON File: ',0
szJSONErrorEmptyFile        DB 'JSON file is empty: ',0

szJSONErrorMessage          DB 512 dup (0)

; Punctuation
szSpace                     DB ' ',0
szColon                     DB ':',0
szLeftBracket               DB '{',0
szRightBracket              DB '}',0


;------------------------------------------------------------------------
; Browse To Open Json File
;------------------------------------------------------------------------
BrowseFile                      BROWSEFILEINFO {}
JsonBrowseFilename              db  MAX_PATH dup (0)
JsonBrowseFilter                db  "JSON Files (*.json)",0,"*.json",0
                                db  "All Files (*.*)",0,"*.*",0,0
JsonBrowseFileTitle             db  "Open JSON File...",0
JsonDefExt                      db  "json",0



.DATA?
;-----------------------------------------------------------------------------------------
; cjsontree Uninitialized Data
;-----------------------------------------------------------------------------------------
icc                     INITCOMMONCONTROLSEX <>
hInstance               DD ?
CommandLine             DD ?
hWnd                    DD ?
hWhiteBrush             DD ?
hTV                     DD ?
hSB                     DD ?
hIL                     DD ?
hICO_MAIN               DD ?
hICO_JSON_ELEMENT       DD ?
hICO_JSON_ATTRIBUTE     DD ?
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


