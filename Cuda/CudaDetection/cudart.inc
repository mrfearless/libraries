;-------------------------------------------------------------------------------------------
; CUDA Runtime Constants, Structures & Prototypes for v8
; http://docs.nvidia.com/cuda/cuda-runtime-api/index.html
;-------------------------------------------------------------------------------------------

;---------------------------------
; CUDA Device Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__DEVICE.html#group__CUDART__DEVICE
;---------------------------------
cudaChooseDevice                    PROTO :QWORD, :QWORD;           ( int* device, const cudaDeviceProp* prop )         Select compute-device which best matches criteria. 
cudaDeviceGetAttribute              PROTO :QWORD, :QWORD, :QWORD;   ( int* value, cudaDeviceAttr attr, int  device );   Returns information about the device. 
cudaDeviceGetByPCIBusId             PROTO :QWORD, :QWORD;           ( int* device, const char* pciBusId );              Returns a handle to a compute device. 
cudaDeviceGetCacheConfig            PROTO :QWORD;                   ( cudaFuncCache ** pCacheConfig );                  Returns the preferred cache configuration for the current device. 
cudaDeviceGetLimit                  PROTO :QWORD, :QWORD;           ( size_t* pValue, cudaLimit limit );                Returns resource limits. 
cudaDeviceGetP2PAttribute           PROTO :QWORD, :QWORD, :QWORD, :QWORD;   ( int* value, cudaDeviceP2PAttr attr, int  srcDevice, int  dstDevice ) Queries attributes of the link between two devices. 
cudaDeviceGetPCIBusId               PROTO :QWORD, :QWORD, :QWORD;   ( char* pciBusId, int  len, int  device );          Returns a PCI Bus Id string for the device. (lpszPciBusID, PCI_BUS_LEN)
cudaDeviceGetSharedMemConfig        PROTO :QWORD;                   ( cudaSharedMemConfig ** pConfig );                 Returns the shared memory configuration for the current device. 
cudaDeviceGetStreamPriorityRange    PROTO :QWORD, :QWORD;           ( int* leastPriority, int* greatestPriority );      Returns numerical values that correspond to the least and greatest stream priorities. 
cudaDeviceReset                     PROTO;                          ( void );                                           Destroy all allocations and reset all state on the current device in the current process. 
cudaDeviceSetCacheConfig            PROTO :QWORD;                   ( cudaFuncCache cacheConfig );                      Sets the preferred cache configuration for the current device. 
cudaDeviceSetLimit                  PROTO :QWORD, :QWORD;           ( cudaLimit limit, size_t value );                  Set resource limits. 
cudaDeviceSetSharedMemConfig        PROTO :QWORD;                   ( cudaSharedMemConfig config );                     Sets the shared memory configuration for the current device. 
cudaDeviceSynchronize               PROTO;                          ( void );                                           Wait for compute device to finish. 
cudaGetDevice                       PROTO :QWORD;                   ( int* device );                                    Returns which device is currently being used. 
cudaGetDeviceCount                  PROTO :QWORD;                   ( int* count );                                     Returns the number of compute-capable devices. (lpdwCount)
cudaGetDeviceFlags                  PROTO :QWORD;                   ( unsigned int* flags );                            Gets the flags for the current device. 
cudaGetDeviceProperties             PROTO :QWORD, :QWORD;           ( cudaDeviceProp* prop, int  device );              Returns information about the compute-device. (lpCudaDeviceProp, dwDeviceID)
cudaIpcCloseMemHandle               PROTO :QWORD;                   ( void* devPtr );                                   Close memory mapped with cudaIpcOpenMemHandle. 
cudaIpcGetEventHandle               PROTO :QWORD, :QWORD;           ( cudaIpcEventHandle_t* handle, cudaEvent_t event ) Gets an interprocess handle for a previously allocated event. 
cudaIpcGetMemHandle                 PROTO :QWORD, :QWORD;           ( cudaIpcMemHandle_t* handle, void* devPtr );       Gets an interprocess memory handle for an existing device memory allocation. 
cudaIpcOpenEventHandle              PROTO :QWORD, :QWORD;           ( cudaEvent_t* event, cudaIpcEventHandle_t handle ) Opens an interprocess event handle for use in the current process. 
cudaIpcOpenMemHandle                PROTO :QWORD, :QWORD, :QWORD;   ( void** devPtr, cudaIpcMemHandle_t handle, unsigned int  flags ) Opens an interprocess memory handle exported from another process and returns a device pointer usable in the local process. 
cudaSetDevice                       PROTO :QWORD;                   ( int  device );                                    Set device to be used for GPU executions. 
cudaSetDeviceFlags                  PROTO :QWORD;                   ( unsigned int  flags );                            Sets flags to be used for device executions. 
cudaSetValidDevices                 PROTO :QWORD, :QWORD;           ( int* device_arr, int  len );                      Set a list of devices that can be used for CUDA. 

;---------------------------------
; CUDA Error Handling Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__ERROR.html#group__CUDART__ERROR
;---------------------------------
cudaGetErrorName                    PROTO :QWORD;                   ( cudaError_t error );                              Returns the string representation of an error code enum name. 
cudaGetErrorString                  PROTO :QWORD;                   ( cudaError_t error );                              Returns the description string for an error code. 
cudaGetLastError                    PROTO;                          ( void );                                           Returns the last error from a runtime call. 
cudaPeekAtLastError                 PROTO;                          ( void );                                           Returns the last error from a runtime call. 

;---------------------------------
; CUDA Stream Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__STREAM.html#group__CUDART__STREAM
;---------------------------------
cudaStreamAddCallback               PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaStream_t stream, cudaStreamCallback_t callback, void* userData, unsigned int  flags ) Add a callback to a compute stream. 
cudaStreamAttachMemAsync            PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaStream_t stream, void* devPtr, size_t length = 0, unsigned int  flags = cudaMemAttachSingle ) Attach memory to a stream asynchronously. 
cudaStreamCreate                    PROTO :QWORD;                   ( cudaStream_t* pStream );                          Create an asynchronous stream. 
cudaStreamCreateWithFlags           PROTO :QWORD, :QWORD;           ( cudaStream_t* pStream, unsigned int  flags );     Create an asynchronous stream. 
cudaStreamCreateWithPriority        PROTO :QWORD, :QWORD, :QWORD;   ( cudaStream_t* pStream, unsigned int  flags, int  priority ) Create an asynchronous stream with the specified priority. 
cudaStreamDestroy                   PROTO :QWORD;                   ( cudaStream_t stream );                            Destroys and cleans up an asynchronous stream. 
cudaStreamGetFlags                  PROTO :QWORD, :QWORD;           ( cudaStream_t hStream, unsigned int* flags );      Query the flags of a stream. 
cudaStreamGetPriority               PROTO :QWORD, :QWORD;           ( cudaStream_t hStream, int* priority );            Query the priority of a stream. 
cudaStreamQuery                     PROTO :QWORD;                   ( cudaStream_t stream );                            Queries an asynchronous stream for completion status. 
cudaStreamSynchronize               PROTO :QWORD;                   ( cudaStream_t stream );                            Waits for stream tasks to complete. 
cudaStreamWaitEvent                 PROTO :QWORD, :QWORD, :QWORD;   ( cudaStream_t stream, cudaEvent_t event, unsigned int  flags ) Make a compute stream wait on an event. 

;---------------------------------
; CUDA Event Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__EVENT.html#group__CUDART__EVENT
;---------------------------------
cudaEventCreate                     PROTO :QWORD;                   ( cudaEvent_t* event );                             Creates an event object. 
cudaEventCreateWithFlags            PROTO :QWORD, :QWORD;           ( cudaEvent_t* event, unsigned int  flags );        Creates an event object with the specified flags. 
cudaEventDestroy                    PROTO :QWORD;                   ( cudaEvent_t event );                              Destroys an event object. 
cudaEventElapsedTime                PROTO :QWORD, :QWORD, :QWORD;   ( float* ms, cudaEvent_t start, cudaEvent_t end );  Computes the elapsed time between events. 
cudaEventQuery                      PROTO :QWORD;                   ( cudaEvent_t event );                              Queries an event's status. 
cudaEventRecord                     PROTO :QWORD, :QWORD;           ( cudaEvent_t event, cudaStream_t stream = 0 );     Records an event. 
cudaEventSynchronize                PROTO :QWORD;                   ( cudaEvent_t event );                              Waits for an event to complete. 

;---------------------------------
; CUDA Execution Control Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__EXECUTION.html#group__CUDART__EXECUTION
;---------------------------------

cudaFuncGetAttributes               PROTO :QWORD, :QWORD;           ( cudaFuncAttributes* attr, const void* func );     Find out attributes for a given function. 
cudaFuncSetCacheConfig              PROTO :QWORD, :QWORD;           ( const void* func, cudaFuncCache cacheConfig );    Sets the preferred cache configuration for a device function. 
cudaFuncSetSharedMemConfig          PROTO :QWORD, :QWORD;           ( const void* func, cudaSharedMemConfig config );   Sets the shared memory configuration for a device function. 
cudaGetParameterBuffer              PROTO :QWORD, :QWORD;           ( size_t alignment, size_t size );                  Obtains a parameter buffer. 
cudaGetParameterBufferV2            PROTO :QWORD, :QWORD, :QWORD, :QWORD;( void* func, dim3 gridDimension, dim3 blockDimension, unsigned int  sharedMemSize );    Launches a specified kernel. 
cudaLaunchKernel                    PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( const void* func, dim3 gridDim, dim3 blockDim, void** args, size_t sharedMem, cudaStream_t stream );    Launches a device function. 
cudaSetDoubleForDevice              PROTO :QWORD;                   ( double* d );                                      Converts a double argument to be executed on a device. 
cudaSetDoubleForHost                PROTO :QWORD;                   ( double* d );                                      Converts a double argument after execution on a device. 

;---------------------------------
; CUDA Occupancy Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__OCCUPANCY.html#group__CUDART__OCCUPANCY
;---------------------------------
cudaOccupancyMaxActiveBlocksPerMultiprocessor           PROTO :QWORD, :QWORD, :QWORD, :QWORD;( int* numBlocks, const void* func, int  blockSize, size_t dynamicSMemSize );    Returns occupancy for a device function. 
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( int* numBlocks, const void* func, int  blockSize, size_t dynamicSMemSize, unsigned int  flags );    Returns occupancy for a device function with the specified flags. 

