JSONNew                         PROTO :DWORD                        ; 'Creates' a new json file state. New treeview items can be added to this and saved 

JSONAddItem                     PROTO :DWORD, :DWORD                ; Add a json item to the treeview
JSONDelItem                     PROTO :DWORD                        ; Delete a json item from the treeview
JSONEditItem                    PROTO :DWORD                        ; Edit currently selected treeview item text

JSONCreateItem                  PROTO :DWORD, :DWORD, :DWORD        ; called from JSONAddItem and JSONPasteItem to create new json item
JSONRemoveItem                  PROTO :DWORD, :DWORD                ; called from JSONDelItem and JSONPasteItem (cut mode) to detach and delete json object


.DATA
szNewObject                     DB 'Object: ',0
szNewArray                      DB 'Array[]: ',0
szNewString                     DB 'New Item: ',0
szNewTrue                       DB 'New Item: true',0
szNewFalse                      DB 'New Item: false',0
szNewNumber                     DB 'New Item: 0',0
szNewNull                       DB 'New Item: null',0

.CODE


;-------------------------------------------------------------------------------------
; Creates a new json treeview
;-------------------------------------------------------------------------------------
JSONNew PROC USES EBX hWin:DWORD
    Invoke JSONFileClose, hWin

    Invoke cJSON_CreateObject
    mov hJSON_Object_Root, eax
    
    Invoke StatusBarSetPanelText, 2, Addr szJSONCreatedNewData
    Invoke SetWindowTitle, hWin, Addr szJSONNew
    mov g_nTVIndex, 0
    Invoke TreeViewItemInsert, hTV, NULL, Addr szJSONNewData, g_nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    mov hTVRoot, eax
    inc g_nTVIndex
    Invoke TreeViewSetSelectedItem, hTV, hTVRoot, TRUE
    Invoke TreeViewItemExpand, hTV, hTVRoot
    ret
JSONNew ENDP


;-------------------------------------------------------------------------------------
; Add a new json item (treeview item) under current branch
;-------------------------------------------------------------------------------------
JSONAddItem PROC USES EBX hWin:DWORD, dwJsonType:DWORD
    LOCAL hJSON:DWORD
    LOCAL hJSONAdd:DWORD
    LOCAL nIcon:DWORD
    LOCAL hTVItem:DWORD
    LOCAL bArray:DWORD
    LOCAL hJSONObjectString:DWORD
    
    Invoke TreeViewGetSelectedItem, hTV
    mov hTVNode, eax
    .IF eax == NULL
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_ROOT, NULL
        mov hTVNode, eax
        .IF eax == NULL
            ret
        .ENDIF
    .ENDIF
    
    Invoke JSONCreateItem, hTV, hTVNode, dwJsonType
    mov hJSONAdd, eax

    .IF hJSONAdd == 0
        ;PrintText 'hJSONAdd == 0'
        ret
    .ENDIF

    mov eax, dwJsonType
    .IF eax == cJSON_Object
        mov eax, IL_ICO_JSON_OBJECT
        mov nIcon, eax
        Invoke szCopy, Addr szNewObject, Addr szItemText
        
    .ELSEIF eax == cJSON_Array
        mov eax, IL_ICO_JSON_ARRAY
        mov nIcon, eax
        Invoke szCopy, Addr szNewArray, Addr szItemText

    .ELSEIF eax == cJSON_String
        mov eax, IL_ICO_JSON_STRING
        mov nIcon, eax
        Invoke szCopy, Addr szNewString, Addr szItemText
      
    .ELSEIF eax == cJSON_Number
        mov eax, IL_ICO_JSON_NUMBER
        mov nIcon, eax
        Invoke szCopy, Addr szNewNumber, Addr szItemText
     
    .ELSEIF eax == cJSON_True
        mov eax, IL_ICO_JSON_LOGICAL
        mov nIcon, eax
        Invoke szCopy, Addr szNewTrue, Addr szItemText

    .ELSEIF eax == cJSON_False
        mov eax, IL_ICO_JSON_LOGICAL
        mov nIcon, eax
        Invoke szCopy, Addr szNewFalse, Addr szItemText

    .ELSEIF eax == cJSON_NULL
        mov eax, IL_ICO_JSON_NULL
        mov nIcon, eax
        Invoke szCopy, Addr szNewNull, Addr szItemText

    .ENDIF

    .IF hJSONAdd != NULL
        mov g_Edit, TRUE
        Invoke MenuSaveEnable, hWin, TRUE
        Invoke MenuSaveAsEnable, hWin, TRUE
        Invoke ToolbarButtonSaveEnable, hWin, TRUE
        Invoke ToolbarButtonSaveAsEnable, hWin, TRUE

        Invoke TreeViewItemInsert, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, nIcon, nIcon, hJSONAdd
        mov hTVItem, eax
        inc g_nTVIndex
        Invoke TreeViewItemExpand, hTV, hTVNode
        Invoke TreeViewSetSelectedItem, hTV, hTVItem, TRUE
        Invoke TreeViewItemExpand, hTV, hTVItem
        Invoke SendMessage, hTV, TVM_EDITLABEL, 0, hTVItem
    .ENDIF
    
    ret
