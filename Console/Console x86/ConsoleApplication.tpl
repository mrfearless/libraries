Console App
ConsoleTemplate
Console Application
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
1=4,O,$B\RC.EXE /v,1
2=3,O,$B\ML.EXE /c /coff /Cp /nologo /I"$I",2
3=5,O,$B\LINK.EXE /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /LIBPATH:"$L" /OUT:"$5",3,4
4=0,0,,5
5=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
6=*.obj,O,$B\ML.EXE /c /coff /Cp /nologo /I"$I",*.asm
7=0,0,"$E\x32dbg.exe",5
11=4,O,$B\RC.EXE /v,1
12=3,O,$B\ML.EXE /c /coff /Cp /Zi /Zd /nologo /I"$I",2
13=5,O,$B\LINK.EXE /SUBSYSTEM:CONSOLE /DEBUG /DEBUGTYPE:CV /PDB:"$18" /VERSION:4.0 /LIBPATH:"$L" /OUT:"$5",3,4
14=0,0,,5
15=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
16=*.obj,O,$B\ML.EXE /c /coff /Cp /Zi /Zd /nologo /I"$I",*.asm
17=0,0,"$E\x32dbg.exe",5
[MakeFiles]
0=ConsoleTemplate.rap
1=ConsoleTemplate.rc
2=ConsoleTemplate.asm
3=ConsoleTemplate.obj
4=ConsoleTemplate.res
5=ConsoleTemplate.exe
6=ConsoleTemplate.def
7=ConsoleTemplate.dll
8=ConsoleTemplate.txt
9=ConsoleTemplate.lib
10=ConsoleTemplate.mak
11=ConsoleTemplate.hla
12=ConsoleTemplate.com
13=ConsoleTemplate.ocx
14=ConsoleTemplate.idl
15=ConsoleTemplate.tlb
16=ConsoleTemplate.sys
17=ConsoleTemplate.dp32
18=ConsoleTemplate.pdb
19=ConsoleTemplate.dp64
[Resource]
1=,1,8,ConsoleTemplate.xml
2=,100,2,ConsoleTemplate.ico
[StringTable]
[Accel]
[VerInf]
Nme=VERINF1
ID=1
FV=1.0.0.0
PV=1.0.0.0
VerOS=0x00000004
VerFT=0x00000001
VerLNG=0x00000409
VerCHS=0x000004B0
ProductVersion=1.0.0.0
ProductName=ConsoleTemplate
OriginalFilename=ConsoleTemplate
LegalTrademarks=(C) 2017 fearless - www.LetTheLightIn.in
LegalCopyright=(C) 2017 fearless - www.LetTheLightIn.in
InternalName=ConsoleTemplate
FileDescription=ConsoleTemplate
FileVersion=1.0.0.0
CompanyName=fearless
[Group]
Group=Assembly,Resources,Misc
1=1
2=1
3=2
[*ENDDEF*]
[*BEGINTXT*]
ConsoleTemplate.asm
.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    Includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    Include M:\Masm32\include\debug32.inc
ENDIF


Include [*PROJECTNAME*].inc


.CODE

Main PROC

    Invoke ConsoleStarted
    .IF eax == TRUE ; Started From Console

        Invoke ConsoleAttach
        Invoke ConsoleSetIcon, ICO_MAIN
        Invoke ConsoleGetTitle, Addr szConTitle, SIZEOF szConTitle
        Invoke ConsoleSetTitle, Addr TitleName
        Invoke [*PROJECTNAME*]ConInfo, CON_OUT_INFO
        
        ; Start main console processing
        Invoke [*PROJECTNAME*]Main
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
        Invoke [*PROJECTNAME*]ConInfo, CON_OUT_INFO
        Invoke [*PROJECTNAME*]ConInfo, CON_OUT_ABOUT
        ;Invoke [*PROJECTNAME*]ConInfo, CON_OUT_USAGE
        Invoke ConsolePause, CON_PAUSE_ANY_KEY_EXIT
        Invoke ConsoleSetIcon, ICO_CMD
        Invoke ConsoleFree
        
    .ENDIF
    
    Invoke  ExitProcess,0
    ret
