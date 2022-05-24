;==============================================================================
;
; RPC
;
; Copyright (c) 2022 by fearless
;
; All Rights Reserved
;
; http://github.com/mrfearless
;
;
; This software is provided 'as-is', without any express or implied warranty. 
; In no event will the author be held liable for any damages arising from the 
; use of this software.
;
; Permission is granted to anyone to use this software for any non-commercial 
; program. If you use the library in an application, an acknowledgement in the
; application or documentation is appreciated but not required. 
;
; You are allowed to make modifications to the source code, but you must leave
; the original copyright notices intact and not misrepresent the origin of the
; software. It is not allowed to claim you wrote the original software. 
; Modified files must have a clear notice that the files are modified, and not
; in the original state. This includes the name of the person(s) who modified 
; the code. 
;
; If you want to distribute or redistribute any portion of this package, you 
; will need to include the full package in it's original state, including this
; license and all the copyrights.  
;
; While distributing this package (in it's original state) is allowed, it is 
; not allowed to charge anything for this. You may not sell or include the 
; package in any commercial package without having permission of the author. 
; Neither is it allowed to redistribute any of the package's components with 
; commercial applications.
;
;==============================================================================
.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1
IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    include M:\Masm32\include\debug32.inc
ENDIF

include windows.inc

include user32.inc
include kernel32.inc
include wininet.inc
include masm32.inc

includelib user32.lib
includelib kernel32.lib
includelib wininet.lib
includelib masm32.lib

include RPC.inc


;-------------------------------------------------------------------------
; Prototypes for internal use
;-------------------------------------------------------------------------
RpcWriteDataToLocalFile PROTO :DWORD,:DWORD,:DWORD                              ; hRpc, lpszLocalFilename, pDataBuffer, dwDataBufferSize
RpcGetRemoteFileSize    PROTO :DWORD,:DWORD                                     ; hRpc, lpdwRemoteFileSize
RpcBase64Encode         PROTO :DWORD,:DWORD,:DWORD                              ; lpszSource, lpszDestination, dwSourceLength
RpcReplacePathVars      PROTO :DWORD,:DWORD                                     ; hRpc, lpszUrl

atou_ex                 PROTO :DWORD
utoa_ex                 PROTO :DWORD, :DWORD 


;-------------------------------------------------------------------------
; Structures for internal use
;-------------------------------------------------------------------------
IFNDEF RPC_HANDLE
RPC_HANDLE                      STRUCT
    hConnect                    DD 0    ; 
    hInternet                   DD 0    ; 
    hRequest                    DD 0    ; 
    bSecure                     DD 0    ; http or https
    dwStatusCode                DD 0    ; 
    lpszHostAddress             DD 0    ; hostname:port
    lpszUrl                     DD 0    ; url buffer
    lpszPathVariable            DD 0    ; /<variable>
    lpszQueryParameters         DD 0    ; url params buffer - "name=value" pairs
    lpszAcceptHeader            DD 0    ; "Accept: text/plain, application/json" etc
    lpszContentTypeHeader       DD 0    ; 
    lpszAuthHeader              DD 0    ; "Authorization: Basic <Base64Encoded(username:password)>"
    lpszApiKeyName              DD 0    ; name of api key to use: "api_key" for example
    lpszApiKeyValue             DD 0    ; value of api key: 7bf567042aea488ba256583eaebf638f
RPC_HANDLE                      ENDS
ENDIF

MAX_PATHVARIABLES               EQU 8

IFNDEF PATHVARIABLE
PATHVARIABLE                    STRUCT
    szVariable                  DB MAX_PATH DUP (0)
PATHVARIABLE                    ENDS
ENDIF

IFNDEF PATHVARIABLES
PATHVARIABLES                   STRUCT
    dwVarCount                  DD 0
    lpPathVariables             PATHVARIABLE MAX_PATHVARIABLES DUP ({})
PATHVARIABLES                   ENDS
ENDIF



.CONST
; WinInet constants
TIMER_INFINITE                  EQU 0FFFFFFFEh
FLAG_ICC_FORCE_CONNECTION       EQU 00000001h 
HTTP_QUERY_FLAG_NUMBER          EQU 20000000h
HTTP_QUERY_CONTENT_LENGTH       EQU 5
ERROR_WINHTTP_CANNOT_CONNECT    EQU 12029d ; Returned if connection to the server failed.

; Buffer sizes for fields in RPC_HANDLE
RPC_HOSTADDRESS_SIZE            EQU 256d
RPC_URL_SIZE                    EQU 8192d
RPC_QUERY_PARAMS_SIZE           EQU 4096d
RPC_PATH_VARIABLE_SIZE          EQU 256d
RPC_ACCEPT_HEADER_SIZE          EQU 256d
RPC_CONTENT_HEADER_SIZE         EQU 256d
RPC_AUTH_HEADER_SIZE            EQU 256d

RPC_READ_CHUNK_SIZE             EQU 2048d
RPC_READ_BUFFER_SIZE            EQU 4096d

; Ports
DEFAULT_HTTP_PORT               EQU 80d
DEFAULT_HTTPS_PORT              EQU 443d

.DATA
Base64Alphabet                  DB "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",0
TimeoutPeriod                   DD 1200d
RetryInterval                   DD 30000d ; secs

; Headers
szAuthHeaderBasicHeader         DB "Authorization: Basic ",0
szAcceptHeader                  DB "Accept: ",0
szContentTypeHeader             DB "Content-Type: ",0
szContentLengthHeader           DB "Content-Length",0

; RPC Type
szGetVerb                       DB "GET",0
szPostVerb                      DB "POST",0
szPutVerb                       DB "PUT",0
szPatchVerb                     DB "PATCH",0
szDeleteVerb                    DB "DELETE",0
szHeadVerb                      DB "HEAD",0
szOptionsVerb                   DB "OPTIONS",0

; Misc Text
szAcceptAll                     DB "*/*",0,0
szHttp                          DB "http://",0
szHttps                         DB "https://",0
szDefaultHttpPort               DB "80",0
szDefaultHttpsPort              DB "443",0
szDefaultLocalhost              DB "localhost",0

; Media Types
szMEDIATYPE_ALL                 DB "*/*",0,0
szMEDIATYPE_TEXT                DB "text/*",0,0
szMEDIATYPE_HTML                DB "text/html",0,0
szMEDIATYPE_XML                 DB "application/xml",0,0
szMEDIATYPE_JSON                DB "application/json",0,0
szMEDIATYPE_FORM                DB "application/x-www-form-urlencoded",0,0

IFDEF DEBUG32
RPC_DEBUG_BUILD_URL             DB MAX_PATH DUP (0) 
ENDIF

.CODE


;------------------------------------------------------------------------------------------------
; Checks connection status
; Returns TRUE if connected, FALSE otherwise
;------------------------------------------------------------------------------------------------
RpcCheckConnection PROC USES EBX lpszHost:DWORD, lpszPort:DWORD, bSecure:DWORD
    LOCAL szUrl[256]:BYTE
    
    Invoke RtlZeroMemory, Addr szUrl, 256
    
    IFDEF DEBUG32
        PrintText 'RpcCheckConnection'
    ENDIF
    
    .IF lpszHost == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, lpszHost
    mov eax, [ebx]
    .IF eax != "ptth"
        .IF bSecure
            Invoke szCopy, Addr szHttps, Addr szUrl
        .ELSE
            Invoke szCopy, Addr szHttp, Addr szUrl
        .ENDIF
        Invoke szCatStr, Addr szUrl, lpszHost
    .ELSE
        Invoke szCatStr, Addr szUrl, lpszHost
    .ENDIF
    Invoke szCatStr, Addr szUrl, CTEXT(":")
    .IF lpszPort == NULL
        Invoke szCatStr, Addr szUrl, Addr szDefaultHttpPort
    .ELSE
        Invoke szCatStr, Addr szUrl, lpszPort
    .ENDIF    
    IFDEF DEBUG32
        PrintText 'InternetCheckConnection'
    ENDIF
    Invoke InternetCheckConnection, Addr szUrl, FLAG_ICC_FORCE_CONNECTION, 0
    .IF eax == TRUE
        mov eax, TRUE
        ret
    .ENDIF
    Invoke GetLastError
    .IF eax == ERROR_WINHTTP_CANNOT_CONNECT
        mov eax, FALSE
    .ELSEIF eax == 0
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
RpcCheckConnection endp

;------------------------------------------------------------------------------
; RpcConnect - Connect to a host:port specifying agent and optionally HTTPS
; Returns: TRUE if succesful or FALSE otherwise. Returns RPC HANDLE (hRpc) in 
; the dword pointed to by lpdwRpcHandle.
;------------------------------------------------------------------------------
RpcConnect PROC USES EBX lpszHost:DWORD, lpszPort:DWORD, bSecure:DWORD, lpszUserAgent:DWORD, lpdwRpcHandle:DWORD
    LOCAL hRpc:DWORD
    LOCAL dwPort:DWORD
    LOCAL hInternet:DWORD
    LOCAL hConnect:DWORD
    LOCAL lpszHostAddress:DWORD
    LOCAL lpszUrl:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcConnect'
    ENDIF
    
    ;--------------------------------------------------------------------------
    ; Basic error checking
    ;--------------------------------------------------------------------------
    .IF lpszHost == NULL || lpdwRpcHandle == NULL
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    
    Invoke RpcCheckConnection, lpszHost, lpszPort, bSecure
    .IF eax == FALSE
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Create RPC HANDLE
    ;--------------------------------------------------------------------------
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, SIZEOF RPC_HANDLE
    .IF eax == NULL
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    mov hRpc, eax
    
    ;--------------------------------------------------------------------------
    ; Alloc memory for RPC handle fields
    ;--------------------------------------------------------------------------
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_HOSTADDRESS_SIZE
    .IF eax == NULL
        Invoke RpcDisconnect, hRpc
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    mov lpszHostAddress, eax
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_URL_SIZE
    .IF eax == NULL
        Invoke RpcDisconnect, hRpc
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    mov lpszUrl, eax
    
    ; Store host and port as lpszHostAddress in RPC HANDLE 
    mov ebx, lpszHost
    mov eax, [ebx]
    .IF eax != "ptth" && eax != 'PTTH' && eax != 'pttH'
        .IF bSecure
            Invoke lstrcpy, lpszHostAddress, Addr szHttps
        .ELSE
            Invoke lstrcpy, lpszHostAddress, Addr szHttp
        .ENDIF
        Invoke lstrcat, lpszHostAddress, lpszHost
    .ELSE
        Invoke lstrcpy, lpszHostAddress, lpszHost
    .ENDIF
    Invoke lstrcat, lpszHostAddress, CTEXT(":")
    .IF lpszPort == NULL
        Invoke lstrcat, lpszHostAddress, Addr szDefaultHttpPort
    .ELSE
        Invoke lstrcat, lpszHostAddress, lpszPort
    .ENDIF        
    ;
    ;--------------------------------------------------------------------------
    ; Open and Connect
    ;--------------------------------------------------------------------------
    Invoke InternetOpen, lpszUserAgent, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0 ;INTERNET_FLAG_NO_COOKIES + INTERNET_FLAG_NO_UI + INTERNET_FLAG_PRAGMA_NOCACHE
    .IF eax == NULL
        IFDEF DEBUG32
            PrintText 'InternetOpen Error'
            Invoke GetLastError
            PrintDec eax
        ENDIF
        Invoke RpcDisconnect, hRpc
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    mov hInternet, eax
    
    Invoke InternetSetOption, hInternet, INTERNET_OPTION_RECEIVE_TIMEOUT, Addr TimeoutPeriod, SIZEOF TimeoutPeriod
    .IF bSecure == TRUE
        mov dwPort, DEFAULT_HTTPS_PORT
    .ELSE    
        .IF lpszPort == 0
            mov dwPort, DEFAULT_HTTP_PORT
        .ELSE    
            Invoke atou_ex, lpszPort
            mov dwPort, eax
        .ENDIF
    .ENDIF
    
    Invoke InternetConnect, hInternet, lpszHost, dwPort, 0, 0, INTERNET_SERVICE_HTTP, 0, 0
    .IF eax == NULL
        IFDEF DEBUG32
            PrintText 'InternetConnect Error'
            Invoke GetLastError
            PrintDec eax
        ENDIF    
        .IF hInternet != NULL
            Invoke InternetCloseHandle, hInternet
        .ENDIF
        Invoke RpcDisconnect, hRpc
        mov ebx, lpdwRpcHandle
        mov eax, NULL
        mov [ebx], eax
        mov eax, FALSE
        ret
    .ENDIF
    mov hConnect, eax
    
    ;--------------------------------------------------------------------------
    ; Store information in RPC HANDLE
    ;--------------------------------------------------------------------------
    mov ebx, hRpc
    mov eax, hInternet
    mov [ebx].RPC_HANDLE.hInternet, eax
    mov eax, hConnect
    mov [ebx].RPC_HANDLE.hConnect, eax
    mov eax, lpszHostAddress
    mov [ebx].RPC_HANDLE.lpszHostAddress, eax
    mov eax, lpszUrl
    mov [ebx].RPC_HANDLE.lpszUrl, eax
    mov eax, bSecure
    mov [ebx].RPC_HANDLE.bSecure, eax
    
    ;--------------------------------------------------------------------------
    ; Return RPC HANDLE
    ;--------------------------------------------------------------------------
    mov ebx, lpdwRpcHandle
    mov eax, hRpc
    mov [ebx], eax
    
    mov eax, TRUE
    ret
RpcConnect ENDP

;------------------------------------------------------------------------------
; RpcDisconnect - Disconnect from previous connection made via RpcConnect
; Returns: None
;------------------------------------------------------------------------------
RpcDisconnect PROC USES EBX hRpc:DWORD
    LOCAL hInternet:DWORD
    LOCAL hConnect:DWORD
    LOCAL hRequest:DWORD
    LOCAL lpszHostAddress:DWORD
    LOCAL lpszUrl:DWORD
    LOCAL lpszPathVariable:DWORD
    LOCAL lpszQueryParameters:DWORD
    LOCAL lpszAcceptHeader:DWORD
    LOCAL lpszAuthHeader:DWORD
    LOCAL lpszApiKeyName:DWORD
    LOCAL lpszApiKeyValue:DWORD

    IFDEF DEBUG32
    PrintText 'RpcDisconnect'
    ENDIF
    
    .IF hRpc == NULL
        xor eax, eax
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.hInternet
    mov hInternet, eax
    mov eax, [ebx].RPC_HANDLE.hConnect
    mov hConnect, eax    
    mov eax, [ebx].RPC_HANDLE.hRequest
    mov hRequest, eax
    mov eax, [ebx].RPC_HANDLE.lpszHostAddress
    mov lpszHostAddress, eax
    mov eax, [ebx].RPC_HANDLE.lpszUrl
    mov lpszUrl, eax
    mov eax, [ebx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, eax
    mov eax, [ebx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, eax
    mov eax, [ebx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, eax
    mov eax, [ebx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, eax
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyName
    mov lpszApiKeyName, eax
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyValue
    mov lpszApiKeyValue, eax

    .IF hRequest != NULL
        Invoke HttpEndRequest, hRequest, NULL, 0, 0
        Invoke InternetCloseHandle, hRequest    
    .ENDIF
    .IF hConnect != NULL
        Invoke InternetCloseHandle, hConnect
    .ENDIF
    .IF hInternet != NULL
        Invoke InternetCloseHandle, hInternet
    .ENDIF
    
    .IF lpszHostAddress != NULL
        Invoke GlobalFree, lpszHostAddress
    .ENDIF
    .IF lpszUrl != NULL
        Invoke GlobalFree, lpszUrl
    .ENDIF
    .IF lpszPathVariable != NULL
        Invoke GlobalFree, lpszPathVariable
    .ENDIF
    .IF lpszQueryParameters != NULL
        Invoke GlobalFree, lpszQueryParameters
    .ENDIF
    .IF lpszAcceptHeader != NULL
        Invoke GlobalFree, lpszAcceptHeader
    .ENDIF
    .IF lpszAuthHeader != NULL
        Invoke GlobalFree, lpszAuthHeader
    .ENDIF
    .IF lpszApiKeyName != NULL
        Invoke GlobalFree, lpszApiKeyName
    .ENDIF
    .IF lpszApiKeyValue != NULL
        Invoke GlobalFree, lpszApiKeyValue
    .ENDIF
    
    Invoke GlobalFree, hRpc
    
    xor eax, eax   
    ret
RpcDisconnect ENDP

;------------------------------------------------------------------------------
; RpcSetCookie - Sets a cookie for the rpc connection opened via RpcConnect 
;------------------------------------------------------------------------------
RpcSetCookie PROC USES EBX hRpc:DWORD, lpszCookieData:DWORD
    LOCAL lpszHostAddress:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcSetCookie'
    ENDIF
    
    .IF hRpc == NULL
        xor eax, eax
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszHostAddress
    .IF eax == NULL
        xor eax, eax
        ret
    .ENDIF
    mov lpszHostAddress, eax
    
    Invoke InternetSetCookie, lpszHostAddress, NULL, lpszCookieData
    mov eax, TRUE
    ret
RpcSetCookie ENDP

;------------------------------------------------------------------------------
; RpcSetAuthBasic - Base64 encode user/pass and add to a Auth Header (Basic) 
; for use in the RpcEndpointOpen function.
; If lpszUsername & lpszPassword = NULL then any existing Auth Header is freed
;------------------------------------------------------------------------------
RpcSetAuthBasic PROC USES EBX hRpc:DWORD, lpszUsername:DWORD, lpszPassword:DWORD
    LOCAL lpszAuthHeader:DWORD
    LOCAL szBase64Auth[256]:BYTE
    LOCAL szPreBase64Auth[256]:BYTE

    IFDEF DEBUG32
    PrintText 'RpcSetAuthBasic'
    ENDIF

    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, eax
    
    .IF lpszUsername == NULL && lpszPassword == NULL
        .IF lpszAuthHeader != NULL
            Invoke GlobalFree, lpszAuthHeader
            mov ebx, hRpc
            mov [ebx].RPC_HANDLE.lpszAuthHeader, 0
        .ENDIF
        mov eax, TRUE
        ret        
    .ENDIF
    
    .IF lpszPassword == NULL
        xor eax, eax
        ret
    .ENDIF
    
    Invoke lstrlen, lpszPassword
    .IF eax == 0
        xor eax, eax
        ret
    .ENDIF
    
    .IF lpszAuthHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_AUTH_HEADER_SIZE
        .IF eax == NULL
            xor eax, eax
            ret
        .ENDIF
        mov lpszAuthHeader, eax
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.lpszAuthHeader, eax
    .ENDIF
    
    .IF lpszUsername != NULL
        Invoke lstrlen, lpszUsername
        .IF eax == 0
            Invoke lstrcpy, Addr szPreBase64Auth, CTEXT(":")
        .ELSE
            Invoke lstrcpy, Addr szPreBase64Auth, lpszUsername
        .ENDIF
    .ELSE
        Invoke lstrcpy, Addr szPreBase64Auth, CTEXT(":")
    .ENDIF
    Invoke lstrcat, Addr szPreBase64Auth, lpszPassword
    
    ; base 64 encode auth
    Invoke lstrlen, Addr szPreBase64Auth
    Invoke RpcBase64Encode, Addr szPreBase64Auth, Addr szBase64Auth, eax

    ; Add header
    Invoke lstrcpy, lpszAuthHeader, Addr szAuthHeaderBasicHeader
    Invoke lstrcat, lpszAuthHeader, Addr szBase64Auth
    
    mov eax, TRUE
    ret
RpcSetAuthBasic ENDP

;------------------------------------------------------------------------------
; RpcSetAcceptType - Add a media content type to a Accept Header for use in the
; RpcEndpointOpen function.
; If lpszAcceptType = NULL then any existing Accept Header is freed
;------------------------------------------------------------------------------
RpcSetAcceptType PROC USES EBX hRpc:DWORD, lpszAcceptType:DWORD, dwAcceptType:DWORD
    LOCAL lpszAcceptHeader:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcSetAcceptType'
    ENDIF

    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, eax
    
    .IF lpszAcceptType == NULL && dwAcceptType == RPC_MEDIATYPE_NONE
        .IF lpszAcceptHeader != NULL
            Invoke GlobalFree, lpszAcceptHeader
            mov ebx, hRpc
            mov [ebx].RPC_HANDLE.lpszAcceptHeader, 0
            mov eax, TRUE
            ret
        .ENDIF
    .ENDIF
    
    .IF lpszAcceptHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_ACCEPT_HEADER_SIZE
        .IF eax == NULL
            mov eax, FALSE
            ret
        .ENDIF
        mov lpszAcceptHeader, eax
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.lpszAcceptHeader, eax
    .ENDIF
    
    Invoke lstrlen, lpszAcceptHeader
    .IF eax == 0
        Invoke lstrcpy, lpszAcceptHeader, Addr szAcceptHeader
    .ELSE
        Invoke lstrcat, lpszAcceptHeader, CTEXT(", ")
    .ENDIF
    .IF lpszAcceptType != NULL
        Invoke lstrcat, lpszAcceptHeader, lpszAcceptType
    .ELSE
        mov eax, dwAcceptType
        .IF eax == RPC_MEDIATYPE_ALL
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_ALL
        .ELSEIF eax == RPC_MEDIATYPE_TEXT
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_TEXT
        .ELSEIF eax == RPC_MEDIATYPE_HTML
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_HTML
        .ELSEIF eax == RPC_MEDIATYPE_XML
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_XML
        .ELSEIF eax == RPC_MEDIATYPE_JSON
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_JSON
        .ELSEIF eax == RPC_MEDIATYPE_FORM
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_FORM
        .ELSE
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_ALL
        .ENDIF
    .ENDIF
    mov eax, TRUE
    ret
RpcSetAcceptType ENDP

;------------------------------------------------------------------------------
; RpcSetContentType - Add a media content type to a ContentType Header for use in the
; RpcEndpointOpen function.
; If lpszContentType = NULL then any existing ContentType Header is freed
;------------------------------------------------------------------------------
RpcSetContentType PROC USES EBX hRpc:DWORD, lpszContentType:DWORD, dwContentType:DWORD
    LOCAL lpszContentTypeHeader:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcSetAcceptType'
    ENDIF

    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszContentTypeHeader
    mov lpszContentTypeHeader, eax
    
    .IF lpszContentType == NULL && dwContentType == RPC_MEDIATYPE_NONE
        .IF lpszContentTypeHeader != NULL
            Invoke GlobalFree, lpszContentTypeHeader
            mov ebx, hRpc
            mov [ebx].RPC_HANDLE.lpszContentTypeHeader, 0
            mov eax, TRUE
            ret
        .ENDIF
    .ENDIF
    
    .IF lpszContentTypeHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_CONTENT_HEADER_SIZE
        .IF eax == NULL
            mov eax, FALSE
            ret
        .ENDIF
        mov lpszContentTypeHeader, eax
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.lpszContentTypeHeader, eax
    .ENDIF
    
    Invoke lstrlen, lpszContentTypeHeader
    .IF eax == 0
        Invoke lstrcpy, lpszContentTypeHeader, Addr szContentTypeHeader
    .ELSE
        Invoke lstrcat, lpszContentTypeHeader, CTEXT(", ")
    .ENDIF
    .IF lpszContentType != NULL
        Invoke lstrcat, lpszContentTypeHeader, lpszContentType
    .ELSE
        mov eax, dwContentType
        .IF eax == RPC_MEDIATYPE_ALL
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_ALL
        .ELSEIF eax == RPC_MEDIATYPE_TEXT
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_TEXT
        .ELSEIF eax == RPC_MEDIATYPE_HTML
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_HTML
        .ELSEIF eax == RPC_MEDIATYPE_XML
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_XML
        .ELSEIF eax == RPC_MEDIATYPE_JSON
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_JSON
        .ELSEIF eax == RPC_MEDIATYPE_FORM
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_FORM
        .ELSE
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_ALL
        .ENDIF
    .ENDIF
    mov eax, TRUE
    ret
RpcSetContentType ENDP

;------------------------------------------------------------------------------
; RpcSetApiKey - Add a api key and value to be included with endpoint calls
; lpszRpcApiKeyName = string for key name, examples: 'ApiKey' or 'api_key'
; lpszRpcApiKeyValue = string for api key value, for example: '7bf567042aea488ba256583eaebf638f'
; Automatically will be added to a Endpoint url in RpcEndpointOpen, example:
; '/GetInfo?api_key=7bf567042aea488ba256583eaebf638f'
;------------------------------------------------------------------------------
RpcSetApiKey PROC USES EBX hRpc:DWORD, lpszRpcApiKeyName:DWORD, lpszRpcApiKeyValue:DWORD
    LOCAL lpszApiKeyName:DWORD
    LOCAL lpszApiKeyValue:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcSetApiKey'
    ENDIF

    .IF hRpc == NULL || lpszRpcApiKeyName == NULL || lpszRpcApiKeyValue == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyName
    mov lpszApiKeyName, eax
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyValue
    mov lpszApiKeyValue, eax
    
    .IF lpszApiKeyName != NULL ; free previous
        Invoke GlobalFree, lpszApiKeyName
        mov ebx, hRpc
        mov eax, 0
        mov [ebx].RPC_HANDLE.lpszApiKeyName, eax
    .ENDIF
    
    .IF lpszApiKeyValue != NULL ; free previous
        Invoke GlobalFree, lpszApiKeyValue
        mov ebx, hRpc
        mov eax, 0
        mov [ebx].RPC_HANDLE.lpszApiKeyValue, eax
    .ENDIF
    
    Invoke lstrlen, lpszRpcApiKeyName
    .IF eax == 0
        mov eax, FALSE
        ret
    .ENDIF
    add eax, 4d
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, eax
    .IF eax == NULL
        mov eax, FALSE
        ret
    .ENDIF
    mov lpszApiKeyName, eax
    
    Invoke lstrlen, lpszRpcApiKeyValue
    .IF eax == 0
        Invoke GlobalFree, lpszApiKeyName
        mov eax, FALSE
        ret
    .ENDIF
    add eax, 4d
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, eax
    .IF eax == NULL
        Invoke GlobalFree, lpszApiKeyName
        mov eax, FALSE
        ret
    .ENDIF
    mov lpszApiKeyValue, eax
    
    ; copy content over
    Invoke lstrcpy, lpszApiKeyName, lpszRpcApiKeyName
    mov ebx, hRpc
    mov eax, lpszApiKeyName
    mov [ebx].RPC_HANDLE.lpszApiKeyName, eax
    
    Invoke lstrcpy, lpszApiKeyValue, lpszRpcApiKeyValue
    mov ebx, hRpc
    mov eax, lpszApiKeyValue
    mov [ebx].RPC_HANDLE.lpszApiKeyValue, eax
    
    ret
RpcSetApiKey ENDP


;------------------------------------------------------------------------------
; RpcSetPathVariable - Adds a path variable to the endpoint url
; If lpszPathVariable = NULL, the buffer used internally is zeroed out.
;------------------------------------------------------------------------------
RpcSetPathVariable PROC USES EBX hRpc:DWORD, lpszVariable:DWORD
    LOCAL lpszPathVariable:DWORD
    
    IFDEF DEBUG32
    PrintText 'RpcSetPathVariable'
    ENDIF
    
    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, eax
    
    .IF lpszVariable == NULL
        .IF lpszPathVariable != NULL
            Invoke lstrlen, lpszPathVariable
            .IF eax == 0
                mov eax, TRUE
                ret
            .ELSEIF eax > RPC_PATH_VARIABLE_SIZE
                mov eax, RPC_PATH_VARIABLE_SIZE
            .ENDIF
            Invoke RtlZeroMemory, lpszPathVariable, eax
        .ENDIF
        mov eax, TRUE
        ret
    .ENDIF
    
    .IF lpszPathVariable == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_PATH_VARIABLE_SIZE
        .IF eax == NULL
            mov eax, FALSE
            ret
        .ENDIF
        mov lpszPathVariable, eax
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.lpszPathVariable, eax
    .ENDIF    

    Invoke lstrlen, lpszPathVariable
    .IF eax > RPC_PATH_VARIABLE_SIZE
        mov eax, FALSE
        ret
    .ENDIF
    
    Invoke lstrcpy, lpszPathVariable, lpszVariable
    
    mov eax, TRUE
    ret
RpcSetPathVariable ENDP

;------------------------------------------------------------------------------
; RpcSetQueryParameters - Constructs and adds Query Parameters (?name=value pairs) 
; to the endpoint url
; If lpszName = NULL, the buffer used internally is zeroed out.
;------------------------------------------------------------------------------
RpcSetQueryParameters PROC USES EBX hRpc:DWORD, lpszName:DWORD, lpszValue:DWORD, dwValue:DWORD
    LOCAL lpszQueryParameters:DWORD
    LOCAL szValue[32]:BYTE
    
    IFDEF DEBUG32
    PrintText 'RpcSetQueryParameters'
    ENDIF
    
    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, eax
    
    .IF lpszName == NULL
        .IF lpszQueryParameters != NULL
            Invoke lstrlen, lpszQueryParameters
            .IF eax == 0
                mov eax, TRUE
                ret
            .ELSEIF eax > RPC_QUERY_PARAMS_SIZE
                mov eax, RPC_QUERY_PARAMS_SIZE
            .ENDIF
            Invoke RtlZeroMemory, lpszQueryParameters, eax
        .ENDIF
        mov eax, TRUE
        ret
    .ENDIF
    
    .IF lpszQueryParameters == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_QUERY_PARAMS_SIZE
        .IF eax == NULL
            mov eax, FALSE
            ret
        .ENDIF
        mov lpszQueryParameters, eax
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.lpszQueryParameters, eax
    .ENDIF    

    Invoke lstrlen, lpszQueryParameters
    .IF eax > RPC_QUERY_PARAMS_SIZE
        mov eax, FALSE
        ret
    .ELSEIF eax == 0
        Invoke lstrcpy, lpszQueryParameters, CTEXT("?")
    .ELSE
        Invoke lstrcat, lpszQueryParameters, CTEXT("?")
    .ENDIF
    
    Invoke lstrcat, lpszQueryParameters, lpszName
    Invoke lstrcat, lpszQueryParameters, CTEXT("=")
    .IF lpszValue != NULL
        Invoke lstrcat, lpszQueryParameters, lpszValue
    .ELSE
        Invoke utoa_ex, dwValue, Addr szValue
        Invoke lstrcat, lpszQueryParameters, Addr szValue
    .ENDIF
    
    mov eax, TRUE
    ret
RpcSetQueryParameters ENDP

;------------------------------------------------------------------------------
; RpcEndpointOpen - Opens a endpoint url, lpszEndpointUrl is the long pointer
; to a zero terminated string containing the url to open. 
; if lpszVerb == NULL then defaults to GET
; lpSendData and dwSendDataSize are typically for POST sending data
; if dwSendDataSize == -1 then assume lpSendData is ascii and will calc length
; Returns: TRUE if succesfull, otherwise FALSE.
;------------------------------------------------------------------------------
RpcEndpointOpen PROC USES EBX hRpc:DWORD, lpszVerb:DWORD, lpszEndpointUrl:DWORD, lpSendData:DWORD, dwSendDataSize:DWORD
    LOCAL bSecure:DWORD
    LOCAL hConnect:DWORD
    LOCAL hRequest:DWORD
    LOCAL lpszUrl:DWORD
    LOCAL lpszPathVariable:DWORD
    LOCAL lpszQueryParameters:DWORD
    LOCAL lpszAcceptHeader:DWORD
    LOCAL lpszContentTypeHeader:DWORD
    LOCAL lpszAuthHeader:DWORD
    LOCAL lpszApiKeyName:DWORD
    LOCAL lpszApiKeyValue:DWORD
    LOCAL dwStatusCode:DWORD
    LOCAL dwSizeStatusCode:DWORD
    LOCAL lpdwIndex:DWORD
    
    IFDEF DEBUG32
        PrintText 'RpcEndpointOpen'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Fetch RPC HANDLE field values
    ;--------------------------------------------------------------------------
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.hConnect
    mov hConnect, eax
    mov eax, [ebx].RPC_HANDLE.bSecure
    mov bSecure, eax
    mov eax, [ebx].RPC_HANDLE.lpszUrl
    mov lpszUrl, eax
    mov eax, [ebx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, eax
    mov eax, [ebx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, eax
    mov eax, [ebx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, eax
    mov eax, [ebx].RPC_HANDLE.lpszContentTypeHeader
    mov lpszContentTypeHeader, eax
    mov eax, [ebx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, eax
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyName
    mov lpszApiKeyName, eax
    mov eax, [ebx].RPC_HANDLE.lpszApiKeyValue
    mov lpszApiKeyValue, eax
    
    .IF hConnect == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov lpdwIndex, 0
    mov hRequest, 0
    mov dwStatusCode, 0
    mov dwSizeStatusCode, SIZEOF DWORD
    
    ;--------------------------------------------------------------------------
    ; Add path parameter and/or query parameters to endpoint url
    ; alternatively use HttpAddRequestHeaders and use key value pairs of query
    ; parameters - todo perhaps.
    ;--------------------------------------------------------------------------
    .IF lpszPathVariable == NULL && lpszQueryParameters == NULL
        ; No path variable and query parameters to add to endpoint url
        ;mov eax, lpszEndpointUrl
        ;mov lpszUrl, eax
        Invoke lstrcpy, lpszUrl, lpszEndpointUrl
    .ELSEIF lpszPathVariable != NULL && lpszQueryParameters == NULL
        ; Add path variable to endpoint url
        Invoke lstrlen, lpszPathVariable
        .IF eax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszPathVariable
        .ENDIF
    .ELSEIF lpszPathVariable == NULL && lpszQueryParameters != NULL
        ; Add query parameters to the endpoint url
        Invoke lstrlen, lpszQueryParameters
        .IF eax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszQueryParameters
        .ENDIF
    .ELSE ; lpszPathVariable != NULL && lpszQueryParameters != NULL 
        ; Add both path variable and query parameters to endpoint url
        Invoke lstrlen, lpszPathVariable
        .IF eax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszPathVariable
            Invoke lstrlen, lpszQueryParameters
            .IF eax != 0
                Invoke lstrcat, lpszUrl, lpszQueryParameters
            .ENDIF
        .ELSE
            Invoke lstrlen, lpszQueryParameters
            .IF eax != 0
                Invoke lstrcpy, lpszUrl, lpszEndpointUrl
                Invoke lstrcat, lpszUrl, lpszQueryParameters
            .ENDIF
        .ENDIF
    .ENDIF
    
    ; Add Api Key and Api Key Value if they exist and are set
    .IF lpszApiKeyName != NULL && lpszApiKeyValue != NULL
        Invoke lstrlen, lpszApiKeyName
        .IF eax != 0
            Invoke lstrcat, lpszUrl, CTEXT("?")
            Invoke lstrcat, lpszUrl, lpszApiKeyName
            Invoke lstrcat, lpszUrl, CTEXT("=")
        .ENDIF
        Invoke lstrlen, lpszApiKeyValue
        .IF eax != 0
            Invoke lstrcat, lpszUrl, lpszApiKeyValue
        .ENDIF
    .ENDIF
    
    
    IFDEF DEBUG32
    Invoke lstrcpy, Addr RPC_DEBUG_BUILD_URL, lpszUrl
    PrintString RPC_DEBUG_BUILD_URL
    ENDIF
    
    ;--------------------------------------------------------------------------
    ; RpcEndpointOpen--HttpOpenRequest
    ;--------------------------------------------------------------------------
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpOpenRequest'
    ENDIF
    .IF bSecure == TRUE
        Invoke HttpOpenRequest, hConnect, lpszVerb, lpszUrl, NULL, NULL, NULL, INTERNET_FLAG_SECURE or INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE or INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_RELOAD, 0 ;+ INTERNET_FLAG_EXISTING_CONNECTINTERNET_FLAG_NO_CACHE_WRITE + INTERNET_FLAG_RELOAD
    .ELSE
        Invoke HttpOpenRequest, hConnect, lpszVerb, lpszUrl, NULL, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE or INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_RELOAD, 0 ;+ INTERNET_FLAG_EXISTING_CONNECTINTERNET_FLAG_NO_CACHE_WRITE + INTERNET_FLAG_RELOAD
    .ENDIF
    .IF eax == NULL
        IFDEF DEBUG32
            Invoke GetLastError
            PrintDec eax
            PrintText 'RpcEndpointOpen--HttpOpenRequest Error'
            PrintStringByAddr lpszEndpointUrl
        ENDIF
        mov ebx, hRpc
        mov eax, dwStatusCode
        mov [ebx].RPC_HANDLE.dwStatusCode, eax
        mov eax, FALSE
        ret
    .ENDIF
    mov hRequest, eax
    mov ebx, hRpc
    mov [ebx].RPC_HANDLE.hRequest, eax
    
    ;--------------------------------------------------------------------------
    ; Add additional headers to request
    ;--------------------------------------------------------------------------
    ; Add Auth Header if required
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszAuthHeader'
    ENDIF
    .IF lpszAuthHeader != 0
        Invoke lstrlen, lpszAuthHeader
        .IF eax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszAuthHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ENDIF
    
    ; Add Accept Header if required
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszAcceptHeader'
    ENDIF
    .IF lpszAcceptHeader != 0
        Invoke lstrlen, lpszAcceptHeader
        .IF eax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszAcceptHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ELSE
            Invoke HttpAddRequestHeaders, hRequest, Addr szAcceptAll, -1, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ELSE
        Invoke HttpAddRequestHeaders, hRequest, Addr szAcceptAll, -1, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
    .ENDIF
    
    ; Add Content-Type Header if required
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszContentTypeHeader'
    ENDIF
    .IF lpszContentTypeHeader != 0
        Invoke lstrlen, lpszContentTypeHeader
        .IF eax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszContentTypeHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; RpcEndpointOpen--HttpSendRequest
    ;--------------------------------------------------------------------------
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpSendRequest'
    ENDIF
    .IF lpSendData != NULL && dwSendDataSize != 0 ; Typically for POST data
        .IF dwSendDataSize == -1 ; if -1 assume zero terminated ascii data, so get length
            Invoke lstrlen, lpSendData
            Invoke HttpSendRequest, hRequest, NULL, 0, lpSendData, eax
        .ELSE
            Invoke HttpSendRequest, hRequest, NULL, 0, lpSendData, dwSendDataSize
        .ENDIF
    .ELSE
        Invoke HttpSendRequest, hRequest, NULL, 0, NULL, 0
    .ENDIF
    .IF eax != TRUE
        IFDEF DEBUG32
        PrintText 'RpcEndpointOpen--HttpSendRequest--HttpQueryInfo'
        ENDIF
        Invoke HttpQueryInfo, hRequest, HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER, Addr dwStatusCode, Addr dwSizeStatusCode, Addr lpdwIndex
        IFDEF DEBUG32
            Invoke GetLastError
            PrintDec eax
            PrintText 'RpcEndpointOpen--HttpSendRequest Error'
        ENDIF
        mov ebx, hRpc
        mov eax, dwStatusCode
        mov [ebx].RPC_HANDLE.dwStatusCode, eax
        mov eax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Tidy up and return
    ;--------------------------------------------------------------------------
    ; Clear lpszPathVariable
    Invoke RpcSetPathVariable, hRpc, NULL
    
    ; Clear lpszQueryParameters
    Invoke RpcSetQueryParameters, hRpc, NULL, NULL, NULL
    
    IFDEF DEBUG32
    PrintText 'RpcEndpointOpen--HttpQueryInfo'
    ENDIF
    Invoke HttpQueryInfo, hRequest, HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER, Addr dwStatusCode, Addr dwSizeStatusCode, Addr lpdwIndex
    mov ebx, hRpc
    mov eax, dwStatusCode
    mov [ebx].RPC_HANDLE.dwStatusCode, eax
    .IF dwStatusCode >= 400 && dwStatusCode <= 500
        IFDEF DEBUG32
        PrintText 'RpcEndpointOpen--HttpSendRequest finished - Status 400-500'
        ENDIF
        mov eax, FALSE
    .ELSE
        IFDEF DEBUG32
        PrintText 'RpcEndpointOpen--HttpSendRequest finished'
        ENDIF
        mov eax, TRUE
    .ENDIF
    ret
RpcEndpointOpen ENDP

;------------------------------------------------------------------------------
; RpcEndpointClose - closes and endpoint url opened by RpcEndpointOpen
;------------------------------------------------------------------------------
RpcEndpointClose PROC hRpc:DWORD
    LOCAL hRequest:DWORD
    
    IFDEF DEBUG32
        PrintText 'RpcEndpointClose'
    ENDIF        
    
    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.hRequest
    mov hRequest, eax
    
    .IF hRequest != NULL
        Invoke HttpEndRequest, hRequest, NULL, 0, 0
        Invoke InternetCloseHandle, hRequest
        mov ebx, hRpc
        mov [ebx].RPC_HANDLE.hRequest, 0
    .ENDIF
    
    mov eax, TRUE
    ret
RpcEndpointClose ENDP

;------------------------------------------------------------------------------
; RpcEndpointReadData - Read endpoint url data and return pointer to data in 
; lpdwDataBuffer, along with size of data in lpdwTotalBytesRead. 
; Returns TRUE if succesful or FALSE otherwise.
; Notes: Use RpcEndpointFreeData after finishing processing file data to free memory  
;------------------------------------------------------------------------------
RpcEndpointReadData PROC USES EBX EDX EDI hRpc:DWORD, lpdwDataBuffer:DWORD, lpdwTotalBytesRead:DWORD
    LOCAL hRequest:DWORD
    LOCAL BytesRead:DWORD
    LOCAL BytesToRead:DWORD
    LOCAL BytesLeftToRead:DWORD
    LOCAL Position:DWORD
    LOCAL pDataBuffer:DWORD
    LOCAL SizeDataBuffer:DWORD
    LOCAL looptrue:DWORD
    LOCAL readchunks:DWORD
    LOCAL DataBufferChunkSize:DWORD

    IFDEF DEBUG32
        PrintText 'RpcEndpointReadData'
    ENDIF
    
    .IF hRpc == NULL
        mov eax, FALSE
        ret
    .ENDIF
    
    .IF lpdwDataBuffer == NULL
        .IF lpdwTotalBytesRead != NULL
            mov ebx, lpdwTotalBytesRead
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        mov eax, FALSE
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.hRequest
    .IF eax == NULL
        mov eax, FALSE
        ret
    .ENDIF
    mov hRequest, eax

    Invoke RpcGetRemoteFileSize, hRpc, Addr BytesToRead
    .IF eax == TRUE && BytesToRead != 0
        mov eax, BytesToRead
        add eax, 4d
        mov SizeDataBuffer, eax
        mov readchunks, FALSE
    .ELSE
        mov readchunks, TRUE
        mov BytesToRead, RPC_READ_CHUNK_SIZE
        mov eax, BytesToRead
        add eax, 4d
        mov SizeDataBuffer, eax
        ;mov SizeDataBuffer, RPC_READ_BUFFER_SIZE
    .ENDIF
    mov pDataBuffer, 0


    ;--------------------------------------------------------------------------
    ; Alloc initial memory for read buffer
    ;--------------------------------------------------------------------------
    IFDEF DEBUG32
        PrintText 'RpcEndpointReadData-GlobalAlloc'
    ENDIF
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, SizeDataBuffer
    .IF eax == NULL
        IFDEF DEBUG32
            PrintText 'RpcEndpointReadData-GlobalAlloc Error'
        ENDIF
        mov ebx, lpdwDataBuffer
        mov eax, 0
        mov [ebx], eax
        .IF lpdwTotalBytesRead != NULL
            mov ebx, lpdwTotalBytesRead
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        mov eax, FALSE
        ret
    .ENDIF
    mov pDataBuffer, eax

    .IF readchunks == FALSE ; try to read all in at once
        IFDEF DEBUG32
            PrintText 'RpcEndpointReadData-InternetReadFile-Try To Read All In'
        ENDIF
        Invoke InternetReadFile, hRequest, pDataBuffer, BytesToRead, Addr BytesRead
        .IF eax == FALSE
            IFDEF DEBUG32
                PrintText 'RpcEndpointReadData-InternetReadFile Error'
                Invoke GetLastError
                PrintDec eax
            ENDIF
            .IF pDataBuffer != NULL
                Invoke GlobalFree, pDataBuffer
            .ENDIF
            mov ebx, lpdwDataBuffer
            mov eax, 0
            mov [ebx], eax
            .IF lpdwTotalBytesRead != NULL
                mov ebx, lpdwTotalBytesRead
                mov eax, 0
                mov [ebx], eax
            .ENDIF
            mov eax, FALSE
            ret
        .ELSE
        
            .IF eax == TRUE && BytesRead == 0 ; finished all reads
                mov eax, BytesRead
                mov Position, eax
                ; return data, size and exit
            .ELSE ; more data to retrieve
                mov eax, BytesRead
                mov Position, eax
                
                mov eax, BytesToRead
                sub eax, BytesRead
                .IF sdword ptr eax > 0 ; more to get
                    mov BytesLeftToRead, eax
                    IFDEF DEBUG32
                        PrintText 'RpcEndpointReadData-InternetReadFile-More Data To Read'
                    ENDIF
                
                    mov eax, TRUE
                    .WHILE eax == TRUE && BytesRead != 0 ; continue
                       
                        mov edi, pDataBuffer
                        add edi, Position
                        
                        Invoke InternetReadFile, hRequest, edi, BytesLeftToRead, Addr BytesRead
                        mov looptrue, eax
                        .IF eax == FALSE
                            IFDEF DEBUG32
                                PrintText 'RpcEndpointReadData-InternetReadFile Error'
                                Invoke GetLastError
                                PrintDec eax
                            ENDIF
                            .IF pDataBuffer != NULL
                                Invoke GlobalFree, pDataBuffer
                            .ENDIF
                            mov ebx, lpdwDataBuffer
                            mov eax, 0
                            mov [ebx], eax
                            .IF lpdwTotalBytesRead != NULL
                                mov ebx, lpdwTotalBytesRead
                                mov eax, 0
                                mov [ebx], eax
                            .ENDIF
                            mov eax, FALSE
                            ret
                        .ELSE
                            .IF eax == TRUE && BytesRead == 0 ; finished all reads
                                ; return data, size and exit
                                mov looptrue, FALSE
                                .BREAK
                            .ELSE ; more data to retrieve
                                
                            .ENDIF
                        .ENDIF
                        
                        mov eax, BytesRead
                        add Position, eax
                        
                        mov eax, looptrue
                    .ENDW
                .ENDIF
            .ENDIF
        .ENDIF    
    
    .ELSE ; read in content in chunks
        IFDEF DEBUG32
            PrintText 'RpcEndpointReadData-InternetReadFile-Read Data In Chunks'
        ENDIF
        
        mov BytesRead, 1
        mov Position, 0 
        mov eax, TRUE
        .WHILE eax == TRUE && BytesRead != 0 ; continue
            
            mov edi, pDataBuffer
            add edi, Position
    
            Invoke InternetReadFile, hRequest, edi, BytesToRead, Addr BytesRead
            mov looptrue, eax
            .IF eax == FALSE
                IFDEF DEBUG32
                    PrintText 'RpcEndpointReadData-InternetReadFile Error'
                    Invoke GetLastError
                    PrintDec eax
                ENDIF
                .IF pDataBuffer != NULL
                    Invoke GlobalFree, pDataBuffer
                .ENDIF
                mov ebx, lpdwDataBuffer
                mov eax, 0
                mov [ebx], eax
                .IF lpdwTotalBytesRead != NULL
                    mov ebx, lpdwTotalBytesRead
                    mov eax, 0
                    mov [ebx], eax
                .ENDIF
                mov eax, FALSE
                ret
            .ELSE
                .IF eax == TRUE && BytesRead == 0 ; finished all reads
                    ; return data, size and exit
                    mov looptrue, FALSE
                    .BREAK                    
                .ELSE  ; more data to retrieve so realloc buffer and loop
                    mov eax, BytesToRead
                    add SizeDataBuffer, eax
        
                    IFDEF DEBUG32
                        PrintText 'RpcEndpointReadData-GlobalReAlloc'
                    ENDIF
                    Invoke GlobalReAlloc, pDataBuffer, SizeDataBuffer, GMEM_ZEROINIT or GMEM_MOVEABLE ; eax new pointer to mem
                    .IF eax == NULL
                        IFDEF DEBUG32
                            PrintText 'RpcEndpointReadData-GlobalReAlloc Error'
                            Invoke GetLastError
                            PrintDec eax
                        ENDIF
                        .IF pDataBuffer != NULL
                            Invoke GlobalFree, pDataBuffer
                        .ENDIF
                        mov ebx, lpdwDataBuffer
                        mov eax, 0
                        mov [ebx], eax
                        .IF lpdwTotalBytesRead != NULL
                            mov ebx, lpdwTotalBytesRead
                            mov eax, 0
                            mov [ebx], eax
                        .ENDIF
                        mov eax, FALSE
                        ret                
                    .ENDIF
                    mov pDataBuffer, eax
                .ENDIF
            .ENDIF
            
            mov eax, BytesRead
            add Position, eax            
            
            mov eax, looptrue
        .ENDW
        
    .ENDIF

    ;--------------------------------------------------------------------------
    ; Return pointers to buffer and buffer size
    ;--------------------------------------------------------------------------
    mov ebx, lpdwDataBuffer
    mov eax, pDataBuffer
    mov [ebx], eax
    .IF lpdwTotalBytesRead != NULL
        mov ebx, lpdwTotalBytesRead
        mov eax, Position
        mov [ebx], eax
    .ENDIF
    
    mov eax, TRUE
    ret
RpcEndpointReadData ENDP

;------------------------------------------------------------------------------
; RpcEndpointFreeData - Frees allocated memory used by RpcEndpointReadData
;------------------------------------------------------------------------------
RpcEndpointFreeData PROC USES EBX lpdwDataBuffer:DWORD

    IFDEF DEBUG32
    PrintText 'RpcEndpointFreeData'
    ENDIF
    
    .IF lpdwDataBuffer != NULL
        mov ebx, lpdwDataBuffer
        mov eax, [ebx]
        .IF eax != NULL
            Invoke GlobalFree, eax
        .ENDIF
        mov ebx, lpdwDataBuffer
        mov eax, 0
        mov [ebx], eax
    .ENDIF
    xor eax, eax
    ret
RpcEndpointFreeData ENDP

;------------------------------------------------------------------------------
; RpcEndpointGET - Access lpszEndpointUrl via GET and optionally return data
; if lpdwData is not null. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; Data returned will be stored as a pointer in the DWORD pointed to by lpdwData
; 
; If data is to be returned, then the DWORD pointed to by lpdwDataSize will 
; contain the size of the data pointed to by lpdwData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszDataToFile is optional, and points to a string containing a filename to 
; write returned data to.
;------------------------------------------------------------------------------
RpcEndpointGET PROC USES EBX hRpc:DWORD, lpszEndpointUrl:DWORD, lpdwData:DWORD, lpdwDataSize:DWORD, lpszDataToFile:DWORD
    LOCAL pDataBuffer:DWORD
    LOCAL dwDataBufferSize:DWORD
    
    IFDEF DEBUG32
        PrintText 'RpcEndpointGET'
    ENDIF     
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpdwData != NULL
            mov ebx, lpdwData
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        .IF lpdwDataSize != NULL
            mov ebx, lpdwDataSize
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Open GET endpoint
    ;--------------------------------------------------------------------------
    IFDEF DEBUG32
        PrintText 'RpcEndpointGET-RpcEndpointOpen'
    ENDIF      
    Invoke RpcEndpointOpen, hRpc, Addr szGetVerb, lpszEndpointUrl, NULL, 0
    .IF eax == FALSE
        IFDEF DEBUG32
            PrintText 'RpcEndpointGET-RpcEndpointOpen Error'
        ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    .IF lpdwData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) if status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            IFDEF DEBUG32
                PrintText 'RpcEndpointGET-RpcEndpointReadData'
            ENDIF          
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr dwDataBufferSize
            .IF eax == FALSE ;|| pDataBuffer == NULL
                IFDEF DEBUG32
                    PrintText 'RpcEndpointGET-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor eax, eax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszDataToFile != NULL
                .IF pDataBuffer != NULL && dwDataBufferSize != 0
                    Invoke RpcWriteDataToLocalFile, lpszDataToFile, pDataBuffer, dwDataBufferSize
                .ENDIF
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov ebx, lpdwData
            mov eax, pDataBuffer
            mov [ebx], eax
            
            .IF lpdwDataSize != NULL
                mov ebx, lpdwDataSize
                mov eax, dwDataBufferSize
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov ebx, lpdwData
            mov eax, 0
            mov [ebx], eax
            
            .IF lpdwDataSize != NULL
                mov ebx, lpdwDataSize
                mov eax, 0
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            mov eax, TRUE
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ENDIF
    ret
RpcEndpointGET ENDP

;------------------------------------------------------------------------------
; RpcEndpointPOST - Access lpszEndpointUrl via POST and optionally send and/or 
; return data. If lpPostData is != NULL, then will send data, if lpdwData is 
; != NULL then will return data. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; if sending data, then dwPostDataSize must include the size of data.
; 
; Data returned will be stored as a pointer in the DWORD pointed to by lpdwData
;
; If data is to be returned, then the DWORD pointed to by lpdwDataSize will 
; contain the size of the data pointed to by lpData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszDataToFile is optional, and points to a string containing a filename to 
; write returned data to.
;------------------------------------------------------------------------------
RpcEndpointPOST PROC USES EBX hRpc:DWORD, lpszEndpointUrl:DWORD, lpPostData:DWORD, dwPostDataSize:DWORD, lpdwData:DWORD, lpdwDataSize:DWORD, lpszDataToFile:DWORD
    LOCAL pDataBuffer:DWORD
    LOCAL dwDataBufferSize:DWORD
    
    IFDEF DEBUG32
        PrintText 'RpcEndpointPOST'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpdwData != NULL
            mov ebx, lpdwData
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        .IF lpdwDataSize != NULL
            mov ebx, lpdwDataSize
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Open POST endpoint and send data if we have some to send
    ;--------------------------------------------------------------------------
    .IF lpPostData != NULL && dwPostDataSize != 0
        Invoke RpcEndpointOpen, hRpc, Addr szPostVerb, lpszEndpointUrl, lpPostData, dwPostDataSize
    .ELSE
        Invoke RpcEndpointOpen, hRpc, Addr szPostVerb, lpszEndpointUrl, NULL, 0
    .ENDIF
    .IF eax == FALSE
        IFDEF DEBUG32
            PrintText 'RpcEndpointPOST-RpcEndpointOpen Error'
        ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    .IF lpdwData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) and status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr dwDataBufferSize
            .IF eax == FALSE ;|| pDataBuffer == NULL
                IFDEF DEBUG32
                    PrintText 'RpcEndpointPOST-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor eax, eax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszDataToFile != NULL
                .IF pDataBuffer != NULL && dwDataBufferSize != 0
                    Invoke RpcWriteDataToLocalFile, lpszDataToFile, pDataBuffer, dwDataBufferSize
                .ENDIF
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov ebx, lpdwData
            mov eax, pDataBuffer
            mov [ebx], eax
            
            .IF lpdwDataSize != NULL
                mov ebx, lpdwDataSize
                mov eax, dwDataBufferSize
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov ebx, lpdwData
            mov eax, 0
            mov [ebx], eax
            
            .IF lpdwDataSize != NULL
                mov ebx, lpdwDataSize
                mov eax, 0
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            mov eax, TRUE
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ENDIF
    ret
RpcEndpointPOST ENDP

;------------------------------------------------------------------------------
; RpcEndpointCall - Access lpszEndpointUrl and optionally send and / or 
; return data. If lpSendData is != NULL, then will send data, if 
; lpdwReceiveData is != NULL then will return data. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; if sending data, then dwSendDataSize must include the size of data.
; 
; Data returned will be stored as a pointer in the DWORD pointed to by 
; lpdwReceiveData
;
; If data is to be returned, then the DWORD pointed to by lpdwReceiveDataSize 
; will contain the size of the data pointed to by lpdwReceiveData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszReceiveDataFile is optional, and points to a string containing a filename
; to write returned data to (in addition to returned data via lpdwReceiveData).
;------------------------------------------------------------------------------
RpcEndpointCall PROC USES EBX hRpc:DWORD, dwRpcType:DWORD, lpszEndpointUrl:DWORD, lpSendData:DWORD, dwSendDataSize:DWORD, lpdwReceiveData:DWORD, lpdwReceiveDataSize:DWORD, lpszReceiveDataFile:DWORD
    LOCAL pDataBuffer:DWORD
    LOCAL dwDataBufferSize:DWORD
    LOCAL lpszVerb:DWORD
    
    IFDEF DEBUG32
        PrintText 'RpcEndpointCall'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpdwReceiveData != NULL
            mov ebx, lpdwReceiveData
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        .IF lpdwReceiveDataSize != NULL
            mov ebx, lpdwReceiveDataSize
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    mov eax, dwRpcType
    .IF eax == RPC_GET
        lea eax, szGetVerb
    .ELSEIF eax == RPC_POST
        lea eax, szPostVerb
    .ELSEIF eax == RPC_PUT
        lea eax, szPutVerb
    .ELSEIF eax == RPC_PATCH
        lea eax, szPatchVerb
    .ELSEIF eax == RPC_DELETE
        lea eax, szDeleteVerb
    .ELSEIF eax == RPC_HEAD
        lea eax, szHeadVerb
    .ELSEIF eax == RPC_OPTIONS
        lea eax, szOptionsVerb
    .ELSE
        lea eax, szGetVerb
    .ENDIF
    mov lpszVerb, eax
    
    ;--------------------------------------------------------------------------
    ; Open endpoint and send data if we have some to send
    ;--------------------------------------------------------------------------
    .IF lpSendData != NULL && dwSendDataSize != 0
        Invoke RpcEndpointOpen, hRpc, lpszVerb, lpszEndpointUrl, lpSendData, dwSendDataSize
    .ELSE
        Invoke RpcEndpointOpen, hRpc, lpszVerb, lpszEndpointUrl, NULL, 0
    .ENDIF
    .IF eax == FALSE
        IFDEF DEBUG32
            PrintText 'RpcEndpointCall-RpcEndpointOpen Error'
        ENDIF
        xor eax, eax
        ret
    .ENDIF
    
    .IF lpdwReceiveData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) and status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr dwDataBufferSize
            .IF eax == FALSE ;|| pDataBuffer == NULL
                IFDEF DEBUG32
                    PrintText 'RpcEndpointCall-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor eax, eax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszReceiveDataFile != NULL
                .IF pDataBuffer != NULL && dwDataBufferSize != 0
                    Invoke RpcWriteDataToLocalFile, lpszReceiveDataFile, pDataBuffer, dwDataBufferSize
                .ENDIF
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov ebx, lpdwReceiveData
            mov eax, pDataBuffer
            mov [ebx], eax
            
            .IF lpdwReceiveDataSize != NULL
                mov ebx, lpdwReceiveDataSize
                mov eax, dwDataBufferSize
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov ebx, lpdwReceiveData
            mov eax, 0
            mov [ebx], eax
            
            .IF lpdwReceiveDataSize != NULL
                mov ebx, lpdwReceiveDataSize
                mov eax, 0
                mov [ebx], eax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov eax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov ebx, hRpc
        mov eax, [ebx].RPC_HANDLE.dwStatusCode
        .IF eax == HTTP_STATUS_OK
            mov eax, TRUE
        .ELSE
            mov eax, FALSE
        .ENDIF
    .ENDIF
    ret
RpcEndpointCall ENDP

;------------------------------------------------------------------------------
; RpcGetStatusCode - Get last status code error. 
; -1 = is hRpc handle is null
;  0 = Unknown Error
; >0 = Same as HTTP status codes: 200 OK, 404 etc
;------------------------------------------------------------------------------
RpcGetStatusCode PROC USES EBX hRpc:DWORD
    .IF hRpc == NULL
        mov eax, -1
        ret
    .ENDIF
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.dwStatusCode
    ret
RpcGetStatusCode ENDP


;##############################################################################
; Internal Utility Functions
;##############################################################################

;------------------------------------------------------------------------------
; RpcGetRemoteFileSize - Get remote file size and return it in lpdwRemoteFileSize
;------------------------------------------------------------------------------
RpcGetRemoteFileSize PROC USES EBX hRpc:DWORD, lpdwRemoteFileSize:DWORD
    LOCAL hRequest:DWORD
    LOCAL BytesToGet:DWORD
    LOCAL BytesToGetSize:DWORD
    LOCAL lpdwIndex:DWORD
    LOCAL ContentLength[32]:BYTE

    IFDEF DEBUG32
        PrintText 'RpcGetRemoteFileSize'
    ENDIF
    
    .IF hRpc == NULL
        .IF lpdwRemoteFileSize != NULL
            mov ebx, lpdwRemoteFileSize
            mov eax, 0
            mov [ebx], eax
        .ENDIF
        mov eax, FALSE
        ret
    .ENDIF

    .IF lpdwRemoteFileSize == NULL
        mov eax, FALSE
        ret
    .ENDIF

    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.hRequest
    .IF eax == NULL
        .IF lpdwRemoteFileSize != NULL
            mov ebx, lpdwRemoteFileSize
            mov eax, 0
            mov [ebx], eax
        .ENDIF    
        mov eax, FALSE
        ret
    .ENDIF    
    mov hRequest, eax

    mov BytesToGetSize, 4d
    mov lpdwIndex, 0
    
    IFDEF DEBUG32
        PrintText 'RpcGetRemoteFileSize-HttpQueryInfo'
    ENDIF
    Invoke HttpQueryInfo, hRequest, HTTP_QUERY_FLAG_NUMBER or HTTP_QUERY_CONTENT_LENGTH, Addr BytesToGet, Addr BytesToGetSize, Addr lpdwIndex ; HTTP_QUERY_FLAG_NUMBER +
    .IF eax == FALSE
        mov BytesToGetSize, 32d
        mov lpdwIndex, 0
        
        Invoke RtlZeroMemory, Addr ContentLength, 32d
        Invoke lstrcpy, Addr ContentLength, Addr szContentLengthHeader
        
        IFDEF DEBUG32
            PrintText 'RpcGetRemoteFileSize-HttpQueryInfo::ContentLength Header'
        ENDIF
        Invoke HttpQueryInfo, hRequest, HTTP_QUERY_CUSTOM, Addr ContentLength, Addr BytesToGetSize, Addr lpdwIndex
        .IF eax == FALSE
            mov ebx, lpdwRemoteFileSize
            mov eax, 0
            mov [ebx], eax
            mov eax, FALSE
            ret
        .ELSE
            lea ebx, ContentLength
            add ebx, 16d ; 'Content-Length: '
            Invoke atou_ex, ebx
            mov BytesToGet, eax
        .ENDIF
    .ENDIF
    IFDEF DEBUG32
        PrintDec BytesToGet
    ENDIF
    mov ebx, lpdwRemoteFileSize
    mov eax, BytesToGet
    mov [ebx], eax
    mov eax, TRUE    
    ret
RpcGetRemoteFileSize ENDP

;------------------------------------------------------------------------------
; RpcBase64Encode - Base64 encode source string to destination string
;------------------------------------------------------------------------------
RpcBase64Encode PROC lpszSource:DWORD, lpszDestination:DWORD, dwSourceLength:DWORD
    push edi
    push esi
    push ebx
    mov  esi, lpszSource
    mov  edi, lpszDestination
@@base64loop:
    xor eax, eax
    .IF dwSourceLength == 1
        lodsb                           ;source ptr + 1
        mov ecx, 2                      ;bytes to output = 2
        mov edx, 03D3Dh                 ;padding = 2 byte
        dec dwSourceLength              ;length - 1
    .ELSEIF dwSourceLength == 2
        lodsw                           ;source ptr + 2
        mov ecx, 3                      ;bytes to output = 3
        mov edx, 03Dh                   ;padding = 1 byte
        sub dwSourceLength, 2           ;length - 2
    .ELSE
        lodsd
        mov ecx, 4                      ;bytes to output = 4
        xor edx, edx                    ;padding = 0 byte
        dec esi                         ;source ptr + 3 (+4-1)
        sub dwSourceLength, 3           ;length - 3 
    .ENDIF

    xchg al,ah                          ; flip eax completely
    rol  eax, 16                        ; can this be done faster
    xchg al,ah                          ; ??

    @@:
    push  eax
    and   eax, 0FC000000h               ;get the last 6 high bits
    rol   eax, 6                        ;rotate them into al
    mov   al, byte ptr [offset Base64Alphabet+eax]      ;get encode character
    stosb                               ;write to destination
    pop   eax
    shl   eax, 6                        ;shift left 6 bits
    dec   ecx
    jnz   @B                            ;loop
    
    cmp   dwSourceLength, 0
    jnz   @@base64loop                  ;main loop
    
    mov   eax, edx                      ;add padding and null terminate
    stosd                               ;  "     "    "     "     "

    pop   ebx
    pop   esi
    pop   edi
    ret
RpcBase64Encode ENDP

;------------------------------------------------------------------------------
; RpcWriteDataToLocalFile - Write data to file
;------------------------------------------------------------------------------
RpcWriteDataToLocalFile PROC USES EBX lpszLocalFilename:DWORD, pDataBuffer:DWORD, dwDataBufferSize:DWORD
    LOCAL hFile:DWORD
    LOCAL hMapFile:DWORD
    LOCAL pViewFile:DWORD
    LOCAL szLocalFilepath[MAX_PATH]:BYTE
    
    IFDEF DEBUG32
        PrintText 'RpcWriteDataToLocalFile'
    ENDIF      
    
    .IF lpszLocalFilename == NULL || pDataBuffer == NULL || dwDataBufferSize == NULL
        IFDEF DEBUG32
            PrintText 'RpcWriteDataToLocalFile null params'
        ENDIF      
        mov eax, FALSE
        ret
    .ENDIF
    
    ; Check for local directory in path starting with .\
    mov ebx, lpszLocalFilename
    movzx eax, word ptr [ebx]
    .IF ax == '\.'
        Invoke GetCurrentDirectory, MAX_PATH, Addr szLocalFilepath
        Invoke lstrcat, Addr szLocalFilepath, CTEXT("\")
        mov ebx, lpszLocalFilename
        add ebx, 2d
        Invoke lstrcat, Addr szLocalFilepath, ebx
    .ELSE
        Invoke lstrcpyn, Addr szLocalFilepath, lpszLocalFilename, MAX_PATH
    .ENDIF 
    
    Invoke CreateFile, Addr szLocalFilepath, GENERIC_READ or GENERIC_WRITE, FILE_SHARE_READ or FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL ;lpszLocalFilename
    .IF eax == INVALID_HANDLE_VALUE
        IFDEF DEBUG32
            PrintText 'RpcWriteDataToLocalFile CreateFile Error'
        ENDIF   
        mov eax, FALSE
        ret
    .ENDIF
    mov hFile, eax
    
    Invoke CreateFileMapping, hFile, NULL, PAGE_READWRITE, 0, dwDataBufferSize, NULL
    .IF eax == NULL
        IFDEF DEBUG32
            PrintText 'RpcWriteDataToLocalFile CreateFileMapping Error'
        ENDIF
        Invoke CloseHandle, hFile 
        mov eax, FALSE
        ret
    .ENDIF
    mov hMapFile, eax    
    
    Invoke MapViewOfFileEx, hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0, NULL
    .IF eax == NULL
        IFDEF DEBUG32
            PrintText 'RpcWriteDataToLocalFile MapViewOfFile Error'
        ENDIF
        Invoke CloseHandle, hMapFile
        Invoke CloseHandle, hFile
        mov eax, FALSE
        ret
    .ENDIF
    mov pViewFile, eax    

    Invoke RtlMoveMemory, pViewFile, pDataBuffer, dwDataBufferSize
    
    Invoke UnmapViewOfFile, pViewFile
    Invoke CloseHandle, hMapFile
    Invoke CloseHandle, hFile
    
    mov eax, TRUE
    ret
RpcWriteDataToLocalFile ENDP

;------------------------------------------------------------------------------
; RpcReplacePathVars - Replace path variables
; /:varname 
; /:varname1/:varname2/:varnameN
; /:varname1/path/:varname2
;------------------------------------------------------------------------------
RpcReplacePathVars PROC USES EBX EDI ESI hRpc:DWORD, lpszEndpointUrl:DWORD
    LOCAL lpszUrl:DWORD
    LOCAL lpszPathVariable:DWORD
    LOCAL nVarCount:DWORD
    LOCAL nVarCurrent:DWORD
    LOCAL lpVars:DWORD
    LOCAL lpVar:DWORD
    LOCAL lpszVar:DWORD
    
    .IF hRpc == NULL
        xor eax, eax
        ret
    .ENDIF
    
    mov ebx, hRpc
    mov eax, [ebx].RPC_HANDLE.lpszPathVariable
    .IF eax == NULL
        xor eax, eax
        ret
    .ENDIF
    mov lpszPathVariable, eax
    mov eax, [ebx].RPC_HANDLE.lpszUrl
    mov lpszUrl, eax
    
    mov ebx, lpszPathVariable
    mov eax, [ebx].PATHVARIABLES.dwVarCount ; Get first dword which is count of vars
    mov nVarCount, eax
    lea eax, [ebx].PATHVARIABLES.lpPathVariables
    mov lpVars, eax
    mov lpVar, eax
    
    mov nVarCurrent, 0
    ; Start copying lpszEndpointUrl to lpszUrl. If we find ':' denoting start of :varname
    ; then copy varname to lpszUrl
    ; look for end of varname - either null or '/' 
    ; if not null, then resume copying lpszEndpointUrl to lpszUrl until null or another varname
    mov edi, lpszUrl
    mov esi, lpszEndpointUrl
    movzx eax, byte ptr [esi]
    .WHILE al != 0
        .IF al == ':'
            movzx eax, byte ptr [esi+1]
            .IF al == '/'
                 ; probably part of http(s)://
                mov byte ptr [edi], al
            .ELSE
                ; get var and copy
                mov eax, nVarCurrent
                .IF eax == nVarCount
                    ; error - too many path vars in endpoint vs vars stored
                    mov byte ptr [edi], 0
                    mov eax, FALSE
                    ret
                .ENDIF
                
                mov ebx, lpVar
                lea eax, [ebx].PATHVARIABLE.szVariable
                .IF eax != 0
                    mov lpszVar, eax
                    
                    mov ebx, lpszVar
                    movzx eax, byte ptr [ebx]
                    .WHILE al != 0
                        mov byte ptr [edi], al
                        inc edi
                        inc ebx
                        movzx eax, byte ptr [ebx]
                    .ENDW
                    
                    add lpVar, SIZEOF PATHVARIABLE
                    inc nVarCurrent
                    
                    ; skip until '/' or 0
                    inc esi
                    movzx eax, byte ptr [esi]
                    .WHILE al != 0 && al != '/'
                        inc esi
                        movzx eax, byte ptr [esi]
                    .ENDW
                    .IF al == 0
                        .BREAK
                    .ELSE
                        mov byte ptr [edi], al
                    .ENDIF
                .ELSE
                    ; error getting varname
                    mov byte ptr [edi], 0
                    mov eax, FALSE
                    ret
                .ENDIF
            .ENDIF
        .ELSE
            mov byte ptr [edi], al
        .ENDIF
        inc edi
        inc esi
        movzx eax, byte ptr [esi]
    .ENDW
    mov byte ptr [edi], 0

    mov eax, TRUE
    ret
RpcReplacePathVars ENDP


;------------------------------------------------------------------------------
; Convert ascii string pointed to by String param to unsigned dword value. 
; Returns dword value in eax.
;------------------------------------------------------------------------------
OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE
ALIGN 16
atou_ex proc String:DWORD

  ; ------------------------------------------------
  ; Convert decimal string into UNSIGNED DWORD value
  ; ------------------------------------------------

    mov edx, [esp+4]

    xor ecx, ecx
    movzx eax, BYTE PTR [edx]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+1]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+2]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+3]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+4]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+5]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+6]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+7]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+8]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+9]
    test eax, eax
    jz quit

    lea ecx, [ecx+ecx*4]
    lea ecx, [eax+ecx*2-48]
    movzx eax, BYTE PTR [edx+10]
    test eax, eax
    jnz out_of_range

  quit:
    lea eax, [ecx]      ; return value in EAX
    or ecx, -1          ; non zero in ECX for success
    ret 4

  out_of_range:
    xor eax, eax        ; zero return value on error
    xor ecx, ecx        ; zero in ECX is out of range error
    ret 4

