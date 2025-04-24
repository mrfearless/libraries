;/* LZO.h -- public interface of the LZO compression algorithms
;
;   This file is part of the LZO real-time data compression library.
;
;   Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer
;   All Rights Reserved.
;
;   The LZO library is free software; you can redistribute it and/or
;   modify it under the terms of the GNU General Public License as
;   published by the Free Software Foundation; either version 2 of
;   the License, or (at your option) any later version.
;
;   The LZO library is distributed in the hope that it will be useful,
;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License
;   along with the LZO library; see the file COPYING.
;   If not, write to the Free Software Foundation, Inc.,
;   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
;
;   Markus F.X.J. Oberhumer
;   <markus@oberhumer.com>
;   http://www.oberhumer.com/opensource/lzo/
; */

; LZO_x86.inc converted from LZO source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

lzo1_99_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1_compress               PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1_decompress             PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1_info                   PROTO STDCALL rbits:DWORD,clevel:DWORD
lzo1a_99_compress           PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1a_compress              PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1a_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1a_info                  PROTO STDCALL rbits:DWORD,clevel:DWORD
lzo1b_1_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_2_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_3_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_4_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_5_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_6_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_7_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_8_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_999_compress_callback PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,cb:DWORD,max_chain:DWORD
lzo1b_99_compress           PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_9_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_compress              PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,compression_level:DWORD
lzo1b_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1b_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_1_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_2_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_3_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_4_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_5_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_6_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_7_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_8_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_999_compress_callback PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,cb:DWORD,max_chain:DWORD
lzo1c_99_compress           PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_9_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_compress              PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,compression_level:DWORD
lzo1c_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1c_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1f_1_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1f_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1f_999_compress_callback PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,cb:DWORD,max_chain:DWORD
lzo1f_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1f_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_1_11_compress         PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_1_12_compress         PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_1_15_compress         PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_1_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_999_compress_dict     PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1x_999_compress_internal PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,try_lazy_parm:DWORD,good_length:DWORD,max_lazy:DWORD,nice_length:DWORD,max_chain:DWORD,flags:DWORD
lzo1x_999_compress_level    PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,compression_level:DWORD
lzo1x_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_decompress_dict_safe  PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1x_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1x_optimize              PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1y_1_compress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1y_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1y_999_compress_dict     PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1y_999_compress_internal PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,try_lazy_parm:DWORD,good_length:DWORD,max_lazy:DWORD,nice_length:DWORD,max_chain:DWORD,flags:DWORD
lzo1y_999_compress_level    PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,compression_level:DWORD
lzo1y_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1y_decompress_dict_safe  PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1y_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1y_optimize              PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1z_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1z_999_compress_dict     PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1z_999_compress_internal PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,try_lazy_parm:DWORD,good_length:DWORD,max_lazy:DWORD,nice_length:DWORD,max_chain:DWORD,flags:DWORD
lzo1z_999_compress_level    PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD,cb:DWORD,compression_level:DWORD
lzo1z_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo1z_decompress_dict_safe  PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD,dict:DWORD,dict_len:DWORD
lzo1z_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo2a_999_compress          PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo2a_999_compress_callback PROTO STDCALL inbuffer:DWORD,in_len:DWORD,outbuffer:DWORD,out_len:DWORD,wrkmem:DWORD,cb:DWORD,max_chain:DWORD
lzo2a_decompress            PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo2a_decompress_safe       PROTO STDCALL src:DWORD,src_len:DWORD,dst:DWORD,dst_len:DWORD,wrkmem:DWORD
lzo_adler32                 PROTO STDCALL char:DWORD,buf:DWORD,len:DWORD
lzo_copyright               PROTO STDCALL 
lzo_crc32                   PROTO STDCALL char:DWORD,buf:DWORD,len:DWORD
lzo_get_crc32_table         PROTO STDCALL 
lzo_memcmp                  PROTO STDCALL a:DWORD,b:DWORD,len:DWORD
lzo_memcpy                  PROTO STDCALL dst:DWORD,src:DWORD,len:DWORD
lzo_memmove                 PROTO STDCALL dst:DWORD,src:DWORD,len:DWORD
lzo_memset                  PROTO STDCALL buf:DWORD,char:DWORD,len:DWORD
lzo_version                 PROTO STDCALL 
lzo_version_date            PROTO STDCALL 
lzo_version_string          PROTO STDCALL 

.CONST

LZO_VERSION                 EQU 020a0h  ; 2.10
LZO_VERSION_STRING          TEXTEQU <"2.10">
LZO_VERSION_DATE            TEXTEQU <"Mar 01 2017">

