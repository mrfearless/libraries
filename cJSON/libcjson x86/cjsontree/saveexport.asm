CalcSaveSpaceRequired           PROTO :DWORD, :DWORD
Spaces                          PROTO :DWORD, :DWORD
SeperateNameValue               PROTO :DWORD, :DWORD, :DWORD
SeperateArrayName               PROTO :DWORD, :DWORD
TestWalk                        PROTO 
TestWalkCallback                PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
ExportJSONBranchToFile          PROTO :DWORD, :DWORD
SaveJSONBranchToFile            PROTO :DWORD, :DWORD, :DWORD
SaveJSONBranchProcess           PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD


SAVEJSON                        STRUCT
    dwOutputType                DD 0 ; 0 = clip, 1 = file
    ptrOutputData               DD 0
    dwBufferPos                 DD 0
SAVEJSON                        ENDS



.DATA
; JSON Export / Copy
szJSONExportStart               DB '{',13,10,0
szJSONExportEnd                 DB '}',13,10,0
szJSONExportObjectStart         DB '{',13,10,0
szJSONExportObjectEnd           DB '}',0;13,10,0
szJSONExportObjectCommaEnd      DB '},',13,10,0
szJSONExportArrayStart          DB '[',0 ;13,10,0
szJSONExportArrayEnd            DB ']',0;13,10,0
szJSONExportArrayEmpty          DB '[]',13,10,0
szJSONExportCRLF                DB 13,10,0
szJSONExportCommaCRLF           DB ',',13,10,0
szJSONExportMiddleString        DB '": "',0
szJSONExportMiddleOther         DB '": ',0
szJSONExportIndentSpaces        DB 32 DUP (32d)
szJSONExportSpacesBuffer        DB 32 DUP (0)

szJSONExportFileSuccess         DB 'JSON data exported to: ',0
szJSONExportFileFailed          DB 'Error exporting JSON data',0

dwLastItemType                  DD 0
dwLastLevel                     DD 0
dwLastStatus                    DD 0
dwTotalBytesToWrite             DD 0
SaveJsonData                    SAVEJSON <>
szTestFile                      DB "M:\radasm\Masm\projects\Test Projects\cjsontree\jsontest.json",0

.CODE



;-------------------------------------------------------------------------------------
; CalcSaveSpaceRequired - max space per item text length x no of items - to allocate mem
;-------------------------------------------------------------------------------------
CalcSaveSpaceRequired PROC hTreeview:DWORD, hItem:DWORD
    LOCAL dwChildrenCount:DWORD
    LOCAL dwMaxDepth:DWORD
    LOCAL dwItemTextLength:DWORD
    LOCAL dwMaxSize:DWORD
    
    Invoke TreeViewCountChildren, hTreeview, hItem, TRUE
    mov dwChildrenCount, eax
    
    Invoke TreeViewBranchDepth, hTreeview, hItem
    mov dwMaxDepth, eax
    
    mov eax, JSON_ITEM_MAX_TEXTLENGTH
    mov dwItemTextLength, eax
    
    ; per line no chars max (approx)
    mov eax, dwItemTextLength
    add eax, dwMaxDepth
    add eax, dwChildrenCount ; for ,
    add eax, 2 ; for cr lf for each line
    add eax, 4 ; for quote pairs
    add eax, dwChildrenCount ; for { (
    add eax, dwChildrenCount ; for } )
    
    mov ebx, dwChildrenCount ; eax x no of lines
    mul ebx
    mov dwMaxSize, eax
    
    ; for text items > 1024, have to realloc space for them
    ret

CalcSaveSpaceRequired ENDP


;-------------------------------------------------------------------------------------
; Spaces - add x amount of spaces to string
;-------------------------------------------------------------------------------------
Spaces PROC lpszBuffer:DWORD, nAmount:DWORD
    LOCAL nCount:DWORD
    mov nCount, 0
    mov eax, 0
    .WHILE eax <= nAmount
        Invoke szCatStr, lpszBuffer, Addr szSpace
        inc nCount
        mov eax, nCount
    .ENDW
    ret
Spaces ENDP


