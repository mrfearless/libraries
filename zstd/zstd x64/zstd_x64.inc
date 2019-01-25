; Zstandard x64 - Fast real-time compression algorithm 
; http://www.zstd.net
; https://github.com/facebook/zstd
; converted to x64 assembler style by fearless 2019

;-------------------------------------------------
; Zstandard Prototypes:
;-------------------------------------------------
ZSTD_CCtxParam_getParameter PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx_params* params, ZSTD_cParameter param, int* value
ZSTD_CCtxParam_setParameter PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx_params* params, ZSTD_cParameter param, int value
ZSTD_CCtxParams_init        PROTO :QWORD,:QWORD ; ZSTD_CCtx_params* cctxParams, int compressionLevel
ZSTD_CCtxParams_init_advanced PROTO :QWORD,:QWORD ; ZSTD_CCtx_params* cctxParams, ZSTD_parameters params
ZSTD_CCtxParams_reset       PROTO :QWORD ; ZSTD_CCtx_params* params
ZSTD_CCtx_getParameter      PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx_params* params, ZSTD_cParameter param, int* value
ZSTD_CCtx_loadDictionary    PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* dict, size_t dictSize
ZSTD_CCtx_loadDictionary_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType
ZSTD_CCtx_loadDictionary_byReference PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* dict, size_t dictSize
ZSTD_CCtx_refCDict          PROTO :QWORD,:QWORD ; ZSTD_CCtx* cctx, const ZSTD_CDict* cdict
ZSTD_CCtx_refPrefix         PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* prefix, size_t prefixSize
ZSTD_CCtx_refPrefix_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* prefix, size_t prefixSize, ZSTD_dictContentType_e dictContentType
ZSTD_CCtx_reset             PROTO :QWORD,:QWORD ; ZSTD_CCtx* cctx, ZSTD_ResetDirective reset
ZSTD_CCtx_setParameter      PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, ZSTD_cParameter param, int value
ZSTD_CCtx_setParametersUsingCCtxParams PROTO :QWORD,:QWORD ; ZSTD_CCtx* cctx, const ZSTD_CCtx_params* params
ZSTD_CCtx_setPledgedSrcSize PROTO :QWORD,:QWORD ; ZSTD_CCtx* cctx, unsigned long long pledgedSrcSize
ZSTD_CStreamInSize          PROTO ; void
ZSTD_CStreamOutSize         PROTO ; void
ZSTD_DCtx_loadDictionary    PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* dict, size_t dictSize
ZSTD_DCtx_loadDictionary_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType
ZSTD_DCtx_loadDictionary_byReference PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* dict, size_t dictSize
ZSTD_DCtx_refDDict          PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, const ZSTD_DDict* ddict
ZSTD_DCtx_refPrefix         PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* prefix, size_t prefixSize
ZSTD_DCtx_refPrefix_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* prefix, size_t prefixSize, ZSTD_dictContentType_e dictContentType
ZSTD_DCtx_reset             PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, ZSTD_ResetDirective reset
ZSTD_DCtx_setFormat         PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, ZSTD_format_e format
ZSTD_DCtx_setMaxWindowSize  PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, size_t maxWindowSize
ZSTD_DCtx_setParameter      PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, ZSTD_dParameter param, int value
ZSTD_DStreamInSize          PROTO ; void
ZSTD_DStreamOutSize         PROTO ; void
ZSTD_adjustCParams          PROTO :QWORD,:QWORD,:QWORD ; ZSTD_compressionParameters cPar, unsigned long long srcSize, size_t dictSize
ZSTD_cParam_getBounds       PROTO :QWORD ; ZSTD_cParameter cParam
ZSTD_checkCParams           PROTO :QWORD ; ZSTD_compressionParameters params
ZSTD_compress               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; size_t ZSTD_compress( void* dst, size_t dstCapacity, const void* src, size_t srcSize, int compressionLevel);
ZSTD_compress2              PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_compressBegin          PROTO :QWORD,:QWORD ; ZSTD_CCtx* cctx, int compressionLevel
ZSTD_compressBegin_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* dict, size_t dictSize, ZSTD_parameters params, unsigned long long pledgedSrcSize
ZSTD_compressBegin_usingCDict PROTO DWORD,:QWORD ; ZSTD_CCtx* cctx, const ZSTD_CDict* cdict
ZSTD_compressBegin_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* const cctx, const ZSTD_CDict* const cdict, ZSTD_frameParameters const fParams, unsigned long long const pledgedSrcSize
ZSTD_compressBegin_usingDict PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const void* dict, size_t dictSize, int compressionLevel
ZSTD_compressBlock          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_compressBound          PROTO :QWORD ; size_t srcSize
ZSTD_compressCCtx           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, int compressionLevel
ZSTD_compressContinue       PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_compressEnd            PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_compressStream         PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CStream* zcs, ZSTD_outBuffer* output, ZSTD_inBuffer* input
ZSTD_compressStream2        PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, ZSTD_outBuffer* output, ZSTD_inBuffer* input, ZSTD_EndDirective endOp
ZSTD_compressStream2_simpleArgs PROTO ::QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, size_t* dstPos, const void* src, size_t srcSize, size_t* srcPos, ZSTD_EndDirective endOp
ZSTD_compress_advanced      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const void* dict, size_t dictSize, ZSTD_parameters params
ZSTD_compress_usingCDict    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const ZSTD_CDict* cdict
ZSTD_compress_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const ZSTD_CDict* cdict, ZSTD_frameParameters fParams
ZSTD_compress_usingDict     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CCtx* ctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const void* dict, size_t dictSize, int compressionLevel
ZSTD_copyCCtx               PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CCtx* cctx, const ZSTD_CCtx* preparedCCtx, unsigned long long pledgedSrcSize
ZSTD_copyDCtx               PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, const ZSTD_DCtx* preparedDCtx
ZSTD_createCCtx             PROTO ; void
ZSTD_createCCtxParams       PROTO ; void
ZSTD_createCCtx_advanced    PROTO :QWORD ; ZSTD_customMem customMem
ZSTD_createCDict            PROTO :QWORD,:QWORD,:QWORD ; const void* dictBuffer, size_t dictSize, int compressionLevel
ZSTD_createCDict_advanced   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType, ZSTD_compressionParameters cParams, ZSTD_customMem customMem
ZSTD_createCDict_byReference PROTO :QWORD,:QWORD,:QWORD ; const void* dictBuffer, size_t dictSize, int compressionLevel
ZSTD_createCStream          PROTO ; void
ZSTD_createCStream_advanced PROTO :QWORD ; ZSTD_customMem customMem
ZSTD_createDCtx             PROTO ; void 
ZSTD_createDCtx_advanced    PROTO :QWORD ; ZSTD_customMem customMem
ZSTD_createDDict            PROTO :QWORD,:QWORD ; const void* dictBuffer, size_t dictSize
ZSTD_createDDict_advanced   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType, ZSTD_customMem customMem
ZSTD_createDDict_byReference PROTO :QWORD,:QWORD ; const void* dictBuffer, size_t dictSize
ZSTD_createDStream          PROTO ; void
ZSTD_createDStream_advanced PROTO :QWORD ; ZSTD_customMem customMem
ZSTD_dParam_getBounds       PROTO :QWORD ; ZSTD_dParameter dParam
ZSTD_decodingBufferSize_min PROTO :QWORD,:QWORD ; unsigned long long windowSize, unsigned long long frameContentSize
ZSTD_decompress             PROTO :QWORD,:QWORD,:QWORD,:QWORD ; size_t ZSTD_decompress( void* dst, size_t dstCapacity, const void* src, size_t compressedSize);
ZSTD_decompressBegin        PROTO :QWORD ; ZSTD_DCtx* dctx
ZSTD_decompressBegin_usingDDict PROTO :QWORD,:QWORD ; ZSTD_DCtx* dctx, const ZSTD_DDict* ddict
ZSTD_decompressBegin_usingDict PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* dict, size_t dictSize
ZSTD_decompressBlock        PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_decompressContinue     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_decompressDCtx         PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize
ZSTD_decompressStream       PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DStream* zds, ZSTD_outBuffer* output, ZSTD_inBuffer* input
ZSTD_decompressStream_simpleArgs PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, size_t* dstPos, const void* src, size_t srcSize, size_t* srcPos
ZSTD_decompress_usingDDict  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const ZSTD_DDict* ddict
ZSTD_decompress_usingDict   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, void* dst, size_t dstCapacity, const void* src, size_t srcSize, const void* dict, size_t dictSize
ZSTD_endStream              PROTO :QWORD,:QWORD ; ZSTD_CStream* zcs, ZSTD_outBuffer* output
ZSTD_estimateCCtxSize       PROTO :QWORD ; int compressionLevel
ZSTD_estimateCCtxSize_usingCCtxParams PROTO :QWORD ; const ZSTD_CCtx_params* params
ZSTD_estimateCCtxSize_usingCParams PROTO :QWORD ; ZSTD_compressionParameters cParams
ZSTD_estimateCDictSize      PROTO :QWORD,:QWORD ; size_t dictSize, int compressionLevel
ZSTD_estimateCDictSize_advanced PROTO :QWORD,:QWORD,:QWORD ; size_t dictSize, ZSTD_compressionParameters cParams, ZSTD_dictLoadMethod_e dictLoadMethod
ZSTD_estimateCStreamSize    PROTO :QWORD ; int compressionLevel
ZSTD_estimateCStreamSize_usingCCtxParams PROTO :QWORD ; const ZSTD_CCtx_params* params
ZSTD_estimateCStreamSize_usingCParams PROTO :QWORD ; ZSTD_compressionParameters cParams
ZSTD_estimateDCtxSize       PROTO ; void
ZSTD_estimateDDictSize      PROTO :QWORD,:QWORD ; size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod
ZSTD_estimateDStreamSize    PROTO :QWORD ; size_t windowSize
ZSTD_estimateDStreamSize_fromFrame PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_findDecompressedSize   PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_findFrameCompressedSize PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_flushStream            PROTO :QWORD,:QWORD ; ZSTD_CStream* zcs, ZSTD_outBuffer* output
ZSTD_frameHeaderSize        PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_freeCCtx               PROTO :QWORD ; ZSTD_CCtx* cctx
ZSTD_freeCCtxParams         PROTO :QWORD ; ZSTD_CCtx_params* params
ZSTD_freeCDict              PROTO :QWORD ; ZSTD_CDict* CDict
ZSTD_freeCStream            PROTO :QWORD ; ZSTD_CStream* zcs
ZSTD_freeDCtx               PROTO :QWORD ; ZSTD_DCtx* dctx
ZSTD_freeDDict              PROTO :QWORD ; ZSTD_DDict* ddict
ZSTD_freeDStream            PROTO :QWORD ; ZSTD_DStream* zds
ZSTD_getBlockSize           PROTO :QWORD ; const ZSTD_CCtx* cctx
ZSTD_getCParams             PROTO :QWORD,:QWORD,:QWORD ; int compressionLevel, unsigned long long estimatedSrcSize, size_t dictSize
ZSTD_getDecompressedSize    PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_getDictID_fromDDict    PROTO :QWORD ; const ZSTD_DDict* ddict
ZSTD_getDictID_fromDict     PROTO :QWORD,:QWORD ; const void* dict, size_t dictSize
ZSTD_getDictID_fromFrame    PROTO :QWORD,:QWORD ; const void* src, size_t srcSize
ZSTD_getErrorName           PROTO :QWORD ; size_t code
ZSTD_getFrameContentSize    PROTO ::QWORD,:QWORD ; const void *src, size_t srcSize
ZSTD_getFrameHeader         PROTO :QWORD,:QWORD,:QWORD ; ZSTD_frameHeader* zfhPtr, const void* src, size_t srcSize
ZSTD_getFrameHeader_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_frameHeader* zfhPtr, const void* src, size_t srcSize, ZSTD_format_e format
ZSTD_getFrameProgression    PROTO :QWORD ; const ZSTD_CCtx* cctx
ZSTD_getParams              PROTO :QWORD,:QWORD,:QWORD ; int compressionLevel, unsigned long long estimatedSrcSize, size_t dictSize
ZSTD_initCStream            PROTO :QWORD,:QWORD ; ZSTD_CStream* zcs, int compressionLevel
ZSTD_initCStream_advanced   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CStream* zcs, const void* dict, size_t dictSize, ZSTD_parameters params, unsigned long long pledgedSrcSize
ZSTD_initCStream_srcSize    PROTO :QWORD,:QWORD,:QWORD ; ZSTD_CStream* zcs, int compressionLevel, unsigned long long pledgedSrcSize
ZSTD_initCStream_usingCDict PROTO :QWORD,:QWORD ; ZSTD_CStream* zcs, const ZSTD_CDict* cdict
ZSTD_initCStream_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CStream* zcs, const ZSTD_CDict* cdict, ZSTD_frameParameters fParams, unsigned long long pledgedSrcSize
ZSTD_initCStream_usingDict  PROTO :QWORD,:QWORD,:QWORD,:QWORD ; ZSTD_CStream* zcs, const void* dict, size_t dictSize, int compressionLevel
ZSTD_initDStream            PROTO :QWORD ; ZSTD_DStream* zds
ZSTD_initDStream_usingDDict PROTO :QWORD,:QWORD ; ZSTD_DStream* zds, const ZSTD_DDict* ddict
ZSTD_initDStream_usingDict  PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DStream* zds, const void* dict, size_t dictSize
ZSTD_initStaticCCtx         PROTO :QWORD,:QWORD ; void* workspace, size_t workspaceSize
ZSTD_initStaticCDict        PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; void* workspace, size_t workspaceSize, const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType, ZSTD_compressionParameters cParams
ZSTD_initStaticCStream      PROTO :QWORD,:QWORD ; void* workspace, size_t workspaceSize
ZSTD_initStaticDCtx         PROTO :QWORD,:QWORD ; void* workspace, size_t workspaceSize
ZSTD_initStaticDDict        PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD ; void* workspace, size_t workspaceSize, const void* dict, size_t dictSize, ZSTD_dictLoadMethod_e dictLoadMethod, ZSTD_dictContentType_e dictContentType
ZSTD_initStaticDStream      PROTO :QWORD,:QWORD ; void* workspace, size_t workspaceSize
ZSTD_insertBlock            PROTO :QWORD,:QWORD,:QWORD ; ZSTD_DCtx* dctx, const void* blockStart, size_t blockSize
ZSTD_isError                PROTO :QWORD ; size_t code
ZSTD_isFrame                PROTO :QWORD,:QWORD ; const void* buffer, size_t size
ZSTD_maxCLevel              PROTO ; void
ZSTD_minCLevel              PROTO ; void
ZSTD_nextInputType          PROTO :QWORD ; ZSTD_DCtx* dctx
ZSTD_nextSrcSizeToDecompress PROTO :QWORD ; ZSTD_DCtx* dctx
ZSTD_resetCStream           PROTO :QWORD,:QWORD ; ZSTD_CStream* zcs, unsigned long long pledgedSrcSize
ZSTD_resetDStream           PROTO :QWORD ; ZSTD_DStream* zds
ZSTD_sizeof_CCtx            PROTO :QWORD ; const ZSTD_CCtx* cctx
ZSTD_sizeof_CDict           PROTO :QWORD ; const ZSTD_CDict* cdict
ZSTD_sizeof_CStream         PROTO :QWORD ; const ZSTD_CStream* zcs
ZSTD_sizeof_DCtx            PROTO :QWORD ; const ZSTD_DCtx* dctx
ZSTD_sizeof_DDict           PROTO :QWORD ; const ZSTD_DDict* ddict
ZSTD_sizeof_DStream         PROTO :QWORD ; const ZSTD_DStream* zds
ZSTD_toFlushNow             PROTO :QWORD ; ZSTD_CCtx* cctx
ZSTD_versionNumber          PROTO ; void
ZSTD_versionString          PROTO ; void


