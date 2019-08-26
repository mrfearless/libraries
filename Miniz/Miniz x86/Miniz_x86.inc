; miniz x86 2.1.0 - Deflate/Inflate compression library with zlib-compatible API, ZIP archive reading/writing, PNG writing - Rich Geldreich
; https://github.com/richgel999/miniz

; zlib-style API Definitions
mz_adler32                  PROTO dwAdler:DWORD,ptr:DWORD,buf_len:DWORD
mz_compress2                PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD,level:DWORD
mz_compress                 PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD
mz_compressBound            PROTO source_len:DWORD
mz_crc32                    PROTO dwCrc:DWORD,ptr:DWORD,buf_len:DWORD
mz_deflate                  PROTO pStream:DWORD,flush:DWORD
mz_deflateBound             PROTO pStream:DWORD,source_len:DWORD
mz_deflateEnd               PROTO pStream:DWORD
mz_deflateInit2             PROTO pStream:DWORD,level:DWORD,method:DWORD,window_bits:DWORD,mem_level:DWORD,strategy:DWORD
mz_deflateInit              PROTO pStream:DWORD,level:DWORD
mz_deflateReset             PROTO pStream:DWORD
mz_error                    PROTO err:DWORD
mz_free                     PROTO p:DWORD
mz_inflate                  PROTO pStream:DWORD,flush:DWORD
mz_inflateEnd               PROTO pStream:DWORD
mz_inflateInit2             PROTO pStream:DWORD,window_bits:DWORD
mz_inflateInit              PROTO pStream:DWORD
mz_inflateReset             PROTO pStream:DWORD
mz_uncompress               PROTO pDest:DWORD,pDest_len:DWORD,pSource:DWORD,source_len:DWORD
mz_version                  PROTO 


; Low-level Compression API Definitions
tdefl_compress              PROTO d:DWORD,pIn_buf:DWORD,pIn_buf_size:DWORD,pOut_buf:DWORD,pOut_buf_size:DWORD,flush:DWORD
tdefl_compress_buffer       PROTO d:DWORD,pIn_buf:DWORD,in_buf_size:DWORD,flush:DWORD
tdefl_compress_mem_to_heap  PROTO pSrc_buf:DWORD,src_buf_len:DWORD,pOut_len:DWORD,flags:DWORD
tdefl_compress_mem_to_mem   PROTO pOut_buf:DWORD,out_buf_len:DWORD,pSrc_buf:DWORD,src_buf_len:DWORD,flags:DWORD
tdefl_compress_mem_to_output PROTO pBuf:DWORD,buf_len:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tdefl_compressor_alloc      PROTO 
tdefl_compressor_free       PROTO pComp:DWORD
tdefl_create_comp_flags_from_zip_params PROTO level:DWORD,window_bits:DWORD,strategy:DWORD
tdefl_get_adler32           PROTO d:DWORD
tdefl_get_prev_return_status PROTO d:DWORD
tdefl_init                  PROTO d:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tdefl_write_image_to_png_file_in_memory PROTO pImage:DWORD,w:DWORD,h:DWORD,num_chans:DWORD,pLen_out:DWORD
tdefl_write_image_to_png_file_in_memory_ex PROTO pImage:DWORD,w:DWORD,h:DWORD,num_chans:DWORD,pLen_out:DWORD,level:DWORD,flip:DWORD
tdefl_put_buf_func_ptr      PROTO pBuf:DWORD, len:DWORD, pUser:DWORD ; proto for callback func


; Low-level Decompression API Definitions
tinfl_decompress            PROTO r:DWORD,pIn_buf_next:DWORD,pIn_buf_size:DWORD,pOut_buf_start:DWORD,pOut_buf_next:DWORD,pOut_buf_size:DWORD,decomp_flags:DWORD
tinfl_decompress_mem_to_callback PROTO pIn_buf:DWORD,pIn_buf_size:DWORD,pPut_buf_func:DWORD,pPut_buf_user:DWORD,flags:DWORD
tinfl_decompress_mem_to_heap PROTO pSrc_buf:DWORD,src_buf_len:DWORD,pOut_len:DWORD,flags:DWORD
tinfl_decompress_mem_to_mem PROTO pOut_buf:DWORD,out_buf_len:DWORD,pSrc_buf:DWORD,src_buf_len:DWORD,flags:DWORD
tinfl_decompressor_alloc    PROTO 
tinfl_decompressor_free     PROTO pDecomp:DWORD
tinfl_put_buf_func_ptr      PROTO pBuf:DWORD, len:DWORD, pUser:DWORD ; proto for callback func


; ZIP archive reading/writing API Definitions

