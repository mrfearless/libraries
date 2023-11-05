include windows.inc
include commctrl.inc
include shellapi.inc
include commdlg.inc
include Masm64.Inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib
includelib comdlg32.Lib
includelib Masm64.lib

include Treeview.inc
includelib Treeview.lib

include libcjson_x64.inc
includelib libcjson_x64.lib

include VirtualStack.inc
includelib VirtualStack.lib


;-----------------------------------------------------------------------------------------
; cjsontree Prototypes
;-----------------------------------------------------------------------------------------
InitGUI                 PROTO :QWORD
InitMenus               PROTO :QWORD
InitJSONStatusbar       PROTO :QWORD
InitJSONTreeview        PROTO :QWORD
BrowseJSONFile          PROTO :QWORD
OpenJSONFile            PROTO :QWORD, :QWORD
CloseJSONFile           PROTO
ProcessJSONFile         PROTO :QWORD, :QWORD
ProcessCmdLine          PROTO
CmdLineOpenFile         PROTO :QWORD
Tester                  PROTO :QWORD, :QWORD

IFNDEF
cJSON                           STRUCT
    next                        QWORD ?
    prev                        QWORD ?
    child                       QWORD ?
    itemtype                    QWORD ?
    valuestring                 QWORD ?
    valueint                    QWORD ?
    valuedouble                 QWORD ?
    itemstring                  QWORD ?
cJSON                           ENDS
ENDIF

.CONST
;-----------------------------------------------------------------------------------------
; cjsontree Constants
;-----------------------------------------------------------------------------------------
; Icon Resource IDs
ICO_MAIN                EQU 100
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
IL_ICO_JSON_STRING       EQU 1
IL_ICO_JSON_INTEGER      EQU 2
IL_ICO_JSON_FLOAT        EQU 3
IL_ICO_JSON_CUSTOM       EQU 4
IL_ICO_JSON_TRUE         EQU 5
IL_ICO_JSON_FALSE        EQU 6
IL_ICO_JSON_ARRAY        EQU 7
IL_ICO_JSON_OBJECT       EQU 8
IL_ICO_JSON_NULL         EQU 9
IL_ICO_JSON_INVALID      EQU 10
IL_ICO_JSON_LOGICAL      EQU 11   

; Main Dialog
IDD_DIALOG              EQU 1000
IDC_TV                  equ 1001
IDC_SB                  equ 1002

; Main Menu 
IDM_MENU                EQU 10000
IDM_FILE_EXIT           EQU 10001
IDM_FILE_OPEN           EQU 10002
IDM_FILE_CLOSE          EQU 10003
IDM_HELP_ABOUT          EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; cjsontree Initialized Data
;-----------------------------------------------------------------------------------------
align 01
szClass					db 'Win64class', 0
szAppName				db 'First Window', 0

ClassName				DB 'DLGCLASS',0
AppName					DB 'LTLI Dialog',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2014',0

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

; JSON pointers
lpszItemString              DQ 0
lpszItemStringValue         DQ 0
dqItemIntValue              DQ 0 
LenItemString               DQ 0
LenItemStringValue          DQ 0

; JSON Text Buffers
szItemIntValue              DB 64 DUP (0)
szItemText                  DB 2048 DUP (0)


; JSON Error messages
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
szBackslash                 DB '\',0

; Command line processing stuff
szCmdLineFilenameDoesNotExist   DB 'The filename specified on the command line does not exist: ',0
CmdLineFilename                 DB 256 DUP (0)
CmdLineFullPathFilename         DB 512 DUP (0)
CmdLineProcessFileFlag          DQ 0 ; 0 = no file to process (normal operation), 1 = file to open
g_fShown                        DQ FALSE

;------------------------------------------------------------------------
; Browse To Open Json File
;------------------------------------------------------------------------
BrowseFile                      OPENFILENAME {}
JsonBrowseFilename              db  MAX_PATH dup (0)
JsonBrowseFilter                db  "JSON Files (*.json)",0,"*.json",0
                                db  "All Files (*.*)",0,"*.*",0,0
JsonBrowseFileTitle             db  "Open JSON File...",0
JsonDefExt                      db  "json",0

DbgVar                  DQ 0

.DATA?
;-----------------------------------------------------------------------------------------
; cjsontree Uninitialized Data
;-----------------------------------------------------------------------------------------
align 08
icc 					INITCOMMONCONTROLSEX <>
hInstance				HINSTANCE ?
CommandLine				LPSTR ?
hWnd					HWND ?
hWhiteBrush             DQ ?
hDrop                   DQ ?
hTVMenu                 DQ ?
hTV                     DQ ?
hSB                     DQ ?
hIL                     DQ ?
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
hTVRoot                 DQ ?
hTVNode                 DQ ?
hTVCurrentNode          DQ ?
hJSONFile               DQ ?
JSONMemMapHandle        DQ ?
JSONMemMapPtr           DQ ?
hJSONTreeRoot           DQ ?
hJSON_Object_Root       DQ ?
;hJSON                   DQ ?
;next                    DQ ?
;prev                    DQ ?
;child                   DQ ?
;jsontype                DQ ?
;level                   DQ ?
dqClientHeight          DQ ?
dqClientWidth           DQ ?
hVirtualStack           DQ ?
dqVirtualStackValue     DQ ?



