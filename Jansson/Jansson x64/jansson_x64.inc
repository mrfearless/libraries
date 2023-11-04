;
; Copyright (c) 2009-2016 Petri Lehtinen <petri@digip.org>
;
; Jansson is free software; you can redistribute it and/or modify
; it under the terms of the MIT license.
;

; jansson_x64.inc converted from jansson source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

hashtable_clear PROTO hashtable:QWORD
hashtable_close PROTO hashtable:QWORD
hashtable_del PROTO hashtable:QWORD, key:QWORD, key_len:QWORD
hashtable_get PROTO hashtable:QWORD, key:QWORD, key_len:QWORD
hashtable_init PROTO hashtable:QWORD
hashtable_iter PROTO hashtable:QWORD
hashtable_iter_at PROTO hashtable:QWORD, key:QWORD, key_len:QWORD
hashtable_iter_key PROTO iter:QWORD
hashtable_iter_key_len PROTO iter:QWORD
hashtable_iter_next PROTO hashtable:QWORD, iter:QWORD
hashtable_iter_set PROTO iter:QWORD, value:QWORD
hashtable_iter_value PROTO iter:QWORD
hashtable_seed PROTO C :VARARG
hashtable_set PROTO hashtable:QWORD, key:QWORD, key_len:QWORD, value:QWORD
jansson_version_cmp PROTO major:QWORD, minor:QWORD, micro:QWORD
jansson_version_str PROTO 
json_array PROTO 
json_array_append_new PROTO array:QWORD, value:QWORD
json_array_clear PROTO array:QWORD
json_array_extend PROTO array:QWORD, other:QWORD
json_array_get PROTO array:QWORD, index:QWORD
json_array_insert_new PROTO array:QWORD, index:QWORD, value:QWORD
json_array_remove PROTO array:QWORD, index:QWORD
json_array_set_new PROTO array:QWORD, index:QWORD, value:QWORD
json_array_size PROTO array:QWORD
json_copy PROTO value:QWORD
json_deep_copy PROTO value:QWORD
json_delete PROTO json:QWORD
json_dump_callback PROTO json:QWORD, callback:QWORD, data:QWORD, flags:QWORD
json_dump_file PROTO json:QWORD, path:QWORD, flags:QWORD
json_dumpb PROTO json:QWORD, buffer:QWORD, bufsize:QWORD, flags:QWORD
json_dumpf PROTO json:QWORD, output:QWORD, flags:QWORD
json_dumpfd PROTO json:QWORD, output:QWORD, flags:QWORD
json_dumps PROTO json:QWORD, flags:QWORD
json_equal PROTO value1:QWORD, value2:QWORD
json_false PROTO 
json_get_alloc_funcs PROTO malloc_fn:QWORD, free_fn:QWORD
json_integer PROTO integer:QWORD
json_integer_set PROTO integer:QWORD, value:QWORD
json_integer_value PROTO integer:QWORD
json_load_callback PROTO callback:QWORD, data:QWORD, flags:QWORD, error:QWORD
json_load_file PROTO path:QWORD, flags:QWORD, error:QWORD
json_loadb PROTO buffer:QWORD, buflen:QWORD, flags:QWORD, error:QWORD
json_loadf PROTO input:QWORD, flags:QWORD, error:QWORD
json_loadfd PROTO input:QWORD, flags:QWORD, error:QWORD
json_loads PROTO input:QWORD, flags:QWORD, error:QWORD
json_null PROTO 
json_number_value PROTO json:QWORD
json_object PROTO 
json_object_clear PROTO object:QWORD
json_object_del PROTO object:QWORD, key:QWORD
json_object_deln PROTO object:QWORD, key:QWORD, key_len:QWORD
json_object_get PROTO object:QWORD, key:QWORD
json_object_getn PROTO object:QWORD, key:QWORD, key_len:QWORD
json_object_iter PROTO object:QWORD
json_object_iter_at PROTO object:QWORD, key:QWORD
json_object_iter_key PROTO iter:QWORD
json_object_iter_key_len PROTO iter:QWORD
json_object_iter_next PROTO object:QWORD, iter:QWORD
json_object_iter_set_new PROTO object:QWORD, iter:QWORD, value:QWORD
json_object_iter_value PROTO iter:QWORD
json_object_key_to_iter PROTO key:QWORD
json_object_seed PROTO seed:QWORD
json_object_set_new PROTO object:QWORD, key:QWORD, value:QWORD
json_object_set_new_nocheck PROTO object:QWORD, key:QWORD, value:QWORD
json_object_setn_new PROTO object:QWORD, key:QWORD, key_len:QWORD, value:QWORD
json_object_setn_new_nocheck PROTO object:QWORD, key:QWORD, key_len:QWORD, value:QWORD
json_object_size PROTO object:QWORD
json_object_update PROTO object:QWORD, other:QWORD
json_object_update_existing PROTO object:QWORD, other:QWORD
json_object_update_missing PROTO object:QWORD, other:QWORD
json_object_update_recursive PROTO object:QWORD, other:QWORD
json_pack PROTO C :VARARG
json_pack_ex PROTO C :VARARG
json_real PROTO value:QWORD
json_real_set PROTO real:QWORD, value:QWORD
json_real_value PROTO real:QWORD
json_set_alloc_funcs PROTO malloc_fn:QWORD, free_fn:QWORD
json_sprintf PROTO C :VARARG
json_string PROTO value:QWORD
json_string_length PROTO string:QWORD
json_string_nocheck PROTO value:QWORD
json_string_set PROTO string:QWORD, value:QWORD
json_string_set_nocheck PROTO string:QWORD, value:QWORD
json_string_setn PROTO string:QWORD, value:QWORD, len:QWORD
json_string_setn_nocheck PROTO string:QWORD, value:QWORD, len:QWORD
json_string_value PROTO string:QWORD
json_stringn PROTO value:QWORD, len:QWORD
json_stringn_nocheck PROTO value:QWORD, len:QWORD
json_true PROTO 
json_unpack PROTO C :VARARG
json_unpack_ex PROTO C :VARARG
json_vpack_ex PROTO error:QWORD, flags:QWORD, fmt:QWORD, ap:QWORD
json_vsprintf PROTO fmt:QWORD, ap:QWORD
json_vunpack_ex PROTO root:QWORD, error:QWORD, flags:QWORD, fmt:QWORD, ap:QWORD

