.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1

;EXPERIMENTAL_ARRAYNAME_STACK EQU 1 ; Experimental, doesnt seem to work properly, so use if you uncomment, use with caution

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
include statusbar.asm
;include TVFind.asm
include search.asm
include clipboard.asm

IFDEF EXPERIMENTAL_ARRAYNAME_STACK
include stack.asm
ENDIF

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
WndProc proc USES EBX hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    LOCAL tvhi:TV_HITTESTINFO
    LOCAL hItem:DWORD
    
    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        push hWin
        pop hWnd
        ; Init Stuff Here
        
        mov hJSONFile, NULL
        mov hJSONTreeRoot, NULL
        
        Invoke InitGUI, hWin

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
                Invoke OpenJSONFile, hWin, Addr JsonOpenedFilename
                .IF eax == TRUE
                    ; Start processing JSON file
                    Invoke ProcessJSONData, hWin, Addr JsonOpenedFilename, NULL
                .ENDIF
            .ENDIF
          
        .ELSEIF eax == IDM_FILE_CLOSE || eax == ACC_FILE_CLOSE || eax == TB_FILE_CLOSE
            ;Invoke TreeViewDeleteAll, hTV
            Invoke CloseJSONFile, hWin
            ;Invoke ResetMenus, hWin
            ;Invoke ResetToolbars, hWin
        
        .ELSEIF eax == IDM_FILE_NEW || eax == ACC_FILE_NEW || eax == TB_FILE_NEW
            Invoke NewJSON, hWin
            ;Invoke SaveMenuState, hWin, TRUE
            ;Invoke SaveToolbarState, hWin, TRUE
        
        .ELSEIF eax == IDM_FILE_SAVE || eax == ACC_FILE_SAVE || eax == TB_FILE_SAVE
            Invoke SaveJSONFile, hWin, FALSE
        
        .ELSEIF eax == IDM_FILE_SAVEAS || eax == ACC_FILE_SAVEAS || eax == TB_FILE_SAVEAS
            Invoke SaveJSONFile, hWin, TRUE
        
        .ELSEIF eax == IDM_HELP_ABOUT
            Invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
        
        .ELSEIF eax == IDM_EDIT_PASTE_JSON || eax == IDM_CMD_PASTE_JSON
            ;Invoke TreeViewDeleteAll, hTV
            Invoke PasteJSON, hWin
        
        .ELSEIF eax == IDM_EDIT_COPY_TEXT || eax == IDM_CMD_COPY_TEXT
            Invoke CopyToClipboard, hWin, FALSE
        
        .ELSEIF eax == IDM_EDIT_COPY_VALUE || eax == IDM_CMD_COPY_VALUE
            Invoke CopyToClipboard, hWin, TRUE
        
        .ELSEIF eax == IDM_EDIT_COPY_ITEM || eax == IDM_CMD_COPY_ITEM || eax == ACC_EDIT_COPY_ITEM || eax == TB_EDIT_COPY_ITEM
            Invoke CopyItem, hWin, NULL, FALSE
            
        .ELSEIF eax == IDM_EDIT_COPY_BRANCH || eax == IDM_CMD_COPY_BRANCH || eax == ACC_EDIT_COPY_BRANCH || eax == TB_EDIT_COPY_BRANCH
            Invoke CopyBranchToClipboard, hWin
        
        .ELSEIF eax == IDM_EDIT_PASTE_ITEM || eax == IDM_CMD_PASTE_ITEM || eax == ACC_EDIT_PASTE_ITEM || eax == TB_EDIT_PASTE_ITEM
            Invoke PasteItem, hWin, NULL
        
        .ELSEIF eax == IDM_EDIT_PASTE_BRANCH || eax == IDM_CMD_PASTE_BRANCH || eax == ACC_EDIT_PASTE_BRANCH || eax == TB_EDIT_PASTE_BRANCH
        
        .ELSEIF eax == IDM_EDIT_FIND || eax == IDM_CMD_FIND || eax == ACC_EDIT_FIND || eax == TB_EDIT_FIND
            Invoke SetFocus, hTxtSearchTextbox
            ;Invoke SearchTextboxStartSearch, hWin
        
        .ELSEIF eax == IDM_CMD_COLLAPSE_BRANCH
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewItemCollapse, hTV, eax
            
        .ELSEIF eax == IDM_CMD_EXPAND_BRANCH
            Invoke TreeViewGetSelectedItem, hTV
            Invoke TreeViewItemExpand, hTV, eax

        .ELSEIF eax == IDM_CMD_COLLAPSE_ALL
            Invoke TreeViewCollapseAll, hTV
            
        .ELSEIF eax == IDM_CMD_EXPAND_ALL
            Invoke TreeViewExpandAll, hTV
        
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
        
        Invoke DragQueryFile, hDrop, 0, Addr JsonOpenedFilename, SIZEOF JsonOpenedFilename
        .IF eax != 0
            Invoke OpenJSONFile, hWin, Addr JsonOpenedFilename
            .IF eax == TRUE
                ; Start processing JSON file
                Invoke ProcessJSONData, hWin, Addr JsonOpenedFilename, NULL
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
        Invoke SendMessage, hSB, WM_SIZE, 0, 0

    .ELSEIF eax==WM_NOTIFY
        mov ebx,lParam
        mov eax, (NMHDR PTR [ebx]).code
        mov ebx, (NMHDR PTR [ebx]).hwndFrom
        
        .IF ebx == hTV
            .IF eax == NM_RCLICK
    	        Invoke UpdateMenus, hWin, NULL
    	        Invoke ToolBarUpdate, hWin, NULL
                Invoke ShowRightClickMenu, hWin
            
            .ELSEIF eax == NM_CLICK
                Invoke GetCursorPos, Addr tvhi.pt
                Invoke ScreenToClient, hTV, addr tvhi.pt
                Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi
                .IF tvhi.flags == TVHT_ONITEMLABEL
                    mov eax, tvhi.hItem
                    mov hFoundItem, eax
                    ;mov hTVSelectedItem, eax
                    ;PrintDec hTVSelectedItem
                    ;mov bSearchTermNew, TRUE
                .ENDIF
                ;Invoke ShowSearchTextbox, hWin, FALSE
                ;Invoke UpdateMenus, hWin, NULL
                ;Invoke ToolBarUpdate, hWin, NULL
            
            .ELSEIF eax == NM_DBLCLK
                Invoke EditJSONItem, hWin
            
            .ELSEIF eax == TVN_KEYDOWN
                mov ebx, lParam
                movzx eax, (TV_KEYDOWN ptr [ebx]).wVKey
                .IF eax == VK_F2
                    Invoke EditJSONItem, hWin
                
                .ELSEIF eax == VK_F3
                    Invoke SetFocus, hTxtSearchTextbox
                    Invoke SearchTextboxStartSearch, hWin

                .ELSEIF eax == VK_F
                    Invoke GetAsyncKeyState, VK_CONTROL
                    .IF eax != 0
                        ;PrintText 'TVN_KEYDOWN:CTRL+F'
                        Invoke SetFocus, hTxtSearchTextbox
                    .ENDIF

                .ELSEIF eax == VK_V
                    Invoke GetAsyncKeyState, VK_CONTROL
                    .IF eax != 0
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
                mov ebx, lParam
                mov eax, (NM_TREEVIEW PTR [ebx]).itemNew.hItem
                mov hItem, eax
                Invoke ToolBarUpdate, hWin, hItem
                Invoke UpdateMenus, hWin, hItem
                
            .ELSEIF eax == TVN_BEGINLABELEDIT
                mov ebx, lParam
                mov eax, (TV_DISPINFO PTR [ebx]).item.pszText
                .IF eax != NULL
                    Invoke szCopy, eax, Addr szTVLabelEditOldText
                .ENDIF
                Invoke SendMessage, hTV, TVM_GETEDITCONTROL, 0, 0
                mov hTVEditControl, eax
                Invoke SetWindowLong, hTVEditControl, GWL_WNDPROC, Addr JSONTreeViewEditSubclass
                Invoke SetWindowLong, hTVEditControl, GWL_USERDATA, eax
                mov eax, FALSE
                ret
                
            .ELSEIF eax == TVN_ENDLABELEDIT
                mov ebx, lParam
                mov eax, (TV_DISPINFO PTR [ebx]).item.pszText
                .IF eax != NULL
                    Invoke szCopy, eax, Addr szTVLabelEditNewText
                    Invoke szCmp, Addr szTVLabelEditOldText, Addr szTVLabelEditNewText
                    .IF eax == 0
                        mov g_Edit, TRUE
                        mov ebx, lParam
                        mov eax, (TV_DISPINFO PTR [ebx]).item.hItem
                        mov hItem, eax
                        Invoke ToolBarUpdate, hWin, hItem
                        Invoke UpdateMenus, hWin, hItem
                    .ENDIF
                    mov eax, TRUE
                    ret
                .ELSE
                    mov eax, TRUE
                    ret
                .ENDIF

            .ENDIF
        
        .ELSE
        
            .IF eax == TBN_DROPDOWN
                Invoke ToolBarShowDropdownAddMenu, hWin
            .ELSE
                Invoke ToolBarTips, lParam
            .ENDIF
            
        .ENDIF

    .ELSEIF eax == WM_CLOSE
        Invoke CloseJSONFile, hWin
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
        Invoke  StatusBarSetPanelText, 2, Addr szJSONErrorMessage    
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
    LOCAL ncm:NONCLIENTMETRICS
    LOCAL lfnt:LOGFONT
    
    Invoke CreateSolidBrush, 0FFFFFFh
    mov hWhiteBrush, eax

	mov ncm.cbSize, SIZEOF NONCLIENTMETRICS
	Invoke SystemParametersInfo, SPI_GETNONCLIENTMETRICS, SIZEOF NONCLIENTMETRICS, Addr ncm, 0
	Invoke CreateFontIndirect, Addr ncm.lfMessageFont
	mov hFontNormal, eax
	Invoke GetObject, hFontNormal, SIZEOF lfnt, Addr lfnt
	mov lfnt.lfWeight, FW_BOLD
	Invoke CreateFontIndirect, Addr lfnt
	mov hFontBold, eax

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
    
    ; Init other controls
    Invoke InitMenus, hWin
    Invoke InitToolbar, hWin, 16, 16
    Invoke InitJSONStatusbar, hWin
    Invoke InitJSONTreeview, hWin
    Invoke InitStatusBar, hWin
    Invoke InitSearchTextbox, hWin
    
    ret

