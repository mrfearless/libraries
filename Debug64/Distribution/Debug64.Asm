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

include windows.inc
includelib user32.lib
includelib kernel32.lib

include Debug64.inc

;-------------------------------------------------------------------------
; Prototypes for internal use
;-------------------------------------------------------------------------
RDBGi64toa          PROTO :QWORD, :QWORD, :QWORD
RDBGitoa            PROTO :QWORD, :QWORD, :QWORD
RDBGi16toa          PROTO :QWORD, :QWORD, :QWORD
RDBGi8toa           PROTO :QWORD, :QWORD, :QWORD

PUBLIC RDBG_SPYENABLED
PUBLIC RDBG_SPYHANDLER
PUBLIC RDBG_SPYLINENUM
PUBLIC RDBG_VEHANDLER
PUBLIC RDBG_SPYVARADDR
PUBLIC RDBG_SPYVARTYPE
PUBLIC RDBG_SPYVARNAME
PUBLIC RDBG_TRACECOUNT





;-------------------------------------------------------------------------
; Structures for internal use
;-------------------------------------------------------------------------

IFNDEF GUID
GUID STRUCT
		Data1	dd 0
		Data2	dw 0
		Data3	dw 0
		Data4	db 8 DUP (0)
GUID    ENDS
ENDIF

IFNDEF COMObject
;// COM Object definition for the output interface
COMObject  STRUCT
	; interface object
	lpVtbl			DQ ?
	; object data
	nRefCount		DQ ?
COMObject   ENDS
ENDIF


; couple structures from RadASM required for compiling the debug64 library
RAFONT                  STRUCT
	hFont		        dd ?	;Code edit normal
	hIFont		        dd ?	;Code edit italics
	hLnrFont	        dd ?	;Line numbers
RAFONT                  ENDS

HEFONT                  STRUCT
	hFont			    dd ?	;Code edit normal
	hLnrFont		    dd ?	;Line numbers
HEFONT                  ENDS

ADDINHANDLES            STRUCT
	hInstance			HINSTANCE ?
	hWnd				HWND ?
	hClient				HWND ?
	hMdi				HWND ?
	hEdt				HWND ?
	hMenu				HMENU ?
	hContextMenu		HMENU ?
	hAccel				HACCEL ?
	hIcon				HICON ?
	hCursor				HCURSOR ?
	hSplitCurV			HCURSOR ?
	hSplitCurH			HCURSOR ?
	hTool				HWND ?
	hToolProject		HWND ?
	hTabProject			HWND ?
	hFileBrowser		HWND ?
	hProjectBrowser		HWND ?
	hToolProperties		HWND ?
	hProperty			HWND ?
	hToolOutput			HWND ?
	hTabOutput			HWND ?
	hOutput				HWND ?
	hImmediate			HWND ?
	hToolTab			HWND ?
	hTab				HWND ?
	hStatus				HWND ?
	hReBar				HWND ?
	hStcBuild			HWND ?
	hCboBuild			HWND ?
	hToolDebug			HWND ?
	hTabDebug			HWND ?
	hREGDebug			HWND ?
	hFPUDebug			HWND ?
	hMMXDebug			HWND ?
	hWATCHDebug			HWND ?
	hToolFont			HFONT ?
	racf				RAFONT <>
	ratf				RAFONT <>
	rahf				HEFONT <>
	hImlTbr				HIMAGELIST ?
	hImlTbrGray			HIMAGELIST ?
	hMnuIml				HIMAGELIST ?
	hTbrFile			HWND ?
	hTbrEdit1			HWND ?
	hTbrEdit2			HWND ?
	hTbrView			HWND ?
	hTbrMake			HWND ?
	hDiv1				HWND ?
	hDiv2				HWND ?
	hCC					HWND ?
	hTT					HWND ?
	hModeless			HWND ?
	hHtmlOcx			HANDLE ?
	hFind				HWND ?
	hDbgTip				HWND ?
	hMemMnu				HGLOBAL ?
	hDCMnu				HDC ?
	hFontMnu			HFONT ?
	hBrMnu				HBRUSH ?
ADDINHANDLES            ENDS

