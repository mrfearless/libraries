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
; https://github.com/DaveGamble/cJSON
;

; cjson_x64.inc converted from cJSON source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

cJSON_Version                   PROTO
cJSON_InitHooks                 PROTO hooks:QWORD
cJSON_Parse                     PROTO value:QWORD
cJSON_ParseWithOpts             PROTO value:QWORD, return_parse_end:QWORD, require_null_terminated:QWORD
cJSON_ParseWithLength           PROTO value:QWORD, buffer_length:QWORD
cJSON_ParseWithLengthOpts       PROTO value:QWORD, buffer_length:QWORD, return_parse_end:QWORD, require_null_terminated:QWORD
cJSON_Print                     PROTO item:QWORD 
cJSON_PrintUnformatted          PROTO item:QWORD
cJSON_PrintBuffered             PROTO item:QWORD, prebuffer:QWORD, fmt:QWORD
cJSON_PrintPreallocated         PROTO item:QWORD, buffer:QWORD, bufferlength:QWORD, format:QWORD
cJSON_Delete                    PROTO item:QWORD
cJSON_GetArraySize              PROTO array:QWORD
cJSON_GetArrayItem              PROTO array:QWORD, index:QWORD
cJSON_GetObjectItem             PROTO object:QWORD, string:QWORD
cJSON_GetObjectItemCaseSensitive PROTO object:QWORD, string:QWORD
cJSON_HasObjectItem             PROTO object:QWORD, string:QWORD
cJSON_GetErrorPtr               PROTO

cJSON_GetStringValue            PROTO item:QWORD
cJSON_GetNumberValue            PROTO item:QWORD

; These functions check the type of an item
cJSON_IsInvalid                 PROTO item:QWORD
cJSON_IsFalse                   PROTO item:QWORD
cJSON_IsTrue                    PROTO item:QWORD
cJSON_IsBool                    PROTO item:QWORD
cJSON_IsNull                    PROTO item:QWORD
cJSON_IsNumber                  PROTO item:QWORD
cJSON_IsString                  PROTO item:QWORD
cJSON_IsArray                   PROTO item:QWORD
cJSON_IsObject                  PROTO item:QWORD
cJSON_IsRaw                     PROTO item:QWORD

; These calls create a cJSON item of the appropriate type.
cJSON_CreateNull                PROTO
cJSON_CreateTrue                PROTO
cJSON_CreateFalse               PROTO
cJSON_CreateBool                PROTO boolean:QWORD
cJSON_CreateNumber              PROTO num:QWORD ; (double num);
cJSON_CreateString              PROTO string:QWORD
; raw json 
cJSON_CreateRaw                 PROTO raw:QWORD
cJSON_CreateArray               PROTO
cJSON_CreateObject              PROTO

; Create a string where valuestring references a string so it will not be freed by cJSON_Delete
cJSON_CreateStringReference     PROTO string:QWORD

; Create an object/arrray that only references it's elements so they will not be freed by cJSON_Delete
cJSON_CreateObjectReference     PROTO child:QWORD
cJSON_CreateArrayReference      PROTO child:QWORD

; These utilities create an Array of count items.
cJSON_CreateIntArray            PROTO numbers:QWORD, count:QWORD ; (const int *numbers, int count);
cJSON_CreateFloatArray          PROTO numbers:QWORD, count:QWORD ; (const float *numbers, int count);
cJSON_CreateDoubleArray         PROTO numbers:QWORD, count:QWORD ; (const double *numbers, int count);
cJSON_CreateStringArray         PROTO strings:QWORD, count:QWORD ; (const char **strings, int count);

