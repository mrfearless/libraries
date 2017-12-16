; zlib x86 Library

; zlib.h -- interface of the 'zlib' general purpose compression library
;  version 1.2.11, January 15th, 2017
;
;  Copyright (C) 1995-2017 Jean-loup Gailly and Mark Adler
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
;  Comments) 1950 to 1952 in the files http://tools.ietf.org/html/rfc1950
;  (zlib format), rfc1951 (deflate format) and rfc1952 (gzip format).
;

; Converted to x86 assembler format from zlib source files by fearless 2017

include     msvcrt.inc
includelib  msvcrt.lib

; WARNING!!!
; Gz functions supported but in order to use them you should link with  C runtime libraries


; basic functions
zlibVersion             PROTO                                                           ; const char * ZEXPORT zlibVersion OF((void));
deflateInit             PROTO :DWORD,:DWORD                                             ; int ZEXPORT deflateInit OF((z_streamp strm, int level));
deflate                 PROTO :DWORD,:DWORD                                             ; int ZEXPORT deflate OF((z_streamp strm, int flush));
deflateEnd              PROTO :DWORD                                                    ; int ZEXPORT deflateEnd OF((z_streamp strm));
inflateInit             PROTO :DWORD                                                    ; int ZEXPORT inflateInit OF((z_streamp strm));
inflate                 PROTO :DWORD,:DWORD                                             ; int ZEXPORT inflate OF((z_streamp strm, int flush));
inflateEnd              PROTO :DWORD                                                    ; int ZEXPORT inflateEnd OF((z_streamp strm));
deflateInit2            PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD                 ; int ZEXPORT deflateInit2 OF((z_streamp strm, int  level, int  method, int  windowBits, int  memLevel, int  strategy));
deflateSetDictionary    PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT deflateSetDictionary OF((z_streamp strm, const Bytef *dictionary, uInt  dictLength));
deflateGetDictionary    PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT deflateGetDictionary OF((z_streamp strm, Bytef *dictionary, uInt *dictLength));
deflateCopy             PROTO :DWORD,:DWORD                                             ; int ZEXPORT deflateCopy OF((z_streamp dest, z_streamp source));
deflateReset            PROTO :DWORD                                                    ; int ZEXPORT deflateReset OF((z_streamp strm));
deflateParams           PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT deflateParams OF((z_streamp strm, int level, int strategy));
deflateTune             PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; int ZEXPORT deflateTune OF((z_streamp strm, int good_length, int max_lazy, int nice_length, int max_chain));
deflateBound            PROTO :DWORD,:DWORD                                             ; uLong ZEXPORT deflateBound OF((z_streamp strm, uLong sourceLen));
deflatePending          PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT deflatePending OF((z_streamp strm, unsigned *pending, int *bits));
deflatePrime            PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT deflatePrime OF((z_streamp strm, int bits, int value));
deflateSetHeader        PROTO :DWORD,:DWORD                                             ; int ZEXPORT deflateSetHeader OF((z_streamp strm, gz_headerp head));
inflateInit2_           PROTO :DWORD,:DWORD                                             ; int ZEXPORT inflateInit2 OF((z_streamp strm, int windowBits));
inflateSetDictionary    PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT inflateSetDictionary OF((z_streamp strm, const Bytef *dictionary, uInt dictLength));
inflateGetDictionary    PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT inflateSetDictionary OF((z_streamp strm, Bytef *dictionary, uInt dictLength));
inflateSync             PROTO :DWORD                                                    ; int ZEXPORT inflateSync OF((z_streamp strm));
inflateCopy             PROTO :DWORD,:DWORD                                             ; int ZEXPORT inflateCopy OF((z_streamp dest, z_streamp source));
inflateReset            PROTO :DWORD                                                    ; int ZEXPORT inflateReset OF((z_streamp strm));
inflateReset2           PROTO :DWORD,:DWORD                                             ; int ZEXPORT inflateReset2 OF((z_streamp strm, int windowBits));
inflatePrime            PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT inflatePrime OF((z_streamp strm, int bits, int value));
inflateMark             PROTO :DWORD                                                    ; long ZEXPORT inflateMark OF((z_streamp strm));
inflateGetHeader        PROTO :DWORD,:DWORD                                             ; int ZEXPORT inflateGetHeader OF((z_streamp strm, gz_headerp head));
inflateBackInit         PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT inflateBackInit OF((z_streamp strm, int windowBits, unsigned char FAR *window));
inflateBack             PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; int ZEXPORT inflateBack OF((z_streamp strm, in_func in, void FAR *in_desc, out_func out, void FAR *out_desc));
inflateBackEnd          PROTO :DWORD                                                    ; int ZEXPORT inflateBackEnd OF((z_streamp strm));
zlibCompileFlags        PROTO                                                           ; uLong ZEXPORT zlibCompileFlags OF((void));


