; Copyright (C) 1999-2020 Dieter Baron and Thomas Klausner
; 
; The authors can be contacted at <info@libzip.org>
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
; 1. Redistributions of source code must retain the above copyright
;   notice, this list of conditions and the following disclaimer.
; 
; 2. Redistributions in binary form must reproduce the above copyright
;   notice, this list of conditions and the following disclaimer in
;   the documentation and/or other materials provided with the
;   distribution.
; 
; 3. The names of the authors may not be used to endorse or promote
;   products derived from this software without specific prior
;   written permission.
; 
; THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY
; DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
; GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
; INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
; IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
; IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

; https://github.com/nih-at/libzip

; libzip_x86.inc converted from libzip source for assembler by fearless 2025
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

zip_add                             PROTO STDCALL archive:DWORD,filename:DWORD,source:DWORD
zip_add_dir                         PROTO STDCALL archive:DWORD,dirname:DWORD

zip_close                           PROTO STDCALL archive:DWORD
zip_compression_method_supported    PROTO STDCALL method:DWORD,bCompression:DWORD
zip_delete                          PROTO STDCALL archive:DWORD,index:QWORD
zip_dir_add                         PROTO STDCALL archive:DWORD,dirname:DWORD,flags:DWORD

zip_discard                         PROTO STDCALL archive:DWORD
zip_encryption_method_supported     PROTO STDCALL method:DWORD,bEncryption:DWORD
zip_error_clear                     PROTO STDCALL archive:DWORD
zip_error_code_system               PROTO STDCALL ze:DWORD
zip_error_code_zip                  PROTO STDCALL ze:DWORD
zip_error_fini                      PROTO STDCALL ze:DWORD
zip_error_get                       PROTO STDCALL archive:DWORD,zep:DWORD,sep:DWORD
zip_error_get_sys_type              PROTO STDCALL ze:DWORD
zip_error_init                      PROTO STDCALL error:DWORD
zip_error_init_with_code            PROTO STDCALL error:DWORD,ze:DWORD
zip_error_set                       PROTO STDCALL ze:DWORD,lec:DWORD,se:DWORD
zip_error_set_from_source           PROTO STDCALL ze:DWORD,src:DWORD
zip_error_strerror                  PROTO STDCALL ze:DWORD
zip_error_system_type               PROTO STDCALL ze:DWORD
zip_error_to_data                   PROTO STDCALL ze:DWORD,data:DWORD,len:QWORD
zip_error_to_str                    PROTO STDCALL buf:DWORD,len:QWORD,ze:DWORD,se:DWORD
zip_fclose                          PROTO STDCALL file:DWORD
zip_fdopen                          PROTO STDCALL fd:DWORD,flags:DWORD,errorp:DWORD
zip_file_add                        PROTO STDCALL archive:DWORD,filename:DWORD,source:DWORD, flags:DWORD
zip_file_attributes_init            PROTO STDCALL attributes:DWORD
zip_file_error_clear                PROTO STDCALL file:DWORD
zip_file_error_get                  PROTO STDCALL file:DWORD,zep:DWORD,sep:DWORD
zip_file_extra_field_delete         PROTO STDCALL archive:DWORD,index:QWORD,extra_field_index:DWORD,flags:DWORD
zip_file_extra_field_delete_by_id   PROTO STDCALL archive:DWORD,index:QWORD,extra_field_id:DWORD,extra_field_index:DWORD,flags:DWORD
zip_file_extra_field_get            PROTO STDCALL archive:DWORD,index:QWORD,extra_field_index:DWORD,idp:DWORD,lenp:DWORD,flags:DWORD
zip_file_extra_field_get_by_id      PROTO STDCALL archive:DWORD,index:QWORD,extra_field_id:DWORD,extra_field_index:DWORD,lenp:DWORD,flags:DWORD
zip_file_extra_field_set            PROTO STDCALL archive:DWORD,index:QWORD,extra_field_id:DWORD,extra_field_index:DWORD,extra_field_data:DWORD,len:DWORD,flags:DWORD
zip_file_extra_fields_count         PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD
zip_file_extra_fields_count_by_id   PROTO STDCALL archive:DWORD,index:QWORD,extra_field_id:DWORD,flags:DWORD
zip_file_get_comment                PROTO STDCALL archive:DWORD,index:QWORD,lenp:DWORD,flags:DWORD
zip_file_get_error                  PROTO STDCALL zf:DWORD
zip_file_get_external_attributes    PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD,opsys:DWORD,attributes:DWORD
zip_file_is_seekable                PROTO STDCALL file:DWORD
zip_file_rename                     PROTO STDCALL archive:DWORD,index:QWORD,filename:DWORD,flags:DWORD
zip_file_replace                    PROTO STDCALL archive:DWORD,index:QWORD,source:DWORD, flags:DWORD
zip_file_set_comment                PROTO STDCALL archive:DWORD,index:QWORD,szcomment:DWORD,len:DWORD,flags:DWORD
zip_file_set_dostime                PROTO STDCALL archive:DWORD,index:QWORD,dostime:DWORD,dosdate:DWORD,flags:DWORD
zip_file_set_encryption             PROTO STDCALL archive:DWORD,index:QWORD,method:DWORD,szpassword:DWORD
zip_file_set_external_attributes    PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD,opsys:DWORD,attributes:DWORD
zip_file_set_mtime                  PROTO STDCALL archive:DWORD,index:QWORD,mtime:QWORD,flags:DWORD
zip_file_strerror                   PROTO STDCALL file:DWORD
zip_fopen                           PROTO STDCALL archive:DWORD,filename:DWORD,flags:DWORD
zip_fopen_encrypted                 PROTO STDCALL archive:DWORD,filename:DWORD,flags:DWORD,szpassword:DWORD
zip_fopen_index                     PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD
zip_fopen_index_encrypted           PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD,szpassword:DWORD
zip_fread                           PROTO STDCALL file:DWORD,buf:DWORD,nbytes:QWORD
zip_fseek                           PROTO STDCALL file:DWORD,seekoffset:QWORD,whence:DWORD
zip_ftell                           PROTO STDCALL file:DWORD
zip_get_archive_comment             PROTO STDCALL archive:DWORD,lenp:DWORD,flags:DWORD
zip_get_archive_flag                PROTO STDCALL archive:DWORD,flag:DWORD,flags:DWORD
zip_get_error                       PROTO STDCALL archive:DWORD
zip_get_file_comment                PROTO STDCALL archive:DWORD,index:QWORD,lenp:DWORD,flags:DWORD
zip_get_name                        PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD;indexHi:DWORD,indexLO:DWORD,flags:DWORD
zip_get_num_entries                 PROTO STDCALL archive:DWORD,flags:DWORD
zip_get_num_files                   PROTO STDCALL archive:DWORD
zip_libzip_version                  PROTO STDCALL 
zip_name_locate                     PROTO STDCALL archive:DWORD,filename:DWORD,flags:DWORD
zip_open                            PROTO STDCALL path:DWORD,flags:DWORD,errorp:DWORD
zip_open_from_source                PROTO STDCALL zs:DWORD,flags:DWORD,ze:DWORD
zip_random_uint32                   PROTO STDCALL 
zip_realloc                         PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

