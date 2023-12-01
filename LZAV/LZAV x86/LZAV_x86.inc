;/**
; * lzav.h version 2.15
; *
; * The inclusion file for the "LZAV" in-memory data compression and
; * decompression algorithms.
; *
; * Description is available at https://github.com/avaneev/lzav
; * E-mail: aleksey.vaneev@gmail.com or info@voxengo.com
; *
; * License
; *
; * Copyright (c) 2023 Aleksey Vaneev
; *
; * Permission is hereby granted, free of charge, to any person obtaining a
; * copy of this software and associated documentation files (the "Software"),
; * to deal in the Software without restriction, including without limitation
; * the rights to use, copy, modify, merge, publish, distribute, sublicense,
; * and/or sell copies of the Software, and to permit persons to whom the
; * Software is furnished to do so, subject to the following conditions:
; *
; * The above copyright notice and this permission notice shall be included in
; * all copies or substantial portions of the Software.
; *
; * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
; * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
; * DEALINGS IN THE SOFTWARE.
; */

; https://github.com/avaneev/lzav

; LZAV_x86.inc converted from lzav source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

lzav_compress           PROTO STDCALL src:DWORD,dst:DWORD,srcl:DWORD,dstl:DWORD,ext_buf:DWORD,ext_bufl:DWORD
lzav_compress_bound     PROTO STDCALL srcl:DWORD
lzav_compress_default   PROTO STDCALL src:DWORD,dst:DWORD,srcl:DWORD,dstl:DWORD
lzav_decompress         PROTO STDCALL src:DWORD,dst:DWORD,srcl:DWORD,dstl:DWORD
lzav_match_len          PROTO STDCALL p1:DWORD,p2:DWORD,ml:DWORD
lzav_write_blk_1        PROTO STDCALL op:DWORD,lc:DWORD,rc:DWORD,d:DWORD,ipa:DWORD,cbpp:DWORD,mref:DWORD
lzav_write_fin_1        PROTO STDCALL op:DWORD,lc:DWORD,ipa:DWORD

.CONST
; Decompression error codes:

LZAV_E_PARAMS           EQU -1 ; Incorrect function parameters.
LZAV_E_SRCOOB           EQU -2 ; Source buffer OOB.
LZAV_E_DSTOOB           EQU -3 ; Destination buffer OOB.
LZAV_E_REFOOB           EQU -4 ; Back-reference OOB.
LZAV_E_DSTLEN           EQU -5 ; Decompressed length mismatch.
LZAV_E_UNKFMT           EQU -6 ; Unknown stream format.

LZAV_WIN_LEN            EQU ( 1 SHL 24 ) ; LZ77 window length, in bytes.
LZAV_LIT_LEN            EQU ( 1 + 15 + 255 + 255 ) ; Max literal length, in bytes.
LZAV_REF_MIN            EQU 6 ; Min reference length, in bytes.
LZAV_REF_LEN            EQU ( LZAV_REF_MIN + 15 + 255 ) ; Max reference length.
LZAV_LIT_FIN            EQU 5 ; The number of literals required at finish.
LZAV_FMT_CUR            EQU 1 ; Stream format identifier used by the compressor.