Main ENDP


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]Main
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]Main PROC

    Invoke [*PROJECTNAME*]RegisterSwitches
    Invoke [*PROJECTNAME*]RegisterCommands    
    Invoke [*PROJECTNAME*]ProcessCmdLine

    ;---------------------------------------------------------------------------------
    ; HELP: /? help switch or no switch
    ;---------------------------------------------------------------------------------
    .IF eax == CMDLINE_NOTHING || eax == CMDLINE_HELP ; no switch provided or /?

        Invoke [*PROJECTNAME*]ConInfo, CON_OUT_HELP   

    ;---------------------------------------------------------------------------------
    ; CMDLINE_FILEIN
    ;---------------------------------------------------------------------------------
    .ELSEIF eax == CMDLINE_FILEIN

    
    ;---------------------------------------------------------------------------------
    ; CMDLINE_FILEIN_FILEOUT
    ;---------------------------------------------------------------------------------    
    .ELSEIF eax == CMDLINE_FILEIN_FILEOUT

    
    ;---------------------------------------------------------------------------------
    ; CMDLINE_FOLDER_FILESPEC
    ;---------------------------------------------------------------------------------    
    .ELSEIF eax == CMDLINE_FOLDER_FILESPEC

    
    ;---------------------------------------------------------------------------------
    ; CMDLINE_FILEIN_FILESPEC
    ;---------------------------------------------------------------------------------    
    .ELSEIF eax == CMDLINE_FILEIN_FILESPEC

    
    ;---------------------------------------------------------------------------------
    ; ERROR
    ;---------------------------------------------------------------------------------    
    .ELSE
    
        Invoke [*PROJECTNAME*]ConErr, eax
        
    .ENDIF
    
    ret
[*PROJECTNAME*]Main ENDP


