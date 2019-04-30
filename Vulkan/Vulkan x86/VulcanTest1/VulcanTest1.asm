;.386
;.model flat,stdcall
;option casemap:none
.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    include M:\Masm32\include\debug32.inc
ENDIF

include VulcanTest1.inc

.code

start:

	Invoke GetModuleHandle,NULL
	mov hInstance, eax
	Invoke GetCommandLine
	mov CommandLine, eax
	Invoke InitCommonControls
	mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
	
	Invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
	Invoke ExitProcess, eax

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL	wc:WNDCLASSEX
	LOCAL	msg:MSG

	mov		wc.cbSize, sizeof WNDCLASSEX
	mov		wc.style, CS_HREDRAW or CS_VREDRAW
	mov		wc.lpfnWndProc, offset WndProc
	mov		wc.cbClsExtra, NULL
	mov		wc.cbWndExtra, DLGWINDOWEXTRA
	push	hInst
	pop		wc.hInstance
	mov		wc.hbrBackground, COLOR_BTNFACE+1 ; COLOR_WINDOW+1
	mov		wc.lpszMenuName, IDM_MENU
	mov		wc.lpszClassName, offset ClassName
	Invoke LoadIcon, NULL, IDI_APPLICATION
	;Invoke LoadIcon, hInstance, ICO_MAIN ; resource icon for main application icon
	;mov hIcoMain, eax ; main application icon
	mov		wc.hIcon, eax
	mov		wc.hIconSm, eax
	Invoke LoadCursor, NULL, IDC_ARROW
	mov		wc.hCursor,eax
	Invoke RegisterClassEx, addr wc
	Invoke CreateDialogParam, hInstance, IDD_DIALOG, NULL, addr WndProc, NULL
	Invoke ShowWindow, hWnd, SW_SHOWNORMAL
	Invoke UpdateWindow, hWnd
	.WHILE TRUE
		invoke GetMessage, addr msg, NULL, 0, 0
	  .BREAK .if !eax
		Invoke TranslateMessage, addr msg
		Invoke DispatchMessage, addr msg
	.ENDW
	mov eax, msg.wParam
	ret
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
	
	mov eax, uMsg
	.IF eax == WM_INITDIALOG
		push hWin
		pop hWnd
		; Init Stuff Here
		Invoke StartVulkan, hWin
		
	.ELSEIF eax == WM_COMMAND
		mov eax, wParam
		and eax, 0FFFFh
		.IF eax == IDM_FILE_EXIT
			Invoke SendMessage,hWin,WM_CLOSE,0,0
			
		.ELSEIF eax == IDM_HELP_ABOUT
			Invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
			
		.ENDIF

	.ELSEIF eax == WM_CLOSE
		Invoke DestroyWindow,hWin
		
	.ELSEIF eax == WM_DESTROY
		Invoke PostQuitMessage,NULL
		
	.ELSE
		Invoke DefWindowProc,hWin,uMsg,wParam,lParam
		ret
	.ENDIF
	xor    eax,eax
	ret
WndProc endp


