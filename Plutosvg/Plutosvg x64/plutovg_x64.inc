; Tiny 2D vector graphics library in C by Samuel Ugochukwu
; https://github.com/sammycage/plutovg

; Plutovg_x64.inc converted from Plutovg source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

PVG_FT_Angle_Diff           PROTO :QWORD,:QWORD
PVG_FT_Atan2                PROTO :QWORD,:QWORD
PVG_FT_Cos                  PROTO :QWORD
PVG_FT_DivFix               PROTO :QWORD,:QWORD
PVG_FT_MulDiv               PROTO :QWORD,:QWORD,:QWORD
PVG_FT_MulFix               PROTO :QWORD,:QWORD
PVG_FT_Outline_Check        PROTO :QWORD
PVG_FT_Outline_Get_CBox     PROTO :QWORD,:QWORD
PVG_FT_Raster_Render        PROTO :QWORD
PVG_FT_Sin                  PROTO :QWORD
PVG_FT_Stroker_BeginSubPath PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Stroker_ConicTo      PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Stroker_CubicTo      PROTO :QWORD,:QWORD,:QWORD,:QWORD
PVG_FT_Stroker_Done         PROTO :QWORD
PVG_FT_Stroker_EndSubPath   PROTO :QWORD
PVG_FT_Stroker_Export       PROTO :QWORD,:QWORD
PVG_FT_Stroker_ExportBorder PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Stroker_GetBorderCounts PROTO :QWORD,:QWORD,:QWORD,:QWORD
PVG_FT_Stroker_GetCounts    PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Stroker_LineTo       PROTO :QWORD,:QWORD
PVG_FT_Stroker_New          PROTO :QWORD
PVG_FT_Stroker_ParseOutline PROTO :QWORD,:QWORD
PVG_FT_Stroker_Rewind       PROTO :QWORD
PVG_FT_Stroker_Set          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
PVG_FT_Tan                  PROTO :QWORD
PVG_FT_Vector_From_Polar    PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Vector_Length        PROTO :QWORD
PVG_FT_Vector_Polarize      PROTO :QWORD,:QWORD,:QWORD
PVG_FT_Vector_Rotate        PROTO :QWORD,:QWORD
PVG_FT_Vector_Unit          PROTO :QWORD,:QWORD

