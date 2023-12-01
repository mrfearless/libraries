;/*
;  FastLZ - Byte-aligned LZ77 compression library
;  Copyright (C) 2005-2020 Ariya Hidayat <ariya.hidayat@gmail.com>
;
;  Permission is hereby granted, free of charge, to any person obtaining a copy
;  of this software and associated documentation files (the "Software"), to deal
;  in the Software without restriction, including without limitation the rights
;  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;  copies of the Software, and to permit persons to whom the Software is
;  furnished to do so, subject to the following conditions:
;
;  The above copyright notice and this permission notice shall be included in
;  all copies or substantial portions of the Software.
;
;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;  THE SOFTWARE.
;*/

; https://github.com/ariya/FastLZ

; FastLZ_x86.inc converted from FastLZ source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

fastlz_compress             PROTO STDCALL input:DWORD,inputlength:DWORD,output:DWORD
fastlz_compress_level       PROTO STDCALL level:DWORD,input:DWORD,inputlength:DWORD,output:DWORD
fastlz_decompress           PROTO STDCALL input:DWORD,inputlength:DWORD,output:DWORD,maxout:DWORD


.CONST

FASTLZ_VERSION              EQU 0000500h

FASTLZ_VERSION_MAJOR        EQU 0
FASTLZ_VERSION_MINOR        EQU 5
FASTLZ_VERSION_REVISION     EQU 0

FASTLZ_VERSION_STRING       TEXTEQU <"0.5.0">
