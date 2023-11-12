;/*
; * BriefLZ - small fast Lempel-Ziv
; *
; * C/C++ header file
; *
; * Copyright (c) 2002-2020 Joergen Ibsen
; *
; * This software is provided 'as-is', without any express or implied
; * warranty. In no event will the authors be held liable for any damages
; * arising from the use of this software.
; *
; * Permission is granted to anyone to use this software for any purpose,
; * including commercial applications, and to alter it and redistribute it
; * freely, subject to the following restrictions:
; *
; *   1. The origin of this software must not be misrepresented; you must
; *      not claim that you wrote the original software. If you use this
; *      software in a product, an acknowledgment in the product
; *      documentation would be appreciated but is not required.
; *
; *   2. Altered source versions must be plainly marked as such, and must
; *      not be misrepresented as being the original software.
; *
; *   3. This notice may not be removed or altered from any source
; *      distribution.
; */
;
; https://github.com/jibsen/brieflz
;
; Compression levels between 1 and 9 offer a trade-off between time/space 
; and ratio. Level 10 is optimal but very slow.
 
; brieflz_x86.inc converted from brieflz source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

blz_depack              PROTO STDCALL src:DWORD,dst:DWORD,depacked_size:DWORD
blz_depack_safe         PROTO STDCALL src:DWORD,src_size:DWORD,dst:DWORD,depacked_size:DWORD
blz_max_packed_size     PROTO STDCALL src_size:DWORD
blz_pack                PROTO STDCALL src:DWORD,dst:DWORD,src_size:DWORD,workmem:DWORD
blz_pack_level          PROTO STDCALL src:DWORD,dst:DWORD,src_size:DWORD,workmem:DWORD,level:DWORD
blz_workmem_size        PROTO STDCALL src_size:DWORD
blz_workmem_size_level  PROTO STDCALL src_size:DWORD,level:DWORD



.CONST

BLZ_VER_MAJOR           EQU 1               ; Major version number
BLZ_VER_MINOR           EQU 3               ; Minor version number
BLZ_VER_PATCH           EQU 0               ; Patch version number
BLZ_VER_STRING          TEXTEQU <"1.3.0">   ; Version number as a string

BLZ_ERROR               EQU -1