zip_rename                          PROTO STDCALL archive:DWORD,index:QWORD,filename:DWORD
zip_replace                         PROTO STDCALL archive:DWORD,index:QWORD,source:DWORD
zip_secure_random                   PROTO STDCALL :DWORD,:DWORD
zip_set_archive_comment             PROTO STDCALL archive:DWORD,szcomment:DWORD,len:DWORD
zip_set_archive_flag                PROTO STDCALL archive:DWORD,flag:DWORD,value:DWORD
zip_set_default_password            PROTO STDCALL archive:DWORD,szpassword:DWORD
zip_set_file_comment                PROTO STDCALL archive:DWORD,index:QWORD,szcomment:DWORD,len:DWORD
zip_set_file_compression            PROTO STDCALL archive:DWORD,index:QWORD,comp:DWORD,comp_flags:DWORD
zip_source_accept_empty             PROTO STDCALL :DWORD
zip_source_begin_write              PROTO STDCALL source:DWORD
zip_source_begin_write_cloning      PROTO STDCALL source:DWORD,sourceoffset:QWORD
zip_source_buffer                   PROTO STDCALL archive:DWORD,data:DWORD,len:QWORD,freep:DWORD
zip_source_buffer_create            PROTO STDCALL data:DWORD,len:QWORD,freep:DWORD,error:DWORD
zip_source_buffer_fragment          PROTO STDCALL archive:DWORD,fragments:DWORD,nfragments:QWORD,freep:DWORD
zip_source_buffer_fragment_create   PROTO STDCALL fragments:DWORD,nfragments:QWORD,freep:DWORD,error:DWORD
zip_source_buffer_fragment_with_attributes_create PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_buffer_with_attributes   PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_buffer_with_attributes_create PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_close                    PROTO STDCALL source:DWORD
zip_source_commit_write             PROTO STDCALL source:DWORD
zip_source_compress                 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zip_source_crc_create               PROTO STDCALL :DWORD,:DWORD,:DWORD
zip_source_decompress               PROTO STDCALL :DWORD,:DWORD,:DWORD
zip_source_error                    PROTO STDCALL source:DWORD
zip_source_file                     PROTO STDCALL archive:DWORD,filename:DWORD,start:QWORD,len:QWORD
zip_source_file_common_new          PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_file_create              PROTO STDCALL filename:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_filep                    PROTO STDCALL archive:DWORD,file:DWORD,start:QWORD,len:QWORD
zip_source_filep_create             PROTO STDCALL file:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_free                     PROTO STDCALL source:DWORD
zip_source_function                 PROTO STDCALL archive:DWORD,source_callback:DWORD,userdata:DWORD
zip_source_function_create          PROTO STDCALL source_callback:DWORD,userdata:DWORD,error:DWORD
zip_source_get_dos_time             PROTO STDCALL :DWORD,:DWORD
zip_source_get_file_attributes      PROTO STDCALL :DWORD,:DWORD
zip_source_is_deleted               PROTO STDCALL source:DWORD
zip_source_is_seekable              PROTO STDCALL source:DWORD
zip_source_keep                     PROTO STDCALL source:DWORD
zip_source_layered                  PROTO STDCALL archive:DWORD,source:DWORD,source_layered_callback:DWORD,userdata:DWORD
zip_source_layered_create           PROTO STDCALL source:DWORD,source_layered_callback:DWORD,userdata:DWORD,error:DWORD

