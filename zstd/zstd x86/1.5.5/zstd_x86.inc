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

; Zstandard x86 - Fast real-time compression algorithm 
; http://www.zstd.net
; https://github.com/facebook/zstd

; zstd_x86.inc converted from zstandard source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

ERR_getErrorString PROTO STDCALL :DWORD
FSE_NCountWriteBound PROTO STDCALL :DWORD,:DWORD
FSE_buildCTable_rle PROTO STDCALL :DWORD,:DWORD
FSE_buildCTable_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_buildDTable_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_compressBound PROTO STDCALL :DWORD
FSE_compress_usingCTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_decompress_wksp_bmi2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_getErrorName PROTO STDCALL :DWORD
FSE_isError PROTO STDCALL :DWORD
FSE_normalizeCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_optimalTableLog PROTO STDCALL :DWORD,:DWORD,:DWORD
FSE_optimalTableLog_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
FSE_readNCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_readNCount_bmi2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FSE_versionNumber PROTO STDCALL 
FSE_writeNCount PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HIST_count PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HIST_countFast PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HIST_countFast_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HIST_count_simple PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
HIST_count_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HIST_isError PROTO STDCALL :DWORD
HUF_buildCTable_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_cardinality PROTO STDCALL :DWORD,:DWORD
HUF_compress1X_repeat PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_compress1X_usingCTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_compress4X_repeat PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_compress4X_usingCTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_compressBound PROTO STDCALL :DWORD
HUF_decompress1X1_DCtx_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_decompress1X2_DCtx_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_decompress1X_DCtx_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_decompress1X_usingDTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_decompress4X_hufOnly_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_decompress4X_usingDTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_estimateCompressedSize PROTO STDCALL :DWORD,:DWORD,:DWORD
HUF_getErrorName PROTO STDCALL :DWORD
HUF_getNbBitsFromCTable PROTO STDCALL :DWORD,:DWORD
HUF_isError PROTO STDCALL :DWORD
HUF_minTableLog PROTO STDCALL :DWORD
HUF_optimalTableLog PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_readCTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_readCTableHeader PROTO STDCALL :DWORD
HUF_readDTableX1_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_readDTableX2_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_readStats PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_readStats_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
HUF_selectDecoder PROTO STDCALL :DWORD,:DWORD
HUF_validateCTable PROTO STDCALL :DWORD,:DWORD,:DWORD
HUF_writeCTable_wksp PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTDMT_compressStream_generic PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTDMT_createCCtx_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTDMT_freeCCtx PROTO STDCALL :DWORD
ZSTDMT_getFrameProgression PROTO STDCALL :DWORD
ZSTDMT_initCStream_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTDMT_nextInputSizeHint PROTO STDCALL :DWORD
ZSTDMT_sizeof_CCtx PROTO STDCALL :DWORD
ZSTDMT_toFlushNow PROTO STDCALL :DWORD
ZSTDMT_updateCParams_whileCompressing PROTO STDCALL :DWORD,:DWORD
ZSTD_CCtxParams_getParameter PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_CCtxParams_init PROTO STDCALL cctxParams:DWORD,compressionLevel:DWORD
ZSTD_CCtxParams_init_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_CCtxParams_reset PROTO STDCALL params:DWORD
ZSTD_CCtxParams_setParameter PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_CCtx_getParameter PROTO STDCALL cctx:DWORD,param:DWORD,value:DWORD
ZSTD_CCtx_loadDictionary PROTO STDCALL cctx:DWORD,dict:DWORD,dictSize:DWORD
ZSTD_CCtx_loadDictionary_advanced PROTO STDCALL cctx:DWORD,dict:DWORD,dictSize:DWORD,dictLoadMethod:DWORD,dictContentType:DWORD
ZSTD_CCtx_loadDictionary_byReference PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_CCtx_refCDict PROTO STDCALL cctx:DWORD,cdict:DWORD
ZSTD_CCtx_refPrefix PROTO STDCALL cctx:DWORD,prefix:DWORD,prefixSize:DWORD
ZSTD_CCtx_refPrefix_advanced PROTO STDCALL cctx:DWORD,prefix:DWORD,prefixSize:DWORD,dictContentType:DWORD
ZSTD_CCtx_refThreadPool PROTO STDCALL :DWORD,:DWORD
ZSTD_CCtx_reset PROTO STDCALL cctx:DWORD,reset:DWORD
ZSTD_CCtx_setCParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_CCtx_setFParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_CCtx_setParameter PROTO STDCALL cctx:DWORD,param:DWORD,value:DWORD
ZSTD_CCtx_setParametersUsingCCtxParams PROTO STDCALL cctx:DWORD,params:DWORD
ZSTD_CCtx_setParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_CCtx_setPledgedSrcSize PROTO STDCALL cctx:DWORD,pledgedSrcSize:QWORD
ZSTD_CCtx_trace PROTO STDCALL :DWORD,:DWORD
ZSTD_CStreamInSize PROTO STDCALL 
ZSTD_CStreamOutSize PROTO STDCALL 
ZSTD_DCtx_getParameter PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_DCtx_loadDictionary PROTO STDCALL dctx:DWORD,dict:DWORD,dictSize:DWORD
ZSTD_DCtx_loadDictionary_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_DCtx_loadDictionary_byReference PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_DCtx_refDDict PROTO STDCALL dctx:DWORD,ddict:DWORD
ZSTD_DCtx_refPrefix PROTO STDCALL dctx:DWORD,prefix:DWORD,prefixSize:DWORD
ZSTD_DCtx_refPrefix_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_DCtx_reset PROTO STDCALL dctx:DWORD,reset:DWORD
ZSTD_DCtx_setFormat PROTO STDCALL :DWORD,:DWORD
ZSTD_DCtx_setMaxWindowSize PROTO STDCALL :DWORD,:DWORD
ZSTD_DCtx_setParameter PROTO STDCALL dctx:DWORD,param:DWORD,value:DWORD
ZSTD_DDict_dictContent PROTO STDCALL :DWORD
ZSTD_DDict_dictSize PROTO STDCALL :DWORD
ZSTD_DStreamInSize PROTO STDCALL 
ZSTD_DStreamOutSize PROTO STDCALL 
ZSTD_XXH32 PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_XXH32_canonicalFromHash PROTO STDCALL :DWORD,:DWORD
ZSTD_XXH32_copyState PROTO STDCALL :DWORD,:DWORD
ZSTD_XXH32_createState PROTO STDCALL 
ZSTD_XXH32_digest PROTO STDCALL :DWORD
ZSTD_XXH32_freeState PROTO STDCALL :DWORD
ZSTD_XXH32_hashFromCanonical PROTO STDCALL :DWORD
ZSTD_XXH32_reset PROTO STDCALL :DWORD,:DWORD
ZSTD_XXH32_update PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_XXH64 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_XXH64_canonicalFromHash PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_XXH64_copyState PROTO STDCALL :DWORD,:DWORD
ZSTD_XXH64_createState PROTO STDCALL 
ZSTD_XXH64_digest PROTO STDCALL :DWORD
ZSTD_XXH64_freeState PROTO STDCALL :DWORD
ZSTD_XXH64_hashFromCanonical PROTO STDCALL :DWORD
ZSTD_XXH64_reset PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_XXH64_update PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_XXH_versionNumber PROTO STDCALL 
ZSTD_adjustCParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_buildBlockEntropyStats PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_buildCTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_buildFSETable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_cParam_getBounds PROTO STDCALL cParam:DWORD
ZSTD_checkCParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_checkContinuity PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_compress2 PROTO STDCALL cctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD
ZSTD_compress PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,compressionLevel:DWORD
ZSTD_compressBegin PROTO STDCALL :DWORD,:DWORD
ZSTD_compressBegin_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBegin_advanced_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBegin_usingCDict PROTO STDCALL :DWORD,:DWORD
ZSTD_compressBegin_usingCDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBegin_usingCDict_deprecated PROTO STDCALL :DWORD,:DWORD
ZSTD_compressBegin_usingDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btlazy2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btlazy2_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btlazy2_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btopt PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btopt_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btopt_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btultra2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btultra PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btultra_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_btultra_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_deprecated PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_doubleFast PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_doubleFast_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_doubleFast_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_fast PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_fast_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_fast_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_dedicatedDictSearch PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_dedicatedDictSearch_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_dictMatchState_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_extDict_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_greedy_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_dedicatedDictSearch PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_dedicatedDictSearch_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_dictMatchState_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_extDict_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy2_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_dedicatedDictSearch PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_dedicatedDictSearch_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_dictMatchState PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_dictMatchState_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_extDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_extDict_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBlock_lazy_row PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressBound PROTO STDCALL srcSize:DWORD
ZSTD_compressCCtx PROTO STDCALL cctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,compressionLevel:DWORD
ZSTD_compressContinue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressContinue_public PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressEnd PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressEnd_public PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressLiterals PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressRleLiteralsBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compressSequences PROTO STDCALL cctx:DWORD,dst:DWORD,dstSize:DWORD,inSeqs:DWORD,inSeqsSize:DWORD,src:DWORD,srcSize:DWORD
ZSTD_compressStream2 PROTO STDCALL cctx:DWORD,output:DWORD,input:DWORD,endOp:DWORD
ZSTD_compressStream2_simpleArgs PROTO STDCALL cctx:DWORD,dst:DWORD,dstCapacity:DWORD,dstPos:DWORD,src:DWORD,srcSize:DWORD,srcPos:DWORD,endOp:DWORD
ZSTD_compressStream PROTO STDCALL zcs:DWORD,output:DWORD,input:DWORD
ZSTD_compressSuperBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compress_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compress_advanced_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compress_usingCDict PROTO STDCALL cctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,cdict:DWORD
ZSTD_compress_usingCDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_compress_usingDict PROTO STDCALL ctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,dict:DWORD,dictSize:DWORD,compressionLevel:DWORD
ZSTD_copyCCtx PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_copyDCtx PROTO STDCALL :DWORD,:DWORD
ZSTD_copyDDictParameters PROTO STDCALL :DWORD,:DWORD
ZSTD_copySequencesToSeqStoreExplicitBlockDelim PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_copySequencesToSeqStoreNoBlockDelim PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_createCCtx PROTO STDCALL 
ZSTD_createCCtxParams PROTO STDCALL 
ZSTD_createCCtx_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_createCDict PROTO STDCALL dictBuffer:DWORD,dictSize:DWORD,compressionLevel:DWORD
ZSTD_createCDict_advanced2 PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_createCDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_createCDict_byReference PROTO STDCALL dictBuffer:DWORD,dictSize:DWORD,compressionLevel:DWORD
ZSTD_createCStream PROTO STDCALL 
ZSTD_createCStream_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_createDCtx PROTO STDCALL 
ZSTD_createDCtx_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_createDDict PROTO STDCALL dictBuffer:DWORD,dictSize:DWORD
ZSTD_createDDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_createDDict_byReference PROTO STDCALL :DWORD,:DWORD
ZSTD_createDStream PROTO STDCALL 
ZSTD_createDStream_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_crossEntropyCost PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_cycleLog PROTO STDCALL :DWORD,:DWORD
ZSTD_dParam_getBounds PROTO STDCALL dParam:DWORD
ZSTD_decodeLiteralsBlock_wrapper PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decodeSeqHeaders PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decodingBufferSize_min PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompress PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,compressedSize:DWORD
ZSTD_decompressBegin PROTO STDCALL :DWORD
ZSTD_decompressBegin_usingDDict PROTO STDCALL :DWORD,:DWORD
ZSTD_decompressBegin_usingDict PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_decompressBlock PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompressBlock_deprecated PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompressBlock_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompressBound PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_decompressContinue PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompressDCtx PROTO STDCALL dctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD
ZSTD_decompressStream PROTO STDCALL zds:DWORD,output:DWORD,input:DWORD
ZSTD_decompressStream_simpleArgs PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_decompress_usingDDict PROTO STDCALL dctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,ddict:DWORD
ZSTD_decompress_usingDict PROTO STDCALL dctx:DWORD,dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,dict:DWORD,dictSize:DWORD
ZSTD_decompressionMargin PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_dedicatedDictSearch_lazy_loadDictionary PROTO STDCALL :DWORD,:DWORD
ZSTD_defaultCLevel PROTO STDCALL 
ZSTD_encodeSequences PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_endStream PROTO STDCALL zcs:DWORD,output:DWORD
ZSTD_estimateCCtxSize PROTO STDCALL maxCompressionLevel:DWORD
ZSTD_estimateCCtxSize_usingCCtxParams PROTO STDCALL params:DWORD
ZSTD_estimateCCtxSize_usingCParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_estimateCDictSize PROTO STDCALL dictSize:DWORD,compressionLevel:DWORD
ZSTD_estimateCDictSize_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_estimateCStreamSize PROTO STDCALL maxCompressionLevel:DWORD
ZSTD_estimateCStreamSize_usingCCtxParams PROTO STDCALL params:DWORD
ZSTD_estimateCStreamSize_usingCParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_estimateDCtxSize PROTO STDCALL 
ZSTD_estimateDDictSize PROTO STDCALL dictSize:DWORD,dictLoadMethod:DWORD
ZSTD_estimateDStreamSize PROTO STDCALL maxWindowSize:DWORD
ZSTD_estimateDStreamSize_fromFrame PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_fillDoubleHashTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_fillHashTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_findDecompressedSize PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_findFrameCompressedSize PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_flushStream PROTO STDCALL zcs:DWORD,output:DWORD
ZSTD_frameHeaderSize PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_freeCCtx PROTO STDCALL cctx:DWORD
ZSTD_freeCCtxParams PROTO STDCALL params:DWORD
ZSTD_freeCDict PROTO STDCALL CDict:DWORD
ZSTD_freeCStream PROTO STDCALL :DWORD
ZSTD_freeDCtx PROTO STDCALL dctx:DWORD
ZSTD_freeDDict PROTO STDCALL ddict:DWORD
ZSTD_freeDStream PROTO STDCALL zds:DWORD
ZSTD_fseBitCost PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_generateSequences PROTO STDCALL zc:DWORD,outSeqs:DWORD,outSeqsSize:DWORD,src:DWORD,srcSize:DWORD
ZSTD_getBlockSize PROTO STDCALL :DWORD
ZSTD_getCParams PROTO STDCALL compressionLevel:DWORD,estimatedSrcSize:QWORD,dictSize:DWORD
ZSTD_getCParamsFromCCtxParams PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_getCParamsFromCDict PROTO STDCALL :DWORD
ZSTD_getDecompressedSize PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_getDictID_fromCDict PROTO STDCALL cdict:DWORD
ZSTD_getDictID_fromDDict PROTO STDCALL ddict:DWORD
ZSTD_getDictID_fromDict PROTO STDCALL dict:DWORD,dictSize:DWORD
ZSTD_getDictID_fromFrame PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_getErrorCode PROTO STDCALL functionResult:DWORD
ZSTD_getErrorName PROTO STDCALL ErrorCode:DWORD
ZSTD_getErrorString PROTO STDCALL ErrorCode:DWORD
ZSTD_getFrameContentSize PROTO STDCALL src:DWORD,srcSize:DWORD
ZSTD_getFrameHeader PROTO STDCALL zfhPtr:DWORD,src:DWORD,srcSize:DWORD
ZSTD_getFrameHeader_advanced PROTO STDCALL zfhPtr:DWORD,src:DWORD,srcSize:DWORD,format:DWORD
ZSTD_getFrameProgression PROTO STDCALL :DWORD
ZSTD_getParams PROTO STDCALL compressionLevel:DWORD,estimatedSrcSize:QWORD,dictSize:DWORD
ZSTD_getSeqStore PROTO STDCALL :DWORD
ZSTD_getcBlockSize PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_initCStream PROTO STDCALL zcs:DWORD,compressionLevel:DWORD
ZSTD_initCStream_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initCStream_internal PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initCStream_srcSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initCStream_usingCDict PROTO STDCALL :DWORD,:DWORD
ZSTD_initCStream_usingCDict_advanced PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initCStream_usingDict PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initDStream PROTO STDCALL zds:DWORD
ZSTD_initDStream_usingDDict PROTO STDCALL :DWORD,:DWORD
ZSTD_initDStream_usingDict PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_initStaticCCtx PROTO STDCALL workspace:DWORD,workspaceSize:DWORD
ZSTD_initStaticCDict PROTO STDCALL workspace:DWORD,workspaceSize:DWORD,dict:DWORD,dictSize:DWORD,dictLoadMethod:DWORD,dictContentType:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_initStaticCStream PROTO STDCALL workspace:DWORD,workspaceSize:DWORD
ZSTD_initStaticDCtx PROTO STDCALL workspace:DWORD,workspaceSize:DWORD
ZSTD_initStaticDDict PROTO STDCALL workspace:DWORD,workspaceSize:DWORD,dict:DWORD,dictSize:DWORD,dictLoadMethod:DWORD,dictContentType:DWORD
ZSTD_initStaticDStream PROTO STDCALL workspace:DWORD,workspaceSize:DWORD
ZSTD_insertAndFindFirstIndex PROTO STDCALL :DWORD,:DWORD
ZSTD_insertBlock PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_invalidateRepCodes PROTO STDCALL :DWORD
ZSTD_isError PROTO STDCALL ErrorCode:DWORD
ZSTD_isFrame PROTO STDCALL buffer:DWORD,dwsize:DWORD
ZSTD_isSkippableFrame PROTO STDCALL buffer:DWORD,dwsize:DWORD
ZSTD_ldm_adjustParameters PROTO STDCALL :DWORD,:DWORD
ZSTD_ldm_blockCompress PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_ldm_fillHashTable PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_ldm_generateSequences PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_ldm_getMaxNbSeq PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_ldm_getTableSize PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_ldm_skipRawSeqStoreBytes PROTO STDCALL :DWORD,:DWORD
ZSTD_ldm_skipSequences PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_loadCEntropy PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_loadDEntropy PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_maxCLevel PROTO STDCALL 
ZSTD_mergeBlockDelimiters PROTO STDCALL sequences:DWORD,seqsSize:DWORD
ZSTD_minCLevel PROTO STDCALL 
ZSTD_nextInputType PROTO STDCALL :DWORD
ZSTD_nextSrcSizeToDecompress PROTO STDCALL :DWORD
ZSTD_noCompressLiterals PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
ZSTD_readSkippableFrame PROTO STDCALL dst:DWORD,dstCapacity:DWORD,magicVariant:DWORD,src:DWORD,srcSize:DWORD
ZSTD_referenceExternalSequences PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_registerSequenceProducer PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_resetCStream PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_resetDStream PROTO STDCALL :DWORD
ZSTD_resetSeqStore PROTO STDCALL :DWORD
ZSTD_reset_compressedBlockState PROTO STDCALL :DWORD
ZSTD_row_update PROTO STDCALL :DWORD,:DWORD
ZSTD_selectBlockCompressor PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_selectEncodingType PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ZSTD_seqToCodes PROTO STDCALL :DWORD
ZSTD_sequenceBound PROTO STDCALL srcSize:DWORD
ZSTD_sizeof_CCtx PROTO STDCALL cctx:DWORD
ZSTD_sizeof_CDict PROTO STDCALL cdict:DWORD
ZSTD_sizeof_CStream PROTO STDCALL zcs:DWORD
ZSTD_sizeof_DCtx PROTO STDCALL dctx:DWORD
ZSTD_sizeof_DDict PROTO STDCALL ddict:DWORD
ZSTD_sizeof_DStream PROTO STDCALL zds:DWORD
ZSTD_toFlushNow PROTO STDCALL :DWORD
ZSTD_updateTree PROTO STDCALL :DWORD,:DWORD,:DWORD
ZSTD_versionNumber PROTO STDCALL 
ZSTD_versionString PROTO STDCALL 
ZSTD_writeLastEmptyBlock PROTO STDCALL :DWORD,:DWORD
ZSTD_writeSkippableFrame PROTO STDCALL dst:DWORD,dstCapacity:DWORD,src:DWORD,srcSize:DWORD,magicVariant:DWORD


;-------------------------------------------------
; Zstandard Structures:
;-------------------------------------------------
ZSTD_inBuffer               STRUCT 
  src                       DWORD ? ; const void* - start of input buffer
  srcsize                   DWORD ? ; size_t - size of input buffer
  pos                       DWORD ? ; size_t - position where reading stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_inBuffer               ENDS

ZSTD_outBuffer              STRUCT 
  dst                       DWORD ? ; void* - start of output buffer
  dstsize                   DWORD ? ; size_t - size of output buffer
  pos                       DWORD ? ; size_t - position where writing stopped. Will be updated. Necessarily 0 <= pos <= size
ZSTD_outBuffer              ENDS

ZSTD_bounds                 STRUCT
    zerror                  DWORD ? ; size_t
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