.686
.MMX
.XMM
.x64

option casemap : none
option win64 : 11
option frame : auto
option stackbase : rsp

_WIN64 EQU 1
WINVER equ 0501h

DEBUG64 EQU 1

IFDEF DEBUG64
    PRESERVEXMMREGS equ 1
    includelib \UASM\lib\x64\Debug64.lib
    DBG64LIB equ 1
    DEBUGEXE textequ <'\UASM\bin\DbgWin.exe'>
    include \UASM\include\debug64.inc
    .DATA
    RDBG_DbgWin	DB DEBUGEXE,0
    .CODE
ENDIF

include CudaDetection.inc

.CODE

WinMainCRTStartup proc FRAME
	invoke GetModuleHandle, NULL
	mov hInstance, rax
	invoke GetCommandLine
	mov CommandLine, rax
	Invoke InitCommonControls
	mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
	invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
	invoke ExitProcess, eax
    ret
WinMainCRTStartup endp
	

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc FRAME hInst:HINSTANCE, hPrev:HINSTANCE, CmdLine:LPSTR, iShow:DWORD
	LOCAL msg:MSG
	LOCAL wcex:WNDCLASSEX
	
	mov wcex.cbSize, sizeof WNDCLASSEX
	mov wcex.style, CS_HREDRAW or CS_VREDRAW
	lea rax, WndProc
	mov wcex.lpfnWndProc, rax
	mov wcex.cbClsExtra, 0
	mov wcex.cbWndExtra, DLGWINDOWEXTRA
	mov rax, hInst
	mov wcex.hInstance, rax
	mov wcex.hbrBackground, COLOR_WINDOW+1
	mov wcex.lpszMenuName, IDM_MENU ;NULL 
	lea rax, ClassName
	mov wcex.lpszClassName, rax
	invoke LoadIcon, NULL, IDI_APPLICATION
	;Invoke LoadIcon, hInst, ICO_MAIN ; resource icon for main application icon
	;mov hIcoMain, eax ; main application icon	
	mov wcex.hIcon, rax
	mov wcex.hIconSm, rax
	invoke LoadCursor, NULL, IDC_ARROW
	mov wcex.hCursor, rax
	invoke RegisterClassEx, addr wcex
	
	;invoke CreateWindowEx, 0, addr ClassName, addr szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL
	Invoke CreateDialogParam, hInstance, IDD_DIALOG, 0, Addr WndProc, 0
	mov hWnd, rax
	
	invoke ShowWindow, hWnd, SW_SHOWNORMAL
	invoke UpdateWindow, hWnd
	
	.while (TRUE)
		invoke GetMessage, addr msg, NULL, 0, 0
		.break .if (!rax)		
		
		invoke TranslateMessage, addr msg
		invoke DispatchMessage, addr msg
	.endw
	
	mov rax, msg.wParam
	ret	
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc FRAME USES RBX hWin:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM

	.IF edx == WM_INITDIALOG
		; Init Stuff Here
		;Invoke cudaGetDeviceCount, Addr device_count
		
		
		;mov rax, device_count
		;PrintQWORD rax
		
		Invoke nvmlInit
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0, Addr szNVMLErrorInit, Addr szAppName, MB_OK
		.ENDIF
		
		Invoke nvmlDeviceGetCount, Addr device_count
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0, Addr szNVMLErrorDeviceGetCount, Addr szAppName, MB_OK
		.ENDIF
		
		mov rax, device_count
		;PrintQWORD rax		
		Invoke utoa_ex, 0, Addr szDeviceID, 10h, FALSE, FALSE
		
		Invoke cudaGetDeviceProperties, Addr props, 0
		
		Invoke cudaDeviceGetPCIBusId, Addr pciBusID, PCI_BUS_LEN, 0
		
		;PrintString pciBusID
		
		Invoke nvmlSystemGetDriverVersion, Addr szDriverVersion, SIZEOF szDriverVersion
		;PrintString szDriverVersion
    
    
        Invoke nvmlSystemGetNVMLVersion, Addr szNVMLVersion, SIZEOF szNVMLVersion
        ;PrintString szNVMLVersion
		
		
		Invoke nvmlDeviceGetHandleByPciBusId, Addr pciBusID, Addr device_t
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0, Addr szNVMLErrorDeviceGetHandleByPciBusId, Addr szAppName, MB_OK
		.ENDIF
		
		Invoke nvmlDeviceGetPciInfo, device_t, Addr pciInfo
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0,  Addr szNVMLErrorDeviceGetPciInfo, Addr szAppName,MB_OK
		.ENDIF
		
		Invoke nvmlDeviceGetUUID, device_t, Addr uuid, UUID_SIZE
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0,  Addr szNVMLErrorDeviceGetUUID, Addr szAppName,MB_OK
		.ENDIF
		;PrintString uuid
		
		Invoke nvmlDeviceGetName, device_t, Addr szDeviceName, NVML_DEVICE_NAME_BUFFER_SIZE
		;PrintString szDeviceName
		
		
		Invoke nvmlDeviceGetSerial, device_t, Addr szSerialNo, NVML_DEVICE_SERIAL_BUFFER_SIZE
		;PrintQWORD rax
		;PrintString szSerialNo
		
		Invoke nvmlDeviceGetMemoryInfo, device_t, Addr GpuMemInfo
		
		mov rax, GpuMemInfo.totalmemory
		;PrintQWORD rax
		mov rax, GpuMemInfo.freememory
		;PrintQWORD rax
		mov rax, GpuMemInfo.usedmemory
		;PrintQWORD rax
		
		Invoke nvmlDeviceGetFanSpeed, device_t, Addr dwFanSpeed
		;PrintDWORD dwFanSpeed
		
		Invoke nvmlDeviceGetEnforcedPowerLimit, device_t, Addr dwPowerLimit
		;PrintDWORD dwPowerLimit
		
		Invoke nvmlDeviceGetMaxClockInfo, device_t, NVML_CLOCK_MEM, Addr dwClock
		;PrintDWORD dwClock
		Invoke nvmlDeviceGetMaxClockInfo, device_t, NVML_CLOCK_GRAPHICS, Addr dwClock
		;PrintDWORD dwClock
		Invoke nvmlDeviceGetMaxClockInfo, device_t, NVML_CLOCK_SM, Addr dwClock
		;PrintDWORD dwClock
		
		
		Invoke nvmlDeviceGetPerformanceState, device_t, Addr dwPState
		;PrintDWORD dwPState
		
		Invoke nvmlDeviceGetPowerUsage, device_t, Addr dwPowerUsage
		;PrintDWORD dwPowerUsage
		
		Invoke nvmlDeviceGetTemperature, device_t, NVML_TEMPERATURE_GPU, Addr dwTemp
		;PrintDWORD dwTemp
		
		
		Invoke nvmlDeviceGetTemperatureThreshold, device_t, NVML_TEMPERATURE_THRESHOLD_SHUTDOWN, Addr dwTemp
		;PrintDWORD dwTemp
		
		Invoke nvmlDeviceGetVbiosVersion, device_t, Addr szBiosVersion, NVML_DEVICE_VBIOS_VERSION_BUFFER_SIZE
		;PrintString szBiosVersion
		
		Invoke nvmlDeviceGetBrand, device_t, Addr dwBrandType
		;PrintDWORD dwBrandType
		
		Invoke nvmlDeviceGetComputeMode, device_t, Addr dwComputeMode
		;PrintDWORD dwComputeMode
		
		Invoke nvmlDeviceGetUtilizationRates, device_t, Addr UtilRates
		mov eax, UtilRates.gpu
		;PrintDWORD eax
		mov eax, UtilRates.memory
		;PrintDWORD eax
		
		
		mov cudaDevice.DeviceID, 0
		
		Invoke getVendorString, Addr pciInfo
		mov cudaDevice.VendorName, rax
		Invoke szCopy, rax, Addr szVendorName
		;PrintString szVendorName
		
		lea rax, props.cudaname
		;PrintQWORD rax
		mov cudaDevice.DeviceName, rax
		;Invoke szCopy, rax, Addr szDeviceName
		;PrintString szDeviceName
		
		mov eax, props.major
		mov cudaDevice.SM_major, eax
		;PrintQWORD rax
		Invoke utoa_ex, eax, Addr szVerMajor, 10h, FALSE, FALSE
		
		mov eax, props.minor
		mov cudaDevice.SM_minor, eax
		Invoke utoa_ex, eax, Addr szVerMinor, 10h, FALSE, FALSE
		;PrintQWORD rax
		
		Invoke szCopy, Addr szVerMajor, Addr szSMVersion
		Invoke szCatStr, Addr szSMVersion, CTEXT(".")
		Invoke szCatStr, Addr szSMVersion, Addr szVerMinor
		
		lea rax, uuid
		mov cudaDevice.UUID, rax 
		
		mov rax, props.totalGlobalMem 
		mov cudaDevice.DeviceGlobalMemory, rax
		Invoke utoa_ex, rax, Addr szDeviceGlobalMemory, 10h, FALSE, FALSE
		
		mov eax, pciInfo.pciDeviceId
		mov cudaDevice.DeviceID, eax
		Invoke dwtoa, eax, Addr szPciDeviceID
		
		mov eax, pciInfo.pciSubSystemId
		mov cudaDevice.pciSubSystemId, eax
		Invoke dwtoa, eax, Addr szPciSubSystemID
		
		mov eax, props.multiProcessorCount
		mov cudaDevice.SMX, eax
		;PrintQWORD rax
		Invoke dwtoa, eax, Addr szSMX
		
		Invoke getVendorId, Addr pciInfo
		mov cudaDevice.VendorID, eax
		Invoke utoa_ex, rax, Addr szVendorID, 10h, FALSE, FALSE
		;Invoke dwtoa, eax, Addr szVendorID
		
		;PrintString pciInfo.busId
		
		;PrintQWORD pciInfo.pciDeviceId
		
		;PrintQWORD pciInfo.pciSubSystemId
		
		
		PrintString szDeviceID
		PrintString szVendorID
		PrintString szVendorName
		PrintString szDeviceName
		PrintString szSMVersion
		PrintString szVerMajor
		PrintString szVerMinor
		PrintString uuid
		PrintString szDeviceGlobalMemory
		PrintString szPciDeviceID
		PrintString szPciSubSystemID
		PrintString szSMX
		
		
		
		Invoke nvmlShutdown
		.IF rax != NVML_SUCCESS 
		    Invoke MessageBox, 0,  Addr szNVMLErrorShutdown, Addr szAppName,MB_OK
		.ENDIF		
		
	.ELSEIF edx == WM_COMMAND
		.IF wParam == IDM_FILE_EXIT
			Invoke SendMessage, hWin, WM_CLOSE, 0, 0
			
		.ELSEIF wParam == IDM_HELP_ABOUT
			Invoke ShellAbout, hWin, Addr AppName, Addr AboutMsg, NULL
			
		.ENDIF

	.ELSEIF edx == WM_CLOSE
		Invoke DestroyWindow, hWin
		
	.ELSEIF edx == WM_DESTROY
		Invoke PostQuitMessage, NULL
		
	.ELSE
		invoke DefWindowProc, rcx, edx, r8, r9
		ret
	.ENDIF
	xor rax, rax
	ret
