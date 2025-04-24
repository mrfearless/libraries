;
;  LZ4 - Fast LZ compression algorithm
;  Header File
;  Copyright (C) 2011-2020, Yann Collet.
;
; BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met:
;
;     * Redistributions of source code must retain the above copyright
; notice, this list of conditions and the following disclaimer.
;     * Redistributions in binary form must reproduce the above
; copyright notice, this list of conditions and the following disclaimer
; in the documentation and/or other materials provided with the
; distribution.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
; You can contact the author at :
;  - LZ4 homepage : http://www.lz4.org
;  - LZ4 source repository : https://github.com/lz4/lz4

; lz4_x86.inc converted from LZ4 source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

LZ4F_compressBegin PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,prefsPtr:DWORD
LZ4F_compressBegin_usingCDict PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,cdict:DWORD,prefsPtr:DWORD
LZ4F_compressBound PROTO STDCALL srcSize:DWORD,prefsPtr:DWORD
LZ4F_compressEnd PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,cOptPtr:DWORD
LZ4F_compressFrame PROTO STDCALL dstBuffer:DWORD,dstCapacity:DWORD,srcBuffer:DWORD,srcSize:DWORD,preferencesPtr:DWORD
LZ4F_compressFrameBound PROTO STDCALL srcSize:DWORD,preferencesPtr:DWORD
LZ4F_compressFrame_usingCDict PROTO STDCALL cctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,cdict:DWORD,preferencesPtr:DWORD
LZ4F_compressUpdate PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,srcBuffer:DWORD,srcSize:DWORD,cOptPtr:DWORD
LZ4F_compressionLevel_max PROTO STDCALL 
LZ4F_createCDict PROTO STDCALL dictBuffer:DWORD,dictSize:DWORD
LZ4F_createCDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZ4F_createCompressionContext PROTO STDCALL cctxPtr:DWORD,version:DWORD
LZ4F_createCompressionContext_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZ4F_createDecompressionContext PROTO STDCALL :DWORD,:DWORD
LZ4F_createDecompressionContext_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZ4F_decompress PROTO STDCALL dctx:DWORD,dstBuffer:DWORD,dstSizePtr:DWORD,srcBuffer:DWORD,srcSizePtr:DWORD,dOptPtr:DWORD
LZ4F_decompress_usingDict PROTO STDCALL dctxPtr:DWORD,dstBuffer:DWORD,dstSizePtr:DWORD,srcBuffer:DWORD,srcSizePtr:DWORD,dict:DWORD,dictSize:DWORD,decompressOptionsPtr:DWORD
LZ4F_flush PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,cOptPtr:DWORD
LZ4F_freeCDict PROTO STDCALL CDict:DWORD
LZ4F_freeCompressionContext PROTO STDCALL cctx:DWORD
LZ4F_freeDecompressionContext PROTO STDCALL :DWORD
LZ4F_getBlockSize PROTO STDCALL blockSizeID:DWORD
LZ4F_getErrorCode PROTO STDCALL functionResult:DWORD
LZ4F_getErrorName PROTO STDCALL LZ4F_errorCode:DWORD
LZ4F_getFrameInfo PROTO STDCALL dctx:DWORD,frameInfoPtr:DWORD,srcBuffer:DWORD,srcSizePtr:DWORD
LZ4F_getVersion PROTO STDCALL 
LZ4F_headerSize PROTO STDCALL src:DWORD,srcSize:DWORD
LZ4F_isError PROTO STDCALL LZ4F_errorCode:DWORD
LZ4F_resetDecompressionContext PROTO STDCALL dctx:DWORD
LZ4F_uncompressedUpdate PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstCapacity:DWORD,srcBuffer:DWORD,srcSize:DWORD,cOptPtr:DWORD
LZ4_attach_HC_dictionary PROTO STDCALL working_stream:DWORD,dictionary_stream:DWORD
LZ4_attach_dictionary PROTO STDCALL workingStream:DWORD,dictionaryStream:DWORD
LZ4_compress PROTO STDCALL src:DWORD,dest:DWORD,srcSize:DWORD ; Obsolete, use LZ4_compress_default() instead
LZ4_compressBound PROTO STDCALL inputSize:DWORD
LZ4_compressHC2 PROTO STDCALL source:DWORD,dest:DWORD,inputSize:DWORD,compressionLevel:DWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC2_continue PROTO STDCALL LZ4HC_Data:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,compressionLevel:DWORD ; Obsolete use LZ4_compress_HC_continue() instead
LZ4_compressHC2_limitedOutput PROTO STDCALL source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD,compressionLevel:DWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC2_limitedOutput_continue PROTO STDCALL LZ4HC_Data:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD,compressionLevel:DWORD ; Obsolete use LZ4_compress_HC_continue() instead
LZ4_compressHC2_limitedOutput_withStateHC PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD,compressionLevel:DWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC2_withStateHC PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,compressionLevel:DWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC PROTO STDCALL source:DWORD,dest:DWORD,inputSize:DWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC_continue PROTO STDCALL LZ4_streamHCPtr:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD ; deprecated use LZ4_compress_HC_continue() instead
LZ4_compressHC_limitedOutput PROTO STDCALL source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC_limitedOutput_continue PROTO STDCALL LZ4_streamHCPtr:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD ; deprecated use LZ4_compress_HC_continue() instead
LZ4_compressHC_limitedOutput_withStateHC PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC_withStateHC PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compress_HC PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,compressionLevel:DWORD
LZ4_compress_HC_continue PROTO STDCALL streamHCPtr:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,maxDstSize:DWORD
LZ4_compress_HC_continue_destSize PROTO STDCALL LZ4_streamHCPtr:DWORD,src:DWORD,dst:DWORD,srcSizePtr:DWORD,targetDstSize:DWORD
LZ4_compress_HC_destSize PROTO STDCALL stateHC:DWORD,src:DWORD,dst:DWORD,srcSizePtr:DWORD,targetDstSize:DWORD,compressionLevel:DWORD
LZ4_compress_HC_extStateHC PROTO STDCALL stateHC:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,maxDstSize:DWORD,compressionLevel:DWORD
LZ4_compress_HC_extStateHC_fastReset PROTO STDCALL state:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,compressionLevel:DWORD
LZ4_compress_continue PROTO STDCALL LZ4_streamPtr:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD ; Obsolete use LZ4_compress_fast_continue() instead
LZ4_compress_default PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD
LZ4_compress_destSize PROTO STDCALL src:DWORD,dst:DWORD,srcSizePtr:DWORD,targetDstSize:DWORD
LZ4_compress_fast PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,acceleration:DWORD
LZ4_compress_fast_continue PROTO STDCALL streamPtr:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,acceleration:DWORD
LZ4_compress_fast_extState PROTO STDCALL state:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,acceleration:DWORD
LZ4_compress_fast_extState_fastReset PROTO STDCALL state:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,acceleration:DWORD
LZ4_compress_forceExtDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LZ4_compress_limitedOutput PROTO STDCALL src:DWORD,dest:DWORD,srcSize:DWORD,maxOutputSize:DWORD ; Obsolete use LZ4_compress_default() instead
LZ4_compress_limitedOutput_continue PROTO STDCALL LZ4_streamPtr:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD ; Obsolete use LZ4_compress_fast_continue() instead
LZ4_compress_limitedOutput_withState PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxOutputSize:DWORD ; Obsolete use LZ4_compress_fast_extState() instead
LZ4_compress_withState PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD ; Obsolete use LZ4_compress_fast_extState() instead
LZ4_create PROTO STDCALL inputBuffer:DWORD ; Obsolete Use LZ4_createStream() instead
LZ4_createHC PROTO STDCALL inputBuffer:DWORD ; Obsolete use LZ4_createStreamHC() instead
LZ4_createStream PROTO STDCALL 
LZ4_createStreamDecode PROTO STDCALL 
LZ4_createStreamHC PROTO STDCALL 
LZ4_decoderRingBufferSize PROTO STDCALL maxBlockSize:DWORD
LZ4_decompress_fast PROTO STDCALL src:DWORD,dst:DWORD,originalSize:DWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe() instead
LZ4_decompress_fast_continue PROTO STDCALL LZ4_streamDecode:DWORD,src:DWORD,dst:DWORD,originalSize:DWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe_continue() instead
LZ4_decompress_fast_usingDict PROTO STDCALL src:DWORD,dst:DWORD,originalSize:DWORD,dictStart:DWORD,dictSize:DWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe_usingDict() instead
LZ4_decompress_fast_withPrefix64k PROTO STDCALL src:DWORD,dst:DWORD,originalSize:DWORD ; Obsolete use LZ4_decompress_fast_usingDict() instead
LZ4_decompress_safe PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LZ4_decompress_safe_continue PROTO STDCALL LZ4_streamDecode:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD
LZ4_decompress_safe_forceExtDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZ4_decompress_safe_partial PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,targetOutputSize:DWORD,dstCapacity:DWORD
LZ4_decompress_safe_partial_forceExtDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZ4_decompress_safe_partial_usingDict PROTO STDCALL src:DWORD,dst:DWORD,compressedSize:DWORD,targetOutputSize:DWORD,maxOutputSize:DWORD,dictStart:DWORD,dictSize:DWORD
LZ4_decompress_safe_usingDict PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,dstCapacity:DWORD,dictStart:DWORD,dictSize:DWORD
LZ4_decompress_safe_withPrefix64k PROTO STDCALL src:DWORD,dst:DWORD,compressedSize:DWORD,maxDstSize:DWORD ; Obsolete use LZ4_decompress_safe_usingDict() instead
LZ4_favorDecompressionSpeed PROTO STDCALL LZ4_streamHCPtr:DWORD,favor:DWORD
LZ4_freeHC PROTO STDCALL LZ4HC_Data:DWORD ; Obsolete use LZ4_freeStreamHC() instead
LZ4_freeStream PROTO STDCALL streamPtr:DWORD
LZ4_freeStreamDecode PROTO STDCALL LZ4_stream:DWORD
LZ4_freeStreamHC PROTO STDCALL streamHCPtr:DWORD
LZ4_initStream PROTO STDCALL buffer:DWORD,dwsize:DWORD
LZ4_initStreamHC PROTO STDCALL buffer:DWORD,dwsize:DWORD
LZ4_loadDict PROTO STDCALL streamPtr:DWORD,dictionary:DWORD,dictSize:DWORD
LZ4_loadDictHC PROTO STDCALL streamHCPtr:DWORD,dictionary:DWORD,dictSize:DWORD
LZ4_resetStream PROTO STDCALL streamPtr:DWORD
LZ4_resetStreamHC PROTO STDCALL :DWORD,:DWORD
LZ4_resetStreamHC_fast PROTO STDCALL streamHCPtr:DWORD,compressionLevel:DWORD
LZ4_resetStreamState PROTO STDCALL state:DWORD,inputBuffer:DWORD ; Obsolete use LZ4_resetStream() instead
LZ4_resetStreamStateHC PROTO STDCALL state:DWORD,inputBuffer:DWORD ; Obsolete use LZ4_initStreamHC() instead
LZ4_resetStream_fast PROTO STDCALL streamPtr:DWORD
LZ4_saveDict PROTO STDCALL streamPtr:DWORD,safeBuffer:DWORD,maxDictSize:DWORD
LZ4_saveDictHC PROTO STDCALL :DWORD,:DWORD,:DWORD
LZ4_setCompressionLevel PROTO STDCALL LZ4_streamHCPtr:DWORD,compressionLevel:DWORD
LZ4_setStreamDecode PROTO STDCALL LZ4_streamDecode:DWORD,dictionary:DWORD,dictSize:DWORD
LZ4_sizeofState PROTO STDCALL 
LZ4_sizeofStateHC PROTO STDCALL 
LZ4_sizeofStreamState PROTO STDCALL ; Obsolete use LZ4_createStream() instead
LZ4_sizeofStreamStateHC PROTO STDCALL ; Obsolete use LZ4_createStreamHC() instead
LZ4_slideInputBuffer PROTO STDCALL state:DWORD ; Obsolete use LZ4_saveDict() instead
LZ4_slideInputBufferHC PROTO STDCALL LZ4HC_Data:DWORD ; Obsolete use LZ4_saveDictHC() instead
LZ4_uncompress PROTO STDCALL source:DWORD,dest:DWORD,outputSize:DWORD ; Obsolete use LZ4_decompress_fast() instead
LZ4_uncompress_unknownOutputSize PROTO STDCALL source:DWORD,dest:DWORD,isize:DWORD,maxOutputSize:DWORD ; Obsolete use LZ4_decompress_safe() instead
LZ4_versionNumber PROTO STDCALL 
LZ4_versionString PROTO STDCALL 
LZ4_XXH32 PROTO STDCALL input:DWORD,dwlength:DWORD,seed:DWORD
LZ4_XXH32_canonicalFromHash PROTO STDCALL dst:DWORD,hash:DWORD
LZ4_XXH32_copyState PROTO STDCALL dst_state:DWORD,src_state:DWORD
LZ4_XXH32_createState PROTO STDCALL 
LZ4_XXH32_digest PROTO STDCALL statePtr:DWORD
LZ4_XXH32_freeState PROTO STDCALL statePtr:DWORD
LZ4_XXH32_hashFromCanonical PROTO STDCALL src:DWORD
LZ4_XXH32_reset PROTO STDCALL statePtr:DWORD,seed:DWORD
LZ4_XXH32_update PROTO STDCALL statePtr:DWORD,input:DWORD,dwlength:DWORD
LZ4_XXH64 PROTO STDCALL input:DWORD,dwlength:DWORD,seed:QWORD
LZ4_XXH64_canonicalFromHash PROTO STDCALL dst:DWORD,hash:QWORD
LZ4_XXH64_copyState PROTO STDCALL dst_state:DWORD,src_state:DWORD
LZ4_XXH64_createState PROTO STDCALL 
LZ4_XXH64_digest PROTO STDCALL statePtr:DWORD
LZ4_XXH64_freeState PROTO STDCALL statePtr:DWORD
LZ4_XXH64_hashFromCanonical PROTO STDCALL src:DWORD
LZ4_XXH64_reset PROTO STDCALL statePtr:DWORD,seed:QWORD
LZ4_XXH64_update PROTO STDCALL statePtr:DWORD,input:DWORD,dwlength:DWORD
LZ4_XXH_versionNumber PROTO STDCALL 