;---------------------------------
; CUDA Memory Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__MEMORY.html#group__CUDART__MEMORY
;---------------------------------
cudaArrayGetInfo                    PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaChannelFormatDesc* desc, cudaExtent* extent, unsigned int* flags, cudaArray_t array );    Gets info about the specified cudaArray. 
cudaFree                            PROTO :QWORD;                   ( void* devPtr );                                   Frees memory on the device. 
cudaFreeArray                       PROTO :QWORD;                   ( cudaArray_t array );                              Frees an array on the device. 
cudaFreeHost                        PROTO :QWORD;                   ( void* ptr );                                      Frees page-locked memory. 
cudaFreeMipmappedArray              PROTO :QWORD;                   ( cudaMipmappedArray_t mipmappedArray );            Frees a mipmapped array on the device. 
cudaGetMipmappedArrayLevel          PROTO :QWORD, :QWORD, :QWORD;   ( cudaArray_t* levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned int  level );    Gets a mipmap level of a CUDA mipmapped array. 
cudaGetSymbolAddress                PROTO :QWORD, :QWORD;           ( void** devPtr, const void* symbol );              Finds the address associated with a CUDA symbol. 
cudaGetSymbolSize                   PROTO :QWORD, :QWORD;           ( size_t* size, const void* symbol );               Finds the size of the object associated with a CUDA symbol. 
cudaHostAlloc                       PROTO :QWORD, :QWORD, :QWORD;   ( void** pHost, size_t size, unsigned int  flags )  Allocates page-locked memory on the host. 
cudaHostGetDevicePointer            PROTO :QWORD, :QWORD, :QWORD;   ( void** pDevice, void* pHost, unsigned int  flags )Passes back device pointer of mapped host memory allocated by cudaHostAlloc or registered by cudaHostRegister. 
cudaHostGetFlags                    PROTO :QWORD, :QWORD;           ( unsigned int* pFlags, void* pHost );              Passes back flags used to allocate pinned host memory allocated by cudaHostAlloc. 
cudaHostRegister                    PROTO :QWORD, :QWORD, :QWORD;   ( void* ptr, size_t size, unsigned int  flags );    Registers an existing host memory range for use by CUDA. 
cudaHostUnregister                  PROTO :QWORD;                   ( void* ptr );                                      Unregisters a memory range that was registered with cudaHostRegister. 
cudaMalloc                          PROTO :QWORD, :QWORD;           ( void** devPtr, size_t size );                     Allocate memory on the device. 
cudaMalloc3D                        PROTO :QWORD, :QWORD;           ( cudaPitchedPtr* pitchedDevPtr, cudaExtent extent )Allocates logical 1D, 2D, or 3D memory objects on the device. 
cudaMalloc3DArray                   PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t* array, const cudaChannelFormatDesc* desc, cudaExtent extent, unsigned int  flags = 0 );    Allocate an array on the device. 
cudaMallocArray                     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t* array, const cudaChannelFormatDesc* desc, size_t width, size_t height = 0, unsigned int  flags = 0 );    Allocate an array on the device. 
cudaMallocHost                      PROTO :QWORD, :QWORD;           ( void** ptr, size_t size );                        Allocates page-locked memory on the host. 
cudaMallocManaged                   PROTO :QWORD, :QWORD, :QWORD;   ( void** devPtr, size_t size, unsigned int  flags = cudaMemAttachGlobal );    Allocates memory that will be automatically managed by the Unified Memory system. 
cudaMallocMipmappedArray            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaMipmappedArray_t* mipmappedArray, const cudaChannelFormatDesc* desc, cudaExtent extent, unsigned int  numLevels, unsigned int  flags = 0 );    Allocate a mipmapped array on the device. 
cudaMallocPitch                     PROTO :QWORD, :QWORD, :QWORD, :QWORD;( void** devPtr, size_t* pitch, size_t width, size_t height );    Allocates pitched memory on the device. 
cudaMemAdvise                       PROTO :QWORD, :QWORD, :QWORD, :QWORD;( const void* devPtr, size_t count, cudaMemoryAdvise advice, int  device );    Advise about the usage of a given memory range. 
cudaMemGetInfo                      PROTO :QWORD, :QWORD;           ( size_t* free, size_t* total );                    Gets free and total device memory. 
cudaMemPrefetchAsync                PROTO :QWORD, :QWORD, :QWORD, :QWORD;( const void* devPtr, size_t count, int  dstDevice, cudaStream_t stream = 0 );    Prefetches memory to the specified destination device. 
cudaMemRangeGetAttribute            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* data, size_t dataSize, cudaMemRangeAttribute attribute, const void* devPtr, size_t count );    Query an attribute of a given memory range. 
cudaMemRangeGetAttributes           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void** data, size_t* dataSizes, cudaMemRangeAttribute ** attributes, size_t numAttributes, const void* devPtr, size_t count );    Query attributes of a given memory range. 
cudaMemcpy                          PROTO :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, const void* src, size_t count, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpy2D                        PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpy2DArrayToArray            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice );    Copies data between host and device. 
cudaMemcpy2DAsync                   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpy2DFromArray               PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpy2DFromArrayAsync          PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpy2DToArray                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpy2DToArrayAsync            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpy3D                        PROTO :QWORD;                   ( const cudaMemcpy3DParms* p );                     Copies data between 3D objects. 
cudaMemcpy3DAsync                   PROTO :QWORD, :QWORD;           ( const cudaMemcpy3DParms* p, cudaStream_t stream = 0 );    Copies data between 3D objects. 
cudaMemcpy3DPeer                    PROTO :QWORD;                   ( const cudaMemcpy3DPeerParms* p );                 Copies memory between devices. 
cudaMemcpy3DPeerAsync               PROTO :QWORD, :QWORD;           ( const cudaMemcpy3DPeerParms* p, cudaStream_t stream = 0 );    Copies memory between devices asynchronously. 
cudaMemcpyArrayToArray              PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice );    Copies data between host and device. 
cudaMemcpyAsync                     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpyFromArray                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpyFromArrayAsync            PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpyFromSymbol                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, const void* symbol, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost );    Copies data from the given symbol on the device. 
cudaMemcpyFromSymbolAsync           PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, const void* symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data from the given symbol on the device. 
cudaMemcpyPeer                      PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, int  dstDevice, const void* src, int  srcDevice, size_t count );    Copies memory between two devices. 
cudaMemcpyPeerAsync                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* dst, int  dstDevice, const void* src, int  srcDevice, size_t count, cudaStream_t stream = 0 );    Copies memory between two devices asynchronously. 
cudaMemcpyToArray                   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t count, cudaMemcpyKind kind );    Copies data between host and device. 
cudaMemcpyToArrayAsync              PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data between host and device. 
cudaMemcpyToSymbol                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( const void* symbol, const void* src, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice );    Copies data to the given symbol on the device. 
cudaMemcpyToSymbolAsync             PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( const void* symbol, const void* src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0 );    Copies data to the given symbol on the device. 
cudaMemset                          PROTO :QWORD, :QWORD;           ( void* devPtr, int  value, size_t count );         Initializes or sets device memory to a value. 
cudaMemset2D                        PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* devPtr, size_t pitch, int  value, size_t width, size_t height );    Initializes or sets device memory to a value. 
cudaMemset2DAsync                   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( void* devPtr, size_t pitch, int  value, size_t width, size_t height, cudaStream_t stream = 0 );    Initializes or sets device memory to a value. 
cudaMemset3D                        PROTO :QWORD, :QWORD, :QWORD;   ( cudaPitchedPtr pitchedDevPtr, int  value, cudaExtent extent );    Initializes or sets device memory to a value. 
cudaMemset3DAsync                   PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaPitchedPtr pitchedDevPtr, int  value, cudaExtent extent, cudaStream_t stream = 0 );    Initializes or sets device memory to a value. 
cudaMemsetAsync                     PROTO :QWORD, :QWORD, :QWORD, :QWORD;( void* devPtr, int  value, size_t count, cudaStream_t stream = 0 );    Initializes or sets device memory to a value. 
make_cudaExtent                     PROTO :QWORD, :QWORD, :QWORD;   ( size_t w, size_t h, size_t d );                   Returns a cudaExtent based on input parameters. 
make_cudaPitchedPtr                 PROTO :QWORD, :QWORD, :QWORD, :QWORD;( void* d, size_t p, size_t xsz, size_t ysz )  Returns a cudaPitchedPtr based on input parameters. 
make_cudaPos                        PROTO :QWORD, :QWORD, :QWORD;   ( size_t x, size_t y, size_t z );                   Returns a cudaPos based on input parameters. 

;---------------------------------
; CUDA Unified Addressing Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__UNIFIED.html#group__CUDART__UNIFIED
;---------------------------------
cudaPointerGetAttributes            PROTO :QWORD, :QWORD;           ( cudaPointerAttributes* attributes, const void* ptr ) Returns attributes about a specified pointer. 

;---------------------------------
; CUDA Peer Device Memory Access Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__PEER.html#group__CUDART__PEER
;---------------------------------
cudaDeviceCanAccessPeer             PROTO :QWORD, :QWORD, :QWORD;   ( int* canAccessPeer, int  device, int  peerDevice )Queries if a device may directly access a peer device's memory. 
cudaDeviceDisablePeerAccess         PROTO :QWORD;                   ( int  peerDevice );                                Disables direct access to memory allocations on a peer device. 
cudaDeviceEnablePeerAccess          PROTO :QWORD, :QWORD;           ( int  peerDevice, unsigned int  flags );           Enables direct access to memory allocations on a peer device. 

;---------------------------------
; CUDA OpenGL Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__OPENGL.html#group__CUDART__OPENGL
;---------------------------------
cudaGLGetDevices                    PROTO :QWORD, :QWORD, :QWORD, :QWORD;( unsigned int* pCudaDeviceCount, int* pCudaDevices, unsigned int  cudaDeviceCount, cudaGLDeviceList deviceList );    Gets the CUDA devices associated with the current OpenGL context. 
cudaGraphicsGLRegisterBuffer        PROTO :QWORD, :QWORD, :QWORD;   ( cudaGraphicsResource** resource, GLuint buffer, unsigned int  flags );    Registers an OpenGL buffer object. 
cudaGraphicsGLRegisterImage         PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaGraphicsResource** resource, GLuint image, GLenum target, unsigned int  flags );    Register an OpenGL texture or renderbuffer object. 
cudaWGLGetDevice                    PROTO :QWORD, :QWORD;           ( int* device, HGPUNV hGpu );                       Gets the CUDA device associated with hGpu. 

