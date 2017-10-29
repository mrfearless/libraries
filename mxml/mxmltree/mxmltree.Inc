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

include	msvcrt.inc
includelib	msvcrt.lib

include mxml.inc
includelib mxml.lib

include TreeView.inc
includelib TreeView.lib


;-----------------------------------------------------------------------------------------
; mxmltree Prototypes
;-----------------------------------------------------------------------------------------
WinMain					PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc					PROTO :DWORD,:DWORD,:DWORD,:DWORD
InitGUI                 PROTO :DWORD
InitXMLStatusbar        PROTO :DWORD
InitXMLTreeview         PROTO :DWORD
OpenXMLFile             PROTO :DWORD
CloseXMLFile            PROTO
ProcessXMLFile          PROTO :DWORD, :DWORD

IFNDEF BROWSEFILEINFO
BROWSEFILEINFO struct 
    lStructSize		DD		?
    hwndOwner		HWND		?
    hInstance		HINSTANCE	?
    lpstrFilter		DD		?
    lpstrCustomFilter	DD		?
    nMaxCustFilter	DD		?
    nFilterIndex		DD		?
    lpstrFile		DD		?
    nMaxFile		DD		?
    lpstrFileTitle	DD		?
    nMaxFileTitle		DD		?
    lpstrInitialDir	DD		?
    lpstrTitle		DD		?
    Flags			DD		?
    nFileOffset		DW		?
    nFileExtension	DW		?
    lpstrDefExt		DD		?
    lCustData		DD		?
    lpfnHook		DD		?
    lpTemplateName	DD		?
BROWSEFILEINFO	ends
ENDIF


.CONST
;-----------------------------------------------------------------------------------------
; mxmltree Constants
;-----------------------------------------------------------------------------------------

; Icon Resource IDs
ICO_MAIN                EQU 100
ICO_XML_ELEMENT         EQU 101
ICO_XML_ATTRIBUTE       EQU 102
ICO_XML_STRING          EQU 103
ICO_XML_INTEGER         EQU 104
ICO_XML_FLOAT           EQU 105
ICO_XML_CUSTOM          EQU 106

; Image list index to icons
IL_ICO_MAIN             EQU 0
IL_ICO_XML_ELEMENT      EQU 1
IL_ICO_XML_ATTRIBUTE    EQU 2
IL_ICO_XML_STRING       EQU 3
IL_ICO_XML_INTEGER      EQU 4
IL_ICO_XML_FLOAT        EQU 5
IL_ICO_XML_CUSTOM       EQU 6



; Main Dialog
IDD_DIALOG				EQU 1000
IDC_TV					equ 1001
IDC_SB					equ 1002

; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_FILE_OPEN			EQU 10002
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; mxmltree Initialized Data
;-----------------------------------------------------------------------------------------
ClassName				DB 'DLGCLASS',0
AppName					DB 'LTLI Dialog',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2017',0



szAttributeName         DB 'name',0
szAttributeType         DB 'type',0
szAttributeValue        DB 'value',0

szAttribEquals          DB ' = ',0

szAttribNameValue       DB 256 dup (0)



szXMLLoadingFile        DB 'Loading XML File...',0
szXMLErrorLoadingFile   DB 'Error loading XML File: ',0
szXMLErrorMappingFile   DB 'Error mapping XML File: ',0
szXMLErrorReadingFile   DB 'Error reading XML File: ',0
szXMLLoadedFile         DB 'Loaded XML File: ',0

szXMLErrorMessage       DB 512 dup (0)

;------------------------------------------------------------------------
; Browse To Open XML File
;### SEE - NOTE1: ###

;------------------------------------------------------------------------
BrowseFile						BROWSEFILEINFO {}
XmlBrowseFilename		        db 	MAX_PATH dup (0)
XmlBrowseFilter				    db	"XML Files (*.xml)",0,"*.xml",0
                                db  "All Files (*.*)",0,"*.*",0,0
XmlBrowseFileTitle	            db	"Open XML File...",0
XmlDefExt				        db  "xml",0


.DATA?
;-----------------------------------------------------------------------------------------
; mxmltree Uninitialized Data
;-----------------------------------------------------------------------------------------
icc 					INITCOMMONCONTROLSEX <>
hInstance				DD ?
CommandLine				DD ?
hWnd					DD ?
hWhiteBrush             DD ?
hTV                     DD ?
hSB                     DD ?
hIL                     DD ?
hICO_MAIN               DD ?
hICO_XML_ELEMENT        DD ?
hICO_XML_ATTRIBUTE      DD ?
hICO_XML_STRING         DD ?
hICO_XML_INTEGER        DD ?
hICO_XML_FLOAT          DD ?
hICO_XML_CUSTOM         DD ?
hXMLFile                DD ?
XMLMemMapHandle         DD ?
XMLMemMapPtr            DD ?
hMXMLTreeRoot           DD ?
hMXMLTreeNode           DD ?
hMXMLNextNode           DD ?
hMXMLPrevNode           DD ?
hMXMLFirstChildNode     DD ?
hMXMLLastChildNode      DD ?
hMXMLParentNode         DD ?
lpszText                DD ?
lpszAttribute           DD ?
lpszElement             DD ?
lpszElementName         DD ?
lpszAttributeName       DD ?
lpszAttributeValue      DD ?
hTVRoot                 DD ?
hTVNode                 DD ?
dwClientHeight          DD ?
dwClientWidth           DD ?