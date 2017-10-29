
#include Debug64.h

BUFSIZE = 512

#IFNDEF GUID
GUID STRUCT
		Data1	dd
		Data2	dw
		Data3	dw
		Data4	db 8 DUP
ENDS
#ENDIF

#IFNDEF COMObject
// COM Object definition for the output interface
COMObject  STRUCT
	; interface object
	lpVtbl			DQ
	; object data
	nRefCount		DQ
ENDS
#ENDIF

QWORD_DEC = 0
QWORD_HEX = 1
DOUBLE_REAL8 = 2
FLOAT_REAL4 = 3
DWORD_DEC = 4
DWORD_HEX = 5
WORD_HEX = 6
BYTE_HEX = 7
WORD_DEC = 8
BYTE_DEC = 9

// Variable types for use with Spy
SPY_TYPE_FLOAT = 0
SPY_TYPE_DOUBLE = 1
SPY_TYPE_QWORD = 2
SPY_TYPE_DWORD = 3
SPY_TYPE_QWORDHEX = 4
SPY_TYPE_DWORDHEX = 5
SPY_TYPE_STRING = 6
SPY_TYPE_REGRAX = 7
SPY_TYPE_REGRBX = 8
SPY_TYPE_REGRCX = 9
SPY_TYPE_REGRDX = 10
SPY_TYPE_REGRSI = 11
SPY_TYPE_REGRDI = 12
SPY_TYPE_REGRSP = 13
SPY_TYPE_REGRBP = 14
SPY_TYPE_REGR8 = 15
SPY_TYPE_REGR9 = 16
SPY_TYPE_REGR10 = 17
SPY_TYPE_REGR11 = 18
SPY_TYPE_REGR12 = 19
SPY_TYPE_REGR13 = 20
SPY_TYPE_REGR14 = 21
SPY_TYPE_REGR15 = 22

AIM_DEBUGGETWIN	equ WM_USER+54

/*
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_HexLookup' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_HexLookup' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ModName' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ModName' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ModName' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ModName' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptionString' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_pIDebugControl' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IID_IDebugControl' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_pIDebugSymbols' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IID_IDebugSymbols' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IDbgOC' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_ExceptLine' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_pIDebugControl' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IID_IDebugControl' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_pIDebugSymbols' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IID_IDebugSymbols' invalid without /LARGEADDRESSAWARE:NO
Debug64.lib(Debug64.obj) : error LNK2017: 'ADDR32' relocation to 'RDBG_IDbgOC' invalid without /LARGEADDRESSAWARE:NO
*/

DATA SECTION
	RDBG_IID_IDebugClient GUID <0x27fe5639, 0x8407, 0x4f47, <0x83, 0x64, 0xee, 0x11, 0x8f, 0xb0, 0x8a, 0xc8>>
	RDBG_IID_IDebugControl GUID <0x5182e668, 0x105e, 0x416e, <0xad, 0x92, 0x24, 0xef, 0x80, 0x04, 0x24, 0xba>>
	RDBG_IID_IUnknown GUID <0x00000000,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
	RDBG_IID_IDebugOutputCallbacks GUID <0x4bf58045, 0xd654, 0x4c40, <0xb0, 0xaf, 0x68, 0x30, 0x90, 0xf3, 0x56, 0xdc>>
	RDBG_IID_IDebugSymbols GUID <0x8c31e98c, 0x983a, 0x48a5, <0x90, 0x16, 0x6f, 0xe5, 0xd6, 0x67, 0xa9, 0x50>>

	RDBG_szDbgFPU6			db "Exception  : e s p u o z d i",0

	RDBG_vtOutputCallbacks	DQ RDBGOC_QueryInterface
						DQ RDBGOC_AddRef
						DQ RDBGOC_Release
						DQ RDBGOC_Output

	RDBG_IDbgOC				COMObject <offset RDBG_vtOutputCallbacks,1>

	RDBG_ExceptionString	DB	64 DUP (0)
	RDBG_ExceptLine			CHAR MAX_PATH*2 DUP (0)
	RDBG_ModName			CHAR MAX_PATH DUP (0)

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

CODE SECTION

#include msvcfunc.asm

RDBGFormatLine FRAME pAddress, LineNum, poptionarg

	mov rax,[poptionarg]
	or rax,rax
	jz >
	invoke wsprintf,[pAddress],OFFSET RDBG_szDbgLineFmt1,[LineNum],[poptionarg]
	jmp >L1
	:
	invoke wsprintf,[pAddress],OFFSET RDBG_szDbgLineFmt2,[LineNum]
	L1:
	invoke lstrlen,[pAddress]
	add rax,[pAddress]

	RET
	RDBG_szDbgLineFmt1:		DB "Line %u: %s",0
	RDBG_szDbgLineFmt2:		DB "Line %u: ",0
ENDF

RDBGPrint2Output FRAME pszText
	LOCAL hRadAsm	:%HANDLE
	LOCAL hwnd		:%HANDLE
	LOCAL pid		:%UINT_PTR
	LOCAL cbread	:%UINT_PTR
	LOCAL hProcess	:%HANDLE
	LOCAL handlebuffer:ADDINHANDLES
	LOCAL cbWritten	:D
	LOCAL sui		:STARTUPINFO
	LOCAL pi		:PROCESS_INFORMATION
	LOCAL nAttempts	:D

	mov D[nAttempts],0

	invoke FindWindow,"RadASM30Class",0
	or rax,rax
	jz >>.NOTFOUND
	mov [hRadAsm],rax

	invoke SendMessage,[hRadAsm],AIM_DEBUGGETWIN,0,1
	mov [hwnd],rax
	test rax,rax
	jnz >>

	invoke GetWindowThreadProcessId,[hRadAsm],offset pid

	invoke OpenProcess,PROCESS_VM_READ,0,[pid]
	mov [hProcess],rax
	invoke SendMessage,[hRadAsm],AIM_GETHANDLES,0,0
	mov rax,eax
	invoke ReadProcessMemory,[hProcess],rax,offset handlebuffer,SIZEOF ADDINHANDLES,offset cbread
	invoke CloseHandle,[hProcess]

	mov rax,[handlebuffer.hOutput]
	mov [hwnd],rax
	:

	invoke SendMessage,[hwnd],EM_SETSEL ,-1,-1
	invoke SendMessage,[hwnd],EM_REPLACESEL,0,offset RDBG_crlf
	invoke SendMessage,[hwnd],EM_REPLACESEL,0,[pszText]
	invoke SendMessage,[hwnd],EM_SCROLLCARET ,0,0

	.EXIT
	ret

	.WNDCREATEFAIL
	invoke CloseHandle,[pi.hProcess]
	invoke CloseHandle,[pi.hThread]
	.PROCESSFAIL
	mov D[RDBG_ExceptLine],0
	invoke GetLastError
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,0,rax,0,OFFSET RDBG_ExceptLine,127,0
	invoke MessageBox,NULL,OFFSET RDBG_ExceptLine,"Error creating debug window",NULL
	// The window cannot be created so continue the run without any output 
	mov D[RDBG_FNOWINDOW],TRUE
	ret

	.ATTACHFAIL
	mov D[RDBG_ExceptLine],0
	invoke MessageBox,NULL,"Failed to attach to output window","Error creating debug window",NULL
	// The window cannot be created so continue the run without any output 
	mov D[RDBG_FNOWINDOW],TRUE
	ret

	.NOTFOUND
	cmp D[RDBG_FNOWINDOW],TRUE
	je .EXIT
	invoke FindWindow,"DbgWinClass",NULL
	mov [hwnd],rax
	invoke GetDlgItem,[hwnd],1001
	mov [hwnd],rax
	test rax,rax
	jnz <<

	inc D[nAttempts]
	cmp D[nAttempts],10
	jge .ATTACHFAIL

	invoke RtlZeroMemory,offset pi,SIZEOF PROCESS_INFORMATION
	invoke RtlZeroMemory,offset sui,SIZEOF STARTUPINFO

	invoke CreateProcess,offset RDBG_DbgWin,NULL,NULL,NULL,TRUE,NULL,NULL,NULL,OFFSET sui,OFFSET pi
	test rax,rax
	jz .PROCESSFAIL
	// Wait until the process is initialized
	invoke WaitForInputIdle,[pi.hProcess],10000
	cmp rax,WAIT_TIMEOUT
	je .WNDCREATEFAIL
	cmp rax,WAIT_FAILED
	je .WNDCREATEFAIL
	invoke CloseHandle,[pi.hProcess]
	invoke CloseHandle,[pi.hThread]

	jmp .NOTFOUND

	RDBG_crlf:	SCHAR	13,10,0