; utility functions
compress                PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; int ZEXPORT compress OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen));
compress2               PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; int ZEXPORT compress2 OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen, int level));
compressBound           PROTO :DWORD                                                    ; uLong ZEXPORT compressBound OF((uLong sourceLen));
uncompress              PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; int ZEXPORT uncompress OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong sourceLen));
uncompress2             PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; int ZEXPORT uncompress2 OF((Bytef *dest, uLongf *destLen, const Bytef *source, uLong *sourceLen));


; gzip file access functions
gzopen                  PROTO :DWORD,:DWORD                                             ; gzFile ZEXPORT gzopen OF((const char *path, const char *mode));
gzdopen                 PROTO :DWORD,:DWORD                                             ; gzFile ZEXPORT gzdopen OF((int fd, const char *mode));
gzbuffer                PROTO :DWORD,:DWORD                                             ; int ZEXPORT gzbuffer OF((gzFile file, unsigned size));
gzsetparams             PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT gzsetparams OF((gzFile file, int level, int strategy));
gzread                  PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT gzread OF((gzFile file, voidp buf, unsigned len));
gzfread                 PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; z_size_t ZEXPORT gzfread OF((voidp buf, z_size_t size, z_size_t nitems, gzFile file));
gzwrite                 PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT gzwrite OF((gzFile file, voidpc buf, unsigned len));
gzfwrite                PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; z_size_t ZEXPORT gzfwrite OF((voidpc buf, z_size_t size, z_size_t nitems, gzFile file));
;gzprintf
gzputs                  PROTO :DWORD,:DWORD                                             ; int ZEXPORT gzputs OF((gzFile file, const char *s));
gzgets                  PROTO :DWORD,:DWORD,:DWORD                                      ; char * ZEXPORT gzgets OF((gzFile file, char *buf, int len));
gzputc                  PROTO :DWORD,:DWORD                                             ; int ZEXPORT gzputc OF((gzFile file, int c));
gzgetc                  PROTO :DWORD                                                    ; int ZEXPORT gzgetc OF((gzFile file));
gzungetc                PROTO :DWORD,:DWORD                                             ; int ZEXPORT gzungetc OF((int c, gzFile file));
gzflush                 PROTO :DWORD,:DWORD                                             ; int ZEXPORT gzflush OF((gzFile file, int flush));
gzseek                  PROTO :DWORD,:DWORD,:DWORD                                      ; z_off_t ZEXPORT gzseek OF((gzFile file, z_off_t offset, int whence));
gzrewind                PROTO :DWORD                                                    ; int ZEXPORT    gzrewind OF((gzFile file));
gztell                  PROTO :DWORD                                                    ; z_off_t ZEXPORT    gztell OF((gzFile file));
gzoffset                PROTO :DWORD                                                    ; z_off_t ZEXPORT gzoffset OF((gzFile file));
gzeof                   PROTO :DWORD                                                    ; int ZEXPORT gzeof OF((gzFile file));
gzdirect                PROTO :DWORD                                                    ; int ZEXPORT gzdirect OF((gzFile file));
gzclose                 PROTO :DWORD                                                    ; int ZEXPORT    gzclose OF((gzFile file));
gzclose_r               PROTO :DWORD                                                    ; int ZEXPORT gzclose_r OF((gzFile file));
gzclose_w               PROTO :DWORD                                                    ; int ZEXPORT gzclose_w OF((gzFile file));
gzerror                 PROTO :DWORD,:DWORD                                             ; const char * ZEXPORT gzerror OF((gzFile file, int *errnum));
gzclearerr              PROTO :DWORD                                                    ; void ZEXPORT gzclearerr OF((gzFile file));


