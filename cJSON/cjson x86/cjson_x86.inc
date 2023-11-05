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

; cjson_x86.inc converted from cJSON source for assembler by fearless 2023
; www.github.com/mrfearless

include msvcrt.inc
includelib ucrt.lib
includelib vcruntime.lib

cJSON_Version                   PROTO STDCALL
cJSON_InitHooks                 PROTO STDCALL hooks:DWORD
cJSON_Parse                     PROTO STDCALL value:DWORD
cJSON_ParseWithOpts             PROTO STDCALL value:DWORD, return_parse_end:DWORD, require_null_terminated:DWORD
cJSON_ParseWithLength           PROTO STDCALL value:DWORD, buffer_length:DWORD
cJSON_ParseWithLengthOpts       PROTO STDCALL value:DWORD, buffer_length:DWORD, return_parse_end:DWORD, require_null_terminated:DWORD
cJSON_Print                     PROTO STDCALL item:DWORD 
cJSON_PrintUnformatted          PROTO STDCALL item:DWORD
cJSON_PrintBuffered             PROTO STDCALL item:DWORD, prebuffer:DWORD, fmt:DWORD
cJSON_PrintPreallocated         PROTO STDCALL item:DWORD, buffer:DWORD, bufferlength:DWORD, format:DWORD
cJSON_Delete                    PROTO STDCALL item:DWORD
cJSON_GetArraySize              PROTO STDCALL array:DWORD
cJSON_GetArrayItem              PROTO STDCALL array:DWORD, index:DWORD
cJSON_GetObjectItem             PROTO STDCALL object:DWORD, string:DWORD
cJSON_GetObjectItemCaseSensitive PROTO STDCALL object:DWORD, string:DWORD
cJSON_HasObjectItem             PROTO STDCALL object:DWORD, string:DWORD
cJSON_GetErrorPtr               PROTO STDCALL

cJSON_GetStringValue            PROTO STDCALL item:DWORD
cJSON_GetNumberValue            PROTO STDCALL item:DWORD

; These functions check the type of an item
cJSON_IsInvalid                 PROTO STDCALL item:DWORD
cJSON_IsFalse                   PROTO STDCALL item:DWORD
cJSON_IsTrue                    PROTO STDCALL item:DWORD
cJSON_IsBool                    PROTO STDCALL item:DWORD
cJSON_IsNull                    PROTO STDCALL item:DWORD
cJSON_IsNumber                  PROTO STDCALL item:DWORD
cJSON_IsString                  PROTO STDCALL item:DWORD
cJSON_IsArray                   PROTO STDCALL item:DWORD
cJSON_IsObject                  PROTO STDCALL item:DWORD
cJSON_IsRaw                     PROTO STDCALL item:DWORD

; These calls create a cJSON item of the appropriate type.
cJSON_CreateNull                PROTO STDCALL
cJSON_CreateTrue                PROTO STDCALL
cJSON_CreateFalse               PROTO STDCALL
cJSON_CreateBool                PROTO STDCALL boolean:DWORD
cJSON_CreateNumber              PROTO STDCALL num:QWORD ; (double num);
cJSON_CreateString              PROTO STDCALL string:DWORD
; raw json 
cJSON_CreateRaw                 PROTO STDCALL raw:DWORD
cJSON_CreateArray               PROTO STDCALL
cJSON_CreateObject              PROTO STDCALL

; Create a string where valuestring references a string so it will not be freed by cJSON_Delete
cJSON_CreateStringReference     PROTO STDCALL string:DWORD

; Create an object/arrray that only references it's elements so they will not be freed by cJSON_Delete
cJSON_CreateObjectReference     PROTO STDCALL child:DWORD
cJSON_CreateArrayReference      PROTO STDCALL child:DWORD

; These utilities create an Array of count items.
cJSON_CreateIntArray            PROTO STDCALL numbers:DWORD, count:DWORD ; (const int *numbers, int count);
cJSON_CreateFloatArray          PROTO STDCALL numbers:DWORD, count:DWORD ; (const float *numbers, int count);
cJSON_CreateDoubleArray         PROTO STDCALL numbers:DWORD, count:DWORD ; (const double *numbers, int count);
cJSON_CreateStringArray         PROTO STDCALL strings:DWORD, count:DWORD ; (const char **strings, int count);

