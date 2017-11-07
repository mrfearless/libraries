.686 
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    include M:\Masm32\include\debug32.inc
ENDIF

CJSONARRAYS_ITERATE EQU 1

include cjsontree.inc

.code

start:

    Invoke GetModuleHandle,NULL
    mov hInstance, eax
    Invoke GetCommandLine
    mov CommandLine, eax
    Invoke InitCommonControls
    mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
    
    Invoke ProcessCmdLine
    
    Invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
    Invoke ExitProcess, eax

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
    LOCAL   wc:WNDCLASSEX
    LOCAL   msg:MSG

    mov     wc.cbSize, sizeof WNDCLASSEX
    mov     wc.style, CS_HREDRAW or CS_VREDRAW
    mov     wc.lpfnWndProc, offset WndProc
    mov     wc.cbClsExtra, NULL
    mov     wc.cbWndExtra, DLGWINDOWEXTRA
    push    hInst
    pop     wc.hInstance
    mov     wc.hbrBackground, COLOR_BTNFACE+1 ; COLOR_WINDOW+1
    mov     wc.lpszMenuName, IDM_MENU
    mov     wc.lpszClassName, offset ClassName
    Invoke LoadIcon, hInstance, ICO_MAIN ; resource icon for main application icon
    mov hICO_MAIN, eax ; main application icon
    mov     wc.hIcon, eax
    mov     wc.hIconSm, eax
    Invoke LoadCursor, NULL, IDC_ARROW
    mov     wc.hCursor,eax
    Invoke RegisterClassEx, addr wc
    Invoke CreateDialogParam, hInstance, IDD_DIALOG, NULL, addr WndProc, NULL
    mov hWnd, eax
    Invoke ShowWindow, hWnd, SW_SHOWNORMAL
    Invoke UpdateWindow, hWnd
    .WHILE TRUE
        invoke GetMessage,addr msg,NULL,0,0
        .BREAK .if !eax

        Invoke IsDialogMessage, hWnd, addr msg
        .IF eax == 0
            invoke TranslateMessage,addr msg
            invoke DispatchMessage,addr msg
        .ENDIF
    .ENDW
    mov eax,msg.wParam
    ret
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc USES EBX ECX hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    
    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        push hWin
        pop hWnd
        ; Init Stuff Here
        
        mov hJSONFile, NULL
        mov hJSONTreeRoot, NULL
        
        Invoke InitGUI, hWin
        Invoke InitMenus, hWin
        Invoke InitJSONStatusbar, hWin
        Invoke InitJSONTreeview, hWin
        
        Invoke DragAcceptFiles, hWin, TRUE
        Invoke SetFocus, hTV
        
    .ELSEIF eax == WM_COMMAND
        mov eax, wParam
        and eax, 0FFFFh
        .IF eax == IDM_FILE_EXIT
            Invoke SendMessage,hWin,WM_CLOSE,0,0

        .ELSEIF eax == IDM_FILE_OPEN
            Invoke BrowseJSONFile, hWin
            .IF eax == TRUE
                Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
                .IF eax == TRUE
                    ; Start processing JSON file
                    Invoke ProcessJSONFile, hWin, Addr JsonBrowseFilename
                .ENDIF
            .ENDIF
          
        .ELSEIF eax == IDM_FILE_CLOSE
            Invoke CloseJSONFile
            
        .ELSEIF eax == IDM_HELP_ABOUT
            Invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
            
        .ENDIF
    
    .ELSEIF eax == WM_DROPFILES
        mov eax, wParam
        mov hDrop, eax
        
        Invoke DragQueryFile, hDrop, 0, Addr JsonBrowseFilename, SIZEOF JsonBrowseFilename
        .IF eax != 0
            Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
            .IF eax == TRUE
                ; Start processing JSON file
                Invoke ProcessJSONFile, hWin, Addr JsonBrowseFilename
            .ENDIF
        .ENDIF
        mov eax, 0
        ret

    .ELSEIF eax == WM_WINDOWPOSCHANGED
        mov ebx, lParam
        mov eax, (WINDOWPOS ptr [ebx]).flags
        and eax, SWP_SHOWWINDOW
        .IF eax == SWP_SHOWWINDOW && g_fShown == FALSE
            mov g_fShown, TRUE
            Invoke PostMessage, hWin, WM_APP, 0, 0
        .ENDIF
        Invoke DefWindowProc,hWin,uMsg,wParam,lParam
        xor eax, eax
        ret
        
    .ELSEIF eax == WM_APP
        .IF CmdLineProcessFileFlag == 1
            Invoke CmdLineOpenFile, hWin
        .ENDIF
        Invoke DefWindowProc,hWin,uMsg,wParam,lParam
        ret      
    
    .ELSEIF eax == WM_CTLCOLORDLG
        mov eax, hWhiteBrush
        ret

    .ELSEIF eax == WM_SIZE
        Invoke SendMessage, hSB, WM_SIZE, 0, 0
        mov eax, lParam
        and eax, 0FFFFh
        mov dwClientWidth, eax
        mov eax, lParam
        shr eax, 16d
        mov dwClientHeight, eax
        sub eax, 23d ; take away statusbar height
        Invoke SetWindowPos, hTV, HWND_TOP, 0,0, dwClientWidth, eax, SWP_NOZORDER

    .ELSEIF eax==WM_NOTIFY
        mov ecx,lParam
        mov eax, (NMHDR PTR [ecx]).code
        
        .IF eax == NM_RCLICK

        .ELSEIF eax == NM_DBLCLK
            Invoke TreeViewGetSelectedItem, hTV
            Invoke SendMessage, hTV, TVM_EDITLABEL, 0, eax
        
        .ELSEIF eax == NM_RETURN ; requires sublass of treeview with WM_GETDLGCODE DLGC_WANTALL
            Invoke TreeViewGetSelectedItem, hTV
            Invoke SendMessage, hTV, TVM_EDITLABEL, 0, eax
        
        .ELSEIF eax == TVN_KEYDOWN
            mov ecx, lParam
            movzx eax, (TV_KEYDOWN ptr [ecx]).wVKey
            .IF eax == VK_F2 
                Invoke TreeViewGetSelectedItem, hTV
                Invoke SendMessage, hTV, TVM_EDITLABEL, 0, eax
            .ENDIF
             
        .ELSEIF eax == TVN_BEGINLABELEDIT
            mov eax, FALSE
            ret
            
        .ELSEIF eax == TVN_ENDLABELEDIT
            mov eax, TRUE
            ret
            
        .ENDIF

    .ELSEIF eax == WM_CLOSE
        Invoke DestroyWindow,hWin
        
    .ELSEIF eax == WM_DESTROY
        Invoke PostQuitMessage,NULL
        
    .ELSE
        Invoke DefWindowProc,hWin,uMsg,wParam,lParam
        ret
    .ENDIF
    xor    eax,eax
    ret
