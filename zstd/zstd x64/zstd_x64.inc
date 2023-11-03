; BSD License
; 
; For Zstandard software
; 
; Copyright (c) Meta Platforms, Inc. and affiliates. All rights reserved.
; 
; Redistribution and use in source and binary forms, with or without modification,
; are permitted provided that the following conditions are met:
; 
;  * Redistributions of source code must retain the above copyright notice, this
;    list of conditions and the following disclaimer.
; 
;  * Redistributions in binary form must reproduce the above copyright notice,
;    this list of conditions and the following disclaimer in the documentation
;    and/or other materials provided with the distribution.
; 
;  * Neither the name Facebook, nor Meta, nor the names of its contributors may
;    be used to endorse or promote products derived from this software without
;    specific prior written permission.
; 
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
; ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
; ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
; (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
; ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

; Zstandard x64 - Fast real-time compression algorithm 
; http://www.zstd.net
; https://github.com/facebook/zstd

; zstd_x646.inc converted from zstandard source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

ERR_getErrorString PROTO :QWORD
FSE_NCountWriteBound PROTO :QWORD,:QWORD
FSE_buildCTable_rle PROTO :QWORD,:QWORD
FSE_buildCTable_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_buildDTable_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_compressBound PROTO :QWORD
FSE_compress_usingCTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_decompress_wksp_bmi2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_getErrorName PROTO :QWORD
FSE_isError PROTO :QWORD
FSE_normalizeCount PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_optimalTableLog PROTO :QWORD,:QWORD,:QWORD
FSE_optimalTableLog_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD
FSE_readNCount PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_readNCount_bmi2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
FSE_versionNumber PROTO 
FSE_writeNCount PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HIST_count PROTO :QWORD,:QWORD,:QWORD,:QWORD
HIST_countFast PROTO :QWORD,:QWORD,:QWORD,:QWORD
HIST_countFast_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HIST_count_simple PROTO :QWORD,:QWORD,:QWORD,:QWORD
HIST_count_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HIST_isError PROTO :QWORD
HUF_buildCTable_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_cardinality PROTO :QWORD,:QWORD
HUF_compress1X_repeat PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_compress1X_usingCTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_compress4X_repeat PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_compress4X_usingCTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_compressBound PROTO :QWORD
HUF_decompress1X1_DCtx_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_decompress1X2_DCtx_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_decompress1X_DCtx_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_decompress1X_usingDTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_decompress4X_hufOnly_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_decompress4X_usingDTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_estimateCompressedSize PROTO :QWORD,:QWORD,:QWORD
HUF_getErrorName PROTO :QWORD
HUF_getNbBitsFromCTable PROTO :QWORD,:QWORD
HUF_isError PROTO :QWORD
HUF_minTableLog PROTO :QWORD
HUF_optimalTableLog PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_readCTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_readCTableHeader PROTO :QWORD
HUF_readDTableX1_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_readDTableX2_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_readStats PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_readStats_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
HUF_selectDecoder PROTO :QWORD,:QWORD
HUF_validateCTable PROTO :QWORD,:QWORD,:QWORD
HUF_writeCTable_wksp PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTDMT_compressStream_generic PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTDMT_createCCtx_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTDMT_freeCCtx PROTO :QWORD
ZSTDMT_getFrameProgression PROTO :QWORD
ZSTDMT_initCStream_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTDMT_nextInputSizeHint PROTO :QWORD
ZSTDMT_sizeof_CCtx PROTO :QWORD
ZSTDMT_toFlushNow PROTO :QWORD
ZSTDMT_updateCParams_whileCompressing PROTO :QWORD,:QWORD
ZSTD_CCtxParams_getParameter PROTO :QWORD,:QWORD,:QWORD
ZSTD_CCtxParams_init PROTO cctxParams:QWORD,compressionLevel:QWORD
ZSTD_CCtxParams_init_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_CCtxParams_reset PROTO params:QWORD
ZSTD_CCtxParams_setParameter PROTO :QWORD,:QWORD,:QWORD
ZSTD_CCtx_getParameter PROTO cctx:QWORD,param:QWORD,value:QWORD
ZSTD_CCtx_loadDictionary PROTO cctx:QWORD,dict:QWORD,dictSize:QWORD
ZSTD_CCtx_loadDictionary_advanced PROTO cctx:QWORD,dict:QWORD,dictSize:QWORD,dictLoadMethod:QWORD,dictContentType:QWORD
ZSTD_CCtx_loadDictionary_byReference PROTO :QWORD,:QWORD,:QWORD
ZSTD_CCtx_refCDict PROTO cctx:QWORD,cdict:QWORD
ZSTD_CCtx_refPrefix PROTO cctx:QWORD,prefix:QWORD,prefixSize:QWORD
ZSTD_CCtx_refPrefix_advanced PROTO cctx:QWORD,prefix:QWORD,prefixSize:QWORD,dictContentType:QWORD
ZSTD_CCtx_refThreadPool PROTO :QWORD,:QWORD
ZSTD_CCtx_reset PROTO cctx:QWORD,reset:QWORD
ZSTD_CCtx_setCParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_CCtx_setFParams PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_CCtx_setParameter PROTO cctx:QWORD,param:QWORD,value:QWORD
ZSTD_CCtx_setParametersUsingCCtxParams PROTO cctx:QWORD,params:QWORD
ZSTD_CCtx_setParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_CCtx_setPledgedSrcSize PROTO cctx:QWORD,pledgedSrcSize:QWORD
ZSTD_CCtx_trace PROTO :QWORD,:QWORD
ZSTD_CStreamInSize PROTO 
ZSTD_CStreamOutSize PROTO 
ZSTD_DCtx_getParameter PROTO :QWORD,:QWORD,:QWORD
ZSTD_DCtx_loadDictionary PROTO dctx:QWORD,dict:QWORD,dictSize:QWORD
ZSTD_DCtx_loadDictionary_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_DCtx_loadDictionary_byReference PROTO :QWORD,:QWORD,:QWORD
ZSTD_DCtx_refDDict PROTO dctx:QWORD,ddict:QWORD
ZSTD_DCtx_refPrefix PROTO dctx:QWORD,prefix:QWORD,prefixSize:QWORD
ZSTD_DCtx_refPrefix_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_DCtx_reset PROTO dctx:QWORD,reset:QWORD
ZSTD_DCtx_setFormat PROTO :QWORD,:QWORD
ZSTD_DCtx_setMaxWindowSize PROTO :QWORD,:QWORD
ZSTD_DCtx_setParameter PROTO dctx:QWORD,param:QWORD,value:QWORD
ZSTD_DDict_dictContent PROTO :QWORD
ZSTD_DDict_dictSize PROTO :QWORD
ZSTD_DStreamInSize PROTO 
ZSTD_DStreamOutSize PROTO 
ZSTD_XXH32 PROTO :QWORD,:QWORD,:QWORD
ZSTD_XXH32_canonicalFromHash PROTO :QWORD,:QWORD
ZSTD_XXH32_copyState PROTO :QWORD,:QWORD
ZSTD_XXH32_createState PROTO 
ZSTD_XXH32_digest PROTO :QWORD
ZSTD_XXH32_freeState PROTO :QWORD
ZSTD_XXH32_hashFromCanonical PROTO :QWORD
ZSTD_XXH32_reset PROTO :QWORD,:QWORD
ZSTD_XXH32_update PROTO :QWORD,:QWORD,:QWORD
ZSTD_XXH64 PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_XXH64_canonicalFromHash PROTO :QWORD,:QWORD,:QWORD
ZSTD_XXH64_copyState PROTO :QWORD,:QWORD
ZSTD_XXH64_createState PROTO 
ZSTD_XXH64_digest PROTO :QWORD
ZSTD_XXH64_freeState PROTO :QWORD
ZSTD_XXH64_hashFromCanonical PROTO :QWORD
ZSTD_XXH64_reset PROTO :QWORD,:QWORD,:QWORD
ZSTD_XXH64_update PROTO :QWORD,:QWORD,:QWORD
ZSTD_XXH_versionNumber PROTO 
ZSTD_adjustCParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_buildBlockEntropyStats PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_buildCTable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_buildFSETable PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_cParam_getBounds PROTO cParam:QWORD
ZSTD_checkCParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_checkContinuity PROTO :QWORD,:QWORD,:QWORD
ZSTD_compress2 PROTO cctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD
ZSTD_compress PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,compressionLevel:QWORD
ZSTD_compressBegin PROTO :QWORD,:QWORD
ZSTD_compressBegin_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBegin_advanced_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBegin_usingCDict PROTO :QWORD,:QWORD
ZSTD_compressBegin_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBegin_usingCDict_deprecated PROTO :QWORD,:QWORD
ZSTD_compressBegin_usingDict PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btlazy2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btlazy2_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btlazy2_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btopt PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btopt_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btopt_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btultra2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btultra PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btultra_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_btultra_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_deprecated PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_doubleFast PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_doubleFast_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_doubleFast_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_fast PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_fast_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_fast_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_dedicatedDictSearch PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_dedicatedDictSearch_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_dictMatchState_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_extDict_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_greedy_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_dedicatedDictSearch PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_dedicatedDictSearch_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_dictMatchState_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_extDict_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy2_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_dedicatedDictSearch PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_dedicatedDictSearch_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_dictMatchState PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_dictMatchState_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_extDict PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_extDict_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBlock_lazy_row PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressBound PROTO srcSize:QWORD
ZSTD_compressCCtx PROTO cctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,compressionLevel:QWORD
ZSTD_compressContinue PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressContinue_public PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressEnd PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressEnd_public PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressLiterals PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressRleLiteralsBlock PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compressSequences PROTO cctx:QWORD,dst:QWORD,dstSize:QWORD,inSeqs:QWORD,inSeqsSize:QWORD,src:QWORD,srcSize:QWORD
ZSTD_compressStream2 PROTO cctx:QWORD,output:QWORD,input:QWORD,endOp:QWORD
ZSTD_compressStream2_simpleArgs PROTO cctx:QWORD,dst:QWORD,dstCapacity:QWORD,dstPos:QWORD,src:QWORD,srcSize:QWORD,srcPos:QWORD,endOp:QWORD
ZSTD_compressStream PROTO zcs:QWORD,output:QWORD,input:QWORD
ZSTD_compressSuperBlock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compress_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compress_advanced_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compress_usingCDict PROTO cctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,cdict:QWORD
ZSTD_compress_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_compress_usingDict PROTO ctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,dict:QWORD,dictSize:QWORD,compressionLevel:QWORD
ZSTD_copyCCtx PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_copyDCtx PROTO :QWORD,:QWORD
ZSTD_copyDDictParameters PROTO :QWORD,:QWORD
ZSTD_copySequencesToSeqStoreExplicitBlockDelim PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_copySequencesToSeqStoreNoBlockDelim PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_createCCtx PROTO 
ZSTD_createCCtxParams PROTO 
ZSTD_createCCtx_advanced PROTO :QWORD,:QWORD,:QWORD
ZSTD_createCDict PROTO dictBuffer:QWORD,dictSize:QWORD,compressionLevel:QWORD
ZSTD_createCDict_advanced2 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_createCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_createCDict_byReference PROTO dictBuffer:QWORD,dictSize:QWORD,compressionLevel:QWORD
ZSTD_createCStream PROTO 
ZSTD_createCStream_advanced PROTO :QWORD,:QWORD,:QWORD
ZSTD_createDCtx PROTO 
ZSTD_createDCtx_advanced PROTO :QWORD,:QWORD,:QWORD
ZSTD_createDDict PROTO dictBuffer:QWORD,dictSize:QWORD
ZSTD_createDDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_createDDict_byReference PROTO :QWORD,:QWORD
ZSTD_createDStream PROTO 
ZSTD_createDStream_advanced PROTO :QWORD,:QWORD,:QWORD
ZSTD_crossEntropyCost PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_cycleLog PROTO :QWORD,:QWORD
ZSTD_dParam_getBounds PROTO dParam:QWORD
ZSTD_decodeLiteralsBlock_wrapper PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decodeSeqHeaders PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decodingBufferSize_min PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompress PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,compressedSize:QWORD
ZSTD_decompressBegin PROTO :QWORD
ZSTD_decompressBegin_usingDDict PROTO :QWORD,:QWORD
ZSTD_decompressBegin_usingDict PROTO :QWORD,:QWORD,:QWORD
ZSTD_decompressBlock PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompressBlock_deprecated PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompressBlock_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompressBound PROTO src:QWORD,srcSize:QWORD
ZSTD_decompressContinue PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompressDCtx PROTO dctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD
ZSTD_decompressStream PROTO zds:QWORD,output:QWORD,input:QWORD
ZSTD_decompressStream_simpleArgs PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_decompress_usingDDict PROTO dctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,ddict:QWORD
ZSTD_decompress_usingDict PROTO dctx:QWORD,dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,dict:QWORD,dictSize:QWORD
ZSTD_decompressionMargin PROTO src:QWORD,srcSize:QWORD
ZSTD_dedicatedDictSearch_lazy_loadDictionary PROTO :QWORD,:QWORD
ZSTD_defaultCLevel PROTO 
ZSTD_encodeSequences PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_endStream PROTO zcs:QWORD,output:QWORD
ZSTD_estimateCCtxSize PROTO maxCompressionLevel:QWORD
ZSTD_estimateCCtxSize_usingCCtxParams PROTO params:QWORD
ZSTD_estimateCCtxSize_usingCParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_estimateCDictSize PROTO dictSize:QWORD,compressionLevel:QWORD
ZSTD_estimateCDictSize_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_estimateCStreamSize PROTO maxCompressionLevel:QWORD
ZSTD_estimateCStreamSize_usingCCtxParams PROTO params:QWORD
ZSTD_estimateCStreamSize_usingCParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_estimateDCtxSize PROTO 
ZSTD_estimateDDictSize PROTO dictSize:QWORD,dictLoadMethod:QWORD
ZSTD_estimateDStreamSize PROTO maxWindowSize:QWORD
ZSTD_estimateDStreamSize_fromFrame PROTO src:QWORD,srcSize:QWORD
ZSTD_fillDoubleHashTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_fillHashTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_findDecompressedSize PROTO src:QWORD,srcSize:QWORD
ZSTD_findFrameCompressedSize PROTO src:QWORD,srcSize:QWORD
ZSTD_flushStream PROTO zcs:QWORD,output:QWORD
ZSTD_frameHeaderSize PROTO src:QWORD,srcSize:QWORD
ZSTD_freeCCtx PROTO cctx:QWORD
ZSTD_freeCCtxParams PROTO params:QWORD
ZSTD_freeCDict PROTO CDict:QWORD
ZSTD_freeCStream PROTO :QWORD
ZSTD_freeDCtx PROTO dctx:QWORD
ZSTD_freeDDict PROTO ddict:QWORD
ZSTD_freeDStream PROTO zds:QWORD
ZSTD_fseBitCost PROTO :QWORD,:QWORD,:QWORD
ZSTD_generateSequences PROTO zc:QWORD,outSeqs:QWORD,outSeqsSize:QWORD,src:QWORD,srcSize:QWORD
ZSTD_getBlockSize PROTO :QWORD
ZSTD_getCParams PROTO compressionLevel:QWORD,estimatedSrcSize:QWORD,dictSize:QWORD
ZSTD_getCParamsFromCCtxParams PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_getCParamsFromCDict PROTO :QWORD
ZSTD_getDecompressedSize PROTO src:QWORD,srcSize:QWORD
ZSTD_getDictID_fromCDict PROTO cdict:QWORD
ZSTD_getDictID_fromDDict PROTO ddict:QWORD
ZSTD_getDictID_fromDict PROTO dict:QWORD,dictSize:QWORD
ZSTD_getDictID_fromFrame PROTO src:QWORD,srcSize:QWORD
ZSTD_getErrorCode PROTO functionResult:QWORD
ZSTD_getErrorName PROTO ErrorCode:QWORD
ZSTD_getErrorString PROTO ErrorCode:QWORD
ZSTD_getFrameContentSize PROTO src:QWORD,srcSize:QWORD
ZSTD_getFrameHeader PROTO zfhPtr:QWORD,src:QWORD,srcSize:QWORD
ZSTD_getFrameHeader_advanced PROTO zfhPtr:QWORD,src:QWORD,srcSize:QWORD,format:QWORD
ZSTD_getFrameProgression PROTO :QWORD
ZSTD_getParams PROTO compressionLevel:QWORD,estimatedSrcSize:QWORD,dictSize:QWORD
ZSTD_getSeqStore PROTO :QWORD
ZSTD_getcBlockSize PROTO :QWORD,:QWORD,:QWORD
ZSTD_initCStream PROTO zcs:QWORD,compressionLevel:QWORD
ZSTD_initCStream_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initCStream_internal PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initCStream_srcSize PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initCStream_usingCDict PROTO :QWORD,:QWORD
ZSTD_initCStream_usingCDict_advanced PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initCStream_usingDict PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initDStream PROTO zds:QWORD
ZSTD_initDStream_usingDDict PROTO :QWORD,:QWORD
ZSTD_initDStream_usingDict PROTO :QWORD,:QWORD,:QWORD
ZSTD_initStaticCCtx PROTO workspace:QWORD,workspaceSize:QWORD
ZSTD_initStaticCDict PROTO workspace:QWORD,workspaceSize:QWORD,dict:QWORD,dictSize:QWORD,dictLoadMethod:QWORD,dictContentType:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_initStaticCStream PROTO workspace:QWORD,workspaceSize:QWORD
ZSTD_initStaticDCtx PROTO workspace:QWORD,workspaceSize:QWORD
ZSTD_initStaticDDict PROTO workspace:QWORD,workspaceSize:QWORD,dict:QWORD,dictSize:QWORD,dictLoadMethod:QWORD,dictContentType:QWORD
ZSTD_initStaticDStream PROTO workspace:QWORD,workspaceSize:QWORD
ZSTD_insertAndFindFirstIndex PROTO :QWORD,:QWORD
ZSTD_insertBlock PROTO :QWORD,:QWORD,:QWORD
ZSTD_invalidateRepCodes PROTO :QWORD
ZSTD_isError PROTO ErrorCode:QWORD
ZSTD_isFrame PROTO buffer:QWORD,dwsize:QWORD
ZSTD_isSkippableFrame PROTO buffer:QWORD,dwsize:QWORD
ZSTD_ldm_adjustParameters PROTO :QWORD,:QWORD
ZSTD_ldm_blockCompress PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_ldm_fillHashTable PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_ldm_generateSequences PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_ldm_getMaxNbSeq PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_ldm_getTableSize PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_ldm_skipRawSeqStoreBytes PROTO :QWORD,:QWORD
ZSTD_ldm_skipSequences PROTO :QWORD,:QWORD,:QWORD
ZSTD_loadCEntropy PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_loadDEntropy PROTO :QWORD,:QWORD,:QWORD
ZSTD_maxCLevel PROTO 
ZSTD_mergeBlockDelimiters PROTO sequences:QWORD,seqsSize:QWORD
ZSTD_minCLevel PROTO 
ZSTD_nextInputType PROTO :QWORD
ZSTD_nextSrcSizeToDecompress PROTO :QWORD
ZSTD_noCompressLiterals PROTO :QWORD,:QWORD,:QWORD,:QWORD
ZSTD_readSkippableFrame PROTO dst:QWORD,dstCapacity:QWORD,magicVariant:QWORD,src:QWORD,srcSize:QWORD
ZSTD_referenceExternalSequences PROTO :QWORD,:QWORD,:QWORD
ZSTD_registerSequenceProducer PROTO :QWORD,:QWORD,:QWORD
ZSTD_resetCStream PROTO :QWORD,:QWORD,:QWORD
ZSTD_resetDStream PROTO :QWORD
ZSTD_resetSeqStore PROTO :QWORD
ZSTD_reset_compressedBlockState PROTO :QWORD
ZSTD_row_update PROTO :QWORD,:QWORD
ZSTD_selectBlockCompressor PROTO :QWORD,:QWORD,:QWORD
ZSTD_selectEncodingType PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
ZSTD_seqToCodes PROTO :QWORD
ZSTD_sequenceBound PROTO srcSize:QWORD
ZSTD_sizeof_CCtx PROTO cctx:QWORD
ZSTD_sizeof_CDict PROTO cdict:QWORD
ZSTD_sizeof_CStream PROTO zcs:QWORD
ZSTD_sizeof_DCtx PROTO dctx:QWORD
ZSTD_sizeof_DDict PROTO ddict:QWORD
ZSTD_sizeof_DStream PROTO zds:QWORD
ZSTD_toFlushNow PROTO :QWORD
ZSTD_updateTree PROTO :QWORD,:QWORD,:QWORD
ZSTD_versionNumber PROTO 
ZSTD_versionString PROTO 
ZSTD_writeLastEmptyBlock PROTO :QWORD,:QWORD
ZSTD_writeSkippableFrame PROTO dst:QWORD,dstCapacity:QWORD,src:QWORD,srcSize:QWORD,magicVariant:QWORD


;-------------------------------------------------
; Zstandard Structures:
;-------------------------------------------------
ZSTD_inBuffer               STRUCT 
  src                       QWORD ? ; const void* - start of input buffer
  srcsize                   QWORD ? ; size_t - size of input buffer
  pos                       QWORD ? ; size_t - position where reading stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_inBuffer               ENDS

ZSTD_outBuffer              STRUCT 
  dst                       QWORD ? ; void* - start of output buffer
  dstsize                   QWORD ? ; size_t - size of output buffer
  pos                       QWORD ? ; size_t - position where writing stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_outBuffer              ENDS

ZSTD_bounds                 STRUCT
    zerror                  QWORD ? ; size_t
    lowerBound              DWORD ? ; int
    upperBound              DWORD ? ; int
ZSTD_bounds                 ENDS

ZSTD_compressionParameters  STRUCT
    windowLog               DWORD ? ; unsigned - largest match distance : larger equals more compression, more memory needed during decompression
    chainLog                DWORD ? ; unsigned - fully searched segment : larger equals more compression, slower, more memory (useless for fast)
    hashLog                 DWORD ? ; unsigned - dispatch table : larger equals faster, more memory
    searchLog               DWORD ? ; unsigned - nb of searches : larger equals more compression, slower
    minMatch                DWORD ? ; unsigned - match length searched : larger equals faster decompression, sometimes less compression
    targetLength            DWORD ? ; unsigned - acceptable match size for optimal parser (only) : larger equals more compression, slower
    strategy                DWORD ? ; see ZSTD_strategy enum
ZSTD_compressionParameters  ENDS

ZSTD_frameParameters        STRUCT
    contentSizeFlag         DWORD ? ; int - 1: content size will be in frame header (when known)
    checksumFlag            DWORD ? ; int - generate a 32-bits checksum using XXH64 algorithm at end of frame, for error detection
    noDictIDFlag            DWORD ? ; int - 1: no dictID will be saved into frame header (dictID is only useful for dictionary compression)
ZSTD_frameParameters        ENDS

ZSTD_parameters             STRUCT
    cParams                 ZSTD_compressionParameters <>
    fParams                 ZSTD_frameParameters <>
ZSTD_parameters             ENDS

ZSTD_frameProgression       STRUCT
    ingested                QWORD ? ; unsigned long long - nb input bytes read and buffered
    consumed                QWORD ? ; unsigned long long - nb input bytes actually compressed
    produced                QWORD ? ; unsigned long long - nb of compressed bytes generated and buffered
    flushed                 QWORD ? ; unsigned long long - nb of compressed bytes flushed : not provided; can be tracked from caller side
    currentJobID            DWORD ? ; unsigned - MT only : latest started job nb
    nbActiveWorkers         DWORD ? ; unsigned - MT only : nb of workers actively compressing at probe time
ZSTD_frameProgression       ENDS

ZSTD_frameHeader            STRUCT
    frameContentSize        QWORD ? ; unsigned long long - if equals ZSTD_CONTENTSIZE_UNKNOWN, it means this field is not available. 0 means "empty"
    windowSize              QWORD ? ; unsigned long long - can be very large, up to <= frameContentSize
    blockSizeMax            DWORD ? ; unsigned
    frameType               DWORD ? ; ZSTD_frameType_e - if equals ZSTD_skippableFrame, frameContentSize is the size of skippable content
    headerSize              DWORD ? ; unsigned
    dictID                  DWORD ? ; unsigned
    checksumFlag            DWORD ? ; unsigned
ZSTD_frameHeader            ENDS



;-------------------------------------------------
; Zstandard Constants & Enums
;-------------------------------------------------
.CONST
ZSTD_VERSION_MAJOR          EQU 1
ZSTD_VERSION_MINOR          EQU 5
ZSTD_VERSION_RELEASE        EQU 5
ZSTD_VERSION_NUMBER         EQU ((ZSTD_VERSION_MAJOR *100*100) + (ZSTD_VERSION_MINOR *100) + ZSTD_VERSION_RELEASE)
ZSTD_CLEVEL_DEFAULT         EQU 3
ZSTD_CONTENTSIZE_UNKNOWN    EQU 1
ZSTD_CONTENTSIZE_ERROR      EQU 2
ZSTD_MAGICNUMBER            EQU 0FD2FB528h    ; valid since v0.8.0
ZSTD_MAGIC_DICTIONARY       EQU 0EC30A437h    ; valid since v0.7.0
ZSTD_MAGIC_SKIPPABLE_START  EQU 0184D2A50h    ; all 16 values, from EQU 0184D2A50 to EQU 0184D2A5F, signal the beginning of a skippable frame
ZSTD_MAGIC_SKIPPABLE_MASK   EQU 0FFFFFFF0h
ZSTD_BLOCKSIZELOG_MAX       EQU 17
ZSTD_BLOCKSIZE_MAX          EQU (1 SHL ZSTD_BLOCKSIZELOG_MAX)
ZSTD_FRAMEHEADERSIZE_PREFIX EQU 5   ; minimum input size required to query frame header size
ZSTD_FRAMEHEADERSIZE_MIN    EQU 6
ZSTD_FRAMEHEADERSIZE_MAX    EQU 18   ; can be useful for static allocation
ZSTD_SKIPPABLEHEADERSIZE    EQU 8
; compression parameter bounds
ZSTD_WINDOWLOG_MAX_32       EQU 30
ZSTD_WINDOWLOG_MAX_64       EQU 31
ZSTD_WINDOWLOG_MAX          EQU ZSTD_WINDOWLOG_MAX_32 ;((int)(sizeof(size_t) equals 4 ? ZSTD_WINDOWLOG_MAX_32 : ZSTD_WINDOWLOG_MAX_64))
ZSTD_WINDOWLOG_MIN          EQU 10
ZSTD_HASHLOG_MAX            EQU ZSTD_WINDOWLOG_MAX ;((ZSTD_WINDOWLOG_MAX < 30) ? ZSTD_WINDOWLOG_MAX : 30)
ZSTD_HASHLOG_MIN            EQU 6
ZSTD_CHAINLOG_MAX_32        EQU 29
ZSTD_CHAINLOG_MAX_64        EQU 30
ZSTD_CHAINLOG_MAX           EQU ZSTD_CHAINLOG_MAX_32 ;((int)(sizeof(size_t) equals 4 ? ZSTD_CHAINLOG_MAX_32 : ZSTD_CHAINLOG_MAX_64))
ZSTD_CHAINLOG_MIN           EQU ZSTD_HASHLOG_MIN
ZSTD_SEARCHLOG_MAX          EQU (ZSTD_WINDOWLOG_MAX-1)
ZSTD_SEARCHLOG_MIN          EQU 1
ZSTD_MINMATCH_MAX           EQU 7   ; only for ZSTD_fast, other strategies are limited to 6
ZSTD_MINMATCH_MIN           EQU 3   ; only for ZSTD_btopt+, faster strategies are limited to 4
ZSTD_TARGETLENGTH_MAX       EQU ZSTD_BLOCKSIZE_MAX
ZSTD_TARGETLENGTH_MIN       EQU 0   ; note : comparing this constant to an unsigned results in a tautological test
ZSTD_STRATEGY_MIN           EQU ZSTD_fast
ZSTD_STRATEGY_MAX           EQU ZSTD_btultra2
ZSTD_OVERLAPLOG_MIN         EQU 0
ZSTD_OVERLAPLOG_MAX         EQU 9
ZSTD_WINDOWLOG_LIMIT_DEFAULT EQU 27
; LDM parameter bounds
ZSTD_LDM_HASHLOG_MIN        EQU ZSTD_HASHLOG_MIN
ZSTD_LDM_HASHLOG_MAX        EQU ZSTD_HASHLOG_MAX
ZSTD_LDM_MINMATCH_MIN       EQU 4
ZSTD_LDM_MINMATCH_MAX       EQU 4096
ZSTD_LDM_BUCKETSIZELOG_MIN  EQU 1
ZSTD_LDM_BUCKETSIZELOG_MAX  EQU 8
ZSTD_LDM_HASHRATELOG_MIN    EQU 0
ZSTD_LDM_HASHRATELOG_MAX    EQU (ZSTD_WINDOWLOG_MAX - ZSTD_HASHLOG_MIN)
; Advanced parameter bounds
ZSTD_TARGETCBLOCKSIZE_MIN   EQU 64
ZSTD_TARGETCBLOCKSIZE_MAX   EQU ZSTD_BLOCKSIZE_MAX
ZSTD_SRCSIZEHINT_MIN        EQU 0
ZSTD_SRCSIZEHINT_MAX        EQU INT_MAX
; internal
ZSTD_HASHLOG3_MAX           EQU 17


;-------------------------------------------------
; Enums:
;-------------------------------------------------
; ZSTD_strategy enum (Compression strategies, listed from fastest to strongest):
ZSTD_fast                   EQU 1
ZSTD_dfast                  EQU 2
ZSTD_greedy                 EQU 3
ZSTD_lazy                   EQU 4
ZSTD_lazy2                  EQU 5
ZSTD_btlazy2                EQU 6
ZSTD_btopt                  EQU 7
ZSTD_btultra                EQU 8
ZSTD_btultra2               EQU 9
; ZSTD_ResetDirective enum:
ZSTD_reset_session_only     EQU 1
ZSTD_reset_parameters       EQU 2
ZSTD_reset_session_and_parameters EQU 3
; ZSTD_EndDirective enum:
ZSTD_e_continue             EQU 0
ZSTD_e_flush                EQU 1
ZSTD_e_end                  EQU 2
; ZSTD_cParameter enum:
ZSTD_c_compressionLevel     EQU 100
ZSTD_c_windowLog            EQU 101
ZSTD_c_hashLog              EQU 102
ZSTD_c_chainLog             EQU 103
ZSTD_c_searchLog            EQU 104
ZSTD_c_minMatch             EQU 105
ZSTD_c_targetLength         EQU 106
ZSTD_c_strategy             EQU 107
; LDM mode parameters
ZSTD_c_enableLongDistanceMatching EQU 160
ZSTD_c_ldmHashLog           EQU 161
ZSTD_c_ldmMinMatch          EQU 162
ZSTD_c_ldmBucketSizeLog     EQU 163
ZSTD_c_ldmHashRateLog       EQU 164
ZSTD_c_contentSizeFlag      EQU 200
ZSTD_c_checksumFlag         EQU 201
ZSTD_c_dictIDFlag           EQU 202
ZSTD_c_nbWorkers            EQU 400
ZSTD_c_jobSize              EQU 401
ZSTD_c_overlapLog           EQU 402
ZSTD_c_experimentalParam1   EQU 500
ZSTD_c_experimentalParam2   EQU 10
ZSTD_c_experimentalParam3   EQU 1000
ZSTD_c_experimentalParam4   EQU 1001
ZSTD_c_experimentalParam6   EQU 1003
ZSTD_c_experimentalParam7   EQU 1004
ZSTD_c_experimentalParam8   EQU 1005
ZSTD_c_experimentalParam9   EQU 1006
ZSTD_c_experimentalParam10  EQU 1007
ZSTD_c_experimentalParam11  EQU 1008
ZSTD_c_experimentalParam12  EQU 1009
ZSTD_c_experimentalParam13  EQU 1010
ZSTD_c_experimentalParam14  EQU 1011
ZSTD_c_experimentalParam15  EQU 1012
ZSTD_c_experimentalParam16  EQU 1013
ZSTD_c_experimentalParam17  EQU 1014
ZSTD_c_experimentalParam18  EQU 1015
ZSTD_c_experimentalParam19  EQU 1016
ZSTD_d_windowLogMax         EQU 100
ZSTD_d_experimentalParam1   EQU 1000
ZSTD_d_experimentalParam2   EQU 1001
ZSTD_d_experimentalParam3   EQU 1002
ZSTD_d_experimentalParam4   EQU 1003
ZSTD_d_experimentalParam5   EQU 1004
ZSTD_d_experimentalParam6   EQU 1005

; ZSTD_dictContentType_e enum:
ZSTD_dct_auto               EQU 0
ZSTD_dct_rawContent         EQU 1
ZSTD_dct_fullDict           EQU 2
; ZSTD_dictLoadMethod_e enum:
ZSTD_dlm_byCopy             EQU 0
ZSTD_dlm_byRef              EQU 1
; ZSTD_format_e enum:
ZSTD_f_zstd1                EQU 0
ZSTD_f_zstd1_magicless      EQU 1
; ZSTD_dictLoadMethod_e enum:
ZSTD_dlm_byCopy             EQU 0
ZSTD_dlm_byRef              EQU 1
; ZSTD_dictAttachPref_e enum:
ZSTD_dictDefaultAttach      EQU 0
ZSTD_dictForceAttach        EQU 1
ZSTD_dictForceCopy          EQU 2
; ZSTD_frameType_e enum:
ZSTD_frame                  EQU 0
ZSTD_skippableFrame         EQU 1

; Error codes list
ZSTD_ERROR_NO_ERROR                          EQU 0
ZSTD_ERROR_GENERIC                           EQU 1
ZSTD_ERROR_PREFIX_UNKNOWN                    EQU 10
ZSTD_ERROR_VERSION_UNSUPPORTED               EQU 12
ZSTD_ERROR_FRAMEPARAMETER_UNSUPPORTED        EQU 14
ZSTD_ERROR_FRAMEPARAMETER_WINDOWTOOLARGE     EQU 16
ZSTD_ERROR_CORRUPTION_DETECTED               EQU 20
ZSTD_ERROR_CHECKSUM_WRONG                    EQU 22
ZSTD_ERROR_LITERALS_HEADERWRONG              EQU 24
ZSTD_ERROR_DICTIONARY_CORRUPTED              EQU 30
ZSTD_ERROR_DICTIONARY_WRONG                  EQU 32
ZSTD_ERROR_DICTIONARYCREATION_FAILED         EQU 34
ZSTD_ERROR_PARAMETER_UNSUPPORTED             EQU 40
ZSTD_ERROR_PARAMETER_COMBINATION_UNSUPPORTED EQU 41
ZSTD_ERROR_PARAMETER_OUTOFBOUND              EQU 42
ZSTD_ERROR_TABLELOG_TOOLARGE                 EQU 44
ZSTD_ERROR_MAXSYMBOLVALUE_TOOLARGE           EQU 46
ZSTD_ERROR_MAXSYMBOLVALUE_TOOSMALL           EQU 48
ZSTD_ERROR_STABILITYCONDITION_NOTRESPECTED   EQU 50
ZSTD_ERROR_STAGE_WRONG                       EQU 60
ZSTD_ERROR_INIT_MISSING                      EQU 62
ZSTD_ERROR_MEMORY_ALLOCATION                 EQU 64
ZSTD_ERROR_WORKSPACE_TOOSMALL                EQU 66
ZSTD_ERROR_DSTSIZE_TOOSMALL                  EQU 70
ZSTD_ERROR_SRCSIZE_WRONG                     EQU 72
ZSTD_ERROR_DSTBUFFER_NULL                    EQU 74
ZSTD_ERROR_NOFORWARDPROGRESS_DESTFULL        EQU 80
ZSTD_ERROR_NOFORWARDPROGRESS_INPUTEMPTY      EQU 82
; FOLLOWING ERROR CODES ARE __NOT STABLE__, THEY CAN BE REMOVED OR CHANGED IN FUTURE VERSIONS
ZSTD_ERROR_FRAMEINDEX_TOOLARGE               EQU 100
ZSTD_ERROR_SEEKABLEIO                        EQU 102
ZSTD_ERROR_DSTBUFFER_WRONG                   EQU 104
ZSTD_ERROR_SRCBUFFER_WRONG                   EQU 105
ZSTD_ERROR_SEQUENCEPRODUCER_FAILED           EQU 106
ZSTD_ERROR_EXTERNALSEQUENCES_INVALID         EQU 107
ZSTD_ERROR_MAXCODE                           EQU 120