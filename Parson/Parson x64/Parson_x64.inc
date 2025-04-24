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

; Parson_x64.inc converted from Parson source for assembler by fearless 2024
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

json_array                  PROTO value:QWORD
json_array_append_boolean   PROTO array:QWORD,boolean:QWORD
json_array_append_null      PROTO array:QWORD
json_array_append_number    PROTO array:QWORD,number:QWORD
json_array_append_string    PROTO array:QWORD,string:QWORD
json_array_append_string_with_len PROTO array:QWORD,string:QWORD,len:QWORD
json_array_append_value     PROTO array:QWORD,value:QWORD
json_array_clear            PROTO array:QWORD
json_array_get_array        PROTO array:QWORD,index:QWORD
json_array_get_boolean      PROTO array:QWORD,index:QWORD
json_array_get_count        PROTO array:QWORD
json_array_get_number       PROTO array:QWORD,index:QWORD
json_array_get_object       PROTO array:QWORD,index:QWORD
json_array_get_string       PROTO array:QWORD,index:QWORD
json_array_get_string_len   PROTO array:QWORD,index:QWORD
json_array_get_value        PROTO array:QWORD,index:QWORD
json_array_get_wrapping_value PROTO array:QWORD
json_array_remove           PROTO array:QWORD,i:QWORD
json_array_replace_boolean  PROTO array:QWORD,i:QWORD,boolean:QWORD
json_array_replace_null     PROTO array:QWORD,i:QWORD
json_array_replace_number   PROTO array:QWORD,i:QWORD,number:QWORD
json_array_replace_string   PROTO array:QWORD,i:QWORD,string:QWORD
json_array_replace_string_with_len PROTO array:QWORD,i:QWORD,string:QWORD,len:QWORD
json_array_replace_value    PROTO array:QWORD,i:QWORD,value:QWORD
json_boolean                PROTO value:QWORD
json_free_serialized_string PROTO string:QWORD
json_number                 PROTO value:QWORD
json_object                 PROTO value:QWORD
json_object_clear           PROTO object:QWORD
json_object_dotget_array    PROTO object:QWORD,name:QWORD
json_object_dotget_boolean  PROTO object:QWORD,name:QWORD
json_object_dotget_number   PROTO object:QWORD,name:QWORD
json_object_dotget_object   PROTO object:QWORD,name:QWORD
json_object_dotget_string   PROTO object:QWORD,name:QWORD
json_object_dotget_string_len PROTO object:QWORD,name:QWORD
json_object_dotget_value    PROTO object:QWORD,name:QWORD
json_object_dothas_value    PROTO object:QWORD,name:QWORD
json_object_dothas_value_of_type PROTO object:QWORD,name:QWORD,type:QWORD
json_object_dotremove       PROTO object:QWORD,key:QWORD
json_object_dotset_boolean  PROTO object:QWORD,name:QWORD,boolean:QWORD
json_object_dotset_null     PROTO object:QWORD,name:QWORD
json_object_dotset_number   PROTO object:QWORD,name:QWORD,number:QWORD
json_object_dotset_string   PROTO object:QWORD,name:QWORD,string:QWORD
json_object_dotset_string_with_len PROTO object:QWORD,name:QWORD,string:QWORD,len:QWORD
json_object_dotset_value    PROTO object:QWORD,name:QWORD,value:QWORD
json_object_get_array       PROTO object:QWORD,name:QWORD
json_object_get_boolean     PROTO object:QWORD,name:QWORD
json_object_get_count       PROTO object:QWORD
json_object_get_name        PROTO object:QWORD,index:QWORD
json_object_get_number      PROTO object:QWORD,name:QWORD
json_object_get_object      PROTO object:QWORD,name:QWORD
json_object_get_string      PROTO object:QWORD,name:QWORD
json_object_get_string_len  PROTO object:QWORD,name:QWORD
json_object_get_value       PROTO object:QWORD,name:QWORD
json_object_get_value_at    PROTO object:QWORD,index:QWORD
json_object_get_wrapping_value PROTO object:QWORD
json_object_has_value       PROTO object:QWORD,name:QWORD
json_object_has_value_of_type PROTO object:QWORD,name:QWORD,type:QWORD
json_object_remove          PROTO object:QWORD,name:QWORD
json_object_set_boolean     PROTO object:QWORD,name:QWORD,boolean:QWORD
json_object_set_null        PROTO object:QWORD,name:QWORD
json_object_set_number      PROTO object:QWORD,name:QWORD,number:QWORD
json_object_set_string      PROTO object:QWORD,name:QWORD,string:QWORD
json_object_set_string_with_len PROTO object:QWORD,name:QWORD,string:QWORD,len:QWORD
json_object_set_value       PROTO object:QWORD,name:QWORD,value:QWORD
json_parse_file             PROTO filename:QWORD
json_parse_file_with_comments PROTO filename:QWORD
json_parse_string           PROTO string:QWORD
json_parse_string_with_comments PROTO string:QWORD
json_serialization_size     PROTO value:QWORD
json_serialization_size_pretty PROTO value:QWORD
json_serialize_to_buffer    PROTO value:QWORD,buf:QWORD,buf_size_in_bytes:QWORD
json_serialize_to_buffer_pretty PROTO value:QWORD,buf:QWORD,buf_size_in_bytes:QWORD
json_serialize_to_file      PROTO value:QWORD,filename:QWORD
json_serialize_to_file_pretty PROTO value:QWORD,filename:QWORD
json_serialize_to_string    PROTO value:QWORD
json_serialize_to_string_pretty PROTO value:QWORD
json_set_allocation_functions PROTO malloc_fun:QWORD,free_fun:QWORD
json_set_escape_slashes     PROTO escape_slashes:QWORD
json_set_float_serialization_format PROTO format:QWORD
json_set_number_serialization_function PROTO fun:QWORD
json_string                 PROTO value:QWORD
json_string_len             PROTO value:QWORD
json_type                   PROTO value:QWORD
json_validate               PROTO schema:QWORD,value:QWORD
json_value_deep_copy        PROTO value:QWORD
json_value_equals           PROTO a:QWORD,b:QWORD
json_value_free             PROTO value:QWORD
json_value_get_array        PROTO value:QWORD
json_value_get_boolean      PROTO value:QWORD
json_value_get_number       PROTO value:QWORD
json_value_get_object       PROTO value:QWORD
json_value_get_parent       PROTO value:QWORD
json_value_get_string       PROTO value:QWORD
json_value_get_string_len   PROTO value:QWORD
json_value_get_type         PROTO value:QWORD
json_value_init_array       PROTO 
json_value_init_boolean     PROTO boolean:QWORD
json_value_init_null        PROTO 
json_value_init_number      PROTO number:QWORD
json_value_init_object      PROTO 
json_value_init_string      PROTO string:QWORD
json_value_init_string_with_len PROTO string:QWORD,length:QWORD

