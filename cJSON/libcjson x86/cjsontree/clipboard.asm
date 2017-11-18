PasteJSON                       PROTO :DWORD
CopyToClipboard                 PROTO :DWORD, :DWORD
CopyBranchToClipboard           PROTO :DWORD
CopyItem                        PROTO :DWORD, :DWORD, :DWORD
PasteItem                       PROTO :DWORD, :DWORD

.DATA
; JSON Export / Copy
szJSONExportStart               DB '{',13,10,0
szJSONExportEnd                 DB '}',13,10,0
szJSONExportObjectStart         DB '{',13,10,0
szJSONExportObjectEnd           DB '}',13,10,0
szJSONExportObjectCommaEnd      DB '},',13,10,0
szJSONExportArrayStart          DB '[',13,10,0
szJSONExportArrayEnd            DB ']',13,10,0
szJSONExportArrayEmpty          DB '[]',13,10,0
szJSONExportCRLF                DB 13,10,0
szJSONExportCommaCRLF           DB ',',13,10,0
szJSONExportMiddleString        DB '": "',0
szJSONExportMiddleOther         DB '": ',0
szJSONExportIndentSpaces        DB 32 DUP (32d)
szJSONExportSpacesBuffer        DB 32 DUP (0)

szCopyTextSuccess               DB 'Copied json item text to clipboard',0
szCopyValueSuccess              DB 'Copied json item value to clipboard',0
szCopyTextEmpty                 DB 'json item text is empty, no text copied to clipboard',0
szCopyValueEmpty                DB 'json item value is empty, no text copied to clipboard',0
szCutItemSuccess                DB 'Cut: Currently selected json item copied',0
szCutBranchSuccess              DB 'Cut: Currently selected json branch item and children copied',0
szCopyItemSuccess               DB 'Copy: Currently selected json item copied',0
szCopyBranchSucces              DB 'Copy: Currently selected json branch item and children copied',0
szPasteItemSuccess              DB 'Paste: copied json item pasted',0
szPasteBranchSucces             DB 'Paste: copied json branch item and children pasted',0

szJSONLoadedClipData            DB 'Loaded JSON data from clipboard',0
szClipboardData                 DB '[clipboard data]',0
szJSONErrorClipData             DB 'Clipboard data does not contain valid JSON data',0
szJSONErrorEmptyClipData        DB 'JSON clipboard data is empty',0

szPasteFromClipboardJSON        DB 'Do you wish to paste JSON text from the clipboard?',0

szCopyPasteNodeText             DB JSON_ITEM_MAX_TEXTLENGTH DUP (0)

.CODE


;-------------------------------------------------------------------------------------
; PasteJSON - paste json from clipboard to create a tree
;-------------------------------------------------------------------------------------
PasteJSON PROC USES EBX hWin:DWORD
    LOCAL ptrClipData:DWORD

    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == FALSE
        ret
    .ENDIF
    
    Invoke MessageBox, hWin, Addr szPasteFromClipboardJSON, Addr AppName, MB_YESNO
    .IF eax == IDNO
        Invoke SetFocus, hTV
        ret
    .ENDIF
    
    Invoke CloseJSONFile, hWin

    Invoke OpenClipboard, hWin
    Invoke GetClipboardData, CF_TEXT
    .IF eax == NULL
        Invoke CloseClipboard
        xor eax, eax
        ret
    .ENDIF
    mov ptrClipData, eax
    Invoke ProcessJSONData, hWin, NULL, ptrClipData
    Invoke CloseClipboard
    ret
PasteJSON ENDP


