.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 15
option frame : auto
;option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

;DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \UASM\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
    include \UASM\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF

include cjsontree.inc

.CODE
;-------------------------------------------------------------------------------------
; Start
;-------------------------------------------------------------------------------------
WinMainCRTStartup proc FRAME
	invoke GetModuleHandle, NULL
	mov hInstance, rax
	invoke GetCommandLine
	mov CommandLine, rax
	Invoke InitCommonControls
	mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
    
    Invoke ProcessCmdLine
    
	invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess, eax
    ret
WinMainCRTStartup endp
	

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc FRAME hInst:HINSTANCE, hPrev:HINSTANCE, CmdLine:LPSTR, iShow:DWORD
	LOCAL msg:MSG
	LOCAL wcex:WNDCLASSEX
	
	mov wcex.cbSize, sizeof WNDCLASSEX
	mov wcex.style, CS_HREDRAW or CS_VREDRAW
	lea rax, WndProc
	mov wcex.lpfnWndProc, rax
	mov wcex.cbClsExtra, 0
	mov wcex.cbWndExtra, DLGWINDOWEXTRA
	mov rax, hInst
	mov wcex.hInstance, rax
	mov wcex.hbrBackground, COLOR_BTNFACE+1
	mov wcex.lpszMenuName, IDM_MENU ;NULL 
	lea rax, ClassName
	mov wcex.lpszClassName, rax
	Invoke LoadIcon, hInst, ICO_MAIN ; resource icon for main application icon
	mov hICO_MAIN, eax ; main application icon	
	mov wcex.hIcon, rax
	mov wcex.hIconSm, rax
	Invoke LoadCursor, NULL, IDC_ARROW
	mov wcex.hCursor, rax
	Invoke RegisterClassEx, addr wcex
	Invoke CreateDialogParam, hInstance, IDD_DIALOG, 0, Addr WndProc, 0
	mov hWnd, rax
	Invoke ShowWindow, hWnd, SW_SHOWNORMAL
	Invoke UpdateWindow, hWnd
	.WHILE (TRUE)
		Invoke GetMessage, addr msg, NULL, 0, 0
		.BREAK .IF (!rax)		
		
        Invoke IsDialogMessage, hWnd, addr msg
        .IF rax == 0
            Invoke TranslateMessage, addr msg
            Invoke DispatchMessage, addr msg
        .ENDIF
	.ENDW
	mov rax, msg.wParam
	ret	
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc FRAME USES RBX RCX hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
    
    mov eax, uMsg
	.IF eax == WM_INITDIALOG
		; Init Stuff Here

        mov hJSONFile, NULL
        mov hJSONTreeRoot, NULL
        
        Invoke InitGUI, hWin
        Invoke InitMenus, hWin
        Invoke InitJSONStatusbar, hWin
        Invoke InitJSONTreeview, hWin
        
        Invoke DragAcceptFiles, hWin, TRUE
        
        Invoke SetFocus, hTV

		