zip_source_open                     PROTO STDCALL source:DWORD
zip_source_pass_to_lower_layer      PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_pkware_decode            PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_pkware_encode            PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_source_read                     PROTO STDCALL source:DWORD,data:DWORD,len:QWORD
zip_source_remove                   PROTO STDCALL :DWORD
zip_source_rollback_write           PROTO STDCALL source:DWORD
zip_source_seek                     PROTO STDCALL source:DWORD,sourceoffset:QWORD,whence:DWORD
zip_source_seek_compute_offset      PROTO STDCALL sourceoffset:QWORD,sourcelength:QWORD,data:DWORD,data_length:QWORD,error:DWORD
zip_source_seek_write               PROTO STDCALL source:DWORD,sourceoffset:QWORD,whence:DWORD
zip_source_stat                     PROTO STDCALL source:DWORD,sb:DWORD
zip_source_supports                 PROTO STDCALL :DWORD
zip_source_supports_reopen          PROTO STDCALL :DWORD
zip_source_tell                     PROTO STDCALL source:DWORD
zip_source_tell_write               PROTO STDCALL source:DWORD
zip_source_win32a                   PROTO STDCALL archive:DWORD,filename:DWORD,start:QWORD,len:QWORD
zip_source_win32a_create            PROTO STDCALL filename:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_win32handle              PROTO STDCALL archive:DWORD,handle:DWORD,start:QWORD,len:QWORD
zip_source_win32handle_create       PROTO STDCALL handle:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_win32w                   PROTO STDCALL archive:DWORD,filename:DWORD,start:QWORD,len:QWORD
zip_source_win32w_create            PROTO STDCALL filename:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_window_create            PROTO STDCALL source:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_write                    PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
zip_source_zip                      PROTO STDCALL archive:DWORD,srcarchive:DWORD,srcidx:QWORD,flags:DWORD,start:QWORD,len:QWORD
zip_source_zip_create               PROTO STDCALL srcarchive:DWORD,srcidx:QWORD,flags:DWORD,start:QWORD,len:QWORD,error:DWORD
zip_source_zip_file                 PROTO STDCALL archive:DWORD,srcarchive:DWORD,srcidx:QWORD,flags:DWORD,start:QWORD,len:QWORD,szpassword:DWORD
zip_source_zip_file_create          PROTO STDCALL srcarchive:DWORD,srcidx:QWORD,flags:DWORD,start:QWORD,len:QWORD,szpassword:DWORD,error:DWORD
zip_stat                            PROTO STDCALL archive:DWORD,filename:DWORD,flags:DWORD,sb:DWORD
zip_stat_index                      PROTO STDCALL archive:DWORD,index:QWORD,flags:DWORD,sb:DWORD
zip_stat_init                       PROTO STDCALL sb:DWORD
zip_strerror                        PROTO STDCALL archive:DWORD
zip_unchange                        PROTO STDCALL archive:DWORD,index:QWORD
zip_unchange_all                    PROTO STDCALL archive:DWORD
zip_unchange_archive                PROTO STDCALL archive:DWORD