;-------------------------------------------------------------------------------------
; Copies selected treeview item text to clipboard. if bValueOnly == TRUE then 
; extracts the value from the colon in the text and copies it to clipboard
;-------------------------------------------------------------------------------------
CopyToClipboard PROC USES EBX hWin:DWORD, bValueOnly:DWORD
    LOCAL ptrClipboardData:DWORD
    LOCAL hClipData:DWORD
    LOCAL pClipData:DWORD
    LOCAL LenData:DWORD
    
    Invoke OpenClipboard, hWin
    .IF eax == 0
        ret
    .ENDIF
    Invoke EmptyClipboard
    
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, JSON_ITEM_MAX_TEXTLENGTH ;1024d
    mov ptrClipboardData, eax
    
    Invoke TreeViewGetSelectedText, hTV, Addr szSelectedTreeviewText, SIZEOF szSelectedTreeviewText
    .IF eax == 0
        Invoke  StatusBarSetPanelText, 2, Addr szCopyTextEmpty
        Invoke GlobalFree, ptrClipboardData
        Invoke CloseClipboard
        ret
    .ENDIF
    Invoke szLen, Addr szSelectedTreeviewText
    mov LenData, eax
    
    .IF bValueOnly == TRUE
        Invoke InString, 1, Addr szSelectedTreeviewText, Addr szColon
        .IF eax == 0 ; no match
            Invoke  StatusBarSetPanelText, 2, Addr szCopyValueEmpty
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
        mov ebx, eax
        mov eax, LenData
        sub eax, ebx
        
        .IF sdword ptr eax > 1
            dec eax ; skip any space
        .ELSE
            Invoke  StatusBarSetPanelText, 2, Addr szCopyValueEmpty
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
        Invoke szRight, Addr szSelectedTreeviewText, ptrClipboardData, eax
        
        Invoke szLen, ptrClipboardData
        .IF eax == 0
            Invoke  StatusBarSetPanelText, 2, Addr szCopyValueEmpty
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
        mov LenData, eax
    .ELSE
        Invoke RtlMoveMemory, ptrClipboardData, Addr szSelectedTreeviewText, LenData
    .ENDIF
    
    .IF LenData == 0
        .IF bValueOnly == TRUE
            Invoke  StatusBarSetPanelText, 2, Addr szCopyValueEmpty
        .ELSE
            Invoke  StatusBarSetPanelText, 2, Addr szCopyTextEmpty
        .ENDIF
        Invoke GlobalFree, ptrClipboardData
        Invoke CloseClipboard
        ret
    .ENDIF
    
    mov eax, LenData
    inc eax
    Invoke GlobalAlloc, GMEM_MOVEABLE, eax ;+GMEM_DDESHARE
    .IF eax == NULL
        Invoke GlobalFree, ptrClipboardData
        Invoke CloseClipboard
        ret
    .ENDIF
    mov hClipData, eax
    
    Invoke GlobalLock, hClipData
    .IF eax == NULL
        Invoke GlobalFree, ptrClipboardData
        Invoke GlobalFree, hClipData
        Invoke CloseClipboard
        ret
    .ENDIF
    mov pClipData, eax
    mov eax, LenData
    Invoke RtlMoveMemory, pClipData, ptrClipboardData, eax
    
    Invoke GlobalUnlock, hClipData 
    invoke SetClipboardData, CF_TEXT, hClipData
    Invoke CloseClipboard

    Invoke GlobalFree, ptrClipboardData
    
    .IF bValueOnly == TRUE
        Invoke  StatusBarSetPanelText, 2, Addr szCopyValueSuccess
    .ELSE
        Invoke  StatusBarSetPanelText, 2, Addr szCopyTextSuccess
    .ENDIF
    
    ret
CopyToClipboard ENDP


;-------------------------------------------------------------------------------------
; Copies branch and all descendants to json formatted text to clipboard
;-------------------------------------------------------------------------------------
CopyBranchToClipboard PROC USES EBX hWin:DWORD
    LOCAL hCurrentChild:DWORD
    LOCAL hCheckItem:DWORD
    LOCAL LenData:DWORD
    LOCAL dwLevel:DWORD
    LOCAL dwSpacingLevel:DWORD
    LOCAL jsontype:DWORD
    LOCAL lpszItemName:DWORD
    LOCAL dwChildrenCount:DWORD
    LOCAL ptrClipboardData:DWORD
    LOCAL hClipData:DWORD
    LOCAL pClipData:DWORD
    LOCAL dwLenSelectedTreeviewText
    LOCAL dwColonPos:DWORD
    LOCAL dwMaxSize:DWORD
    
    Invoke TreeViewGetSelectedItem, hTV
    .IF eax == NULL
        ret
    .ENDIF
    mov hCurrentChild, eax
    
    mov dwLevel, 0
    mov dwSpacingLevel, 0

    Invoke TreeViewCountChildren, hTV, hCurrentChild, TRUE
    mov dwChildrenCount, eax
    IFDEF DEBUG32
    PrintDec dwChildrenCount
    ENDIF
    ; estimate space for clipboard: no children and items in branch x 1024d 
    ; (+ each item requires up to 4 quotes and comma, cr, lf) + indent spacing per line + brackets or array brackets pairs) (11)
    ; estimate 10 spaces per item for indenting (10)
    ; = 1048 x no children
    
    mov eax, dwChildrenCount
    mov ebx, JSON_ITEM_MAX_TEXTLENGTH 
    add ebx, 64d ;1048d
    mul ebx
    mov dwMaxSize, eax
    
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, dwMaxSize
    .IF eax == NULL
        ret
    .ENDIF
    mov ptrClipboardData, eax    

    Invoke OpenClipboard, hWin
    .IF eax == 0
        Invoke GlobalFree, ptrClipboardData
        ret
    .ENDIF
    Invoke EmptyClipboard



