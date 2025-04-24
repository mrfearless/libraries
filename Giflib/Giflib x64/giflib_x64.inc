; Eric S. Raymond
; https://sourceforge.net/projects/giflib/
; https://giflib.sourceforge.net/
; Docs: https://giflib.sourceforge.net/gif_lib.html

; Giflib_x64.inc converted from Giflib source for assembler by fearless 2024
; www.github.com/mrfearless

DGifCloseFile               PROTO GifFile:QWORD,ErrorCode:QWORD
DGifExtensionToGCB          PROTO GifExtensionLength:QWORD,GifExtension:QWORD,GCB:QWORD
DGifGetCode                 PROTO GifFile:QWORD,GifCodeSize:QWORD,GifCodeBlock:QWORD
DGifGetCodeNext             PROTO GifFile:QWORD,GifCodeBlock:QWORD
DGifGetExtension            PROTO GifFile:QWORD,GifExtCode:QWORD,GifExtension:QWORD
DGifGetExtensionNext        PROTO GifFile:QWORD,GifExtension:QWORD
DGifGetGifVersion           PROTO GifFile:QWORD
DGifGetImageDesc            PROTO GifFile:QWORD
DGifGetImageHeader          PROTO GifFile:QWORD
DGifGetLZCodes              PROTO GifFile:QWORD,GifCode:QWORD
DGifGetLine                 PROTO GifFile:QWORD,GifPixelType:QWORD,GifLineLen:QWORD
DGifGetPixel                PROTO GifFile:QWORD,GifPixel:QWORD
DGifGetRecordType           PROTO GifFile:QWORD,GifType:QWORD
DGifGetScreenDesc           PROTO GifFile:QWORD
DGifOpen                    PROTO userPtr:QWORD,readFunc:QWORD,Error:QWORD
DGifOpenFileHandle          PROTO GifFileHandle:QWORD,Error:QWORD
DGifOpenFileName            PROTO GifFileName:QWORD,Error:QWORD
DGifSavedExtensionToGCB     PROTO GifFile:QWORD,ImageIndex:QWORD,GCB:QWORD
DGifSlurp                   PROTO GifFile:QWORD
EGifCloseFile               PROTO GifFile:QWORD,ErrorCode:QWORD
EGifGCBToExtension          PROTO GCB:QWORD,GifExtension:QWORD
EGifGCBToSavedExtension     PROTO GCB:QWORD,GifFile:QWORD,ImageIndex:QWORD
EGifGetGifVersion           PROTO GifFile:QWORD
EGifOpen                    PROTO userPtr:QWORD,writeFunc:QWORD,Error:QWORD
EGifOpenFileHandle          PROTO GifFileHandle:QWORD,Error:QWORD
EGifOpenFileName            PROTO GifFileName:QWORD,GifTestExistence:QWORD,Error:QWORD
EGifPutCode                 PROTO GifFile:QWORD,GifCodeSize:QWORD,GifCodeBlock:QWORD
EGifPutCodeNext             PROTO GifFile:QWORD,GifCodeBlock:QWORD
EGifPutComment              PROTO GifFile:QWORD,GifComment:QWORD
EGifPutExtension            PROTO GifFile:QWORD,GifExtCode:QWORD,GifExtLen:QWORD,GifExtension:QWORD
EGifPutExtensionBlock       PROTO GifFile:QWORD,GifExtLen:QWORD,GifExtension:QWORD
EGifPutExtensionLeader      PROTO GifFile:QWORD,GifExtCode:QWORD
EGifPutExtensionTrailer     PROTO GifFile:QWORD
EGifPutImageDesc            PROTO GifFile:QWORD,GifLeft:QWORD,GifTop:QWORD,GifWidth:QWORD,GifHeight:QWORD,GifInterlace:QWORD,GifColorMap:QWORD
EGifPutLine                 PROTO GifFile:QWORD,GifLine:QWORD,GifLineLen:QWORD
EGifPutPixel                PROTO GifFile:QWORD,GifPixel:QWORD
EGifPutScreenDesc           PROTO GifFile:QWORD,GifWidth:QWORD,GifHeight:QWORD,GifColorRes:QWORD,GifBackGround:QWORD,GifColorMap:QWORD
EGifSetGifVersion           PROTO GifFile:QWORD,gif89:QWORD
EGifSpew                    PROTO GifFile:QWORD
FreeLastSavedImage          PROTO :QWORD
GifAddExtensionBlock        PROTO ExtensionBlock_Count:QWORD,ExtensionBlocks:QWORD,Function:QWORD,Len:QWORD,ExtData:QWORD
GifApplyTranslation         PROTO Image:QWORD,Translation:QWORD
GifAsciiTable8x8            PROTO C :VARARG
GifBitSize                  PROTO n:QWORD
GifDrawBox                  PROTO Image:QWORD,x:QWORD,y:QWORD,w:QWORD,d:QWORD,color:QWORD
GifDrawBoxedText8x8         PROTO Image:QWORD,x:QWORD,y:QWORD,legend:QWORD,border:QWORD,bg:QWORD,fg:QWORD
GifDrawRectangle            PROTO Image:QWORD,x:QWORD,y:QWORD,w:QWORD,d:QWORD,color:QWORD
GifDrawText8x8              PROTO Image:QWORD,x:QWORD,y:QWORD,legend:QWORD,color:QWORD
GifErrorString              PROTO ErrorCode:QWORD
GifFreeExtensions           PROTO ExtensionBlock_Count:QWORD,ExtensionBlocks:QWORD
GifFreeMapObject            PROTO Object:QWORD
GifFreeSavedImages          PROTO GifFile:QWORD
GifMakeMapObject            PROTO ColorCount:QWORD,ColorMap:QWORD
GifMakeSavedImage           PROTO GifFile:QWORD,CopyFrom:QWORD
GifQuantizeBuffer           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
GifUnionColorMap            PROTO ColorIn1:QWORD,ColorIn2:QWORD,ColorTransIn2:QWORD

