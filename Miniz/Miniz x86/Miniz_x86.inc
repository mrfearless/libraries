; Copyright 2013-2014 RAD Game Tools and Valve Software
; Copyright 2010-2014 Rich Geldreich and Tenacious Software LLC
; 
; All Rights Reserved.
; 
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
; 
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
; 
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.

; https://github.com/richgel999/miniz
; 3.0.2 | 11.0.2
 
; miniz_x86.inc converted from miniz source for assembler by fearless 2025
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

; zlib-style API Definitions
mz_adler32       PROTO dwAdler:DWORD,memptr:DWORD,buf_len:DWORD
mz_compress2     PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD,level:DWORD
mz_compress      PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD
mz_compressBound PROTO source_len:DWORD
mz_crc32         PROTO dwCrc:DWORD,memptr:DWORD,buf_len:DWORD
mz_deflate       PROTO pStream:DWORD,flush:DWORD
mz_deflateBound  PROTO pStream:DWORD,source_len:DWORD
mz_deflateEnd    PROTO pStream:DWORD
mz_deflateInit2  PROTO pStream:DWORD,level:DWORD,method:DWORD,window_bits:DWORD,mem_level:DWORD,strategy:DWORD
mz_deflateInit   PROTO pStream:DWORD,level:DWORD
mz_deflateReset  PROTO pStream:DWORD
mz_error         PROTO err:DWORD
mz_free          PROTO p:DWORD
mz_inflate       PROTO pStream:DWORD,flush:DWORD
mz_inflateEnd    PROTO pStream:DWORD
mz_inflateInit2  PROTO pStream:DWORD,window_bits:DWORD
mz_inflateInit   PROTO pStream:DWORD
mz_inflateReset  PROTO pStream:DWORD
mz_uncompress    PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD
mz_version       PROTO 


; Low-level Compression API Definitions
tdefl_compress                             PROTO d:DWORD,pIn_buf:DWORD,pIn_buf_size:DWORD,pOut_buf:DWORD,pOut_buf_size:DWORD,flush:DWORD
tdefl_compress_buffer                      PROTO d:DWORD,pIn_buf:DWORD,in_buf_size:DWORD,flush:DWORD
tdefl_compress_mem_to_heap                 PROTO pSrc_buf:DWORD,src_buf_len:DWORD,pOut_len:DWORD,flags:DWORD
tdefl_compress_mem_to_mem                  PROTO pOut_buf:DWORD,out_buf_len:DWORD,pSrc_buf:DWORD,src_buf_len:DWORD,flags:DWORD
tdefl_compress_mem_to_output               PROTO pBuf:DWORD,buf_len:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tdefl_compressor_alloc                     PROTO 
tdefl_compressor_free                      PROTO pComp:DWORD
tdefl_create_comp_flags_from_zip_params    PROTO level:DWORD,window_bits:DWORD,strategy:DWORD
tdefl_get_adler32                          PROTO d:DWORD
tdefl_get_prev_return_status               PROTO d:DWORD
tdefl_init                                 PROTO d:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tdefl_write_image_to_png_file_in_memory    PROTO pImage:DWORD,w:DWORD,h:DWORD,num_chans:DWORD,pLen_out:DWORD
tdefl_write_image_to_png_file_in_memory_ex PROTO pImage:DWORD,w:DWORD,h:DWORD,num_chans:DWORD,pLen_out:DWORD,level:DWORD,flip:DWORD
tdefl_put_buf_func_ptr                     PROTO pBuf:DWORD, len:DWORD, pUser:DWORD ; proto for callback func


; Low-level Decompression API Definitions
tinfl_decompress                 PROTO r:DWORD,pIn_buf_next:DWORD,pIn_buf_size:DWORD,pOut_buf_start:DWORD,pOut_buf_next:DWORD,pOut_buf_size:DWORD,decomp_flags:DWORD
tinfl_decompress_mem_to_callback PROTO pIn_buf:DWORD,pIn_buf_size:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tinfl_decompress_mem_to_heap     PROTO pSrc_buf:DWORD,src_buf_len:DWORD,pOut_len:DWORD,flags:DWORD
tinfl_decompress_mem_to_mem      PROTO pOut_buf:DWORD,out_buf_len:DWORD,pSrc_buf:DWORD,src_buf_len:DWORD,flags:DWORD
tinfl_decompressor_alloc         PROTO 
tinfl_decompressor_free          PROTO pDecomp:DWORD
tinfl_put_buf_func_ptr           PROTO pBuf:DWORD, len:DWORD, pUser:DWORD ; proto for callback func