JSONAddItem ENDP


;-------------------------------------------------------------------------------------
; Deletes a selected json item (treeview item)
; detachs json item from parent item and deletes the cJSON items and children
;-------------------------------------------------------------------------------------
JSONDelItem PROC USES EBX hWin:DWORD
    LOCAL hItem:DWORD
    LOCAL hParent:DWORD
    LOCAL hJSON:DWORD
    LOCAL hJSONParent:DWORD
    
    Invoke TreeViewGetSelectedItem, hTV
    mov hItem, eax
    
    Invoke JSONRemoveItem, hTV, hItem
    
;    Invoke TreeViewGetItemParam, hTV, hItem
;    mov hJSON, eax
;    .IF eax != 0 
;        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_PARENT, hItem ; get parent item
;        mov hParent, eax
;        .IF eax != 0
;            Invoke TreeViewGetItemParam, hTV, hParent ; get parents json
;            mov hJSONParent, eax
;            .IF eax != 0
;                Invoke cJSON_DetachItemViaPointer, hJSONParent, hJSON ; detach object from rest of json stuff
;            .ENDIF
;        .ENDIF
;        Invoke cJSON_Delete, hJSON ; delete json item and all children it has
;    .ENDIF  
    


    Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    .IF eax == 0
        mov g_nTVIndex, 0
        mov g_Edit, FALSE
        Invoke StatusBarSetPanelText, 2, Addr szSpace
        Invoke SetWindowTitle, hWin, NULL
        Invoke MenuSaveEnable, hWin, FALSE
        Invoke MenuSaveAsEnable, hWin, FALSE
        Invoke ToolbarButtonSaveEnable, hWin, FALSE
        Invoke ToolbarButtonSaveAsEnable, hWin, FALSE
    .ELSE
        mov g_Edit, TRUE
        Invoke MenuSaveEnable, hWin, TRUE
        Invoke MenuSaveAsEnable, hWin, TRUE
        Invoke ToolbarButtonSaveEnable, hWin, TRUE
        Invoke ToolbarButtonSaveAsEnable, hWin, TRUE
    .ENDIF

    Invoke MenusUpdate, hWin, NULL
    Invoke ToolBarUpdate, hWin, NULL    
    ret

JSONDelItem ENDP


;-------------------------------------------------------------------------------------
; Edit the json item (treeview item) text, F2 or double clicking on label does the same
;-------------------------------------------------------------------------------------
JSONEditItem PROC hWin:DWORD
    Invoke TreeViewGetSelectedItem, hTV
    .IF eax != 0
        Invoke SendMessage, hTV, TVM_EDITLABEL, 0, eax
    .ENDIF
    ret
JSONEditItem ENDP


