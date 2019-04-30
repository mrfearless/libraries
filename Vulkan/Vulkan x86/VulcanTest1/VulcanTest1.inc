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

include advapi32.inc
includelib advapi32.lib

include cfgmgr32.inc
includelib cfgmgr32.lib

includelib msvcrt14.lib
includelib libcmt.lib
includelib ucrt.lib
includelib vcruntime.lib

include Vulkan.inc
includelib Vulkan.lib

FP4 MACRO value
    LOCAL vname
    .data
    align 4
      vname REAL4 value
    .code
    EXITM <vname>
ENDM

InitOnceExecuteOnce     PROTO :DWORD, :DWORD, :DWORD, :DWORD ; WinBase.h / Kernel32.lib


;-----------------------------------------------------------------------------------------
; VulcanTest1 Prototypes
;-----------------------------------------------------------------------------------------
WinMain					PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc					PROTO :DWORD,:DWORD,:DWORD,:DWORD
StartVulkan             PROTO :DWORD

.CONST
;-----------------------------------------------------------------------------------------
; VulcanTest1 Constants
;-----------------------------------------------------------------------------------------
; Main Dialog
IDD_DIALOG				EQU 1000

; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; VulcanTest1 Initialized Data
;-----------------------------------------------------------------------------------------
ClassName				DB 'DLGCLASS',0
AppName					DB 'LTLI Dialog',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2014',0
APP_SHORT_NAME          DB 'VulkanTest1',0

szErrorFindICD          DB "cannot find a compatible Vulkan ICD",0
szErrorUnknown          DB "Unknown error",0
szSuccess               DB "Success",0
szErrorEnumDevices      DB "Error Enumeratating Physical Devices",0
szErrorCreateDevice     DB "Error Creating Devices",0
szErrorCreateCmdPool    DB "Error Creating Command Pool",0
szErrorAllocCmdBuf      DB "Error Allocating Command Buffer",0
szErrorWin32Surface     DB "Error Creating Win32 Surface",0
szErrorNoQueues         DB "Could not get appropriate queues",0

.DATA?
;-----------------------------------------------------------------------------------------
; VulcanTest1 Uninitialized Data
;-----------------------------------------------------------------------------------------
icc 					INITCOMMONCONTROLSEX <>
hInstance				DD ?
CommandLine				DD ?
hWnd					DD ?