WndProc endp


getVendorId PROC FRAME USES RBX nvmlPciInfo:QWORD
    LOCAL vendorId:DWORD
    LOCAL subSystemId:DWORD
    
    mov vendorId, 0
    mov subSystemId, 0
    
    mov rbx, nvmlPciInfo
    xor rax, rax
    mov eax, [rbx].nvmlPciInfo_t.pciDeviceId
    and eax, 0FFFFh
    mov vendorId, eax
;    PrintDWORD eax
;
;    PrintText 'SubVendorID'
;    mov rbx, nvmlPciInfo
;    xor rax, rax
;    mov eax, [rbx].nvmlPciInfo_t.pciSubVendorId
;    PrintDWORD eax
;
;    mov rbx, nvmlPciInfo
;    xor rax, rax
;    mov eax, [rbx].nvmlPciInfo_t.dwReserved1
;    PrintDWORD eax
;
;    mov rbx, nvmlPciInfo
;    xor rax, rax
;    mov eax, [rbx].nvmlPciInfo_t.dwReserved2
;    PrintDWORD eax
;
;    mov rbx, nvmlPciInfo
;    xor rax, rax
;    mov eax, [rbx].nvmlPciInfo_t.dwReserved3
;    PrintDWORD eax
;
;    mov rbx, nvmlPciInfo
;    xor rax, rax
;    mov eax, [rbx].nvmlPciInfo_t.device
;    PrintDWORD eax
;
;
;    mov eax, vendorId
;    .IF eax == 10DEh && subSystemId == 0
;       mov eax, subSystemId
;       and eax, 0FFFFh
;       mov vendorId, eax 
;    .ENDIF
    xor rax, rax
    mov eax, vendorId
    ret