; ZIP reading
mz_zip_reader_init          PROTO pZip:DWORD,qwSize:QWORD,flags:DWORD
mz_zip_reader_init_cfile    PROTO pZip:DWORD,pFile:DWORD,archive_size:QWORD,flags:DWORD
mz_zip_reader_init_file     PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD
mz_zip_reader_init_file_v2  PROTO pZip:DWORD,pFilename:DWORD,flags:DWORD,file_start_ofs:QWORD,archive_size:QWORD
mz_zip_reader_init_mem      PROTO pZip:DWORD,pMem:DWORD,dwSizw:DWORD,flags:DWORD
mz_zip_reader_end           PROTO pZip:DWORD

; ZIP reading or writing
mz_zip_zero_struct          PROTO pZip:DWORD
mz_zip_get_mode             PROTO pZip:DWORD
mz_zip_get_type             PROTO pZip:DWORD
mz_zip_reader_get_num_files PROTO pZip:DWORD
mz_zip_get_archive_size     PROTO pZip:DWORD
mz_zip_get_archive_file_start_offset PROTO pZip:DWORD
mz_zip_get_cfile            PROTO pZip:DWORD
mz_zip_read_archive_data    PROTO pZip:DWORD,file_ofs:QWORD,pBuf:DWORD,n:DWORD
mz_zip_set_last_error       PROTO pZip:DWORD,err_num:DWORD
mz_zip_peek_last_error      PROTO pZip:DWORD
mz_zip_clear_last_error     PROTO pZip:DWORD
mz_zip_get_last_error       PROTO pZip:DWORD
mz_zip_get_error_string     PROTO pZip:DWORD
mz_zip_reader_is_file_a_directory PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_is_file_encrypted PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_is_file_supported PROTO pZip:DWORD,file_index:DWORD
mz_zip_reader_get_filename  PROTO pZip:DWORD,file_index:DWORD,pFilename:DWORD,filename_buf_size:DWORD
mz_zip_reader_locate_file   PROTO pZip:DWORD,pName:DWORD,pComment:DWORD,flags:DWORD
mz_zip_reader_locate_file_v2 PROTO pZip:DWORD,pName:DWORD,pComment:DWORD,flags:DWORD,ptr_file_index:DWORD
mz_zip_reader_file_stat     PROTO pZip:DWORD,file_index:DWORD,pStat:DWORD
mz_zip_is_zip64             PROTO pZip:DWORD
mz_zip_get_central_dir_size PROTO pZip:DWORD
mz_zip_end                  PROTO :DWORD

mz_zip_reader_extract_file_iter_new PROTO :DWORD,:DWORD,:DWORD
mz_zip_reader_extract_file_to_callback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_file_to_cfile PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_file_to_file PROTO pZip:DWORD,pArchive_filename:DWORD,pDst_filename:DWORD,flags:DWORD
mz_zip_reader_extract_file_to_heap PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_file_to_mem PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_file_to_mem_no_alloc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_iter_free PROTO :DWORD
mz_zip_reader_extract_iter_new PROTO :DWORD,:DWORD,:DWORD
mz_zip_reader_extract_iter_read PROTO :DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_callback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_cfile PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_file PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_heap PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_mem PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_reader_extract_to_mem_no_alloc PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

; Misc utils/helpers, valid for ZIP reading or writing
mz_zip_validate_file        PROTO pZip:DWORD,file_index:DWORD,flags:DWORD
mz_zip_validate_archive     PROTO pZip:DWORD,flags:DWORD
mz_zip_validate_mem_archive PROTO pMem:DWORD,dwSize:DWORD,flags:DWORD,pErr:DWORD
mz_zip_validate_file_archive PROTO pFilename:DWORD,flags:DWORD,pErr:DWORD

; ZIP writing
mz_zip_writer_add_cfile     PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_add_file      PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_add_from_zip_reader PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_add_mem       PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_add_mem_ex    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_add_mem_ex_v2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_add_read_buf_callback PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_end           PROTO :DWORD
mz_zip_writer_finalize_archive PROTO :DWORD
mz_zip_writer_finalize_heap_archive PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_init          PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_init_cfile    PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_init_file     PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_init_file_v2  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_init_from_reader PROTO :DWORD,:DWORD
mz_zip_writer_init_from_reader_v2 PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_init_heap     PROTO :DWORD,:DWORD,:DWORD
mz_zip_writer_init_heap_v2  PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_writer_init_v2       PROTO :DWORD,:DWORD,:DWORD,:DWORD

; Misc. high-level helper functions
mz_zip_add_mem_to_archive_file_in_place PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_add_mem_to_archive_file_in_place_v2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
mz_zip_extract_archive_file_to_heap PROTO :DWORD,:DWORD,:DWORD,:DWORD
mz_zip_extract_archive_file_to_heap_v2 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

; Misc
miniz_def_alloc_func        PROTO :DWORD,:DWORD,:DWORD
miniz_def_free_func         PROTO :DWORD,:DWORD
miniz_def_realloc_func      PROTO :DWORD,:DWORD,:DWORD,:DWORD


