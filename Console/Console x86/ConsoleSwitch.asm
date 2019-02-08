.686
.MMX
.XMM
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc

ConsoleStringLength             PROTO :DWORD
ConsoleStringCompareSensitive   PROTO :DWORD, :DWORD
ConsoleStringCompareInsensitive PROTO :DWORD, :DWORD


SWITCH_NAME_MAX_LENGTH      EQU 32
CMDLINE_MAX_SWITCHES        EQU 64
COMMAND_NAME_MAX_LENGTH     EQU 4
CMDLINE_MAX_COMMANDS        EQU 32

SWITCHDEF                   STRUCT
    lpszSwitch              DB SWITCH_NAME_MAX_LENGTH DUP (0)
    dwSwitchID              DD 0
SWITCHDEF                   ENDS

COMMANDDEF                  STRUCT
    lpszCommand             DB COMMAND_NAME_MAX_LENGTH DUP (0)
    dwCommandID             DD 0
COMMANDDEF                  ENDS

.DATA
CmdLineSwitchBuffer         DB SWITCH_NAME_MAX_LENGTH DUP (0)
RegisteredSwitchesTotal     DD 0
RegisteredSwitches          SWITCHDEF CMDLINE_MAX_SWITCHES DUP ({})

CmdLineCommandBuffer        DB COMMAND_NAME_MAX_LENGTH DUP (0)
RegisteredCommandsTotal     DD 0
RegisteredCommands          COMMANDDEF CMDLINE_MAX_COMMANDS DUP ({})

align 16
Cmpi_tbl \
db   0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15
db  16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
db  32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47
db  48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
db  64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
db 112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95
db  96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111
db 112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127
db 128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143
db 144,145,146,147,148,149,150,151,152,153,154,155,156,156,158,159
db 160,161,162,163,164,165,166,167,168,169,170,171,172,173,173,175
db 176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191
db 192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207
db 208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223
db 224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239
db 240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255


.CODE


;-----------------------------------------------------------------------------------------
; ConsoleSwitchRegister - register a switch for use with cmdline. / or - or -- start
;-----------------------------------------------------------------------------------------
ConsoleSwitchRegister PROC USES EBX lpszSwitch:DWORD, dwSwitchID:DWORD
    LOCAL ptrCurrentSwitchEntry:DWORD
    
    .IF lpszSwitch == NULL
        mov eax, FALSE
        ret
    .ENDIF
    Invoke ConsoleStringLength, lpszSwitch
    .IF eax == 0
        mov eax, FALSE
        ret
    .ELSEIF sdword ptr eax > SWITCH_NAME_MAX_LENGTH
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, lpszSwitch
    movzx eax, byte ptr [ebx]
    .IF !(al == '/' || al == '-')
        mov eax, FALSE
        ret
    .ENDIF
    
    mov eax, RegisteredSwitchesTotal
    .IF eax >= CMDLINE_MAX_SWITCHES
        mov eax, FALSE
        ret
    .ENDIF
    
    mov eax, RegisteredSwitchesTotal
    mov ebx, SIZEOF SWITCHDEF
    mul ebx
    lea ebx, RegisteredSwitches
    add eax, ebx
    mov ptrCurrentSwitchEntry, eax
    
    mov ebx, ptrCurrentSwitchEntry
    mov eax, lpszSwitch
    lea ebx, [ebx].SWITCHDEF.lpszSwitch
    Invoke lstrcpyn, ebx, eax, SWITCH_NAME_MAX_LENGTH

    mov ebx, ptrCurrentSwitchEntry
    mov eax, dwSwitchID
    mov [ebx].SWITCHDEF.dwSwitchID, eax
    
    inc RegisteredSwitchesTotal
    mov eax, TRUE
    
    ret
ConsoleSwitchRegister ENDP