plutovg_blend               PROTO :QWORD,:QWORD
plutovg_canvas_add_glyph    PROTO canvas:QWORD,codepoint:QWORD,x:REAL4,y:REAL4
plutovg_canvas_add_path     PROTO canvas:QWORD,path:QWORD
plutovg_canvas_add_text     PROTO canvas:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD,x:REAL4,y:REAL4
plutovg_canvas_arc          PROTO canvas:QWORD,cxx:REAL4,cyy:REAL4,r:REAL4,a0:REAL4,a1:REAL4,ccw:QWORD
plutovg_canvas_arc_to       PROTO canvas:QWORD,rx:REAL4,ry:REAL4,angle:REAL4,large_arc_flag:QWORD,sweep_flag:QWORD,x:REAL4,y:REAL4
plutovg_canvas_circle       PROTO canvas:QWORD,cxx:REAL4,cyy:REAL4,r:REAL4
plutovg_canvas_clip         PROTO canvas:QWORD
plutovg_canvas_clip_extents PROTO canvas:QWORD,extents:QWORD
plutovg_canvas_clip_path    PROTO canvas:QWORD,path:QWORD
plutovg_canvas_clip_preserve PROTO canvas:QWORD
plutovg_canvas_clip_rect    PROTO canvas:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_clip_text    PROTO canvas:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD,x:REAL4,y:REAL4
plutovg_canvas_close_path   PROTO canvas:QWORD
plutovg_canvas_create       PROTO surface:QWORD
plutovg_canvas_cubic_to     PROTO canvas:QWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,x3:REAL4,y3:REAL4
plutovg_canvas_destroy      PROTO canvas:QWORD
plutovg_canvas_ellipse      PROTO canvas:QWORD,cxx:REAL4,cyy:REAL4,rx:REAL4,ry:REAL4
plutovg_canvas_fill         PROTO canvas:QWORD
plutovg_canvas_fill_extents PROTO canvas:QWORD,extents:QWORD
plutovg_canvas_fill_path    PROTO canvas:QWORD,path:QWORD
plutovg_canvas_fill_preserve PROTO canvas:QWORD
plutovg_canvas_fill_rect    PROTO canvas:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_fill_text    PROTO canvas:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD,x:REAL4,y:REAL4
plutovg_canvas_font_metrics PROTO canvas:QWORD,ascent:REAL4,descent:REAL4,line_gap:REAL4,extents:QWORD
plutovg_canvas_get_current_point PROTO canvas:QWORD,x:REAL4,y:REAL4
plutovg_canvas_get_dash_array PROTO canvas:QWORD,dashes:REAL4
plutovg_canvas_get_dash_offset PROTO canvas:QWORD
plutovg_canvas_get_fill_rule PROTO canvas:QWORD
plutovg_canvas_get_font_face PROTO canvas:QWORD
plutovg_canvas_get_font_size PROTO canvas:QWORD
plutovg_canvas_get_line_cap PROTO canvas:QWORD
plutovg_canvas_get_line_join PROTO canvas:QWORD
plutovg_canvas_get_line_width PROTO canvas:QWORD
plutovg_canvas_get_matrix   PROTO canvas:QWORD,:QWORD
plutovg_canvas_get_miter_limit PROTO canvas:QWORD
plutovg_canvas_get_opacity  PROTO canvas:QWORD
plutovg_canvas_get_operator PROTO canvas:QWORD
plutovg_canvas_get_paint    PROTO canvas:QWORD,color:QWORD
plutovg_canvas_get_path     PROTO canvas:QWORD
plutovg_canvas_get_reference_count PROTO canvas:QWORD
plutovg_canvas_get_surface  PROTO canvas:QWORD
plutovg_canvas_glyph_metrics PROTO canvas:QWORD,codepoint:QWORD,advance_width:REAL4,left_side_bearing:REAL4,extents:QWORD
plutovg_canvas_line_to      PROTO canvas:QWORD,x:REAL4,y:REAL4
plutovg_canvas_map          PROTO canvas:QWORD,x:REAL4,y:REAL4,xx:REAL4,yy:REAL4
plutovg_canvas_map_point    PROTO canvas:QWORD,src:QWORD,dst:QWORD
plutovg_canvas_map_rect     PROTO canvas:QWORD,src:QWORD,dst:QWORD
plutovg_canvas_move_to      PROTO canvas:QWORD,x:REAL4,y:REAL4
plutovg_canvas_new_path     PROTO canvas:QWORD
plutovg_canvas_paint        PROTO canvas:QWORD
plutovg_canvas_quad_to      PROTO canvas:QWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4
plutovg_canvas_rect         PROTO canvas:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_reference    PROTO canvas:QWORD
plutovg_canvas_reset_matrix PROTO canvas:QWORD
plutovg_canvas_restore      PROTO canvas:QWORD
plutovg_canvas_rotate       PROTO canvas:QWORD,angle:REAL4
plutovg_canvas_round_rect   PROTO canvas:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4,rx:REAL4,ry:REAL4
plutovg_canvas_save         PROTO canvas:QWORD
plutovg_canvas_scale        PROTO canvas:QWORD,sx:REAL4,sy:REAL4
plutovg_canvas_set_color    PROTO canvas:QWORD,color:QWORD
plutovg_canvas_set_dash     PROTO canvas:QWORD,startoffset:QWORD,dashes:QWORD,ndashes:QWORD
plutovg_canvas_set_dash_array PROTO canvas:QWORD,dashes:REAL4,ndashes:QWORD
plutovg_canvas_set_dash_offset PROTO canvas:QWORD,startoffset:QWORD
plutovg_canvas_set_fill_rule PROTO canvas:QWORD,winding:QWORD
plutovg_canvas_set_font     PROTO canvas:QWORD,face:QWORD,fsize:REAL4
plutovg_canvas_set_font_face PROTO canvas:QWORD,face:QWORD
plutovg_canvas_set_font_size PROTO canvas:QWORD,fsize:REAL4
plutovg_canvas_set_line_cap PROTO canvas:QWORD,line_cap:QWORD
plutovg_canvas_set_line_join PROTO canvas:QWORD,line_join:QWORD
plutovg_canvas_set_line_width PROTO canvas:QWORD,line_width:REAL4
plutovg_canvas_set_linear_gradient PROTO canvas:QWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,spread:QWORD,stops:QWORD,nstops:QWORD,matrix:QWORD
plutovg_canvas_set_matrix   PROTO canvas:QWORD,matrix:QWORD
plutovg_canvas_set_miter_limit PROTO canvas:QWORD,miter_limit:REAL4
plutovg_canvas_set_opacity  PROTO canvas:QWORD,opacity:REAL4
plutovg_canvas_set_operator PROTO canvas:QWORD,op:QWORD
plutovg_canvas_set_paint    PROTO canvas:QWORD,paint:QWORD
plutovg_canvas_set_radial_gradient PROTO canvas:QWORD,cxx:REAL4,cyy:REAL4,cr:REAL4,fx:REAL4,fy:REAL4,fr:REAL4,spread:QWORD,stops:QWORD,nstops:QWORD,matrix:QWORD
plutovg_canvas_set_rgb      PROTO canvas:QWORD,r:REAL4,g:REAL4,b:REAL4
plutovg_canvas_set_rgba     PROTO canvas:QWORD,r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_canvas_set_texture  PROTO canvas:QWORD,surface:QWORD,dwtype:QWORD,opacity:REAL4,matrix:QWORD
plutovg_canvas_shear        PROTO canvas:QWORD,shx:REAL4,shy:REAL4
plutovg_canvas_stroke       PROTO canvas:QWORD
plutovg_canvas_stroke_extents PROTO canvas:QWORD,:QWORD
plutovg_canvas_stroke_path  PROTO canvas:QWORD,path:QWORD
plutovg_canvas_stroke_preserve PROTO canvas:QWORD
plutovg_canvas_stroke_rect  PROTO canvas:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_stroke_text  PROTO canvas:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD,x:REAL4,y:REAL4
plutovg_canvas_text_extents PROTO canvas:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD,extents:QWORD
plutovg_canvas_transform    PROTO canvas:QWORD,matrix:QWORD
plutovg_canvas_translate    PROTO canvas:QWORD,tx:REAL4,ty:REAL4
plutovg_color_init_argb32   PROTO color:QWORD,value:QWORD
plutovg_color_init_rgb8     PROTO color:QWORD,r:QWORD,g:QWORD,b:QWORD
plutovg_color_init_rgb      PROTO color:QWORD,r:REAL4,g:REAL4,b:REAL4
plutovg_color_init_rgba32   PROTO color:QWORD,value:QWORD
plutovg_color_init_rgba8    PROTO color:QWORD,r:QWORD,g:QWORD,b:QWORD,a:QWORD
plutovg_color_init_rgba     PROTO color:QWORD,r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_color_parse         PROTO color:QWORD,data:QWORD,dwlength:QWORD
plutovg_color_to_argb32     PROTO color:QWORD
plutovg_color_to_rgba32     PROTO color:QWORD
plutovg_convert_argb_to_rgba PROTO dst:QWORD,src:QWORD,dwwidth:QWORD,dwheight:QWORD,stride:QWORD
plutovg_convert_rgba_to_argb PROTO dst:QWORD,src:QWORD,dwwidth:QWORD,dwheight:QWORD,stride:QWORD
plutovg_font_face_destroy   PROTO face:QWORD
plutovg_font_face_get_glyph_metrics PROTO face:QWORD,fsize:REAL4,codepoint:QWORD,advance_width:REAL4,left_side_bearing:REAL4,extents:QWORD
plutovg_font_face_get_glyph_path PROTO face:QWORD,fsize:REAL4,x:REAL4,y:REAL4,codepoint:QWORD,path:QWORD
plutovg_font_face_get_metrics PROTO face:QWORD,fsize:REAL4,ascent:REAL4,descent:REAL4,line_gap:REAL4,extents:QWORD
plutovg_font_face_get_reference_count PROTO face:QWORD
plutovg_font_face_load_from_data PROTO data:QWORD,dwlength:QWORD,ttcindex:QWORD,destroy_func:QWORD,closure:QWORD
plutovg_font_face_load_from_file PROTO filename:QWORD,ttcindex:QWORD
plutovg_font_face_reference PROTO face:QWORD
plutovg_font_face_text_extents PROTO face:QWORD,fsize:REAL4,text:QWORD,dwlength:QWORD,encoding:QWORD,extents:QWORD
plutovg_font_face_traverse_glyph_path PROTO face:QWORD,fsize:REAL4,x:REAL4,y:REAL4,codepoint:QWORD,traverse_func:QWORD,closure:QWORD
plutovg_matrix_init         PROTO matrix:QWORD,a:REAL4,b:REAL4,c_:REAL4,d:REAL4,e:REAL4,f:REAL4
plutovg_matrix_init_identity PROTO matrix:QWORD
plutovg_matrix_init_rotate  PROTO matrix:QWORD,angle:REAL4
plutovg_matrix_init_scale   PROTO matrix:QWORD,sx:REAL4,sy:REAL4
plutovg_matrix_init_shear   PROTO matrix:QWORD,shx:REAL4,shy:REAL4
plutovg_matrix_init_translate PROTO matrix:QWORD,tx:REAL4,ty:REAL4
plutovg_matrix_invert       PROTO matrix:QWORD,inverse:QWORD
plutovg_matrix_map          PROTO matrix:QWORD,x:REAL4,y:REAL4,xx:REAL4,yy:REAL4
plutovg_matrix_map_point    PROTO matrix:QWORD,src:QWORD,dst:QWORD
plutovg_matrix_map_points   PROTO matrix:QWORD,src:QWORD,dst:QWORD,count:QWORD
plutovg_matrix_map_rect     PROTO matrix:QWORD,src:QWORD,dst:QWORD
plutovg_matrix_multiply     PROTO matrix:QWORD,left:QWORD,right:QWORD
plutovg_matrix_parse        PROTO matrix:QWORD,data:QWORD,datalength:QWORD
plutovg_matrix_rotate       PROTO matrix:QWORD,angle:REAL4
plutovg_matrix_scale        PROTO matrix:QWORD,sx:REAL4,sy:REAL4
plutovg_matrix_shear        PROTO matrix:QWORD,shx:QWORD,shy:QWORD
plutovg_matrix_translate    PROTO matrix:QWORD,tx:REAL4,ty:REAL4
plutovg_memfill32           PROTO :QWORD,:QWORD,:QWORD
plutovg_paint_create_color  PROTO color:QWORD
plutovg_paint_create_linear_gradient PROTO x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,spread:QWORD,stops:QWORD,nstops:QWORD,matrix:QWORD
plutovg_paint_create_radial_gradient PROTO cxx:REAL4,cyy:REAL4,cr:REAL4,fx:REAL4,fy:REAL4,fr:REAL4,spread:QWORD,stops:QWORD,nstops:QWORD,matrix:QWORD
plutovg_paint_create_rgb    PROTO r:REAL4,g:REAL4,b:REAL4
plutovg_paint_create_rgba   PROTO r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_paint_create_texture PROTO surface:QWORD,dwtype:QWORD,opacity:REAL4,matrix:QWORD
plutovg_paint_destroy       PROTO paint:QWORD
plutovg_paint_get_reference_count PROTO paint:QWORD
plutovg_paint_reference     PROTO paint:QWORD
plutovg_path_add_arc        PROTO path:QWORD,cxx:REAL4,cyy:REAL4,r:REAL4,a0:REAL4,a1:REAL4,ccw:REAL4
plutovg_path_add_circle     PROTO path:QWORD,cxx:REAL4,cyy:REAL4,r:REAL4
plutovg_path_add_ellipse    PROTO path:QWORD,cxx:REAL4,cyy:REAL4,rx:REAL4,ry:REAL4
plutovg_path_add_path       PROTO path:QWORD,source:QWORD,matrix:QWORD
plutovg_path_add_rect       PROTO path:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_path_add_round_rect PROTO path:QWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4,rx:REAL4,ry:REAL4
plutovg_path_arc_to         PROTO path:QWORD,rx:REAL4,ry:REAL4,angle:REAL4,large_arc_flag:QWORD,sweep_flag:QWORD,x:REAL4,y:REAL4
plutovg_path_clone          PROTO path:QWORD
plutovg_path_clone_dashed   PROTO path:QWORD,startoffset:QWORD,dashes:QWORD,ndashes:QWORD
plutovg_path_clone_flatten  PROTO path:QWORD
plutovg_path_close          PROTO path:QWORD
plutovg_path_create         PROTO 
plutovg_path_cubic_to       PROTO path:QWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,x3:REAL4,y3:REAL4
plutovg_path_destroy        PROTO path:QWORD
plutovg_path_extents        PROTO path:QWORD,extents:QWORD,tight:QWORD
plutovg_path_get_current_point PROTO path:QWORD,x:REAL4,y:REAL4
plutovg_path_get_elements   PROTO path:QWORD,elements:QWORD
plutovg_path_get_reference_count PROTO path:QWORD
plutovg_path_iterator_has_next PROTO it:QWORD
plutovg_path_iterator_init  PROTO it:QWORD,path:QWORD
plutovg_path_iterator_next  PROTO it:QWORD,points:QWORD
plutovg_path_length         PROTO path:QWORD
plutovg_path_line_to        PROTO path:QWORD,x:REAL4,y:REAL4
plutovg_path_move_to        PROTO path:QWORD,x:REAL4,y:REAL4
plutovg_path_parse          PROTO path:QWORD,data:QWORD,dwlength:QWORD
plutovg_path_quad_to        PROTO path:QWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4
plutovg_path_reference      PROTO path:QWORD
plutovg_path_reserve        PROTO path:QWORD,count:QWORD
plutovg_path_reset          PROTO path:QWORD
plutovg_path_transform      PROTO path:QWORD,matrix:QWORD
plutovg_path_traverse       PROTO path:QWORD,traverse_func:QWORD,closure:QWORD
plutovg_path_traverse_dashed PROTO path:QWORD,startoffset:QWORD,dashes:QWORD,ndashes:QWORD,traverse_func:QWORD,closure:QWORD
plutovg_path_traverse_flatten PROTO path:QWORD,traverse_func:QWORD,closure:QWORD
plutovg_rasterize           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
plutovg_span_buffer_copy    PROTO :QWORD,:QWORD
plutovg_span_buffer_destroy PROTO :QWORD
plutovg_span_buffer_extents PROTO :QWORD,:QWORD
plutovg_span_buffer_init    PROTO :QWORD
plutovg_span_buffer_init_rect PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
plutovg_span_buffer_intersect PROTO :QWORD,:QWORD,:QWORD
plutovg_span_buffer_reset   PROTO :QWORD
plutovg_surface_clear       PROTO surface:QWORD,color:QWORD
plutovg_surface_create      PROTO dwwidth:QWORD,dwheight:QWORD
plutovg_surface_create_for_data PROTO data:QWORD,dwwidth:QWORD,dwheight:QWORD,stride:QWORD
plutovg_surface_destroy     PROTO surface:QWORD
plutovg_surface_get_data    PROTO surface:QWORD
plutovg_surface_get_height  PROTO surface:QWORD
plutovg_surface_get_reference_count PROTO surface:QWORD
plutovg_surface_get_stride  PROTO surface:QWORD
plutovg_surface_get_width   PROTO surface:QWORD
plutovg_surface_load_from_image_base64 PROTO data:QWORD,dwlength:QWORD
plutovg_surface_load_from_image_data PROTO data:QWORD,dwlength:QWORD
plutovg_surface_load_from_image_file PROTO filename:QWORD
plutovg_surface_reference   PROTO surface:QWORD
plutovg_surface_write_to_jpg PROTO surface:QWORD,filename:QWORD,quality:QWORD
plutovg_surface_write_to_jpg_stream PROTO surface:QWORD,write_func:QWORD,closure:QWORD,quality:QWORD
plutovg_surface_write_to_png PROTO surface:QWORD,filename:QWORD
plutovg_surface_write_to_png_stream PROTO surface:QWORD,write_func:QWORD,closure:QWORD
plutovg_text_iterator_has_next PROTO it:QWORD
plutovg_text_iterator_init  PROTO it:QWORD,text:QWORD,dwlength:QWORD,encoding:QWORD
plutovg_text_iterator_next  PROTO it:QWORD
plutovg_version             PROTO 
plutovg_version_string      PROTO 

