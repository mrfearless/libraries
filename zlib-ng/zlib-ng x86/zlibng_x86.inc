;/* zlib-ng.h -- interface of the 'zlib-ng' compression library, forked from zlib.
;
;  Copyright (C) 1995-2024 Jean-loup Gailly and Mark Adler
;
;  This software is provided 'as-is', without any express or implied
;  warranty.  In no event will the authors be held liable for any damages
;  arising from the use of this software.
;
;  Permission is granted to anyone to use this software for any purpose,
;  including commercial applications, and to alter it and redistribute it
;  freely, subject to the following restrictions:
;
;  1. The origin of this software must not be misrepresented; you must not
;     claim that you wrote the original software. If you use this software
;     in a product, an acknowledgment in the product documentation would be
;     appreciated but is not required.
;  2. Altered source versions must be plainly marked as such, and must not be
;     misrepresented as being the original software.
;  3. This notice may not be removed or altered from any source distribution.
;
;  Jean-loup Gailly        Mark Adler
;  jloup@gzip.org          madler@alumni.caltech.edu
;
;
;  The data format used by the zlib library is described by RFCs (Request for
;  Comments) 1950 to 1952 in the files https://tools.ietf.org/html/rfc1950
;  (zlib format), rfc1951 (deflate format) and rfc1952 (gzip format).
;*/
;
; https://github.com/zlib-ng/zlib-ng
;
; zlibng_x86.inc converted from zlib-ng source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

 
zng_adler32         PROTO STDCALL adler:DWORD,buf:DWORD,len:DWORD
zng_adler32_combine PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zng_adler32_z       PROTO STDCALL adler:DWORD,buf:DWORD,len:DWORD
zng_bi_reverse      PROTO STDCALL :DWORD,:DWORD
zng_compress2       PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD,level:DWORD
zng_compress        PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
zng_compressBound   PROTO STDCALL sourceLen:DWORD
zng_crc32           PROTO STDCALL crc:DWORD,buf:DWORD,len:DWORD
zng_crc32_braid     PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_crc32_combine   PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zng_crc32_combine_gen PROTO STDCALL :DWORD,:DWORD
zng_crc32_combine_op PROTO STDCALL crc1:DWORD,crc2:DWORD,op:DWORD
zng_crc32_z         PROTO STDCALL crc:DWORD,buf:DWORD,len:DWORD
zng_deflate         PROTO STDCALL strm:DWORD,flush:DWORD
zng_deflateBound    PROTO STDCALL strm:DWORD,sourceLen:DWORD
zng_deflateCopy     PROTO STDCALL dest:DWORD,source:DWORD
zng_deflateEnd      PROTO STDCALL strm:DWORD
zng_deflateGetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
zng_deflateGetParams PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_deflateInit2    PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zng_deflateInit2_   PROTO STDCALL strm:DWORD,level:DWORD,method:DWORD,windowBits:DWORD,memLevel:DWORD,strategy:DWORD,version:DWORD,stream_size:DWORD
zng_deflateInit     PROTO STDCALL :DWORD,:DWORD
zng_deflateInit_    PROTO STDCALL strm:DWORD,level:DWORD,version:DWORD,stream_size:DWORD
zng_deflateParams   PROTO STDCALL strm:DWORD,level:DWORD,strategy:DWORD
zng_deflatePending  PROTO STDCALL strm:DWORD,pending:DWORD,bits:DWORD
zng_deflatePrime    PROTO STDCALL strm:DWORD,bits:DWORD,value:DWORD
zng_deflateReset    PROTO STDCALL strm:DWORD
zng_deflateResetKeep PROTO STDCALL :DWORD
zng_deflateSetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
zng_deflateSetHeader PROTO STDCALL strm:DWORD,head:DWORD
zng_deflateSetParams PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_deflateTune     PROTO STDCALL strm:DWORD,good_length:DWORD,max_lazy:DWORD,nice_length:DWORD,max_chain:DWORD
zng_deflate_copyright PROTO C :VARARG
zng_dist_code       PROTO C :VARARG
zng_fill_window     PROTO STDCALL :DWORD
zng_fixedtables     PROTO STDCALL :DWORD
zng_flush_pending   PROTO STDCALL :DWORD
zng_get_crc_table   PROTO STDCALL 
zng_inflate         PROTO STDCALL strm:DWORD,flush:DWORD
zng_inflateBack     PROTO STDCALL strm:DWORD,in_func:DWORD,in_desc:DWORD,out_func:DWORD,out_desc:DWORD
zng_inflateBackEnd  PROTO STDCALL strm:DWORD
zng_inflateBackInit PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_inflateBackInit_ PROTO STDCALL strm:DWORD,windowBits:DWORD,window:DWORD,version:DWORD,stream_size:DWORD
zng_inflateCodesUsed PROTO STDCALL :DWORD
zng_inflateCopy     PROTO STDCALL dest:DWORD,source:DWORD
zng_inflateEnd      PROTO STDCALL strm:DWORD
zng_inflateGetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
zng_inflateGetHeader PROTO STDCALL strm:DWORD,head:DWORD
zng_inflateInit2    PROTO STDCALL :DWORD,:DWORD
zng_inflateInit2_   PROTO STDCALL strm:DWORD,windowBits:DWORD,version:DWORD,stream_size:DWORD
zng_inflateInit     PROTO STDCALL :DWORD
zng_inflateInit_    PROTO STDCALL strm:DWORD,version:DWORD,stream_size:DWORD
zng_inflateMark     PROTO STDCALL strm:DWORD
zng_inflatePrime    PROTO STDCALL strm:DWORD,bits:DWORD,value:DWORD
zng_inflateReset2   PROTO STDCALL strm:DWORD,windowBits:DWORD
zng_inflateReset    PROTO STDCALL strm:DWORD
zng_inflateResetKeep PROTO STDCALL :DWORD
zng_inflateSetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
zng_inflateSync     PROTO STDCALL strm:DWORD
zng_inflateSyncPoint PROTO STDCALL :DWORD
zng_inflateUndermine PROTO STDCALL :DWORD,:DWORD
zng_inflateValidate PROTO STDCALL :DWORD,:DWORD
zng_inflate_copyright PROTO C :VARARG
zng_inflate_table   PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zng_length_code     PROTO C :VARARG
zng_read_buf        PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_tr_align        PROTO STDCALL :DWORD
zng_tr_flush_bits   PROTO STDCALL :DWORD
zng_tr_flush_block  PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zng_tr_init         PROTO STDCALL :DWORD
zng_tr_stored_block PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zng_uncompress2     PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
zng_uncompress      PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
zng_vstring         PROTO C :VARARG
zng_zError          PROTO STDCALL :DWORD
zng_z_errmsg        PROTO C :VARARG
zng_zcalloc         PROTO STDCALL :DWORD,:DWORD,:DWORD
zng_zcfree          PROTO STDCALL :DWORD,:DWORD
zng_zlibCompileFlags PROTO STDCALL 
zlibng_version      PROTO STDCALL