.CONST
; some equates from RadASM required for compiling the debug64 library
AIM_DEBUGGETWIN	        equ WM_USER+54
AIM_GETHANDLES			equ WM_USER+50
WAIT_TIMEOUT	        EQU	102h
DEBUG_OUTPUT_NORMAL	    EQU	00000001h

.DATA
align 01
; some strings, defined here instead of in situ, otherwise we get linker errors about setting /LARGEADDRESSAWARE:NO
RDBG_szDbgLineFmt1		        DB "Line %u: %s",0
RDBG_szDbgLineFmt2		        DB "Line %u: ",0
RDBG_crlf	                    DB 13,10,0,0
szRadASM30Class                 DB "RadASM30Class",0
szErrorCreatingDebugWindow      DB "Error creating debug window",0
szFailedToAttachToOutputWindow  DB "Failed to attach to output window",0
szDbgWinClass                   DB "DbgWinClass",0
szHexDumpLine                   DB "Line %u : Hex dump of %u bytes at address 0x%p",0
szHexDumpFormat                 DB "%p: %s",0
szPrintNumber0x                 DB " (0x",0
szPrintNumberFormatReal8        DB "%.9f",0
szPrintNumberFormatReal4        DB "%.6f"
szPrintNumberRightBracket       DB ")",0


    ; Other bits and pieces directly from Donkey's vKim like original code 
	RDBG_IID_IDebugClient       GUID <027fe5639h, 08407h, 04f47h, <083h, 064h, 0eeh, 011h, 08fh, 0b0h, 08ah, 0c8h>>
	RDBG_IID_IDebugControl      GUID <05182e668h, 0105eh, 0416eh, <0adh, 092h, 024h, 0efh, 080h, 004h, 024h, 0bah>>
	RDBG_IID_IUnknown           GUID <000000000h, 00000h, 00000h, <0C0h, 000h, 000h, 000h, 000h, 000h, 000h, 046h>>
    RDBG_IID_IDebugOutputCallbacks  GUID <04bf58045h, 0d654h, 04c40h, <0b0h, 0afh, 068h, 030h, 090h, 0f3h, 056h, 0dch>>
	RDBG_IID_IDebugSymbols      GUID <08c31e98ch, 0983ah, 048a5h, <090h, 016h, 06fh, 0e5h, 0d6h, 067h, 0a9h, 050h>>

	RDBG_szDbgFPU6			    db "Exception  : e s p u o z d i",0

	RDBG_vtOutputCallbacks	    DQ RDBGOC_QueryInterface
						        DQ RDBGOC_AddRef
						        DQ RDBGOC_Release
						        DQ RDBGOC_Output

	RDBG_IDbgOC				    COMObject <offset RDBG_vtOutputCallbacks,1>

	RDBG_ExceptionString	    DB 64 DUP (0)
	RDBG_ExceptLine			    DB MAX_PATH*2 DUP (0)
	RDBG_ModName			    DB MAX_PATH DUP (0)

	RDBG_FNOWINDOW				DQ 0

	RDBG_SPYENABLED				DQ ?
	RDBG_SPYHANDLER				DQ -1
	RDBG_SPYLINENUM				DQ ?
	RDBG_VEHANDLER 				DQ ?
	RDBG_SPYVARADDR				DQ ?
	RDBG_SPYVARTYPE				DQ ?
	RDBG_SPYVARNAME				DB 256 DUP (?)

	RDBG_pIDebugClient			DQ ?
	RDBG_pIDebugControl			DQ ?
	RDBG_pIDebugSymbols			DQ ?

	RDBG_HexLookup				DB "0123456789ABCDEF               ",0


.CODE

;**************************************************************************
; RDBGPrintString
;**************************************************************************
RDBGPrintString PROC FRAME LineNum:QWORD, pArg:QWORD, pArgName:QWORD, szType:QWORD
	LOCAL pMem:HANDLE
	LOCAL pString:HANDLE
    LOCAL wstrlen:DWORD
    
	cmp szType, 1
	jne @F
		invoke lstrlenW, pArg
		inc rax
		shl rax, 2
		push rax
		invoke GlobalAlloc, 040h, rax
		mov [pString], rax
		pop rax
		mov wstrlen, eax
		invoke WideCharToMultiByte,0, 0, pArg, -1, pString, wstrlen, 0, 0
		jmp L1
