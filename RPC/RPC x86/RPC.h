#ifndef RPC__h
#define RPC__h

#ifdef __cplusplus
extern "C"
{
#endif

#define RPC_STDCALL __stdcall

RPC_STDCALL(bool) RpcCheckConnection(const char *lpszHostAddress, const char *lpszPort, bool bSecure);
RPC_STDCALL(bool) RpcConnect(const char *lpszHostAddress, const char *lpszPort, bool bSecure, const char *lpszUserAgent, HANDLE *lpdwRpcHandle);
RPC_STDCALL(bool) RpcDisconnect(HANDLE hRpc);

RPC_STDCALL(bool) RpcSetCookie(HANDLE hRpc, const char *lpszCookieData);
RPC_STDCALL(bool) RpcSetAuthBasic(HANDLE hRpc, const char *lpszUsername, const char *lpszPassword);
RPC_STDCALL(bool) RpcSetAcceptType(HANDLE hRpc, const char *lpszAcceptType, int dwAcceptType);
RPC_STDCALL(bool) RpcSetContentType(HANDLE hRpc, const char *lpszContentType, int dwContentType);
RPC_STDCALL(bool) RpcSetPathVariable(HANDLE hRpc, const char *lpszVariable);
RPC_STDCALL(bool) RpcSetQueryParameters(HANDLE hRpc, const char *lpszName, const char *lpszValue, int dwValue);

RPC_STDCALL(bool) RpcEndpointOpen(HANDLE hRpc, const char *lpszVerb, const char *lpszEndpointUrl, int *lpSendData, int dwSendDataSize);
RPC_STDCALL(bool) RpcEndpointClose(HANDLE hRpc);

RPC_STDCALL(bool) RpcEndpointReadData(HANDLE hRpc, int *lpdwDataBuffer, int *lpdwTotalBytesRead);
RPC_STDCALL(bool) RpcEndpointFreeData(int *lpdwDataBuffer);

RPC_STDCALL(bool) RpcEndpointGET(HANDLE hRpc, const char *lpszEndpointUrl, int *lpdwData, int *lpdwDataSize, const char *lpszDataToFile);
RPC_STDCALL(bool) RpcEndpointPOST(HANDLE hRpc, const char *lpszEndpointUrl, int lpPostData, int dwPostDataSize, int *lpdwData, int *lpdwDataSize, const char *lpszDataToFile);
RPC_STDCALL(bool) RpcEndpointCall(HANDLE hRpc, int dwRpcType, const char *lpszEndpointUrl, int *lpSendData, int dwSendDataSize, int *lpdwReceiveData, int *lpdwReceiveDataSize, const char *lpszReceiveDataFile);

RPC_STDCALL(bool) RpcGetStatusCode(HANDLE hRpc);

// RpcSetAcceptType dwAcceptType or RpcSetContentType dwContentType values (only common types):
#define RPC_MEDIATYPE_NONE   0 //
#define RPC_MEDIATYPE_ALL    1 // */*
#define RPC_MEDIATYPE_TEXT   2 // text/*
#define RPC_MEDIATYPE_HTML   3 // text/html
#define RPC_MEDIATYPE_XML    4 // application/xml
#define RPC_MEDIATYPE_JSON   5 // application/json
#define RPC_MEDIATYPE_FORM   6 // application/x-www-form-urlencoded



#ifdef __cplusplus
}
#endif

#endif