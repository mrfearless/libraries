SearchTextboxInit                   PROTO :DWORD
SearchTextboxSubclass               PROTO :DWORD, :DWORD, :DWORD, :DWORD
SearchTextboxShow                   PROTO :DWORD, :DWORD
SearchTextboxClear                  PROTO :DWORD, :DWORD
SearchTextboxStartSearch            PROTO :DWORD
SearchTreeviewThread                PROTO :DWORD 
SearchTextboxStatusBarSubclass      PROTO :DWORD, :DWORD, :DWORD, :DWORD


.CONST
STACK8MB                    EQU 8388608d
STACK16MB                   EQU 16777216d
STACK32MB                   EQU 33554432d
STACK64MB                   EQU 67108864d

IDC_TxtSearchbox            EQU 1004
IDC_BtnCaseToggle           EQU 1099

BMP_CASE_SENSITIVE          EQU 998
BMP_CASE_INSENSITIVE        EQU 999


.DATA
TxtSearchboxClass           DB 'edit',0
BtnSearchboxCaseClass       DB 'button',0

szWideNull                  DB 0,0,0,0
szWideSearchForText         DB 'S',0,'e',0,'a',0,'r',0,'c',0,'h',0,' ',0
                            DB 'f',0,'o',0,'r',0,' ',0,'t',0,'e',0,'x',0,'t',0,0,0,0,0,0
szSegoeUIFont               DB "Segoe UI",0 


szSearchText                DB 256 DUP (0)
szLastSearchText            DB 256 DUP (0)
szSearchingForBuffer        DB 320 DUP (0)
szSearchingFor              DB "Searching for '",0
szSearchingFor2             DB "', please wait...",0
szSearchingAgainFor         DB "Searching again for '",0
szSearchFound               DB "Found occurance of '",0
szSearchFound2              DB "'",0
szSearchFoundFindAgain      DB " (F3 to search for next)",0
szSearchFoundNext           DB "Found the next occurance of '",0
szSearchNotFound            DB "No occurance of '",0
szFound                     DB "' found",0
szSearchNoMoreFound         DB "No more occurances of '",0
szSearchEmpty               DB 'No text to search for has been provided',0
szSearchCaseSensitive       DB " (case sensitive is on - F4 to toggle)",0

hFoundItem                  DD 0
hLastFoundItem              DD 0
bSearchTermNew              DD TRUE

hSearchThread               DD 0
lpSearchThreadId            DD 0

.DATA?
hTxtSearchTextbox           DD ?
hBtnCaseToggle              DD ?
hBmpCaseSensitive           DD ?
hBmpCaseInsensitive         DD ?

.CODE


;-------------------------------------------------------------------------------------
; SearchTextboxInit
;-------------------------------------------------------------------------------------
SearchTextboxInit PROC hWin:DWORD

    Invoke CreateWindowEx, WS_EX_CLIENTEDGE, Addr TxtSearchboxClass, NULL, WS_VISIBLE or WS_TABSTOP or WS_CHILD or ES_LEFT or ES_AUTOHSCROLL, 2, 3, 130, 19, hSB, 0, hInstance, NULL
    .IF eax == NULL
        ;PrintText 'Failed to create text search box'
        ret
    .ENDIF
    mov hTxtSearchTextbox, eax
    
    Invoke SendMessage, hTxtSearchTextbox, EM_LIMITTEXT, 255, 0
    
    Invoke SetWindowLong, hTxtSearchTextbox, GWL_WNDPROC, Addr SearchTextboxSubclass
    Invoke SetWindowLong, hTxtSearchTextbox, GWL_USERDATA, eax
    
    Invoke SendMessage, hTxtSearchTextbox, WM_SETFONT, hFontNormal, TRUE
    Invoke SendMessageW, hTxtSearchTextbox, EM_SETCUEBANNER, FALSE, Addr szWideSearchForText

    