zip_register_cancel_callback_with_state PROTO STDCALL archive:DWORD,cancel_callback:DWORD,ud_free:DWORD,ud:DWORD
zip_register_progress_callback      PROTO STDCALL archive:DWORD,progress_callback:DWORD
zip_register_progress_callback_with_state PROTO STDCALL archive:DWORD,progression_state:QWORD,progress_callback:DWORD,ud_free:DWORD,ud:DWORD

zip_dirent_check_consistency        PROTO STDCALL :DWORD
zip_dirent_get_last_mod_mtime       PROTO STDCALL :DWORD
zip_dirent_process_ef_zip64         PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
zip_dirent_torrentzip_normalize     PROTO STDCALL :DWORD

zip_source_make_command_bitmap      PROTO C :VARARG
zip_algorithm_deflate_compress      PROTO C :VARARG
zip_algorithm_deflate_decompress    PROTO C :VARARG

; Typedefs
zip_int8_t              TYPEDEF BYTE
zip_uint8_t             TYPEDEF BYTE
zip_int16_t             TYPEDEF WORD
zip_uint16_t            TYPEDEF WORD
zip_int32_t             TYPEDEF DWORD
zip_uint32_t            TYPEDEF DWORD
zip_int64_t             TYPEDEF QWORD
zip_uint64_t            TYPEDEF QWORD

zip_t                   TYPEDEF DWORD
zip_file_t              TYPEDEF DWORD
zip_source_t            TYPEDEF DWORD
zip_error_t             TYPEDEF DWORD
zip_file_attributes_t   TYPEDEF PTR zip_file_attributes
zip_stats_t             TYPEDEF PTR zip_stats
zip_buffer_fragment_t   TYPEDEF PTR zip_buffer_fragment
zip_source_args_seek_t  TYPEDEF PTR zip_source_args_seek
zip_flags_t             TYPEDEF zip_uint32_t

; Structures

