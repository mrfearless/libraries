; zlib.h -- interface of the 'zlib' general purpose compression library
; version 1.3, August 18th, 2023
; 
; Copyright (C) 1995-2023 Jean-loup Gailly and Mark Adler
; 
; This software is provided 'as-is', without any express or implied
; warranty.  In no event will the authors be held liable for any damages
; arising from the use of this software.
; 
; Permission is granted to anyone to use this software for any purpose,
; including commercial applications, and to alter it and redistribute it
; freely, subject to the following restrictions:
; 
; 1. The origin of this software must not be misrepresented; you must not
;    claim that you wrote the original software. If you use this software
;    in a product, an acknowledgment in the product documentation would be
;    appreciated but is not required.
; 2. Altered source versions must be plainly marked as such, and must not be
;    misrepresented as being the original software.
; 3. This notice may not be removed or altered from any source distribution.
; 
; Jean-loup Gailly        Mark Adler
; jloup@gzip.org          madler@alumni.caltech.edu
; 
; 
; The data format used by the zlib library is described by RFCs (Request for
; Comments) 1950 to 1952 in the files http://tools.ietf.org/html/rfc1950
; (zlib format), rfc1951 (deflate format) and rfc1952 (gzip format).
; 

; zlib_x86.inc converted from zlib source for assembler by fearless 2023
; www.github.com/mrfearless