endf

RDBGPrintString FRAME LineNum,pArg,pArgName,szType
	LOCAL pMem		:%HANDLE
	LOCAL pString	:%HANDLE

	cmp D[szType],1
	jne >
		invoke lstrlenW,[pArg]
		inc rax
		shl rax,2
		push rax
		invoke GlobalAlloc,040h,rax
		mov [pString],rax
		pop rax
		invoke WideCharToMultiByte,0,0,[pArg],-1,[pString],rax,0,0
		jmp >L1
	:
		invoke lstrlen,[pArg]
		inc rax
		invoke GlobalAlloc,040h,rax
		mov [pString],rax
		invoke lstrcpy,[pString],[pArg]
	L1:
	invoke lstrlen,[pString]
	add rax,32
	invoke GlobalAlloc,040h,rax
	mov [pMem],rax
	invoke RDBGFormatLine,rax,[LineNum],[pArgName]
	invoke lstrcat,rax,[pString]
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]
	invoke GlobalFree,[pString]
	RET
ENDF

RDBGPrintError FRAME LineNum
	uses rdi
	LOCAL pMem			:%HANDLE

	invoke GlobalAlloc,040h,128
	mov [pMem],rax
	invoke GetLastError
	mov rdi,rax
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,0,rdi,0,OFFSET RDBG_ExceptLine,127,0
	invoke wsprintf,[pMem],"Line %u: Error %u > %s",[LineNum],rdi,OFFSET RDBG_ExceptLine
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]

	RET
ENDF

RDBGPrintErrorByNum FRAME LineNum,OleError
	uses rdi
	LOCAL pMem			:%HANDLE

	mov rdi,[OleError]
	invoke GlobalAlloc,040h,128
	mov [pMem],rax
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,0,rdi,0,OFFSET RDBG_ExceptLine,127,0
	invoke wsprintf,[pMem],"Line %u: Error 0x%X > %s",[LineNum],rdi,OFFSET RDBG_ExceptLine
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]

	RET
ENDF

RDBGPrintNumber FRAME LineNum,fOutType,pArgName,Arg ; 0 = qword dec, 1 = qword hex, 2 = double, 3 = float, 4 = dword dec, 5 = dword hex
	USES RDI
	LOCAL pMem		:%HANDLE
	LOCAL Double	:Q
	LOCAL dpoint	:Q
	LOCAL sign		:Q
	LOCAL OutString[32]:B

	invoke GlobalAlloc,040h,128
	mov [pMem],rax
	invoke RDBGFormatLine,rax,[LineNum],[pArgName]
	mov rdi,rax
	mov rax,[fOutType]
	or rax,rax
	jnz >>
		// QWORD DEC
		invoke RDBGi64toa,[Arg],rdi,10
		lea rdi,OutString
		invoke lstrcpy,rdi," (0x"
		add rdi,4
		invoke RDBGi64toa,[Arg],rdi,16
		invoke lstrcat,offset OutString,")"
		invoke lstrcat,[pMem],offset OutString
		jmp >>.DONE
	:
	cmp rax,1
	jne >
		//QWORD HEX
		mov D[rdi],"0x"
		add rdi,2
		invoke RDBGi64toa,[Arg],rdi,16
		jmp >>.DONE
	:
	cmp rax,2
	jne >
		// DOUBLE (REAL8)
		invoke sprintf,rdi,"%.9f",[Arg]
		jmp >>.DONE
	:
	cmp rax,3
	jne >>
		// FLOAT (REAL4)
		// Convert to DOUBLE
		CVTSS2SD XMM0,[Arg]
		movq RAX,XMM0
		invoke sprintf,RDI,"%.6f",RAX
		jmp >>.DONE
	:
	cmp rax,4
	jne >>
		// DWORD DEC
		mov rcx,[Arg]
		and rcx,0xFFFFFFFF
		invoke RDBGitoa,rcx,rdi,10
		lea rdi,OutString
		invoke lstrcpy,rdi," (0x"
		add rdi,4
		invoke RDBGitoa,[Arg],rdi,16
		invoke lstrcat,offset OutString,")"
		invoke lstrcat,[pMem],offset OutString
		jmp >>.DONE
	:
	cmp rax,5
	jne >>
		// DWORD HEX
		mov D[rdi],"0x"
		add rdi,2
		mov rcx,[Arg]
		and rcx,0xFFFFFFFF
		invoke RDBGitoa,rcx,rdi,16
		jmp >>.DONE
	:
	cmp rax,6
	jne >>
		// WORD HEX
		mov D[rdi],"0x"
		add rdi,2
		mov rcx,[Arg]
		invoke RDBGi16toa,rcx,rdi,16
		jmp >>.DONE
	:
	cmp rax,7
	jne >>
		// BYTE HEX
		mov D[rdi],"0x"
		add rdi,2
		mov rcx,[Arg]
		and rcx,0xFF
		invoke RDBGi8toa,rcx,rdi,16
		jmp >>.DONE
	:
	cmp rax,8
	jne >>
		// WORD DEC
		mov rcx,[Arg]
		invoke RDBGi16toa,rcx,rdi,10
		lea rdi,OutString
		invoke lstrcpy,rdi," (0x"
		add rdi,4
		invoke RDBGi16toa,[Arg],rdi,16
		invoke lstrcat,offset OutString,")"
		invoke lstrcat,[pMem],offset OutString
		jmp >>.DONE
	:
	cmp rax,9
	jne >>
		// BYTE DEC
		mov rcx,[Arg]
		invoke RDBGi8toa,rcx,rdi,10
		lea rdi,OutString
		invoke lstrcpy,rdi," (0x"
		add rdi,4
		invoke RDBGi8toa,[Arg],rdi,16
		invoke lstrcat,offset OutString,")"
		invoke lstrcat,[pMem],offset OutString
		jmp >>.DONE
	:

	.DONE
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]
	RET
ENDF

RDBGPrintSpacer FRAME
	LOCAL pMem		:%HANDLE

	pushfq
	cld
	invoke GlobalAlloc,040h,128
	mov [pMem],rax
	mov rdi,rax
	mov rcx,5
	mov rax,"--------"
	rep stosq
	mov Q[rdi],0
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]
	popfq

	RET
ENDF