;-------------------------------------------------------------------------------------
; SeperateNameValue - seperates name and value from text string
;-------------------------------------------------------------------------------------
SeperateNameValue PROC USES EBX lpszString:DWORD, lpszName:DWORD, lpszValue:DWORD
    LOCAL dwColonPos:DWORD
    LOCAL LenString:DWORD
    
    .IF lpszString == 0
        mov ebx, lpszName
        mov byte ptr [ebx], 0
        mov ebx, lpszValue
        mov byte ptr [ebx], 0
        xor eax, eax
        ret
    .ENDIF
   
    Invoke szLen, lpszString
    mov LenString, eax 
    
    Invoke InString, 1, lpszString, Addr szColon
    mov dwColonPos, eax
    .IF eax != 0 ; match
        dec dwColonPos ; adjust for 1 based
        Invoke szLeft, lpszString, lpszName, dwColonPos
    .ELSE
        mov ebx, lpszName
        mov byte ptr [ebx], 0
        dec dwColonPos ; adjust for 1 based
    .ENDIF
    
    inc dwColonPos  ; adjust for 1 based
    mov ebx, dwColonPos
    mov eax, LenString
    sub eax, ebx
    .IF sdword ptr eax > 1
        dec eax ; skip any space
        Invoke szRight, lpszString, lpszValue, eax
    .ELSE
        mov ebx, lpszValue
        mov byte ptr [ebx], 0    
    .ENDIF
    ret

SeperateNameValue ENDP


;-------------------------------------------------------------------------------------
; SeperateArrayName - seperates array name from text string
;-------------------------------------------------------------------------------------
SeperateArrayName PROC USES EBX lpszString:DWORD, lpszName:DWORD
    LOCAL dwBracketPos:DWORD
    LOCAL LenString:DWORD
    
    .IF lpszString == 0
        mov ebx, lpszName
        mov byte ptr [ebx], 0
        xor eax, eax
        ret
    .ENDIF
   
    Invoke szLen, lpszString
    mov LenString, eax 
    
    Invoke InString, 1, lpszString, Addr szLeftSquareBracket
    mov dwBracketPos, eax
    .IF eax != 0 ; match
        dec dwBracketPos ; adjust for 1 based
        Invoke szLeft, lpszString, lpszName, dwBracketPos
    .ELSE
        mov ebx, lpszName
        mov byte ptr [ebx], 0
    .ENDIF

    ret

SeperateArrayName ENDP



TestWalk PROC USES EBX
    LOCAL hFile:DWORD
    LOCAL hItem:DWORD
    LOCAL dwDepth:DWORD
    LOCAL dwMaxSize:DWORD
    LOCAL pData:DWORD
    LOCAL dwTotalBytesWritten:DWORD
    
    mov dwLastItemType, 0
    mov dwLastLevel, 0
    mov dwLastStatus, 0
    mov dwTotalBytesToWrite, 0
    
    Invoke CreateFile, Addr szTestFile, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ+FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL
    .IF eax == INVALID_HANDLE_VALUE
        PrintText 'Failed to create output file'
        ret
    .ENDIF
    mov hFile, eax
    
    Invoke TreeViewGetSelectedItem, hTV
    .IF eax == 0
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ENDIF
    mov hItem, eax
    
    Invoke CalcSaveSpaceRequired, hTV, hItem
    mov dwMaxSize, eax
    PrintDec dwMaxSize
    
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, dwMaxSize
    .IF eax == NULL
        ret
    .ENDIF
    mov pData, eax    
    PrintDec pData
    
    lea ebx, SaveJsonData
    mov [ebx].SAVEJSON.ptrOutputData, eax
    mov [ebx].SAVEJSON.dwOutputType, 1
    
    Invoke TreeViewWalk, hTV, hItem, Addr TestWalkCallback, pData
    
    .IF sdword ptr dwTotalBytesToWrite > 0
        PrintDec dwTotalBytesToWrite
        Invoke SetFilePointer, hFile, 0, 0, FILE_BEGIN	
        Invoke WriteFile, hFile, pData, dwTotalBytesToWrite, Addr dwTotalBytesWritten, NULL
        .IF eax != TRUE
            Invoke GetLastError
            PrintDec eax
        .ENDIF
        Invoke SetEndOfFile, hFile
    .ENDIF
    Invoke GlobalFree, pData
    Invoke CloseHandle, hFile
    
    ret

