; FSE : Finite State Entropy codec
; Public Prototypes declaration
; Copyright (c) 2013-2020, Yann Collet, Facebook, Inc.
;
; You can contact the author at :
; - Source repository : https://github.com/Cyan4973/FiniteStateEntropy

; fse_x86.inc converted from FSE source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

FSE_NCountWriteBound          PROTO STDCALL maxSymbolValue:DWORD,tableLog:DWORD
FSE_buildCTable               PROTO STDCALL ctable:DWORD,normalizedCounter:DWORD,maxSymbolValue:DWORD,tableLog:DWORD
FSE_buildCTable_raw           PROTO STDCALL ctable:DWORD,nbBits:DWORD
FSE_buildCTable_rle           PROTO STDCALL ctable:DWORD,symbolValue:DWORD
FSE_buildCTable_wksp          PROTO STDCALL ctable:DWORD,normalizedCounter:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD
FSE_buildDTable               PROTO STDCALL dtable:DWORD,normalizedCounter:DWORD,maxSymbolValue:DWORD,tableLog:DWORD
FSE_buildDTable_raw           PROTO STDCALL dtable:DWORD,nbBits:DWORD
FSE_buildDTable_rle           PROTO STDCALL dtable:DWORD,symbolValue:DWORD
FSE_compress2                 PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD
FSE_compress                  PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD
FSE_compressBound             PROTO STDCALL dwsize:DWORD
FSE_compress_usingCTable      PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,ctable:DWORD
FSE_compress_wksp             PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD
FSE_createCTable              PROTO STDCALL maxSymbolValue:DWORD,tableLog:DWORD
FSE_createDTable              PROTO STDCALL tableLog:DWORD
FSE_decompress                PROTO STDCALL dst:DWORD,dstCapacity:DWORD,cSrc:DWORD,cSrcSize:DWORD
FSE_decompressU16_usingDTable PROTO STDCALL dst:DWORD,dstCapacity:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
FSE_decompress_usingDTable    PROTO STDCALL dst:DWORD,dstCapacity:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
FSE_decompress_wksp           PROTO STDCALL dst:DWORD,dstCapacity:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,maxLog:DWORD
FSE_freeCTable                PROTO STDCALL ctable:DWORD
FSE_freeDTable                PROTO STDCALL dtable:DWORD
FSE_getErrorName              PROTO STDCALL errorcode:DWORD
FSE_isError                   PROTO STDCALL errorcode:DWORD
FSE_normalizeCount            PROTO STDCALL normalizedCounter:DWORD,tableLog:DWORD,count:DWORD,srcSize:DWORD,maxSymbolValue:DWORD
FSE_optimalTableLog           PROTO STDCALL maxTableLog:DWORD,srcSize:DWORD,maxSymbolValue:DWORD
FSE_optimalTableLog_internal  PROTO STDCALL maxTableLog:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,minus:DWORD
FSE_readNCount                PROTO STDCALL normalizedCounter:DWORD,maxSymbolValuePtr:DWORD,tableLogPtr:DWORD,rBuffer:DWORD,rBuffSize:DWORD
FSE_versionNumber             PROTO STDCALL 
FSE_writeNCount               PROTO STDCALL buffer:DWORD,bufferSize:DWORD,normalizedCounter:DWORD,maxSymbolValue:DWORD,tableLog:DWORD

HIST_count                    PROTO STDCALL count:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD
HIST_countFast                PROTO STDCALL count:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD
HIST_countFast_wksp           PROTO STDCALL count:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD,workSpace:DWORD,workSpaceSize:DWORD
HIST_count_simple             PROTO STDCALL count:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD
HIST_count_wksp               PROTO STDCALL count:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD,workSpace:DWORD,workSpaceSize:DWORD
HIST_isError                  PROTO STDCALL errorcode:DWORD