;-------------------------------------------------
; Zstandard Structures:
;-------------------------------------------------
ZSTD_inBuffer               STRUCT 
  src                       QWORD ? ; const void* - start of input buffer
  srcsize                   QWORD ? ; size_t - size of input buffer
  pos                       QWORD ? ; size_t - position where reading stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_inBuffer               ENDS

ZSTD_outBuffer              STRUCT 
  dst                       QWORD ? ; void* - start of output buffer
  dstsize                   QWORD ? ; size_t - size of output buffer
  pos                       QWORD ? ; size_t - position where writing stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_outBuffer              ENDS

ZSTD_bounds                 STRUCT
    zerror                  QWORD ? ; size_t
    lowerBound              DWORD ? ; int
    upperBound              DWORD ? ; int
ZSTD_bounds                 ENDS

ZSTD_compressionParameters  STRUCT
    windowLog               DWORD ? ; unsigned - largest match distance : larger equals more compression, more memory needed during decompression
    chainLog                DWORD ? ; unsigned - fully searched segment : larger equals more compression, slower, more memory (useless for fast)
    hashLog                 DWORD ? ; unsigned - dispatch table : larger equals faster, more memory
    searchLog               DWORD ? ; unsigned - nb of searches : larger equals more compression, slower
    minMatch                DWORD ? ; unsigned - match length searched : larger equals faster decompression, sometimes less compression
    targetLength            DWORD ? ; unsigned - acceptable match size for optimal parser (only) : larger equals more compression, slower
    strategy                DWORD ? ; see ZSTD_strategy enum
