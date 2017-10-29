
.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib \Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'\Masm32\DbgWin.exe'>
    include \Masm32\include\debug32.inc
ENDIF

include mxmltree.inc

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
	
	Invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
	Invoke ExitProcess, eax

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL	wc:WNDCLASSEX
	LOCAL	msg:MSG

	mov		wc.cbSize, sizeof WNDCLASSEX
	mov		wc.style, CS_HREDRAW or CS_VREDRAW
	mov		wc.lpfnWndProc, offset WndProc
	mov		wc.cbClsExtra, NULL
	mov		wc.cbWndExtra, DLGWINDOWEXTRA
	push	hInst
	pop		wc.hInstance
	mov		wc.hbrBackground, COLOR_WINDOW+1
	mov		wc.lpszMenuName, IDM_MENU
	mov		wc.lpszClassName, offset ClassName
	Invoke LoadIcon, hInstance, ICO_MAIN ; resource icon for main application icon
	mov		wc.hIcon, eax
	mov		wc.hIconSm, eax
	Invoke LoadCursor, NULL, IDC_ARROW
	mov		wc.hCursor,eax
	Invoke RegisterClassEx, addr wc
	Invoke CreateDialogParam, hInstance, IDD_DIALOG, NULL, addr WndProc, NULL
	Invoke ShowWindow, hWnd, SW_SHOWNORMAL
	Invoke UpdateWindow, hWnd
	.WHILE TRUE
		invoke GetMessage, addr msg, NULL, 0, 0
	  .BREAK .if !eax
		Invoke TranslateMessage, addr msg
		Invoke DispatchMessage, addr msg
	.ENDW
	mov eax, msg.wParam
	ret
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
	
	mov eax, uMsg
	.IF eax == WM_INITDIALOG
		push hWin
		pop hWnd
        
        mov hXMLFile, NULL
        mov hMXMLTreeRoot, NULL
        
		Invoke InitGUI, hWin
		Invoke InitXMLStatusbar, hWin
		Invoke InitXMLTreeview, hWin

	.ELSEIF eax == WM_COMMAND
		mov eax, wParam
		and eax, 0FFFFh
		.IF eax == IDM_FILE_EXIT
			Invoke SendMessage, hWin, WM_CLOSE, 0, 0
		
		.ELSEIF eax == IDM_FILE_OPEN
		    Invoke OpenXMLFile, hWin
		
		.ELSEIF eax == IDM_HELP_ABOUT
			Invoke ShellAbout, hWin, Addr AppName, Addr AboutMsg, NULL
			
		.ENDIF

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

	.ELSEIF eax == WM_CLOSE
		Invoke DestroyWindow, hWin
		
	.ELSEIF eax == WM_DESTROY
		Invoke PostQuitMessage, NULL
		
	.ELSE
		Invoke DefWindowProc, hWin, uMsg, wParam, lParam
		ret
	.ENDIF
	xor    eax,eax
	ret
WndProc endp


;-------------------------------------------------------------------------------------
; InitGUI - Initialize GUI stuff
;-------------------------------------------------------------------------------------
InitGUI PROC hWin:DWORD

    Invoke CreateSolidBrush, 0FFFFFFh
    mov hWhiteBrush, eax
    
    Invoke GetDlgItem, hWin, IDC_TV
    mov hTV, eax
    
