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

; deflate_x64.inc converted from libdeflate source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

libdeflate_alloc_compressor       PROTO compression_level:QWORD ; 1-12
libdeflate_alloc_compressor_ex    PROTO compression_level:QWORD,options:QWORD
libdeflate_alloc_decompressor     PROTO 
libdeflate_alloc_decompressor_ex  PROTO options:QWORD
libdeflate_set_memory_allocator   PROTO malloc_func:QWORD,free_func:QWORD

libdeflate_deflate_compress       PROTO compressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD
libdeflate_deflate_compress_bound PROTO compressor:QWORD,in_nbytes:QWORD
libdeflate_free_compressor        PROTO compressor:QWORD
libdeflate_deflate_decompress     PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_out_nbytes_ret:QWORD
libdeflate_deflate_decompress_ex  PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_in_nbytes_ret:QWORD,actual_out_nbytes_ret:QWORD
libdeflate_free_decompressor      PROTO decompressor:QWORD

libdeflate_gzip_compress          PROTO compressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD
libdeflate_gzip_compress_bound    PROTO compressor:QWORD,in_nbytes:QWORD
libdeflate_gzip_decompress        PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_out_nbytes_ret:QWORD
libdeflate_gzip_decompress_ex     PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_in_nbytes_ret:QWORD,actual_out_nbytes_ret:QWORD

libdeflate_zlib_compress          PROTO compressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD
libdeflate_zlib_compress_bound    PROTO compressor:QWORD,in_nbytes:QWORD
libdeflate_zlib_decompress        PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_out_nbytes_ret:QWORD
libdeflate_zlib_decompress_ex     PROTO decompressor:QWORD,inbuffer:QWORD,in_nbytes:QWORD,outbuffer:QWORD,out_nbytes_avail:QWORD,actual_in_nbytes_ret:QWORD,actual_out_nbytes_ret:QWORD

libdeflate_adler32                PROTO adler:QWORD,buffer:QWORD,len:QWORD
libdeflate_crc32                  PROTO crc:QWORD,buffer:QWORD,len:QWORD


libdeflate_options                STRUCT 8
    sizeof_options                QWORD ? ; size_t
    malloc_func                   QWORD ? ; 
    free_func                     QWORD ? ; 
libdeflate_options                ENDS

libdeflate_compressor             TYPEDEF QWORD
libdeflate_decompressor           TYPEDEF QWORD
libdeflate_result                 TYPEDEF QWORD

.CONST
LIBDEFLATE_VERSION_MAJOR          EQU 1
LIBDEFLATE_VERSION_MINOR          EQU 20
LIBDEFLATE_VERSION_STRING         TEXTEQU <"1.20">


LIBDEFLATE_SUCCESS                EQU 0 ; Decompression was successful.
LIBDEFLATE_BAD_DATA               EQU 1 ; Decompression failed because the compressed data was invalid corrupt, or otherwise unsupported
LIBDEFLATE_SHORT_OUTPUT           EQU 2 ; A NULL 'actual_out_nbytes_ret' was provided, but the data would have decompressed to fewer than 'out_nbytes_avail' bytes.
LIBDEFLATE_INSUFFICIENT_SPACE     EQU 3 ; The data would have decompressed to more than 'out_nbytes_avail' bytes.


