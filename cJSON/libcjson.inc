;
;  Copyright (c) 2009-2017 Dave Gamble and cJSON contributors
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
;

; libcjson.inc converted from cJSON.h for masm by fearless 2017

include msvcrt.inc
includelib msvcrt.lib
includelib msvcrt14.lib

; cJSON project version
CJSON_VERSION_MAJOR             EQU 1
CJSON_VERSION_MINOR             EQU 6
CJSON_VERSION_PATCH             EQU 0

; cJSON Types:
cJSON_Invalid                   EQU 0; (0)
cJSON_False                     EQU 1; (1 << 0)
cJSON_True                      EQU 2; (1 << 1)
cJSON_NULL                      EQU 4; (1 << 2)
cJSON_Number                    EQU 8; (1 << 3)
cJSON_String                    EQU 16; (1 << 4)
cJSON_Array                     EQU 32; (1 << 5)
cJSON_Object                    EQU 64; (1 << 6)
cJSON_Raw                       EQU 128; (1 << 7) - raw json

cJSON_IsReference               EQU 256
cJSON_StringIsConst             EQU 512



; The cJSON structure:
cJSON                           STRUCT
    next                        DWORD ?
    prev                        DWORD ?
    child                       DWORD ?
    itemtype                    DWORD ?
    valuestring                 DWORD ?
    valueint                    DWORD ?
    valuedouble                 QWORD ?
    itemstring                  DWORD ?
cJSON                           ENDS

cJSON_Hooks                     STRUCT
    malloc_fn                   DWORD ?
    free_fn                     DWORD ?
cJSON_Hooks                     ENDS

cJSON_bool                      TYPEDEF DWORD

CJSON_NESTING_LIMIT             EQU 1000


cJSON_Version                   PROTO 
cJSON_InitHooks                 PROTO :DWORD ; (cJSON_Hooks* hooks);
cJSON_Parse                     PROTO :DWORD ; (const char *value);
cJSON_ParseWithOpts             PROTO :DWORD, :DWORD, :DWORD ; (const char *value, const char **return_parse_end, cJSON_bool require_null_terminated);
cJSON_Print                     PROTO :DWORD ; (const cJSON *item);
cJSON_PrintUnformatted          PROTO :DWORD ; (const cJSON *item);
cJSON_PrintBuffered             PROTO :DWORD, :DWORD, :DWORD ; (const cJSON *item, int prebuffer, cJSON_bool fmt);
cJSON_PrintPreallocated         PROTO :DWORD, :DWORD, :DWORD, :DWORD ; (cJSON *item, char *buffer, const int length, const cJSON_bool format);
cJSON_Delete                    PROTO :DWORD ; (cJSON *c);
cJSON_GetArraySize              PROTO :DWORD ; (const cJSON *array);
cJSON_GetObjectItem             PROTO :DWORD, :DWORD ; (const cJSON * const object, const char * const string);
cJSON_GetObjectItemCaseSensitive PROTO :DWORD, :DWORD ; (const cJSON * const object, const char * const string);
cJSON_HasObjectItem             PROTO :DWORD, :DWORD ; (const cJSON *object, const char *string);
cJSON_GetErrorPtr               PROTO



; These functions check the type of an item
cJSON_IsInvalid                 PROTO :DWORD ; (const cJSON * const item);
cJSON_IsFalse                   PROTO :DWORD ; (const cJSON * const item);
cJSON_IsTrue                    PROTO :DWORD ; (const cJSON * const item);
cJSON_IsBool                    PROTO :DWORD ; (const cJSON * const item);
cJSON_IsNull                    PROTO :DWORD ; (const cJSON * const item);
cJSON_IsNumber                  PROTO :DWORD ; (const cJSON * const item);
cJSON_IsString                  PROTO :DWORD ; (const cJSON * const item);
cJSON_IsArray                   PROTO :DWORD ; (const cJSON * const item);
cJSON_IsObject                  PROTO :DWORD ; (const cJSON * const item);
cJSON_IsRaw                     PROTO :DWORD ; (const cJSON * const item);

