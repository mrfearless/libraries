
TreeViewFindItemBranch      PROTO :DWORD, :DWORD, :DWORD
TreeViewFindTextCheckString PROTO :DWORD, :DWORD, :DWORD
TreeViewFindItemInString    PROTO :DWORD, :DWORD, :DWORD


.DATA
szTreeViewFindItemText      DB MAX_PATH DUP (0)
szTextViewFindSearchText    DB MAX_PATH DUP (0)

; do master loop calling to iterate child/next branches, if not found, then do another loop, getparent, check, if not get parents next, if not 0 do mini loop again.


.code

;**************************************************************************
; TreeViewFindItem - count child items under current item,
; if bRecurse is TRUE then it will count all grandchildren etc as well
;**************************************************************************
TreeViewFindItem PROC hTreeview:DWORD, hItem:DWORD, lpszFindText:DWORD
    LOCAL hCurrentItem:DWORD
    LOCAL hFoundItem:DWORD
    
    ;PrintText '----------------------'
    ;PrintText 'TreeViewFindItem'
    ;PrintDec hTreeview
    ;PrintDec hItem
    ;PrintDec lpszFindText
    ;PrintText '----------------------'
    
    .IF hTreeview == NULL || lpszFindText == NULL
        mov eax, 0
        ret
    .ENDIF
    
    Invoke lstrlen, lpszFindText
    .IF eax == 0
        mov eax, 0
        ret
    .ENDIF
    
    Invoke lstrcpy, Addr szTextViewFindSearchText, lpszFindText
    ;Invoke szUpper, Addr szTextViewFindSearchText
    
    mov hFoundItem, 0
    
    .IF hItem == NULL
        ;Invoke TreeViewGetSelectedItem, hTreeview
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax
    
    .WHILE eax != NULL
        mov hCurrentItem, eax

        Invoke TreeViewFindItemBranch, hTreeview, hCurrentItem, Addr szTextViewFindSearchText ;lpszFindText
        mov hFoundItem, eax
        
        .IF hFoundItem != 0
            ;PrintText 'found match in TreeViewFindItemBranch'
            ;.BREAK ; found our item so break out of loop
            mov eax, hFoundItem
            .BREAK
        .ENDIF
        
        ;PrintText 'no match found in TreeViewFindItemBranch, start looping up parent/next'
        mov eax, hCurrentItem
        .WHILE eax != NULL
            
            ;PrintText 'Looking for next sibling'
            
            Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
            .IF eax != NULL ; current item has a sibling, so go check that
                mov hCurrentItem, eax
                
                Invoke TreeViewFindTextCheckString, hTreeview, hCurrentItem, lpszFindText
                .IF eax == TRUE
                    mov eax, hCurrentItem
                    mov hFoundItem, eax
                    .BREAK
                .ENDIF
                
                ;Invoke TreeViewGetItemText, hTreeview, hCurrentItem, Addr szSelectedTreeviewText, SIZEOF szSelectedTreeviewText
                ;PrintString szSelectedTreeviewText
                
                mov eax, hCurrentItem
                mov hFoundItem, 0
                .BREAK                
            .ELSE
                ;PrintText 'Looking for parent of item'
                Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_PARENT, hCurrentItem
                .IF eax != NULL ; current item has no sibling so we goto parent, check that first
                    mov hCurrentItem, eax
                    mov eax, hCurrentItem
                    mov hFoundItem, 0
                    .CONTINUE ; didnt find our item in parent, so get parents sibling to check for
                 .ELSE ; top parent, no more parents to check so return 0
                    ;PrintText 'no more parents to check'
                    mov eax, NULL
                    mov hFoundItem, 0
                    .BREAK
                .ENDIF
            .ENDIF
            ; eax contains next sibling to check for or null (no sibling)
        .ENDW

        .IF hFoundItem != 0
            .BREAK ; found our item so break out of loop
        .ENDIF

    .ENDW

    ;PrintDec hFoundItem
    mov eax, hFoundItem
    ret

TreeViewFindItem ENDP


;**************************************************************************
; Finds text from current node down the current branch - all children under
; this node and their children
;**************************************************************************
TreeViewFindItemBranch PROC hTreeview:DWORD, hItem:DWORD, lpszFindText:DWORD
    LOCAL hCurrentItem:DWORD
    LOCAL hFoundItem:DWORD

    mov hFoundItem, 0
    
    .IF hItem == NULL
        ;Invoke TreeViewGetSelectedItem, hTreeview
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hCurrentItem, eax
    
    Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentItem
    .WHILE eax != NULL
        mov hCurrentItem, eax
        
        ; check if correct item
        Invoke TreeViewFindTextCheckString, hTreeview, hCurrentItem, lpszFindText
        .IF eax == TRUE
            mov eax, hCurrentItem
            mov hFoundItem, eax
            .BREAK
        .ELSE
            mov hFoundItem, 0
            Invoke TreeViewFindItemBranch, hTreeview, hCurrentItem, lpszFindText
            mov hFoundItem, eax
        .ENDIF
         
        .IF hFoundItem != 0
            .BREAK
        .ENDIF
         
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentItem
    .ENDW
    
    mov eax, hFoundItem
    ret

TreeViewFindItemBranch ENDP


;**************************************************************************
; TreeViewFindTextCheckString - check text matches, return true or false
;**************************************************************************
TreeViewFindTextCheckString PROC hTreeview:DWORD, hItem:DWORD, lpszFindText:DWORD
    Invoke TreeViewGetItemText, hTreeview, hItem, Addr szTreeViewFindItemText, MAX_PATH
    .IF eax != 0
        Invoke szLen, Addr szTreeViewFindItemText
        .IF eax == 0
            mov eax, FALSE
            ret
        .ENDIF
        Invoke TreeViewFindItemInString, 1, Addr szTreeViewFindItemText, lpszFindText
        .IF sdword ptr eax > 0 ;eax == 0 ; no found sdword ptr eax > 0
            mov eax, TRUE
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
TreeViewFindTextCheckString ENDP


;**************************************************************************
; InString function taken from masm32 library
;**************************************************************************
TreeViewFindItemInString PROC USES EBX ECX EDX EDI ESI startpos:DWORD, lpSource:DWORD, lpPattern:DWORD

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

TreeViewFindItemInString ENDP












