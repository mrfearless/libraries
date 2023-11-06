; RtlCompression_x86.inc created from ntdll.dll for assembler by fearless 2023
; www.github.com/mrfearless
;
; Created using dll2def on ntdll.dll, editing the ntdll.def file for just the
; required functions and renaming it RtlCompression_x86.def. Then using lib to 
; create the import library and finally using lib2inc to generate our include
; file which i edited for completeness and added the constants etc.
;
; Note: The RtlCompression.def file requires @size after the function name for 
; stdcall (x86), but not for fastcall (x64)
;
; lib /def:RtlCompression_x86.def /out:RtlCompression_x86.lib /machine:x86
;
; lib2inc RtlCompression_x86.lib -s

; https://modexp.wordpress.com/2019/12/08/shellcode-compression/#ntdll

RtlCompressBuffer PROTO STDCALL CompressionFormatAndEngine:DWORD,UncompressedBuffer:DWORD,UncompressedBufferSize:DWORD,CompressedBuffer:DWORD,CompressedBufferSize:DWORD,UncompressedChunkSize:DWORD,FinalCompressedSize:DWORD,WorkSpace:DWORD
RtlDecompressBuffer PROTO STDCALL CompressionFormat:DWORD,UncompressedBuffer:DWORD,UncompressedBufferSize:DWORD,CompressedBuffer:DWORD,CompressedBufferSize:DWORD,FinalUncompressedSize:DWORD
RtlDecompressFragment PROTO STDCALL CompressionFormat:DWORD,UncompressedFragment:DWORD,UncompressedFragmentSize:DWORD,CompressedBuffer:DWORD,CompressedBufferSize:DWORD,FragmentOffset:DWORD,FinalUncompressedSize:DWORD,WorkSpace:DWORD
RtlGetCompressionWorkSpaceSize PROTO STDCALL CompressionFormatAndEngine:DWORD,CompressBufferWorkSpaceSize:DWORD,CompressFragmentWorkSpaceSize:DWORD


.CONST
COMPRESSION_FORMAT_NONE          EQU 0000h ; 
COMPRESSION_FORMAT_DEFAULT       EQU 0001h ; 
COMPRESSION_FORMAT_LZNT1         EQU 0002h ; WinXP - requires RtlDecompressBuffer
COMPRESSION_FORMAT_XPRESS        EQU 0003h ; Windows 8 - requires RtlDecompressBufferEx
COMPRESSION_FORMAT_XPRESS_HUFF   EQU 0004h ; Windows 8 - requires RtlDecompressBufferEx or multi threaded RtlDecompressBufferEx2
COMPRESSION_FORMAT_XP10          EQU 0005h ; Windows 10+?
COMPRESSION_ENGINE_STANDARD      EQU 0000h ; 
COMPRESSION_ENGINE_MAXIMUM       EQU 0100h ; 
COMPRESSION_ENGINE_HIBER         EQU 0200h ; 

STATUS_SUCCESS                   EQU 000000000h ; 
STATUS_INVALID_PARAMETER         EQU 0C000000Dh ; An invalid parameter was passed to a service or function.
STATUS_BUFFER_TOO_SMALL          EQU 0C0000023h ; The buffer is too small to contain the entry. No information has been written to the buffer.
STATUS_NOT_SUPPORTED             EQU 0C00000BBh ; The request is not supported.
STATUS_BUFFER_ALL_ZEROS          EQU 000000117h ; Specified buffer contains all zeros.
STATUS_BAD_COMPRESSION_BUFFER    EQU 0C0000242h ; The specified buffer contains ill-formed data.
STATUS_UNSUPPORTED_COMPRESSION   EQU 0C000025Fh ; The specified compression format is unsupported.

