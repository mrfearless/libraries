.686
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc

GetCommandLineA             PROTO
GetCommandLine              EQU <GetCommandLineA>
ConsoleCmdLineParamInString PROTO :DWORD, :DWORD, :DWORD


.DATA
szDotChar                   DB '.',0 
szColonChar                 DB ':',0
szForwardSlashChar          DB '\',0
szBackSlashChar             DB '/',0
szAsteriskChar              DB '*',0
szQuestionChar              DB '?',0

.CODE


;-----------------------------------------------------------------------------------------
; Command-line parser for console applications http://masm32.com/board/index.php?topic=2598.msg27628#msg27628
; Coded by Vortex
; Returns no of parameters parsed and stored in the dwParametersArray
;-----------------------------------------------------------------------------------------
ConsoleParseCmdLine PROC USES EBX EDI ESI dwParametersArray:DWORD

    invoke  GetCommandLine
    lea     edx,[eax-1]
    xor     eax,eax
    mov     esi,dwParametersArray
    lea     edi,[esi+256]
    mov     ch,32
    mov     bl,9

scan:

    inc     edx
    mov     cl,BYTE PTR [edx]
    test    cl,cl
    jz      finish
    cmp     cl,32
    je      scan
    cmp     cl,9
    je      scan
    inc     eax
    mov     DWORD PTR [esi],edi
    add     esi,4

restart:

    mov     cl,BYTE PTR [edx]
    test    cl,cl
    jne     @f
    mov     BYTE PTR [edi],cl
    ret
@@:
    cmp     cl,ch
    je      end_of_line
    cmp     cl,bl
    je      end_of_line
    cmp     cl,34
    jne     @f
    xor     ch,32
    xor     bl,9
    jmp     next_char
@@:	
    mov     BYTE PTR [edi],cl
    inc     edi

next_char:

    inc     edx
    jmp     restart

end_of_line:

    mov     BYTE PTR [edi],0
    inc     edi
    jmp     scan	

finish:

    ret

ConsoleParseCmdLine ENDP


;-----------------------------------------------------------------------------------------
; ConsoleCmdLineParam by fearless - fetch parameter by index from cmd line that was
; parsed via ConsoleParseCmdLine and stored in an array buffer
; 
; Returns -1 if dwParametersArray is empty
; Returns 0 if parameter required is invalid
; Returns > 0 if parameter was fetched, on return lpszReturnedParameter will contain
;             the string value of the parameter and eax contains the lenght of parameter
;-----------------------------------------------------------------------------------------
ConsoleCmdLineParam PROC USES EBX ESI dwParametersArray:DWORD, dwParameterToFetch:DWORD, dwTotalParameters:DWORD, lpszReturnedParameter:DWORD
    .IF dwParametersArray == 0
        mov eax, -1
        ret
    .ENDIF
    
    mov eax, dwParameterToFetch
    .IF eax > dwTotalParameters ; for safety we require total params so we dont go over and crash
        mov ebx, [lpszReturnedParameter]
        mov byte ptr [ebx], 0h
        mov eax, 0
        ret
    .ENDIF
    
    mov esi, dwParametersArray		
    mov ebx, 4
    mul ebx ; eax contains the no of parameter we want offset for
    add esi, eax ; Now at offset for parameters string

    .IF lpszReturnedParameter != NULL
        Invoke lstrcpy, lpszReturnedParameter, DWORD PTR [esi]
        Invoke lstrlen, lpszReturnedParameter ; Get length of parameter. >0 = success
    .ELSE
        mov eax, 0
    .ENDIF
    ret
ConsoleCmdLineParam endp