;-------------------------------------------------------------------------------------
; Creates a new json item and adds it as a child of current json item
; Called from JSONAddItem and JSONPasteItem
; Returns NULL or handle to the new json created item if successful.
;-------------------------------------------------------------------------------------
JSONCreateItem PROC USES EBX hTreeview:DWORD, hParentItem:DWORD, dwJsonObjectType:DWORD
    LOCAL hItem:DWORD
    LOCAL hJSONParent:DWORD
    LOCAL hJSONAdd:DWORD
    LOCAL bArray:DWORD
    
    .IF hTreeview == NULL
        xor eax, eax
        ret
    .ENDIF
    
    .IF hParentItem == NULL
        Invoke TreeViewGetSelectedItem, hTreeview
    .ELSE    
        mov eax, hParentItem
    .ENDIF
    mov hItem, eax
    
    .IF hItem == NULL
        xor eax, eax
        ret
    .ENDIF

    Invoke TreeViewGetItemParam, hTreeview, hItem
    mov hJSONParent, eax
    .IF eax == NULL
        xor eax, eax
        ret
    .ENDIF

    Invoke cJSON_IsArray, hJSONParent
    mov bArray, eax

    mov eax, dwJsonObjectType
    .IF eax == cJSON_Object
        .IF bArray == FALSE
            Invoke cJSON_AddStringToObject, hJSONParent, Addr szNullNull, Addr szNullNull
        .ELSE
            Invoke cJSON_AddStringToArray, hJSONParent, Addr szNullNull
        .ENDIF
        mov hJSONAdd, eax
        
    .ELSEIF eax == cJSON_Array
        .IF bArray == FALSE
            Invoke cJSON_AddArrayToObject, hJSONParent, Addr szNullNull
        .ELSE
            Invoke cJSON_AddArrayToArray, hJSONParent
        .ENDIF
        mov hJSONAdd, eax
        
    .ELSEIF eax == cJSON_String
        .IF bArray == FALSE
            Invoke cJSON_AddStringToObject, hJSONParent, Addr szNullNull, Addr szNullNull
        .ELSE
            Invoke cJSON_AddStringToArray, hJSONParent, Addr szNullNull
        .ENDIF
        mov hJSONAdd, eax        
        
    .ELSEIF eax == cJSON_Number
        .IF bArray == FALSE
            Invoke cJSON_AddNumberToObject, hJSONParent, Addr szNullNull, 0
        .ELSE
            Invoke cJSON_AddNumberToArray, hJSONParent, 0
        .ENDIF
        mov hJSONAdd, eax        
        
    .ELSEIF eax == cJSON_True
        .IF bArray == FALSE
            Invoke cJSON_AddTrueToObject, hJSONParent, Addr szNullNull
        .ELSE
            Invoke cJSON_AddTrueToArray, hJSONParent
        .ENDIF
        mov hJSONAdd, eax        
        
    .ELSEIF eax == cJSON_False
        .IF bArray == FALSE
            Invoke cJSON_AddFalseToObject, hJSONParent, Addr szNullNull
        .ELSE
            Invoke cJSON_AddFalseToArray, hJSONParent
        .ENDIF
        mov hJSONAdd, eax
        
    .ENDIF

    .IF hJSONAdd == 0
        ;PrintText 'hJSONAdd == 0'
        xor eax, eax
        ret
    .ENDIF

    mov ebx, hJSONAdd
    mov eax, dwJsonObjectType
    mov [ebx].cJSON.itemtype, eax
    mov [ebx].cJSON.valuestring, 0
    mov [ebx].cJSON.itemstring, 0

    mov eax, hJSONAdd

    ret

JSONCreateItem ENDP


;-------------------------------------------------------------------------------------
; Removes a json item (detaches from parent json item and deletes it and children)
; Called from JSONDelItem and JSONPasteItem (Cut Mode)
;-------------------------------------------------------------------------------------
JSONRemoveItem PROC hTreeview:DWORD, hItem:DWORD
    LOCAL hParent:DWORD
    LOCAL hJSON:DWORD
    LOCAL hJSONParent:DWORD
    
    .IF hItem == 0
        xor eax, eax
    .ENDIF
    
    Invoke TreeViewGetItemParam, hTreeview, hItem
    mov hJSON, eax
    .IF eax != 0 
        Invoke SendMessage, hTreeview, TVM_GETNEXTITEM, TVGN_PARENT, hItem ; get parent item
        mov hParent, eax
        .IF eax != 0
            Invoke TreeViewGetItemParam, hTreeview, hParent ; get parents json
            mov hJSONParent, eax
            .IF eax != 0
                Invoke cJSON_DetachItemViaPointer, hJSONParent, hJSON ; detach object from rest of json stuff
            .ENDIF
        .ENDIF
        Invoke cJSON_Delete, hJSON ; delete json item and all children it has
    .ENDIF
    
    Invoke TreeViewSetItemParam, hTV, hItem, NULL
    Invoke TreeViewItemDelete, hTV, hItem
    
    mov eax, TRUE 
    ret
JSONRemoveItem ENDP









