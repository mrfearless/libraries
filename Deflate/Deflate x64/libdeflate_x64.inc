; libdeflate x64 is a library for fast, whole-buffer DEFLATE-based compression and
decompression.
; https://github.com/ebiggers/libdeflate

libdeflate_adler32                  PROTO C dwAdler32:DWORD,lpBuffer:QWORD,qwLenBuffer:QWORD
libdeflate_alloc_compressor         PROTO C dwCompressionLevel:DWORD
libdeflate_alloc_decompressor       PROTO C 
libdeflate_crc32                    PROTO C dwCrc:DWORD,lpBuffer:QWORD,qwLenBuffer:QWORD
libdeflate_deflate_compress         PROTO C lpCompressor:QWORD,lpInBuffer:QWORD,dwInBytes:QWORD,lpOutBuffer:QWORD,dwOutBytesAvail:QWORD
libdeflate_deflate_compress_bound   PROTO C lpCompressor:QWORD,qwInBytes:QWORD
libdeflate_deflate_decompress       PROTO C lpDecompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD,qwActualOutBytesRet:QWORD
libdeflate_deflate_decompress_ex    PROTO C lpDecompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD,qwActualInBytesRet:QWORD,qwActualOutBytesRet:QWORD
libdeflate_free_compressor          PROTO C lpCompressor:QWORD
libdeflate_free_decompressor        PROTO C lpDecompressor:QWORD
libdeflate_gzip_compress            PROTO C lpCompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD
libdeflate_gzip_compress_bound      PROTO C lpCompressor:QWORD,qwInBytes:QWORD
libdeflate_gzip_decompress          PROTO C lpDecompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD,qwActualOutBytesRet:QWORD
libdeflate_gzip_decompress_ex       PROTO C lpDecompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD,qwActualInBytesRet:QWORD,qwActualOutBytesRet:QWORD
libdeflate_zlib_compress            PROTO C lpCompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD
libdeflate_zlib_compress_bound      PROTO C lpCompressor:QWORD,qwInBytes:QWORD
libdeflate_zlib_decompress          PROTO C lpDecompressor:QWORD,lpInBuffer:QWORD,qwInBytes:QWORD,lpOutBuffer:QWORD,qwOutBytesAvail:QWORD,qwActualOutBytesRet:QWORD


.CONST
LIBDEFLATE_VERSION_MAJOR	    EQU 1
LIBDEFLATE_VERSION_MINOR	    EQU 3
LIBDEFLATE_VERSION_STRING	    textequ <"1.3">

; libdeflate result:

LIBDEFLATE_SUCCESS              EQU 0 ; Decompression was successful.
LIBDEFLATE_BAD_DATA             EQU 1 ; Decompressed failed because the compressed data was invalid, corrupt, * or otherwise unsupported
LIBDEFLATE_SHORT_OUTPUT         EQU 2 ; A NULL 'actual_out_nbytes_ret' was provided, but the data would have * decompressed to fewer than 'out_nbytes_avail' bytes
LIBDEFLATE_INSUFFICIENT_SPACE   EQU 3 ; The data would have decompressed to more than 'out_nbytes_avail' * bytes