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
.x64
;include \uasm\macros\macros.asm

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

include windows.inc


;DEBUG64 EQU 1
;IFDEF DEBUG64
;    PRESERVEXMMREGS equ 1
;    includelib \UASM\lib\x64\Debug64.lib
;    DBG64LIB equ 1
;    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
;    include \UASM\include\debug64.inc
;    .DATA
;    RDBG_DbgWin	DB DEBUGEXE,0
;    .CODE
;ENDIF

include wininet.inc
include masm64.inc

includelib user32.lib
includelib kernel32.lib
includelib wininet.lib
includelib masm64.lib

include RPC64.inc


;-------------------------------------------------------------------------
; Prototypes for internal use
;-------------------------------------------------------------------------
RpcWriteDataToLocalFile PROTO :QWORD,:QWORD,:QWORD                              ; hRpc, lpszLocalFilename, pDataBuffer, qwDataBufferSize
RpcGetRemoteFileSize    PROTO :QWORD,:QWORD                                     ; hRpc, lpqwRemoteFileSize
RpcBase64Encode         PROTO :QWORD,:QWORD,:QWORD                              ; lpszSource, lpszDestination, qwSourceLength

atou_ex                 PROTO :QWORD
utoa_ex                 PROTO :QWORD, :QWORD, :DWORD, :DWORD, :DWORD


;-------------------------------------------------------------------------
; Structures for internal use
;-------------------------------------------------------------------------
IFNDEF RPC_HANDLE
RPC_HANDLE                      STRUCT
    hConnect                    DQ 0    ; 
    hInternet                   DQ 0    ; 
    hRequest                    DQ 0    ; 
    bSecure                     DQ 0    ; http or https
    qwStatusCode                DQ 0    ; 
    lpszHostAddress             DQ 0    ; hostname:port
    lpszUrl                     DQ 0    ; url buffer
    lpszPathVariable            DQ 0    ; /<variable>
    lpszQueryParameters         DQ 0    ; url params buffer - "name=value" pairs
    lpszAcceptHeader            DQ 0    ; "Accept: text/plain, application/json" etc
    lpszContentTypeHeader       DQ 0    ; 
    lpszAuthHeader              DQ 0    ; "Authorization: Basic <Base64Encoded(username:password)>"
RPC_HANDLE                      ENDS
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
hextbl                          DB '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
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

IFDEF DEBUG64
RPC_DEBUG_BUILD_URL             DB MAX_PATH DUP (0) 
ENDIF

.CODE


;------------------------------------------------------------------------------------------------
; Checks connection status
; Returns TRUE if connected, FALSE otherwise
;------------------------------------------------------------------------------------------------
RpcCheckConnection PROC FRAME USES RBX lpszHost:QWORD, lpszPort:QWORD, bSecure:QWORD
    LOCAL szUrl[256]:BYTE
    
    Invoke RtlZeroMemory, Addr szUrl, 256
    
    IFDEF DEBUG64
        PrintText 'RpcCheckConnection'
    ENDIF
    
    .IF lpszHost == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, lpszHost
    mov rax, [rbx]
    .IF rax != "ptth"
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
    IFDEF DEBUG64
        PrintText 'InternetCheckConnection'
    ENDIF
    Invoke InternetCheckConnection, Addr szUrl, FLAG_ICC_FORCE_CONNECTION, 0
    .IF rax == TRUE
        mov rax, TRUE
        ret
    .ENDIF
    Invoke GetLastError
    .IF rax == ERROR_WINHTTP_CANNOT_CONNECT
        mov rax, FALSE
    .ELSEIF rax == 0
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
RpcCheckConnection endp

;------------------------------------------------------------------------------
; RpcConnect - Connect to a host:port specifying agent and optionally HTTPS
; Returns: TRUE if succesful or FALSE otherwise. Returns RPC HANDLE (hRpc) in 
; the qword pointed to by lpqwRpcHandle.
;------------------------------------------------------------------------------
RpcConnect PROC FRAME USES RBX lpszHost:QWORD, lpszPort:QWORD, bSecure:QWORD, lpszUserAgent:QWORD, lpqwRpcHandle:QWORD
    LOCAL hRpc:QWORD
    LOCAL qwPort:QWORD
    LOCAL hInternet:QWORD
    LOCAL hConnect:QWORD
    LOCAL lpszHostAddress:QWORD
    LOCAL lpszUrl:QWORD
    
    IFDEF DEBUG64
    PrintText 'RpcConnect'
    ENDIF
    
    ;--------------------------------------------------------------------------
    ; Basic error checking
    ;--------------------------------------------------------------------------
    .IF lpszHost == NULL || lpqwRpcHandle == NULL
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    
    Invoke RpcCheckConnection, lpszHost, lpszPort, bSecure
    .IF rax == FALSE
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Create RPC HANDLE
    ;--------------------------------------------------------------------------
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, SIZEOF RPC_HANDLE
    .IF rax == NULL
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    mov hRpc, rax
    
    ;--------------------------------------------------------------------------
    ; Alloc memory for RPC handle fields
    ;--------------------------------------------------------------------------
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_HOSTADDRESS_SIZE
    .IF rax == NULL
        Invoke RpcDisconnect, hRpc
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    mov lpszHostAddress, rax
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_URL_SIZE
    .IF rax == NULL
        Invoke RpcDisconnect, hRpc
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    mov lpszUrl, rax
    
    ; Store host and port as lpszHostAddress in RPC HANDLE 
    mov rbx, lpszHost
    mov rax, [rbx]
    .IF rax != "ptth" && rax != 'PTTH' && rax != 'pttH'
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
    .IF rax == NULL
        IFDEF DEBUG64
            PrintText 'InternetOpen Error'
            Invoke GetLastError
            PrintDec rax
        ENDIF
        Invoke RpcDisconnect, hRpc
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    mov hInternet, rax
    
    Invoke InternetSetOption, hInternet, INTERNET_OPTION_RECEIVE_TIMEOUT, Addr TimeoutPeriod, SIZEOF TimeoutPeriod
    .IF bSecure == TRUE
        mov qwPort, DEFAULT_HTTPS_PORT
    .ELSE    
        .IF lpszPort == 0
            mov qwPort, DEFAULT_HTTP_PORT
        .ELSE    
            Invoke atou_ex, lpszPort
            mov qwPort, rax
        .ENDIF
    .ENDIF
    
    Invoke InternetConnect, hInternet, lpszHost, dword ptr qwPort, 0, 0, INTERNET_SERVICE_HTTP, 0, 0
    .IF rax == NULL
        IFDEF DEBUG64
            PrintText 'InternetConnect Error'
            Invoke GetLastError
            PrintDec rax
        ENDIF    
        .IF hInternet != NULL
            Invoke InternetCloseHandle, hInternet
        .ENDIF
        Invoke RpcDisconnect, hRpc
        mov rbx, lpqwRpcHandle
        mov rax, NULL
        mov [rbx], rax
        mov rax, FALSE
        ret
    .ENDIF
    mov hConnect, rax
    
    ;--------------------------------------------------------------------------
    ; Store information in RPC HANDLE
    ;--------------------------------------------------------------------------
    mov rbx, hRpc
    mov rax, hInternet
    mov [rbx].RPC_HANDLE.hInternet, rax
    mov rax, hConnect
    mov [rbx].RPC_HANDLE.hConnect, rax
    mov rax, lpszHostAddress
    mov [rbx].RPC_HANDLE.lpszHostAddress, rax
    mov rax, lpszUrl
    mov [rbx].RPC_HANDLE.lpszUrl, rax
    mov rax, bSecure
    mov [rbx].RPC_HANDLE.bSecure, rax
    
    ;--------------------------------------------------------------------------
    ; Return RPC HANDLE
    ;--------------------------------------------------------------------------
    mov rbx, lpqwRpcHandle
    mov rax, hRpc
    mov [rbx], rax
    
    mov rax, TRUE
    ret