;-----------------------------------------------------------------------------------------
; ConsoleCommandRegister - register a command for use with cmdline. (no / or - start)
;-----------------------------------------------------------------------------------------
ConsoleCommandRegister PROC USES EBX lpszCommand:DWORD, dwCommandID:DWORD
    LOCAL ptrCurrentCmdEntry:DWORD
    
    .IF lpszCommand == NULL
        mov eax, FALSE
        ret
    .ENDIF
    Invoke ConsoleStringLength, lpszCommand
    .IF eax == 0
        mov eax, FALSE
        ret
    .ELSEIF sdword ptr eax > COMMAND_NAME_MAX_LENGTH
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, lpszCommand
    movzx eax, byte ptr [ebx]
    .IF (al == '/' || al == '-')
        mov eax, FALSE
        ret
    .ENDIF
    
    mov eax, RegisteredCommandsTotal
    .IF eax >= CMDLINE_MAX_COMMANDS
        mov eax, FALSE
        ret
    .ENDIF
    
    mov eax, RegisteredCommandsTotal
    mov ebx, SIZEOF COMMANDDEF
    mul ebx
    lea ebx, RegisteredCommands
    add eax, ebx
    mov ptrCurrentCmdEntry, eax
        
    mov ebx, ptrCurrentCmdEntry
    mov eax, lpszCommand
    lea ebx, [ebx].COMMANDDEF.lpszCommand
    Invoke lstrcpyn, ebx, eax, COMMAND_NAME_MAX_LENGTH

    mov ebx, ptrCurrentCmdEntry
    mov eax, dwCommandID
    mov [ebx].COMMANDDEF.dwCommandID, eax
    
    inc RegisteredCommandsTotal
    mov eax, TRUE
    
    ret
ConsoleCommandRegister ENDP


;-----------------------------------------------------------------------------------------
; Returns switchid if lpszSwitch matches a registered switch or -1 otherwise
;-----------------------------------------------------------------------------------------
ConsoleSwitchID PROC USES EBX lpszSwitch:DWORD, bCaseSensitive:DWORD
    LOCAL nCurrentSwitch:DWORD
    LOCAL ptrCurrentSwitchEntry:DWORD

    .IF lpszSwitch == NULL
        mov eax, -1
        ret
    .ENDIF
    Invoke ConsoleStringLength, lpszSwitch
    .IF eax == 0
        mov eax, -1
        ret
    .ENDIF
    
    lea eax, RegisteredSwitches
    mov ptrCurrentSwitchEntry, eax
    
    mov eax, 0
    mov nCurrentSwitch, 0
    .WHILE eax < RegisteredSwitchesTotal
        mov ebx, ptrCurrentSwitchEntry
        
        mov eax, lpszSwitch
        lea ebx, [ebx].SWITCHDEF.lpszSwitch        
        .IF bCaseSensitive == FALSE
            Invoke ConsoleStringCompareInsensitive, eax, ebx
           .IF eax == 0 ; match
                mov ebx, ptrCurrentSwitchEntry
                mov eax, [ebx].SWITCHDEF.dwSwitchID
                ret
            .ELSE
                ; continue and try next entry
            .ENDIF                       
        .ELSE
            Invoke ConsoleStringCompareSensitive, eax, ebx
            .IF eax == 0 ; no match
                ; continue and try next entry
            .ELSE
                mov ebx, ptrCurrentSwitchEntry
                mov eax, [ebx].SWITCHDEF.dwSwitchID
                ret
            .ENDIF
        .ENDIF

        add ptrCurrentSwitchEntry, SIZEOF SWITCHDEF
        inc nCurrentSwitch
        mov eax, nCurrentSwitch
    .ENDW
    
    mov eax, -1
    ret
ConsoleSwitchID ENDP