;-----------------------------------------------------------------------------------------
; Process command line information
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ProcessCmdLine PROC
    LOCAL dwLenCmdLineParameter:DWORD
    LOCAL bFileIn:DWORD
    LOCAL bCommand:DWORD
    
    Invoke GetCommandLine
    Invoke ConsoleParseCmdLine, Addr CmdLineParameters
    mov TotalCmdLineParameters, eax ; will be at least 1 as param 0 is name of exe
    
   .IF TotalCmdLineParameters == 1 ; nothing extra specified
        mov eax, CMDLINE_NOTHING
        ret       
    .ENDIF       

    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 1, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
    .ENDIF
    
    .IF TotalCmdLineParameters == 2
        
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_ERROR'
            mov eax, CMDLINE_ERROR
            ret
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_UNKNOWN
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_UNKNOWN'
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_SWITCH'
            Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
            .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2 
                mov eax, CMDLINE_HELP
                ret
            .ELSE
                mov eax, CMDLINE_UNKNOWN_SWITCH
                ret
            .ENDIF
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_COMMAND
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_COMMAND'
            Invoke ConsoleCommandID, Addr CmdLineParameter, FALSE
            ;PrintDec eax
            .IF eax == -1 
                mov eax, CMDLINE_UNKNOWN_COMMAND
                ret
            .ELSE
                mov eax, CMDLINE_COMMAND_WITHOUT_FILEIN
                ret
            .ENDIF

        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_FILESPEC'
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            mov eax, CMDLINE_FILEIN_FILESPEC
            ret            
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILENAME
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_FILENAME'
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            Invoke exist, Addr sz[*PROJECTNAME*]InFilename
            .IF eax == TRUE ; does exist
                mov eax, CMDLINE_FILEIN
                ret
            .ELSE
                mov eax, CMDLINE_FILEIN_NOT_EXIST
                ret
            .ENDIF
                
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
            ;PrintText 'ConsoleCmdLineParamType CMDLINE_PARAM_TYPE_FOLDER'
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            Invoke exist, Addr sz[*PROJECTNAME*]InFilename
            .IF eax == TRUE ; does exist
                ; assume filespec of *.* in folder provided
                Invoke lstrcat, Addr sz[*PROJECTNAME*]InFilename, Addr szFolderAllFiles
                mov eax, CMDLINE_FOLDER_FILESPEC
                ret
            .ELSE
                mov eax, CMDLINE_FILEIN_NOT_EXIST
                ret
            .ENDIF
        .ENDIF
    .ENDIF
    
    ;-------------------------------------------------------------------------------------
    ; FILENAMEIN FILENAMEOUT or OPTION FILENAMEIN/FILESPECIN
    ;-------------------------------------------------------------------------------------    
    mov bFileIn, FALSE
    mov bCommand, FALSE
    .IF TotalCmdLineParameters == 3
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            mov eax, CMDLINE_ERROR
            ret    

        .ELSEIF eax == CMDLINE_PARAM_TYPE_UNKNOWN
        
        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
            Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
            .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2 
                mov eax, CMDLINE_HELP
                ret
            .ELSE
                mov eax, CMDLINE_UNKNOWN_SWITCH
                ret
            .ENDIF
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_COMMAND
            Invoke ConsoleCommandID, Addr CmdLineParameter, FALSE
            .IF eax == -1 
                mov eax, CMDLINE_UNKNOWN_COMMAND
                ret
            .ELSE
                ; check commands
            .ENDIF
            mov bCommand, TRUE
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILENAME
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            Invoke exist, Addr sz[*PROJECTNAME*]InFilename
            .IF eax == TRUE ; does exist
                ;mov bFileIn, TRUE
                ;mov eax, CMDLINE_FILEIN
                ;ret
            .ELSE
                mov eax, CMDLINE_FILEIN_NOT_EXIST
                ret
            .ENDIF            
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            Invoke exist, Addr sz[*PROJECTNAME*]InFilename
            .IF eax == TRUE ; does exist
                ; assume filespec of *.* in folder provided
                Invoke lstrcat, Addr sz[*PROJECTNAME*]InFilename, Addr szFolderAllFiles
            .ELSE
                mov eax, CMDLINE_FILEIN_NOT_EXIST
                ret
            .ENDIF            
            
        .ENDIF
        
        ; Get 2nd param
        Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr CmdLineParameter
        .IF sdword ptr eax > 0
            mov dwLenCmdLineParameter, eax
        .ELSE
            mov eax, CMDLINE_ERROR
            ret
        .ENDIF
        
        Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 2, TotalCmdLineParameters
        .IF eax == CMDLINE_PARAM_TYPE_ERROR
            mov eax, CMDLINE_ERROR
            ret
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_UNKNOWN
        
        .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
            Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
            .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2 
                mov eax, CMDLINE_HELP
                ret
            .ELSE
                mov eax, CMDLINE_UNKNOWN_SWITCH
                ret
            .ENDIF
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_COMMAND ; user specified filename/filespec/folder first then command?
            Invoke ConsoleCommandID, Addr CmdLineParameter, FALSE
            .IF eax == -1 
                mov eax, CMDLINE_UNKNOWN_COMMAND
                ret
            .ELSE
                ; check commands
            .ENDIF

        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
            Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
            .IF bCommand == TRUE
                mov eax, CMDLINE_FILEIN_FILESPEC
                ret
            .ELSE
                mov eax, CMDLINE_FILESPEC_NOT_SUPPORTED
                ret
            .ENDIF
            
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FILENAME
            .IF bCommand == TRUE
                Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
                Invoke exist, Addr sz[*PROJECTNAME*]InFilename
                .IF eax == TRUE ; does exist
                    mov eax, CMDLINE_FILEIN
                    ret
                .ELSE
                    mov eax, CMDLINE_FILEIN_NOT_EXIST
                    ret
                .ENDIF
            .ELSE
                Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]OutFilename
                Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
                .IF eax == CMDLINE_PARAM_TYPE_FILENAME
                    mov eax, CMDLINE_FILEIN_FILEOUT
                    ret
                .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
                    mov eax, CMDLINE_FILESPEC_NOT_SUPPORTED
                    ret
                .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
                    mov eax, CMDLINE_FOLDER_NOT_SUPPORTED
                    ret
                .ELSE
                    mov eax, CMDLINE_ERROR
                    ret
                .ENDIF
            .ENDIF
       
        .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
            .IF bCommand == TRUE
                Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
                Invoke exist, Addr sz[*PROJECTNAME*]InFilename
                .IF eax == TRUE ; does exist
                    ; assume filespec of *.* in folder provided
                    Invoke lstrcat, Addr sz[*PROJECTNAME*]InFilename, Addr szFolderAllFiles
                    mov eax, CMDLINE_FOLDER_FILESPEC
                    ret
                .ELSE
                    mov eax, CMDLINE_FILEIN_NOT_EXIST
                    ret
                .ENDIF        
            .ELSE
                mov eax, CMDLINE_FILESPEC_NOT_SUPPORTED
                ret
            .ENDIF
        .ENDIF
    .ENDIF    


    ;-------------------------------------------------------------------------------------
    ; OPTION FILENAMEIN FILENAMEOUT
    ;-------------------------------------------------------------------------------------

    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 1, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CMDLINE_ERROR
        ret

    .ELSEIF eax == CMDLINE_PARAM_TYPE_SWITCH
        Invoke ConsoleSwitchID, Addr CmdLineParameter, FALSE
        .IF eax == SWITCH_HELP || eax == SWITCH_HELP_UNIX || eax == SWITCH_HELP_UNIX2 
            mov eax, CMDLINE_HELP
            ret
        .ELSE
            mov eax, CMDLINE_UNKNOWN_SWITCH
            ret
        .ENDIF    

    .ELSEIF eax == CMDLINE_PARAM_TYPE_COMMAND
        Invoke ConsoleCommandID, Addr CmdLineParameter, FALSE
        .IF eax == -1 
            mov eax, CMDLINE_UNKNOWN_COMMAND
            ret
        .ELSE
            ; check commands
        .ENDIF
        mov bCommand, TRUE
    
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
    .ENDIF
    
    ; Get 2nd param
    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 2, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
    .ENDIF
    
    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 2, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CMDLINE_ERROR
        ret

    .ELSEIF eax == CMDLINE_PARAM_TYPE_FILENAME
        Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]InFilename
        Invoke exist, Addr sz[*PROJECTNAME*]InFilename
        .IF eax == TRUE ; does exist
        .ELSE
            mov eax, CMDLINE_FILEIN_NOT_EXIST
            ret
        .ENDIF

    .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
        mov eax, CMDLINE_FILESPEC_NOT_SUPPORTED
        ret
    
    .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
        mov eax, CMDLINE_FOLDER_NOT_SUPPORTED
        ret
    
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
        
    .ENDIF

    ; Get 3rd param
    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 3, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sdword ptr eax > 0
        mov dwLenCmdLineParameter, eax
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
    .ENDIF
    
    Invoke ConsoleCmdLineParamType, Addr CmdLineParameters, 3, TotalCmdLineParameters
    .IF eax == CMDLINE_PARAM_TYPE_ERROR
        mov eax, CMDLINE_ERROR
        ret
    
    .ELSEIF eax == CMDLINE_PARAM_TYPE_FILENAME
        Invoke szCopy, Addr CmdLineParameter, Addr sz[*PROJECTNAME*]OutFilename
        mov eax, CMDLINE_FILEIN_FILEOUT
        ret
        
    .ELSEIF eax == CMDLINE_PARAM_TYPE_FILESPEC
        mov eax, CMDLINE_FILESPEC_NOT_SUPPORTED
        ret
    
    .ELSEIF eax == CMDLINE_PARAM_TYPE_FOLDER
        mov eax, CMDLINE_FOLDER_NOT_SUPPORTED
        ret
    
    .ELSE
        mov eax, CMDLINE_ERROR
        ret
        
    .ENDIF    
    
    ret