;---------------------------------
; CUDA Direct3D 9 Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__D3D9.html#group__CUDART__D3D9
;---------------------------------
cudaD3D9GetDevice                   PROTO :QWORD, :QWORD;           ( int* device, const char* pszAdapterName );        Gets the device number for an adapter. 
cudaD3D9GetDevices                  PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( unsigned int* pCudaDeviceCount, int* pCudaDevices, unsigned int  cudaDeviceCount, IDirect3DDevice9* pD3D9Device, cudaD3D9DeviceList deviceList );    Gets the CUDA devices corresponding to a Direct3D 9 device. 
cudaD3D9GetDirect3DDevice           PROTO :QWORD;                   ( IDirect3DDevice9** ppD3D9Device );    Gets the Direct3D device against which the current CUDA context was created. 
cudaD3D9SetDirect3DDevice           PROTO :QWORD, :QWORD;           ( IDirect3DDevice9* pD3D9Device, int  device = -1 ) Sets the Direct3D 9 device to use for interoperability with a CUDA device. 
cudaGraphicsD3D9RegisterResource    PROTO :QWORD, :QWORD, :QWORD;   ( cudaGraphicsResource** resource, IDirect3DResource9* pD3DResource, unsigned int  flags );    Register a Direct3D 9 resource for access by CUDA. 

;---------------------------------
; CUDA Direct3D 10 Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__D3D10.html#group__CUDART__D3D10
;---------------------------------
cudaD3D10GetDevice                  PROTO :QWORD, :QWORD;           ( int* device, IDXGIAdapter* pAdapter );            Gets the device number for an adapter. 
cudaD3D10GetDevices                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( unsigned int* pCudaDeviceCount, int* pCudaDevices, unsigned int  cudaDeviceCount, ID3D10Device* pD3D10Device, cudaD3D10DeviceList deviceList );    Gets the CUDA devices corresponding to a Direct3D 10 device. 
cudaGraphicsD3D10RegisterResource   PROTO :QWORD, :QWORD, :QWORD;   ( cudaGraphicsResource** resource, ID3D10Resource* pD3DResource, unsigned int  flags );    Registers a Direct3D 10 resource for access by CUDA. 

;---------------------------------
; CUDA Direct3D 11 Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__D3D11.html#group__CUDART__D3D11
;---------------------------------
cudaD3D11GetDevice                  PROTO :QWORD, :QWORD;           ( int* device, IDXGIAdapter* pAdapter );            Gets the device number for an adapter. 
cudaD3D11GetDevices                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( unsigned int* pCudaDeviceCount, int* pCudaDevices, unsigned int  cudaDeviceCount, ID3D11Device* pD3D11Device, cudaD3D11DeviceList deviceList );    Gets the CUDA devices corresponding to a Direct3D 11 device. 
cudaGraphicsD3D11RegisterResource   PROTO :QWORD, :QWORD, :QWORD;   ( cudaGraphicsResource** resource, ID3D11Resource* pD3DResource, unsigned int  flags );    Register a Direct3D 11 resource for access by CUDA. 

;---------------------------------
;CUDA VDPAU Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__VDPAU.html#group__CUDART__VDPAU
;---------------------------------
cudaGraphicsVDPAURegisterOutputSurface PROTO :QWORD, :QWORD, :QWORD;( cudaGraphicsResource** resource, VdpOutputSurface vdpSurface, unsigned int  flags );    Register a VdpOutputSurface object. 
cudaGraphicsVDPAURegisterVideoSurface PROTO :QWORD, :QWORD, :QWORD; ( cudaGraphicsResource** resource, VdpVideoSurface vdpSurface, unsigned int  flags );    Register a VdpVideoSurface object. 
cudaVDPAUGetDevice                  PROTO :QWORD, :QWORD, :QWORD;   ( int* device, VdpDevice vdpDevice, VdpGetProcAddress* vdpGetProcAddress );    Gets the CUDA device associated with a VdpDevice. 
cudaVDPAUSetVDPAUDevice             PROTO :QWORD, :QWORD, :QWORD;   ( int  device, VdpDevice vdpDevice, VdpGetProcAddress* vdpGetProcAddress );    Sets a CUDA device to use VDPAU interoperability. 

;---------------------------------
;CUDA EGL Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__EGL.html#group__CUDART__EGL
;---------------------------------
cudaEGLStreamConsumerAcquireFrame   PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaEglStreamConnection* conn, cudaGraphicsResource_t* pCudaResource, cudaStream_t* pStream, unsigned int  timeout );    Acquire an image frame from the EGLStream with CUDA as a consumer. 
cudaEGLStreamConsumerConnect        PROTO :QWORD, :QWORD;           ( cudaEglStreamConnection* conn, EGLStreamKHR eglStream );    Connect CUDA to EGLStream as a consumer. 
cudaEGLStreamConsumerConnectWithFlags PROTO :QWORD, :QWORD, :QWORD; ( cudaEglStreamConnection* conn, EGLStreamKHR eglStream, unsigned int  flags );     Connect CUDA to EGLStream as a consumer with given flags. 
cudaEGLStreamConsumerReleaseFrame   PROTO :QWORD, :QWORD, :QWORD;   ( cudaEglStreamConnection* conn, cudaGraphicsResource_t pCudaResource, cudaStream_t* pStream );    Releases the last frame acquired from the EGLStream. 
cudaEGLStreamProducerConnect        PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaEglStreamConnection* conn, EGLStreamKHR eglStream, EGLint width, EGLint height );    Connect CUDA to EGLStream as a producer. 
cudaEGLStreamProducerDisconnect     PROTO :QWORD;                   ( cudaEglStreamConnection* conn );                  Disconnect CUDA as a producer to EGLStream . 
cudaEGLStreamProducerPresentFrame   PROTO :QWORD, :QWORD, :QWORD;   ( cudaEglStreamConnection* conn, cudaEglFrame eglframe, cudaStream_t* pStream );    Present a CUDA eglFrame to the EGLStream with CUDA as a producer. 
cudaEGLStreamProducerReturnFrame    PROTO :QWORD, :QWORD, :QWORD;   ( cudaEglStreamConnection* conn, cudaEglFrame* eglframe, cudaStream_t* pStream );   Return the CUDA eglFrame to the EGLStream last released by the consumer. 
cudaGraphicsEGLRegisterImage        PROTO :QWORD, :QWORD, :QWORD;   ( cudaGraphicsResource** pCudaResource, EGLImageKHR image, unsigned int  flags );   Registers an EGL image. 
cudaGraphicsResourceGetMappedEglFrame PROTO :QWORD, :QWORD, :QWORD, :QWORD;udaEglFrame* eglFrame, cudaGraphicsResource_t resource, unsigned int  index, unsigned int  mipLevel );    Get an eglFrame through which to access a registered EGL graphics resource. 

;---------------------------------
;CUDA Graphics Interoperability Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__INTEROP.html#group__CUDART__INTEROP
;---------------------------------
cudaGraphicsMapResources            PROTO :QWORD, :QWORD, :QWORD;   ( int  count, cudaGraphicsResource_t* resources, cudaStream_t stream = 0 );    Map graphics resources for access by CUDA. 
cudaGraphicsResourceGetMappedMipmappedArray PROTO :QWORD, :QWORD;   ( cudaMipmappedArray_t* mipmappedArray, cudaGraphicsResource_t resource );    Get a mipmapped array through which to access a mapped graphics resource. 
cudaGraphicsResourceGetMappedPointer PROTO :QWORD, :QWORD, :QWORD;  ( void** devPtr, size_t* size, cudaGraphicsResource_t resource );    Get an device pointer through which to access a mapped graphics resource. 
cudaGraphicsResourceSetMapFlags     PROTO :QWORD, :QWORD;           ( cudaGraphicsResource_t resource, unsigned int  flags );    Set usage flags for mapping a graphics resource. 
cudaGraphicsSubResourceGetMappedArray PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaArray_t* array, cudaGraphicsResource_t resource, unsigned int  arrayIndex, unsigned int  mipLevel );    Get an array through which to access a subresource of a mapped graphics resource. 
cudaGraphicsUnmapResources          PROTO :QWORD, :QWORD, :QWORD;   ( int  count, cudaGraphicsResource_t* resources, cudaStream_t stream = 0 );    Unmap graphics resources. 
cudaGraphicsUnregisterResource      PROTO :QWORD;                   ( cudaGraphicsResource_t resource );                Unregisters a graphics resource for access by CUDA. 

;---------------------------------
;CUDA Texture Reference Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__TEXTURE.html#group__CUDART__TEXTURE
;---------------------------------
cudaBindTexture                     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t size = UINT_MAX );    Binds a memory area to a texture. 
cudaBindTexture2D                   PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t width, size_t height, size_t pitch );    Binds a 2D memory area to a texture. 
cudaBindTextureToArray              PROTO :QWORD, :QWORD, :QWORD;   ( const textureReference* texref, cudaArray_const_t array, const cudaChannelFormatDesc* desc );    Binds an array to a texture. 
cudaBindTextureToMipmappedArray     PROTO :QWORD, :QWORD, :QWORD;   ( const textureReference* texref, cudaMipmappedArray_const_t mipmappedArray, const cudaChannelFormatDesc* desc );    Binds a mipmapped array to a texture. 
cudaCreateChannelDesc               PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( int  x, int  y, int  z, int  w, cudaChannelFormatKind f );    Returns a channel descriptor using the specified format. 
cudaGetChannelDesc                  PROTO :QWORD, :QWORD;           ( cudaChannelFormatDesc* desc, cudaArray_const_t array );    Get the channel descriptor of an array. 
cudaGetTextureAlignmentOffset       PROTO :QWORD, :QWORD;           ( size_t* offset, const textureReference* texref )  Get the alignment offset of a texture. 
cudaGetTextureReference             PROTO :QWORD, :QWORD;           ( const textureReference** texref, const void* symbol );    Get the texture reference associated with a symbol. 
cudaUnbindTexture                   PROTO :QWORD;                   ( const textureReference* texref );                 Unbinds a texture. 

;---------------------------------
;CUDA Surface Reference Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__SURFACE.html#group__CUDART__SURFACE
;---------------------------------
cudaBindSurfaceToArray              PROTO :QWORD, :QWORD, :QWORD;   ( const surfaceReference* surfref, cudaArray_const_t array, const cudaChannelFormatDesc* desc );    Binds an array to a surface. 
cudaGetSurfaceReference             PROTO :QWORD, :QWORD;           ( const surfaceReference** surfref, const void* symbol )    Get the surface reference associated with a symbol. 

