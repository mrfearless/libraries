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


include cjsontree.inc
include menus.asm
include toolbar.asm
include stack.asm
include clipboard.asm

.code

start:

    Invoke GetModuleHandle,NULL
    mov hInstance, eax
    invoke LoadAccelerators, hInstance, ACCTABLE
    mov hAcc, eax    
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
        invoke GetMessage, addr msg, NULL, 0, 0
        .BREAK .if !eax

        Invoke TranslateAccelerator, hWnd, hAcc, addr msg
        .IF eax == 0
            Invoke IsDialogMessage, hWnd, addr msg
            .IF eax == 0
                Invoke TranslateMessage, addr msg
                Invoke DispatchMessage, addr msg
            .ENDIF
        .ENDIF
    .ENDW
    mov eax,msg.wParam
    ret
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc USES EBX ECX hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    LOCAL tvhi:TV_HITTESTINFO
    ;LOCAL hItem:DWORD
    
    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        push hWin
        pop hWnd
        ; Init Stuff Here
        
        mov hJSONFile, NULL
        mov hJSONTreeRoot, NULL
        
        Invoke InitGUI, hWin
        Invoke InitMenus, hWin
        Invoke InitToolbar, hWin, 16, 16
        Invoke InitJSONStatusbar, hWin
        Invoke InitJSONTreeview, hWin
        
        Invoke DragAcceptFiles, hWin, TRUE
        Invoke SetFocus, hTV
        
    .ELSEIF eax == WM_COMMAND
        mov eax, wParam
        and eax, 0FFFFh
        .IF eax == IDM_FILE_EXIT
            Invoke SendMessage,hWin,WM_CLOSE,0,0

        .ELSEIF eax == IDM_FILE_OPEN || eax == ACC_FILE_OPEN || eax == TB_FILE_OPEN
            Invoke BrowseJSONFile, hWin
            .IF eax == TRUE
                Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
                .IF eax == TRUE
                    ; Start processing JSON file
                    Invoke ProcessJSONData, hWin, Addr JsonBrowseFilename, NULL
                .ENDIF
            .ENDIF
          
        .ELSEIF eax == IDM_FILE_CLOSE || eax == ACC_FILE_CLOSE || eax == TB_FILE_CLOSE
            Invoke TreeViewDeleteAll, hTV
            Invoke CloseJSONFile
            Invoke ResetMenus, hWin
            Invoke ResetToolbars, hWin
        
        .ELSEIF eax == IDM_FILE_NEW || eax == ACC_FILE_NEW || eax == TB_FILE_NEW
            Invoke NewJSON, hWin
            Invoke SaveMenuState, hWin, TRUE
            Invoke SaveToolbarState, hWin, TRUE
        
        .ELSEIF eax == IDM_FILE_SAVE || eax == ACC_FILE_SAVE || eax == TB_FILE_SAVE
        
        .ELSEIF eax == IDM_FILE_SAVEAS || eax == ACC_FILE_SAVEAS || eax == TB_FILE_SAVEAS
        
        .ELSEIF eax == IDM_HELP_ABOUT
            Invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
        
        .ELSEIF eax == IDM_EDIT_PASTE_JSON || eax == IDM_CMD_PASTE_JSON
            Invoke TreeViewDeleteAll, hTV
            Invoke PasteJSON, hWin
        
        .ELSEIF eax == IDM_EDIT_COPY_TEXT || eax == IDM_CMD_COPY_TEXT
            Invoke CopyToClipboard, hWin, FALSE
        
        .ELSEIF eax == IDM_EDIT_COPY_VALUE || eax == IDM_CMD_COPY_VALUE
            Invoke CopyToClipboard, hWin, TRUE
        
        .ELSEIF eax == IDM_EDIT_COPY_BRANCH || eax == IDM_CMD_COPY_BRANCH || eax == ACC_EDIT_COPY_BRANCH
            Invoke CopyBranchToClipboard, hWin
            
        .ELSEIF eax == IDM_CMD_COLLAPSE_BRANCH
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewItemCollapse, hTV, eax
            
        .ELSEIF eax == IDM_CMD_EXPAND_BRANCH
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewItemExpand, hTV, eax

        .ELSEIF eax == IDM_CMD_COLLAPSE_CHILDREN
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewChildItemsCollapse, hTV, eax
            
        .ELSEIF eax == IDM_CMD_EXPAND_CHILDREN
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewChildItemsExpand, hTV, eax
        
        .ELSEIF eax == IDM_CMD_ADD_ITEM
            ; submenu is processed
        
        .ELSEIF eax == TB_ADD_ITEM
            Invoke ToolBarShowDropdownAddMenu, hWin
        
        .ELSEIF eax == IDM_CMD_DEL_ITEM || eax == TB_DEL_ITEM
            Invoke DelJSONItem, hWin
        
        .ELSEIF eax == IDM_CMD_EDIT_ITEM
            Invoke EditJSONItem, hWin
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_STRING || eax == TB_ADD_ITEM_STRING
            Invoke AddJSONItem, hWin, cJSON_String
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_NUMBER || eax == TB_ADD_ITEM_NUMBER
            Invoke AddJSONItem, hWin, cJSON_Number
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_TRUE || eax == TB_ADD_ITEM_TRUE
            Invoke AddJSONItem, hWin, cJSON_True
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_FALSE || eax == TB_ADD_ITEM_FALSE
            Invoke AddJSONItem, hWin, cJSON_False
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_ARRAY || eax == TB_ADD_ITEM_ARRAY
            Invoke AddJSONItem, hWin, cJSON_Array
            
        .ELSEIF eax == IDM_CMD_ADD_ITEM_OBJECT    || eax == TB_ADD_ITEM_OBJECT        
            Invoke AddJSONItem, hWin, cJSON_Object
            
        .ENDIF
    
    .ELSEIF eax == WM_DROPFILES
        mov eax, wParam
        mov hDrop, eax
        
        Invoke DragQueryFile, hDrop, 0, Addr JsonBrowseFilename, SIZEOF JsonBrowseFilename
        .IF eax != 0
            Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
            .IF eax == TRUE
                ; Start processing JSON file
                Invoke ProcessJSONData, hWin, Addr JsonBrowseFilename, NULL
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
        sub eax, 28d ; take away toolbar height
        Invoke SetWindowPos, hTV, HWND_TOP, 0,29, dwClientWidth, eax, SWP_NOZORDER
        Invoke SendMessage, hToolBar, TB_AUTOSIZE, 0, 0

    .ELSEIF eax==WM_NOTIFY
        mov ecx,lParam
        mov eax, (NMHDR PTR [ecx]).code
        mov ecx, (NMHDR PTR [ecx]).hwndFrom
        
        .IF ecx == hTV
            .IF eax == NM_RCLICK
    	        Invoke UpdateMenus, hWin, NULL
    	        Invoke ToolBarUpdate, hWin, NULL
                Invoke ShowRightClickMenu, hWin
            
            .ELSEIF eax == NM_CLICK
                ;Invoke UpdateMenus, hWin, NULL
                ;Invoke ToolBarUpdate, hWin, NULL
            
            .ELSEIF eax == NM_DBLCLK
                Invoke EditJSONItem, hWin
            
            .ELSEIF eax == TVN_KEYDOWN
                mov ecx, lParam
                movzx eax, (TV_KEYDOWN ptr [ecx]).wVKey
                .IF eax == VK_F2
                    Invoke EditJSONItem, hWin
                
                .ELSEIF eax == VK_V
                    Invoke GetAsyncKeyState, VK_CONTROL
                    .IF eax != 0
                        Invoke TreeViewDeleteAll, hTV
                        Invoke PasteJSON, hWin
                    .ENDIF
                
                .ELSEIF eax == VK_DELETE
                    Invoke DelJSONItem, hWin
                
                .ELSEIF eax == VK_INSERT ; show add submenu only if on an item with children or on an object or array item
                    ;Invoke GetAsyncKeyState, VK_CONTROL
                    ;.IF eax != 0
            	        Invoke ShowRightClickAddSubmenu, hWin
                    ;.ENDIF

                .ENDIF
            
            .ELSEIF eax == TVN_SELCHANGED
                mov ecx, lParam
                mov eax, (NM_TREEVIEW PTR [ecx]).itemNew.hItem 
                Invoke ToolBarUpdate, hWin, eax
                mov ecx, lParam
                mov eax, (NM_TREEVIEW PTR [ecx]).itemNew.hItem 
                Invoke UpdateMenus, hWin, eax
                
            .ELSEIF eax == TVN_BEGINLABELEDIT
                Invoke SendMessage, hTV, TVM_GETEDITCONTROL, 0, 0
                mov hTVEditControl, eax
                Invoke SetWindowLong, hTVEditControl, GWL_WNDPROC, Addr JSONTreeViewEditSubclass
                Invoke SetWindowLong, hTVEditControl, GWL_USERDATA, eax
                mov eax, FALSE
                ret
                
            .ELSEIF eax == TVN_ENDLABELEDIT
                mov eax, TRUE
                ret
            
            .ENDIF
        
        .ELSE
        
            .IF eax == TBN_DROPDOWN
                Invoke ToolBarShowDropdownAddMenu, hWin
            .ELSE
                Invoke ToolBarTips, lParam
            .ENDIF
            
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
        Invoke ProcessJSONData, hWin, Addr CmdLineFullPathFilename, NULL
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
; PasteJSON - paste json from clipboard to create a tree
;-------------------------------------------------------------------------------------
PasteJSON PROC USES EBX hWin:DWORD
    LOCAL ptrClipData:DWORD
    
    Invoke CloseJSONFile
    
    Invoke IsClipboardFormatAvailable, CF_TEXT
    .IF eax == FALSE
        ret
    .ENDIF
    
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
; Copies selected treeview item text to clipboard. if dwValueOnly == TRUE then 
; extracts the value from the colon in the text and copies it to clipboard
;-------------------------------------------------------------------------------------
CopyToClipboard PROC USES EBX hWin:DWORD, dwValueOnly:DWORD
    LOCAL ptrClipboardData:DWORD
    LOCAL hClipData:DWORD
    LOCAL pClipData:DWORD
    LOCAL LenData:DWORD
    
    Invoke OpenClipboard, hWin
    .IF eax == 0
        ret
    .ENDIF
    Invoke EmptyClipboard
    
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, 1024d
    mov ptrClipboardData, eax
    
    Invoke TreeViewGetSelectedText, hTV, Addr szSelectedTreeviewText, SIZEOF szSelectedTreeviewText
    .IF eax == 0
        Invoke GlobalFree, ptrClipboardData
        Invoke CloseClipboard
        ret
    .ENDIF
    Invoke szLen, Addr szSelectedTreeviewText
    mov LenData, eax
    
    .IF dwValueOnly == TRUE
        Invoke InString, 1, Addr szSelectedTreeviewText, Addr szColon
        .IF eax == 0 ; no match
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
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
        Invoke szRight, Addr szSelectedTreeviewText, ptrClipboardData, eax
        
        Invoke szLen, ptrClipboardData
        .IF eax == 0
            Invoke GlobalFree, ptrClipboardData
            Invoke CloseClipboard
            ret
        .ENDIF
    .ELSE
        Invoke RtlMoveMemory, ptrClipboardData, Addr szSelectedTreeviewText, LenData
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
    
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONCopiedDataToClipboard
    
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
    mov ebx, 1048d
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
; Add a new json type treeview item under current branch
;-------------------------------------------------------------------------------------
AddJSONItem PROC USES EBX hWin:DWORD, dwJsonType:DWORD
    LOCAL hJSON:DWORD
    LOCAL hJSONPrev:DWORD
    LOCAL hItemPrev:DWORD
    LOCAL nTVIndex:DWORD
    LOCAL prev:DWORD
    LOCAL nIcon:DWORD
    LOCAL hTVItem:DWORD
    
    Invoke TreeViewGetSelectedItem, hTV
    mov hTVNode, eax
    .IF eax == NULL
        Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_ROOT, NULL
        mov hTVNode, eax
        .IF eax == NULL
            ret
        .ENDIF
    .ENDIF
    
    Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    mov nTVIndex, eax

    mov eax, dwJsonType
    .IF eax == cJSON_Object
        Invoke szCopy, Addr szNewItem, Addr szItemText
        mov eax, IL_ICO_JSON_OBJECT
        mov nIcon, eax
    .ELSEIF eax == cJSON_Array
        Invoke szCopy, Addr szNewItem, Addr szItemText
        mov eax, IL_ICO_JSON_ARRAY
        mov nIcon, eax
    .ELSEIF eax == cJSON_String
        Invoke szCopy, Addr szNewItem, Addr szItemText
        mov eax, IL_ICO_JSON_STRING
        mov nIcon, eax        
    .ELSEIF eax == cJSON_Number
        Invoke szCopy, Addr szNewNumber, Addr szItemText
        mov eax, IL_ICO_JSON_NUMBER
        mov nIcon, eax        
    .ELSEIF eax == cJSON_True
        Invoke szCopy, Addr szNewTrue, Addr szItemText
        mov eax, IL_ICO_JSON_LOGICAL
        mov nIcon, eax        
    .ELSEIF eax == cJSON_False
        Invoke szCopy, Addr szNewFalse, Addr szItemText
        mov eax, IL_ICO_JSON_LOGICAL
        mov nIcon, eax
    .ENDIF
    
    ; Create a JSON object for our new item
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, SIZEOF cJSON
    mov hJSON, eax
    mov ebx, eax
    mov eax, dwJsonType
    mov [ebx].cJSON.itemtype, eax
    mov eax, hJSON
    mov [ebx].cJSON.valueint, eax ; store handle in this value
    mov dword ptr [ebx].cJSON.valuedouble, eax ; store handle in this value
    
    ; Get hJSON from previous treeview item and adjust its record to point to our new items hJSON
    ; and set our new items hJSON prev value to point to previous treeview item hJSON
    ; or if item didnt have a child before, point it to out new item we added
    Invoke SendMessage, hTV, TVM_GETNEXTITEM, TVGN_PREVIOUS, hTVNode
    .IF eax != NULL
        mov hItemPrev, eax
        Invoke TreeViewGetItemParam, hTV, hItemPrev
        .IF eax != NULL
            mov hJSONPrev, eax
            mov ebx, eax
            mov eax, hJSON
            mov [ebx].cJSON.next, eax
            mov ebx, hJSON
            mov eax, hJSONPrev
            mov [ebx].cJSON.prev, eax
        .ENDIF    
    .ELSE
        Invoke TreeViewGetItemParam, hTV, hTVNode
        .IF eax != NULL
            mov hJSONPrev, eax
            mov ebx, eax
            mov eax, [ebx].cJSON.child
            .IF eax == 0 ; didnt have a child previously
                mov eax, hJSONPrev
                mov [ebx].cJSON.child, eax
            .ENDIF
        .ENDIF
    .ENDIF

    Invoke SaveMenuState, hWin, TRUE
    Invoke SaveToolbarState, hWin, TRUE
    .IF nTVIndex == 1
        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, nIcon, nIcon, hJSON
    .ELSE
        Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, nIcon, nIcon, hJSON
    .ENDIF
    mov hTVItem, eax
    Invoke TreeViewItemExpand, hTV, hTVNode
    Invoke TreeViewSetSelectedItem, hTV, hTVItem, TRUE
    Invoke TreeViewItemExpand, hTV, hTVItem
    Invoke SendMessage, hTV, TVM_EDITLABEL, 0, hTVItem
    
    ret
