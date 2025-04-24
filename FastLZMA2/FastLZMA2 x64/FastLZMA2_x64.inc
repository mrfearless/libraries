;/*
; * Copyright (c) 2017-present, Conor McCarthy
; * All rights reserved.
; * Based on zstd.h copyright Yann Collet
; *
; * This source code is licensed under both the BSD-style license (found in the
; * LICENSE file in the root directory of this source tree) and the GPLv2 (found
; * in the COPYING file in the root directory of this source tree).
; * You may select, at your option, one of the above-listed licenses.
;*/

; https://github.com/conor42/fast-lzma2

; FastLZMA2_x64.inc converted from Fast-LZMA2 source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib


FL2_CCtx_getParameter   PROTO :QWORD,:QWORD
FL2_CCtx_setParameter   PROTO :QWORD,:QWORD,:QWORD
FL2_CStream_getParameter PROTO :QWORD,:QWORD
FL2_CStream_setParameter PROTO :QWORD,:QWORD,:QWORD
FL2_cancelCStream       PROTO :QWORD
FL2_cancelDStream       PROTO :QWORD
FL2_checkNbThreads      PROTO :QWORD
FL2_compress            PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,compressionLevel:QWORD
FL2_compressBound       PROTO srcSize:QWORD
FL2_compressCCtx        PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FL2_compressMt          PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,compressionLevel:QWORD,nbThreads:QWORD
FL2_compressStream      PROTO :QWORD,:QWORD,:QWORD
FL2_copyCStreamOutput   PROTO :QWORD,:QWORD
FL2_createCCtx          PROTO 
FL2_createCCtxMt        PROTO :QWORD
FL2_createCStream       PROTO 
FL2_createCStreamMt     PROTO :QWORD,:QWORD
FL2_createDCtx          PROTO 
FL2_createDCtxMt        PROTO :QWORD
FL2_createDStream       PROTO 
FL2_createDStreamMt     PROTO :QWORD
FL2_decompress          PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,compressedSize:QWORD
FL2_decompressDCtx      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FL2_decompressMt        PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,compressedSize:QWORD,nbThreads:QWORD
FL2_decompressStream    PROTO :QWORD,:QWORD,:QWORD
FL2_endStream           PROTO :QWORD,:QWORD
FL2_estimateCCtxSize    PROTO :QWORD,:QWORD
FL2_estimateCCtxSize_byParams PROTO :QWORD,:QWORD
FL2_estimateCCtxSize_usingCCtx PROTO :QWORD
FL2_estimateCStreamSize PROTO :QWORD,:QWORD,:QWORD
FL2_estimateCStreamSize_byParams PROTO :QWORD,:QWORD,:QWORD
FL2_estimateCStreamSize_usingCStream PROTO :QWORD
FL2_estimateDCtxSize    PROTO :QWORD
FL2_estimateDStreamSize PROTO :QWORD,:QWORD
FL2_findDecompressedSize PROTO src:QWORD,srcSize:QWORD
FL2_flushStream         PROTO :QWORD,:QWORD
FL2_freeCCtx            PROTO :QWORD
FL2_freeCStream         PROTO :QWORD
FL2_freeDCtx            PROTO :QWORD
FL2_freeDStream         PROTO :QWORD
FL2_getCCtxDictProp     PROTO :QWORD
FL2_getCCtxThreadCount  PROTO :QWORD
FL2_getCStreamProgress  PROTO :QWORD,:QWORD
FL2_getDCtxThreadCount  PROTO :QWORD
FL2_getDStreamProgress  PROTO :QWORD
FL2_getDictSizeFromProp PROTO :QWORD
FL2_getDictionaryBuffer PROTO :QWORD,:QWORD
FL2_getErrorCode        PROTO functionResult:QWORD
FL2_getErrorName        PROTO errorcode:QWORD
FL2_getErrorString      PROTO errorcode:QWORD
FL2_getLevelParameters  PROTO :QWORD,:QWORD,:QWORD
FL2_getNextCompressedBuffer PROTO :QWORD,:QWORD
FL2_initCStream         PROTO :QWORD,:QWORD
FL2_initDCtx            PROTO :QWORD,:QWORD
FL2_initDStream         PROTO :QWORD
FL2_initDStream_withProp PROTO :QWORD,:QWORD
FL2_isError             PROTO errorcode:QWORD
FL2_isTimedOut          PROTO errorcode:QWORD
FL2_maxCLevel           PROTO 
FL2_maxHighCLevel       PROTO 
FL2_pthread_create      PROTO :QWORD,:QWORD,:QWORD,:QWORD
FL2_pthread_join        PROTO :QWORD,:QWORD,:QWORD,:QWORD
FL2_remainingOutputSize PROTO :QWORD
FL2_setCStreamTimeout   PROTO :QWORD,:QWORD
FL2_setDStreamMemoryLimitMt PROTO :QWORD,:QWORD
FL2_setDStreamTimeout   PROTO :QWORD,:QWORD
FL2_updateDictionary    PROTO :QWORD,:QWORD
FL2_versionNumber       PROTO 
FL2_versionString       PROTO 
FL2_waitCStream         PROTO :QWORD
FL2_waitDStream         PROTO :QWORD


.CONST
; Version
FL2_VERSION_MAJOR               EQU 1
FL2_VERSION_MINOR               EQU 0
FL2_VERSION_RELEASE             EQU 1
FL2_VERSION_NUMBER              EQU (FL2_VERSION_MAJOR *100*100 + FL2_VERSION_MINOR *100 + FL2_VERSION_RELEASE)

FL2_MAXTHREADS                  EQU 200

; Pre-defined compression levels
FL2_MAX_HIGH_CLEVEL             EQU 10      
FL2_CLEVEL_DEFAULT              EQU 5
FL2_MAX_CLEVEL                  EQU 9

; Error codes list
FL2_error_no_error              EQU 0
FL2_error_GENERIC               EQU 1
FL2_error_internal              EQU 2
FL2_error_corruption_detected   EQU 3
FL2_error_checksum_wrong        EQU 4
FL2_error_parameter_unsupported EQU 5
FL2_error_parameter_outOfBound  EQU 6
FL2_error_lclpMax_exceeded      EQU 7
FL2_error_stage_wrong           EQU 8
FL2_error_init_missing          EQU 9
FL2_error_memory_allocation     EQU 10
FL2_error_dstSize_tooSmall      EQU 11
FL2_error_srcSize_wrong         EQU 12
FL2_error_canceled              EQU 13
FL2_error_buffer                EQU 14
FL2_error_timedOut              EQU 15
FL2_error_maxCode               EQU 20
FL2_ErrorCode                   TYPEDEF DWORD






