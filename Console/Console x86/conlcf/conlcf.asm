.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1
;
;IFDEF DEBUG32
;    PRESERVEXMMREGS equ 1
;    Includelib M:\Masm32\lib\Debug32.lib
;    DBG32LIB equ 1
;    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
;    Include M:\Masm32\include\debug32.inc
;ENDIF


Include conlcf.inc

include Console.inc
includelib Console.lib


.CODE

Main PROC

    Invoke ConsoleStarted
    .IF eax == TRUE ; Started From Console

        Invoke ConsoleAttach
        Invoke ConsoleSetIcon, ICO_MAIN
        Invoke ConsoleGetTitle, Addr szConTitle, SIZEOF szConTitle
        Invoke ConsoleSetTitle, Addr TitleName
        Invoke conlcfConInfo, CON_OUT_INFO
        
        ; Start main console processing
        Invoke conlcfMain
        ; Exit main console processing
        
        ;Invoke ConsolePause, CON_PAUSE_ANY_KEY_CONTINUE
        Invoke ConsoleSetTitle, Addr szConTitle
        Invoke ConsoleSetIcon, ICO_CMD
        Invoke ConsoleShowCursor
        Invoke ConsoleFree

    .ELSE ; Started From Explorer
        
	    Invoke ConsoleAttach
        Invoke ConsoleSetIcon, ICO_MAIN
        Invoke ConsoleSetTitle, Addr TitleName 
        Invoke conlcfConInfo, CON_OUT_INFO
        Invoke conlcfConInfo, CON_OUT_ABOUT
        ;Invoke conlcfConInfo, CON_OUT_USAGE
        Invoke ConsolePause, CON_PAUSE_ANY_KEY_EXIT
        Invoke ConsoleSetIcon, ICO_CMD
        Invoke ConsoleFree
        
    .ENDIF
    
    Invoke  ExitProcess,0
    ret
Main ENDP


;-------------------------------------------------------------------------------------
; conlcfMain
;-------------------------------------------------------------------------------------
conlcfMain PROC

    Invoke conlcfRegisterSwitches
    Invoke conlcfRegisterCommands    
    Invoke conlcfProcessCmdLine

    ;---------------------------------------------------------------------------------
    ; HELP: /? help switch or no switch
    ;---------------------------------------------------------------------------------
    .IF eax == CONSOLE_NOTHING || eax == CONSOLE_HELP ; no switch provided or /?    : 0 or 1
        Invoke conlcfConInfo, CON_OUT_HELP   

    .ELSEIF eax == CONSOLE_D_WITH_PARAM ; /d with something else - is good          : 2
        ; we have the something else part in D_ParamBuffer
        Invoke ConsoleStdOut, Addr szDParam1
        Invoke ConsoleStdOut, Addr D_ParamBuffer
        Invoke ConsoleStdOut, Addr szDParam2

    .ELSEIF eax == CONSOLE_E ; /e on its own                                        : 3
        Invoke ConsoleStdOut, Addr szESwitchOnly

    .ELSEIF eax == CONSOLE_D_PARAM_E ; /d something and /e - is good                : 4
        ; we have the something else part in D_ParamBuffer
        Invoke ConsoleStdOut, Addr szDparamE1
        Invoke ConsoleStdOut, Addr D_ParamBuffer
        Invoke ConsoleStdOut, Addr szDparamE2   

    ; Normally < 0 we would pass to error handling conlcfConErr, but for demo purposes we handle here:

    .ELSEIF eax == CONSOLE_D_PARAM_E_UNKNOWN ; /d something something - illegal     : -7
        Invoke conlcfConErr, eax

    .ELSEIF eax == CONSOLE_D_PARAM_E_INVALID ; /d something /x - illegal            : -6
        Invoke conlcfConErr, eax

    .ELSEIF eax == CONSOLE_E_WITH_PARAM ; /e and something else - illegal           : -5
        Invoke conlcfConErr, eax

    .ELSEIF eax == CONSOLE_D_PARAM_INVALID ; /d and /x - illegal                    : -4
        Invoke conlcfConErr, eax

    .ELSEIF CONSOLE_D_WITHOUT_PARAM ; /d on its own - illegal                       : -3
        Invoke conlcfConErr, eax
    
    ;---------------------------------------------------------------------------------
    ; ERROR
    ;---------------------------------------------------------------------------------    
    .ELSE
    
        Invoke conlcfConErr, eax
        
    .ENDIF
    
    ret
conlcfMain ENDP