HUF_buildCTable               PROTO STDCALL ctable:DWORD,count:DWORD,maxSymbolValue:DWORD,maxNbBits:DWORD
HUF_buildCTable_wksp          PROTO STDCALL tree:DWORD,count:DWORD,maxSymbolValue:DWORD,maxNbBits:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_compress1X                PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD
HUF_compress1X_repeat         PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD,hufTable:DWORD,hufrepeat:DWORD,preferRepeat:DWORD,bmi2:DWORD
HUF_compress1X_usingCTable    PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,ctable:DWORD
HUF_compress1X_wksp           PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_compress2                 PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD
HUF_compress4X_repeat         PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD,hufTable:DWORD,hufrepeat:DWORD,preferRepeat:DWORD,bmi2:DWORD
HUF_compress4X_usingCTable    PROTO STDCALL dst:DWORD,dstSize:DWORD,src:DWORD,srcSize:DWORD,ctable:DWORD
HUF_compress4X_wksp           PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,maxSymbolValue:DWORD,tableLog:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_compress                  PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD
HUF_compressBound             PROTO STDCALL dwsize:DWORD
HUF_decompress1X1             PROTO STDCALL dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress1X1_DCtx        PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress1X1_DCtx_wksp   PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress1X1_DCtx_wksp_bmi2 PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD,bmi2:DWORD
HUF_decompress1X1_usingDTable PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress1X2             PROTO STDCALL dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress1X2_DCtx        PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress1X2_DCtx_wksp   PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress1X2_usingDTable PROTO STDCALL dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress1X_DCtx         PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress1X_DCtx_wksp    PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress1X_usingDTable  PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress1X_usingDTable_bmi2 PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD,bmi2:DWORD
HUF_decompress4X1             PROTO STDCALL dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X1_DCtx        PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X1_DCtx_wksp   PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress4X1_usingDTable PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress4X2             PROTO STDCALL dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X2_DCtx        PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X2_DCtx_wksp   PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress4X2_usingDTable PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress4X_DCtx         PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X_hufOnly      PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_decompress4X_hufOnly_wksp PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_decompress4X_hufOnly_wksp_bmi2 PROTO STDCALL dctx:DWORD,dst:DWORD,dstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,workSpace:DWORD,wkspSize:DWORD,bmi2:DWORD
HUF_decompress4X_usingDTable  PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD
HUF_decompress4X_usingDTable_bmi2 PROTO STDCALL dst:DWORD,maxDstSize:DWORD,cSrc:DWORD,cSrcSize:DWORD,dtable:DWORD,bmi2:DWORD
HUF_decompress                PROTO STDCALL dst:DWORD,originalSize:DWORD,cSrc:DWORD,cSrcSize:DWORD
HUF_estimateCompressedSize    PROTO STDCALL ctable:DWORD,count:DWORD,maxSymbolValue:DWORD
HUF_getErrorName              PROTO STDCALL errorcode:DWORD
HUF_getNbBits                 PROTO STDCALL symbolTable:DWORD,symbolValue:DWORD
HUF_isError                   PROTO STDCALL errorcode:DWORD
HUF_optimalTableLog           PROTO STDCALL maxTableLog:DWORD,srcSize:DWORD,maxSymbolValue:DWORD
HUF_readCTable                PROTO STDCALL ctable:DWORD,maxSymbolValuePtr:DWORD,src:DWORD,srcSize:DWORD,hasZeroWeights:DWORD
HUF_readDTableX1              PROTO STDCALL dtable:DWORD,src:DWORD,srcSize:DWORD
HUF_readDTableX1_wksp         PROTO STDCALL dtable:DWORD,src:DWORD,srcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_readDTableX2              PROTO STDCALL dtable:DWORD,src:DWORD,srcSize:DWORD
HUF_readDTableX2_wksp         PROTO STDCALL dtable:DWORD,src:DWORD,srcSize:DWORD,workSpace:DWORD,wkspSize:DWORD
HUF_readStats                 PROTO STDCALL huffWeight:DWORD,hwSize:DWORD,rankStats:DWORD,nbSymbolsPtr:DWORD,tableLogPtr:DWORD,src:DWORD,srcSize:DWORD
HUF_selectDecoder             PROTO STDCALL dstSize:DWORD,cSrcSize:DWORD
HUF_validateCTable            PROTO STDCALL ctable:DWORD,count:DWORD,maxSymbolValue:DWORD
HUF_writeCTable               PROTO STDCALL dst:DWORD,maxDstSize:DWORD,ctable:DWORD,maxSymbolValue:DWORD,huffLog:DWORD




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
FSE_ErrorCode                 TYPEDEF DWORD


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
HUF_repeat                    TYPEDEF DWORD


HUF_CTABLE_WORKSPACE_SIZE_U32 EQU (2 * HUF_SYMBOLVALUE_MAX +1 +1)
HUF_CTABLE_WORKSPACE_SIZE     EQU (HUF_CTABLE_WORKSPACE_SIZE_U32 * SIZEOF (DWORD))

HUF_DECOMPRESS_WORKSPACE_SIZE EQU (2 SHL 10)
HUF_DECOMPRESS_WORKSPACE_SIZE_U32 EQU (HUF_DECOMPRESS_WORKSPACE_SIZE / SIZEOF (DWORD))


HIST_WKSP_SIZE_U32            EQU 1024
HIST_WKSP_SIZE                EQU (HIST_WKSP_SIZE_U32 * SIZEOF (DWORD))





