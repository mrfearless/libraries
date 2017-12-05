Console App
ConsoleTemplate
Console x64 Application
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0
1=4,O,$B\RC.EXE /v,1
2=3,O,$B\UASM64.exe /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /W2 /I"$I",2
3=5,O,$B\LINK.EXE /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /MACHINE:X64 /LIBPATH:"$L" /OUT:"$5",3,4
4=0,0,,5
5=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
6=*.obj,O,$B\UASM64.EXE /c -win64 -Zp8 /win64 /D_WIN64 /Cp /nologo /W2 /I"$I",*.asm
7=0,0,"$E\x64\x64dbg",5
11=4,O,$B\RC.EXE /v,1
12=3,O,$B\UASM64.EXE /c -win64 -Zp8 /Zi /win64 /D_WIN64 /Cp /nologo /W2 /Zi /Zd /nologo /I"$I",2
13=5,O,$B\LINK.EXE /SUBSYSTEM:CONSOLE /DEBUG /DEBUGTYPE:CV /PDB:"$18" /VERSION:4.0 /MACHINE:X64 /LIBPATH:"$L" /OUT:"$5",3,4
14=0,0,,5
15=rsrc.obj,O,$B\CVTRES.EXE,rsrc.res
16=*.obj,O,$B\UASM64.EXE /c /coff /Cp /Zi /Zd /nologo /I"$I",*.asm
17=0,0,"$E\x64\x64dbg",$.exe
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
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

include windows.inc
includelib kernel32.lib
includelib user32.lib

;DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \UASM\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
    include \UASM\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF


Include [*PROJECTNAME*].inc


.CODE

mainCRTStartup PROC FRAME
    Invoke ConsoleStarted
    .IF rax == TRUE ; Started From Console

        Invoke ConsoleAttach
        Invoke ConsoleSetIcon, ICO_MAIN
        Invoke ConsoleGetTitle, Addr szConTitle, SIZEOF szConTitle
        Invoke ConsoleSetTitle, Addr TitleName
        Invoke [*PROJECTNAME*]ConInfo
        
        ; Start main console processing
        Invoke [*PROJECTNAME*]Main
        ; Exit main console processing
        
        ;Invoke ConsolePause, CON_PAUSE_ANY_KEY_CONTINUE
        Invoke ConsoleSetTitle, Addr szConTitle
        Invoke ConsoleSetIcon, 0
        Invoke ConsoleShowCursor
        Invoke ConsoleFree

    .ELSE ; Started From Explorer
        
	    Invoke ConsoleAttach
        Invoke ConsoleSetIcon, ICO_MAIN
        Invoke ConsoleSetTitle, Addr TitleName 
        Invoke [*PROJECTNAME*]ConInfo
        Invoke [*PROJECTNAME*]ConAbout
        Invoke [*PROJECTNAME*]ConUsage
        Invoke ConsolePause, CON_PAUSE_ANY_KEY_EXIT
        
        Invoke ConsoleSetIcon, 0
        Invoke ConsoleFree
        
    .ENDIF
    
    Invoke  ExitProcess,0
    ret
mainCRTStartup endp


;-------------------------------------------------------------------------------------
; [*PROJECTNAME*]Main
;-------------------------------------------------------------------------------------
[*PROJECTNAME*]Main PROC FRAME
    
    Invoke [*PROJECTNAME*]ProcessCmdLine

    ;---------------------------------------------------------------------------------
    ; HELP: /? help switch or no switch
    ;---------------------------------------------------------------------------------
    .IF rax == CMDLINE_NOTHING || rax == CMDLINE_HELP ; no switch provided or /?

        Invoke [*PROJECTNAME*]ConHelp    

    ;---------------------------------------------------------------------------------
    ; ERROR: Invalid Switch / unrecognised parameter
    ;---------------------------------------------------------------------------------
    .ELSEIF rax == CMDLINE_NOT_RECOGNISED
        Invoke ConsoleStdOut, Addr szError
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr CmdLineParameter
        Invoke ConsoleStdOut, Addr szSingleQuote
        Invoke ConsoleStdOut, Addr szErrorNotRecognised
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke ConsoleStdOut, Addr szCRLF
        Invoke [*PROJECTNAME*]ConUsage
        
    .ENDIF
    
    ret
[*PROJECTNAME*]Main ENDP