; These calls create a cJSON item of the appropriate type.
cJSON_CreateNull                PROTO
cJSON_CreateTrue                PROTO
cJSON_CreateFalse               PROTO
cJSON_CreateBool                PROTO :DWORD ; (cJSON_bool boolean);
cJSON_CreateNumber              PROTO :DWORD ; (double num);
cJSON_CreateString              PROTO :DWORD ; (const char *string);
; raw json 
cJSON_CreateRaw                 PROTO :DWORD ; (const char *raw);
cJSON_CreateArray               PROTO
cJSON_CreateObject              PROTO

; These utilities create an Array of count items.
cJSON_CreateIntArray            PROTO :DWORD, :DWORD ; (const int *numbers, int count);
cJSON_CreateFloatArray          PROTO :DWORD, :DWORD ; (const float *numbers, int count);
cJSON_CreateDoubleArray         PROTO :DWORD, :DWORD ; (const double *numbers, int count);
cJSON_CreateStringArray         PROTO :DWORD, :DWORD ; (const char **strings, int count);

; Append item to the specified array/object.
cJSON_AddItemToArray            PROTO :DWORD, :DWORD ; (cJSON *array, cJSON *item);
cJSON_AddItemToObject           PROTO :DWORD, :DWORD, :DWORD ; (cJSON *object, const char *string, cJSON *item);
; Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the; cJSON object.
; WARNING: When this function was used, make sure to always check that (item->type & cJSON_StringIsConst); is zero before writing to `item->string`
cJSON_AddItemToObjectCS         PROTO :DWORD, :DWORD, :DWORD ; (cJSON *object, const char *string, cJSON *item);
; Append reference to item to the specified array/object. Use this when you want to add an existing cJSON to a new cJSON, but don't want to corrupt your existing cJSON.
cJSON_AddItemReferenceToArray   PROTO :DWORD, :DWORD ; (cJSON *array, cJSON *item);
cJSON_AddItemReferenceToObject  PROTO :DWORD, :DWORD, :DWORD ; (cJSON *object, const char *string, cJSON *item);

; Remove/Detatch items from Arrays/Objects.
cJSON_DetachItemViaPointer      PROTO :DWORD, :DWORD ; (cJSON *parent, cJSON * const item);
cJSON_DetachItemFromArray       PROTO :DWORD, :DWORD ; (cJSON *array, int which);
cJSON_DeleteItemFromArray       PROTO :DWORD, :DWORD ; (cJSON *array, int which);
cJSON_DetachItemFromObject      PROTO :DWORD, :DWORD ; (cJSON *object, const char *string);
cJSON_DetachItemFromObjectCaseSensitive PROTO :DWORD, :DWORD ; (cJSON *object, const char *string);
cJSON_DeleteItemFromObject      PROTO :DWORD, :DWORD ; (cJSON *object, const char *string);
cJSON_DeleteItemFromObjectCaseSensitive PROTO :DWORD, :DWORD ; (cJSON *object, const char *string);

; Update array items.
cJSON_InsertItemInArray         PROTO :DWORD, :DWORD, :DWORD ; (cJSON *array, int which, cJSON *newitem);  Shifts pre-existing items to the right.
cJSON_ReplaceItemViaPointer     PROTO :DWORD, :DWORD, :DWORD ; (cJSON * const parent, cJSON * const item, cJSON * replacement);
cJSON_ReplaceItemInArray        PROTO :DWORD, :DWORD, :DWORD ; (cJSON *array, int which, cJSON *newitem);
cJSON_ReplaceItemInObject       PROTO :DWORD, :DWORD, :DWORD ; (cJSON *object,const char *string,cJSON *newitem);
cJSON_ReplaceItemInObjectCaseSensitive PROTO :DWORD, :DWORD, :DWORD ; (cJSON *object,const char *string,cJSON *newitem);


cJSON_Duplicate                 PROTO :DWORD, :DWORD ; (const cJSON *item, cJSON_bool recurse);
cJSON_Compare                   PROTO :DWORD, :DWORD, :DWORD ; (const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive);
cJSON_Minify                    PROTO :DWORD ; (char *json);


cJSON_malloc                    PROTO :DWORD ; (size_t size);
cJSON_free                      PROTO :DWORD ; (void *object);
