;---------------------------------
;CUDA Texture Object Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__TEXTURE__OBJECT.html#group__CUDART__TEXTURE__OBJECT
;---------------------------------
cudaCreateTextureObject             PROTO :QWORD, :QWORD, :QWORD, :QWORD;( cudaTextureObject_t* pTexObject, const cudaResourceDesc* pResDesc, const cudaTextureDesc* pTexDesc, const cudaResourceViewDesc* pResViewDesc );    Creates a texture object. 
cudaDestroyTextureObject            PROTO :QWORD;                   ( cudaTextureObject_t texObject );    Destroys a texture object. 
cudaGetTextureObjectResourceDesc    PROTO :QWORD, :QWORD;           ( cudaResourceDesc* pResDesc, cudaTextureObject_t texObject );    Returns a texture object's resource descriptor. 
cudaGetTextureObjectResourceViewDesc PROTO :QWORD, :QWORD;          ( cudaResourceViewDesc* pResViewDesc, cudaTextureObject_t texObject );    Returns a texture object's resource view descriptor. 
cudaGetTextureObjectTextureDesc     PROTO :QWORD, :QWORD;           ( cudaTextureDesc* pTexDesc, cudaTextureObject_t texObject );    Returns a texture object's texture descriptor. 

;---------------------------------
;CUDA Surface Object Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__SURFACE__OBJECT.html#group__CUDART__SURFACE__OBJECT
;---------------------------------
cudaCreateSurfaceObject             PROTO :QWORD, :QWORD;           ( cudaSurfaceObject_t* pSurfObject, const cudaResourceDesc* pResDesc );    Creates a surface object. 
cudaDestroySurfaceObject            PROTO :QWORD;                   ( cudaSurfaceObject_t surfObject );    Destroys a surface object. 
cudaGetSurfaceObjectResourceDesc    PROTO :QWORD, :QWORD;           ( cudaResourceDesc* pResDesc, cudaSurfaceObject_t surfObject );    Returns a surface object's resource descriptor Returns the resource descriptor for the surface object specified by surfObject. 

;---------------------------------
;CUDA Version Management Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART____VERSION.html#group__CUDART____VERSION
;---------------------------------
cudaDriverGetVersion                PROTO :QWORD;                   ( int* driverVersion );                             Returns the CUDA driver version. 
cudaRuntimeGetVersion               PROTO :QWORD;                   ( int* runtimeVersion );                            Returns the CUDA Runtime version. 

;---------------------------------
;CUDA Profiler Control Prototypes - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__PROFILER.html#group__CUDART__PROFILER
;---------------------------------
cudaProfilerInitialize              PROTO :QWORD, :QWORD, :QWORD;   ( const char* configFile, const char* outputFile, cudaOutputMode_t outputMode );    Initialize the CUDA profiler. 
cudaProfilerStart                   PROTO;                          ( void );                                           Enable profiling. 
cudaProfilerStop                    PROTO;                          ( void );                                           Disable profiling. 


;---------------------------------
; CUDA Defines - http://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__TYPES.html#group__CUDART__TYPES
;---------------------------------
CUDA_EGL_MAX_PLANES                 EQU 3;     Maximum number of planes per frame
CUDA_IPC_HANDLE_SIZE                EQU 64;    CUDA IPC Handle Size
cudaArrayCubemap                    EQU 4h;    Must be set in cudaMalloc3DArray to create a cubemap CUDA array
cudaArrayDefault                    EQU 0h;    Default CUDA array allocation flag
cudaArrayLayered                    EQU 1h;    Must be set in cudaMalloc3DArray to create a layered CUDA array
cudaArraySurfaceLoadStore           EQU 2h;    Must be set in cudaMallocArray or cudaMalloc3DArray in order to bind surfaces to the CUDA array
cudaArrayTextureGather              EQU 8h;    Must be set in cudaMallocArray or cudaMalloc3DArray in order to perform texture gather operations on the CUDA array
cudaCpuDeviceId                     EQU -1;    Device id that represents the CPU
cudaDeviceBlockingSync              EQU 4h;    Deprecated. This flag was deprecated as of CUDA 4.0 and replaced with cudaDeviceScheduleBlockingSync.
cudaDeviceLmemResizeToMax           EQU 10h;   Device flag - Keep local memory allocation after launch
cudaDeviceMapHost                   EQU 8h;    Device flag - Support mapped pinned allocations
cudaDeviceMask                      EQU 1fh;   Device flags mask
cudaDevicePropDontCare              EQU 0h;    Empty device properties
cudaDeviceScheduleAuto              EQU 0h;    Device flag - Automatic scheduling
cudaDeviceScheduleBlockingSync      EQU 4h;    Device flag - Use blocking synchronization
cudaDeviceScheduleMask              EQU 7h;    Device schedule flags mask
cudaDeviceScheduleSpin              EQU 1h;    Device flag - Spin default scheduling
cudaDeviceScheduleYield             EQU 2h;    Device flag - Yield default scheduling
cudaEventBlockingSync               EQU 1h;    Event uses blocking synchronization
cudaEventDefault                    EQU 0h;    Default event flag
cudaEventDisableTiming              EQU 2h;    Event will not record timing data
cudaEventInterprocess               EQU 4h;    Event is suitable for interprocess use. cudaEventDisableTiming must be set
cudaHostAllocDefault                EQU 0h;    Default page-locked allocation flag
cudaHostAllocMapped                 EQU 2h;    Map allocation into device space
cudaHostAllocPortable               EQU 1h;    Pinned memory accessible by all CUDA contexts
cudaHostAllocWriteCombined          EQU 4h;    Write-combined memory
cudaHostRegisterDefault             EQU 0h;    Default host memory registration flag
cudaHostRegisterIoMemory            EQU 4h;    Memory-mapped I/O space
cudaHostRegisterMapped              EQU 2h;    Map registered memory into device space
cudaHostRegisterPortable            EQU 1h;    Pinned memory accessible by all CUDA contexts
cudaInvalidDeviceId                 EQU -2;    Device id that represents an invalid device
cudaIpcMemLazyEnablePeerAccess      EQU 1h;    Automatically enable peer access between remote devices as needed
cudaMemAttachGlobal                 EQU 1h;    Memory can be accessed by any stream on any device
cudaMemAttachHost                   EQU 2h;    Memory cannot be accessed by any stream on any device
cudaMemAttachSingle                 EQU 4h;    Memory can only be accessed by a single stream on the associated device
cudaOccupancyDefault                EQU 0h;    Default behavior
cudaOccupancyDisableCachingOverride EQU 1h;    Assume global caching is enabled and cannot be automatically turned off
cudaPeerAccessDefault               EQU 0h;    Default peer addressing enable flag
cudaStreamDefault                   EQU 0h;    Default stream flag
cudaStreamLegacy                    EQU 1h;    Legacy stream handle    Stream handle that can be passed as a cudaStream_t to use an implicit stream with legacy synchronization behavior.
cudaStreamNonBlocking               EQU 1h;    Stream does not synchronize with stream 0 (the NULL stream)
cudaStreamPerThread                 EQU 2h;    Per-thread stream handle    Stream handle that can be passed as a cudaStream_t to use an implicit stream with per-thread synchronization behavior.

;---------------------------------
; CUDA Enumeration and Equates
;---------------------------------
;cudaChannelFormatKind              Channel format kind 
cudaChannelFormatKindSigned         EQU 0;    Signed channel format 
cudaChannelFormatKindUnsigned       EQU 1;    Unsigned channel format 
cudaChannelFormatKindFloat          EQU 2;    Float channel format 
cudaChannelFormatKindNone           EQU 3;    No channel format 

;cudaComputeMode                    CUDA device compute modes
cudaComputeModeDefault              EQU 0;    Default compute mode (Multiple threads can use cudaSetDevice() with this device) 
cudaComputeModeExclusive            EQU 1;    Compute-exclusive-thread mode (Only one thread in one process will be able to use cudaSetDevice() with this device) 
cudaComputeModeProhibited           EQU 2;    Compute-prohibited mode (No threads can use cudaSetDevice() with this device) 
cudaComputeModeExclusiveProcess     EQU 3;    Compute-exclusive-process mode (Many threads in one process will be able to use cudaSetDevice() with this device) 