;### SEE - TODO1: ###
    Invoke GetDlgItem, hWin, IDC_SB
    mov hSB, eax
    
    Invoke LoadIcon, hInstance, ICO_MAIN
    mov hICO_MAIN, eax
    
    Invoke LoadIcon, hInstance, ICO_XML_ELEMENT
    mov hICO_XML_ELEMENT, eax
    
    Invoke LoadIcon, hInstance, ICO_XML_ATTRIBUTE
    mov hICO_XML_ATTRIBUTE, eax
    
    Invoke LoadIcon, hInstance, ICO_XML_STRING
    mov hICO_XML_STRING, eax
    
    Invoke LoadIcon, hInstance, ICO_XML_INTEGER
    mov hICO_XML_INTEGER, eax
    
    Invoke LoadIcon, hInstance, ICO_XML_FLOAT
    mov hICO_XML_FLOAT, eax

    Invoke LoadIcon, hInstance, ICO_XML_CUSTOM
    mov hICO_XML_CUSTOM, eax
    
    Invoke ImageList_Create, 16, 16, ILC_COLOR32, 8, 16
    mov hIL, eax
    
    Invoke ImageList_AddIcon, hIL, hICO_MAIN
    Invoke ImageList_AddIcon, hIL, hICO_XML_ELEMENT
    Invoke ImageList_AddIcon, hIL, hICO_XML_ATTRIBUTE
    Invoke ImageList_AddIcon, hIL, hICO_XML_STRING
    Invoke ImageList_AddIcon, hIL, hICO_XML_INTEGER
    Invoke ImageList_AddIcon, hIL, hICO_XML_FLOAT
    Invoke ImageList_AddIcon, hIL, hICO_XML_CUSTOM
    
    
    ret

InitGUI ENDP


;-------------------------------------------------------------------------------------
; InitXMLTreeview - Initialize XML Treeview
;-------------------------------------------------------------------------------------
InitXMLTreeview PROC hWin:DWORD

    Invoke SendMessage, hTV, TVM_SETEXTENDEDSTYLE, TVS_EX_DOUBLEBUFFER, TVS_EX_DOUBLEBUFFER
    Invoke TreeViewLinkImageList, hTV, hIL, TVSIL_NORMAL
    
    ret

InitXMLTreeview ENDP


;-------------------------------------------------------------------------------------
; InitXMLStatusbar - Initialize XML Statusbar
;-------------------------------------------------------------------------------------
InitXMLStatusbar PROC hWin:DWORD
    LOCAL sbParts[8]:DWORD

	mov [sbParts +  0], 70		; Panel 1 Size
	mov [sbParts +  4], -1		; Panel 2 Size to rest of dialog with -1

    Invoke SendMessage, hSB, SB_SETPARTS, 2, ADDR sbParts ; Set amount of parts

	Invoke SendMessage, hSB, SB_SETTEXT, 0, CTEXT(" Info: ") 
	Invoke SendMessage, hSB, SB_SETTEXT, 1, CTEXT("  ") 	    
    
    ret

InitXMLStatusbar ENDP