InitGUI ENDP


;-------------------------------------------------------------------------------------
; Add a new json type treeview item under current branch
;-------------------------------------------------------------------------------------
AddJSONItem PROC USES EBX hWin:DWORD, dwJsonType:DWORD
    LOCAL hJSON:DWORD
    LOCAL hJSONPrev:DWORD
    LOCAL hItemPrev:DWORD
    ;LOCAL nTVIndex:DWORD
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
    
    ;Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    ;mov nTVIndex, eax
    

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
    
    mov g_Edit, TRUE
    Invoke SaveMenuState, hWin, TRUE
    Invoke SaveToolbarState, hWin, TRUE

    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, nIcon, nIcon, hJSON

    mov hTVItem, eax
    inc g_nTVIndex
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
        mov g_nTVIndex, 0
        mov g_Edit, FALSE
        Invoke  StatusBarSetPanelText, 2, Addr szSpace
        Invoke SetWindowTitle, hWin, NULL

    .ELSE
        mov g_Edit, TRUE
    .ENDIF

    Invoke UpdateMenus, hWin, NULL
    Invoke ToolBarUpdate, hWin, NULL    
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
    Invoke CloseJSONFile, hWin
    
    ; Create a JSON object for our new item
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, SIZEOF cJSON
    mov hJSON_Object_Root, eax
    mov ebx, eax
    mov eax, cJSON_Object
    mov [ebx].cJSON.itemtype, eax
    mov eax, hJSON_Object_Root
    mov [ebx].cJSON.valueint, eax ; store handle in this value
    mov dword ptr [ebx].cJSON.valuedouble, eax ; store handle in this value    
    
    Invoke  StatusBarSetPanelText, 2, Addr szJSONCreatedNewData
    Invoke SetWindowTitle, hWin, Addr szJSONNew

    mov g_Edit, TRUE
    Invoke SaveMenuState, hWin, TRUE
    Invoke SaveToolbarState, hWin, TRUE
    Invoke UpdateMenus, hWin, NULL
    Invoke ToolBarUpdate, hWin, NULL
    
    mov g_nTVIndex, 0
    
    Invoke TreeViewInsertItem, hTV, NULL, Addr szJSONNewData, g_nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
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
    Invoke  StatusBarSetPanelText, 2, CTEXT("  ")         
    
    ret

