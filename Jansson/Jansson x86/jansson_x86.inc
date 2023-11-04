;
; Copyright (c) 2009-2016 Petri Lehtinen <petri@digip.org>
;
; Jansson is free software; you can redistribute it and/or modify
; it under the terms of the MIT license.
;

; jansson_x86.inc converted from jansson source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

hashtable_clear PROTO C hashtable:DWORD
hashtable_close PROTO C hashtable:DWORD
hashtable_del PROTO C hashtable:DWORD, key:DWORD, key_len:DWORD
hashtable_get PROTO C hashtable:DWORD, key:DWORD, key_len:DWORD
hashtable_init PROTO C hashtable:DWORD
hashtable_iter PROTO C hashtable:DWORD
hashtable_iter_at PROTO C hashtable:DWORD, key:DWORD, key_len:DWORD
hashtable_iter_key PROTO C iter:DWORD
hashtable_iter_key_len PROTO C iter:DWORD
hashtable_iter_next PROTO C hashtable:DWORD, iter:DWORD
hashtable_iter_set PROTO C iter:DWORD, value:DWORD
hashtable_iter_value PROTO C iter:DWORD
hashtable_seed PROTO C :VARARG
hashtable_set PROTO C hashtable:DWORD, key:DWORD, key_len:DWORD, value:DWORD
jansson_version_cmp PROTO C major:DWORD, minor:DWORD, micro:DWORD
jansson_version_str PROTO C 
json_array PROTO C 
json_array_append_new PROTO C array:DWORD, value:DWORD
json_array_clear PROTO C array:DWORD
json_array_extend PROTO C array:DWORD, other:DWORD
json_array_get PROTO C array:DWORD, index:DWORD
json_array_insert_new PROTO C array:DWORD, index:DWORD, value:DWORD
json_array_remove PROTO C array:DWORD, index:DWORD
json_array_set_new PROTO C array:DWORD, index:DWORD, value:DWORD
json_array_size PROTO C array:DWORD
json_copy PROTO C value:DWORD
json_deep_copy PROTO C value:DWORD
json_delete PROTO C json:DWORD
json_dump_callback PROTO C json:DWORD, callback:DWORD, data:DWORD, flags:DWORD
json_dump_file PROTO C json:DWORD, path:DWORD, flags:DWORD
json_dumpb PROTO C json:DWORD, buffer:DWORD, bufsize:DWORD, flags:DWORD
json_dumpf PROTO C json:DWORD, output:DWORD, flags:DWORD
json_dumpfd PROTO C json:DWORD, output:DWORD, flags:DWORD
json_dumps PROTO C json:DWORD, flags:DWORD
json_equal PROTO C value1:DWORD, value2:DWORD
json_false PROTO C 
json_get_alloc_funcs PROTO C malloc_fn:DWORD, free_fn:DWORD
json_integer PROTO C integer:DWORD
json_integer_set PROTO C integer:DWORD, value:DWORD
json_integer_value PROTO C integer:DWORD
json_load_callback PROTO C callback:DWORD, data:DWORD, flags:DWORD, error:DWORD
json_load_file PROTO C path:DWORD, flags:DWORD, error:DWORD
json_loadb PROTO C buffer:DWORD, buflen:DWORD, flags:DWORD, error:DWORD
json_loadf PROTO C input:DWORD, flags:DWORD, error:DWORD
json_loadfd PROTO C input:DWORD, flags:DWORD, error:DWORD
json_loads PROTO C input:DWORD, flags:DWORD, error:DWORD
json_null PROTO C 
json_number_value PROTO C json:DWORD
json_object PROTO C 
json_object_clear PROTO C object:DWORD
json_object_del PROTO C object:DWORD, key:DWORD
json_object_deln PROTO C object:DWORD, key:DWORD, key_len:DWORD
json_object_get PROTO C object:DWORD, key:DWORD
json_object_getn PROTO C object:DWORD, key:DWORD, key_len:DWORD
json_object_iter PROTO C object:DWORD
json_object_iter_at PROTO C object:DWORD, key:DWORD
json_object_iter_key PROTO C iter:DWORD
json_object_iter_key_len PROTO C iter:DWORD
json_object_iter_next PROTO C object:DWORD, iter:DWORD
json_object_iter_set_new PROTO C object:DWORD, iter:DWORD, value:DWORD
json_object_iter_value PROTO C iter:DWORD
json_object_key_to_iter PROTO C key:DWORD
json_object_seed PROTO C seed:DWORD
json_object_set_new PROTO C object:DWORD, key:DWORD, value:DWORD
json_object_set_new_nocheck PROTO C object:DWORD, key:DWORD, value:DWORD
json_object_setn_new PROTO C object:DWORD, key:DWORD, key_len:DWORD, value:DWORD
json_object_setn_new_nocheck PROTO C object:DWORD, key:DWORD, key_len:DWORD, value:DWORD
json_object_size PROTO C object:DWORD
json_object_update PROTO C object:DWORD, other:DWORD
json_object_update_existing PROTO C object:DWORD, other:DWORD
json_object_update_missing PROTO C object:DWORD, other:DWORD
json_object_update_recursive PROTO C object:DWORD, other:DWORD
json_pack PROTO C :VARARG
json_pack_ex PROTO C :VARARG
json_real PROTO C value:QWORD
json_real_set PROTO C real:DWORD, value:QWORD
json_real_value PROTO C real:DWORD
json_set_alloc_funcs PROTO C malloc_fn:DWORD, free_fn:DWORD
json_sprintf PROTO C :VARARG
json_string PROTO C value:DWORD
json_string_length PROTO C string:DWORD
json_string_nocheck PROTO C value:DWORD
json_string_set PROTO C string:DWORD, value:DWORD
json_string_set_nocheck PROTO C string:DWORD, value:DWORD
json_string_setn PROTO C string:DWORD, value:DWORD, len:DWORD
json_string_setn_nocheck PROTO C string:DWORD, value:DWORD, len:DWORD
json_string_value PROTO C string:DWORD
json_stringn PROTO C value:DWORD, len:DWORD
json_stringn_nocheck PROTO C value:DWORD, len:DWORD
json_true PROTO C 
json_unpack PROTO C :VARARG
json_unpack_ex PROTO C :VARARG
json_vpack_ex PROTO C error:DWORD, flags:DWORD, fmt:DWORD, ap:DWORD
json_vsprintf PROTO C fmt:DWORD, ap:DWORD
json_vunpack_ex PROTO C root:DWORD, error:DWORD, flags:DWORD, fmt:DWORD, ap:DWORD