;cudaDeviceAttr                                 CUDA device attributes
cudaDevAttrMaxThreadsPerBlock                   EQU 1;     Maximum number of threads per block 
cudaDevAttrMaxBlockDimX                         EQU 2;     Maximum block dimension X 
cudaDevAttrMaxBlockDimY                         EQU 3;     Maximum block dimension Y 
cudaDevAttrMaxBlockDimZ                         EQU 4;     Maximum block dimension Z 
cudaDevAttrMaxGridDimX                          EQU 5;     Maximum grid dimension X 
cudaDevAttrMaxGridDimY                          EQU 6;     Maximum grid dimension Y 
cudaDevAttrMaxGridDimZ                          EQU 7;     Maximum grid dimension Z 
cudaDevAttrMaxSharedMemoryPerBlock              EQU 8;     Maximum shared memory available per block in bytes 
cudaDevAttrTotalConstantMemory                  EQU 9;     Memory available on device for __constant__ variables in a CUDA C kernel in bytes 
cudaDevAttrWarpSize                             EQU 10;    Warp size in threads 
cudaDevAttrMaxPitch                             EQU 11;    Maximum pitch in bytes allowed by memory copies 
cudaDevAttrMaxRegistersPerBlock                 EQU 12;    Maximum number of 32-bit registers available per block 
cudaDevAttrClockRate                            EQU 13;    Peak clock frequency in kilohertz 
cudaDevAttrTextureAlignment                     EQU 14;    Alignment requirement for textures 
cudaDevAttrGpuOverlap                           EQU 15;    Device can possibly copy memory and execute a kernel concurrently 
cudaDevAttrMultiProcessorCount                  EQU 16;    Number of multiprocessors on device 
cudaDevAttrKernelExecTimeout                    EQU 17;    Specifies whether there is a run time limit on kernels 
cudaDevAttrIntegrated                           EQU 18;    Device is integrated with host memory 
cudaDevAttrCanMapHostMemory                     EQU 19;    Device can map host memory into CUDA address space 
cudaDevAttrComputeMode                          EQU 20;    Compute mode (See cudaComputeMode for details) 
cudaDevAttrMaxTexture1DWidth                    EQU 21;    Maximum 1D texture width 
cudaDevAttrMaxTexture2DWidth                    EQU 22;    Maximum 2D texture width 
cudaDevAttrMaxTexture2DHeight                   EQU 23;    Maximum 2D texture height 
cudaDevAttrMaxTexture3DWidth                    EQU 24;    Maximum 3D texture width 
cudaDevAttrMaxTexture3DHeight                   EQU 25;    Maximum 3D texture height 
cudaDevAttrMaxTexture3DDepth                    EQU 26;    Maximum 3D texture depth 
cudaDevAttrMaxTexture2DLayeredWidth             EQU 27;    Maximum 2D layered texture width 
cudaDevAttrMaxTexture2DLayeredHeight            EQU 28;    Maximum 2D layered texture height 
cudaDevAttrMaxTexture2DLayeredLayers            EQU 29;    Maximum layers in a 2D layered texture 
cudaDevAttrSurfaceAlignment                     EQU 30;    Alignment requirement for surfaces 
cudaDevAttrConcurrentKernels                    EQU 31;    Device can possibly execute multiple kernels concurrently 
cudaDevAttrEccEnabled                           EQU 32;    Device has ECC support enabled 
cudaDevAttrPciBusId                             EQU 33;    PCI bus ID of the device 
cudaDevAttrPciDeviceId                          EQU 34;    PCI device ID of the device 
cudaDevAttrTccDriver                            EQU 35;    Device is using TCC driver model 
cudaDevAttrMemoryClockRate                      EQU 36;    Peak memory clock frequency in kilohertz 
cudaDevAttrGlobalMemoryBusWidth                 EQU 37;    Global memory bus width in bits 
cudaDevAttrL2CacheSize                          EQU 38;    Size of L2 cache in bytes 
cudaDevAttrMaxThreadsPerMultiProcessor          EQU 39;    Maximum resident threads per multiprocessor 
cudaDevAttrAsyncEngineCount                     EQU 40;    Number of asynchronous engines 
cudaDevAttrUnifiedAddressing                    EQU 41;    Device shares a unified address space with the host 
cudaDevAttrMaxTexture1DLayeredWidth             EQU 42;    Maximum 1D layered texture width 
cudaDevAttrMaxTexture1DLayeredLayers            EQU 43;    Maximum layers in a 1D layered texture 
cudaDevAttrMaxTexture2DGatherWidth              EQU 45;    Maximum 2D texture width if cudaArrayTextureGather is set 
cudaDevAttrMaxTexture2DGatherHeight             EQU 46;    Maximum 2D texture height if cudaArrayTextureGather is set 
cudaDevAttrMaxTexture3DWidthAlt                 EQU 47;    Alternate maximum 3D texture width 
cudaDevAttrMaxTexture3DHeightAlt                EQU 48;    Alternate maximum 3D texture height 
cudaDevAttrMaxTexture3DDepthAlt                 EQU 49;    Alternate maximum 3D texture depth 
cudaDevAttrPciDomainId                          EQU 50;    PCI domain ID of the device 
cudaDevAttrTexturePitchAlignment                EQU 51;    Pitch alignment requirement for textures 
cudaDevAttrMaxTextureCubemapWidth               EQU 52;    Maximum cubemap texture width/height 
cudaDevAttrMaxTextureCubemapLayeredWidth        EQU 53;    Maximum cubemap layered texture width/height 
cudaDevAttrMaxTextureCubemapLayeredLayers       EQU 54;    Maximum layers in a cubemap layered texture 
cudaDevAttrMaxSurface1DWidth                    EQU 55;    Maximum 1D surface width 
cudaDevAttrMaxSurface2DWidth                    EQU 56;    Maximum 2D surface width 
cudaDevAttrMaxSurface2DHeight                   EQU 57;    Maximum 2D surface height 
cudaDevAttrMaxSurface3DWidth                    EQU 58;    Maximum 3D surface width 
cudaDevAttrMaxSurface3DHeight                   EQU 59;    Maximum 3D surface height 
cudaDevAttrMaxSurface3DDepth                    EQU 60;    Maximum 3D surface depth 
cudaDevAttrMaxSurface1DLayeredWidth             EQU 61;    Maximum 1D layered surface width 
cudaDevAttrMaxSurface1DLayeredLayers            EQU 62;    Maximum layers in a 1D layered surface 
cudaDevAttrMaxSurface2DLayeredWidth             EQU 63;    Maximum 2D layered surface width 
cudaDevAttrMaxSurface2DLayeredHeight            EQU 64;    Maximum 2D layered surface height 
cudaDevAttrMaxSurface2DLayeredLayers            EQU 65;    Maximum layers in a 2D layered surface 
cudaDevAttrMaxSurfaceCubemapWidth               EQU 66;    Maximum cubemap surface width 
cudaDevAttrMaxSurfaceCubemapLayeredWidth        EQU 67;    Maximum cubemap layered surface width 
cudaDevAttrMaxSurfaceCubemapLayeredLayers       EQU 68;    Maximum layers in a cubemap layered surface 
cudaDevAttrMaxTexture1DLinearWidth              EQU 69;    Maximum 1D linear texture width 
cudaDevAttrMaxTexture2DLinearWidth              EQU 70;    Maximum 2D linear texture width 
cudaDevAttrMaxTexture2DLinearHeight             EQU 71;    Maximum 2D linear texture height 
cudaDevAttrMaxTexture2DLinearPitch              EQU 72;    Maximum 2D linear texture pitch in bytes 
cudaDevAttrMaxTexture2DMipmappedWidth           EQU 73;    Maximum mipmapped 2D texture width 
cudaDevAttrMaxTexture2DMipmappedHeight          EQU 74;    Maximum mipmapped 2D texture height 
cudaDevAttrComputeCapabilityMajor               EQU 75;    Major compute capability version number 
cudaDevAttrComputeCapabilityMinor               EQU 76;    Minor compute capability version number 
cudaDevAttrMaxTexture1DMipmappedWidth           EQU 77;    Maximum mipmapped 1D texture width 
cudaDevAttrStreamPrioritiesSupported            EQU 78;    Device supports stream priorities 
cudaDevAttrGlobalL1CacheSupported               EQU 79;    Device supports caching globals in L1 
cudaDevAttrLocalL1CacheSupported                EQU 80;    Device supports caching locals in L1 
cudaDevAttrMaxSharedMemoryPerMultiprocessor     EQU 81;    Maximum shared memory available per multiprocessor in bytes 
cudaDevAttrMaxRegistersPerMultiprocessor        EQU 82;    Maximum number of 32-bit registers available per multiprocessor 
cudaDevAttrManagedMemory                        EQU 83;    Device can allocate managed memory on this system 
cudaDevAttrIsMultiGpuBoard                      EQU 84;    Device is on a multi-GPU board 
cudaDevAttrMultiGpuBoardGroupID                 EQU 85;    Unique identifier for a group of devices on the same multi-GPU board 
cudaDevAttrHostNativeAtomicSupported            EQU 86;    Link between the device and the host supports native atomic operations 
cudaDevAttrSingleToDoublePrecisionPerfRatio     EQU 87;    Ratio of single precision performance (in floating-point operations per second) to double precision performance 
cudaDevAttrPageableMemoryAccess                 EQU 88;    Device supports coherently accessing pageable memory without calling cudaHostRegister on it 
cudaDevAttrConcurrentManagedAccess              EQU 89;    Device can coherently access managed memory concurrently with the CPU 
cudaDevAttrComputePreemptionSupported           EQU 90;    Device supports Compute Preemption 
cudaDevAttrCanUseHostPointerForRegisteredMem    EQU 91;    Device can access host registered memory at the same virtual address as the CPU 

;cudaDeviceP2PAttr                  CUDA device P2P attributes
cudaDevP2PAttrPerformanceRank       EQU 1;     A relative value indicating the performance of the link between two devices 
cudaDevP2PAttrAccessSupported       EQU 2;     Peer access is enabled 
cudaDevP2PAttrNativeAtomicSupported EQU 3;     Native atomic operation over the link supported 

;cudaEglColorFormat                 CUDA EGL Color Format - The different planar and multiplanar formats currently supported for CUDA_EGL interops
cudaEglColorFormatYUV420Planar      EQU 0;     Y, U, V in three surfaces, each in a separate surface, U/V width EQU 1/2 Y width, U/V height EQU 1/2 Y height. 
cudaEglColorFormatYUV420SemiPlanar  EQU 1;     Y, UV in two surfaces (UV as one surface), width, height ratio same as YUV420Planar. 
cudaEglColorFormatYUV422Planar      EQU 2;     Y, U, V each in a separate surface, U/V width EQU 1/2 Y width, U/V height EQU Y height. 
cudaEglColorFormatYUV422SemiPlanar  EQU 3;     Y, UV in two surfaces, width, height ratio same as YUV422Planar. 
cudaEglColorFormatRGB               EQU 4;     R/G/B three channels in one surface with RGB byte ordering. 
cudaEglColorFormatBGR               EQU 5;     R/G/B three channels in one surface with BGR byte ordering. 
cudaEglColorFormatARGB              EQU 6;     R/G/B/A four channels in one surface with ARGB byte ordering. 
cudaEglColorFormatRGBA              EQU 7;     R/G/B/A four channels in one surface with RGBA byte ordering. 
cudaEglColorFormatL                 EQU 8;     single luminance channel in one surface. 
cudaEglColorFormatR                 EQU 9;     single color channel in one surface. 
cudaEglColorFormatYUV444Planar      EQU 10;    Y, U, V in three surfaces, each in a separate surface, U/V width EQU Y width, U/V height EQU Y height. 
cudaEglColorFormatYUV444SemiPlanar  EQU 11;    Y, UV in two surfaces (UV as one surface), width, height ratio same as YUV444Planar. 
cudaEglColorFormatYUYV422           EQU 12;    Y, U, V in one surface, interleaved as YUYV. 
cudaEglColorFormatUYVY422           EQU 13;    Y, U, V in one surface, interleaved as UYVY. 

;cudaEglFrameType                   CUDA EglFrame type - array or pointer
cudaEglFrameTypeArray               EQU 0;     Frame type CUDA array 
cudaEglFrameTypePitch               EQU 1;     Frame type CUDA pointer 

;cudaEglResourceLocationFlags       Resource location flags- sysmem or vidmem
cudaEglResourceLocationSysmem       EQU 00h;    Resource location sysmem 
cudaEglResourceLocationVidmem       EQU 01h;    Resource location vidmem 

