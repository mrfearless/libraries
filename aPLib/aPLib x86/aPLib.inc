;
; aPLib compression library  -  the smaller the better :)
;
; COFF format header file
;
; Copyright (c) 1998-2014 Joergen Ibsen
; All Rights Reserved
;
; http://www.ibsensoftware.com/
;

aP_pack                 PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; const void *source, void *destination, unsigned int length, void *workmem, int *aP_PackCallback, void *cbparam
aP_workmem_size         PROTO C :DWORD ; unsigned int inputsize
aP_max_packed_size      PROTO C :DWORD ; unsigned int inputsize
aP_depack_asm           PROTO C :DWORD, :DWORD ; const void *source, void *destination
aP_depack_asm_fast      PROTO C :DWORD, :DWORD ; const void *source, void *destination
aP_depack_asm_safe      PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; const void *source, unsigned int srclen, void *destination, unsigned int dstlen
aP_crc32                PROTO C :DWORD, :DWORD ; const void *source, unsigned int length

aPsafe_pack             PROTO C :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; const void *source, void *destination, unsigned int length, void *workmem, int *aP_PackCallback, void *cbparam
aPsafe_check            PROTO C :DWORD ; const void *source
aPsafe_get_orig_size    PROTO C :DWORD ; const void *source
aPsafe_depack           PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; const void *source, unsigned int srclen, void *destination, unsigned int dstlen

aP_PackCallback         PROTO C :DWORD, :DWORD, :DWORD, :DWORD ; (unsigned int, unsigned int, unsigned int, void *)


.CONST
APLIB_ERROR             EQU -1