plutovg_path_command        TYPEDEF QWORD
plutovg_path_command_t      TYPEDEF QWORD
plutovg_text_encoding       TYPEDEF QWORD
plutovg_text_encoding_t     TYPEDEF QWORD
plutovg_path                TYPEDEF QWORD
plutovg_path_t              TYPEDEF QWORD
plutovg_codepoint           TYPEDEF QWORD
plutovg_codepoint_t         TYPEDEF QWORD
plutovg_font_face           TYPEDEF QWORD 
plutovg_font_face_t         TYPEDEF QWORD
plutovg_surface             TYPEDEF QWORD
plutovg_surface_t           TYPEDEF QWORD
plutovg_paint               TYPEDEF QWORD
plutovg_paint_t             TYPEDEF QWORD
plutovg_canvas              TYPEDEF QWORD
plutovg_canvas_t            TYPEDEF QWORD

plutovg_point STRUCT 8
    x REAL4 ?
    y REAL4 ?
plutovg_point ENDS
plutovg_point_t TYPEDEF PTR plutovg_point

plutovg_rect STRUCT 8
    x REAL4 ?
    y REAL4 ?
    w REAL4 ?
    h REAL4 ?
plutovg_rect ENDS
plutovg_rect_t TYPEDEF PTR plutovg_rect