;-----------------------------------------------------------------------------------------
; Attempts to return the type of the parameter in eax
;-----------------------------------------------------------------------------------------
ConsoleCmdLineParamType PROC USES EBX dwParametersArray:DWORD, dwParameterToFetch:DWORD, dwTotalParameters:DWORD
    LOCAL szParameter[256]:BYTE
    LOCAL dwLenParameter:DWORD
    LOCAL bDotChar:DWORD
    LOCAL bColonChar:DWORD
    LOCAL bForwardSlashChar:DWORD
    LOCAL bBackSlashChar:DWORD
    LOCAL bAsteriskChar:DWORD
    LOCAL bQuestionChar:DWORD
    
    Invoke ConsoleCmdLineParam, dwParametersArray, dwParameterToFetch, dwTotalParameters, Addr szParameter
    .IF sdword ptr eax > 0
        mov dwLenParameter, eax
        lea ebx, szParameter

        .IF eax == 0
            mov eax, CMDLINE_PARAM_TYPE_ERROR
            ret
            
        .ELSEIF eax == 1
            mov eax, CMDLINE_PARAM_TYPE_COMMAND
            ret
        
        .ELSEIF eax == 2
            movzx eax, byte ptr [ebx]
            .IF al == '-' || al == '/' ; -? /?
                mov eax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            .ELSE
                mov eax, CMDLINE_PARAM_TYPE_COMMAND
                ret
            .ENDIF
        
        .ELSEIF eax == 3 ; 
            movzx eax, byte ptr [ebx]
            .IF al == '-' ; -
                mov eax, CMDLINE_PARAM_TYPE_SWITCH
                ret

            .ELSEIF al == '/' ; starts with forward slash
                mov eax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            
            .ELSEIF al == '*'
                movzx eax, byte ptr [ebx+1]
                .IF al == '.'
                    mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                    ret
                .ELSE
                    mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF
                
            .ELSE
                movzx eax, byte ptr [ebx+1]
                .IF al == '.'
                    movzx eax, byte ptr [ebx+2]
                    .IF al == '*'
                        mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                        ret
                    .ENDIF
                .ENDIF
                mov eax, CMDLINE_PARAM_TYPE_COMMAND
                ret
            .ENDIF
        
        .ELSE ; IF eax > 3
            movzx eax, byte ptr [ebx]
            .IF al == '-' || al == '/' ; starts with forward slash
                mov eax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            
            .ELSEIF al == '*'
                movzx eax, byte ptr [ebx+1]
                .IF al == '.'
                    mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                    ret
                .ELSE
                    mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF
            
            .ELSE

                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szDotChar
                .IF sdword ptr eax > 0
                    mov bDotChar, TRUE
                .ELSE
                    mov bDotChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szColonChar
                .IF sdword ptr eax > 0
                    mov bColonChar, TRUE
                .ELSE
                    mov bColonChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szForwardSlashChar
                .IF sdword ptr eax > 0
                    mov bForwardSlashChar, TRUE
                .ELSE
                    mov bForwardSlashChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szBackSlashChar
                .IF sdword ptr eax > 0
                    mov bBackSlashChar, TRUE
                .ELSE
                    mov bBackSlashChar, FALSE
                .ENDIF                
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szAsteriskChar
                .IF sdword ptr eax > 0
                    mov bAsteriskChar, TRUE
                .ELSE
                    mov bAsteriskChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szQuestionChar
                .IF sdword ptr eax > 0
                    mov bQuestionChar, TRUE
                .ELSE
                    mov bQuestionChar, FALSE
                .ENDIF                  
                
                .IF bColonChar == TRUE
                    .IF bForwardSlashChar == TRUE || bBackSlashChar == TRUE
                       .IF bDotChar == TRUE
                            .IF bAsteriskChar == TRUE || bQuestionChar == TRUE ; .\*.*, ..\*.???
                                mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                                ret
                            .ELSE
                                lea ebx, szParameter
                                movzx eax, byte ptr [ebx]
                                .IF al == '.'
                                    movzx eax, byte ptr [ebx+1]
                                    .IF al == '.' || al == '\' || al == '/'
                                        Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                        .IF sdword ptr eax > 0
                                            mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                        .ELSE
                                            mov eax, CMDLINE_PARAM_TYPE_FOLDER
                                        .ENDIF
                                    .ELSE
                                        mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                                        ret
                                    .ENDIF
                                .ELSE
                                    mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                    ret
                                .ENDIF
                            .ENDIF                       
                        .ELSE
                            mov eax, CMDLINE_PARAM_TYPE_FOLDER
                            ret
                        .ENDIF
                    .ELSE
                        .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                            mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                            ret
                        .ELSE
                            .IF bDotChar == TRUE
                                lea ebx, szParameter
                                movzx eax, byte ptr [ebx]
                                .IF al == '.'
                                    movzx eax, byte ptr [ebx+1]
                                    .IF al == '.' || al == '\' || al == '/'
                                        Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                        .IF sdword ptr eax > 0
                                            mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                        .ELSE
                                            mov eax, CMDLINE_PARAM_TYPE_FOLDER
                                        .ENDIF
                                    .ELSE
                                        mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                                        ret
                                    .ENDIF
                                .ELSE
                                    mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                    ret
                                .ENDIF                            
                            .ELSE
                                mov eax, CMDLINE_PARAM_TYPE_FOLDER
                                ret
                            .ENDIF
                        .ENDIF
                    .ENDIF
                .ENDIF

               .IF bForwardSlashChar == TRUE || bBackSlashChar == TRUE
                   .IF bDotChar == TRUE
                        .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                            mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                            ret
                        .ELSE
                            lea ebx, szParameter
                            movzx eax, byte ptr [ebx]
                            .IF al == '.'
                                movzx eax, byte ptr [ebx+1]
                                .IF al == '.' || al == '\' || al == '/'
                                    Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                    .IF sdword ptr eax > 0
                                        mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                    .ELSE
                                        mov eax, CMDLINE_PARAM_TYPE_FOLDER
                                    .ENDIF
                                .ELSE
                                    mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                                    ret
                                .ENDIF
                            .ELSE
                                mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                ret
                            .ENDIF                           
                        .ENDIF    
                    .ELSE
                        mov eax, CMDLINE_PARAM_TYPE_FOLDER
                        ret
                    .ENDIF
                .ENDIF

                .IF bDotChar == TRUE
                    .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                        mov eax, CMDLINE_PARAM_TYPE_FILESPEC
                        ret
                    .ELSE
                        lea ebx, szParameter
                        movzx eax, byte ptr [ebx]
                        .IF al == '.'
                            movzx eax, byte ptr [ebx+1]
                            .IF al == '.' || al == '\' || al == '/'
                                Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                .IF sdword ptr eax > 0
                                    mov eax, CMDLINE_PARAM_TYPE_FILENAME
                                .ELSE
                                    mov eax, CMDLINE_PARAM_TYPE_FOLDER
                                .ENDIF
                            .ELSE
                                mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                                ret
                            .ENDIF
                        .ELSE
                            mov eax, CMDLINE_PARAM_TYPE_FILENAME
                            ret
                        .ENDIF
                    .ENDIF
                
                .ELSE
                    ; folder or options?
                    mov eax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF

            .ENDIF
        
        .ENDIF

    .ELSE
        mov eax, CMDLINE_PARAM_TYPE_ERROR
        ret
    .ENDIF
    
    ret