;    Invoke CreateWindowEx, NULL, Addr BtnSearchboxCaseClass, NULL, WS_VISIBLE or WS_CHILD or BS_PUSHBUTTON or BS_ICON, 134, 4, 16, 16, hWin, 0, hInstance, IDC_BtnCaseToggle
;    mov hBtnCaseToggle, eax
    Invoke SetWindowLong, hSB, GWL_WNDPROC, Addr SearchTextboxStatusBarSubclass
    Invoke SetWindowLong, hSB, GWL_USERDATA, eax
;    
;    ;Invoke LoadIcon, hInstance, BMP_CASE_SENSITIVE
;    Invoke LoadImage, hInstance, BMP_CASE_SENSITIVE, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
;    ;Invoke LoadBitmap, hInstance, BMP_CASE_SENSITIVE
;    mov hBmpCaseSensitive, eax
;    
;    ;Invoke LoadIcon, hInstance, BMP_CASE_INSENSITIVE
;    Invoke LoadImage, hInstance, BMP_CASE_INSENSITIVE, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
;    ;Invoke LoadBitmap, hInstance, BMP_CASE_INSENSITIVE
;    mov hBmpCaseInsensitive, eax
;    
;    ;Invoke SendMessage, hBtnCaseToggle, BM_SETIMAGE, IMAGE_BITMAP, hBmpCaseSensitive
;    Invoke SendMessage, hBtnCaseToggle, STM_SETIMAGE, IMAGE_ICON, hBmpCaseSensitive
;
;        ;invoke LoadCursor, 0, IDC_HAND
;        ;invoke SetClassLong, hBtnCaseToggle, GCL_HCURSOR,eax
    
    ret
SearchTextboxInit ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxStatusBarSubclass - to handle color of search box text to indicate case sensitivity
;-------------------------------------------------------------------------------------
SearchTextboxStatusBarSubclass PROC hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    LOCAL wNotifyCode:DWORD
    
    mov eax, uMsg
    .IF eax == WM_CTLCOLOREDIT
        .IF g_CaseSensitiveSearch == FALSE ; black text
            Invoke SetTextColor, wParam, 230194h ;94015Fh
            ;mov eax, hStatusbarGreyBrush
            ret
        .ELSE ; green text
	        Invoke SetTextColor, wParam, 0E07A21h ;0A9401h
	        ;mov eax, hStatusbarGreyBrush	
	        ret
        .ENDIF
		 
	.ELSE
	    Invoke GetWindowLong, hWin, GWL_USERDATA
	    Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	    ret
	.ENDIF

	Invoke GetWindowLong, hWin, GWL_USERDATA
	Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam	
	ret

SearchTextboxStatusBarSubclass ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxShow
;-------------------------------------------------------------------------------------
SearchTextboxShow PROC hWin:DWORD, bShow:DWORD
    
    .IF bShow == TRUE
        Invoke EnableWindow, hTxtSearchTextbox, TRUE
        ;Invoke ShowWindow, hTxtSearchTextbox, SW_SHOW
    .ELSE
        ;Invoke ShowWindow, hTxtSearchTextbox, SW_HIDE
        Invoke EnableWindow, hTxtSearchTextbox, FALSE
    .ENDIF
    ret

SearchTextboxShow ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxClear
;-------------------------------------------------------------------------------------
SearchTextboxClear PROC hWin:DWORD, bShowCue:DWORD
    
    Invoke SetWindowTextW, hTxtSearchTextbox, Addr szWideNull
    .IF bShowCue == TRUE
        Invoke SendMessageW, hTxtSearchTextbox, EM_SETCUEBANNER, FALSE, Addr szWideSearchForText
    .ELSE
        Invoke SendMessageW, hTxtSearchTextbox, EM_SETCUEBANNER, FALSE, Addr szWideNull
    .ENDIF
    
    ret