plutovg_matrix STRUCT 8
    a REAL4 ?
    b REAL4 ?
    c_ REAL4 ?
    d REAL4 ?
    e REAL4 ?
    f REAL4 ?
plutovg_matrix ENDS
plutovg_matrix_t TYPEDEF PTR plutovg_matrix

plutovg_color STRUCT 8
    r REAL4 ? ; Red component (0 to 1).
    g REAL4 ? ; Green component (0 to 1).
    b REAL4 ? ; Blue component (0 to 1).
    a REAL4 ? ; Alpha (opacity) component (0 to 1)
plutovg_color ENDS
plutovg_color_t TYPEDEF PTR plutovg_color

plutovg_gradient_stop_t STRUCT 8
    foffset             REAL4 ?
    color               plutovg_color_t ?
plutovg_gradient_stop_t ENDS

pathheader      STRUCT 8
    command     plutovg_path_command_t ?
    dwlength    DWORD ?
pathheader      ENDS

plutovg_path_element UNION
    header           pathheader <>
    point            plutovg_point_t ?
plutovg_path_element ENDS
plutovg_path_element_t TYPEDEF PTR plutovg_path_element

plutovg_path_iterator STRUCT 8
    elements          plutovg_path_element_t ?
    dwSize            DWORD ?
    dwIndex           DWORD ?