.CONST

MZ_VERSION                  EQU <10.1.0>
MZ_VERNUM                   EQU 0A100h
MZ_VER_MAJOR                EQU 10
MZ_VER_MINOR                EQU 1
MZ_VER_REVISION             EQU 0
MZ_VER_SUBREVISION          EQU 0

; Compression strategies:
MZ_DEFAULT_STRATEGY         EQU 0
MZ_FILTERED                 EQU 1
MZ_HUFFMAN_ONLY             EQU 2
MZ_RLE                      EQU 3
MZ_FIXED                    EQU 4

; Method
MZ_DEFLATED                 EQU 8

; Compression levels: 
; 0-9 are the standard zlib-style levels
; 10 is best possible compression (not zlib compatible, and may be very slow)
; MZ_DEFAULT_COMPRESSION EQU MZ_DEFAULT_LEVEL
MZ_NO_COMPRESSION           EQU 0
MZ_BEST_SPEED               EQU 1
MZ_BEST_COMPRESSION         EQU 9
MZ_UBER_COMPRESSION         EQU 10
MZ_DEFAULT_LEVEL            EQU 6
MZ_DEFAULT_COMPRESSION      EQU -1

; Flush values. 
; For typical usage you only need MZ_NO_FLUSH and MZ_FINISH. 
; The other values are for advanced use (refer to the zlib docs)
MZ_NO_FLUSH                 EQU 0
MZ_PARTIAL_FLUSH            EQU 1
MZ_SYNC_FLUSH               EQU 2
MZ_FULL_FLUSH               EQU 3
MZ_FINISH                   EQU 4
MZ_BLOCK                    EQU 5

; Return status codes. MZ_PARAM_ERROR is non-standard
MZ_OK                       EQU 0
MZ_STREAM_END               EQU 1
MZ_NEED_DICT                EQU 2
MZ_ERRNO                    EQU -1
MZ_STREAM_ERROR             EQU -2
MZ_DATA_ERROR               EQU -3
MZ_MEM_ERROR                EQU -4
MZ_BUF_ERROR                EQU -5
MZ_VERSION_ERROR            EQU -6
MZ_PARAM_ERROR              EQU -10000

; Window bits
MZ_DEFAULT_WINDOW_BITS      EQU 15

; Set TDEFL_LESS_MEMORY to 1 to use less memory (compression will be slightly slower, and raw/dynamic blocks will be output more frequently).
TDEFL_LESS_MEMORY           EQU 0

; tdefl_init() compression flags logically OR'd together (low 12 bits contain the max. number of probes per dictionary search):
; TDEFL_DEFAULT_MAX_PROBES: The compressor defaults to 128 dictionary probes per dictionary search. 0EQUHuffman only, 1EQUHuffman+LZ (fastest/crap compression), 4095EQUHuffman+LZ (slowest/best compression).
TDEFL_HUFFMAN_ONLY          EQU 0
TDEFL_DEFAULT_MAX_PROBES    EQU 128
TDEFL_MAX_PROBES_MASK       EQU 0FFFh

; TDEFL_WRITE_ZLIB_HEADER: If set, the compressor outputs a zlib header before the deflate data, and the Adler-32 of the source data at the end. Otherwise, you'll get raw deflate data.
; TDEFL_COMPUTE_ADLER32: Always compute the adler-32 of the input data (even when not writing zlib headers).
; TDEFL_GREEDY_PARSING_FLAG: Set to use faster greedy parsing, instead of more efficient lazy parsing.
; TDEFL_NONDETERMINISTIC_PARSING_FLAG: Enable to decrease the compressor's initialization time to the minimum, but the output may vary from run to run given the same input (depending on the contents of memory).
; TDEFL_RLE_MATCHES: Only look for RLE matches (matches with a distance of 1)
; TDEFL_FILTER_MATCHES: Discards matches <EQU 5 chars if enabled.
; TDEFL_FORCE_ALL_STATIC_BLOCKS: Disable usage of optimized Huffman tables.
; TDEFL_FORCE_ALL_RAW_BLOCKS: Only use raw (uncompressed) deflate blocks.
; The low 12 bits are reserved to control the max # of hash probes per dictionary lookup (see TDEFL_MAX_PROBES_MASK).
TDEFL_WRITE_ZLIB_HEADER     EQU 01000h
TDEFL_COMPUTE_ADLER32       EQU 02000h
TDEFL_GREEDY_PARSING_FLAG   EQU 04000h
TDEFL_NONDETERMINISTIC_PARSING_FLAG EQU 08000h
TDEFL_RLE_MATCHES           EQU 10000h
TDEFL_FILTER_MATCHES        EQU 20000h
TDEFL_FORCE_ALL_STATIC_BLOCKS EQU 40000h
TDEFL_FORCE_ALL_RAW_BLOCKS  EQU 80000h