;-----------------------------------------------------------------------------------------
; Process command line information
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ProcessCmdLine PROC FRAME
    LOCAL qwLenCmdLineParameter:QWORD
    
    Invoke GetCommandLine
    Invoke ConsoleParseCmdLine, Addr CmdLineParameters
    mov TotalCmdLineParameters, rax ; will be at least 1 as param 0 is name of exe
    
   .IF TotalCmdLineParameters == 1 ; nothing extra specified
        mov rax, CMDLINE_NOTHING
        ret       
    .ENDIF       

    Invoke ConsoleCmdLineParam, Addr CmdLineParameters, 1, TotalCmdLineParameters, Addr CmdLineParameter
    .IF sqword ptr rax > 0
        mov qwLenCmdLineParameter, rax
    .ELSE
        mov rax, CMDLINE_ERROR
        ret
    .ENDIF
    
    ;-------------------------------------------------------------------------------------
    ; /?
    ;-------------------------------------------------------------------------------------
    Invoke szCmpi, Addr CmdLineParameter, Addr SwitchHelp, qwLenCmdLineParameter
    .IF rax == 0 ; match for /?
        mov rax, CMDLINE_HELP
        ret
    .ENDIF

    ;-------------------------------------------------------------------------------------
    ; -?
    ;-------------------------------------------------------------------------------------
    Invoke szCmpi, Addr CmdLineParameter, Addr SwitchHelpAlt, qwLenCmdLineParameter
    .IF rax == 0 ; match for -?
        mov rax, CMDLINE_HELP
        ret
    .ENDIF

    ;-------------------------------------------------------------------------------------
    ; --?
    ;-------------------------------------------------------------------------------------
    Invoke szCmpi, Addr CmdLineParameter, Addr SwitchHelpAlt2, qwLenCmdLineParameter
    .IF rax == 0 ; match for --?
        mov rax, CMDLINE_HELP
        ret
    .ENDIF

    ;-------------------------------------------------------------------------------------
    ; 
    ;-------------------------------------------------------------------------------------




    ; else invalid switch or other option not correct
    mov rax, CMDLINE_NOT_RECOGNISED
    ret
[*PROJECTNAME*]ProcessCmdLine ENDP


;-----------------------------------------------------------------------------------------
; Prints out main header information about the ConsoleTemplate
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConInfo PROC FRAME
    Invoke ConsoleStdOut, Addr szConsoleTemplateConInfo
    ret
[*PROJECTNAME*]ConInfo ENDP


;-----------------------------------------------------------------------------------------
; Prints out main help information for ConsoleTemplate
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConHelp PROC FRAME
    Invoke ConsoleStdOut, Addr szConsoleTemplateConHelp
    ret
[*PROJECTNAME*]ConHelp ENDP


;-----------------------------------------------------------------------------------------
; Displays usage help only, to console
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConUsage PROC FRAME
    Invoke ConsoleStdOut, Addr szConsoleTemplateConHelpUsage
    ret
[*PROJECTNAME*]ConUsage ENDP


;-----------------------------------------------------------------------------------------
; Displays about info only, to console
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]ConAbout PROC FRAME
    Invoke ConsoleStdOut, Addr szConsoleTemplateConAbout
    ret
[*PROJECTNAME*]ConAbout ENDP




END mainCRTStartup







[*ENDTXT*]
[*BEGINTXT*]
ConsoleTemplate.inc
include windows.inc
include shellapi.inc
include masm64.inc
includelib user32.lib
includelib kernel32.lib
includelib shell32.lib
includelib masm64.lib

include Console.inc
includelib Console.lib


;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Prototypes
;-----------------------------------------------------------------------------------------
[*PROJECTNAME*]Main             PROTO
[*PROJECTNAME*]ProcessCmdLine   PROTO

[*PROJECTNAME*]ConInfo          PROTO
[*PROJECTNAME*]ConHelp          PROTO
[*PROJECTNAME*]ConUsage         PROTO
[*PROJECTNAME*]ConAbout         PROTO



IFNDEF GetCommandLineA
GetCommandLineA                 PROTO 
GetCommandLine                  EQU <GetCommandLineA>
ENDIF


.CONST
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Constants
;-----------------------------------------------------------------------------------------
ICO_MAIN                        EQU 100

CMDLINE_ERROR                   EQU -2
CMDLINE_NOT_RECOGNISED          EQU -1
CMDLINE_NOTHING                 EQU 0
CMDLINE_HELP                    EQU 1


.DATA
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Initialized Data
;-----------------------------------------------------------------------------------------
AppName                         DB '[*PROJECTNAME*] x64',0
TitleName                       DB '[*PROJECTNAME*] x64 Tool v1.0.0.0',0
szConTitle                      DB MAX_PATH DUP (0)
CmdLineParameters               DB 512 DUP (0)
CmdLineParameter                DB 256 DUP (0)
TotalCmdLineParameters          DQ 0

; Help
sz[*PROJECTNAME*]ConInfo        DB 13,10,"[[*PROJECTNAME*] x64] v1.00 - [*PROJECTNAME*] Tool - Copyright (C) 2017 fearless",13,10,13,10,0

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

sz[*PROJECTNAME*]ConHelpUsage   DB "Usage: [*PROJECTNAME*] [/?]",13,10
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
szErrorNotRecognised            DB " Not recognised as a valid switch/options.",0


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
szWildCardStar                  DB '*',0
szLF                            DB 10,0
szCRLF                          DB 13,10,0

SwitchHelp                      DB '/?',0
SwitchHelpAlt                   DB '-?',0
SwitchHelpAlt2                  DB '--?',0



.DATA?
;-----------------------------------------------------------------------------------------
; [*PROJECTNAME*] Uninitialized Data
;-----------------------------------------------------------------------------------------




















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
        processorArchitecture="amd64"
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
