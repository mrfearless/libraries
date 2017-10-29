IFNDEF _wininc_
include		windows.inc
ENDIF

IFNDEF KERNEL32_INC
includelib	kernel32.lib
ENDIF

IFNDEF USER32_INC
includelib	user32.lib
ENDIF

IFNDEF COMCTL32_INC
include		CommCtrl.inc
includelib	Comctl32.lib
ENDIF

IFNDEF SHELL32_INC
include		shellapi.inc
includelib	shell32.lib
ENDIF

IFNDEF OLE32_INC
;include		OLE2.INC
includelib	ole32.lib
ENDIF

IFNDEF PSAPI_INC
include		psapi.inc
includelib	psapi.lib
ENDIF

IFNDEF SHLWAPI_INC
include		shlwapi.inc
includelib	shlwapi.lib
ENDIF

IFNDEF COMDLG32_INC
include		commdlg.INC
includelib	comdlg32.lib
ENDIF

IFNDEF c_msvcrt
include STDIO.INC
include stdlib.INC
includelib	msvcrt.lib
ENDIF

IFNDEF DBG64LIB
	includelib	Debug64.lib
ENDIF

includelib	dbghelp.lib
includelib	dbgeng.lib
includelib	ntdll.lib

;PUBLIC RDBG_SPYENABLED
;PUBLIC RDBG_SPYHANDLER
;PUBLIC RDBG_SPYLINENUM
;PUBLIC RDBG_VEHANDLER
;PUBLIC RDBG_SPYVARADDR
;PUBLIC RDBG_SPYVARTYPE
;PUBLIC RDBG_SPYVARNAME
PUBLIC RDBG_TRACECOUNT
PUBLIC RDBG_DbgWin

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

;// Variable types for use with Spy
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

;RDBGAttachForTry PROTO :QWORD
;RDBGdd2hex PROTO :QWORD,:QWORD
;RDBGDetachForTry PROTO
;RDBGDisAssemble PROTO :QWORD,:QWORD
;RDBGdq2ascii PROTO :QWORD,:QWORD
;RDBGDropHandler PROTO
;RDBGDumpEFlags PROTO :QWORD,:QWORD
;RDBGDumpHex PROTO :QWORD,:QWORD,:QWORD
;RDBGDumpStack PROTO :QWORD
;RDBGEnumerateSymbols PROTO :QWORD,:QWORD,:QWORD
;RDBGFormatLine PROTO :QWORD,:QWORD,:QWORD
;RDBGFPUDump PROTO :QWORD
;RDBGGetExceptName PROTO :QWORD
;RDBGGetHandler PROTO
;RDBGGetModuleByAddr PROTO :QWORD,:QWORD,:QWORD
;RDBGGetSpy PROTO
;RDBGGetSymbols PROTO :QWORD
;RDBGMMXDump PROTO :QWORD
;RDBGOC_AddRef PROTO :QWORD
;RDBGOC_Output PROTO :QWORD,:QWORD,:QWORD
;RDBGOC_QueryInterface PROTO :QWORD,:QWORD,:QWORD
;RDBGOC_Release PROTO :QWORD
;RDBGPrint2Output PROTO :QWORD
;RDBGPrintError PROTO :QWORD
;RDBGPrintErrorByNum PROTO :QWORD,:QWORD
;RDBGPrintModuleError PROTO :QWORD,:QWORD,:QWORD
;RDBGPrintNumber PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
;RDBGPrintSpacer PROTO
RDBGPrintString PROTO :QWORD,:QWORD,:QWORD,:QWORD
;RDBGShowHandlesThisProcess PROTO
;RDBGSpy PROTO :QWORD
;RDBGSymEnumSymbolsProc PROTO :QWORD,:QWORD,:QWORD
;RDBGVectoredHandler PROTO :QWORD
;RDBGWalkHandles PROTO :QWORD,:QWORD

IFNDEF GUID
GUID STRUCT
		Data1	dd ?
		Data2	dw ?
		Data3	dw ?
		Data4	db 8 DUP (?)
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

IFNDEF DEBUGEXE
	DEBUGEXE textequ <'DbgWin.exe'>
ENDIF

.DATA
RDBG_DbgWin					DB DEBUGEXE,0
RDBG_TRACECOUNT				DQ 50
RDBG_VEHANDLER				DD -1
RDBG_SPYENABLED				DD 0
RDBG_SPYHANDLER				DD -1
RDBG_SPYLINENUM				DD 0
RDBG_SPYVARADDR				DD 0
RDBG_SPYVARTYPE				DD 0
RDBG_SPYVARNAME				DB 256 DUP (0)
ALIGN 16
RDBG_XMMSAVEAREA			DB 512 DUP (0)

.CODE
IFNDEF _WIN64
	;GOASM_ECHO Macros for 64 bit programs only !
	;GOASM_EXIT
ENDIF

;#dynamiclinkfile comdlg32.dll
;#dynamiclinkfile msvcrt.dll
;#dynamiclinkfile kernel32.dll
;#dynamiclinkfile user32.dll
;#dynamiclinkfile shlwapi.dll
;#dynamiclinkfile dbgeng.dll
;#dynamiclinkfile dbghelp.dll
;#dynamiclinkfile Psapi.dll
;#dynamiclinkfile ntdll.dll