ConsoleCmdLineParamType ENDP


;**************************************************************************
; InString function taken from masm32 library
;**************************************************************************
ConsoleCmdLineParamInString PROC USES EBX ECX EDX EDI ESI startpos:DWORD, lpSource:DWORD, lpPattern:DWORD

  ; ------------------------------------------------------------------
  ; InString searches for a substring in a larger string and if it is
  ; found, it returns its position in eax. 
  ;
  ; It uses a one (1) based character index (1st character is 1,
  ; 2nd is 2 etc...) for both the "StartPos" parameter and the returned
  ; character position.
  ;
  ; Return Values.
  ; If the function succeeds, it returns the 1 based index of the start
  ; of the substring.
  ;  0 = no match found
  ; -1 = substring same length or longer than main string
  ; -2 = "StartPos" parameter out of range (less than 1 or longer than
  ; main string)
  ; ------------------------------------------------------------------

    LOCAL sLen:DWORD
    LOCAL pLen:DWORD

    ;push ebx
    ;push esi
    ;push edi

    invoke lstrlen, lpSource
    mov sLen, eax           ; source length
    invoke lstrlen, lpPattern
    mov pLen, eax           ; pattern length

    cmp startpos, 1
    jge @F
    mov eax, -2
    jmp isOut               ; exit if startpos not 1 or greater
  @@:

    dec startpos            ; correct from 1 to 0 based index

    cmp  eax, sLen
    jl @F
    mov eax, -1
    jmp isOut               ; exit if pattern longer than source
  @@:

    sub sLen, eax           ; don't read past string end
    inc sLen

    mov ecx, sLen
    cmp ecx, startpos
    jg @F
    mov eax, -2
    jmp isOut               ; exit if startpos is past end
  @@:

  ; ----------------
  ; setup loop code
  ; ----------------
    mov esi, lpSource
    mov edi, lpPattern
    mov al, [edi]           ; get 1st char in pattern

    add esi, ecx            ; add source length
    neg ecx                 ; invert sign
    add ecx, startpos       ; add starting offset

    jmp Scan_Loop

    align 16

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Pre_Scan:
    inc ecx                 ; start on next byte

  Scan_Loop:
    cmp al, [esi+ecx]       ; scan for 1st byte of pattern
    je Pre_Match            ; test if it matches
    inc ecx
    js Scan_Loop            ; exit on sign inversion

    jmp No_Match

  Pre_Match:
    lea ebx, [esi+ecx]      ; put current scan address in EBX
    mov edx, pLen           ; put pattern length into EDX

  Test_Match:
    mov ah, [ebx+edx-1]     ; load last byte of pattern length in main string
    cmp ah, [edi+edx-1]     ; compare it with last byte in pattern
    jne Pre_Scan            ; jump back on mismatch
    dec edx
    jnz Test_Match          ; 0 = match, fall through on match

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Match:
    add ecx, sLen
    mov eax, ecx
    inc eax
    jmp isOut
    
  No_Match:
    xor eax, eax

  isOut:
    ;pop edi
    ;pop esi
    ;pop ebx

    ret

ConsoleCmdLineParamInString ENDP


END