SearchTextboxClear ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxSubclass
;-------------------------------------------------------------------------------------
SearchTextboxSubclass PROC hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM

	mov eax, uMsg
	.IF eax == WM_GETDLGCODE
	    mov eax, DLGC_WANTALLKEYS or DLGC_WANTTAB
	    ret
    
    .ELSEIF eax == WM_CHAR
        mov eax, wParam
        .IF eax == VK_RETURN || wParam == VK_TAB
            ;PrintText 'WM_CHAR:VK_RETURN or VK_TAB'
            ;Invoke SetFocus, hTV
            xor eax, eax
            ret
        .ELSE
	        Invoke GetWindowLong, hWin, GWL_USERDATA
	        Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	        ret
        .ENDIF

    .ELSEIF eax == WM_KEYDOWN
        mov eax, wParam
        .IF eax == VK_F3
            ; search (default)
            Invoke SearchTextboxStartSearch, hWin
            Invoke SetFocus, hTV
            xor eax, eax ; FALSE
            ret            
        .ELSEIF eax == VK_F4
            Invoke IniToggleCaseSensitiveSearch
            Invoke MenuOptionsUpdate, hWnd
            Invoke InvalidateRect, hWin, NULL, TRUE
            xor eax, eax ; FALSE
            ret   
        ;.ELSEIF eax == VK_F6
        ;    ; search again forward for next ref
        ;    Invoke SearchTextboxStartSearch, hWin
            
        ;.ELSEIF eax == VK_F7
        ;    ; search again backward for prev ref
        
        .ELSEIF eax == VK_RETURN
            Invoke SearchTextboxStartSearch, hWin
            Invoke SetFocus, hTV
            xor eax, eax ; FALSE
            ret

        .ELSEIF eax == VK_TAB
            ;PrintText 'WM_KEYDOWN:VK_RETURN or VK_TAB'
            Invoke SetFocus, hTV
            xor eax, eax ; FALSE
            ret
            
        .ELSE
	        Invoke GetWindowLong, hWin, GWL_USERDATA
	        Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	        ret
        .ENDIF
    
	.ELSE
	    Invoke GetWindowLong, hWin, GWL_USERDATA
	    Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam
	    ret
	.ENDIF

	Invoke GetWindowLong, hWin, GWL_USERDATA
	Invoke CallWindowProc, eax, hWin, uMsg, wParam, lParam	
 
    ret
SearchTextboxSubclass ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxFocus
;-------------------------------------------------------------------------------------
SearchTextboxFocus PROC hWin:DWORD
    
    Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    .IF sdword ptr eax > 0
        ;Invoke SearchTextboxShow, hWin, TRUE
        Invoke SetFocus, hTxtSearchTextbox
    .ENDIF
    
    ret

SearchTextboxFocus ENDP


;-------------------------------------------------------------------------------------
; SearchTextboxStartSearch
;-------------------------------------------------------------------------------------
SearchTextboxStartSearch PROC hWin:DWORD
    LOCAL lpExitCode:DWORD
    
    Invoke SendMessage, hTV, TVM_GETCOUNT, 0, 0
    .IF eax == 0
        mov bSearchTermNew, TRUE
        ret
    .ENDIF
    
    Invoke GetWindowText, hTxtSearchTextbox, Addr szSearchText, SIZEOF szSearchText
    .IF eax == 0
        mov bSearchTermNew, TRUE
        Invoke SetFocus, hTxtSearchTextbox
        ;Invoke StatusBarSetPanelText, 2, Addr szSearchEmpty
        ret
    .ENDIF
    
    ; check if last seatch term is same as last, if it is not then we have a new search term
    Invoke szLen, Addr szSearchText
    .IF eax == 0
        mov bSearchTermNew, TRUE
        mov hFoundItem, 0
        mov hLastFoundItem, 0
        Invoke SetFocus, hTxtSearchTextbox
    .ELSE
        Invoke szCmp, Addr szLastSearchText, Addr szSearchText
        .IF eax == 0 ; no match
            mov bSearchTermNew, TRUE
            mov hFoundItem, 0
            mov hLastFoundItem, 0
        .ENDIF
    .ENDIF
    
    ; inform user search has started
    .IF bSearchTermNew == TRUE
        Invoke szCopy, Addr szSearchingFor, Addr szSearchingForBuffer
        Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
        Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchingFor2
        Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer
    .ELSE
        Invoke szCopy, Addr szSearchingAgainFor, Addr szSearchingForBuffer
        Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
        Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchingFor2
        Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer
    .ENDIF
    .IF hSearchThread != 0
        Invoke GetExitCodeThread, hSearchThread, Addr lpExitCode
        .IF eax != 0
            mov eax, lpExitCode
            .IF eax == STILL_ACTIVE
                ;PrintText 'Thread Still Active!'
                ret
            .ENDIF
        .ENDIF
        mov hSearchThread, 0
    .ENDIF

    Invoke CreateThread, NULL, STACK16MB, Addr SearchTreeviewThread, Addr szSearchText, NULL, Addr lpSearchThreadId
    mov hSearchThread, eax

    ret