[*PROJECTNAME*]ProcessCmdLine ENDP


;-----------------------------------------------------------------------------------------
; Register switches for use on command line
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]RegisterSwitches PROC
    Invoke ConsoleSwitchRegister, CTEXT("/?"), SWITCH_HELP
    Invoke ConsoleSwitchRegister, CTEXT("-?"), SWITCH_HELP_UNIX
    Invoke ConsoleSwitchRegister, CTEXT("--?"), SWITCH_HELP_UNIX2
    ret
[*PROJECTNAME*]RegisterSwitches ENDP


;-----------------------------------------------------------------------------------------
; Register commands for use on command line
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]RegisterCommands PROC
    ;Invoke ConsoleCommandRegister, CTEXT("c"), COMMAND_COMPRESS
    ;Invoke ConsoleCommandRegister, CTEXT("d"), COMMAND_DECOMPRESS
    ret
[*PROJECTNAME*]RegisterCommands ENDP


;-----------------------------------------------------------------------------------------
; Prints out console information
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConInfo PROC dwMsgType:DWORD
    mov eax, dwMsgType
    .IF eax == CON_OUT_INFO
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]ConInfo
    .ELSEIF eax == CON_OUT_ABOUT
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]ConAbout
    .ELSEIF eax == CON_OUT_USAGE
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]ConHelpUsage
    .ELSEIF eax == CON_OUT_HELP
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]ConHelp
    .ENDIF
    ret
[*PROJECTNAME*]ConInfo ENDP


;-----------------------------------------------------------------------------------------
; Prints out error information to console
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConErr PROC dwErrorType:DWORD
    mov eax, dwErrorType
    .IF eax == CMDLINE_UNKNOWN_SWITCH || eax == CMDLINE_UNKNOWN_COMMAND || eax == CMDLINE_COMMAND_WITHOUT_FILEIN
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr CmdLineParameter
        Invoke ConsoleStdOut, Addr szSingleQuote
        mov eax, dwErrorType
        .IF eax == CMDLINE_UNKNOWN_SWITCH
            Invoke ConsoleStdOut, Addr szErrorUnknownSwitch
        .ELSEIF eax == CMDLINE_UNKNOWN_COMMAND
            Invoke ConsoleStdOut, Addr szErrorUnknownCommand
        .ELSEIF eax == CMDLINE_COMMAND_WITHOUT_FILEIN
            Invoke ConsoleStdOut, Addr szErrorCommandWithoutFile
        .ENDIF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke [*PROJECTNAME*]ConInfo, CON_OUT_USAGE
        
    .ELSEIF eax == CMDLINE_FILEIN_NOT_EXIST
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]InFilename
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr szErrorFilenameNotExist
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        
    .ELSEIF eax == CMDLINE_ERROR
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorOther
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
    
    .ELSEIF eax == ERROR_FILEIN_IS_EMPTY
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]InFilename
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr szErrorFileZeroBytes
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        
    .ELSEIF eax == ERROR_OPENING_FILEIN
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]InFilename
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr szErrorOpeningInFile
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
            
    .ELSEIF eax == ERROR_CREATING_FILEOUT
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr sz[*PROJECTNAME*]OutFilename
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr szErrorCreatingOutFile
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
    
    .ELSEIF eax == ERROR_ALLOC_MEMORY
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szErrorAllocMemory
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
    .ENDIF
    ret