; checksum functions
adler32                 PROTO :DWORD,:DWORD,:DWORD                                      ; uLong ZEXPORT adler32 OF((uLong adler, const Bytef *buf, uInt len));
adler32_z               PROTO :DWORD,:DWORD,:DWORD                                      ; uLong ZEXPORT adler32_z OF((uLong adler, const Bytef *buf, z_size_t len));
adler32_combine         PROTO :DWORD,:DWORD,:DWORD                                      ; uLong ZEXPORT adler32_combine OF((uLong adler1, uLong adler2, z_off_t len2));
crc32                   PROTO :DWORD,:DWORD,:DWORD                                      ; uLong ZEXPORT crc32   OF((uLong crc, const Bytef *buf, uInt len));


; various hacks, don't look
deflateInit_            PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; ZEXTERN int ZEXPORT deflateInit_ OF((z_streamp strm, int level, const char *version, int stream_size));
inflateInit_            PROTO :DWORD,:DWORD,:DWORD                                      ; ZEXTERN int ZEXPORT inflateInit_ OF((z_streamp strm, const char *version, int stream_size));
deflateInit2_           PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; ZEXTERN int ZEXPORT deflateInit2_ OF((z_streamp strm, int level, int method, int windowBits, int memLevel, int strategy, const char *version, int stream_size));
inflateInit2_           PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; ZEXTERN int ZEXPORT inflateInit2_ OF((z_streamp strm, int windowBits, const char *version, int stream_size));
inflateBackInit_        PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; ZEXTERN int ZEXPORT inflateBackInit_ OF((z_streamp strm, int windowBits, unsigned char FAR *window, const char *version, int stream_size));
gzgetc_                 PROTO :DWORD                                                    ; int ZEXPORT gzgetc_ OF((gzFile file));  ; backward compatibility


; Large64 functions
gzopen64                PROTO :DWORD,:DWORD                                             ; ZEXTERN gzFile ZEXPORT gzopen64 OF((const char *, const char *));
gzseek64                PROTO :DWORD,:DWORD                                             ; ZEXTERN z_off64_t ZEXPORT gzseek64 OF((gzFile, z_off64_t, int));
gztell64                PROTO :DWORD                                                    ; ZEXTERN z_off64_t ZEXPORT gztell64 OF((gzFile));
gzoffset64              PROTO :DWORD                                                    ; ZEXTERN z_off64_t ZEXPORT gzoffset64 OF((gzFile));
adler32_combine64       PROTO :DWORD,:DWORD,:DWORD                                      ; ZEXTERN uLong ZEXPORT adler32_combine64 OF((uLong, uLong, z_off64_t));
crc32_combine64         PROTO :DWORD,:DWORD,:DWORD                                      ; ZEXTERN uLong ZEXPORT crc32_combine64 OF((uLong, uLong, z_off64_t));


; undocumented functions
zError                  PROTO :DWORD                                                    ; ZEXTERN const char   * ZEXPORT zError           OF((int));
inflateSyncPoint        PROTO :DWORD                                                    ; ZEXTERN int            ZEXPORT inflateSyncPoint OF((z_streamp));
get_crc_table           PROTO                                                           ; ZEXTERN const z_crc_t FAR * ZEXPORT get_crc_table    OF((void));
inflateUndermine        PROTO :DWORD,:DWORD                                             ; ZEXTERN int            ZEXPORT inflateUndermine OF((z_streamp, int));
inflateValidate         PROTO :DWORD,:DWORD                                             ; ZEXTERN int            ZEXPORT inflateValidate OF((z_streamp, int));
inflateCodesUsed        PROTO :DWORD                                                    ; ZEXTERN unsigned long  ZEXPORT inflateCodesUsed OF ((z_streamp));
inflateResetKeep        PROTO :DWORD                                                    ; ZEXTERN int            ZEXPORT inflateResetKeep OF((z_streamp));
deflateResetKeep        PROTO :DWORD                                                    ; ZEXTERN int            ZEXPORT deflateResetKeep OF((z_streamp));
gzopen_w                PROTO :DWORD                                                    ; ZEXTERN gzFile         ZEXPORT gzopen_w OF((const wchar_t *path, const char *mode));
;gzvprintf              PROTO :DWORD,:DWORD,:DWORD                                      ; ZEXTERN int            ZEXPORTVA gzvprintf Z_ARG((gzFile file, const char *format, va_list va));


