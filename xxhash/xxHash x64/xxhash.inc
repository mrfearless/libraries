; xxHash x64 - Extremely Fast Hash algorithm
; Copyright (C) 2012-2016, Yann Collet.
; https://github.com/Cyan4973/xxHash

XXH_versionNumber           PROTO 

;32-Bit hash
XXH32                       PROTO lpInput:QWORD,qwLength:QWORD,seed:DWORD
XXH32_canonicalFromHash     PROTO dst:QWORD,hash:QWORD
XXH32_copyState             PROTO dst_state:QWORD,src_state:QWORD
XXH32_createState           PROTO 
XXH32_digest                PROTO statePtr:QWORD
XXH32_freeState             PROTO statePtr:QWORD
XXH32_hashFromCanonical     PROTO src:QWORD
XXH32_reset                 PROTO statePtr:QWORD,seed:DWORD
XXH32_update                PROTO statePtr:QWORD,lpInput:QWORD,qwLength:QWORD

;64-bit hash
XXH64                       PROTO lpInput:QWORD,qwLength:QWORD,seed:QWORD
XXH64_canonicalFromHash     PROTO :QWORD,:QWORD,:QWORD
XXH64_copyState             PROTO dst_state:QWORD,src_state:QWORD
XXH64_createState           PROTO 
XXH64_digest                PROTO statePtr:QWORD
XXH64_freeState             PROTO statePtr:QWORD
XXH64_hashFromCanonical     PROTO :QWORD
XXH64_reset                 PROTO statePtr:QWORD,seed:QWORD
XXH64_update                PROTO statePtr:QWORD,lpInput:QWORD,qwLength:QWORD

;XXH3 - New experimental hash 2 variants: _64bits and _128bits
XXH3_copyState              PROTO dst_state:QWORD,src_state:QWORD
XXH3_createState            PROTO 
XXH3_freeState              PROTO statePtr:QWORD
;XXH3 64bits
XXH3_64bits                 PROTO data:QWORD,len:QWORD
XXH3_64bits_withSecret      PROTO data:QWORD,len:QWORD,secret:QWORD,secretSize:QWORD
XXH3_64bits_withSeed        PROTO data:QWORD,len:QWORD,seed:QWORD
XXH3_64bits_digest          PROTO statePtr:QWORD
XXH3_64bits_reset           PROTO statePtr:QWORD
XXH3_64bits_reset_withSecret PROTO statePtr:QWORD,secret:QWORD,secretSize:QWORD
XXH3_64bits_reset_withSeed  PROTO statePtr:QWORD,seed:QWORD
XXH3_64bits_update          PROTO statePtr:QWORD,lpInput:QWORD,qwLength:QWORD
;XXH3 128bits
XXH128                      PROTO data:QWORD,len:QWORD,seed:QWORD
XXH3_128bits                PROTO data:QWORD,len:QWORD
XXH3_128bits_withSecret     PROTO data:QWORD,len:QWORD,secret:QWORD,secretSize:QWORD
XXH3_128bits_withSeed       PROTO data:QWORD,len:QWORD,seed:QWORD
XXH3_128bits_digest         PROTO statePtr:QWORD
XXH3_128bits_reset          PROTO statePtr:QWORD
XXH3_128bits_reset_withSecret PROTO statePtr:QWORD,secret:QWORD,secretSize:QWORD
XXH3_128bits_reset_withSeed PROTO statePtr:QWORD,seed:QWORD
XXH3_128bits_update         PROTO statePtr:QWORD,lpInput:QWORD,qwLength:QWORD
XXH128_canonicalFromHash    PROTO dst:QWORD,hash:OWORD
XXH128_cmp                  PROTO h128_1:QWORD,h128_2:QWORD
XXH128_hashFromCanonical    PROTO src:QWORD
XXH128_isEqual              PROTO h1:OWORD,h2:OWORD


XXH32_hash_t                TYPEDEF DWORD
XXH64_hash_t                TYPEDEF QWORD
;XXH128_hash_t               TYPEDEF OWORD
XXH128_hash_t               STRUCT
    low64                   XXH64_hash_t ?;
    high64                  XXH64_hash_t ?;
XXH128_hash_t               ENDS

XXH32_state_s               STRUCT 
    total_len_32            XXH32_hash_t ?
    large_len               XXH32_hash_t ?
    v1                      XXH32_hash_t ?
    v2                      XXH32_hash_t ?
    v3                      XXH32_hash_t ?
    v4                      XXH32_hash_t ?
    mem32                   XXH32_hash_t 4 DUP (?);
    memsize                 XXH32_hash_t ?
    reserved                XXH32_hash_t ? ; never read nor write
XXH32_state_s               ENDS
XXH32_state_t               TYPEDEF XXH32_state_s

XXH64_state_s               STRUCT 
    total_len_32            XXH64_hash_t ?
    large_len               XXH64_hash_t ?
    v1                      XXH64_hash_t ?
    v2                      XXH64_hash_t ?
    v3                      XXH64_hash_t ?
    v4                      XXH64_hash_t ?
    mem64                   XXH64_hash_t 4 DUP (?);
    memsize                 XXH64_hash_t ?
    reserved                XXH64_hash_t 2 DUP (?); never read nor write
XXH64_state_s               ENDS
XXH64_state_t               TYPEDEF XXH64_state_s

XXH3_SECRET_SIZE_MIN        EQU 136
XXH3_SECRET_DEFAULT_SIZE    EQU 192 ; minimum XXH3_SECRET_SIZE_MIN
XXH3_INTERNALBUFFER_SIZE    EQU 256

XXH3_state_s                STRUCT
ALIGN 64
    acc                     XXH64_hash_t 8 dup (?) ; XXH_ALIGN(64)  
    customSecret            DB XXH3_SECRET_DEFAULT_SIZE DUP (?); XXH_ALIGN(64)
    buffer                  DB XXH3_INTERNALBUFFER_SIZE DUP (?); XXH_ALIGN(64)
ALIGN 4
    secret                  QWORD ? ; const void*
    bufferedSize            XXH32_hash_t ?
    nbStripesPerBlock       XXH32_hash_t ?
    nbStripesSoFar          XXH32_hash_t ?
    reserved32              XXH32_hash_t ?
    reserved32_2            XXH32_hash_t ?
    secretLimit             XXH32_hash_t ?
    totalLen                XXH64_hash_t ?
    seed                    XXH64_hash_t ?
    reserved64              XXH64_hash_t ?
XXH3_state_s                ENDS
XXH3_state_t                TYPEDEF XXH3_state_s
XXH128_state_s              TYPEDEF XXH3_state_s
XXH128_state_t              TYPEDEF XXH128_state_s

XXH32_canonical_t           STRUCT
    digest                  DB 4 DUP (?)
XXH32_canonical_t           ENDS

XXH64_canonical_t           STRUCT
    digest                  DB 8 DUP (?)
XXH64_canonical_t           ENDS

XXH128_canonical_t          STRUCT
    digest                  DB 16 DUP (?)
XXH128_canonical_t          ENDS

.CONST
XXH_VERSION_MAJOR           EQU 0
XXH_VERSION_MINOR           EQU 7
XXH_VERSION_RELEASE         EQU 1
XXH_VERSION_NUMBER          EQU (XXH_VERSION_MAJOR *100*100 + XXH_VERSION_MINOR *100 + XXH_VERSION_RELEASE)