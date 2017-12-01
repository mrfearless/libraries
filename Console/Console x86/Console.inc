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
ConsoleStdIn            PROTO :DWORD, :DWORD                            ; lpszConInputBuffer, dwSizeConInputBuffer
ConsoleStdInW           PROTO :DWORD, :DWORD                            ; lpszWideConInputBuffer, dwSizeWideConInputBuffer
ConsoleStdErr           PROTO :DWORD                                    ; lpszErrText
ConsoleClearScreen      PROTO                                           ;
ConsoleCls              EQU ConsoleClearScreen                          ;
ConsoleShowCursor       PROTO                                           ;
ConsoleHideCursor       PROTO                                           ;
ConsoleSetIcon          PROTO :DWORD                                    ; IcoResID
ConsoleSetTitle         PROTO :DWORD                                    ; lpszConTitle
ConsoleSetPosition      PROTO :DWORD, :DWORD                            ; dwXpos, dwYpos
ConsoleStarted          PROTO                                           ; eax returns TRUE if started via console or FALSE if started via explorer
ConsoleAttach           EQU AttachConsole
ConsoleFree             EQU FreeConsole
ConsoleParseCmdLine     PROTO :DWORD                                    ; dwParametersArray (make sure buffer is large enough for all parameters)
ConsoleCmdLineParam     PROTO :DWORD, :DWORD, :DWORD, :DWORD            ; dwParametersArray, dwParameterToFetch, dwTotalParameters, lpszReturnedParameter

.CONST
;-----------------------------------------------------------------------------------------
; LTLI Console Constants
;-----------------------------------------------------------------------------------------

;ConsolePause bConMsgType:
CON_PAUSE_NO_MSG            EQU 0
CON_PAUSE_ANY_KEY_CONTINUE  EQU 1
CON_PAUSE_ANY_KEY_EXIT      EQU 2











