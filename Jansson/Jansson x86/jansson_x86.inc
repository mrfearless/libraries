;
; Copyright (c) 2009-2016 Petri Lehtinen <petri@digip.org>
;
; Jansson is free software; you can redistribute it and/or modify
; it under the terms of the MIT license. See LICENSE for details.
;

; jansson_x86.inc converted from jansson.h for assembler by fearless 2017


; Prototypes
json_object_seed                PROTO C :DWORD ; void json_object_seed(size_t seed);
json_object_size                PROTO C :DWORD ; size_t json_object_size(const json_t *object);
json_object_get                 PROTO C :DWORD,:DWORD ; json_t *json_object_get(const json_t *object, const char *key);
json_object_set_new             PROTO C :DWORD,:DWORD,:DWORD ; int json_object_set_new(json_t *object, const char *key, json_t *value);
json_object_set_new_nocheck     PROTO C :DWORD,:DWORD,:DWORD ; int json_object_set_new_nocheck(json_t *object, const char *key, json_t *value);
json_object_del                 PROTO C :DWORD,:DWORD ; int json_object_del(json_t *object, const char *key);
json_object_clear               PROTO C :DWORD ; int json_object_clear(json_t *object);
json_object_update              PROTO C :DWORD,:DWORD ; int json_object_update(json_t *object, json_t *other);
json_object_update_existing     PROTO C :DWORD,:DWORD ; int json_object_update_existing(json_t *object, json_t *other);
json_object_update_missing      PROTO C :DWORD,:DWORD ; int json_object_update_missing(json_t *object, json_t *other);
json_object_iter                PROTO C :DWORD ; void *json_object_iter(json_t *object);
json_object_iter_at             PROTO C :DWORD,:DWORD ; void *json_object_iter_at(json_t *object, const char *key);
json_object_key_to_iter         PROTO C :DWORD ; void *json_object_key_to_iter(const char *key);
json_object_iter_next           PROTO C :DWORD,:DWORD ; void *json_object_iter_next(json_t *object, void *iter);
json_object_iter_key            PROTO C :DWORD ; const char *json_object_iter_key(void *iter);
json_object_iter_value          PROTO C :DWORD ; json_t *json_object_iter_value(void *iter);
json_object_iter_set_new        PROTO C :DWORD,:DWORD,:DWORD ; int json_object_iter_set_new(json_t *object, void *iter, json_t *value);
json_array_size                 PROTO C :DWORD ; size_t json_array_size(const json_t *array);
json_array_get                  PROTO C :DWORD,:DWORD ; json_t *json_array_get(const json_t *array, size_t index);
json_array_set_new              PROTO C :DWORD,:DWORD,:DWORD ; int json_array_set_new(json_t *array, size_t index, json_t *value);
json_array_append_new           PROTO C :DWORD,:DWORD ; int json_array_append_new(json_t *array, json_t *value);
json_array_insert_new           PROTO C :DWORD,:DWORD,:DWORD ; int json_array_insert_new(json_t *array, size_t index, json_t *value);
json_array_remove               PROTO C :DWORD,:DWORD ; int json_array_remove(json_t *array, size_t index);
json_array_clear                PROTO C :DWORD ; int json_array_clear(json_t *array);
json_array_extend               PROTO C :DWORD,:DWORD ; int json_array_extend(json_t *array, json_t *other);
json_string_value               PROTO C :DWORD ; const char *json_string_value(const json_t *string);
json_string_length              PROTO C :DWORD ; size_t json_string_length(const json_t *string);
json_integer_value              PROTO C :DWORD ; json_int_t json_integer_value(const json_t *integer);
json_real_value                 PROTO C :DWORD ; double json_real_value(const json_t *real);
json_number_value               PROTO C :DWORD ; double json_number_value(const json_t *json);
json_string_set                 PROTO C :DWORD,:DWORD ; int json_string_set(json_t *string, const char *value);
json_string_setn                PROTO C :DWORD,:DWORD,:DWORD ; int json_string_setn(json_t *string, const char *value, size_t len);
json_string_set_nocheck         PROTO C :DWORD,:DWORD ; int json_string_set_nocheck(json_t *string, const char *value);
json_string_setn_nocheck        PROTO C :DWORD,:DWORD,:DWORD ; int json_string_setn_nocheck(json_t *string, const char *value, size_t len);
json_integer_set                PROTO C :DWORD,:DWORD ; int json_integer_set(json_t *integer, json_int_t value);
json_real_set                   PROTO C :DWORD,:DWORD ; int json_real_set(json_t *real, double value);
json_equal                      PROTO C :DWORD,:DWORD ; int json_equal(const json_t *value1, const json_t *value2);
json_copy                       PROTO C :DWORD ; json_t *json_copy(json_t *value);
json_deep_copy                  PROTO C :DWORD ; json_t *json_deep_copy(const json_t *value);
json_loads                      PROTO C :DWORD,:DWORD,:DWORD ; json_t *json_loads(const char *input, size_t flags, json_error_t *error);
json_loadb                      PROTO C :DWORD,:DWORD,:DWORD,:DWORD ; json_t *json_loadb(const char *buffer, size_t buflen, size_t flags, json_error_t *error);
json_loadf                      PROTO C :DWORD,:DWORD,:DWORD ; json_t *json_loadf(FILE *input, size_t flags, json_error_t *error);
json_loadfd                     PROTO C :DWORD,:DWORD,:DWORD ; json_t *json_loadfd(int input, size_t flags, json_error_t *error);
json_load_file                  PROTO C :DWORD,:DWORD,:DWORD ; json_t *json_load_file(const char *path, size_t flags, json_error_t *error);
json_load_callback              PROTO C :DWORD,:DWORD,:DWORD,:DWORD ; json_t *json_load_callback(json_load_callback_t callback, void *data, size_t flags, json_error_t *error);
json_dump_callback_t            PROTO C :DWORD,:DWORD,:DWORD ; typedef int (*json_dump_callback_t)(const char *buffer, size_t size, void *data);
json_dumps                      PROTO C :DWORD,:DWORD ; char *json_dumps(const json_t *json, size_t flags);
json_dumpb                      PROTO C :DWORD,:DWORD,:DWORD,:DWORD ; size_t json_dumpb(const json_t *json, char *buffer, size_t size, size_t flags);
json_dumpf                      PROTO C :DWORD,:DWORD,:DWORD ; int json_dumpf(const json_t *json, FILE *output, size_t flags);
json_dumpfd                     PROTO C :DWORD,:DWORD,:DWORD ; int json_dumpfd(const json_t *json, int output, size_t flags);
json_dump_file                  PROTO C :DWORD,:DWORD,:DWORD ; int json_dump_file(const json_t *json, const char *path, size_t flags);
json_dump_callback              PROTO C :DWORD,:DWORD,:DWORD,:DWORD ; int json_dump_callback(const json_t *json, json_dump_callback_t callback, void *data, size_t flags);
json_set_alloc_funcs            PROTO C :DWORD,:DWORD ; void json_set_alloc_funcs(json_malloc_t malloc_fn, json_free_t free_fn);
json_get_alloc_funcs            PROTO C :DWORD,:DWORD ; void json_get_alloc_funcs(json_malloc_t *malloc_fn, json_free_t *free_fn);
json_typeof                     PROTO :DWORD ; (json)      ((json)->type)
json_is_object                  PROTO :DWORD ; (json)   ((json) && json_typeof(json) == JSON_OBJECT)
json_is_array                   PROTO :DWORD ; (json)    ((json) && json_typeof(json) == JSON_ARRAY)
json_is_string                  PROTO :DWORD ; (json)   ((json) && json_typeof(json) == JSON_STRING)
json_is_integer                 PROTO :DWORD ; (json)  ((json) && json_typeof(json) == JSON_INTEGER)
json_is_real                    PROTO :DWORD ; (json)     ((json) && json_typeof(json) == JSON_REAL)
json_is_number                  PROTO :DWORD ; (json)   (json_is_integer(json) || json_is_real(json))
json_is_true                    PROTO :DWORD ; (json)     ((json) && json_typeof(json) == JSON_TRUE)
json_is_false                   PROTO :DWORD ; (json)    ((json) && json_typeof(json) == JSON_FALSE)
json_boolean_value              PROTO :DWORD ;      json_is_true
json_is_boolean                 PROTO :DWORD ; (json)  (json_is_true(json) || json_is_false(json))
json_is_null                    PROTO :DWORD ; (json)     ((json) && json_typeof(json) == JSON_NULL)