; Append item to the specified array/object.
cJSON_AddItemToArray            PROTO array:QWORD, item:QWORD 
cJSON_AddItemToObject           PROTO object:QWORD, string:QWORD, item:QWORD
; Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the; cJSON object.
; WARNING: When this function was used, make sure to always check that (item->type & cJSON_StringIsConst); is zero before writing to `item->string`
cJSON_AddItemToObjectCS         PROTO object:QWORD, string:QWORD, item:QWORD
; Append reference to item to the specified array/object. Use this when you want to add an existing cJSON to a new cJSON, but don't want to corrupt your existing cJSON.
cJSON_AddItemReferenceToArray   PROTO array:QWORD, item:QWORD
cJSON_AddItemReferenceToObject  PROTO object:QWORD, string:QWORD, item:QWORD

; Remove/Detatch items from Arrays/Objects.
cJSON_DetachItemViaPointer      PROTO parent:QWORD, item:QWORD
cJSON_DetachItemFromArray       PROTO array:QWORD, which:QWORD
cJSON_DeleteItemFromArray       PROTO array:QWORD, which:QWORD
cJSON_DetachItemFromObject      PROTO object:QWORD, string:QWORD
cJSON_DetachItemFromObjectCaseSensitive PROTO object:QWORD, string:QWORD
cJSON_DeleteItemFromObject      PROTO object:QWORD, string:QWORD
cJSON_DeleteItemFromObjectCaseSensitive PROTO object:QWORD, string:QWORD

; Update array items.
cJSON_InsertItemInArray         PROTO array:QWORD, which:QWORD, newitem:QWORD
cJSON_ReplaceItemViaPointer     PROTO parent:QWORD, item:QWORD, replacement:QWORD
cJSON_ReplaceItemInArray        PROTO array:QWORD, which:QWORD, newitem:QWORD
cJSON_ReplaceItemInObject       PROTO object:QWORD, string:QWORD, newitem:QWORD
cJSON_ReplaceItemInObjectCaseSensitive PROTO object:QWORD, string:QWORD, newitem:QWORD


cJSON_Duplicate                 PROTO item:QWORD, recurse:QWORD
cJSON_Compare                   PROTO a:QWORD, b:QWORD, case_sensitive:QWORD
cJSON_Minify                    PROTO json:QWORD ; (char *json);

; Helper functions for creating and adding items to an object at the same time.
; They return the added item or NULL on failure.
cJSON_AddNullToObject           PROTO object:QWORD, itemname:QWORD
cJSON_AddTrueToObject           PROTO object:QWORD, itemname:QWORD
cJSON_AddFalseToObject          PROTO object:QWORD, itemname:QWORD
cJSON_AddBoolToObject           PROTO object:QWORD, itemname:QWORD, boolean:QWORD
cJSON_AddNumberToObject         PROTO object:QWORD, itemname:QWORD, number:QWORD ; (cJSON * const object, const char * const name, const double number);
cJSON_AddStringToObject         PROTO object:QWORD, itemname:QWORD, string:QWORD
cJSON_AddRawToObject            PROTO object:QWORD, itemname:QWORD, raw:QWORD
cJSON_AddObjectToObject         PROTO object:QWORD, itemname:QWORD
cJSON_AddArrayToObject          PROTO object:QWORD, itemname:QWORD

cJSON_SetNumberHelper           PROTO object:QWORD, number:QWORD ; (cJSON *object, double number);
cJSON_SetValuestring            PROTO object:QWORD, valuestring:QWORD

cJSON_malloc                    PROTO dwsize:QWORD ; (size_t size);
cJSON_free                      PROTO object:QWORD ; (void *object);

; Extra helper functions i wrote - fearless
cJSON_AddObjectToArray          PROTO item:QWORD
cJSON_AddArrayToArray           PROTO item:QWORD
cJSON_AddNullToArray            PROTO item:QWORD
cJSON_AddTrueToArray            PROTO item:QWORD
cJSON_AddFalseToArray           PROTO item:QWORD
cJSON_AddBoolToArray            PROTO item:QWORD, dwBoolValue:QWORD
cJSON_AddNumberToArray          PROTO item:QWORD, dwNumberValue:QWORD
cJSON_AddStringToArray          PROTO item:QWORD, lpszString:QWORD
cJSON_AddRawToArray             PROTO item:QWORD, lpszRawJson:QWORD