RDBGDumpEFlags FRAME LineNum,eflagdata
	USES RDI
	LOCAL pdbbuf	:%HANDLE
	LOCAL buffer[256]:%CHAR

	invoke GlobalAlloc,040h,128
	mov [pdbbuf],rax

	// Eflags are dumped as part of the Try function
	// there is no need for a line number in that case
	// so don't add one if line number = -1
	cmp D[LineNum],-1
	je >
	invoke RDBGFormatLine,[pdbbuf],[LineNum],"EFLAGS ="
	jmp >.DECODEFLAGS
	:
	invoke lstrcpy,[pdbbuf],"EFLAGS ="
	add rax,8

	.DECODEFLAGS
	push rax
	lea rdi,buffer

	mov B[rdi],0
	mov eax,[eflagdata]
	bt rax,0
	jnc >
	mov D[rdi],A" CF"
	add rdi,3
	:
	bt rax,2
	jnc >
	mov D[rdi],A" PF"
	add rdi,3
	:
	bt rax,4
	jnc >
	mov D[rdi],A" AF"
	add rdi,3
	:
	bt rax,6
	jnc >
	mov D[rdi],A" ZF"
	add rdi,3
	:
	bt rax,7
	jnc >
	mov D[rdi],A" SF"
	add rdi,3
	:
	bt rax,8
	jnc >
	mov D[rdi],A" TF"
	add rdi,3
	:
	bt rax,9
	jnc >
	mov D[rdi],A" IF"
	add rdi,3
	:
	bt rax,10
	jnc >
	mov D[rdi],A" DF"
	add rdi,3
	:
	bt rax,11
	jnc >
	mov D[rdi],A" OF"
	add rdi,3
	:
	mov B[rdi],0

	pop rax

	invoke lstrcpy,rax,offset buffer

	invoke RDBGPrint2Output,[pdbbuf]
	invoke GlobalFree,[pdbbuf]

	RET

ENDF

RDBGDumpHex FRAME pStart, Length, LineNum
	uses rdi,rsi,rbx
	LOCAL mbi:MEMORY_BASIC_INFORMATION
	LOCAL OutputLine[256]:%TCHAR
	LOCAL FinalLine[256]:%TCHAR
	LOCAL iLow:Q
	LOCAL iHigh:Q
	
	mov rdi,[pStart]
	test rdi,rdi
	jz >>.ERROR
	invoke VirtualQuery,rdi,offset mbi,SIZEOF MEMORY_BASIC_INFORMATION
	test rax,rax
	jz >>.ERROR
	mov rax,[mbi.Protect]
	cmp rax,1
	je >>.ERROR
	// ok we have the memory and its not NOACCESS
	// 16 bytes per line

	invoke wsprintf,offset FinalLine,"Line %u : Hex dump of %u bytes at address 0x%p",[LineNum],[Length],[pStart]
	invoke RDBGPrint2Output,offset FinalLine
	
	mov rsi,offset OutputLine
	mov r8,[Length]
	add r8,[pStart]
	xor r9,r9
	.TOPLOOP
		mov rax,[rdi]
		mov rdx,rax
		and rax,0xF
		shr rdx,4
		and rdx,0xF
		add rdx,offset RDBG_HexLookup
		add rax,offset RDBG_HexLookup
		mov rax,[rax]
		mov rdx,[rdx]
		mov B[rsi+1],al
		mov B[rsi],dl
		mov B[rsi+2]," "
		mov B[rsi+3],0
		inc rdi
		add rsi,3
		inc r9
		cmp r9,16
		jne >>.CONTINUE
			push RAX,RCX,RDX,R8,R9,R10,R11
			mov rsi,rdi
			sub RSI,16
			invoke wsprintf,offset FinalLine,"%p: %s",RSI,offset OutputLine
			lea rax,[FinalLine+rax]
			mov rcx,16
			.INSERTCHAR
				mov dl,[rsi]
				cmp dl,20h
				jge >.NOSUB
					mov dl,"."
				.NOSUB
				mov [rax],dl
				inc rax
				inc rsi
				dec rcx
				jnz .INSERTCHAR
			mov B[rax],0
			invoke RDBGPrint2Output,offset FinalLine
			pop R11,R10,R9,R8,RDX,RCX,RAX
			xor r9,r9
			mov rsi,offset OutputLine
		.CONTINUE
		cmp rdi,r8
		jl .TOPLOOP
		mov rbx,[Length]
		and rbx,0xF
		jz >>.EXIT
		mov RSI,RDI
		sub RSI,rbx
		invoke wsprintf,offset FinalLine,"%p: %s",RSI,offset OutputLine
		lea rax,[FinalLine+rax]
		// padd the rest of the line
		mov r10,16
		sub r10,rbx
		:
			mov D[rax],"    "
			add rax,3
			dec r10
			jnz <
		mov B[rax],0
		mov rcx,rbx
		.INSERTCHAR2
			mov dl,[rsi]
			cmp dl,20h
			jge >.NOSUB2
				mov dl,"."
			.NOSUB2
			mov [rax],dl
			inc rax
			inc rsi
			dec rcx
			jnz .INSERTCHAR2
		mov B[rax],0
		invoke RDBGPrint2Output,offset FinalLine
		.EXIT
	ret
	.ERROR
	ret
endf

RDBGGetHandler FRAME
	LOCAL dummy:Q
	mov rax,offset RDBGVectoredHandler
	ret
endf

RDBGVectoredHandler FRAME pExcptPointers
	uses rbx,rdi,rsi,r15

	invoke RDBGPrintSpacer
	invoke lstrcpy,offset RDBG_ExceptLine,"Empty"

	mov rdi,[pExcptPointers]
	mov rdi,[rdi]

	xor rbx,rbx
	mov ebx,[rdi+EXCEPTION_RECORD64.ExceptionCode]
	mov rsi,[rdi+EXCEPTION_RECORD64.ExceptionAddress]

	invoke GetCurrentProcess
	invoke RDBGGetModuleByAddr,rax,rsi,offset RDBG_ModName

	invoke RDBGGetExceptName,rbx
	mov r15,rax

	// Special handlers for ;0C0000006h ;0C0000005h
	cmp ebx,0C0000006h // EXCEPTION_IN_PAGE_ERROR
	je >>.SPECIALCASE
	cmp ebx,0C0000005h // EXCEPTION_ACCESS_VIOLATION
	jne >>.EXIT
		.SPECIALCASE

		mov r10,[rdi+EXCEPTION_RECORD64.ExceptionInformation]
		mov r11,[rdi+EXCEPTION_RECORD64.ExceptionInformation+8]

		cmp r10,1
		jne >>
			invoke wsprintf,offset RDBG_ExceptLine,"%s encountered at address %p in %s writing to %p",r15,rsi,offset RDBG_ModName,r11
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXTRAS
		:
		cmp r10,0
		jne >>
			invoke wsprintf,offset RDBG_ExceptLine,"%s encountered at address %p in %s reading from %p",r15,rsi,offset RDBG_ModName,r11
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXTRAS
		:
		cmp r10,8
		jne >>
			invoke wsprintf,offset RDBG_ExceptLine,"%s encountered at address %p in %s DEP violation at %p",r15,rsi,offset RDBG_ModName,r11
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXTRAS
		:

	.EXIT

	invoke wsprintf,offset RDBG_ExceptLine,"%s encountered at address %p in module %s",r15,rsi,offset RDBG_ModName
	invoke RDBGPrint2Output,offset RDBG_ExceptLine
	
	.EXTRAS
	mov rdi,[pExcptPointers]
	mov rbx,[rdi+EXCEPTION_POINTERS.ContextRecord]

	invoke RDBGPrintSpacer
	invoke RDBGPrint2Output,"Registers"
	invoke RDBGPrintSpacer

	invoke wsprintf,offset RDBG_ExceptLine,offset RDBG_RegDump1,[rbx+CONTEXT.Rax],[rbx+CONTEXT.Rbx],[rbx+CONTEXT.Rcx],[rbx+CONTEXT.Rdx]
	invoke RDBGPrint2Output,offset RDBG_ExceptLine
	invoke wsprintf,offset RDBG_ExceptLine,offset RDBG_RegDump2,[rbx+CONTEXT.Rsi],[rbx+CONTEXT.Rdi],[rbx+CONTEXT.Rbp],[rbx+CONTEXT.Rsp]
	invoke RDBGPrint2Output,offset RDBG_ExceptLine
	invoke wsprintf,offset RDBG_ExceptLine,offset RDBG_RegDump3,[rbx+CONTEXT.R8],[rbx+CONTEXT.R9],[rbx+CONTEXT.R10],[rbx+CONTEXT.R11]
	invoke RDBGPrint2Output,offset RDBG_ExceptLine
	invoke wsprintf,offset RDBG_ExceptLine,offset RDBG_RegDump4,[rbx+CONTEXT.R12],[rbx+CONTEXT.R13],[rbx+CONTEXT.R14],[rbx+CONTEXT.R15]
	invoke RDBGPrint2Output,offset RDBG_ExceptLine

	invoke RDBGPrintSpacer
	invoke RDBGDumpEFlags,-1,[rbx+CONTEXT.EFlags]
	invoke RDBGPrintSpacer

	invoke RDBGDumpStack,rbx

	invoke ExitProcess,0
	mov rax,0
	ret

	RDBG_RegDump1:	DB	"RAX %p RBX %p RCX %p RDX %p",0
	RDBG_RegDump2:	DB	"RSI %p RDI %p RBP %p RSP %p",0
	RDBG_RegDump3:	DB	"R8  %p R9  %p R10 %p R11 %p",0
	RDBG_RegDump4:	DB	"R12 %p R13 %p R14 %p R15 %p",0