TDEFL_MAX_HUFF_TABLES       EQU 3
TDEFL_MAX_HUFF_SYMBOLS_0    EQU 288
TDEFL_MAX_HUFF_SYMBOLS_1    EQU 32
TDEFL_MAX_HUFF_SYMBOLS_2    EQU 19
TDEFL_LZ_DICT_SIZE          EQU 32768
TDEFL_LZ_DICT_SIZE_MASK     EQU TDEFL_LZ_DICT_SIZE - 1
TDEFL_MIN_MATCH_LEN         EQU 3
TDEFL_MAX_MATCH_LEN         EQU 258

; TDEFL_OUT_BUF_SIZE MUST be large enough to hold a single entire compressed output block (using static/fixed Huffman codes).
ifdef TDEFL_LESS_MEMORY
    TDEFL_LZ_CODE_BUF_SIZE  EQU 24 * 1024
    TDEFL_OUT_BUF_SIZE      EQU (TDEFL_LZ_CODE_BUF_SIZE * 13) / 10
    TDEFL_MAX_HUFF_SYMBOLS  EQU 288
    TDEFL_LZ_HASH_BITS      EQU 12
    TDEFL_LEVEL1_HASH_SIZE_MASK EQU 4095
    TDEFL_LZ_HASH_SHIFT     EQU (TDEFL_LZ_HASH_BITS + 2) / 3
    TDEFL_LZ_HASH_SIZE      EQU 1 shl TDEFL_LZ_HASH_BITS
else
    TDEFL_LZ_CODE_BUF_SIZE  EQU 64 * 1024
    TDEFL_OUT_BUF_SIZE      EQU (TDEFL_LZ_CODE_BUF_SIZE * 13) / 10
    TDEFL_MAX_HUFF_SYMBOLS  EQU 288
    TDEFL_LZ_HASH_BITS      EQU 15
    TDEFL_LEVEL1_HASH_SIZE_MASK EQU 4095
    TDEFL_LZ_HASH_SHIFT     EQU (TDEFL_LZ_HASH_BITS + 2) / 3
    TDEFL_LZ_HASH_SIZE      EQU 1 shl TDEFL_LZ_HASH_BITS
endif

; The low-level tdefl functions below may be used directly if the above helper functions aren't flexible enough. The low-level functions don't make any heap allocations, unlike the above helper functions.

; tdefl_status:
TDEFL_STATUS_BAD_PARAM      EQU -2
TDEFL_STATUS_PUT_BUF_FAILED EQU -1
TDEFL_STATUS_OKAY           EQU 0
TDEFL_STATUS_DONE           EQU 1

; Must map to MZ_NO_FLUSH, MZ_SYNC_FLUSH, etc. enums
; tdefl_flush:
TDEFL_NO_FLUSH              EQU 0
TDEFL_SYNC_FLUSH            EQU 2
TDEFL_FULL_FLUSH            EQU 3
TDEFL_FINISH                EQU 4