InitJSONStatusbar ENDP


;-------------------------------------------------------------------------------------
; Subclass to capture and handle enter key pressed in labels
;-------------------------------------------------------------------------------------
JSONTreeViewSubclass PROC hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

	mov eax, uMsg
	.IF eax == WM_GETDLGCODE
	    mov eax, DLGC_WANTARROWS or DLGC_WANTTAB ;or DLGC_WANTALLKEYS ; DLGC_WANTARROWS or 
	    ret
	    
    .ELSEIF eax == WM_CHAR
        mov eax, wParam
        .IF eax == VK_TAB
            xor eax, eax
            ret

        .ELSE
	        Invoke GetWindowLong, hWin, GWL_USERDATA
	        Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	        ret
        .ENDIF
    
    .ELSEIF eax == WM_KEYDOWN
        mov eax, wParam
        .IF eax == VK_TAB
            Invoke SetFocus, hTxtSearchTextbox
            xor eax, eax
            ret
            
;        .ELSEIF eax == VK_F
;            Invoke GetAsyncKeyState, VK_CONTROL
;            .IF eax != 0
;                PrintText 'WM_KEYDOWN:CTRL+F'
;                Invoke SetFocus, hTxtSearchTextbox
;                xor eax, eax
;                ret                
;            .ELSE
;	            Invoke GetWindowLong, hWin, GWL_USERDATA
;	            Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
;	            ret
;            .ENDIF
        .ELSE
	        Invoke GetWindowLong, hWin, GWL_USERDATA
	        Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	        ret
        .ENDIF
    
	.ELSE
	    invoke GetWindowLong, hWin, GWL_USERDATA
	    invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	    ret
	.ENDIF
	
	Invoke GetWindowLong, hWin, GWL_USERDATA
	Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam		
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
    Invoke RtlZeroMemory, Addr BrowseFile, SIZEOF BrowseFile
    Invoke RtlZeroMemory, Addr JsonOpenedFilename, SIZEOF JsonOpenedFilename
    push hWin
    pop BrowseFile.hwndOwner
    lea eax, JsonOpenFileFilter
    mov BrowseFile.lpstrFilter, eax
    lea eax, JsonOpenedFilename
    mov BrowseFile.lpstrFile, eax
    lea eax, JsonOpenFileFileTitle
    mov BrowseFile.lpstrTitle, eax
    mov BrowseFile.nMaxFile, SIZEOF JsonOpenedFilename
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
        Invoke CloseJSONFile, hWin
    .ENDIF
    
    ; Tell user we are loading file
    Invoke szCopy, Addr szJSONLoadingFile, Addr szJSONErrorMessage
    Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
    Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
    ;Invoke StatusBarSetPanelText, 2, lpszJSONFile
    
    Invoke CreateFile, lpszJSONFile, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    .IF eax == INVALID_HANDLE_VALUE
        ; Tell user via statusbar that JSON file did not load
        Invoke szCopy, Addr szJSONErrorLoadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
        mov eax, FALSE
        ret
    .ENDIF
    mov hJSONFile, eax

    Invoke CreateFileMapping, hJSONFile, NULL, PAGE_READWRITE, 0, 0, NULL ; Create memory mapped file
    .IF eax == NULL
        ; Tell user via statusbar that JSON file did not map
        Invoke szCopy, Addr szJSONErrorMappingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
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
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
        Invoke CloseHandle, JSONMemMapHandle
        Invoke CloseHandle, hJSONFile
        mov eax, FALSE
        ret
    .ENDIF
    mov JSONMemMapPtr, eax  
    
    Invoke GetFileSize, hJSONFile, NULL
    mov dwFileSize, eax
    
    
    mov eax, TRUE
    
    ret