SearchTextboxStartSearch ENDP


;-------------------------------------------------------------------------------------
; SearchTreeviewThread
;-------------------------------------------------------------------------------------
SearchTreeviewThread PROC lpszSearchText:DWORD
    
    .IF bSearchTermNew == TRUE
        Invoke TreeViewFindItem, hTV, 0, lpszSearchText, g_CaseSensitiveSearch
    .ELSE
        mov eax, hFoundItem
        .IF eax == 0 && eax != hLastFoundItem
            ;PrintText 'Search again from start'
            ;PrintDec hFoundItem
            ;PrintDec hLastFoundItem
            Invoke TreeViewFindItem, hTV, 0, lpszSearchText, g_CaseSensitiveSearch
        .ELSE
            ;PrintText 'Search again'
            ;PrintDec hFoundItem
            ;PrintDec hLastFoundItem            
            Invoke TreeViewFindItem, hTV, hFoundItem, lpszSearchText, g_CaseSensitiveSearch
        .ENDIF
    .ENDIF
    mov hFoundItem, eax

    ; tell user result of search
    .IF hFoundItem != 0
        .IF bSearchTermNew == TRUE
            Invoke szCopy, Addr szSearchFound, Addr szSearchingForBuffer
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchFound2
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchFoundFindAgain
            Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer
        .ELSE
            Invoke szCopy, Addr szSearchFoundNext, Addr szSearchingForBuffer
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchFound2
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchFoundFindAgain
            Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer            
        .ENDIF
        mov eax, hFoundItem
        mov hLastFoundItem, eax

        ;Invoke SetFocus, hTV
        Invoke TreeViewSetSelectedItem, hTV, hFoundItem, TRUE
        ;Invoke SetFocus, hTV
        mov bSearchTermNew, FALSE
    .ELSE
        .IF bSearchTermNew == TRUE

            Invoke szCopy, Addr szSearchNotFound, Addr szSearchingForBuffer
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szFound
            .IF g_CaseSensitiveSearch == TRUE
                Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchCaseSensitive
            .ENDIF
            Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer
        .ELSE
            Invoke szCopy, Addr szSearchNoMoreFound, Addr szSearchingForBuffer
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchText
            Invoke szCatStr, Addr szSearchingForBuffer, Addr szFound
            .IF g_CaseSensitiveSearch == TRUE
                Invoke szCatStr, Addr szSearchingForBuffer, Addr szSearchCaseSensitive
            .ENDIF            
            Invoke StatusBarSetPanelText, 2, Addr szSearchingForBuffer
 
        .ENDIF
        mov eax, hFoundItem
        mov hLastFoundItem, eax
    .ENDIF
    
    
    Invoke szCopy, lpszSearchText, Addr szLastSearchText
    
    ret

SearchTreeviewThread ENDP