;-------------------------------------------------------------------------------------
; Add /IGNORE:4210 to linker
;-------------------------------------------------------------------------------------
StartVulkan PROC USES EBX hWin:DWORD
    LOCAL app_info:VkApplicationInfo
    LOCAL inst_info:VkInstanceCreateInfo
    LOCAL queue_info:VkDeviceQueueCreateInfo
    LOCAL device_info:VkDeviceCreateInfo
    LOCAL physicalDevice:VkPhysicalDevice
    LOCAL cmd_pool_info:VkCommandPoolCreateInfo
    LOCAL cmd_info:VkCommandBufferAllocateInfo
    LOCAL createInfo:VkWin32SurfaceCreateInfoKHR
    LOCAL inst:VkInstance
    LOCAL res:VkResult
    LOCAL device:VkDevice
    LOCAL cmd_pool:VkCommandPool
    LOCAL cmd_buff:VkCommandBuffer
    LOCAL cmd_bufs[1]:VkCommandBuffer
    LOCAL gpu_count:DWORD
    LOCAL gpus[16]:VkPhysicalDevice
    LOCAL queue_family_count:DWORD
    LOCAL queue_props[16]:VkQueueFamilyProperties
    LOCAL queue_priorities:REAL4
    LOCAL bFound:DWORD
    LOCAL i:DWORD
    LOCAL queueFamilyIndex:DWORD
    LOCAL connection:DWORD
    LOCAL window:DWORD
    LOCAL surface:VkSurfaceKHR
    LOCAL device_extension_names[4]:DWORD
    LOCAL instance_extension_names[4]:DWORD
    LOCAL pSupportsPresent:DWORD
    LOCAL graphics_queue_family_index:DWORD
    LOCAL present_queue_family_index:DWORD
    
    ; clear structures before usage
    Invoke RtlZeroMemory, Addr app_info, SIZEOF app_info
    Invoke RtlZeroMemory, Addr inst_info, SIZEOF inst_info
    Invoke RtlZeroMemory, Addr queue_info, SIZEOF queue_info
    Invoke RtlZeroMemory, Addr device_info, SIZEOF device_info
    Invoke RtlZeroMemory, Addr gpus, SIZEOF gpus
    Invoke RtlZeroMemory, Addr queue_props, SIZEOF queue_props
    Invoke RtlZeroMemory, Addr cmd_pool_info, SIZEOF cmd_pool_info
    Invoke RtlZeroMemory, Addr cmd_info, SIZEOF cmd_info
    Invoke RtlZeroMemory, Addr cmd_bufs, SIZEOF cmd_bufs
    Invoke RtlZeroMemory, Addr createInfo, SIZEOF createInfo
    
    ; 1
    ; initialize the VkApplicationInfo structure
    mov app_info.sType, VK_STRUCTURE_TYPE_APPLICATION_INFO
    mov app_info.pNext, NULL
    lea eax, APP_SHORT_NAME
    mov app_info.pApplicationName, eax ;APP_SHORT_NAME
    mov app_info.applicationVersion, 1
    lea eax, APP_SHORT_NAME
    mov app_info.pEngineName, eax ; APP_SHORT_NAME
    mov app_info.engineVersion, 1
    mov app_info.apiVersion, VK_API_VERSION_1_0

    ; initialize the VkInstanceCreateInfo structure
    mov inst_info.sType, VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO
    mov inst_info.pNext, NULL
    mov inst_info.flags, 0
    lea eax, app_info
    mov inst_info.pApplicationInfo, eax ;&app_info;
    
    lea eax, VK_KHR_SURFACE_EXTENSION_NAME
    mov instance_extension_names[0], eax
    
    mov inst_info.enabledExtensionCount, 1;0
    lea eax, instance_extension_names
    mov inst_info.ppEnabledExtensionNames, eax ;NULL
    mov inst_info.enabledLayerCount, 0
    mov inst_info.ppEnabledLayerNames, NULL

    Invoke vkCreateInstance, Addr inst_info, NULL, Addr inst
    mov res, eax
    .IF res == VK_ERROR_INCOMPATIBLE_DRIVER
        Invoke MessageBox, hWin, Addr szErrorFindICD, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ELSEIF res == VK_SUCCESS
        ;Invoke MessageBox, hWin, Addr szSuccess, Addr APP_SHORT_NAME, MB_OK
    .ELSE
        Invoke MessageBox, hWin, Addr szErrorUnknown, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ENDIF
    
    ; 2
    mov gpu_count, 1
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, NULL
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorEnumDevices, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ENDIF
    PrintDec gpu_count
    Invoke vkEnumeratePhysicalDevices, inst, Addr gpu_count, Addr gpus
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorEnumDevices, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ENDIF
    
    ;lea eax, gpus
    ;DbgDump eax, SIZEOF gpus
    
    ; 3
    lea ebx, gpus
    mov eax, [ebx]
    mov dword ptr physicalDevice, eax
    ;PrintDec physicalDevice
    ;mov eax, gpus[0]
    ;PrintDec eax
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, NULL
    .IF !(queue_family_count >= 1)
        jmp ExitStartVulkan
    .ENDIF
    
    Invoke vkGetPhysicalDeviceQueueFamilyProperties, gpus[0], Addr queue_family_count, Addr queue_props
    .IF !(queue_family_count >= 1)
        jmp ExitStartVulkan
    .ENDIF

    PrintDec queue_family_count

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
            mov eax, i
            mov queueFamilyIndex, eax
            mov bFound, TRUE
            .BREAK
        .ENDIF
        inc i
        mov eax, i
    .ENDW
    
    .IF bFound == FALSE
        PrintText 'Not found'
        jmp ExitStartVulkan
    .ELSE
        ;PrintText 'found'
    .ENDIF
    .IF !(queue_family_count >= 1)
        jmp ExitStartVulkan
    .ENDIF

    fld FP4(0.00)
    fstp queue_priorities
    mov queue_info.sType, VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO
    mov queue_info.pNext, NULL
    mov queue_info.queueCount, 1
    fld queue_priorities
    fstp queue_info.pQueuePriorities

    mov device_info.sType, VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO
    mov device_info.pNext, NULL
    mov device_info.queueCreateInfoCount, 1
    lea eax, queue_info
    mov device_info.pQueueCreateInfos, eax ;&queue_info
    
    
    lea eax, VK_KHR_SWAPCHAIN_EXTENSION_NAME
    mov device_extension_names[0], eax
    
    mov device_info.enabledExtensionCount, 1;0
    lea eax, device_extension_names
    mov device_info.ppEnabledExtensionNames, eax ;NULL
    mov device_info.enabledLayerCount, 0
    mov device_info.ppEnabledLayerNames, NULL
    mov device_info.pEnabledFeatures, NULL
    
    PrintText 'vkCreateDevice'
    Invoke vkCreateDevice, gpus[0], Addr device_info, NULL, Addr device
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorCreateDevice, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ELSE
        PrintText 'vkCreateDevice Success!'
    .ENDIF
    PrintDec device
    
    
    ; 4
    
    ; Create a command pool to allocate our command buffer from */
    mov cmd_pool_info.sType, VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
    mov cmd_pool_info.pNext, NULL
    mov eax, queueFamilyIndex
    mov cmd_pool_info.queueFamilyIndex, eax
    mov cmd_pool_info.flags, 0