AddJSONItem ENDP


;-------------------------------------------------------------------------------------
; Deletes a selected treeview item
;-------------------------------------------------------------------------------------
DelJSONItem PROC USES EBX hWin:DWORD
    LOCAL hItem:DWORD
    Invoke TreeViewGetSelectedItem, hTV
    mov hItem, eax
    Invoke TreeViewGetItemParam, hTV, hItem
    mov ebx, eax
    mov eax, [ebx].cJSON.valueint
    mov ebx, dword ptr [ebx].cJSON.valuedouble
    .IF (eax != 0 && ebx != 0) && (eax == ebx) ; if user added item in treeview, we stored handle to mem allocated cJSON struct in valueint and valuedouble fields
        Invoke GlobalFree, eax ; if both are the same value and are not 0 then we assume this value is the handle and try to free it.
    .ENDIF  
    
    Invoke TreeViewSetItemParam, hTV, hItem, NULL
    Invoke TreeViewItemDelete, hTV, hItem

    Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    .IF eax == 0
        Invoke SaveMenuState, hWin, FALSE
        Invoke SaveToolbarState, hWin, FALSE
        Invoke UpdateMenus, hWin, NULL
        Invoke ToolBarUpdate, hWin, NULL
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szSpace
    .ENDIF
    
    ret