ZSTD_compressionParameters  ENDS

ZSTD_frameParameters        STRUCT
    contentSizeFlag         DWORD ? ; int - 1: content size will be in frame header (when known)
    checksumFlag            DWORD ? ; int - generate a 32-bits checksum using XXH64 algorithm at end of frame, for error detection
    noDictIDFlag            DWORD ? ; int - 1: no dictID will be saved into frame header (dictID is only useful for dictionary compression)
ZSTD_frameParameters        ENDS

ZSTD_parameters             STRUCT
    cParams                 ZSTD_compressionParameters <>
    fParams                 ZSTD_frameParameters <>
ZSTD_parameters             ENDS

ZSTD_frameProgression       STRUCT
    ingested                QWORD ? ; unsigned long long - nb input bytes read and buffered
    consumed                QWORD ? ; unsigned long long - nb input bytes actually compressed
    produced                QWORD ? ; unsigned long long - nb of compressed bytes generated and buffered
    flushed                 QWORD ? ; unsigned long long - nb of compressed bytes flushed : not provided; can be tracked from caller side
    currentJobID            DWORD ? ; unsigned - MT only : latest started job nb
    nbActiveWorkers         DWORD ? ; unsigned - MT only : nb of workers actively compressing at probe time
ZSTD_frameProgression       ENDS

