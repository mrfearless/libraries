InitToolBar			            PROTO :DWORD, :DWORD, :DWORD ; Place in WM_INITDIALOG event
InitRebar                       PROTO :DWORD

ToolBarUpdate                   PROTO :DWORD, :DWORD
ToolBarUpdateByKeyboard         PROTO :DWORD, :DWORD
ToolBarShowDropdownAddMenu      PROTO :DWORD
ResetToolbars                   PROTO :DWORD

SaveToolbarState                PROTO :DWORD, :DWORD

.CONST
TB_SETEXTENDEDSTYLE             EQU WM_USER + 84
TBSTYLE_EX_DRAWDDARROWS         EQU 00000001h

IDC_MAINTOOLBAR					EQU 1003
IDC_RbBAM						EQU 1004

; Toolbar Icons: Enabled
ICO_TB_FILE_OPEN			    EQU 1500
ICO_TB_FILE_CLOSE			    EQU 1501
ICO_TB_FILE_NEW				    EQU 1502
ICO_TB_FILE_SAVE			    EQU 1503
ICO_TB_FILE_SAVEAS			    EQU 1504
ICO_TB_EDIT_COPY_ITEM		    EQU 1505
ICO_TB_EDIT_COPY_BRANCH		    EQU 1506
ICO_TB_EDIT_PASTE_ITEM		    EQU 1507
ICO_TB_EDIT_PASTE_BRANCH	    EQU 1508
ICO_TB_ADD_ITEM 			    EQU 1509
ICO_TB_DEL_ITEM 			    EQU 1510
; Toolbar Icons: Disabled (Greyed)
ICO_TB_FILE_OPEN_GREY			EQU 1600
ICO_TB_FILE_CLOSE_GREY			EQU 1601
ICO_TB_FILE_NEW_GREY			EQU 1602
ICO_TB_FILE_SAVE_GREY			EQU 1603
ICO_TB_FILE_SAVEAS_GREY			EQU 1604
ICO_TB_EDIT_COPY_ITEM_GREY		EQU 1605
ICO_TB_EDIT_COPY_BRANCH_GREY	EQU 1606
ICO_TB_EDIT_PASTE_ITEM_GREY		EQU 1607
ICO_TB_EDIT_PASTE_BRANCH_GREY	EQU 1608
ICO_TB_ADD_ITEM_GREY			EQU 1609
ICO_TB_DEL_ITEM_GREY 			EQU 1610
; Toolbar Icons Add Dropdown: Enabled
ICO_TB_ADD_ITEM_STRING		    EQU 1540
ICO_TB_ADD_ITEM_NUMBER		    EQU 1541
ICO_TB_ADD_ITEM_TRUE		    EQU 1542
ICO_TB_ADD_ITEM_FALSE		    EQU 1543
ICO_TB_ADD_ITEM_ARRAY		    EQU 1544
ICO_TB_ADD_ITEM_OBJECT		    EQU 1545
; Toolbar Icons Add Dropdown: Disabled (Greyed)
ICO_TB_ADD_ITEM_STRING_GREY		EQU 1640
ICO_TB_ADD_ITEM_NUMBER_GREY		EQU 1641
ICO_TB_ADD_ITEM_TRUE_GREY		EQU 1642
ICO_TB_ADD_ITEM_FALSE_GREY		EQU 1643
ICO_TB_ADD_ITEM_ARRAY_GREY		EQU 1644
ICO_TB_ADD_ITEM_OBJECT_GREY		EQU 1645

; Toolbar IDs
TB_FILE_OPEN			        EQU 2000
TB_FILE_CLOSE			        EQU 2001
TB_FILE_NEW				        EQU 2002
TB_FILE_SAVE			        EQU 2003
TB_FILE_SAVEAS			        EQU 2004
TB_EDIT_COPY_ITEM		        EQU 2005
TB_EDIT_COPY_BRANCH		        EQU 2006
TB_EDIT_PASTE_ITEM		        EQU 2007
TB_EDIT_PASTE_BRANCH	        EQU 2008
TB_ADD_ITEM 			        EQU 2009
TB_DEL_ITEM 			        EQU 2010
TB_ADD_ITEM_STRING		        EQU 2040
TB_ADD_ITEM_NUMBER		        EQU 2041
TB_ADD_ITEM_TRUE		        EQU 2042
TB_ADD_ITEM_FALSE		        EQU 2043
TB_ADD_ITEM_ARRAY		        EQU 2044
TB_ADD_ITEM_OBJECT		        EQU 2045