@@:
		invoke lstrlen, pArg
		inc rax
		invoke GlobalAlloc, 040h, rax
		mov [pString], rax
		invoke lstrcpy, pString, pArg
L1:
	invoke lstrlen, pString
	add rax, 32
	invoke GlobalAlloc, 040h, rax
	mov [pMem], rax
	invoke RDBGFormatLine, rax, LineNum, pArgName
	invoke lstrcat, rax, pString
	invoke RDBGPrint2Output, pMem
	invoke GlobalFree, pMem
	invoke GlobalFree, pString
	RET
RDBGPrintString ENDP


;**************************************************************************
; RDBGFormatLine
;**************************************************************************
RDBGFormatLine PROC FRAME pAddress:QWORD, LineNum:QWORD, poptionarg:QWORD

	mov rax,[poptionarg]
	or rax,rax
	jz @F
	invoke wsprintf,[pAddress],OFFSET RDBG_szDbgLineFmt1,[LineNum],[poptionarg]
	jmp L1
@@:
	invoke wsprintf,[pAddress],OFFSET RDBG_szDbgLineFmt2,[LineNum]
L1:
	invoke lstrlen,[pAddress]
	add rax,[pAddress]

	RET

RDBGFormatLine ENDP


;**************************************************************************
; RDBGPrint2Output
;**************************************************************************
RDBGPrint2Output PROC FRAME pszText:QWORD
	LOCAL hRadAsm:HANDLE
	LOCAL hwnd:HANDLE
	LOCAL pid:DWORD
	LOCAL cbread:DWORD
	LOCAL hProcess:HANDLE
	LOCAL handlebuffer:ADDINHANDLES
	LOCAL cbWritten:DWORD
	LOCAL sui:STARTUPINFO
	LOCAL pi:PROCESS_INFORMATION
	LOCAL nAttempts:DWORD

	mov nAttempts, 0

	invoke FindWindow, Addr szRadASM30Class, 0
	or rax,rax
	jz NOTFOUND
	mov hRadAsm, rax

	invoke SendMessage, hRadAsm, AIM_DEBUGGETWIN, 0, 1
	mov hwnd, rax
	test rax, rax
	jnz @F

	invoke GetWindowThreadProcessId, hRadAsm, Addr pid
    ;mov rax, pid

	invoke OpenProcess, PROCESS_VM_READ, 0, pid ;pid
	mov hProcess, rax
	invoke SendMessage, hRadAsm, AIM_GETHANDLES, 0, 0
	;mov rax, eax
	invoke ReadProcessMemory, hProcess, rax, Addr handlebuffer, SIZEOF ADDINHANDLES, Addr cbread
	invoke CloseHandle, hProcess

	mov rax,[handlebuffer.hOutput]
	mov hwnd, rax
@@:

	invoke SendMessage,[hwnd],EM_SETSEL ,-1,-1
	invoke SendMessage,[hwnd],EM_REPLACESEL,0, Addr RDBG_crlf
	invoke SendMessage,[hwnd],EM_REPLACESEL,0, pszText
	invoke SendMessage,[hwnd],EM_SCROLLCARET ,0,0

EXIT:
	ret

WNDCREATEFAIL:
	invoke CloseHandle,[pi.hProcess]
	invoke CloseHandle,[pi.hThread]
PROCESSFAIL:
	mov [RDBG_ExceptLine], 0
	invoke GetLastError
	invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM, 0, eax, 0, Addr RDBG_ExceptLine, 127, 0
	invoke MessageBox, NULL, Addr RDBG_ExceptLine, Addr szErrorCreatingDebugWindow, NULL
	; The window cannot be created so continue the run without any output 
	mov RDBG_FNOWINDOW, TRUE
	ret

ATTACHFAIL:
	mov [RDBG_ExceptLine],0
	invoke MessageBox, NULL, Addr szFailedToAttachToOutputWindow, Addr szErrorCreatingDebugWindow, NULL
	; The window cannot be created so continue the run without any output 
	mov RDBG_FNOWINDOW, TRUE
	ret