;szJSONExportStart           DB '{',13,10,0
;szJSONExportEnd             DB '}',13,10,0
;szJSONExportArrayStart      DB '[',13,10,0
;szJSONExportArrayEnd        DB ']',13,10,0
;szJSONExportArrayEmpty      DB '[]',13,10,0
;szJSONExportCRLF            DB 13,10,0
;szJSONExportCommaCRLF       DB ',',13,10,0
;szJSONExportMiddleString    DB '": "',0
;szJSONExportMiddleOther     DB '": ',0
;szJSONExportIndentSpaces    DB 32 DUP (32d)


    Invoke szCopy, Addr szJSONExportStart, ptrClipboardData

    Invoke TreeViewGetItemText, hTV, hCurrentChild, Addr szSelectedTreeviewText, SIZEOF szSelectedTreeviewText
    Invoke szLen, Addr szSelectedTreeviewText
    mov dwLenSelectedTreeviewText, eax
    Invoke TreeViewGetItemParam, hTV, hCurrentChild
    ;PrintDec eax
    .IF eax != NULL
        mov ebx, eax
        mov eax, [ebx].cJSON.itemtype
        mov jsontype, eax
        mov eax, [ebx].cJSON.itemstring
        mov lpszItemName, eax
        mov eax, [ebx].cJSON.valuestring
        mov lpszItemString, eax
        ;PrintDec jsontype
        mov eax, jsontype
        .IF eax == cJSON_Object
            IFDEF DEBUG32
            PrintText 'cJSON_Object'
            ENDIF
            Invoke szCatStr, ptrClipboardData, Addr szSpace
            Invoke szCatStr, ptrClipboardData, Addr szJSONExportObjectStart
            
            .IF lpszItemName != NULL
                Invoke szCatStr, ptrClipboardData, Addr szSpace
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                Invoke szCatStr, ptrClipboardData, lpszItemName
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                Invoke szCatStr, ptrClipboardData, Addr szColon                
            .ELSE
                ;Invoke szCatStr, ptrClipboardData, Addr szObject
            .ENDIF
            ;Invoke szCatStr, ptrClipboardData, Addr szJSONExportCRLF
        .ELSEIF eax == cJSON_Array
            IFDEF DEBUG32
            PrintText 'cJSON_Array'
            ENDIF
            Invoke szCatStr, ptrClipboardData, Addr szSpace
            Invoke szCatStr, ptrClipboardData, Addr szQuote
            .IF lpszItemName != NULL
                Invoke szCatStr, ptrClipboardData, lpszItemName
            .ELSE
                Invoke szCatStr, ptrClipboardData, Addr szArray
            .ENDIF
            Invoke szCatStr, ptrClipboardData, Addr szQuote
            Invoke szCatStr, ptrClipboardData, Addr szColon
            Invoke szCatStr, ptrClipboardData, Addr szSpace
            Invoke szCatStr, ptrClipboardData, Addr szLeftSquareBracket
            ;Invoke szCatStr, ptrClipboardData, Addr szJSONExportCRLF
        .ENDIF
        inc dwSpacingLevel
    .ENDIF
    IFDEF DEBUG32
    PrintText 'TVM_GETNEXTITEM, TVGN_CHILD'
    ENDIF
    push hCurrentChild
    Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentChild
    .WHILE eax != NULL
        mov hCurrentChild, eax      
        
        .IF dwSpacingLevel != 0
            Invoke szLeft, Addr szJSONExportIndentSpaces, Addr szJSONExportSpacesBuffer, dwSpacingLevel
            Invoke szCatStr, ptrClipboardData, Addr szJSONExportSpacesBuffer
        .ENDIF
        
        IFDEF DEBUG32
        PrintText 'TreeViewGetItemText hCurrentChild'
        ENDIF
        Invoke TreeViewGetItemText, hTV, hCurrentChild, Addr szSelectedTreeviewText, SIZEOF szSelectedTreeviewText
        .IF eax == 0
            IFDEF DEBUG32
            PrintText 'TreeViewGetItemText error'
            ENDIF
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
        
        IFDEF DEBUG32
        PrintText 'TreeViewGetItemText Length'
        ENDIF
        
        Invoke szLen, Addr szSelectedTreeviewText
        mov dwLenSelectedTreeviewText, eax
        
        IFDEF DEBUG32
        PrintString szSelectedTreeviewText
        ENDIF
        
        Invoke TreeViewGetItemParam, hTV, hCurrentChild
        ;PrintDec eax
        .IF eax != NULL
            mov ebx, eax
            mov eax, [ebx].cJSON.itemtype
            mov jsontype, eax
            mov eax, [ebx].cJSON.itemstring
            mov lpszItemName, eax
            mov eax, [ebx].cJSON.valuestring
            mov lpszItemString, eax
            ;PrintDec jsontype
            mov eax, jsontype
            .IF eax == cJSON_Object
                IFDEF DEBUG32
                PrintText 'cJSON_Object'
                ENDIF
                Invoke szCatStr, ptrClipboardData, Addr szJSONExportObjectStart
                ;Invoke szCatStr, ptrClipboardData, Addr szJSONExportSpacesBuffer
                
                .IF lpszItemName != NULL
                    Invoke szCatStr, ptrClipboardData, Addr szQuote
                    Invoke szCatStr, ptrClipboardData, lpszItemName
                    Invoke szCatStr, ptrClipboardData, Addr szQuote
                    Invoke szCatStr, ptrClipboardData, Addr szColon
                .ELSE
                    ;Invoke szCatStr, ptrClipboardData, Addr szObject
                .ENDIF
                inc dwSpacingLevel
 
            .ELSEIF eax == cJSON_Array
                IFDEF DEBUG32
                PrintText 'cJSON_Array'
                ENDIF
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                .IF lpszItemName != NULL
                    Invoke szCatStr, ptrClipboardData, lpszItemName
                .ELSE
                    Invoke szCatStr, ptrClipboardData, Addr szArray
                .ENDIF
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                Invoke szCatStr, ptrClipboardData, Addr szColon                
                Invoke szCatStr, ptrClipboardData, Addr szSpace
                Invoke szCatStr, ptrClipboardData, Addr szLeftSquareBracket
                inc dwSpacingLevel
                
            .ELSEIF eax == cJSON_String
                IFDEF DEBUG32
                PrintText 'cJSON_String'
                ENDIF
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                
                Invoke InString, 1, Addr szSelectedTreeviewText, Addr szColon
                mov dwColonPos, eax
                .IF eax != 0 ; match                
                    Invoke szLeft, Addr szSelectedTreeviewText, Addr szItemTextValue, dwColonPos
                    Invoke szCatStr, ptrClipboardData, Addr szItemTextValue
                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportMiddleString
                .ELSE
                    IFDEF DEBUG32
                    PrintText '!!!'
                    ENDIF
                .ENDIF
                
                mov ebx, dwColonPos
                mov eax, dwLenSelectedTreeviewText
                sub eax, ebx
                .IF sdword ptr eax > 1
                    dec eax ; skip any space
                    Invoke szRight, Addr szSelectedTreeviewText, Addr szItemTextValue, eax
                    Invoke szCatStr, ptrClipboardData, Addr szItemTextValue
                .ENDIF
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                
            .ELSEIF eax == cJSON_Number
                IFDEF DEBUG32
                PrintText 'cJSON_Number'
                ENDIF
            .ELSEIF eax == cJSON_True
                IFDEF DEBUG32
                PrintText 'cJSON_True'
                ENDIF
