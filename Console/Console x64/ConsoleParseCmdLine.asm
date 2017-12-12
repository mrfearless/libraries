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

include Console.inc

;GetCommandLineA PROTO
;GetCommandLine equ <GetCommandLineA>
ConsoleCmdLineParamInString PROTO :QWORD, :QWORD, :QWORD


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
; Returns no of parameters parsed and stored in the qwParametersArray
;-----------------------------------------------------------------------------------------
ConsoleParseCmdLine PROC FRAME USES RBX RDI RSI qwParametersArray:QWORD ;PARMAREA=4*QWORD

    mov     rsi,rcx ; = buffer
    invoke  GetCommandLine
    lea     rdx,[rax-1]
    xor     rax,rax

    lea     rdi,[rsi+256]
    mov     ch,32
    mov     bl,9

scan:

    inc     rdx
    mov     cl,BYTE PTR [rdx]
    test    cl,cl
    jz      finish
    cmp     cl,32
    je      scan
    cmp     cl,9
    je      scan
    inc     rax
    mov     QWORD PTR [rsi],rdi
    add     rsi,8

restart:

    mov     cl,BYTE PTR [rdx]
    test    cl,cl
    jne     @f
    mov     BYTE PTR [rdi],cl
    jmp     finish
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
    mov     BYTE PTR [rdi],cl
    inc     rdi

next_char:

    inc     rdx
    jmp     restart

end_of_line:

    mov     BYTE PTR [rdi],0
    inc     rdi
    jmp     scan
    
finish:

    ret

ConsoleParseCmdLine ENDP


;-----------------------------------------------------------------------------------------
; ConsoleCmdLineParam by fearless - fetch parameter by index from cmd line that was
; parsed via ConsoleParseCmdLine and stored in an array buffer
; 
; Returns -1 if qwParametersArray is empty
; Returns 0 if parameter required is invalid
; Returns > 0 if parameter was fetched, on return lpszReturnedParameter will contain
;             the string value of the parameter and rax contains the lenght of parameter
;-----------------------------------------------------------------------------------------
ConsoleCmdLineParam PROC FRAME USES RBX RSI qwParametersArray:QWORD, qwParameterToFetch:QWORD, qwTotalParameters:QWORD, lpszReturnedParameter:QWORD
    
    .IF qwParametersArray == 0
        mov rax, -1
        ret
    .ENDIF
    
    mov rax, qwParameterToFetch
    .IF rax > qwTotalParameters ; for safety we require total params so we dont go over and crash
        mov rbx, [lpszReturnedParameter]
        mov byte ptr [rbx], 0h
        mov rax, 0
        ret
    .ENDIF
    
    mov rsi, qwParametersArray		
    mov rbx, 4
    mul rbx ; rax contains the no of parameter we want offset for
    add rsi, rax ; Now at offset for parameters string
    ;Invoke szCopy, QWORD PTR [esi], lpszReturnedParameter ; Copy param to our chosen passed location - make sure enough space in buffer or crashh
    .IF lpszReturnedParameter != NULL
        Invoke lstrcpy, lpszReturnedParameter, QWORD PTR [rsi]
        Invoke lstrlen, lpszReturnedParameter ; Get length of parameter. >0 = success
    .ELSE
        mov rax, 0
    .ENDIF
    ret
ConsoleCmdLineParam endp