;cudaError                          CUDA error types 
cudaSuccess                         EQU 0;     The API call returned with no errors. In the case of query calls, this can also mean that the operation being queried is complete (see cudaEventQuery() and cudaStreamQuery()). 
cudaErrorMissingConfiguration       EQU 1;     The device function being invoked (usually via cudaLaunchKernel()) was not previously configured via the cudaConfigureCall() function. 
cudaErrorMemoryAllocation           EQU 2;     The API call failed because it was unable to allocate enough memory to perform the requested operation. 
cudaErrorInitializationError        EQU 3;     The API call failed because the CUDA driver and runtime could not be initialized. 
cudaErrorLaunchFailure              EQU 4;     An exception occurred on the device while executing a kernel. Common causes include dereferencing an invalid device pointer and accessing out of bounds shared memory. The device cannot be used until cudaThreadExit() is called. All existing device memory allocations are invalid and must be reconstructed if the program is to continue using CUDA. 
cudaErrorPriorLaunchFailure         EQU 5;     Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorLaunchTimeout              EQU 6;     This indicates that the device kernel took too long to execute. This can only occur if timeouts are enabled - see the device property kernelExecTimeoutEnabled for more information. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorLaunchOutOfResources       EQU 7;     This indicates that a launch did not occur because it did not have appropriate resources. Although this error is similar to cudaErrorInvalidConfiguration, this error usually indicates that the user has attempted to pass too many arguments to the device kernel, or the kernel launch specifies too many threads for the kernel's register count. 
cudaErrorInvalidDeviceFunction      EQU 8;     The requested device function does not exist or is not compiled for the proper device architecture. 
cudaErrorInvalidConfiguration       EQU 9;     This indicates that a kernel launch is requesting resources that can never be satisfied by the current device. Requesting more shared memory per block than the device supports will trigger this error, as will requesting too many threads or blocks. See cudaDeviceProp for more device limitations. 
cudaErrorInvalidDevice              EQU 10;    This indicates that the device ordinal supplied by the user does not correspond to a valid CUDA device. 
cudaErrorInvalidValue               EQU 11;    This indicates that one or more of the parameters passed to the API call is not within an acceptable range of values. 
cudaErrorInvalidPitchValue          EQU 12;    This indicates that one or more of the pitch-related parameters passed to the API call is not within the acceptable range for pitch. 
cudaErrorInvalidSymbol              EQU 13;    This indicates that the symbol name/identifier passed to the API call is not a valid name or identifier. 
cudaErrorMapBufferObjectFailed      EQU 14;    This indicates that the buffer object could not be mapped. 
cudaErrorUnmapBufferObjectFailed    EQU 15;    This indicates that the buffer object could not be unmapped. 
cudaErrorInvalidHostPointer         EQU 16;    This indicates that at least one host pointer passed to the API call is not a valid host pointer. 
cudaErrorInvalidDevicePointer       EQU 17;    This indicates that at least one device pointer passed to the API call is not a valid device pointer. 
cudaErrorInvalidTexture             EQU 18;    This indicates that the texture passed to the API call is not a valid texture. 
cudaErrorInvalidTextureBinding      EQU 19;    This indicates that the texture binding is not valid. This occurs if you call cudaGetTextureAlignmentOffset() with an unbound texture. 
cudaErrorInvalidChannelDescriptor   EQU 20;    This indicates that the channel descriptor passed to the API call is not valid. This occurs if the format is not one of the formats specified by cudaChannelFormatKind, or if one of the dimensions is invalid. 
cudaErrorInvalidMemcpyDirection     EQU 21;    This indicates that the direction of the memcpy passed to the API call is not one of the types specified by cudaMemcpyKind. 
cudaErrorAddressOfConstant          EQU 22;    Deprecated. This error return is deprecated as of CUDA 3.1. Variables in constant memory may now have their address taken by the runtime via cudaGetSymbolAddress().
cudaErrorTextureFetchFailed         EQU 23;    Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorTextureNotBound            EQU 24;    Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorSynchronizationError       EQU 25;    Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorInvalidFilterSetting       EQU 26;    This indicates that a non-float texture was being accessed with linear filtering. This is not supported by CUDA. 
cudaErrorInvalidNormSetting         EQU 27;    This indicates that an attempt was made to read a non-float texture as a normalized float. This is not supported by CUDA. 
cudaErrorMixedDeviceExecution       EQU 28;    Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorCudartUnloading            EQU 29;    This indicates that a CUDA Runtime API call cannot be executed because it is being called during process shut down, at a point in time after CUDA driver has been unloaded. 
cudaErrorUnknown                    EQU 30;    This indicates that an unknown internal error has occurred. 
cudaErrorNotYetImplemented          EQU 31;    Deprecated. This error return is deprecated as of CUDA 4.1.
cudaErrorMemoryValueTooLarge        EQU 32;    Deprecated. This error return is deprecated as of CUDA 3.1. Device emulation mode was removed with the CUDA 3.1 release.
cudaErrorInvalidResourceHandle      EQU 33;    This indicates that a resource handle passed to the API call was not valid. Resource handles are opaque types like cudaStream_t and cudaEvent_t. 
cudaErrorNotReady                   EQU 34;    This indicates that asynchronous operations issued previously have not completed yet. This result is not actually an error, but must be indicated differently than cudaSuccess (which indicates completion). Calls that may return this value include cudaEventQuery() and cudaStreamQuery(). 
cudaErrorInsufficientDriver         EQU 35;    This indicates that the installed NVIDIA CUDA driver is older than the CUDA runtime library. This is not a supported configuration. Users should install an updated NVIDIA display driver to allow the application to run. 
cudaErrorSetOnActiveProcess         EQU 36;    This indicates that the user has called cudaSetValidDevices(), cudaSetDeviceFlags(), cudaD3D9SetDirect3DDevice(), cudaD3D10SetDirect3DDevice, cudaD3D11SetDirect3DDevice(), or cudaVDPAUSetVDPAUDevice() after initializing the CUDA runtime by calling non-device management operations (allocating memory and launching kernels are examples of non-device management operations). This error can also be returned if using runtime/driver interoperability and there is an existing CUcontext active on the host thread. 
cudaErrorInvalidSurface             EQU 37;    This indicates that the surface passed to the API call is not a valid surface. 
cudaErrorNoDevice                   EQU 38;    This indicates that no CUDA-capable devices were detected by the installed CUDA driver. 
cudaErrorECCUncorrectable           EQU 39;    This indicates that an uncorrectable ECC error was detected during execution. 
cudaErrorSharedObjectSymbolNotFound EQU 40;    This indicates that a link to a shared object failed to resolve. 
cudaErrorSharedObjectInitFailed     EQU 41;    This indicates that initialization of a shared object failed. 
cudaErrorUnsupportedLimit           EQU 42;    This indicates that the cudaLimit passed to the API call is not supported by the active device. 
cudaErrorDuplicateVariableName      EQU 43;    This indicates that multiple global or constant variables (across separate CUDA source files in the application) share the same string name. 
cudaErrorDuplicateTextureName       EQU 44;    This indicates that multiple textures (across separate CUDA source files in the application) share the same string name. 
cudaErrorDuplicateSurfaceName       EQU 45;    This indicates that multiple surfaces (across separate CUDA source files in the application) share the same string name. 
cudaErrorDevicesUnavailable         EQU 46;    This indicates that all CUDA devices are busy or unavailable at the current time. Devices are often busy/unavailable due to use of cudaComputeModeExclusive, cudaComputeModeProhibited or when long running CUDA kernels have filled up the GPU and are blocking new work from starting. They can also be unavailable due to memory constraints on a device that already has active CUDA work being performed. 
cudaErrorInvalidKernelImage         EQU 47;    This indicates that the device kernel image is invalid. 
cudaErrorNoKernelImageForDevice     EQU 48;    This indicates that there is no kernel image available that is suitable for the device. This can occur when a user specifies code generation options for a particular CUDA source file that do not include the corresponding device configuration. 
cudaErrorIncompatibleDriverContext  EQU 49;    This indicates that the current context is not compatible with this the CUDA Runtime. This can only occur if you are using CUDA Runtime/Driver interoperability and have created an existing Driver context using the driver API. The Driver context may be incompatible either because the Driver context was created using an older version of the API, because the Runtime API call expects a primary driver context and the Driver context is not primary, or because the Driver context has been destroyed. Please see Interactions with the CUDA Driver API" for more information. 
cudaErrorPeerAccessAlreadyEnabled   EQU 50;    This error indicates that a call to cudaDeviceEnablePeerAccess() is trying to re-enable peer addressing on from a context which has already had peer addressing enabled. 
cudaErrorPeerAccessNotEnabled       EQU 51;    This error indicates that cudaDeviceDisablePeerAccess() is trying to disable peer addressing which has not been enabled yet via cudaDeviceEnablePeerAccess(). 
cudaErrorDeviceAlreadyInUse         EQU 54;    This indicates that a call tried to access an exclusive-thread device that is already in use by a different thread. 
cudaErrorProfilerDisabled           EQU 55;    This indicates profiler is not initialized for this run. This can happen when the application is running with external profiling tools like visual profiler. 
cudaErrorProfilerNotInitialized     EQU 56;    Deprecated. This error return is deprecated as of CUDA 5.0. It is no longer an error to attempt to enable/disable the profiling via cudaProfilerStart or cudaProfilerStop without initialization.
cudaErrorProfilerAlreadyStarted     EQU 57;    Deprecated. This error return is deprecated as of CUDA 5.0. It is no longer an error to call cudaProfilerStart() when profiling is already enabled.
cudaErrorProfilerAlreadyStopped     EQU 58;    Deprecated. This error return is deprecated as of CUDA 5.0. It is no longer an error to call cudaProfilerStop() when profiling is already disabled.
cudaErrorAssert                     EQU 59;    An assert triggered in device code during kernel execution. The device cannot be used again until cudaThreadExit() is called. All existing allocations are invalid and must be reconstructed if the program is to continue using CUDA. 
cudaErrorTooManyPeers               EQU 60;    This error indicates that the hardware resources required to enable peer access have been exhausted for one or more of the devices passed to cudaEnablePeerAccess(). 
cudaErrorHostMemoryAlreadyRegistered EQU 61;   This error indicates that the memory range passed to cudaHostRegister() has already been registered. 
cudaErrorHostMemoryNotRegistered    EQU 62;    This error indicates that the pointer passed to cudaHostUnregister() does not correspond to any currently registered memory region. 
cudaErrorOperatingSystem            EQU 63;    This error indicates that an OS call failed. 
cudaErrorPeerAccessUnsupported      EQU 64;    This error indicates that P2P access is not supported across the given devices. 
cudaErrorLaunchMaxDepthExceeded     EQU 65;    This error indicates that a device runtime grid launch did not occur because the depth of the child grid would exceed the maximum supported number of nested grid launches. 
cudaErrorLaunchFileScopedTex        EQU 66;    This error indicates that a grid launch did not occur because the kernel uses file-scoped textures which are unsupported by the device runtime. Kernels launched via the device runtime only support textures created with the Texture Object API's. 
cudaErrorLaunchFileScopedSurf       EQU 67;    This error indicates that a grid launch did not occur because the kernel uses file-scoped surfaces which are unsupported by the device runtime. Kernels launched via the device runtime only support surfaces created with the Surface Object API's. 
cudaErrorSyncDepthExceeded          EQU 68;    This error indicates that a call to cudaDeviceSynchronize made from the device runtime failed because the call was made at grid depth greater than than either the default (2 levels of grids) or user specified device limit cudaLimitDevRuntimeSyncDepth. To be able to synchronize on launched grids at a greater depth successfully, the maximum nested depth at which cudaDeviceSynchronize will be called must be specified with the cudaLimitDevRuntimeSyncDepth limit to the cudaDeviceSetLimit api before the host-side launch of a kernel using the device runtime. Keep in mind that additional levels of sync depth require the runtime to reserve large amounts of device memory that cannot be used for user allocations. 
cudaErrorLaunchPendingCountExceeded EQU 69;    This error indicates that a device runtime grid launch failed because the launch would exceed the limit cudaLimitDevRuntimePendingLaunchCount. For this launch to proceed successfully, cudaDeviceSetLimit must be called to set the cudaLimitDevRuntimePendingLaunchCount to be higher than the upper bound of outstanding launches that can be issued to the device runtime. Keep in mind that raising the limit of pending device runtime launches will require the runtime to reserve device memory that cannot be used for user allocations. 
cudaErrorNotPermitted               EQU 70;    This error indicates the attempted operation is not permitted. 
cudaErrorNotSupported               EQU 71;    This error indicates the attempted operation is not supported on the current system or device. 
cudaErrorHardwareStackError         EQU 72;    Device encountered an error in the call stack during kernel execution, possibly due to stack corruption or exceeding the stack size limit. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorIllegalInstruction         EQU 73;    The device encountered an illegal instruction during kernel execution This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorMisalignedAddress          EQU 74;    The device encountered a load or store instruction on a memory address which is not aligned. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorInvalidAddressSpace        EQU 75;    While executing a kernel, the device encountered an instruction which can only operate on memory locations in certain address spaces (global, shared, or local), but was supplied a memory address not belonging to an allowed address space. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorInvalidPc                  EQU 76;    The device encountered an invalid program counter. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorIllegalAddress             EQU 77;    The device encountered a load or store instruction on an invalid memory address. This leaves the process in an inconsistent state and any further CUDA work will return the same error. To continue using CUDA, the process must be terminated and relaunched. 
cudaErrorInvalidPtx                 EQU 78;    A PTX compilation failed. The runtime may fall back to compiling PTX if an application does not contain a suitable binary for the current device. 
cudaErrorInvalidGraphicsContext     EQU 79;    This indicates an error with the OpenGL or DirectX context. 
cudaErrorNvlinkUncorrectable        EQU 80;    This indicates that an uncorrectable NVLink error was detected during the execution. 
cudaErrorStartupFailure             EQU 7fh;   This indicates an internal startup failure in the CUDA runtime. 
cudaErrorApiFailureBase             EQU 10000; Deprecated. This error return is deprecated as of CUDA 4.1.

