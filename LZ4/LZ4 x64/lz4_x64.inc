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

; lz4_x64.inc converted from LZ4 source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

LZ4F_compressBegin PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,prefsPtr:QWORD
LZ4F_compressBegin_usingCDict PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,cdict:QWORD,prefsPtr:QWORD
LZ4F_compressBound PROTO srcSize:QWORD,prefsPtr:QWORD
LZ4F_compressEnd PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,cOptPtr:QWORD
LZ4F_compressFrame PROTO dstBuffer:QWORD,dstCapacity:QWORD,srcBuffer:QWORD,srcSize:QWORD,preferencesPtr:QWORD
LZ4F_compressFrameBound PROTO srcSize:QWORD,preferencesPtr:QWORD
LZ4F_compressFrame_usingCDict PROTO cctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,cdict:QWORD,preferencesPtr:QWORD
LZ4F_compressUpdate PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,srcBuffer:QWORD,srcSize:QWORD,cOptPtr:QWORD
LZ4F_compressionLevel_max PROTO 
LZ4F_createCDict PROTO dictBuffer:QWORD,dictSize:QWORD
LZ4F_createCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LZ4F_createCompressionContext PROTO cctxPtr:QWORD,version:QWORD
LZ4F_createCompressionContext_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LZ4F_createDecompressionContext PROTO :QWORD,:QWORD
LZ4F_createDecompressionContext_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LZ4F_decompress PROTO dctx:QWORD,dstBuffer:QWORD,dstSizePtr:QWORD,srcBuffer:QWORD,srcSizePtr:QWORD,dOptPtr:QWORD
LZ4F_decompress_usingDict PROTO dctxPtr:QWORD,dstBuffer:QWORD,dstSizePtr:QWORD,srcBuffer:QWORD,srcSizePtr:QWORD,dict:QWORD,dictSize:QWORD,decompressOptionsPtr:QWORD
LZ4F_flush PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,cOptPtr:QWORD
LZ4F_freeCDict PROTO CDict:QWORD
LZ4F_freeCompressionContext PROTO cctx:QWORD
LZ4F_freeDecompressionContext PROTO :QWORD
LZ4F_getBlockSize PROTO blockSizeID:QWORD
LZ4F_getErrorCode PROTO :QWORD
LZ4F_getErrorName PROTO LZ4F_errorCode:QWORD
LZ4F_getFrameInfo PROTO dctx:QWORD,frameInfoPtr:QWORD,srcBuffer:QWORD,srcSizePtr:QWORD
LZ4F_getVersion PROTO 
LZ4F_headerSize PROTO src:QWORD,srcSize:QWORD
LZ4F_isError PROTO LZ4F_errorCode:QWORD
LZ4F_resetDecompressionContext PROTO dctx:QWORD
LZ4F_uncompressedUpdate PROTO cctx:QWORD,dstBuffer:QWORD,dstCapacity:QWORD,srcBuffer:QWORD,srcSize:QWORD,cOptPtr:QWORD
LZ4_attach_HC_dictionary PROTO working_stream:QWORD,dictionary_stream:QWORD
LZ4_attach_dictionary PROTO workingStream:QWORD,dictionaryStream:QWORD
LZ4_compress PROTO src:QWORD,dest:QWORD,srcSize:QWORD ; Obsolete, use LZ4_compress_default() instead
LZ4_compressBound PROTO inputSize:QWORD
LZ4_compressHC2 PROTO source:QWORD,dest:QWORD,inputSize:QWORD,compressionLevel:QWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC2_continue PROTO LZ4HC_Data:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,compressionLevel:QWORD ; Obsolete use LZ4_compress_HC_continue() instead
LZ4_compressHC2_limitedOutput PROTO source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD,compressionLevel:QWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC2_limitedOutput_continue PROTO LZ4HC_Data:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD,compressionLevel:QWORD ; Obsolete use LZ4_compress_HC_continue() instead
LZ4_compressHC2_limitedOutput_withStateHC PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD,compressionLevel:QWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC2_withStateHC PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,compressionLevel:QWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC PROTO source:QWORD,dest:QWORD,inputSize:QWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC_continue PROTO LZ4_streamHCPtr:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD ; deprecated use LZ4_compress_HC_continue() instead
LZ4_compressHC_limitedOutput PROTO source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD ; deprecated use LZ4_compress_HC() instead
LZ4_compressHC_limitedOutput_continue PROTO LZ4_streamHCPtr:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD ; deprecated use LZ4_compress_HC_continue() instead
LZ4_compressHC_limitedOutput_withStateHC PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compressHC_withStateHC PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD ; deprecated use LZ4_compress_HC_extStateHC() instead
LZ4_compress_HC PROTO src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,compressionLevel:QWORD
LZ4_compress_HC_continue PROTO streamHCPtr:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,maxDstSize:QWORD
LZ4_compress_HC_continue_destSize PROTO LZ4_streamHCPtr:QWORD,src:QWORD,dst:QWORD,srcSizePtr:QWORD,targetDstSize:QWORD
LZ4_compress_HC_destSize PROTO stateHC:QWORD,src:QWORD,dst:QWORD,srcSizePtr:QWORD,targetDstSize:QWORD,compressionLevel:QWORD
LZ4_compress_HC_extStateHC PROTO stateHC:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,maxDstSize:QWORD,compressionLevel:QWORD
LZ4_compress_HC_extStateHC_fastReset PROTO state:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,compressionLevel:QWORD
LZ4_compress_continue PROTO LZ4_streamPtr:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD ; Obsolete use LZ4_compress_fast_continue() instead
LZ4_compress_default PROTO src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD
LZ4_compress_destSize PROTO src:QWORD,dst:QWORD,srcSizePtr:QWORD,targetDstSize:QWORD
LZ4_compress_fast PROTO src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,acceleration:QWORD
LZ4_compress_fast_continue PROTO streamPtr:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,acceleration:QWORD
LZ4_compress_fast_extState PROTO state:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,acceleration:QWORD
LZ4_compress_fast_extState_fastReset PROTO state:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,acceleration:QWORD
LZ4_compress_forceExtDict PROTO :QWORD,:QWORD,:QWORD,:QWORD
LZ4_compress_limitedOutput PROTO src:QWORD,dest:QWORD,srcSize:QWORD,maxOutputSize:QWORD ; Obsolete use LZ4_compress_default() instead
LZ4_compress_limitedOutput_continue PROTO LZ4_streamPtr:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD ; Obsolete use LZ4_compress_fast_continue() instead
LZ4_compress_limitedOutput_withState PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxOutputSize:QWORD ; Obsolete use LZ4_compress_fast_extState() instead
LZ4_compress_withState PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD ; Obsolete use LZ4_compress_fast_extState() instead
LZ4_create PROTO inputBuffer:QWORD ; Obsolete Use LZ4_createStream() instead
LZ4_createHC PROTO inputBuffer:QWORD ; Obsolete use LZ4_createStreamHC() instead
LZ4_createStream PROTO 
LZ4_createStreamDecode PROTO 
LZ4_createStreamHC PROTO 
LZ4_decoderRingBufferSize PROTO maxBlockSize:QWORD
LZ4_decompress_fast PROTO src:QWORD,dst:QWORD,originalSize:QWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe() instead
LZ4_decompress_fast_continue PROTO LZ4_streamDecode:QWORD,src:QWORD,dst:QWORD,originalSize:QWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe_continue() instead
LZ4_decompress_fast_usingDict PROTO src:QWORD,dst:QWORD,originalSize:QWORD,dictStart:QWORD,dictSize:QWORD ; This function is deprecated and unsafe. Consider using LZ4_decompress_safe_usingDict() instead
LZ4_decompress_fast_withPrefix64k PROTO src:QWORD,dst:QWORD,originalSize:QWORD ; Obsolete use LZ4_decompress_fast_usingDict() instead
LZ4_decompress_safe PROTO src:QWORD,dst:QWORD,compressedSize:QWORD,dstCapacity:QWORD
LZ4_decompress_safe_continue PROTO LZ4_streamDecode:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD
LZ4_decompress_safe_forceExtDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LZ4_decompress_safe_partial PROTO src:QWORD,dst:QWORD,srcSize:QWORD,targetOutputSize:QWORD,dstCapacity:QWORD
LZ4_decompress_safe_partial_forceExtDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LZ4_decompress_safe_partial_usingDict PROTO src:QWORD,dst:QWORD,compressedSize:QWORD,targetOutputSize:QWORD,maxOutputSize:QWORD,dictStart:QWORD,dictSize:QWORD
LZ4_decompress_safe_usingDict PROTO src:QWORD,dst:QWORD,srcSize:QWORD,dstCapacity:QWORD,dictStart:QWORD,dictSize:QWORD
LZ4_decompress_safe_withPrefix64k PROTO src:QWORD,dst:QWORD,compressedSize:QWORD,maxDstSize:QWORD ; Obsolete use LZ4_decompress_safe_usingDict() instead
LZ4_favorDecompressionSpeed PROTO LZ4_streamHCPtr:QWORD,favor:QWORD
LZ4_freeHC PROTO LZ4HC_Data:QWORD ; Obsolete use LZ4_freeStreamHC() instead
LZ4_freeStream PROTO streamPtr:QWORD
LZ4_freeStreamDecode PROTO LZ4_stream:QWORD
LZ4_freeStreamHC PROTO streamHCPtr:QWORD
LZ4_initStream PROTO buffer:QWORD,dwsize:QWORD
LZ4_initStreamHC PROTO buffer:QWORD,dwsize:QWORD
LZ4_loadDict PROTO streamPtr:QWORD,dictionary:QWORD,dictSize:QWORD
LZ4_loadDictHC PROTO streamHCPtr:QWORD,dictionary:QWORD,dictSize:QWORD
LZ4_resetStream PROTO streamPtr:QWORD
LZ4_resetStreamHC PROTO :QWORD,:QWORD
LZ4_resetStreamHC_fast PROTO streamHCPtr:QWORD,compressionLevel:QWORD
LZ4_resetStreamState PROTO state:QWORD,inputBuffer:QWORD ; Obsolete use LZ4_resetStream() instead
LZ4_resetStreamStateHC PROTO state:QWORD,inputBuffer:QWORD ; Obsolete use LZ4_initStreamHC() instead
LZ4_resetStream_fast PROTO streamPtr:QWORD
LZ4_saveDict PROTO streamPtr:QWORD,safeBuffer:QWORD,maxDictSize:QWORD
LZ4_saveDictHC PROTO :QWORD,:QWORD,:QWORD
LZ4_setCompressionLevel PROTO LZ4_streamHCPtr:QWORD,compressionLevel:QWORD
LZ4_setStreamDecode PROTO LZ4_streamDecode:QWORD,dictionary:QWORD,dictSize:QWORD
LZ4_sizeofState PROTO 
LZ4_sizeofStateHC PROTO 
LZ4_sizeofStreamState PROTO ; Obsolete use LZ4_createStream() instead
LZ4_sizeofStreamStateHC PROTO ; Obsolete use LZ4_createStreamHC() instead
LZ4_slideInputBuffer PROTO state:QWORD ; Obsolete use LZ4_saveDict() instead
LZ4_slideInputBufferHC PROTO LZ4HC_Data:QWORD ; Obsolete use LZ4_saveDictHC() instead
LZ4_uncompress PROTO source:QWORD,dest:QWORD,outputSize:QWORD ; Obsolete use LZ4_decompress_fast() instead
LZ4_uncompress_unknownOutputSize PROTO source:QWORD,dest:QWORD,isize:QWORD,maxOutputSize:QWORD ; Obsolete use LZ4_decompress_safe() instead
LZ4_versionNumber PROTO 
LZ4_versionString PROTO 
XXH32 PROTO input:QWORD,qwlength:QWORD,seed:QWORD
XXH32_canonicalFromHash PROTO dst:QWORD,hash:QWORD
XXH32_copyState PROTO dst_state:QWORD,src_state:QWORD
XXH32_createState PROTO 
XXH32_digest PROTO statePtr:QWORD
XXH32_freeState PROTO statePtr:QWORD
XXH32_hashFromCanonical PROTO src:QWORD
XXH32_reset PROTO statePtr:QWORD,seed:QWORD
XXH32_update PROTO statePtr:QWORD,input:QWORD,qwlength:QWORD
XXH64 PROTO input:QWORD,qwlength:QWORD,seed:QWORD
XXH64_canonicalFromHash PROTO dst:QWORD,hash:QWORD
XXH64_copyState PROTO dst_state:QWORD,src_state:QWORD
XXH64_createState PROTO 
XXH64_digest PROTO statePtr:QWORD
XXH64_freeState PROTO statePtr:QWORD
XXH64_hashFromCanonical PROTO src:QWORD
XXH64_reset PROTO statePtr:QWORD,seed:QWORD
XXH64_update PROTO statePtr:QWORD,input:QWORD,qwlength:QWORD
XXH_versionNumber PROTO 

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
LZ4_VERSION_MINOR               EQU 9    ; for new (non-breaking) interface capabilities
LZ4_VERSION_RELEASE             EQU 5    ; for tweaks, bug-fixes, or development

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