;-----------------------------------------------------------------------------------------
; Returns commandid if lpszCommand matches a registered command or -1 otherwise
;-----------------------------------------------------------------------------------------
ConsoleCommandID PROC USES EBX lpszCommand:DWORD, bCaseSensitive:DWORD
    LOCAL nCurrentCmd:DWORD
    LOCAL ptrCurrentCmdEntry:DWORD

    .IF lpszCommand == NULL
        mov eax, -1
        ret
    .ENDIF
    Invoke ConsoleStringLength, lpszCommand
    .IF eax == 0
        mov eax, -1
        ret
    .ENDIF

    lea eax, RegisteredCommands
    mov ptrCurrentCmdEntry, eax
    
    mov eax, 0
    mov nCurrentCmd, 0
    .WHILE eax < RegisteredCommandsTotal
        mov ebx, ptrCurrentCmdEntry
        
        mov eax, lpszCommand
        lea ebx, [ebx].COMMANDDEF.lpszCommand
        .IF bCaseSensitive == FALSE
            Invoke ConsoleStringCompareInsensitive, eax, ebx
           .IF eax == 0 ; match
                mov ebx, ptrCurrentCmdEntry
                mov eax, [ebx].COMMANDDEF.dwCommandID
                ret
            .ELSE
                ; continue and try next entry
            .ENDIF                       
        .ELSE
            Invoke ConsoleStringCompareSensitive, eax, ebx
            .IF eax == 0 ; no match
                ; continue and try next entry
            .ELSE
                mov ebx, ptrCurrentCmdEntry
                mov eax, [ebx].COMMANDDEF.dwCommandID
                ret
            .ENDIF            
        .ENDIF
        
        add ptrCurrentCmdEntry, SIZEOF COMMANDDEF
        inc nCurrentCmd
        mov eax, nCurrentCmd
    .ENDW
    
    mov eax, -1
    ret
ConsoleCommandID ENDP


;**************************************************************************
; szCmp function taken from masm32 library
;**************************************************************************
OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 
align 16
ConsoleStringCompareSensitive PROC str1:DWORD, str2:DWORD
    mov ecx, [esp+4]
    mov edx, [esp+8]
    
    push ebx
    push esi
    mov eax, -1
    mov esi, 1
    align 4
cmst:
    REPEAT 3
    add eax, esi
    movzx ebx, BYTE PTR [ecx+eax]
    cmp bl, [edx+eax]
    jne no_match
    test ebx, ebx       ; check for terminator
    je retlen
    ENDM
    add eax, esi
    movzx ebx, BYTE PTR [ecx+eax]
    cmp bl, [edx+eax]
    jne no_match
    test ebx, ebx       ; check for terminator
    jne cmst
retlen:                 ; length is in EAX
    pop esi
    pop ebx
    ret 8
no_match:
    xor eax, eax        ; return zero on no match
    pop esi
    pop ebx
    ret 8
ConsoleStringCompareSensitive ENDP
OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 


;**************************************************************************
; Cmpi function taken from masm32 library - ecx, edx might be trashed
;**************************************************************************
OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 
align 16
ConsoleStringCompareInsensitive PROC src:DWORD,dst:DWORD
    push ebx
    push esi
    push edi

    mov esi, [esp+16]               ; src
    mov edi, [esp+20]               ; dst
    sub eax, eax                    ; zero eax as index
    
  align 4
  @@:
    movzx edx, BYTE PTR [esi+eax]
    movzx ebx, BYTE PTR [edi+eax]
    movzx ecx, BYTE PTR [edx+Cmpi_tbl]
    add eax, 1
    cmp cl, [ebx+Cmpi_tbl]
    jne quit                        ; exit on 1st mismatch with
    test cl, cl                     ; non zero value in EAX
    jnz @B

    sub eax, eax                    ; set EAX to ZERO on match

  quit:
    pop edi
    pop esi
    pop ebx

    ret 8
ConsoleStringCompareInsensitive ENDP
OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 


;**************************************************************************
; szLen function taken from masm32 library
;**************************************************************************
OPTION PROLOGUE:NONE 
OPTION EPILOGUE:NONE 
align 4
ConsoleStringLength PROC src:DWORD
    mov eax, [esp+4]
    sub eax, 4
  @@:
    add eax, 4
    cmp BYTE PTR [eax], 0
    je lb1
    cmp BYTE PTR [eax+1], 0
    je lb2
    cmp BYTE PTR [eax+2], 0
    je lb3
    cmp BYTE PTR [eax+3], 0
    jne @B

    sub eax, [esp+4]
    add eax, 3
    ret 4
  lb3:
    sub eax, [esp+4]
    add eax, 2
    ret 4
  lb2:
    sub eax, [esp+4]
    add eax, 1
    ret 4
  lb1:
    sub eax, [esp+4]
    ret 4
ConsoleStringLength ENDP
OPTION PROLOGUE:PrologueDef 
OPTION EPILOGUE:EpilogueDef 

END