;                Invoke szCatStr, ptrClipboardData, Addr szQuote
;                Invoke InString, 1, Addr szSelectedTreeviewText, Addr szColon
;                mov dwColonPos, eax
;                .IF eax != 0 ; match
;                    Invoke szLeft, Addr szSelectedTreeviewText, Addr szItemTextValue, dwColonPos
;                    Invoke szCatStr, ptrClipboardData, Addr szItemTextValue
;                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportMiddleOther
;                .ELSE
;                    PrintText '!!!'
;                .ENDIF
;                mov ebx, dwColonPos
;                mov eax, dwLenSelectedTreeviewText
;                sub eax, ebx
;                dec eax
;                Invoke szRight, Addr szSelectedTreeviewText, Addr szItemTextValue, eax
;                Invoke szCatStr, ptrClipboardData, Addr szItemTextValue

                
            .ELSEIF eax == cJSON_False
                IFDEF DEBUG32
                PrintText 'cJSON_False'
                ENDIF
            .ELSEIF eax == cJSON_Invalid
                IFDEF DEBUG32
                PrintText 'cJSON_Invalid'
                ENDIF
            .ENDIF
            
            mov eax, jsontype
            .IF eax == cJSON_Number || eax == cJSON_True || eax == cJSON_False || eax == cJSON_Invalid
                Invoke szCatStr, ptrClipboardData, Addr szQuote
                Invoke InString, 1, Addr szSelectedTreeviewText, Addr szColon
                mov dwColonPos, eax
                .IF eax != 0 ; match
                    Invoke szLeft, Addr szSelectedTreeviewText, Addr szItemTextValue, dwColonPos
                    Invoke szCatStr, ptrClipboardData, Addr szItemTextValue
                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportMiddleOther
                .ELSE
                    IFDEF DEBUG32
                    PrintText '!!!'
                    ENDIF
                .ENDIF
                mov ebx, dwColonPos
                mov eax, dwLenSelectedTreeviewText
                sub eax, ebx
                .IF sdword ptr eax > 1
                    dec eax ; skip any space
                    Invoke szRight, Addr szSelectedTreeviewText, Addr szItemTextValue, eax
                    Invoke szCatStr, ptrClipboardData, Addr szItemTextValue
                .ENDIF
            .ENDIF
             
        .ENDIF
        
        
        mov LenData, eax
        
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_CHILD, hCurrentChild
        .IF eax != 0
            inc dwLevel
            inc dwSpacingLevel
            IFDEF DEBUG32
            PrintDec hCurrentChild
            ENDIF
            push hCurrentChild
            mov hCurrentChild, eax
        .ENDIF
        
        ;mov eax, hCurrentChild
        ;mov hCheckItem, eax
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentChild
        mov hCurrentChild, eax
        .IF eax == 0
            IFDEF DEBUG32
            PrintText 'TVM_GETNEXTITEM == 0 '
            ENDIF
            Invoke szCatStr, ptrClipboardData, Addr szJSONExportCRLF
            
            ; pop always, then check for last object type?
            
            .IF dwLevel != 0
                IFDEF DEBUG32
                PrintText 'dwLevel != 0'
                ENDIF
                dec dwLevel
                dec dwSpacingLevel
                pop hCurrentChild
                mov eax, hCurrentChild
                mov hCheckItem, eax
                Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_NEXT, hCurrentChild
                mov hCurrentChild, eax
                
                .IF dwSpacingLevel != 0
                    Invoke szLeft, Addr szJSONExportIndentSpaces, Addr szJSONExportSpacesBuffer, dwSpacingLevel
                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportSpacesBuffer                
                .ENDIF
                
                mov eax, hCurrentChild
                .IF eax == 0
                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportObjectEnd
                .ELSE
                    Invoke szCatStr, ptrClipboardData, Addr szJSONExportObjectCommaEnd
                .ENDIF
                IFDEF DEBUG32
                PrintText 'Checking Last objects'
                PrintDec hCheckItem
                ENDIF
                Invoke TreeViewGetItemParam, hTV, hCheckItem
                ;PrintDec eax
                .IF eax != NULL
                    mov ebx, eax
                    mov eax, [ebx].cJSON.itemtype                
                    .IF eax == cJSON_Object
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Object'
                        ENDIF
                    .ELSEIF eax == cJSON_Array
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Array'
                        ENDIF
                    .ENDIF
                .ENDIF                
                
            .ELSE
                IFDEF DEBUG32
                PrintText 'dwLevel == 0'
                ENDIF
                pop hCurrentChild
                mov eax, hCurrentChild
                mov hCheckItem, eax
                
                IFDEF DEBUG32
                PrintText 'Checking Last objects'
                PrintDec hCheckItem
                ENDIF
                Invoke TreeViewGetItemParam, hTV, hCheckItem
                ;PrintDec eax
                .IF eax != NULL
                    mov ebx, eax
                    mov eax, [ebx].cJSON.itemtype                
                    .IF eax == cJSON_Object
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Object'
                        ENDIF
                    .ELSEIF eax == cJSON_Array
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Array'
                        ENDIF
                    .ENDIF
                .ENDIF                   
                
            .ENDIF
        .ELSE
            mov eax, jsontype
            .IF eax == cJSON_Object || eax == cJSON_Array
                ;Invoke szCatStr, ptrClipboardData, Addr szJSONExportCRLF
            .ELSE
                Invoke szCatStr, ptrClipboardData, Addr szJSONExportCommaCRLF
            .ENDIF
        .ENDIF

        mov eax, hCurrentChild
    .ENDW

    pop hCurrentChild
                mov eax, hCurrentChild
                mov hCheckItem, eax
               Invoke TreeViewGetItemParam, hTV, hCheckItem
                ;PrintDec eax
                .IF eax != NULL
                    mov ebx, eax
                    mov eax, [ebx].cJSON.itemtype                
                    .IF eax == cJSON_Object
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Object'
                        ENDIF
                    .ELSEIF eax == cJSON_Array
                        IFDEF DEBUG32
                        PrintText 'Last objects: cJSON_Array'
                        ENDIF
                    .ENDIF
                .ENDIF                       
    
    
    Invoke szCatStr, ptrClipboardData, Addr szJSONExportEnd 


    ;DbgDump ptrClipboardData, dwMaxSize
    
    Invoke szLen, ptrClipboardData
    mov LenData, eax
    inc eax
    Invoke GlobalAlloc, GMEM_MOVEABLE, eax ;+GMEM_DDESHARE
    .IF eax == NULL
        Invoke GlobalFree, ptrClipboardData
        Invoke CloseClipboard
        ret
    .ENDIF
    mov hClipData, eax
    
    Invoke GlobalLock, hClipData
    .IF eax == NULL
        Invoke GlobalFree, ptrClipboardData
        Invoke GlobalFree, hClipData
        Invoke CloseClipboard
        ret
    .ENDIF
    mov pClipData, eax
    mov eax, LenData
    Invoke RtlMoveMemory, pClipData, ptrClipboardData, eax
    
    Invoke GlobalUnlock, hClipData 
    invoke SetClipboardData, CF_TEXT, hClipData

    Invoke CloseClipboard
    Invoke GlobalFree, ptrClipboardData

    ret
