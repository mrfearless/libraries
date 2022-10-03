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

include .\Capstone\capstone_x86.inc
includelib .\Capstone\capstone_x86_dll.lib

;-----------------------------------------------------------------------------------------
; CSExample_x86 Prototypes
;-----------------------------------------------------------------------------------------
WinMain                 PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc                 PROTO :DWORD,:DWORD,:DWORD,:DWORD
DoDecode                PROTO :DWORD


.CONST
;-----------------------------------------------------------------------------------------
; CSExample_x86 Constants
;-----------------------------------------------------------------------------------------
; Main Dialog
ICO_MAIN                        EQU 100

;CSExample_x86.dlg
IDD_DIALOG						equ 1000
IDC_LblAsmDecoded				equ 1001
IDC_TxtRawBytes					equ 1002
IDC_LblRawBytes					equ 1003
IDC_TxtAsmDecoded				equ 1004
IDC_BtnDecode					equ 1005
IDC_BtnExit						equ 1006

; Main Menu 
IDM_MENU                EQU 10000
IDM_FILE_EXIT           EQU 10001
IDM_HELP_ABOUT          EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; CSExample_x86 Initialized Data
;-----------------------------------------------------------------------------------------
ClassName               DB 'DLGCLASS',0
AppName                 DB 'Capstone Example x86',0
AboutMsg                DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2018',0

szCSError               DB 'Capstone Error',0
szCSCodeEmpty           DB 'Please enter some raw byte code to decode.',0
szCSOpenFail            DB 'ERROR: failed on cs_open',0
szCSDisasmFail          DB 'ERROR: cs_disasm failed',0

szFmt                   DB '0x%lx',9,'%s %s',13,10,0;'%02X ',0
szOutput                DB 1024 DUP (0)
szFinalOutput           DB 2048 DUP (0)
szBuffer                DB 256  DUP (0)

szInitialRawCode        DB "\x55\x48\x8b\x05\xb8\x13\x00\x00",0

RAWCODE                 DB 055h,048h,08bh,005h,0b8h,013h,000h,000h
dwSizeRAWCODE           DD $-RAWCODE

.DATA?
;-----------------------------------------------------------------------------------------
; CSExample_x86 Uninitialized Data
;-----------------------------------------------------------------------------------------
icc                     INITCOMMONCONTROLSEX <>
hInstance               DD ?
CommandLine             DD ?
hWnd                    DD ?
hIcoMain                DD ?
hWhiteBrush             DD ?
hTxtAsmDecoded			DD ?
hTxtRawBytes		    DD ?