NOTFOUND:
	cmp RDBG_FNOWINDOW, TRUE
	je EXIT
	invoke FindWindow, Addr szDbgWinClass, NULL
	mov hwnd, rax
	invoke GetDlgItem, hwnd, 1001
	mov hwnd, rax
	test rax, rax
	jnz @B

	inc nAttempts
	cmp nAttempts, 10
	jge ATTACHFAIL

	invoke RtlZeroMemory, Addr pi, SIZEOF PROCESS_INFORMATION
	invoke RtlZeroMemory, Addr sui,SIZEOF STARTUPINFO

	invoke CreateProcess, Addr RDBG_DbgWin, NULL, NULL, NULL, TRUE, NULL, NULL, NULL, Addr sui, Addr pi
	test rax,rax
	jz PROCESSFAIL
	; Wait until the process is initialized
	invoke WaitForInputIdle,[pi.hProcess],10000
	cmp rax, WAIT_TIMEOUT
	je WNDCREATEFAIL
	cmp rax, WAIT_FAILED
	je WNDCREATEFAIL
	invoke CloseHandle,[pi.hProcess]
	invoke CloseHandle,[pi.hThread]

	jmp NOTFOUND
    ret
	
RDBGPrint2Output ENDP


;**************************************************************************
; RDBGOC_QueryInterface
;**************************************************************************
RDBGOC_QueryInterface PROC FRAME this:QWORD, riid:QWORD, ppv:QWORD

	mov rax,[ppv]
	mov byte ptr [rax], 0

	invoke IsEqualGUID, [riid], offset RDBG_IID_IUnknown
	test rax,rax
	jz @F
		mov RAX, [this]
		mov RDX, [ppv]
		mov [RDX],RAX
		mov RAX, 0
		RET
@@:
	invoke IsEqualGUID, [riid], offset RDBG_IID_IDebugOutputCallbacks
	test rax,rax
	jz @F
		mov RAX, [this]
		mov RDX, [ppv]
		mov [RDX],RAX
		mov RAX, 0
		RET
@@:
	mov rax,E_NOINTERFACE
	ret
RDBGOC_QueryInterface ENDP


;**************************************************************************
; RDBGOC_AddRef
;**************************************************************************
RDBGOC_AddRef PROC FRAME this:QWORD
;	This is a static interface, it does not track instances
	xor rax,rax
	inc rax
	ret
RDBGOC_AddRef ENDP


;**************************************************************************
; RDBGOC_Release
;**************************************************************************
RDBGOC_Release PROC FRAME this:QWORD
;	This is a static interface, it does not track instances
	xor rax,rax
	ret
RDBGOC_Release ENDP


;**************************************************************************
; RDBGOC_Output
;**************************************************************************
RDBGOC_Output PROC FRAME USES RDI RSI this:QWORD, mask_:QWORD, text:QWORD
	;uses rdi,rsi

	mov rax, mask_
	test rax, DEBUG_OUTPUT_NORMAL
	jz SKIP
		; text sent to the ouput is delimited by 0x0A
		; so we have to parse the line before printing it
		invoke lstrlen,text
		mov rcx,rax
		mov rdi,[text]
		mov al, 00Ah
@@:
		mov rsi,rdi
		repne scasb
		mov BYTE PTR [rdi-1], 0
		push rcx
		push rax
		push rdi
		invoke RDBGPrint2Output, rsi
		pop rdi
		pop rax
		pop rcx
		cmp rcx, 0
		jg @B
SKIP:

	ret
RDBGOC_Output ENDP


;**************************************************************************
; RDBGPrintSpacer
;**************************************************************************
RDBGPrintSpacer PROC FRAME
	LOCAL pMem:HANDLE

	pushfq
	cld
	invoke GlobalAlloc, 040h, 128
	mov pMem,rax
	mov rdi, rax
	mov rcx, 5
	mov rax, "--------"
	rep stosq
	mov BYTE PTR [rdi], 0
	invoke RDBGPrint2Output, pMem
	invoke GlobalFree, pMem
	popfq

	RET
RDBGPrintSpacer ENDP