endf

RDBGGetExceptName FRAME ExCode
	mov eax, [ExCode]
	
	cmp eax,0x080000001
	jne >
		mov rax,OFFSET "EXCEPTION_GUARD_PAGE"
		jmp >>.exit
	:
	cmp eax,0x080000002
	jne >
		mov rax,OFFSET "EXCEPTION_DATATYPE_MISALIGNMENT"
		jmp >>.exit
	:
	cmp eax,0x080000003
	jne >
		mov rax,OFFSET "EXCEPTION_BREAKPOINT"
		jmp >>.exit
	:
	cmp eax,0x080000004
	jne >
		mov rax,OFFSET "EXCEPTION_SINGLE_STEP"
		jmp >>.exit
	:
	cmp eax,0x0C0000005
	jne >
		mov rax,OFFSET "EXCEPTION_ACCESS_VIOLATION"
		jmp >>.exit
	:
	cmp eax,0x0C0000006
	jne >
		mov rax,OFFSET "EXCEPTION_IN_PAGE_ERROR"
		jmp >>.exit
	:
	cmp eax,0x0C0000008
	jne >
		mov rax,OFFSET "EXCEPTION_INVALID_HANDLE"
		jmp >>.exit
	:
	cmp eax,0x0C000001D
	jne >
		mov rax,OFFSET "EXCEPTION_ILLEGAL_INSTRUCTION"
		jmp >>.exit
	:
	cmp eax,0x0C0000025
	jne >
		mov rax,OFFSET "EXCEPTION_NONCONTINUABLE_EXCEPTION"
		jmp >>.exit
	:
	cmp eax,0x0C0000026
	jne >
		mov rax,OFFSET "EXCEPTION_INVALID_DISPOSITION"
		jmp >>.exit
	:
	cmp eax,0x0C000008C
	jne >
		mov rax,OFFSET "EXCEPTION_ARRAY_BOUNDS_EXCEEDED"
		jmp >>.exit
	:
	cmp eax,0x0C000008D
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_DENORMAL_OPERAND"
		jmp >>.exit
	:
	cmp eax,0x0C000008E
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_DIVIDE_BY_ZERO"
		jmp >>.exit
	:
	cmp eax,0x0C000008F
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_INEXACT_RESULT"
		jmp >>.exit
	:
	cmp eax,0x0C0000090
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_INVALID_OPERATION"
		jmp >>.exit
	:
	cmp eax,0x0C0000091
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_OVERFLOW"
		jmp >>.exit
	:
	cmp eax,0x0C0000092
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_STACK_CHECK"
		jmp >>.exit
	:
	cmp eax,0x0C0000093
	jne >
		mov rax,OFFSET "EXCEPTION_FLT_UNDERFLOW"
		jmp >>.exit
	:
	cmp eax,0x0C0000094
	jne >
		mov rax,OFFSET "EXCEPTION_INT_DIVIDE_BY_ZERO"
		jmp >>.exit
	:
	cmp eax,0x0C0000095
	jne >
		mov rax,OFFSET "EXCEPTION_INT_OVERFLOW"
		jmp >>.exit
	:
	cmp eax,0x0C0000096
	jne >
		mov rax,OFFSET "EXCEPTION_PRIV_INSTRUCTION"
		jmp >>.exit
	:
	cmp eax,0x0C00000FD
	jne >
		mov rax,OFFSET "EXCEPTION_STACK_OVERFLOW"
		jmp >>.exit
	:
	cmp eax,0x0C000013A
	jne >
		mov rax,OFFSET "CONTROL_C_EXIT"
		jmp >>.exit
	:
	cmp eax,0x0C0000194
	jne >
		mov rax,OFFSET "EXCEPTION_POSSIBLE_DEADLOCK"
		jmp >>.exit
	:
		CInvoke(wsprintf,offset RDBG_ExceptionString,"Unknown exception - code 0x%0.8X",eax)
		mov eax,OFFSET RDBG_ExceptionString
	.exit
	ret
endf

RDBGFPUDump FRAME LineNum
	uses rsi,rdi,rbx
	LOCAL sts		:W
	LOCAL pad		:W
	LOCAL lev		:D
	LOCAL stks[8]	:T
	LOCAL pdbbuf	:%HANDLE
	LOCAL pdbbuf1	:%HANDLE

	invoke GlobalAlloc,040h,256
	mov [pdbbuf],rax
	add rax,128
	mov [pdbbuf1],rax

	invoke RDBGPrintSpacer
	invoke RDBGFormatLine,[pdbbuf],[LineNum],"FPU Dump"
	invoke RDBGPrint2Output,[pdbbuf]
	invoke RDBGPrintSpacer
	invoke RtlZeroMemory,[pdbbuf],256

	fstsw W[sts]

	xor eax, eax
	mov ax, [sts]
	shr eax, 11
	neg eax
	and eax, 7
	mov [lev], eax
	or eax,eax
	jnz >L1
		fst Q[stks]
		fstsw ax
		and ax,41h
		jz >
			mov D[lev], 0
			jmp >L13
		:
			mov D[lev], 8
		L13:
	L1:

	invoke wsprintf, [pdbbuf], "FPU Levels : %d ", [lev]
	invoke RDBGPrint2Output, [pdbbuf]

	xor eax, eax
	mov ax, [sts]
	shr eax, 6
	shl al, 3
	shl ax, 1
	shl al, 1
	shr eax, 7
	and eax, 7
	or eax,eax
	jnz >
		invoke RDBGPrint2Output, "Conditional: ST > Source"
		jmp >L2
	:
	cmp eax,1
	jne >
		invoke RDBGPrint2Output, "Conditional: ST < Source"
		jmp >L2
	:
	cmp eax,4
	jne >
		invoke RDBGPrint2Output, "Conditional: ST = Source"
		jmp >L2
	:
		invoke RDBGPrint2Output, "Conditional: Undefined"
	L2:


	xor eax, eax
	xor ecx, ecx
	mov ax,[sts]
	mov rdx, OFFSET RDBG_szDbgFPU6
	add rdx, 13
	jmp >L3
	L4:
		rol al,1
		jc >
			or B[rdx],20h
			jmp >L5
		:
			and B[rdx],0DFh
		L5:
		add rdx,2
		inc ecx
	L3:
	cmp ecx,8
	jl <L4

	invoke RDBGPrint2Output,offset RDBG_szDbgFPU6

	xor esi, esi
	xor eax,eax
	lea rdi, stks
	jmp >L6
     L7:
     	fstp Q[edi +esi*8]
     	inc esi
	L6:
	cmp esi,[lev]
	jl <L7

	xor esi, esi

	jmp >>L8
	L9:
		invoke sprintf,[pdbbuf1],"%.9f",[edi +esi*8]
		invoke lstrlen,[pdbbuf1]
		cmp eax,1
		jne >
			mov eax,[pdbbuf1]
			mov D[eax],"0.00"
			mov B[eax+4],0
		:
		invoke lstrcat,[pdbbuf1],"0000000000000000000"
		invoke wsprintf, [pdbbuf], "St(%d)      : %.16s",esi, [pdbbuf1]
		invoke RDBGPrint2Output, [pdbbuf]
		inc esi
	L8:
	cmp esi,[lev]
	jl <<L9

	mov esi, [lev]
	dec esi

	cmp esi,0
	jle >L10
		jmp >L11
		L12:
			fld Q[edi +esi*8]
			dec esi
		L11:
		cmp esi,0
		jge <L12
	L10:

	invoke GlobalFree,[pdbbuf]

	invoke RDBGPrintSpacer
     ret