TestWalk ENDP



TestWalkCallback PROC USES EBX hTreeview:DWORD, hItem:DWORD, dwStatus:DWORD, dwTotalItems:DWORD, dwItemNo:DWORD, dwLevel:DWORD, dwCustomData:DWORD
    LOCAL hJSON:DWORD
    LOCAL jsontype:DWORD
    
    

    
    Invoke TreeViewGetItemText, hTreeview, hItem, Addr szItemText, SIZEOF szItemText
    

    
    Invoke TreeViewGetItemParam, hTreeview, hItem
    mov hJSON, eax
    .IF hJSON == NULL
        ret
    .ENDIF
    mov ebx, eax
    mov eax, [ebx].cJSON.itemtype
    mov jsontype, eax
    
    PrintText '----------------'
    PrintDec dwLevel

    .IF dwStatus == TREEVIEWWALK_ITEM
        
        mov eax, dwLevel
        .IF eax == dwLastLevel
            mov eax, dwLastStatus
            .IF eax == dwStatus
                ;PrintText ','
                Invoke szCatStr, dwCustomData, Addr szJSONExportCommaCRLF
                add dwTotalBytesToWrite, 3
            .ELSE
                Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                add dwTotalBytesToWrite, 2
            .ENDIF
        .ELSE
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                ;PrintText ','
                Invoke szCatStr, dwCustomData, Addr szJSONExportCommaCRLF
                add dwTotalBytesToWrite, 3
            .ELSEIF eax == TREEVIEWWALK_ITEM_START
                mov eax, dwLevel
                ;dec eax
                add dwTotalBytesToWrite, eax     
            .ELSE
                Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                add dwTotalBytesToWrite, 2            
            .ENDIF        
        .ENDIF

        Invoke Spaces, dwCustomData, dwLevel
        mov eax, dwLevel
        ;dec eax
        add dwTotalBytesToWrite, eax        
    
        ;PrintText 'TREEVIEWWALK_ITEM'
        
        Invoke SeperateNameValue, Addr szItemText, Addr szItemTextString, Addr szItemTextValue
        PrintText 'SeperateNameValue'
        Invoke szLen, Addr szItemTextString
        PrintDec eax
        add dwTotalBytesToWrite, eax
        Invoke szLen, Addr szItemTextValue
        PrintDec eax
        add dwTotalBytesToWrite, eax
        
        

        Invoke szCatStr, dwCustomData, Addr szQuote
        Invoke szCatStr, dwCustomData, Addr szItemTextString
        
        mov eax, jsontype
        .IF eax == cJSON_String
            Invoke szCatStr, dwCustomData, Addr szJSONExportMiddleString
            Invoke szCatStr, dwCustomData, Addr szItemTextValue
            Invoke szCatStr, dwCustomData, Addr szQuote
            add dwTotalBytesToWrite, 7 ; quotes and stuff            
            
        .ELSEIF eax == cJSON_Number
            Invoke szCatStr, dwCustomData, Addr szJSONExportMiddleOther
            Invoke szCatStr, dwCustomData, Addr szItemTextValue
            add dwTotalBytesToWrite, 5 ; quotes and stuff 
            
        .ELSEIF eax == cJSON_True
            Invoke szCatStr, dwCustomData, Addr szJSONExportMiddleOther
            Invoke szCatStr, dwCustomData, Addr szItemTextValue
            add dwTotalBytesToWrite, 5 ; quotes and stuff 
            
        .ELSEIF eax == cJSON_False
            Invoke szCatStr, dwCustomData, Addr szJSONExportMiddleOther
            Invoke szCatStr, dwCustomData, Addr szItemTextValue
            add dwTotalBytesToWrite, 5 ; quotes and stuff 
            
        .ELSEIF eax == cJSON_NULL
            Invoke szCatStr, dwCustomData, Addr szJSONExportMiddleOther
            Invoke szCatStr, dwCustomData, Addr szItemTextValue
            add dwTotalBytesToWrite, 5 ; quotes and stuff 
        .ELSE
            PrintText 'Other'
            add dwTotalBytesToWrite, 5 ; quotes and stuff 
        .ENDIF
        
        PrintString szItemText
        ;Invoke szCatStr, dwCustomData, Addr szItemText
    

    
    .ELSEIF dwStatus == TREEVIEWWALK_ITEM_START
        ;PrintText 'TREEVIEWWALK_ITEM_START'

        mov eax, jsontype
        .IF eax == cJSON_Array

            Invoke Spaces, dwCustomData, dwLevel
            mov eax, dwLevel
            ;dec eax
            add dwTotalBytesToWrite, eax        
            
            Invoke SeperateArrayName, Addr szItemText, Addr szItemTextString
            
            Invoke szCatStr, dwCustomData, Addr szQuote
            Invoke szCatStr, dwCustomData, Addr szItemTextString
            Invoke szCatStr, dwCustomData, Addr szQuote
            Invoke szCatStr, dwCustomData, Addr szColon
            Invoke szCatStr, dwCustomData, Addr szSpace
            
            Invoke szLen, Addr szItemTextString
            add dwTotalBytesToWrite, eax
            add dwTotalBytesToWrite, 4 ; quotes and stuff
            
            PrintString szItemText
                    
            ;PrintText '['
            Invoke szCatStr, dwCustomData, Addr szJSONExportArrayStart
            add dwTotalBytesToWrite, 3
            
        .ELSEIF eax == cJSON_Object

            ;mov eax, dwLevel
            ;.IF eax == dwLastLevel
                mov eax, dwLastStatus
                .IF eax == TREEVIEWWALK_ITEM_FINISH
                    ;PrintText ','
                    Invoke szCatStr, dwCustomData, Addr szJSONExportCommaCRLF
                    add dwTotalBytesToWrite, 3
                .ELSE
                    Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                    add dwTotalBytesToWrite, 2     
                .ENDIF
            ;.ENDIF

            Invoke Spaces, dwCustomData, dwLevel
            mov eax, dwLevel
            ;dec eax
            add dwTotalBytesToWrite, eax
        
            ;PrintText '{'
            Invoke szCatStr, dwCustomData, Addr szJSONExportObjectStart
            add dwTotalBytesToWrite, 3
        .ENDIF
        
        
    .ELSEIF dwStatus == TREEVIEWWALK_ITEM_FINISH
        mov eax, jsontype
        .IF eax == cJSON_Array
            ;PrintText ']'
           
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                mov eax, dwLevel
                .IF eax == dwLastLevel            
                    ;PrintText ','
                    Invoke szCatStr, dwCustomData, Addr szJSONExportCommaCRLF
                    add dwTotalBytesToWrite, 3
                .ELSE
                    Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                    add dwTotalBytesToWrite, 2
                .ENDIF
            .ELSE
                Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                add dwTotalBytesToWrite, 2
            .ENDIF
            
            Invoke Spaces, dwCustomData, dwLevel
            mov eax, dwLevel
            ;dec eax
            add dwTotalBytesToWrite, eax            
            
            Invoke szCatStr, dwCustomData, Addr szJSONExportArrayEnd
            add dwTotalBytesToWrite, 1
            
        .ELSEIF eax == cJSON_Object
            ;PrintText '}'