DelJSONItem ENDP


;-------------------------------------------------------------------------------------
; Edit the treeview item text, F2 or double clicking on label does the same
;-------------------------------------------------------------------------------------
EditJSONItem PROC USES EBX hWin:DWORD
    Invoke TreeViewGetSelectedItem, hTV
    .IF eax != 0
        Invoke SendMessage, hTV, TVM_EDITLABEL, 0, eax
    .ENDIF
    ret
EditJSONItem ENDP


;-------------------------------------------------------------------------------------
; Creates a new json treeview
;-------------------------------------------------------------------------------------
NewJSON PROC USES EBX hWin:DWORD
    Invoke TreeViewDeleteAll, hTV
    Invoke CloseJSONFile
    
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONCreatedNewData

    ; Create a JSON object for our new item
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, SIZEOF cJSON
    mov hJSON_Object_Root, eax
    mov ebx, eax
    mov eax, cJSON_Object
    mov [ebx].cJSON.itemtype, eax
    mov eax, hJSON_Object_Root
    mov [ebx].cJSON.valueint, eax ; store handle in this value
    mov dword ptr [ebx].cJSON.valuedouble, eax ; store handle in this value    
    
    Invoke TreeViewInsertItem, hTV, NULL, Addr szJSONNewData, 0, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    mov hTVRoot, eax
    Invoke TreeViewSetSelectedItem, hTV, hTVRoot, TRUE
    Invoke TreeViewItemExpand, hTV, hTVRoot
    
    ret