; for use by sources
zip_source_args_seek    STRUCT 8
    sourceoffset        zip_int64_t ?
    whence              DWORD ? ; int
zip_source_args_seek    ENDS

; error information
; use zip_error_*() to access
zip_error               STRUCT
    zip_err             DWORD ? ; int ; libzip error code (ZIP_ER_*)
    sys_err             DWORD ? ; int ; ; copy of errno (E*) or zlib error code
    string              DWORD ? ; char *_Nullable str; ; string representation or NULL
zip_error               ENDS

zip_stats               STRUCT 8
    valid               zip_uint64_t ? ; which fields have valid values
    filename            DWORD ? ; const char *_Nullable ; name of the file
    index               zip_uint64_t ? ; index within archive
    uncomp_size         zip_uint64_t ? ; size of file (uncompressed)
    comp_size           zip_uint64_t ? ; size of file (compressed)
    mtime               QWORD ? ; time_t ? ; modification time
    filecrc             zip_uint32_t ? ; crc of file data
    comp_method         zip_uint16_t ? ; compression method used
    encryption_method   zip_uint16_t ? ; encryption method used
    flags               zip_uint32_t ? ; reserved for future use
zip_stats               ENDS

zip_buffer_fragment     STRUCT 8
    data                DWORD ? ; zip_uint8_t *_Nonnull ;
    len                 zip_uint64_t  ? ; length
zip_buffer_fragment     ENDS

zip_file_attributes     STRUCT 8
    valid               zip_uint64_t ? ; which fields have valid values
    version             zip_uint8_t ? ; version of this struct, currently 1
    host_system         zip_uint8_t ? ; host system on which file was created
    ascii               zip_uint8_t ? ; flag whether file is ASCII text
    version_needed      zip_uint8_t ? ; minimum version needed to extract file
    external_file_attributes    zip_uint32_t ? ; external file attributes (host-system specific)
    general_purpose_bit_flags   zip_uint16_t ? ; general purpose big flags, only some bits are honored
    general_purpose_bit_mask    zip_uint16_t ? ; which bits in general_purpose_bit_flags are valid
zip_file_attributes     ENDS




.CONST
LIBZIP_VERSION          TEXTEQU <"1.11.3">
LIBZIP_VERSION_MAJOR    EQU 1
LIBZIP_VERSION_MINOR    EQU 11
LIBZIP_VERSION_MICRO    EQU 3

; flags for zip_open
ZIP_CREATE              EQU 1
ZIP_EXCL                EQU 2
ZIP_CHECKCONS           EQU 4
ZIP_TRUNCATE            EQU 8
ZIP_RDONLY              EQU 16

; flags for zip_name_locate, zip_fopen, zip_stat, ...
ZIP_FL_NOCASE           EQU 1   ; ignore case on name lookup
ZIP_FL_NODIR            EQU 2   ; ignore directory component
ZIP_FL_COMPRESSED       EQU 4   ; read compressed data
ZIP_FL_UNCHANGED        EQU 8   ; use original data, ignoring changes
;                       EQU 16  ; was ZIP_FL_RECOMPRESS, which is deprecated
ZIP_FL_ENCRYPTED        EQU 32  ; read encrypted data (implies ZIP_FL_COMPRESSED)
ZIP_FL_ENC_GUESS        EQU 0   ; guess string encoding (is default)
ZIP_FL_ENC_RAW          EQU 64  ; get unmodified string
ZIP_FL_ENC_STRICT       EQU 128 ; follow specification strictly
ZIP_FL_LOCAL            EQU 256 ; in local header
ZIP_FL_CENTRAL          EQU 512 ; in central directory
;                       EQU 1024; reserved for internal use
ZIP_FL_ENC_UTF_8        EQU 2048; string is UTF-8 encoded
ZIP_FL_ENC_CP437        EQU 4096; string is CP437 encoded
ZIP_FL_OVERWRITE        EQU 8192; zip_file_add: if file with name exists, overwrite (replace) it