;            Invoke Spaces, dwCustomData, dwLevel
;            mov eax, dwLevel
;            dec eax
;            add dwTotalBytesToWrite, eax
            
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                ;PrintText ','
                Invoke szCatStr, dwCustomData, Addr szJSONExportCommaCRLF
                add dwTotalBytesToWrite, 3            
            .ELSE
                Invoke szCatStr, dwCustomData, Addr szJSONExportCRLF
                add dwTotalBytesToWrite, 2  
            .ENDIF
            Invoke Spaces, dwCustomData, dwLevel
            mov eax, dwLevel
            ;dec eax
            add dwTotalBytesToWrite, eax
            
            Invoke szCatStr, dwCustomData, Addr szJSONExportObjectEnd
            add dwTotalBytesToWrite, 1
            
        .ENDIF    
        ;PrintString szItemText
    
        ;PrintText 'TREEVIEWWALK_ITEM_FINISH'
        .IF dwLevel == 0
            PrintText '=============='
            PrintDec dwItemNo
            PrintDec dwTotalItems
        .ENDIF
        
    .ELSEIF dwStatus == TREEVIEWWALK_ROOT_START
        PrintDec dwCustomData
        ;PrintText '{'
        Invoke szCatStr, dwCustomData, Addr szJSONExportStart
        add dwTotalBytesToWrite, 3
        
    .ELSEIF dwStatus == TREEVIEWWALK_ROOT_FINISH
        ;PrintText '}'
        Invoke szCatStr, dwCustomData, Addr szJSONExportEnd
        add dwTotalBytesToWrite, 3
        
    .ENDIF
    
    mov eax, jsontype
    mov dwLastItemType, eax
    
    mov eax, dwLevel
    mov dwLastLevel, eax
    
    mov eax, dwStatus
    mov dwLastStatus, eax
    
    ret