;-----------------------------------------------------------------------------------------
; Process command line information
;-----------------------------------------------------------------------------------------
conlcfProcessCmdLine PROC
    LOCAL dwLenCmdLineParameter:DWORD
    
    Invoke GetCommandLine
    Invoke ConsoleParseCmdLine, Addr CmdLineParameters
    mov TotalCmdLineParameters, eax ; will be at least 1 as param 0 is name of exe
    
   .IF TotalCmdLineParameters == 1 ; nothing extra specified
        mov eax, CONSOLE_NOTHING
        ret       
    .ENDIF       

    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 1, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CONSOLE_ERROR
        ret
    .ENDIF

    ;-------------------------------------------------------------------------------------
    ; User provided a single parameter for us to check
    ;-------------------------------------------------------------------------------------    
    .IF TotalCmdLineParameters == 2
        ; Param 1 of 1
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            mov eax, CONSOLE_ERROR
            ret

        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
            Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
            .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2 
                mov eax, CONSOLE_HELP ; user specified /? -? or --? as switch
                ret
                
            .ELSEIF eax == SWITCH_E || eax == SWITCH_E_ALT 
                mov eax, CONSOLE_E ; /e (-e) on its own is good
                ret
            
            .ELSEIF eax == SWITCH_D || eax == SWITCH_D_ALT     
                mov eax, CONSOLE_D_WITHOUT_PARAM ; /d (-d) requires a parameter
                ret
                
            .ELSE
                mov eax, CONSOLE_UNKNOWN_SWITCH
                ret
            .ENDIF
            
        .ELSE
            mov eax, CONSOLE_ERROR
            ret
            
        .ENDIF
    .ENDIF
    
    ;-------------------------------------------------------------------------------------
    ; User provided two parameters for us to check
    ;-------------------------------------------------------------------------------------    
    .IF TotalCmdLineParameters == 3
        ; 1st param of 2
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            mov eax, CONSOLE_ERROR
            ret    

        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
            Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
            .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2
                mov eax, CONSOLE_HELP ; user specified /? -? or --? as first switch, ignore other parameters
                ret
                
            .ELSEIF eax == SWITCH_E || eax == SWITCH_E_ALT ; user provided /e and another param which is illegal
                mov eax, CONSOLE_E_WITH_PARAM
                ret
                
            .ELSEIF eax == SWITCH_D || eax == SWITCH_D_ALT  ; user specified /d with a param - which is good
                ; continue to check next paramter: 2 of 2
                
            .ELSE
                mov eax, CONSOLE_UNKNOWN_SWITCH
                ret
            .ENDIF

        .ELSE
            mov eax, CONSOLE_ERROR
            ret
            
        .ENDIF
        
        ; Get 2nd param of 2
        Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr CmdLineParameter
        .IF sdword ptr eax > 0
            mov dwLenCmdLineParameter, eax
        .ELSE
            mov eax, CONSOLE_ERROR
            ret
        .ENDIF
        
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 2, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            mov eax, CONSOLE_ERROR
            ret

        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH ; user specified /d and a switch which is illegal
            mov eax, CONSOLE_D_PARAM_INVALID
            ret
 
        .ELSE
            ; we assume this parameter is something we need for the /d something, so get it and store it in D_ParamBuffer
            Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr D_ParamBuffer
            mov eax, CONSOLE_D_WITH_PARAM
            ret
        .ENDIF
    .ENDIF    


    ;-------------------------------------------------------------------------------------
    ; User provided three parameters for us to check
    ;-------------------------------------------------------------------------------------
    ; 1st param of 3
    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CONSOLE_ERROR
        ret

    .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
        Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
        .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2
            mov eax, CONSOLE_HELP ; user specified /? -? or --? as first switch, ignore other parameters
            ret
            
        .ELSEIF eax == SWITCH_E || eax == SWITCH_E_ALT ; user provided /e and another param which is illegal
            mov eax, CONSOLE_E_WITH_PARAM
            ret
            
        .ELSEIF eax == SWITCH_D || eax == SWITCH_D_ALT ; user specified /d with a param - which is good
            ; continue to check next paramter: 2 of 3
            
        .ELSE
            mov eax, CONSOLE_UNKNOWN_SWITCH
            ret
        .ENDIF

    .ELSE
        mov eax, CONSOLE_ERROR
        ret
        
    .ENDIF
    
    
    ; Get 2nd param of 3
    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CONSOLE_ERROR
        ret
    .ENDIF
    
    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 2, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CONSOLE_ERROR
        ret

    .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH ; user specified /d and a switch which is illegal
        mov eax, CONSOLE_D_PARAM_INVALID
        ret

    .ELSE
        ; we assume this parameter is something we need for the /d something, so get it and store it in D_ParamBuffer
        Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr D_ParamBuffer
        ; continue to 3rd param

    .ENDIF

    ; Get 3rd param
    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 3, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CONSOLE_ERROR
        ret
    .ENDIF
    
    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 3, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CONSOLE_ERROR
        ret

    .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
        Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
        .IF eax == SWITCH_E
            mov eax, CONSOLE_D_PARAM_E ; /d something /e specified, which is all good
            ret
            
        .ELSE
            mov eax, CONSOLE_D_PARAM_E_INVALID ; /d something and some other switch specified, which is illegal
            ret
            
        .ENDIF
    
    .ELSE
        mov eax, CONSOLE_D_PARAM_E_UNKNOWN ; /d something and something else other than /e specified, which is illegal
        ret
        
    .ENDIF    
    
    ret