;		Invoke cJSON_Version
;		mov DbgVar, rax
;		PrintStringByAddr DbgVar
;		
;		
;		Invoke cJSON_Parse, Addr szSomeJSON
;		mov root, rax
;		PrintDec root
;        Invoke cJSON_GetObjectItemCaseSensitive, root, Addr szFormat ; CTEXT("format")
;        mov format, rax
;        PrintDec format
;        Invoke cJSON_GetObjectItemCaseSensitive, format, Addr szFrameRate ;CTEXT("frame rate")
;        mov framerate_item, rax
;        PrintDec framerate_item
;        mov rbx, framerate_item
;        mov eax, [rbx].cJSON.valueint
;        mov framerate, rax
;        PrintDec framerate
;				
		
		
	.ELSEIF eax == WM_COMMAND
        mov rax, wParam
		.IF rax == IDM_FILE_EXIT
			Invoke SendMessage, hWin, WM_CLOSE, 0, 0

        .ELSEIF rax == IDM_FILE_OPEN
            Invoke BrowseJSONFile, hWin
            .IF rax == TRUE
                Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
                .IF rax == TRUE
                    ; Start processing JSON file
                    Invoke ProcessJSONFile, hWin, Addr JsonBrowseFilename
                    ;Invoke Tester, hWin, Addr JsonBrowseFilename
                .ENDIF
            .ENDIF
          
        .ELSEIF rax == IDM_FILE_CLOSE
            Invoke CloseJSONFile
			
		.ELSEIF rax == IDM_HELP_ABOUT
			Invoke ShellAbout, hWin, Addr AppName, Addr AboutMsg, NULL
			
		.ENDIF

    .ELSEIF eax == WM_DROPFILES
        mov rax, wParam
        mov hDrop, rax
        
        Invoke DragQueryFile, hDrop, 0, Addr JsonBrowseFilename, SIZEOF JsonBrowseFilename
        .IF rax != 0
            Invoke OpenJSONFile, hWin, Addr JsonBrowseFilename
            .IF rax == TRUE
                ; Start processing JSON file
                Invoke ProcessJSONFile, hWin, Addr JsonBrowseFilename
            .ENDIF
        .ENDIF
        mov rax, 0
        ret

    .ELSEIF eax == WM_WINDOWPOSCHANGED
        mov rbx, lParam
        mov eax, (WINDOWPOS ptr [rbx]).flags
        and eax, SWP_SHOWWINDOW
        .IF eax == SWP_SHOWWINDOW && g_fShown == FALSE
            mov g_fShown, TRUE
            Invoke PostMessage, hWin, WM_APP, 0, 0
        .ENDIF
        Invoke DefWindowProc, hWin, uMsg, wParam, lParam
        xor rax, rax
        ret
        
    .ELSEIF eax == WM_APP
        .IF CmdLineProcessFileFlag == 1
            Invoke CmdLineOpenFile, hWin
        .ENDIF
        Invoke DefWindowProc, hWin, uMsg, wParam, lParam
        ret   

    .ELSEIF eax == WM_CTLCOLORDLG
        mov rax, hWhiteBrush
        ret

    .ELSEIF eax == WM_SIZE
        Invoke SendMessage, hSB, WM_SIZE, 0, 0
        mov rax, lParam
        and rax, 0FFFFh
        mov dqClientWidth, rax
        mov rax, lParam
        shr rax, 16d
        sub rax, 23d ; take away statusbar height
        mov dqClientHeight, rax        
        Invoke SetWindowPos, hTV, HWND_TOP, 0,0, dqClientWidth, dqClientHeight, SWP_NOZORDER

	.ELSEIF eax==WM_NOTIFY
		mov rcx,lParam
		mov eax, (NMHDR PTR [rcx]).code
		
		.IF eax == NM_RCLICK

		.ELSEIF eax == NM_DBLCLK
		    Invoke TreeViewGetSelectedItem, hTV
		    Invoke SendMessage, hTV, TVM_EDITLABEL, 0, rax
		
		.ELSEIF eax == NM_RETURN ; requires sublass of treeview with WM_GETDLGCODE DLGC_WANTALL
	        Invoke TreeViewGetSelectedItem, hTV
	        Invoke SendMessage, hTV, TVM_EDITLABEL, 0, rax
		
		.ELSEIF eax == TVN_KEYDOWN
		    mov rcx, lParam
		    movzx rax, (TV_KEYDOWN ptr [rcx]).wVKey
		    .IF eax == VK_F2 
		        Invoke TreeViewGetSelectedItem, hTV
		        Invoke SendMessage, hTV, TVM_EDITLABEL, 0, rax
		    .ENDIF
		     
	    .ELSEIF eax == TVN_BEGINLABELEDIT
            mov rax, FALSE
            ret
            
	    .ELSEIF eax == TVN_ENDLABELEDIT
	        mov rax, TRUE
	        ret
	        
	    .ENDIF

	.ELSEIF eax == WM_CLOSE
		Invoke DestroyWindow, hWin
		
	.ELSEIF eax == WM_DESTROY
		Invoke PostQuitMessage, NULL
		
	.ELSE
		invoke DefWindowProc, hWin, uMsg, wParam, lParam ; rcx, edx, r8, r9
		ret
	.ENDIF
	xor rax, rax
	ret