endf

RDBGMMXDump FRAME LineNum
	uses rdi,rsi,rbx
	LOCAL pMem		:%HANDLE
	LOCAL tempq		:Q

	mov Q[tempq],0

	invoke GlobalAlloc,040h,256
	mov [pMem],eax

	invoke RDBGPrintSpacer
	invoke RDBGFormatLine,[pMem],[LineNum],"MMX register dump"
	invoke RDBGPrint2Output,[pMem]
	invoke RDBGPrintSpacer

	mov rax,[pMem]
	mov D[rax],A"MM0 "
	mov D[rax+4],A"= "

	movq [tempq],mm0
	mov rax,[pMem]
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm1
	mov rax,[pMem]
	mov B[eax+2],"1"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm2
	mov rax,[pMem]
	mov B[eax+2],"2"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm3
	mov rax,[pMem]
	mov B[eax+2],"3"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm4
	mov rax,[pMem]
	mov B[eax+2],"4"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm5
	mov rax,[pMem]
	mov B[eax+2],"5"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm6
	mov rax,[pMem]
	mov B[eax+2],"6"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	movq [tempq],mm7
	mov rax,[pMem]
	mov B[eax+2],"7"
	add rax,6
	invoke RDBGi64toa,[tempq],rax,16
	invoke RDBGPrint2Output,[pMem]

	invoke GlobalFree,[pMem]
	emms

	invoke RDBGPrintSpacer
	RET
ENDF

RDBGGetSpy FRAME
	LOCAL dummy:Q
	mov rax,offset RDBGSpy
	ret
endf

RDBGSpy FRAME pExcptPointers
	uses rbx,rdi,rsi
	LOCAL dpoint	:Q
	LOCAL sign		:Q

	mov rdi,[pExcptPointers]
	mov rsi,[rdi+EXCEPTION_POINTERS.ContextRecord] // Pointer to context structure
	mov rdi,[rdi+EXCEPTION_POINTERS.ExceptionRecord] // Pointer to exception record

	xor rbx,rbx
	mov ebx,[rdi+EXCEPTION_RECORD64.ExceptionCode]
	mov rax,[rdi+EXCEPTION_RECORD64.ExceptionAddress]

	// Check for single step
	cmp ebx,EXCEPTION_SINGLE_STEP
	jne >>.STARTSINGLESTEP
		.PRINTSPY
		lea rbx,RDBG_ExceptLine
		invoke wsprintf,RBX,"0x%p: %s = ",RAX,offset RDBG_SPYVARNAME
		add rbx, rax

		mov rax,[RDBG_SPYVARADDR]
		// output
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_FLOAT
		jne >>.DOUBLE
			CVTSS2SD XMM0,[RAX]
			movq RAX,XMM0
			invoke sprintf,RBX,"%.6f",RAX
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.DOUBLE
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_DOUBLE
		jne >>.QWORD
			invoke sprintf,rbx,"%.9f",[RAX]
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.QWORD
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_QWORD
		jne >>.QWORDHEX
			invoke RDBGi64toa,[RAX],rbx,10
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.QWORDHEX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_QWORDHEX
		jne >>.DWORD
			mov D[rbx],"0x"
			add rbx,2
			invoke RDBGi64toa,[RAX],rbx,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.DWORD
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_DWORD
		jne >>.DWORDHEX
			invoke RDBGitoa,[RAX],rbx,10
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.DWORDHEX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_DWORDHEX
		jne >>.STRING
			mov D[rbx],"0x"
			add rbx,2
			invoke RDBGitoa,[RAX],rbx,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.STRING
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_STRING
		jne >>.CHECKREGISTERS
			invoke lstrcat,offset RDBG_ExceptLine,RAX
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.CHECKREGISTERS
		lea rbx,RDBG_ExceptLine
		mov rax,[rdi+EXCEPTION_RECORD64.ExceptionAddress]

		.REGRAX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRAX
		jne >>.REGRBX
			invoke wsprintf,RBX,"0x%p: RAX = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rax],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRBX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRBX
		jne >>.REGRCX
			invoke wsprintf,RBX,"0x%p: RBX = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rbx],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRCX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRCX
		jne >>.REGRDX
			invoke wsprintf,RBX,"0x%p: RCX = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rcx],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRDX
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRDX
		jne >>.REGRDI
			invoke wsprintf,RBX,"0x%p: RBX = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rdx],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRDI
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRDI
		jne >>.REGRSI
			invoke wsprintf,RBX,"0x%p: RDI = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rdi],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRSI
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRSI
		jne >>.REGRSP
			invoke wsprintf,RBX,"0x%p: RSI = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rsi],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRSP
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRSP
		jne >>.REGRBP
			invoke wsprintf,RBX,"0x%p: RSP = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rsp],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGRBP
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGRBP
		jne >>.REGR8
			invoke wsprintf,RBX,"0x%p: RBP = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.Rbp],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR8
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR8
		jne >>.REGR9
			invoke wsprintf,RBX,"0x%p: R8 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R8],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR9
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR9
		jne >>.REGR10
			invoke wsprintf,RBX,"0x%p: R9 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R9],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR10
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR10
		jne >>.REGR11
			invoke wsprintf,RBX,"0x%p: R10 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R10],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR11
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR11
		jne >>.REGR12
			invoke wsprintf,RBX,"0x%p: R11 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R11],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR12
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR12
		jne >>.REGR13
			invoke wsprintf,RBX,"0x%p: R12 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R12],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR13
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR13
		jne >>.REGR14
			invoke wsprintf,RBX,"0x%p: R13 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R13],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR14
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR14
		jne >>.REGR15
			invoke wsprintf,RBX,"0x%p: R14 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R14],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine
			jmp >>.EXIT

		.REGR15
		cmp Q[RDBG_SPYVARTYPE], SPY_TYPE_REGR15
		jne >>.EXIT
			invoke wsprintf,RBX,"0x%p: R15 = 0x",RAX
			add rax,rbx
			invoke RDBGi64toa,[rsi+CONTEXT.R15],rax,16
			invoke RDBGPrint2Output,offset RDBG_ExceptLine

		.EXIT
			// Reset single step
			or D[rsi+CONTEXT.EFlags],0x100
			mov rax,EXCEPTION_CONTINUE_EXECUTION
			ret

	.STARTSINGLESTEP
	cmp ebx,EXCEPTION_BREAKPOINT
	jne >>.UNHANDLED
		cmp Q[RDBG_SPYENABLED],0
		jne >>
		// Set the flag
		mov Q[RDBG_SPYENABLED], 1
		// Format the header
		invoke RDBGPrintSpacer
		invoke wsprintf,offset RDBG_ExceptLine,"Line %u: Begin spying %s",[RDBG_SPYLINENUM],offset RDBG_SPYVARNAME
		invoke RDBGPrint2Output,offset RDBG_ExceptLine
		invoke RDBGPrintSpacer
		invoke RDBGPrint2Output,"ADDRESS             DATA"

		// Increment RIP to jump past the INT3
		inc Q[rsi+CONTEXT.Rip]

		// Ouput the initial value
		// Be sure to set the Exception address to reflect the new
		// one that jumps past the INT3
		mov rax,[rsi+CONTEXT.Rip]
		mov [rdi+EXCEPTION_RECORD64.ExceptionAddress],rax

		// Jump to the normal output routine to convert the value
		// to whatever the user has selected
		jmp .PRINTSPY
 
		:
		// Reset the flag
		mov Q[RDBG_SPYENABLED], 0
		// Format the footer
		invoke wsprintf,offset RDBG_ExceptLine,"End spying %s",offset RDBG_SPYVARNAME
		invoke RDBGPrintSpacer
		invoke RDBGPrint2Output,offset RDBG_ExceptLine
		invoke RDBGPrintSpacer
		// Reset the single step flag
		and D[rsi+CONTEXT.EFlags],0xFFFFFEFF
		// Jump past the INT3
		inc Q[rsi+CONTEXT.Rip]
		// Blank the variable name
		mov rax,offset RDBG_SPYVARNAME
		mov Q[rax],0
		// Continue normal execution
		mov rax,EXCEPTION_CONTINUE_EXECUTION
		ret

	.UNHANDLED
	// Pass other exceptions to the next handler, we're now using INT3 to exit single step
	mov rax,EXCEPTION_CONTINUE_SEARCH
	ret
