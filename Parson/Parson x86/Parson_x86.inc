; /*
;  SPDX-License-Identifier: MIT
; 
;  Parson 1.5.3 (https://github.com/kgabis/parson)
;  Copyright (c) 2012 - 2023 Krzysztof Gabis
; 
;  Permission is hereby granted, free of charge, to any person obtaining a copy
;  of this software and associated documentation files (the "Software"), to deal
;  in the Software without restriction, including without limitation the rights
;  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;  copies of the Software, and to permit persons to whom the Software is
;  furnished to do so, subject to the following conditions:
; 
;  The above copyright notice and this permission notice shall be included in
;  all copies or substantial portions of the Software.
; 
;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;  THE SOFTWARE.
; */

; Parson_x86.inc converted from Parson source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

json_array                  PROTO STDCALL value:DWORD
json_array_append_boolean   PROTO STDCALL array:DWORD,boolean:DWORD
json_array_append_null      PROTO STDCALL array:DWORD
json_array_append_number    PROTO STDCALL array:DWORD,number:QWORD
json_array_append_string    PROTO STDCALL array:DWORD,string:DWORD
json_array_append_string_with_len PROTO STDCALL array:DWORD,string:DWORD,len:DWORD
json_array_append_value     PROTO STDCALL array:DWORD,value:DWORD
json_array_clear            PROTO STDCALL array:DWORD
json_array_get_array        PROTO STDCALL array:DWORD,index:DWORD
json_array_get_boolean      PROTO STDCALL array:DWORD,index:DWORD
json_array_get_count        PROTO STDCALL array:DWORD
json_array_get_number       PROTO STDCALL array:DWORD,index:DWORD
json_array_get_object       PROTO STDCALL array:DWORD,index:DWORD
json_array_get_string       PROTO STDCALL array:DWORD,index:DWORD
json_array_get_string_len   PROTO STDCALL array:DWORD,index:DWORD
json_array_get_value        PROTO STDCALL array:DWORD,index:DWORD
json_array_get_wrapping_value PROTO STDCALL array:DWORD
json_array_remove           PROTO STDCALL array:DWORD,i:DWORD
json_array_replace_boolean  PROTO STDCALL array:DWORD,i:DWORD,boolean:DWORD
json_array_replace_null     PROTO STDCALL array:DWORD,i:DWORD
json_array_replace_number   PROTO STDCALL array:DWORD,i:DWORD,number:QWORD
json_array_replace_string   PROTO STDCALL array:DWORD,i:DWORD,string:DWORD
json_array_replace_string_with_len PROTO STDCALL array:DWORD,i:DWORD,string:DWORD,len:DWORD
json_array_replace_value    PROTO STDCALL array:DWORD,i:DWORD,value:DWORD
json_boolean                PROTO STDCALL value:DWORD
json_free_serialized_string PROTO STDCALL string:DWORD
json_number                 PROTO STDCALL value:DWORD
json_object                 PROTO STDCALL value:DWORD
json_object_clear           PROTO STDCALL object:DWORD
json_object_dotget_array    PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_boolean  PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_number   PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_object   PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_string   PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_string_len PROTO STDCALL object:DWORD,name:DWORD
json_object_dotget_value    PROTO STDCALL object:DWORD,name:DWORD
json_object_dothas_value    PROTO STDCALL object:DWORD,name:DWORD
json_object_dothas_value_of_type PROTO STDCALL object:DWORD,name:DWORD,type:DWORD
json_object_dotremove       PROTO STDCALL object:DWORD,key:DWORD
json_object_dotset_boolean  PROTO STDCALL object:DWORD,name:DWORD,boolean:DWORD
json_object_dotset_null     PROTO STDCALL object:DWORD,name:DWORD
json_object_dotset_number   PROTO STDCALL object:DWORD,name:DWORD,number:QWORD
json_object_dotset_string   PROTO STDCALL object:DWORD,name:DWORD,string:DWORD
json_object_dotset_string_with_len PROTO STDCALL object:DWORD,name:DWORD,string:DWORD,len:DWORD
json_object_dotset_value    PROTO STDCALL object:DWORD,name:DWORD,value:DWORD
json_object_get_array       PROTO STDCALL object:DWORD,name:DWORD
json_object_get_boolean     PROTO STDCALL object:DWORD,name:DWORD
json_object_get_count       PROTO STDCALL object:DWORD
json_object_get_name        PROTO STDCALL object:DWORD,index:DWORD
json_object_get_number      PROTO STDCALL object:DWORD,name:DWORD
json_object_get_object      PROTO STDCALL object:DWORD,name:DWORD
json_object_get_string      PROTO STDCALL object:DWORD,name:DWORD
json_object_get_string_len  PROTO STDCALL object:DWORD,name:DWORD
json_object_get_value       PROTO STDCALL object:DWORD,name:DWORD
json_object_get_value_at    PROTO STDCALL object:DWORD,index:DWORD
json_object_get_wrapping_value PROTO STDCALL object:DWORD
json_object_has_value       PROTO STDCALL object:DWORD,name:DWORD
json_object_has_value_of_type PROTO STDCALL object:DWORD,name:DWORD,type:DWORD
json_object_remove          PROTO STDCALL object:DWORD,name:DWORD
json_object_set_boolean     PROTO STDCALL object:DWORD,name:DWORD,boolean:DWORD
json_object_set_null        PROTO STDCALL object:DWORD,name:DWORD
json_object_set_number      PROTO STDCALL object:DWORD,name:DWORD,number:QWORD
json_object_set_string      PROTO STDCALL object:DWORD,name:DWORD,string:DWORD
json_object_set_string_with_len PROTO STDCALL object:DWORD,name:DWORD,string:DWORD,len:DWORD
json_object_set_value       PROTO STDCALL object:DWORD,name:DWORD,value:DWORD
json_parse_file             PROTO STDCALL filename:DWORD
json_parse_file_with_comments PROTO STDCALL filename:DWORD
json_parse_string           PROTO STDCALL string:DWORD
json_parse_string_with_comments PROTO STDCALL string:DWORD
json_serialization_size     PROTO STDCALL value:DWORD
json_serialization_size_pretty PROTO STDCALL value:DWORD
json_serialize_to_buffer    PROTO STDCALL value:DWORD,buf:DWORD,buf_size_in_bytes:DWORD
json_serialize_to_buffer_pretty PROTO STDCALL value:DWORD,buf:DWORD,buf_size_in_bytes:DWORD
json_serialize_to_file      PROTO STDCALL value:DWORD,filename:DWORD
json_serialize_to_file_pretty PROTO STDCALL value:DWORD,filename:DWORD
json_serialize_to_string    PROTO STDCALL value:DWORD
json_serialize_to_string_pretty PROTO STDCALL value:DWORD
json_set_allocation_functions PROTO STDCALL malloc_fun:DWORD,free_fun:DWORD
json_set_escape_slashes     PROTO STDCALL escape_slashes:DWORD
json_set_float_serialization_format PROTO STDCALL format:DWORD
json_set_number_serialization_function PROTO STDCALL fun:DWORD
json_string                 PROTO STDCALL value:DWORD
json_string_len             PROTO STDCALL value:DWORD
json_type                   PROTO STDCALL value:DWORD
json_validate               PROTO STDCALL schema:DWORD,value:DWORD
json_value_deep_copy        PROTO STDCALL value:DWORD
json_value_equals           PROTO STDCALL a:DWORD,b:DWORD
json_value_free             PROTO STDCALL value:DWORD
json_value_get_array        PROTO STDCALL value:DWORD
json_value_get_boolean      PROTO STDCALL value:DWORD
json_value_get_number       PROTO STDCALL value:DWORD
json_value_get_object       PROTO STDCALL value:DWORD
json_value_get_parent       PROTO STDCALL value:DWORD
json_value_get_string       PROTO STDCALL value:DWORD
json_value_get_string_len   PROTO STDCALL value:DWORD
json_value_get_type         PROTO STDCALL value:DWORD
json_value_init_array       PROTO STDCALL 
json_value_init_boolean     PROTO STDCALL boolean:DWORD
json_value_init_null        PROTO STDCALL 
json_value_init_number      PROTO STDCALL number:QWORD
json_value_init_object      PROTO STDCALL 
json_value_init_string      PROTO STDCALL string:DWORD
json_value_init_string_with_len PROTO STDCALL string:DWORD,length:DWORD