; ZIP archive reading/writing API Definitions

; ZIP reading
mz_zip_reader_init         PROTO pZip:DWORD,qwSize:QWORD,flags:DWORD
mz_zip_reader_init_cfile   PROTO pZip:DWORD,pFile:DWORD,archive_size:QWORD,flags:DWORD
mz_zip_reader_init_file    PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD
mz_zip_reader_init_file_v2 PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD,file_start_ofs:QWORD,archive_size:QWORD
mz_zip_reader_init_mem     PROTO pZip:DWORD,pMem:DWORD,dwSize:DWORD,flags:DWORD
mz_zip_reader_end          PROTO pZip:DWORD

; ZIP reading or writing
mz_zip_zero_struct                   PROTO pZip:DWORD
mz_zip_get_mode                      PROTO pZip:DWORD
mz_zip_get_type                      PROTO pZip:DWORD
mz_zip_reader_get_num_files          PROTO pZip:DWORD
mz_zip_get_archive_size              PROTO pZip:DWORD
mz_zip_get_archive_file_start_offset PROTO pZip:DWORD
mz_zip_get_cfile                     PROTO pZip:DWORD
mz_zip_read_archive_data             PROTO pZip:DWORD,file_ofs:QWORD,pBuf:DWORD,n:DWORD
mz_zip_set_last_error                PROTO pZip:DWORD,err_num:DWORD
mz_zip_peek_last_error               PROTO pZip:DWORD
mz_zip_clear_last_error              PROTO pZip:DWORD
mz_zip_get_last_error                PROTO pZip:DWORD
mz_zip_get_error_string              PROTO mz_err:DWORD
mz_zip_reader_is_file_a_directory    PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_is_file_encrypted      PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_is_file_supported      PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_get_filename           PROTO pZip:DWORD,file_index:DWORD,pFilename:DWORD,filename_buf_size:DWORD
mz_zip_reader_locate_file            PROTO pZip:DWORD,pName:DWORD,pComment:DWORD,flags:DWORD
mz_zip_reader_locate_file_v2         PROTO pZip:DWORD,pName:DWORD,pComment:DWORD,flags:DWORD,ptr_file_index:DWORD
mz_zip_reader_file_stat              PROTO pZip:DWORD,file_index:DWORD,pStat:DWORD
mz_zip_is_zip64                      PROTO pZip:DWORD
mz_zip_get_central_dir_size          PROTO pZip:DWORD
mz_zip_end                           PROTO :DWORD

mz_zip_reader_extract_file_iter_new        PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_callback     PROTO pZip:DWORD,pFilename:DWORD,pCallback:DWORD,pOpaque:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_cfile        PROTO pZip:DWORD,pArchive_filename:DWORD,pFile:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_file         PROTO pZip:DWORD,pArchive_filename:DWORD,pDst_filename:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_heap         PROTO pZip:DWORD,pFilename:DWORD,pSize:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_mem          PROTO pZip:DWORD,pFilename:DWORD,pBuf:DWORD,buf_size:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_mem_no_alloc PROTO pZip:DWORD,pFilename:DWORD,pBuf:DWORD,buf_size:DWORD,flags:DWORD,pUser_read_buf:DWORD,user_read_buf_size:DWORD
mz_zip_reader_extract_iter_free            PROTO pState:DWORD
mz_zip_reader_extract_iter_new             PROTO pZip:DWORD,file_index:DWORD,flags:DWORD
mz_zip_reader_extract_iter_read            PROTO pState:DWORD,pvBuf:DWORD,buf_size:DWORD
mz_zip_reader_extract_to_callback          PROTO pZip:DWORD,file_index:DWORD,pCallback:DWORD,pOpaque:DWORD,flags:DWORD
mz_zip_reader_extract_to_cfile             PROTO pZip:DWORD,file_index:DWORD,File:DWORD,flags:DWORD
mz_zip_reader_extract_to_file              PROTO pZip:DWORD,file_index:DWORD,pDst_filename:DWORD,flags:DWORD
mz_zip_reader_extract_to_heap              PROTO pZip:DWORD,file_index:DWORD,pSize:DWORD,flags:DWORD
mz_zip_reader_extract_to_mem               PROTO pZip:DWORD,file_index:DWORD,pBuf:DWORD,buf_size:DWORD,flags:DWORD
mz_zip_reader_extract_to_mem_no_alloc      PROTO pZip:DWORD,file_index:DWORD,pBuf:DWORD,buf_size:DWORD,flags:DWORD,pUser_read_buf:DWORD,user_read_buf_size:DWORD

