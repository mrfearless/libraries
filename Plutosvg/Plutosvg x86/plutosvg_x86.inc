; Tiny SVG rendering library in C by Samuel Ugochukwu
; https://github.com/sammycage/plutosvg

; Plutosvg_x86.inc converted from Plutosvg source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

plutosvg_document_destroy           PROTO STDCALL document:DWORD
plutosvg_document_extents           PROTO STDCALL document:DWORD,id:DWORD,extents:DWORD
plutosvg_document_get_height        PROTO STDCALL document:DWORD
plutosvg_document_get_width         PROTO STDCALL document:DWORD
plutosvg_document_load_from_data    PROTO STDCALL data:DWORD,dwLength:DWORD,fWidth:REAL4,fHeight:REAL4,destroy_func:DWORD,closure:DWORD
plutosvg_document_load_from_file    PROTO STDCALL lpszfilename:DWORD,fWidth:REAL4,fHeight:REAL4
plutosvg_document_render            PROTO STDCALL document:DWORD,id:DWORD,canvas:DWORD,current_color:DWORD,palette_func:DWORD,closure:DWORD
plutosvg_document_render_to_surface PROTO STDCALL document:DWORD,id:DWORD,dwWidth:DWORD,dwHeight:DWORD,current_color:DWORD,palette_func:DWORD,closure:DWORD
plutosvg_ft_svg_hooks               PROTO STDCALL 
plutosvg_version                    PROTO STDCALL 
plutosvg_version_string             PROTO STDCALL 


plutosvg_palette_func_t             PROTO STDCALL closure:DWORD, lpszname:DWORD, dwlength:DWORD, pcolor:DWORD ; plutovg_color_t* 

.CONST
PLUTOSVG_VERSION_MAJOR              EQU 0
PLUTOSVG_VERSION_MINOR              EQU 0
PLUTOSVG_VERSION_MICRO              EQU 2

plutosvg_document                   TYPEDEF DWORD
plutosvg_document_t                 TYPEDEF DWORD