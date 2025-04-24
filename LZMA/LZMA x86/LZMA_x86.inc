;/* LzmaLib.h -- LZMA library interface
;2023-04-02 : Igor Pavlov : Public domain */

; https://www.7-zip.org/sdk.html

; Lzma_x86.inc converted from Lzma source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

LzFindPrepare                   PROTO STDCALL 
LzmaCompress                    PROTO STDCALL dest:DWORD,destLen:DWORD,src:DWORD,srcLen:DWORD,outProps:DWORD,outPropsSize:DWORD,level:DWORD,dictSize:DWORD,lc:DWORD,lp:DWORD,pb:DWORD,fb:DWORD,numThreads:DWORD
LzmaDec_Allocate                PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LzmaDec_AllocateProbs           PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
LzmaDec_DecodeToBuf             PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaDec_DecodeToDic             PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaDec_Free                    PROTO STDCALL :DWORD,:DWORD
LzmaDec_FreeProbs               PROTO STDCALL :DWORD,:DWORD
LzmaDec_Init                    PROTO STDCALL :DWORD
LzmaDec_InitDicAndState         PROTO STDCALL :DWORD,:DWORD,:DWORD
LzmaDecode                      PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaEncProps_GetDictSize        PROTO STDCALL :DWORD
LzmaEncProps_Init               PROTO STDCALL :DWORD
LzmaEncProps_Normalize          PROTO STDCALL :DWORD
LzmaEnc_CodeOneMemBlock         PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaEnc_Create                  PROTO STDCALL :DWORD
LzmaEnc_Destroy                 PROTO STDCALL :DWORD,:DWORD,:DWORD
LzmaEnc_Encode                  PROTO STDCALL p:DWORD,outStream:DWORD,inStream:DWORD,progress:DWORD,alloc:DWORD,allocBig:DWORD
LzmaEnc_Finish                  PROTO STDCALL :DWORD
LzmaEnc_GetCurBuf               PROTO STDCALL :DWORD
LzmaEnc_IsWriteEndMark          PROTO STDCALL :DWORD
LzmaEnc_MemEncode               PROTO STDCALL p:DWORD,dest:DWORD,destLen:DWORD,src:DWORD,srcLen:DWORD,writeEndMark:DWORD,progress:DWORD,alloc:DWORD,allocBig:DWORD
LzmaEnc_MemPrepare              PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaEnc_PrepareForLzma2         PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LzmaEnc_RestoreState            PROTO STDCALL :DWORD
LzmaEnc_SaveState               PROTO STDCALL :DWORD
LzmaEnc_SetDataSize             PROTO STDCALL :DWORD,:DWORD,:DWORD
LzmaEnc_SetProps                PROTO STDCALL :DWORD,:DWORD
LzmaEnc_WriteProperties         PROTO STDCALL :DWORD,:DWORD,:DWORD
LzmaEncode                      PROTO STDCALL dest:DWORD,destLen:DWORD,src:DWORD,srcLen:DWORD,props:DWORD,propsEncoded:DWORD,propsSize:DWORD,writeEndMark:DWORD,progress:DWORD,alloc:DWORD,allocBig:DWORD
LzmaProps_Decode                PROTO STDCALL :DWORD,:DWORD,:DWORD
LzmaUncompress                  PROTO STDCALL dest:DWORD,destLen:DWORD,src:DWORD,srcLen:DWORD,props:DWORD,propsSize:DWORD


CLzmaEncProps                   STRUCT
    level                       DWORD ? ; int 0 <= level <= 9 */
    dictSize                    DWORD ? ; UInt32 (1 << 12) <= dictSize <= (1 << 27) for 32-bit version
                                        ; (1 << 12) <= dictSize <= (3 << 29) for 64-bit version
                                        ; default = (1 << 24) */
    lc                          DWORD ? ; 0 <= lc <= 8, default = 3 */
    lp                          DWORD ? ; 0 <= lp <= 4, default = 0 */
    pb                          DWORD ? ; 0 <= pb <= 4, default = 2 */
    algo                        DWORD ? ; 0 - fast, 1 - normal, default = 1 */
    fb                          DWORD ? ; 5 <= fb <= 273, default = 32 */
    btMode                      DWORD ? ; 0 - hashChain Mode, 1 - binTree mode - normal, default = 1 */
    numHashBytes                DWORD ? ; 2, 3 or 4, default = 4 */
    numHashOutBits              DWORD ? ; unsigned default = ? */
    mc                          DWORD ? ; UInt32 1 <= mc <= (1 << 30), default = 32 */
    writeEndMark                DWORD ? ; unsigned 0 - do not write EOPM, 1 - write EOPM, default = 0 */
    numThreads                  DWORD ? ; 1 or 2, default = 2 */
    _pad                        DWORD ? ; ;
    reduceSize                  QWORD ? ; UInt64 ; /* estimated size of data that will be compressed. default = (UInt64)(Int64)-1.
                                        ; Encoder uses this value to reduce dictionary size */
    affinity                    QWORD ? ; UInt64
CLzmaEncProps                   ENDS


.CONST
LZMA_PROPS_SIZE                 EQU 5

SZ_OK                           EQU 0
SZ_ERROR_DATA                   EQU 1
SZ_ERROR_MEM                    EQU 2
SZ_ERROR_CRC                    EQU 3
SZ_ERROR_UNSUPPORTED            EQU 4
SZ_ERROR_PARAM                  EQU 5
SZ_ERROR_INPUT_EOF              EQU 6
SZ_ERROR_OUTPUT_EOF             EQU 7
SZ_ERROR_READ                   EQU 8
SZ_ERROR_WRITE                  EQU 9
SZ_ERROR_PROGRESS               EQU 10
SZ_ERROR_FAIL                   EQU 11
SZ_ERROR_THREAD                 EQU 12
SZ_ERROR_ARCHIVE                EQU 16
SZ_ERROR_NO_ARCHIVE             EQU 17