; Misc utils/helpers, valid for ZIP reading or writing
mz_zip_validate_file         PROTO pZip:DWORD,file_index:DWORD,flags:DWORD
mz_zip_validate_archive      PROTO pZip:DWORD,flags:DWORD
mz_zip_validate_mem_archive  PROTO pMem:DWORD,dwSize:DWORD,flags:DWORD,pErr:DWORD
mz_zip_validate_file_archive PROTO pFilename:DWORD,flags:DWORD,pErr:DWORD

; ZIP writing
mz_zip_writer_add_cfile             PROTO pZip:DWORD,pArchive_name:DWORD,pSrc_file:DWORD,max_size:QWORD,pFile_time:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD,user_extra_data_local:DWORD,user_extra_data_local_len:DWORD,user_extra_data_central:DWORD,user_extra_data_central_len:DWORD
mz_zip_writer_add_file              PROTO pZip:DWORD,pArchive_name:DWORD,pSrc_filename:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD
mz_zip_writer_add_from_zip_reader   PROTO pZip:DWORD,pSource_zip:DWORD,src_file_index:DWORD
mz_zip_writer_add_mem               PROTO pZip:DWORD,pArchive_name:DWORD,pBuf:DWORD,buf_size:DWORD,level_and_flags:DWORD
mz_zip_writer_add_mem_ex            PROTO pZip:DWORD,pArchive_name:DWORD,pBuf:DWORD,buf_size:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD,uncomp_size:QWORD,uncomp_crc32:DWORD
mz_zip_writer_add_mem_ex_v2         PROTO pZip:DWORD,pArchive_name:DWORD,pBuf:DWORD,buf_size:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD,uncomp_size:QWORD,uncomp_crc32:DWORD,last_modified:DWORD,user_extra_data_local:DWORD,user_extra_data_local_len:DWORD,user_extra_data_central:DWORD,user_extra_data_central_len:DWORD
mz_zip_writer_add_read_buf_callback PROTO pZip:DWORD,pArchive_name:DWORD,read_callback:DWORD,callback_opaque:DWORD,max_size:QWORD,pFile_time:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD,user_extra_data_local:DWORD,user_extra_data_local_len:DWORD,user_extra_data_central:DWORD
mz_zip_writer_end                   PROTO pZip:DWORD
mz_zip_writer_finalize_archive      PROTO pZip:DWORD
mz_zip_writer_finalize_heap_archive PROTO pZip:DWORD,ppBuf:DWORD,pSize:DWORD
mz_zip_writer_init                  PROTO pZip:DWORD,existing_size:QWORD
mz_zip_writer_init_cfile            PROTO pZip:DWORD,pFile:DWORD,flags:DWORD
mz_zip_writer_init_file             PROTO pZip:DWORD,pFilename:DWORD,size_to_reserve_at_beginning:QWORD
mz_zip_writer_init_file_v2          PROTO pZip:DWORD,pFilename:DWORD,size_to_reserve_at_beginning:QWORD,flags:DWORD
mz_zip_writer_init_from_reader      PROTO pZip:DWORD,pFilename:DWORD
mz_zip_writer_init_from_reader_v2   PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD
mz_zip_writer_init_heap             PROTO pZip:DWORD,size_to_reserve_at_beginning:DWORD,initial_allocation_size:DWORD
mz_zip_writer_init_heap_v2          PROTO pZip:DWORD,size_to_reserve_at_beginning:DWORD,initial_allocation_size:DWORD,flags:DWORD
mz_zip_writer_init_v2               PROTO pZip:DWORD,existing_size:QWORD,flags:DWORD


