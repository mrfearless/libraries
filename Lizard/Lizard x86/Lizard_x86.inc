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

; Lizard_x86.inc converted from Lizard source for assembler by fearless 2023
; www.github.com/mrfearless

LizardF_compressBegin               PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstMaxSize:DWORD,prefsPtr:DWORD
LizardF_compressBound               PROTO STDCALL srcSize:DWORD,prefsPtr:DWORD
LizardF_compressEnd                 PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstMaxSize:DWORD,cOptPtr:DWORD
LizardF_compressFrame               PROTO STDCALL dstBuffer:DWORD,dstMaxSize:DWORD,srcBuffer:DWORD,srcSize:DWORD,preferencesPtr:DWORD
LizardF_compressFrameBound          PROTO STDCALL srcSize:DWORD,preferencesPtr:DWORD
LizardF_compressUpdate              PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstMaxSize:DWORD,srcBuffer:DWORD,srcSize:DWORD,cOptPtr:DWORD
LizardF_createCompressionContext    PROTO STDCALL cctxPtr:DWORD,version:DWORD
LizardF_createDecompressionContext  PROTO STDCALL dctxPtr:DWORD,version:DWORD
LizardF_decompress                  PROTO STDCALL dctx:DWORD,dstBuffer:DWORD,dstSizePtr:DWORD,srcBuffer:DWORD,srcSizePtr:DWORD,dOptPtr:DWORD
LizardF_flush                       PROTO STDCALL cctx:DWORD,dstBuffer:DWORD,dstMaxSize:DWORD,cOptPtr:DWORD
LizardF_freeCompressionContext      PROTO STDCALL cctx:DWORD
LizardF_freeDecompressionContext    PROTO STDCALL dctx:DWORD
LizardF_getErrorName                PROTO STDCALL errorcode:DWORD
LizardF_getFrameInfo                PROTO STDCALL dctx:DWORD,frameInfoPtr:DWORD,srcBuffer:DWORD,srcSizePtr:DWORD
LizardF_isError                     PROTO STDCALL errorcode:DWORD
Lizard_compress                     PROTO STDCALL src:DWORD,dst:DWORD,srcSize:DWORD,maxDstSize:DWORD,compressionLevel:DWORD
Lizard_compressBound                PROTO STDCALL inputSize:DWORD
Lizard_compress_MinLevel            PROTO STDCALL source:DWORD,dest:DWORD,sourceSize:DWORD,maxDestSize:DWORD
Lizard_compress_continue            PROTO STDCALL streamPtr:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,maxDstSize:DWORD
Lizard_compress_extState            PROTO STDCALL state:DWORD,src:DWORD,dst:DWORD,srcSize:DWORD,maxDstSize:DWORD,compressionLevel:DWORD
Lizard_compress_extState_MinLevel   PROTO STDCALL state:DWORD,source:DWORD,dest:DWORD,inputSize:DWORD,maxDestSize:DWORD
Lizard_createStream                 PROTO STDCALL compressionLevel:DWORD
Lizard_createStreamDecode           PROTO STDCALL 
Lizard_createStream_MinLevel        PROTO STDCALL 
Lizard_decompress_safe              PROTO STDCALL source:DWORD,dest:DWORD,compressedSize:DWORD,maxDecompressedSize:DWORD
Lizard_decompress_safe_continue     PROTO STDCALL Lizard_streamDecode:DWORD,source:DWORD,dest:DWORD,compressedSize:DWORD,maxDecompressedSize:DWORD
Lizard_decompress_safe_forceExtDict PROTO STDCALL source:DWORD,dest:DWORD,compressedSize:DWORD,maxOutputSize:DWORD,dictStart:DWORD,dictSize:DWORD
Lizard_decompress_safe_partial      PROTO STDCALL source:DWORD,dest:DWORD,compressedSize:DWORD,targetOutputSize:DWORD,maxDecompressedSize:DWORD
Lizard_decompress_safe_usingDict    PROTO STDCALL source:DWORD,dest:DWORD,compressedSize:DWORD,maxDecompressedSize:DWORD,dictStart:DWORD,dictSize:DWORD
Lizard_freeStream                   PROTO STDCALL streamPtr:DWORD
Lizard_freeStreamDecode             PROTO STDCALL Lizard_stream:DWORD
Lizard_initBlock                    PROTO STDCALL ctx:DWORD
Lizard_initStream                   PROTO STDCALL ctx:DWORD,compressionLevel:DWORD
Lizard_loadDict                     PROTO STDCALL streamPtr:DWORD,dictionary:DWORD,dictSize:DWORD
Lizard_resetStream                  PROTO STDCALL streamPtr:DWORD,compressionLevel:DWORD
Lizard_resetStream_MinLevel         PROTO STDCALL streamPtr:DWORD
Lizard_saveDict                     PROTO STDCALL streamPtr:DWORD,safeBuffer:DWORD,dictSize:DWORD
Lizard_setStreamDecode              PROTO STDCALL Lizard_streamDecode:DWORD,dictionary:DWORD,dictSize:DWORD
Lizard_sizeofState                  PROTO STDCALL compressionLevel:DWORD
Lizard_sizeofState_MinLevel         PROTO STDCALL 
Lizard_verifyCompressionLevel       PROTO STDCALL compressionLevel:DWORD
Lizard_versionNumber                PROTO STDCALL 
Lizard_writeBlock                   PROTO STDCALL ctx:DWORD,ip:DWORD,inputSize:DWORD,op:DWORD,oend:DWORD



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