RpcConnect ENDP

;------------------------------------------------------------------------------
; RpcDisconnect - Disconnect from previous connection made via RpcConnect
; Returns: None
;------------------------------------------------------------------------------
RpcDisconnect PROC FRAME USES RBX hRpc:QWORD
    LOCAL hInternet:QWORD
    LOCAL hConnect:QWORD
    LOCAL hRequest:QWORD
    LOCAL lpszHostAddress:QWORD
    LOCAL lpszUrl:QWORD
    LOCAL lpszPathVariable:QWORD
    LOCAL lpszQueryParameters:QWORD
    LOCAL lpszAcceptHeader:QWORD
    LOCAL lpszAuthHeader:QWORD

    IFDEF DEBUG64
    PrintText 'RpcDisconnect'
    ENDIF
    
    .IF hRpc == NULL
        xor rax, rax
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.hInternet
    mov hInternet, rax
    mov rax, [rbx].RPC_HANDLE.hConnect
    mov hConnect, rax    
    mov rax, [rbx].RPC_HANDLE.hRequest
    mov hRequest, rax
    mov rax, [rbx].RPC_HANDLE.lpszHostAddress
    mov lpszHostAddress, rax
    mov rax, [rbx].RPC_HANDLE.lpszUrl
    mov lpszUrl, rax
    mov rax, [rbx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, rax
    mov rax, [rbx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, rax
    mov rax, [rbx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, rax
    mov rax, [rbx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, rax

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
    
    Invoke GlobalFree, hRpc
    
    xor rax, rax   
    ret
RpcDisconnect ENDP

;------------------------------------------------------------------------------
; RpcSetCookie - Sets a cookie for the rpc connection opened via RpcConnect 
;------------------------------------------------------------------------------
RpcSetCookie PROC FRAME USES RBX hRpc:QWORD, lpszCookieData:QWORD
    LOCAL lpszHostAddress:QWORD
    
    IFDEF DEBUG64
    PrintText 'RpcSetCookie'
    ENDIF
    
    .IF hRpc == NULL
        xor rax, rax
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszHostAddress
    .IF rax == NULL
        xor rax, rax
        ret
    .ENDIF
    mov lpszHostAddress, rax
    
    Invoke InternetSetCookie, lpszHostAddress, NULL, lpszCookieData
    mov rax, TRUE
    ret
RpcSetCookie ENDP

;------------------------------------------------------------------------------
; RpcSetAuthBasic - Base64 encode user/pass and add to a Auth Header (Basic) 
; for use in the RpcEndpointOpen function.
; If lpszUsername & lpszPassword = NULL then any existing Auth Header is freed
;------------------------------------------------------------------------------
RpcSetAuthBasic PROC FRAME USES RBX hRpc:QWORD, lpszUsername:QWORD, lpszPassword:QWORD
    LOCAL lpszAuthHeader:QWORD
    LOCAL szBase64Auth[256]:BYTE
    LOCAL szPreBase64Auth[256]:BYTE

    IFDEF DEBUG64
    PrintText 'RpcSetAuthBasic'
    ENDIF

    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, rax
    
    .IF lpszUsername == NULL && lpszPassword == NULL
        .IF lpszAuthHeader != NULL
            Invoke GlobalFree, lpszAuthHeader
            mov rbx, hRpc
            mov [rbx].RPC_HANDLE.lpszAuthHeader, 0
        .ENDIF
        mov rax, TRUE
        ret        
    .ENDIF
    
    .IF lpszPassword == NULL
        xor rax, rax
        ret
    .ENDIF
    
    Invoke lstrlen, lpszPassword
    .IF rax == 0
        xor rax, rax
        ret
    .ENDIF
    
    .IF lpszAuthHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_AUTH_HEADER_SIZE
        .IF rax == NULL
            xor rax, rax
            ret
        .ENDIF
        mov lpszAuthHeader, rax
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.lpszAuthHeader, rax
    .ENDIF
    
    .IF lpszUsername != NULL
        Invoke lstrlen, lpszUsername
        .IF rax == 0
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
    Invoke RpcBase64Encode, Addr szPreBase64Auth, Addr szBase64Auth, rax

    ; Add header
    Invoke lstrcpy, lpszAuthHeader, Addr szAuthHeaderBasicHeader
    Invoke lstrcat, lpszAuthHeader, Addr szBase64Auth
    
    mov rax, TRUE
    ret
RpcSetAuthBasic ENDP

;------------------------------------------------------------------------------
; RpcSetAcceptType - Add a media content type to a Accept Header for use in the
; RpcEndpointOpen function.
; If lpszAcceptType = NULL then any existing Accept Header is freed
;------------------------------------------------------------------------------
RpcSetAcceptType PROC FRAME USES RBX hRpc:QWORD, lpszAcceptType:QWORD, qwAcceptType:QWORD
    LOCAL lpszAcceptHeader:QWORD
    
    IFDEF DEBUG64
    PrintText 'RpcSetAcceptType'
    ENDIF

    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, rax
    
    .IF lpszAcceptType == NULL && qwAcceptType == RPC_MEDIATYPE_NONE
        .IF lpszAcceptHeader != NULL
            Invoke GlobalFree, lpszAcceptHeader
            mov rbx, hRpc
            mov [rbx].RPC_HANDLE.lpszAcceptHeader, 0
            mov rax, TRUE
            ret
        .ENDIF
    .ENDIF
    
    .IF lpszAcceptHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_ACCEPT_HEADER_SIZE
        .IF rax == NULL
            mov rax, FALSE
            ret
        .ENDIF
        mov lpszAcceptHeader, rax
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.lpszAcceptHeader, rax
    .ENDIF
    
    Invoke lstrlen, lpszAcceptHeader
    .IF rax == 0
        Invoke lstrcpy, lpszAcceptHeader, Addr szAcceptHeader
    .ELSE
        Invoke lstrcat, lpszAcceptHeader, CTEXT(", ")
    .ENDIF
    .IF lpszAcceptType != NULL
        Invoke lstrcat, lpszAcceptHeader, lpszAcceptType
    .ELSE
        mov rax, qwAcceptType
        .IF rax == RPC_MEDIATYPE_ALL
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_ALL
        .ELSEIF rax == RPC_MEDIATYPE_TEXT
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_TEXT
        .ELSEIF rax == RPC_MEDIATYPE_HTML
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_HTML
        .ELSEIF rax == RPC_MEDIATYPE_XML
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_XML
        .ELSEIF rax == RPC_MEDIATYPE_JSON
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_JSON
        .ELSEIF rax == RPC_MEDIATYPE_FORM
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_FORM
        .ELSE
            Invoke lstrcat, lpszAcceptHeader, Addr szMEDIATYPE_ALL
        .ENDIF
    .ENDIF
    mov rax, TRUE
    ret
RpcSetAcceptType ENDP

;------------------------------------------------------------------------------
; RpcSetContentType - Add a media content type to a ContentType Header for use in the
; RpcEndpointOpen function.
; If lpszContentType = NULL then any existing ContentType Header is freed
;------------------------------------------------------------------------------
RpcSetContentType PROC FRAME USES RBX hRpc:QWORD, lpszContentType:QWORD, qwContentType:QWORD
    LOCAL lpszContentTypeHeader:QWORD
    
    IFDEF DEBUG64
    PrintText 'RpcSetContentType'
    ENDIF

    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszContentTypeHeader
    mov lpszContentTypeHeader, rax
    
    .IF lpszContentType == NULL && qwContentType == RPC_MEDIATYPE_NONE
        .IF lpszContentTypeHeader != NULL
            Invoke GlobalFree, lpszContentTypeHeader
            mov rbx, hRpc
            mov [rbx].RPC_HANDLE.lpszContentTypeHeader, 0
            mov rax, TRUE
            ret
        .ENDIF
    .ENDIF
    
    .IF lpszContentTypeHeader == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_CONTENT_HEADER_SIZE
        .IF rax == NULL
            mov rax, FALSE
            ret
        .ENDIF
        mov lpszContentTypeHeader, rax
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.lpszContentTypeHeader, rax
    .ENDIF
    
    Invoke lstrlen, lpszContentTypeHeader
    .IF rax == 0
        Invoke lstrcpy, lpszContentTypeHeader, Addr szContentTypeHeader
    .ELSE
        Invoke lstrcat, lpszContentTypeHeader, CTEXT(", ")
    .ENDIF
    .IF lpszContentType != NULL
        Invoke lstrcat, lpszContentTypeHeader, lpszContentType
    .ELSE
        mov rax, qwContentType
        .IF rax == RPC_MEDIATYPE_ALL
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_ALL
        .ELSEIF rax == RPC_MEDIATYPE_TEXT
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_TEXT
        .ELSEIF rax == RPC_MEDIATYPE_HTML
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_HTML
        .ELSEIF rax == RPC_MEDIATYPE_XML
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_XML
        .ELSEIF rax == RPC_MEDIATYPE_JSON
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_JSON
        .ELSEIF rax == RPC_MEDIATYPE_FORM
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_FORM
        .ELSE
            Invoke lstrcat, lpszContentTypeHeader, Addr szMEDIATYPE_ALL
        .ENDIF
    .ENDIF
    mov rax, TRUE
    ret
RpcSetContentType ENDP

;------------------------------------------------------------------------------
; RpcSetPathVariable - Adds a path variable to the endpoint url
; If lpszPathVariable = NULL, the buffer used internally is zeroed out.
;------------------------------------------------------------------------------
RpcSetPathVariable PROC FRAME USES RBX hRpc:QWORD, lpszVariable:QWORD
    LOCAL lpszPathVariable:QWORD
    
    IFDEF DEBUG64
    PrintText 'RpcSetPathVariable'
    ENDIF
    
    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, rax
    
    .IF lpszVariable == NULL
        .IF lpszPathVariable != NULL
            Invoke lstrlen, lpszPathVariable
            .IF rax == 0
                mov rax, TRUE
                ret
            .ELSEIF rax > RPC_PATH_VARIABLE_SIZE
                mov rax, RPC_PATH_VARIABLE_SIZE
            .ENDIF
            Invoke RtlZeroMemory, lpszPathVariable, rax
        .ENDIF
        mov rax, TRUE
        ret
    .ENDIF
    
    .IF lpszPathVariable == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_PATH_VARIABLE_SIZE
        .IF rax == NULL
            mov rax, FALSE
            ret
        .ENDIF
        mov lpszPathVariable, rax
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.lpszPathVariable, rax
    .ENDIF    

    Invoke lstrlen, lpszPathVariable
    .IF rax > RPC_PATH_VARIABLE_SIZE
        mov rax, FALSE
        ret
    .ENDIF
    
    Invoke lstrcpy, lpszPathVariable, lpszVariable
    
    mov rax, TRUE
    ret
RpcSetPathVariable ENDP

;------------------------------------------------------------------------------
; RpcSetQueryParameters - Constructs and adds Query Parameters (?name=value pairs) 
; to the endpoint url
; If lpszName = NULL, the buffer used internally is zeroed out.
;------------------------------------------------------------------------------
RpcSetQueryParameters PROC FRAME USES RBX hRpc:QWORD, lpszName:QWORD, lpszValue:QWORD, qwValue:QWORD
    LOCAL lpszQueryParameters:QWORD
    LOCAL szValue[32]:BYTE
    
    IFDEF DEBUG64
    PrintText 'RpcSetQueryParameters'
    ENDIF
    
    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, rax
    
    .IF lpszName == NULL
        .IF lpszQueryParameters != NULL
            Invoke lstrlen, lpszQueryParameters
            .IF rax == 0
                mov rax, TRUE
                ret
            .ELSEIF rax > RPC_QUERY_PARAMS_SIZE
                mov rax, RPC_QUERY_PARAMS_SIZE
            .ENDIF
            Invoke RtlZeroMemory, lpszQueryParameters, rax
        .ENDIF
        mov rax, TRUE
        ret
    .ENDIF
    
    .IF lpszQueryParameters == NULL
        Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, RPC_QUERY_PARAMS_SIZE
        .IF rax == NULL
            mov rax, FALSE
            ret
        .ENDIF
        mov lpszQueryParameters, rax
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.lpszQueryParameters, rax
    .ENDIF    

    Invoke lstrlen, lpszQueryParameters
    .IF rax > RPC_QUERY_PARAMS_SIZE
        mov rax, FALSE
        ret
    .ELSEIF rax == 0
        Invoke lstrcpy, lpszQueryParameters, CTEXT("?")
    .ELSE
        Invoke lstrcat, lpszQueryParameters, CTEXT("?")
    .ENDIF
    
    Invoke lstrcat, lpszQueryParameters, lpszName
    Invoke lstrcat, lpszQueryParameters, CTEXT("=")
    .IF lpszValue != NULL
        Invoke lstrcat, lpszQueryParameters, lpszValue
    .ELSE
        Invoke utoa_ex, qwValue, Addr szValue, 10h, FALSE, FALSE
        Invoke lstrcat, lpszQueryParameters, Addr szValue
    .ENDIF
    
    mov rax, TRUE
    ret
RpcSetQueryParameters ENDP

;------------------------------------------------------------------------------
; RpcEndpointOpen - Opens a endpoint url, lpszEndpointUrl is the long pointer
; to a zero terminated string containing the url to open. 
; if lpszVerb == NULL then defaults to GET
; lpSendData and qwSendDataSize are typically for POST sending data
; if dwSendDataSize == -1 then assume lpSendData is ascii and will calc length
; Returns: TRUE if succesfull, otherwise FALSE.
;------------------------------------------------------------------------------
RpcEndpointOpen PROC FRAME USES RBX hRpc:QWORD, lpszVerb:QWORD, lpszEndpointUrl:QWORD, lpSendData:QWORD, qwSendDataSize:QWORD
    LOCAL bSecure:QWORD
    LOCAL hConnect:QWORD
    LOCAL hRequest:QWORD
    LOCAL lpszUrl:QWORD
    LOCAL lpszPathVariable:QWORD
    LOCAL lpszQueryParameters:QWORD
    LOCAL lpszAcceptHeader:QWORD
    LOCAL lpszContentTypeHeader:QWORD
    LOCAL lpszAuthHeader:QWORD
    LOCAL qwStatusCode:QWORD
    LOCAL qwSizeStatusCode:QWORD
    LOCAL lpqwIndex:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointOpen'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Fetch RPC HANDLE field values
    ;--------------------------------------------------------------------------
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.hConnect
    mov hConnect, rax
    mov rax, [rbx].RPC_HANDLE.bSecure
    mov bSecure, rax
    mov rax, [rbx].RPC_HANDLE.lpszUrl
    mov lpszUrl, rax
    mov rax, [rbx].RPC_HANDLE.lpszPathVariable
    mov lpszPathVariable, rax
    mov rax, [rbx].RPC_HANDLE.lpszQueryParameters
    mov lpszQueryParameters, rax
    mov rax, [rbx].RPC_HANDLE.lpszAcceptHeader
    mov lpszAcceptHeader, rax
    mov rax, [rbx].RPC_HANDLE.lpszContentTypeHeader
    mov lpszContentTypeHeader, rax
    mov rax, [rbx].RPC_HANDLE.lpszAuthHeader
    mov lpszAuthHeader, rax
    
    .IF hConnect == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov lpqwIndex, 0
    mov hRequest, 0
    mov qwStatusCode, 0
    mov qwSizeStatusCode, SIZEOF QWORD
    
    ;--------------------------------------------------------------------------
    ; Add path parameter and/or query parameters to endpoint url
    ;--------------------------------------------------------------------------
    .IF lpszPathVariable == NULL && lpszQueryParameters == NULL
        ; No path variable and query parameters to add to endpoint url
        mov rax, lpszEndpointUrl
        mov lpszUrl, rax
    .ELSEIF lpszPathVariable != NULL && lpszQueryParameters == NULL
        ; Add path variable to endpoint url
        Invoke lstrlen, lpszPathVariable
        .IF rax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszPathVariable
        .ENDIF
    .ELSEIF lpszPathVariable == NULL && lpszQueryParameters != NULL
        ; Add query parameters to the endpoint url
        Invoke lstrlen, lpszQueryParameters
        .IF rax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszQueryParameters
        .ENDIF
    .ELSE ; lpszPathVariable != NULL && lpszQueryParameters != NULL 
        ; Add both path variable and query parameters to endpoint url
        Invoke lstrlen, lpszPathVariable
        .IF rax != 0
            Invoke lstrcpy, lpszUrl, lpszEndpointUrl
            Invoke lstrcat, lpszUrl, lpszPathVariable
            Invoke lstrlen, lpszQueryParameters
            .IF rax != 0
                Invoke lstrcat, lpszUrl, lpszQueryParameters
            .ENDIF
        .ELSE
            Invoke lstrlen, lpszQueryParameters
            .IF rax != 0
                Invoke lstrcpy, lpszUrl, lpszEndpointUrl
                Invoke lstrcat, lpszUrl, lpszQueryParameters
            .ENDIF
        .ENDIF
    .ENDIF
    
    IFDEF DEBUG64
    Invoke lstrcpy, Addr RPC_DEBUG_BUILD_URL, lpszUrl
    ;PrintString RPC_DEBUG_BUILD_URL
    ENDIF
    
    ;--------------------------------------------------------------------------
    ; RpcEndpointOpen--HttpOpenRequest
    ;--------------------------------------------------------------------------
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpOpenRequest'
    ENDIF
    .IF bSecure == TRUE
        Invoke HttpOpenRequest, hConnect, lpszVerb, lpszUrl, NULL, NULL, NULL, INTERNET_FLAG_SECURE or INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE or INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_RELOAD, 0 ;+ INTERNET_FLAG_EXISTING_CONNECTINTERNET_FLAG_NO_CACHE_WRITE + INTERNET_FLAG_RELOAD
    .ELSE
        Invoke HttpOpenRequest, hConnect, lpszVerb, lpszUrl, NULL, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION or INTERNET_FLAG_NO_CACHE_WRITE or INTERNET_FLAG_PRAGMA_NOCACHE or INTERNET_FLAG_RELOAD, 0 ;+ INTERNET_FLAG_EXISTING_CONNECTINTERNET_FLAG_NO_CACHE_WRITE + INTERNET_FLAG_RELOAD
    .ENDIF
    .IF rax == NULL
        IFDEF DEBUG64
            Invoke GetLastError
            PrintDec rax
            PrintText 'RpcEndpointOpen--HttpOpenRequest Error'
            PrintStringByAddr lpszEndpointUrl
        ENDIF
        mov rbx, hRpc
        mov rax, qwStatusCode
        mov [rbx].RPC_HANDLE.qwStatusCode, rax
        mov rax, FALSE
        ret
    .ENDIF
    mov hRequest, rax
    mov rbx, hRpc
    mov [rbx].RPC_HANDLE.hRequest, rax
    
    ;--------------------------------------------------------------------------
    ; Add additional headers to request
    ;--------------------------------------------------------------------------
    ; Add Auth Header if required
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszAuthHeader'
    ENDIF
    .IF lpszAuthHeader != 0
        Invoke lstrlen, lpszAuthHeader
        .IF rax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszAuthHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ENDIF
    
    ; Add Accept Header if required
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszAcceptHeader'
    ENDIF
    .IF lpszAcceptHeader != 0
        Invoke lstrlen, lpszAcceptHeader
        .IF rax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszAcceptHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ELSE
            Invoke HttpAddRequestHeaders, hRequest, Addr szAcceptAll, -1, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ELSE
        Invoke HttpAddRequestHeaders, hRequest, Addr szAcceptAll, -1, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
    .ENDIF
    
    ; Add Content-Type Header if required
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpAddRequestHeaders::lpszContentHeader'
    ENDIF
    .IF lpszContentTypeHeader != 0
        Invoke lstrlen, lpszContentTypeHeader
        .IF rax != 0
            Invoke HttpAddRequestHeaders, hRequest, lpszContentTypeHeader, eax, HTTP_ADDREQ_FLAG_ADD or HTTP_ADDREQ_FLAG_REPLACE
        .ENDIF
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; RpcEndpointOpen--HttpSendRequest
    ;--------------------------------------------------------------------------
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpSendRequest'
    ENDIF
    .IF lpSendData != NULL && qwSendDataSize != 0 ; Typically for POST data
        .IF qwSendDataSize == -1 ; if -1 assume zero terminated ascii data, so get length
            Invoke lstrlen, lpSendData
            Invoke HttpSendRequest, hRequest, NULL, 0, lpSendData, eax
        .ELSE
            Invoke HttpSendRequest, hRequest, NULL, 0, lpSendData, dword ptr qwSendDataSize
        .ENDIF    
     .ELSE
        Invoke HttpSendRequest, hRequest, NULL, 0, NULL, 0
    .ENDIF
    .IF rax != TRUE
        IFDEF DEBUG64
        PrintText 'RpcEndpointOpen--HttpSendRequest--HttpQueryInfo'
        ENDIF
        Invoke HttpQueryInfo, hRequest, HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER, Addr qwStatusCode, Addr qwSizeStatusCode, Addr lpqwIndex
        IFDEF DEBUG64
            Invoke GetLastError
            PrintDec rax
            PrintText 'RpcEndpointOpen--HttpSendRequest Error'
        ENDIF
        mov rbx, hRpc
        mov rax, qwStatusCode
        mov [rbx].RPC_HANDLE.qwStatusCode, rax
        mov rax, FALSE
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Tidy up and return
    ;--------------------------------------------------------------------------
    ; Clear lpszPathVariable
    Invoke RpcSetPathVariable, hRpc, NULL
    
    ; Clear lpszQueryParameters
    Invoke RpcSetQueryParameters, hRpc, NULL, NULL, NULL
    
    IFDEF DEBUG64
    PrintText 'RpcEndpointOpen--HttpQueryInfo'
    ENDIF
    Invoke HttpQueryInfo, hRequest, HTTP_QUERY_STATUS_CODE or HTTP_QUERY_FLAG_NUMBER, Addr qwStatusCode, Addr qwSizeStatusCode, Addr lpqwIndex
    mov rbx, hRpc
    mov rax, qwStatusCode
    mov [rbx].RPC_HANDLE.qwStatusCode, rax
    .IF qwStatusCode >= 400 && qwStatusCode <= 500
        IFDEF DEBUG64
        PrintText 'RpcEndpointOpen--HttpSendRequest finished - Status 400-500'
        ENDIF
        mov rax, FALSE
    .ELSE
        IFDEF DEBUG64
        PrintText 'RpcEndpointOpen--HttpSendRequest finished'
        ENDIF
        mov rax, TRUE
    .ENDIF
    ret
RpcEndpointOpen ENDP

;------------------------------------------------------------------------------
; RpcEndpointClose - closes and endpoint url opened by RpcEndpointOpen
;------------------------------------------------------------------------------
RpcEndpointClose PROC FRAME hRpc:QWORD
    LOCAL hRequest:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointClose'
    ENDIF        
    
    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.hRequest
    mov hRequest, rax
    
    .IF hRequest != NULL
        Invoke HttpEndRequest, hRequest, NULL, 0, 0
        Invoke InternetCloseHandle, hRequest
        mov rbx, hRpc
        mov [rbx].RPC_HANDLE.hRequest, 0
    .ENDIF
    
    mov rax, TRUE
    ret
RpcEndpointClose ENDP

;------------------------------------------------------------------------------
; RpcEndpointReadData - Read endpoint url data and return pointer to data in 
; lpqwDataBuffer, along with size of data in lpqwTotalBytesRead. 
; Returns TRUE if succesful or FALSE otherwise.
; Notes: Use RpcEndpointFreeData after finishing processing file data to free memory  
;------------------------------------------------------------------------------
RpcEndpointReadData PROC FRAME USES RBX RDX RDI hRpc:QWORD, lpqwDataBuffer:QWORD, lpqwTotalBytesRead:QWORD
    LOCAL hRequest:QWORD
    LOCAL BytesRead:DWORD
    LOCAL BytesToRead:DWORD
    LOCAL BytesLeftToRead:DWORD
    LOCAL Position:QWORD
    LOCAL pDataBuffer:QWORD
    LOCAL SizeDataBuffer:DWORD
    LOCAL looptrue:QWORD
    LOCAL readchunks:DWORD
    LOCAL DataBufferChunkSize:DWORD

    IFDEF DEBUG64
        PrintText 'RpcEndpointReadData'
    ENDIF
    
    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF
    
    .IF lpqwDataBuffer == NULL
        .IF lpqwTotalBytesRead != NULL
            mov rbx, lpqwTotalBytesRead
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        mov rax, FALSE
        ret
    .ENDIF
    
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.hRequest
    .IF rax == NULL
        mov rax, FALSE
        ret
    .ENDIF
    mov hRequest, rax
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointReadData-RpcGetRemoteFileSize'
    ENDIF
    Invoke RpcGetRemoteFileSize, hRpc, Addr BytesToRead
    .IF rax == TRUE && BytesToRead != 0
        mov eax, BytesToRead
        add eax, 4
        mov SizeDataBuffer, eax
        mov readchunks, FALSE
    .ELSE
        mov readchunks, TRUE
        mov BytesToRead, RPC_READ_CHUNK_SIZE
        mov eax, BytesToRead
        add eax, 4d
        mov SizeDataBuffer, eax
        ;mov DataBufferChunkSize, RPC_READ_CHUNK_SIZE
        ;mov SizeDataBuffer, RPC_READ_BUFFER_SIZE
    .ENDIF
    mov pDataBuffer, 0
    
    ;--------------------------------------------------------------------------
    ; Alloc initial memory for read buffer
    ;--------------------------------------------------------------------------
    IFDEF DEBUG64
        PrintText 'RpcEndpointReadData-GlobalAlloc'
    ENDIF
    Invoke GlobalAlloc, GMEM_FIXED or GMEM_ZEROINIT, SizeDataBuffer
    .IF rax == NULL
        IFDEF DEBUG64
            PrintText 'RpcEndpointReadData-GlobalAlloc Error'
        ENDIF
        mov rbx, lpqwDataBuffer
        mov rax, 0
        mov [rbx], rax
        .IF lpqwTotalBytesRead != NULL
            mov rbx, lpqwTotalBytesRead
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        mov rax, FALSE
        ret
    .ENDIF
    mov pDataBuffer, rax

    .IF readchunks == FALSE ; try to read all in at once
        IFDEF DEBUG32
            PrintText 'RpcEndpointReadData-InternetReadFile-Try To Read All In'
        ENDIF
        Invoke InternetReadFile, hRequest, pDataBuffer, BytesToRead, Addr BytesRead
        .IF rax == FALSE
            IFDEF DEBUG32
                PrintText 'RpcEndpointReadData-InternetReadFile Error'
                Invoke GetLastError
                PrintDec rax
            ENDIF
            .IF pDataBuffer != NULL
                Invoke GlobalFree, pDataBuffer
            .ENDIF
            mov rbx, lpqwDataBuffer
            mov rax, 0
            mov [rbx], rax
            .IF lpqwTotalBytesRead != NULL
                mov rbx, lpqwTotalBytesRead
                mov rax, 0
                mov [rbx], rax
            .ENDIF
            mov rax, FALSE
            ret
        .ELSE
        
            .IF rax == TRUE && BytesRead == 0 ; finished all reads
                mov eax, BytesRead
                mov Position, rax
                ; return data, size and exit
            .ELSE ; more data to retrieve
                mov eax, BytesRead
                mov Position, rax
                
                mov eax, BytesToRead
                sub eax, BytesRead
                .IF sdword ptr eax > 0 ; more to get
                    mov BytesLeftToRead, eax
                    IFDEF DEBUG32
                        PrintText 'RpcEndpointReadData-InternetReadFile-More Data To Read'
                    ENDIF
                
                    mov rax, TRUE
                    .WHILE rax == TRUE && BytesRead != 0 ; continue
                       
                        mov rdi, pDataBuffer
                        add rdi, Position
                        
                        Invoke InternetReadFile, hRequest, rdi, BytesLeftToRead, Addr BytesRead
                        mov looptrue, rax
                        .IF rax == FALSE
                            IFDEF DEBUG32
                                PrintText 'RpcEndpointReadData-InternetReadFile Error'
                                Invoke GetLastError
                                PrintDec rax
                            ENDIF
                            .IF pDataBuffer != NULL
                                Invoke GlobalFree, pDataBuffer
                            .ENDIF
                            mov rbx, lpqwDataBuffer
                            mov rax, 0
                            mov [rbx], rax
                            .IF lpqwTotalBytesRead != NULL
                                mov rbx, lpqwTotalBytesRead
                                mov rax, 0
                                mov [rbx], rax
                            .ENDIF
                            mov rax, FALSE
                            ret
                        .ELSE
                            .IF rax == TRUE && BytesRead == 0 ; finished all reads
                                ; return data, size and exit
                                mov looptrue, FALSE
                                .BREAK
                            .ELSE ; more data to retrieve
                                
                            .ENDIF
                        .ENDIF
                        
                        mov eax, BytesRead
                        add Position, rax
                        
                        mov rax, looptrue
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
        mov rax, TRUE
        .WHILE rax == TRUE && BytesRead != 0 ; continue
            
            mov rdi, pDataBuffer
            add rdi, Position
    
            Invoke InternetReadFile, hRequest, rdi, BytesToRead, Addr BytesRead
            mov looptrue, rax
            .IF rax == FALSE
                IFDEF DEBUG32
                    PrintText 'RpcEndpointReadData-InternetReadFile Error'
                    Invoke GetLastError
                    PrintDec rax
                ENDIF
                .IF pDataBuffer != NULL
                    Invoke GlobalFree, pDataBuffer
                .ENDIF
                mov rbx, lpqwDataBuffer
                mov rax, 0
                mov [rbx], rax
                .IF lpqwTotalBytesRead != NULL
                    mov rbx, lpqwTotalBytesRead
                    mov rax, 0
                    mov [rbx], rax
                .ENDIF
                mov rax, FALSE
                ret
            .ELSE
                .IF rax == TRUE && BytesRead == 0 ; finished all reads
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
                    .IF rax == NULL
                        IFDEF DEBUG32
                            PrintText 'RpcEndpointReadData-GlobalReAlloc Error'
                            Invoke GetLastError
                            PrintDec rax
                        ENDIF
                        .IF pDataBuffer != NULL
                            Invoke GlobalFree, pDataBuffer
                        .ENDIF
                        mov rbx, lpqwDataBuffer
                        mov rax, 0
                        mov [rbx], rax
                        .IF lpqwTotalBytesRead != NULL
                            mov rbx, lpqwTotalBytesRead
                            mov rax, 0
                            mov [rbx], rax
                        .ENDIF
                        mov rax, FALSE
                        ret                
                    .ENDIF
                    mov pDataBuffer, rax
                .ENDIF
            .ENDIF
            
            mov eax, BytesRead
            add Position, rax            
            
            mov rax, looptrue
        .ENDW
        
    .ENDIF

    ;--------------------------------------------------------------------------
    ; Return pointers to buffer and buffer size
    ;--------------------------------------------------------------------------
    mov rbx, lpqwDataBuffer
    mov rax, pDataBuffer
    mov [rbx], rax
    .IF lpqwTotalBytesRead != NULL
        mov rbx, lpqwTotalBytesRead
        mov rax, Position
        mov [rbx], rax
    .ENDIF
    
    mov rax, TRUE
    ret
RpcEndpointReadData ENDP

;------------------------------------------------------------------------------
; RpcEndpointFreeData - Frees allocated memory used by RpcEndpointReadData
;------------------------------------------------------------------------------
RpcEndpointFreeData PROC FRAME USES RBX lpqwDataBuffer:QWORD

    IFDEF DEBUG64
    PrintText 'RpcEndpointFreeData'
    ENDIF
    
    .IF lpqwDataBuffer != NULL
        mov rbx, lpqwDataBuffer
        mov rax, [rbx]
        .IF rax != NULL
            Invoke GlobalFree, rax
        .ENDIF
        mov rbx, lpqwDataBuffer
        mov rax, 0
        mov [rbx], rax
    .ENDIF
    xor rax, rax
    ret
RpcEndpointFreeData ENDP

;------------------------------------------------------------------------------
; RpcEndpointGET - Access lpszEndpointUrl via GET and optionally return data
; if lpqwData is not null. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; Data returned will be stored as a pointer in the QWORD pointed to by lpqwData
; 
; If data is to be returned, then the QWORD pointed to by lpqwDataSize will 
; contain the size of the data pointed to by lpqwData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszDataToFile is optional, and points to a string containing a filename to 
; write returned data to.
;------------------------------------------------------------------------------
RpcEndpointGET PROC FRAME USES RBX hRpc:QWORD, lpszEndpointUrl:QWORD, lpqwData:QWORD, lpqwDataSize:QWORD, lpszDataToFile:QWORD
    LOCAL pDataBuffer:QWORD
    LOCAL qwDataBufferSize:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointGET'
    ENDIF     
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpqwData != NULL
            mov rbx, lpqwData
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        .IF lpqwDataSize != NULL
            mov rbx, lpqwDataSize
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Open GET endpoint
    ;--------------------------------------------------------------------------
    IFDEF DEBUG64
        PrintText 'RpcEndpointGET-RpcEndpointOpen'
    ENDIF      
    Invoke RpcEndpointOpen, hRpc, Addr szGetVerb, lpszEndpointUrl, NULL, 0
    .IF rax == FALSE
        IFDEF DEBUG64
            PrintText 'RpcEndpointGET-RpcEndpointOpen Error'
        ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    .IF lpqwData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) if status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            IFDEF DEBUG64
                PrintText 'RpcEndpointGET-RpcEndpointReadData'
            ENDIF          
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr qwDataBufferSize
            .IF rax == FALSE || pDataBuffer == NULL
                IFDEF DEBUG64
                    PrintText 'RpcEndpointGET-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor rax, rax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszDataToFile != NULL
                Invoke RpcWriteDataToLocalFile, lpszDataToFile, pDataBuffer, qwDataBufferSize
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov rbx, lpqwData
            mov rax, pDataBuffer
            mov [rbx], rax
            
            .IF lpqwDataSize != NULL
                mov rbx, lpqwDataSize
                mov rax, qwDataBufferSize
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov rbx, lpqwData
            mov rax, 0
            mov [rbx], rax
            
            .IF lpqwDataSize != NULL
                mov rbx, lpqwDataSize
                mov rax, 0
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            mov rax, TRUE
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ENDIF
    ret
RpcEndpointGET ENDP

;------------------------------------------------------------------------------
; RpcEndpointPOST - Access lpszEndpointUrl via POST and optionally send and/or 
; return data. If lpPostData is != NULL, then will send data, if lpqwData is 
; != NULL then will return data. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; if sending data, then qwPostDataSize must include the size of data.
; 
; Data returned will be stored as a pointer in the QWORD pointed to by lpqwData
;
; If data is to be returned, then the QWORD pointed to by lpqwDataSize will 
; contain the size of the data pointed to by lpData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszDataToFile is optional, and points to a string containing a filename to 
; write returned data to.
;------------------------------------------------------------------------------
RpcEndpointPOST PROC FRAME USES RBX hRpc:QWORD, lpszEndpointUrl:QWORD, lpPostData:QWORD, qwPostDataSize:QWORD, lpqwData:QWORD, lpqwDataSize:QWORD, lpszDataToFile:QWORD
    LOCAL pDataBuffer:QWORD
    LOCAL qwDataBufferSize:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointPOST'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpqwData != NULL
            mov rbx, lpqwData
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        .IF lpqwDataSize != NULL
            mov rbx, lpqwDataSize
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    ;--------------------------------------------------------------------------
    ; Open POST endpoint and send data if we have some to send
    ;--------------------------------------------------------------------------
    .IF lpPostData != NULL && qwPostDataSize != 0
        Invoke RpcEndpointOpen, hRpc, Addr szPostVerb, lpszEndpointUrl, lpPostData, qwPostDataSize
    .ELSE
        Invoke RpcEndpointOpen, hRpc, Addr szPostVerb, lpszEndpointUrl, NULL, 0
    .ENDIF
    .IF rax == FALSE
        IFDEF DEBUG64
            PrintText 'RpcEndpointPOST-RpcEndpointOpen Error'
        ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    .IF lpqwData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) and status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr qwDataBufferSize
            .IF rax == FALSE || pDataBuffer == NULL
                IFDEF DEBUG64
                    PrintText 'RpcEndpointPOST-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor rax, rax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszDataToFile != NULL
                Invoke RpcWriteDataToLocalFile, lpszDataToFile, pDataBuffer, qwDataBufferSize
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov rbx, lpqwData
            mov rax, pDataBuffer
            mov [rbx], rax
            
            .IF lpqwDataSize != NULL
                mov rbx, lpqwDataSize
                mov rax, qwDataBufferSize
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov rbx, lpqwData
            mov rax, 0
            mov [rbx], rax
            
            .IF lpqwDataSize != NULL
                mov rbx, lpqwDataSize
                mov rax, 0
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            mov rax, TRUE
        .ELSE
            mov rax, FALSE
        .ENDIF
    .ENDIF
    ret
RpcEndpointPOST ENDP

;------------------------------------------------------------------------------
; RpcEndpointCall - Access lpszEndpointUrl and optionally send and / or 
; return data. If lpSendData is != NULL, then will send data, if 
; lpqwReceiveData is != NULL then will return data. 
; Returns: TRUE if successfull or FALSE otherwise
; 
; if sending data, then qwSendDataSize must include the size of data.
; 
; Data returned will be stored as a pointer in the QWORD pointed to by 
; lpqwReceiveData
;
; If data is to be returned, then the QWORD pointed to by lpqwReceiveDataSize 
; will contain the size of the data pointed to by lpqwReceiveData.
;
; Data returned should be freed via the use of RpcEndpointFreeData when it is 
; no longer needed or required.
; 
; lpszReceiveDataFile is optional, and points to a string containing a filename
; to write returned data to (in addition to returned data via lpqwReceiveData).
;------------------------------------------------------------------------------
RpcEndpointCall PROC FRAME USES RBX hRpc:QWORD, qwRpcType:QWORD, lpszEndpointUrl:QWORD, lpSendData:QWORD, qwSendDataSize:QWORD, lpqwReceiveData:QWORD, lpqwReceiveDataSize:QWORD, lpszReceiveDataFile:QWORD
    LOCAL pDataBuffer:QWORD
    LOCAL qwDataBufferSize:QWORD
    LOCAL lpszVerb:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcEndpointCall'
    ENDIF
    
    .IF hRpc == NULL || lpszEndpointUrl == NULL
        .IF lpqwReceiveData != NULL
            mov rbx, lpqwReceiveData
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        .IF lpqwReceiveDataSize != NULL
            mov rbx, lpqwReceiveDataSize
            mov rax, 0
            mov [rbx], rax
        .ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    mov rax, qwRpcType
    .IF rax == RPC_GET
        lea rax, szGetVerb
    .ELSEIF rax == RPC_POST
        lea rax, szPostVerb
    .ELSEIF rax == RPC_PUT
        lea rax, szPutVerb
    .ELSEIF rax == RPC_PATCH
        lea rax, szPatchVerb
    .ELSEIF rax == RPC_DELETE
        lea rax, szDeleteVerb
    .ELSEIF rax == RPC_HEAD
        lea rax, szHeadVerb
    .ELSEIF rax == RPC_OPTIONS
        lea rax, szOptionsVerb
    .ELSE
        lea rax, szGetVerb
    .ENDIF
    mov lpszVerb, rax
    
    ;--------------------------------------------------------------------------
    ; Open endpoint and send data if we have some to send
    ;--------------------------------------------------------------------------
    .IF lpSendData != NULL && qwSendDataSize != 0
        Invoke RpcEndpointOpen, hRpc, lpszVerb, lpszEndpointUrl, lpSendData, qwSendDataSize
    .ELSE
        Invoke RpcEndpointOpen, hRpc, lpszVerb, lpszEndpointUrl, NULL, 0
    .ENDIF
    .IF rax == FALSE
        IFDEF DEBUG64
            PrintText 'RpcEndpointCall-RpcEndpointOpen Error'
        ENDIF
        xor rax, rax
        ret
    .ENDIF
    
    .IF lpqwReceiveData != NULL
        ;----------------------------------------------------------------------
        ; Get data returned (if required) and status is 200 (HTTP_STATUS_OK)
        ;----------------------------------------------------------------------
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            ;------------------------------------------------------------------
            ; Read endpoint data
            ;------------------------------------------------------------------
            Invoke RpcEndpointReadData, hRpc, Addr pDataBuffer, Addr qwDataBufferSize
            .IF rax == FALSE || pDataBuffer == NULL
                IFDEF DEBUG64
                    PrintText 'RpcEndpointCall-RpcEndpointReadData Error'
                ENDIF
                Invoke RpcEndpointClose, hRpc
                xor rax, rax
                ret
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Write endpoint data to local file (optional)
            ;------------------------------------------------------------------
            .IF lpszReceiveDataFile != NULL
                Invoke RpcWriteDataToLocalFile, lpszReceiveDataFile, pDataBuffer, qwDataBufferSize
            .ENDIF
            
            ;------------------------------------------------------------------
            ; Return pointers to endpoint data and data size 
            ;------------------------------------------------------------------
            mov rbx, lpqwReceiveData
            mov rax, pDataBuffer
            mov [rbx], rax
            
            .IF lpqwReceiveDataSize != NULL
                mov rbx, lpqwReceiveDataSize
                mov rax, qwDataBufferSize
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, TRUE
        .ELSE
            ;------------------------------------------------------------------
            ; Looking to fetch data, but error instead (! 200 - HTTP_STATUS_OK)
            ;------------------------------------------------------------------
            mov rbx, lpqwReceiveData
            mov rax, 0
            mov [rbx], rax
            
            .IF lpqwReceiveDataSize != NULL
                mov rbx, lpqwReceiveDataSize
                mov rax, 0
                mov [rbx], rax
            .ENDIF
            
            Invoke RpcEndpointClose, hRpc
            mov rax, FALSE
        .ENDIF
    .ELSE
        ;----------------------------------------------------------------------
        ; Endpoint data wasnt required, so just return ok if 200 - HTTP_STATUS_OK
        ;----------------------------------------------------------------------
        Invoke RpcEndpointClose, hRpc
        mov rbx, hRpc
        mov rax, [rbx].RPC_HANDLE.qwStatusCode
        .IF rax == HTTP_STATUS_OK
            mov rax, TRUE
        .ELSE
            mov rax, FALSE
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
RpcGetStatusCode PROC FRAME USES RBX hRpc:QWORD
    .IF hRpc == NULL
        mov rax, -1
        ret
    .ENDIF
    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.qwStatusCode
    ret
RpcGetStatusCode ENDP


;##############################################################################
; Internal Utility Functions
;##############################################################################

;------------------------------------------------------------------------------
; RpcGetRemoteFileSize - Get remote file size and return it in lpqwRemoteFileSize
;------------------------------------------------------------------------------
RpcGetRemoteFileSize PROC FRAME USES RBX hRpc:QWORD, lpdwRemoteFileSize:QWORD
    LOCAL hRequest:QWORD
    LOCAL BytesToGet:QWORD
    LOCAL BytesToGetSize:QWORD
    LOCAL lpqwIndex:QWORD
    LOCAL ContentLength[32]:BYTE

    IFDEF DEBUG64
        PrintText 'RpcGetRemoteFileSize'
    ENDIF
    
    .IF hRpc == NULL
        mov rax, FALSE
        ret
    .ENDIF

    .IF lpdwRemoteFileSize == NULL
        mov rax, FALSE
        ret
    .ENDIF

    mov rbx, hRpc
    mov rax, [rbx].RPC_HANDLE.hRequest
    .IF rax == NULL
        mov rax, FALSE
        ret
    .ENDIF    
    mov hRequest, rax

    mov BytesToGetSize, 4d
    mov lpqwIndex, 0

    IFDEF DEBUG64
        PrintText 'RpcGetRemoteFileSize-HttpQueryInfo'
    ENDIF
    Invoke HttpQueryInfo, hRequest, HTTP_QUERY_FLAG_NUMBER or HTTP_QUERY_CONTENT_LENGTH, Addr BytesToGet, Addr BytesToGetSize, Addr lpqwIndex ; HTTP_QUERY_FLAG_NUMBER +
    .IF rax == FALSE
        mov BytesToGetSize, 32d
        mov lpqwIndex, 0
        
        Invoke RtlZeroMemory, Addr ContentLength, 32d
        Invoke lstrcpy, Addr ContentLength, Addr szContentLengthHeader
        
        IFDEF DEBUG64
            PrintText 'RpcGetRemoteFileSize-HttpQueryInfo::ContentLength Header'
        ENDIF
        Invoke HttpQueryInfo, hRequest, HTTP_QUERY_CUSTOM, Addr ContentLength, Addr BytesToGetSize, Addr lpqwIndex
        .IF rax == FALSE
            mov rbx, lpdwRemoteFileSize
            mov rax, 0
            mov [rbx], rax
            mov rax, FALSE
            ret
        .ELSE
            lea rbx, ContentLength
            add rbx, 16d ; 'Content-Length: '
            Invoke atou_ex, rbx
            mov BytesToGet, rax
        .ENDIF
    .ENDIF
    mov rbx, lpdwRemoteFileSize
    mov rax, BytesToGet
    mov dword ptr [rbx], eax
    mov rax, TRUE    
    ret
RpcGetRemoteFileSize ENDP

;------------------------------------------------------------------------------
; RpcBase64Encode - Base64 encode source string to destination string
;------------------------------------------------------------------------------
RpcBase64Encode PROC FRAME USES RBX RCX RDX RDI RSI lpszSource:QWORD, lpszDestination:QWORD, qwSourceLength:QWORD

    mov  rsi, lpszSource
    mov  rdi, lpszDestination
@@base64loop:
    xor rax, rax
    .IF qwSourceLength == 1
        lodsb                           ;source ptr + 1
        mov ecx, 2                      ;bytes to output = 2
        mov edx, 03D3Dh                 ;padding = 2 byte
        dec qwSourceLength              ;length - 1
    .ELSEIF qwSourceLength == 2
        lodsw                           ;source ptr + 2
        mov ecx, 3                      ;bytes to output = 3
        mov edx, 03Dh                   ;padding = 1 byte
        sub qwSourceLength, 2           ;length - 2
    .ELSE
        lodsd
        mov ecx, 4                      ;bytes to output = 4
        xor edx, edx                    ;padding = 0 byte
        dec rsi                         ;source ptr + 3 (+4-1)
        sub qwSourceLength, 3           ;length - 3 
    .ENDIF

    xchg al,ah                          ; flip eax completely
    rol  eax, 16                        ; can this be done faster
    xchg al,ah                          ; ??

    @@:
    push  rax
    and   eax, 0FC000000h               ;get the last 6 high bits
    rol   eax, 6                        ;rotate them into al
    lea   rbx, Base64Alphabet
    mov   al, byte ptr [rbx+rax]        ;get encode character
    stosb                               ;write to destination
    pop   rax
    shl   eax, 6                        ;shift left 6 bits
    dec   ecx
    jnz   @B                            ;loop
    
    cmp   qwSourceLength, 0
    jnz   @@base64loop                  ;main loop
    
    mov   eax, edx                      ;add padding and null terminate
    stosd   

    ret
RpcBase64Encode ENDP

;------------------------------------------------------------------------------
; RpcWriteDataToLocalFile - Write data to file
;------------------------------------------------------------------------------
RpcWriteDataToLocalFile PROC FRAME lpszLocalFilename:QWORD, pDataBuffer:QWORD, qwDataBufferSize:QWORD
    LOCAL hFile:QWORD
    LOCAL hMapFile:QWORD
    LOCAL pViewFile:QWORD
    
    IFDEF DEBUG64
        PrintText 'RpcWriteDataToLocalFile'
    ENDIF      
    
    .IF lpszLocalFilename == NULL || pDataBuffer == NULL || qwDataBufferSize == NULL
        IFDEF DEBUG64
            PrintText 'RpcWriteDataToLocalFile null params'
        ENDIF      
        mov rax, FALSE
        ret
    .ENDIF
    
    Invoke CreateFile, lpszLocalFilename, GENERIC_READ or GENERIC_WRITE, FILE_SHARE_READ or FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL
    .IF rax == INVALID_HANDLE_VALUE
        IFDEF DEBUG64
            PrintText 'RpcWriteDataToLocalFile CreateFile Error'
        ENDIF   
        mov rax, FALSE
        ret
    .ENDIF
    mov hFile, rax
    
    Invoke CreateFileMapping, hFile, NULL, PAGE_READWRITE, 0, dword ptr qwDataBufferSize, NULL
    .IF rax == NULL
        IFDEF DEBUG64
            PrintText 'RpcWriteDataToLocalFile CreateFileMapping Error'
        ENDIF
        Invoke CloseHandle, hFile 
        mov rax, FALSE
        ret
    .ENDIF
    mov hMapFile, rax    
    
    Invoke MapViewOfFileEx, hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0, NULL
    .IF rax == NULL
        IFDEF DEBUG64
            PrintText 'RpcWriteDataToLocalFile MapViewOfFile Error'
        ENDIF
        Invoke CloseHandle, hMapFile
        Invoke CloseHandle, hFile
        mov rax, FALSE
        ret
    .ENDIF
    mov pViewFile, rax    

    Invoke RtlMoveMemory, pViewFile, pDataBuffer, qwDataBufferSize
    
    Invoke UnmapViewOfFile, pViewFile
    Invoke CloseHandle, hMapFile
    Invoke CloseHandle, hFile
    
    mov rax, TRUE
    ret
RpcWriteDataToLocalFile ENDP

;------------------------------------------------------------------------------
; Convert ascii string pointed to by String param to unsigned qword value. 
; Returns qword value in rax.
;------------------------------------------------------------------------------
atou_ex PROC FRAME String:QWORD
    xor eax,eax
    xor edx,edx
  .repeat
    movzx r8, BYTE PTR [rcx+rdx]
    .if (!r8)
      mov rcx, -1          ; non zero in RCX for success
      jmp done
    .endif
    lea rax, [rax+rax*4]
    lea rax, [r8+rax*2-48]
    inc edx
  .until (edx==20)
  xor ecx,ecx              ;zero means out of range error
done:     
    ret                    ; rax contains the number
atou_ex endp



utoa_ex PROC FRAME USES rbx value:QWORD, buffer:QWORD, radix:DWORD, sign:DWORD, addzero:DWORD
    LOCAL tmpbuf[34]:BYTE 
    mov rbx,rdx      ;buffer
    mov r10,rdx      ;buffer
    .if (!rcx)
        mov rax,rdx
        mov byte ptr[rax],'0'
        jmp done
    .endif 
    .if (r9b)
        mov byte ptr [rdx],2Dh           
        lea r10,[rdx+1]       
        neg rcx
    .endif
    lea r9, tmpbuf[33]                     
    mov byte ptr tmpbuf[33],0
    lea r11, hextbl
    .repeat
        xor edx,edx                      ;clear rdx               
        mov rax,rcx                      ;value into rax
        dec r9                           ;make space for next char
        div r8                           ;div value with radix (2, 8, 10, 16)
        mov rcx,rax                      ;mod is in rdx, save result back in rcx
        movzx eax,byte ptr [rdx+r11]     ;put char from hextbl pointed by rdx
        mov byte ptr [r9], al            ;store char from al to tmpbuf pointed by r9
    .until (!rcx)                        ;repeat if rcx not clear
    .if (addzero && al > '9')            ;add a leading '0' if first digit is alpha
        mov word ptr[r10],'x0'
        add r10, 2
        ;mov byte ptr[r10],'0'
        ;inc r10
    .endif
    lea r8, tmpbuf[34]                   ;start of the buffer in r8
    sub r8, r9                           ;that will give a count of chars to be copied
    invoke RtlMoveMemory, r10, r9, r8    ;call routine to copy
    mov rax,rbx                          ;return the address of the buffer in rax
done: ret
utoa_ex ENDP




END
