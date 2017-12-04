;
; Copyright (c) 2009-2016 Petri Lehtinen <petri@digip.org>
;
; Jansson is free software; you can redistribute it and/or modify
; it under the terms of the MIT license. See LICENSE for details.
;

; jansson_x64.inc converted from jansson.h for assembler by fearless 2017


; Prototypes
json_object_seed                PROTO :QWORD ; void json_object_seed(size_t seed);
json_object_size                PROTO :QWORD ; size_t json_object_size(const json_t *object);
json_object_get                 PROTO :QWORD,:QWORD ; json_t *json_object_get(const json_t *object, const char *key);
json_object_set_new             PROTO :QWORD,:QWORD,:QWORD ; int json_object_set_new(json_t *object, const char *key, json_t *value);
json_object_set_new_nocheck     PROTO :QWORD,:QWORD,:QWORD ; int json_object_set_new_nocheck(json_t *object, const char *key, json_t *value);
json_object_del                 PROTO :QWORD,:QWORD ; int json_object_del(json_t *object, const char *key);
json_object_clear               PROTO :QWORD ; int json_object_clear(json_t *object);
json_object_update              PROTO :QWORD,:QWORD ; int json_object_update(json_t *object, json_t *other);
json_object_update_existing     PROTO :QWORD,:QWORD ; int json_object_update_existing(json_t *object, json_t *other);
json_object_update_missing      PROTO :QWORD,:QWORD ; int json_object_update_missing(json_t *object, json_t *other);
json_object_iter                PROTO :QWORD ; void *json_object_iter(json_t *object);
json_object_iter_at             PROTO :QWORD,:QWORD ; void *json_object_iter_at(json_t *object, const char *key);
json_object_key_to_iter         PROTO :QWORD ; void *json_object_key_to_iter(const char *key);
json_object_iter_next           PROTO :QWORD,:QWORD ; void *json_object_iter_next(json_t *object, void *iter);
json_object_iter_key            PROTO :QWORD ; const char *json_object_iter_key(void *iter);
json_object_iter_value          PROTO :QWORD ; json_t *json_object_iter_value(void *iter);
json_object_iter_set_new        PROTO :QWORD,:QWORD,:QWORD ; int json_object_iter_set_new(json_t *object, void *iter, json_t *value);
json_array_size                 PROTO :QWORD ; size_t json_array_size(const json_t *array);
json_array_get                  PROTO :QWORD,:QWORD ; json_t *json_array_get(const json_t *array, size_t index);
json_array_set_new              PROTO :QWORD,:QWORD,:QWORD ; int json_array_set_new(json_t *array, size_t index, json_t *value);
json_array_append_new           PROTO :QWORD,:QWORD ; int json_array_append_new(json_t *array, json_t *value);
json_array_insert_new           PROTO :QWORD,:QWORD,:QWORD ; int json_array_insert_new(json_t *array, size_t index, json_t *value);
json_array_remove               PROTO :QWORD,:QWORD ; int json_array_remove(json_t *array, size_t index);
json_array_clear                PROTO :QWORD ; int json_array_clear(json_t *array);
json_array_extend               PROTO :QWORD,:QWORD ; int json_array_extend(json_t *array, json_t *other);
json_string_value               PROTO :QWORD ; const char *json_string_value(const json_t *string);
json_string_length              PROTO :QWORD ; size_t json_string_length(const json_t *string);
json_integer_value              PROTO :QWORD ; json_int_t json_integer_value(const json_t *integer);
json_real_value                 PROTO :QWORD ; double json_real_value(const json_t *real);
json_number_value               PROTO :QWORD ; double json_number_value(const json_t *json);
json_string_set                 PROTO :QWORD,:QWORD ; int json_string_set(json_t *string, const char *value);
json_string_setn                PROTO :QWORD,:QWORD,:QWORD ; int json_string_setn(json_t *string, const char *value, size_t len);
json_string_set_nocheck         PROTO :QWORD,:QWORD ; int json_string_set_nocheck(json_t *string, const char *value);
json_string_setn_nocheck        PROTO :QWORD,:QWORD,:QWORD ; int json_string_setn_nocheck(json_t *string, const char *value, size_t len);
json_integer_set                PROTO :QWORD,:QWORD ; int json_integer_set(json_t *integer, json_int_t value);
json_real_set                   PROTO :QWORD,:QWORD ; int json_real_set(json_t *real, double value);
json_equal                      PROTO :QWORD,:QWORD ; int json_equal(const json_t *value1, const json_t *value2);
json_copy                       PROTO :QWORD ; json_t *json_copy(json_t *value);
json_deep_copy                  PROTO :QWORD ; json_t *json_deep_copy(const json_t *value);
json_loads                      PROTO :QWORD,:QWORD,:QWORD ; json_t *json_loads(const char *input, size_t flags, json_error_t *error);
json_loadb                      PROTO :QWORD,:QWORD,:QWORD,:QWORD ; json_t *json_loadb(const char *buffer, size_t buflen, size_t flags, json_error_t *error);
json_loadf                      PROTO :QWORD,:QWORD,:QWORD ; json_t *json_loadf(FILE *input, size_t flags, json_error_t *error);
json_loadfd                     PROTO :QWORD,:QWORD,:QWORD ; json_t *json_loadfd(int input, size_t flags, json_error_t *error);
json_load_file                  PROTO :QWORD,:QWORD,:QWORD ; json_t *json_load_file(const char *path, size_t flags, json_error_t *error);
json_load_callback              PROTO :QWORD,:QWORD,:QWORD,:QWORD ; json_t *json_load_callback(json_load_callback_t callback, void *data, size_t flags, json_error_t *error);
json_dump_callback_t            PROTO :QWORD,:QWORD,:QWORD ; typedef int (*json_dump_callback_t)(const char *buffer, size_t size, void *data);
json_dumps                      PROTO :QWORD,:QWORD ; char *json_dumps(const json_t *json, size_t flags);
json_dumpb                      PROTO :QWORD,:QWORD,:QWORD,:QWORD ; size_t json_dumpb(const json_t *json, char *buffer, size_t size, size_t flags);
json_dumpf                      PROTO :QWORD,:QWORD,:QWORD ; int json_dumpf(const json_t *json, FILE *output, size_t flags);
json_dumpfd                     PROTO :QWORD,:QWORD,:QWORD ; int json_dumpfd(const json_t *json, int output, size_t flags);
json_dump_file                  PROTO :QWORD,:QWORD,:QWORD ; int json_dump_file(const json_t *json, const char *path, size_t flags);
json_dump_callback              PROTO :QWORD,:QWORD,:QWORD,:QWORD ; int json_dump_callback(const json_t *json, json_dump_callback_t callback, void *data, size_t flags);
json_set_alloc_funcs            PROTO :QWORD,:QWORD ; void json_set_alloc_funcs(json_malloc_t malloc_fn, json_free_t free_fn);
json_get_alloc_funcs            PROTO :QWORD,:QWORD ; void json_get_alloc_funcs(json_malloc_t *malloc_fn, json_free_t *free_fn);
json_typeof                     PROTO :QWORD ; (json)      ((json)->type)
json_is_object                  PROTO :QWORD ; (json)   ((json) && json_typeof(json) == JSON_OBJECT)
json_is_array                   PROTO :QWORD ; (json)    ((json) && json_typeof(json) == JSON_ARRAY)
json_is_string                  PROTO :QWORD ; (json)   ((json) && json_typeof(json) == JSON_STRING)
json_is_integer                 PROTO :QWORD ; (json)  ((json) && json_typeof(json) == JSON_INTEGER)
json_is_real                    PROTO :QWORD ; (json)     ((json) && json_typeof(json) == JSON_REAL)
json_is_number                  PROTO :QWORD ; (json)   (json_is_integer(json) || json_is_real(json))
json_is_true                    PROTO :QWORD ; (json)     ((json) && json_typeof(json) == JSON_TRUE)
json_is_false                   PROTO :QWORD ; (json)    ((json) && json_typeof(json) == JSON_FALSE)
json_boolean_value              PROTO :QWORD ;      json_is_true
json_is_boolean                 PROTO :QWORD ; (json)  (json_is_true(json) || json_is_false(json))
json_is_null                    PROTO :QWORD ; (json)     ((json) && json_typeof(json) == JSON_NULL)


