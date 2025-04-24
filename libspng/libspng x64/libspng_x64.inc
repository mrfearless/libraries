; BSD 2-Clause License
; 
; Copyright (c) 2018-2023, Randy <randy408@protonmail.com>
; All rights reserved.
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions are met:
; 
; * Redistributions of source code must retain the above copyright notice, this
;   list of conditions and the following disclaimer.
; 
; * Redistributions in binary form must reproduce the above copyright notice,
;   this list of conditions and the following disclaimer in the documentation
;   and/or other materials provided with the distribution.
; 
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
; IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
; DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
; FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
; DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
; CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
; OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
; https://github.com/randy408/libspng

; libspng_x64.inc converted from libspng source for assembler by fearless 2024
; www.github.com/mrfearless

spng_ctx_free           PROTO ctx:QWORD
spng_ctx_new2           PROTO alloc:QWORD,flags_:QWORD
spng_ctx_new            PROTO flags_:QWORD
spng_decode_chunks      PROTO ctx:QWORD
spng_decode_image       PROTO ctx:QWORD,outbuffer:QWORD,len:QWORD,fmt:QWORD,flags_:QWORD
spng_decode_row         PROTO ctx:QWORD,outbuffer:QWORD,len:QWORD
spng_decode_scanline    PROTO ctx:QWORD,outbuffer:QWORD,len:QWORD
spng_decoded_image_size PROTO ctx:QWORD,fmt:QWORD,lplen:QWORD
spng_encode_chunks      PROTO ctx:QWORD
spng_encode_image       PROTO ctx:QWORD,img:QWORD,len:QWORD,fmt:QWORD,flags_:QWORD
spng_encode_row         PROTO ctx:QWORD,row:QWORD,len:QWORD
spng_encode_scanline    PROTO ctx:QWORD,scanline:QWORD,len:QWORD
spng_get_bkgd           PROTO ctx:QWORD,bkgd:QWORD
spng_get_chrm           PROTO ctx:QWORD,chrm:QWORD
spng_get_chrm_int       PROTO ctx:QWORD,chrm_int:QWORD
spng_get_chunk_limits   PROTO ctx:QWORD,lpchunk_size:QWORD,lpcache_size:QWORD
spng_get_exif           PROTO ctx:QWORD,exif:QWORD
spng_get_gama           PROTO ctx:QWORD,gamma:QWORD
spng_get_gama_int       PROTO ctx:QWORD,gama_int:QWORD
spng_get_hist           PROTO ctx:QWORD,hist:QWORD
spng_get_iccp           PROTO ctx:QWORD,iccp:QWORD
spng_get_ihdr           PROTO ctx:QWORD,ihdr:QWORD
spng_get_image_limits   PROTO ctx:QWORD,lpwidth:QWORD,lpheight:QWORD
spng_get_offs           PROTO ctx:QWORD,offs:QWORD
spng_get_option         PROTO ctx:QWORD,option:QWORD,lpvalue:QWORD
spng_get_phys           PROTO ctx:QWORD,phys:QWORD
spng_get_plte           PROTO ctx:QWORD,plte:QWORD
spng_get_png_buffer     PROTO ctx:QWORD,len:QWORD,error:QWORD
spng_get_row_info       PROTO ctx:QWORD,lprow_info:QWORD
spng_get_sbit           PROTO ctx:QWORD,sbit:QWORD
spng_get_splt           PROTO ctx:QWORD,splt:QWORD,n_splt:QWORD
spng_get_srgb           PROTO ctx:QWORD,rendering_intent:QWORD
spng_get_text           PROTO ctx:QWORD,text:QWORD,n_text:QWORD
spng_get_time           PROTO ctx:QWORD,time:QWORD
spng_get_trns           PROTO ctx:QWORD,trns:QWORD
spng_get_unknown_chunks PROTO ctx:QWORD,chunks:QWORD,n_chunks:QWORD
spng_set_bkgd           PROTO ctx:QWORD,bkgd:QWORD
spng_set_chrm           PROTO ctx:QWORD,chrm:QWORD
spng_set_chrm_int       PROTO ctx:QWORD,chrm_int:QWORD
spng_set_chunk_limits   PROTO ctx:QWORD,chunk_size:QWORD,cache_size:QWORD
spng_set_crc_action     PROTO ctx:QWORD,critical:QWORD,ancillary:QWORD
spng_set_exif           PROTO ctx:QWORD,exif:QWORD
spng_set_gama           PROTO ctx:QWORD,gamma:REAL8
spng_set_gama_int       PROTO ctx:QWORD,gamma:QWORD
spng_set_hist           PROTO ctx:QWORD,hist:QWORD
spng_set_iccp           PROTO ctx:QWORD,iccp:QWORD
spng_set_ihdr           PROTO ctx:QWORD,ihdr:QWORD
spng_set_image_limits   PROTO ctx:QWORD,width:QWORD,height:QWORD
spng_set_offs           PROTO ctx:QWORD,offs:QWORD
spng_set_option         PROTO ctx:QWORD,:optionDWORD,value:QWORD
spng_set_phys           PROTO ctx:QWORD,phys:QWORD
spng_set_plte           PROTO ctx:QWORD,plte:QWORD
spng_set_png_buffer     PROTO ctx:QWORD,buf:QWORD,size:QWORD
spng_set_png_file       PROTO ctx:QWORD,file:QWORD
spng_set_png_stream     PROTO ctx:QWORD,rw_func:QWORD,user:QWORD
spng_set_sbit           PROTO ctx:QWORD,sbit:QWORD
spng_set_splt           PROTO ctx:QWORD,:QWORD,:QWORD
spng_set_srgb           PROTO ctx:QWORD,rendering_intent:QWORD
spng_set_text           PROTO ctx:QWORD,text:QWORD,n_text:QWORD
spng_set_time           PROTO ctx:QWORD,time:QWORD
spng_set_trns           PROTO ctx:QWORD,trns:QWORD
spng_set_unknown_chunks PROTO ctx:QWORD,chunks:QWORD,n_chunks:QWORD
spng_strerror           PROTO err:QWORD
spng_version_string     PROTO 