; ToolBar Tooltips String Table IDs - 1000 more than toolbar resources
TT_FILE_OPEN			        EQU 3000
TT_FILE_CLOSE			        EQU 3001
TT_FILE_NEW				        EQU 3002
TT_FILE_SAVE			        EQU 3003
TT_FILE_SAVEAS			        EQU 3004
TT_EDIT_COPY_ITEM		        EQU 3005
TT_EDIT_COPY_BRANCH		        EQU 3006
TT_EDIT_PASTE_ITEM		        EQU 3007
TT_EDIT_PASTE_BRANCH	        EQU 3008
TT_ADD_ITEM 			        EQU 3009
TT_DEL_ITEM 			        EQU 3010
TT_ADD_ITEM_STRING		        EQU 3040
TT_ADD_ITEM_NUMBER		        EQU 3041
TT_ADD_ITEM_TRUE		        EQU 3042
TT_ADD_ITEM_FALSE		        EQU 3043
TT_ADD_ITEM_ARRAY		        EQU 3044
TT_ADD_ITEM_OBJECT		        EQU 3045


.DATA
ToolBarTipText 		            DB 64 DUP (0) ; buffer to hold toolbar button tip text for displaying


.DATA?
hToolBar			            DD ? ; Handle for ToolBar
hToolBarIL_Enabled              DD ? ; Image list enabled handle
hToolBarIL_Disabled             DD ? ; Image list disabled (greyed) handle
hRebarBam                       DD ?
ToolBarHeight		            DD ?



.CODE


;-------------------------------------------------------------------------------------
; InitToolbar
;-------------------------------------------------------------------------------------
InitToolbar PROC USES EBX hWin:DWORD, dwToolbarButtonWidth:DWORD, dwToolbarButtonHeight:DWORD
	LOCAL bSize:DWORD
	LOCAL bSizeConnect:DWORD
	LOCAL tbab:TBADDBITMAP
	LOCAL tbb:TBBUTTON
	LOCAL dwToolbarState:DWORD

	Invoke GetDlgItem, hWin, IDC_MAINTOOLBAR
	mov hToolBar, eax
	
    Invoke ImageList_Create, 16, 16, ILC_COLOR32, 16, 32
    mov hToolBarIL_Enabled, eax
    Invoke ImageList_Create, 16, 16, ILC_COLOR32, 16, 32
    mov hToolBarIL_Disabled, eax

    Invoke SendMessage, hToolBar, CCM_SETVERSION, 5, 0
    Invoke SendMessage, hToolBar, TB_SETIMAGELIST, 0, hToolBarIL_Enabled
    Invoke SendMessage, hToolBar, TB_SETDISABLEDIMAGELIST, 0, hToolBarIL_Disabled
    Invoke SendMessage, hToolBar, TB_SETEXTENDEDSTYLE, 0, TBSTYLE_EX_DRAWDDARROWS
    
    ; Load enabled icons
    Invoke LoadIcon, hInstance, ICO_TB_FILE_OPEN
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_CLOSE
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_NEW
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_SAVE
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax    
    Invoke LoadIcon, hInstance, ICO_TB_FILE_SAVEAS
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_COPY_ITEM
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_COPY_BRANCH
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_PASTE_ITEM
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_PASTE_BRANCH
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_ADD_ITEM
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_DEL_ITEM
    Invoke ImageList_AddIcon, hToolBarIL_Enabled, eax
    
    ; Load disabled icons
    Invoke LoadIcon, hInstance, ICO_TB_FILE_OPEN_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_CLOSE_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_NEW_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_FILE_SAVE_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax    
    Invoke LoadIcon, hInstance, ICO_TB_FILE_SAVEAS_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_COPY_ITEM_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_COPY_BRANCH_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_PASTE_ITEM_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_EDIT_PASTE_BRANCH_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_ADD_ITEM_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax
    Invoke LoadIcon, hInstance, ICO_TB_DEL_ITEM_GREY
    Invoke ImageList_AddIcon, hToolBarIL_Disabled, eax    

    Invoke SendMessage, hToolBar, TB_BUTTONSTRUCTSIZE, sizeof TBBUTTON, 0	; Set toolbar struct size

	mov ebx, dwToolbarButtonWidth
	mov eax, dwToolbarButtonHeight
	mov ToolBarHeight, eax ; save toolbar height for later calculations
	shl eax, 16d
	mov ax, bx
	mov bSize, eax
	Invoke SendMessage, hToolBar, TB_SETBITMAPSIZE, 0, bSize ; Set bitmap size
	Invoke SendMessage, hToolBar, TB_SETBUTTONSIZE, 0, bSize ; Set each button size

	mov tbb.fsState, TBSTATE_ENABLED
	mov tbb.dwData, 0
	mov tbb.iString, 0

	mov tbb.iBitmap, 0
	mov tbb.idCommand, TB_FILE_OPEN
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb	

	mov tbb.iBitmap, 1
	mov tbb.idCommand, TB_FILE_CLOSE
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 2
	mov tbb.idCommand, TB_FILE_NEW
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 3
	mov tbb.idCommand, TB_FILE_SAVE
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 4
	mov tbb.idCommand, TB_FILE_SAVEAS
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

    mov tbb.iBitmap, -1
    mov tbb.fsStyle, TBSTYLE_SEP
    invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 5
	mov tbb.idCommand, TB_EDIT_COPY_ITEM
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 6
	mov tbb.idCommand, TB_EDIT_COPY_BRANCH
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 7
	mov tbb.idCommand, TB_EDIT_PASTE_ITEM
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 8
	mov tbb.idCommand, TB_EDIT_PASTE_BRANCH
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

    mov tbb.iBitmap, -1
    mov tbb.fsStyle, TBSTYLE_SEP
    invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 9
	mov tbb.idCommand, TB_ADD_ITEM
	mov tbb.fsStyle, TBSTYLE_BUTTON or TBSTYLE_AUTOSIZE or TBSTYLE_DROPDOWN
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb

	mov tbb.iBitmap, 10
	mov tbb.idCommand, TB_DEL_ITEM
	mov tbb.fsStyle, TBSTYLE_BUTTON
	Invoke SendMessage, hToolBar, TB_ADDBUTTONS, 1, Addr tbb
    
    Invoke ResetToolbars, hWin
   
	ret