WndProc endp


;-------------------------------------------------------------------------------------
; ProcessCmdLine - has user passed a file at the command line 
;-------------------------------------------------------------------------------------
ProcessCmdLine PROC FRAME
	Invoke getcl_ex, 1, Addr CmdLineFilename
	.IF rax == 1
        mov CmdLineProcessFileFlag, 1 ; filename specified, attempt to open it
    .ELSE
        mov CmdLineProcessFileFlag, 0 ; do nothing, continue as normal
    .ENDIF
    ret
ProcessCmdLine endp


;------------------------------------------------------------------------------
; Opens a file from the command line or shell explorer call
;------------------------------------------------------------------------------
CmdLineOpenFile PROC FRAME hWin:QWORD

    Invoke InString, 1, Addr CmdLineFilename, Addr szBackslash
    .IF rax == 0
        Invoke GetCurrentDirectory, MAX_PATH, Addr CmdLineFullPathFilename
        Invoke szCatStr, Addr CmdLineFullPathFilename, Addr szBackslash
        Invoke szCatStr, Addr CmdLineFullPathFilename, Addr CmdLineFilename
    .ELSE
        Invoke szCopy, Addr CmdLineFilename, Addr CmdLineFullPathFilename
    .ENDIF
    
    Invoke exist, Addr CmdLineFullPathFilename
    .IF rax == 0 ; does not exist
        Invoke szCopy, Addr szCmdLineFilenameDoesNotExist, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, Addr CmdLineFullPathFilename
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
        ret
    .ENDIF

    Invoke OpenJSONFile, hWin, Addr CmdLineFullPathFilename
    .IF rax == TRUE
        ; Start processing JSON file
        Invoke ProcessJSONFile, hWin, Addr CmdLineFullPathFilename
    .ENDIF

    ret
CmdLineOpenFile endp


;-------------------------------------------------------------------------------------
; InitGUI - Initialize GUI stuff
;-------------------------------------------------------------------------------------
InitGUI PROC FRAME hWin:QWORD

    Invoke CreateSolidBrush, 0FFFFFFh
    mov hWhiteBrush, rax
    
    Invoke GetDlgItem, hWin, IDC_TV
    mov hTV, rax
    
    Invoke GetDlgItem, hWin, IDC_SB
    mov hSB, rax
    
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
    mov hIL, rax
    
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
InitMenus PROC FRAME hWin:QWORD
    
    ; Create right click treeview menu
    ;Invoke CreatePopupMenu
    ;mov hTVMenu, eax
    
    
    ret

InitMenus ENDP


;-------------------------------------------------------------------------------------
; InitJSONTreeview - Initialize JSON Treeview
;-------------------------------------------------------------------------------------
InitJSONTreeview PROC FRAME hWin:QWORD

    Invoke SendMessage, hTV, TVM_SETEXTENDEDSTYLE, TVS_EX_DOUBLEBUFFER, TVS_EX_DOUBLEBUFFER
    Invoke TreeViewLinkImageList, hTV, hIL, TVSIL_NORMAL
    
    ret

InitJSONTreeview ENDP


;-------------------------------------------------------------------------------------
; InitJSONStatusbar - Initialize JSON Statusbar
;-------------------------------------------------------------------------------------
InitJSONStatusbar PROC FRAME hWin:QWORD
    LOCAL sbParts[8]:DWORD

    mov [sbParts +  0], 70      ; Panel 1 Size
    mov [sbParts +  4], -1      ; Panel 2 Size to rest of dialog with -1

    Invoke SendMessage, hSB, SB_SETPARTS, 2, Addr sbParts ; Set amount of parts

    Invoke SendMessage, hSB, SB_SETTEXT, 0, CTEXT(" Info: ") 
    Invoke SendMessage, hSB, SB_SETTEXT, 1, CTEXT("  ")         
    
    ret

