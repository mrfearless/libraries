; Squish library x64

Squish_Compress               PROTO rgba:QWORD,block:QWORD,flags:QWORD,metric:QWORD
Squish_CompressImage          PROTO rgba:QWORD,ImageWidth:QWORD,ImageHeight:QWORD,blocks:QWORD,flags:QWORD,metric:QWORD
Squish_CompressMasked         PROTO rgba:QWORD,pixelmask:QWORD,block:QWORD,flags:QWORD,metric:QWORD
Squish_Decompress             PROTO rgba:QWORD,block:QWORD,flags:QWORD
Squish_DecompressImage        PROTO rgba:QWORD,ImageWidth:QWORD,ImageHeight:QWORD,blocks:QWORD,flags:QWORD
Squish_GetStorageRequirements PROTO ImageWidth:QWORD,ImageHeight:QWORD,flags:QWORD


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