ZSTD_frameHeader            STRUCT
    frameContentSize        QWORD ? ; unsigned long long - if equals ZSTD_CONTENTSIZE_UNKNOWN, it means this field is not available. 0 means "empty"
    windowSize              QWORD ? ; unsigned long long - can be very large, up to <= frameContentSize
    blockSizeMax            DWORD ? ; unsigned
    frameType               DWORD ? ; ZSTD_frameType_e - if equals ZSTD_skippableFrame, frameContentSize is the size of skippable content
    headerSize              DWORD ? ; unsigned
    dictID                  DWORD ? ; unsigned
    checksumFlag            DWORD ? ; unsigned
ZSTD_frameHeader            ENDS



;-------------------------------------------------
; Zstandard Constants & Enums
;-------------------------------------------------
.CONST
ZSTD_VERSION_MAJOR          EQU 1
ZSTD_VERSION_MINOR          EQU 3
ZSTD_VERSION_RELEASE        EQU 8
ZSTD_VERSION_NUMBER         EQU ((ZSTD_VERSION_MAJOR *100*100) + (ZSTD_VERSION_MINOR *100) + ZSTD_VERSION_RELEASE)
ZSTD_CLEVEL_DEFAULT         EQU 3
ZSTD_CONTENTSIZE_UNKNOWN    EQU 1
ZSTD_CONTENTSIZE_ERROR      EQU 2
ZSTD_MAGICNUMBER            EQU 0FD2FB528h    ; valid since v0.8.0
ZSTD_MAGIC_DICTIONARY       EQU 0EC30A437h    ; valid since v0.7.0
ZSTD_MAGIC_SKIPPABLE_START  EQU 0184D2A50h    ; all 16 values, from EQU 0184D2A50 to EQU 0184D2A5F, signal the beginning of a skippable frame
ZSTD_MAGIC_SKIPPABLE_MASK   EQU 0FFFFFFF0h
ZSTD_BLOCKSIZELOG_MAX       EQU 17
ZSTD_BLOCKSIZE_MAX          EQU (1 SHL ZSTD_BLOCKSIZELOG_MAX)
ZSTD_FRAMEHEADERSIZE_PREFIX EQU 5   ; minimum input size required to query frame header size
ZSTD_FRAMEHEADERSIZE_MIN    EQU 6
ZSTD_FRAMEHEADERSIZE_MAX    EQU 18   ; can be useful for static allocation
ZSTD_SKIPPABLEHEADERSIZE    EQU 8
; compression parameter bounds
ZSTD_WINDOWLOG_MAX_32       EQU 30
ZSTD_WINDOWLOG_MAX_64       EQU 31
ZSTD_WINDOWLOG_MAX          EQU ZSTD_WINDOWLOG_MAX_64 ;((int)(sizeof(size_t) equals 4 ? ZSTD_WINDOWLOG_MAX_32 : ZSTD_WINDOWLOG_MAX_64))
ZSTD_WINDOWLOG_MIN          EQU 10
ZSTD_HASHLOG_MAX            EQU ZSTD_WINDOWLOG_MAX ;((ZSTD_WINDOWLOG_MAX < 30) ? ZSTD_WINDOWLOG_MAX : 30)
ZSTD_HASHLOG_MIN            EQU 6
ZSTD_CHAINLOG_MAX_32        EQU 29
ZSTD_CHAINLOG_MAX_64        EQU 30
ZSTD_CHAINLOG_MAX           EQU ZSTD_CHAINLOG_MAX_64 ;((int)(sizeof(size_t) equals 4 ? ZSTD_CHAINLOG_MAX_32 : ZSTD_CHAINLOG_MAX_64))
ZSTD_CHAINLOG_MIN           EQU ZSTD_HASHLOG_MIN
ZSTD_SEARCHLOG_MAX          EQU (ZSTD_WINDOWLOG_MAX-1)
ZSTD_SEARCHLOG_MIN          EQU 1
ZSTD_MINMATCH_MAX           EQU 7   ; only for ZSTD_fast, other strategies are limited to 6
ZSTD_MINMATCH_MIN           EQU 3   ; only for ZSTD_btopt+, faster strategies are limited to 4
ZSTD_TARGETLENGTH_MAX       EQU ZSTD_BLOCKSIZE_MAX
ZSTD_TARGETLENGTH_MIN       EQU 0   ; note : comparing this constant to an unsigned results in a tautological test
ZSTD_STRATEGY_MIN           EQU ZSTD_fast
ZSTD_STRATEGY_MAX           EQU ZSTD_btultra2
ZSTD_OVERLAPLOG_MIN         EQU 0
ZSTD_OVERLAPLOG_MAX         EQU 9
ZSTD_WINDOWLOG_LIMIT_DEFAULT EQU 27
; LDM parameter bounds
ZSTD_LDM_HASHLOG_MIN        EQU ZSTD_HASHLOG_MIN
ZSTD_LDM_HASHLOG_MAX        EQU ZSTD_HASHLOG_MAX
ZSTD_LDM_MINMATCH_MIN       EQU 4
ZSTD_LDM_MINMATCH_MAX       EQU 4096
ZSTD_LDM_BUCKETSIZELOG_MIN  EQU 1
ZSTD_LDM_BUCKETSIZELOG_MAX  EQU 8
ZSTD_LDM_HASHRATELOG_MIN    EQU 0
ZSTD_LDM_HASHRATELOG_MAX    EQU (ZSTD_WINDOWLOG_MAX - ZSTD_HASHLOG_MIN)
; internal
ZSTD_HASHLOG3_MAX           EQU 17


