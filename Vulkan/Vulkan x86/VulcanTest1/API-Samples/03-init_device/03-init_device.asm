; Vulkan API-Samples:
;
; 03-init_device
;
; Compile and link settings:
; 
; \masm32\bin\ml /c /coff /I"\masm32\include" 03-init_device.asm
; \masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 03-init_device.obj


;-----------------------------------------------------------------------------------------
; 03-init_device Includes, Libraries, Prototypes, Structures & Macros
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


layer_properties                STRUCT
    properties                  VkLayerProperties <>
    instance_extensions         DWORD ? ; VkExtensionProperties arrays
    device_extensions           DWORD ? ; VkExtensionProperties arrays
layer_properties                ENDS

init_global_extension_properties PROTO :DWORD
init_global_layer_properties    PROTO
init_instance                   PROTO :DWORD
init_enumerate_device           PROTO


.DATA
;-----------------------------------------------------------------------------------------
; 03-init_device Initialized Data
;-----------------------------------------------------------------------------------------
app_info                VkApplicationInfo <>
inst_info               VkInstanceCreateInfo <>
device_info             VkDeviceCreateInfo  <>
queue_info              VkDeviceQueueCreateInfo <>
memory_properties       VkPhysicalDeviceMemoryProperties <>
gpu_props               VkPhysicalDeviceProperties <>
queue_props             VkQueueFamilyProperties 16 DUP (<>)

szCRLF                  DB 13,10,0
APP_SHORT_NAME          DB "[VulkanAsm] 03-init_device.asm",0

szErrorInitInstance     DB "Error Initializing Instance",0
szErrorEnumDevices      DB "Error Enumeratating Physical Devices",0
szErrorQueueFamily      DB "Queue family count is 0",0
szErrorQueueNone        DB "Could not find queue for usage",0
szErrorCreateDevice     DB "Error Creating Device",0


szStep1                 DB "- vkGetPhysicalDeviceQueueFamilyProperties Queue Family Count",0
szStep2                 DB "- vkGetPhysicalDeviceQueueFamilyProperties Queue Properties",0
szStep3                 DB "- Queue Family Count: ",0
szStep4                 DB "- Find Queue With Capabilties We Require",0
szStep5                 DB "- Initialize the VkDeviceQueueCreateInfo structure",0
szStep6                 DB "- Initialize the VkDeviceCreateInfo structure",0
szStep7                 DB "- Call vkCreateDevice",0
szDevice                DB "- Device: ",0
szStep8                 DB "- Call vkDestroyDevice",0
szStep9                 DB "- Call vkDestroyInstance",0


.DATA?
;-----------------------------------------------------------------------------------------
; 03-init_device Uninitialized Data
;-----------------------------------------------------------------------------------------
inst                    VkInstance ?
instance_layer_count    DWORD ?
vk_props                DWORD ? ; ptr to VkLayerProperties
res                     VkResult ?
gpu_count               DWORD ?
gpus                    VkPhysicalDevice 16 DUP (?)
physicalDevice          VkPhysicalDevice ?
queue_family_count      DWORD ?
queue_priorities        REAL4 ?
bFound                  DWORD ?
i                       DWORD ?
queueFamilyIndex        DWORD ?
device                  VkDevice ?


.CODE
;-----------------------------------------------------------------------------------------
; 03-init_device
;-----------------------------------------------------------------------------------------