; The cJSON structure:
cJSON                           STRUCT 8
    next                        QWORD ?
    prev                        QWORD ?
    child                       QWORD ?
    itemtype                    QWORD ?
    valuestring                 QWORD ?
    valueint                    QWORD ?
    valuedouble                 QWORD ?
    itemstring                  QWORD ?
cJSON                           ENDS

cJSON_Hooks                     STRUCT 8
    malloc_fn                   QWORD ?
    free_fn                     QWORD ?
cJSON_Hooks                     ENDS

cJSON_bool                      TYPEDEF QWORD

.CONST
; cJSON project version
CJSON_VERSION_MAJOR             EQU 1
CJSON_VERSION_MINOR             EQU 7
CJSON_VERSION_PATCH             EQU 12

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

CJSON_NESTING_LIMIT             EQU 1000

; Extra helper functions i wrote - fearless
; uncomment to use

;.CODE

;cJSON_AddObjectToArray PROC FRAME item:QWORD
;     LOCAL hJSONObject:QWORD
;     Invoke cJSON_CreateObject
;     mov hJSONObject, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObject
;     mov rax, hJSONObject
;     ret
;cJSON_AddObjectToArray ENDP

;cJSON_AddArrayToArray PROC FRAME item:QWORD
;     LOCAL hJSONObjectArray:QWORD
;     Invoke cJSON_CreateArray
;     mov hJSONObjectArray, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectArray
;     mov rax, hJSONObjectArray
;     ret
;cJSON_AddArrayToArray ENDP

;cJSON_AddNullToArray PROC FRAME item:QWORD
;     LOCAL hJSONObjectNull:QWORD
;     Invoke cJSON_CreateNull
;     mov hJSONObjectNull, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectNull
;     mov rax, hJSONObjectNull
;     ret
;cJSON_AddNullToArray ENDP

;cJSON_AddTrueToArray PROC FRAME item:QWORD
;     LOCAL hJSONObjectTrue:QWORD
;     Invoke cJSON_CreateTrue
;     mov hJSONObjectTrue, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectTrue
;     mov rax, hJSONObjectTrue
;     ret
;cJSON_AddTrueToArray ENDP

;cJSON_AddFalseToArray PROC FRAME item:QWORD
;     LOCAL hJSONObjectFalse:QWORD
;     Invoke cJSON_CreateFalse
;     mov hJSONObjectFalse, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectFalse
;     mov rax, hJSONObjectFalse
;     ret
;cJSON_AddFalseToArray ENDP

;cJSON_AddBoolToArray PROC FRAME item:QWORD, qwBoolValue:QWORD
;     LOCAL hJSONObjectBool:QWORD
;     Invoke cJSON_CreateBool, qwBoolValue
;     mov hJSONObjectBool, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectBool
;     mov rax, hJSONObjectBool
;     ret
;cJSON_AddBoolToArray ENDP

;cJSON_AddNumberToArray PROC FRAME item:QWORD, qwNumberValue:QWORD
;     LOCAL hJSONObjectNumber:QWORD
;     Invoke cJSON_CreateNumber, qwNumberValue
;     mov hJSONObjectNumber, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectNumber
;     mov rax, hJSONObjectNumber
;     ret
;cJSON_AddNumberToArray ENDP

;cJSON_AddStringToArray PROC FRAME item:QWORD, lpszString:QWORD
;     LOCAL hJSONObjectString:QWORD
;     Invoke cJSON_CreateString, lpszString
;     mov hJSONObjectString, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectString
;     mov rax, hJSONObjectString
;     ret
;cJSON_AddStringToArray ENDP

;cJSON_AddRawToArray PROC FRAME item:QWORD, lpszRawJson:QWORD
;     LOCAL hJSONObjectRaw:QWORD
;     Invoke cJSON_CreateRaw, lpszRawJson
;     mov hJSONObjectRaw, rax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectRaw
;     mov rax, hJSONObjectRaw
;     ret
;cJSON_AddRawToArray ENDP


