; Private functions
jsonp_stringn_nocheck_own       PROTO C :DWORD,:DWORD ; json_t *jsonp_stringn_nocheck_own(const char *value, size_t len);
jsonp_error_init                PROTO C :DWORD,:DWORD ; void jsonp_error_init(json_error_t *error, const char *source);
jsonp_error_set_source          PROTO C :DWORD,:DWORD ; void jsonp_error_set_source(json_error_t *error, const char *source);
jsonp_strtod                    PROTO C :DWORD,:DWORD ; int jsonp_strtod(strbuffer_t *strbuffer, double *out);
jsonp_dtostr                    PROTO C :DWORD,:DWORD,:DWORD,:DWORD ; int jsonp_dtostr(char *buffer, size_t size, double value, int prec);
jsonp_malloc                    PROTO C :DWORD ; void* jsonp_malloc(size_t size);
jsonp_free                      PROTO C :DWORD ; void jsonp_free(void *ptr);
jsonp_strndup                   PROTO C :DWORD,:DWORD ; char *jsonp_strndup(const char *str, size_t length);
jsonp_strdup                    PROTO C :DWORD ; char *jsonp_strdup(const char *str);
json_delete                     PROTO C :DWORD ; (json_t *json);

; hashtable functions
hashtable_init                  PROTO C :DWORD ; int hashtable_init(hashtable_t *hashtable);
hashtable_close                 PROTO C :DWORD ; void hashtable_close(hashtable_t *hashtable);
hashtable_set                   PROTO C :DWORD,:DWORD,:DWORD ; int hashtable_set(hashtable_t *hashtable, const char *key, json_t *value);
hashtable_get                   PROTO C :DWORD,:DWORD ; void *hashtable_get(hashtable_t *hashtable, const char *key);
hashtable_del                   PROTO C :DWORD,:DWORD ; int hashtable_del(hashtable_t *hashtable, const char *key);