getVendorId endp


getVendorString PROC FRAME nvmlPciInfo:QWORD
    LOCAL venId:DWORD
    
    xor rax, rax
    Invoke getVendorId, nvmlPciInfo
    mov venId, eax
    
    .IF eax == 0x1043
        lea rax, vendorAsus
    .ELSEIF eax == 0x107D
        lea rax, vendorLeadtek
    .ELSEIF eax == 0x10B0
        lea rax, vendorGainward
    .ELSEIF eax == 0x10DE
        lea rax, vendorNvidia
    .ELSEIF eax == 0x1458
        lea rax, vendorGigabyte
    .ELSEIF eax == 0x1462
        lea rax, vendorMsi
    .ELSEIF eax == 0x154B
        lea rax, vendorPny
    .ELSEIF eax == 0x1682
        lea rax, vendorXfx
    .ELSEIF eax == 0x196D
        lea rax, vendorClub3D
    .ELSEIF eax == 0x19DA
        lea rax, vendorZotac
    .ELSEIF eax == 0x19F1
        lea rax, vendorBfg
    .ELSEIF eax == 0x1ACC
        lea rax, vendorPov
    .ELSEIF eax == 0x1B4C
        lea rax, vendorKfa2
    .ELSEIF eax == 0x3842
        lea rax, vendorEvga
    .ELSEIF eax == 0x7377
        lea rax, vendorColorful
    .ELSE
        lea rax, vendorUnknown
    .ENDIF    
    ret