WndProc endp


;-------------------------------------------------------------------------------------
; ProcessCmdLine - has user passed a file at the command line 
;-------------------------------------------------------------------------------------
ProcessCmdLine PROC
    Invoke getcl_ex, 1, ADDR CmdLineFilename
    .IF eax == 1
        mov CmdLineProcessFileFlag, 1 ; filename specified, attempt to open it
    .ELSE
        mov CmdLineProcessFileFlag, 0 ; do nothing, continue as normal
    .ENDIF
    ret
ProcessCmdLine endp


;------------------------------------------------------------------------------
; Opens a file from the command line or shell explorer call
;------------------------------------------------------------------------------
CmdLineOpenFile PROC hWin:DWORD

    Invoke InString, 1, Addr CmdLineFilename, Addr szBackslash
    .IF eax == 0
        Invoke GetCurrentDirectory, MAX_PATH, Addr CmdLineFullPathFilename
        Invoke szCatStr, Addr CmdLineFullPathFilename, Addr szBackslash
        Invoke szCatStr, Addr CmdLineFullPathFilename, Addr CmdLineFilename
    .ELSE
        Invoke szCopy, Addr CmdLineFilename, Addr CmdLineFullPathFilename
    .ENDIF
    
    Invoke exist, Addr CmdLineFullPathFilename
    .IF eax == 0 ; does not exist
        Invoke szCopy, Addr szCmdLineFilenameDoesNotExist, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, Addr CmdLineFullPathFilename
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret
    .ENDIF

    Invoke OpenJSONFile, hWin, Addr CmdLineFullPathFilename
    .IF eax == TRUE
        ; Start processing JSON file
        Invoke ProcessJSONFile, hWin, Addr CmdLineFullPathFilename
    .ENDIF

    ret