NewJSON ENDP


;-------------------------------------------------------------------------------------
; InitJSONTreeview - Initialize JSON Treeview
;-------------------------------------------------------------------------------------
InitJSONTreeview PROC hWin:DWORD

    Invoke SendMessage, hTV, TVM_SETEXTENDEDSTYLE, TVS_EX_DOUBLEBUFFER, TVS_EX_DOUBLEBUFFER
    Invoke TreeViewLinkImageList, hTV, hIL, TVSIL_NORMAL
    
    Invoke TreeViewSubClassProc, hTV, Addr JSONTreeViewSubclass
    mov pOldTVProc, eax
    Invoke TreeViewSubClassData, hTV, pOldTVProc
    
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
; Subclass to capture and handle enter key pressed in labels
;-------------------------------------------------------------------------------------
JSONTreeViewSubclass PROC hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

	mov eax, uMsg
	.IF eax == WM_GETDLGCODE
	    mov eax, DLGC_WANTARROWS
	    ret
    
	.ELSE
	    invoke GetWindowLong, hWin, GWL_USERDATA
	    invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	.ENDIF
    ret

JSONTreeViewSubclass ENDP


;-------------------------------------------------------------------------------------
; Subclass to capture and handle enter key pressed in labels
;-------------------------------------------------------------------------------------
JSONTreeViewEditSubclass PROC hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    
	mov eax, uMsg
	.IF eax == WM_GETDLGCODE
	    mov eax, DLGC_WANTALLKEYS
	    ret
    
	.ELSE
	    invoke GetWindowLong, hWin, GWL_USERDATA
	    invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	.ENDIF
    ret

