.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm


include CSExample_x86.inc

.code

start:

    Invoke GetModuleHandle, NULL
    mov hInstance, eax
    Invoke GetCommandLine
    mov CommandLine, eax
    Invoke InitCommonControls
    mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, Offset icc
    
    Invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
    Invoke ExitProcess, eax

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain PROC hInst:HINSTANCE, hPrevInst:HINSTANCE, CmdLine:LPSTR, CmdShow:DWORD
    LOCAL wc:WNDCLASSEX
    LOCAL msg:MSG

    mov wc.cbSize, SIZEOF WNDCLASSEX
    mov wc.style, CS_HREDRAW or CS_VREDRAW
    mov wc.lpfnWndProc, Offset WndProc
    mov wc.cbClsExtra, NULL
    mov wc.cbWndExtra, DLGWINDOWEXTRA
    push hInst
    pop wc.hInstance
    mov wc.hbrBackground, COLOR_WINDOW+1
    mov wc.lpszMenuName, NULL ;IDM_MENU
    mov wc.lpszClassName, Offset ClassName
    Invoke LoadIcon, hInstance, ICO_MAIN ; resource icon for main application icon
    mov hIcoMain, eax ; main application icon
    mov  wc.hIcon, eax
    mov wc.hIconSm, eax
    Invoke LoadCursor, NULL, IDC_ARROW
    mov wc.hCursor,eax
    Invoke RegisterClassEx, Addr wc
    Invoke CreateDialogParam, hInstance, IDD_DIALOG, NULL, Addr WndProc, NULL
    mov hWnd, eax
    Invoke ShowWindow, hWnd, SW_SHOWNORMAL
    Invoke UpdateWindow, hWnd
    .WHILE TRUE
        Invoke GetMessage, Addr msg, NULL, 0, 0
        .BREAK .if !eax
        Invoke TranslateMessage, Addr msg
        Invoke DispatchMessage, Addr msg
    .ENDW
    mov eax, msg.wParam
    ret
WinMain ENDP


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc PROC hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
    
    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        ; Init Stuff Here
        
        Invoke GetSysColorBrush, COLOR_WINDOW
        mov hWhiteBrush, eax		
		
        Invoke GetDlgItem, hWin, IDC_TxtRawBytes
        mov hTxtRawBytes, eax  
        
		Invoke GetDlgItem, hWin, IDC_TxtAsmDecoded
        mov hTxtAsmDecoded, eax
        
        Invoke SetWindowText, hTxtRawBytes, Addr szInitialRawCode
        
        
    .ELSEIF eax == WM_COMMAND
        mov eax, wParam
        and eax, 0FFFFh
        .IF eax == IDM_FILE_EXIT
            Invoke SendMessage, hWin, WM_CLOSE, 0, 0
            
        .ELSEIF eax == IDM_HELP_ABOUT
            Invoke ShellAbout, hWin, Addr AppName, Addr AboutMsg,NULL
		
		.ELSEIF eax == IDC_BtnExit
		    Invoke SendMessage, hWin, WM_CLOSE, 0, 0
		
		.ELSEIF eax == IDC_BtnDecode
		    Invoke DoDecode, hWin
		    
        .ENDIF

    .ELSEIF eax == WM_CTLCOLORSTATIC
        mov eax, hWhiteBrush
        ret

    .ELSEIF eax == WM_CLOSE
        Invoke DestroyWindow, hWin
        
    .ELSEIF eax == WM_DESTROY
        Invoke PostQuitMessage, NULL
        
    .ELSE
        Invoke DefWindowProc, hWin, uMsg, wParam, lParam
        ret
    .ENDIF
    xor eax, eax
    ret
WndProc ENDP


;-------------------------------------------------------------------------------------
; DoDecode - Capstone decode text box to assembler bytes
;-------------------------------------------------------------------------------------
DoDecode PROC USES EBX hWin:DWORD
    LOCAL j:DWORD
    LOCAL handle:csh
    LOCAL insn:DWORD ; pointer to cs_insn
    LOCAL count:DWORD
    LOCAL Address:QWORD ; Note has to be QWORD sized as a parameter for cs_disasm
    LOCAL dwAddress:DWORD
    LOCAL dwAddressLow:DWORD
    LOCAL dwAddressHigh:DWORD
    LOCAL ptrInsnAddress:DWORD
    LOCAL ptrInsnMnemonic:DWORD
    LOCAL ptrInsnOpStr:DWORD
    LOCAL ptrInsn:DWORD

    Invoke cs_open, CS_ARCH_X86, CS_MODE_32, Addr handle
    .IF eax != CS_ERR_OK
        Invoke MessageBox, 0, Addr szCSOpenFail, Addr szCSError, MB_OK
        mov eax, FALSE
        ret
    .ENDIF
    
    ; Set address variable by setting low order and high order DWORDs:
    mov dword ptr [Address+0], 00000000h ; High order DWORD of 64bit address
    mov dword ptr [Address+4], 00010000h ; Low order DWORD of 64bit address    
    
    Invoke cs_disasm, handle, Addr RAWCODE, dwSizeRAWCODE, Address, 0, Addr insn
    mov count, eax

    .IF count > 0
        
        mov ebx, insn
        mov ptrInsn, ebx
        
	    ; loop through
	    mov j, 0
	    mov eax, 0
	    .WHILE eax < count
	    
	        mov ebx, ptrInsn
	        lea eax, [ebx].cs_insn.address
	        mov ptrInsnAddress, eax
	        
	        mov eax, dword ptr [ebx].cs_insn.address
	        mov dwAddressLow, eax
	        
	        mov eax, dword ptr [ebx].cs_insn.address+4
	        mov dwAddressHigh, eax
	        
	        mov eax, dwAddressHigh
	        add eax, dwAddressLow
	        mov dwAddress, eax
	        
	        mov ebx, ptrInsn
	        lea eax, [ebx].cs_insn.mnemonic
	        mov ptrInsnMnemonic, eax
	        
	        mov ebx, ptrInsn
	        lea eax, [ebx].cs_insn.op_str
	        mov ptrInsnOpStr, eax

	        Invoke wsprintf, Addr szOutput, Addr szFmt, dwAddress, ptrInsnMnemonic, ptrInsnOpStr
            Invoke lstrcat, Addr szFinalOutput, Addr szOutput

            add ptrInsn, SIZEOF cs_insn
	        inc j
	        mov eax, j
	    .ENDW

	    Invoke cs_free, insn, 0

	.ELSE
	    Invoke MessageBox, 0, Addr szCSDisasmFail, Addr szCSError, MB_OK
        mov eax, FALSE
        ret
	.ENDIF        

    Invoke cs_close, Addr handle

    Invoke SetWindowText, hTxtAsmDecoded, Addr szFinalOutput

    mov eax, TRUE
    ret
DoDecode ENDP


end start
