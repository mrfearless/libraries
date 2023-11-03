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

; zlib_x64.inc converted from zlib source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

adler32 PROTO adler:QWORD,buf:QWORD,len:QWORD
adler32_combine64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
adler32_combine PROTO :QWORD,:QWORD,:QWORD
adler32_z PROTO adler:QWORD,buf:QWORD,len:QWORD
call_zopen64 PROTO :QWORD,:QWORD,:QWORD
call_zseek64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
call_ztell64 PROTO :QWORD,:QWORD
compress2 PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD,level:QWORD
compress PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
compressBound PROTO sourceLen:QWORD
;crc32 PROTO crc_:QWORD,buf:QWORD,len:QWORD
crc32_combine64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
crc32_combine PROTO :QWORD,:QWORD,:QWORD
crc32_combine_gen64 PROTO :QWORD,:QWORD
crc32_combine_gen PROTO :QWORD
crc32_combine_op PROTO crc1:QWORD,crc2:QWORD,op:QWORD
crc32_z PROTO crc:QWORD,buf:QWORD,len:QWORD
deflate PROTO strm:QWORD,flush:QWORD
deflateBound PROTO strm:QWORD,sourceLen:QWORD
deflateCopy PROTO dest:QWORD,source:QWORD
deflateEnd PROTO strm:QWORD
deflateGetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
deflateInit2_ PROTO strm:QWORD,level:QWORD,method:QWORD,windowBits:QWORD,memLevel:QWORD,strategy:QWORD,version:QWORD,stream_size:QWORD
deflateInit_ PROTO strm:QWORD,level:QWORD,version:QWORD,stream_size:QWORD
deflateParams PROTO strm:QWORD,level:QWORD,strategy:QWORD
deflatePending PROTO strm:QWORD,pending:QWORD,bits:QWORD
deflatePrime PROTO strm:QWORD,bits:QWORD,value:QWORD
deflateReset PROTO strm:QWORD
deflateResetKeep PROTO :QWORD
deflateSetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
deflateSetHeader PROTO strm:QWORD,head:QWORD
deflateTune PROTO strm:QWORD,good_length:QWORD,max_lazy:QWORD,nice_length:QWORD,max_chain:QWORD
deflate_copyright PROTO C :VARARG
fill_fopen64_filefunc PROTO :QWORD
fill_fopen_filefunc PROTO :QWORD
fill_zlib_filefunc64_32_def_from_filefunc32 PROTO :QWORD,:QWORD
get_crc_table PROTO 
gz_error PROTO :QWORD,:QWORD,:QWORD
gzbuffer PROTO file:QWORD,dwsize:QWORD
gzclearerr PROTO file:QWORD
gzclose PROTO file:QWORD
gzclose_r PROTO file:QWORD
gzclose_w PROTO file:QWORD
gzdirect PROTO file:QWORD
gzdopen PROTO :QWORD,:QWORD
gzeof PROTO file:QWORD
gzerror PROTO file:QWORD,errnum:QWORD
gzflush PROTO file:QWORD,flush:QWORD
gzfread PROTO buf:QWORD,dwsize:QWORD,nitems:QWORD,file:QWORD
gzfwrite PROTO buf:QWORD,dwsize:QWORD,nitems:QWORD,file:QWORD
gzgetc PROTO file:QWORD
gzgetc_ PROTO :QWORD
gzgets PROTO file:QWORD,buf:QWORD,len:QWORD
gzoffset64 PROTO :QWORD
gzoffset PROTO :QWORD
gzopen64 PROTO :QWORD,:QWORD
gzopen PROTO fd:QWORD,mode:QWORD
gzopen_w PROTO :QWORD,:QWORD
gzprintf PROTO C :VARARG
gzputc PROTO file:QWORD,char:QWORD
gzputs PROTO file:QWORD,s:QWORD
gzread PROTO file:QWORD,buf:QWORD,len:QWORD
gzrewind PROTO file:QWORD
gzseek64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
gzseek PROTO :QWORD,:QWORD,:QWORD
gzsetparams PROTO file:QWORD,level:QWORD,strategy:QWORD
gztell64 PROTO :QWORD
gztell PROTO :QWORD
gzungetc PROTO :QWORD,:QWORD
gzvprintf PROTO C :VARARG
gzwrite PROTO file:QWORD,buf:QWORD,len:QWORD
inflate PROTO strm:QWORD,flush:QWORD
inflateBack PROTO strm:QWORD,in_func:QWORD,in_desc:QWORD,out_func:QWORD,out_desc:QWORD
inflateBackEnd PROTO strm:QWORD
inflateBackInit_ PROTO strm:QWORD,windowBits:QWORD,window:QWORD,version:QWORD,stream_size:QWORD
inflateCodesUsed PROTO :QWORD
inflateCopy PROTO dest:QWORD,source:QWORD
inflateEnd PROTO strm:QWORD
inflateGetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
inflateGetHeader PROTO strm:QWORD,head:QWORD
inflateInit2_ PROTO strm:QWORD,windowBits:QWORD,version:QWORD,stream_size:QWORD
inflateInit_ PROTO strm:QWORD,version:QWORD,stream_size:QWORD
inflateMark PROTO strm:QWORD
inflatePrime PROTO strm:QWORD,bits:QWORD,value:QWORD
inflateReset2 PROTO strm:QWORD,windowBits:QWORD
inflateReset PROTO strm:QWORD
inflateResetKeep PROTO :QWORD
inflateSetDictionary PROTO strm:QWORD,dictionary:QWORD,dictLength:QWORD
inflateSync PROTO strm:QWORD
inflateSyncPoint PROTO :QWORD
inflateUndermine PROTO :QWORD,:QWORD
inflateValidate PROTO :QWORD,:QWORD
inflate_copyright PROTO C :VARARG
inflate_fast PROTO :QWORD,:QWORD
inflate_table PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
snprintf PROTO C :VARARG
uncompress2 PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
uncompress PROTO dest:QWORD,destLen:QWORD,source:QWORD,sourceLen:QWORD
unzClose PROTO :QWORD
unzCloseCurrentFile PROTO :QWORD
unzGetCurrentFileInfo64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
unzGetCurrentFileInfo PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
unzGetCurrentFileZStreamPos64 PROTO :QWORD
unzGetFilePos64 PROTO :QWORD,:QWORD
unzGetFilePos PROTO :QWORD,:QWORD
unzGetGlobalComment PROTO :QWORD,:QWORD,:QWORD
unzGetGlobalInfo64 PROTO :QWORD,:QWORD
unzGetGlobalInfo PROTO :QWORD,:QWORD
unzGetLocalExtrafield PROTO :QWORD,:QWORD,:QWORD
unzGetOffset64 PROTO :QWORD
unzGetOffset PROTO :QWORD
unzGoToFilePos64 PROTO :QWORD,:QWORD
unzGoToFilePos PROTO :QWORD,:QWORD
unzGoToFirstFile PROTO :QWORD
unzGoToNextFile PROTO :QWORD
unzLocateFile PROTO :QWORD,:QWORD,:QWORD
unzOpen2 PROTO :QWORD,:QWORD
unzOpen2_64 PROTO :QWORD,:QWORD
unzOpen64 PROTO :QWORD
unzOpen PROTO :QWORD
unzOpenCurrentFile2 PROTO :QWORD,:QWORD,:QWORD,:QWORD
unzOpenCurrentFile3 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
unzOpenCurrentFile PROTO :QWORD
unzOpenCurrentFilePassword PROTO :QWORD,:QWORD
unzReadCurrentFile PROTO :QWORD,:QWORD,:QWORD
unzSetOffset64 PROTO :QWORD,:QWORD,:QWORD
unzSetOffset PROTO :QWORD,:QWORD
unzStringFileNameCompare PROTO :QWORD,:QWORD,:QWORD
unz_copyright PROTO C :VARARG
unzeof PROTO :QWORD
unztell64 PROTO :QWORD
unztell PROTO :QWORD
zError PROTO :QWORD
z_errmsg PROTO C :VARARG
zcalloc PROTO :QWORD,:QWORD,:QWORD
zcfree PROTO :QWORD,:QWORD
zipClose PROTO :QWORD,:QWORD
zipCloseFileInZip PROTO :QWORD
zipCloseFileInZipRaw64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
zipCloseFileInZipRaw PROTO :QWORD,:QWORD,:QWORD
zipOpen2 PROTO :QWORD,:QWORD,:QWORD,:QWORD
zipOpen2_64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
zipOpen3 PROTO :QWORD,:QWORD,:QWORD,:QWORD
zipOpen64 PROTO :QWORD,:QWORD
zipOpen PROTO :QWORD,:QWORD
zipOpenNewFileInZip2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip2_64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip3 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip3_64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip4 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip4_64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip64 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipOpenNewFileInZip PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
zipRemoveExtraInfoBlock PROTO :QWORD,:QWORD,:QWORD
zipWriteInFileInZip PROTO :QWORD,:QWORD,:QWORD
zip_copyright PROTO C :VARARG
zlibCompileFlags PROTO 
zlibVersion PROTO 