;-------------------------------------------------
; Enums:
;-------------------------------------------------
; ZSTD_strategy enum (Compression strategies, listed from fastest to strongest):
ZSTD_fast                   EQU 1
ZSTD_dfast                  EQU 2
ZSTD_greedy                 EQU 3
ZSTD_lazy                   EQU 4
ZSTD_lazy2                  EQU 5
ZSTD_btlazy2                EQU 6
ZSTD_btopt                  EQU 7
ZSTD_btultra                EQU 8
ZSTD_btultra2               EQU 9
; ZSTD_ResetDirective enum:
ZSTD_reset_session_only     EQU 1
ZSTD_reset_parameters       EQU 2
ZSTD_reset_session_and_parameters EQU 3
; ZSTD_EndDirective enum:
ZSTD_e_continue             EQU 0
ZSTD_e_flush                EQU 1
ZSTD_e_end                  EQU 2
; ZSTD_cParameter enum:
ZSTD_c_compressionLevel     EQU 100
ZSTD_c_windowLog            EQU 101
ZSTD_c_hashLog              EQU 102
ZSTD_c_chainLog             EQU 103
ZSTD_c_searchLog            EQU 104
ZSTD_c_minMatch             EQU 105
ZSTD_c_targetLength         EQU 106
ZSTD_c_strategy             EQU 107
; LDM mode parameters
ZSTD_c_enableLongDistanceMatching EQU 160
ZSTD_c_ldmHashLog           EQU 161
ZSTD_c_ldmMinMatch          EQU 162
ZSTD_c_ldmBucketSizeLog     EQU 163
ZSTD_c_ldmHashRateLog       EQU 164
ZSTD_c_contentSizeFlag      EQU 200
ZSTD_c_checksumFlag         EQU 201
ZSTD_c_dictIDFlag           EQU 202
ZSTD_c_nbWorkers            EQU 400
ZSTD_c_jobSize              EQU 401
ZSTD_c_overlapLog           EQU 402
ZSTD_c_experimentalParam1   EQU 500
ZSTD_c_experimentalParam2   EQU 10
ZSTD_c_experimentalParam3   EQU 1000
ZSTD_c_experimentalParam4   EQU 1001
; ZSTD_dictContentType_e enum:
ZSTD_dct_auto               EQU 0
ZSTD_dct_rawContent         EQU 1
ZSTD_dct_fullDict           EQU 2
; ZSTD_dictLoadMethod_e enum:
ZSTD_dlm_byCopy             EQU 0
ZSTD_dlm_byRef              EQU 1
; ZSTD_format_e enum:
ZSTD_f_zstd1                EQU 0
ZSTD_f_zstd1_magicless      EQU 1
; ZSTD_dictLoadMethod_e enum:
ZSTD_dlm_byCopy             EQU 0
ZSTD_dlm_byRef              EQU 1
; ZSTD_dictAttachPref_e enum:
ZSTD_dictDefaultAttach      EQU 0
ZSTD_dictForceAttach        EQU 1
ZSTD_dictForceCopy          EQU 2
; ZSTD_frameType_e enum:
ZSTD_frame                  EQU 0
ZSTD_skippableFrame         EQU 1