; Error codes for the compression/decompression functions. Negative
; values are errors, positive values will be used for special but
; normal events.
LZO_E_OK                    EQU 0
LZO_E_ERROR                 EQU (-1)
LZO_E_OUT_OF_MEMORY         EQU (-2)    ; [lzo_alloc_func_t failure]
LZO_E_NOT_COMPRESSIBLE      EQU (-3)    ; [not used right now]
LZO_E_INPUT_OVERRUN         EQU (-4)
LZO_E_OUTPUT_OVERRUN        EQU (-5)
LZO_E_LOOKBEHIND_OVERRUN    EQU (-6)
LZO_E_EOF_NOT_FOUND         EQU (-7)
LZO_E_INPUT_NOT_CONSUMED    EQU (-8)
LZO_E_NOT_YET_IMPLEMENTED   EQU (-9)    ; [not used right now]
LZO_E_INVALID_ARGUMENT      EQU (-10)
LZO_E_INVALID_ALIGNMENT     EQU (-11)   ; pointer argument is not properly aligned
LZO_E_OUTPUT_NOT_CONSUMED   EQU (-12)
LZO_E_INTERNAL_ERROR        EQU (-99)

lzo_sizeof_dict_t           EQU SIZEOF DWORD ; SIZEOF QWORD in x64


LZO1_MEM_COMPRESS           EQU (8192 * lzo_sizeof_dict_t)
LZO1_MEM_DECOMPRESS         EQU (0)

LZO1A_MEM_COMPRESS          EQU (8192 * lzo_sizeof_dict_t)
LZO1A_MEM_DECOMPRESS        EQU (0)
LZO1A_99_MEM_COMPRESS       EQU (65536 * lzo_sizeof_dict_t)

LZO1B_MEM_COMPRESS          EQU (16384 * lzo_sizeof_dict_t)
LZO1B_MEM_DECOMPRESS        EQU (0)
LZO1B_BEST_SPEED            EQU 1
LZO1B_BEST_COMPRESSION      EQU 9
LZO1B_DEFAULT_COMPRESSION   EQU (-1) ; fastest by default
LZO1B_99_MEM_COMPRESS       EQU (65536 * lzo_sizeof_dict_t)
LZO1B_999_MEM_COMPRESS      EQU (3 * 65536 * SIZEOF (DWORD)) ; SIZEOF QWORD in x64

LZO1C_MEM_COMPRESS          EQU (16384 * lzo_sizeof_dict_t)
LZO1C_MEM_DECOMPRESS        EQU (0)
LZO1C_BEST_SPEED            EQU 1
LZO1C_BEST_COMPRESSION      EQU 9
LZO1C_DEFAULT_COMPRESSION   EQU (-1) ; fastest by default
LZO1C_99_MEM_COMPRESS       EQU (65536 * lzo_sizeof_dict_t)
LZO1C_999_MEM_COMPRESS      EQU (5 * 16384 * SIZEOF (WORD))

LZO1F_MEM_COMPRESS          EQU (16384 * lzo_sizeof_dict_t)
LZO1F_MEM_DECOMPRESS        EQU (0)
LZO1F_999_MEM_COMPRESS      EQU (5 * 16384 * SIZEOF (WORD))

LZO1X_MEM_COMPRESS          EQU LZO1X_1_MEM_COMPRESS
LZO1X_MEM_DECOMPRESS        EQU (0)
LZO1X_MEM_OPTIMIZE          EQU (0)
LZO1X_1_MEM_COMPRESS        EQU (16384 * lzo_sizeof_dict_t)
LZO1X_1_11_MEM_COMPRESS     EQU (2048 * lzo_sizeof_dict_t)
LZO1X_1_12_MEM_COMPRESS     EQU (4096 * lzo_sizeof_dict_t)
LZO1X_1_15_MEM_COMPRESS     EQU (32768 * lzo_sizeof_dict_t)
LZO1X_999_MEM_COMPRESS      EQU (14 * 16384 * SIZEOF (WORD))

LZO1Y_MEM_COMPRESS          EQU (16384 * lzo_sizeof_dict_t)
LZO1Y_MEM_DECOMPRESS        EQU (0)
LZO1Y_MEM_OPTIMIZE          EQU (0)
LZO1Y_999_MEM_COMPRESS      EQU (14 * 16384 * SIZEOF (WORD))

LZO1Z_MEM_DECOMPRESS        EQU (0)
LZO1Z_999_MEM_COMPRESS      EQU (14 * 16384 * SIZEOF (WORD))

LZO2A_MEM_DECOMPRESS        EQU (0)
LZO2A_999_MEM_COMPRESS      EQU (8 * 16384 * SIZEOF (WORD))