;cudaFuncCache                      CUDA function cache configurations 
cudaFuncCachePreferNone             EQU 0;     Default function cache configuration, no preference 
cudaFuncCachePreferShared           EQU 1;     Prefer larger shared memory and smaller L1 cache 
cudaFuncCachePreferL1               EQU 2;     Prefer larger L1 cache and smaller shared memory 
cudaFuncCachePreferEqual            EQU 3;     Prefer equal size L1 cache and shared memory 

;cudaGraphicsCubeFace               CUDA graphics interop array indices for cube maps 
cudaGraphicsCubeFacePositiveX       EQU 00;    Positive X face of cubemap 
cudaGraphicsCubeFaceNegativeX       EQU 01;    Negative X face of cubemap 
cudaGraphicsCubeFacePositiveY       EQU 02;    Positive Y face of cubemap 
cudaGraphicsCubeFaceNegativeY       EQU 03;    Negative Y face of cubemap 
cudaGraphicsCubeFacePositiveZ       EQU 04;    Positive Z face of cubemap 
cudaGraphicsCubeFaceNegativeZ       EQU 05;    Negative Z face of cubemap 

;cudaGraphicsMapFlags               CUDA graphics interop map flags
cudaGraphicsMapFlagsNone            EQU 0;     Default; Assume resource can be read/written 
cudaGraphicsMapFlagsReadOnly        EQU 1;     CUDA will not write to this resource 
cudaGraphicsMapFlagsWriteDiscard    EQU 2;     CUDA will only write to and will not read from this resource 

;cudaGraphicsRegisterFlags                  CUDA graphics interop register flags 
cudaGraphicsRegisterFlagsNone               EQU 0;     Default 
cudaGraphicsRegisterFlagsReadOnly           EQU 1;     CUDA will not write to this resource 
cudaGraphicsRegisterFlagsWriteDiscard       EQU 2;     CUDA will only write to and will not read from this resource 
cudaGraphicsRegisterFlagsSurfaceLoadStore   EQU 4;     CUDA will bind this resource to a surface reference 
cudaGraphicsRegisterFlagsTextureGather      EQU 8;     CUDA will perform texture gather operations on this resource 

;cudaLimit                                  CUDA Limits 
cudaLimitStackSize                          EQU 00h;   GPU thread stack size 
cudaLimitPrintfFifoSize                     EQU 01h;   GPU printf/fprintf FIFO size 
cudaLimitMallocHeapSize                     EQU 02h;   GPU malloc heap size 
cudaLimitDevRuntimeSyncDepth                EQU 03h;   GPU device runtime synchronize depth 
cudaLimitDevRuntimePendingLaunchCount       EQU 04h;   GPU device runtime pending launch count 

;cudaMemRangeAttribute                      CUDA range attributes 
cudaMemRangeAttributeReadMostly             EQU 1;     Whether the range will mostly be read and only occassionally be written to 
cudaMemRangeAttributePreferredLocation      EQU 2;     The preferred location of the range 
cudaMemRangeAttributeAccessedBy             EQU 3;     Memory range has cudaMemAdviseSetAccessedBy set for specified device 
cudaMemRangeAttributeLastPrefetchLocation   EQU 4;     The last location to which the range was prefetched 

;cudaMemcpyKind                     CUDA memory copy types 
cudaMemcpyHostToHost                EQU 0;     Host -> Host 
cudaMemcpyHostToDevice              EQU 1;     Host -> Device 
cudaMemcpyDeviceToHost              EQU 2;     Device -> Host 
cudaMemcpyDeviceToDevice            EQU 3;     Device -> Device 
cudaMemcpyDefault                   EQU 4;     Direction of the transfer is inferred from the pointer values. Requires unified virtual addressing 

;cudaMemoryAdvise                   CUDA Memory Advise values 
cudaMemAdviseSetReadMostly          EQU 1;     Data will mostly be read and only occassionally be written to 
cudaMemAdviseUnsetReadMostly        EQU 2;     Undo the effect of cudaMemAdviseSetReadMostly
cudaMemAdviseSetPreferredLocation   EQU 3;     Set the preferred location for the data as the specified device 
cudaMemAdviseUnsetPreferredLocation EQU 4;     Clear the preferred location for the data 
cudaMemAdviseSetAccessedBy          EQU 5;     Data will be accessed by the specified device, so prevent page faults as much as possible 
cudaMemAdviseUnsetAccessedBy        EQU 6;     Let the Unified Memory subsystem decide on the page faulting policy for the specified device 

;cudaMemoryType                     CUDA memory types 
cudaMemoryTypeHost                  EQU 1;     Host memory 
cudaMemoryTypeDevice                EQU 2;     Device memory 

;cudaOutputMode                     CUDA Profiler Output modes 
cudaKeyValuePair                    EQU 00h;   Output mode Key-Value pair format. 
cudaCSV                             EQU 01h;   Output mode Comma separated values format. 

;cudaResourceType                   CUDA resource types 
cudaResourceTypeArray               EQU 00h;   Array resource 
cudaResourceTypeMipmappedArray      EQU 01h;   Mipmapped array resource 
cudaResourceTypeLinear              EQU 02h;   Linear resource 
cudaResourceTypePitch2D             EQU 03h;   Pitch 2D resource 