; prototypes for static inline functions
json_typeof                     PROTO json:DWORD ; (json)   ((json)->type)
json_is_object                  PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_OBJECT)
json_is_array                   PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_ARRAY)
json_is_string                  PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_STRING)
json_is_integer                 PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_INTEGER)
json_is_real                    PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_REAL)
json_is_number                  PROTO json:DWORD ; (json)   (json_is_integer(json) || json_is_real(json))
json_is_true                    PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_TRUE)
json_is_false                   PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_FALSE)
json_boolean_value              PROTO json:DWORD ; json_is_true
json_is_boolean                 PROTO json:DWORD ; (json)   (json_is_true(json) || json_is_false(json))
json_is_null                    PROTO json:DWORD ; (json)   ((json) && json_typeof(json) == JSON_NULL)

json_incref                     PROTO json:DWORD ; json_t *json_incref(json_t *json)
json_decref                     PROTO json:DWORD ; void json_decref(json_t *json)
json_decrefp                    PROTO json:DWORD ; void json_decrefp(json_t **json)
json_object_set                 PROTO object:DWORD,key:DWORD,value:DWORD
json_object_set_nocheck         PROTO object:DWORD,key:DWORD,value:DWORD
json_object_iter_set            PROTO object:DWORD,iter:DWORD,value:DWORD
json_array_set                  PROTO array:DWORD,ind:DWORD,value:DWORD
json_array_append               PROTO array:DWORD,value:DWORD
json_array_insert               PROTO array:DWORD,ind:DWORD,value:DWORD


JSON_ERROR_TEXT_LENGTH          EQU 160
JSON_ERROR_SOURCE_LENGTH        EQU 80

; Structures
JSON_T                          STRUCT
    type_                       DWORD ? ; json_type type;
    refcount                    DWORD ? ; size_t refcount;
JSON_T                          ENDS