; Private functions
jsonp_stringn_nocheck_own       PROTO :QWORD,:QWORD ; json_t *jsonp_stringn_nocheck_own(const char *value, size_t len);
jsonp_error_init                PROTO :QWORD,:QWORD ; void jsonp_error_init(json_error_t *error, const char *source);
jsonp_error_set_source          PROTO :QWORD,:QWORD ; void jsonp_error_set_source(json_error_t *error, const char *source);
jsonp_strtod                    PROTO :QWORD,:QWORD ; int jsonp_strtod(strbuffer_t *strbuffer, double *out);
jsonp_dtostr                    PROTO :QWORD,:QWORD,:QWORD,:QWORD ; int jsonp_dtostr(char *buffer, size_t size, double value, int prec);
jsonp_malloc                    PROTO :QWORD ; void* jsonp_malloc(size_t size);
jsonp_free                      PROTO :QWORD ; void jsonp_free(void *ptr);
jsonp_strndup                   PROTO :QWORD,:QWORD ; char *jsonp_strndup(const char *str, size_t length);
jsonp_strdup                    PROTO :QWORD ; char *jsonp_strdup(const char *str);
json_delete                     PROTO :QWORD ; (json_t *json);

; hashtable functions
hashtable_init                  PROTO :QWORD ; int hashtable_init(hashtable_t *hashtable);
hashtable_close                 PROTO :QWORD ; void hashtable_close(hashtable_t *hashtable);
hashtable_set                   PROTO :QWORD,:QWORD,:QWORD ; int hashtable_set(hashtable_t *hashtable, const char *key, json_t *value);
hashtable_get                   PROTO :QWORD,:QWORD ; void *hashtable_get(hashtable_t *hashtable, const char *key);
hashtable_del                   PROTO :QWORD,:QWORD ; int hashtable_del(hashtable_t *hashtable, const char *key);