OpenJSONFile ENDP


;-------------------------------------------------------------------------------------
; CloseJSONFile - Closes JSON file and deletes any treeview data and json data
;-------------------------------------------------------------------------------------
CloseJSONFile PROC hWin:DWORD

    .IF g_Edit == TRUE
		Invoke MessageBox, hWin, Addr szJSONSaveChanges, Addr AppName, MB_ICONQUESTION+MB_YESNO
		.IF eax == IDYES
			Invoke SaveJSONFile, hWin, FALSE
		.ENDIF         
    .ENDIF

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
    
    Invoke RtlZeroMemory, Addr JsonOpenedFilename, SIZEOF JsonOpenedFilename
    Invoke RtlZeroMemory, Addr JsonSavedFilename, SIZEOF JsonSavedFilename
    
    Invoke TreeViewDeleteAll, hTV
    Invoke SetWindowTitle, hWin, NULL
    Invoke  StatusBarSetPanelText, 2, Addr szSpace

    mov g_nTVIndex, 0

    mov g_Edit, FALSE
    Invoke ResetMenus, hWin
    Invoke ResetToolbars, hWin
    Invoke SetFocus, hTV

    ret

CloseJSONFile ENDP


;-------------------------------------------------------------------------------------
; SaveJSONFile - Saves json file
;-------------------------------------------------------------------------------------
SaveJSONFile PROC hWin:DWORD, bSaveAs:DWORD
    LOCAL bShowSaveAsDialog:DWORD
    
    mov bShowSaveAsDialog, FALSE
    
    mov eax, bSaveAs
    .IF bSaveAs == TRUE
        mov bShowSaveAsDialog, TRUE
    .ELSE
        .IF JsonOpenedFilename == 0
            mov bShowSaveAsDialog, TRUE
        .ELSE
            Invoke szLen, Addr JsonOpenedFilename
            .IF eax == 0
                mov bShowSaveAsDialog, TRUE
            .ENDIF
        .ENDIF
    .ENDIF
    
    
    .IF bShowSaveAsDialog == TRUE
        
        Invoke RtlZeroMemory, Addr SaveFile, SIZEOF SaveFile
        Invoke RtlZeroMemory, Addr JsonSavedFilename, SIZEOF JsonSavedFilename
        push hWin
        pop SaveFile.hwndOwner
        lea eax, JsonSaveFileFilter
        mov SaveFile.lpstrFilter, eax
        lea eax, JsonSavedFilename
        mov SaveFile.lpstrFile, eax
        lea eax, JsonSaveFileFileTitle
        mov SaveFile.lpstrTitle, eax
        mov SaveFile.nMaxFile, SIZEOF JsonSavedFilename
        lea eax, JsonSaveDefExt
        mov SaveFile.lpstrDefExt, eax
        mov SaveFile.nFilterIndex, 1 ; json
        mov SaveFile.Flags, OFN_EXPLORER
        mov SaveFile.lStructSize, SIZEOF SaveFile
        Invoke GetSaveFileName, Addr SaveFile

    .ELSE
        Invoke szCopy, Addr JsonOpenedFilename, Addr JsonSavedFilename
        mov eax, TRUE
    .ENDIF

    .IF eax !=0
        ; save actual file contents
        
        ; update opened file to reflect new file name
        ; update status bar with filename
        ; update title bar with filename
        
        Invoke szCopy, Addr JsonSavedFilename, Addr JsonOpenedFilename
        Invoke SetWindowTitle, hWin, Addr JsonSavedFilename
        
        Invoke TreeViewSetItemText, hTV, hTVRoot, Addr JsonSavedFilename
        
        Invoke szCopy, Addr szJSONSavedFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, Addr JsonSavedFilename
        Invoke  StatusBarSetPanelText, 2, Addr szJSONErrorMessage    
        
        mov g_Edit, FALSE
        Invoke SaveMenuState, hWin, FALSE
        Invoke SaveToolbarState, hWin, FALSE        
    .ENDIF    
    
    ret

