include shell32.inc
includelib shell32.lib
include advapi32.inc
includelib advapi32.lib

IniCreateFilename                   PROTO :DWORD, :DWORD
IniGetSettingExpandAllOnLoad        PROTO
IniSetSettingExpandAllOnLoad        PROTO :DWORD
IniGetSettingCaseSensitiveSearch    PROTO
IniSetSettingCaseSensitiveSearch    PROTO :DWORD
IniToggleExpandAllOnLoad            PROTO
IniToggleCaseSensitiveSearch        PROTO



.DATA

szBackslashChar		            DB "\",0			; backslash char
szExtEXE 			            DB ".exe",0 		; exe file extension
szExtINI 			            DB ".ini",0			; ini file extension
szIniFilename		            DB MAX_PATH dup (0)	; buffer to hold our ini filename
szZero                          DB "0",0
szOne                           DB "1",0

; ini options:
szExpandAllOnLoad               DB "ExpandAllOnLoad",0
szCaseSensitiveSearch           DB "CaseSensitiveSearch",0
szMRUSection                    DB "MRU",0
szMRUFilename                   DB MAX_PATH dup (0)





.CODE


;--------------------------------------------------------------------------------------
; Create an .ini filename based on the executables name.
; Example Usage: Invoke IniCreateFilename, Addr szIniFilename
;--------------------------------------------------------------------------------------
IniCreateFilename PROC USES ECX EDI ESI lpszIniFile:DWORD, lpszBaseModuleName:DWORD
    LOCAL VersionInformation:OSVERSIONINFO
    LOCAL ModuleFullPathname[MAX_PATH]:BYTE
    LOCAL ModuleName[MAX_PATH]:BYTE
    LOCAL hInst:DWORD
    LOCAL ppidl:DWORD
    LOCAL LenFilePathName:DWORD
    LOCAL PosFullStop:DWORD
    LOCAL PosBackSlash:DWORD
    LOCAL Version:DWORD
    
	Invoke GetModuleFileName, NULL, Addr ModuleFullPathname, Sizeof ModuleFullPathname
	Invoke lstrlen, Addr ModuleFullPathname			; length of module path
	mov LenFilePathName, eax						; save var for later
	
	;----------------------------------------------------------------------
	; Find the fullstop position in the module full pathname
	;----------------------------------------------------------------------
	mov PosFullStop, 0 
	lea esi, ModuleFullPathname
	add esi, LenFilePathName
	mov ecx, LenFilePathName
	.WHILE ecx >= 0
		movzx eax, byte ptr [esi]
		.IF al == 46d ; 46d = 2Eh is full stop .
			mov PosFullStop, ecx ; save fullstop position
			.BREAK
		.ELSE
			dec esi ; move down string by 1
			dec ecx ; decrease ecx counter
		.ENDIF
	.ENDW
	.IF PosFullStop == 0 ; if for some reason we dont have the position
		mov eax, FALSE		 ; we should probably exit with an error
		ret
	.ENDIF
	;----------------------------------------------------------------------
	
    ; Determine what OS we are running on
	mov VersionInformation.dwOSVersionInfoSize, SIZEOF OSVERSIONINFO
    Invoke GetVersionEx, Addr VersionInformation
    mov eax, VersionInformation.dwMajorVersion
    mov Version, eax
    
	;----------------------------------------------------------------------
	; Find the backslash position in the module full pathname
	;----------------------------------------------------------------------
	mov PosBackSlash, 0
	lea esi, ModuleFullPathname
	add esi, PosFullStop
	mov ecx, PosFullStop
	.WHILE ecx >= 0
		movzx eax, byte ptr [esi]
		.IF al == 92 ; 92d = 5Ch is backslash \
			mov PosBackSlash, ecx ; save backslash position
			.BREAK
		.ELSE
			dec esi ; move down string by 1
			dec ecx ; decrease ecx counter
		.ENDIF
	.ENDW
	.IF PosBackSlash == 0 ; if for some reason we dont have the position
		mov eax, FALSE		  ; we should probably exit with an error
		ret
	.ENDIF		
	
	; Fetch just the module name based on last backslash position
	; and the fullstop positions that we found above.
	lea edi, ModuleName
	lea esi, ModuleFullPathname
	add esi, PosBackSlash
	inc esi ; skip over the \
	
	mov ecx, PosBackSlash
	inc ecx ; skip over the \
	.WHILE ecx < PosFullStop
		movzx eax, byte ptr [esi]
		mov byte ptr [edi], al
		inc esi
		inc edi
		inc ecx
	.ENDW
	mov byte ptr [edi], 0 ; zero last byte to terminate string.
	;----------------------------------------------------------------------

    
	.IF Version > 5 ; Vista / Win7			
		;----------------------------------------------------------------------
		; Glue all the bits together to make the new ini file location
		; 
		; include shell32.inc & includelib shell32.lib required for the 
		; SHGetSpecialFolderLocation & SHGetPathFromIDList functions
		;----------------------------------------------------------------------
        Invoke GetModuleHandle, NULL
        mov hInst, eax		
        Invoke SHGetSpecialFolderLocation, hInst, CSIDL_APPDATA, Addr ppidl
        Invoke SHGetPathFromIDList, ppidl, lpszIniFile
        Invoke lstrcat, lpszIniFile, Addr szBackslash	; add a backslash to this path
        Invoke lstrcat, lpszIniFile, Addr ModuleName	; and add our app exe name
        Invoke GetFileAttributes, lpszIniFile
        .IF eax != FILE_ATTRIBUTE_DIRECTORY				
            Invoke CreateDirectory, lpszIniFile, NULL	; create directory if needed
        .ENDIF
        Invoke lstrcat, lpszIniFile, Addr szBackslashChar	; add a backslash to this as well		

        Invoke lstrcat, lpszIniFile, Addr ModuleName ; add module name to our folder path
        invoke lstrcat, lpszIniFile, Addr szExtINI
		;----------------------------------------------------------------------
		
    .ELSE ; WinXP
        inc PosFullStop
		Invoke lstrcpyn, lpszIniFile, Addr ModuleFullPathname, PosFullStop
		Invoke lstrcat, lpszIniFile, Addr szExtINI
    .ENDIF
    .IF lpszBaseModuleName != NULL ; save the result to address specified by user
        Invoke lstrcpy, lpszBaseModuleName, Addr ModuleName ; (2nd parameter)
    .ENDIF
	mov eax, TRUE
	ret