zng_stream                      STRUCT
    next_in                     DWORD ? ; next input byte
    avail_in                    DWORD ? ; number of bytes available at next_in
    total_in                    DWORD ? ; total number of input bytes read so far
    next_out                    DWORD ? ; next output byte will go here
    avail_out                   DWORD ? ; remaining free space at next_out
    total_out                   DWORD ? ; total number of bytes output so far
    msg                         DWORD ? ; last error message, NULL if no error
    state                       DWORD ? ; not visible by applications
    zalloc                      DWORD ? ; used to allocate the internal state
    zfree                       DWORD ? ; used to free the internal state
    opaque                      DWORD ? ; private data object passed to zalloc and zfree
    data_type                   DWORD ? ; best guess about the data type: binary or text for deflate, or the decoding state for inflate
    adler                       DWORD ? ; Adler-32 or CRC-32 value of the uncompressed data
    reserved                    DWORD ? ; reserved for future use
zng_stream                      ENDS

.CONST
ZLIBNG_VERSION              TEXTEQU <"2.2.0">
ZLIBNG_VERNUM               EQU 0020200F0h ; MMNNRRSM: major minor revision status modified
ZLIBNG_VER_MAJOR            EQU 2
ZLIBNG_VER_MINOR            EQU 2
ZLIBNG_VER_REVISION         EQU 0
ZLIBNG_VER_STATUS           EQU 0Eh ; 0=devel, 1-E=beta, F=Release (DEPRECATED)
ZLIBNG_VER_STATUSH          EQU 0Eh ; Hex values: 0=devel, 1-E=beta, F=Release
ZLIBNG_VER_MODIFIED         EQU 0   ; non-zero if modified externally from zlib-ng 

; Allowed flush values; see deflate() and inflate() below for details
Z_NO_FLUSH                      EQU 0
Z_PARTIAL_FLUSH                 EQU 1
Z_SYNC_FLUSH                    EQU 2
Z_FULL_FLUSH                    EQU 3
Z_FINISH                        EQU 4
Z_BLOCK                         EQU 5
Z_TREES                         EQU 6

; Return codes for the compression/decompression functions. Negative values
; are errors, positive values are used for special but normal events.
Z_OK                            EQU 0
Z_STREAM_END                    EQU 1
Z_NEED_DICT                     EQU 2
Z_ERRNO                         EQU (-1)
Z_STREAM_ERROR                  EQU (-2)
Z_DATA_ERROR                    EQU (-3)
Z_MEM_ERROR                     EQU (-4)
Z_BUF_ERROR                     EQU (-5)
Z_VERSION_ERROR                 EQU (-6)

; Compression levels
Z_NO_COMPRESSION                EQU 0
Z_BEST_SPEED                    EQU 1
Z_BEST_COMPRESSION              EQU 9
Z_DEFAULT_COMPRESSION           EQU (-1)

; Compression strategy; see deflateInit2() below for details
Z_FILTERED                      EQU 1
Z_HUFFMAN_ONLY                  EQU 2
Z_RLE                           EQU 3
Z_FIXED                         EQU 4
Z_DEFAULT_STRATEGY              EQU 0

; Possible values of the data_type field for deflate()
Z_BINARY                        EQU 0
Z_TEXT                          EQU 1
Z_ASCII                         EQU Z_TEXT ;for compatibility with 1.2.2 and earlier
Z_UNKNOWN                       EQU 2

; The deflate compression method (the only one supported in this version)
Z_DEFLATED                      EQU 8

; For initializing zalloc, zfree, opaque
Z_NULL                          EQU 0



