;=========================================================================================
;
; LICENSE
;
; LTLI Console Library v1.0.0.0
;
; Copyright (c) 2017 by KSR aka fearless
;
; All Rights Reserved
;
; http://www.LetTheLight.in
;
;
; This software is provided 'as-is', without any express or implied warranty. In no
; event will the author be held liable for any damages arising from the use of this
; software.
;
; Permission is granted to anyone to use this software for any non-commercial program.
; If you use the library in an application, an acknowledgement in the application or
; documentation is appreciated but not required. 
;
; You are allowed to make modifications to the source code, but you must leave the
; original copyright notices intact and not mispresent the origin of the software.
; It is not allowed to claim you wrote the original software. Modified files must have
; a clear notice that the files are modified, and not in the original state. This includes
; the name of the person(s) who modified the code. 
;
; If you want to distribute or redistribute any portion of this package, you will need
; to include the full package in it's original state, including this license and all
; the copyrights. 
;
; While distributing this package (in it's original state) is allowed, it is not allowed
; to charge anything for this. You may not sell or include the package in any commercial
; package without having permission of the author. Neither is it allowed to redistribute
; any of the package's components with commercial applications.
;
;=========================================================================================

;-----------------------------------------------------------------------------------------
; LTLI Console Prototypes
;-----------------------------------------------------------------------------------------
ConsolePause            PROTO :DWORD                                    ; dwConMsgType
ConsoleStdOut           PROTO :DWORD                                    ; lpszConText
ConsoleText             PROTO :DWORD                                    ; lpszConText (ConsoleText is alias for ConsoleStdOut)
ConsoleStdOutColor      PROTO :DWORD, :DWORD                            ; lpszConText, Color
ConsoleTextColor        PROTO :DWORD, :DWORD                            ; lpszConText, Color (ConsoleTextColor is alias for ConsoleStdOutColor)
ConsoleStdIn            PROTO :DWORD, :DWORD                            ; lpszConInputBuffer, dwSizeConInputBuffer
ConsoleStdInW           PROTO :DWORD, :DWORD                            ; lpszWideConInputBuffer, dwSizeWideConInputBuffer
ConsoleStdErr           PROTO :DWORD                                    ; lpszErrText
ConsoleError            PROTO :DWORD                                    ; lpszErrText (ConsoleError is alias for ConsoleStdErr)

ConsoleClearScreen      PROTO                                           ; no return
ConsoleCls              PROTO                                           ; no return
ConsoleShowCursor       PROTO                                           ; no return
ConsoleHideCursor       PROTO                                           ; no return

ConsoleGetTitle         PROTO :DWORD, :DWORD                            ; lpszConTitle, dwSizeConTitle
ConsoleGetPosition      PROTO :DWORD, :DWORD                            ; lpdwXpos, lpdwYpos
ConsoleSetTitle         PROTO :DWORD                                    ; lpszConTitle
ConsoleSetPosition      PROTO :DWORD, :DWORD                            ; dwXpos, dwYpos

ConsoleSetIcon          PROTO :DWORD                                    ; IcoResID
ConsoleAnimateIconStart PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; IcoResIDStart, IcoResIDFinish, dwTime, dwTimeIconStep
ConsoleAnimateIconStop  PROTO                                           ; 

ConsoleSpinnerStart     PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; dwXpos, dwYpos, dwXoffset, dwYoffset
ConsoleSpinnerStop      PROTO

ConsoleStarted          PROTO                                           ; eax returns TRUE if started via console or FALSE if started via explorer
ConsoleAlloc            TEXTEQU <AllocConsole>
ConsoleAttach           PROTO                                           ; no return
ConsoleAttachProcess    PROTO :DWORD
ConsoleFree             PROTO                                           ; no return

ConsoleParseCmdLine     PROTO :DWORD                                    ; dwParametersArray (make sure buffer is large enough for all parameters)
ConsoleCmdLineParam     PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; dwParametersArray, dwParameterToFetch, dwTotalParameters, lpszReturnedParameter
ConsoleCmdLineParamType PROTO :DWORD, :DWORD, :DWORD                    ; dwParametersArray, dwParameterToFetch, dwTotalParameters

ConsoleSwitchRegister   PROTO :DWORD, :DWORD                            ; lpszSwitch, dwSwitchID, bCaseSensitive
ConsoleSwitchID         PROTO :DWORD, :DWORD                            ; lpszSwitch, bCaseSensitive. Returns in eax dwSwitchID or -1 if fail
ConsoleCommandRegister  PROTO :DWORD, :DWORD                            ; lpszCommand, dwCommandID, bCaseSensitive
ConsoleCommandID        PROTO :DWORD, :DWORD                            ; lpszCommand, bCaseSensitive. Returns in eax dwCommandID or -1 if fail

.CONST
;-----------------------------------------------------------------------------------------
; LTLI Console Constants
;-----------------------------------------------------------------------------------------

;ConsolePause bConMsgType:
CON_PAUSE_NO_MSG            EQU 0
CON_PAUSE_ANY_KEY_CONTINUE  EQU 1
CON_PAUSE_ANY_KEY_EXIT      EQU 2

;ConsoleCmdLineParamType return values:
CMDLINE_PARAM_TYPE_ERROR    EQU -1  ;
CMDLINE_PARAM_TYPE_UNKNOWN  EQU 0   ;
CMDLINE_PARAM_TYPE_SWITCH   EQU 1   ; /? /Q
CMDLINE_PARAM_TYPE_COMMAND  EQU 2   ; Xa C
CMDLINE_PARAM_TYPE_FILESPEC EQU 3   ; *.*, <filename>.*, *.<ext>
CMDLINE_PARAM_TYPE_FILENAME EQU 4   ; <filename.ext>
CMDLINE_PARAM_TYPE_FOLDER   EQU 5   ; C:\Windows, .\MyFolder, ..\OtherFolder

; Colors for ConsoleStdOutColor
FOREGROUND_WHITE		    EQU (FOREGROUND_RED or FOREGROUND_BLUE or FOREGROUND_GREEN)
FOREGROUND_YELLOW       	EQU (FOREGROUND_RED or FOREGROUND_GREEN)
FOREGROUND_CYAN		        EQU (FOREGROUND_BLUE or FOREGROUND_GREEN)
FOREGROUND_MAGENTA	        EQU (FOREGROUND_RED or FOREGROUND_BLUE)
FOREGROUND_BLACK		    EQU 0

FOREGROUND_INTENSE_RED		EQU (FOREGROUND_RED or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_GREEN	EQU (FOREGROUND_GREEN or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_BLUE		EQU (FOREGROUND_BLUE or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_WHITE	EQU (FOREGROUND_WHITE or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_YELLOW	EQU (FOREGROUND_YELLOW or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_CYAN		EQU (FOREGROUND_CYAN or FOREGROUND_INTENSITY)
FOREGROUND_INTENSE_MAGENTA	EQU (FOREGROUND_MAGENTA or FOREGROUND_INTENSITY)

BACKGROUND_WHITE		    EQU (BACKGROUND_RED or BACKGROUND_BLUE or BACKGROUND_GREEN)
BACKGROUND_YELLOW	        EQU (BACKGROUND_RED or BACKGROUND_GREEN)
BACKGROUND_CYAN		        EQU (BACKGROUND_BLUE or BACKGROUND_GREEN)
BACKGROUND_MAGENTA	        EQU (BACKGROUND_RED or BACKGROUND_BLUE)
BACKGROUND_BLACK		    EQU 0

BACKGROUND_INTENSE_RED		EQU (BACKGROUND_RED or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_GREEN	EQU (BACKGROUND_GREEN or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_BLUE		EQU (BACKGROUND_BLUE or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_WHITE	EQU (BACKGROUND_WHITE or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_YELLOW	EQU (BACKGROUND_YELLOW or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_CYAN		EQU (BACKGROUND_CYAN or BACKGROUND_INTENSITY)
BACKGROUND_INTENSE_MAGENTA	EQU (BACKGROUND_MAGENTA or BACKGROUND_INTENSITY)





