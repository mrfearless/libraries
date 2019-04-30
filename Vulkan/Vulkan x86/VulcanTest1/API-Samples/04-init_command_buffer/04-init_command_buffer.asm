; Vulkan API-Samples:
;
; 04-init_command_buffer
;
; Compile and link settings:
; 
; \masm32\bin\ml /c /coff /I"\masm32\include" 04-init_command_buffer.asm
; \masm32\bin\link /SUBSYSTEM:CONSOLE /RELEASE /VERSION:4.0 /IGNORE:4210 /LIBPATH:"\masm32\lib" 04-init_command_buffer.obj


;-----------------------------------------------------------------------------------------
; 04-init_command_buffer Includes, Libraries, Prototypes, Structures & Macros
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

init_instance           PROTO :DWORD
init_enumerate_device   PROTO
init_device             PROTO


.DATA
;-----------------------------------------------------------------------------------------
; 04-init_command_buffer Initialized Data
;-----------------------------------------------------------------------------------------
app_info            VkApplicationInfo <>
inst_info           VkInstanceCreateInfo <>
device_info         VkDeviceCreateInfo  <>
queue_info          VkDeviceQueueCreateInfo <>
queue_props         VkQueueFamilyProperties 16 DUP (<>)
cmd_pool_info       VkCommandPoolCreateInfo <>
cmd_info            VkCommandBufferAllocateInfo <>

szCRLF              DB 13,10,0
APP_SHORT_NAME      DB "[VulkanAsm] 04-init_command_buffer.asm",0

szErrorInitInstance DB "Error Initializing Instance",0
szErrorEnumDevices  DB "Error Enumeratating Physical Devices",0
szErrorCreateDevice DB "Error Creating Device",0
szErrorCreateCmdPl  DB "Error Creating Command Pool",0
szErrorAllocCmdBufs DB "Error Allocating Command Buffers",0
szErrorFreeCmdBufs  DB "Error Freeing Command Buffers",0
szErrorDestroyCmdPl DB "Error Destroying Command Pool",0

szStep1             DB "- Initialize the VkCommandPoolCreateInfo structure",0
szStep2             DB "- Call vkCreateCommandPool",0
szStep3             DB "- Initialize the VkCommandBufferAllocateInfo structure",0
szStep4             DB "- Call vkAllocateCommandBuffers",0
szStep5             DB "- Call vkFreeCommandBuffers",0
szStep6             DB "- Call vkDestroyCommandPool",0
szStep7             DB "- Call vkDestroyDevice",0
szStep8             DB "- Call vkDestroyInstance",0


.DATA?
;-----------------------------------------------------------------------------------------
; 04-init_command_buffer Uninitialized Data
;-----------------------------------------------------------------------------------------
inst                VkInstance ?
res                 VkResult ?
gpu_count           DWORD ?
gpus                VkPhysicalDevice 16 DUP (?)
physicalDevice      VkPhysicalDevice ?
queue_family_count  DWORD ?
queue_priorities    REAL4 ?
bFound              DWORD ?
i                   DWORD ?
queueFamilyIndex    DWORD ?
device              VkDevice ?
cmd_pool            VkCommandPool ?
cmd_buff            VkCommandBuffer ?
cmd_bufs            VkCommandBuffer 1 DUP (?)  


.CODE
;-----------------------------------------------------------------------------------------
; 04-init_command_buffer
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

    Invoke init_device
    .IF eax != VK_SUCCESS
        print Addr szErrorCreateDevice,13,10
        jmp ExitVulkan
    .ENDIF

    Invoke RtlZeroMemory, Addr cmd_pool_info, SIZEOF cmd_pool_info
    Invoke RtlZeroMemory, Addr cmd_info, SIZEOF cmd_info
    Invoke RtlZeroMemory, Addr cmd_bufs, SIZEOF cmd_bufs

    ; VULKAN_KEY_START

    ; Initialize the VkCommandPoolCreateInfo structure
    print Addr szStep1,13,10
    mov cmd_pool_info.sType, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
    mov cmd_pool_info.pNext, NULL
    mov eax, queueFamilyIndex
    mov cmd_pool_info.queueFamilyIndex, eax
    mov cmd_pool_info.flags, 0

    ; Call vkCreateCommandPool
    print Addr szStep2,13,10
    Invoke vkCreateCommandPool, device, Addr cmd_pool_info, NULL, Addr cmd_pool
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorCreateCmdPl,13,10
        jmp ExitVulkan
    .ENDIF

    ; Initialize the VkCommandBufferAllocateInfo structure
    print Addr szStep3,13,10
    mov cmd_info.sType, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO
    mov cmd_info.pNext, NULL
    mov eax, dword ptr cmd_pool
    mov dword ptr cmd_info.commandPool, eax
    mov cmd_info.level, VK_COMMAND_BUFFER_LEVEL_PRIMARY
    mov cmd_info.commandBufferCount, 1

    ; Call vkAllocateCommandBuffers
    print Addr szStep4,13,10
    Invoke vkAllocateCommandBuffers, device, Addr cmd_info, Addr cmd_buff
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorAllocCmdBufs,13,10
        jmp ExitVulkan
    .ENDIF
    
    ; Call vkFreeCommandBuffers
    print Addr szStep5,13,10
    mov eax, cmd_buff
    mov cmd_bufs[0], eax
    Invoke vkFreeCommandBuffers, device, DWORD PTR cmd_pool, 0, 1, Addr cmd_bufs
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorFreeCmdBufs,13,10
        jmp ExitVulkan
    .ENDIF
    
    ; Call vkDestroyCommandPool
    print Addr szStep6,13,10
    Invoke vkDestroyCommandPool, device, DWORD PTR cmd_pool, 0, NULL
    mov res, eax
    .IF res != VK_SUCCESS
        print Addr szErrorDestroyCmdPl,13,10
        jmp ExitVulkan
    .ENDIF
    
    ; VULKAN_KEY_END
    
    ; Call vkDestroyDevice
    print Addr szStep7,13,10
    Invoke vkDestroyDevice, device, NULL 
    
    ; Call vkDestroyInstance
    print Addr szStep8,13,10
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
 
    ; Enumerate Physical Devices
    mov gpu_count, 1
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, NULL
    .IF eax != VK_SUCCESS
        ret
    .ENDIF
    
    ; Enumerate Physical Devices with data (gpus)
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, Addr gpus
    ; eax contains result
    ret
init_enumerate_device ENDP


;-----------------------------------------------------------------------------------------
; init_device - similar to 03-init_device
;-----------------------------------------------------------------------------------------
init_device PROC

    Invoke RtlZeroMemory, Addr queue_info, SIZEOF queue_info
    Invoke RtlZeroMemory, Addr device_info, SIZEOF device_info
    Invoke RtlZeroMemory, Addr queue_props, SIZEOF queue_props
    
    ; vkGetPhysicalDeviceQueueFamilyProperties Queue Family Count
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, NULL
    .IF !(queue_family_count >= 1)
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF
    
    ;vkGetPhysicalDeviceQueueFamilyProperties Queue Properties
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, Addr queue_props
    .IF !(queue_family_count >= 1)
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF
    
    ; Find Queue With Capabilties We Require
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
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF
    .IF !(queue_family_count >= 1)
        mov eax, VK_INCOMPLETE ; using VK_INCOMPLETE as a false return value. For !VK_SUCCESS
        ret
    .ENDIF

    ; Initialize the VkDeviceQueueCreateInfo structure
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
    Invoke vkCreateDevice, gpus[0], Addr device_info, NULL, Addr device
    ; result is in eax  
    ret
init_device ENDP



END start
