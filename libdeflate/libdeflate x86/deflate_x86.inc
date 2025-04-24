; Copyright 2016 Eric Biggers
; Copyright 2024 Google LLC
; 
; Permission is hereby granted, free of charge, to any person
; obtaining a copy of this software and associated documentation files
; (the "Software"), to deal in the Software without restriction,
; including without limitation the rights to use, copy, modify, merge,
; publish, distribute, sublicense, and/or sell copies of the Software,
; and to permit persons to whom the Software is furnished to do so,
; subject to the following conditions:
; 
; The above copyright notice and this permission notice shall be
; included in all copies or substantial portions of the Software.
; 
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
; NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
; BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
; ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
; CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
; SOFTWARE.
;
; https://github.com/ebiggers/libdeflate

; deflate_x86.inc converted from libdeflate source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

libdeflate_alloc_compressor       PROTO STDCALL compression_level:DWORD ; 1-12
libdeflate_alloc_compressor_ex    PROTO STDCALL compression_level:DWORD,options:DWORD
libdeflate_alloc_decompressor     PROTO STDCALL 
libdeflate_alloc_decompressor_ex  PROTO STDCALL options:DWORD
libdeflate_set_memory_allocator   PROTO STDCALL malloc_func:DWORD,free_func:DWORD

libdeflate_deflate_compress       PROTO STDCALL compressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD
libdeflate_deflate_compress_bound PROTO STDCALL compressor:DWORD,in_nbytes:DWORD
libdeflate_free_compressor        PROTO STDCALL compressor:DWORD
libdeflate_deflate_decompress     PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_out_nbytes_ret:DWORD
libdeflate_deflate_decompress_ex  PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_in_nbytes_ret:DWORD,actual_out_nbytes_ret:DWORD
libdeflate_free_decompressor      PROTO STDCALL decompressor:DWORD

libdeflate_gzip_compress          PROTO STDCALL compressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD
libdeflate_gzip_compress_bound    PROTO STDCALL compressor:DWORD,in_nbytes:DWORD
libdeflate_gzip_decompress        PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_out_nbytes_ret:DWORD
libdeflate_gzip_decompress_ex     PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_in_nbytes_ret:DWORD,actual_out_nbytes_ret:DWORD

libdeflate_zlib_compress          PROTO STDCALL compressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD
libdeflate_zlib_compress_bound    PROTO STDCALL compressor:DWORD,in_nbytes:DWORD
libdeflate_zlib_decompress        PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_out_nbytes_ret:DWORD
libdeflate_zlib_decompress_ex     PROTO STDCALL decompressor:DWORD,inbuffer:DWORD,in_nbytes:DWORD,outbuffer:DWORD,out_nbytes_avail:DWORD,actual_in_nbytes_ret:DWORD,actual_out_nbytes_ret:DWORD

libdeflate_adler32                PROTO STDCALL adler:DWORD,buffer:DWORD,len:DWORD
libdeflate_crc32                  PROTO STDCALL crc:DWORD,buffer:DWORD,len:DWORD


libdeflate_options                STRUCT
    sizeof_options                DWORD ? ; size_t
    malloc_func                   DWORD ? ; 
    free_func                     DWORD ? ; 
libdeflate_options                ENDS

libdeflate_compressor             TYPEDEF DWORD
libdeflate_decompressor           TYPEDEF DWORD
libdeflate_result                 TYPEDEF DWORD

.CONST
LIBDEFLATE_VERSION_MAJOR          EQU 1
LIBDEFLATE_VERSION_MINOR          EQU 20
LIBDEFLATE_VERSION_STRING         TEXTEQU <"1.20">


LIBDEFLATE_SUCCESS                EQU 0 ; Decompression was successful.
LIBDEFLATE_BAD_DATA               EQU 1 ; Decompression failed because the compressed data was invalid corrupt, or otherwise unsupported
LIBDEFLATE_SHORT_OUTPUT           EQU 2 ; A NULL 'actual_out_nbytes_ret' was provided, but the data would have decompressed to fewer than 'out_nbytes_avail' bytes.
LIBDEFLATE_INSUFFICIENT_SPACE     EQU 3 ; The data would have decompressed to more than 'out_nbytes_avail' bytes.