;-------------------------------------------------------------------------------------
; OpenXMLFile - Open XML file to process
;-------------------------------------------------------------------------------------
OpenXMLFile PROC hWin:DWORD

    ; Browse for xml file to open
	Invoke RtlZeroMemory, Addr XmlBrowseFilename, SIZEOF XmlBrowseFilename
	push hWin
    pop BrowseFile.hwndOwner
	mov BrowseFile.lpstrFilter, Offset XmlBrowseFilter
	mov BrowseFile.lpstrFile, Offset XmlBrowseFilename
	mov BrowseFile.lpstrTitle, Offset XmlBrowseFileTitle
	mov BrowseFile.nMaxFile, SIZEOF XmlBrowseFilename
	mov BrowseFile.lpstrDefExt, 0
	mov BrowseFile.Flags, OFN_EXPLORER
	mov BrowseFile.lStructSize, SIZEOF BrowseFile
	Invoke GetOpenFileName, Addr BrowseFile

    ; If user selected an xml and didnt cancel browse operation...
	.IF eax !=0
	
        .IF hXMLFile != NULL
            Invoke CloseXMLFile
        .ENDIF
    	
	    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLLoadingFile
	    ;PrintString XmlBrowseFilename
	    
	    Invoke CreateFile, Addr XmlBrowseFilename, GENERIC_READ + GENERIC_WRITE, FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL
	    .IF eax == INVALID_HANDLE_VALUE
	        ; Tell user via statusbar that xml file did not load
	        Invoke szCopy, Addr szXMLErrorLoadingFile, Addr szXMLErrorMessage
	        Invoke szCatStr, Addr szXMLErrorMessage, Addr XmlBrowseFilename
	        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLErrorMessage
	        ret
	    .ENDIF
	    mov hXMLFile, eax

        Invoke CreateFileMapping, hXMLFile, NULL, PAGE_READWRITE, 0, 0, NULL ; Create memory mapped file
        .IF eax == NULL
	        ; Tell user via statusbar that xml file did not map
	        Invoke szCopy, Addr szXMLErrorMappingFile, Addr szXMLErrorMessage
	        Invoke szCatStr, Addr szXMLErrorMessage, Addr XmlBrowseFilename
	        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLErrorMessage
	        Invoke CloseHandle, hXMLFile
	        ret
        .ENDIF
        mov XMLMemMapHandle, eax

        Invoke MapViewOfFileEx, XMLMemMapHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0, NULL
        .IF eax == NULL
	        ; Tell user via statusbar that xml file did not map
	        Invoke szCopy, Addr szXMLErrorMappingFile, Addr szXMLErrorMessage
	        Invoke szCatStr, Addr szXMLErrorMessage, Addr XmlBrowseFilename
	        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLErrorMessage
	        Invoke CloseHandle, XMLMemMapHandle
	        Invoke CloseHandle, hXMLFile
	        ret
        .ENDIF
        mov XMLMemMapPtr, eax	
	    
	    ; Tell user via statusbar that xml file was successfully loaded
        Invoke szCopy, Addr szXMLLoadedFile, Addr szXMLErrorMessage
        Invoke szCatStr, Addr szXMLErrorMessage, Addr XmlBrowseFilename
        Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLErrorMessage	    
	    
	    ; Start processing xml file
	    Invoke ProcessXMLFile, hWin, Addr XmlBrowseFilename
	.ENDIF

    ret

OpenXMLFile ENDP


;-------------------------------------------------------------------------------------
; ProcessXMLFile - Process XML file and load data into treeview
;-------------------------------------------------------------------------------------
ProcessXMLFile PROC USES EBX hWin:DWORD, lpszXMLFile:DWORD
    LOCAL nNumberOfAttributes:DWORD
    LOCAL nAttribute:DWORD
    LOCAL ptrAttributesArray:DWORD
    LOCAL nTVIndex:DWORD
    LOCAL oTVNode:DWORD
    LOCAL FilePointer:DWORD

;    invoke crt_fopen ,chr$ ("test.xml"), chr$ ("r");
;	.if eax!=0
;		mov	FilePointer,eax
;		invoke	mxmlLoadFile,NULL,FilePointer,MXML_NO_CALLBACK
;	.endif

    Invoke mxmlLoadString, NULL, XMLMemMapPtr, MXML_NO_CALLBACK
    mov hMXMLTreeRoot, eax
    mov hMXMLTreeNode, eax
    
    IFDEF DEBUG32
    PrintDec hMXMLTreeRoot
    ENDIF
    
    .IF hMXMLTreeRoot == NULL
        ; error
	    Invoke szCopy, Addr szXMLErrorReadingFile, Addr szXMLErrorMessage
	    Invoke szCatStr, Addr szXMLErrorMessage, Addr XmlBrowseFilename
	    Invoke SendMessage, hSB, SB_SETTEXT, 1, Addr szXMLErrorMessage    
        ret
    .ENDIF
    
    
    ; Treeview Root
    mov nTVIndex, 0
    Invoke TreeViewInsertItem, hTV, NULL, Addr XmlBrowseFilename, nTVIndex, TVI_ROOT, IL_ICO_MAIN, IL_ICO_MAIN, 0
    mov hTVRoot, eax
    mov hTVNode, eax
    inc nTVIndex
    ;Invoke TreeViewChildItemsExpand, hTV, eax
    push hTVNode

    mov eax, hMXMLTreeNode
    .WHILE eax != NULL
        
        Invoke mxmlWalkNext, hMXMLTreeNode, NULL, MXML_DESCEND
        mov hMXMLTreeNode, eax

        Invoke mxmlGetType, hMXMLTreeNode
        .IF eax == MXML_ELEMENT
            IFDEF DEBUG32
            PrintText 'MXML_ELEMENT'
            ENDIF
            
            Invoke mxmlElementGetAttr, hMXMLTreeNode, Addr szAttributeName
            mov lpszAttribute, eax
            IFDEF DEBUG32
            ;PrintStringByAddr lpszAttribute
            ENDIF
            
            Invoke mxmlGetElement, hMXMLTreeNode
            mov lpszElement, eax
            IFDEF DEBUG32
            ;PrintStringByAddr lpszElement
            ENDIF
            

            Invoke mxmlGetParent, hMXMLTreeNode
            mov hMXMLParentNode, eax
            Invoke mxmlGetNextSibling, hMXMLTreeNode
            mov hMXMLNextNode, eax
            Invoke mxmlGetPrevSibling, hMXMLTreeNode
            mov hMXMLPrevNode, eax
            Invoke mxmlGetFirstChild, hMXMLTreeNode
            mov hMXMLFirstChildNode, eax
            Invoke mxmlGetLastChild, hMXMLTreeNode
            mov hMXMLLastChildNode, eax
    
