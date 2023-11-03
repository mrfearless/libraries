;
; aPLib x64 compression library  -  the smaller the better :)
;
; Copyright (c) 1998-2014 Joergen Ibsen
; All Rights Reserved
;
; http://www.ibsensoftware.com/

; aPLib_x64.inc for assembler by fearless 2023
; www.github.com/mrfearless

aP_pack                PROTO source:QWORD, destination:QWORD, qwlength:QWORD, workmem:QWORD, callback:QWORD, cbparam:QWORD
aP_workmem_size        PROTO input_size:QWORD
aP_max_packed_size     PROTO input_size:QWORD
aP_depack_asm          PROTO source:QWORD, destination:QWORD
aP_depack_asm_fast     PROTO source:QWORD, destination:QWORD
aP_depack_asm_safe     PROTO source:QWORD, srclen:QWORD, destination:QWORD, dstlen:QWORD
aP_crc32               PROTO source:QWORD, qwlength:QWORD

aPsafe_pack            PROTO source:QWORD, destination:QWORD, qwlength:QWORD, workmem:QWORD, callback:QWORD, cbparam:QWORD
aPsafe_check           PROTO source:QWORD
aPsafe_get_orig_size   PROTO source:QWORD
aPsafe_depack          PROTO source:QWORD, srclen:QWORD, destination:QWORD, dstlen:QWORD

.CONST

APLIB_ERROR             EQU -1