; Decompression flags used by tinfl_decompress().
; TINFL_FLAG_PARSE_ZLIB_HEADER: If set, the input has a valid zlib header and ends with an adler32 checksum (it's a valid zlib stream). Otherwise, the input is a raw deflate stream.
; TINFL_FLAG_HAS_MORE_INPUT: If set, there are more input bytes available beyond the end of the supplied input buffer. If clear, the input buffer contains all remaining input.
; TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF: If set, the output buffer is large enough to hold the entire decompressed stream. If clear, the output buffer is at least the size of the dictionary (typically 32KB).
; TINFL_FLAG_COMPUTE_ADLER32: Force adler-32 checksum computation of the decompressed bytes.
TINFL_FLAG_PARSE_ZLIB_HEADER EQU 1
TINFL_FLAG_HAS_MORE_INPUT   EQU 2
TINFL_FLAG_USING_NON_WRAPPING_OUTPUT_BUF EQU 4
TINFL_FLAG_COMPUTE_ADLER32  EQU 8

; Max size of LZ dictionary.
TINFL_LZ_DICT_SIZE          EQU 32768

; Return status.
; This flags indicates the inflator needs 1 or more input bytes to make forward progress, but the caller is indicating that no more are available. The compressed data
; is probably corrupted. If you call the inflator again with more bytes it'll try to continue processing the input but this is a BAD sign (either the data is corrupted or you called it incorrectly).
; If you call it again with no input you'll just get TINFL_STATUS_FAILED_CANNOT_MAKE_PROGRESS again.
TINFL_STATUS_FAILED_CANNOT_MAKE_PROGRESS EQU -4

; This flag indicates that one or more of the input parameters was obviously bogus. (You can try calling it again, but if you get this error the calling code is wrong.)
TINFL_STATUS_BAD_PARAM      EQU -3

; This flags indicate the inflator is finished but the adler32 check of the uncompressed data didn't match. If you call it again it'll return TINFL_STATUS_DONE.
TINFL_STATUS_ADLER32_MISMATCH EQU -2

; This flags indicate the inflator has somehow failed (bad code, corrupted input, etc.). If you call it again without resetting via tinfl_init() it it'll just keep on returning the same status failure code.
TINFL_STATUS_FAILED         EQU -1

; Any status code less than TINFL_STATUS_DONE must indicate a failure.

; This flag indicates the inflator has returned every byte of uncompressed data that it can, has consumed every byte that it needed, has successfully reached the end of the deflate stream, and
; if zlib headers and adler32 checking enabled that it has successfully checked the uncompressed data's adler32. If you call it again you'll just get TINFL_STATUS_DONE over and over again.
TINFL_STATUS_DONE           EQU 0

; This flag indicates the inflator MUST have more input data (even 1 byte) before it can make any more forward progress, or you need to clear the TINFL_FLAG_HAS_MORE_INPUT
; flag on the next call if you don't have any more source data. If the source data was somehow corrupted it's also possible (but unlikely) for the inflator to keep on demanding input to
; proceed, so be sure to properly set the TINFL_FLAG_HAS_MORE_INPUT flag.
TINFL_STATUS_NEEDS_MORE_INPUT EQU 1

; This flag indicates the inflator definitely has 1 or more bytes of uncompressed data available, but it cannot write this data into the output buffer.
; Note if the source compressed data was corrupted it's possible for the inflator to return a lot of uncompressed data to the caller. I've been assuming you know how much uncompressed data to expect
; (either exact or worst case) and will stop calling the inflator and fail after receiving too much. In pure streaming scenarios where you have no idea how many bytes to expect this may not be possible
; so I may need to add some code to address this.
TINFL_STATUS_HAS_MORE_OUTPUT EQU 2


; Internal/private bits follow.
TINFL_MAX_HUFF_TABLES       EQU 3
TINFL_MAX_HUFF_SYMBOLS_0    EQU 288
TINFL_MAX_HUFF_SYMBOLS_1    EQU 32
TINFL_MAX_HUFF_SYMBOLS_2    EQU 19
TINFL_FAST_LOOKUP_BITS      EQU 10
TINFL_FAST_LOOKUP_SIZE      EQU 1 shl TINFL_FAST_LOOKUP_BITS

; Note: These enums can be reduced as needed to save memory or stack space - they are pretty conservative.
MZ_ZIP_MAX_IO_BUF_SIZE      EQU 64 * 1024
MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE EQU 512
MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE EQU 512

; mz_zip_mode:
MZ_ZIP_MODE_INVALID         EQU 0
MZ_ZIP_MODE_READING         EQU 1
MZ_ZIP_MODE_WRITING         EQU 2
MZ_ZIP_MODE_WRITING_HAS_BEEN_FINALIZED EQU 3

; mz_zip_flags:
MZ_ZIP_FLAG_CASE_SENSITIVE  EQU 0100h
MZ_ZIP_FLAG_IGNORE_PATH     EQU 0200h
MZ_ZIP_FLAG_COMPRESSED_DATA EQU 0400h
MZ_ZIP_FLAG_DO_NOT_SORT_CENTRAL_DIRECTORY EQU 0800h
MZ_ZIP_FLAG_VALIDATE_LOCATE_FILE_FLAG EQU 1000h ; if enabled, mz_zip_reader_locate_file() will be called on each file as its validated to ensure the func finds the file in the central dir (intended for testing)
MZ_ZIP_FLAG_VALIDATE_HEADERS_ONLY EQU 2000h     ; validate the local headers, but don't decompress the entire file and check the crc32
MZ_ZIP_FLAG_WRITE_ZIP64     EQU 4000h               ; always use the zip64 file format, instead of the original zip file format with automatic switch to zip64. Use as flags parameter with mz_zip_writer_init*_v2
MZ_ZIP_FLAG_WRITE_ALLOW_READING EQU 8000h
MZ_ZIP_FLAG_ASCII_FILENAME  EQU 10000h

; mz_zip_type:
MZ_ZIP_TYPE_INVALID         EQU 0
MZ_ZIP_TYPE_USER            EQU 1
MZ_ZIP_TYPE_MEMORY          EQU 2
MZ_ZIP_TYPE_HEAP            EQU 3
MZ_ZIP_TYPE_FILE            EQU 4
MZ_ZIP_TYPE_CFILE           EQU 5
MZ_ZIP_TOTAL_TYPES          EQU 6

; miniz error codes. 
; Be sure to update mz_zip_get_error_string() if you add or modify this enum.
MZ_ZIP_NO_ERROR             EQU 0
MZ_ZIP_UNDEFINED_ERROR      EQU 1
MZ_ZIP_TOO_MANY_FILES       EQU 2
MZ_ZIP_FILE_TOO_LARGE       EQU 3
MZ_ZIP_UNSUPPORTED_METHOD   EQU 4
MZ_ZIP_UNSUPPORTED_ENCRYPTION EQU 5 
MZ_ZIP_UNSUPPORTED_FEATURE  EQU 6
MZ_ZIP_FAILED_FINDING_CENTRAL_DIR EQU 7
MZ_ZIP_NOT_AN_ARCHIVE       EQU 8
MZ_ZIP_INVALID_HEADER_OR_CORRUPTED EQU 9
MZ_ZIP_UNSUPPORTED_MULTIDISK EQU 10
MZ_ZIP_DECOMPRESSION_FAILED EQU 11
MZ_ZIP_COMPRESSION_FAILED   EQU 12
MZ_ZIP_UNEXPECTED_DECOMPRESSED_SIZE EQU 13
MZ_ZIP_CRC_CHECK_FAILED     EQU 14
MZ_ZIP_UNSUPPORTED_CDIR_SIZE EQU 15
MZ_ZIP_ALLOC_FAILED         EQU 16
MZ_ZIP_FILE_OPEN_FAILED     EQU 17
MZ_ZIP_FILE_CREATE_FAILED   EQU 18
MZ_ZIP_FILE_WRITE_FAILED    EQU 19
MZ_ZIP_FILE_READ_FAILED     EQU 20
MZ_ZIP_FILE_CLOSE_FAILED    EQU 21
MZ_ZIP_FILE_SEEK_FAILED     EQU 22
MZ_ZIP_FILE_STAT_FAILED     EQU 23
MZ_ZIP_INVALID_PARAMETER    EQU 24
MZ_ZIP_INVALID_FILENAME     EQU 25
MZ_ZIP_BUF_TOO_SMALL        EQU 26
MZ_ZIP_INTERNAL_ERROR       EQU 27
MZ_ZIP_FILE_NOT_FOUND       EQU 28
MZ_ZIP_ARCHIVE_TOO_LARGE    EQU 29
MZ_ZIP_VALIDATION_FAILED    EQU 30
MZ_ZIP_WRITE_CALLBACK_FAILED EQU 31
MZ_ZIP_TOTAL_ERRORS         EQU 32


mz_ulong                    TYPEDEF DWORD ;unsigned long mz_ulong;

; Structures

;Compression/decompression stream struct. 
mz_stream                   STRUCT
    next_in                 DD ? ; const unsigned char *next_in - pointer to next byte to read 
    avail_in                DD ? ; unsigned int avail_in - number of bytes available at next_in 
    total_in                DD ? ; mz_ulong total_in - total number of bytes consumed so far 
    next_out                DD ? ; unsigned char *next_out - pointer to next byte to write 
    avail_out               DD ? ; unsigned int avail_out - number of bytes that can be written to next_out 
    total_out               DD ? ; mz_ulong total_out - total number of bytes produced so far 
    msg                     DD ? ; char *msg - error msg (unused) 
    state                   DD ? ; struct mz_internal_state *state - internal state, allocated by zalloc/zfree 
    zalloc                  DD ? ; mz_alloc_func zalloc - optional heap allocation function (defaults to malloc) 
    zfree                   DD ? ; mz_free_func zfree - optional heap free function (defaults to free) 
    opaque                  DD ? ; void *opaque - heap alloc function user pointer 
    data_type               DD ? ; int data_type - data_type (unused) 
    adler                   DD ? ; mz_ulong adler - adler32 of the source or uncompressed data 
    reserved                DD ? ; mz_ulong reserved - not used 
mz_stream                   ENDS


ifdef MINIZ_NO_TIME
mz_dummy_time               STRUCT
    m_dummy                 DD ? ; int m_dummy;
mz_dummy_time               ENDS
MZ_TIME_T                   TYPEDEF mz_dummy_time
else
MZ_TIME_T                   TYPEDEF QWORD
endif


;tdefl's compression state structure. 
tdefl_compressor            STRUCT
    m_pPut_buf_func         DD ? ;tdefl_put_buf_func_ptr m_pPut_buf_func;
    m_pPut_buf_user         DD ? ;void *m_pPut_buf_user;
    m_flags                 DD ?
    m_max_probes            DD 2 DUP (?) ; mz_uint m_flags, m_max_probes[2];
    m_greedy_parsing        DD ? ;int m_greedy_parsing;
    m_adler32               DD ? ;
    m_lookahead_pos         DD ? ;
    m_lookahead_size        DD ? ;
    m_dict_size             DD ? ;mz_uint m_adler32, m_lookahead_pos, m_lookahead_size, m_dict_size;
    m_pLZ_code_buf          DD ? ;
    m_pLZ_flags             DD ? ;
    m_pOutput_buf           DD ? ;
    m_pOutput_buf_end       DD ? ;mz_uint8 *m_pLZ_code_buf, *m_pLZ_flags, *m_pOutput_buf, *m_pOutput_buf_end;
    m_num_flags_left        DD ? ;
    m_total_lz_bytes        DD ? ;
    m_lz_code_buf_dict_pos  DD ? ;
    m_bits_in               DD ? ;
    m_bit_buffer            DD ? ;mz_uint m_num_flags_left, m_total_lz_bytes, m_lz_code_buf_dict_pos, m_bits_in, m_bit_buffer;
    m_saved_match_dist      DD ? ;
    m_saved_match_len       DD ? ;
    m_saved_lit             DD ? ;
    m_output_flush_ofs      DD ? ;
    m_output_flush_remaining DD ? ;
    m_finished              DD ? ;
    m_block_index           DD ? ;
    m_wants_to_finish       DD ? ; mz_uint m_saved_match_dist, m_saved_match_len, m_saved_lit, m_output_flush_ofs, m_output_flush_remaining, m_finished, m_block_index, m_wants_to_finish;
    m_prev_return_status    DD ? ;tdefl_status m_prev_return_status;
    m_pIn_buf               DD ? ;const void *m_pIn_buf;
    m_pOut_buf              DD ? ;void *m_pOut_buf;
    m_pIn_buf_size          DD ? ;
    m_pOut_buf_size         DD ? ;size_t *m_pIn_buf_size, *m_pOut_buf_size;
    m_flush                 DD ? ;tdefl_flush m_flush;
    m_pSrc                  DD ? ;const mz_uint8 *m_pSrc;
    m_src_buf_left          DD ? ;
    m_out_buf_ofs           DD ? ;size_t m_src_buf_left, m_out_buf_ofs;
    m_dict                  DB (TDEFL_LZ_DICT_SIZE + TDEFL_MAX_MATCH_LEN - 1) DUP (?) ;mz_uint8 m_dict[TDEFL_LZ_DICT_SIZE + TDEFL_MAX_MATCH_LEN - 1];
    m_huff_count            DW (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?) ; m_huff_count[TDEFL_MAX_HUFF_TABLES][TDEFL_MAX_HUFF_SYMBOLS];
    m_huff_codes            DW (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?) ; m_huff_codes[TDEFL_MAX_HUFF_TABLES][TDEFL_MAX_HUFF_SYMBOLS];
    m_huff_code_sizes       DB (TDEFL_MAX_HUFF_TABLES * TDEFL_MAX_HUFF_SYMBOLS) DUP (?) ;m_huff_code_sizes[TDEFL_MAX_HUFF_TABLES][TDEFL_MAX_HUFF_SYMBOLS];
    m_lz_code_buf           DB TDEFL_LZ_CODE_BUF_SIZE DUP (?) ;m_lz_code_buf[TDEFL_LZ_CODE_BUF_SIZE];
    m_next                  DW TDEFL_LZ_DICT_SIZE DUP (?) ;m_next[TDEFL_LZ_DICT_SIZE];
    m_hash                  DW TDEFL_LZ_HASH_SIZE DUP (?) ;m_hash[TDEFL_LZ_HASH_SIZE];
    m_output_buf            DB TDEFL_OUT_BUF_SIZE DUP (?) ;m_output_buf[TDEFL_OUT_BUF_SIZE];
tdefl_compressor            ENDS

tinfl_huff_table            STRUCT
    m_code_size             DB TINFL_MAX_HUFF_SYMBOLS_0 DUP (?) ;mz_uint8 m_code_size[TINFL_MAX_HUFF_SYMBOLS_0];
    m_look_up               DW TINFL_FAST_LOOKUP_SIZE DUP (?) ;mz_int16 m_look_up[TINFL_FAST_LOOKUP_SIZE], 
    m_tree                  DW (TINFL_MAX_HUFF_SYMBOLS_0 * 2) DUP (?) ;m_tree[TINFL_MAX_HUFF_SYMBOLS_0 * 2];
tinfl_huff_table            ENDS

mz_zip_archive_file_stat    STRUCT
    ;Central directory file index. 
    m_file_index            DD ? ; mz_uint32 m_file_index;
    ;Byte offset of this entry in the archive's central directory. Note we currently only support up to UINT_MAX or less bytes in the central dir. 
    m_central_dir_ofs       DQ ? ; mz_uint64 m_central_dir_ofs;
    ;These fields are copied directly from the zip's central dir. 
    m_version_made_by       DW ? ; mz_uint16 m_version_made_by;
    m_version_needed        DW ? ; mz_uint16 m_version_needed;
    m_bit_flag              DW ? ; mz_uint16 m_bit_flag;
    m_method                DW ? ; mz_uint16 m_method;
ifndef MINIZ_NO_TIME
    m_time                  MZ_TIME_T ? ;
endif
    ;CRC-32 of uncompressed data. 
    m_crc32                 DD ? ; mz_uint32 m_crc32;
    ;File's compressed size. 
    m_comp_size             DQ ? ; mz_uint64 m_comp_size;
    ;File's uncompressed size. Note, I've seen some old archives where directory entries had 512 bytes for their uncompressed sizes, but when you try to unpack them you actually get 0 bytes. 
    m_uncomp_size           DQ ? ; mz_uint64 m_uncomp_size;
    ;Zip internal and external file attributes. 
    m_internal_attr         DW ? ; mz_uint16 m_internal_attr;
    m_external_attr         DD ? ; mz_uint32 m_external_attr;
    ;Entry's local header file offset in bytes. 
    m_local_header_ofs      DQ ? ; mz_uint64 m_local_header_ofs;
    ;Size of comment in bytes. 
    m_comment_size          DD ? ; mz_uint32 m_comment_size;
    ;MZ_TRUE if the entry appears to be a directory. 
    m_is_directory          DD ? ; mz_bool m_is_directory;
    ;MZ_TRUE if the entry uses encryption/strong encryption (which miniz_zip doesn't support) 
    m_is_encrypted          DD ? ; mz_bool m_is_encrypted;
    ;MZ_TRUE if the file is not encrypted, a patch file, and if it uses a compression method we support. 
    m_is_supported          DD ? ; mz_bool m_is_supported;
    ;Filename. If string ends in '/' it's a subdirectory entry. 
    ;Guaranteed to be zero terminated, may be truncated to fit. 
    m_filename              DB MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE DUP (?) ; char m_filename[MZ_ZIP_MAX_ARCHIVE_FILENAME_SIZE];
    ;Comment field. 
    ;Guaranteed to be zero terminated, may be truncated to fit. 
    m_comment               DB MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE DUP (?) ; char m_comment[MZ_ZIP_MAX_ARCHIVE_FILE_COMMENT_SIZE];
mz_zip_archive_file_stat    ENDS

mz_zip_archive              STRUCT
    m_archive_size          DQ ? ; mz_uint64 m_archive_size;
    m_central_directory_file_ofs DQ ? ; mz_uint64 m_central_directory_file_ofs;
    ;We only support up to UINT32_MAX files in zip64 mode. 
    m_total_files           DD ? ;mz_uint32 m_total_files;
    m_zip_mode              DD ? ;mz_zip_mode m_zip_mode;
    m_zip_type              DD ? ;mz_zip_type m_zip_type;
    m_last_error            DD ? ;mz_zip_error m_last_error;
    m_file_offset_alignment DQ ? ; mz_uint64 m_file_offset_alignment;
    m_pAlloc                DD ? ;mz_alloc_func m_pAlloc;
    m_pFree                 DD ? ;mz_free_func m_pFree;
    m_pRealloc              DD ? ;mz_realloc_func m_pRealloc;
    m_pAlloc_opaque         DD ? ;void *m_pAlloc_opaque;
    m_pRead                 DD ? ;mz_file_read_func m_pRead;
    m_pWrite                DD ? ;mz_file_write_func m_pWrite;
    m_pNeeds_keepalive      DD ? ;mz_file_needs_keepalive m_pNeeds_keepalive;
    m_pIO_opaque            DD ? ;void *m_pIO_opaque;
    m_pState                DD ? ;mz_zip_internal_state *m_pState;
mz_zip_archive              ENDS

mz_zip_reader_extract_iter_state STRUCT
    pZip                    DD ? ;mz_zip_archive *pZip;
    flags                   DD ? ;mz_uint flags;
    status                  DD ? ;int status;
ifndef MINIZ_DISABLE_ZIP_READER_CRC32_CHECKS
    file_crc32              DD ? ;mz_uint file_crc32;
endif
    read_buf_size           DQ ?
    read_buf_ofs            DQ ?
    read_buf_avail          DQ ?
    comp_remaining          DQ ?
    out_buf_ofs             DQ ?
    cur_file_ofs            DQ ? ; mz_uint64 read_buf_size, read_buf_ofs, read_buf_avail, comp_remaining, out_buf_ofs, cur_file_ofs;
    file_stat               DD ? ;mz_zip_archive_file_stat ;
    pRead_buf               DD ? ;void *pRead_buf;
    pWrite_buf              DD ? ;void *pWrite_buf;
    out_blk_remain          DD ? ;size_t out_blk_remain;
    inflator                DD ? ;tinfl_decompressor inflator;
mz_zip_reader_extract_iter_state ENDS



