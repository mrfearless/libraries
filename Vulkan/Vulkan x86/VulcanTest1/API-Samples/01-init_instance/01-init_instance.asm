; Vulkan API-Samples:
;
; 01-init_instance
;
; Compile and link settings:
; 
; \masm32\bin\ml /c /coff /I"\masm32\include" 01-init_instance.asm
; \masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 01-init_instance.obj


;-----------------------------------------------------------------------------------------
; 01-init_instance Includes, Libraries, Prototypes, Structures & Macros
;-----------------------------------------------------------------------------------------
include \masm32\include\masm32rt.inc

include advapi32.inc
includelib advapi32.lib

include cfgmgr32.inc
includelib cfgmgr32.lib

includelib msvcrt14.lib
includelib libcmt.lib
includelib ucrt.lib
includelib vcruntime.lib

include Vulkan.inc
includelib Vulkan.lib

FP4 MACRO value
    LOCAL vname
    .data
    align 4
      vname REAL4 value
    .code
    EXITM <vname>
ENDM


.DATA
;-----------------------------------------------------------------------------------------
; 01-init_instance Initialized Data
;-----------------------------------------------------------------------------------------
app_info            VkApplicationInfo <>
inst_info           VkInstanceCreateInfo <>

szCRLF              DB 13,10,0
APP_SHORT_NAME      DB "[VulkanAsm] 01-init_instance.asm",0
szErrorFindICD      DB "Cannot find a compatible Vulkan ICD",0
szErrorUnknown      DB "Unknown error occured",0
szSuccess           DB "Success",0


szStep1             DB "- Initialize the VkApplicationInfo structure",0
szStep2             DB "- Initialize the VkInstanceCreateInfo structure",0
szStep3             DB "- Call vkCreateInstance",0
szStep4             DB "- Result: ",0
szStep5             DB "- Call vkDestroyInstance",0

.DATA?
;-----------------------------------------------------------------------------------------
; 01-init_instance Uninitialized Data
;-----------------------------------------------------------------------------------------
inst                VkInstance ?
res                 VkResult ?


.CODE
;-----------------------------------------------------------------------------------------
; 01-init_instance
;-----------------------------------------------------------------------------------------

start:
    
    cls
    print Addr APP_SHORT_NAME,13,10,13,10
    
    Invoke RtlZeroMemory, Addr app_info, SIZEOF app_info
    Invoke RtlZeroMemory, Addr inst_info, SIZEOF inst_info
    
    ; VULKAN_KEY_START
    
    ; Initialize the VkApplicationInfo structure
    print Addr szStep1,13,10
    mov app_info.sType, VK_STRUCTURE_TYPE_APPLICATION_INFO
    mov app_info.pNext, NULL
    lea eax, APP_SHORT_NAME
    mov app_info.pApplicationName, eax ;APP_SHORT_NAME
    mov app_info.applicationVersion, 1
    lea eax, APP_SHORT_NAME
    mov app_info.pEngineName, eax ; APP_SHORT_NAME
    mov app_info.engineVersion, 1
    mov app_info.apiVersion, VK_API_VERSION_1_0

    ; Initialize the VkInstanceCreateInfo structure
    print Addr szStep2,13,10
    mov inst_info.sType, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO
    mov inst_info.pNext, NULL
    mov inst_info.flags, 0
    lea eax, app_info
    mov inst_info.pApplicationInfo, eax ;&app_info;
    mov inst_info.enabledExtensionCount, 0
    mov inst_info.ppEnabledExtensionNames, NULL
    mov inst_info.enabledLayerCount, 0
    mov inst_info.ppEnabledLayerNames, NULL
    
    ; Call vkCreateInstance
    print Addr szStep3,13,10
    Invoke vkCreateInstance, Addr inst_info, NULL, Addr inst
    mov res, eax
    
    ; Output result: 
    print Addr szStep4
    .IF res == VK_SUCCESS
        print Addr szSuccess,13,10
        ; continue onwards
    .ELSEIF res == VK_ERROR_INCOMPATIBLE_DRIVER
        print Addr szErrorFindICD,13,10
        jmp ExitVulkan ; exit
    .ELSE
        print Addr szErrorUnknown,13,10
        jmp ExitVulkan ; exit
    .ENDIF    

    ; Call vkDestroyInstance
    print Addr szStep5,13,10
    Invoke vkDestroyInstance, inst, NULL
    
    ; VULKAN_KEY_END
    
ExitVulkan:

    print Addr szCRLF
    ; Pause for user
    inkey

    Invoke ExitProcess,0
    ret

END start