; archive global flags flags
ZIP_AFL_RDONLY          EQU 2   ; read only -- cannot be cleared
ZIP_AFL_IS_TORRENTZIP	EQU 4   ; current archive is torrentzipped
ZIP_AFL_WANT_TORRENTZIP	EQU 8   ; write archive in torrentzip format
ZIP_AFL_CREATE_OR_KEEP_FILE_FOR_EMPTY_ARCHIVE EQU 16 ; don't remove file if archive is empty

; libzip error codes
ZIP_ER_OK               EQU 0   ; N No error
ZIP_ER_MULTIDISK        EQU 1   ; N Multi-disk zip archives not supported
ZIP_ER_RENAME           EQU 2   ; S Renaming temporary file failed
ZIP_ER_CLOSE            EQU 3   ; S Closing zip archive failed
ZIP_ER_SEEK             EQU 4   ; S Seek error
ZIP_ER_READ             EQU 5   ; S Read error
ZIP_ER_WRITE            EQU 6   ; S Write error
ZIP_ER_CRC              EQU 7   ; N CRC error
ZIP_ER_ZIPCLOSED        EQU 8   ; N Containing zip archive was closed
ZIP_ER_NOENT            EQU 9   ; N No such file
ZIP_ER_EXISTS           EQU 10  ; N File already exists
ZIP_ER_OPEN             EQU 11  ; S Can't open file
ZIP_ER_TMPOPEN          EQU 12  ; S Failure to create temporary file
ZIP_ER_ZLIB             EQU 13  ; Z Zlib error
ZIP_ER_MEMORY           EQU 14  ; N Malloc failure
ZIP_ER_CHANGED          EQU 15  ; N Entry has been changed
ZIP_ER_COMPNOTSUPP      EQU 16  ; N Compression method not supported
ZIP_ER_EOF              EQU 17  ; N Premature end of file
ZIP_ER_INVAL            EQU 18  ; N Invalid argument
ZIP_ER_NOZIP            EQU 19  ; N Not a zip archive
ZIP_ER_INTERNAL         EQU 20  ; N Internal error
ZIP_ER_INCONS           EQU 21  ; L Zip archive inconsistent
ZIP_ER_REMOVE           EQU 22  ; S Can't remove file
ZIP_ER_DELETED          EQU 23  ; N Entry has been deleted
ZIP_ER_ENCRNOTSUPP      EQU 24  ; N Encryption method not supported
ZIP_ER_RDONLY           EQU 25  ; N Read-only archive
ZIP_ER_NOPASSWD         EQU 26  ; N No password provided
ZIP_ER_WRONGPASSWD      EQU 27  ; N Wrong password provided
ZIP_ER_OPNOTSUPP        EQU 28  ; N Operation not supported
ZIP_ER_INUSE            EQU 29  ; N Resource still in use
ZIP_ER_TELL             EQU 30  ; S Tell error
ZIP_ER_COMPRESSED_DATA  EQU 31  ; N Compressed data invalid
ZIP_ER_CANCELLED        EQU 32  ; N Operation cancelled
ZIP_ER_DATA_LENGTH      EQU 33  ; N Unexpected length of data
ZIP_ER_NOT_ALLOWED      EQU 34  ; N Not allowed in torrentzip
ZIP_ER_TRUNCATED_ZIP    EQU 35  ; N Possibly truncated or corrupted zip archive

; type of system error value
ZIP_ET_NONE             EQU 0   ; sys_err unused
ZIP_ET_SYS              EQU 1   ; sys_err is errno
ZIP_ET_ZLIB             EQU 2   ; sys_err is zlib error code
ZIP_ET_LIBZIP           EQU 3   ; sys_err is libzip error code