JSONTreeViewEditSubclass ENDP



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
ProcessJSONData PROC USES EBX hWin:DWORD, lpszJSONFile:DWORD, lpdwJSONData:DWORD
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
    
    .IF lpdwJSONData == NULL
        Invoke cJSON_Parse, JSONMemMapPtr
    .ELSE
        Invoke cJSON_Parse, lpdwJSONData
    .ENDIF
    mov hJSON_Object_Root, eax

    .IF hJSON_Object_Root == NULL && lpdwJSONData == NULL
        ; If empty then tell user some error about reading file
        Invoke szCopy, Addr szJSONErrorReadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret        
    .ELSEIF hJSON_Object_Root == NULL && lpdwJSONData != NULL
         ; If empty then tell user some error about reading clipboard data
        Invoke szCopy, Addr szJSONErrorClipData, Addr szJSONErrorMessage
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        ret  
    .ENDIF

    ; Just a check to make sure JSON has some stuff to process
    Invoke cJSON_GetArraySize, hJSON_Object_Root
    .IF eax == 0
        .IF lpdwJSONData == NULL
            Invoke szCopy, Addr szJSONErrorEmptyFile, Addr szJSONErrorMessage
            Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        .ELSE
            Invoke szCopy, Addr szJSONErrorEmptyClipData, Addr szJSONErrorMessage
        .ENDIF
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret
    .ENDIF

    ; Treeview Root is created, save handle to it, specifically we will need hTVNode later for when inserting children to treeview
    mov nTVIndex, 0
    .IF lpdwJSONData == NULL
        Invoke TreeViewInsertItem, hTV, NULL, lpszJSONFile, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    .ELSE
        Invoke TreeViewInsertItem, hTV, NULL, Addr szJSONClipboard, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    .ENDIF
    mov hTVRoot, eax
    mov hTVNode, eax
    mov hTVCurrentNode, eax
    inc nTVIndex
    
    
    ; Each time we insert a treeview item we need to increment our nTVIndex counter



    mov level, -1000d ; hack to force our while loop below, only used for possibly debugging/tracking indented levels (children)
    mov eax, hJSON_Object_Root 
    mov hJSON, eax ; use hJSON as variable to process in our loop
    
    ; create virtual stack to hold array iterator names
    Invoke VirtualStackCreate, VIRTUALSTACK_SIZE_TINY, VIRTUALSTACK_OPTION_UNIQUE
    mov hVirtualStack, eax
    mov hArray, NULL
    mov hCurrentArray, NULL

    .WHILE level != 0

        .IF level == -1000d
            mov level, 1 ; set our level to 1, useful for debugging and checking we havnt push/popd too much
            push hJSON ; push hJSON, then hTVNode. NOTE: we must pop these in reverse order to retrieve them when we fall back up the tree
            push hTVNode
            Invoke VirtualStackPush, hVirtualStack, hArray
            ;Push hArray
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
        
            .IF hArray != NULL

                Invoke CreateJSONArrayIteratorName, hArray, Addr szItemTextArrayName
                Invoke IncJSONStackItemCount, hArray
                
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
                    
                    Invoke TreeViewGetItemParam, hTV, hTVCurrentNode
                    ;PrintDec eax
                    ;PrintDec hTVCurrentNode
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

            .IF LenItemString == 0
                Invoke szCopy, Addr szNullArray, Addr szItemTextArrayName
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemTextArrayName
            .ENDIF
            Invoke CreateJSONStackItem, Addr szItemTextArrayName
            mov hCurrentArray, eax

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

            mov eax, jsontype
            .IF eax == cJSON_Array
                Invoke VirtualStackPush, hVirtualStack, hCurrentArray
                ;push hCurrentArray
                mov eax, hCurrentArray
                mov hArray, eax
                ;mov hCurrentArray, NULL
            .ELSE
                Invoke VirtualStackPush, hVirtualStack, hArray
                ;push hArray
                mov hArray, NULL
            .ENDIF
            mov eax, hArray
            mov hCurrentArray, eax

            
        .ELSE ; No child cJSON object, so look for siblings
            .IF next != 0 ; we have a sibling
                mov eax, next ; set next cJSON object as the cJSON object to process in our loop
                mov hJSON, eax
            .ELSE ; No child or siblings, so must be at the last sibling, so here is the fun stuff
                    
                Invoke VirtualStackPop, hVirtualStack, Addr VSValue
                .IF eax == TRUE
                    mov eax, VSValue
                    mov hArray, eax
                .ELSEIF eax == FALSE
                    IFDEF DEBUG32
                    PrintText 'VirtualStackPop Error'
                    ENDIF
                    ret
                .ELSE
                    IFDEF DEBUG32
                    PrintText 'VirtualStackPop End of Stack'
                    ENDIF
                    ret
                .ENDIF
                ;pop hArray

                pop hTVNode ; pop hTVNode before hJSON (reverse of what we pushed previously)
                pop hJSON ; we now have the last levels cJSON object and the parent of the last inserted treeview item
                
                dec level ; we are moving down a level, so decrement level
                mov ebx, hJSON ; fetch the next cJSON object of the cJSON object we just restored with the pop hJSON 
                mov eax, [ebx].cJSON.next
                
                .WHILE eax == 0 && level != 1 ; if next is 0 and we are still a level greater than 1 we loop, restoring previous cJSON objects and hTVNodes

                    Invoke VirtualStackPop, hVirtualStack, Addr VSValue
                    .IF eax == TRUE
                        mov eax, VSValue
                        mov hArray, eax
                    .ELSEIF eax == FALSE
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPop Error'
                        ENDIF
                        ret
                    .ELSE
                        IFDEF DEBUG32
                        PrintText 'VirtualStackPop End of Stack'
                        ENDIF
                        ret
                    .ENDIF
                    ;pop hArray
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

        Invoke TreeViewItemExpand, hTV, hTVNode

    .ENDW