[*PROJECTNAME*]ConErr ENDP


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]FileInOpen - Open file to process
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]FileInOpen PROC lpszFilename:DWORD

    .IF lpszFilename == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    ; Tell user we are loading file
    mov hFileIn, NULL
    mov hMemMapIn, NULL
    mov hMemMapInPtr, NULL
    mov DWORD ptr qwFileSize+4, 0
    mov DWORD ptr qwFileSize, 0    
    mov dwFileSize, 0
    mov dwFileSizeHigh, 0

    Invoke CreateFile, lpszFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    .IF eax == INVALID_HANDLE_VALUE
        ; Tell user that file did not load
        mov eax, FALSE
        ret
    .ENDIF
    mov hFileIn, eax

    Invoke CreateFileMapping, hFileIn, NULL, PAGE_READONLY, 0, 0, NULL ; Create memory mapped file
    .IF eax == NULL
        ; Tell user that file did not map
        Invoke CloseHandle, hFileIn
        mov eax, FALSE
        ret
    .ENDIF
    mov hMemMapIn, eax

    Invoke MapViewOfFileEx, hMemMapIn, FILE_MAP_READ, 0, 0, 0, NULL
    .IF eax == NULL
        ; Tell user that file did not mapview
        Invoke CloseHandle, hMemMapIn
        Invoke CloseHandle, hFileIn
        mov eax, FALSE
        ret
    .ENDIF
    mov hMemMapInPtr, eax  
    
    Invoke GetFileSizeEx, hFileIn, Addr qwFileSize
    mov	eax, DWORD ptr qwFileSize
    mov dwFileSize, eax
	mov	eax, DWORD ptr qwFileSize+4
	mov dwFileSizeHigh, eax
	
    mov eax, TRUE
    
    ret

[*PROJECTNAME*]FileInOpen ENDP


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]FileInClose - Closes currently opened file
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]FileInClose PROC

    .IF hMemMapInPtr != NULL
        Invoke UnmapViewOfFile, hMemMapInPtr
        mov hMemMapInPtr, NULL
    .ENDIF
    .IF hMemMapIn != NULL
        Invoke CloseHandle, hMemMapIn
        mov hMemMapIn, NULL
    .ENDIF
    .IF hFileIn != NULL
        Invoke CloseHandle, hFileIn
        mov hFileIn, NULL
    .ENDIF
    
    mov DWORD ptr qwFileSize+4, 0
    mov DWORD ptr qwFileSize, 0
    mov dwFileSize, 0
    mov dwFileSizeHigh, 0

    ret
[*PROJECTNAME*]FileInClose ENDP


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]FileOutOpen - Create out file
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]FileOutOpen PROC lpszFilename:DWORD

    .IF lpszFilename == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    ; Tell user we are loading file
    mov hFileOut, NULL
    mov hMemMapOut, NULL
    mov hMemMapOutPtr, NULL

    Invoke CreateFile, lpszFilename, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE + FILE_SHARE_DELETE, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL
    .IF eax == INVALID_HANDLE_VALUE
        ; Tell user that file did not load
        mov eax, FALSE
        ret
    .ENDIF
    mov hFileOut, eax

    mov eax, TRUE
    
    ret

[*PROJECTNAME*]FileOutOpen ENDP


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]FileOutClose - Closes output file
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]FileOutClose PROC
    .IF hFileOut != NULL
        Invoke CloseHandle, hFileOut
        mov hFileOut, NULL
    .ENDIF
    ret
[*PROJECTNAME*]FileOutClose ENDP