InitToolbar ENDP


;-------------------------------------------------------------------------------------
; Process ToolBar Buttons Tooltips - Call from WM_NOTIFY
;-------------------------------------------------------------------------------------
ToolBarTips PROC lParam:DWORD
	mov ecx, lParam
	mov eax, (NMHDR PTR [ecx]).code
	.IF eax ==  TTN_NEEDTEXT
		mov ecx, lParam
		mov eax, (NMHDR PTR [ecx]).idFrom
		add eax, 1000 ; add 1000 to get tooltip
		Invoke LoadString, hInstance, eax, Addr ToolBarTipText, 64
		mov ecx, lParam
		lea eax, ToolBarTipText
		mov (TOOLTIPTEXT PTR [ecx]).lpszText, eax ; OFFSET ToolBarTipText
	.ENDIF
	ret
ToolBarTips endp


;-------------------------------------------------------------------------------------
; ToolBarUpdate
;-------------------------------------------------------------------------------------
ToolBarUpdate PROC hWin:DWORD, hItem:DWORD
    LOCAL tvhi:TV_HITTESTINFO
    LOCAL hCurrentItem:DWORD
    LOCAL bInTV:DWORD
    LOCAL bHasChildren:DWORD
    LOCAL bObjectOrArray:DWORD
    LOCAL dwToolbarState:DWORD
    
    mov bInTV, FALSE
    mov bHasChildren, FALSE
    mov bObjectOrArray, FALSE
    
    .IF hItem == NULL
        Invoke GetCursorPos, Addr tvhi.pt
        Invoke ScreenToClient, hTV, addr tvhi.pt
        Invoke SendMessage, hTV, TVM_HITTEST, 0, Addr tvhi
        .IF tvhi.flags == TVHT_ONITEMLABEL
            mov bInTV, TRUE
        .ENDIF        
        Invoke SendMessage, hTV, TVM_SELECTITEM, TVGN_CARET, tvhi.hItem
        mov eax, tvhi.hItem
    .ELSE
        mov bInTV, TRUE
        mov eax, hItem
    .ENDIF

    mov hCurrentItem, eax
    .IF eax != 0 ;&& tvhi.flags == TVHT_ONITEMLABEL
        Invoke TreeViewItemHasChildren, hTV, hCurrentItem
        mov bHasChildren, eax
        
        Invoke TreeViewGetItemParam, hTV, hCurrentItem
        .IF eax != NULL ; eax = hJSON
            mov ebx, eax
            mov eax, [ebx].cJSON.itemtype
            .IF eax == cJSON_Object || eax == cJSON_Array
                mov bObjectOrArray, TRUE
            .ENDIF 
        .ENDIF
        
    .ENDIF

    ; Main menu toolbar icons
    mov eax, TBSTATE_ENABLED
    mov dwToolbarState, eax
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_OPEN, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_CLOSE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_NEW, dwToolbarState

    ; On a treeview item
	.IF bInTV == TRUE
	    mov eax, TBSTATE_ENABLED
    .ELSE
        mov eax, TBSTATE_INDETERMINATE
    .ENDIF
    mov dwToolbarState, eax
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_COPY_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_PASTE_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_DEL_ITEM, dwToolbarState

    ; On a treeview item that has children or is an object or array
	.IF bInTV == TRUE && (bHasChildren == TRUE || bObjectOrArray == TRUE)
	    mov eax, TBSTATE_ENABLED
    .ELSE
        mov eax, TBSTATE_INDETERMINATE
    .ENDIF
    mov dwToolbarState, eax
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_COPY_BRANCH, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_PASTE_BRANCH, dwToolbarState

    .IF bInTV == TRUE && bObjectOrArray == TRUE
        mov eax, TBSTATE_ENABLED
    .ELSE
        mov eax, TBSTATE_INDETERMINATE
    .ENDIF
    mov dwToolbarState, eax
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM, dwToolbarState   
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_STRING, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_NUMBER, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_TRUE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_FALSE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_ARRAY, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_OBJECT, dwToolbarState

    ret
