;=========================================================================================
;
; Debug64 Library x64 
;
; 2015 fearless
;
; Original code from Donkey's vKim like tools - adapted for JWasm64 
;
; Original Thread: http://www.masmforum.com/board/index.php?topic=16317.msg135041#msg135041
; Download Link: http://www.masmforum.com/board/index.php?action=dlattach;topic=16317.0;id=10334
;
;=========================================================================================

; WinInc includes
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
RDBGDumpHex PROTO :QWORD,:QWORD,:QWORD
;RDBGDumpStack PROTO :QWORD
;RDBGEnumerateSymbols PROTO :QWORD,:QWORD,:QWORD
RDBGFormatLine PROTO :QWORD,:QWORD,:QWORD
;RDBGFPUDump PROTO :QWORD
;RDBGGetExceptName PROTO :QWORD
;RDBGGetHandler PROTO
;RDBGGetModuleByAddr PROTO :QWORD,:QWORD,:QWORD
;RDBGGetSpy PROTO
;RDBGGetSymbols PROTO :QWORD
;RDBGMMXDump PROTO :QWORD
RDBGOC_AddRef PROTO :QWORD
RDBGOC_Output PROTO :QWORD,:QWORD,:QWORD
RDBGOC_QueryInterface PROTO :QWORD,:QWORD,:QWORD
RDBGOC_Release PROTO :QWORD
RDBGPrint2Output PROTO :QWORD
;RDBGPrintError PROTO :QWORD
;RDBGPrintErrorByNum PROTO :QWORD,:QWORD
;RDBGPrintModuleError PROTO :QWORD,:QWORD,:QWORD
RDBGPrintNumber PROTO :QWORD,:QWORD,:QWORD,:QWORD
RDBGPrintSpacer PROTO
RDBGPrintString PROTO :QWORD,:QWORD,:QWORD,:QWORD
;RDBGShowHandlesThisProcess PROTO
;RDBGSpy PROTO :QWORD
;RDBGSymEnumSymbolsProc PROTO :QWORD,:QWORD,:QWORD
;RDBGVectoredHandler PROTO :QWORD
;RDBGWalkHandles PROTO :QWORD,:QWORD

IFNDEF DBG64LIB
	DBG64LIB textequ <'\JWasm\Lib\x64\Debug64.lib'>
ENDIF

PUBLIC RDBG_DbgWin
EXTERNDEF RDBG_DbgWin:BYTE
;IFNDEF DEBUGEXE
;	DEBUGEXE textequ <'.\DbgWin.exe'>
;ENDIF

.DATA
align 01
; define it in start of our program instead, made it external
;RDBG_DbgWin					DB DEBUGEXE,0
RDBG_TRACECOUNT				DQ 50
ALIGN 16
RDBG_XMMSAVEAREA			DB 512 DUP (0)

.CODE

; MACROS for placing in your code
;
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
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGDisAssemble, pTarget, nLines
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DumpHandles macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGShowHandlesThisProcess
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

Try macro var1
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	#IF ARGCOUNT = 1
		mov rax,var1
	#ELSE
		invoke RDBGGetHandler
	#ENDIF
	invoke AddVectoredExceptionHandler,1,rax
	mov [RDBG_VEHANDLER],rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

EndTry macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RemoveVectoredExceptionHandler,[RDBG_VEHANDLER]
	mov Q[RDBG_VEHANDLER],-1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

Spy macro Type,ARG
    LOCAL argtext, __argtext, typetext, __typetext
    __argtext CATSTR <!">, <ARG>, <!">
    __typetext CATSTR <!">, <Type>, <!">
    .data
    align 8
    argtext db __argtext,0
    typetext db __typetext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	#IF ARGCOUNT = 2
		push offset ARG
		pop [RDBG_SPYVARADDR]
		invoke lstrcpy,offset RDBG_SPYVARNAME, Addr argtext ;"%Arg"
	#ELSE
		invoke lstrcpy,offset RDBG_SPYVARNAME, Addr typetext ;"%Type"
	#ENDIF
	mov Q[RDBG_SPYLINENUM],@Line
	mov Q[RDBG_SPYVARTYPE],Type
	invoke RDBGGetSpy
	invoke AddVectoredExceptionHandler,1,RAX
	mov [RDBG_SPYHANDLER],rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
	int3
endm

StopSpy macro
	int3
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RemoveVectoredExceptionHandler,[RDBG_SPYHANDLER]
	mov Q[RDBG_SPYHANDLER],-1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
endm

DumpSymbols macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGGetSymbols,1
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DumpFPU macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGFPUDump,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DumpMMX macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGMMXDump,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

; Only works with variables defined in .DATA or .DATA? or register values, wont work with LOCAL variables.
PrintString MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	IFDEF UNICODE
		invoke RDBGPrintString,@Line, offset ARG, Addr eqtext, 1
	ELSE

		invoke RDBGPrintString,@Line, offset ARG, Addr eqtext, 0
	ENDIF
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
ENDM

PrintStringByAddr MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	IFDEF UNICODE
		invoke RDBGPrintString,@Line, ARG, Addr eqtext, 1
	ELSE
		invoke RDBGPrintString,@Line, ARG, Addr eqtext, 0
	ENDIF
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
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
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintError,@Line
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DumpMem MACRO Start,nLength
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintSpacer
	invoke RDBGDumpHex, Start, nLength, @Line
	invoke RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DbgDump MACRO Start,nLength
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintSpacer
	invoke RDBGDumpHex,Start, nLength, @Line
	invoke RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintLine MACRO
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintSpacer
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintOleError MACRO ARG
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintErrorByNum,@Line,ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintModMessage MACRO Arg1,Arg2
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintModuleError,@Line,Arg1,Arg2
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

; Only works with variables defined in .DATA or .DATA? or register values, wont work with LOCAL variables.
PrintQWORD MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,0,Addr eqtext, ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

; Only works with variables defined in .DATA or .DATA? or register values, wont work with LOCAL variables.
PrintDec MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,0,Addr eqtext, &ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintQWORDHex MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,1,Addr eqtext, &ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintDWORD MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,4,Addr eqtext, &ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintDWORDHex MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,5,Addr eqtext, &ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintWORD MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,8,Addr eqtext, &ARG
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintWORDHex MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push ARG
	pop rax
	and rax,0FFFFh
	invoke RDBGPrintNumber,@Line,WORD_HEX,Addr eqtext,rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintBYTE Macro ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push ARG
	pop rax
	and rax,0FFFFh
	invoke RDBGPrintNumber,@Line,BYTE_DEC,Addr eqtext,rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintBYTEHex MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	push ARG
	pop rax
	and rax,0FFFFh
	invoke RDBGPrintNumber,@Line,BYTE_HEX,Addr eqtext,rax
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintFloat MACRO ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,3,Addr eqtext,[ARG]
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

PrintDouble Macro ARG
    LOCAL eqtext, __eqtext
    __eqtext CATSTR <!">, <ARG>, <= >, <!">
    .data
    align 8
    eqtext db __eqtext,0
    .code
    align 8
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	cld
	invoke RDBGPrintNumber,@Line,2,Addr eqtext,[ARG]
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm

DumpEFlags Macro
	pushfq
	push RAX
	push RCX
	push RDX
	push R8
	push R9
	push R10
	push R11
	fxsave [RDBG_XMMSAVEAREA]
	pushfq
	pop rax
	cld
	invoke RDBGDumpEFlags,@Line,RAX
	fxrstor [RDBG_XMMSAVEAREA]
	pop R11
	pop R10
	pop R9
	pop R8
	pop RDX
	pop RCX
	pop RAX
	popfq
endm