JSON_ERROR_T                    STRUCT
    line                        DWORD ? ; int line;
    column                      DWORD ? ; int column;
    position                    DWORD ? ; int position;
    source                      DB JSON_ERROR_SOURCE_LENGTH DUP (?) ; char source[JSON_ERROR_SOURCE_LENGTH];
    text                        DB JSON_ERROR_TEXT_LENGTH DUP (?) ; char text[JSON_ERROREXT_LENGTH];
JSON_ERROR_T                    ENDS

JSON_OBJECT_T                   STRUCT
    json                        JSON_T <> ; json_t json;
    hashtable                   DWORD ? ; hashtable_t hashtable;
    visited                     DWORD ? ; int visited;
JSON_OBJECT_T                   ENDS

JSON_ARRAY_T                    STRUCT
    json                        JSON_T <> ; json_t json;
    size_                       DWORD ? ; size_t size;
    entries                     DWORD ? ; size_t entries;
    table                       DWORD ? ; json_t **table;
    visited                     DWORD ? ; int visited;
JSON_ARRAY_T                    ENDS

JSON_STRING_T                   STRUCT
    json                        JSON_T <> ; json_t json;
    value                       DWORD ? ; char *value;
    length_                     DWORD ? ; size_t length;
JSON_STRING_T                   ENDS

JSON_REAL_T                     STRUCT
    json                        JSON_T <> ; json_t json;
    value                       REAL4 ? ; double value;
JSON_REAL_T                     ENDS

JSON_INTEGER_T                  STRUCT
    json                        JSON_T <> ; json_t json;
    value                       DWORD ? ; json_int_t value;
JSON_INTEGER_T                  ENDS

HASHTABLE_LIST                  STRUCT
    prev                        DWORD ? ; struct hashtable_list *prev;
    next                        DWORD ? ; struct hashtable_list *next;
HASHTABLE_LIST                  ENDS

; "pair" may be a bit confusing a name, but think of it as a
; key-value pair. In this case, it just encodes some extra data too
HASHTABLE_PAIR                  STRUCT
    list                        HASHTABLE_LIST <> ; DWORD ? ; struct hashtable_list list;
    ordered_list                HASHTABLE_LIST <> ; DWORD ? ; struct hashtable_list ordered_list;
    hash                        DWORD ? ; size_t hash;
    value                       DWORD ? ; json_t *value;
    key                         DB ? ; char key[1];
HASHTABLE_PAIR                  ENDS

HASHTABLE_BUCKET                STRUCT
    first                       DWORD ? ; struct hashtable_list *first;
    last                        DWORD ? ; struct hashtable_list *last;
HASHTABLE_BUCKET                ENDS

HASHTABLE                       STRUCT
    size_                       DWORD ? ; size_t size;
    buckets                     DWORD ? ; struct hashtable_bucket *buckets;
    order                       DWORD ? ; size_t order;  /* hashtable has pow(2, order) buckets */
    list                        HASHTABLE_LIST <> ; DWORD ? ; struct hashtable_list list;
    ordered_list                HASHTABLE_LIST <> ; DWORD ? ; struct hashtable_list ordered_list;
HASHTABLE                       ENDS

.CONST

; Constants
JANSSON_MAJOR_VERSION           EQU 2
JANSSON_MINOR_VERSION           EQU 14
JANSSON_MICRO_VERSION           EQU 0
JANSSON_VERSION                 EQU "2.14"
JANSSON_VERSION_HEX             EQU ((JANSSON_MAJOR_VERSION SHL 16) or (JANSSON_MINOR_VERSION SHL 8) or (JANSSON_MICRO_VERSION SHL 0))

; unpack flags
JSON_VALIDATE_ONLY              EQU 1h
JSON_STRICT                     EQU 2h

; decoding
JSON_REJECT_DUPLICATES          EQU 1h
JSON_DISABLE_EOF_CHECK          EQU 2h
JSON_DECODE_ANY                 EQU 4h
JSON_DECODE_INT_AS_REAL         EQU 8h
JSON_ALLOW_NUL                  EQU 10h

; encoding
JSON_MAX_INDENT                 EQU 1Fh
JSON_COMPACT                    EQU 20h
JSON_ENSURE_ASCII               EQU 40h
JSON_SORT_KEYS                  EQU 80h
JSON_PRESERVE_ORDER             EQU 100h
JSON_ENCODE_ANY                 EQU 200h
JSON_ESCAPE_SLASH               EQU 400h
JSON_EMBED                      EQU 10000h


