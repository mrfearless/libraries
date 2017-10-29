; ########################################################################
;
;               This original module was written by f0dder.
;
;      Part of the code has been optimised by Alexander Yackubtchik
;
; ########################################################################

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

.code

; ########################################################################

dw2hex proc FRAME USES RCX RDX RSI source:DWORD, lpBuffer:QWORD

    mov rdx, lpBuffer
    xor rsi, rsi
    mov esi, source

    xor rax, rax
    xor rcx, rcx

    mov [rdx+8], al         ; rdx+8 put terminator at correct length
    mov cl, 7 ;7               ; length of hexstring - 1

  @@:
    mov rax, rsi            ; we're going to work on AL
    and al, 00001111b       ; mask out high nibble

    .IF al < 10
        add al, "0"         ; convert digits 0-9 to ascii
    .ELSE
        add al, ("A"-10)    ; convert digits A-F to ascii
    .ENDIF

    ;cmp al,10
    ;sbb al,69h
    ;das

    mov [rdx + rcx], al     ; store the asciihex(AL) in the string
    shr rsi, 4              ; next nibble
    dec rcx                 ; decrease counter (one byte less than dec cl :-)
    jns @B                  ; eat them if there's any more

    ret

dw2hex endp

; #########################################################################

end 