; prototypes for static inline functions
json_typeof                     PROTO json:QWORD ; (json)   ((json)->type)
json_is_object                  PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_OBJECT)
json_is_array                   PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_ARRAY)
json_is_string                  PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_STRING)
json_is_integer                 PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_INTEGER)
json_is_real                    PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_REAL)
json_is_number                  PROTO json:QWORD ; (json)   (json_is_integer(json) || json_is_real(json))
json_is_true                    PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_TRUE)
json_is_false                   PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_FALSE)
json_boolean_value              PROTO json:QWORD ; json_is_true
json_is_boolean                 PROTO json:QWORD ; (json)   (json_is_true(json) || json_is_false(json))
json_is_null                    PROTO json:QWORD ; (json)   ((json) && json_typeof(json) == JSON_NULL)

json_incref                     PROTO json:QWORD ; json_t *json_incref(json_t *json)
json_decref                     PROTO json:QWORD ; void json_decref(json_t *json)
json_decrefp                    PROTO json:QWORD ; void json_decrefp(json_t **json)
json_object_set                 PROTO object:QWORD,key:QWORD,value:QWORD
json_object_set_nocheck         PROTO object:QWORD,key:QWORD,value:QWORD
json_object_iter_set            PROTO object:QWORD,iter:QWORD,value:QWORD
json_array_set                  PROTO array:QWORD,ind:QWORD,value:QWORD
json_array_append               PROTO array:QWORD,value:QWORD
json_array_insert               PROTO array:QWORD,ind:QWORD,value:QWORD


JSON_ERROR_TEXT_LENGTH          EQU 160
JSON_ERROR_SOURCE_LENGTH        EQU 80

; Structures
JSON_T                          STRUCT
    type_                       QWORD ? ; json_type type;
    refcount                    QWORD ? ; size_t refcount;
JSON_T                          ENDS

JSON_ERROR_T                    STRUCT
    line                        QWORD ? ; int line;
    column                      QWORD ? ; int column;
    position                    QWORD ? ; int position;
    source                      DB JSON_ERROR_SOURCE_LENGTH DUP (?) ; char source[JSON_ERROR_SOURCE_LENGTH];
    text                        DB JSON_ERROR_TEXT_LENGTH DUP (?) ; char text[JSON_ERROREXT_LENGTH];
JSON_ERROR_T                    ENDS

JSON_OBJECT_T                   STRUCT
    json                        JSON_T <> ; json_t json;
    hashtable                   QWORD ? ; hashtable_t hashtable;
    visited                     QWORD ? ; int visited;
JSON_OBJECT_T                   ENDS

JSON_ARRAY_T                    STRUCT
    json                        JSON_T <> ; json_t json;
    size_                       QWORD ? ; size_t size;
    entries                     QWORD ? ; size_t entries;
    table                       QWORD ? ; json_t **table;
    visited                     QWORD ? ; int visited;
JSON_ARRAY_T                    ENDS

JSON_STRING_T                   STRUCT
    json                        JSON_T <> ; json_t json;
    value                       QWORD ? ; char *value;
    length_                     QWORD ? ; size_t length;
