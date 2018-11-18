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
includelib user32.lib

include Listview.inc


_LVFindItemInStringSearch           PROTO :QWORD, :QWORD, :QWORD
_LVFindItemUpperString              PROTO :QWORD


EXTERNDEF ListViewGetColumnCount    :PROTO :QWORD
EXTERNDEF ListViewGetItemCount      :PROTO :QWORD
EXTERNDEF ListViewDeselectAll       :PROTO :QWORD, :QWORD
EXTERNDEF ListViewGetItemText       :PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD
EXTERNDEF ListViewEnsureVisible     :PROTO :QWORD, :QWORD
EXTERNDEF ListViewSetSelected       :PROTO :QWORD, :QWORD, :QWORD

.CONST
LVFI_ERR    EQU -2
LVFI_END    EQU -1

.CODE

;**************************************************************************	
; ListViewFindItem
;
; LVM_FINDITEM can only find a string in the first Column
;
; This function will search for a matching string, 
; (which can be case-sensitive) in all columns / subitems specified, and
; optionally select the matching item.
;
; Adapted from: http://www.winasm.net/forum/index.php?showtopic=3934
;
; if qwStartCol is -1 & qwEndCol is -1, search will include all columns.
; Otherwise can be used to limit search to a particular column / subitem.
;
; if qwStartItem is -1 or -2, search will start at listview item 0
; Otherwise search will start at item specified.
;
; if qwStartSubItem is -1 or -2, search will start at qwStartCol 
; (or column 0 if qwStartCol is -1) 
; Otherwise search will start at column / subitem specified.
;
; Returns in RAX:
; * Item (>=0)    - Item that was found to match.
; * LVFI_END (-1) - Not found, no more items left to search.
; * LVFI_ERR (-2) - An error occured.
;
; Returns in RBX: 
; * SubItem (>=0) - SubItem that was found to match.
; * LVFI_END (-1) - Not found, no more items left to search.
; * LVFI_ERR (-2) - An error occured.
;
;
; Example: Searching a single column / subitem
;
; .DATA
; FoundItem     DQ -1
; FoundSubitem  DQ -1
; TotalItems    DQ 0
; .CODE
; Invoke ListViewGetItemCount, hLV
; mov TotalItems, rax
; ...
; ...
; Invoke ListViewFindItem, hLV, Addr szFindStuff, FoundItem, FoundSubitem, 1, 1, TRUE, FALSE
; mov FoundItem, rax
; mov FoundSubitem, rbx
; .IF rax >= 0 ; match found
;     ; Do some processing on found item and subitem if required.
;     ; Once done with that, increment FoundItem to prepare next search
;     ; to start from the last found item. 
;     ; Or start from beginning again if we are at the last item in listview.
;     mov rax, FoundItem
;     inc rax
;     .IF rax < TotalItems
;         inc FoundItem
;         mov FoundSubitem, -1
;     .ELSE
;         mov FoundItem, -1
;         mov FoundSubitem, -1
;     .ENDIF
; .ELSE
;     ; Nothing found, all items where searched
;     ; or an error occured.
; .ENDIF
;
;
;**************************************************************************	
ListViewFindItem PROC FRAME hListview:HWND, lpszFindString:QWORD, qwStartItem:QWORD, qwStartSubItem:QWORD, qwStartCol:QWORD, qwEndCol:QWORD, bShowFoundItem:QWORD, bCaseSensitive:QWORD
    LOCAL lvi:LV_ITEM
    LOCAL buffer[256]:QWORD
    LOCAL findstring[256]:QWORD
    LOCAL nRows:QWORD
    LOCAL nColumns:QWORD
    LOCAL nItem:QWORD
    LOCAL nSubItem:QWORD
    LOCAL LenFindString:QWORD
    LOCAL LenBufferString:QWORD
    LOCAL nStartCol:QWORD
    LOCAL nEndCol:QWORD
    LOCAL nStartItem:QWORD
    LOCAL bSubItemStart:QWORD
    
    Invoke lstrlen, lpszFindString
    .IF rax == 0
        mov rax, LVFI_ERR
        mov rbx, LVFI_ERR
        ret
    .ENDIF
    mov LenFindString, rax
    
    Invoke ListViewGetColumnCount, hListview
    mov nColumns, rax
    .IF nColumns != 0
        ; 0 base the column count
        dec nColumns
        dec rax
    .ENDIF
    .IF qwEndCol == -1
        mov nEndCol, rax
    .ELSE
        mov rax, qwEndCol
        mov nEndCol, rax
    .ENDIF
    
    .IF qwStartCol == -1
        mov nStartCol, 0
    .ELSE
        mov rax, qwStartCol
        mov nStartCol, rax
    .ENDIF
    
    mov rax, nStartCol
    .IF rax > nEndCol
        mov rax, LVFI_ERR
        mov rbx, LVFI_ERR
        ret
    .ENDIF
    
    mov rax, qwStartItem
    mov nStartItem, rax
    
    Invoke lstrcpy, Addr findstring, lpszFindString
    .IF bCaseSensitive == FALSE
        Invoke _LVFindItemUpperString, Addr findstring
    .ENDIF
    
    Invoke ListViewGetItemCount, hListview
    mov nRows, rax
    