; Misc. high-level helper functions
mz_zip_add_mem_to_archive_file_in_place    PROTO pZip_filename:DWORD,pArchive_name:DWORD,pBuf:DWORD,buf_size:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD
mz_zip_add_mem_to_archive_file_in_place_v2 PROTO pZip_filename:DWORD,pArchive_name:DWORD,pBuf:DWORD,buf_size:DWORD,pComment:DWORD,comment_size:DWORD,level_and_flags:DWORD,pErr:DWORD
mz_zip_extract_archive_file_to_heap        PROTO pZip_filename:DWORD,pArchive_name:DWORD,pSize:DWORD,flags:DWORD
mz_zip_extract_archive_file_to_heap_v2     PROTO pZip_filename:DWORD,pArchive_name:DWORD,pComment:DWORD,pSize:DWORD,flags:DWORD,pErr:DWORD

; Misc
miniz_def_alloc_func    PROTO :DWORD,:DWORD,:DWORD
miniz_def_free_func     PROTO :DWORD,:DWORD
miniz_def_realloc_func  PROTO :DWORD,:DWORD,:DWORD,:DWORD

mz_uint8                TYPEDEF BYTE  ; unsigned char 
mz_int16                TYPEDEF WORD  ; int16_t
mz_uint16               TYPEDEF WORD  ; uint16_t
mz_uint32               TYPEDEF DWORD ; uint32_t
mz_uint                 TYPEDEF DWORD ; uint32_t
mz_int64                TYPEDEF QWORD ; int64_t
mz_uint64               TYPEDEF QWORD ; uint64_t
mz_bool                 TYPEDEF DWORD ; int 
mz_zip_mode             TYPEDEF DWORD
mz_zip_flags            TYPEDEF DWORD
mz_zip_type             TYPEDEF DWORD
mz_zip_error            TYPEDEF DWORD
mz_alloc_func           TYPEDEF PTR
mz_free_func            TYPEDEF PTR
mz_realloc_func         TYPEDEF PTR
mz_file_read_func       TYPEDEF PTR
mz_file_write_func      TYPEDEF PTR
mz_file_needs_keepalive TYPEDEF PTR
IFNDEF size_t
size_t                  TYPEDEF DWORD
ENDIF
tinfl_bit_buf_t         TYPEDEF mz_uint32
;tdefl_put_buf_func_ptr  TYPEDEF PTR
tdefl_status            TYPEDEF DWORD
tdefl_flush             TYPEDEF DWORD

mz_dummy_time_t         STRUCT
    m_dummy1            mz_uint32 ?
    m_dummy2            mz_uint32 ?
mz_dummy_time_t         ENDS
MZ_TIME_T               STRUCT
    time1               mz_uint32 ?
    time2               mz_uint32 ?
MZ_TIME_T               ENDS

; mz_zip
MZ_ZIP_MAX_IO_BUF_SIZE               EQU (64 * 1024)
MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE     EQU 512
MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE EQU 512