; Enumeration
; json_type:
JSON_OBJECT                     EQU 0
JSON_ARRAY                      EQU 1
JSON_STRING                     EQU 2
JSON_INTEGER                    EQU 3
JSON_REAL                       EQU 4
JSON_TRUE                       EQU 5
JSON_FALSE                      EQU 6
JSON_NULL                       EQU 7

; json_error_code:
json_error_unknown              EQU 0
json_error_out_of_memory        EQU 1
json_error_stack_overflow       EQU 2
json_error_cannot_open_file     EQU 3
json_error_invalid_argument     EQU 4
json_error_invalid_utf8         EQU 5
json_error_premature_end_of_input EQU 6
json_error_end_of_input_expected EQU 7
json_error_invalid_syntax       EQU 8
json_error_invalid_format       EQU 9
json_error_wrong_type           EQU 10
json_error_null_character       EQU 11
json_error_null_value           EQU 12
json_error_null_byte_in_key     EQU 13
json_error_duplicate_key        EQU 14
json_error_numeric_overflow     EQU 15
json_error_item_not_found       EQU 16
json_error_index_out_of_range   EQU 17


.CODE

; functions for static inlines
json_typeof PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    ret
json_typeof ENDP

json_is_object PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_OBJECT
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_object ENDP

json_is_array PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_ARRAY
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_array ENDP

json_is_string PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_STRING
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_string ENDP

json_is_integer PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_INTEGER
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_integer ENDP

json_is_real PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_REAL
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_real ENDP

json_is_number PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_REAL || eax == JSON_INTEGER
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_number ENDP

json_is_true PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_TRUE
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_true ENDP

json_is_false PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_FALSE
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_false ENDP

json_boolean_value PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_TRUE
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_boolean_value ENDP

json_is_boolean PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_TRUE || eax == JSON_FALSE
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_boolean ENDP

json_is_null PROC USES EBX hJSON:DWORD
    mov ebx, hJSON
    mov eax, [ebx].JSON_T.type_
    .IF eax == JSON_NULL
        mov eax, TRUE
    .ELSE
        mov eax, FALSE
    .ENDIF
    ret
json_is_null ENDP

json_incref PROC USES EBX hJSON:DWORD
    .IF hJSON != NULL
        mov ebx, hJSON
        mov eax, [ebx].JSON_T.refcount
        .IF eax != -1
            inc eax
            mov [ebx].JSON_T.refcount, eax
        .ENDIF
    .ENDIF
    mov eax, hJSON
    ret
json_incref ENDP

json_decref PROC USES EBX hJSON:DWORD
    .IF hJSON != NULL
        mov ebx, hJSON
        mov eax, [ebx].JSON_T.refcount
        .IF eax != -1
            dec eax
            .IF eax == 0
                Invoke json_delete, hJSON
            .ENDIF
        .ENDIF
    .ENDIF
    ret
json_decref ENDP

json_decrefp PROC USES EBX lpJSON:DWORD;void json_decrefp(json_t **json)
    .IF lpJSON != NULL
        Invoke json_decref, lpJSON
        mov ebx, lpJSON
        mov eax, NULL
        mov [ebx], eax
    .ENDIF
    ret
json_decrefp ENDP

json_object_set PROC object:DWORD, key:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_object_set_new, object, key, newvalue 
    ret
json_object_set ENDP

json_object_set_nocheck PROC object:DWORD, key:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_object_set_new_nocheck, object, key, newvalue
    ret
json_object_set_nocheck ENDP

json_object_iter_set PROC object:DWORD, iter:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_object_iter_set_new, object, iter, newvalue
    ret
json_object_iter_set ENDP

json_array_set PROC array:DWORD, ind:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_array_set_new, array, ind, newvalue
    ret
json_array_set ENDP

json_array_append PROC array:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_array_append_new, array, newvalue
    ret
json_array_append ENDP

json_array_insert PROC array:DWORD, ind:DWORD, value:DWORD
    LOCAL newvalue:DWORD
    Invoke json_incref, value
    mov newvalue, eax
    Invoke json_array_insert_new, array, ind, newvalue
    ret
json_array_insert ENDP


