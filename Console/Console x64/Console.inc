;=========================================================================================
;
; LICENSE
;
; LTLI Console Library x64 v1.0.0.0
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
; original copyright notices intact and not misrepresent the origin of the software.
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
ConsolePause            PROTO :QWORD                                    ; qwConMsgType
ConsoleStdOut           PROTO :QWORD                                    ; lpszConText
ConsoleStdIn            PROTO :QWORD, :QWORD                            ; lpszConInputBuffer, qwSizeConInputBuffer
ConsoleStdInW           PROTO :QWORD, :QWORD                            ; lpszWideConInputBuffer, qwSizeWideConInputBuffer
ConsoleStdErr           PROTO :QWORD                                    ; lpszErrText

ConsoleClearScreen      PROTO                                           ;
ConsoleCls              EQU ConsoleClearScreen                          ;
ConsoleShowCursor       PROTO                                           ;
ConsoleHideCursor       PROTO                                           ;

ConsoleGetTitle         PROTO :QWORD, :QWORD                            ; lpszConTitle, qwSizeConTitle
ConsoleGetPosition      PROTO :QWORD, :QWORD                            ; lpqwXpos, lpqwYpos
ConsoleSetTitle         PROTO :QWORD                                    ; lpszConTitle
ConsoleSetPosition      PROTO :QWORD, :QWORD                            ; qwXpos, qwYpos

ConsoleSetIcon          PROTO :QWORD                                    ; IcoResID
ConsoleAnimateIconStart PROTO :QWORD, :QWORD, :QWORD, :QWORD            ; IcoResIDStart, IcoResIDFinish, qwTime, qwTimeIconStep
ConsoleAnimateIconStop  PROTO     

ConsoleSpinnerStart     PROTO :QWORD, :QWORD, :QWORD, :QWORD            ; qwXpos, qwYpos, qwXoffset, qwYoffset
ConsoleSpinnerStop      PROTO

ConsoleStarted          PROTO                                           ; rax returns TRUE if started via console or FALSE if started via explorer
ConsoleAttach           PROTO                                           ; no return
ConsoleFree             PROTO                                           ; no return

ConsoleParseCmdLine     PROTO :QWORD                                    ; qwParametersArray (make sure buffer is large enough for all parameters)
ConsoleCmdLineParam     PROTO :QWORD, :QWORD, :QWORD, :QWORD            ; qwParametersArray, qwParameterToFetch, qwTotalParameters, lpszReturnedParameter
ConsoleCmdLineParamType PROTO :QWORD, :QWORD, :QWORD                    ; qwParametersArray, qwParameterToFetch, qwTotalParameters

ConsoleSwitchRegister   PROTO :QWORD, :QWORD                            ; lpszSwitch, qwSwitchID, bCaseSensitive
ConsoleSwitchID         PROTO :QWORD, :QWORD                            ; lpszSwitch, bCaseSensitive. Returns in rax qwSwitchID or -1 if fail
ConsoleCommandRegister  PROTO :QWORD, :QWORD                            ; lpszCommand, qwCommandID, bCaseSensitive
ConsoleCommandID        PROTO :QWORD, :QWORD                            ; lpszCommand, bCaseSensitive. Returns in rax qwCommandID or -1 if fail

.CONST
;-----------------------------------------------------------------------------------------
; LTLI Console Constants
;-----------------------------------------------------------------------------------------

;ConsolePause qwConMsgType:
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