InitJSONStatusbar ENDP


;-------------------------------------------------------------------------------------
; BrowseJSONFile - Browse for JSON file to open
;-------------------------------------------------------------------------------------
BrowseJSONFile PROC FRAME hWin:QWORD
    
    ; Browse for JSON file to open
    Invoke RtlZeroMemory, Addr JsonBrowseFilename, SIZEOF JsonBrowseFilename
    push hWin
    pop BrowseFile.hwndOwner
    lea rax, JsonBrowseFilter
    mov BrowseFile.lpstrFilter, rax
    lea rax, JsonBrowseFilename
    mov BrowseFile.lpstrFile, rax
    lea rax, JsonBrowseFileTitle
    mov BrowseFile.lpstrTitle, rax
    mov BrowseFile.nMaxFile, SIZEOF JsonBrowseFilename
    mov BrowseFile.lpstrDefExt, 0
    mov BrowseFile.Flags, OFN_EXPLORER
    mov BrowseFile.lStructSize, SIZEOF BrowseFile
    Invoke GetOpenFileName, Addr BrowseFile

    ; If user selected an JSON and didnt cancel browse operation...
    .IF rax !=0
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret

BrowseJSONFile ENDP


;-------------------------------------------------------------------------------------
; OpenJSONFile - Open JSON file to process
;-------------------------------------------------------------------------------------
OpenJSONFile PROC FRAME hWin:QWORD, lpszJSONFile:QWORD
    
    .IF hJSONFile != NULL
        Invoke CloseJSONFile
    .ENDIF
    
    Invoke SendMessage, hSB, SB_SETTEXT, 1, lpszJSONFile
    
    Invoke CreateFile, lpszJSONFile, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
    .IF rax == INVALID_HANDLE_VALUE
        ; Tell user via statusbar that JSON file did not load
        Invoke szCopy, Addr szJSONErrorLoadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        mov rax, FALSE
        ret
    .ENDIF
    mov hJSONFile, rax

    Invoke CreateFileMapping, hJSONFile, NULL, PAGE_READWRITE, 0, 0, NULL ; Create memory mapped file
    .IF rax == NULL
        ; Tell user via statusbar that JSON file did not map
        Invoke szCopy, Addr szJSONErrorMappingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        Invoke CloseHandle, hJSONFile
        mov rax, FALSE
        ret
    .ENDIF
    mov JSONMemMapHandle, rax

    Invoke MapViewOfFileEx, JSONMemMapHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0, NULL
    .IF rax == NULL
        ; Tell user via statusbar that JSON file did not map
        Invoke szCopy, Addr szJSONErrorMappingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        Invoke CloseHandle, JSONMemMapHandle
        Invoke CloseHandle, hJSONFile
        mov rax, FALSE
        ret
    .ENDIF
    mov JSONMemMapPtr, rax  

    mov rax, TRUE
    
    ret

OpenJSONFile ENDP