; Unzip functions
unzStringFileNameCompare PROTO :DWORD,:DWORD,:DWORD                                     ; int ZEXPORT unzStringFileNameCompare OF ((const char* fileName1, const char* fileName2, int iCaseSensitivity));
unzOpen                 PROTO :DWORD                                                    ; unzFile ZEXPORT unzOpen OF((const char *path));
unzOpen64               PROTO :DWORD                                                    ; unzFile ZEXPORT unzOpen64 OF((const void *path));
unzOpen2                PROTO :DWORD,:DWORD                                             ; unzFile ZEXPORT unzOpen2 OF((const char *path, zlib_filefunc_def* pzlib_filefunc_def));
unzOpen2_64             PROTO :DWORD,:DWORD                                             ; unzFile ZEXPORT unzOpen2 OF((const char *path, zlib_filefunc64_def* pzlib_filefunc_def));
unzClose                PROTO :DWORD                                                    ; int ZEXPORT unzClose OF((unzFile file));
unzGetGlobalInfo        PROTO :DWORD,:DWORD                                             ; int ZEXPORT unzGetGlobalInfo OF((unzFile file, unz_global_info *pglobal_info));
unzGetGlobalInfo64      PROTO :DWORD,:DWORD                                             ; int ZEXPORT unzGetGlobalInfo OF((unzFile file, unz_global_info64 *pglobal_info));
unzGetGlobalComment     PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT unzGetGlobalComment OF((unzFile file, char *szComment, uLong uSizeBuf));
unzGoToFirstFile        PROTO :DWORD                                                    ; int ZEXPORT unzGoToFirstFile OF((unzFile file));
unzGoToNextFile         PROTO :DWORD                                                    ; int ZEXPORT unzGoToNextFile OF((unzFile file));
unzLocateFile           PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT unzLocateFile OF((unzFile file, const char *szFileName, int iCaseSensitivity));
unzGetCurrentFileInfo64 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; int ZEXPORT unzGetCurrentFileInfo64 OF((unzFile file, unz_file_info64 *pfile_info, char *szFileName, uLong fileNameBufferSize, void *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize));
unzGetCurrentFileInfo   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; int ZEXPORT unzGetCurrentFileInf OF((unzFile file, unz_file_info64 *pfile_info, char *szFileName, uLong fileNameBufferSize, void *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize));
unzGetCurrentFileZStreamPos64 PROTO :DWORD                                              ; ZPOS64_T ZEXPORT unzGetCurrentFileZStreamPos64 OF((unzFile file));
unzOpenCurrentFile      PROTO :DWORD                                                    ; int ZEXPORT unzOpenCurrentFile OF((unzFile file));
unzOpenCurrentFilePassword PROTO :DWORD,:DWORD                                          ; int ZEXPORT unzOpenCurrentFilePassword OF((unzFile file, const char* password));
unzOpenCurrentFile2     PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; int ZEXPORT unzOpenCurrentFile2 OF((unzFile file, int* method, int* level, int raw));
unzOpenCurrentFile3     PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD                        ; int ZEXPORT unzOpenCurrentFile2 OF((unzFile file, int* method, int* level, int raw, const char* password));
unzCloseCurrentFile     PROTO :DWORD                                                    ; int ZEXPORT unzCloseCurrentFile OF((unzFile file));
unzReadCurrentFile      PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT unzReadCurrentFile OF((unzFile file, voidp buf, unsigned len));
unztell                 PROTO :DWORD                                                    ; z_off_t ZEXPORT unztell OF((unzFile file));
unztell64               PROTO :DWORD                                                    ; ZPOS64_T ZEXPORT unztell64 OF((unzFile file));
unzeof                  PROTO :DWORD                                                    ; int ZEXPORT unzeof OF((unzFile file));
unzGetLocalExtrafield   PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT unzGetLocalExtrafield OF((unzFile file, voidp buf, unsigned len));
unzGetOffset64          PROTO :DWORD                                                    ; ZPOS64_T ZEXPORT unzGetOffset64 (unzFile file);
unzGetOffset            PROTO :DWORD                                                    ; uLong ZEXPORT unzGetOffset (unzFile file);
unzSetOffset64          PROTO :DWORD,:DWORD                                             ; int ZEXPORT unzSetOffset64 (unzFile file, ZPOS64_T pos);
unzSetOffset            PROTO :DWORD,:DWORD                                             ; int ZEXPORT unzSetOffset (unzFile file, uLong pos);