plutovg_path_iterator ENDS
plutovg_path_iterator_t TYPEDEF PTR plutovg_path_iterator

plutovg_text_iterator STRUCT 8
    text              DWORD ? ; Pointer to the text data.
    dwlength          DWORD ? ; Length of the text data.
    encoding          plutovg_text_encoding_t ? ; Encoding format of the text data.
    dwIndex           DWORD ?
plutovg_text_iterator ENDS
plutovg_text_iterator_t TYPEDEF PTR plutovg_text_iterator



.CONST
PLUTOVG_VERSION_MAJOR       EQU 0
PLUTOVG_VERSION_MINOR       EQU 0
PLUTOVG_VERSION_MICRO       EQU 7

PLUTOVG_PI                  REAL4 3.14159265358979323846
PLUTOVG_TWO_PI              REAL4 6.28318530717958647693
PLUTOVG_HALF_PI             REAL4 1.57079632679489661923
PLUTOVG_SQRT2               REAL4 1.41421356237309504880
PLUTOVG_KAPPA               REAL4 0.55228474983079339840

;PLUTOVG_DEG2RAD(x) ((x) * (PLUTOVG_PI / 180.0f))
;PLUTOVG_RAD2DEG(x) ((x) * (180.0f / PLUTOVG_PI))

; plutovg_path_command
PLUTOVG_PATH_COMMAND_MOVE_TO    EQU 0 ; Moves the current point to a new position.
PLUTOVG_PATH_COMMAND_LINE_TO    EQU 1 ; Draws a straight line to a new point.
PLUTOVG_PATH_COMMAND_CUBIC_TO   EQU 2 ; Draws a cubic Bézier curve to a new point.
PLUTOVG_PATH_COMMAND_CLOSE      EQU 3 ; Closes the current path by drawing a line to the starting point.

