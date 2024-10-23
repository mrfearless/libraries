; Tiny 2D vector graphics library in C by Samuel Ugochukwu
; https://github.com/sammycage/plutovg

; Plutovg_x86.inc converted from Plutovg source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

PVG_FT_Angle_Diff           PROTO STDCALL :DWORD,:DWORD
PVG_FT_Atan2                PROTO STDCALL :DWORD,:DWORD
PVG_FT_Cos                  PROTO STDCALL :DWORD
PVG_FT_DivFix               PROTO STDCALL :DWORD,:DWORD
PVG_FT_MulDiv               PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_MulFix               PROTO STDCALL :DWORD,:DWORD
PVG_FT_Outline_Check        PROTO STDCALL :DWORD
PVG_FT_Outline_Get_CBox     PROTO STDCALL :DWORD,:DWORD
PVG_FT_Raster_Render        PROTO STDCALL :DWORD
PVG_FT_Sin                  PROTO STDCALL :DWORD
PVG_FT_Stroker_BeginSubPath PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Stroker_ConicTo      PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Stroker_CubicTo      PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PVG_FT_Stroker_Done         PROTO STDCALL :DWORD
PVG_FT_Stroker_EndSubPath   PROTO STDCALL :DWORD
PVG_FT_Stroker_Export       PROTO STDCALL :DWORD,:DWORD
PVG_FT_Stroker_ExportBorder PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Stroker_GetBorderCounts PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
PVG_FT_Stroker_GetCounts    PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Stroker_LineTo       PROTO STDCALL :DWORD,:DWORD
PVG_FT_Stroker_New          PROTO STDCALL :DWORD
PVG_FT_Stroker_ParseOutline PROTO STDCALL :DWORD,:DWORD
PVG_FT_Stroker_Rewind       PROTO STDCALL :DWORD
PVG_FT_Stroker_Set          PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PVG_FT_Tan                  PROTO STDCALL :DWORD
PVG_FT_Vector_From_Polar    PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Vector_Length        PROTO STDCALL :DWORD
PVG_FT_Vector_Polarize      PROTO STDCALL :DWORD,:DWORD,:DWORD
PVG_FT_Vector_Rotate        PROTO STDCALL :DWORD,:DWORD
PVG_FT_Vector_Unit          PROTO STDCALL :DWORD,:DWORD

