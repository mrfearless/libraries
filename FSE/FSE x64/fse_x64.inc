; FSE : Finite State Entropy codec
; Public Prototypes declaration
; Copyright (c) 2013-2020, Yann Collet, Facebook, Inc.
;
; You can contact the author at :
; - Source repository : https://github.com/Cyan4973/FiniteStateEntropy

; fse_x64.inc converted from FSE source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

FSE_NCountWriteBound          PROTO maxSymbolValue:QWORD,tableLog:QWORD
FSE_buildCTable               PROTO ctable:QWORD,normalizedCounter:QWORD,maxSymbolValue:QWORD,tableLog:QWORD
FSE_buildCTable_raw           PROTO ctable:QWORD,nbBits:QWORD
FSE_buildCTable_rle           PROTO ctable:QWORD,symbolValue:QWORD
FSE_buildCTable_wksp          PROTO ctable:QWORD,normalizedCounter:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD
FSE_buildDTable               PROTO dtable:QWORD,normalizedCounter:QWORD,maxSymbolValue:QWORD,tableLog:QWORD
FSE_buildDTable_raw           PROTO dtable:QWORD,nbBits:QWORD
FSE_buildDTable_rle           PROTO dtable:QWORD,symbolValue:QWORD
FSE_compress2                 PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD
FSE_compress                  PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD
FSE_compressBound             PROTO qwsize:QWORD
FSE_compress_usingCTable      PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,ctable:QWORD
FSE_compress_wksp             PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD
FSE_createCTable              PROTO maxSymbolValue:QWORD,tableLog:QWORD
FSE_createDTable              PROTO tableLog:QWORD
FSE_decompress                PROTO dst:QWORD,dstCapacity:QWORD,cSrc:QWORD,cSrcSize:QWORD
FSE_decompressU16_usingDTable PROTO dst:QWORD,dstCapacity:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
FSE_decompress_usingDTable    PROTO dst:QWORD,dstCapacity:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
FSE_decompress_wksp           PROTO dst:QWORD,dstCapacity:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,maxLog:QWORD
FSE_freeCTable                PROTO ctable:QWORD
FSE_freeDTable                PROTO dtable:QWORD
FSE_getErrorName              PROTO errorcode:QWORD
FSE_isError                   PROTO errorcode:QWORD
FSE_normalizeCount            PROTO normalizedCounter:QWORD,tableLog:QWORD,count:QWORD,srcSize:QWORD,maxSymbolValue:QWORD
FSE_optimalTableLog           PROTO maxTableLog:QWORD,srcSize:QWORD,maxSymbolValue:QWORD
FSE_optimalTableLog_internal  PROTO maxTableLog:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,minus:QWORD
FSE_readNCount                PROTO normalizedCounter:QWORD,maxSymbolValuePtr:QWORD,tableLogPtr:QWORD,rBuffer:QWORD,rBuffSize:QWORD
FSE_versionNumber             PROTO 
FSE_writeNCount               PROTO buffer:QWORD,bufferSize:QWORD,normalizedCounter:QWORD,maxSymbolValue:QWORD,tableLog:QWORD

HIST_count                    PROTO count:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD
HIST_countFast                PROTO count:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD
HIST_countFast_wksp           PROTO count:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD,workSpace:QWORD,workSpaceSize:QWORD
HIST_count_simple             PROTO count:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD
HIST_count_wksp               PROTO count:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD,workSpace:QWORD,workSpaceSize:QWORD
HIST_isError                  PROTO errorcode:QWORD