IFNDEF POINTER
POINTER                     TYPEDEF QWORD
ENDIF

IFNDEF bool
bool                        TYPEDEF DWORD
ENDIF

GifPixelType                TYPEDEF BYTE
GifRowType                  TYPEDEF PTR BYTE
GifByteType                 TYPEDEF BYTE
GifPrefixType               TYPEDEF DWORD
GifWord                     TYPEDEF DWORD

GifColorType                STRUCT
    Red                     GifByteType ?
    Green                   GifByteType ?
    Blue                    GifByteType ?
GifColorType                ENDS

ColorMapObject              STRUCT 8
    ColorCount              DWORD ?
    BitsPerPixel            DWORD ?
    SortFlag                bool ?
    Colors                  POINTER ?
ColorMapObject              ENDS

GifImageDesc                STRUCT 8
    Left                    GifWord ?
    Top                     GifWord ?
    Width_                  GifWord ?
    Height                  GifWord ?
    Interlace               bool ?
    ColorMap                POINTER ?
GifImageDesc                ENDS

ExtensionBlock              STRUCT 8
    ByteCount               DWORD ?
    Bytes                   POINTER ?
    Function                DWORD ?
ExtensionBlock              ENDS

SavedImage                  STRUCT 8
    ImageDesc               GifImageDesc <>
    RasterBits              POINTER ?
    ExtensionBlockCount     DWORD ?
    ExtensionBlocks         POINTER ?
SavedImage                  ENDS

GifFileType                 STRUCT 8
    SWidth                  GifWord ?
    SHeight                 GifWord ?
    SColorResolution        GifWord ?
    SBackGroundColor        GifWord ?
    AspectByte              GifByteType ?
    SColorMap               POINTER ?
    ImageCount              DWORD ?
    Image                   GifImageDesc <>
    SavedImages             POINTER ?
    ExtensionBlockCount     DWORD ?
    ExtensionBlocks         POINTER ?
    Error                   DWORD ?
    UserData                POINTER ?
    Private_                POINTER ?
