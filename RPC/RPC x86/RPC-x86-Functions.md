# RPC x86 Functions

### RpcCheckConnection

*Description*: Checks if connection can be made to specified host address

*Parameters*: `lpszHost`, `lpszPort`, `bSecure`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcConnect

*Description*: Connects to specified host address specified via `lpszHost` and `lpszPort`. If `bSecure` is `FALSE` then it uses `http` , `TRUE` it uses `https`. `lpdwRpcHandle` points to a `DWORD` for storing the returning RPC handle (`hRpc`) which is used in other RPC functions.

*Parameters*: `lpszHost`, `lpszPort`, `bSecure`, `lpszUserAgent`, `lpdwRpcHandle`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcDisconnect

*Description*: Disconnects from a connection made via the `RpcConnect` function.

*Parameters*: `hRpc`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetCookie

*Description*: Sets cookie data for an RPC connection.

*Parameters*: `hRpc`, `lpszCookieData`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetAuthBasic

*Description*: Sets authentication (basic) header for an RPC connection.

*Parameters*: `hRpc`, `lpszUsername`, `lpszPassword`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetAcceptType

*Description*: Sets the `Accept` header for MIME / Media types that are accepted by the client for an RPC conneciton. If `lpszAcceptType` is `NULL` then any existing `Accept` header is freed. `dwAcceptType` can be used as an alternative, to provide a constant value representing some common media types.

*Parameters*: `hRpc`, `lpszAcceptType`, `dwAcceptType`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.se.

### RpcSetContentType

*Description*: Sets the `ContentType` header for MIME / Media types that are being sent by the client for an RPC conneciton. If `lpszContentType` is `NULL` then any existing `ContentType` header is freed. `dwContentType` can be used as an alternative, to provide a constant value representing some common media types.

*Parameters*: `hRpc`, `lpszContentType`, `dwContentType`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetApiKey

*Description*: Add an api key and value to be included with endpoint calls. `lpszRpcApiKeyName` is a pointer to a string containing the api key name, for example: 'ApiKey' or 'api_key', etc. `lpszRpcApiKeyValue` is a pointer to a string containing the api key value, for example: '7bf567042aea488ba256583eaebf638f'. These are automatically added to all Endpoint url in `RpcEndpointOpen`, for example:
`/GetInfo?api_key=7bf567042aea488ba256583eaebf638f`

*Parameters*: `hRpc`, `lpszRpcApiKeyName`, `lpszRpcApiKeyValue`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetPathVariable

*Description*: Adds a path variable to the endpoint url.

*Parameters*: `hRpc`, `lpszVariable`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetQueryParameters

*Description*: Constructs and adds Query Parameters (`?name=value` pairs) to the endpoint url. `dwValue` can be used instead of `lpszValue` and it will convert the value to a string.

*Parameters*: `hRpc`, `lpszName`, `lpszValue`, `dwValue`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointOpen

*Description*: Opens a endpoint url, `lpszEndpointUrl` is the long pointer to a zero terminated string containing the url to open. If `lpszVerb` is `NULL` then defaults to `GET`. `lpSendData` and `dwSendDataSize` are optional -  typically for `POST` sending data.

*Parameters*: `hRpc`, `lpszVerb`, `lpszEndpointUrl`, `lpSendData`, `dwSendDataSize`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointClose

*Description*: Closes and endpoint url opened by `RpcEndpointOpen`

*Parameters*: `hRpc`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointReadData

*Description*: Read endpoint url data and return pointer to data in `lpdwDataBuffer`, along with size of data in `lpdwTotalBytesRead`. _Note_: Use `RpcEndpointFreeData` after finishing processing file data, to free memory.

*Parameters*: `hRpc`, `lpdwDataBuffer`, `lpdwTotalBytesRead`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointFreeData

*Description*: Frees allocated memory used by `RpcEndpointReadData`. `lpdwDataBuffer` is the same long pointer to a `DWORD` that stores the pointer to the data returned from the `RpcEndpointReadData` function.

*Parameters*: `lpdwDataBuffer`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointGET

*Description*: Access `lpszEndpointUrl` via `GET` and optionally return data if `lpdwData` is not null. Data returned will be stored as a pointer in the `DWORD` pointed to by `lpdwData`. If data is to be returned, then the `DWORD` pointed to by `lpdwDataSize` will contain the size of the data pointed to by `lpdwData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszDataToFile` is optional, and points to a string containing a filename to write returned data to.

*Parameters*: `hRpc`, `lpszEndpointUrl`, `lpdwData`, `lpdwDataSize`, `lpszDataToFile`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointPOST

*Description*: Access `lpszEndpointUrl` via `POST` and optionally send and/or return data. If `lpPostData` is != `NULL`, then will send data, if `lpdwData` is != `NULL` then will return data. If sending data, then `dwPostDataSize` must include the size of data. Data returned will be stored as a pointer in the `DWORD` pointed to by `lpdwData`. If data is to be returned, then the `DWORD` pointed to by `lpdwDataSize` will contain the size of the data pointed to by `lpData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszDataToFile` is optional, and points to a string containing a filename to write returned data to.

*Parameters*: `hRpc`, `lpszEndpointUrl`, `lpPostData`, `dwPostDataSize`, `lpdwData`, `lpdwDataSize`, `lpszDataToFile`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointCall

*Description*: Access `lpszEndpointUrl` and optionally send and / or return data. If `lpSendData` is != `NULL`, then will send data, if `lpdwReceiveData` is != NULL then will return data. If sending data, then `dwSendDataSize` must include the size of data. Data returned will be stored as a pointer in the `DWORD` pointed to by `lpdwReceiveData`. If data is to be returned, then the `DWORD` pointed to by `lpdwReceiveDataSize` will contain the size of the data pointed to by `lpdwReceiveData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszReceiveDataFile` is optional, and points to a string containing a filename to write returned data to (in addition to returned data via `lpdwReceiveData`).

*Parameters*: `hRpc`, `dwRpcType`, `lpszEndpointUrl`, `lpSendData`, `dwSendDataSize`, `lpdwReceiveData`, `lpdwReceiveDataSize`, `lpszReceiveDataFile`

*Returns*: `eax` contains `TRUE` on success or `FALSE` otherwise.

### RpcGetStatusCode

*Description*: Get last status code error.

*Parameters*: `hRpc`,

*Returns*: `eax` contains: `-1` hRpc handle is null, `0` unknown Error, `>0` same as HTTP status codes: `200` OK, `404` etc.