;**************************************************************************
; Strip path name to just filename with extention
;**************************************************************************
JustFnameExt PROC USES ESI EDI szFilePathName:DWORD, szFileName:DWORD
	LOCAL LenFilePathName:DWORD
	LOCAL nPosition:DWORD
	
	Invoke szLen, szFilePathName
	mov LenFilePathName, eax
	mov nPosition, eax
	
	.IF LenFilePathName == 0
	    mov edi, szFileName
		mov byte ptr [edi], 0
		mov eax, FALSE
		ret
	.ENDIF
	
	mov esi, szFilePathName
	add esi, eax
	
	mov eax, nPosition
	.WHILE eax != 0
		movzx eax, byte ptr [esi]
		.IF al == '\' || al == ':' || al == '/'
			inc esi
			.BREAK
		.ENDIF
		dec esi
		dec nPosition
		mov eax, nPosition
	.ENDW
	mov edi, szFileName
	mov eax, nPosition
	.WHILE eax != LenFilePathName
		movzx eax, byte ptr [esi]
		mov byte ptr [edi], al
		inc edi
		inc esi
		inc nPosition
		mov eax, nPosition
	.ENDW
	mov byte ptr [edi], 0h ; null out filename
	mov eax, TRUE
	ret

JustFnameExt ENDP



END Main







[*ENDTXT*]
[*BEGINTXT*]
ConsoleTemplate.inc
include windows.inc
include user32.inc
include kernel32.inc
include shell32.inc
include masm32.inc
includelib user32.lib
includelib kernel32.lib
includelib shell32.lib
includelib masm32.lib

include Console.inc
includelib Console.lib


;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Prototypes
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]Main             PROTO
[*PROJECTNAME*]RegisterSwitches PROTO
[*PROJECTNAME*]RegisterCommands PROTO
[*PROJECTNAME*]ProcessCmdLine   PROTO

[*PROJECTNAME*]ConInfo          PROTO :DWORD
[*PROJECTNAME*]ConErr           PROTO :DWORD

[*PROJECTNAME*]FileInOpen       PROTO :DWORD
[*PROJECTNAME*]FileInClose      PROTO
[*PROJECTNAME*]FileOutOpen      PROTO :DWORD
[*PROJECTNAME*]FileOutClose     PROTO


JustFnameExt                    PROTO :DWORD, :DWORD
IFNDEF GetCommandLineA
GetCommandLineA                 PROTO 
GetCommandLine                  EQU <GetCommandLineA>
ENDIF


.CONST
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Constants
;-----------------------------------------------------------------------------------------
ICO_MAIN                        EQU 100
ICO_CMD                         EQU 101

; [*PROJECTNAME*]ConInfo dwMsgType:
CON_OUT_INFO                    EQU 0   ; Header information
CON_OUT_ABOUT                   EQU 1   ; About information
CON_OUT_USAGE                   EQU 2   ; Usage information: switches/commands and params
CON_OUT_HELP                    EQU 3   ; Help information

; Constants for [*PROJECTNAME*]ProcessCmdLine
; return values and for [*PROJECTNAME*]ConErr
; dwErrorType:
ERROR_WRITING_DECOMPRESS_DATA   EQU -15 ; Writefile failed with writing data out
ERROR_WRITING_COMPRESS_DATA     EQU -14 ; Writefile failed with writing data out
ERROR_ALLOC_MEMORY              EQU -13 ; GlobalAlloc failed for some reason
ERROR_CREATING_FILEOUT          EQU -12 ; Couldnt create temporary output file
ERROR_OPENING_FILEIN            EQU -11 ; Couldnt open input filename
ERROR_FILEIN_IS_EMPTY           EQU -10 ; 0 byte file
CMDLINE_COMMAND_WITHOUT_FILEIN  EQU -8  ; User forgot to supply a filename or filespec or folder with command
CMDLINE_FOLDER_NOT_SUPPORTED    EQU -6  ; A folder (assumes <foldername>\*.* filespec) provided whilst supplying output filename
CMDLINE_FILESPEC_NOT_SUPPORTED  EQU -5  ; Using *.* etc wildcards whilst supplying output filename
CMDLINE_FILEIN_NOT_EXIST        EQU -4  ; Filename or filepath provided does not exist
CMDLINE_ERROR                   EQU -3  ; General error reading parameters
CMDLINE_UNKNOWN_COMMAND         EQU -2  ; User provided a <X> command that wasnt recognised
CMDLINE_UNKNOWN_SWITCH          EQU -1  ; User provided a /<X> or -<X> switch that wasnt recognised
CMDLINE_NOTHING                 EQU 0   ;
CMDLINE_HELP                    EQU 1   ; User specified /? -? --? as a parameter
CMDLINE_FILEIN                  EQU 2   ; A single filename was specified
CMDLINE_FILEIN_FILESPEC         EQU 3   ; A filespec (*.*, *.txt) was specified
CMDLINE_FILEIN_FILEOUT          EQU 4   ; A filename for input and a filename for output was specified
CMDLINE_FOLDER_FILESPEC         EQU 5   ; A folder was specified (assumes <foldername>\*.* filespec)

