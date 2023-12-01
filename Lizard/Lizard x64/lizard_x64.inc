;/*
;    Lizard - Fast LZ compression algorithm 
;    Copyright (C) 2011-2015, Yann Collet
;    Copyright (C) 2016-2017, Przemyslaw Skibinski <inikep@gmail.com>
;
;    BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)
;
;    Redistribution and use in source and binary forms, with or without
;    modification, are permitted provided that the following conditions are
;    met:
;
;    * Redistributions of source code must retain the above copyright
;    notice, this list of conditions and the following disclaimer.
;    * Redistributions in binary form must reproduce the above
;    copyright notice, this list of conditions and the following disclaimer
;    in the documentation and/or other materials provided with the
;    distribution.
;
;    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;    A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;    OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;    You can contact the author at :
;       - Lizard source repository : https://github.com/inikep/lizard
;*/

; lizard_x64.inc converted from lizard source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

LizardF_compressBegin               PROTO cctx:QWORD,dstBuffer:QWORD,dstMaxSize:QWORD,prefsPtr:QWORD
LizardF_compressBound               PROTO srcSize:QWORD,prefsPtr:QWORD
LizardF_compressEnd                 PROTO cctx:QWORD,dstBuffer:QWORD,dstMaxSize:QWORD,cOptPtr:QWORD
LizardF_compressFrame               PROTO dstBuffer:QWORD,dstMaxSize:QWORD,srcBuffer:QWORD,srcSize:QWORD,preferencesPtr:QWORD
LizardF_compressFrameBound          PROTO srcSize:QWORD,preferencesPtr:QWORD
LizardF_compressUpdate              PROTO cctx:QWORD,dstBuffer:QWORD,dstMaxSize:QWORD,srcBuffer:QWORD,srcSize:QWORD,cOptPtr:QWORD
LizardF_createCompressionContext    PROTO cctxPtr:QWORD,version:QWORD
LizardF_createDecompressionContext  PROTO dctxPtr:QWORD,version:QWORD
LizardF_decompress                  PROTO dctx:QWORD,dstBuffer:QWORD,dstSizePtr:QWORD,srcBuffer:QWORD,srcSizePtr:QWORD,dOptPtr:QWORD
LizardF_flush                       PROTO cctx:QWORD,dstBuffer:QWORD,dstMaxSize:QWORD,cOptPtr:QWORD
LizardF_freeCompressionContext      PROTO cctx:QWORD
LizardF_freeDecompressionContext    PROTO dctx:QWORD
LizardF_getErrorName                PROTO errorcode:QWORD
LizardF_getFrameInfo                PROTO dctx:QWORD,frameInfoPtr:QWORD,srcBuffer:QWORD,srcSizePtr:QWORD
LizardF_isError                     PROTO errorcode:QWORD
Lizard_compress                     PROTO src:QWORD,dst:QWORD,srcSize:QWORD,maxDstSize:QWORD,compressionLevel:QWORD
Lizard_compressBound                PROTO inputSize:QWORD
Lizard_compress_MinLevel            PROTO source:QWORD,dest:QWORD,sourceSize:QWORD,maxDestSize:QWORD
Lizard_compress_continue            PROTO streamPtr:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,maxDstSize:QWORD
Lizard_compress_extState            PROTO state:QWORD,src:QWORD,dst:QWORD,srcSize:QWORD,maxDstSize:QWORD,compressionLevel:QWORD
Lizard_compress_extState_MinLevel   PROTO state:QWORD,source:QWORD,dest:QWORD,inputSize:QWORD,maxDestSize:QWORD
Lizard_createStream                 PROTO compressionLevel:QWORD
Lizard_createStreamDecode           PROTO 
Lizard_createStream_MinLevel        PROTO 
Lizard_decompress_safe              PROTO source:QWORD,dest:QWORD,compressedSize:QWORD,maxDecompressedSize:QWORD
Lizard_decompress_safe_continue     PROTO Lizard_streamDecode:QWORD,source:QWORD,dest:QWORD,compressedSize:QWORD,maxDecompressedSize:QWORD
Lizard_decompress_safe_forceExtDict PROTO source:QWORD,dest:QWORD,compressedSize:QWORD,maxOutputSize:QWORD,dictStart:QWORD,dictSize:QWORD
Lizard_decompress_safe_partial      PROTO source:QWORD,dest:QWORD,compressedSize:QWORD,targetOutputSize:QWORD,maxDecompressedSize:QWORD
Lizard_decompress_safe_usingDict    PROTO source:QWORD,dest:QWORD,compressedSize:QWORD,maxDecompressedSize:QWORD,dictStart:QWORD,dictSize:QWORD
Lizard_freeStream                   PROTO streamPtr:QWORD
Lizard_freeStreamDecode             PROTO Lizard_stream:QWORD
Lizard_initBlock                    PROTO ctx:QWORD
Lizard_initStream                   PROTO ctx:QWORD,compressionLevel:QWORD
Lizard_loadDict                     PROTO streamPtr:QWORD,dictionary:QWORD,dictSize:QWORD
Lizard_resetStream                  PROTO streamPtr:QWORD,compressionLevel:QWORD
Lizard_resetStream_MinLevel         PROTO streamPtr:QWORD
Lizard_saveDict                     PROTO streamPtr:QWORD,safeBuffer:QWORD,dictSize:QWORD
Lizard_setStreamDecode              PROTO Lizard_streamDecode:QWORD,dictionary:QWORD,dictSize:QWORD
Lizard_sizeofState                  PROTO compressionLevel:QWORD
Lizard_sizeofState_MinLevel         PROTO 
Lizard_verifyCompressionLevel       PROTO compressionLevel:QWORD
Lizard_versionNumber                PROTO 
Lizard_writeBlock                   PROTO ctx:QWORD,ip:QWORD,inputSize:QWORD,op:QWORD,oend:QWORD
XXH32                               PROTO :QWORD,:QWORD,:QWORD
XXH32_canonicalFromHash             PROTO :QWORD,:QWORD
XXH32_copyState                     PROTO :QWORD,:QWORD
XXH32_createState                   PROTO 
XXH32_digest                        PROTO :QWORD
XXH32_freeState                     PROTO :QWORD
XXH32_hashFromCanonical             PROTO :QWORD
XXH32_reset                         PROTO :QWORD,:QWORD
XXH32_update                        PROTO :QWORD,:QWORD,:QWORD
XXH64                               PROTO :QWORD,:QWORD,:QWORD,:QWORD
XXH64_canonicalFromHash             PROTO :QWORD,:QWORD,:QWORD
XXH64_copyState                     PROTO :QWORD,:QWORD
XXH64_createState                   PROTO 
XXH64_digest                        PROTO :QWORD
XXH64_freeState                     PROTO :QWORD
XXH64_hashFromCanonical             PROTO :QWORD
XXH64_reset                         PROTO :QWORD,:QWORD,:QWORD
XXH64_update                        PROTO :QWORD,:QWORD,:QWORD
XXH_versionNumber                   PROTO 


