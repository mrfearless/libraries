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
; zlibng_x64.inc converted from zlib-ng source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

zng_adler32         PROTO adler:QWORD,buf:QWORD,len:QWORD
zng_adler32_combine PROTO :QWORD,:QWORD,:QWORD,:QWORD
zng_adler32_z       PROTO adler:QWORD,buf:QWORD,len:QWORD
zng_bi_reverse      PROTO :QWORD,:QWORD
zng_compress2       PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD,level:QWORD
zng_compress        PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
zng_compressBound   PROTO sourceLen:QWORD
zng_crc32           PROTO crc:QWORD,buf:QWORD,len:QWORD
zng_crc32_braid     PROTO :QWORD,:QWORD,:QWORD
zng_crc32_combine   PROTO :QWORD,:QWORD,:QWORD,:QWORD
zng_crc32_combine_gen PROTO :QWORD,:QWORD
zng_crc32_combine_op PROTO crc1:QWORD,crc2:QWORD,op:QWORD
zng_crc32_z         PROTO crc:QWORD,buf:QWORD,len:QWORD
zng_deflate         PROTO strm:QWORD,flush:QWORD
zng_deflateBound    PROTO strm:QWORD,sourceLen:QWORD
zng_deflateCopy     PROTO dest:QWORD,source:QWORD
zng_deflateEnd      PROTO strm:QWORD
zng_deflateGetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
zng_deflateGetParams PROTO :QWORD,:QWORD,:QWORD
zng_deflateInit2    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zng_deflateInit2_   PROTO strm:QWORD,level:QWORD,method:QWORD,windowBits:QWORD,memLevel:QWORD,strategy:QWORD,version:QWORD,stream_size:QWORD
zng_deflateInit     PROTO :QWORD,:QWORD
zng_deflateInit_    PROTO strm:QWORD,level:QWORD,version:QWORD,stream_size:QWORD
zng_deflateParams   PROTO strm:QWORD,level:QWORD,strategy:QWORD
zng_deflatePending  PROTO strm:QWORD,pending:QWORD,bits:QWORD
zng_deflatePrime    PROTO strm:QWORD,bits:QWORD,value:QWORD
zng_deflateReset    PROTO strm:QWORD
zng_deflateResetKeep PROTO :QWORD
zng_deflateSetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
zng_deflateSetHeader PROTO strm:QWORD,head:QWORD
zng_deflateSetParams PROTO :QWORD,:QWORD,:QWORD
zng_deflateTune     PROTO strm:QWORD,good_length:QWORD,max_lazy:QWORD,nice_length:QWORD,max_chain:QWORD
zng_deflate_copyright PROTO :VARARG
zng_dist_code       PROTO :VARARG
zng_fill_window     PROTO :QWORD
zng_fixedtables     PROTO :QWORD
zng_flush_pending   PROTO :QWORD
zng_get_crc_table   PROTO 
zng_inflate         PROTO strm:QWORD,flush:QWORD
zng_inflateBack     PROTO strm:QWORD,in_func:QWORD,in_desc:QWORD,out_func:QWORD,out_desc:QWORD
zng_inflateBackEnd  PROTO strm:QWORD
zng_inflateBackInit PROTO :QWORD,:QWORD,:QWORD
zng_inflateBackInit_ PROTO strm:QWORD,windowBits:QWORD,window:QWORD,version:QWORD,stream_size:QWORD
zng_inflateCodesUsed PROTO :QWORD
zng_inflateCopy     PROTO dest:QWORD,source:QWORD
zng_inflateEnd      PROTO strm:QWORD
zng_inflateGetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
zng_inflateGetHeader PROTO strm:QWORD,head:QWORD
zng_inflateInit2    PROTO :QWORD,:QWORD
zng_inflateInit2_   PROTO strm:QWORD,windowBits:QWORD,version:QWORD,stream_size:QWORD
zng_inflateInit     PROTO :QWORD
zng_inflateInit_    PROTO strm:QWORD,version:QWORD,stream_size:QWORD
zng_inflateMark     PROTO strm:QWORD
zng_inflatePrime    PROTO strm:QWORD,bits:QWORD,value:QWORD
zng_inflateReset2   PROTO strm:QWORD,windowBits:QWORD
zng_inflateReset    PROTO strm:QWORD
zng_inflateResetKeep PROTO :QWORD
zng_inflateSetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
zng_inflateSync     PROTO strm:QWORD
zng_inflateSyncPoint PROTO :QWORD
zng_inflateUndermine PROTO :QWORD,:QWORD
zng_inflateValidate PROTO :QWORD,:QWORD
zng_inflate_copyright PROTO :VARARG
zng_inflate_table   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zng_length_code     PROTO :VARARG
zng_read_buf        PROTO :QWORD,:QWORD,:QWORD
zng_tr_align        PROTO :QWORD
zng_tr_flush_bits   PROTO :QWORD
zng_tr_flush_block  PROTO :QWORD,:QWORD,:QWORD,:QWORD
zng_tr_init         PROTO :QWORD
zng_tr_stored_block PROTO :QWORD,:QWORD,:QWORD,:QWORD
zng_uncompress2     PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
zng_uncompress      PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
zng_vstring         PROTO :VARARG
zng_zError          PROTO :QWORD
zng_z_errmsg        PROTO :VARARG
zng_zcalloc         PROTO :QWORD,:QWORD,:QWORD
zng_zcfree          PROTO :QWORD,:QWORD
zng_zlibCompileFlags PROTO 
zlibng_version      PROTO

zng_stream                      STRUCT 8
    next_in                     QWORD ? ; next input byte
    avail_in                    QWORD ? ; number of bytes available at next_in
    total_in                    QWORD ? ; total number of input bytes read so far
    next_out                    QWORD ? ; next output byte will go here
    avail_out                   QWORD ? ; remaining free space at next_out
    total_out                   QWORD ? ; total number of bytes output so far
    msg                         QWORD ? ; last error message, NULL if no error
    state                       QWORD ? ; not visible by applications
    zalloc                      QWORD ? ; used to allocate the internal state
    zfree                       QWORD ? ; used to free the internal state
    opaque                      QWORD ? ; private data object passed to zalloc and zfree
    data_type                   QWORD ? ; best guess about the data type: binary or text for deflate, or the decoding state for inflate
    adler                       QWORD ? ; Adler-32 or CRC-32 value of the uncompressed data
    reserved                    QWORD ? ; reserved for future use
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




