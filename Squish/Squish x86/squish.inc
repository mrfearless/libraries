; Squish library

Squish_Compress               PROTO STDCALL rgba:DWORD,block:DWORD,flags:DWORD,metric:DWORD
Squish_CompressImage          PROTO STDCALL rgba:DWORD,ImageWidth:DWORD,ImageHeight:DWORD,blocks:DWORD,flags:DWORD,metric:DWORD
Squish_CompressMasked         PROTO STDCALL rgba:DWORD,pixelmask:DWORD,block:DWORD,flags:DWORD,metric:DWORD
Squish_Decompress             PROTO STDCALL rgba:DWORD,block:DWORD,flags:DWORD
Squish_DecompressImage        PROTO STDCALL rgba:DWORD,ImageWidth:DWORD,ImageHeight:DWORD,blocks:DWORD,flags:DWORD
Squish_GetStorageRequirements PROTO STDCALL ImageWidth:DWORD,ImageHeight:DWORD,flags:DWORD


.CONST
; Compression flags:
kDxt1                         EQU ( 1 SHL 0 ) ; Use DXT1 compression
kDxt3                         EQU ( 1 SHL 1 ) ; Use DXT3 compression
kDxt5                         EQU ( 1 SHL 2 ) ; Use DXT5 compression
kDxt1GCN                      EQU ( 1 SHL 9 ) ; Use DXT1 compression with GCN byte-ordering
kColourIterativeClusterFit    EQU ( 1 SHL 8 ) ; Use a very slow but very high quality colour compressor
kColourClusterFit             EQU ( 1 SHL 3 ) ; Use a slow but high quality colour compressor (the default)
kColourRangeFit	              EQU ( 1 SHL 4 ) ; Use a fast but low quality colour compressor
kWeightColourByAlpha          EQU ( 1 SHL 7 ) ; Weight the colour by alpha during cluster fit (disabled by default)