SaveJSONFile ENDP


;-------------------------------------------------------------------------------------
; ProcessJSONFile - Process JSON file and load data into treeview
;-------------------------------------------------------------------------------------
ProcessJSONData PROC USES EBX hWin:DWORD, lpszJSONFile:DWORD, lpdwJSONData:DWORD
    ;LOCAL nTVIndex:DWORD
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
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage    
        ret        
    .ELSEIF hJSON_Object_Root == NULL && lpdwJSONData != NULL
         ; If empty then tell user some error about reading clipboard data
        Invoke szCopy, Addr szJSONErrorClipData, Addr szJSONErrorMessage
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage
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
        Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage    
        ret
    .ENDIF

    ; Treeview Root is created, save handle to it, specifically we will need hTVNode later for when inserting children to treeview
    ;mov nTVIndex, 0
    .IF lpdwJSONData == NULL
        Invoke JustFnameExt, lpszJSONFile, Addr szJustFilename
        Invoke TreeViewInsertItem, hTV, NULL, Addr szJustFilename, g_nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    .ELSE
        Invoke TreeViewInsertItem, hTV, NULL, Addr szJSONClipboard, g_nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, hJSON_Object_Root
    .ENDIF
    mov hTVRoot, eax
    mov hTVNode, eax
    mov hTVCurrentNode, eax
    inc g_nTVIndex
    
    
    ; Each time we insert a treeview item we need to increment our nTVIndex counter



    mov level, -1000d ; hack to force our while loop below, only used for possibly debugging/tracking indented levels (children)
    mov eax, hJSON_Object_Root 
    mov hJSON, eax ; use hJSON as variable to process in our loop
    
    IFDEF EXPERIMENTAL_ARRAYNAME_STACK
    ; create virtual stack to hold array iterator names
    Invoke VirtualStackCreate, VIRTUALSTACK_SIZE_TINY, VIRTUALSTACK_OPTION_UNIQUE
    mov hVirtualStack, eax
    mov hArray, NULL
    mov hCurrentArray, NULL
    ENDIF

    Invoke SendMessage, hTV, WM_SETREDRAW, FALSE, 0

    .WHILE level != 0

        .IF level == -1000d
            mov level, 1 ; set our level to 1, useful for debugging and checking we havnt push/popd too much
            push hJSON ; push hJSON, then hTVNode. NOTE: we must pop these in reverse order to retrieve them when we fall back up the tree
            push hTVNode
            IFDEF EXPERIMENTAL_ARRAYNAME_STACK
            Invoke VirtualStackPush, hVirtualStack, hArray
            ENDIF
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
            
            IFDEF EXPERIMENTAL_ARRAYNAME_STACK
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
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemTextArrayName, g_nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc g_nTVIndex
                    
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
                
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc g_nTVIndex
                .ENDIF
                
            .ELSE
            ENDIF
            
                .IF LenItemString == 0
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szObject, g_nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc g_nTVIndex
                .ELSE
                    
                    Invoke szCopy, lpszItemString, Addr szItemText
                    Invoke szCatStr, Addr szItemText, Addr szColon
                    .IF LenItemStringValue != 0
                        Invoke szCatStr, Addr szItemText, Addr szSpace
                        Invoke szCatStr, Addr szItemText, lpszItemStringValue
                    .ENDIF
                    Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                    mov hTVCurrentNode, eax
                    inc g_nTVIndex
                    ;Invoke TreeViewItemExpand, hTV, hTVNode
                    ;Invoke TreeViewItemExpand, hTV, hTVCurrentNode
                .ENDIF
            
            IFDEF EXPERIMENTAL_ARRAYNAME_STACK
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
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_STRING, IL_ICO_JSON_STRING, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex

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
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_INTEGER, IL_ICO_JSON_INTEGER, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex
        
        .ELSEIF eax == cJSON_True
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szTrue
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex

        .ELSEIF eax == cJSON_False
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szFalse
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex

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

            IFDEF EXPERIMENTAL_ARRAYNAME_STACK
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullArray, Addr szItemTextArrayName
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemTextArrayName
            .ENDIF
            Invoke CreateJSONStackItem, Addr szItemTextArrayName
            mov hCurrentArray, eax
            ENDIF
            
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_ARRAY, IL_ICO_JSON_ARRAY, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex
            ;Invoke TreeViewItemExpand, hTV, hTVNode
            ;Invoke TreeViewItemExpand, hTV, hTVCurrentNode

        .ELSEIF eax == cJSON_NULL
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullNull, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szNull
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_NULL, IL_ICO_JSON_NULL, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex

        .ELSEIF eax == cJSON_Invalid
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullInvalid, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szInvalid
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, g_nTVIndex, TVI_LAST, IL_ICO_JSON_INVALID, IL_ICO_JSON_INVALID, hJSON
            mov hTVCurrentNode, eax
            inc g_nTVIndex

        .ELSEIF eax == cJSON_Raw

        .ENDIF
        
        Invoke TreeViewItemExpand, hTV, hTVNode
        Invoke TreeViewItemExpand, hTV, hTVCurrentNode


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
            
            IFDEF EXPERIMENTAL_ARRAYNAME_STACK
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
            ENDIF
            
        .ELSE ; No child cJSON object, so look for siblings
            .IF next != 0 ; we have a sibling
                
                mov eax, next ; set next cJSON object as the cJSON object to process in our loop
                mov hJSON, eax
            .ELSE ; No child or siblings, so must be at the last sibling, so here is the fun stuff
                
                IFDEF EXPERIMENTAL_ARRAYNAME_STACK
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
                ENDIF

                pop hTVNode ; pop hTVNode before hJSON (reverse of what we pushed previously)
                pop hJSON ; we now have the last levels cJSON object and the parent of the last inserted treeview item
                dec level ; we are moving down a level, so decrement level
                
                mov ebx, hJSON ; fetch the next cJSON object of the cJSON object we just restored with the pop hJSON 
                mov eax, [ebx].cJSON.next
                
                .WHILE eax == 0 && level != 1 ; if next is 0 and we are still a level greater than 1 we loop, restoring previous cJSON objects and hTVNodes
                    
                    IFDEF EXPERIMENTAL_ARRAYNAME_STACK
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

    .ENDW

    Invoke SendMessage, hTV, WM_SETREDRAW, TRUE, 0

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
    
    IFDEF EXPERIMENTAL_ARRAYNAME_STACK
    Invoke VirtualStackDelete, hVirtualStack, Addr DeleteStackItemsCallback
    ENDIF
    
    ; we have finished processing the cJSON objects, following children then following siblings, then moving back up the list/level, getting next object and 
    ; repeating till no more objects where left to process and all treeview items have been inserted at the correct 'level' indentation or whatever.
    
    Invoke cJSON_free, hJSON_Object_Root ; Clear up the mem alloced by cJSON_Parse

    ; Tell user via statusbar that JSON file was successfully loaded
    .IF lpdwJSONData == NULL
        Invoke szCopy, Addr szJSONLoadedFile, Addr szJSONErrorMessage
        Invoke JustFnameExt, lpszJSONFile, Addr szJustFilename
        Invoke szCatStr, Addr szJSONErrorMessage, Addr szJustFilename ;lpszJSONFile
        Invoke SetWindowTitle, hWin, lpszJSONFile
    .ELSE
        Invoke szCopy, Addr szJSONLoadedClipData, Addr szJSONErrorMessage
        Invoke SetWindowTitle, hWin, Addr szClipboardData
    .ENDIF
    Invoke StatusBarSetPanelText, 2, Addr szJSONErrorMessage     
    
    Invoke UpdateMenus, hWin, NULL
    Invoke ToolBarUpdate, hWin, NULL

    
    Invoke SetFocus, hTV
    
    mov eax, TRUE
    
    ret