;    ;===================
    Invoke vkCreateCommandPool, device, Addr cmd_pool_info, NULL, Addr cmd_pool
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorCreateCmdPool, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ELSE
        PrintText 'vkCreateCommandPool Success!'
    .ENDIF

    ; Create the command buffer from the command pool */
    mov cmd_info.sType, VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO
    mov cmd_info.pNext, NULL
    mov eax, dword ptr cmd_pool
    mov dword ptr cmd_info.commandPool, eax
    mov cmd_info.level, VK_COMMAND_BUFFER_LEVEL_PRIMARY
    mov cmd_info.commandBufferCount, 1
;    
;    ;PrintText 'vkAllocateCommandBuffers'
    PrintDec device
;    mov eax, device
;    PrintDec eax
    Invoke vkAllocateCommandBuffers, device, Addr cmd_info, Addr cmd_buff
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorAllocCmdBuf, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ELSE
        PrintText 'vkAllocateCommandBuffers Success!'
    .ENDIF

    mov eax, cmd_buff
    mov cmd_bufs[0], eax
    PrintText 'vkFreeCommandBuffers'
    Invoke vkFreeCommandBuffers, device, dword ptr cmd_pool, 0, 1, Addr cmd_bufs
    mov res, eax
    .IF res != VK_SUCCESS
        PrintText 'vkFreeCommandBuffers Error!'
        jmp ExitStartVulkan
    .ELSE
        PrintText 'vkFreeCommandBuffers Success!'
    .ENDIF
    
    PrintDec device
    Invoke vkDestroyCommandPool, device, dword ptr cmd_pool, 0, NULL
    mov res, eax
    .IF res != VK_SUCCESS
        PrintText 'vkDestroyCommandPool Error!'
        jmp ExitStartVulkan
    .ELSE
        PrintText 'vkDestroyCommandPool Success!'
    .ENDIF
    
    ; 5  05-init_swapchain
    
    Invoke GetModuleHandle, NULL
    mov connection, eax
    mov eax, hWnd
    mov window, eax
    
    ; Construct the surface description
    mov createInfo.sType, VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR
    mov createInfo.pNext, NULL
    mov eax, connection
    mov createInfo.hinstance, eax ; info.connection;
    mov eax, window
    mov createInfo.hwnd, eax ; info.window
    Invoke vkCreateWin32SurfaceKHR, inst, Addr createInfo, NULL, Addr surface ; info.surface
    mov res, eax
    .IF res != VK_SUCCESS
        Invoke MessageBox, hWin, Addr szErrorWin32Surface, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ENDIF
    
    mov eax, queue_family_count
    mov ebx, SIZEOF VkBool32
    mul ebx
    Invoke GlobalAlloc, GMEM_FIXED + GMEM_ZEROINIT, eax
    mov pSupportsPresent, eax
    
    ; Iterate over each queue to learn whether it supports presenting:
    mov eax, 0
    mov i, 0
    .WHILE eax < queue_family_count
        mov eax, i
        Invoke vkGetPhysicalDeviceSurfaceSupportKHR, gpus[0], i, dword ptr surface, 0, Addr pSupportsPresent[eax]
        inc i
        mov eax, i
    .ENDW    
    
    mov graphics_queue_family_index, 0ffffffffh;UINT32_MAX;
    mov present_queue_family_index, 0ffffffffh

    ; Search for a graphics and a present queue in the array of queue
    ; families, try to find one that supports both
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
            mov eax, i
            mov graphics_queue_family_index, eax

            mov ebx, pSupportsPresent[eax]
            .IF ebx == VK_TRUE
                mov eax, i
                mov graphics_queue_family_index, eax
                mov present_queue_family_index, eax
                .BREAK
            .ENDIF
        .ENDIF
        inc i
        mov eax, i
    .ENDW
    
    ; If didn't find a queue that supports both graphics and present, then
    ; find a separate present queue.
    .IF present_queue_family_index == 0ffffffffh
        mov eax, 0
        mov i, 0
        .WHILE eax < queue_family_count
            mov eax, i
            mov ebx, pSupportsPresent[eax]
            .IF ebx == VK_TRUE
                mov eax, i
                mov present_queue_family_index, eax
                .BREAK
            .ENDIF
            inc i
            mov eax, i
        .ENDW        
    .ENDIF
    
    Invoke GlobalFree, pSupportsPresent

    ; Generate error if could not find queues that support graphics and present
    .IF graphics_queue_family_index == 0ffffffffh || present_queue_family_index == 0ffffffffh
        Invoke MessageBox, hWin, Addr szErrorNoQueues, Addr APP_SHORT_NAME, MB_OK
        jmp ExitStartVulkan
    .ENDIF



    
    
    Invoke vkDestroyDevice, device, NULL
    
    PrintText 'vkDestroyDevice'
    
    Invoke vkDestroyInstance, inst, NULL

    PrintText 'vkDestroyInstance'
ExitStartVulkan:

    ret
StartVulkan ENDP


















end start





































