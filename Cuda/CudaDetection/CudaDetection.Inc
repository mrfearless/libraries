include windows.inc
include CommCtrl.inc
include shellapi.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib


include windows.inc
include CommCtrl.inc
include shellapi.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib comctl32.lib
includelib shell32.lib


include cudart.inc
includelib cudart.lib

;includelib cublas.lib
;includelib cublas_device.lib
;includelib cuda.lib
;includelib cudadevrt.lib

;includelib M:\radasm\UASM64\Projects\CudaDetection\cudart_static.lib
;includelib cufft.lib
;includelib cufftw.lib
;includelib curand.lib
;includelib cusolver.lib
;includelib cusparse.lib
;includelib nppc.lib
;includelib nppi.lib
;includelib nppial.lib
;includelib nppicc.lib
;includelib nppicom.lib
;includelib nppidei.lib
;includelib nppif.lib
;includelib nppig.lib
;includelib nppim.lib
;includelib nppist.lib
;includelib nppisu.lib
;includelib nppitc.lib
;includelib npps.lib
;includelib nvblas.lib
;includelib nvcuvid.lib
;includelib nvgraph.lib
include nvml.inc
includelib nvml.lib
;includelib nvrtc.lib
;includelib OpenCL.lib

include Masm64.Inc
includelib Masm64.lib

include LTLILIB64.inc
includelib LTLILIB64.lib






CudaDevice          STRUCT 8
    DeviceID        DD ?
    VendorName      DQ ?
    DeviceName      DQ ?
    SMVersionString DQ ?
    SM_major        DD ? 
    SM_minor        DD ?
    UUID            DQ ?
    DeviceGlobalMemory DQ ?
    pciDeviceId     DD ?
    pciSubSystemId  DD ?
    SMX             DD ?
    VendorID        DD ?
CudaDevice          ENDS





getVendorId                     PROTO :QWORD
getVendorString                 PROTO :QWORD

;-----------------------------------------------------------------------------------------
; CudaDetection Prototypes
;-----------------------------------------------------------------------------------------
 
nvmlDevice_t                    TYPEDEF QWORD


.CONST

;-----------------------------------------------------------------------------------------
; CudaDetection Constants
;-----------------------------------------------------------------------------------------
; Main Dialog
IDD_DIALOG				EQU 1000

; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; CudaDetection Initialized Data
;-----------------------------------------------------------------------------------------
align 01
szClass					db 'Win64class', 0
szAppName				db 'First Window', 0

ClassName				DB 'DLGCLASS',0
AppName					DB 'LTLI Dialog',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2014',0
szNVMLErrorInit                         DB 'NVML Init Error',0
szNVMLErrorShutdown                     DB 'NVML Shutdown Error',0
szNVMLErrorDeviceGetCount               DB 'NVML DeviceGetCount Error',0
szNVMLErrorDeviceGetHandleByPciBusId    DB 'NVML DeviceGetHandleByPciBusId Error',0
szNVMLErrorDeviceGetPciInfo             DB 'NVML DeviceGetPciInfo Error',0
szNVMLErrorDeviceGetUUID                DB 'NVML DeviceGetUUID Error',0

vendorAsus              DB "ASUS",0
vendorLeadtek           DB "Leadtek",0
vendorGainward          DB "Gainward",0
vendorNvidia            DB "NVIDIA",0
vendorGigabyte          DB "Gigabyte",0
vendorMsi               DB "MSI",0
vendorPny               DB "PNY",0
vendorXfx               DB "XFX",0
vendorClub3D            DB "Club3D",0
vendorZotac             DB "Zotac",0
vendorBfg               DB "BFG",0
vendorPov               DB "PoV",0
vendorKfa2              DB "KFA2",0
vendorEvga              DB "EVGA",0
vendorColorful          DB "Colorful",0
vendorUnknown           DB "UNKNOWN",0


GpuMemInfo              nvmlMemory_t <>
UtilRates               nvmlUtilization_t <>
device_count            DQ 0
props                   CudaDeviceProp <>
cudaDevice              CudaDevice <>
pciBusID                DB PCI_BUS_LEN DUP (0)
uuid                    DB UUID_SIZE DUP (0)
pciInfo                 nvmlPciInfo_t <>
device_t                nvmlDevice_t 0


szDeviceID              DB 8 DUP (0)
szVendorID              DB 8 DUP (0)
szVendorName            DB 256 DUP (0)
szDeviceName            DB NVML_DEVICE_NAME_BUFFER_SIZE DUP (0)
szSMVersion             DB 16 DUP (0)
szSerialNo              DB NVML_DEVICE_SERIAL_BUFFER_SIZE DUP (0)
szBiosVersion           DB NVML_DEVICE_VBIOS_VERSION_BUFFER_SIZE DUP (0)
szDriverVersion         DB NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE DUP (0)
szNVMLVersion           DB NVML_SYSTEM_NVML_VERSION_BUFFER_SIZE DUP (0)
szDeviceGlobalMemory    DB 16 DUP (0)
szPciDeviceID           DB 16 DUP (0)
szPciSubSystemID        DB 16 DUP (0)
szSMX                   DB 8  DUP (0)

szVerMajor              DB 4 DUP (0)
szVerMinor              DB 4 DUP (0)


dwFanSpeed              DD 0
dwPowerLimit            DD 0
dwClock                 DD 0
dwPState                DD 0
dwPowerUsage            DD 0
dwTemp                  DD 0
dwBrandType             DD 0
dwComputeMode           DD 0


hextbl  db '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'

.DATA?
;-----------------------------------------------------------------------------------------
; CudaDetection Uninitialized Data
;-----------------------------------------------------------------------------------------
align 08
icc 					INITCOMMONCONTROLSEX <>
hInstance				HINSTANCE ?
CommandLine				LPSTR ?
hWnd					HWND ?





