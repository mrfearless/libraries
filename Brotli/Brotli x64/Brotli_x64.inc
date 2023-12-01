;/* Copyright 2016 Google Inc. All Rights Reserved.
;   Distributed under MIT license.
;*/

; https://github.com/google/brotli

; Brotli_x64.inc converted from Brotli source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

BrotliAllocate                  PROTO :QWORD,:QWORD
BrotliBootstrapAlloc            PROTO :QWORD,:QWORD,:QWORD,:QWORD
BrotliBootstrapFree             PROTO :QWORD,:QWORD
BrotliDecoderAttachDictionary   PROTO state:QWORD,qwtype:QWORD,data_size:QWORD,data:QWORD
BrotliDecoderCreateInstance     PROTO alloc_func:QWORD,free_func:QWORD,opaque:QWORD
BrotliDecoderDecompress         PROTO encoded_size:QWORD,encoded_buffer:QWORD,decoded_size:QWORD,decoded_buffer:QWORD
BrotliDecoderDecompressStream   PROTO state:QWORD,available_in:QWORD,next_in:QWORD,available_out:QWORD,next_out:QWORD,total_out:QWORD
BrotliDecoderDestroyInstance    PROTO state:QWORD
BrotliDecoderErrorString        PROTO cstring:QWORD
BrotliDecoderGetErrorCode       PROTO state:QWORD
BrotliDecoderHasMoreOutput      PROTO state:QWORD
BrotliDecoderIsFinished         PROTO state:QWORD
BrotliDecoderIsUsed             PROTO state:QWORD
BrotliDecoderSetMetadataCallbacks PROTO state:QWORD,start_func:QWORD,chunk_func:QWORD,opaque:QWORD
BrotliDecoderSetParameter       PROTO state:QWORD,param:QWORD,qwvalue:QWORD
BrotliDecoderTakeOutput         PROTO state:QWORD,qwsize:QWORD
BrotliDecoderVersion            PROTO 
BrotliDefaultAllocFunc          PROTO :QWORD,:QWORD
BrotliDefaultFreeFunc           PROTO :QWORD,:QWORD
BrotliEncoderAttachPreparedDictionary PROTO state:QWORD,dictionary:QWORD
BrotliEncoderCompress           PROTO quality:QWORD,lgwin:QWORD,mode:QWORD,input_size:QWORD,input_buffer:QWORD,encoded_size:QWORD,encoded_buffer:QWORD
BrotliEncoderCompressStream     PROTO state:QWORD,op:QWORD,available_in:QWORD,next_in:QWORD,available_out:QWORD,next_out:QWORD,total_out:QWORD
BrotliEncoderCreateInstance     PROTO alloc_func:QWORD,free_func:QWORD,opaque:QWORD
BrotliEncoderDestroyInstance    PROTO state:QWORD
BrotliEncoderDestroyPreparedDictionary PROTO dictionary:QWORD
BrotliEncoderEstimatePeakMemoryUsage PROTO quality:QWORD,lgwin:QWORD,input_size:QWORD
BrotliEncoderGetPreparedDictionarySize PROTO dictionary:QWORD
BrotliEncoderHasMoreOutput      PROTO state:QWORD
BrotliEncoderIsFinished         PROTO state:QWORD
BrotliEncoderMaxCompressedSize  PROTO input_size:QWORD
BrotliEncoderPrepareDictionary  PROTO qwtype:QWORD,data_size:QWORD,data:QWORD,quality:QWORD,alloc_func:QWORD,free_func:QWORD,opaque:QWORD
BrotliEncoderSetParameter       PROTO state:QWORD,param:QWORD,qwvalue:QWORD
BrotliEncoderTakeOutput         PROTO state:QWORD,qwsize:QWORD
BrotliEncoderVersion            PROTO 
BrotliFree                      PROTO :QWORD,:QWORD
BrotliInitMemoryManager         PROTO :QWORD,:QWORD,:QWORD,:QWORD
BrotliWipeOutMemoryManager      PROTO :QWORD

.CONST
BROTLI_VERSION_MAJOR            EQU 1
BROTLI_VERSION_MINOR            EQU 1
BROTLI_VERSION_PATCH            EQU 0

BROTLI_ABI_CURRENT              EQU 2
BROTLI_ABI_REVISION             EQU 0
BROTLI_ABI_AGE                  EQU 1

BROTLI_BOOL                     TYPEDEF QWORD
BROTLI_TRUE                     EQU 1
BROTLI_FALSE                    EQU 0