; Append item to the specified array/object.
cJSON_AddItemToArray            PROTO STDCALL array:DWORD, item:DWORD 
cJSON_AddItemToObject           PROTO STDCALL object:DWORD, string:DWORD, item:DWORD
; Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the; cJSON object.
; WARNING: When this function was used, make sure to always check that (item->type & cJSON_StringIsConst); is zero before writing to `item->string`
cJSON_AddItemToObjectCS         PROTO STDCALL object:DWORD, string:DWORD, item:DWORD
; Append reference to item to the specified array/object. Use this when you want to add an existing cJSON to a new cJSON, but don't want to corrupt your existing cJSON.
cJSON_AddItemReferenceToArray   PROTO STDCALL array:DWORD, item:DWORD
cJSON_AddItemReferenceToObject  PROTO STDCALL object:DWORD, string:DWORD, item:DWORD

; Remove/Detatch items from Arrays/Objects.
cJSON_DetachItemViaPointer      PROTO STDCALL parent:DWORD, item:DWORD
cJSON_DetachItemFromArray       PROTO STDCALL array:DWORD, which:DWORD
cJSON_DeleteItemFromArray       PROTO STDCALL array:DWORD, which:DWORD
cJSON_DetachItemFromObject      PROTO STDCALL object:DWORD, string:DWORD
cJSON_DetachItemFromObjectCaseSensitive PROTO STDCALL object:DWORD, string:DWORD
cJSON_DeleteItemFromObject      PROTO STDCALL object:DWORD, string:DWORD
cJSON_DeleteItemFromObjectCaseSensitive PROTO STDCALL object:DWORD, string:DWORD

; Update array items.
cJSON_InsertItemInArray         PROTO STDCALL array:DWORD, which:DWORD, newitem:DWORD
cJSON_ReplaceItemViaPointer     PROTO STDCALL parent:DWORD, item:DWORD, replacement:DWORD
cJSON_ReplaceItemInArray        PROTO STDCALL array:DWORD, which:DWORD, newitem:DWORD
cJSON_ReplaceItemInObject       PROTO STDCALL object:DWORD, string:DWORD, newitem:DWORD
cJSON_ReplaceItemInObjectCaseSensitive PROTO STDCALL object:DWORD, string:DWORD, newitem:DWORD


cJSON_Duplicate                 PROTO STDCALL item:DWORD, recurse:DWORD
cJSON_Compare                   PROTO STDCALL a:DWORD, b:DWORD, case_sensitive:DWORD
cJSON_Minify                    PROTO STDCALL json:DWORD ; (char *json);

; Helper functions for creating and adding items to an object at the same time.
; They return the added item or NULL on failure.
cJSON_AddNullToObject           PROTO STDCALL object:DWORD, itemname:DWORD
cJSON_AddTrueToObject           PROTO STDCALL object:DWORD, itemname:DWORD
cJSON_AddFalseToObject          PROTO STDCALL object:DWORD, itemname:DWORD
cJSON_AddBoolToObject           PROTO STDCALL object:DWORD, itemname:DWORD, boolean:DWORD
cJSON_AddNumberToObject         PROTO STDCALL object:DWORD, itemname:DWORD, number:QWORD ; (cJSON * const object, const char * const name, const double number);
cJSON_AddStringToObject         PROTO STDCALL object:DWORD, itemname:DWORD, string:DWORD
cJSON_AddRawToObject            PROTO STDCALL object:DWORD, itemname:DWORD, raw:DWORD
cJSON_AddObjectToObject         PROTO STDCALL object:DWORD, itemname:DWORD
cJSON_AddArrayToObject          PROTO STDCALL object:DWORD, itemname:DWORD

cJSON_SetNumberHelper           PROTO STDCALL object:DWORD, number:QWORD ; (cJSON *object, double number);
cJSON_SetValuestring            PROTO STDCALL object:DWORD, valuestring:DWORD

cJSON_malloc                    PROTO STDCALL dwsize:DWORD ; (size_t size);
cJSON_free                      PROTO STDCALL object:DWORD ; (void *object);

