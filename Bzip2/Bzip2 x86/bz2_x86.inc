; This program, "bzip2", the associated library "libbzip2", and all
; documentation, are copyright (C) 1996-2010 Julian R Seward.  All
; rights reserved.
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
; 1. Redistributions of source code must retain the above copyright
;    notice, this list of conditions and the following disclaimer.
; 
; 2. The origin of this software must not be misrepresented; you must
;    not claim that you wrote the original software.  If you use this
;    software in a product, an acknowledgment in the product
;    documentation would be appreciated but is not required.
; 
; 3. Altered source versions must be plainly marked as such, and must
;    not be misrepresented as being the original software.
; 
; 4. The name of the author may not be used to endorse or promote
;    products derived from this software without specific prior written
;    permission.
; 
; THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
; WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
; ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
; DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
; GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
; INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
; WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
; NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; Julian Seward, jseward@acm.org
; bzip2/libbzip2 version 1.1.0 of 6 September 2010
;
; Copyright (C) 1996-2010 Julian Seward <jseward@acm.org>
; Copyright (C) 2019-2020 Federico Mena Quintero <federico@gnome.org>
; Copyright (C) 2021 [Micah Snyder](https://gitlab.com/micahsnyder).

; bz2_x86.inc converted from bzip2 source for assembler by fearless 2023
; www.github.com/mrfearless
;
; https://www.cs.cmu.edu/afs/cs/project/pscico-guyb/realworld/99/code/bzip2-0.9.5c/manual_3.html

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

BZ2_bzBuffToBuffCompress PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD,blockSize100k:DWORD,verbosity:DWORD,workFactor:DWORD
BZ2_bzBuffToBuffDecompress PROTO STDCALL dest:DWORD,destLen:DWORD,source:DWORD,sourceLen:DWORD,small:DWORD,verbosity:DWORD
BZ2_bzCompress PROTO STDCALL strm:DWORD,action:DWORD
BZ2_bzCompressEnd PROTO STDCALL strm:DWORD
BZ2_bzCompressInit PROTO STDCALL strm:DWORD,blockSize100k:DWORD,verbosity:DWORD,workFactor:DWORD
BZ2_bzDecompress PROTO STDCALL strm:DWORD
BZ2_bzDecompressEnd PROTO STDCALL strm:DWORD
BZ2_bzDecompressInit PROTO STDCALL strm:DWORD,verbosity:DWORD,small:DWORD
BZ2_bzRead PROTO STDCALL bzerror:DWORD,b:DWORD,buf:DWORD,len:DWORD
BZ2_bzReadClose PROTO STDCALL bzerror:DWORD,b:DWORD
BZ2_bzReadGetUnused PROTO STDCALL bzerror:DWORD,b:DWORD,unused:DWORD,nUnused:DWORD
BZ2_bzReadOpen PROTO STDCALL bzerror:DWORD,f:DWORD,verbosity:DWORD,small:DWORD,unused:DWORD,nUnused:DWORD
BZ2_bzWrite PROTO STDCALL bzerror:DWORD,b:DWORD,buf:DWORD,len:DWORD
BZ2_bzWriteClose64 PROTO STDCALL bzerror:DWORD,b:DWORD,abandon:DWORD,nbytes_in_lo32:DWORD,nbytes_in_hi32:DWORD,nbytes_out_lo32:DWORD,nbytes_out_hi32:DWORD
BZ2_bzWriteClose PROTO STDCALL bzerror:DWORD,b:DWORD,abandon:DWORD,nbytes_in:DWORD,nbytes_out:DWORD
BZ2_bzWriteOpen PROTO STDCALL bzerror:DWORD,f:DWORD,blockSize100k:DWORD,verbosity:DWORD,workFactor:DWORD
BZ2_bzclose PROTO STDCALL b:DWORD
BZ2_bzdopen PROTO STDCALL fd:DWORD,mode:DWORD
BZ2_bzerror PROTO STDCALL b:DWORD,errnum:DWORD
BZ2_bzflush PROTO STDCALL b:DWORD
BZ2_bzlibVersion PROTO STDCALL 
BZ2_bzopen PROTO STDCALL path:DWORD,mode:DWORD
BZ2_bzread PROTO STDCALL b:DWORD,buf:DWORD,len:DWORD
BZ2_bzwrite PROTO STDCALL b:DWORD,buf:DWORD,len:DWORD



bz_stream               STRUCT
    next_in             DD ? ; char *;
    avail_in            DD ? ; unsigned int ;
    total_in_lo32       DD ? ; unsigned int 
    total_in_hi32       DD ? ; unsigned int 
    next_out            DD ? ; char *
    avail_out           DD ? ; unsigned int 
    total_out_lo32      DD ? ; unsigned int 
    total_out_hi32      DD ? ; unsigned int 
    state               DD ? ; void *
    bzalloc             DD ? ; void *(*bzalloc)(void *,int,int);
    bzfree              DD ? ; void (*bzfree)(void *,void *);
    opaque              DD ? ; void *
bz_stream               ENDS

BZFILE                  TYPEDEF DWORD

.CONST
; blockSize100k         : 1-9 (9)
; workFactor            : 0 - 250 (30)
; verbosity             : 0-4

; BZ2_bzCompress action parameter
BZ_RUN                  EQU 0
BZ_FLUSH                EQU 1
BZ_FINISH               EQU 2

BZ_OK                   EQU 0
BZ_RUN_OK               EQU 1
BZ_FLUSH_OK             EQU 2
BZ_FINISH_OK            EQU 3
BZ_STREAM_END           EQU 4
BZ_SEQUENCE_ERROR       EQU (-1)
BZ_PARAM_ERROR          EQU (-2)
BZ_MEM_ERROR            EQU (-3)
BZ_DATA_ERROR           EQU (-4)
BZ_DATA_ERROR_MAGIC     EQU (-5)
BZ_IO_ERROR             EQU (-6)
BZ_UNEXPECTED_EOF       EQU (-7)
BZ_OUTBUFF_FULL         EQU (-8)
BZ_CONFIG_ERROR         EQU (-9)

BZ_MAX_UNUSED           EQU 5000

; -- source modes; F==file, I==stdin, O==stdout --
SM_I2O                  EQU 1
SM_F2O                  EQU 2
SM_F2F                  EQU 3

; -- operation modes --
OM_Z                    EQU 1
OM_UNZ                  EQU 2
OM_TEST                 EQU 3

; -- Header bytes. --
BZ_HDR_B                EQU 042h   ; 'B'
BZ_HDR_Z                EQU 05ah   ; 'Z'
BZ_HDR_h                EQU 068h   ; 'h'
BZ_HDR_0                EQU 030h   ; '0'

; -- Constants for the back end. --
BZ_MAX_ALPHA_SIZE       EQU 258
BZ_MAX_CODE_LEN         EQU 23
BZ_RUNA                 EQU 0
BZ_RUNB                 EQU 1
BZ_N_GROUPS             EQU 6
BZ_G_SIZE               EQU 50
BZ_N_ITERS              EQU 4
BZ_MAX_SELECTORS        EQU (2 + (900000 / BZ_G_SIZE))


;-- States and modes for compression. (bz_stream.state) --
BZ_M_IDLE               EQU 1
BZ_M_RUNNING            EQU 2
BZ_M_FLUSHING           EQU 3
BZ_M_FINISHING          EQU 4
BZ_S_OUTPUT             EQU 1
BZ_S_INPUT              EQU 2
BZ_N_RADIX              EQU 2
BZ_N_QSORT              EQU 12
BZ_N_SHELL              EQU 18
BZ_N_OVERSHOOT          EQU (BZ_N_RADIX + BZ_N_QSORT + BZ_N_SHELL + 2)

; -- states for decompression. --
BZ_X_IDLE               EQU 1
BZ_X_OUTPUT             EQU 2
BZ_X_MAGIC_1            EQU 10
BZ_X_MAGIC_2            EQU 11
BZ_X_MAGIC_3            EQU 12
BZ_X_MAGIC_4            EQU 13
BZ_X_BLKHDR_1           EQU 14
BZ_X_BLKHDR_2           EQU 15
BZ_X_BLKHDR_3           EQU 16
BZ_X_BLKHDR_4           EQU 17
BZ_X_BLKHDR_5           EQU 18
BZ_X_BLKHDR_6           EQU 19
BZ_X_BCRC_1             EQU 20
BZ_X_BCRC_2             EQU 21
BZ_X_BCRC_3             EQU 22
BZ_X_BCRC_4             EQU 23
BZ_X_RANDBIT            EQU 24
BZ_X_ORIGPTR_1          EQU 25
BZ_X_ORIGPTR_2          EQU 26
BZ_X_ORIGPTR_3          EQU 27
BZ_X_MAPPING_1          EQU 28
BZ_X_MAPPING_2          EQU 29
BZ_X_SELECTOR_1         EQU 30
BZ_X_SELECTOR_2         EQU 31
BZ_X_SELECTOR_3         EQU 32
BZ_X_CODING_1           EQU 33
BZ_X_CODING_2           EQU 34
BZ_X_CODING_3           EQU 35
BZ_X_MTF_1              EQU 36
BZ_X_MTF_2              EQU 37
BZ_X_MTF_3              EQU 38
BZ_X_MTF_4              EQU 39
BZ_X_MTF_5              EQU 40
BZ_X_MTF_6              EQU 41
BZ_X_ENDHDR_2           EQU 42
BZ_X_ENDHDR_3           EQU 43
BZ_X_ENDHDR_4           EQU 44
BZ_X_ENDHDR_5           EQU 45
BZ_X_ENDHDR_6           EQU 46
BZ_X_CCRC_1             EQU 47
BZ_X_CCRC_2             EQU 48
BZ_X_CCRC_3             EQU 49
BZ_X_CCRC_4             EQU 50

; -- Constants for the fast MTF decoder. --

MTFA_SIZE               EQU 4096
MTFL_SIZE               EQU 16