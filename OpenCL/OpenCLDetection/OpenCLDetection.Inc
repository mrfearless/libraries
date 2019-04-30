include windows.inc
include CommCtrl.inc
include shellapi.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib


;-----------------------------------------------------------------------------------------
; OpenCLDetection Prototypes
;-----------------------------------------------------------------------------------------



.CONST
;-----------------------------------------------------------------------------------------
; OpenCLDetection Constants
;-----------------------------------------------------------------------------------------
; Main Dialog
IDD_DIALOG				EQU 1000

; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; OpenCLDetection Initialized Data
;-----------------------------------------------------------------------------------------
align 01
szClass					db 'Win64class', 0
szAppName				db 'First Window', 0

ClassName				DB 'DLGCLASS',0
AppName					DB 'LTLI Dialog',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2014',0





.DATA?
;-----------------------------------------------------------------------------------------
; OpenCLDetection Uninitialized Data
;-----------------------------------------------------------------------------------------
align 08
icc 					INITCOMMONCONTROLSEX <>
hInstance				HINSTANCE ?
CommandLine				LPSTR ?
hWnd					HWND ?