CmdLineOpenFile endp


;-------------------------------------------------------------------------------------
; InitGUI - Initialize GUI stuff
;-------------------------------------------------------------------------------------
InitGUI PROC hWin:DWORD

    Invoke CreateSolidBrush, 0FFFFFFh
    mov hWhiteBrush, eax
    
    Invoke GetDlgItem, hWin, IDC_TV
    mov hTV, eax
    
    Invoke GetDlgItem, hWin, IDC_SB
    mov hSB, eax
    
    Invoke LoadIcon, hInstance, ICO_MAIN
    mov hICO_MAIN, eax
    
    Invoke LoadIcon, hInstance, ICO_JSON_STRING
    mov hICO_JSON_STRING, eax
    Invoke LoadIcon, hInstance, ICO_JSON_INTEGER
    mov hICO_JSON_INTEGER, eax
    Invoke LoadIcon, hInstance, ICO_JSON_FLOAT
    mov hICO_JSON_FLOAT, eax
    Invoke LoadIcon, hInstance, ICO_JSON_CUSTOM
    mov hICO_JSON_CUSTOM, eax
    Invoke LoadIcon, hInstance, ICO_JSON_TRUE
    mov hICO_JSON_TRUE, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_FALSE
    mov hICO_JSON_FALSE, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_ARRAY
    mov hICO_JSON_ARRAY, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_OBJECT
    mov hICO_JSON_OBJECT, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_NULL
    mov hICO_JSON_NULL, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_INVALID
    mov hICO_JSON_INVALID, eax    
    Invoke LoadIcon, hInstance, ICO_JSON_LOGICAL
    mov hICO_JSON_LOGICAL, eax
    
    Invoke ImageList_Create, 16, 16, ILC_COLOR32, 16, 16
    mov hIL, eax
    
    Invoke ImageList_AddIcon, hIL, hICO_MAIN
    Invoke ImageList_AddIcon, hIL, hICO_JSON_STRING
    Invoke ImageList_AddIcon, hIL, hICO_JSON_INTEGER
    Invoke ImageList_AddIcon, hIL, hICO_JSON_FLOAT
    Invoke ImageList_AddIcon, hIL, hICO_JSON_CUSTOM
    Invoke ImageList_AddIcon, hIL, hICO_JSON_TRUE
    Invoke ImageList_AddIcon, hIL, hICO_JSON_FALSE
    Invoke ImageList_AddIcon, hIL, hICO_JSON_ARRAY
    Invoke ImageList_AddIcon, hIL, hICO_JSON_OBJECT
    Invoke ImageList_AddIcon, hIL, hICO_JSON_NULL
    Invoke ImageList_AddIcon, hIL, hICO_JSON_INVALID
    Invoke ImageList_AddIcon, hIL, hICO_JSON_LOGICAL
    
    ret

InitGUI ENDP


;-------------------------------------------------------------------------------------
; InitMenus - Initialize menus
;-------------------------------------------------------------------------------------
InitMenus PROC hWin:DWORD
    
    ; Create right click treeview menu
    ;Invoke CreatePopupMenu
    ;mov hTVMenu, eax
    
    
    ret

InitMenus ENDP


;-------------------------------------------------------------------------------------
; InitJSONTreeview - Initialize JSON Treeview
;-------------------------------------------------------------------------------------
InitJSONTreeview PROC hWin:DWORD

    Invoke SendMessage, hTV, TVM_SETEXTENDEDSTYLE, TVS_EX_DOUBLEBUFFER, TVS_EX_DOUBLEBUFFER
    Invoke TreeViewLinkImageList, hTV, hIL, TVSIL_NORMAL
    
    ret

InitJSONTreeview ENDP