GifFileType                 ENDS

GraphicsControlBlock        STRUCT
    DisposalMode            DWORD ?
    UserInputFlag           bool ?
    DelayTime               DWORD ?
    TransparentColor        DWORD ?
GraphicsControlBlock        ENDS

GIF_ASPECT_RATIO macro n
    exitm <( ( n ) + 15.0 / 64.0 ) >
endm

.CONST

GIFLIB_MAJOR                EQU 5
GIFLIB_MINOR                EQU 2
GIFLIB_RELEASE              EQU 1
GIF_ERROR                   EQU 0
GIF_OK                      EQU 1

GIF_STAMP                   TEXTEQU <"GIFVER",0>
GIF_STAMP_LEN               EQU SIZEOF ( GIF_STAMP ) - 1
GIF_VERSION_POS             EQU 3
GIF87_STAMP                 TEXTEQU <"GIF87a",0>
GIF89_STAMP                 TEXTEQU <"GIF89a",0>

CONTINUE_EXT_FUNC_CODE      EQU 00h
COMMENT_EXT_FUNC_CODE       EQU 0feh
GRAPHICS_EXT_FUNC_CODE      EQU 0f9h
PLAINTEXT_EXT_FUNC_CODE     EQU 01h
APPLICATION_EXT_FUNC_CODE   EQU 0ffh

GifRecordType TYPEDEF SDWORD
UNDEFINED_RECORD_TYPE       EQU 0
SCREEN_DESC_RECORD_TYPE     EQU 1
IMAGE_DESC_RECORD_TYPE      EQU 2
EXTENSION_RECORD_TYPE       EQU 3
TERMINATE_RECORD_TYPE       EQU 4

DISPOSAL_UNSPECIFIED        EQU 0
DISPOSE_DO_NOT              EQU 1
DISPOSE_BACKGROUND          EQU 2
DISPOSE_PREVIOUS            EQU 3
NO_TRANSPARENT_COLOR        EQU -1

E_GIF_SUCCEEDED             EQU 0
E_GIF_ERR_OPEN_FAILED       EQU 1
E_GIF_ERR_WRITE_FAILED      EQU 2
E_GIF_ERR_HAS_SCRN_DSCR     EQU 3
E_GIF_ERR_HAS_IMAG_DSCR     EQU 4
E_GIF_ERR_NO_COLOR_MAP      EQU 5
E_GIF_ERR_DATA_TOO_BIG      EQU 6
E_GIF_ERR_NOT_ENOUGH_MEM    EQU 7
E_GIF_ERR_DISK_IS_FULL      EQU 8
E_GIF_ERR_CLOSE_FAILED      EQU 9
E_GIF_ERR_NOT_WRITEABLE     EQU 10

D_GIF_SUCCEEDED             EQU 0
D_GIF_ERR_OPEN_FAILED       EQU 101
D_GIF_ERR_READ_FAILED       EQU 102
D_GIF_ERR_NOT_GIF_FILE      EQU 103
D_GIF_ERR_NO_SCRN_DSCR      EQU 104
D_GIF_ERR_NO_IMAG_DSCR      EQU 105
D_GIF_ERR_NO_COLOR_MAP      EQU 106
D_GIF_ERR_WRONG_RECORD      EQU 107
D_GIF_ERR_DATA_TOO_BIG      EQU 108
D_GIF_ERR_NOT_ENOUGH_MEM    EQU 109
D_GIF_ERR_CLOSE_FAILED      EQU 110
D_GIF_ERR_NOT_READABLE      EQU 111
D_GIF_ERR_IMAGE_DEFECT      EQU 112
D_GIF_ERR_EOF_TOO_SOON      EQU 113

GIF_FONT_WIDTH              EQU 8
GIF_FONT_HEIGHT             EQU 8

externdef c GifAsciiTable8x8: BYTE