; Zip functions
zipOpen                 PROTO :DWORD,:DWORD                                             ; zipFile ZEXPORT zipOpen OF((const char *pathname, int append));
zipOpen64               PROTO :DWORD,:DWORD                                             ; zipFile ZEXPORT zipOpen64 OF((const void *pathname, int append));
zipOpen2                PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; zipFile ZEXPORT zipOpen2_64 OF((const void *pathname, int append, zipcharpc* globalcomment, zlib_filefunc_def* pzlib_filefunc_def));
zipOpen2_64             PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; zipFile ZEXPORT zipOpen2_64 OF((const void *pathname, int append, zipcharpc* globalcomment, zlib_filefunc64_def* pzlib_filefunc_def));
zipOpenNewFileInZip     PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level));
zipOpenNewFileInZip64   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level, int zip64));
zipOpenNewFileInZip2    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ;  int ZEXPORT zipOpenNewFileInZip2_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level, int raw);
zipOpenNewFileInZip2_64 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip2_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level, int raw, int zip64));
zipOpenNewFileInZip3    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip3_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment,int method, int level, int raw, int windowBits, int memLevel, int strategy, const char* password, uLong crcForCrypting));
zipOpenNewFileInZip3_64 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip3_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment,int method, int level, int raw, int windowBits, int memLevel, int strategy, const char* password, uLong crcForCrypting, int zip64));
zipOpenNewFileInZip4    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip4_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level, int raw, int windowBits, int memLevel, int strategy, const char* password, uLong crcForCrypting, uLong versionMadeBy, uLong flagBase));
zipOpenNewFileInZip4_64 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD ; int ZEXPORT zipOpenNewFileInZip4_64 OF((zipFile file, const char* filename, const zip_fileinfo* zipfi, const void* extrafield_local, uInt size_extrafield_local, const void* extrafield_global, uInt size_extrafield_global, const char* comment, int method, int level, int raw, int windowBits, int memLevel, int strategy, const char* password, uLong crcForCrypting, uLong versionMadeBy, uLong flagBase, int zip64));
zipWriteInFileInZip     PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT zipWriteInFileInZip OF((zipFile file, const void* buf, unsigned len));
zipCloseFileInZip       PROTO :DWORD                                                    ; int ZEXPORT zipCloseFileInZip OF((zipFile file));
zipCloseFileInZipRaw    PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT zipCloseFileInZipRaw OF((zipFile file, uLong uncompressed_size, uLong crc32));
zipCloseFileInZipRaw64  PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT zipCloseFileInZipRaw64 OF((zipFile file, ZPOS64_T uncompressed_size, uLong crc32));
zipClose                PROTO :DWORD,:DWORD                                             ; int ZEXPORT zipClose OF((zipFile file, const char* global_comment));
zipRemoveExtraInfoBlock PROTO :DWORD,:DWORD,:DWORD                                      ; int ZEXPORT zipRemoveExtraInfoBlock OF((char* pData, int* dataLen, short sHeader));