endf

RDBGOC_QueryInterface FRAME this, riid, ppv

	mov rax,[ppv]
	mov S[rax], 0

	invoke IsEqualGUID, [riid], offset RDBG_IID_IUnknown
	test rax,rax
	jz >
		mov RAX, [this]
		mov RDX, [ppv]
		mov [RDX],RAX
		mov RAX, 0
		RET
	:
	invoke IsEqualGUID, [riid], offset RDBG_IID_IDebugOutputCallbacks
	test rax,rax
	jz >
		mov RAX, [this]
		mov RDX, [ppv]
		mov [RDX],RAX
		mov RAX, 0
		RET
	:
	mov rax,E_NOINTERFACE
	ret
ENDF

RDBGOC_AddRef FRAME this
;	This is a static interface, it does not track instances
	xor rax,rax
	inc rax
	ret
ENDF

RDBGOC_Release FRAME this
;	This is a static interface, it does not track instances
	xor rax,rax
	ret
ENDF

RDBGOC_Output FRAME this, mask, text
	uses rdi,rsi

	mov rax,[mask]
	test rax,DEBUG_OUTPUT_NORMAL
	jz >>.SKIP
		// text sent to the ouput is delimited by 0x0A
		// so we have to parse the line before printing it
		invoke lstrlen,[text]
		mov rcx,rax
		mov rdi,[text]
		mov al,0x0A
		:
		mov rsi,rdi
		repne scasb
		mov B[rdi-1],0
		push rcx,rax,rdi
		invoke RDBGPrint2Output,rsi
		pop rdi,rax,rcx
		cmp rcx,0
		jg <
	.SKIP

	ret
endf

RDBGDisAssemble FRAME pTarget, nLines
	uses rbx
	LOCAL EndOffset:Q
	LOCAL pBuffer:%PTR
	LOCAL pszPath:%PTR

	mov Q[RDBG_pIDebugSymbols],0
	mov Q[RDBG_pIDebugControl],0

	invoke CoTaskMemAlloc,1024
	mov [pszPath],rax

	invoke CoTaskMemAlloc,1024
	mov [pBuffer],rax

	invoke GetModuleFileName,NULL,[pszPath],MAX_PATH
	invoke PathRemoveFileSpec,[pszPath]

	invoke DebugCreate,offset RDBG_IID_IDebugClient, offset RDBG_pIDebugClient
	test rax,rax
	jnz >>.DBGCFAIL
	CoInvoke(RDBG_pIDebugClient,IDebugClient.QueryInterface,offset RDBG_IID_IDebugControl,offset RDBG_pIDebugControl)
	test rax,rax
	jnz >>.QIFAIL
	CoInvoke(RDBG_pIDebugClient,IDebugClient.QueryInterface,offset RDBG_IID_IDebugSymbols,offset RDBG_pIDebugSymbols)
	test rax,rax
	jnz >>.QIFAIL

	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetSymbolOptions,0x10000)
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetSymbolPath,[pszPath])
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetImagePath ,[pszPath])

	invoke GetCurrentProcessId
	CoInvoke(RDBG_pIDebugClient,IDebugClient.AttachProcess,0,rax,DEBUG_ATTACH_NONINVASIVE | DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND)
	test rax,rax
	jnz >>.ATTACHFAIL
	CoInvoke(RDBG_pIDebugControl,IDebugControl.WaitForEvent,DEBUG_WAIT_DEFAULT,INFINITE)

	CoInvoke(RDBG_pIDebugClient,IDebugClient.SetOutputCallbacks,offset RDBG_IDbgOC)

	invoke RDBGPrintSpacer
	invoke wsprintf,[pBuffer],"Disassembling %u lines beginning at %p",[nLines],[pTarget]
	invoke RDBGPrint2Output,[pBuffer]
	invoke RDBGPrintSpacer

	mov rbx,[nLines]
	mov rdx,[pTarget]
	CoInvoke(RDBG_pIDebugControl,IDebugControl.OutputDisassemblyLines,DEBUG_OUTCTL_THIS_CLIENT,0,[nLines],rdx,DEBUG_DISASM_EFFECTIVE_ADDRESS,0,0,offset EndOffset,0)
	test rax,rax
	jnz >>.DISASMFAIL

	invoke RDBGPrintSpacer
	invoke wsprintf,[pBuffer],"Disassembly ended, next instruction at %p",[EndOffset]
	invoke RDBGPrint2Output,[pBuffer]
	invoke RDBGPrintSpacer

	CoInvoke(RDBG_pIDebugClient,IDebugClient.SetOutputCallbacks,NULL)
	CoInvoke(RDBG_pIDebugClient,IDebugClient.DetachProcesses)
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.Release)
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	ret

	.DBGCFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"DebugCreate failed"
	invoke RDBGPrint2Output,[pBuffer]
	invoke CoTaskMemFree,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	ret
	.QIFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"QueryInterface failed"
	invoke RDBGPrint2Output,[pBuffer]
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	ret
	.ATTACHFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"Attach to process failed"
	invoke RDBGPrint2Output,[pBuffer]
	cmp Q[RDBG_pIDebugSymbols],0
	je >
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.Release)
	:
	cmp Q[RDBG_pIDebugControl],0
	je >
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	:
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	ret
	.DISASMFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"Disassemble failed"
	invoke RDBGPrint2Output,[pBuffer]
	cmp Q[RDBG_pIDebugSymbols],0
	je >
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.Release)
	:
	cmp Q[RDBG_pIDebugControl],0
	je >
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	:
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	ret
endf

RDBGGetSymbols FRAME DbgType
	LOCAL BaseAddress:Q
	LOCAL hModule:Q
	LOCAL hProcess:Q
	LOCAL szPath[2048]:B
	LOCAL modinfo:MODULEINFO

	invoke RDBGPrintSpacer
	invoke RDBGPrint2Output,"Dumping symbol table"
	invoke RDBGPrintSpacer

	invoke GetCurrentProcess
	mov [hProcess],rax
	invoke GetModuleHandle,NULL
	mov [hModule],rax
	invoke GetModuleInformation,[hProcess],[hModule],offset modinfo,SIZEOF MODULEINFO

	invoke RDBGEnumerateSymbols,[hProcess],[modinfo.lpBaseOfDll],[DbgType]
	invoke RDBGPrintSpacer
	ret
endf