hashtable_clear                 PROTO :QWORD ; void hashtable_clear(hashtable_t *hashtable);
hashtable_iter                  PROTO :QWORD ; void *hashtable_iter(hashtable_t *hashtable);
hashtable_iter_at               PROTO :QWORD,:QWORD ; void *hashtable_iter_at(hashtable_t *hashtable, const char *key);
hashtable_iter_next             PROTO :QWORD,:QWORD ; void *hashtable_iter_next(hashtable_t *hashtable, void *iter);
hashtable_iter_key              PROTO :QWORD ; void *hashtable_iter_key(void *iter);
hashtable_iter_value            PROTO :QWORD ; void *hashtable_iter_value(void *iter);
hashtable_iter_set              PROTO :QWORD,:QWORD ; void hashtable_iter_set(void *iter, json_t *value);

json_load_callback              PROTO :QWORD,:QWORD,:QWORD ; typedef size_t (*json_load_callback_t)(void *buffer, size_t buflen, void *data);

json_incref                     PROTO :QWORD ; json_t *json_incref(json_t *json)
json_decref                     PROTO :QWORD ; void json_decref(json_t *json)
json_decrefp                    PROTO :QWORD ; void json_decrefp(json_t **json)
json_object_set                 PROTO :QWORD,:QWORD,:QWORD ; object:QWORD, key:QWORD, value:QWORD
json_object_set_nocheck         PROTO :QWORD,:QWORD,:QWORD ; object:QWORD, key:QWORD, value:QWORD
json_object_iter_set            PROTO :QWORD,:QWORD,:QWORD ; object:QWORD, iter:QWORD, value:QWORD
json_array_set                  PROTO :QWORD,:QWORD,:QWORD ; array:QWORD, ind:QWORD, value:QWORD
json_array_append               PROTO :QWORD,:QWORD ; array:QWORD, value:QWORD
json_array_insert               PROTO :QWORD,:QWORD,:QWORD ; array:QWORD, ind:QWORD, value:QWORD



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
JANSSON_MINOR_VERSION           EQU 10
JANSSON_MICRO_VERSION           EQU 0
JANSSON_VERSION                 EQU "2.10"
JANSSON_VERSION_HEX             EQU ((JANSSON_MAJOR_VERSION SHL 16) or (JANSSON_MINOR_VERSION SHL 8) or (JANSSON_MICRO_VERSION SHL 0))

; unpack flags
JSON_VALIDATE_ONLY              EQU 1h
JSON_STRICT                     EQU 2h

; flags
JSON_REJECT_DUPLICATES          EQU 1h
JSON_DISABLE_EOF_CHECK          EQU 2h
JSON_DECODE_ANY                 EQU 4h
JSON_DECODE_INT_AS_REAL         EQU 8h
JSON_ALLOW_NUL                  EQU 10h
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
    mov rax, [rbx].JSON.type_
    ret
json_typeof ENDP

json_is_object PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_OBJECT
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_object ENDP

json_is_array PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_ARRAY
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_array ENDP

json_is_string PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_STRING
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_string ENDP

json_is_integer PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_INTEGER
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_integer ENDP

json_is_real PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_REAL
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_real ENDP

json_is_number PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_REAL || rax == JSON_INTEGER
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_number ENDP

json_is_true PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_TRUE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_true ENDP

json_is_false PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_FALSE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_false ENDP

json_boolean_value PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_TRUE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_boolean_value ENDP

json_is_boolean PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
    .IF rax == JSON_TRUE || rax == JSON_FALSE
        mov rax, TRUE
    .ELSE
        mov rax, FALSE
    .ENDIF
    ret
json_is_boolean ENDP

json_is_null PROC FRAME USES RBX hJSON:QWORD
    mov rbx, hJSON
    mov rax, [rbx].JSON.type_
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
        mov rax, [rbx].JSON.refcount
        .IF rax != -1
            inc rax
            mov [rbx].JSON.refcount, rax
        .ENDIF
    .ENDIF
    mov rax, hJSON
    ret
json_incref ENDP

json_decref PROC FRAME USES RBX hJSON:QWORD
    .IF hJSON != NULL
        mov rbx, hJSON
        mov rax, [rbx].JSON.refcount
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
    return json_object_set_new_nocheck, object, key, newvalue
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