; [*PROJECTNAME*] Switch IDs: /? -? --?
SWITCH_HELP                     EQU 0   ; /? help switch
SWITCH_HELP_UNIX                EQU 1   ; -? help switch
SWITCH_HELP_UNIX2               EQU 2   ; --? help switch

; [*PROJECTNAME*] Command IDs: c d 
;COMMAND_COMPRESS                EQU 0   ; c - set [*PROJECTNAME*] mode to compress
;COMMAND_DECOMPRESS              EQU 1   ; d - set [*PROJECTNAME*] mode to decompress


.DATA
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Initialized Data
;-----------------------------------------------------------------------------------------
AppName                         DB '[*PROJECTNAME*]',0
TitleName                       DB '[*PROJECTNAME*] Tool v1.0.0.0',0
szConTitle                      DB MAX_PATH DUP (0)
CmdLineParameters               DB 512 DUP (0)
CmdLineParameter                DB 256 DUP (0)
ErrParameter                    DB 256 DUP (0)
TotalCmdLineParameters          DD 0

; Help
sz[*PROJECTNAME*]ConInfo        DB 13,10,"[[*PROJECTNAME*]] v1.00 - [*PROJECTNAME*] Tool - Copyright (C) 2017 fearless",13,10,13,10,0

sz[*PROJECTNAME*]ConAbout       DB "About:",13,10
                                DB "========",13,10
                                DB "[*PROJECTNAME*] is a console program which needs to be ran from a command prompt.",13,10
                                DB "For detailed help on the [*PROJECTNAME*] options, specify [*PROJECTNAME*] /? at the prompt.",13,10
                                DB 13,10,13,10
                                DB "Credits:",13,10
                                DB "========",13,10
                                DB "[*PROJECTNAME*] is designed and programmed by fearless (C) Copyright 2017",13,10
                                DB "Written using Microsoft Macro Assembler, Steve Hutch MASM32 libraries and",13,10
                                DB "Zlib library Copyright (C) 1995-2010 Jean-loup Gailly and Mark Adler. ",13,10
                                DB 13,10,0

sz[*PROJECTNAME*]ConHelp        DB "Usage: [*PROJECTNAME*] [/?]",13,10
                                DB "               [path]infilename",13,10
                                DB "               [path]infilename [[path]outfilename]",13,10
                                DB 13,10
                                DB 13,10
                                DB "  /?           Displays this help",13,10
                                DB 13,10
                                DB "               [path]infilename is name of a valid file to uncompress",13,10
                                DB "               to a standard bif file. Supports the use of wildcards * and ? ",13,10
                                DB "               for batch operations. See note below for details on how files",13,10
                                DB "               are saved if you use this feature",13,10 
                                DB 13,10
                                DB "               [path]outfilename (optional) is name of the file to save the",13,10
                                DB "               uncompressed file to. Cannot use wildcards if this is used.",13,10 
                                DB 13,10
                                DB 13,10                        
                                DB "Note:          If outfilename is not specified, the output is to the original",13,10 
                                DB "               infilename provided, overwritting the original file data.",13,10
                                DB 13,10
                                DB "               If you wish to prevent accidentally overwritting files, specify",13,10
                                DB "               both infilename and outfilename.",13,10 
                                DB 13,10
                                DB 13,10
                                DB 13,10,0

sz[*PROJECTNAME*]ConHelpUsage   DB "Usage: [*PROJECTNAME*] [/?]",13,10
                                DB "               [path]infilename",13,10
                                DB "               [path]infilename [[path]outfilename]",13,10
                                DB 13,10,0


; Error message
szError                         DB "[!] Error: ",0
szErrorUnknownSwitch            DB " invalid switch specified.",0
szErrorUnknownCommand           DB " invalid command specified.",0
szErrorCommandWithoutFile       DB " command specified but no filename or filespec provided.",0
szErrorFileSpecNotSupported     DB " wildcard filespec not supported for input file(s) when also specifying output filename as well.",0
szErrorFilenameNotExist         DB " filename/filepath does not exist.",0
szErrorOther                    DB "unknown error occured whilst parsing parameters and switches.",0
szErrorFolderNotSupported       DB " folder (assumes *.*) not supported for input file(s) when also specifying output filename as well.",0
szErrorFileZeroBytes            DB " file 0 bytes, skipping.",0
szErrorOpeningInFile            DB " failed to open input file.",0
szErrorCreatingOutFile          DB " failed to create output file.",0
szErrorAllocMemory              DB "failed to allocate memory for operation.",0


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