mz_zip_archive_file_stat STRUCT 8
    ; Central directory file index.
    m_file_index        mz_uint32 ?
    ; Byte offset of this entry in the archive's central directory. Note we currently only support up to UINT_MAX or less bytes in the central dir.
    m_central_dir_ofs   mz_uint64 ?
    ; These fields are copied directly from the zip's central dir.
    m_version_made_by   mz_uint16 ?
    m_version_needed    mz_uint16 ?
    m_bit_flag          mz_uint16 ?
    m_method            mz_uint16 ?
    ; CRC-32 of uncompressed data.
    m_crc32             mz_uint32 ?
    ; File's compressed size.
    m_comp_size         mz_uint64 ?
    ; File's uncompressed size. Note, I've seen some old archives where directory entries had 512 bytes for their uncompressed sizes, but when you try to unpack them you actually get 0 bytes.
    m_uncomp_size       mz_uint64 ?
    ; Zip internal and external file attributes.
    m_internal_attr     mz_uint16 ?
    m_external_attr     mz_uint32 ?
    ; Entry's local header file offset in bytes.
    m_local_header_ofs  mz_uint64 ?
    ; Size of comment in bytes.
    m_comment_size      mz_uint32 ?
    ; MZ_TRUE if the entry appears to be a directory.
    m_is_directory      mz_bool ?
    ; MZ_TRUE if the entry uses encryption/strong encryption (which miniz_zip doesn't support)
    m_is_encrypted      mz_bool ?
    ; MZ_TRUE if the file is not encrypted, a patch file, and if it uses a compression method we support.
    m_is_supported      mz_bool ?
    ; Filename. If string ends in '/' it's a subdirectory entry.
    ; Guaranteed to be zero terminated, may be truncated to fit.
    m_filename          DB MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE DUP (?) ; char
    ; Comment field.
    ; Guaranteed to be zero terminated, may be truncated to fit.
    m_comment           DB MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE DUP (?) ; char
    m_time              MZ_TIME_T <>
mz_zip_archive_file_stat ENDS

mz_zip_archive          STRUCT 8
    m_archive_size      mz_uint64 ?
    m_central_directory_file_ofs mz_uint64 ?
    ; We only support up to UINT32_MAX files in zip64 mode. */
    m_total_files       mz_uint32 ?
    m_zip_mode          mz_zip_mode ?
    m_zip_type          mz_zip_type ?
    m_last_error        mz_zip_error ?
    m_file_offset_alignment mz_uint64 ?
    m_pAlloc            mz_alloc_func ?
    m_pFree             mz_free_func ?
    m_pRealloc          mz_realloc_func ?
    m_pAlloc_opaque     DWORD ? ; void *;
    m_pRead             mz_file_read_func ?
    m_pWrite            mz_file_write_func ?
    m_pNeeds_keepalive  mz_file_needs_keepalive ?
    m_pIO_opaque        DWORD ? ; void *;
    m_pState            DWORD ? ; mz_zip_internal_state *;
mz_zip_archive          ENDS

TINFL_MAX_HUFF_TABLES    EQU 3
TINFL_MAX_HUFF_SYMBOLS_0 EQU 288
TINFL_MAX_HUFF_SYMBOLS_1 EQU 32
TINFL_MAX_HUFF_SYMBOLS_2 EQU 19
TINFL_FAST_LOOKUP_BITS   EQU 10
TINFL_FAST_LOOKUP_SIZE   EQU 1 SHL TINFL_FAST_LOOKUP_BITS

tinfl_decompressor  STRUCT
    m_state         mz_uint32 ?
    m_num_bits      mz_uint32 ?
    m_zhdr0         mz_uint32 ?
    m_zhdr1         mz_uint32 ?
    m_z_adler32     mz_uint32 ?
    m_final         mz_uint32 ?
    m_type          mz_uint32 ?
    m_check_adler32 mz_uint32 ?
    m_dist          mz_uint32 ?
    m_counter       mz_uint32 ?
    m_num_extra     mz_uint32 ?
    m_table_sizes   mz_uint32 TINFL_MAX_HUFF_TABLES DUP (?)
    m_bit_buf       tinfl_bit_buf_t ?
    m_dist_from_out_buf_start size_t ?
    m_look_up       mz_int16 (TINFL_MAX_HUFF_TABLES * TINFL_FAST_LOOKUP_SIZE) DUP (?)
    m_tree_0        mz_int16 (TINFL_MAX_HUFF_SYMBOLS_0 * 2) DUP (?)
    m_tree_1        mz_int16 (TINFL_MAX_HUFF_SYMBOLS_1 * 2) DUP (?)
    m_tree_2        mz_int16 (TINFL_MAX_HUFF_SYMBOLS_2 * 2) DUP (?)
    m_code_size_0   mz_uint8 TINFL_MAX_HUFF_SYMBOLS_0 DUP (?)
    m_code_size_1   mz_uint8 TINFL_MAX_HUFF_SYMBOLS_1 DUP (?)
    m_code_size_2   mz_uint8 TINFL_MAX_HUFF_SYMBOLS_2 DUP (?)
    m_raw_header    mz_uint8 4 DUP (?)
    m_len_codes     mz_uint8 (TINFL_MAX_HUFF_SYMBOLS_0 + TINFL_MAX_HUFF_SYMBOLS_1 + 137) DUP (?)
tinfl_decompressor  ENDS

mz_zip_reader_extract_iter_state STRUCT
    pZip                DWORD ? ; mz_zip_archive *
    flags               mz_uint ? ;
    status              DWORD ? ; int 
    read_buf_size       mz_uint64 ?
    read_buf_ofs        mz_uint64 ?
    read_buf_avail      mz_uint64 ?
    comp_remaining      mz_uint64 ?
    out_buf_ofs         mz_uint64 ?
    cur_file_ofs        mz_uint64 ?
    file_stat           mz_zip_archive_file_stat <>
    pRead_buf           DWORD ? ; void *
    pWrite_buf          DWORD ? ; void *
    out_blk_remain      size_t ?
    inflator            tinfl_decompressor <>
    file_crc32          mz_uint ?
mz_zip_reader_extract_iter_state ENDS



TDEFL_MAX_HUFF_TABLES    EQU 3
TDEFL_MAX_HUFF_SYMBOLS_0 EQU 288
TDEFL_MAX_HUFF_SYMBOLS_1 EQU 32
TDEFL_MAX_HUFF_SYMBOLS_2 EQU 19
TDEFL_LZ_DICT_SIZE       EQU 32768
TDEFL_LZ_DICT_SIZE_MASK  EQU TDEFL_LZ_DICT_SIZE - 1
TDEFL_MIN_MATCH_LEN      EQU 3
TDEFL_MAX_MATCH_LEN      EQU 258

TDEFL_LZ_CODE_BUF_SIZE      EQU (64 * 1024)
TDEFL_OUT_BUF_SIZE          EQU ((TDEFL_LZ_CODE_BUF_SIZE * 13) / 10)
TDEFL_MAX_HUFF_SYMBOLS      EQU 288
TDEFL_LZ_HASH_BITS          EQU 15
TDEFL_LEVEL1_HASH_SIZE_MASK EQU 4095
TDEFL_LZ_HASH_SHIFT         EQU (TDEFL_LZ_HASH_BITS + 2) / 3
TDEFL_LZ_HASH_SIZE          EQU 1 SHL TDEFL_LZ_HASH_BITS

tdefl_compressor        STRUCT
    m_pPut_buf_func     DWORD ? ; tdefl_put_buf_func_ptr* 
    m_pPut_buf_user     DWORD ? ; void *;
    m_flags             mz_uint ?
    m_max_probes        mz_uint 2 DUP (?)
    m_greedy_parsing    DWORD ? ; int
    m_adler32           mz_uint ?
    m_lookahead_pos     mz_uint ?
    m_lookahead_size    mz_uint ?
    m_dict_size         mz_uint ?
    m_pLZ_code_buf      DWORD ? ; mz_uint8 *
    m_pLZ_flags         DWORD ? ; mz_uint8 *
    m_pOutput_buf       DWORD ? ; mz_uint8 *
    m_pOutput_buf_end   DWORD ? ; mz_uint8 *
    m_num_flags_left    mz_uint ?
    m_total_lz_bytes    mz_uint ?
    m_lz_code_buf_dict_pos mz_uint ?
    m_bits_in           mz_uint ?
    m_bit_buffer        mz_uint ?
    m_saved_match_dist  mz_uint ?
    m_saved_match_len   mz_uint ?
    m_saved_lit         mz_uint ?
    m_output_flush_ofs  mz_uint ?
    m_output_flush_remaining mz_uint ?
    m_finished          mz_uint ?
    m_block_index       mz_uint ?
    m_wants_to_finish   mz_uint ?
    m_prev_return_status tdefl_status ?
    m_pIn_buf           DWORD ? ; const void *
    m_pOut_buf          DWORD ? ; void *
    m_pIn_buf_size      DWORD ? ; size_t *
    m_pOut_buf_size     DWORD ? ; size_t *
    m_flush             tdefl_flush ?
    m_pSrc              DWORD ? ; const mz_uint8 *
    m_src_buf_left      size_t ?
    m_out_buf_ofs       size_t ?
    m_dict              mz_uint8 (TDEFL_LZ_DICT_SIZE + TDEFL_MAX_MATCH_LEN - 1) DUP (?)
    m_huff_count        mz_uint16 (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?)
    m_huff_codes        mz_uint16 (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?)
    m_huff_code_sizes   mz_uint8 (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?)
    m_lz_code_buf       mz_uint8 TDEFL_LZ_CODE_BUF_SIZE DUP (?)
    m_next              mz_uint16 TDEFL_LZ_DICT_SIZE DUP (?)
    m_hash              mz_uint16 TDEFL_LZ_HASH_SIZE DUP (?)
    m_output_buf        mz_uint8 TDEFL_OUT_BUF_SIZE DUP (?)
tdefl_compressor        ENDS


.CONST
MZ_VERSION              EQU TEXTEQU <"11.0.2">
MZ_VERNUM               EQU 0B002h
MZ_VER_MAJOR            EQU 11
MZ_VER_MINOR            EQU 2
MZ_VER_REVISION         EQU 0
MZ_VER_SUBREVISION      EQU 0

MZ_FALSE                EQU 0
MZ_TRUE                 EQU 1

MZ_UINT16_MAX           EQU 0FFFFh
MZ_UINT32_MAX           EQU 0FFFFFFFFh

; Compression strategies.
MZ_DEFAULT_STRATEGY     EQU 0
MZ_FILTERED             EQU 1
MZ_HUFFMAN_ONLY         EQU 2
MZ_RLE                  EQU 3
MZ_FIXED                EQU 4

MZ_DEFLATED             EQU 8

; Compression levels: 0-9 are the standard zlib-style levels, 10 is best possible compression (not zlib compatible, and may be very slow), MZ_DEFAULT_COMPRESSION=MZ_DEFAULT_LEVEL.
MZ_NO_COMPRESSION       EQU 0
MZ_BEST_SPEED           EQU 1
MZ_BEST_COMPRESSION     EQU 9
MZ_UBER_COMPRESSION     EQU 10
MZ_DEFAULT_LEVEL        EQU 6
MZ_DEFAULT_COMPRESSION  EQU -1

; Flush values.
MZ_NO_FLUSH             EQU 0
MZ_PARTIAL_FLUSH        EQU 1
MZ_SYNC_FLUSH           EQU 2
MZ_FULL_FLUSH           EQU 3
MZ_FINISH               EQU 4
MZ_BLOCK                EQU 5

; Return status codes. MZ_PARAM_ERROR is non-standard.
MZ_OK                   EQU 0
MZ_STREAM_END           EQU 1
MZ_NEED_DICT            EQU 2
MZ_ERRNO                EQU -1
MZ_STREAM_ERROR         EQU -2
MZ_DATA_ERROR           EQU -3
MZ_MEM_ERROR            EQU -4
MZ_BUF_ERROR            EQU -5
MZ_VERSION_ERROR        EQU -6
MZ_PARAM_ERROR          EQU -10000

MZ_DEFAULT_WINDOW_BITS  EQU 15

; mz_zip_mode
MZ_ZIP_MODE_INVALID                    EQU 0
MZ_ZIP_MODE_READING                    EQU 1
MZ_ZIP_MODE_WRITING                    EQU 2
MZ_ZIP_MODE_WRITING_HAS_BEEN_FINALIZED EQU 3

; mz_zip_flags
MZ_ZIP_FLAG_CASE_SENSITIVE                EQU 00100h
MZ_ZIP_FLAG_IGNORE_PATH                   EQU 00200h
MZ_ZIP_FLAG_COMPRESSED_DATA               EQU 00400h
MZ_ZIP_FLAG_DO_NOT_SORT_CENTRAL_DIRECTORY EQU 00800h
MZ_ZIP_FLAG_VALIDATE_LOCATE_FILE_FLAG     EQU 01000h ; if enabled, mz_zip_reader_locate_file() will be called on each file as its validated to ensure the func finds the file in the central dir (intended for testing) */
MZ_ZIP_FLAG_VALIDATE_HEADERS_ONLY         EQU 02000h     ; validate the local headers, but don't decompress the entire file and check the crc32 */
MZ_ZIP_FLAG_WRITE_ZIP64                   EQU 04000h               ; always use the zip64 file format, instead of the original zip file format with automatic switch to zip64. Use as flags parameter with mz_zip_writer_init*_v2 */
MZ_ZIP_FLAG_WRITE_ALLOW_READING           EQU 08000h
MZ_ZIP_FLAG_ASCII_FILENAME                EQU 010000h
; After adding a compressed file, seek back to local file header and set the correct sizes 
MZ_ZIP_FLAG_WRITE_HEADER_SET_SIZE         EQU 020000h
MZ_ZIP_FLAG_READ_ALLOW_WRITING            EQU 040000h

; mz_zip_type
MZ_ZIP_TYPE_INVALID EQU 0
MZ_ZIP_TYPE_USER    EQU 1
MZ_ZIP_TYPE_MEMORY  EQU 2
MZ_ZIP_TYPE_HEAP    EQU 3
MZ_ZIP_TYPE_FILE    EQU 4
MZ_ZIP_TYPE_CFILE   EQU 5
MZ_ZIP_TOTAL_TYPES  EQU 6

; mz_zip_error
MZ_ZIP_NO_ERROR                     EQU 0
MZ_ZIP_UNDEFINED_ERROR              EQU 1
MZ_ZIP_TOO_MANY_FILES               EQU 2
MZ_ZIP_FILE_TOO_LARGE               EQU 3
MZ_ZIP_UNSUPPORTED_METHOD           EQU 4
MZ_ZIP_UNSUPPORTED_ENCRYPTION       EQU 5
MZ_ZIP_UNSUPPORTED_FEATURE          EQU 6
MZ_ZIP_FAILED_FINDING_CENTRAL_DIR   EQU 7
MZ_ZIP_NOT_AN_ARCHIVE               EQU 8
MZ_ZIP_INVALID_HEADER_OR_CORRUPTED  EQU 9
MZ_ZIP_UNSUPPORTED_MULTIDISK        EQU 10
MZ_ZIP_DECOMPRESSION_FAILED         EQU 11
MZ_ZIP_COMPRESSION_FAILED           EQU 12
MZ_ZIP_UNEXPECTED_DECOMPRESSED_SIZE EQU 13
MZ_ZIP_CRC_CHECK_FAILED             EQU 14
MZ_ZIP_UNSUPPORTED_CDIR_SIZE        EQU 15
MZ_ZIP_ALLOC_FAILED                 EQU 16
MZ_ZIP_FILE_OPEN_FAILED             EQU 17
MZ_ZIP_FILE_CREATE_FAILED           EQU 18
MZ_ZIP_FILE_WRITE_FAILED            EQU 19
MZ_ZIP_FILE_READ_FAILED             EQU 20
MZ_ZIP_FILE_CLOSE_FAILED            EQU 21
MZ_ZIP_FILE_SEEK_FAILED             EQU 22
MZ_ZIP_FILE_STAT_FAILED             EQU 23
MZ_ZIP_INVALID_PARAMETER            EQU 24
MZ_ZIP_INVALID_FILENAME             EQU 25
MZ_ZIP_BUF_TOO_SMALL                EQU 26
MZ_ZIP_INTERNAL_ERROR               EQU 27
MZ_ZIP_FILE_NOT_FOUND               EQU 28
MZ_ZIP_ARCHIVE_TOO_LARGE            EQU 29
MZ_ZIP_VALIDATION_FAILED            EQU 30
MZ_ZIP_WRITE_CALLBACK_FAILED        EQU 31
MZ_ZIP_TOTAL_ERRORS                 EQU 32


; tinfl
TINFL_BITBUF_SIZE                   EQU 32

TINFL_FLAG_PARSE_ZLIB_HEADER             EQU 1
TINFL_FLAG_HAS_MORE_INPUT                EQU 2
TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF EQU 4
TINFL_FLAG_COMPUTE_ADLER32               EQU 8

TINFL_LZ_DICT_SIZE EQU 32768

; tinfl_status
TINFL_STATUS_FAILED_CANNOT_MAKE_PROGRESS EQU -4
TINFL_STATUS_BAD_PARAM                   EQU -3
TINFL_STATUS_ADLER32_MISMATCH            EQU -2
TINFL_STATUS_FAILED                      EQU -1
TINFL_STATUS_DONE                        EQU 0
TINFL_STATUS_NEEDS_MORE_INPUT            EQU 1
TINFL_STATUS_HAS_MORE_OUTPUT             EQU 2


; tdefl
TDEFL_HUFFMAN_ONLY                  EQU 0
TDEFL_DEFAULT_MAX_PROBES            EQU 128
TDEFL_MAX_PROBES_MASK               EQU 0FFFh

TDEFL_WRITE_ZLIB_HEADER             EQU 001000h
TDEFL_COMPUTE_ADLER32               EQU 002000h
TDEFL_GREEDY_PARSING_FLAG           EQU 004000h
TDEFL_NONDETERMINISTIC_PARSING_FLAG EQU 008000h
TDEFL_RLE_MATCHES                   EQU 010000h
TDEFL_FILTER_MATCHES                EQU 020000h
TDEFL_FORCE_ALL_STATIC_BLOCKS       EQU 040000h
TDEFL_FORCE_ALL_RAW_BLOCKS          EQU 080000h


; tdefl_status
TDEFL_STATUS_BAD_PARAM      EQU -2
TDEFL_STATUS_PUT_BUF_FAILED EQU -1
TDEFL_STATUS_OKAY           EQU 0
TDEFL_STATUS_DONE           EQU 1

; tdefl_flush
TDEFL_NO_FLUSH   EQU 0
TDEFL_SYNC_FLUSH EQU 2
TDEFL_FULL_FLUSH EQU 3
TDEFL_FINISH     EQU 4
