IFNDEF uint32_t
uint32_t                TYPEDEF DWORD
ENDIF
IFNDEF uint16_t
uint16_t                TYPEDEF WORD
ENDIF
IFNDEF uint8_t
uint8_t                 TYPEDEF BYTE
ENDIF
IFNDEF size_t
size_t                  TYPEDEF QWORD
ENDIF
IFNDEF POINTER
POINTER                 TYPEDEF QWORD
ENDIF

spng_ihdr               STRUCT
    width_              uint32_t ?
    height              uint32_t ?
    bit_depth           uint8_t ?
    color_type          uint8_t ?
    compression_method  uint8_t ?
    filter_method       uint8_t ?
    interlace_method    uint8_t ?
spng_ihdr               ENDS

spng_plte_entry         STRUCT
    red                 uint8_t ?
    green               uint8_t ?
    blue                uint8_t ?
    alpha               uint8_t ?
spng_plte_entry         ENDS

spng_plte               STRUCT
    n_entries           uint32_t ?
    entries             spng_plte_entry <>
spng_plte               ENDS

spng_trns               STRUCT
    gray                uint16_t ?
    red                 uint16_t ?
    green               uint16_t ?
    blue                uint16_t ?
    n_type3_entries     uint32_t ?
    type3_alpha         uint8_t 256 dup (?)
spng_trns               ENDS

spng_chrm_int           STRUCT
    white_point_x       uint32_t ?
    white_point_y       uint32_t ?
    red_x               uint32_t ?
    red_y               uint32_t ?
    green_x             uint32_t ?
    green_y             uint32_t ?
    blue_x              uint32_t ?
    blue_y              uint32_t ?
spng_chrm_int           ENDS

spng_chrm               STRUCT 8
    white_point_x       REAL8 ?
    white_point_y       REAL8 ?
    red_x               REAL8 ?
    red_y               REAL8 ?
    green_x             REAL8 ?
    green_y             REAL8 ?
    blue_x              REAL8 ?
    blue_y              REAL8 ?