CTEXT MACRO quoted_text:VARARG
    LOCAL local_text
    .data
    align 8
    local_text db quoted_text,0
    .code
    align 8
    EXITM <offset local_text> 
ENDM


Disassemble MACRO pTarget,nLines
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGDisAssemble, %pTarget, %nLines
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DumpHandles macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGShowHandlesThisProcess
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

Try macro var1
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	#IF ARGCOUNT = 1
		mov rax,%var1
	#ELSE
		invoke DBG64LIB:RDBGGetHandler
	#ENDIF
	invoke AddVectoredExceptionHandler,1,rax
	mov [RDBG_VEHANDLER],rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

EndTry macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RemoveVectoredExceptionHandler,[RDBG_VEHANDLER]
	mov Q[RDBG_VEHANDLER],-1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

Spy macro Type,Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	#IF ARGCOUNT = 2
		push offset %Arg
		pop [RDBG_SPYVARADDR]
		invoke lstrcpy,offset RDBG_SPYVARNAME,"%Arg"
	#ELSE
		invoke lstrcpy,offset RDBG_SPYVARNAME,"%Type"
	#ENDIF
	mov Q[RDBG_SPYLINENUM],@Line
	mov Q[RDBG_SPYVARTYPE],%Type
	invoke DBG64LIB:RDBGGetSpy
	invoke AddVectoredExceptionHandler,1,RAX
	mov [RDBG_SPYHANDLER],rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
	int3
endm

StopSpy macro
	int3
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RemoveVectoredExceptionHandler,[RDBG_SPYHANDLER]
	mov Q[RDBG_SPYHANDLER],-1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
endm

DumpSymbols macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGGetSymbols,1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DumpFPU macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGFPUDump,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DumpMMX macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGMMXDump,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintString MACRO ARG
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	IFDEF UNICODE
		invoke DBG64LIB:RDBGPrintString,@Line,offset %ARG, CTEXT("%ARG = "), 1
	ELSE
		invoke DBG64LIB:RDBGPrintString,@Line,offset %ARG, CTEXT("%ARG = "), 0
	ENDIF
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
ENDM

PrintStringByAddr MACRO ARG
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	IFDEF UNICODE
		invoke DBG64LIB:RDBGPrintString,@Line,%ARG, A"%ARG = ", 1
	ELSE
		invoke DBG64LIB:RDBGPrintString,@Line,%ARG, A"%ARG = ", 0
	ENDIF
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
ENDM

PrintText MACRO ARG
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave RDBG_XMMSAVEAREA
	cld
	Invoke GlobalAlloc, GPTR, 256d
	mov rbx, rax
	IFDEF UNICODE
		invoke RDBGPrintString, @Line, CTEXT(ARG), rbx, 1
	ELSE
		invoke RDBGPrintString, @Line, CTEXT(ARG), rbx, 0
	ENDIF
	Invoke GlobalFree, rbx
	fxrstor RDBG_XMMSAVEAREA
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
ENDM

PrintError MACRO
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintError,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DumpMem MACRO Start,Length
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintSpacer
	invoke DBG64LIB:RDBGDumpHex,%Start,%Length,@Line
	invoke DBG64LIB:RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DbgDump MACRO Start,Length
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintSpacer
	invoke DBG64LIB:RDBGDumpHex,%Start,%Length,@Line
	invoke DBG64LIB:RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintLine MACRO
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintOleError MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintErrorByNum,@Line,%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintModMessage MACRO Arg1,Arg2
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintModuleError,@Line,%Arg1,%Arg2
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintQWORD MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,0,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintDec MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,0,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintQWORDHex MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,1,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintDWORD MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,4,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintDWORDHex MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,5,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintWORD MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,8,"%Arg = ",%Arg
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintWORDHex MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push %Arg
	pop rax
	and rax,0xFFFF
	invoke RDBGPrintNumber,@Line,WORD_HEX,"%Arg = ",rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintBYTE Macro Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push %Arg
	pop rax
	and rax,0xFFFF
	invoke RDBGPrintNumber,@Line,BYTE_DEC,"%Arg = ",rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintBYTEHex MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push %Arg
	pop rax
	and rax,0xFFFF
	invoke RDBGPrintNumber,@Line,BYTE_HEX,"%Arg = ",rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintFloat MACRO Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,3,"%Arg = ",[%Arg]
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

PrintDouble Macro Arg
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke DBG64LIB:RDBGPrintNumber,@Line,2,"%Arg = ",[%Arg]
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm

DumpEFlags Macro
	pushfq
	push RAX,RCX,RDX,R8,R9,R10,R11
	fxsave [RDBG_XMMSAVEAREA]
	pushfq
	pop rax
	cld
	invoke DBG64LIB:RDBGDumpEFlags,@Line,RAX
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11,R10,R9,R8,RDX,RCX,RAX
	popfq
endm