;    IFDEF DEBUG32
;        Invoke VirtualStackDepth, hVirtualStack
;        mov nStackDepth, eax
;        PrintDec nStackDepth
;        
;        Invoke VirtualStackUniqueCount, hVirtualStack
;        mov nUniqueCount, eax
;        PrintDec nUniqueCount
;        
;        Invoke VirtualStackData, hVirtualStack
;        mov pStackData, eax
;        PrintDec pStackData
;        mov eax, VIRTUALSTACK_SIZE_TINY
;        mov ebx, SIZEOF DWORD
;        mul ebx
;        DbgDump pStackData, eax
;    ENDIF
    
    Invoke TreeViewItemExpand, hTV, hTVRoot
    Invoke TreeViewSetSelectedItem, hTV, hTVRoot, TRUE
    
    Invoke VirtualStackDelete, hVirtualStack, Addr DeleteStackItemsCallback
    
    ; we have finished processing the cJSON objects, following children then following siblings, then moving back up the list/level, getting next object and 
    ; repeating till no more objects where left to process and all treeview items have been inserted at the correct 'level' indentation or whatever.
    
    Invoke cJSON_free, hJSON_Object_Root ; Clear up the mem alloced by cJSON_Parse

    ; Tell user via statusbar that JSON file was successfully loaded
    .IF lpdwJSONData == NULL
        Invoke szCopy, Addr szJSONLoadedFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
    .ELSE
        Invoke szCopy, Addr szJSONLoadedClipData, Addr szJSONErrorMessage
    .ENDIF
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage     
    
    Invoke SetFocus, hTV
    
    mov eax, TRUE
    
    ret
ProcessJSONData ENDP




end start
