;            IFDEF DEBUG32
;            PrintDec hMXMLParentNode
;            PrintDec hMXMLTreeNode
;            PrintDec hMXMLNextNode
;            PrintDec hMXMLPrevNode
;            PrintDec hMXMLFirstChildNode
;            PrintDec hMXMLLastChildNode
;            ENDIF
           
            Invoke TreeViewChildItemsExpand, hTV, hTVNode
            ; Treeview Element Node
            Invoke TreeViewInsertItem, hTV, hTVNode, lpszElement, nTVIndex, TVI_LAST, IL_ICO_XML_ELEMENT, IL_ICO_XML_ELEMENT, hMXMLTreeNode ;hTVRoot
            mov hTVNode, eax
            inc nTVIndex
            Invoke TreeViewChildItemsExpand, hTV, hTVNode
            
            ; Fetch element name from node object
            mov ebx, hMXMLTreeNode
            mov eax, [ebx].mxml_node_t.node_value.element.element_name
            mov lpszElementName, eax
            IFDEF DEBUG32
            PrintStringByAddr lpszElementName
            ENDIF
            
            ; Fetch no of attributes from node object
            mov ebx, hMXMLTreeNode
            mov eax, [ebx].mxml_node_t.node_value.element.num_attrs
            mov nNumberOfAttributes, eax
            mov eax, [ebx].mxml_node_t.node_value.element.attrs
            mov ptrAttributesArray, eax
            
            IFDEF DEBUG32
            ;PrintDec nNumberOfAttributes
            ENDIF
            
            ; loop through attributes and fetch name and value for each
            mov eax, 0
            mov nAttribute, 0
            .WHILE eax < nNumberOfAttributes
                mov ebx, ptrAttributesArray
                
                mov eax, [ebx].mxml_attr_t.attr_name
                mov lpszAttributeName, eax
                mov eax, [ebx].mxml_attr_t.attr_value
                mov lpszAttributeValue, eax
                
                IFDEF DEBUG32
                ;PrintStringByAddr lpszAttributeName
                ;PrintStringByAddr lpszAttributeValue
                ENDIF
                
                Invoke szCopy, lpszAttributeName, Addr szAttribNameValue
                Invoke szCatStr, Addr szAttribNameValue, Addr szAttribEquals
                Invoke szCatStr, Addr szAttribNameValue, lpszAttributeValue
                
                ; Treeview Attribute Node
                Invoke TreeViewInsertItem, hTV, hTVNode, Addr szAttribNameValue, nTVIndex, TVI_LAST, IL_ICO_XML_ATTRIBUTE, IL_ICO_XML_ATTRIBUTE, hMXMLTreeNode
                inc nTVIndex
                Invoke TreeViewChildItemsExpand, hTV, hTVNode
                
                ; update array to point to next attribute
                add ptrAttributesArray, SIZEOF mxml_attr_t
                inc nAttribute
                mov eax, nAttribute
            .ENDW
            Invoke TreeViewChildItemsExpand, hTV, hTVNode
            
            push hTVNode

            


        .ELSEIF eax == MXML_REAL
            IFDEF DEBUG32
            PrintText 'MXML_REAL'
            ENDIF
            pop hTVNode
        .ELSEIF eax == MXML_OPAQUE
            IFDEF DEBUG32
            PrintText 'MXML_OPAQUE'
            ENDIF
            pop hTVNode
        .ELSEIF eax == MXML_INTEGER
            IFDEF DEBUG32
            PrintText 'MXML_INTEGER'
            ENDIF
            pop hTVNode
        .ELSEIF eax == MXML_TEXT
            IFDEF DEBUG32
            PrintText 'MXML_TEXT'
            ENDIF
            
            Invoke mxmlGetText, hMXMLTreeNode, 0
            mov lpszText, eax
            
            .IF lpszText != NULL
                Invoke szLen, lpszText
                .IF eax != 0
                    Invoke TreeViewInsertItem, hTV, hTVNode, lpszText, nTVIndex, TVI_LAST, IL_ICO_XML_STRING, IL_ICO_XML_STRING, hMXMLTreeNode
                    inc nTVIndex
                    Invoke TreeViewChildItemsExpand, hTV, eax
                    IFDEF DEBUG32
                    PrintStringByAddr lpszText
                    ENDIF
                    Invoke TreeViewChildItemsExpand, hTV, hTVNode
                    pop hTVNode
                    pop hTVNode
                    ;Invoke TreeViewChildItemsExpand, hTV, hTVNode
                    pop hTVNode
                    ;Invoke TreeViewChildItemsExpand, hTV, hTVNode
                    push hTVNode
                    ;Invoke TreeViewChildItemsExpand, hTV, hTVNode
                    push hTVNode
                    ;Invoke TreeViewChildItemsExpand, hTV, hTVNode
                .ELSE
                    pop hTVNode
                    ;pop hTVNode
                    ;push hTVNode
                    ;push hTVNode
                .ENDIF

            .ENDIF
            ;pop hTVNode

            
        .ELSEIF eax == MXML_IGNORE
            IFDEF DEBUG32
            PrintText 'MXML_IGNORE'
            ENDIF
            pop hTVNode
            
        .ELSEIF eax == MXML_CUSTOM
            IFDEF DEBUG32
            PrintText 'MXML_CUSTOM'
            ENDIF
            pop hTVNode
        .ELSE
            IFDEF DEBUG32
            PrintText 'Other'
            ENDIF
            pop hTVNode
        .ENDIF

        Invoke TreeViewChildItemsExpand, hTV, hTVNode
        
        mov eax, hMXMLTreeNode
    .ENDW

    Invoke TreeViewChildItemsExpand, hTV, hTVRoot
    pop hTVNode  
    
    
    
    ret

ProcessXMLFile ENDP


;-------------------------------------------------------------------------------------
; CloseXMLFile - Closes XML file and deletes any treeview data and mxml data
;-------------------------------------------------------------------------------------
CloseXMLFile PROC

    .IF XMLMemMapPtr != NULL
        Invoke UnmapViewOfFile, XMLMemMapPtr
        mov XMLMemMapPtr, NULL
    .ENDIF
    .IF XMLMemMapHandle != NULL
        Invoke CloseHandle, XMLMemMapHandle
        mov XMLMemMapHandle, NULL
    .ENDIF
    .IF hXMLFile != NULL
        Invoke CloseHandle, hXMLFile
        mov hXMLFile, NULL
    .ENDIF
    
    .IF hMXMLTreeRoot != NULL
        Invoke mxmlDelete, hMXMLTreeRoot
        mov hMXMLTreeRoot, NULL
    .ENDIF
    
    Invoke TreeViewDeleteAll, hTV
    
    ret

CloseXMLFile ENDP


























end start