plutovg_blend               PROTO STDCALL :DWORD,:DWORD
plutovg_canvas_add_glyph    PROTO STDCALL canvas:DWORD,codepoint:DWORD,x:REAL4,y:REAL4
plutovg_canvas_add_path     PROTO STDCALL canvas:DWORD,path:DWORD
plutovg_canvas_add_text     PROTO STDCALL canvas:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD,x:REAL4,y:REAL4
plutovg_canvas_arc          PROTO STDCALL canvas:DWORD,cxx:REAL4,cyy:REAL4,r:REAL4,a0:REAL4,a1:REAL4,ccw:DWORD
plutovg_canvas_arc_to       PROTO STDCALL canvas:DWORD,rx:REAL4,ry:REAL4,angle:REAL4,large_arc_flag:DWORD,sweep_flag:DWORD,x:REAL4,y:REAL4
plutovg_canvas_circle       PROTO STDCALL canvas:DWORD,cxx:REAL4,cyy:REAL4,r:REAL4
plutovg_canvas_clip         PROTO STDCALL canvas:DWORD
plutovg_canvas_clip_extents PROTO STDCALL canvas:DWORD,extents:DWORD
plutovg_canvas_clip_path    PROTO STDCALL canvas:DWORD,path:DWORD
plutovg_canvas_clip_preserve PROTO STDCALL canvas:DWORD
plutovg_canvas_clip_rect    PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_clip_text    PROTO STDCALL canvas:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD,x:REAL4,y:REAL4
plutovg_canvas_close_path   PROTO STDCALL canvas:DWORD
plutovg_canvas_create       PROTO STDCALL surface:DWORD
plutovg_canvas_cubic_to     PROTO STDCALL canvas:DWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,x3:REAL4,y3:REAL4
plutovg_canvas_destroy      PROTO STDCALL canvas:DWORD
plutovg_canvas_ellipse      PROTO STDCALL canvas:DWORD,cxx:REAL4,cyy:REAL4,rx:REAL4,ry:REAL4
plutovg_canvas_fill         PROTO STDCALL canvas:DWORD
plutovg_canvas_fill_extents PROTO STDCALL canvas:DWORD,extents:DWORD
plutovg_canvas_fill_path    PROTO STDCALL canvas:DWORD,path:DWORD
plutovg_canvas_fill_preserve PROTO STDCALL canvas:DWORD
plutovg_canvas_fill_rect    PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_fill_text    PROTO STDCALL canvas:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD,x:REAL4,y:REAL4
plutovg_canvas_font_metrics PROTO STDCALL canvas:DWORD,ascent:REAL4,descent:REAL4,line_gap:REAL4,extents:DWORD
plutovg_canvas_get_current_point PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4
plutovg_canvas_get_dash_array PROTO STDCALL canvas:DWORD,dashes:REAL4
plutovg_canvas_get_dash_offset PROTO STDCALL canvas:DWORD
plutovg_canvas_get_fill_rule PROTO STDCALL canvas:DWORD
plutovg_canvas_get_font_face PROTO STDCALL canvas:DWORD
plutovg_canvas_get_font_size PROTO STDCALL canvas:DWORD
plutovg_canvas_get_line_cap PROTO STDCALL canvas:DWORD
plutovg_canvas_get_line_join PROTO STDCALL canvas:DWORD
plutovg_canvas_get_line_width PROTO STDCALL canvas:DWORD
plutovg_canvas_get_matrix   PROTO STDCALL canvas:DWORD,:DWORD
plutovg_canvas_get_miter_limit PROTO STDCALL canvas:DWORD
plutovg_canvas_get_opacity  PROTO STDCALL canvas:DWORD
plutovg_canvas_get_operator PROTO STDCALL canvas:DWORD
plutovg_canvas_get_paint    PROTO STDCALL canvas:DWORD,color:DWORD
plutovg_canvas_get_path     PROTO STDCALL canvas:DWORD
plutovg_canvas_get_reference_count PROTO STDCALL canvas:DWORD
plutovg_canvas_get_surface  PROTO STDCALL canvas:DWORD
plutovg_canvas_glyph_metrics PROTO STDCALL canvas:DWORD,codepoint:DWORD,advance_width:REAL4,left_side_bearing:REAL4,extents:DWORD
plutovg_canvas_line_to      PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4
plutovg_canvas_map          PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,xx:REAL4,yy:REAL4
plutovg_canvas_map_point    PROTO STDCALL canvas:DWORD,src:DWORD,dst:DWORD
plutovg_canvas_map_rect     PROTO STDCALL canvas:DWORD,src:DWORD,dst:DWORD
plutovg_canvas_move_to      PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4
plutovg_canvas_new_path     PROTO STDCALL canvas:DWORD
plutovg_canvas_paint        PROTO STDCALL canvas:DWORD
plutovg_canvas_quad_to      PROTO STDCALL canvas:DWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4
plutovg_canvas_rect         PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_reference    PROTO STDCALL canvas:DWORD
plutovg_canvas_reset_matrix PROTO STDCALL canvas:DWORD
plutovg_canvas_restore      PROTO STDCALL canvas:DWORD
plutovg_canvas_rotate       PROTO STDCALL canvas:DWORD,angle:REAL4
plutovg_canvas_round_rect   PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4,rx:REAL4,ry:REAL4
plutovg_canvas_save         PROTO STDCALL canvas:DWORD
plutovg_canvas_scale        PROTO STDCALL canvas:DWORD,sx:REAL4,sy:REAL4
plutovg_canvas_set_color    PROTO STDCALL canvas:DWORD,color:DWORD
plutovg_canvas_set_dash     PROTO STDCALL canvas:DWORD,startoffset:DWORD,dashes:DWORD,ndashes:DWORD
plutovg_canvas_set_dash_array PROTO STDCALL canvas:DWORD,dashes:REAL4,ndashes:DWORD
plutovg_canvas_set_dash_offset PROTO STDCALL canvas:DWORD,startoffset:DWORD
plutovg_canvas_set_fill_rule PROTO STDCALL canvas:DWORD,winding:DWORD
plutovg_canvas_set_font     PROTO STDCALL canvas:DWORD,face:DWORD,fsize:REAL4
plutovg_canvas_set_font_face PROTO STDCALL canvas:DWORD,face:DWORD
plutovg_canvas_set_font_size PROTO STDCALL canvas:DWORD,fsize:REAL4
plutovg_canvas_set_line_cap PROTO STDCALL canvas:DWORD,line_cap:DWORD
plutovg_canvas_set_line_join PROTO STDCALL canvas:DWORD,line_join:DWORD
plutovg_canvas_set_line_width PROTO STDCALL canvas:DWORD,line_width:REAL4
plutovg_canvas_set_linear_gradient PROTO STDCALL canvas:DWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,spread:DWORD,stops:DWORD,nstops:DWORD,matrix:DWORD
plutovg_canvas_set_matrix   PROTO STDCALL canvas:DWORD,matrix:DWORD
plutovg_canvas_set_miter_limit PROTO STDCALL canvas:DWORD,miter_limit:REAL4
plutovg_canvas_set_opacity  PROTO STDCALL canvas:DWORD,opacity:REAL4
plutovg_canvas_set_operator PROTO STDCALL canvas:DWORD,op:DWORD
plutovg_canvas_set_paint    PROTO STDCALL canvas:DWORD,paint:DWORD
plutovg_canvas_set_radial_gradient PROTO STDCALL canvas:DWORD,cxx:REAL4,cyy:REAL4,cr:REAL4,fx:REAL4,fy:REAL4,fr:REAL4,spread:DWORD,stops:DWORD,nstops:DWORD,matrix:DWORD
plutovg_canvas_set_rgb      PROTO STDCALL canvas:DWORD,r:REAL4,g:REAL4,b:REAL4
plutovg_canvas_set_rgba     PROTO STDCALL canvas:DWORD,r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_canvas_set_texture  PROTO STDCALL canvas:DWORD,surface:DWORD,dwtype:DWORD,opacity:REAL4,matrix:DWORD
plutovg_canvas_shear        PROTO STDCALL canvas:DWORD,shx:REAL4,shy:REAL4
plutovg_canvas_stroke       PROTO STDCALL canvas:DWORD
plutovg_canvas_stroke_extents PROTO STDCALL canvas:DWORD,:DWORD
plutovg_canvas_stroke_path  PROTO STDCALL canvas:DWORD,path:DWORD
plutovg_canvas_stroke_preserve PROTO STDCALL canvas:DWORD
plutovg_canvas_stroke_rect  PROTO STDCALL canvas:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_canvas_stroke_text  PROTO STDCALL canvas:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD,x:REAL4,y:REAL4
plutovg_canvas_text_extents PROTO STDCALL canvas:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD,extents:DWORD
plutovg_canvas_transform    PROTO STDCALL canvas:DWORD,matrix:DWORD
plutovg_canvas_translate    PROTO STDCALL canvas:DWORD,tx:REAL4,ty:REAL4
plutovg_color_init_argb32   PROTO STDCALL color:DWORD,value:DWORD
plutovg_color_init_rgb8     PROTO STDCALL color:DWORD,r:DWORD,g:DWORD,b:DWORD
plutovg_color_init_rgb      PROTO STDCALL color:DWORD,r:REAL4,g:REAL4,b:REAL4
plutovg_color_init_rgba32   PROTO STDCALL color:DWORD,value:DWORD
plutovg_color_init_rgba8    PROTO STDCALL color:DWORD,r:DWORD,g:DWORD,b:DWORD,a:DWORD
plutovg_color_init_rgba     PROTO STDCALL color:DWORD,r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_color_parse         PROTO STDCALL color:DWORD,data:DWORD,dwlength:DWORD
plutovg_color_to_argb32     PROTO STDCALL color:DWORD
plutovg_color_to_rgba32     PROTO STDCALL color:DWORD
plutovg_convert_argb_to_rgba PROTO STDCALL dst:DWORD,src:DWORD,dwwidth:DWORD,dwheight:DWORD,stride:DWORD
plutovg_convert_rgba_to_argb PROTO STDCALL dst:DWORD,src:DWORD,dwwidth:DWORD,dwheight:DWORD,stride:DWORD
plutovg_font_face_destroy   PROTO STDCALL face:DWORD
plutovg_font_face_get_glyph_metrics PROTO STDCALL face:DWORD,fsize:REAL4,codepoint:DWORD,advance_width:REAL4,left_side_bearing:REAL4,extents:DWORD
plutovg_font_face_get_glyph_path PROTO STDCALL face:DWORD,fsize:REAL4,x:REAL4,y:REAL4,codepoint:DWORD,path:DWORD
plutovg_font_face_get_metrics PROTO STDCALL face:DWORD,fsize:REAL4,ascent:REAL4,descent:REAL4,line_gap:REAL4,extents:DWORD
plutovg_font_face_get_reference_count PROTO STDCALL face:DWORD
plutovg_font_face_load_from_data PROTO STDCALL data:DWORD,dwlength:DWORD,ttcindex:DWORD,destroy_func:DWORD,closure:DWORD
plutovg_font_face_load_from_file PROTO STDCALL filename:DWORD,ttcindex:DWORD
plutovg_font_face_reference PROTO STDCALL face:DWORD
plutovg_font_face_text_extents PROTO STDCALL face:DWORD,fsize:REAL4,text:DWORD,dwlength:DWORD,encoding:DWORD,extents:DWORD
plutovg_font_face_traverse_glyph_path PROTO STDCALL face:DWORD,fsize:REAL4,x:REAL4,y:REAL4,codepoint:DWORD,traverse_func:DWORD,closure:DWORD
plutovg_matrix_init         PROTO STDCALL matrix:DWORD,a:REAL4,b:REAL4,c_:REAL4,d:REAL4,e:REAL4,f:REAL4
plutovg_matrix_init_identity PROTO STDCALL matrix:DWORD
plutovg_matrix_init_rotate  PROTO STDCALL matrix:DWORD,angle:REAL4
plutovg_matrix_init_scale   PROTO STDCALL matrix:DWORD,sx:REAL4,sy:REAL4
plutovg_matrix_init_shear   PROTO STDCALL matrix:DWORD,shx:REAL4,shy:REAL4
plutovg_matrix_init_translate PROTO STDCALL matrix:DWORD,tx:REAL4,ty:REAL4
plutovg_matrix_invert       PROTO STDCALL matrix:DWORD,inverse:DWORD
plutovg_matrix_map          PROTO STDCALL matrix:DWORD,x:REAL4,y:REAL4,xx:REAL4,yy:REAL4
plutovg_matrix_map_point    PROTO STDCALL matrix:DWORD,src:DWORD,dst:DWORD
plutovg_matrix_map_points   PROTO STDCALL matrix:DWORD,src:DWORD,dst:DWORD,count:DWORD
plutovg_matrix_map_rect     PROTO STDCALL matrix:DWORD,src:DWORD,dst:DWORD
plutovg_matrix_multiply     PROTO STDCALL matrix:DWORD,left:DWORD,right:DWORD
plutovg_matrix_parse        PROTO STDCALL matrix:DWORD,data:DWORD,datalength:DWORD
plutovg_matrix_rotate       PROTO STDCALL matrix:DWORD,angle:REAL4
plutovg_matrix_scale        PROTO STDCALL matrix:DWORD,sx:REAL4,sy:REAL4
plutovg_matrix_shear        PROTO STDCALL matrix:DWORD,shx:DWORD,shy:DWORD
plutovg_matrix_translate    PROTO STDCALL matrix:DWORD,tx:REAL4,ty:REAL4
plutovg_memfill32           PROTO STDCALL :DWORD,:DWORD,:DWORD
plutovg_paint_create_color  PROTO STDCALL color:DWORD
plutovg_paint_create_linear_gradient PROTO STDCALL x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,spread:DWORD,stops:DWORD,nstops:DWORD,matrix:DWORD
plutovg_paint_create_radial_gradient PROTO STDCALL cxx:REAL4,cyy:REAL4,cr:REAL4,fx:REAL4,fy:REAL4,fr:REAL4,spread:DWORD,stops:DWORD,nstops:DWORD,matrix:DWORD
plutovg_paint_create_rgb    PROTO STDCALL r:REAL4,g:REAL4,b:REAL4
plutovg_paint_create_rgba   PROTO STDCALL r:REAL4,g:REAL4,b:REAL4,a:REAL4
plutovg_paint_create_texture PROTO STDCALL surface:DWORD,dwtype:DWORD,opacity:REAL4,matrix:DWORD
plutovg_paint_destroy       PROTO STDCALL paint:DWORD
plutovg_paint_get_reference_count PROTO STDCALL paint:DWORD
plutovg_paint_reference     PROTO STDCALL paint:DWORD
plutovg_path_add_arc        PROTO STDCALL path:DWORD,cxx:REAL4,cyy:REAL4,r:REAL4,a0:REAL4,a1:REAL4,ccw:REAL4
plutovg_path_add_circle     PROTO STDCALL path:DWORD,cxx:REAL4,cyy:REAL4,r:REAL4
plutovg_path_add_ellipse    PROTO STDCALL path:DWORD,cxx:REAL4,cyy:REAL4,rx:REAL4,ry:REAL4
plutovg_path_add_path       PROTO STDCALL path:DWORD,source:DWORD,matrix:DWORD
plutovg_path_add_rect       PROTO STDCALL path:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4
plutovg_path_add_round_rect PROTO STDCALL path:DWORD,x:REAL4,y:REAL4,w:REAL4,h:REAL4,rx:REAL4,ry:REAL4
plutovg_path_arc_to         PROTO STDCALL path:DWORD,rx:REAL4,ry:REAL4,angle:REAL4,large_arc_flag:DWORD,sweep_flag:DWORD,x:REAL4,y:REAL4
plutovg_path_clone          PROTO STDCALL path:DWORD
plutovg_path_clone_dashed   PROTO STDCALL path:DWORD,startoffset:DWORD,dashes:DWORD,ndashes:DWORD
plutovg_path_clone_flatten  PROTO STDCALL path:DWORD
plutovg_path_close          PROTO STDCALL path:DWORD
plutovg_path_create         PROTO STDCALL 
plutovg_path_cubic_to       PROTO STDCALL path:DWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4,x3:REAL4,y3:REAL4
plutovg_path_destroy        PROTO STDCALL path:DWORD
plutovg_path_extents        PROTO STDCALL path:DWORD,extents:DWORD,tight:DWORD
plutovg_path_get_current_point PROTO STDCALL path:DWORD,x:REAL4,y:REAL4
plutovg_path_get_elements   PROTO STDCALL path:DWORD,elements:DWORD
plutovg_path_get_reference_count PROTO STDCALL path:DWORD
plutovg_path_iterator_has_next PROTO STDCALL it:DWORD
plutovg_path_iterator_init  PROTO STDCALL it:DWORD,path:DWORD
plutovg_path_iterator_next  PROTO STDCALL it:DWORD,points:DWORD
plutovg_path_length         PROTO STDCALL path:DWORD
plutovg_path_line_to        PROTO STDCALL path:DWORD,x:REAL4,y:REAL4
plutovg_path_move_to        PROTO STDCALL path:DWORD,x:REAL4,y:REAL4
plutovg_path_parse          PROTO STDCALL path:DWORD,data:DWORD,dwlength:DWORD
plutovg_path_quad_to        PROTO STDCALL path:DWORD,x1:REAL4,y1:REAL4,x2:REAL4,y2:REAL4
plutovg_path_reference      PROTO STDCALL path:DWORD
plutovg_path_reserve        PROTO STDCALL path:DWORD,count:DWORD
plutovg_path_reset          PROTO STDCALL path:DWORD
plutovg_path_transform      PROTO STDCALL path:DWORD,matrix:DWORD
plutovg_path_traverse       PROTO STDCALL path:DWORD,traverse_func:DWORD,closure:DWORD
plutovg_path_traverse_dashed PROTO STDCALL path:DWORD,startoffset:DWORD,dashes:DWORD,ndashes:DWORD,traverse_func:DWORD,closure:DWORD
plutovg_path_traverse_flatten PROTO STDCALL path:DWORD,traverse_func:DWORD,closure:DWORD
plutovg_rasterize           PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
plutovg_span_buffer_copy    PROTO STDCALL :DWORD,:DWORD
plutovg_span_buffer_destroy PROTO STDCALL :DWORD
plutovg_span_buffer_extents PROTO STDCALL :DWORD,:DWORD
plutovg_span_buffer_init    PROTO STDCALL :DWORD
plutovg_span_buffer_init_rect PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
plutovg_span_buffer_intersect PROTO STDCALL :DWORD,:DWORD,:DWORD
plutovg_span_buffer_reset   PROTO STDCALL :DWORD
plutovg_surface_clear       PROTO STDCALL surface:DWORD,color:DWORD
plutovg_surface_create      PROTO STDCALL dwwidth:DWORD,dwheight:DWORD
plutovg_surface_create_for_data PROTO STDCALL data:DWORD,dwwidth:DWORD,dwheight:DWORD,stride:DWORD
plutovg_surface_destroy     PROTO STDCALL surface:DWORD
plutovg_surface_get_data    PROTO STDCALL surface:DWORD
plutovg_surface_get_height  PROTO STDCALL surface:DWORD
plutovg_surface_get_reference_count PROTO STDCALL surface:DWORD
plutovg_surface_get_stride  PROTO STDCALL surface:DWORD
plutovg_surface_get_width   PROTO STDCALL surface:DWORD
plutovg_surface_load_from_image_base64 PROTO STDCALL data:DWORD,dwlength:DWORD
plutovg_surface_load_from_image_data PROTO STDCALL data:DWORD,dwlength:DWORD
plutovg_surface_load_from_image_file PROTO STDCALL filename:DWORD
plutovg_surface_reference   PROTO STDCALL surface:DWORD
plutovg_surface_write_to_jpg PROTO STDCALL surface:DWORD,filename:DWORD,quality:DWORD
plutovg_surface_write_to_jpg_stream PROTO STDCALL surface:DWORD,write_func:DWORD,closure:DWORD,quality:DWORD
plutovg_surface_write_to_png PROTO STDCALL surface:DWORD,filename:DWORD
plutovg_surface_write_to_png_stream PROTO STDCALL surface:DWORD,write_func:DWORD,closure:DWORD
plutovg_text_iterator_has_next PROTO STDCALL it:DWORD
plutovg_text_iterator_init  PROTO STDCALL it:DWORD,text:DWORD,dwlength:DWORD,encoding:DWORD
plutovg_text_iterator_next  PROTO STDCALL it:DWORD
plutovg_version             PROTO STDCALL 
plutovg_version_string      PROTO STDCALL 

