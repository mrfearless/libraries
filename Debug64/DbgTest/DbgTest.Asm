.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \JWasm\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\Jwasm\bin\DbgWin.exe'>
    include \JWasm\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF


include DbgTest.inc

.CODE

WinMainCRTStartup proc FRAME
	invoke GetModuleHandle, NULL
	mov hInstance, rax
	invoke GetCommandLine
	mov CommandLine, rax
	Invoke InitCommonControls
	mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
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
	mov wcex.hbrBackground, COLOR_WINDOW+1
	mov wcex.lpszMenuName, IDM_MENU ;NULL 
	lea rax, ClassName
	mov wcex.lpszClassName, rax
	invoke LoadIcon, NULL, IDI_APPLICATION
	;Invoke LoadIcon, hInst, ICO_MAIN ; resource icon for main application icon
	;mov hIcoMain, eax ; main application icon	
	mov wcex.hIcon, rax
	mov wcex.hIconSm, rax
	invoke LoadCursor, NULL, IDC_ARROW
	mov wcex.hCursor, rax
	invoke RegisterClassEx, addr wcex
	
	;invoke CreateWindowEx, 0, addr ClassName, addr szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL
	Invoke CreateDialogParam, hInstance, IDD_DIALOG, 0, Addr WndProc, 0
	mov hWnd, rax
	
	invoke ShowWindow, hWnd, SW_SHOWNORMAL
	invoke UpdateWindow, hWnd
	
	.while (TRUE)
		invoke GetMessage, addr msg, NULL, 0, 0
		.break .if (!rax)		
		
		invoke TranslateMessage, addr msg
		invoke DispatchMessage, addr msg
	.endw
	
	mov rax, msg.wParam
	ret	
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc FRAME hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
    LOCAL dwTestLocal:DWORD
    
	.IF edx == WM_INITDIALOG
		; Init Stuff Here
		
		
	.ELSEIF edx == WM_COMMAND
		.IF wParam == IDM_FILE_EXIT
			Invoke SendMessage, hWin, WM_CLOSE, 0, 0
		
		.ELSEIF wParam == IDC_BTNEXIT
			Invoke SendMessage, hWin, WM_CLOSE, 0, 0
		
		.ELSEIF wParam == IDC_BTN1
		    PrintText 'User clicked test button 1'
		    PrintString szDbgTestString
		    
		.ELSEIF wParam == IDC_BTN2    
		    PrintText 'User clicked test button 2'
		    mov eax, 1
		    PrintDec eax
		    
		    lea rbx, szDbgTestStringBy
		    mov dwTestString, rbx 
		    PrintStringByAddr rbx
		    
		.ELSEIF wParam == IDC_BTN3
		    PrintText 'User clicked test button 3'
		    PrintDec dwTestDWORD
		    PrintQWORD dwTestQWORD
		    mov dwTestLocal, 1234d
		    PrintDec dwTestLocal
		
		.ELSEIF wParam == IDM_HELP_ABOUT
			Invoke ShellAbout, hWin, Addr AppName, Addr AboutMsg, NULL
			
		.ENDIF

	.ELSEIF edx == WM_CLOSE
		Invoke DestroyWindow, hWin
		
	.ELSEIF edx == WM_DESTROY
		Invoke PostQuitMessage, NULL
		
	.ELSE
		invoke DefWindowProc, rcx, edx, r8, r9
		ret
	.ENDIF
	xor rax, rax
	ret
WndProc endp

end WinMainCRTStartup