;-------------------------------------------------------------------------------------
; InitJSONStatusbar - Initialize JSON Statusbar
;-------------------------------------------------------------------------------------
InitJSONStatusbar PROC hWin:DWORD
    LOCAL sbParts[8]:DWORD

    mov [sbParts +  0], 70      ; Panel 1 Size
    mov [sbParts +  4], -1      ; Panel 2 Size to rest of dialog with -1

    Invoke SendMessage, hSB, SB_SETPARTS, 2, ADDR sbParts ; Set amount of parts

    Invoke SendMessage, hSB, SB_SETTEXT, 0, CTEXT(" Info: ") 
    Invoke SendMessage, hSB, SB_SETTEXT, 1, CTEXT("  ")         
    
    ret

InitJSONStatusbar ENDP


;-------------------------------------------------------------------------------------
; BrowseJSONFile - Browse for JSON file to open
;-------------------------------------------------------------------------------------
BrowseJSONFile PROC hWin:DWORD
    
    ; Browse for JSON file to open
    Invoke RtlZeroMemory, Addr JsonBrowseFilename, SIZEOF JsonBrowseFilename
    push hWin
    pop BrowseFile.hwndOwner
    mov BrowseFile.lpstrFilter, Offset JsonBrowseFilter
    mov BrowseFile.lpstrFile, Offset JsonBrowseFilename
    mov BrowseFile.lpstrTitle, Offset JsonBrowseFileTitle
    mov BrowseFile.nMaxFile, SIZEOF JsonBrowseFilename
    mov BrowseFile.lpstrDefExt, 0
    mov BrowseFile.Flags, OFN_EXPLORER
    mov BrowseFile.lStructSize, SIZEOF BrowseFile
    Invoke GetOpenFileName, Addr BrowseFile

    ; If user selected an JSON and didnt cancel browse operation...
    .IF eax !=0
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret

BrowseJSONFile ENDP


;-------------------------------------------------------------------------------------
; OpenJSONFile - Open JSON file to process
;-------------------------------------------------------------------------------------
OpenJSONFile PROC hWin:DWORD, lpszJSONFile:DWORD
    
    .IF hJSONFile != NULL
        Invoke CloseJSONFile
    .ENDIF
    
    ; Tell user we are loading file
    Invoke szCopy, Addr szJSONLoadingFile, Addr szJSONErrorMessage
    Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
    ;Invoke SendMessage, hSB, SB_SETTEXT, 1, lpszJSONFile
    
    Invoke CreateFile, lpszJSONFile, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    .IF eax == INVALID_HANDLE_VALUE
        ; Tell user via statusbar that JSON file did not load
        Invoke szCopy, Addr szJSONErrorLoadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        mov eax, FALSE
        ret
    .ENDIF
    mov hJSONFile, eax

    Invoke CreateFileMapping, hJSONFile, NULL, PAGE_READWRITE, 0, 0, NULL ; Create memory mapped file
    .IF eax == NULL
        ; Tell user via statusbar that JSON file did not map
        Invoke szCopy, Addr szJSONErrorMappingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        Invoke CloseHandle, hJSONFile
        mov eax, FALSE
        ret
    .ENDIF
    mov JSONMemMapHandle, eax

    Invoke MapViewOfFileEx, JSONMemMapHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0, NULL
    .IF eax == NULL
        ; Tell user via statusbar that JSON file did not map
        Invoke szCopy, Addr szJSONErrorMappingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        Invoke CloseHandle, JSONMemMapHandle
        Invoke CloseHandle, hJSONFile
        mov eax, FALSE
        ret
    .ENDIF
    mov JSONMemMapPtr, eax  

    mov eax, TRUE
    
    ret

OpenJSONFile ENDP