plutovg_path_command        TYPEDEF DWORD
plutovg_path_command_t      TYPEDEF DWORD
plutovg_text_encoding       TYPEDEF DWORD
plutovg_text_encoding_t     TYPEDEF DWORD
plutovg_path                TYPEDEF DWORD
plutovg_path_t              TYPEDEF DWORD
plutovg_codepoint           TYPEDEF DWORD
plutovg_codepoint_t         TYPEDEF DWORD
plutovg_font_face           TYPEDEF DWORD 
plutovg_font_face_t         TYPEDEF DWORD
plutovg_surface             TYPEDEF DWORD
plutovg_surface_t           TYPEDEF DWORD
plutovg_paint               TYPEDEF DWORD
plutovg_paint_t             TYPEDEF DWORD
plutovg_canvas              TYPEDEF DWORD
plutovg_canvas_t            TYPEDEF DWORD

plutovg_point STRUCT
    x REAL4 ?
    y REAL4 ?
plutovg_point ENDS
plutovg_point_t TYPEDEF PTR plutovg_point

plutovg_rect STRUCT
    x REAL4 ?
    y REAL4 ?
    w REAL4 ?
    h REAL4 ?
plutovg_rect ENDS
plutovg_rect_t TYPEDEF PTR plutovg_rect

plutovg_matrix STRUCT
    a REAL4 ?
    b REAL4 ?
    c_ REAL4 ?
    d REAL4 ?
    e REAL4 ?
    f REAL4 ?
plutovg_matrix ENDS
plutovg_matrix_t TYPEDEF PTR plutovg_matrix

plutovg_color STRUCT
    r REAL4 ? ; Red component (0 to 1).
    g REAL4 ? ; Green component (0 to 1).
    b REAL4 ? ; Blue component (0 to 1).
    a REAL4 ? ; Alpha (opacity) component (0 to 1)
plutovg_color ENDS
plutovg_color_t TYPEDEF PTR plutovg_color

plutovg_gradient_stop_t STRUCT
    foffset             REAL4 ?
    color               plutovg_color_t ?
plutovg_gradient_stop_t ENDS

pathheader      STRUCT
    command     plutovg_path_command_t ?
    dwlength    DWORD ?
pathheader      ENDS

plutovg_path_element UNION
    header           pathheader <>
    point            plutovg_point_t ?
plutovg_path_element ENDS
plutovg_path_element_t TYPEDEF PTR plutovg_path_element

plutovg_path_iterator STRUCT
    elements          plutovg_path_element_t ?
    dwSize            DWORD ?
    dwIndex           DWORD ?
plutovg_path_iterator ENDS
plutovg_path_iterator_t TYPEDEF PTR plutovg_path_iterator

plutovg_text_iterator STRUCT
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