;**************************************************************************
; RDBGPrintNumber
;**************************************************************************
RDBGPrintNumber PROC FRAME USES RDI LineNum:QWORD, fOutType:QWORD, pArgName:QWORD, Arg:QWORD ; 0 = qword dec, 1 = qword hex, 2 = double, 3 = float, 4 = dword dec, 5 = dword hex
	;USES RDI
	LOCAL pMem:HANDLE
	LOCAL Double:QWORD
	LOCAL dpoint:QWORD
	LOCAL sign:QWORD
	LOCAL OutString[32]:BYTE

	invoke GlobalAlloc,040h,128
	mov pMem,rax
	invoke RDBGFormatLine, rax, LineNum, pArgName
	mov rdi,rax
	mov rax, fOutType
	or rax,rax
	jnz @F
		; QWORD DEC
		invoke RDBGi64toa, [Arg], rdi, 10
		lea rdi, OutString
		invoke lstrcpy, rdi, Addr szPrintNumber0x ;" (0x"
		add rdi, 4
		invoke RDBGi64toa, [Arg], rdi, 16
		invoke lstrcat, Addr OutString, Addr szPrintNumberRightBracket ;")"
		invoke lstrcat, pMem, Addr OutString
		jmp DONE
@@:
	cmp rax,1
	jne @F
		; QWORD HEX
		mov DWORD PTR [rdi], "0x"
		add rdi,2
		invoke RDBGi64toa, [Arg], rdi, 16
		jmp DONE
@@:
	cmp rax,2
	jne @F
		; DOUBLE (REAL8)
		invoke sprintf, rdi, Addr szPrintNumberFormatReal8, Arg ; "%.9f"
		jmp DONE
@@:
	cmp rax,3
	jne @F
		; FLOAT (REAL4)
		; Convert to DOUBLE
		CVTSS2SD XMM0, dword ptr [Arg]
		movd RAX,XMM0 ; movq bug?
		invoke sprintf, RDI, Addr szPrintNumberFormatReal4, RAX ; "%.6f"
		jmp DONE
@@:
	cmp rax,4
	jne @F
		; DWORD DEC
		mov rcx,[Arg]
		and rcx,0FFFFFFFFh
		invoke RDBGitoa, rcx, rdi, 10
		lea rdi, OutString
		invoke lstrcpy, rdi, Addr szPrintNumber0x ;" (0x"
		add rdi, 4
		invoke RDBGitoa, [Arg], rdi, 16
		invoke lstrcat, Addr OutString, Addr szPrintNumberRightBracket ;")"
		invoke lstrcat, pMem, Addr OutString
		jmp DONE
@@:
	cmp rax,5
	jne @F
		; DWORD HEX
		mov DWORD PTR [rdi],"0x"
		add rdi, 2
		mov rcx, [Arg]
		and rcx, 0FFFFFFFFh
		invoke RDBGitoa, rcx, rdi, 16
		jmp DONE
@@:
	cmp rax,6
	jne @F
		; WORD HEX
		mov DWORD PTR [rdi],"0x"
		add rdi, 2
		mov rcx, [Arg]
		invoke RDBGi16toa, rcx, rdi, 16
		jmp DONE
@@:
	cmp rax,7
	jne @F
		; BYTE HEX
		mov DWORD PTR [rdi],"0x"
		add rdi, 2
		mov rcx, [Arg]
		and rcx, 0FFh
		invoke RDBGi8toa, rcx, rdi, 16
		jmp DONE
@@:
	cmp rax,8
	jne @F
		; WORD DEC
		mov rcx,[Arg]
		invoke RDBGi16toa, rcx, rdi, 10
		lea rdi, OutString
		invoke lstrcpy, rdi, Addr szPrintNumber0x ;" (0x"
		add rdi, 4
		invoke RDBGi16toa, [Arg], rdi, 16
		invoke lstrcat, Addr OutString, Addr szPrintNumberRightBracket ;")"
		invoke lstrcat, pMem, Addr OutString
		jmp DONE
@@:
	cmp rax,9
	jne @F
		; BYTE DEC
		mov rcx,[Arg]
		invoke RDBGi8toa, rcx, rdi, 10
		lea rdi, OutString
		invoke lstrcpy, rdi, Addr szPrintNumber0x ;" (0x"
		add rdi, 4
		invoke RDBGi8toa, [Arg], rdi, 16
		invoke lstrcat, Addr OutString, Addr szPrintNumberRightBracket ;")"
		invoke lstrcat, pMem, Addr OutString
		jmp DONE
@@:

DONE:
	invoke RDBGPrint2Output, pMem
	invoke GlobalFree, pMem
	RET
RDBGPrintNumber ENDP