TestWalkCallback ENDP


;-------------------------------------------------------------------------------------
; SaveJSONBranchToFile - saves/exports json data to file
;-------------------------------------------------------------------------------------
ExportJSONBranchToFile PROC hWin:DWORD, hItem:DWORD
    LOCAL hItemExport:DWORD

    .IF hItem == 0
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_ROOT, NULL
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hItemExport, eax

    Invoke RtlZeroMemory, Addr ExportFile, SIZEOF ExportFile
    push hWin
    pop ExportFile.hwndOwner
    lea eax, JsonExportFileFilter
    mov ExportFile.lpstrFilter, eax
    lea eax, JsonExportFilename
    mov ExportFile.lpstrFile, eax
    lea eax, JsonExportFileFileTitle
    mov ExportFile.lpstrTitle, eax
    mov ExportFile.nMaxFile, SIZEOF JsonExportFilename
    lea eax, JsonExportDefExt
    mov ExportFile.lpstrDefExt, eax
    mov ExportFile.nFilterIndex, 1 ; json
    mov ExportFile.Flags, OFN_EXPLORER
    mov ExportFile.lStructSize, SIZEOF ExportFile
    Invoke GetSaveFileName, Addr ExportFile
    
    .IF eax !=0
        Invoke SaveJSONBranchToFile, hWin, Addr JsonExportFilename, hItemExport
        .IF eax == TRUE
            Invoke szCopy, Addr szJSONExportFileSuccess, Addr szJSONErrorMessage
            Invoke szCatStr, Addr szJSONErrorMessage, Addr JsonExportFilename
            Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
        .ELSE
            Invoke StatusBarSetPanelText, 2, Addr szJSONExportFileFailed
        .ENDIF
    .ENDIF
    ret
ExportJSONBranchToFile ENDP