IniCreateFilename ENDP


;--------------------------------------------------------------------------------------
; IniGetSettingExpandAllOnLoad
;--------------------------------------------------------------------------------------
IniGetSettingExpandAllOnLoad PROC
    Invoke GetPrivateProfileInt, Addr AppName, Addr szExpandAllOnLoad, 1, Addr szIniFilename
    mov g_ExpandAllOnLoad, eax
    ret
IniGetSettingExpandAllOnLoad ENDP


;--------------------------------------------------------------------------------------
; IniSetSettingExpandAllOnLoad
;--------------------------------------------------------------------------------------
IniSetSettingExpandAllOnLoad PROC dwValue:DWORD
    .IF dwValue == 0
        Invoke WritePrivateProfileString, Addr AppName, Addr szExpandAllOnLoad, Addr szZero, Addr szIniFilename
        mov g_ExpandAllOnLoad, 0
    .ELSE
        Invoke WritePrivateProfileString, Addr AppName, Addr szExpandAllOnLoad, Addr szOne, Addr szIniFilename
        mov g_ExpandAllOnLoad, 1
    .ENDIF
    mov eax, g_ExpandAllOnLoad
    ret
IniSetSettingExpandAllOnLoad ENDP


;--------------------------------------------------------------------------------------
; IniGetSettingCaseSensitiveSearch
;--------------------------------------------------------------------------------------
IniGetSettingCaseSensitiveSearch PROC
    Invoke GetPrivateProfileInt, Addr AppName, Addr szCaseSensitiveSearch, 1, Addr szIniFilename
    mov g_CaseSensitiveSearch, eax
    ret
IniGetSettingCaseSensitiveSearch ENDP


;--------------------------------------------------------------------------------------
; IniSetSettingCaseSensitiveSearch
;--------------------------------------------------------------------------------------
IniSetSettingCaseSensitiveSearch PROC dwValue:DWORD
    .IF dwValue == 0
        Invoke WritePrivateProfileString, Addr AppName, Addr szCaseSensitiveSearch, Addr szZero, Addr szIniFilename
        mov g_CaseSensitiveSearch, 0
    .ELSE
        Invoke WritePrivateProfileString, Addr AppName, Addr szCaseSensitiveSearch, Addr szOne, Addr szIniFilename
        mov g_CaseSensitiveSearch, 1
    .ENDIF
    mov eax, g_CaseSensitiveSearch
    ret
IniSetSettingCaseSensitiveSearch ENDP


;--------------------------------------------------------------------------------------
; IniToggleExpandAllOnLoad
;--------------------------------------------------------------------------------------
IniToggleExpandAllOnLoad PROC
    .IF g_ExpandAllOnLoad == 0
        mov g_ExpandAllOnLoad, 1
    .ELSE
        mov g_ExpandAllOnLoad, 0
    .ENDIF
    Invoke IniSetSettingExpandAllOnLoad, g_ExpandAllOnLoad
    ret
IniToggleExpandAllOnLoad ENDP


;--------------------------------------------------------------------------------------
; IniToggleCaseSensitiveSearch
;--------------------------------------------------------------------------------------
IniToggleCaseSensitiveSearch PROC
    .IF g_CaseSensitiveSearch == 0
        mov g_CaseSensitiveSearch, 1
    .ELSE
        mov g_CaseSensitiveSearch, 0
    .ENDIF
    Invoke IniSetSettingCaseSensitiveSearch, g_CaseSensitiveSearch
    ret
IniToggleCaseSensitiveSearch ENDP








