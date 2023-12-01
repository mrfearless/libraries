;/*
; * BZip3 - A spiritual successor to BZip2.
; * Copyright (C) 2022-2023 Kamila Szewczyk
; *
; * This program is free software: you can redistribute it and/or modify it
; * under the terms of the GNU Lesser General Public License as published by the Free
; * Software Foundation, either version 3 of the License, or (at your option)
; * any later version.
; *
; * This program is distributed in the hope that it will be useful, but WITHOUT
; * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
; * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
; * more details.
; *
; * You should have received a copy of the GNU Lesser General Public License along with
; * this program.  If not, see <http://www.gnu.org/licenses/>.
; */

; https://github.com/kspalaiologos/bzip3

; bzip3_x86.inc converted from bzip3 source for assembler by fearless 2023
; www.github.com/mrfearless

; The maximum block size must be between 65KiB and 511MiB

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

bz3_bound           PROTO STDCALL input_size:DWORD
bz3_compress        PROTO STDCALL block_size:DWORD,indata:DWORD,outdata:DWORD,indata_size:DWORD,outdata_size:DWORD
bz3_decode_block    PROTO STDCALL state:DWORD,buffer:DWORD,buffersize:DWORD,orig_size:DWORD
bz3_decompress      PROTO STDCALL indata:DWORD,outdata:DWORD,indata_size:DWORD,outdata_size:DWORD
bz3_encode_block    PROTO STDCALL state:DWORD,buffer:DWORD,buffersize:DWORD
bz3_free            PROTO STDCALL state:DWORD
bz3_last_error      PROTO STDCALL state:DWORD
bz3_new             PROTO STDCALL block_size:DWORD
bz3_strerror        PROTO STDCALL state:DWORD
bz3_version         PROTO STDCALL 


.CONST
BZ3_OK                      EQU  0
BZ3_ERR_OUT_OF_BOUNDS       EQU -1
BZ3_ERR_BWT                 EQU -2
BZ3_ERR_CRC                 EQU -3
BZ3_ERR_MALFORMED_HEADER    EQU -4
BZ3_ERR_TRUNCATED_DATA      EQU -5
BZ3_ERR_DATA_TOO_BIG        EQU -6
BZ3_ERR_INIT                EQU -7

