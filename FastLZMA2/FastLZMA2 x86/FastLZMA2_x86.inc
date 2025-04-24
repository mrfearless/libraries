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

; FastLZMA2_x86.inc converted from Fast-LZMA2 source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib


FL2_CCtx_getParameter   PROTO STDCALL :DWORD,:DWORD
FL2_CCtx_setParameter   PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_CStream_getParameter PROTO STDCALL :DWORD,:DWORD
FL2_CStream_setParameter PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_cancelCStream       PROTO STDCALL :DWORD
FL2_cancelDStream       PROTO STDCALL :DWORD
FL2_checkNbThreads      PROTO STDCALL :DWORD
FL2_compress            PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,compressionLevel:DWORD
FL2_compressBound       PROTO STDCALL srcSize:DWORD
FL2_compressCCtx        PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FL2_compressMt          PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,compressionLevel:DWORD,nbThreads:DWORD
FL2_compressStream      PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_copyCStreamOutput   PROTO STDCALL :DWORD,:DWORD
FL2_createCCtx          PROTO STDCALL 
FL2_createCCtxMt        PROTO STDCALL :DWORD
FL2_createCStream       PROTO STDCALL 
FL2_createCStreamMt     PROTO STDCALL :DWORD,:DWORD
FL2_createDCtx          PROTO STDCALL 
FL2_createDCtxMt        PROTO STDCALL :DWORD
FL2_createDStream       PROTO STDCALL 
FL2_createDStreamMt     PROTO STDCALL :DWORD
FL2_decompress          PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,compressedSize:DWORD
FL2_decompressDCtx      PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FL2_decompressMt        PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,compressedSize:DWORD,nbThreads:DWORD
FL2_decompressStream    PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_endStream           PROTO STDCALL :DWORD,:DWORD
FL2_estimateCCtxSize    PROTO STDCALL :DWORD,:DWORD
FL2_estimateCCtxSize_byParams PROTO STDCALL :DWORD,:DWORD
FL2_estimateCCtxSize_usingCCtx PROTO STDCALL :DWORD
FL2_estimateCStreamSize PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_estimateCStreamSize_byParams PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_estimateCStreamSize_usingCStream PROTO STDCALL :DWORD
FL2_estimateDCtxSize    PROTO STDCALL :DWORD
FL2_estimateDStreamSize PROTO STDCALL :DWORD,:DWORD
FL2_findDecompressedSize PROTO STDCALL src:DWORD,srcSize:DWORD
FL2_flushStream         PROTO STDCALL :DWORD,:DWORD
FL2_freeCCtx            PROTO STDCALL :DWORD
FL2_freeCStream         PROTO STDCALL :DWORD
FL2_freeDCtx            PROTO STDCALL :DWORD
FL2_freeDStream         PROTO STDCALL :DWORD
FL2_getCCtxDictProp     PROTO STDCALL :DWORD
FL2_getCCtxThreadCount  PROTO STDCALL :DWORD
FL2_getCStreamProgress  PROTO STDCALL :DWORD,:DWORD
FL2_getDCtxThreadCount  PROTO STDCALL :DWORD
FL2_getDStreamProgress  PROTO STDCALL :DWORD
FL2_getDictSizeFromProp PROTO STDCALL :DWORD
FL2_getDictionaryBuffer PROTO STDCALL :DWORD,:DWORD
FL2_getErrorCode        PROTO STDCALL functionResult:DWORD
FL2_getErrorName        PROTO STDCALL errorcode:DWORD
FL2_getErrorString      PROTO STDCALL errorcode:DWORD
FL2_getLevelParameters  PROTO STDCALL :DWORD,:DWORD,:DWORD
FL2_getNextCompressedBuffer PROTO STDCALL :DWORD,:DWORD
FL2_initCStream         PROTO STDCALL :DWORD,:DWORD
FL2_initDCtx            PROTO STDCALL :DWORD,:DWORD
FL2_initDStream         PROTO STDCALL :DWORD
FL2_initDStream_withProp PROTO STDCALL :DWORD,:DWORD
FL2_isError             PROTO STDCALL errorcode:DWORD
FL2_isTimedOut          PROTO STDCALL errorcode:DWORD
FL2_maxCLevel           PROTO STDCALL 
FL2_maxHighCLevel       PROTO STDCALL 
FL2_pthread_create      PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FL2_pthread_join        PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FL2_remainingOutputSize PROTO STDCALL :DWORD
FL2_setCStreamTimeout   PROTO STDCALL :DWORD,:DWORD
FL2_setDStreamMemoryLimitMt PROTO STDCALL :DWORD,:DWORD
FL2_setDStreamTimeout   PROTO STDCALL :DWORD,:DWORD
FL2_updateDictionary    PROTO STDCALL :DWORD,:DWORD
FL2_versionNumber       PROTO STDCALL 
FL2_versionString       PROTO STDCALL 
FL2_waitCStream         PROTO STDCALL :DWORD
FL2_waitDStream         PROTO STDCALL :DWORD


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






