; Tiny SVG rendering library in C by Samuel Ugochukwu
; https://github.com/sammycage/plutosvg

; Plutosvg_x64.inc converted from Plutosvg source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

plutosvg_document_destroy           PROTO document:QWORD
plutosvg_document_extents           PROTO document:QWORD,id:QWORD,extents:QWORD
plutosvg_document_get_height        PROTO document:QWORD
plutosvg_document_get_width         PROTO document:QWORD
plutosvg_document_load_from_data    PROTO data:QWORD,dwLength:QWORD,fWidth:REAL4,fHeight:REAL4,destroy_func:QWORD,closure:QWORD
plutosvg_document_load_from_file    PROTO lpszfilename:QWORD,fWidth:REAL4,fHeight:REAL4
plutosvg_document_render            PROTO document:QWORD,id:QWORD,canvas:QWORD,current_color:QWORD,palette_func:QWORD,closure:QWORD
plutosvg_document_render_to_surface PROTO document:QWORD,id:QWORD,dwWidth:QWORD,dwHeight:QWORD,current_color:QWORD,palette_func:QWORD,closure:QWORD
plutosvg_ft_svg_hooks               PROTO 
plutosvg_version                    PROTO 
plutosvg_version_string             PROTO 


plutosvg_palette_func_t             PROTO closure:QWORD, lpszname:QWORD, dwlength:QWORD, pcolor:QWORD ; plutovg_color_t* 

.CONST
PLUTOSVG_VERSION_MAJOR              EQU 0
PLUTOSVG_VERSION_MINOR              EQU 0
PLUTOSVG_VERSION_MICRO              EQU 2

plutosvg_document                   TYPEDEF QWORD
plutosvg_document_t                 TYPEDEF QWORD