;    .IF qwStartItem == -1 && qwStartSubItem == -1
;        Invoke ListViewDeselectAll, hListview
;    .ENDIF
    
    ; If we are starting search from a subitem
    ; we set a flag so its only triggered once
    ; then normal start col to end col search
    ; continues as normal
    mov rax, qwStartSubItem
    .IF rax == -1 || rax == -2
        mov bSubItemStart, FALSE
    .ELSE
        mov rax, qwStartCol
        .IF rax == qwEndCol ; if columns the same, ignore startcol
            mov bSubItemStart, FALSE
        .ELSE
            ; check start subitem is within search cols
            .IF rax < nStartCol 
                mov rax, LVFI_ERR
                mov rbx, LVFI_ERR
                ret
            .ELSEIF rax > nEndCol 
                mov rax, nStartItem
                inc rax
                .IF rax < nRows ; try next item if possible
                    inc nStartItem
                    mov bSubItemStart, FALSE
                .ELSE
                    mov rax, LVFI_END
                    mov rbx, LVFI_END
                    ret
                .ENDIF
            .ELSE
                mov bSubItemStart, TRUE
            .ENDIF
        .ENDIF
    .ENDIF
    
    ; Check start item
    mov rax, nStartItem
    .IF rax == -1 || rax == -2
        mov rax, 0
    .ELSEIF rax >= nRows
        mov rax, LVFI_END
        mov rbx, LVFI_END
        ret
    .ELSE
        mov rax, nStartItem
    .ENDIF
    mov nItem, rax
    
    .WHILE rax < nRows
    
        .IF bSubItemStart == TRUE
            mov bSubItemStart, FALSE
            mov rax, qwStartSubItem
        .ELSE
            mov rax, nStartCol
        .ENDIF
        mov nSubItem, rax
        
        mov rbx, nStartCol
        .WHILE rbx <= nEndCol
            Invoke ListViewGetItemText, hListview, nItem, nSubItem, Addr buffer, SIZEOF buffer
            .IF rax == 0
                inc nSubItem
                mov rbx, nSubItem
                .continue
            .ENDIF 

            Invoke lstrlen, Addr buffer
            mov LenBufferString, rax
            .IF rax == 0
                inc nSubItem
                mov rbx, nSubItem            
                .continue
            .ENDIF
            
            .IF bCaseSensitive == FALSE
                Invoke _LVFindItemUpperString, Addr buffer
            .ENDIF
            
;            IFDEF DEBUG32
;            lea rax, buffer
;            mov DbgVar1, rax
;            mov rax, lpszFindString
;            mov DbgVar2, rax
;            PrintStringByAddr DbgVar1
;            PrintStringByAddr DbgVar2
;            ENDIF
            
            mov rax, LenFindString
            .IF rax == LenBufferString ; if same do str compare
                Invoke lstrcmpi, Addr buffer, Addr findstring ;lpszFindString
                .IF rax == 0
                    .IF bShowFoundItem == TRUE
                        ;Invoke ListViewDeselectAll, hListview
                        Invoke ListViewSetSelected, hListview, nItem, TRUE
                        Invoke ListViewEnsureVisible, hListview, nItem
                        mov rax, nItem
                        mov rbx, nSubItem
                        ret
                    .ELSE
                        mov rax, nItem
                        mov rbx, nSubItem
                        ret
                    .ENDIF
                .ENDIF

            .ELSEIF rax < LenBufferString
                Invoke _LVFindItemInStringSearch, 1, Addr buffer, Addr findstring ;lpszFindString
                IFDEF DEBUG32
                PrintDec rax
                ENDIF
                .IF rax > 0
                    .IF bShowFoundItem == TRUE
                        ;Invoke ListViewDeselectAll, hListview
                        Invoke ListViewSetSelected, hListview, nItem, TRUE
                        Invoke ListViewEnsureVisible, hListview, nItem
                        mov rax, nItem
                        mov rbx, nSubItem
                        ret
                    .ELSE
                        mov rax, nItem
                        mov rbx, nSubItem
                        ret
                    .ENDIF
                .ENDIF
            
            .ELSE ; do nothing as findstring > than buffer string
                
            .ENDIF
            inc nSubItem
            mov rbx, nSubItem            
        .ENDW
        inc nItem
        mov rax, nItem
    .ENDW
    
    ;Nothing found / end of listview
    mov rax, LVFI_END
    mov rbx, LVFI_END
    ret
ListViewFindItem endp



align 8
_LVFindItemInStringSearch PROC FRAME USES RBX RCX RDX RDI RSI startpos:QWORD,lpSource:QWORD,lpPattern:QWORD

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


    invoke lstrlen,lpSource
    mov sLen, rax           ; source length
    invoke lstrlen,lpPattern
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

_LVFindItemInStringSearch endp


align 8
_LVFindItemUpperString proc FRAME text:QWORD

  ; -----------------------------
  ; converts string to upper case
  ; invoke szUpper,ADDR szString
  ; -----------------------------

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

_LVFindItemUpperString endp


end