RDBGEnumerateSymbols FRAME hProcess, ImageBase, DbgType
	LOCAL hFile:Q
	LOCAL ProcessPath[2048]:B
	LOCAL SymPath[2048]:B
	LOCAL ihmod64:IMAGEHLP_MODULE64
	LOCAL ModuleBase:Q

	mov B[ProcessPath],0
	mov B[SymPath],0

	invoke GetModuleFileName,NULL,offset ProcessPath,MAX_PATH

	invoke lstrcpy,offset SymPath,offset ProcessPath
	invoke PathRemoveFileSpec,offset SymPath

	invoke CreateFile,offset ProcessPath,GENERIC_READ,NULL,NULL,OPEN_EXISTING,NULL,NULL
	mov [hFile],rax

	invoke SymInitialize,[hProcess], offset SymPath, FALSE // returns TRUE if success

	invoke SymLoadModule64,[hProcess],[hFile],offset ProcessPath,NULL,[ImageBase],0
	mov [ModuleBase],rax

	mov D[ihmod64.SizeOfStruct],SIZEOF IMAGEHLP_MODULE64
	invoke SymGetModuleInfo64,[hProcess],[ModuleBase],offset ihmod64

	cmp D[ihmod64.SymType],SymNone
	je >>.NOSYMBOLS

	invoke SymEnumSymbols,[hProcess],[ModuleBase],"*",offset RDBGSymEnumSymbolsProc, 0

	invoke SymUnloadModule64,[hProcess],[ModuleBase]

	invoke SymCleanup,[hProcess]
	invoke CloseHandle,[hFile]
	xor rax,rax
	RET

	.NOSYMBOLS
	invoke SymUnloadModule64,[hProcess],[ModuleBase]
	invoke SymCleanup,[hProcess]
	invoke CloseHandle,[hFile]
	invoke RDBGPrint2Output,"No symbol data found"
	xor rax,rax
	dec rax
	ret
ENDF

RDBGSymEnumSymbolsProc FRAME pSymInfo, SymbolSize, UserContext
	uses rdi,rbx
	LOCAL mbi:MEMORY_BASIC_INFORMATION
	LOCAL AddrBuffer[1024]:%CHAR
	LOCAL TypeBuffer[16]:%CHAR

	mov edi,[pSymInfo]

	mov Q[TypeBuffer],0

	// Find which section it is in
	invoke VirtualQuery,[rdi+SYMBOL_INFO.Address],offset mbi,SIZEOF MEMORY_BASIC_INFORMATION
	mov eax,[mbi.Protect]
	mov rax,eax
	
	cmp rax,PAGE_EXECUTE
	jne >
	invoke lstrcpy,offset TypeBuffer,"CODE"
	jmp >>.DISPLAYSYMBOL
	:
	cmp rax,PAGE_EXECUTE_READ
	jne >
	invoke lstrcpy,offset TypeBuffer,"CODE"
	jmp >>.DISPLAYSYMBOL
	:
	cmp rax,PAGE_WRITECOPY
	jne >
	invoke lstrcpy,offset TypeBuffer,"DATA"
	jmp >>.DISPLAYSYMBOL
	:
	cmp rax,PAGE_READWRITE
	jne >
	invoke lstrcpy,offset TypeBuffer,"DATA"
	jmp >>.DISPLAYSYMBOL
	:
	cmp rax,PAGE_READONLY
	jne >
	invoke lstrcpy,offset TypeBuffer,"CNST"
	jmp >>.DISPLAYSYMBOL
	:
	invoke wsprintf,offset TypeBuffer,"0x%0.2X",rax

	.DISPLAYSYMBOL
	// These will remove symbols starting with % and with RDBG
	// those are used in the debug routines and the filter removes
	// them so they will not make the symbols list difficult to read 
	mov al,[rdi+SYMBOL_INFO.Name]
	cmp al,"%"
	je >>.EXIT
	mov eax,[rdi+SYMBOL_INFO.Name]
	bswap eax
	cmp eax,"GBDR"
	je >>.EXIT

	lea rax,rdi+SYMBOL_INFO.Name
	invoke wsprintf,offset AddrBuffer,"0x%p : %s : %s",[rdi+SYMBOL_INFO.Address],offset TypeBuffer,rax
	invoke RDBGPrint2Output,offset AddrBuffer

	.EXIT
	mov rax,TRUE
	RET
ENDF

RDBGPrintModuleError FRAME LineNum, pszModulePath, ErrorNumber
	uses rbx
	LOCAL pMem			:%HANDLE

	invoke GlobalAlloc,040h,128
	mov [pMem],rax

	invoke LoadLibrary,[pszModulePath]
	mov rbx,rax
	invoke FormatMessage,FORMAT_MESSAGE_FROM_HMODULE,rbx,[ErrorNumber],NULL,offset RDBG_ExceptLine,127,NULL
	invoke FreeLibrary,rbx
	CInvoke(wsprintf,[pMem],"Line %u: Error %u > %s",[LineNum],[ErrorNumber],OFFSET RDBG_ExceptLine)
	invoke RDBGPrint2Output,[pMem]
	invoke GlobalFree,[pMem]
	ret
endf

RDBGGetModuleByAddr FRAME hProcess,Address,pModuleName
	uses rdi,rsi,rbx
	LOCAL hMods[1024]			:%HANDLE
	LOCAL cbNeeded				:D
	LOCAL modinfo				:MODULEINFO
	LOCAL hModule				:%HANDLE
	LOCAL ModuleName[MAX_PATH]		:%CHAR

	mov rax,[pModuleName]
	mov B[rax],0

	mov rbx,[Address]
	invoke EnumProcessModules,[hProcess],offset hMods,1024,offset cbNeeded
	or rax,rax
	jz >>.DONE
		mov edi,[cbNeeded]
		shr edi,2
		mov rsi,offset hMods
		L1:
		mov rax,[rsi]
		mov [hModule],rax
		add esi,8

		invoke GetModuleInformation,[hProcess],[hModule],offset modinfo,SIZEOF MODULEINFO
		or rax,rax
		jz >.DONE
		cmp rbx,[modinfo.lpBaseOfDll]
		jg >L2
			dec edi
			js >.DONE
			jmp <L1
		L2:
			mov eax,[modinfo.SizeOfImage]
			add rax,[modinfo.lpBaseOfDll]
			cmp rbx,rax
			jl >L3
			dec edi
			js >.DONE
			jmp <L1
		L3:
		invoke GetModuleFileName,[hModule],OFFSET ModuleName,256
		invoke GetFileTitle,OFFSET ModuleName,[pModuleName],256

	.DONE
	invoke lstrlen,[pModuleName]
	test rax,rax
	RET
ENDF

RDBGDumpStack  FRAME pContext
	uses rbx,r15
	LOCAL pBuffer:%PTR
	LOCAL CxrCommand[64]:%CHAR
	LOCAL pszPath:%PTR
	LOCAL pszSymPath:%PTR