;**************************************************************************
; RDBGDumpHex
;**************************************************************************
RDBGDumpHex PROC FRAME USES RDI RSI RBX pStart:QWORD, nLength:QWORD, LineNum:QWORD
	;uses rdi,rsi,rbx
	LOCAL mbi:MEMORY_BASIC_INFORMATION
	LOCAL OutputLine[256]:BYTE
	LOCAL FinalLine[256]:BYTE
	LOCAL iLow:QWORD
	LOCAL iHigh:QWORD
	
	mov rdi, pStart
	test rdi, rdi
	jz ERROREXIT
	invoke VirtualQuery, rdi, Addr mbi,SIZEOF MEMORY_BASIC_INFORMATION
	test rax, rax
	jz ERROREXIT
	xor rax, rax
	mov eax, [mbi.Protect]
	cmp eax, 1
	je ERROREXIT
	; ok we have the memory and its not NOACCESS
	; 16 bytes per line

	invoke wsprintf, Addr FinalLine, Addr szHexDumpLine,  LineNum, nLength, pStart
	invoke RDBGPrint2Output, Addr FinalLine
	
	lea rsi, OutputLine
	mov r8, nLength
	add r8, pStart
	xor r9, r9
TOPLOOP:
		mov rax,[rdi]
		mov rdx,rax
		and rax,0Fh
		shr rdx,4
		and rdx,0Fh
		lea rbx, RDBG_HexLookup
		add rdx, rbx
		add rax, rbx
		;add rdx,offset RDBG_HexLookup
		;add rax,offset RDBG_HexLookup
		;add rdx,
		;lea rax, [RDBG_HexLookup+rax]
		;lea rdx, [RDBG_HexLookup+rdx]
		mov rax,[rax]
		mov rdx,[rdx]
		mov [rsi+1],al
		mov [rsi],dl
		mov BYTE PTR [rsi+2]," "
		mov BYTE PTR [rsi+3],0
		inc rdi
		add rsi,3
		inc r9
		cmp r9,16
		jne CONTINUE
			push RAX
			push RCX
			push RDX
			push R8
			push R9
			push R10
			push R11
			mov rsi,rdi
			sub RSI,16
			invoke wsprintf, Addr FinalLine, Addr szHexDumpFormat, RSI, Addr OutputLine
			;lea ebx, FinalLine
			;add rax, rbx
			lea rax, [FinalLine+rax]
			mov rcx, 16
INSERTCHAR:
				mov dl, [rsi]
				cmp dl, 20h
				jge NOSUB
					mov dl, "."
NOSUB:
				mov [rax],dl
				inc rax
				inc rsi
				dec rcx
				jnz INSERTCHAR
			mov BYTE PTR [rax], 0
			invoke RDBGPrint2Output, Addr FinalLine
			pop R11
			pop R10
			pop R9
			pop R8
			pop RDX
			pop RCX
			pop RAX
			xor r9, r9
			lea rsi, OutputLine
CONTINUE:
		cmp rdi, r8
		jl TOPLOOP
		mov rbx, nLength
		and rbx, 0Fh
		jz ERROREXIT
		mov RSI, RDI
		sub RSI, rbx
		invoke wsprintf, Addr FinalLine, Addr szHexDumpFormat, RSI, Addr OutputLine
		lea rax, [FinalLine+rax]
		; padd the rest of the line
		mov r10, 16
		sub r10, rbx
@@:
			mov DWORD PTR [rax], "    "
			add rax, 3
			dec r10
			jnz @B
		mov BYTE PTR [rax], 0
		mov rcx, rbx
INSERTCHAR2:
			mov dl, [rsi]
			cmp dl, 20h
			jge NOSUB2
				mov dl, "."
NOSUB2:
			mov [rax], dl
			inc rax
			inc rsi
			dec rcx
			jnz INSERTCHAR2
		mov BYTE PTR [rax], 0
		invoke RDBGPrint2Output, Addr FinalLine
EXIT:
	ret
ERROREXIT:
	ret
RDBGDumpHex ENDP


