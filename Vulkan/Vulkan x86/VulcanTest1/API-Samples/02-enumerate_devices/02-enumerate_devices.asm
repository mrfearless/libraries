; Vulkan API-Samples:
;
; 02-enumerate_devices
;
; Compile and link settings:
; 
; \masm32\bin\ml /c /coff /I"\masm32\include" 02-enumerate_devices.asm
; \masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 02-enumerate_devices.obj


;-----------------------------------------------------------------------------------------
; 02-enumerate_devices Includes, Libraries, Prototypes, Structures & Macros
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

init_instance       PROTO :DWORD


.DATA
;-----------------------------------------------------------------------------------------
; 02-enumerate_devices Initialized Data
;-----------------------------------------------------------------------------------------
app_info            VkApplicationInfo <>
inst_info           VkInstanceCreateInfo <>

szCRLF              DB 13,10,0
APP_SHORT_NAME      DB "[VulkanAsm] 02-enumerate_devices.asm",0

szErrorInitInstance DB "Error Initializing Instance",0
szErrorEnumDevices  DB "Error Enumeratating Physical Devices",0

szGpuCount          DB "- GPU Count: ",0
szStep1             DB "- Enumerate Physical Devices",0
szStep2             DB "- Enumerate Physical Devices Into Array",0
szStep3             DB "- Call vkDestroyInstance",0


.DATA?
;-----------------------------------------------------------------------------------------
; 02-enumerate_devices Uninitialized Data
;-----------------------------------------------------------------------------------------
inst                VkInstance ?
res                 VkResult ?
gpu_count           DWORD ?
gpus                VkPhysicalDevice 16 DUP (?)


.CODE
;-----------------------------------------------------------------------------------------
; 02-enumerate_devices
;-----------------------------------------------------------------------------------------

start:
    
    cls
    print Addr APP_SHORT_NAME,13,10,13,10
    
    Invoke init_instance, Addr APP_SHORT_NAME
    .IF eax != VK_SUCCESS
        print Addr szErrorInitInstance,13,10
        jmp ExitVulkan
    .ENDIF
 
    Invoke RtlZeroMemory, Addr gpus, SIZEOF gpus
 
    ; VULKAN_KEY_START
 
    ; Enumerate Physical Devices
    print Addr szStep1,13,10
    mov gpu_count, 1
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, NULL
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorEnumDevices,13,10
        jmp ExitVulkan
    .ENDIF
    print Addr szGpuCount
    print str$(gpu_count),13,10
    
    ; Enumerate Physical Devices with data (gpus)
    print Addr szStep2,13,10
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, Addr gpus
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorEnumDevices,13,10
        jmp ExitVulkan
    .ENDIF
    
    ; VULKAN_KEY_END
    
    ; Call vkDestroyInstance
    print Addr szStep3,13,10
    Invoke vkDestroyInstance, inst, NULL

ExitVulkan:

    print Addr szCRLF
    ; Pause for user
    inkey

    Invoke ExitProcess,0
    ret



;-----------------------------------------------------------------------------------------
; init_instance - similar to 01-init_instance
;-----------------------------------------------------------------------------------------
init_instance PROC lpszAppShortName:DWORD
    Invoke RtlZeroMemory, Addr app_info, SIZEOF app_info
    Invoke RtlZeroMemory, Addr inst_info, SIZEOF inst_info

    ; Initialize the VkApplicationInfo structure
    mov app_info.sType, VK_STRUCTURE_TYPE_APPLICATION_INFO
    mov app_info.pNext, NULL
    mov eax, lpszAppShortName
    mov app_info.pApplicationName, eax ;APP_SHORT_NAME
    mov app_info.applicationVersion, 1
    mov eax, lpszAppShortName
    mov app_info.pEngineName, eax ; APP_SHORT_NAME
    mov app_info.engineVersion, 1
    mov app_info.apiVersion, VK_API_VERSION_1_0

    ; Initialize the VkInstanceCreateInfo structure
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
    Invoke vkCreateInstance, Addr inst_info, NULL, Addr inst
    ; eax contains result  
    ret
init_instance ENDP





END start