JSON_Object         TYPEDEF PTR json_object_t
JSON_Array          TYPEDEF PTR json_array_t
JSON_Value          TYPEDEF PTR json_value_t
JSON_Value_Type     TYPEDEF QWORD
JSON_Status         TYPEDEF QWORD
parson_bool_t       TYPEDEF QWORD

JSON_String         STRUCT 8
    chars           QWORD ? ; char *
    length          QWORD ? ; size_t 
JSON_String         ENDS

; Type definitions
JSON_Value_Value    UNION 8
    string          JSON_String <>;
    number          REAL8 ?
    object          JSON_Object ? ; *
    array           JSON_Array ? ; *
    boolean         DWORD ? ; int          
    null            DWORD ? ; int          
JSON_Value_Value    ENDS

json_value_t        STRUCT 8
    parent          JSON_Value ? ; *
    type_           JSON_Value_Type ? ;
    value           JSON_Value_Value <> ;
json_value_t        ENDS

json_object_t       STRUCT 8
    wrapping_value  JSON_Value ? ; *
    cells           QWORD ? ; size_t *
    hashes          DWORD ? ; unsigned long *
    names           QWORD ? ; char **
    values          JSON_Value ? ; **
    cell_ixs        QWORD ? ; size_t *
    count           QWORD ? ; size_t
    item_capacity   QWORD ? ; size_t
    cell_capacity   QWORD ? ; size_t
json_object_t       ENDS

json_array_t        STRUCT 8
    wrapping_value  JSON_Value ? ; *
    items           JSON_Value ? ; **
    count           QWORD ? ; size_t
    capacity        QWORD ? ; size_t
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