spng_chrm               ENDS

spng_iccp               STRUCT 8
    profile_name        SBYTE 80 dup (?)
    profile_len         size_t ?
    profile             POINTER ?
spng_iccp               ENDS

spng_sbit               STRUCT
    grayscale_bits      uint8_t ?
    red_bits            uint8_t ?
    green_bits          uint8_t ?
    blue_bits           uint8_t ?
    alpha_bits          uint8_t ?
spng_sbit               ENDS

spng_text               STRUCT 8
    keyword             SBYTE 80 dup (?)
    type_               DWORD ?
    length_             size_t ?
    text                POINTER ?
    compression_flag    uint8_t ?
    compression_method  uint8_t ?
    language_tag        POINTER ?
    translated_keyword  POINTER ?
spng_text               ENDS

spng_bkgd               STRUCT
    gray                uint16_t ?
    red                 uint16_t ?
    green               uint16_t ?
    blue                uint16_t ?
    plte_index          uint16_t ?
spng_bkgd               ENDS

spng_hist               STRUCT
    frequency           uint16_t 256 dup (?)
spng_hist               ENDS

spng_phys               STRUCT
    ppu_x               uint32_t ?
    ppu_y               uint32_t ?
    unit_specifier      uint8_t ?
spng_phys               ENDS

spng_splt_entry         STRUCT
    red                 uint16_t ?
    green               uint16_t ?
    blue                uint16_t ?
    alpha               uint16_t ?
    frequency           uint16_t ?
spng_splt_entry         ENDS

spng_splt               STRUCT 8
    name_               SBYTE 80 dup (?)
    sample_depth        uint8_t ?
    n_entries           uint32_t ?
    entries             POINTER ?
spng_splt               ENDS

spng_time               STRUCT
    year                uint16_t ?
    month               uint8_t ?
    day                 uint8_t ?
    hour                uint8_t ?
    minute              uint8_t ?
    second              uint8_t ?
spng_time               ENDS

spng_offs               STRUCT
    x                   int32_t ?
    y                   int32_t ?
    unit_specifier      uint8_t ?
spng_offs               ENDS

spng_exif               STRUCT 8
    length_             size_t ?
    data                POINTER ?
spng_exif               ENDS

spng_chunk              STRUCT 8
    offset_             size_t ?
    length_             uint32_t ?
    type_               uint8_t 4 dup (?)
    crc_                uint32_t ?
spng_chunk              ENDS

spng_location           TYPEDEF SDWORD

spng_unknown_chunk      STRUCT 8
    type_               uint8_t 4 dup (?)
    length_             size_t ?
    data                POINTER ?
    location            spng_location ?
spng_unknown_chunk      ENDS

spng_alloc              STRUCT 8
    malloc_fn           POINTER ?
    realloc_fn          POINTER ?
    calloc_fn           POINTER ?
    free_fn             POINTER ?
spng_alloc              ENDS

spng_row_info           STRUCT
    scanline_idx        uint32_t ?
    row_num             uint32_t ?
    pass                DWORD ?
    filter              uint8_t ?
spng_row_info           ENDS

.CONST

SPNG_VERSION_MAJOR      EQU 0
SPNG_VERSION_MINOR      EQU 7
SPNG_VERSION_PATCH      EQU 4