; Options for ::BROTLI_PARAM_MODE parameter.
BrotliEncoderMode               TYPEDEF QWORD
BROTLI_MODE_GENERIC             EQU 0 ; Default compression mode.
BROTLI_MODE_TEXT                EQU 1 ; Compression mode for UTF-8 formatted text input.
BROTLI_MODE_FONT                EQU 2 ; Compression mode used in WOFF 2.0.

BROTLI_MIN_WINDOW_BITS          EQU 10 ; Minimal value for ::BROTLI_PARAM_LGWIN parameter.
BROTLI_MAX_WINDOW_BITS          EQU 24 ; Maximal value for ::BROTLI_PARAM_LGWIN parameter.
BROTLI_LARGE_MAX_WINDOW_BITS    EQU 30 ; Maximal value for ::BROTLI_PARAM_LGWIN parameter in "Large Window Brotli" (32-bit).
BROTLI_MIN_INPUT_BLOCK_BITS     EQU 16 ; Minimal value for ::BROTLI_PARAM_LGBLOCK parameter.
BROTLI_MAX_INPUT_BLOCK_BITS     EQU 24 ; Maximal value for ::BROTLI_PARAM_LGBLOCK parameter.
BROTLI_MIN_QUALITY              EQU 0  ; Minimal value for ::BROTLI_PARAM_QUALITY parameter.
BROTLI_MAX_QUALITY              EQU 11 ; Maximal value for ::BROTLI_PARAM_QUALITY parameter.

BROTLI_DEFAULT_QUALITY          EQU 11
BROTLI_DEFAULT_WINDOW           EQU 22
BROTLI_DEFAULT_MODE             EQU BROTLI_MODE_GENERIC

; Operations that can be performed by streaming encoder.
BrotliEncoderOperation          TYPEDEF QWORD
BROTLI_OPERATION_PROCESS        EQU 0 ; Process input.
BROTLI_OPERATION_FLUSH          EQU 1 ; Produce output for all processed input.
BROTLI_OPERATION_FINISH         EQU 2 ; Finalize the stream.
BROTLI_OPERATION_EMIT_METADATA  EQU 3 ; Emit metadata block to stream.

; Options to be used with ::BrotliEncoderSetParameter.
BrotliEncoderParameter          TYPEDEF QWORD
BROTLI_PARAM_MODE               EQU 0 ; Tune encoder for specific input.
BROTLI_PARAM_QUALITY            EQU 1 ; The main compression speed-density lever.
BROTLI_PARAM_LGWIN              EQU 2 ; Recommended sliding LZ77 window size.
BROTLI_PARAM_LGBLOCK            EQU 3 ; Recommended input block size.
BROTLI_PARAM_DISABLE_LITERAL_CONTEXT_MODELING EQU 4 ; Flag that affects usage of "literal context modeling" format feature.
BROTLI_PARAM_SIZE_HINT          EQU 5 ; Estimated total input size for all ::BrotliEncoderCompressStream calls.
BROTLI_PARAM_LARGE_WINDOW       EQU 6 ; Flag that determines if "Large Window Brotli" is used.
BROTLI_PARAM_NPOSTFIX           EQU 7 ; Recommended number of postfix bits (NPOSTFIX).
BROTLI_PARAM_NDIRECT            EQU 8 ; Recommended number of direct distance codes (NDIRECT).
BROTLI_PARAM_STREAM_OFFSET      EQU 9 ; Number of bytes of input stream already processed by a different instance.

; Result type for ::BrotliDecoderDecompress and ::BrotliDecoderDecompressStream functions.
BROTLI_DECODER_RESULT_ERROR     EQU 0 ; Decoding error, e.g. corrupted input or memory allocation problem.
BROTLI_DECODER_RESULT_SUCCESS   EQU 1 ; Decoding successfully completed.
BROTLI_DECODER_RESULT_NEEDS_MORE_INPUT EQU 2 ; Partially done; should be called again with more input.
BROTLI_DECODER_RESULT_NEEDS_MORE_OUTPUT EQU 3 ; Partially done; should be called again with more output.

; Options to be used with ::BrotliDecoderSetParameter. */
BrotliDecoderParameter          TYPEDEF QWORD
BROTLI_DECODER_PARAM_DISABLE_RING_BUFFER_REALLOCATION EQU 0 ; Disable "canny" ring buffer allocation strategy.
BROTLI_DECODER_PARAM_LARGE_WINDOW EQU 1 ; Flag that determines if "Large Window Brotli" is used.