;-----------------------------------------------------------------------------------------
; Attempts to return the type of the parameter in rax
;-----------------------------------------------------------------------------------------
ConsoleCmdLineParamType PROC FRAME USES RBX qwParametersArray:QWORD, qwParameterToFetch:QWORD, qwTotalParameters:QWORD
    LOCAL szParameter[256]:BYTE
    LOCAL qwLenParameter:QWORD
    LOCAL bDotChar:QWORD
    LOCAL bColonChar:QWORD
    LOCAL bForwardSlashChar:QWORD
    LOCAL bBackSlashChar:QWORD
    LOCAL bAsteriskChar:QWORD
    LOCAL bQuestionChar:QWORD
    
    Invoke ConsoleCmdLineParam, qwParametersArray, qwParameterToFetch, qwTotalParameters, Addr szParameter
    .IF sqword ptr rax > 0
        mov qwLenParameter, rax
        lea rbx, szParameter

        .IF rax == 0
            mov rax, CMDLINE_PARAM_TYPE_ERROR
            ret
            
        .ELSEIF rax == 1
            mov rax, CMDLINE_PARAM_TYPE_COMMAND
            ret
        
        .ELSEIF rax == 2
            movzx rax, byte ptr [rbx]
            .IF al == '-' || al == '/' ; -? /?
                mov rax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            .ELSE
                mov rax, CMDLINE_PARAM_TYPE_COMMAND
                ret
            .ENDIF
        
        .ELSEIF rax == 3 ; 
            movzx rax, byte ptr [rbx]
            .IF al == '-' ; -
                ;movzx rax, byte ptr [rbx+1]
                ;.IF al == '-' ; --?
                    mov rax, CMDLINE_PARAM_TYPE_SWITCH
                    ret
                ;.ELSE ; -xa
                ;    mov rax, CMDLINE_PARAM_TYPE_OPTIONS
                ;    ret
                ;.ENDIF
                
            .ELSEIF al == '/' ; starts with forward slash
                mov rax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            
            .ELSEIF al == '*'
                movzx rax, byte ptr [rbx+1]
                .IF al == '.'
                    mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                    ret
                .ELSE
                    mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF
                
            .ELSE
                movzx rax, byte ptr [rbx+1]
                .IF al == '.'
                    movzx rax, byte ptr [rbx+2]
                    .IF al == '*'
                        mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                        ret
                    .ENDIF
                .ENDIF
                mov rax, CMDLINE_PARAM_TYPE_COMMAND
                ret
            .ENDIF
        
        .ELSE ; IF rax > 3
            movzx rax, byte ptr [rbx]
            .IF al == '-' || al == '/' ; starts with forward slash
                mov rax, CMDLINE_PARAM_TYPE_SWITCH
                ret
            
            .ELSEIF al == '*'
                movzx rax, byte ptr [rbx+1]
                .IF al == '.'
                    mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                    ret
                .ELSE
                    mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF
            
            .ELSE

                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szDotChar
                .IF sqword ptr rax > 0
                    mov bDotChar, TRUE
                .ELSE
                    mov bDotChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szColonChar
                .IF sqword ptr rax > 0
                    mov bColonChar, TRUE
                .ELSE
                    mov bColonChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szForwardSlashChar
                .IF sqword ptr rax > 0
                    mov bForwardSlashChar, TRUE
                .ELSE
                    mov bForwardSlashChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szBackSlashChar
                .IF sqword ptr rax > 0
                    mov bBackSlashChar, TRUE
                .ELSE
                    mov bBackSlashChar, FALSE
                .ENDIF                
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szAsteriskChar
                .IF sqword ptr rax > 0
                    mov bAsteriskChar, TRUE
                .ELSE
                    mov bAsteriskChar, FALSE
                .ENDIF
                
                Invoke ConsoleCmdLineParamInString, 1, Addr szParameter, Addr szQuestionChar
                .IF sqword ptr rax > 0
                    mov bQuestionChar, TRUE
                .ELSE
                    mov bQuestionChar, FALSE
                .ENDIF                  
                
                .IF bColonChar == TRUE
                    .IF bForwardSlashChar == TRUE || bBackSlashChar == TRUE
                       .IF bDotChar == TRUE
                            .IF bAsteriskChar == TRUE || bQuestionChar == TRUE ; .\*.*, ..\*.???
                                mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                                ret
                            .ELSE
                                lea rbx, szParameter
                                movzx rax, byte ptr [rbx]
                                .IF al == '.'
                                    movzx rax, byte ptr [rbx+1]
                                    .IF al == '.' || al == '\' || al == '/'
                                        Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                        .IF sqword ptr rax > 0
                                            mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                        .ELSE
                                            mov rax, CMDLINE_PARAM_TYPE_FOLDER
                                        .ENDIF
                                    .ELSE
                                        mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                                        ret
                                    .ENDIF
                                .ELSE
                                    mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                    ret
                                .ENDIF
                            .ENDIF                       
                        .ELSE
                            mov rax, CMDLINE_PARAM_TYPE_FOLDER
                            ret
                        .ENDIF
                    .ELSE
                        .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                            mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                            ret
                        .ELSE
                            .IF bDotChar == TRUE
                                lea rbx, szParameter
                                movzx rax, byte ptr [rbx]
                                .IF al == '.'
                                    movzx rax, byte ptr [rbx+1]
                                    .IF al == '.' || al == '\' || al == '/'
                                        Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                        .IF sqword ptr rax > 0
                                            mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                        .ELSE
                                            mov rax, CMDLINE_PARAM_TYPE_FOLDER
                                        .ENDIF
                                    .ELSE
                                        mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                                        ret
                                    .ENDIF
                                .ELSE
                                    mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                    ret
                                .ENDIF                            
                            .ELSE
                                mov rax, CMDLINE_PARAM_TYPE_FOLDER
                                ret
                            .ENDIF
                        .ENDIF
                    .ENDIF
                .ENDIF

               .IF bForwardSlashChar == TRUE || bBackSlashChar == TRUE
                   .IF bDotChar == TRUE
                        .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                            mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                            ret
                        .ELSE
                            lea rbx, szParameter
                            movzx rax, byte ptr [rbx]
                            .IF al == '.'
                                movzx rax, byte ptr [rbx+1]
                                .IF al == '.' || al == '\' || al == '/'
                                    Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                    .IF sqword ptr rax > 0
                                        mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                    .ELSE
                                        mov rax, CMDLINE_PARAM_TYPE_FOLDER
                                    .ENDIF
                                .ELSE
                                    mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                                    ret
                                .ENDIF
                            .ELSE
                                mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                ret
                            .ENDIF                           
                        .ENDIF    
                    .ELSE
                        mov rax, CMDLINE_PARAM_TYPE_FOLDER
                        ret
                    .ENDIF
                .ENDIF

                .IF bDotChar == TRUE
                    .IF bAsteriskChar == TRUE || bQuestionChar == TRUE
                        mov rax, CMDLINE_PARAM_TYPE_FILESPEC
                        ret
                    .ELSE
                        lea rbx, szParameter
                        movzx rax, byte ptr [rbx]
                        .IF al == '.'
                            movzx rax, byte ptr [rbx+1]
                            .IF al == '.' || al == '\' || al == '/'
                                Invoke ConsoleCmdLineParamInString, 3, Addr szParameter, Addr szDotChar
                                .IF sqword ptr rax > 0
                                    mov rax, CMDLINE_PARAM_TYPE_FILENAME
                                .ELSE
                                    mov rax, CMDLINE_PARAM_TYPE_FOLDER
                                .ENDIF
                            .ELSE
                                mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                                ret
                            .ENDIF
                        .ELSE
                            mov rax, CMDLINE_PARAM_TYPE_FILENAME
                            ret
                        .ENDIF
                    .ENDIF
                
                .ELSE
                    ; folder or options?
                    mov rax, CMDLINE_PARAM_TYPE_UNKNOWN
                    ret
                .ENDIF

            .ENDIF
        
        .ENDIF

    .ELSE
        mov rax, CMDLINE_PARAM_TYPE_ERROR
        ret
    .ENDIF
    
    ret