adler32 PROTO STDCALL adler:DWORD,buf:DWORD,len:DWORD
adler32_combine64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
adler32_combine PROTO STDCALL :DWORD,:DWORD,:DWORD
adler32_z PROTO STDCALL adler:DWORD,buf:DWORD,len:DWORD
call_zopen64 PROTO STDCALL :DWORD,:DWORD,:DWORD
call_zseek64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
call_ztell64 PROTO STDCALL :DWORD,:DWORD
compress2 PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD,level:DWORD
compress PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
compressBound PROTO STDCALL sourceLen:DWORD
crc32 PROTO STDCALL crc:DWORD,buf:DWORD,len:DWORD
crc32_combine64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
crc32_combine PROTO STDCALL :DWORD,:DWORD,:DWORD
crc32_combine_gen64 PROTO STDCALL :DWORD,:DWORD
crc32_combine_gen PROTO STDCALL :DWORD
crc32_combine_op PROTO STDCALL crc1:DWORD,crc2:DWORD,op:DWORD
crc32_z PROTO STDCALL crc:DWORD,buf:DWORD,len:DWORD
deflate PROTO STDCALL strm:DWORD,flush:DWORD
deflateBound PROTO STDCALL strm:DWORD,sourceLen:DWORD
deflateCopy PROTO STDCALL dest:DWORD,source:DWORD
deflateEnd PROTO STDCALL strm:DWORD
deflateGetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
deflateInit2_ PROTO STDCALL strm:DWORD,level:DWORD,method:DWORD,windowBits:DWORD,memLevel:DWORD,strategy:DWORD,version:DWORD,stream_size:DWORD
deflateInit_ PROTO STDCALL strm:DWORD,level:DWORD,version:DWORD,stream_size:DWORD
deflateParams PROTO STDCALL strm:DWORD,level:DWORD,strategy:DWORD
deflatePending PROTO STDCALL strm:DWORD,pending:DWORD,bits:DWORD
deflatePrime PROTO STDCALL strm:DWORD,bits:DWORD,value:DWORD
deflateReset PROTO STDCALL strm:DWORD
deflateResetKeep PROTO STDCALL :DWORD
deflateSetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
deflateSetHeader PROTO STDCALL strm:DWORD,head:DWORD
deflateTune PROTO STDCALL strm:DWORD,good_length:DWORD,max_lazy:DWORD,nice_length:DWORD,max_chain:DWORD
deflate_copyright PROTO C :VARARG
fill_fopen64_filefunc PROTO STDCALL :DWORD
fill_fopen_filefunc PROTO STDCALL :DWORD
fill_zlib_filefunc64_32_def_from_filefunc32 PROTO STDCALL :DWORD,:DWORD
get_crc_table PROTO STDCALL 
gz_error PROTO STDCALL :DWORD,:DWORD,:DWORD
gzbuffer PROTO STDCALL file:DWORD,dwsize:DWORD
gzclearerr PROTO STDCALL file:DWORD
gzclose PROTO STDCALL file:DWORD
gzclose_r PROTO STDCALL file:DWORD
gzclose_w PROTO STDCALL file:DWORD
gzdirect PROTO STDCALL file:DWORD
gzdopen PROTO STDCALL :DWORD,:DWORD
gzeof PROTO STDCALL file:DWORD
gzerror PROTO STDCALL file:DWORD,errnum:DWORD
gzflush PROTO STDCALL file:DWORD,flush:DWORD
gzfread PROTO STDCALL buf:DWORD,dwsize:DWORD,nitems:DWORD,file:DWORD
gzfwrite PROTO STDCALL buf:DWORD,dwsize:DWORD,nitems:DWORD,file:DWORD
gzgetc PROTO STDCALL file:DWORD
gzgetc_ PROTO STDCALL :DWORD
gzgets PROTO STDCALL file:DWORD,buf:DWORD,len:DWORD
gzoffset64 PROTO STDCALL :DWORD
gzoffset PROTO STDCALL :DWORD
gzopen64 PROTO STDCALL :DWORD,:DWORD
gzopen PROTO STDCALL fd:DWORD,mode:DWORD
gzopen_w PROTO STDCALL :DWORD,:DWORD
gzprintf PROTO C :VARARG
gzputc PROTO STDCALL file:DWORD,char:DWORD
gzputs PROTO STDCALL file:DWORD,s:DWORD
gzread PROTO STDCALL file:DWORD,buf:DWORD,len:DWORD
gzrewind PROTO STDCALL file:DWORD
gzseek64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
gzseek PROTO STDCALL :DWORD,:DWORD,:DWORD
gzsetparams PROTO STDCALL file:DWORD,level:DWORD,strategy:DWORD
gztell64 PROTO STDCALL :DWORD
gztell PROTO STDCALL :DWORD
gzungetc PROTO STDCALL :DWORD,:DWORD
gzvprintf PROTO C :VARARG
gzwrite PROTO STDCALL file:DWORD,buf:DWORD,len:DWORD
inflate PROTO STDCALL strm:DWORD,flush:DWORD
inflateBack PROTO STDCALL strm:DWORD,in_func:DWORD,in_desc:DWORD,out_func:DWORD,out_desc:DWORD
inflateBackEnd PROTO STDCALL strm:DWORD
inflateBackInit_ PROTO STDCALL strm:DWORD,windowBits:DWORD,window:DWORD,version:DWORD,stream_size:DWORD
inflateCodesUsed PROTO STDCALL :DWORD
inflateCopy PROTO STDCALL dest:DWORD,source:DWORD
inflateEnd PROTO STDCALL strm:DWORD
inflateGetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
inflateGetHeader PROTO STDCALL strm:DWORD,head:DWORD
inflateInit2_ PROTO STDCALL strm:DWORD,windowBits:DWORD,version:DWORD,stream_size:DWORD
inflateInit_ PROTO STDCALL strm:DWORD,version:DWORD,stream_size:DWORD
inflateMark PROTO STDCALL strm:DWORD
inflatePrime PROTO STDCALL strm:DWORD,bits:DWORD,value:DWORD
inflateReset2 PROTO STDCALL strm:DWORD,windowBits:DWORD
inflateReset PROTO STDCALL strm:DWORD
inflateResetKeep PROTO STDCALL :DWORD
inflateSetDictionary PROTO STDCALL strm:DWORD,dictionary:DWORD,dictLength:DWORD
inflateSync PROTO STDCALL strm:DWORD
inflateSyncPoint PROTO STDCALL :DWORD
inflateUndermine PROTO STDCALL :DWORD,:DWORD
inflateValidate PROTO STDCALL :DWORD,:DWORD
inflate_copyright PROTO C :VARARG
inflate_fast PROTO STDCALL :DWORD,:DWORD
inflate_table PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
snprintf PROTO C :VARARG
uncompress2 PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
uncompress PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD
unzClose PROTO STDCALL :DWORD
unzCloseCurrentFile PROTO STDCALL :DWORD
unzGetCurrentFileInfo64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
unzGetCurrentFileInfo PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
unzGetCurrentFileZStreamPos64 PROTO STDCALL :DWORD
unzGetFilePos64 PROTO STDCALL :DWORD,:DWORD
unzGetFilePos PROTO STDCALL :DWORD,:DWORD
unzGetGlobalComment PROTO STDCALL :DWORD,:DWORD,:DWORD
unzGetGlobalInfo64 PROTO STDCALL :DWORD,:DWORD
unzGetGlobalInfo PROTO STDCALL :DWORD,:DWORD
unzGetLocalExtrafield PROTO STDCALL :DWORD,:DWORD,:DWORD
unzGetOffset64 PROTO STDCALL :DWORD
unzGetOffset PROTO STDCALL :DWORD
unzGoToFilePos64 PROTO STDCALL :DWORD,:DWORD
unzGoToFilePos PROTO STDCALL :DWORD,:DWORD
unzGoToFirstFile PROTO STDCALL :DWORD
unzGoToNextFile PROTO STDCALL :DWORD
unzLocateFile PROTO STDCALL :DWORD,:DWORD,:DWORD
unzOpen2 PROTO STDCALL :DWORD,:DWORD
unzOpen2_64 PROTO STDCALL :DWORD,:DWORD
unzOpen64 PROTO STDCALL :DWORD
unzOpen PROTO STDCALL :DWORD
unzOpenCurrentFile2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
unzOpenCurrentFile3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
unzOpenCurrentFile PROTO STDCALL :DWORD
unzOpenCurrentFilePassword PROTO STDCALL :DWORD,:DWORD
unzReadCurrentFile PROTO STDCALL :DWORD,:DWORD,:DWORD
unzSetOffset64 PROTO STDCALL :DWORD,:DWORD,:DWORD
unzSetOffset PROTO STDCALL :DWORD,:DWORD
unzStringFileNameCompare PROTO STDCALL :DWORD,:DWORD,:DWORD
unz_copyright PROTO C :VARARG
unzeof PROTO STDCALL :DWORD
unztell64 PROTO STDCALL :DWORD
unztell PROTO STDCALL :DWORD
zError PROTO STDCALL :DWORD
z_errmsg PROTO C :VARARG
zcalloc PROTO STDCALL :DWORD,:DWORD,:DWORD
zcfree PROTO STDCALL :DWORD,:DWORD
zipClose PROTO STDCALL :DWORD,:DWORD
zipCloseFileInZip PROTO STDCALL :DWORD
zipCloseFileInZipRaw64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zipCloseFileInZipRaw PROTO STDCALL :DWORD,:DWORD,:DWORD
zipOpen2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zipOpen2_64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zipOpen3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zipOpen64 PROTO STDCALL :DWORD,:DWORD
zipOpen PROTO STDCALL :DWORD,:DWORD
zipOpenNewFileInZip2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip2_64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip3 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip3_64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip4 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip4_64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipOpenNewFileInZip PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zipRemoveExtraInfoBlock PROTO STDCALL :DWORD,:DWORD,:DWORD
zipWriteInFileInZip PROTO STDCALL :DWORD,:DWORD,:DWORD
zip_copyright PROTO C :VARARG
zlibCompileFlags PROTO STDCALL 
zlibVersion PROTO STDCALL 


