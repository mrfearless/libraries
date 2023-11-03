;
; aPLib x86 compression library  -  the smaller the better :)
;
; Copyright (c) 1998-2014 Joergen Ibsen
; All Rights Reserved
;
; http://www.ibsensoftware.com/

; aPLib_x86.inc for assembler by fearless 2023
; www.github.com/mrfearless

aP_pack                PROTO C, source:DWORD, destination:DWORD, dwlength:DWORD, workmem:DWORD, callback:DWORD, cbparam:DWORD
aP_workmem_size        PROTO C, input_size:DWORD
aP_max_packed_size     PROTO C, input_size:DWORD
aP_depack_asm          PROTO C, source:DWORD, destination:DWORD
aP_depack_asm_fast     PROTO C, source:DWORD, destination:DWORD
aP_depack_asm_safe     PROTO C, source:DWORD, srclen:DWORD, destination:DWORD, dstlen:DWORD
aP_crc32               PROTO C, source:DWORD, dwlength:DWORD

aPsafe_pack            PROTO C, source:DWORD, destination:DWORD, dwlength:DWORD, workmem:DWORD, callback:DWORD, cbparam:DWORD
aPsafe_check           PROTO C, source:DWORD
aPsafe_get_orig_size   PROTO C, source:DWORD
aPsafe_depack          PROTO C, source:DWORD, srclen:DWORD, destination:DWORD, dstlen:DWORD

.CONST

APLIB_ERROR             EQU -1