;typedef struct {
;LZ4F_blockSizeID_t     blockSizeID;         /* max64KB, max256KB, max1MB, max4MB; 0 == default */
;LZ4F_blockMode_t       blockMode;           /* LZ4F_blockLinked, LZ4F_blockIndependent; 0 == default */
;LZ4F_contentChecksum_t contentChecksumFlag; /* 1: frame terminated with 32-bit checksum of decompressed data; 0: disabled (default) */
;LZ4F_frameType_t       frameType;           /* read-only field : LZ4F_frame or LZ4F_skippableFrame */
;unsigned long long     contentSize;         /* Size of uncompressed content ; 0 == unknown */
;unsigned               dictID;              /* Dictionary ID, sent by compressor to help decoder select correct dictionary; 0 == no dictID provided */
;LZ4F_blockChecksum_t   blockChecksumFlag;   /* 1: each block followed by a checksum of block's compressed data; 0: disabled (default) */
;} LZ4F_frameInfo_t;
;
;typedef struct {
;LZ4F_frameInfo_t frameInfo;
;int      compressionLevel;    /* 0: default (fast mode); values > LZ4HC_CLEVEL_MAX count as LZ4HC_CLEVEL_MAX; values < 0 trigger "fast acceleration" */
;unsigned autoFlush;           /* 1: always flush; reduces usage of internal buffers */
;unsigned favorDecSpeed;       /* 1: parser favors decompression speed vs compression ratio. Only works for high compression modes (>= LZ4HC_CLEVEL_OPT_MIN) */  /* v1.8.2+ */
;unsigned reserved[3];         /* must be zero for forward compatibility */
;} LZ4F_preferences_t;
;
;typedef struct {
;unsigned stableSrc;    /* 1 == src content will remain present on future calls to LZ4F_compress(); skip copying src content within tmp buffer */
;unsigned reserved[3];
;} LZ4F_compressOptions_t;
;
;typedef struct {
;unsigned stableDst;     /* pledges that last 64KB decompressed data is present right before @dstBuffer pointer.
;                       * This optimization skips internal storage operations.
;                       * Once set, this pledge must remain valid up to the end of current frame. */
;unsigned skipChecksums; /* disable checksum calculation and verification, even when one is present in frame, to save CPU time.
;                       * Setting this option to 1 once disables all checksums for the rest of the frame. */
;unsigned reserved1;     /* must be set to zero for forward compatibility */
;unsigned reserved0;     /* idem */
;} LZ4F_decompressOptions_t;
;
;struct LZ4HC_CCtx_internal
;{
;LZ4_u32   hashTable[LZ4HC_HASHTABLESIZE];
;LZ4_u16   chainTable[LZ4HC_MAXD];
;const LZ4_byte* end;       /* next block here to continue on current prefix */
;const LZ4_byte* prefixStart;  /* Indexes relative to this position */
;const LZ4_byte* dictStart; /* alternate reference for extDict */
;LZ4_u32   dictLimit;       /* below that point, need extDict */
;LZ4_u32   lowLimit;        /* below that point, no more dict */
;LZ4_u32   nextToUpdate;    /* index from which to continue dictionary update */
;short     compressionLevel;
;LZ4_i8    favorDecSpeed;   /* favor decompression speed if this flag set,
;                              otherwise, favor compression ratio */
;LZ4_i8    dirty;           /* stream has to be fully reset if this flag is set */
;const LZ4HC_CCtx_internal* dictCtx;
;};



