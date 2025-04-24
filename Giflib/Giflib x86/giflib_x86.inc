; Eric S. Raymond
; https://sourceforge.net/projects/giflib/
; https://giflib.sourceforge.net/
; Docs: https://giflib.sourceforge.net/gif_lib.html

; Giflib_x86.inc converted from Giflib source for assembler by fearless 2024
; www.github.com/mrfearless

DGifCloseFile               PROTO STDCALL GifFile:DWORD,ErrorCode:DWORD
DGifExtensionToGCB          PROTO STDCALL GifExtensionLength:DWORD,GifExtension:DWORD,GCB:DWORD
DGifGetCode                 PROTO STDCALL GifFile:DWORD,GifCodeSize:DWORD,GifCodeBlock:DWORD
DGifGetCodeNext             PROTO STDCALL GifFile:DWORD,GifCodeBlock:DWORD
DGifGetExtension            PROTO STDCALL GifFile:DWORD,GifExtCode:DWORD,GifExtension:DWORD
DGifGetExtensionNext        PROTO STDCALL GifFile:DWORD,GifExtension:DWORD
DGifGetGifVersion           PROTO STDCALL GifFile:DWORD
DGifGetImageDesc            PROTO STDCALL GifFile:DWORD
DGifGetImageHeader          PROTO STDCALL GifFile:DWORD
DGifGetLZCodes              PROTO STDCALL GifFile:DWORD,GifCode:DWORD
DGifGetLine                 PROTO STDCALL GifFile:DWORD,GifPixelType:DWORD,GifLineLen:DWORD
DGifGetPixel                PROTO STDCALL GifFile:DWORD,GifPixel:DWORD
DGifGetRecordType           PROTO STDCALL GifFile:DWORD,GifType:DWORD
DGifGetScreenDesc           PROTO STDCALL GifFile:DWORD
DGifOpen                    PROTO STDCALL userPtr:DWORD,readFunc:DWORD,Error:DWORD
DGifOpenFileHandle          PROTO STDCALL GifFileHandle:DWORD,Error:DWORD
DGifOpenFileName            PROTO STDCALL GifFileName:DWORD,Error:DWORD
DGifSavedExtensionToGCB     PROTO STDCALL GifFile:DWORD,ImageIndex:DWORD,GCB:DWORD
DGifSlurp                   PROTO STDCALL GifFile:DWORD
EGifCloseFile               PROTO STDCALL GifFile:DWORD,ErrorCode:DWORD
EGifGCBToExtension          PROTO STDCALL GCB:DWORD,GifExtension:DWORD
EGifGCBToSavedExtension     PROTO STDCALL GCB:DWORD,GifFile:DWORD,ImageIndex:DWORD
EGifGetGifVersion           PROTO STDCALL GifFile:DWORD
EGifOpen                    PROTO STDCALL userPtr:DWORD,writeFunc:DWORD,Error:DWORD
EGifOpenFileHandle          PROTO STDCALL GifFileHandle:DWORD,Error:DWORD
EGifOpenFileName            PROTO STDCALL GifFileName:DWORD,GifTestExistence:DWORD,Error:DWORD
EGifPutCode                 PROTO STDCALL GifFile:DWORD,GifCodeSize:DWORD,GifCodeBlock:DWORD
EGifPutCodeNext             PROTO STDCALL GifFile:DWORD,GifCodeBlock:DWORD
EGifPutComment              PROTO STDCALL GifFile:DWORD,GifComment:DWORD
EGifPutExtension            PROTO STDCALL GifFile:DWORD,GifExtCode:DWORD,GifExtLen:DWORD,GifExtension:DWORD
EGifPutExtensionBlock       PROTO STDCALL GifFile:DWORD,GifExtLen:DWORD,GifExtension:DWORD
EGifPutExtensionLeader      PROTO STDCALL GifFile:DWORD,GifExtCode:DWORD
EGifPutExtensionTrailer     PROTO STDCALL GifFile:DWORD
EGifPutImageDesc            PROTO STDCALL GifFile:DWORD,GifLeft:DWORD,GifTop:DWORD,GifWidth:DWORD,GifHeight:DWORD,GifInterlace:DWORD,GifColorMap:DWORD
EGifPutLine                 PROTO STDCALL GifFile:DWORD,GifLine:DWORD,GifLineLen:DWORD
EGifPutPixel                PROTO STDCALL GifFile:DWORD,GifPixel:DWORD
EGifPutScreenDesc           PROTO STDCALL GifFile:DWORD,GifWidth:DWORD,GifHeight:DWORD,GifColorRes:DWORD,GifBackGround:DWORD,GifColorMap:DWORD
EGifSetGifVersion           PROTO STDCALL GifFile:DWORD,gif89:DWORD
EGifSpew                    PROTO STDCALL GifFile:DWORD
FreeLastSavedImage          PROTO STDCALL :DWORD
GifAddExtensionBlock        PROTO STDCALL ExtensionBlock_Count:DWORD,ExtensionBlocks:DWORD,Function:DWORD,Len:DWORD,ExtData:DWORD
GifApplyTranslation         PROTO STDCALL Image:DWORD,Translation:DWORD
GifAsciiTable8x8            PROTO C :VARARG
GifBitSize                  PROTO STDCALL n:DWORD
GifDrawBox                  PROTO STDCALL Image:DWORD,x:DWORD,y:DWORD,w:DWORD,d:DWORD,color:DWORD
GifDrawBoxedText8x8         PROTO STDCALL Image:DWORD,x:DWORD,y:DWORD,legend:DWORD,border:DWORD,bg:DWORD,fg:DWORD
GifDrawRectangle            PROTO STDCALL Image:DWORD,x:DWORD,y:DWORD,w:DWORD,d:DWORD,color:DWORD
GifDrawText8x8              PROTO STDCALL Image:DWORD,x:DWORD,y:DWORD,legend:DWORD,color:DWORD
GifErrorString              PROTO STDCALL ErrorCode:DWORD
GifFreeExtensions           PROTO STDCALL ExtensionBlock_Count:DWORD,ExtensionBlocks:DWORD
GifFreeMapObject            PROTO STDCALL Object:DWORD
GifFreeSavedImages          PROTO STDCALL GifFile:DWORD
GifMakeMapObject            PROTO STDCALL ColorCount:DWORD,ColorMap:DWORD
GifMakeSavedImage           PROTO STDCALL GifFile:DWORD,CopyFrom:DWORD
GifQuantizeBuffer           PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GifUnionColorMap            PROTO STDCALL ColorIn1:DWORD,ColorIn2:DWORD,ColorTransIn2:DWORD

IFNDEF POINTER
POINTER                     TYPEDEF DWORD
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

ColorMapObject              STRUCT
    ColorCount              DWORD ?
    BitsPerPixel            DWORD ?
    SortFlag                bool ?
    Colors                  POINTER ?
ColorMapObject              ENDS

GifImageDesc                STRUCT
    Left                    GifWord ?
    Top                     GifWord ?
    Width_                  GifWord ?
    Height                  GifWord ?
    Interlace               bool ?
    ColorMap                POINTER ?
GifImageDesc                ENDS

ExtensionBlock              STRUCT
    ByteCount               DWORD ?
    Bytes                   POINTER ?
    Function                DWORD ?
ExtensionBlock              ENDS

SavedImage                  STRUCT
    ImageDesc               GifImageDesc <>
    RasterBits              POINTER ?
    ExtensionBlockCount     DWORD ?
    ExtensionBlocks         POINTER ?
SavedImage                  ENDS

GifFileType                 STRUCT
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