; compression methods
ZIP_CM_DEFAULT          EQU -1  ; better of deflate or store
ZIP_CM_STORE            EQU 0   ; stored (uncompressed)
ZIP_CM_SHRINK           EQU 1   ; shrunk
ZIP_CM_REDUCE_1         EQU 2   ; reduced with factor 1
ZIP_CM_REDUCE_2         EQU 3   ; reduced with factor 2
ZIP_CM_REDUCE_3         EQU 4   ; reduced with factor 3
ZIP_CM_REDUCE_4         EQU 5   ; reduced with factor 4
ZIP_CM_IMPLODE          EQU 6   ; imploded
;                       EQU 7   ; Reserved for Tokenizing compression algorithm
ZIP_CM_DEFLATE          EQU 8   ; deflated
ZIP_CM_DEFLATE64        EQU 9   ; deflate64
ZIP_CM_PKWARE_IMPLODE   EQU 10  ; PKWARE imploding
;                       EQU 1   ; Reserved by PKWARE
ZIP_CM_BZIP2            EQU 12  ; compressed using BZIP2 algorithm
;                       EQU 13  ; Reserved by PKWARE
ZIP_CM_LZMA             EQU 14  ; LZMA (EFS)
;                       EQU 15  ; Reserved by PKWARE
;                       EQU 16  ; Reserved by PKWARE
;                       EQU 17  ; Reserved by PKWARE
ZIP_CM_TERSE            EQU 18  ; compressed using IBM TERSE (new)
ZIP_CM_LZ77             EQU 19  ; IBM LZ77 z Architecture (PFS)
;                       EQU 20  ; old value for Zstandard
ZIP_CM_LZMA2            EQU 33
ZIP_CM_ZSTD             EQU 93  ; Zstandard compressed data
ZIP_CM_XZ               EQU 95  ; XZ compressed data
ZIP_CM_JPEG             EQU 96  ; Compressed Jpeg data
ZIP_CM_WAVPACK          EQU 97  ; WavPack compressed data
ZIP_CM_PPMD             EQU 98  ; PPMd version I, Rev 1

; encryption methods
ZIP_EM_NONE             EQU 0   ; not encrypted
ZIP_EM_TRAD_PKWARE      EQU 1   ; traditional PKWARE encryption
ZIP_EM_DES              EQU 6601h  ; strong encryption: DES
ZIP_EM_RC2_OLD          EQU 6602h  ; strong encryption: RC2, version < 5.2
ZIP_EM_3DES_168         EQU 6603h
ZIP_EM_3DES_112         EQU 6609h
ZIP_EM_PKZIP_AES_128    EQU 660eh
ZIP_EM_PKZIP_AES_192    EQU 660fh
ZIP_EM_PKZIP_AES_256    EQU 6610h
ZIP_EM_RC2              EQU 6702h  ; strong encryption: RC2, version >= 5.2
ZIP_EM_RC4              EQU 6801h
ZIP_EM_AES_128          EQU 0101h  ; Winzip AES encryption
ZIP_EM_AES_192          EQU 0102h
ZIP_EM_AES_256          EQU 0103h
ZIP_EM_UNKNOWN          EQU 0ffffh  ; unknown algorithm

ZIP_OPSYS_DOS           EQU 00h
ZIP_OPSYS_AMIGA         EQU 01h
ZIP_OPSYS_OPENVMS       EQU 02h
ZIP_OPSYS_UNIX          EQU 03h
ZIP_OPSYS_VM_CMS        EQU 04h
ZIP_OPSYS_ATARI_ST      EQU 05h
ZIP_OPSYS_OS_2          EQU 06h
ZIP_OPSYS_MACINTOSH     EQU 07h
ZIP_OPSYS_Z_SYSTEM      EQU 08h
ZIP_OPSYS_CPM           EQU 09h
ZIP_OPSYS_WINDOWS_NTFS  EQU 0ah
ZIP_OPSYS_MVS           EQU 0bh
ZIP_OPSYS_VSE           EQU 0ch
ZIP_OPSYS_ACORN_RISC    EQU 0dh
ZIP_OPSYS_VFAT          EQU 0eh
ZIP_OPSYS_ALTERNATE_MVS EQU 0fh
ZIP_OPSYS_BEOS          EQU 10h
ZIP_OPSYS_TANDEM        EQU 11h
ZIP_OPSYS_OS_400        EQU 12h
ZIP_OPSYS_OS_X          EQU 13h
    