;	invoke RDBGPrintSpacer
	invoke RDBGPrint2Output,"Stack trace"
	invoke RDBGPrintSpacer

	invoke CoTaskMemAlloc,1024
	mov [pszPath],rax

	invoke CoTaskMemAlloc,1024
	mov [pszSymPath],rax

	invoke CoTaskMemAlloc,1024
	mov [pBuffer],rax

	invoke GetModuleFileName,NULL,[pszPath],MAX_PATH

	invoke lstrcpy,[pszSymPath],[pszPath]
	invoke PathRemoveFileSpec,[pszSymPath]

	invoke DebugCreate,offset RDBG_IID_IDebugClient, offset RDBG_pIDebugClient
	test rax,rax
	jnz >>.DBGCFAIL
	CoInvoke(RDBG_pIDebugClient,IDebugClient.QueryInterface,offset RDBG_IID_IDebugControl,offset RDBG_pIDebugControl)
	test rax,rax
	jnz >>.QIFAIL

	invoke GetCurrentProcessId
	CoInvoke(RDBG_pIDebugClient,IDebugClient.AttachProcess,0,rax,DEBUG_ATTACH_NONINVASIVE | DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND)
	test eax,eax
	jnz >>.ATTACHFAIL
	CoInvoke(RDBG_pIDebugControl,IDebugControl.WaitForEvent,DEBUG_WAIT_DEFAULT,INFINITE)
	test eax,eax
	jnz >>.ATTACHFAIL

	CoInvoke(RDBG_pIDebugClient,IDebugClient.QueryInterface,offset RDBG_IID_IDebugSymbols,offset RDBG_pIDebugSymbols)
	test rax,rax
	jnz >>.QIFAIL
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetSymbolOptions,0x10000)
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetSymbolPath,[pszSymPath])
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.SetImagePath ,[pszPath])

	CoInvoke(RDBG_pIDebugClient,IDebugClient.SetOutputCallbacks,offset RDBG_IDbgOC)

	invoke wsprintf,offset CxrCommand,".cxr 0x%p",[pContext]
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Execute,DEBUG_OUTCTL_IGNORE,offset CxrCommand,DEBUG_EXECUTE_NOT_LOGGED)
	test rax,rax
	jnz >>.EXECFAIL

	CoInvoke(RDBG_pIDebugControl,IDebugControl.OutputStackTrace,DEBUG_OUTCTL_ALL_CLIENTS, NULL, [RDBG_TRACECOUNT], DEBUG_STACK_SOURCE_LINE|DEBUG_STACK_FRAME_ADDRESSES|DEBUG_STACK_COLUMN_NAMES|DEBUG_STACK_FRAME_NUMBERS)
	test eax,eax
	jnz >>.STACKTRACEFAIL

	CoInvoke(RDBG_pIDebugClient,IDebugClient.SetOutputCallbacks,NULL)

	CoInvoke(RDBG_pIDebugClient,IDebugClient.DetachProcesses)
	CoInvoke(RDBG_pIDebugSymbols,IDebugSymbols.Release)
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]

	ret

	.DBGCFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"DebugCreate failed"
	invoke RDBGPrint2Output,[pBuffer]
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]
	ret

	.QIFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"QueryInterface failed"
	invoke RDBGPrint2Output,[pBuffer]
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]
	ret

	.ATTACHFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"Attach to process failed"
	invoke RDBGPrint2Output,[pBuffer]
	cmp S[RDBG_pIDebugControl],0
	je >
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	:
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]
	ret

	.EXECFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"Execute failed"
	invoke RDBGPrint2Output,[pBuffer]
	cmp S[RDBG_pIDebugControl],0
	je >
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	:
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]
	ret

	.STACKTRACEFAIL
	invoke FormatMessage,FORMAT_MESSAGE_FROM_SYSTEM,NULL,rax,NULL,[pBuffer],1024,NULL
	invoke RDBGPrint2Output,"Stack trace failed"
	invoke RDBGPrint2Output,[pBuffer]
	cmp S[RDBG_pIDebugControl],0
	je >
	CoInvoke(RDBG_pIDebugControl,IDebugControl.Release)
	:
	CoInvoke(RDBG_pIDebugClient,IDebugClient.Release)
	invoke CoTaskMemFree,[pszPath]
	invoke CoTaskMemFree,[pBuffer]
	ret
endf

RDBGShowHandlesThisProcess FRAME
	uses edi,ebx,esi
	LOCAL pid:%HANDLE
	LOCAL hProcess:%HANDLE
	LOCAL hHandles:%HANDLE
	LOCAL BytesNeeded:D

	invoke RDBGPrintSpacer
	invoke RDBGPrint2Output,"Handle dump"
	invoke RDBGPrintSpacer

	invoke GetCurrentProcessId
	mov [pid],rax

	// Allocate memory for the handle array
	invoke GlobalAlloc,GMEM_FIXED,1024*1024
	mov [hHandles],eax

	invoke NtQuerySystemInformation, SystemHandleInformation, [hHandles], 1048576, offset BytesNeeded

	mov rbx, [hHandles]
	mov rdi,[rbx] // Handle count
	add rbx,8 // skip past the count QWORD
	invoke qsort, rbx, rdi , SIZEOF SYSTEM_HANDLE_ENTRY, offset RDBGqsort_compare

	// Scan ahead to our PID
	imul rdi,SIZEOF SYSTEM_HANDLE_ENTRY
	add rdi,rbx
	mov rsi,rbx
	:
	mov eax,[rsi]
	cmp eax,[pid]
	je >
	add rsi, SIZEOF SYSTEM_HANDLE_ENTRY
	cmp rsi,rdi
	jl <
	ret
	:

	invoke RDBGWalkHandles,rsi, [pid]

	invoke RDBGPrintSpacer

	invoke GlobalFree,[hHandles]
	ret
endf

RDBGWalkHandles FRAME pArray, pid
	uses ebx,edi,esi
	LOCAL hObject:%HANDLE
	LOCAL ObjTypeInfo:LOCAL_OBJECT_TYPE_INFORMATION
	LOCAL ObjNameInfo:LOCAL_OBJECT_NAME_INFORMATION
	LOCAL cbWritten:D
	LOCAL szType[256]:%CHAR
	LOCAL szFileName[MAX_PATH]:%CHAR
	LOCAL OutString[MAX_PATH]:%CHAR
	LOCAL iostat:IO_STATUS_BLOCK
	LOCAL hChild:%HANDLE // used to add information to an objects entry if any

	mov rbx,[pArray]
	:
	mov W[ObjTypeInfo.oti.TypeName.Length],0
	mov W[ObjTypeInfo.oti.TypeName.MaximumLength],128
	lea rax,ObjTypeInfo.ustring
	mov Q[ObjTypeInfo.oti.TypeName.Buffer],rax

	movzx rax,W[ebx+SYSTEM_HANDLE_ENTRY.HandleValue]
	mov [hObject],rax
	test rax,rax
	jz >>.exit
	invoke NtQueryObject,[hObject],ObjectTypeInformation,offset ObjTypeInfo,SIZEOF LOCAL_OBJECT_TYPE_INFORMATION,offset cbWritten

	invoke wsprintf,offset OutString,"HANDLE 0x%0.8X: ",[hObject]

	lea rax,ObjTypeInfo
	mov rsi,[rax+8]
	movzx rax, W[rax]
	invoke WideCharToMultiByte,CP_ACP,NULL,rsi,rax,offset szType,256,NULL,NULL

	invoke lstrcat,offset OutString,offset szType

	// Get any name information
	invoke NtQueryObject,[hObject],ObjectNameInformation,offset ObjNameInfo,SIZEOF LOCAL_OBJECT_NAME_INFORMATION,offset cbWritten
	lea rax,ObjNameInfo
	add rax,8
	mov rax,[rax]
	test rax,rax
	jz >>.CLOSEHANDLE
	invoke WideCharToMultiByte,CP_ACP,NULL,rax,-1,offset szFileName,MAX_PATH,NULL,NULL

	invoke lstrcat,offset OutString," = "
	invoke lstrcat,offset OutString,offset szFileName

	.CLOSEHANDLE
	invoke RDBGPrint2Output,offset OutString
	// Get the next object
	add rbx,SIZEOF SYSTEM_HANDLE_ENTRY
	mov eax,[rbx]
	cmp eax,[pid]
	je <<

	.exit
	ret
endf

RDBGqsort_compare:
	/*
	return values

	< 0	elem1 less than elem2
	0	elem1 equivalent to elem2
	> 0	elem1 greater than elem2

	*/

	// In FASTCALL the parameters are passed to the function
	// in the registers. Since there are only 2 we don't have
	// to worry about the stack so just use them directly

	mov eax,[rcx]
	mov ecx,[rdx]

	sub eax,ecx // Element 1 minus element 2 yeilds the desired return value
	neg eax // reverses the sort
	ret