; Extra helper functions i wrote - fearless
cJSON_AddObjectToArray          PROTO STDCALL item:DWORD
cJSON_AddArrayToArray           PROTO STDCALL item:DWORD
cJSON_AddNullToArray            PROTO STDCALL item:DWORD
cJSON_AddTrueToArray            PROTO STDCALL item:DWORD
cJSON_AddFalseToArray           PROTO STDCALL item:DWORD
cJSON_AddBoolToArray            PROTO STDCALL item:DWORD, dwBoolValue:DWORD
cJSON_AddNumberToArray          PROTO STDCALL item:DWORD, dwNumberValue:DWORD
cJSON_AddStringToArray          PROTO STDCALL item:DWORD, lpszString:DWORD
cJSON_AddRawToArray             PROTO STDCALL item:DWORD, lpszRawJson:DWORD

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

.CONST
; cJSON project version
CJSON_VERSION_MAJOR             EQU 1
CJSON_VERSION_MINOR             EQU 7
CJSON_VERSION_PATCH             EQU 16

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

;cJSON_AddObjectToArray PROC item:DWORD
;     LOCAL hJSONObject:DWORD
;     Invoke cJSON_CreateObject
;     mov hJSONObject, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObject
;     mov eax, hJSONObject
;     ret
;cJSON_AddObjectToArray ENDP

;cJSON_AddArrayToArray PROC item:DWORD
;     LOCAL hJSONObjectArray:DWORD
;     Invoke cJSON_CreateArray
;     mov hJSONObjectArray, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectArray
;     mov eax, hJSONObjectArray
;     ret
;cJSON_AddArrayToArray ENDP

;cJSON_AddNullToArray PROC item:DWORD
;     LOCAL hJSONObjectNull:DWORD
;     Invoke cJSON_CreateNull
;     mov hJSONObjectNull, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectNull
;     mov eax, hJSONObjectNull
;     ret
;cJSON_AddNullToArray ENDP

;cJSON_AddTrueToArray PROC item:DWORD
;     LOCAL hJSONObjectTrue:DWORD
;     Invoke cJSON_CreateTrue
;     mov hJSONObjectTrue, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectTrue
;     mov eax, hJSONObjectTrue
;     ret
;cJSON_AddTrueToArray ENDP

;cJSON_AddFalseToArray PROC item:DWORD
;     LOCAL hJSONObjectFalse:DWORD
;     Invoke cJSON_CreateFalse
;     mov hJSONObjectFalse, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectFalse
;     mov eax, hJSONObjectFalse
;     ret
;cJSON_AddFalseToArray ENDP

;cJSON_AddBoolToArray PROC item:DWORD, dwBoolValue:DWORD
;     LOCAL hJSONObjectBool:DWORD
;     Invoke cJSON_CreateBool, dwBoolValue
;     mov hJSONObjectBool, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectBool
;     mov eax, hJSONObjectBool
;     ret
;cJSON_AddBoolToArray ENDP

;cJSON_AddNumberToArray PROC item:DWORD, dwNumberValue:DWORD
;     LOCAL hJSONObjectNumber:DWORD
;     LOCAL qwNumberValue:QWORD
;     mov eax, dwNumberValue
;     mov dword ptr [qwNumberValue+0], eax
;     mov dword ptr [qwNumberValue+4], eax
;     Invoke cJSON_CreateNumber, qwNumberValue
;     mov hJSONObjectNumber, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectNumber
;     mov eax, hJSONObjectNumber
;     ret
;cJSON_AddNumberToArray ENDP

;cJSON_AddStringToArray PROC item:DWORD, lpszString:DWORD
;     LOCAL hJSONObjectString:DWORD
;     Invoke cJSON_CreateString, lpszString
;     mov hJSONObjectString, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectString
;     mov eax, hJSONObjectString
;     ret
;cJSON_AddStringToArray ENDP

;cJSON_AddRawToArray PROC item:DWORD, lpszRawJson:DWORD
;     LOCAL hJSONObjectRaw:DWORD
;     Invoke cJSON_CreateRaw, lpszRawJson
;     mov hJSONObjectRaw, eax
;     Invoke cJSON_AddItemToArray, item, hJSONObjectRaw
;     mov eax, hJSONObjectRaw
;     ret
;cJSON_AddRawToArray ENDP


























