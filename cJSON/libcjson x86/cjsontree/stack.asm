CreateJSONStackItem         PROTO :DWORD
FreeJSONStackItem           PROTO :DWORD
GetJSONStackItemCount       PROTO :DWORD
SetJSONStackItemCount       PROTO :DWORD, :DWORD
IncJSONStackItemCount       PROTO :DWORD
CreateJSONArrayIteratorName PROTO :DWORD, :DWORD
DeleteStackItemsCallback    PROTO :DWORD, :DWORD


JSONSTACKITEM               STRUCT
    szItemName              DB 64 DUP (?) 
    dwItemCount             DD ?
JSONSTACKITEM               ENDS


.CODE


;-------------------------------------------------------------------------------------
; CreateJSONStackItem - Creates a JSONSTACKITEM json stack item
;-------------------------------------------------------------------------------------
CreateJSONStackItem PROC USES EBX lpszJsonItemName:DWORD
    LOCAL ptrJsonStackItem:DWORD
    
    .IF lpszJsonItemName == NULL
        mov eax, NULL
        ret
    .ENDIF
    
    Invoke szLen, lpszJsonItemName
    .IF eax == 0
        mov eax, NULL
        ret
    .ENDIF
    
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, SIZEOF JSONSTACKITEM
    .IF eax == NULL
        ret
    .ENDIF
    mov ptrJsonStackItem, eax
    mov ebx, eax
    lea eax, [ebx].JSONSTACKITEM.szItemName
    Invoke lstrcpyn, eax, lpszJsonItemName, 64d
    
    mov ebx, ptrJsonStackItem
    mov [ebx].JSONSTACKITEM.dwItemCount, 0
    
    mov eax, ptrJsonStackItem
    ret

CreateJSONStackItem ENDP


;-------------------------------------------------------------------------------------
; FreeJSONStackItem - Free JSONSTACKITEM item created by CreateJSONStackItem
;-------------------------------------------------------------------------------------
FreeJSONStackItem PROC ptrJsonStackItem:DWORD
    mov eax, ptrJsonStackItem
    .IF eax != NULL
        Invoke GlobalFree, eax
    .ENDIF
    xor eax, eax
    ret
FreeJSONStackItem ENDP


;-------------------------------------------------------------------------------------
; IncJSONStackItemCount - increments JSONSTACKITEM counter for use in next call to 
;CreateJSONArrayIteratorName
;-------------------------------------------------------------------------------------
IncJSONStackItemCount PROC USES EBX ptrJsonStackItem:DWORD
    .IF ptrJsonStackItem == NULL
        mov eax, 0
        ret
    .ENDIF
    mov ebx, ptrJsonStackItem
    mov eax, [ebx].JSONSTACKITEM.dwItemCount
    inc eax
    mov [ebx].JSONSTACKITEM.dwItemCount, eax
    ret
IncJSONStackItemCount ENDP


;-------------------------------------------------------------------------------------
; CreateJSONArrayIteratorName - Creates next array name: Thing[1], Thing[2], etc
;-------------------------------------------------------------------------------------
CreateJSONArrayIteratorName PROC USES EBX ptrJsonStackItem:DWORD, lpszNameBuffer:DWORD
    LOCAL dwCount:DWORD
    LOCAL szCount[16]:BYTE

    .IF ptrJsonStackItem == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    .IF lpszNameBuffer == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, ptrJsonStackItem
    mov eax, [ebx].JSONSTACKITEM.dwItemCount
    mov dwCount, eax
    lea eax, [ebx].JSONSTACKITEM.szItemName
    Invoke lstrcpyn, lpszNameBuffer, eax, 64d
    
    Invoke dwtoa, dwCount, Addr szCount
    Invoke szCatStr, lpszNameBuffer, Addr szLeftSquareBracket
    Invoke szCatStr, lpszNameBuffer, Addr szCount
    Invoke szCatStr, lpszNameBuffer, Addr szRightSquareBracket
    mov eax, TRUE
    ret
CreateJSONArrayIteratorName ENDP


;-------------------------------------------------------------------------------------
; DeleteStackItemsCallback - callback to clean up virtual stack that had array names 
; Calls FreeJSONStackItem to free JSONSTACKITEM items, only unique items, so we
; dont get an error trying to free memory we already freed
;-------------------------------------------------------------------------------------
DeleteStackItemsCallback PROC hStack:DWORD, ptrStackItem:DWORD
    
    .IF hStack == NULL
        ret   
    .ENDIF
    
    .IF ptrStackItem == NULL
        ret
    .ENDIF
    ;PrintText 'DeleteStackItemsCallback'
    ;PrintDec hStack
    ;PrintDec ptrStackItem
    Invoke FreeJSONStackItem, ptrStackItem
    ret

DeleteStackItemsCallback endp


;-------------------------------------------------------------------------------------
; GetJSONStackItemCount - Function not used currently
;-------------------------------------------------------------------------------------
GetJSONStackItemCount PROC USES EBX ptrJsonStackItem:DWORD
;    .IF ptrJsonStackItem == NULL
;        mov eax, 0
;        ret
;    .ENDIF
;    mov ebx, ptrJsonStackItem
;    mov eax, [ebx].JSONSTACKITEM.dwItemCount
    ret
GetJSONStackItemCount ENDP


;-------------------------------------------------------------------------------------
; SetJSONStackItemCount - Function not used currently
;-------------------------------------------------------------------------------------
SetJSONStackItemCount PROC USES EBX ptrJsonStackItem:DWORD, dwCountValue:DWORD
;    .IF ptrJsonStackItem == NULL
;        mov eax, 0
;        ret
;    .ENDIF
;    mov ebx, ptrJsonStackItem
;    mov eax, dwCountValue
;    mov [ebx].JSONSTACKITEM.dwItemCount, eax
    ret
SetJSONStackItemCount ENDP