JSON_Object         TYPEDEF PTR json_object_t
JSON_Array          TYPEDEF PTR json_array_t
JSON_Value          TYPEDEF PTR json_value_t
JSON_Value_Type     TYPEDEF DWORD
JSON_Status         TYPEDEF DWORD
parson_bool_t       TYPEDEF DWORD

JSON_String         STRUCT
    chars           DWORD ? ; char *
    length          DWORD ? ; size_t 
JSON_String         ENDS

; Type definitions
JSON_Value_Value    UNION
    string          JSON_String <>;
    number          REAL8 ?
    object          JSON_Object ? ; *
    array           JSON_Array ? ; *
    boolean         DWORD ? ; int          
    null            DWORD ? ; int          
JSON_Value_Value    ENDS

json_value_t        STRUCT
    parent          JSON_Value ? ; *
    type_           JSON_Value_Type ? ;
    value           JSON_Value_Value <> ;
json_value_t        ENDS

json_object_t       STRUCT
    wrapping_value  JSON_Value ? ; *
    cells           DWORD ? ; size_t *
    hashes          DWORD ? ; unsigned long *
    names           DWORD ? ; char **
    values          JSON_Value ? ; **
    cell_ixs        DWORD ? ; size_t *
    count           DWORD ? ; size_t
    item_capacity   DWORD ? ; size_t
    cell_capacity   DWORD ? ; size_t
json_object_t       ENDS

json_array_t        STRUCT
    wrapping_value  JSON_Value ? ; *
    items           JSON_Value ? ; **
    count           DWORD ? ; size_t
    capacity        DWORD ? ; size_t
json_array_t        ENDS

.CONST

PARSON_VERSION_MAJOR EQU 1
PARSON_VERSION_MINOR EQU 5
PARSON_VERSION_PATCH EQU 3

PARSON_VERSION_STRING TEXTEQU <"1.5.3">

; json_value_type
JSONError           EQU -1
JSONNull            EQU 1
JSONString          EQU 2
JSONNumber          EQU 3
JSONObject          EQU 4
JSONArray           EQU 5
JSONBoolean         EQU 6

; json_result_t
JSONSuccess         EQU 0
JSONFailure         EQU -1

PARSON_TRUE         EQU 1
PARSON_FALSE        EQU 0