;--------------------Structures-----------------------------
;internal_state     STRUCT 
;dummy              DWORD ?
;internal_state     ENDS

zlib_filefunc_def               STRUCT 
    zopen_file                  DWORD ?
    zread_file                  DWORD ?
    zwrite_file                 DWORD ?
    ztell_file                  DWORD ?
    zseek_file                  DWORD ?
    zclose_file                 DWORD ?
    zerror_file                 DWORD ?
    opaque                      DWORD ?
zlib_filefunc_def               ENDS

linkedlist_datablock_internal   STRUCT
    next_datablock              DWORD ? ;PTR linkedlist_datablock_internal
    avail_in_this_block         DWORD ?
    filled_in_this_block        DWORD ?
    unused                      DWORD ?
    data                        BYTE 4080 DUP (?)
linkedlist_datablock_internal   ENDS

linkedlist_data                 STRUCT 
    first_block                 DWORD ? ;linkedlist_datablock_internal
    last_block                  DWORD ? ;linkedlist_datablock_internal
linkedlist_data                 ENDS

z_stream                        STRUCT
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
z_stream                        ENDS

gz_header                       STRUCT
    text                        DWORD ? ; true if compressed data believed to be text
    time                        DWORD ? ; modification time
    xflags                      DWORD ? ; extra flags (not used when writing a gzip file)
    os                          DWORD ? ; operating system
    extra                       DWORD ? ; pointer to extra field or Z_NULL if none
    extra_len                   DWORD ? ; extra field length (valid if extra != Z_NULL)
    extra_max                   DWORD ? ; space at extra (only when reading header)
    szname                      DWORD ? ; pointer to zero-terminated file name or Z_NULL
    name_max                    DWORD ? ; space at name (only when reading header)
    szcomment                   DWORD ? ; pointer to zero-terminated comment or Z_NULL
    comm_max                    DWORD ? ; space at comment (only when reading header)
    hcrc                        DWORD ? ; true if there was or will be a header crc
    done                        DWORD ? ; true when done reading gzip header (not used when writing a gzip file)
