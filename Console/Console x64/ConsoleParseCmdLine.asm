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
    ;Invoke szCopy, dword PTR [esi], lpszReturnedParameter ; Copy param to our chosen passed location - make sure enough space in buffer or crashh
    Invoke lstrcpy, lpszReturnedParameter, QWORD PTR [rsi]
    Invoke lstrlen, lpszReturnedParameter ; Get length of parameter. >0 = success
    ret
ConsoleCmdLineParam endp





END
