; Copyright 2005 and onwards Google Inc.
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are
; met:
;
;    ; Redistributions of source code must retain the above copyright
; notice, this list of conditions and the following disclaimer.
;    ; Redistributions in binary form must reproduce the above
; copyright notice, this list of conditions and the following disclaimer
; in the documentation and/or other materials provided with the
; distribution.
;    ; Neither the name of Google Inc. nor the names of its
; contributors may be used to endorse or promote products derived from
; this software without specific prior written permission.
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
; A light-weight compression algorithm.  It is designed for speed of
; compression and decompression, rather than for the utmost in space
; savings.
;
; For getting better compression ratios when you are compressing data
; with long repeated sequences or compressing data that is similar to
; other data, while still compressing fast, you might look at first
; using BMDiff and then compressing the output of BMDiff with
; Snappy.

; Snappy_x86.inc converted from snappy source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

snappy_compress                     PROTO lpUncompressedData:DWORD,dwUncompressedDataSize:DWORD,lpCompressedData:DWORD,lpdwCompressedDataSize:DWORD
snappy_max_compressed_length        PROTO dwUncompressedDataSize:DWORD
snappy_uncompress                   PROTO lpCompressedData:DWORD,dwCompressedDataSize:DWORD,lpUncompressedData:DWORD,lpdwUncompressedDataSize:DWORD
snappy_uncompressed_length          PROTO lpCompressedData:DWORD,dwCompressedDataSize:DWORD,lpdwUncompressedDataSize:DWORD
snappy_validate_compressed_buffer   PROTO lpCompressedData:DWORD,dwCompressedDataSize:DWORD

snappy_status           TYPEDEF DWORD

.CONST
SNAPPY_MAJOR            EQU 1
SNAPPY_MINOR            EQU 2
SNAPPY_PATCHLEVEL       EQU 1
SNAPPY_BUILD            EQU 0
SNAPPY_VERSION          EQU ((SNAPPY_MAJOR SHL 16) or (SNAPPY_MINOR SHL 8) or SNAPPY_PATCHLEVEL)

; snappy_status
SNAPPY_OK               EQU 0
SNAPPY_INVALID_INPUT    EQU 1
SNAPPY_BUFFER_TOO_SMALL EQU 2


kBlockLog               EQU 16;
kBlockSize              EQU 1 ; << kBlockLog;
kMaxHashTableBits       EQU 14;
kMaxHashTableSize       EQU 1 ; << kMaxHashTableBits;
  
.DATA
SNAPPY_VERSION_STRING   DB "1.2.1",0
  
  
  
  
  
  
  
  
  
  
  
  
  
  