getVendorString endp






utoa_ex PROC FRAME USES rbx value:QWORD, buffer:QWORD, radix:DWORD, sign:DWORD, addzero:DWORD
    LOCAL tmpbuf[34]:BYTE 
    mov rbx,rdx      ;buffer
    mov r10,rdx      ;buffer
    .if (!rcx)
        mov rax,rdx
        mov byte ptr[rax],'0'
        jmp done
    .endif 
    .if (r9b)
        mov byte ptr [rdx],2Dh           
        lea r10,[rdx+1]       
        neg rcx
    .endif
    lea r9, tmpbuf[33]                     
    mov byte ptr tmpbuf[33],0
    lea r11, hextbl
    .repeat
        xor edx,edx                      ;clear rdx               
        mov rax,rcx                      ;value into rax
        dec r9                           ;make space for next char
        div r8                           ;div value with radix (2, 8, 10, 16)
        mov rcx,rax                      ;mod is in rdx, save result back in rcx
        movzx eax,byte ptr [rdx+r11]     ;put char from hextbl pointed by rdx
        mov byte ptr [r9], al            ;store char from al to tmpbuf pointed by r9
    .until (!rcx)                        ;repeat if rcx not clear
    .if (addzero && al > '9')            ;add a leading '0' if first digit is alpha
        mov word ptr[r10],'x0'
        add r10, 2
        ;mov byte ptr[r10],'0'
        ;inc r10
    .endif
    lea r8, tmpbuf[34]                   ;start of the buffer in r8
    sub r8, r9                           ;that will give a count of chars to be copied
    invoke RtlMoveMemory, r10, r9, r8    ;call routine to copy
    mov rax,rbx                          ;return the address of the buffer in rax
done: ret
utoa_ex ENDP













end WinMainCRTStartup