HUF_buildCTable               PROTO ctable:QWORD,count:QWORD,maxSymbolValue:QWORD,maxNbBits:QWORD
HUF_buildCTable_wksp          PROTO tree:QWORD,count:QWORD,maxSymbolValue:QWORD,maxNbBits:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_compress1X                PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD
HUF_compress1X_repeat         PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD,hufTable:QWORD,hufrepeat:QWORD,preferRepeat:QWORD,bmi2:QWORD
HUF_compress1X_usingCTable    PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,ctable:QWORD
HUF_compress1X_wksp           PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_compress2                 PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD
HUF_compress4X_repeat         PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD,hufTable:QWORD,hufrepeat:QWORD,preferRepeat:QWORD,bmi2:QWORD
HUF_compress4X_usingCTable    PROTO dst:QWORD,dstSize:QWORD,src:QWORD,srcSize:QWORD,ctable:QWORD
HUF_compress4X_wksp           PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,maxSymbolValue:QWORD,tableLog:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_compress                  PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD
HUF_compressBound             PROTO qwsize:QWORD
HUF_decompress1X1             PROTO dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress1X1_DCtx        PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress1X1_DCtx_wksp   PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress1X1_DCtx_wksp_bmi2 PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD,bmi2:QWORD
HUF_decompress1X1_usingDTable PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress1X2             PROTO dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress1X2_DCtx        PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress1X2_DCtx_wksp   PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress1X2_usingDTable PROTO dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress1X_DCtx         PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress1X_DCtx_wksp    PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress1X_usingDTable  PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress1X_usingDTable_bmi2 PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD,bmi2:QWORD
HUF_decompress4X1             PROTO dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X1_DCtx        PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X1_DCtx_wksp   PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress4X1_usingDTable PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress4X2             PROTO dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X2_DCtx        PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X2_DCtx_wksp   PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress4X2_usingDTable PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress4X_DCtx         PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X_hufOnly      PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_decompress4X_hufOnly_wksp PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_decompress4X_hufOnly_wksp_bmi2 PROTO dctx:QWORD,dst:QWORD,dstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,workSpace:QWORD,wkspSize:QWORD,bmi2:QWORD
HUF_decompress4X_usingDTable  PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD
HUF_decompress4X_usingDTable_bmi2 PROTO dst:QWORD,maxDstSize:QWORD,cSrc:QWORD,cSrcSize:QWORD,dtable:QWORD,bmi2:QWORD
HUF_decompress                PROTO dst:QWORD,originalSize:QWORD,cSrc:QWORD,cSrcSize:QWORD
HUF_estimateCompressedSize    PROTO ctable:QWORD,count:QWORD,maxSymbolValue:QWORD
HUF_getErrorName              PROTO errorcode:QWORD
HUF_getNbBits                 PROTO symbolTable:QWORD,symbolValue:QWORD
HUF_isError                   PROTO errorcode:QWORD
HUF_optimalTableLog           PROTO maxTableLog:QWORD,srcSize:QWORD,maxSymbolValue:QWORD
HUF_readCTable                PROTO ctable:QWORD,maxSymbolValuePtr:QWORD,src:QWORD,srcSize:QWORD,hasZeroWeights:QWORD
HUF_readDTableX1              PROTO dtable:QWORD,src:QWORD,srcSize:QWORD
HUF_readDTableX1_wksp         PROTO dtable:QWORD,src:QWORD,srcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_readDTableX2              PROTO dtable:QWORD,src:QWORD,srcSize:QWORD
HUF_readDTableX2_wksp         PROTO dtable:QWORD,src:QWORD,srcSize:QWORD,workSpace:QWORD,wkspSize:QWORD
HUF_readStats                 PROTO huffWeight:QWORD,hwSize:QWORD,rankStats:QWORD,nbSymbolsPtr:QWORD,tableLogPtr:QWORD,src:QWORD,srcSize:QWORD
HUF_selectDecoder             PROTO dstSize:QWORD,cSrcSize:QWORD
HUF_validateCTable            PROTO ctable:QWORD,count:QWORD,maxSymbolValue:QWORD
HUF_writeCTable               PROTO dst:QWORD,maxDstSize:QWORD,ctable:QWORD,maxSymbolValue:QWORD,huffLog:QWORD




.CONST

FSE_VERSION_MAJOR             EQU 0
FSE_VERSION_MINOR             EQU 9
FSE_VERSION_RELEASE           EQU 0

FSE_VERSION_NUMBER            EQU (FSE_VERSION_MAJOR *100*100 + FSE_VERSION_MINOR *100 + FSE_VERSION_RELEASE)

FSE_error_no_error            EQU 0
FSE_error_GENERIC             EQU 1
FSE_error_dstSize_tooSmall    EQU 2
FSE_error_srcSize_wrong       EQU 3
FSE_error_corruption_detected EQU 4
FSE_error_tableLog_tooLarge   EQU 5
FSE_error_maxSymbolValue_tooLarge EQU 6
FSE_error_maxSymbolValue_tooSmall EQU 7
FSE_error_workSpace_tooSmall  EQU 8
FSE_error_maxCode             EQU 9
FSE_ErrorCode                 TYPEDEF QWORD


HUF_BLOCKSIZE_MAX             EQU (128 * 1024) ; < maximum input size for a single block compressed with HUF_compress

HUF_WORKSPACE_SIZE            EQU  ((6 SHL 10) + 256)
HUF_WORKSPACE_SIZE_U32        EQU (HUF_WORKSPACE_SIZE / SIZEOF (DWORD))
HUF_TABLELOG_MAX              EQU 12 ; max runtime value of tableLog (due to static allocation); can be modified up to HUF_ABSOLUTEMAX_TABLELOG
HUF_TABLELOG_DEFAULT          EQU 11 ; default tableLog value when none specified
HUF_SYMBOLVALUE_MAX           EQU 255
HUF_TABLELOG_ABSOLUTEMAX      EQU 15 ;absolute limit of HUF_MAX_TABLELOG. Beyond that value, code does not work

HUF_CTABLEBOUND               EQU 129

HUF_repeat_none               EQU 0 ; Cannot use the previous table
HUF_repeat_check              EQU 1 ; Can use the previous table but it must be checked. Note : The previous table must have been constructed by HUF_compress{1, 4}X_repeat  
HUF_repeat_valid              EQU 2 ; Can use the previous table and it is assumed to be valid
HUF_repeat                    TYPEDEF QWORD


HUF_CTABLE_WORKSPACE_SIZE_U32 EQU (2 * HUF_SYMBOLVALUE_MAX +1 +1)
HUF_CTABLE_WORKSPACE_SIZE     EQU (HUF_CTABLE_WORKSPACE_SIZE_U32 * SIZEOF (DWORD))

HUF_DECOMPRESS_WORKSPACE_SIZE EQU (2 SHL 10)
HUF_DECOMPRESS_WORKSPACE_SIZE_U32 EQU (HUF_DECOMPRESS_WORKSPACE_SIZE / SIZEOF (DWORD))


HIST_WKSP_SIZE_U32            EQU 1024
HIST_WKSP_SIZE                EQU (HIST_WKSP_SIZE_U32 * SIZEOF (DWORD))