spng_errno typedef SDWORD
SPNG_IO_ERROR           EQU - 2 
SPNG_IO_EOF             EQU - 1 
SPNG_OK                 EQU 0 
SPNG_EINVAL             EQU 1
SPNG_EMEM               EQU 2
SPNG_EOVERFLOW          EQU 3
SPNG_ESIGNATURE         EQU 4
SPNG_EWIDTH             EQU 5
SPNG_EHEIGHT            EQU 6
SPNG_EUSER_WIDTH        EQU 7
SPNG_EUSER_HEIGHT       EQU 8
SPNG_EBIT_DEPTH         EQU 9
SPNG_ECOLOR_TYPE        EQU 10
SPNG_ECOMPRESSION_METHOD EQU 11
SPNG_EFILTER_METHOD     EQU 12
SPNG_EINTERLACE_METHOD EQU 13
SPNG_EIHDR_SIZE         EQU 14
SPNG_ENOIHDR            EQU 15
SPNG_ECHUNK_POS         EQU 16
SPNG_ECHUNK_SIZE        EQU 17
SPNG_ECHUNK_CRC         EQU 18
SPNG_ECHUNK_TYPE        EQU 19
SPNG_ECHUNK_UNKNOWN_CRITICAL EQU 20
SPNG_EDUP_PLTE          EQU 21
SPNG_EDUP_CHRM          EQU 22
SPNG_EDUP_GAMA          EQU 23
SPNG_EDUP_ICCP          EQU 24
SPNG_EDUP_SBIT          EQU 25
SPNG_EDUP_SRGB          EQU 26
SPNG_EDUP_BKGD          EQU 27
SPNG_EDUP_HIST          EQU 28
SPNG_EDUP_TRNS          EQU 29
SPNG_EDUP_PHYS          EQU 30
SPNG_EDUP_TIME          EQU 31
SPNG_EDUP_OFFS          EQU 32
SPNG_EDUP_EXIF          EQU 33
SPNG_ECHRM              EQU 34
SPNG_EPLTE_IDX          EQU 35
SPNG_ETRNS_COLOR_TYPE   EQU 36
SPNG_ETRNS_NO_PLTE      EQU 37
SPNG_EGAMA              EQU 38
SPNG_EICCP_NAME         EQU 39
SPNG_EICCP_COMPRESSION_METHOD EQU 40
SPNG_ESBIT              EQU 41
SPNG_ESRGB              EQU 42
SPNG_ETEXT              EQU 43
SPNG_ETEXT_KEYWORD      EQU 44
SPNG_EZTXT              EQU 45
SPNG_EZTXT_COMPRESSION_METHOD EQU 46
SPNG_EITXT              EQU 47
SPNG_EITXT_COMPRESSION_FLAG EQU 48
SPNG_EITXT_COMPRESSION_METHOD EQU 49
SPNG_EITXT_LANG_TAG     EQU 50
SPNG_EITXT_TRANSLATED_KEY EQU 51
SPNG_EBKGD_NO_PLTE      EQU 52
SPNG_EBKGD_PLTE_IDX     EQU 53
SPNG_EHIST_NO_PLTE      EQU 54
SPNG_EPHYS              EQU 55
SPNG_ESPLT_NAME         EQU 56
SPNG_ESPLT_DUP_NAME     EQU 57
SPNG_ESPLT_DEPTH        EQU 58
SPNG_ETIME              EQU 59
SPNG_EOFFS              EQU 60
SPNG_EEXIF              EQU 61
SPNG_EIDAT_TOO_SHORT    EQU 62
SPNG_EIDAT_STREAM       EQU 63
SPNG_EZLIB              EQU 64
SPNG_EFILTER            EQU 65
SPNG_EBUFSIZ            EQU 66
SPNG_EIO                EQU 67
SPNG_EOF                EQU 68
SPNG_EBUF_SET           EQU 69
SPNG_EBADSTATE          EQU 70
SPNG_EFMT               EQU 71
SPNG_EFLAGS             EQU 72
SPNG_ECHUNKAVAIL        EQU 73
SPNG_ENCODE_ONLY        EQU 74
SPNG_EOI                EQU 75
SPNG_ENOPLTE            EQU 76
SPNG_ECHUNK_LIMITS      EQU 77
SPNG_EZLIB_INIT         EQU 78
SPNG_ECHUNK_STDLEN      EQU 79
SPNG_EINTERNAL          EQU 80
SPNG_ECTXTYPE           EQU 81
SPNG_ENOSRC             EQU 82
SPNG_ENODST             EQU 83
SPNG_EOPSTATE           EQU 84
SPNG_ENOTFINAL          EQU 85

