;/* LzmaLib.h -- LZMA library interface
;2023-04-02 : Igor Pavlov : Public domain */

; https://www.7-zip.org/sdk.html

; Lzma_x64.inc converted from Lzma source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

LzFindPrepare                   PROTO 
LzmaCompress                    PROTO dest:QWORD,destLen:QWORD,src:QWORD,srcLen:QWORD,outProps:QWORD,outPropsSize:QWORD,level:QWORD,dictSize:QWORD,lc:QWORD,lp:QWORD,pb:QWORD,fb:QWORD,numThreads:QWORD
LzmaDec_Allocate                PROTO :QWORD,:QWORD,:QWORD,:QWORD
LzmaDec_AllocateProbs           PROTO :QWORD,:QWORD,:QWORD,:QWORD
LzmaDec_DecodeToBuf             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaDec_DecodeToDic             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaDec_Free                    PROTO :QWORD,:QWORD
LzmaDec_FreeProbs               PROTO :QWORD,:QWORD
LzmaDec_Init                    PROTO :QWORD
LzmaDec_InitDicAndState         PROTO :QWORD,:QWORD,:QWORD
LzmaDecode                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaEncProps_GetDictSize        PROTO :QWORD
LzmaEncProps_Init               PROTO :QWORD
LzmaEncProps_Normalize          PROTO :QWORD
LzmaEnc_CodeOneMemBlock         PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaEnc_Create                  PROTO :QWORD
LzmaEnc_Destroy                 PROTO :QWORD,:QWORD,:QWORD
LzmaEnc_Encode                  PROTO p:QWORD,outStream:QWORD,inStream:QWORD,progress:QWORD,alloc:QWORD,allocBig:QWORD
LzmaEnc_Finish                  PROTO :QWORD
LzmaEnc_GetCurBuf               PROTO :QWORD
LzmaEnc_IsWriteEndMark          PROTO :QWORD
LzmaEnc_MemEncode               PROTO p:QWORD,dest:QWORD,destLen:QWORD,src:QWORD,srcLen:QWORD,writeEndMark:QWORD,progress:QWORD,alloc:QWORD,allocBig:QWORD
LzmaEnc_MemPrepare              PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaEnc_PrepareForLzma2         PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
LzmaEnc_RestoreState            PROTO :QWORD
LzmaEnc_SaveState               PROTO :QWORD
LzmaEnc_SetDataSize             PROTO :QWORD,:QWORD,:QWORD
LzmaEnc_SetProps                PROTO :QWORD,:QWORD
LzmaEnc_WriteProperties         PROTO :QWORD,:QWORD,:QWORD
LzmaEncode                      PROTO dest:QWORD,destLen:QWORD,src:QWORD,srcLen:QWORD,props:QWORD,propsEncoded:QWORD,propsSize:QWORD,writeEndMark:QWORD,progress:QWORD,alloc:QWORD,allocBig:QWORD
LzmaProps_Decode                PROTO :QWORD,:QWORD,:QWORD
LzmaUncompress                  PROTO dest:QWORD,destLen:QWORD,src:QWORD,srcLen:QWORD,props:QWORD,propsSize:QWORD


CLzmaEncProps                   STRUCT 8
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
