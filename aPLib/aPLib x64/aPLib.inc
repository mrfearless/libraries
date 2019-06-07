;
; aPLib compression library  -  the smaller the better :)
;
; COFF 64-bit format header file
;
; Copyright (c) 1998-2014 Joergen Ibsen
; All Rights Reserved
;
; http://www.ibsensoftware.com/
;

aP_pack                 PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; const void *source, void *destination, unsigned int length, void *workmem, int *aP_PackCallback, void *cbparam
aP_workmem_size         PROTO :QWORD ; unsigned int inputsize
aP_max_packed_size      PROTO :QWORD ; unsigned int inputsize
aP_depack_asm           PROTO :QWORD, :QWORD ; const void *source, void *destination
aP_depack_asm_fast      PROTO :QWORD, :QWORD ; const void *source, void *destination
aP_depack_asm_safe      PROTO :QWORD, :QWORD, :QWORD, :QWORD ; const void *source, unsigned int srclen, void *destination, unsigned int dstlen
aP_crc32                PROTO :QWORD, :QWORD ; const void *source, unsigned int length

aPsafe_pack             PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD ; const void *source, void *destination, unsigned int length, void *workmem, int *aP_PackCallback, void *cbparam
aPsafe_check            PROTO :QWORD ; const void *source
aPsafe_get_orig_size    PROTO :QWORD ; const void *source
aPsafe_depack           PROTO :QWORD, :QWORD, :QWORD, :QWORD ; const void *source, unsigned int srclen, void *destination, unsigned int dstlen

aP_PackCallback         PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (unsigned int, unsigned int, unsigned int, void *)


.CONST
APLIB_ERROR             EQU -1