.486                        ; force 32 bit code
.model flat, stdcall        ; memory model & calling convention
option casemap :none        ; case sensitive

include windows.inc

include kernel32.inc
includelib kernel32.lib

include Console.inc

GetCommandLineA PROTO
GetCommandLine equ <GetCommandLineA>


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
    ;Invoke szCopy, dword PTR [esi], lpszReturnedParameter ; Copy param to our chosen passed location - make sure enough space in buffer or crashh
    Invoke lstrcpy, lpszReturnedParameter, DWORD PTR [esi]
    Invoke lstrlen, lpszReturnedParameter ; Get length of parameter. >0 = success
    ret
ConsoleCmdLineParam endp


END