SwitchHelp                      DB '/?',0
SwitchHelpAlt                   DB '-?',0
SwitchHelpAlt2                  DB '--?',0

; Filename Buffers
sz[*PROJECTNAME*]SelfFilename   DB MAX_PATH DUP (0)
sz[*PROJECTNAME*]SelfFilepath   DB MAX_PATH DUP (0)
sz[*PROJECTNAME*]InFilename     DB MAX_PATH DUP (0)
sz[*PROJECTNAME*]OutFilename    DB MAX_PATH DUP (0)


.DATA?
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Uninitialized Data
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



















[*ENDTXT*]
[*BEGINTXT*]
ConsoleTemplate.rc
#include "Res/ConsoleTemplateVer.rc"
#include "Res/ConsoleTemplateRes.rc"
[*ENDTXT*]
[*ENDPRO*]
[*BEGINTXT*]
Res\[*PROJECTNAME*]Res.Rc
#define MANIFEST 						24
1						MANIFEST  DISCARDABLE "[*PROJECTNAME*].xml"
100						ICON      DISCARDABLE "[*PROJECTNAME*].ico"
[*ENDTXT*]
[*BEGINBIN*]
[*PROJECTNAME*].ico
0000010001002020040000000000E80200001600000028000000200000004000
0000010004000000000000020000000000000000000000000000000000000000
000000008000008000000080800080000000800080008080000080808000C0C0
C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
0000000000000000000000000000000000000000000000000000000700000000
0000000000000000000000111100000000000000000000000000011111100000
0000000000000000000011911117000000000000000000000001199991110000
0000000000000000001199999911000000000000000000000119999999100000
0000000000000000119999999100000000000000000000011999999910000000
0000000000000011999999910000000000000000000001199999991000000000
0000000000001199999991000000000000000000000119999999100000000000
0000000000119999999100000000000867000000011999999910000000000088
707000001199999991000000000008FF8770000719999999100000000000778F
F8780001999999910000000000007778FF877771999999100000000000000777
8FF8777719999100000000000000007778FF8887119910000000000000000000
778FFF887777000000000000000000007788FFF8877700000000000000000000
07788FFF887777000000000000000000087788FFF87777777000000000000000
0077788FFF8778877000000000000000000877888FFF87777000000000000000
000087778888FF88700000000000000000000087778888880000000000000000
000000000777700000000000000000000000000000000000000000000000FFFF
FFFFFFFFFFEFFFFFFFC3FFFFFF81FFFFFF00FFFFFE00FFFFFC00FFFFF801FFFF
F003FFFFE007FFFFC00FFFFF801FFFFF003FFFFE007FFFFC00FFE3F801FFC1F0
03FF81E007FF00E00FFF00001FFF80003FFFC0007FFFF000FFFFF000FFFFF800
3FFFF80007FFFC0007FFFE0007FFFF0007FFFFC00FFFFFF87FFFFFFFFFFF
[*ENDBIN*]
[*BEGINTXT*]
[*PROJECTNAME*].xml
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly
    xmlns="urn:schemas-microsoft-com:asm.v1"
    manifestVersion="1.0">
    <assemblyIdentity
        version="1.0.0.0"
        processorArchitecture="X86"
        name="Company.Product.Application"
        type="Win32"
    />
    <description>[*PROJECTNAME*]</description>
    <dependency>
        <dependentAssembly>
            <assemblyIdentity
                type="win32"
                name="Microsoft.Windows.Common-Controls"
                version="6.0.0.0"
                processorArchitecture="X86"
                publicKeyToken="6595b64144ccf1df"
                language="*"
            />
        </dependentAssembly>
    </dependency>
</assembly>
[*ENDTXT*]
[*BEGINTXT*]
Res\[*PROJECTNAME*]Ver.rc
#define VERINF1 1
VERINF1 VERSIONINFO
FILEVERSION 1,0,0,0
PRODUCTVERSION 1,0,0,0
FILEOS 0x00000004
FILETYPE 0x00000001
BEGIN
  BLOCK "StringFileInfo"
  BEGIN
    BLOCK "040904B0"
    BEGIN
      VALUE "FileVersion", "1.0.0.0\0"
      VALUE "FileDescription", "[*PROJECTNAME*]\0"
      VALUE "InternalName", "[*PROJECTNAME*]\0"
      VALUE "OriginalFilename", "[*PROJECTNAME*]\0"
      VALUE "ProductName", "[*PROJECTNAME*]\0"
      VALUE "ProductVersion", "1.0.0.0\0"
    END
  END
  BLOCK "VarFileInfo"
  BEGIN
    VALUE "Translation", 0x0409, 0x04B0
  END
END
[*ENDTXT*]