ProcessJSONData ENDP


;-------------------------------------------------------------------------------------
; Sets window title
;-------------------------------------------------------------------------------------
SetWindowTitle PROC hWin:DWORD, lpszTitleText:DWORD
    Invoke szCopy, Addr AppName, Addr TitleText
    .IF lpszTitleText != NULL
        Invoke szLen, lpszTitleText
        .IF eax != 0
            Invoke szCatStr, Addr TitleText, Addr szSpace
            Invoke szCatStr, Addr TitleText, Addr szDash
            Invoke szCatStr, Addr TitleText, Addr szSpace
            Invoke szCatStr, Addr TitleText, lpszTitleText
        .ENDIF
    .ENDIF
    Invoke SetWindowText, hWin, Addr TitleText
    ret
SetWindowTitle ENDP



;**************************************************************************
; Strip path name to just filename with extention
;**************************************************************************
JustFnameExt PROC USES ESI EDI szFilePathName:DWORD, szFileName:DWORD
	LOCAL LenFilePathName:DWORD
	LOCAL nPosition:DWORD
	
	Invoke szLen, szFilePathName
	mov LenFilePathName, eax
	mov nPosition, eax
	
	.IF LenFilePathName == 0
	    mov edi, szFileName
		mov byte ptr [edi], 0
		mov eax, FALSE
		ret
	.ENDIF
	
	mov esi, szFilePathName
	add esi, eax
	
	mov eax, nPosition
	.WHILE eax != 0
		movzx eax, byte ptr [esi]
		.IF al == '\' || al == ':' || al == '/'
			inc esi
			.BREAK
		.ENDIF
		dec esi
		dec nPosition
		mov eax, nPosition
	.ENDW
	mov edi, szFileName
	mov eax, nPosition
	.WHILE eax != LenFilePathName
		movzx eax, byte ptr [esi]
		mov byte ptr [edi], al
		inc edi
		inc esi
		inc nPosition
		mov eax, nPosition
	.ENDW
	mov byte ptr [edi], 0h ; null out filename
	mov eax, TRUE
	ret

JustFnameExt	ENDP


end start
















