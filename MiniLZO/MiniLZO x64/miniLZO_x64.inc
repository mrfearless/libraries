;/* minilzo.h -- mini subset of the LZO real-time data compression library
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
;
;/*
; * NOTE:
; *   the full LZO package can be found at
; *   http://www.oberhumer.com/opensource/lzo/
; */

; miniLZO_x64.inc converted from miniLZO source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

lzo1x_1_compress            PROTO src:QWORD,src_len:QWORD,dst:QWORD,dst_len:QWORD,wrkmem:QWORD
lzo1x_decompress            PROTO src:QWORD,src_len:QWORD,dst:QWORD,dst_len:QWORD,wrkmem:QWORD
lzo1x_decompress_safe       PROTO src:QWORD,src_len:QWORD,dst:QWORD,dst_len:QWORD,wrkmem:QWORD
lzo_adler32                 PROTO char:QWORD,buf:QWORD,len:QWORD
lzo_copyright               PROTO 
lzo_memcmp                  PROTO a:QWORD,b:QWORD,len:QWORD
lzo_memcpy                  PROTO dst:QWORD,src:QWORD,len:QWORD
lzo_memmove                 PROTO dst:QWORD,src:QWORD,len:QWORD
lzo_memset                  PROTO buf:QWORD,char:QWORD,len:QWORD
lzo_version                 PROTO 
lzo_version_date            PROTO 
lzo_version_string          PROTO 

.CONST
MINILZO_VERSION             EQU 020a0h  ; 2.10

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

IFNDEF LZO1X_MEM_COMPRESS
LZO1X_MEM_COMPRESS          EQU LZO1X_1_MEM_COMPRESS
ENDIF
IFNDEF LZO1X_1_MEM_COMPRESS
LZO1X_1_MEM_COMPRESS        EQU (16384 * SIZEOF QWORD) *2
ENDIF
IFNDEF LZO1X_MEM_DECOMPRESS
LZO1X_MEM_DECOMPRESS        EQU (0)
ENDIF