start:
    
    cls
    print Addr APP_SHORT_NAME,13,10,13,10
    
    Invoke init_instance, Addr APP_SHORT_NAME
    .IF eax != VK_SUCCESS
        print Addr szErrorInitInstance,13,10
        jmp ExitVulkan
    .ENDIF
    
    Invoke init_enumerate_device
    .IF eax != VK_SUCCESS
        print Addr szErrorEnumDevices,13,10
        jmp ExitVulkan
    .ENDIF

    Invoke RtlZeroMemory, Addr queue_info, SIZEOF queue_info
    Invoke RtlZeroMemory, Addr device_info, SIZEOF device_info
    Invoke RtlZeroMemory, Addr queue_props, SIZEOF queue_props

    ; VULKAN_KEY_START

    lea ebx, gpus
    mov eax, [ebx]
    mov physicalDevice, eax ; or use gpus[0]
    
    ; vkGetPhysicalDeviceQueueFamilyProperties Queue Family Count
    print Addr szStep1,13,10
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, NULL
    .IF !(queue_family_count >= 1)
        print Addr szErrorQueueFamily,13,10
        jmp ExitVulkan
    .ENDIF
    
    ;vkGetPhysicalDeviceQueueFamilyProperties Queue Properties
    print Addr szStep2,13,10
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, Addr queue_props
    .IF !(queue_family_count >= 1)
        print Addr szErrorQueueFamily,13,10
        jmp ExitVulkan
    .ENDIF
    print Addr szStep3
    print str$(queue_family_count),13,10

    ; Find Queue With Capabilties We Require
    print Addr szStep4,13,10
    mov bFound, FALSE
    mov eax, 0
    mov i, 0
    .WHILE eax < queue_family_count
        mov eax, i
        mov ebx, SIZEOF VkQueueFamilyProperties
        mul ebx
        lea ebx, queue_props
        add eax, ebx
        mov eax, [ebx].VkQueueFamilyProperties.queueFlags
        and eax, VK_QUEUE_GRAPHICS_BIT
        .IF eax == VK_QUEUE_GRAPHICS_BIT
            mov i, eax
            mov queueFamilyIndex, eax
            mov bFound, TRUE
            .BREAK
        .ENDIF
        inc i
        mov eax, i
    .ENDW
    
    .IF bFound == FALSE
        print Addr szErrorQueueNone,13,10
        jmp ExitVulkan
    .ELSE
    .ENDIF
    .IF !(queue_family_count >= 1)
        print Addr szErrorQueueFamily,13,10
        jmp ExitVulkan
    .ENDIF

    ; Initialize the VkDeviceQueueCreateInfo structure
    print Addr szStep5,13,10
    fld FP4(0.00)
    fstp queue_priorities
    mov queue_info.sType, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO
    mov queue_info.pNext, NULL
    mov queue_info.queueCount, 1
    fld queue_priorities
    fstp queue_info.pQueuePriorities

    ; Initialize the VkDeviceCreateInfo structure
    print Addr szStep6,13,10
    mov device_info.sType, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO
    mov device_info.pNext, NULL
    mov device_info.queueCreateInfoCount, 1
    lea eax, queue_info
    mov device_info.pQueueCreateInfos, eax ;&queue_info
    mov device_info.enabledExtensionCount, 0
    mov device_info.ppEnabledExtensionNames, NULL
    mov device_info.enabledLayerCount, 0
    mov device_info.ppEnabledLayerNames, NULL
    mov device_info.pEnabledFeatures, NULL
    
    ; Call vkCreateDevice
    print Addr szStep7,13,10
    Invoke vkCreateDevice, gpus[0], Addr device_info, NULL, Addr device
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorCreateDevice,13,10
        jmp ExitVulkan
    .ENDIF
    print Addr szDevice
    print str$(device),13,10    
    
    ; Call vkDestroyDevice
    print Addr szStep8,13,10
    Invoke vkDestroyDevice, device, NULL 
    
    ; VULKAN_KEY_END
    
    ; Call vkDestroyInstance
    print Addr szStep9,13,10
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


;-----------------------------------------------------------------------------------------
; init_enumerate_device - similar to 02-enumerate_devices
;-----------------------------------------------------------------------------------------
init_enumerate_device PROC
    
    Invoke RtlZeroMemory, Addr gpus, SIZEOF gpus
    Invoke RtlZeroMemory, Addr memory_properties, SIZEOF memory_properties
    Invoke RtlZeroMemory, Addr gpu_props, SIZEOF gpu_props
 
    ; Enumerate Physical Devices
    mov gpu_count, 1
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, NULL
    .IF eax != VK_SUCCESS
        ret
    .ENDIF
    
    ; Enumerate Physical Devices with data (gpus)
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, Addr gpus
    .IF eax != VK_SUCCESS
        ret
    .ENDIF
    
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, NULL
    .IF !(queue_family_count >= 1)
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF

    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, Addr queue_props
    .IF !(queue_family_count >= 1)
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF    

    Invoke vkGetPhysicalDeviceMemoryProperties, gpus[0], Addr memory_properties
    Invoke vkGetPhysicalDeviceProperties, gpus[0], Addr gpu_props
    ; query device extensions for enabled layers */
    ;for (auto& layer_props : info.instance_layer_properties) {
    ;  init_device_extension_properties(info, layer_props);
    ;}    
    mov eax, VK_SUCCESS
    
    ret