; ioapi functions
fopen_file_func         PROTO :DWORD,:DWORD,:DWORD                                      ; voidpf  ZCALLBACK fopen_file_func OF((voidpf opaque, const char* filename, int mode));
fread_file_func         PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; uLong   ZCALLBACK fread_file_func OF((voidpf opaque, voidpf stream, void* buf, uLong size));
fwrite_file_func        PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; uLong   ZCALLBACK fwrite_file_func OF((voidpf opaque, voidpf stream, const void* buf,uLong size));
ftell64_file_func       PROTO :DWORD,:DWORD                                             ; ZPOS64_T ZCALLBACK ftell64_file_func OF((voidpf opaque, voidpf stream));
fseek64_file_func       PROTO :DWORD,:DWORD,:DWORD,:DWORD                               ; long    ZCALLBACK fseek64_file_func OF((voidpf opaque, voidpf stream, ZPOS64_T offset, int origin));
fclose_file_func        PROTO :DWORD,:DWORD                                             ; int     ZCALLBACK fclose_file_func OF((voidpf opaque, voidpf stream));
ferror_file_func        PROTO :DWORD,:DWORD                                             ; int     ZCALLBACK ferror_file_func OF((voidpf opaque, voidpf stream));





;--------------------Structures-----------------------------
;internal_state     STRUCT 
;dummy      DWORD       ?
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
    data                        BYTE 4080t DUP (?)
linkedlist_datablock_internal   ENDS

linkedlist_data                 STRUCT 
    first_block                 DWORD       ? ;linkedlist_datablock_internal
    last_block                  DWORD       ? ;linkedlist_datablock_internal
linkedlist_data                 ENDS

z_stream                        STRUCT
    next_in                     DWORD ?
    avail_in                    DWORD ?
    total_in                    DWORD ?
    next_out                    DWORD ?
    avail_out                   DWORD ?
    total_out                   DWORD ?
    msg                         DWORD ?
    state                       DWORD ?
    zalloc                      DWORD ?
    zfree                       DWORD ?
    opaque                      DWORD ?
    data_type                   DWORD ?
    adler                       DWORD ?
    reserved                    DWORD ?
z_stream                        ENDS

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
    buffered_data               Byte 16384t DUP (?)
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
    z_filefunc                  zlib_filefunc_def   <>
    filestream                  DWORD ?
    compression_method          DWORD ?
    byte_before_the_zipfile     DWORD ?
    raw                         DWORD ?
file_in_zip_read_info           ENDS

unz_s                           STRUCT
    z_filefunc                  zlib_filefunc_def <>
    filestream                  DWORD ?
    gi                          unz_global_info  <>
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
ZLIB_VERSION                    TEXTEQU "1.2.11"
ZLIB_VERNUM                     EQU 12b0h
ZLIB_VER_MAJOR                  EQU 1
ZLIB_VER_MINOR                  EQU 2
ZLIB_VER_REVISION               EQU 11
ZLIB_VER_SUBREVISION            EQU 0

Z_NO_FLUSH                      EQU 0
Z_PARTIAL_FLUSH                 EQU 1
Z_SYNC_FLUSH                    EQU 2
Z_FULL_FLUSH                    EQU 3
Z_FINISH                        EQU 4
Z_BLOCK                         EQU 5
Z_TREES                         EQU 6

Z_OK                            EQU 0
Z_STREAM_END                    EQU 1
Z_NEED_DICT                     EQU 2
Z_ERRNO                         EQU (-1)
Z_STREAM_ERROR                  EQU (-2)
Z_DATA_ERROR                    EQU (-3)
Z_MEM_ERROR                     EQU (-4)
Z_BUF_ERROR                     EQU (-5)
Z_VERSION_ERROR                 EQU (-6)

Z_NO_COMPRESSION                EQU 0
Z_BEST_SPEED                    EQU 1
Z_BEST_COMPRESSION              EQU 9
Z_DEFAULT_COMPRESSION           EQU (-1)