atou_ex endp
OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

;------------------------------------------------------------------------------
; Convert unsigned dword value to an ascii string. 
;------------------------------------------------------------------------------
OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE
ALIGN 16
utoa_ex proc uvar:DWORD,pbuffer:DWORD

  ; --------------------------------------------------------------------------------
  ; this algorithm was written by Paul Dixon and has been converted to MASM notation
  ; --------------------------------------------------------------------------------

    mov eax, [esp+4]                ; uvar      : unsigned variable to convert
    mov ecx, [esp+8]                ; pbuffer   : pointer to result buffer

    push esi
    push edi

    jmp udword

  align 4
  chartab:
    dd "00","10","20","30","40","50","60","70","80","90"
    dd "01","11","21","31","41","51","61","71","81","91"
    dd "02","12","22","32","42","52","62","72","82","92"
    dd "03","13","23","33","43","53","63","73","83","93"
    dd "04","14","24","34","44","54","64","74","84","94"
    dd "05","15","25","35","45","55","65","75","85","95"
    dd "06","16","26","36","46","56","66","76","86","96"
    dd "07","17","27","37","47","57","67","77","87","97"
    dd "08","18","28","38","48","58","68","78","88","98"
    dd "09","19","29","39","49","59","69","79","89","99"

  udword:
    mov esi, ecx                    ; get pointer to answer
    mov edi, eax                    ; save a copy of the number

    mov edx, 0D1B71759h             ; =2^45\10000    13 bit extra shift
    mul edx                         ; gives 6 high digits in edx

    mov eax, 68DB9h                 ; =2^32\10000+1

    shr edx, 13                     ; correct for multiplier offset used to give better accuracy
    jz short skiphighdigits         ; if zero then don't need to process the top 6 digits

    mov ecx, edx                    ; get a copy of high digits
    imul ecx, 10000                 ; scale up high digits
    sub edi, ecx                    ; subtract high digits from original. EDI now = lower 4 digits

    mul edx                         ; get first 2 digits in edx
    mov ecx, 100                    ; load ready for later

    jnc short next1                 ; if zero, supress them by ignoring
    cmp edx, 9                      ; 1 digit or 2?
    ja   ZeroSupressed              ; 2 digits, just continue with pairs of digits to the end

    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dh                   ; but only write the 1 we need, supress the leading zero
    inc esi                         ; update pointer by 1
    jmp  ZS1                        ; continue with pairs of digits to the end

  align 16
  next1:
    mul ecx                         ; get next 2 digits
    jnc short next2                 ; if zero, supress them by ignoring
    cmp edx, 9                      ; 1 digit or 2?
    ja   ZS1a                       ; 2 digits, just continue with pairs of digits to the end

    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dh                   ; but only write the 1 we need, supress the leading zero
    add esi, 1                      ; update pointer by 1
    jmp  ZS2                        ; continue with pairs of digits to the end

  align 16
  next2:
    mul ecx                         ; get next 2 digits
    jnc short next3                 ; if zero, supress them by ignoring
    cmp edx, 9                      ; 1 digit or 2?
    ja   ZS2a                       ; 2 digits, just continue with pairs of digits to the end

    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dh                   ; but only write the 1 we need, supress the leading zero
    add esi, 1                      ; update pointer by 1
    jmp  ZS3                        ; continue with pairs of digits to the end

  align 16
  next3:

  skiphighdigits:
    mov eax, edi                    ; get lower 4 digits
    mov ecx, 100

    mov edx, 28F5C29h               ; 2^32\100 +1
    mul edx
    jnc short next4                 ; if zero, supress them by ignoring
    cmp edx, 9                      ; 1 digit or 2?
    ja  short ZS3a                  ; 2 digits, just continue with pairs of digits to the end

    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dh                   ; but only write the 1 we need, supress the leading zero
    inc esi                         ; update pointer by 1
    jmp short  ZS4                  ; continue with pairs of digits to the end

  align 16
  next4:
    mul ecx                         ; this is the last pair so don; t supress a single zero
    cmp edx, 9                      ; 1 digit or 2?
    ja  short ZS4a                  ; 2 digits, just continue with pairs of digits to the end

    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dh                   ; but only write the 1 we need, supress the leading zero
    mov byte ptr [esi+1], 0         ; zero terminate string

    pop edi
    pop esi
    ret 8

  align 16
  ZeroSupressed:
    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dx
    add esi, 2                      ; write them to answer

  ZS1:
    mul ecx                         ; get next 2 digits
  ZS1a:
    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dx                   ; write them to answer
    add esi, 2

  ZS2:
    mul ecx                         ; get next 2 digits
  ZS2a:
    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dx                   ; write them to answer
    add esi, 2

  ZS3:
    mov eax, edi                    ; get lower 4 digits
    mov edx, 28F5C29h               ; 2^32\100 +1
    mul edx                         ; edx= top pair
  ZS3a:
    mov edx, chartab[edx*4]         ; look up 2 digits
    mov [esi], dx                   ; write to answer
    add esi, 2                      ; update pointer

  ZS4:
    mul ecx                         ; get final 2 digits
  ZS4a:
    mov edx, chartab[edx*4]         ; look them up
    mov [esi], dx                   ; write to answer

    mov byte ptr [esi+2], 0         ; zero terminate string

  sdwordend:

    pop edi
    pop esi

    ret 8

utoa_ex endp
OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef








END