init_enumerate_device ENDP


;-----------------------------------------------------------------------------------------
;
;-----------------------------------------------------------------------------------------
init_global_extension_properties PROC USES EBX layerprops:DWORD
    LOCAL memsizebytes:DWORD
    LOCAL layer_name:DWORD
    LOCAL instance_extensions:DWORD ; ptr to VkExtensionProperties
    LOCAL instance_extension_count:DWORD
    
    mov instance_extensions, NULL
    
    mov ebx, layerprops
    lea eax, [ebx].layer_properties.properties.layerName
    mov layer_name, eax
    
    mov res, VK_INCOMPLETE
    .WHILE res == VK_INCOMPLETE
        Invoke vkEnumerateInstanceExtensionProperties, layer_name, Addr instance_extension_count, NULL
        mov res, eax
        .IF res == VK_SUCCESS
            ret
        .ENDIF

        .IF instance_extension_count == 0
            mov eax, VK_SUCCESS
            ret
        .ENDIF
        
        mov eax, instance_extension_count
        mov ebx, SIZEOF VkExtensionProperties
        mul ebx
        mov memsizebytes, eax
        
       .IF instance_extensions == NULL
            Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, memsizebytes
        .ELSE
            Invoke GlobalUnlock, instance_extensions
            Invoke GlobalReAlloc, instance_extensions, memsizebytes, GMEM_ZEROINIT + GMEM_MOVEABLE
            Invoke GlobalLock, eax
        .ENDIF
        mov instance_extensions, eax

        mov ebx, layerprops
        mov eax, instance_extensions
        mov [ebx].layer_properties.instance_extensions, eax
        
        Invoke vkEnumerateInstanceExtensionProperties, layer_name, Addr instance_extension_count, instance_extensions
        mov res, eax
    .ENDW
    
    mov eax, res
    ret

init_global_extension_properties ENDP


;-----------------------------------------------------------------------------------------
;
;-----------------------------------------------------------------------------------------
init_global_layer_properties PROC USES EBX
    LOCAL memsizebytes:DWORD
    LOCAL ii:DWORD
    LOCAL layer_props:layer_properties
    
    mov vk_props, NULL
    mov res, VK_INCOMPLETE
    
    .WHILE res == VK_INCOMPLETE

        Invoke vkEnumerateInstanceLayerProperties, Addr instance_layer_count, NULL
        mov res, eax
        .IF eax == VK_SUCCESS
            ret
        .ENDIF
        
        .IF instance_layer_count == 0
            mov eax, VK_SUCCESS
            ret
        .ENDIF
        
        mov eax, instance_layer_count
        mov ebx, SIZEOF VkLayerProperties
        mul ebx
        mov memsizebytes, eax
        
        .IF vk_props == NULL
            Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, memsizebytes
        .ELSE
            Invoke GlobalUnlock, vk_props
            Invoke GlobalReAlloc, vk_props, memsizebytes, GMEM_ZEROINIT + GMEM_MOVEABLE
            Invoke GlobalLock, eax
        .ENDIF
        mov vk_props, eax
        
        Invoke vkEnumerateInstanceLayerProperties, Addr instance_layer_count, vk_props
        mov res, eax

    .ENDW
    
    ; Now gather the extension list for each instance layer.
    mov ii, 0
    mov eax, 0
    .WHILE eax < instance_layer_count
        
        mov eax, ii
        mov ebx, vk_props[eax]
        
        lea eax, layer_props.properties
        Invoke RtlMoveMemory, eax, ebx, SIZEOF VkLayerProperties
        
        Invoke init_global_extension_properties, Addr layer_props
        mov res, eax
        .IF eax == VK_SUCCESS
            ret
        .ENDIF
        
        
        inc ii
        mov eax, ii
    .ENDW

    Invoke GlobalUnlock, vk_props
    Invoke GlobalFree, vk_props
    
    mov eax, VK_SUCCESS
    ret

init_global_layer_properties ENDP


END start
