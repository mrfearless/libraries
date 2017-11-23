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
include commctrl.inc
;include user32.inc
includelib user32.lib

include TreeView.inc

TreeViewFindItemBranch      PROTO :QWORD, :QWORD, :QWORD, :QWORD
TreeViewFindTextCheckString PROTO :QWORD, :QWORD, :QWORD, :QWORD
TreeViewFindItemInString    PROTO :QWORD, :QWORD, :QWORD
TreeViewFindItemUpperString PROTO :QWORD

.DATA
szTreeViewFindItemText      DB MAX_PATH DUP (0)
szTextViewFindSearchText    DB MAX_PATH DUP (0)


.code

;**************************************************************************
; TreeViewFindItem - find text in treeview and return handle to item or 0
;**************************************************************************
TreeViewFindItem PROC FRAME hTreeview:QWORD, hItem:QWORD, lpszFindText:QWORD, bCaseSensitive:QWORD
    LOCAL hCurrentItem:QWORD
    LOCAL hFoundItem:QWORD

    .IF hTreeview == NULL || lpszFindText == NULL
        mov rax, 0
        ret
    .ENDIF
    
    Invoke lstrlen, lpszFindText
    .IF rax == 0
        mov rax, 0
        ret
    .ENDIF
    
    Invoke lstrcpy, Addr szTextViewFindSearchText, lpszFindText
    .IF bCaseSensitive == FALSE
        Invoke TreeViewFindItemUpperString, Addr szTextViewFindSearchText
    .ENDIF

    mov hFoundItem, 0
    
    .IF hItem == NULL
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentItem, rax
    
    .WHILE rax != NULL
        mov hCurrentItem, rax

        Invoke TreeViewFindItemBranch, hTreeview, hCurrentItem, Addr szTextViewFindSearchText, bCaseSensitive ;lpszFindText
        mov hFoundItem, rax
        
        .IF hFoundItem != 0
            mov rax, hFoundItem
            .BREAK
        .ENDIF
        
        ;start looping up parent/next'
        mov rax, hCurrentItem
        .WHILE rax != NULL

            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
            .IF rax != NULL ; current item has a sibling, so go check that
                mov hCurrentItem, rax

                Invoke TreeViewFindTextCheckString, hTreeview, hCurrentItem, lpszFindText, bCaseSensitive
                .IF rax == TRUE
                    mov rax, hCurrentItem
                    mov hFoundItem, rax
                    .BREAK
                .ENDIF

                mov rax, hCurrentItem
                mov hFoundItem, 0
                .BREAK                
            .ELSE
                Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_PARENT, hCurrentItem
                .IF rax != NULL ; current item has no sibling so we goto parent, check that first
                    mov hCurrentItem, rax
                    mov rax, hCurrentItem
                    mov hFoundItem, 0
                    .CONTINUE ; didnt find our item in parent, so get parents sibling to check for
                 .ELSE ; top parent, no more parents to check so return 0
                    mov rax, NULL
                    mov hFoundItem, 0
                    .BREAK
                .ENDIF
            .ENDIF
            ; rax contains next sibling to check for or null (no sibling)
        .ENDW

        .IF hFoundItem != 0
            .BREAK ; found our item so break out of loop
        .ENDIF

    .ENDW

    mov rax, hFoundItem
    ret

TreeViewFindItem ENDP


;**************************************************************************
; Finds text from current node down the current branch - all children under
; this node and their children
;**************************************************************************
TreeViewFindItemBranch PROC FRAME hTreeview:QWORD, hItem:QWORD, lpszFindText:QWORD, bCaseSensitive:QWORD
    LOCAL hCurrentItem:QWORD
    LOCAL hFoundItem:QWORD

    mov hFoundItem, 0
    
    .IF hItem == NULL
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ELSE
        mov rax, hItem
    .ENDIF
    mov hCurrentItem, rax
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE rax != NULL
        mov hCurrentItem, rax
        
        ; check if correct item
        Invoke TreeViewFindTextCheckString, hTreeview, hCurrentItem, lpszFindText, bCaseSensitive
        .IF rax == TRUE
            mov rax, hCurrentItem
            mov hFoundItem, rax
            .BREAK
        .ELSE
            mov hFoundItem, 0
            Invoke TreeViewFindItemBranch, hTreeview, hCurrentItem, lpszFindText, bCaseSensitive
            mov hFoundItem, rax
        .ENDIF
         
        .IF hFoundItem != 0
            .BREAK
        .ENDIF
         
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    
    mov rax, hFoundItem
    ret

TreeViewFindItemBranch ENDP


;**************************************************************************
; TreeViewFindTextCheckString - check text matches, return true or false
;**************************************************************************
TreeViewFindTextCheckString PROC FRAME hTreeview:QWORD, hItem:QWORD, lpszFindText:QWORD, bCaseSensitive:QWORD
    Invoke TreeViewGetItemText, hTreeview, hItem, Addr szTreeViewFindItemText, MAX_PATH
    .IF rax != 0
        Invoke lstrlen, Addr szTreeViewFindItemText
        .IF rax == 0
            mov rax, FALSE
            ret
        .ENDIF
        
        .IF bCaseSensitive == FALSE
            Invoke TreeViewFindItemUpperString, Addr szTreeViewFindItemText
        .ENDIF
        
        Invoke TreeViewFindItemInString, 1, Addr szTreeViewFindItemText, lpszFindText
        .IF sqword ptr rax > 0 ;rax == 0 ; no found sdword ptr rax > 0
            mov rax, TRUE
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
TreeViewFindTextCheckString ENDP


;**************************************************************************
; InString function taken from masm64 library
;**************************************************************************
TreeViewFindItemInString PROC FRAME USES RBX RCX RDX RDI RSI startpos:QWORD,lpSource:QWORD,lpPattern:QWORD

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
TreeViewFindItemInString ENDP


;**************************************************************************
; szUpper function taken from masm64 library
;**************************************************************************
TreeViewFindItemUpperString PROC FRAME text:QWORD
    mov rax, text
    dec rax

  @@:
    add rax, 1
    cmp BYTE PTR [rax], 0
    je @F
    cmp BYTE PTR [rax], "a"
    jb @B
    cmp BYTE PTR [rax], "z"
    ja @B
    sub BYTE PTR [rax], 32
    jmp @B
  @@:

    mov rax, text
    ret
TreeViewFindItemUpperString ENDP


end