;-------------------------------------------------------------------------------------
; SaveJSONBranchToFile - saves/exports json data to file
;-------------------------------------------------------------------------------------
SaveJSONBranchToFile PROC hWin:DWORD, lpszSaveFilename:DWORD, hItem:DWORD
    LOCAL hFile:DWORD
    LOCAL hItemSave:DWORD
    LOCAL dwDepth:DWORD
    LOCAL dwMaxSize:DWORD
    LOCAL pData:DWORD
    LOCAL dwTotalBytesWritten:DWORD
    LOCAL ReturnVal:DWORD
    
    mov dwLastItemType, 0
    mov dwLastLevel, 0
    mov dwLastStatus, 0
    mov dwTotalBytesToWrite, 0
    
    Invoke CloseJSONFileHandles, hWin
    
    .IF lpszSaveFilename == NULL
        PrintText 'no save filename specified'
        ret
    .ENDIF
    
    Invoke CreateFile, lpszSaveFilename, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ+FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL
    .IF eax == INVALID_HANDLE_VALUE
        PrintText 'Failed to create output file'
        mov eax, FALSE
        ret
    .ENDIF
    mov hFile, eax
    
    .IF hItem == 0
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_ROOT, NULL
        ;Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_CHILD, eax
        .IF eax == 0
            PrintText 'nothing to save'
            ret
        .ENDIF
    .ELSE
        mov eax, hItem
    .ENDIF
    mov hItemSave, eax
    
    Invoke CalcSaveSpaceRequired, hTV, hItemSave
    mov dwMaxSize, eax
    PrintDec dwMaxSize
    
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, dwMaxSize
    .IF eax == NULL
        mov eax, FALSE
        ret
    .ENDIF
    mov pData, eax    
    PrintDec pData
    
    Invoke TreeViewWalk, hTV, hItemSave, Addr SaveJSONBranchProcess, Addr pData
    
    Invoke szLen, pData
    mov dwTotalBytesToWrite, eax
    
    .IF sdword ptr dwTotalBytesToWrite > 0
        PrintDec dwTotalBytesToWrite
        Invoke SetFilePointer, hFile, 0, 0, FILE_BEGIN	
        Invoke WriteFile, hFile, pData, dwTotalBytesToWrite, Addr dwTotalBytesWritten, NULL
        .IF eax != TRUE
            Invoke GetLastError
            PrintDec eax
        .ENDIF
        Invoke SetEndOfFile, hFile
        mov ReturnVal, TRUE
    .ELSE
        mov ReturnVal, FALSE
    .ENDIF
    Invoke GlobalFree, pData
    Invoke CloseHandle, hFile
     
    mov eax, ReturnVal
    ret

SaveJSONBranchToFile ENDP