ConsoleCmdLineParamType ENDP


;**************************************************************************
; InString function taken from masm64 library
;**************************************************************************
ConsoleCmdLineParamInString proc FRAME USES RBX RCX RDX RDI RSI startpos:QWORD,lpSource:QWORD,lpPattern:QWORD

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

    LOCAL sLen:QWORD
    LOCAL pLen:QWORD


    invoke lstrlen, lpSource
    mov sLen, rax           ; source length
    invoke lstrlen, lpPattern
    mov pLen, rax           ; pattern length

    cmp startpos, 1
    jge @F
    mov rax, -2
    jmp isOut               ; exit if startpos not 1 or greater
  @@:

    dec startpos            ; correct from 1 to 0 based index

    cmp  rax, sLen
    jl @F
    mov rax, -1
    jmp isOut               ; exit if pattern longer than source
  @@:

    sub sLen, rax           ; don't read past string end
    inc sLen

    mov rcx, sLen
    cmp rcx, startpos
    jg @F
    mov rax, -2
    jmp isOut               ; exit if startpos is past end
  @@:

  ; ----------------
  ; setup loop code
  ; ----------------
    mov rsi, lpSource
    mov rdi, lpPattern
    mov al, [rdi]           ; get 1st char in pattern

    add rsi, rcx            ; add source length
    neg rcx                 ; invert sign
    add rcx, startpos       ; add starting offset

    jmp Scan_Loop

    align 16

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Pre_Scan:
    inc rcx                 ; start on next byte

  Scan_Loop:
    cmp al, [rsi+rcx]       ; scan for 1st byte of pattern
    je Pre_Match            ; test if it matches
    inc rcx
    js Scan_Loop            ; exit on sign inversion

    jmp No_Match

  Pre_Match:
    lea rbx, [rsi+rcx]      ; put current scan address in EBX
    mov rdx, pLen           ; put pattern length into EDX

  Test_Match:
    mov ah, [rbx+rdx-1]     ; load last byte of pattern length in main string
    cmp ah, [rdi+rdx-1]     ; compare it with last byte in pattern
    jne Pre_Scan            ; jump back on mismatch
    dec rdx
    jnz Test_Match          ; 0 = match, fall through on match

  ; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  Match:
    add rcx, sLen
    mov rax, rcx
    inc rax
    jmp isOut
    
  No_Match:
    xor rax, rax

  isOut:

    ret

ConsoleCmdLineParamInString endp


END