; plutovg_text_encoding
PLUTOVG_TEXT_ENCODING_UTF8      EQU 0 ; UTF-8 encoding
PLUTOVG_TEXT_ENCODING_UTF16     EQU 1 ; UTF-16 encoding
PLUTOVG_TEXT_ENCODING_UTF32     EQU 2 ; UTF-32 encoding
PLUTOVG_TEXT_ENCODING_LATIN1    EQU 3 ; Latin-1 encoding

; plutovg_texture_type_t
PLUTOVG_TEXTURE_TYPE_PLAIN      EQU 0 ; Plain texture.
PLUTOVG_TEXTURE_TYPE_TILED      EQU 1 ; Tiled texture.

; plutovg_spread_method_t
PLUTOVG_SPREAD_METHOD_PAD       EQU 0 ; Pad the gradient's edges.
PLUTOVG_SPREAD_METHOD_REFLECT   EQU 1 ; Reflect the gradient beyond its bounds.
PLUTOVG_SPREAD_METHOD_REPEAT    EQU 2 ; Repeat the gradient pattern.

; plutovg_fill_rule_t
PLUTOVG_FILL_RULE_NON_ZERO      EQU 0 ; Non-zero winding fill rule.
PLUTOVG_FILL_RULE_EVEN_ODD      EQU 1 ; Even-odd fill rule.

; plutovg_operator_t
PLUTOVG_OPERATOR_SRC            EQU 0 ; Source replaces destination.
PLUTOVG_OPERATOR_SRC_OVER       EQU 1 ; Source over destination.
PLUTOVG_OPERATOR_DST_IN         EQU 2 ; Destination within source.
PLUTOVG_OPERATOR_DST_OUT        EQU 3 ; Destination outside source.

; plutovg_line_cap_t 
PLUTOVG_LINE_CAP_BUTT           EQU 0 ; Flat edge at the end of the stroke.
PLUTOVG_LINE_CAP_ROUND          EQU 1 ; Rounded ends at the end of the stroke.
PLUTOVG_LINE_CAP_SQUARE         EQU 2 ; Square ends at the end of the stroke.

; plutovg_line_join_t
PLUTOVG_LINE_JOIN_MITER         EQU 0 ; Miter join with sharp corners.
PLUTOVG_LINE_JOIN_ROUND         EQU 1 ; Rounded join.
PLUTOVG_LINE_JOIN_BEVEL         EQU 2 ; Beveled join with a flattened corner.