CopyBranchToClipboard ENDP


;-------------------------------------------------------------------------------------
; Copy node item
;-------------------------------------------------------------------------------------
CopyItem PROC USES EBX hWin:DWORD, hItem:DWORD, bCut:DWORD
    LOCAL tvhi:TV_HITTESTINFO
    
    .IF hItem == NULL
        Invoke TreeViewGetSelectedItem, hTV
        .IF eax == 0
            Invoke GetCursorPos, Addr tvhi.pt
            Invoke ScreenToClient, hTV, addr tvhi.pt
            Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi        
            mov eax, tvhi.hItem
        .ENDIF
    .ELSE
        mov eax, hItem
    .ENDIF
    mov g_hCutCopyNode, eax
    
    .IF eax != 0
        .IF bCut == TRUE
            mov g_Cut, TRUE
            Invoke  StatusBarSetPanelText, 2, Addr szCutItemSuccess
        .ELSE
            mov g_Cut, FALSE
            Invoke  StatusBarSetPanelText, 2, Addr szCopyItemSuccess
        .ENDIF
    .ENDIF
    ;PrintDec g_hCutCopyNode
    
    ret
CopyItem ENDP


;-------------------------------------------------------------------------------------
; Paste node item
;-------------------------------------------------------------------------------------
PasteItem PROC USES EBX hWin:DWORD, hItem:DWORD
    LOCAL tvhi:TV_HITTESTINFO
    LOCAL tvi:TV_ITEM
    LOCAL hPasteToNode:DWORD
    LOCAL hCopyFromNode:DWORD
    LOCAL hNewNode:DWORD
    LOCAL hJSONCopyFrom:DWORD
    LOCAL hJSONPasteTo:DWORD
    LOCAL hJSONNew:DWORD
    LOCAL hJSONPrev:DWORD
    ;LOCAL dwJsonType:DWORD
    LOCAL nIcon:DWORD
    LOCAL hItemPrev:DWORD
    
    .IF g_hCutCopyNode == 0
        ret
    .ELSE
        mov eax, g_hCutCopyNode
        mov hCopyFromNode, eax
    .ENDIF
    
    mov eax, hItem
    .IF eax == 0
        Invoke TreeViewGetSelectedItem, hTV
        .IF eax == 0
            Invoke GetCursorPos, Addr tvhi.pt
            Invoke ScreenToClient, hTV, addr tvhi.pt
            Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi        
            mov eax, tvhi.hItem
        .ENDIF
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hPasteToNode, eax
    
    .IF hPasteToNode == 0
        ret
    .ENDIF
    
    IFDEF DEBUG32
    ;PrintDec hCopyFromNode
    ;PrintDec hPasteToNode
    ENDIF
    
    ; got copy and paste nodes
    Invoke RtlZeroMemory, Addr szCopyPasteNodeText, SIZEOF szCopyPasteNodeText
    Invoke TreeViewGetItemText, hTV, hCopyFromNode, Addr szCopyPasteNodeText, SIZEOF szCopyPasteNodeText
    Invoke TreeViewGetItemParam, hTV, hCopyFromNode
    mov hJSONCopyFrom, eax
    Invoke TreeViewGetItemImage, hTV, hCopyFromNode
    mov nIcon, eax
    ; Create a JSON object for our new item
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, SIZEOF cJSON
    mov hJSONNew, eax
    ; copy contents
    Invoke RtlMoveMemory, hJSONNew, hJSONCopyFrom, SIZEOF cJSON

    IFDEF DEBUG32
    ;PrintDec hJSONCopyFrom
    ;PrintDec hJSONNew
    ;PrintDec nIcon
    ENDIF
    
    ;mov ebx, hJSONCopyFrom
    ;mov eax, [ebx].cJSON.itemtype
    ;mov dwJsonType, eax
    
    ; store our handle to mem inside hJSONNew structure
    mov ebx, hJSONNew
    mov eax, hJSONNew
    mov [ebx].cJSON.valueint, eax ; store handle in this value
    mov dword ptr [ebx].cJSON.valuedouble, eax ; store handle in this value
    mov [ebx].cJSON.prev, 0
    mov [ebx].cJSON.next, 0
    mov [ebx].cJSON.child, 0
    
    ; add new child ref to pasted node if it hasnt got a child already
    Invoke TreeViewGetItemParam, hTV, hPasteToNode
    mov hJSONPasteTo, eax
    .IF eax != NULL
        mov ebx, hJSONPasteTo
        mov eax, [ebx].cJSON.child
        .IF eax == 0
            mov ebx, hJSONPasteTo
            mov eax, hJSONNew
            mov [ebx].cJSON.child, eax
        .ENDIF
    .ENDIF

    Invoke TreeViewInsertItem, hTV, hPasteToNode, Addr szCopyPasteNodeText, g_nTVIndex, TVI_LAST, nIcon, nIcon, hJSONPasteTo
    mov hNewNode, eax
    inc g_nTVIndex
    
    Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_PREVIOUS, hNewNode
    .IF eax != NULL
        mov hItemPrev, eax
        Invoke TreeViewGetItemParam, hTV, hItemPrev
        .IF eax != NULL
            mov hJSONPrev, eax
            mov ebx, eax
            mov eax, hJSONNew
            mov [ebx].cJSON.next, eax
            
            mov ebx, hJSONNew
            mov eax, hJSONPrev
            mov [ebx].cJSON.prev, eax
        .ENDIF
    .ENDIF

    .IF g_Cut == TRUE
        
        ; delete previous
        
        mov g_Cut, FALSE
        mov g_hCutCopyNode, NULL
        
    .ENDIF
    
    Invoke  StatusBarSetPanelText, 2, Addr szPasteItemSuccess    

    mov g_Edit, TRUE
    Invoke SaveMenuState, hWin, TRUE
    Invoke SaveToolbarState, hWin, TRUE

    ;Invoke TreeViewSetSelectedItem, hTV, hNewNode, TRUE
    ;Invoke TreeViewItemExpand, hTV, hNewNode
    
    ret
PasteItem ENDP






