JSON_STRING_T                   ENDS

JSON_REAL_T                     STRUCT
    json                        JSON_T <> ; json_t json;
    value                       REAL4 ? ; double value;
JSON_REAL_T                     ENDS

JSON_INTEGER_T                  STRUCT
    json                        JSON_T <> ; json_t json;
    value                       QWORD ? ; json_int_t value;
JSON_INTEGER_T                  ENDS

HASHTABLE_LIST                  STRUCT
    prev                        QWORD ? ; struct hashtable_list *prev;
    next                        QWORD ? ; struct hashtable_list *next;
HASHTABLE_LIST                  ENDS

; "pair" may be a bit confusing a name, but think of it as a
; key-value pair. In this case, it just encodes some extra data too
HASHTABLE_PAIR                  STRUCT
    list                        HASHTABLE_LIST <> ; QWORD ? ; struct hashtable_list list;
    ordered_list                HASHTABLE_LIST <> ; QWORD ? ; struct hashtable_list ordered_list;
    hash                        QWORD ? ; size_t hash;
    value                       QWORD ? ; json_t *value;
    key                         DB ? ; char key[1];
HASHTABLE_PAIR                  ENDS

HASHTABLE_BUCKET                STRUCT
    first                       QWORD ? ; struct hashtable_list *first;
    last                        QWORD ? ; struct hashtable_list *last;
HASHTABLE_BUCKET                ENDS

HASHTABLE                       STRUCT
    size_                       QWORD ? ; size_t size;
    buckets                     QWORD ? ; struct hashtable_bucket *buckets;
    order                       QWORD ? ; size_t order;  /* hashtable has pow(2, order) buckets */
    list                        HASHTABLE_LIST <> ; QWORD ? ; struct hashtable_list list;
    ordered_list                HASHTABLE_LIST <> ; QWORD ? ; struct hashtable_list ordered_list;
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

json_typeof PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    ret
json_typeof ENDP

json_is_object PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_OBJECT
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_object ENDP

json_is_array PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_ARRAY
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_array ENDP

json_is_string PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_STRING
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_string ENDP

json_is_integer PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_INTEGER
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_integer ENDP

json_is_real PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_REAL
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_real ENDP

json_is_number PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_REAL || rax == JSON_INTEGER
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_number ENDP

json_is_true PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_TRUE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_true ENDP

json_is_false PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_FALSE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_false ENDP

json_boolean_value PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_TRUE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_boolean_value ENDP

json_is_boolean PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_TRUE || rax == JSON_FALSE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_boolean ENDP

json_is_null PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON_T.type_
    .IF rax == JSON_NULL
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_null ENDP

json_incref PROC FRAME USES RBX hJSON:QWORD
    .IF hJSON != NULL
        mov rbx, hJSON
        mov rax, [rbx].JSON_T.refcount
        .IF rax != -1
            inc rax
            mov [rbx].JSON_T.refcount, rax
        .ENDIF
    .ENDIF
    mov rax, hJSON
    ret
json_incref ENDP

json_decref PROC FRAME USES RBX hJSON:QWORD
    .IF hJSON != NULL
        mov rbx, hJSON
        mov rax, [rbx].JSON_T.refcount
        .IF rax != -1
            dec rax
            .IF rax == 0
                Invoke json_delete, hJSON
            .ENDIF
        .ENDIF
    .ENDIF
    ret
json_decref ENDP

json_decrefp PROC FRAME USES RBX lpJSON:QWORD;void json_decrefp(json_t **json)
    .IF lpJSON != NULL
        Invoke json_decref, lpJSON
        mov rbx, lpJSON
        mov rax, NULL
        mov [rbx], rax
    .ENDIF
    ret
json_decrefp ENDP

json_object_set PROC FRAME object:QWORD, key:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_object_set_new, object, key, newvalue
    ret
json_object_set ENDP

json_object_set_nocheck PROC FRAME object:QWORD, key:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_object_set_new_nocheck, object, key, newvalue
    ret
json_object_set_nocheck ENDP

json_object_iter_set PROC FRAME object:QWORD, iter:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_object_iter_set_new, object, iter, newvalue
    ret
json_object_iter_set ENDP

json_array_set PROC FRAME array:QWORD, ind:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_array_set_new, array, ind, newvalue
    ret
json_array_set ENDP

json_array_append PROC FRAME array:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_array_append_new, array, newvalue
    ret
json_array_append ENDP

json_array_insert PROC FRAME array:QWORD, ind:QWORD, value:QWORD
    LOCAL newvalue:QWORD
    Invoke json_incref, value
    mov newvalue, rax
    Invoke json_array_insert_new, array, ind, newvalue
    ret
json_array_insert ENDP