.CONST

LIZARD_VERSION_MAJOR                EQU 1    ; for breaking interface changes
LIZARD_VERSION_MINOR                EQU 0    ; for new (non-breaking) interface capabilities
LIZARD_VERSION_RELEASE              EQU 0    ; for tweaks, bug-fixes, or development
LIZARD_VERSION_NUMBER               EQU (LIZARD_VERSION_MAJOR *100*100 + LIZARD_VERSION_MINOR *100 + LIZARD_VERSION_RELEASE)

LIZARD_MIN_CLEVEL                   EQU 10  ; minimum compression level
LIZARD_MAX_CLEVEL                   EQU 29  ; maximum compression level (LIZARD_NO_HUFFMAN)
;LIZARD_MAX_CLEVEL                   EQU 49  ; maximum compression level
LIZARD_DEFAULT_CLEVEL               EQU 17


LIZARD_MAX_INPUT_SIZE               EQU 07E000000h   ; 2 113 929 216 bytes
LIZARD_BLOCK_SIZE                   EQU (1 SHL 17)
LIZARD_BLOCK64K_SIZE                EQU (1 SHL 16)

LIZARD_DICT_SIZE                    EQU (1 SHL 24)

; header byte
LIZARD_FLAG_LITERALS                EQU 1
LIZARD_FLAG_FLAGS                   EQU 2
LIZARD_FLAG_OFFSET16                EQU 4
LIZARD_FLAG_OFFSET24                EQU 8
LIZARD_FLAG_LEN                     EQU 16
LIZARD_FLAG_UNCOMPRESSED            EQU 128

; stream numbers 
LIZARD_STREAM_LITERALS              EQU 0
LIZARD_STREAM_FLAGS                 EQU 1
LIZARD_STREAM_OFFSET16              EQU 2
LIZARD_STREAM_OFFSET24              EQU 3
LIZARD_STREAM_LEN                   EQU 4
LIZARD_STREAM_UNCOMPRESSED          EQU 5

; HC Pre-defined compression levels
LIZARD_WINDOWLOG_LZ4                EQU 16
LIZARD_CHAINLOG_LZ4                 EQU LIZARD_WINDOWLOG_LZ4
LIZARD_HASHLOG_LZ4                  EQU 18
LIZARD_HASHLOG_LZ4SM                EQU 12
LIZARD_WINDOWLOG_LIZv1              EQU 22
LIZARD_CHAINLOG_LIZv1               EQU LIZARD_WINDOWLOG_LIZv1
LIZARD_HASHLOG_LIZv1                EQU 18

; Frame compression types
LizardF_default                     EQU 0
LizardF_max128KB                    EQU 1
LizardF_max256KB                    EQU 2
LizardF_max1MB                      EQU 3
LizardF_max4MB                      EQU 4
LizardF_max16MB                     EQU 5
LizardF_max64MB                     EQU 6
LizardF_max256MB                    EQU 7