ZIP_OPSYS_DEFAULT       EQU ZIP_OPSYS_UNIX


; zip_source_cmd
ZIP_SOURCE_OPEN                EQU 0   ; prepare for reading
ZIP_SOURCE_READ                EQU 1   ; read data
ZIP_SOURCE_CLOSE               EQU 2   ; reading is done
ZIP_SOURCE_STAT                EQU 3   ; get meta information
ZIP_SOURCE_ERROR               EQU 4   ; get error information
ZIP_SOURCE_FREE                EQU 5   ; cleanup and free resources
ZIP_SOURCE_SEEK                EQU 6   ; set position for reading
ZIP_SOURCE_TELL                EQU 7   ; get read position
ZIP_SOURCE_BEGIN_WRITE         EQU 8   ; prepare for writing
ZIP_SOURCE_COMMIT_WRITE        EQU 9   ; writing is done
ZIP_SOURCE_ROLLBACK_WRITE      EQU 10  ; discard written changes
ZIP_SOURCE_WRITE               EQU 11  ; write data
ZIP_SOURCE_SEEK_WRITE          EQU 12  ; set position for writing
ZIP_SOURCE_TELL_WRITE          EQU 13  ; get write position
ZIP_SOURCE_SUPPORTS            EQU 14  ; check whether source supports command
ZIP_SOURCE_REMOVE              EQU 15  ; remove file
ZIP_SOURCE_RESERVED_1          EQU 16  ; previously used internally
ZIP_SOURCE_BEGIN_WRITE_CLONING EQU 17  ; like ZIP_SOURCE_BEGIN_WRITE  but keep part of original file
ZIP_SOURCE_ACCEPT_EMPTY        EQU 18  ; whether empty files are valid archives
ZIP_SOURCE_GET_FILE_ATTRIBUTES EQU 19  ; get additional file attributes
ZIP_SOURCE_SUPPORTS_REOPEN     EQU 20  ; allow reading from changed entry
ZIP_SOURCE_GET_DOS_TIME        EQU 21  ; get last modification time in DOS format


ZIP_STAT_NAME              EQU 0001h
ZIP_STAT_INDEX             EQU 0002h
ZIP_STAT_SIZE              EQU 0004h
ZIP_STAT_COMP_SIZE         EQU 0008h
ZIP_STAT_MTIME             EQU 0010h
ZIP_STAT_CRC               EQU 0020h
ZIP_STAT_COMP_METHOD       EQU 0040h
ZIP_STAT_ENCRYPTION_METHOD EQU 0080h
ZIP_STAT_FLAGS             EQU 0100h

ZIP_FILE_ATTRIBUTES_HOST_SYSTEM               EQU 0001h
ZIP_FILE_ATTRIBUTES_ASCII                     EQU 0002h
ZIP_FILE_ATTRIBUTES_VERSION_NEEDED            EQU 0004h
ZIP_FILE_ATTRIBUTES_EXTERNAL_FILE_ATTRIBUTES  EQU 0008h
ZIP_FILE_ATTRIBUTES_GENERAL_PURPOSE_BIT_FLAGS EQU 0010h

ZIP_EXTRA_FIELD_ALL         EQU 0ffffh ; ZIP_UINT16_MAX
ZIP_EXTRA_FIELD_NEW         EQU 0ffffh ; ZIP_UINT16_MAX

ZIP_SEEK_SET   EQU 0 ; Seek from beginning of file.
ZIP_SEEK_CUR   EQU 1 ; Seek from current position.
ZIP_SEEK_END   EQU 2 ; Set file pointer to EOF.
