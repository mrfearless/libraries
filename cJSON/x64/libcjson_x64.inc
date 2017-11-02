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

; libcjson_x64.inc converted from cJSON.h for masm by fearless 2017

;include msvcrt.inc
;includelib msvcrt.lib
includelib msvcrt14.lib



cJSON_Version                   PROTO 
cJSON_InitHooks                 PROTO :QWORD ; (cJSON_Hooks* hooks);
cJSON_Parse                     PROTO :QWORD ; (const char *value);
cJSON_ParseWithOpts             PROTO :QWORD, :QWORD, :QWORD ; (const char *value, const char **return_parse_end, cJSON_bool require_null_terminated);
cJSON_Print                     PROTO :QWORD ; (const cJSON *item);
cJSON_PrintUnformatted          PROTO :QWORD ; (const cJSON *item);
cJSON_PrintBuffered             PROTO :QWORD, :QWORD, :QWORD ; (const cJSON *item, int prebuffer, cJSON_bool fmt);
cJSON_PrintPreallocated         PROTO :QWORD, :QWORD, :QWORD, :QWORD ; (cJSON *item, char *buffer, const int length, const cJSON_bool format);
cJSON_Delete                    PROTO :QWORD ; (cJSON *c);
cJSON_GetArraySize              PROTO :QWORD ; (const cJSON *array);
cJSON_GetArrayItem      PROTO :QWORD, :QWORD ; (const cJSON *array, int index);
cJSON_GetObjectItem             PROTO :QWORD, :QWORD ; (const cJSON * const object, const char * const string);
cJSON_GetObjectItemCaseSensitive PROTO :QWORD, :QWORD ; (const cJSON * const object, const char * const string);
cJSON_HasObjectItem             PROTO :QWORD, :QWORD ; (const cJSON *object, const char *string);
cJSON_GetErrorPtr               PROTO



; These functions check the type of an item
cJSON_IsInvalid                 PROTO :QWORD ; (const cJSON * const item);
cJSON_IsFalse                   PROTO :QWORD ; (const cJSON * const item);
cJSON_IsTrue                    PROTO :QWORD ; (const cJSON * const item);
cJSON_IsBool                    PROTO :QWORD ; (const cJSON * const item);
cJSON_IsNull                    PROTO :QWORD ; (const cJSON * const item);
cJSON_IsNumber                  PROTO :QWORD ; (const cJSON * const item);
cJSON_IsString                  PROTO :QWORD ; (const cJSON * const item);
cJSON_IsArray                   PROTO :QWORD ; (const cJSON * const item);
cJSON_IsObject                  PROTO :QWORD ; (const cJSON * const item);
cJSON_IsRaw                     PROTO :QWORD ; (const cJSON * const item);

; These calls create a cJSON item of the appropriate type.
cJSON_CreateNull                PROTO
cJSON_CreateTrue                PROTO
cJSON_CreateFalse               PROTO
cJSON_CreateBool                PROTO :QWORD ; (cJSON_bool boolean);
cJSON_CreateNumber              PROTO :QWORD ; (double num);
cJSON_CreateString              PROTO :QWORD ; (const char *string);
; raw json 
cJSON_CreateRaw                 PROTO :QWORD ; (const char *raw);
cJSON_CreateArray               PROTO
cJSON_CreateObject              PROTO

; These utilities create an Array of count items.
cJSON_CreateIntArray            PROTO :QWORD, :QWORD ; (const int *numbers, int count);
cJSON_CreateFloatArray          PROTO :QWORD, :QWORD ; (const float *numbers, int count);
cJSON_CreateDoubleArray         PROTO :QWORD, :QWORD ; (const double *numbers, int count);
cJSON_CreateStringArray         PROTO :QWORD, :QWORD ; (const char **strings, int count);

; Append item to the specified array/object.
cJSON_AddItemToArray            PROTO :QWORD, :QWORD ; (cJSON *array, cJSON *item);
cJSON_AddItemToObject           PROTO :QWORD, :QWORD, :QWORD ; (cJSON *object, const char *string, cJSON *item);
; Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the; cJSON object.
; WARNING: When this function was used, make sure to always check that (item->type & cJSON_StringIsConst); is zero before writing to `item->string`
cJSON_AddItemToObjectCS         PROTO :QWORD, :QWORD, :QWORD ; (cJSON *object, const char *string, cJSON *item);
; Append reference to item to the specified array/object. Use this when you want to add an existing cJSON to a new cJSON, but don't want to corrupt your existing cJSON.
cJSON_AddItemReferenceToArray   PROTO :QWORD, :QWORD ; (cJSON *array, cJSON *item);
cJSON_AddItemReferenceToObject  PROTO :QWORD, :QWORD, :QWORD ; (cJSON *object, const char *string, cJSON *item);

; Remove/Detatch items from Arrays/Objects.
cJSON_DetachItemViaPointer      PROTO :QWORD, :QWORD ; (cJSON *parent, cJSON * const item);
cJSON_DetachItemFromArray       PROTO :QWORD, :QWORD ; (cJSON *array, int which);
cJSON_DeleteItemFromArray       PROTO :QWORD, :QWORD ; (cJSON *array, int which);
cJSON_DetachItemFromObject      PROTO :QWORD, :QWORD ; (cJSON *object, const char *string);
cJSON_DetachItemFromObjectCaseSensitive PROTO :QWORD, :QWORD ; (cJSON *object, const char *string);
cJSON_DeleteItemFromObject      PROTO :QWORD, :QWORD ; (cJSON *object, const char *string);
cJSON_DeleteItemFromObjectCaseSensitive PROTO :QWORD, :QWORD ; (cJSON *object, const char *string);

; Update array items.
cJSON_InsertItemInArray         PROTO :QWORD, :QWORD, :QWORD ; (cJSON *array, int which, cJSON *newitem);  Shifts pre-existing items to the right.
cJSON_ReplaceItemViaPointer     PROTO :QWORD, :QWORD, :QWORD ; (cJSON * const parent, cJSON * const item, cJSON * replacement);
cJSON_ReplaceItemInArray        PROTO :QWORD, :QWORD, :QWORD ; (cJSON *array, int which, cJSON *newitem);
cJSON_ReplaceItemInObject       PROTO :QWORD, :QWORD, :QWORD ; (cJSON *object,const char *string,cJSON *newitem);
cJSON_ReplaceItemInObjectCaseSensitive PROTO :QWORD, :QWORD, :QWORD ; (cJSON *object,const char *string,cJSON *newitem);


cJSON_Duplicate                 PROTO :QWORD, :QWORD ; (const cJSON *item, cJSON_bool recurse);
cJSON_Compare                   PROTO :QWORD, :QWORD, :QWORD ; (const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive);
cJSON_Minify                    PROTO :QWORD ; (char *json);


cJSON_malloc                    PROTO :QWORD ; (size_t size);
cJSON_free                      PROTO :QWORD ; (void *object);


; The cJSON structure:
cJSON                           STRUCT 
    next                        QWORD ?
    prev                        QWORD ?
    child                       QWORD ?
    itemtype                    QWORD ?
    valuestring                 QWORD ?
    valueint                    QWORD ?
    valuedouble                 QWORD ?
    itemstring                  QWORD ?
cJSON                           ENDS

cJSON_Hooks                     STRUCT
    malloc_fn                   QWORD ?
    free_fn                     QWORD ?
cJSON_Hooks                     ENDS

cJSON_bool                      TYPEDEF QWORD



.CONST
CJSON_NESTING_LIMIT             EQU 1000

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







































