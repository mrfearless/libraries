include windows.inc
include CommCtrl.inc
include shellapi.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib


;-----------------------------------------------------------------------------------------
; DbgTest Prototypes
;-----------------------------------------------------------------------------------------



.CONST
;-----------------------------------------------------------------------------------------
; DbgTest Constants
;-----------------------------------------------------------------------------------------
; Main Dialog
;DbgTest.dlg
IDD_DIALOG				equ 1000
IDC_BTN1				equ 1001
IDC_BTN2				equ 1002
IDC_BTN3				equ 1003
IDC_BTNEXIT				equ 1004


; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; DbgTest Initialized Data
;-----------------------------------------------------------------------------------------
align 01
szClass					db 'Win64class', 0
szAppName				db 'First Window', 0

ClassName				DB 'DLGCLASS',0
AppName					DB 'DbgTest',0
AboutMsg				DB 'fearless 2015',0

szDbgTestString         DB "This is a test string",0
szDbgTestStringBy       DB "This is a test string that is printed by PrintStringByAddr",0

dwTestDWORD             DD 1234567d
dwTestQWORD             DQ 1234567891011d 

dwTestString            DQ 0


.DATA?
;-----------------------------------------------------------------------------------------
; DbgTest Uninitialized Data
;-----------------------------------------------------------------------------------------
align 08
icc 					INITCOMMONCONTROLSEX <>
hInstance				HINSTANCE ?
CommandLine				LPSTR ?
hWnd					HWND ?
IFDEF DEBUG64
    DbgVar DD ?
ENDIF




