# RPC x64 Functions

### RpcCheckConnection

*Description*: Checks if connection can be made to specified host address

*Parameters*: `lpszHost`, `lpszPort`, `bSecure`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcConnect

*Description*: Connects to specified host address specified via `lpszHost` and `lpszPort`. If `bSecure` is `FALSE` then it uses `http` , `TRUE` it uses `https`. `lpqwRpcHandle` points to a `QWORD` for storing the returning RPC handle (`hRpc`) which is used in other RPC functions.

*Parameters*: `lpszHost`, `lpszPort`, `bSecure`, `lpszUserAgent`, `lpqwRpcHandle`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcDisconnect

*Description*: Disconnects from a connection made via the `RpcConnect` function.

*Parameters*: `hRpc`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetCookie

*Description*: Sets cookie data for an RPC connection.

*Parameters*: `hRpc`, `lpszCookieData`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetAuthBasic

*Description*: Sets authentication (basic) header for an RPC connection.

*Parameters*: `hRpc`, `lpszUsername`, `lpszPassword`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetAcceptType

*Description*: Sets the `Accept` header for MIME / Media types that are accepted by the client for an RPC conneciton. If `lpszAcceptType` is `NULL` then any existing `Accept` header is freed. `qwAcceptType` can be used as an alternative, to provide a constant value representing some common media types.

*Parameters*: `hRpc`, `lpszAcceptType`, `qwAcceptType`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.se.

### RpcSetContentType

*Description*: Sets the `ContentType` header for MIME / Media types that are being sent by the client for an RPC conneciton. If `lpszContentType` is `NULL` then any existing `ContentType` header is freed. `qwContentType` can be used as an alternative, to provide a constant value representing some common media types.

*Parameters*: `hRpc`, `lpszContentType`, `qwContentType`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetApiKey

*Description*: Add an api key and value to be included with endpoint calls. `lpszRpcApiKeyName` is a pointer to a string containing the api key name, for example: 'ApiKey' or 'api_key', etc. `lpszRpcApiKeyValue` is a pointer to a string containing the api key value, for example: '7bf567042aea488ba256583eaebf638f'. These are automatically added to all Endpoint url in `RpcEndpointOpen`, for example:
`/GetInfo?api_key=7bf567042aea488ba256583eaebf638f`

*Parameters*: `hRpc`, `lpszRpcApiKeyName`, `lpszRpcApiKeyValue`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetPathVariable

*Description*: Adds a path variable to the endpoint url.

*Parameters*: `hRpc`, `lpszVariable`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcSetQueryParameters

*Description*: Constructs and adds Query Parameters (`?name=value` pairs) to the endpoint url. `qwValue` can be used instead of `lpszValue` and it will convert the value to a string.

*Parameters*: `hRpc`, `lpszName`, `lpszValue`, `qwValue`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointOpen

*Description*: Opens a endpoint url, `lpszEndpointUrl` is the long pointer to a zero terminated string containing the url to open. If `lpszVerb` is `NULL` then defaults to `GET`. `lpSendData` and `qwSendDataSize` are optional -  typically for `POST` sending data.

*Parameters*: `hRpc`, `lpszVerb`, `lpszEndpointUrl`, `lpSendData`, `qwSendDataSize`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointClose

*Description*: Closes and endpoint url opened by `RpcEndpointOpen`

*Parameters*: `hRpc`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointReadData

*Description*: Read endpoint url data and return pointer to data in `lpqwDataBuffer`, along with size of data in `lpqwTotalBytesRead`. _Note_: Use `RpcEndpointFreeData` after finishing processing file data, to free memory.

*Parameters*: `hRpc`, `lpqwDataBuffer`, `lpqwTotalBytesRead`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointFreeData

*Description*: Frees allocated memory used by `RpcEndpointReadData`. `lpqwDataBuffer` is the same long pointer to a `QWORD` that stores the pointer to the data returned from the `RpcEndpointReadData` function.

*Parameters*: `lpqwDataBuffer`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointGET

*Description*: Access `lpszEndpointUrl` via `GET` and optionally return data if `lpqwData` is not null. Data returned will be stored as a pointer in the `QWORD` pointed to by `lpqwData`. If data is to be returned, then the `QWORD` pointed to by `lpqwDataSize` will contain the size of the data pointed to by `lpqwData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszDataToFile` is optional, and points to a string containing a filename to write returned data to.

*Parameters*: `hRpc`, `lpszEndpointUrl`, `lpqwData`, `lpqwDataSize`, `lpszDataToFile`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointPOST

*Description*: Access `lpszEndpointUrl` via `POST` and optionally send and/or return data. If `lpPostData` is != `NULL`, then will send data, if `lpqwData` is != `NULL` then will return data. If sending data, then `qwPostDataSize` must include the size of data. Data returned will be stored as a pointer in the `QWORD` pointed to by `lpqwData`. If data is to be returned, then the `QWORD` pointed to by `lpqwDataSize` will contain the size of the data pointed to by `lpData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszDataToFile` is optional, and points to a string containing a filename to write returned data to.

*Parameters*: `hRpc`, `lpszEndpointUrl`, `lpPostData`, `qwPostDataSize`, `lpqwData`, `lpqwDataSize`, `lpszDataToFile`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcEndpointCall

*Description*: Access `lpszEndpointUrl` and optionally send and / or return data. If `lpSendData` is != `NULL`, then will send data, if `lpqwReceiveData` is != NULL then will return data. If sending data, then `qwSendDataSize` must include the size of data. Data returned will be stored as a pointer in the `QWORD` pointed to by `lpqwReceiveData`. If data is to be returned, then the `QWORD` pointed to by `lpqwReceiveDataSize` will contain the size of the data pointed to by `lpqwReceiveData`. Data returned should be freed via the use of `RpcEndpointFreeData` when it is no longer needed or required. `lpszReceiveDataFile` is optional, and points to a string containing a filename to write returned data to (in addition to returned data via `lpqwReceiveData`).

*Parameters*: `hRpc`, `qwRpcType`, `lpszEndpointUrl`, `lpSendData`, `qwSendDataSize`, `lpqwReceiveData`, `lpqwReceiveDataSize`, `lpszReceiveDataFile`

*Returns*: `rax` contains `TRUE` on success or `FALSE` otherwise.

### RpcGetStatusCode

*Description*: Get last status code error.

*Parameters*: `hRpc`,

*Returns*: `rax` contains: `-1` hRpc handle is null, `0` unknown Error, `>0` same as HTTP status codes: `200` OK, `404` etc.