hashtable_clear                 PROTO C :DWORD ; void hashtable_clear(hashtable_t *hashtable);
hashtable_iter                  PROTO C :DWORD ; void *hashtable_iter(hashtable_t *hashtable);
hashtable_iter_at               PROTO C :DWORD,:DWORD ; void *hashtable_iter_at(hashtable_t *hashtable, const char *key);
hashtable_iter_next             PROTO C :DWORD,:DWORD ; void *hashtable_iter_next(hashtable_t *hashtable, void *iter);
hashtable_iter_key              PROTO C :DWORD ; void *hashtable_iter_key(void *iter);
hashtable_iter_value            PROTO C :DWORD ; void *hashtable_iter_value(void *iter);
hashtable_iter_set              PROTO C :DWORD,:DWORD ; void hashtable_iter_set(void *iter, json_t *value);

json_load_callback              PROTO C :DWORD,:DWORD,:DWORD ; typedef size_t (*json_load_callback_t)(void *buffer, size_t buflen, void *data);

json_incref                     PROTO :DWORD ; json_t *json_incref(json_t *json)
json_decref                     PROTO :DWORD ; void json_decref(json_t *json)
json_decrefp                    PROTO :DWORD ; void json_decrefp(json_t **json)
json_object_set                 PROTO :DWORD,:DWORD,:DWORD ; object:DWORD, key:DWORD, value:DWORD
json_object_set_nocheck         PROTO :DWORD,:DWORD,:DWORD ; object:DWORD, key:DWORD, value:DWORD
json_object_iter_set            PROTO :DWORD,:DWORD,:DWORD ; object:DWORD, iter:DWORD, value:DWORD
json_array_set                  PROTO :DWORD,:DWORD,:DWORD ; array:DWORD, ind:DWORD, value:DWORD
json_array_append               PROTO :DWORD,:DWORD ; array:DWORD, value:DWORD
json_array_insert               PROTO :DWORD,:DWORD,:DWORD ; array:DWORD, ind:DWORD, value:DWORD



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




