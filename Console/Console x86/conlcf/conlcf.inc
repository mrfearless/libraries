include windows.inc
include user32.inc
include kernel32.inc
include shell32.inc
include masm32.inc
includelib user32.lib
includelib kernel32.lib
includelib shell32.lib
includelib masm32.lib




;-----------------------------------------------------------------------------------------
; conlcf Prototypes
;-----------------------------------------------------------------------------------------
conlcfMain             PROTO
conlcfRegisterSwitches PROTO
conlcfRegisterCommands PROTO
conlcfProcessCmdLine   PROTO

conlcfConInfo          PROTO :DWORD
conlcfConErr           PROTO :DWORD

conlcfFileInOpen       PROTO :DWORD
conlcfFileInClose      PROTO
conlcfFileOutOpen      PROTO :DWORD
conlcfFileOutClose     PROTO


JustFnameExt                    PROTO :DWORD, :DWORD
IFNDEF GetCommandLineA
GetCommandLineA                 PROTO 
GetCommandLine                  EQU <GetCommandLineA>
ENDIF


.CONST
;-----------------------------------------------------------------------------------------
; conlcf Constants
;-----------------------------------------------------------------------------------------
ICO_MAIN                        EQU 100
ICO_CMD                         EQU 101

; conlcfConInfo dwMsgType:
CON_OUT_INFO                    EQU 0   ; Header information
CON_OUT_ABOUT                   EQU 1   ; About information
CON_OUT_USAGE                   EQU 2   ; Usage information: switches/commands and params
CON_OUT_HELP                    EQU 3   ; Help information

; Constants for conlcfProcessCmdLine
; return values and for conlcfConErr
; dwErrorType:
CONSOLE_ERROR                   EQU -8 ; general error
CONSOLE_D_PARAM_E_UNKNOWN       EQU -7
CONSOLE_D_PARAM_E_INVALID       EQU -6
CONSOLE_E_WITH_PARAM            EQU -5
CONSOLE_D_PARAM_INVALID         EQU -4
CONSOLE_D_WITHOUT_PARAM         EQU -3
CONSOLE_UNKNOWN_COMMAND         EQU -2  ; User provided a <X> command that wasnt recognised
CONSOLE_UNKNOWN_SWITCH          EQU -1  ; User provided a /<X> or -<X> switch that wasnt recognised
CONSOLE_NOTHING                 EQU 0   ;
CONSOLE_HELP                    EQU 1   ; User specified /? -? --? as a parameter
CONSOLE_D_WITH_PARAM            EQU 2
CONSOLE_E                       EQU 3
CONSOLE_D_PARAM_E	            EQU 4

; conlcf Switch IDs: /? -? --?
SWITCH_HELP                     EQU 0   ; /? help switch
SWITCH_HELP_UNIX                EQU 1   ; -? help switch
SWITCH_HELP_UNIX2               EQU 2   ; --? help switch
SWITCH_D                        EQU 3   ; -d
SWITCH_D_ALT                    EQU 4   ; /d
SWITCH_E                        EQU 5   ; -e
SWITCH_E_ALT                    EQU 6   ; /e



.DATA
;-----------------------------------------------------------------------------------------
; conlcf Initialized Data
;-----------------------------------------------------------------------------------------
AppName                         DB 'conlcf',0
TitleName                       DB 'conlcf Tool v1.0.0.0',0
szConTitle                      DB MAX_PATH DUP (0)
CmdLineParameters               DB 512 DUP (0)
CmdLineParameter                DB 256 DUP (0)
ErrParameter                    DB 256 DUP (0)
TotalCmdLineParameters          DD 0

; Switches
SwitchHelp                      DB '/?',0
SwitchHelpAlt                   DB '-?',0
SwitchHelpAlt2                  DB '--?',0
SwitchD                         DB '-D',0
SwitchDAlt                      DB '/D',0
SwitchE                         DB '-E',0
SwitchEAlt                      DB '/E',0


; Help
szconlcfConInfo                 DB 13,10,"[conlcf] v1.00 - conlcf Tool - Copyright (C) 2017 fearless",13,10,13,10,0

szconlcfConAbout                DB "About:",13,10
                                DB "========",13,10
                                DB "conlcf is a console program which needs to be ran from a command prompt.",13,10
                                DB "For detailed help on the conlcf options, specify conlcf /? at the prompt.",13,10
                                DB 13,10,13,10
                                 DB 13,10,0

szconlcfConHelp                 DB "Usage: conlcf [/?]",13,10
                                DB 13,10
                                DB "  /?           Displays this help",13,10
                                DB 13,10
                                DB 13,10,0

szconlcfConHelpUsage            DB "Usage: conlcf [/?]",13,10
                                DB 13,10,0


; Error message
szError                         DB "[!] Error: ",0
szErrorOther                    DB " an unknown error has occurred.",0
szErrorUnknownSwitch            DB " invalid switch specified.",0
szErrorUnknownCommand           DB " invalid command specified.",0
szErrorDswitchOnly              DB "/D switch on its own. Missing a parameter.",0
szErrorDswitchXSwitch           DB "/D invalid parameter specified (second parameter was a switch)",0
szErrorEparameter               DB "/E specified with an additional parameter, which is illegal.",0
szErrorDEInvalid                DB "/D with a parameter and an invalid switch specified. Expecting /E for third parameter.",0
szErrorDEUnknown                DB "/D with two parameters specified. Expecting /E for third parameter.",0


; Success messages
szESwitchOnly                   DB "User specified /E on its own.",13,10,0
szDParam1                       DB "User specified /D and '",0
szDParam2                       DB "' ",13,10,0
szDparamE1                      DB "User specified /D, '",0
szDparamE2                      DB "' and /E",13,10,0



; Punctuation
szComma                         DB ',',0
szSpace                         DB ' ',0
szColon                         DB ':',0
szLeftBracket                   DB '{',0
szRightBracket                  DB '}',0
szBackslash                     DB '\',0
szLeftSquareBracket             DB '[',0
szRightSquareBracket            DB ']',0
szQuote                         DB '"',0
szSingleQuote                   DB "'",0
szDash                          DB '-',0
szForwardslash                  DB '/',0
szWildCardStar                  DB '*',0
szWildCardQuestion              DB '?',0
szLF                            DB 10,0
szCRLF                          DB 13,10,0
szFolderAllFiles                DB '\*.*',0

D_ParamBuffer                   DB MAX_PATH DUP (0)
 


.DATA?
;-----------------------------------------------------------------------------------------
; conlcf Uninitialized Data
;-----------------------------------------------------------------------------------------
hFileIn                         DD ?
hMemMapIn                       DD ?
hMemMapInPtr                    DD ?
hFileOut                        DD ?
hMemMapOut                      DD ?
hMemMapOutPtr                   DD ?
qwFileSize                      DQ ?
dwFileSize                      DD ?
dwFileSizeHigh                  DD ?



