.CONST

; Version
LZ4_VERSION_MAJOR               EQU 1    ; for breaking interface changes
LZ4_VERSION_MINOR               EQU 10   ; for new (non-breaking) interface capabilities
LZ4_VERSION_RELEASE             EQU 0    ; for tweaks, bug-fixes, or development

; Tuning parameter

LZ4_MEMORY_USAGE_MIN            EQU 10
LZ4_MEMORY_USAGE_DEFAULT        EQU 14
LZ4_MEMORY_USAGE_MAX            EQU 20

; Advanced Functions
LZ4_MAX_INPUT_SIZE              EQU 07E000000h   ; 2 113 929 216 bytes


LZ4_DISTANCE_MAX                EQU 65535
LZ4_COMPRESS_INPLACE_MARGIN     EQU (LZ4_DISTANCE_MAX + 32)
LZ4_STREAMDECODE_MINSIZE        EQU 32

; Frame compression types

; The larger the block size, the (slightly) better the compression ratio,
; though there are diminishing returns.
; Larger blocks also increase memory usage on both compression and decompression sides.

LZ4F_default                    EQU 0
LZ4F_max64KB                    EQU 4
LZ4F_max256KB                   EQU 5
LZ4F_max1MB                     EQU 6
LZ4F_max4MB                     EQU 7