gz_header                       ENDS


curfile_info                    STRUCT
    stream                      z_stream <>
    stream_initialised          SDWORD ?
    pos_in_buffered_data        DWORD ?
    pos_local_header            DWORD ?
    central_header              DWORD ?
    size_centralheader          DWORD ?
    flag                        DWORD ?
    method                      SDWORD ?
    raw                         SDWORD ?
    buffered_data               Byte 16384 DUP (?)
    dosDate                     DWORD ?
    crc32                       DWORD ?
curfile_info                    ENDS

zip_internal                    STRUCT
    z_filefunc                  zlib_filefunc_def <>
    filestream                  DWORD ?
    central_dir                 linkedlist_data <>
    in_opened_file_inzip        DWORD ?
    ci                          curfile_info <>
    begin_pos                   DWORD ?
    number_entry                DWORD ?
zip_internal                    ENDS

tm_zip                          STRUCT
    tm_sec                      DWORD ?
    tm_min                      DWORD ?
    tm_hour                     DWORD ?
    tm_mday                     DWORD ?
    tm_mon                      DWORD ?
    tm_year                     DWORD ?
tm_zip                          ENDS

zip_fileinfo                    STRUCT
    tmz_date                    tm_zip <>
    dosDate                     DWORD ?
    iflag                       DWORD ?
    eflag                       DWORD ?
zip_fileinfo                    ENDS

;-----------------Unzip Structures-----------------------------
tm_unz                          STRUCT
    tm_sec                      DWORD ?
    tm_min                      DWORD ?
    tm_hour                     DWORD ?
    tm_mday                     DWORD ?
    tm_mon                      DWORD ?
    tm_year                     DWORD ?
tm_unz                          ENDS

unz_global_info                 STRUCT
    number_entry                DWORD ?
    size_comment                DWORD ?
unz_global_info                 ENDS

unz_file_info                   STRUCT
    version                     DWORD ?
    version_needed              DWORD ?
    flag                        DWORD ?
    compression_method          DWORD ?
    dosDate                     DWORD ?
    crc                         DWORD ?
    compressed_size             DWORD ?
    uncompressed_size           DWORD ?
    size_filename               DWORD ?
    size_file_extra             DWORD ?
    size_file_comment           DWORD ?
    disk_num_start              DWORD ?
    internal_fa                 DWORD ?
    external_fa                 DWORD ?
    tmu_date                    tm_unz <>
unz_file_info                   ENDS