ToolBarUpdate ENDP


;-------------------------------------------------------------------------------------
; From Toolbar Add button, show dropdown menu
;-------------------------------------------------------------------------------------
ToolBarShowDropdownAddMenu PROC USES EBX hWin:DWORD
    LOCAL rect:RECT
    LOCAL nLeft:DWORD
    LOCAL nHeight:DWORD

    Invoke SendMessage, hToolBar, TB_GETITEMRECT, 10, Addr rect
    mov eax, rect.left
    mov nLeft, eax
    
    mov eax, rect.bottom
    mov ebx, rect.top
    sub eax, ebx
 
    add eax, 8 ; for menu height
    mov nHeight, eax
    Invoke MapWindowPoints, hToolBar, NULL, Addr rect, 2
    push eax
    shr eax, 16
    add eax, nHeight
    mov TVRCMenuPoint.y, eax
    pop eax
    and	eax,0FFFFh
    add eax, nLeft
    mov TVRCMenuPoint.x, eax

	;PrintDec TVRCMenuPoint.x
	;PrintDec TVRCMenuPoint.y
	
	; Focus Main Window - ; Fix for shortcut menu not popping up right
	Invoke SetForegroundWindow, hWin 
	Invoke TrackPopupMenu, hTVAddMenu, TPM_LEFTALIGN +TPM_LEFTBUTTON, TVRCMenuPoint.x, TVRCMenuPoint.y, NULL, hWin, NULL
	Invoke PostMessage, hWin, WM_NULL, 0, 0 ; Fix for shortcut menu not popping up right      
    ret

ToolBarShowDropdownAddMenu ENDP


;-------------------------------------------------------------------------------------
; ResetToolbars
;-------------------------------------------------------------------------------------
ResetToolbars PROC hWin:DWORD
    LOCAL dwToolbarState:DWORD
    
    mov eax, TBSTATE_ENABLED
    mov dwToolbarState, eax
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_OPEN, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_CLOSE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_NEW, dwToolbarState
    mov eax, TBSTATE_INDETERMINATE
    mov dwToolbarState, eax    
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_SAVE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_SAVEAS, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_COPY_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_PASTE_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_DEL_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_COPY_BRANCH, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_EDIT_PASTE_BRANCH, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_STRING, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_NUMBER, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_TRUE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_FALSE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_ARRAY, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_ADD_ITEM_OBJECT, dwToolbarState
    ret

ResetToolbars ENDP


;-------------------------------------------------------------------------------------
; Change state of save, save as toolbar buttons
;-------------------------------------------------------------------------------------
SaveToolbarState PROC hWin:DWORD, bEnable:DWORD
    LOCAL dwToolbarState:DWORD
    
    .IF bEnable == TRUE
        mov eax, TBSTATE_ENABLED
    .ELSE
        mov eax, TBSTATE_INDETERMINATE
    .ENDIF
    mov dwToolbarState, eax

    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_SAVE, dwToolbarState
    Invoke SendMessage, hToolBar, TB_SETSTATE, TB_FILE_SAVEAS, dwToolbarState

    ret
SaveToolbarState ENDP



















