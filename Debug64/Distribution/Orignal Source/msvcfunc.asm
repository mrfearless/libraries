CODE SECTION

RDBGitoa FRAME Value, pString, Radix
	uses EBX

	// All parameters are 64 bit, a dword is required so
	// take the bottom 32 bits and sign extend to 64 bit
	MOV RAX,[Value]
	MOVSXD RCX,EAX
	XOR EAX,EAX
	MOV RBX,[pString]
	// only base 10 has a sign
	CMP D[Radix],10
	JNE >.SETSIGN
	// If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE >.SETSIGN
	// If <0 then sign flag = 1
	inc eax
	.SETSIGN
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
ENDF

RDBGi16toa FRAME Value, pString, Radix
	uses EBX

	// All parameters are 64 bit, a dword is required so
	// take the bottom 32 bits and sign extend to 64 bit
	MOV RAX,[Value]
	MOVSX RCX,AX
	XOR EAX,EAX
	MOV RBX,[pString]
	// only base 10 has a sign
	CMP D[Radix],10
	JNE >.SETSIGN
	// If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE >.SETSIGN
	// If <0 then sign flag = 1
	inc eax
	.SETSIGN
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
ENDF

RDBGi8toa FRAME Value, pString, Radix
	uses EBX

	// All parameters are 64 bit, a dword is required so
	// take the bottom 32 bits and sign extend to 64 bit
	MOV RAX,[Value]
	MOVSX RCX,AL
	XOR EAX,EAX
	MOV RBX,[pString]
	// only base 10 has a sign
	CMP D[Radix],10
	JNE >.SETSIGN
	// If >=0 then sign flag = 0
	CMP RCX,RAX
	JGE >.SETSIGN
	// If <0 then sign flag = 1
	inc eax
	.SETSIGN
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
ENDF

RDBGi64toa FRAME Value, pString, Radix
	uses EBX

	XOR EAX,EAX
	MOV RBX,[pString]
	// only base 10 has a sign
	CMP D[Radix],10
	JNE >.SETSIGN
	CMP [Value],RAX
	JGE >.SETSIGN
	inc eax
	.SETSIGN
	MOV R9D,EAX ; Sign
	call RDBGConvertI64
	MOV RAX,RBX
	RET
ENDF

RDBGConvertI64:

	MOV R11D,R8D ; [Radix]
	MOV R10, RDX ; [pString]
	MOV RAX, RCX ; [Value]
	TEST R9D,R9D ; Sign flag
	JZ >L0
	INC R10
	MOV B[RDX],"-"
	NEG RAX
	L0:
	MOV R8,R10
	MOV RCX,R11
	L1:
	XOR EDX,EDX
	DIV RCX
	CMP EDX,0x9
	JBE >L2
	ADD DL,0x57
	JMP >L3
	L2:
	ADD DL,0x30
	L3:
	MOV [R10],DL
	INC R10
	TEST RAX,RAX
	JNZ <L1
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
	JB  <L4
	RET