conlcfProcessCmdLine ENDP


;-----------------------------------------------------------------------------------------
; Register switches for use on command line
;-----------------------------------------------------------------------------------------
conlcfRegisterSwitches PROC
    Invoke ConsoleSwitchRegister, CTEXT("/?"), SWITCH_HELP
    Invoke ConsoleSwitchRegister, CTEXT("-?"), SWITCH_HELP_UNIX
    Invoke ConsoleSwitchRegister, CTEXT("--?"), SWITCH_HELP_UNIX2
    Invoke ConsoleSwitchRegister, CTEXT("-D"), SWITCH_D
    Invoke ConsoleSwitchRegister, CTEXT("/D"), SWITCH_D_ALT
    Invoke ConsoleSwitchRegister, CTEXT("-E"), SWITCH_E
    Invoke ConsoleSwitchRegister, CTEXT("/E"), SWITCH_E_ALT
    ret
conlcfRegisterSwitches ENDP


;-----------------------------------------------------------------------------------------
; Register commands for use on command line
;-----------------------------------------------------------------------------------------
conlcfRegisterCommands PROC
    ret
conlcfRegisterCommands ENDP


;-----------------------------------------------------------------------------------------
; Prints out console information
;-----------------------------------------------------------------------------------------
conlcfConInfo PROC dwMsgType:DWORD
    mov eax, dwMsgType
    .IF eax == CON_OUT_INFO
        Invoke ConsoleStdOut, Addr szconlcfConInfo
    .ELSEIF eax == CON_OUT_ABOUT
        Invoke ConsoleStdOut, Addr szconlcfConAbout
    .ELSEIF eax == CON_OUT_USAGE
        Invoke ConsoleStdOut, Addr szconlcfConHelpUsage
    .ELSEIF eax == CON_OUT_HELP
        Invoke ConsoleStdOut, Addr szconlcfConHelp
    .ENDIF
    ret
conlcfConInfo ENDP


;-----------------------------------------------------------------------------------------
; Prints out error information to console
;-----------------------------------------------------------------------------------------
conlcfConErr PROC dwErrorType:DWORD
    mov eax, dwErrorType
    .IF eax == CONSOLE_UNKNOWN_SWITCH || eax == CONSOLE_UNKNOWN_COMMAND
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr CmdLineParameter
        Invoke ConsoleStdOut, Addr szSingleQuote
        mov eax, dwErrorType
        .IF eax == CONSOLE_UNKNOWN_SWITCH
            Invoke ConsoleStdOut, Addr szErrorUnknownSwitch
        .ELSEIF eax == CONSOLE_UNKNOWN_COMMAND
            Invoke ConsoleStdOut, Addr szErrorUnknownCommand
        .ENDIF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE
    
    .ELSEIF eax == CONSOLE_D_WITHOUT_PARAM
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorDswitchOnly
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE

    .ELSEIF eax == CONSOLE_D_PARAM_INVALID
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorDswitchXSwitch
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE
        
    .ELSEIF eax == CONSOLE_D_PARAM_E_INVALID
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorDEInvalid
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE

    .ELSEIF eax == CONSOLE_D_PARAM_E_UNKNOWN
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorDEUnknown
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE
 
    .ELSEIF eax == CONSOLE_E_WITH_PARAM
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorEparameter
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke conlcfConInfo, CON_OUT_USAGE

    .ELSEIF eax == CONSOLE_ERROR
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorOther
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF

    .ENDIF
    ret
conlcfConErr ENDP





END Main