;-------------------------------------------------------------------------------------
; SaveJSONBranchProcess - callback from TreeViewWalk to format json data for
; save/export
;-------------------------------------------------------------------------------------
SaveJSONBranchProcess PROC USES EBX hTreeview:DWORD, hItem:DWORD, dwStatus:DWORD, dwTotalItems:DWORD, dwItemNo:DWORD, dwLevel:DWORD, dwCustomData:DWORD
    LOCAL hJSON:DWORD
    LOCAL jsontype:DWORD
    LOCAL pData:DWORD

    Invoke TreeViewGetItemText, hTreeview, hItem, Addr szItemText, SIZEOF szItemText
    Invoke TreeViewGetItemParam, hTreeview, hItem
    mov hJSON, eax
    .IF hJSON == NULL
        ret
    .ENDIF
    mov ebx, eax
    mov eax, [ebx].cJSON.itemtype
    mov jsontype, eax
    
    PrintString szItemText
    PrintDec jsontype
    
    mov ebx, dwCustomData
    mov eax, [ebx] ; ebx contains pointer to pData
    mov pData, eax

    mov eax, dwStatus
    ;-----------------------------------------------------------------------------
    .IF eax == TREEVIEWWALK_ITEM

        mov eax, dwLevel
        .IF eax == dwLastLevel
            mov eax, dwLastStatus
            .IF eax == dwStatus
                Invoke szCatStr, pData, Addr szJSONExportCommaCRLF
            .ELSE
                Invoke szCatStr, pData, Addr szJSONExportCRLF
            .ENDIF
        .ELSE
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                Invoke szCatStr, pData, Addr szJSONExportCommaCRLF
            .ELSEIF eax == TREEVIEWWALK_ITEM_START
  
            .ELSE
                Invoke szCatStr, pData, Addr szJSONExportCRLF
            .ENDIF        
        .ENDIF

        Invoke Spaces, pData, dwLevel

        Invoke SeperateNameValue, Addr szItemText, Addr szItemTextString, Addr szItemTextValue
        Invoke szCatStr, pData, Addr szQuote
        Invoke szCatStr, pData, Addr szItemTextString

        mov eax, jsontype
        .IF eax == cJSON_String
            Invoke szCatStr, pData, Addr szJSONExportMiddleString
            Invoke szCatStr, pData, Addr szItemTextValue
            Invoke szCatStr, pData, Addr szQuote
            
        .ELSEIF eax == cJSON_Number
            Invoke szCatStr, pData, Addr szJSONExportMiddleOther
            Invoke szCatStr, pData, Addr szItemTextValue
            
        .ELSEIF eax == cJSON_True
            Invoke szCatStr, pData, Addr szJSONExportMiddleOther
            Invoke szCatStr, pData, Addr szItemTextValue
            
        .ELSEIF eax == cJSON_False
            Invoke szCatStr, pData, Addr szJSONExportMiddleOther
            Invoke szCatStr, pData, Addr szItemTextValue
            
        .ELSEIF eax == cJSON_NULL
            Invoke szCatStr, pData, Addr szJSONExportMiddleOther
            Invoke szCatStr, pData, Addr szItemTextValue
        .ELSE

        .ENDIF


    ;-----------------------------------------------------------------------------
    .ELSEIF eax == TREEVIEWWALK_ITEM_START

        mov eax, jsontype
        .IF eax == cJSON_Array
            Invoke Spaces, pData, dwLevel
      
            Invoke SeperateArrayName, Addr szItemText, Addr szItemTextString
            Invoke szCatStr, pData, Addr szQuote
            Invoke szCatStr, pData, Addr szItemTextString
            Invoke szCatStr, pData, Addr szQuote
            Invoke szCatStr, pData, Addr szColon
            Invoke szCatStr, pData, Addr szSpace
            Invoke szCatStr, pData, Addr szJSONExportArrayStart

        .ELSEIF eax == cJSON_Object
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                Invoke szCatStr, pData, Addr szJSONExportCommaCRLF
            
            .ELSEIF eax == TREEVIEWWALK_ITEM_START
                mov eax, dwLastItemType
                .IF eax == cJSON_Array
                    Invoke szCatStr, pData, Addr szJSONExportCRLF
                .ENDIF
            
            .ELSEIF eax == TREEVIEWWALK_ROOT_START
                
            .ELSE
                Invoke szCatStr, pData, Addr szJSONExportCRLF
            .ENDIF
            Invoke Spaces, pData, dwLevel
            Invoke szCatStr, pData, Addr szJSONExportObjectStart
        .ENDIF


    ;-----------------------------------------------------------------------------
    .ELSEIF eax == TREEVIEWWALK_ITEM_FINISH

        mov eax, jsontype
        .IF eax == cJSON_Array
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                mov eax, dwLevel
                .IF eax == dwLastLevel            
                    Invoke szCatStr, pData, Addr szJSONExportCommaCRLF
                .ELSE
                    Invoke szCatStr, pData, Addr szJSONExportCRLF
                .ENDIF
            .ELSEIF eax == TREEVIEWWALK_ITEM_START
                mov eax, dwLastItemType
                .IF eax == cJSON_Array
                    ; []
                .ENDIF
            .ELSE
                Invoke szCatStr, pData, Addr szJSONExportCRLF
            .ENDIF
            Invoke Spaces, pData, dwLevel
            Invoke szCatStr, pData, Addr szJSONExportArrayEnd

        .ELSEIF eax == cJSON_Object
            mov eax, dwLastStatus
            .IF eax == TREEVIEWWALK_ITEM_FINISH
                Invoke szCatStr, pData, Addr szJSONExportCommaCRLF
            .ELSE
                Invoke szCatStr, pData, Addr szJSONExportCRLF
            .ENDIF
            Invoke Spaces, pData, dwLevel
            Invoke szCatStr, pData, Addr szJSONExportObjectEnd
        .ENDIF    


    ;-----------------------------------------------------------------------------
    .ELSEIF eax == TREEVIEWWALK_ROOT_START
        Invoke szCatStr, pData, Addr szJSONExportStart


    ;-----------------------------------------------------------------------------
    .ELSEIF eax == TREEVIEWWALK_ROOT_FINISH

        ;mov eax, dwLastStatus
        ;.IF eax == TREEVIEWWALK_ITEM_FINISH
            Invoke szCatStr, pData, Addr szJSONExportCRLF
        ;.ENDIF    
        Invoke szCatStr, pData, Addr szJSONExportEnd


    .ENDIF

    mov eax, jsontype
    mov dwLastItemType, eax
    mov eax, dwLevel
    mov dwLastLevel, eax
    mov eax, dwStatus
    mov dwLastStatus, eax

    mov eax, TRUE
    ret
SaveJSONBranchProcess ENDP
