;cudaResourceViewFormat                     CUDA texture resource view formats 
cudaResViewFormatNone                       EQU 00h;    No resource view format (use underlying resource format) 
cudaResViewFormatUnsignedChar1              EQU 01h;    1 channel unsigned 8-bit integers 
cudaResViewFormatUnsignedChar2              EQU 02h;    2 channel unsigned 8-bit integers 
cudaResViewFormatUnsignedChar4              EQU 03h;    4 channel unsigned 8-bit integers 
cudaResViewFormatSignedChar1                EQU 04h;    1 channel signed 8-bit integers 
cudaResViewFormatSignedChar2                EQU 05h;    2 channel signed 8-bit integers 
cudaResViewFormatSignedChar4                EQU 06h;    4 channel signed 8-bit integers 
cudaResViewFormatUnsignedShort1             EQU 07h;    1 channel unsigned 16-bit integers 
cudaResViewFormatUnsignedShort2             EQU 08h;    2 channel unsigned 16-bit integers 
cudaResViewFormatUnsignedShort4             EQU 09h;    4 channel unsigned 16-bit integers 
cudaResViewFormatSignedShort1               EQU 0ah;    1 channel signed 16-bit integers 
cudaResViewFormatSignedShort2               EQU 0bh;    2 channel signed 16-bit integers 
cudaResViewFormatSignedShort4               EQU 0ch;    4 channel signed 16-bit integers 
cudaResViewFormatUnsignedInt1               EQU 0dh;    1 channel unsigned 32-bit integers 
cudaResViewFormatUnsignedInt2               EQU 0eh;    2 channel unsigned 32-bit integers 
cudaResViewFormatUnsignedInt4               EQU 0fh;    4 channel unsigned 32-bit integers 
cudaResViewFormatSignedInt1                 EQU 10h;    1 channel signed 32-bit integers 
cudaResViewFormatSignedInt2                 EQU 11h;    2 channel signed 32-bit integers 
cudaResViewFormatSignedInt4                 EQU 12h;    4 channel signed 32-bit integers 
cudaResViewFormatHalf1                      EQU 13h;    1 channel 16-bit floating point 
cudaResViewFormatHalf2                      EQU 14h;    2 channel 16-bit floating point 
cudaResViewFormatHalf4                      EQU 15h;    4 channel 16-bit floating point 
cudaResViewFormatFloat1                     EQU 16h;    1 channel 32-bit floating point 
cudaResViewFormatFloat2                     EQU 17h;    2 channel 32-bit floating point 
cudaResViewFormatFloat4                     EQU 18h;    4 channel 32-bit floating point 
cudaResViewFormatUnsignedBlockCompressed1   EQU 19h;    Block compressed 1 
cudaResViewFormatUnsignedBlockCompressed2   EQU 1ah;    Block compressed 2 
cudaResViewFormatUnsignedBlockCompressed3   EQU 1bh;    Block compressed 3 
cudaResViewFormatUnsignedBlockCompressed4   EQU 1ch;    Block compressed 4 unsigned 
cudaResViewFormatSignedBlockCompressed4     EQU 1dh;    Block compressed 4 signed 
cudaResViewFormatUnsignedBlockCompressed5   EQU 1eh;    Block compressed 5 unsigned 
cudaResViewFormatSignedBlockCompressed5     EQU 1fh;    Block compressed 5 signed 
cudaResViewFormatUnsignedBlockCompressed6H  EQU 20h;    Block compressed 6 unsigned half-float 
cudaResViewFormatSignedBlockCompressed6H    EQU 21h;    Block compressed 6 signed half-float 
cudaResViewFormatUnsignedBlockCompressed7   EQU 22h;    Block compressed 7 

;cudaSharedMemConfig                CUDA shared memory configuration
cudaSharedMemBankSizeDefault        EQU 0
cudaSharedMemBankSizeFourByte       EQU 1
cudaSharedMemBankSizeEightByte      EQU 2

;cudaSurfaceBoundaryMode            CUDA Surface boundary modes
cudaBoundaryModeZero                EQU 0;    Zero boundary mode 
cudaBoundaryModeClamp               EQU 1;    Clamp boundary mode 
cudaBoundaryModeTrap                EQU 2;    Trap boundary mode 

;cudaSurfaceFormatMode              CUDA Surface format modes 
cudaFormatModeForced                EQU 0;    Forced format mode 
cudaFormatModeAuto                  EQU 1;    Auto format mode 

;cudaTextureAddressMode             CUDA texture address modes 
cudaAddressModeWrap                 EQU 0;    Wrapping address mode 
cudaAddressModeClamp                EQU 1;    Clamp to edge address mode 
cudaAddressModeMirror               EQU 2;    Mirror address mode 
cudaAddressModeBorder               EQU 3;    Border address mode 

;cudaTextureFilterMode              CUDA texture filter modes
cudaFilterModePoint                 EQU 0;    Point filter mode 
cudaFilterModeLinear                EQU 1;    Linear filter mode 

;cudaTextureReadMode                CUDA texture read modes 
cudaReadModeElementType             EQU 0;    Read texture as specified element type 
cudaReadModeNormalizedFloat         EQU 1;    Read texture as normalized float 


;CUDA Typedefs
cudaIpcEventHandle                  TYPEDEF QWORD;  CUDA IPC event handle
cudaIpcEventHandle_t                TYPEDEF QWORD;  CUDA IPC event handle
cudaIpcMemHandle                    TYPEDEF QWORD;  CUDA IPC memory handle
cudaIpcMemHandle_t                  TYPEDEF QWORD;  CUDA IPC memory handle 

;---------------------------------
; CUDA Structures - http://docs.nvidia.com/cuda/cuda-runtime-api/annotated.html#annotated
;---------------------------------

;cudaChannelFormatDesc              http://docs.nvidia.com/cuda/cuda-runtime-api/structcudaChannelFormatDesc.html#structcudaChannelFormatDesc
IFNDEF cudaChannelFormatDesc        ;CUDA Channel format descriptor  
cudaChannelFormatDesc               STRUCT 8
    x                               DD ?; /**< x */
    y                               DD ?; /**< y */
    z                               DD ?; /**< z */
    w                               DD ?; /**< w */
    f                               DD ?; /**< Channel format kind */ enum cudaChannelFormatKind 
cudaChannelFormatDesc               ENDS
ENDIF

;CudaDeviceProp                     http://docs.nvidia.com/cuda/cuda-runtime-api/structcudaDeviceProp.html#structcudaDeviceProp
IFNDEF CudaDeviceProp               ;CUDA device properties 
CudaDeviceProp                      STRUCT 8
    cudaname                        DB 256 DUP (?)
    totalGlobalMem                  DQ ?
    sharedMemPerBlock               DQ ?
    regsPerBlock                    DD ?
    warpSize                        DD ?
    memPitch                        DQ ?
    maxThreadsPerBlock              DD ?
    maxThreadsDim                   DD 3 DUP (?)
    maxGridSize                     DD 3 DUP (?)
    clockRate                       DD ?
    totalConstMem                   DQ ?
    major                           DD ?
    minor                           DD ?
    textureAlignment                DQ ?
    texturePitchAlignment           DQ ?
    deviceOverlap                   DD ?
    multiProcessorCount             DD ?
    kernelExecTimeoutEnabled        DD ?
    integrated                      DD ?
    canMapHostMemory                DD ?
    computeMode                     DD ?
    maxTexture1D                    DD ?
    maxTexture1DMipmap              DD ?
    maxTexture1DLinear              DD ?
    maxTexture2D                    DD 2 DUP (?)
    maxTexture2DMipmap              DD 2 DUP (?)
    maxTexture2DLinear              DD 3 DUP (?)
    maxTexture2DGather              DD 2 DUP (?)
    maxTexture3D                    DD 3 DUP (?)
    maxTexture3DAlt                 DD 3 DUP (?)
    maxTextureCubemap               DD ?
    maxTexture1DLayered             DD 2 DUP (?)
    maxTexture2DLayered             DD 3 DUP (?)
    maxTextureCubemapLayered        DD 2 DUP (?)
    maxSurface1D                    DD ?
    maxSurface2D                    DD 2 DUP (?)
    maxSurface3D                    DD 3 DUP (?)
    maxSurface1DLayered             DD 2 DUP (?)
    maxSurface2DLayered             DD 3 DUP (?)
    maxSurfaceCubemap               DD ?
    maxSurfaceCubemapLayered        DD 2 DUP (?)
    surfaceAlignment                DQ ?  
    concurrentKernels               DD ?
    ECCEnabled                      DD ?
    pciBusID                        DD ?
    pciDeviceID                     DD ?
    pciDomainID                     DD ?
    tccDriver                       DD ?
    asyncEngineCount                DD ?
    unifiedAddressing               DD ?
    memoryClockRate                 DD ?
    memoryBusWidth                  DD ?
    l2CacheSize                     DD ?
    maxThreadsPerMultiProcessor     DD ?
    streamPrioritiesSupported       DD ?
    globalL1CacheSupported          DD ?
    localL1CacheSupported           DD ?
    sharedMemPerMultiprocessor      DQ ?
    regsPerMultiprocessor           DD ?
    managedMemSupported             DD ?
    isMultiGpuBoard                 DD ?
    multiGpuBoardGroupID            DD ?
    singleToDoublePrecisionPerfRatio DD ?
    pageableMemoryAccess            DD ?
    concurrentManagedAccess         DD ?  
CudaDeviceProp                      ENDS
ENDIF

;cudaEglPlaneDesc                   http://docs.nvidia.com/cuda/cuda-runtime-api/structcudaEglFrame.html#structcudaEglFrame
IFNDEF cudaEglPlaneDesc             ;CUDA EGLFrame Descriptor - structure defining one frame of EGL.
cudaEglPlaneDesc                    STRUCT
    pwidth                          DD ?  
    pheight                         DD ?  
    pdepth                          DD ?  
    pitch                           DD ?  
    numChannels                     DD ?  
    channelDesc                     cudaChannelFormatDesc <?,?,?,?,?>
    reserved                        DD 4 DUP (?)
cudaEglPlaneDesc                    ENDS
ENDIF

;cudaExtent                         ;http://docs.nvidia.com/cuda/cuda-runtime-api/structcudaExtent.html#structcudaExtent
IFNDEF cudaExtent                   ;CUDA extent
cudaExtent                          STRUCT
    pwidth                          DQ ?;     /**< Width in elements when referring to array memory, in bytes when referring to linear memory */
    pheight                         DQ ?;    /**< Height in elements */
    pdepth                          DQ ?;     /**< Depth in elements */
cudaExtent                          ENDS
ENDIF

;cudaFuncAttributes                 ;http://docs.nvidia.com/cuda/cuda-runtime-api/structcudaFuncAttributes.html#structcudaFuncAttributes
IFNDEF cudaFuncAttributes           ;CUDA function attributes 
cudaFuncAttributes                  STRUCT
    sharedSizeBytes                 DQ ?;   The size in bytes of statically-allocated shared memory per block required by this function. This does not include dynamically-allocated shared memory requested by the user at runtime.
    constSizeBytes                  DQ ?;   The size in bytes of user-allocated constant memory required by this function.
    localSizeBytes                  DQ ?;   The size in bytes of local memory used by each thread of this function.
    maxThreadsPerBlock              DD ?;   The maximum number of threads per block, beyond which a launch of the function would fail. This number depends on both the function and the device on which the function is currently loaded.
    numRegs                         DD ?;   The number of registers used by each thread of this function.
    ptxVersion                      DD ?;   The PTX virtual architecture version for which the function was compiled. This value is the major PTX version * 10 + the minor PTX version, so a PTX version 1.3 function would return the value 13.
    binaryVersion                   DD ?;   The binary architecture version for which the function was compiled.This value is the major binary version * 10 + the minor binary version,so a binary version 1.3 function would return the value 13.
    cacheModeCA                     DD ?;   The attribute to indicate whether the function has been compiled with user specified option "-Xptxas --dlcm=ca" set.
cudaFuncAttributes                  ENDS
ENDIF