;-------------------------------------------------------------------------------------
; CloseJSONFile - Closes JSON file and deletes any treeview data and json data
;-------------------------------------------------------------------------------------
CloseJSONFile PROC

    .IF JSONMemMapPtr != NULL
        Invoke UnmapViewOfFile, JSONMemMapPtr
        mov JSONMemMapPtr, NULL
    .ENDIF
    .IF JSONMemMapHandle != NULL
        Invoke CloseHandle, JSONMemMapHandle
        mov JSONMemMapHandle, NULL
    .ENDIF
    .IF hJSONFile != NULL
        Invoke CloseHandle, hJSONFile
        mov hJSONFile, NULL
    .ENDIF
    
    .IF hJSONTreeRoot != NULL
        ;Invoke mxmlDelete, hJSONTreeRoot
        mov hJSONTreeRoot, NULL
    .ENDIF
    
    Invoke TreeViewDeleteAll, hTV
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szSpace
    
    ret

CloseJSONFile ENDP


;-------------------------------------------------------------------------------------
; ProcessJSONFile - Process JSON file and load data into treeview
;-------------------------------------------------------------------------------------
ProcessJSONFile PROC USES EBX hWin:DWORD, lpszJSONFile:DWORD
    LOCAL nTVIndex:DWORD
    LOCAL next:DWORD
    LOCAL prev:DWORD
    LOCAL child:DWORD
    LOCAL jsontype:DWORD
    LOCAL itemcount:DWORD
    LOCAL currentitem:DWORD
    LOCAL hJSON:DWORD
    LOCAL level:DWORD
    LOCAL dwArrayCount:DWORD
    
    ; JSONMemMapPtr is pointer to file in memory, mapped previously in OpenJSONFile
    ; Parse this with cJSON library cJSON_Parse function, returns root handle to JSON stuff

    Invoke cJSON_Parse, JSONMemMapPtr
    mov hJSON_Object_Root, eax

    .IF hJSON_Object_Root == NULL
        ; If empty then tell user some error about reading file
        Invoke szCopy, Addr szJSONErrorReadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret        
    .ENDIF

    ; Treeview Root is created, save handle to it, specifically we will need hTVNode later for when inserting children to treeview
    mov nTVIndex, 0
    Invoke TreeViewInsertItem, hTV, NULL, lpszJSONFile, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, 0
    mov hTVRoot, eax
    mov hTVNode, eax
    mov hTVCurrentNode, eax
    inc nTVIndex
    
    
    ; Each time we insert a treeview item we need to increment our nTVIndex counter

    ; Just a check to make sure JSON has some stuff to process
    Invoke cJSON_GetArraySize, hJSON_Object_Root
    .IF eax == 0
        Invoke szCopy, Addr szJSONErrorEmptyFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret
    .ENDIF

    mov level, -1000d ; hack to force our while loop below, only used for possibly debugging/tracking indented levels (children)
    mov eax, hJSON_Object_Root 
    mov hJSON, eax ; use hJSON as variable to process in our loop
    
    IFDEF CJSONARRAYS_ITERATE
    Invoke VirtualStackCreate, VIRTUALSTACK_SIZE_LARGE
    mov hVirtualStack, eax
    mov hArray, NULL
    mov hCurrentArray, NULL
    ENDIF
    
    ;PrintDec hJSON
    ;PrintDec hTVNode

    .WHILE level != 0

        .IF level == -1000d
            mov level, 1 ; set our level to 1, useful for debugging and checking we havnt push/popd too much
            push hJSON ; push hJSON, then hTVNode. NOTE: we must pop these in reverse order to retrieve them when we fall back up the tree
            push hTVNode
            IFDEF CJSONARRAYS_ITERATE
            Invoke VirtualStackPush, hVirtualStack, NULL
            ENDIF
        .ENDIF
        
        mov ebx, hJSON ; get our cJSON object (first time in loop is the hJSON_Object_Root, subsequent times it will be the next or child item
        
        ; Fetch some values for our cJSON object
        mov eax, [ebx].cJSON.itemtype
        mov jsontype, eax
        mov eax, [ebx].cJSON.child
        mov child, eax
        mov eax, [ebx].cJSON.next
        mov next, eax
        mov eax, [ebx].cJSON.prev
        mov prev, eax
        mov eax, [ebx].cJSON.itemstring
        mov lpszItemString, eax
        mov eax, [ebx].cJSON.valuestring
        mov lpszItemStringValue, eax  
        mov eax, [ebx].cJSON.valueint
        mov dwItemIntValue, eax          
        
        ; Check strings are present and > 0 in length (to stop crashes when copying etc)
        .IF lpszItemString == 0
            mov LenItemString, 0
        .ELSE
            Invoke szLen, lpszItemString
            mov LenItemString, eax
        .ENDIF
        
        .IF lpszItemStringValue == 0
            mov LenItemStringValue, 0
        .ELSE
            Invoke szLen, lpszItemStringValue
            mov LenItemStringValue, eax
        .ENDIF        
        
        ; Determine the type of cJSON object, so we can decide what to do with it
        mov eax, jsontype
        .IF eax == cJSON_Object
        
            IFDEF CJSONARRAYS_ITERATE
                
                .IF hArray != NULL
                    
                    Invoke CreateJSONArrayIteratorName, hArray, Addr szItemTextArrayName
                    Invoke IncJSONStackItemCount, hArray
                    
                    IFDEF DEBUG32
                    PrintString szItemTextArrayName
                    ENDIF
                    
                    .IF LenItemString == 0
                        .IF g_ShowJsonType == TRUE
                            ;Invoke szCatStr, Addr szItemTextArrayName, Addr szSpace
                            Invoke szCatStr, Addr szItemTextArrayName, Addr szColon
                            Invoke szCatStr, Addr szItemTextArrayName, Addr szSpace
                            Invoke szCatStr, Addr szItemTextArrayName, Addr szObject                    
                        .ENDIF
                        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemTextArrayName, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                        mov hTVCurrentNode, eax
                        inc nTVIndex
                    .ELSE
                        
                        Invoke szCopy, Addr szItemTextArrayName, Addr szItemText
                        Invoke szCatStr, Addr szItemText, Addr szSpace
                        Invoke szCatStr, Addr szItemText, lpszItemString
                        Invoke szCatStr, Addr szItemText, Addr szColon
                        .IF LenItemStringValue != 0
                            Invoke szCatStr, Addr szItemText, Addr szSpace
                            Invoke szCatStr, Addr szItemText, lpszItemStringValue
                        .ENDIF
                    
                        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                        mov hTVCurrentNode, eax
                        inc nTVIndex
                    .ENDIF
                    
                .ELSE
                    .IF LenItemString == 0
                        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szObject, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                        mov hTVCurrentNode, eax
                        inc nTVIndex
                    .ELSE
                        
                        Invoke szCopy, lpszItemString, Addr szItemText
                        Invoke szCatStr, Addr szItemText, Addr szColon
                        .IF LenItemStringValue != 0
                            Invoke szCatStr, Addr szItemText, Addr szSpace
                            Invoke szCatStr, Addr szItemText, lpszItemStringValue
                        .ENDIF
                        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                        mov hTVCurrentNode, eax
                        inc nTVIndex
                    .ENDIF
                .ENDIF
                
            ELSE
                .IF LenItemString == 0
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szObject, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc nTVIndex
                .ELSE
                    
                    Invoke szCopy, lpszItemString, Addr szItemText
                    Invoke szCatStr, Addr szItemText, Addr szColon
                    .IF LenItemStringValue != 0
                        Invoke szCatStr, Addr szItemText, Addr szSpace
                        Invoke szCatStr, Addr szItemText, lpszItemStringValue
                    .ENDIF
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc nTVIndex
                .ENDIF
            ENDIF

        .ELSEIF eax == cJSON_String
            .IF LenItemString == 0
                .IF LenItemStringValue != 0
                    Invoke szCopy, lpszItemStringValue, Addr szItemText 
                .ENDIF                
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
                Invoke szCatStr, Addr szItemText, Addr szColon
                .IF LenItemStringValue > SIZEOF szItemTextValue ;!= 0
                    Invoke lstrcpyn, Addr szItemTextValue, lpszItemStringValue, SIZEOF szItemTextValue
                    Invoke szCatStr, Addr szItemText, Addr szSpace
                    Invoke szCatStr, Addr szItemText, Addr szItemTextValue
                .ELSE
                    .IF LenItemStringValue != 0
                        Invoke szCatStr, Addr szItemText, Addr szSpace
                        Invoke szCatStr, Addr szItemText, lpszItemStringValue
                    .ENDIF
                .ENDIF
            .ENDIF
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_STRING, IL_ICO_JSON_STRING, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_Number
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullInteger, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke dwtoa, dwItemIntValue, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szItemIntValue
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_INTEGER, IL_ICO_JSON_INTEGER, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex
        
        .ELSEIF eax == cJSON_True
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szTrue
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_False
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szFalse
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_Array
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullArray, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke cJSON_GetArraySize, hJSON
            mov dwArrayCount, eax
            Invoke dwtoa, dwArrayCount, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szLeftSquareBracket
            Invoke szCatStr, Addr szItemText, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szRightSquareBracket
            .IF g_ShowJsonType == TRUE
                ;Invoke szCatStr, Addr szItemText, Addr szSpace
                Invoke szCatStr, Addr szItemText, Addr szColon
                Invoke szCatStr, Addr szItemText, Addr szSpace
                Invoke szCatStr, Addr szItemText, Addr szArray
            .ENDIF
            
            IFDEF CJSONARRAYS_ITERATE
                .IF LenItemString == 0
                    Invoke szCopy, Addr szNullArray, Addr szItemTextArrayName
                .ELSE
                    Invoke szCopy, lpszItemString, Addr szItemTextArrayName
                .ENDIF
                Invoke CreateJSONStackItem, Addr szItemTextArrayName
                mov hCurrentArray, eax
                IFDEF DEBUG32
                PrintString szItemTextArrayName
                ENDIF
            ENDIF
        
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_ARRAY, IL_ICO_JSON_ARRAY, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_NULL
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullNull, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szNull
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_NULL, IL_ICO_JSON_NULL, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_Invalid
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullInvalid, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szInvalid
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_INVALID, IL_ICO_JSON_INVALID, hJSON
            mov hTVCurrentNode, eax
            inc nTVIndex

        .ELSEIF eax == cJSON_Raw

        .ENDIF
        
        ; we have inserted a treeview item, now we check what the next cJSON item is and how to handle it
        ; get child if there is one, otherwise sibling if there is one
        .IF child != 0
            inc level ; we are moving up a level, so increment level
            push hJSON ; push hJSON, before hTVNode as always. Remember to pop them in reverse order later.
            push hTVNode
            
            mov eax, child ; set child cJSON object as the cJSON object to process in our loop
            mov hJSON, eax
            
            mov eax, hTVCurrentNode ; set currently inserted treeview item as hTVNode, so next one will be inserted as a child of this one.
            mov hTVNode, eax
            
            IFDEF CJSONARRAYS_ITERATE
                mov eax, jsontype
                .IF eax == cJSON_Array
                    ;.IF hCurrentArray != NULL && hArray == NULL
                        Invoke VirtualStackPush, hVirtualStack, hCurrentArray
                        mov eax, hCurrentArray
                        mov hArray, eax
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPush'
                        PrintText 'cJSON_Array'
                        PrintDec hCurrentArray
                        PrintDec hArray
                        ENDIF
                .ELSE
                    IFDEF DEBUG32
                    PrintText 'VirtualStackPush'
                    PrintDec hArray
                    ENDIF
                    Invoke VirtualStackPush, hVirtualStack, hArray
                    mov hArray, NULL
                .ENDIF    
            ENDIF
            
        .ELSE ; No child cJSON object, so look for siblings
            .IF next != 0 ; we have a sibling
                mov eax, next ; set next cJSON object as the cJSON object to process in our loop
                mov hJSON, eax
            .ELSE ; No child or siblings, so must be at the last sibling, so here is the fun stuff
            
                IFDEF CJSONARRAYS_ITERATE
                    Invoke VirtualStackPop, hVirtualStack, Addr VSValue
                    .IF eax == TRUE
                        mov eax, VSValue
                        mov hArray, eax
                    .ELSEIF eax == FALSE
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPop Error'
                        ENDIF
                    .ELSE
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPop End of Stack'
                        ENDIF
                    .ENDIF
                    IFDEF DEBUG32
                    PrintText 'VirtualStackPop'
                    PrintDec hArray
                    ENDIF
                ENDIF
            
                pop hTVNode ; pop hTVNode before hJSON (reverse of what we pushed previously)
                pop hJSON ; we now have the last levels cJSON object and the parent of the last inserted treeview item
                
                dec level ; we are moving down a level, so decrement level
                mov ebx, hJSON ; fetch the next cJSON object of the cJSON object we just restored with the pop hJSON 
                mov eax, [ebx].cJSON.next
                
                .WHILE eax == 0 && level != 1 ; if next is 0 and we are still a level greater than 1 we loop, restoring previous cJSON objects and hTVNodes
                
                    IFDEF CJSONARRAYS_ITERATE
                        Invoke VirtualStackPop, hVirtualStack, Addr VSValue
                        .IF eax == TRUE
                            mov eax, VSValue
                            mov hArray, eax
                        .ELSEIF eax == FALSE
                            IFDEF DEBUG32
                            PrintText 'VirtualStackPop Error'
                            ENDIF
                        .ELSE
                            IFDEF DEBUG32
                            PrintText 'VirtualStackPop End of Stack'
                            ENDIF
                        .ENDIF
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPop'
                        PrintDec hArray
                        ENDIF                            
                    ENDIF

                    pop hTVNode
                    dec level
                    pop hJSON
                    mov ebx, hJSON
                    mov eax, [ebx].cJSON.next
                .ENDW
                ; we are now are level 1 (start) so the cJSON objects next object is either a value we can use in our loop or it is 0
                
                .IF eax == 0 ; no more left so exit as we are done
                    .BREAK
                .ELSE
                    mov hJSON, eax ; else we did find a new cJSON object which we can start the whole major loop process with again 
                .ENDIF
            .ENDIF

        .ENDIF
    
        ;Invoke TreeViewChildItemsExpand, hTV, hTVCurrentNode
        Invoke TreeViewChildItemsExpand, hTV, hTVNode

    .ENDW
    
    Invoke TreeViewChildItemsExpand, hTV, hTVRoot
    
    ;PrintDec hTVNode
    ;PrintDec hJSON
    IFDEF CJSONARRAYS_ITERATE
    Invoke VirtualStackDelete, hVirtualStack
    ENDIF
    
    ; we have finished processing the cJSON objects, following children then following siblings, then moving back up the list/level, getting next object and 
    ; repeating till no more objects where left to process and all treeview items have been inserted at the correct 'level' indentation or whatever.
    
    Invoke cJSON_free, hJSON_Object_Root ; Clear up the mem alloced by cJSON_Parse

    ; Tell user via statusbar that JSON file was successfully loaded
    Invoke szCopy, Addr szJSONLoadedFile, Addr szJSONErrorMessage
    Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage     
    
    Invoke SetFocus, hTV
    
    mov eax, TRUE
    
    ret
ProcessJSONFile ENDP





IFDEF JSONSTACKITEM
;-------------------------------------------------------------------------------------
; CreateJSONStackItem - Creates a json stack item
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
; FreeJSONStackItem
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
; GetJSONStackItemCount
;-------------------------------------------------------------------------------------
GetJSONStackItemCount PROC USES EBX ptrJsonStackItem:DWORD
    .IF ptrJsonStackItem == NULL
        mov eax, 0
        ret
    .ENDIF
    mov ebx, ptrJsonStackItem
    mov eax, [ebx].JSONSTACKITEM.dwItemCount
    ret
GetJSONStackItemCount ENDP


;-------------------------------------------------------------------------------------
; SetJSONStackItemCount
;-------------------------------------------------------------------------------------
SetJSONStackItemCount PROC USES EBX ptrJsonStackItem:DWORD, dwCountValue:DWORD
    .IF ptrJsonStackItem == NULL
        mov eax, 0
        ret
    .ENDIF
    mov ebx, ptrJsonStackItem
    mov eax, dwCountValue
    mov [ebx].JSONSTACKITEM.dwItemCount, eax
    ret
SetJSONStackItemCount ENDP


;-------------------------------------------------------------------------------------
; IncJSONStackItemCount
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
; CreateJSONArrayIteratorName
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
ENDIF

end start
















