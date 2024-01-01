;/*
; Copyright (c) 2015-2016, Apple Inc. All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification
; are permitted provided that the following conditions are met:
;
; 1.  Redistributions of source code must retain the above copyright notice, this
;     list of conditions and the following disclaimer.
;
; 2.  Redistributions in binary form must reproduce the above copyright notice, 
;     this list of conditions and the following disclaimer in the documentation 
;     and/or other materials provided with the distribution.
;
; 3.  Neither the name of the copyright holder(s) nor the names of any 
;     contributors may be used to endorse or promote products derived from this 
;     software without specific prior written permission.
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE 
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
; CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
; OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;*/

; https://github.com/lzfse/lzfse

; LZFSE_x64.inc converted from LZFSE source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

fse_init_decoder_table           PROTO nstates:QWORD,nsymbols:QWORD,freq:QWORD,t:QWORD
fse_init_encoder_table           PROTO nstates:QWORD,nsymbols:QWORD,freq:QWORD,t:QWORD
fse_init_value_decoder_table     PROTO nstates:QWORD,nsymbols:QWORD,freq:QWORD,symbol_vbits:QWORD,symbol_vbase:QWORD,t:QWORD
fse_normalize_freq               PROTO nstates:QWORD,nsymbols:QWORD,t:QWORD,freq:QWORD
lzfse_decode                     PROTO state:QWORD
lzfse_decode_buffer              PROTO dst_buffer:QWORD,dst_size:QWORD,src_buffer:QWORD,src_size:QWORD,scratch_buffer:QWORD
lzfse_decode_buffer_with_scratch PROTO dst_buffer:QWORD,dst_size:QWORD,src_buffer:QWORD,src_size:QWORD,scratch_buffer:QWORD
lzfse_decode_scratch_size        PROTO 
lzfse_encode_base                PROTO state:QWORD
lzfse_encode_buffer              PROTO dst_buffer:QWORD,dst_size:QWORD,src_buffer:QWORD,src_size:QWORD,scratch_buffer:QWORD
lzfse_encode_buffer_with_scratch PROTO dst_buffer:QWORD,dst_size:QWORD,src_buffer:QWORD,src_size:QWORD,scratch_buffer:QWORD
lzfse_encode_finish              PROTO state:QWORD
lzfse_encode_init                PROTO state:QWORD
lzfse_encode_scratch_size        PROTO 
lzfse_encode_translate           PROTO state:QWORD,delta:QWORD
lzvn_decode                      PROTO state:QWORD
lzvn_encode                      PROTO state:QWORD
lzvn_encode_buffer               PROTO dst_buffer:QWORD,dst_size:QWORD,src_buffer:QWORD,src_size:QWORD,scratch_buffer:QWORD
lzvn_encode_scratch_size         PROTO 


.CONST
LZFSE_STATUS_OK                 EQU 0
LZFSE_STATUS_SRC_EMPTY          EQU -1
LZFSE_STATUS_DST_FULL           EQU -2
LZFSE_STATUS_ERROR              EQU -3