;--------------------Structures-----------------------------
;internal_state     STRUCT 
;dummy              DWORD ?
;internal_state     ENDS

zlib_filefunc_def               STRUCT 8
    zopen_file                  QWORD ?
    zread_file                  QWORD ?
    zwrite_file                 QWORD ?
    ztell_file                  QWORD ?
    zseek_file                  QWORD ?
    zclose_file                 QWORD ?
    zerror_file                 QWORD ?
    opaque                      QWORD ?
zlib_filefunc_def               ENDS

linkedlist_datablock_internal   STRUCT 8
    next_datablock              QWORD ? ;PTR linkedlist_datablock_internal
    avail_in_this_block         QWORD ?
    filled_in_this_block        QWORD ?
    unused                      QWORD ?
    data                        BYTE 4080 DUP (?)
linkedlist_datablock_internal   ENDS

linkedlist_data                 STRUCT 8
    first_block                 QWORD ? ;linkedlist_datablock_internal
    last_block                  QWORD ? ;linkedlist_datablock_internal
linkedlist_data                 ENDS

z_stream                        STRUCT 8
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
z_stream                        ENDS

gz_header                       STRUCT 8
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
    crc32_                      DWORD ?
curfile_info                    ENDS

zip_internal                    STRUCT 8
    z_filefunc                  zlib_filefunc_def <>
    filestream                  QWORD ?
    central_dir                 linkedlist_data <>
    in_opened_file_inzip        QWORD ?
    ci                          curfile_info <>
    begin_pos                   QWORD ?
    number_entry                QWORD ?
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
    crc32_                      DWORD ?
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