unz_file_info_internal          STRUCT
    offset_curfile              DWORD ?
unz_file_info_internal          ENDS

file_in_zip_read_info           STRUCT
    read_buffer                 DWORD ?
    stream                      z_stream <>
    pos_in_zipfile              DWORD ?
    stream_initialised          DWORD ?
    offset_local_extrafield     DWORD ?
    size_local_extrafield       DWORD ?
    pos_local_extrafield        DWORD ?
    crc32                       DWORD ?
    crc32_wait                  DWORD ?
    rest_read_compressed        DWORD ?
    rest_read_uncompressed      DWORD ?
    z_filefunc                  zlib_filefunc_def <>
    filestream                  DWORD ?
    compression_method          DWORD ?
    byte_before_the_zipfile     DWORD ?
    raw                         DWORD ?
file_in_zip_read_info           ENDS

unz_s                           STRUCT
    z_filefunc                  zlib_filefunc_def <>
    filestream                  DWORD ?
    gi                          unz_global_info <>
    byte_before_the_zipfile     DWORD ?
    num_file                    DWORD ?
    pos_in_central_dir          DWORD ?
    current_file_ok             DWORD ?
    central_pos                 DWORD ?
    size_central_dir            DWORD ?
    offset_central_dir          DWORD ?
    cur_file_info               unz_file_info <>
    cur_file_info_internal      unz_file_info_internal <>
    pfile_in_zip_read           DWORD ?
unz_s                           ENDS




.CONST
ZLIB_VERSION                    TEXTEQU <"1.3">
ZLIB_VERNUM                     EQU 1300h
ZLIB_VER_MAJOR                  EQU 1
ZLIB_VER_MINOR                  EQU 3
ZLIB_VER_REVISION               EQU 0
ZLIB_VER_SUBREVISION            EQU 0

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

; Header definitions for gz* operations
GZBUFSIZE                       EQU 8192
; gzip modes, also provide a little integrity check on the passed structure
GZ_NONE                         EQU 0
GZ_READ                         EQU 7247
GZ_WRITE                        EQU 31153
GZ_APPEND                       EQU 1   ; mode set to GZ_WRITE after the file is opened

; values for gz_state how
LOOK                            EQU 0   ; look for a gzip header
COPY                            EQU 1   ; copy input directly
GZIP                            EQU 2   ; decompress a gzip stream

; Minizip - for compress/uncompress .zip
ZLIB_FILEFUNC_SEEK_CUR          EQU (1)
ZLIB_FILEFUNC_SEEK_END          EQU (2)
ZLIB_FILEFUNC_SEEK_SET          EQU (0)

ZLIB_FILEFUNC_MODE_READ         EQU (1)
ZLIB_FILEFUNC_MODE_WRITE        EQU (2)
ZLIB_FILEFUNC_MODE_READWRITEFILTER EQU (3)

ZLIB_FILEFUNC_MODE_EXISTING     EQU (4)
ZLIB_FILEFUNC_MODE_CREATE       EQU (8)

; Minizip - for uncompress .zip files using zlib
UNZ_OK                          EQU (0)
UNZ_END_OF_LIST_OF_FILE         EQU (-100)
UNZ_ERRNO                       EQU (Z_ERRNO)
UNZ_EOF                         EQU (0)
UNZ_PARAMERROR                  EQU (-102)
UNZ_BADZIPFILE                  EQU (-103)
UNZ_INTERNALERROR               EQU (-104)
UNZ_CRCERROR                    EQU (-105)

; Minizip - for compress .zip files using zlib
ZIP_OK                          EQU (0)
ZIP_EOF                         EQU (0)
ZIP_ERRNO                       EQU (Z_ERRNO)
ZIP_PARAMERROR                  EQU (-102)
ZIP_BADZIPFILE                  EQU (-103)
ZIP_INTERNALERROR               EQU (-104)

; Minizip - for append
APPEND_STATUS_CREATE            EQU (0)
APPEND_STATUS_CREATEAFTER       EQU (1)
APPEND_STATUS_ADDINZIP          EQU (2)