Z_FILTERED                      EQU 1
Z_HUFFMAN_ONLY                  EQU 2
Z_RLE                           EQU 3
Z_FIXED                         EQU 4
Z_DEFAULT_STRATEGY              EQU 0

Z_BINARY                        EQU 0
Z_TEXT                          EQU 1
Z_ASCII                         EQU Z_TEXT ;for compatibility with 1.2.2 and earlier
Z_UNKNOWN                       EQU 2

Z_DEFLATED                      EQU 8
Z_NULL                          EQU 0


UNZ_OK                          EQU (0)
UNZ_END_OF_LIST_OF_FILE         EQU (-100)
UNZ_ERRNO                       EQU (Z_ERRNO)
UNZ_EOF                         EQU (0)
UNZ_PARAMERROR                  EQU (-102)
UNZ_BADZIPFILE                  EQU (-103)
UNZ_INTERNALERROR               EQU (-104)
UNZ_CRCERROR                    EQU (-105)

ZIP_OK                          EQU (0)
ZIP_EOF                         EQU (0)
ZIP_ERRNO                       EQU (Z_ERRNO)
ZIP_PARAMERROR                  EQU (-102)
ZIP_BADZIPFILE                  EQU (-103)
ZIP_INTERNALERROR               EQU (-104)


ZLIB_FILEFUNC_SEEK_CUR          EQU (1)
ZLIB_FILEFUNC_SEEK_END          EQU (2)
ZLIB_FILEFUNC_SEEK_SET          EQU (0)

ZLIB_FILEFUNC_MODE_READ         EQU (1)
ZLIB_FILEFUNC_MODE_WRITE        EQU (2)
ZLIB_FILEFUNC_MODE_READWRITEFILTER EQU (3)

ZLIB_FILEFUNC_MODE_EXISTING     EQU (4)
ZLIB_FILEFUNC_MODE_CREATE       EQU (8)

GZBUFSIZE                       EQU 8192
; gzip modes, also provide a little integrity check on the passed structure */
GZ_NONE                         EQU 0
GZ_READ                         EQU 7247
GZ_WRITE                        EQU 31153
GZ_APPEND                       EQU 1   ; mode set to GZ_WRITE after the file is opened */
; values for gz_state how */
LOOK                            EQU 0   ; look for a gzip header */
COPY                            EQU 1   ; copy input directly */
GZIP                            EQU 2   ; decompress a gzip stream */

APPEND_STATUS_CREATE            EQU (0)
APPEND_STATUS_CREATEAFTER       EQU (1)
APPEND_STATUS_ADDINZIP          EQU (2)


LENGTH_CODES                    EQU 29  ; number of length codes, not counting the special END_BLOCK code */
LITERALS                        EQU 256 ; number of literal bytes 0..255 */
L_CODES                         EQU (LITERALS+1+LENGTH_CODES); number of Literal or Length codes, including the END_BLOCK code */
D_CODES                         EQU 30  ; number of distance codes */
BL_CODES                        EQU 19  ; number of codes used to transfer the bit lengths */
HEAP_SIZE                       EQU (2*L_CODES+1); maximum heap size */
MAX_BITS                        EQU 15  ; All codes must not exceed MAX_BITS bits */
Buf_size                        EQU 16  ; size of bit buffer in bi_buf */
INIT_STATE                      EQU 42  ; zlib header -> BUSY_STATE */
GZIP_STATE                      EQU 57  ; gzip header -> BUSY_STATE | EXTRA_STATE */
EXTRA_STATE                     EQU 69  ; gzip extra block -> NAME_STATE */
NAME_STATE                      EQU 73  ; gzip file name -> COMMENT_STATE */
COMMENT_STATE                   EQU 91  ; gzip comment -> HCRC_STATE */
HCRC_STATE                      EQU 103 ; gzip header CRC -> BUSY_STATE */
BUSY_STATE                      EQU 113 ; deflate -> FINISH_STATE */
FINISH_STATE                    EQU 666 ; stream complete */