;-------------------------------------------------------------------------------------
; CloseJSONFile - Closes JSON file and deletes any treeview data and json data
;-------------------------------------------------------------------------------------
CloseJSONFile PROC FRAME

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
; Uses VirtualStack library as push pop can be corrupted by calling leaf functions
;-------------------------------------------------------------------------------------
ProcessJSONFile PROC FRAME USES RBX hWin:QWORD, lpszJSONFile:QWORD
    LOCAL nTVIndex:QWORD
    LOCAL next:QWORD
    LOCAL prev:QWORD
    LOCAL child:QWORD
    LOCAL jsontype:QWORD
    LOCAL itemcount:QWORD
    LOCAL currentitem:QWORD
    LOCAL level:QWORD
    LOCAL dwArrayCount:DWORD
    LOCAL dwItemValue:DWORD
    LOCAL hJSON:QWORD
    ; JSONMemMapPtr is pointer to file in memory, mapped previously in OpenJSONFile
    ; Parse this with cJSON library cJSON_Parse function, returns root handle to JSON stuff

    Invoke cJSON_Parse, JSONMemMapPtr
    mov hJSON_Object_Root, rax

    .IF hJSON_Object_Root == NULL
        ; If empty then tell user some error about reading file
        Invoke szCopy, Addr szJSONErrorReadingFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        xor eax, eax ; FALSE
        ret        
    .ENDIF

    ; Treeview Root is created, save handle to it, specifically we will need hTVNode later for when inserting children to treeview
    mov nTVIndex, 0
    Invoke TreeViewInsertItem, hTV, NULL, lpszJSONFile, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, 0
    mov hTVRoot, rax
    mov hTVNode, rax
    mov hTVCurrentNode, rax
    inc nTVIndex
    
    ; Each time we insert a treeview item we need to increment our nTVIndex counter

    ; Just a check to make sure JSON has some stuff to process
    Invoke cJSON_GetArraySize, hJSON_Object_Root
    .IF rax == 0
        Invoke szCopy, Addr szJSONErrorEmptyFile, Addr szJSONErrorMessage
        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage
        xor eax, eax ; FALSE
        ret
    .ENDIF

    mov level, -1000d ; hack to force our while loop below, only used for possibly debugging/tracking indented levels (children)
    mov rax, hJSON_Object_Root 
    mov hJSON, rax ; use hJSON as variable to process in our loop

    Invoke VirtualStackCreate, VIRTUALSTACK_SIZE_MEDIUM
    .IF rax == NULL
        ;PrintText 'VirtualStackCreate failed'
        xor eax, eax ; FALSE
        ret
    .ENDIF
    mov hVirtualStack, rax

    ;PrintQWORD hJSON_Object_Root
    ;PrintQWORD hJSON

    .WHILE sqword ptr level != 0
        
        .IF sqword ptr level == -1000d
            mov level, 1 ; set our level to 1, useful for debugging and checking we havnt push/popd too much
            ; push hJSON, then hTVNode. NOTE: we must pop these in reverse order to retrieve them when we fall back up the tree
            Invoke VirtualStackPush, hVirtualStack, hJSON
            Invoke VirtualStackPush, hVirtualStack, hTVNode
            
        .ENDIF
        ;PrintQWORD level
        ;PrintText 'fetching values for cJSON object'
        mov rbx, hJSON ; get our cJSON object (first time in loop is the hJSON_Object_Root, subsequent times it will be the next or child item
        ; Fetch some values for our cJSON object
        mov rax, [rbx].cJSON.itemtype
        mov jsontype, rax
        mov rax, [rbx].cJSON.child
        mov child, rax
        mov rax, [rbx].cJSON.next
        mov next, rax
        mov rax, [rbx].cJSON.prev
        mov prev, rax
        mov rax, [rbx].cJSON.itemstring
        mov lpszItemString, rax
        mov rax, [rbx].cJSON.valuestring
        mov lpszItemStringValue, rax  
        mov rax, [rbx].cJSON.valueint
        mov dqItemIntValue, rax
        
        IFDEF DEBUG64
            ;PrintQWORD hJSON
            ;PrintQWORD jsontype
            ;PrintQWORD child
            ;PrintQWORD next
            ;PrintQWORD prev
            ;PrintQWORD lpszItemString
            ;PrintQWORD lpszItemStringValue
            ;PrintQWORD dqItemIntValue
            ;PrintStringByAddr lpszItemString
            ;PrintStringByAddr lpszItemStringValue
        ENDIF
        
        ; Check strings are present and > 0 in length (to stop crashes when copying etc)
        .IF lpszItemString == 0
            mov LenItemString, 0
        .ELSE
            Invoke szLen, lpszItemString
            mov LenItemString, rax
        .ENDIF
        
        .IF lpszItemStringValue == 0
            mov LenItemStringValue, 0
        .ELSE
            Invoke szLen, lpszItemStringValue
            mov LenItemStringValue, rax
        .ENDIF        
        
        ; Determine the type of cJSON object, so we can decide what to do with it
        mov rax, jsontype
        .IF rax == cJSON_Object
            .IF LenItemString == 0
                Invoke TreeViewInsertItem, hTV, hTVNode, Addr szObject, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                mov hTVCurrentNode, rax
                inc nTVIndex
            .ELSE
                ; lstrcat
                Invoke szCopy, lpszItemString, Addr szItemText
                Invoke szCatStr, Addr szItemText, Addr szColon
                .IF LenItemStringValue != 0
                    Invoke szCatStr, Addr szItemText, Addr szSpace
                    Invoke szCatStr, Addr szItemText, lpszItemStringValue
                .ENDIF
                ;PrintText 'cJSON_Object'
                ;PrintString szItemText
                Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_OBJECT, IL_ICO_JSON_OBJECT, hJSON
                mov hTVCurrentNode, rax
                inc nTVIndex
            .ENDIF

        .ELSEIF rax == cJSON_String
            .IF LenItemString == 0
                .IF LenItemStringValue != 0
                    Invoke szCopy, lpszItemStringValue, Addr szItemText
                .ENDIF                
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
                Invoke szCatStr, Addr szItemText, Addr szColon
                .IF LenItemStringValue != 0
                    Invoke szCatStr, Addr szItemText, Addr szSpace
                    Invoke szCatStr, Addr szItemText, lpszItemStringValue
                .ENDIF
            .ENDIF
            ;PrintText 'cJSON_String'
            ;PrintString szItemText
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_STRING, IL_ICO_JSON_STRING, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_Number
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullInteger, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            ;mov rax, dqItemIntValue
            ;mov dwItemValue, eax
            Invoke qwtoa, dqItemIntValue, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szItemIntValue
            ;PrintText 'cJSON_Number'
            ;PrintString szItemText
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_INTEGER, IL_ICO_JSON_INTEGER, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_True
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szTrue
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
                        
        .ELSEIF rax == cJSON_False
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullLogical, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szFalse
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_LOGICAL, IL_ICO_JSON_LOGICAL, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_Array
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullArray, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szArray
            Invoke cJSON_GetArraySize, hJSON
            mov dwArrayCount, eax
            Invoke dwtoa, dwArrayCount, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szLeftBracket
            Invoke szCatStr, Addr szItemText, Addr szItemIntValue
            Invoke szCatStr, Addr szItemText, Addr szRightBracket
            ;PrintText 'cJSON_Array'
            ;PrintString szItemText
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_ARRAY, IL_ICO_JSON_ARRAY, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_NULL
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullNull, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szNull
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_NULL, IL_ICO_JSON_NULL, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_Invalid
            .IF LenItemString == 0
                Invoke szCopy, Addr szNullInvalid, Addr szItemText
            .ELSE
                Invoke szCopy, lpszItemString, Addr szItemText
            .ENDIF
            Invoke szCatStr, Addr szItemText, Addr szColon
            Invoke szCatStr, Addr szItemText, Addr szSpace
            Invoke szCatStr, Addr szItemText, Addr szInvalid
            Invoke TreeViewInsertItem, hTV, hTVNode, Addr szItemText, nTVIndex, TVI_LAST, IL_ICO_JSON_INVALID, IL_ICO_JSON_INVALID, hJSON
            mov hTVCurrentNode, rax
            inc nTVIndex
            
        .ELSEIF rax == cJSON_Raw

        .ENDIF
        
        ; we have inserted a treeview item, now we check what the next cJSON item is and how to handle it
        ; get child if there is one, otherwise sibling if there is one
        .IF child != 0
            inc level ; we are moving up a level, so increment level
            Invoke VirtualStackPush, hVirtualStack, hJSON
            Invoke VirtualStackPush, hVirtualStack, hTVNode
            mov rax, child ; set child cJSON object as the cJSON object to process in our loop
            mov hJSON, rax
            mov rax, hTVCurrentNode ; set currently inserted treeview item as hTVNode, so next one will be inserted as a child of this one.
            mov hTVNode, rax
            
        .ELSE ; No child cJSON object, so look for siblings
            .IF next != 0 ; we have a sibling
                mov rax, next ; set next cJSON object as the cJSON object to process in our loop
                mov hJSON, rax
            .ELSE ; No child or siblings, so must be at the last sibling, so here is the fun stuff
                Invoke VirtualStackPop, hVirtualStack, Addr dqVirtualStackValue
                .IF rax == FALSE
                    ;PrintText 'VirtualStackPop failed'
                .ELSEIF rax == -1
                    ;PrintText 'VirtualStackPop EndOfStack'
                .ELSE
                    mov rax, dqVirtualStackValue
                    mov hTVNode, rax
                .ENDIF                
                Invoke VirtualStackPop, hVirtualStack, Addr dqVirtualStackValue
                .IF rax == FALSE
                    ;PrintText 'VirtualStackPop failed'
                .ELSEIF rax == -1
                    ;PrintText 'VirtualStackPop EndOfStack'
                .ELSE
                    mov rax, dqVirtualStackValue
                    mov hJSON, rax
                .ENDIF    
                ;pop hTVNode before hJSON (reverse of what we pushed previously)
                ;we now have the last levels cJSON object and the parent of the last inserted treeview item

                dec level ; we are moving down a level, so decrement level
                mov rbx, hJSON ; fetch the next cJSON object of the cJSON object we just restored with the pop hJSON 
                mov rax, [rbx].cJSON.next
                .WHILE rax == 0 && sqword ptr level > 0 ; if next is 0 and we are still a level greater than 1 we loop, restoring previous cJSON objects and hTVNodes
                    Invoke VirtualStackPop, hVirtualStack, Addr dqVirtualStackValue
                    .IF rax == FALSE
                        ;PrintText 'VirtualStackPop failed'
                    .ELSEIF rax == -1
                        ;PrintText 'VirtualStackPop EndOfStack'
                    .ELSE
                        mov rax, dqVirtualStackValue
                        mov hTVNode, rax
                    .ENDIF                
                    Invoke VirtualStackPop, hVirtualStack, Addr dqVirtualStackValue
                    .IF rax == FALSE
                        ;PrintText 'VirtualStackPop failed'
                    .ELSEIF rax == -1
                        ;PrintText 'VirtualStackPop EndOfStack'
                    .ELSE
                        mov rax, dqVirtualStackValue
                        mov hJSON, rax
                    .ENDIF                       

                    dec level
                    mov rbx, hJSON
                    mov rax, [rbx].cJSON.next
                .ENDW
                ; we are now are level 1 (start) so the cJSON objects next object is either a value we can use in our loop or it is 0
                
                .IF rax == 0 ; no more left so exit as we are done
                    .BREAK
                .ELSE
                    mov hJSON, rax ; else we did find a new cJSON object which we can start the whole major loop process with again 
                .ENDIF
            .ENDIF

        .ENDIF
    
        Invoke TreeViewChildItemsExpand, hTV, hTVCurrentNode
        Invoke TreeViewChildItemsExpand, hTV, hTVNode
        
    .ENDW
    
    Invoke TreeViewChildItemsExpand, hTV, hTVRoot
    
    ; we have finished processing the cJSON objects, following children then following siblings, then moving back up the list/level, getting next object and 
    ; repeating till no more objects where left to process and all treeview items have been inserted at the correct 'level' indentation or whatever.
    
    Invoke cJSON_free, hJSON_Object_Root ; Clear up the mem alloced by cJSON_Parse

    ; Tell user via statusbar that JSON file was successfully loaded
    Invoke szCopy, Addr szJSONLoadedFile, Addr szJSONErrorMessage
    Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage     
    
    Invoke SetFocus, hTV
    
    mov rax, TRUE
    
    ret
ProcessJSONFile ENDP



;-------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------
;Tester PROC FRAME USES RBX hWin:QWORD, lpszJSONFile:QWORD
;    LOCAL nTVIndex:QWORD
;    LOCAL itemcount:QWORD
;    LOCAL currentitem:QWORD
;    ;LOCAL level:QWORD
;    LOCAL dwArrayCount:DWORD
;    ;LOCAL hJSON:QWORD
;    
;    Invoke cJSON_Parse, JSONMemMapPtr
;    mov hJSON_Object_Root, rax
;
;    .IF hJSON_Object_Root == NULL
;        ; If empty then tell user some error about reading file
;        Invoke szCopy, Addr szJSONErrorReadingFile, Addr szJSONErrorMessage
;        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
;        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
;        ret        
;    .ENDIF
;
;    ; Treeview Root is created, save handle to it, specifically we will need hTVNode later for when inserting children to treeview
;    mov nTVIndex, 0
;    Invoke TreeViewInsertItem, hTV, NULL, lpszJSONFile, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, 0
;    mov hTVRoot, rax
;    mov hTVNode, rax
;    mov hTVCurrentNode, rax
;    inc nTVIndex
;    
;    ; Each time we insert a treeview item we need to increment our nTVIndex counter
;
;    ; Just a check to make sure JSON has some stuff to process
;    Invoke cJSON_GetArraySize, hJSON_Object_Root
;    .IF rax == 0
;        Invoke szCopy, Addr szJSONErrorEmptyFile, Addr szJSONErrorMessage
;        Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
;        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage    
;        ret
;    .ENDIF
;
;    mov level, -1000d ; hack to force our while loop below, only used for possibly debugging/tracking indented levels (children)
;    mov rax, hJSON_Object_Root 
;    mov hJSON, rax ; use hJSON as variable to process in our loop
;
;    ; ------------------------------------------------------------------------------------
;        
;        PrintQWORD hJSON_Object_Root
;        PrintQWORD hJSON
;        
;        mov rbx, hJSON ; get our cJSON object (first time in loop is the hJSON_Object_Root, subsequent times it will be the next or child item
;        ; Fetch some values for our cJSON object
;        mov rax, [rbx].cJSON.itemtype
;        mov jsontype, rax
;        mov rax, [rbx].cJSON.child
;        mov child, rax
;        mov rax, [rbx].cJSON.next
;        mov next, rax
;        mov rax, [rbx].cJSON.prev
;        mov prev, rax
;        mov rax, [rbx].cJSON.itemstring
;        mov lpszItemString, rax
;        mov rax, [rbx].cJSON.valuestring
;        mov lpszItemStringValue, rax  
;        xor rax, rax
;        mov rax, [rbx].cJSON.valueint
;        mov dqItemIntValue, rax
;
;    PrintQWORD jsontype
;    PrintQWORD child
;    PrintQWORD next
;    PrintQWORD prev
;    PrintQWORD lpszItemString
;    PrintQWORD lpszItemStringValue
;    PrintQWORD dqItemIntValue
;    
;
;    ; ------------------------------------------------------------------------------------
;
;
;
;
;    Invoke TreeViewChildItemsExpand, hTV, hTVRoot
;
;    ; we have finished processing the cJSON objects, following children then following siblings, then moving back up the list/level, getting next object and 
;    ; repeating till no more objects where left to process and all treeview items have been inserted at the correct 'level' indentation or whatever.
;    
;    Invoke cJSON_free, hJSON_Object_Root ; Clear up the mem alloced by cJSON_Parse
;
;    ; Tell user via statusbar that JSON file was successfully loaded
;    Invoke szCopy, Addr szJSONLoadedFile, Addr szJSONErrorMessage
;    Invoke szCatStr, Addr szJSONErrorMessage, lpszJSONFile
;    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szJSONErrorMessage     
;    
;    Invoke SetFocus, hTV
;    
;    mov rax, TRUE
;
;    ret
;Tester ENDP



end WinMainCRTStartup