LZ4F_blockLinked                EQU 0
LZ4F_blockIndependent           EQU 1

LZ4F_noContentChecksum          EQU 0
LZ4F_contentChecksumEnabled     EQU 1

LZ4F_noBlockChecksum            EQU 0
LZ4F_blockChecksumEnabled       EQU 1

LZ4F_frame                      EQU 0
LZ4F_skippableFrame             EQU 1

; Compression

LZ4F_HEADER_SIZE_MIN            EQU 7   ; LZ4 Frame header size can vary, depending on selected parameters
LZ4F_HEADER_SIZE_MAX            EQU 19

; Size in bytes of a block header in little-endian format. Highest bit indicates if block data is uncompressed 
LZ4F_BLOCK_HEADER_SIZE          EQU 4

; Size in bytes of a block checksum footer in little-endian format.
LZ4F_BLOCK_CHECKSUM_SIZE        EQU 4

; Size in bytes of the content checksum.
LZ4F_CONTENT_CHECKSUM_SIZE      EQU 4

LZ4F_MAGICNUMBER                EQU 0184D2204h
LZ4F_MAGIC_SKIPPABLE_START      EQU 0184D2A50h
LZ4F_MIN_SIZE_TO_KNOW_HEADER_LENGTH EQU 5

LZ4HC_CLEVEL_MIN                EQU 3
LZ4HC_CLEVEL_DEFAULT            EQU 9
LZ4HC_CLEVEL_OPT_MIN            EQU 10
LZ4HC_CLEVEL_MAX                EQU 12

LZ4HC_DICTIONARY_LOGSIZE        EQU 16
LZ4HC_MAXD                      EQU (1 SHL LZ4HC_DICTIONARY_LOGSIZE)
LZ4HC_MAXD_MASK                 EQU (LZ4HC_MAXD - 1)

LZ4HC_HASH_LOG                  EQU 15
LZ4HC_HASHTABLESIZE             EQU (1 SHL LZ4HC_HASH_LOG)
LZ4HC_HASH_MASK                 EQU (LZ4HC_HASHTABLESIZE - 1)

XXH_OK                          EQU 0
XXH_ERROR                       EQU 1

XXH_VERSION_MAJOR               EQU 0
XXH_VERSION_MINOR               EQU 6
XXH_VERSION_RELEASE             EQU 5