;**************************************************************************
; RDBGitoa
;**************************************************************************
RDBGitoa PROC FRAME USES RBX Value_:QWORD, pString:QWORD, Radix:QWORD
	;uses EBX

	; All parameters are 64 bit, a dword is required so
	; take the bottom 32 bits and sign extend to 64 bit
	MOV RAX, Value_
	MOVSXD RCX,EAX
	XOR EAX,EAX
	MOV RBX,pString
	; only base 10 has a sign
	CMP Radix,10
	JNE SETSIGN
	; If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE SETSIGN
	; If <0 then sign flag = 1
	inc eax
SETSIGN:
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
RDBGitoa ENDP


;**************************************************************************
; RDBGitoa
;**************************************************************************
RDBGi16toa PROC FRAME USES RBX Value:QWORD, pString:QWORD, Radix:QWORD
	;uses EBX

	; All parameters are 64 bit, a dword is required so
	; take the bottom 32 bits and sign extend to 64 bit
	MOV RAX,Value
	MOVSX RCX,AX
	XOR EAX,EAX
	MOV RBX,pString
	; only base 10 has a sign
	CMP Radix,10
	JNE SETSIGN
	; If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE SETSIGN
	; If <0 then sign flag = 1
	inc eax
SETSIGN:
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
RDBGi16toa ENDP


;**************************************************************************
; RDBGitoa
;**************************************************************************
RDBGi8toa PROC FRAME USES RBX Value:QWORD, pString:QWORD, Radix:QWORD
	;uses EBX

	; All parameters are 64 bit, a dword is required so
	; take the bottom 32 bits and sign extend to 64 bit
	MOV RAX,Value
	MOVSX RCX,AL
	XOR EAX,EAX
	MOV RBX,pString
	; only base 10 has a sign
	CMP Radix,10
	JNE SETSIGN
	; If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE SETSIGN
	; If <0 then sign flag = 1
	inc eax
SETSIGN:
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
RDBGi8toa ENDP


;**************************************************************************
; RDBGi64toa
;**************************************************************************
RDBGi64toa PROC FRAME USES RBX Value:QWORD, pString:QWORD, Radix:QWORD
	;uses EBX

	XOR EAX,EAX
	MOV RBX,pString
	; only base 10 has a sign
	CMP Radix,10
	JNE SETSIGN
	CMP Value,RAX
	JGE SETSIGN
	inc eax
SETSIGN:
	MOV R9D,EAX ; Sign
	;call RDBGConvertI64
	
	MOV R11D,R8D ; [Radix]
	MOV R10, RDX ; [pString]
	MOV RAX, RCX ; [Value]
	TEST R9D,R9D ; Sign flag
	JZ L0
	INC R10
	MOV BYTE PTR [RDX],"-"
	NEG RAX
L0:
	MOV R8,R10
	MOV RCX,R11
L1:
	XOR EDX,EDX
	DIV RCX
	CMP EDX,09h
	JBE L2
	ADD DL,057h
	JMP L3
L2:
	ADD DL,030h
L3:
	MOV [R10],DL
	INC R10
	TEST RAX,RAX
	JNZ L1
	MOV [R10],AL
	DEC R10
L4:
	MOV AL,[R8]
	MOV CL,[R10]
	MOV [R10],AL
	MOV [R8],CL
	INC R8
	DEC R10
	CMP R8,R10
	JB L4	
	
	MOV RAX,RBX
	RET
RDBGi64toa ENDP


;**************************************************************************
; RDBGConvertI64
;**************************************************************************
RDBGConvertI64 PROC

	MOV R11D,R8D ; [Radix]
	MOV R10, RDX ; [pString]
	MOV RAX, RCX ; [Value]
	TEST R9D,R9D ; Sign flag
	JZ L0
	INC R10
	MOV BYTE PTR [RDX],"-"
	NEG RAX
L0:
	MOV R8,R10
	MOV RCX,R11
L1:
	XOR EDX,EDX
	DIV RCX
	CMP EDX,09h
	JBE L2
	ADD DL,057h
	JMP L3
L2:
	ADD DL,030h
L3:
	MOV [R10],DL
	INC R10
	TEST RAX,RAX
	JNZ L1
	MOV [R10],AL
	DEC R10
L4:
	MOV AL,[R8]
	MOV CL,[R10]
	MOV [R10],AL
	MOV [R8],CL
	INC R8
	DEC R10
	CMP R8,R10
	JB L4
	RET
RDBGConvertI64 ENDP

































END