spng_text_type typedef SDWORD
SPNG_TEXT               EQU 1 
SPNG_ZTXT               EQU 2 
SPNG_ITXT               EQU 3 

spng_color_type typedef SDWORD
SPNG_COLOR_TYPE_GRAYSCALE EQU 0 
SPNG_COLOR_TYPE_TRUECOLOR EQU 2 
SPNG_COLOR_TYPE_INDEXED EQU 3 
SPNG_COLOR_TYPE_GRAYSCALE_ALPHA EQU 4 
SPNG_COLOR_TYPE_TRUECOLOR_ALPHA EQU 6 

spng_filter typedef SDWORD
SPNG_FILTER_NONE        EQU 0 
SPNG_FILTER_SUB         EQU 1 
SPNG_FILTER_UP          EQU 2 
SPNG_FILTER_AVERAGE     EQU 3 
SPNG_FILTER_PAETH       EQU 4 

spng_filter_choice typedef SDWORD
SPNG_DISABLE_FILTERING  EQU 0 
SPNG_FILTER_CHOICE_NONE EQU 8 
SPNG_FILTER_CHOICE_SUB  EQU 16 
SPNG_FILTER_CHOICE_UP   EQU 32 
SPNG_FILTER_CHOICE_AVG  EQU 64 
SPNG_FILTER_CHOICE_PAETH EQU 128 
SPNG_FILTER_CHOICE_ALL  EQU ( 8 or 16 or 32 or 64 or 128 ) 

spng_interlace_method typedef SDWORD
SPNG_INTERLACE_NONE     EQU 0 
SPNG_INTERLACE_ADAM7    EQU 1 

spng_format typedef SDWORD
SPNG_FMT_RGBA8          EQU 1 
SPNG_FMT_RGBA16         EQU 2 
SPNG_FMT_RGB8           EQU 4 
SPNG_FMT_GA8            EQU 16 
SPNG_FMT_GA16           EQU 32 
SPNG_FMT_G8             EQU 64 
SPNG_FMT_PNG            EQU 256 
SPNG_FMT_RAW            EQU 512 

spng_ctx_flags typedef SDWORD
SPNG_CTX_IGNORE_ADLER32 EQU 1 
SPNG_CTX_ENCODER        EQU 2 

spng_decode_flags typedef SDWORD
SPNG_DECODE_USE_TRNS    EQU 1 
SPNG_DECODE_USE_GAMA    EQU 2 
SPNG_DECODE_USE_SBIT    EQU 8 
SPNG_DECODE_TRNS        EQU 1 
SPNG_DECODE_GAMMA       EQU 2 
SPNG_DECODE_PROGRESSIVE EQU 256 

spng_crc_action typedef SDWORD
SPNG_CRC_ERROR          EQU 0 
SPNG_CRC_DISCARD        EQU 1 
SPNG_CRC_USE            EQU 2 

spng_encode_flags typedef SDWORD
SPNG_ENCODE_PROGRESSIVE EQU 1 
SPNG_ENCODE_FINALIZE    EQU 2 


SPNG_AFTER_IHDR         EQU 1 
SPNG_AFTER_PLTE         EQU 2 
SPNG_AFTER_IDAT         EQU 8 

spng_option typedef SDWORD
SPNG_KEEP_UNKNOWN_CHUNKS EQU 1 
SPNG_IMG_COMPRESSION_LEVEL EQU 2
SPNG_IMG_WINDOW_BITS    EQU 3
SPNG_IMG_MEM_LEVEL      EQU 4
SPNG_IMG_COMPRESSION_STRATEGY EQU 5
SPNG_TEXT_COMPRESSION_LEVEL EQU 6
SPNG_TEXT_WINDOW_BITS   EQU 7
SPNG_TEXT_MEM_LEVEL     EQU 8
SPNG_TEXT_COMPRESSION_STRATEGY EQU 9
SPNG_FILTER_CHOICE      EQU 10
SPNG_CHUNK_COUNT_LIMIT  EQU 11
SPNG_ENCODE_TO_BUFFER   EQU 12