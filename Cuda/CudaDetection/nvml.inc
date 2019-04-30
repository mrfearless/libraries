;-------------------------------------------------------------------------------------------
; NVML Constants, Structures & Prototypes
; http://docs.nvidia.com/deploy/nvml-api/index.html
;-------------------------------------------------------------------------------------------


;---------------------------------
; NVML Initialization and Cleanup Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlInitializationAndCleanup.html
;---------------------------------
nvmlInit                            PROTO;                          (void)                                                      Initialize NVML, but don't initialize any GPUs yet.
nvmlShutdown                        PROTO;                          (void)                                                      Shut down NVML by releasing all GPU resources previously allocated with nvmlInit()

;---------------------------------
; NVML Error Reporting Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlErrorReporting.html#group__nvmlErrorReporting
;---------------------------------
nvmlErrorString                     PROTO :QWORD;                   ( nvmlReturn_t result )                                     Helper method for converting NVML error codes into readable strings.

;---------------------------------
; NVML System Queries Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlSystemQueries.html
;---------------------------------
nvmlSystemGetDriverVersion          PROTO :QWORD, :QWORD;           ( char* version, unsigned int  length )                     Retrieves the version of the system's graphics driver.
nvmlSystemGetNVMLVersion            PROTO :QWORD, :QWORD;           ( char* version, unsigned int  length )                     Retrieves the version of the NVML library.
nvmlSystemGetProcessName            PROTO :QWORD, :QWORD;           ( unsigned int  pid, char* name, unsigned int  length )     Gets name of the process with provided process id

;---------------------------------
; NVML Unit Queries Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlUnitQueries.html#group__nvmlUnitQueries
;---------------------------------
nvmlSystemGetHicVersion             PROTO :QWORD, :QWORD;           ( unsigned int* hwbcCount, nvmlHwbcEntry_t* hwbcEntries )   Retrieves the IDs and firmware versions for any Host Interface Cards (HICs) in the system
nvmlUnitGetCount                    PROTO :QWORD;                   ( unsigned int* unitCount )                                 Retrieves the number of units in the system.
nvmlUnitGetDevices                  PROTO :QWORD, :QWORD, :QWORD;   ( nvmlUnit_t unit, unsigned int* deviceCount, nvmlDevice_t* devices ) Retrieves the set of GPU devices that are attached to the specified unit.
nvmlUnitGetFanSpeedInfo             PROTO :QWORD, :QWORD;           ( nvmlUnit_t unit, nvmlUnitFanSpeeds_t* fanSpeeds )         Retrieves the fan speed readings for the unit.
nvmlUnitGetHandleByIndex            PROTO :QWORD, :QWORD;           ( unsigned int  index, nvmlUnit_t* unit )                   Acquire the handle for a particular unit, based on its index.
nvmlUnitGetLedState                 PROTO :QWORD, :QWORD;           ( nvmlUnit_t unit, nvmlLedState_t* state )                  Retrieves the LED state associated with this unit.
nvmlUnitGetPsuInfo                  PROTO :QWORD, :QWORD;           ( nvmlUnit_t unit, nvmlPSUInfo_t* psu )                     Retrieves the PSU stats for the unit.
nvmlUnitGetTemperature              PROTO :QWORD, :QWORD, :QWORD;   ( nvmlUnit_t unit, unsigned int  type, unsigned int* temp ) Retrieves the temperature readings for the unit, in degrees C.
nvmlUnitGetUnitInfo                 PROTO :QWORD, :QWORD;           ( nvmlUnit_t unit, nvmlUnitInfo_t* info )                   Retrieves the static information associated with a unit.

;---------------------------------
; NVML Device Queries Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlDeviceQueries.html#group__nvmlDeviceQueries
;---------------------------------
nvmlDeviceClearCpuAffinity          PROTO :QWORD;                   ( nvmlDevice_t device )                                     Clear all affinity bindings
nvmlDeviceGetAPIRestriction         PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t* isRestricted ) Retrieves the root/admin permissions on the target API. See nvmlRestrictedAPI_t for the list of supported APIs. If an API is restricted only root users can call that API. See nvmlDeviceSetAPIRestriction to change current permissions. 
nvmlDeviceGetApplicationsClock      PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlClockType_t clockType, unsigned int* clockMHz ) Retrieves the current setting of a clock that applications will use unless an overspec situation occurs. Can be changed using nvmlDeviceSetApplicationsClocks
nvmlDeviceGetAutoBoostedClocksEnabled PROTO :QWORD, :QWORD, :QWORD; ( nvmlDevice_t device, nvmlEnableState_t* isEnabled, nvmlEnableState_t* defaultIsEnabled ) Retrieve the current state of auto boosted clocks on a device and store it in isEnabled 
nvmlDeviceGetBAR1MemoryInfo         PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlBAR1Memory_t* bar1Memory )       Gets Total, Available and Used size of BAR1 memory.
nvmlDeviceGetBoardId                PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* boardId )              Retrieves the device boardId from 0-N. Devices with the same boardId indicate GPUs connected to the same PLX. Use in conjunction with nvmlDeviceGetMultiGpuBoard() to decide if they are on the same board as well. The boardId returned is a unique ID for the current configuration.
nvmlDeviceGetBrand                  PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlBrandType_t* type )              Retrieves the brand of this device.
nvmlDeviceGetBridgeChipInfo         PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlBridgeChipHierarchy_t* bridgeHierarchy ) Get Bridge Chip Information for all the bridge chips on the board.
nvmlDeviceGetClockInfo              PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlClockType_t type, unsigned int* clock ) Retrieves the current clock speeds for the device.
nvmlDeviceGetComputeMode            PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlComputeMode_t* mode )            Retrieves the current compute mode for the device.
nvmlDeviceGetComputeRunningProcesses PROTO :QWORD, :QWORD, :QWORD;  ( nvmlDevice_t device, unsigned int* infoCount, nvmlProcessInfo_t* infos ) Get information about processes with a compute context on a device
nvmlDeviceGetCount                  PROTO :QWORD;                   ( unsigned int* deviceCount )                               Retrieves the number of compute devices in the system. A compute device is a single GPU.
nvmlDeviceGetCpuAffinity            PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned int  cpuSetSize, unsignedlong* cpuSet ) Retrieves an array of unsigned ints (sized to cpuSetSize) of bitmasks with the ideal CPU affinity for the device For example, if processors 0, 1, 32, and 33 are ideal for the device and cpuSetSize == 2, result[0] = 0x3, result[1] = 0x3 
nvmlDeviceGetCurrPcieLinkGeneration PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* currLinkGen )          Retrieves the current PCIe link generation
nvmlDeviceGetCurrPcieLinkWidth      PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* currLinkWidth )        Retrieves the current PCIe link width
nvmlDeviceGetCurrentClocksThrottleReasons PROTO :QWORD, :QWORD;     ( nvmlDevice_t device, unsigned long long* clocksThrottleReasons ) Retrieves current clocks throttling reasons.
nvmlDeviceGetDecoderUtilization     PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned int* utilization, unsigned int* samplingPeriodUs ) Retrieves the current utilization and sampling size in microseconds for the Decoder
nvmlDeviceGetDefaultApplicationsClock PROTO :QWORD, :QWORD, :QWORD; ( nvmlDevice_t device, nvmlClockType_t clockType, unsigned int* clockMHz ) etrieves the default applications clock that GPU boots with or defaults to after nvmlDeviceResetApplicationsClocks call. 
nvmlDeviceGetDetailedEccErrors      PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t* eccCounts ) Retrieves the detailed ECC error counts for the device.
nvmlDeviceGetDisplayActive          PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t* isActive )        Retrieves the display active state for the device.
nvmlDeviceGetDisplayMode            PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t* display )         Retrieves the display mode for the device.
nvmlDeviceGetDriverModel            PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlDriverModel_t* current, nvmlDriverModel_t* pending ) Retrieves the current and pending driver model for the device.
nvmlDeviceGetEccMode                PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlEnableState_t* current, nvmlEnableState_t* pending ) Retrieves the current and pending ECC modes for the device.
nvmlDeviceGetEncoderUtilization     PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned int* utilization, unsigned int* samplingPeriodUs ) Retrieves the current utilization and sampling size in microseconds for the Encoder
nvmlDeviceGetEnforcedPowerLimit     PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* limit )                Get the effective power limit that the driver enforces after taking into account all limiters
nvmlDeviceGetFanSpeed               PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* speed )                Retrieves the intended operating speed of the device's fan.
nvmlDeviceGetGpuOperationMode       PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlGpuOperationMode_t* current, nvmlGpuOperationMode_t* pending ) etrieves the current GOM and pending GOM (the one that GPU will switch to after reboot).
nvmlDeviceGetGraphicsRunningProcesses PROTO :QWORD, :QWORD, :QWORD; ( nvmlDevice_t device, unsigned int* infoCount, nvmlProcessInfo_t* infos ) Get information about processes with a graphics context on a device
nvmlDeviceGetHandleByIndex          PROTO :QWORD, :QWORD;           ( unsigned int  index, nvmlDevice_t* device )               Acquire the handle for a particular device, based on its index.
nvmlDeviceGetHandleByPciBusId       PROTO :QWORD, :QWORD;           ( const char* pciBusId, nvmlDevice_t* device )              Acquire the handle for a particular device, based on its PCI bus id.
nvmlDeviceGetHandleBySerial         PROTO :QWORD, :QWORD;           ( const char* serial, nvmlDevice_t* device )                Acquire the handle for a particular device, based on its board serial number.
nvmlDeviceGetHandleByUUID           PROTO :QWORD, :QWORD;           ( const char* uuid, nvmlDevice_t* device )                  Acquire the handle for a particular device, based on its globally unique immutable UUID associated with each device.
nvmlDeviceGetIndex                  PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* index )                Retrieves the NVML index of this device.
nvmlDeviceGetInforomConfigurationChecksum PROTO :QWORD, :QWORD;     ( nvmlDevice_t device, unsigned int* checksum )             Retrieves the checksum of the configuration stored in the device's infoROM.
nvmlDeviceGetInforomImageVersion    PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, char* version, unsigned int  length ) Retrieves the global infoROM image version
nvmlDeviceGetInforomVersion         PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlInforomObject_t object, char* version, unsigned int  length ) Retrieves the version information for the device's infoROM object.
nvmlDeviceGetMaxClockInfo           PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlClockType_t type, unsigned int* clock ) Retrieves the maximum clock speeds for the device.
nvmlDeviceGetMaxPcieLinkGeneration  PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* maxLinkGen )           Retrieves the maximum PCIe link generation possible with this device and system
nvmlDeviceGetMaxPcieLinkWidth       PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* maxLinkWidth )         Retrieves the maximum PCIe link width possible with this device and system
nvmlDeviceGetMemoryErrorCounter     PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, unsigned long long* count ) Retrieves the requested memory error counter for the device.
nvmlDeviceGetMemoryInfo             PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlMemory_t* memory )               Retrieves the amount of used, free and total memory available on the device, in bytes.
nvmlDeviceGetMinorNumber            PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* minorNumber )          Retrieves minor number for the device. The minor number for the device is such that the Nvidia device node file for each GPU will have the form /dev/nvidia[minor number]. 
nvmlDeviceGetMultiGpuBoard          PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* multiGpuBool )         Retrieves whether the device is on a Multi-GPU Board Devices that are on multi-GPU boards will set multiGpuBool to a non-zero value. 
nvmlDeviceGetName                   PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, char* name, unsigned int  length )   Retrieves the name of this device.
nvmlDeviceGetPciInfo                PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlPciInfo_t* pci )                 Retrieves the PCI attributes of this device.
nvmlDeviceGetPcieReplayCounter      PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* value )                Retrieve the PCIe replay counter and rollover information
nvmlDeviceGetPcieThroughput         PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int* value ) Retrieve PCIe utilization information. This function is querying a byte counter over a 20ms interval and thus is the PCIe throughput over that interval. 
nvmlDeviceGetPerformanceState       PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlPstates_t* pState )              Retrieves the current performance state for the device.
nvmlDeviceGetPersistenceMode        PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t* mode )            Retrieves the persistence mode associated with this device.
nvmlDeviceGetPowerManagementDefaultLimit PROTO :QWORD, :QWORD;      ( nvmlDevice_t device, unsigned int* defaultLimit )         Retrieves default power management limit on this device, in milliwatts. Default power management limit is a power management limit that the device boots with. 
nvmlDeviceGetPowerManagementLimit   PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* limit )                Retrieves the power management limit associated with this device.
nvmlDeviceGetPowerManagementLimitConstraints PROTO :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, unsigned int* minLimit, unsigned int* maxLimit ) Retrieves information about possible values of power management limits on this device.
nvmlDeviceGetPowerManagementMode    PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t* mode )            This API has been deprecated.
nvmlDeviceGetPowerState             PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlPstates_t* pState )              Deprecated: Use nvmlDeviceGetPerformanceState.
nvmlDeviceGetPowerUsage             PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int* power )                Retrieves power usage for this GPU in milliwatts and its associated circuitry (e.g. memory)
nvmlDeviceGetRetiredPages           PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int* pageCount, unsigned long long* addresses ) Returns the list of retired pages by source, including pages that are pending retirement
nvmlDeviceGetRetiredPagesPendingStatus PROTO :QWORD, :QWORD;        ( nvmlDevice_t device, nvmlEnableState_t* isPending )       Check if any pages are pending retirement and need a reboot to fully retire.
nvmlDeviceGetSamples                PROTO :QWORD, :QWORD, :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t* sampleValType, unsigned int* sampleCount, nvmlSample_t* samples ) Gets recent samples for the GPU.
nvmlDeviceGetSerial                 PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, char* serial, unsigned int  length ) Retrieves the globally unique board serial number associated with this device's board.
nvmlDeviceGetSupportedClocksThrottleReasons PROTO :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned long long* supportedClocksThrottleReasons ) Retrieves bitmask of supported clocks throttle reasons that can be returned by nvmlDeviceGetCurrentClocksThrottleReasons
nvmlDeviceGetSupportedGraphicsClocks PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, unsigned int  memoryClockMHz, unsigned int* count, unsigned int* clocksMHz ) Retrieves the list of possible graphics clocks that can be used as an argument for nvmlDeviceSetApplicationsClocks. 
nvmlDeviceGetSupportedMemoryClocks  PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned int* count, unsigned int* clocksMHz ) Retrieves the list of possible memory clocks that can be used as an argument for nvmlDeviceSetApplicationsClocks
nvmlDeviceGetTemperature            PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int* temp ) Retrieves the current temperature readings for the device, in degrees C.
nvmlDeviceGetTemperatureThreshold   PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int* temp ) Retrieves the temperature threshold for the GPU with the specified threshold type in degrees C.
nvmlDeviceGetTopologyCommonAncestor PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t* pathInfo ) Retrieve the common ancestor for two devices For all products. Supported on Linux only.
nvmlDeviceGetTopologyNearestGpus    PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int* count, nvmlDevice_t* deviceArray ) Retrieve the set of GPUs that are nearest to a given device at a specific interconnectivity level For all products. Supported on Linux only. 
nvmlDeviceGetTotalEccErrors         PROTO :QWORD, :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long* eccCounts ) Retrieves the total ECC error counts for the device.
nvmlDeviceGetUUID                   PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, char* uuid, unsigned int  length )   Retrieves the globally unique immutable UUID associated with this device, as a 5 part hexadecimal string, that augments the immutable, board serial identifier. 
nvmlDeviceGetUtilizationRates       PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlUtilization_t* utilization )     Retrieves the current utilization rates for the device's major subsystems.
nvmlDeviceGetVbiosVersion           PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, char* version, unsigned int  length ) Get VBIOS version of the device.
nvmlDeviceGetViolationStatus        PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t* violTime ) Gets the duration of time during which the device was throttled (lower than requested clocks) due to power or thermal constraints.
nvmlDeviceOnSameBoard               PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device1, nvmlDevice_t device2, int* onSameBoard ) Check if the GPU devices are on the same physical board.
nvmlDeviceResetApplicationsClocks   PROTO :QWORD;                   ( nvmlDevice_t device )                                     Resets the application clock to the default value
nvmlDeviceSetAutoBoostedClocksEnabled PROTO :QWORD, :QWORD;         ( nvmlDevice_t device, nvmlEnableState_t enabled )          Try to set the current state of auto boosted clocks on a device.
nvmlDeviceSetCpuAffinity            PROTO :QWORD;                   ( nvmlDevice_t device )                                     Sets the ideal affinity for a device using the guidelines given in nvmlDeviceGetCpuAffinity() Currently supports up to 64 processors
nvmlDeviceSetDefaultAutoBoostedClocksEnabled PROTO :QWORD, :QWORD, :QWORD;( nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int  flags ) Try to set the default state of auto boosted clocks on a device. This is the default state that auto boosted clocks will return to when no compute running processes (e.g. CUDA application which have an active context) are running 
nvmlDeviceValidateInforom           PROTO :QWORD;                   ( nvmlDevice_t device )                                     Reads the infoROM from the flash and verifies the checksums.
nvmlSystemGetTopologyGpuSet         PROTO :QWORD, :QWORD, :QWORD;   ( unsigned int  cpuNumber, unsigned int* count, nvmlDevice_t* deviceArray ) Retrieve the set of GPUs that have a CPU affinity with the given CPU number For all products. Supported on Linux only.

;---------------------------------
; NVML Unit Commands Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlUnitCommands.html#group__nvmlUnitCommands
;---------------------------------
nvmlUnitSetLedState                 PROTO :QWORD, :QWORD;           ( nvmlUnit_t unit, nvmlLedColor_t color )                   Set the LED state for the unit. The LED can be either green (0) or amber (1).

;---------------------------------
; NVML Device Commands Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlDeviceCommands.html#group__nvmlDeviceCommands
;---------------------------------
nvmlDeviceClearEccErrorCounts       PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEccCounterType_t counterType )   Clear the ECC error and other memory error counts for the device.
nvmlDeviceSetAPIRestriction         PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted ) Changes the root/admin restructions on certain APIs. See nvmlRestrictedAPI_t for the list of supported APIs
nvmlDeviceSetApplicationsClocks     PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, unsigned int  memClockMHz, unsigned int  graphicsClockMHz ) Set clocks that applications will lock to.
nvmlDeviceSetComputeMode            PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlComputeMode_t mode )             Set the compute mode for the device.
nvmlDeviceSetDriverModel            PROTO :QWORD, :QWORD, :QWORD;   ( nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int  flags ) Set the driver model for the device.
nvmlDeviceSetEccMode                PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t ecc )              Set the ECC mode for the device.
nvmlDeviceSetGpuOperationMode       PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlGpuOperationMode_t mode )        Sets new GOM. See nvmlGpuOperationMode_t for details.
nvmlDeviceSetPersistenceMode        PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, nvmlEnableState_t mode )             Set the persistence mode for the device. For all products. For Linux only
nvmlDeviceSetPowerManagementLimit   PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned int  limit )                Set new power limit of this device.

;---------------------------------
; NVML Event Handling Methods Prototypes - http://docs.nvidia.com/deploy/nvml-api/group__nvmlEvents.html#group__nvmlEvents
;---------------------------------
nvmlDeviceGetSupportedEventTypes    PROTO :QWORD, :QWORD;           ( nvmlDevice_t device, unsigned long long* eventTypes )     Returns information about events supported on device
nvmlDeviceRegisterEvents            PROTO :QWORD, :QWORD, :QWORD; ( nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set ) Starts recording of events on a specified devices and add the events to specified nvmlEventSet_t
nvmlEventSetCreate                  PROTO :QWORD;                   ( nvmlEventSet_t* set )                                     Create an empty set of events. Event set should be freed by nvmlEventSetFree
nvmlEventSetFree                    PROTO :QWORD;                   ( nvmlEventSet_t set )                                      Releases events in the set
nvmlEventSetWait                    PROTO :QWORD, :QWORD, :QWORD;   ( nvmlEventSet_t set, nvmlEventData_t* data, unsigned int  timeoutms ) Waits on events and delivers events


;---------------------------------
; NVML Defines
;---------------------------------
PCI_BUS_LEN                             EQU 64
UUID_SIZE                               EQU 128
NVML_DEVICE_PCI_BUS_ID_BUFFER_SIZE      EQU 16;     Buffer size guaranteed to be large enough for pci bus id 
NVML_MAX_PHYSICAL_BRIDGE                EQU 128;    Maximum limit on Physical Bridges per Board
NVML_VALUE_NOT_AVAILABLE                EQU -1;     Special constant that some fields take when they are not available. Used when only part of the struct is not available.
NVML_DEVICE_INFOROM_VERSION_BUFFER_SIZE EQU 16;     Buffer size guaranteed to be large enough for nvmlDeviceGetInforomVersion and nvmlDeviceGetInforomImageVersion
NVML_DEVICE_UUID_BUFFER_SIZE            EQU 80;     Buffer size guaranteed to be large enough for nvmlDeviceGetUUID
NVML_DEVICE_PART_NUMBER_BUFFER_SIZE     EQU 80
NVML_SYSTEM_DRIVER_VERSION_BUFFER_SIZE  EQU 80;     Buffer size guaranteed to be large enough for nvmlSystemGetDriverVersion
NVML_SYSTEM_NVML_VERSION_BUFFER_SIZE    EQU 80;     Buffer size guaranteed to be large enough for nvmlSystemGetNVMLVersion
NVML_DEVICE_NAME_BUFFER_SIZE            EQU 64;     Buffer size guaranteed to be large enough for nvmlDeviceGetName
NVML_DEVICE_SERIAL_BUFFER_SIZE          EQU 30;     Buffer size guaranteed to be large enough for nvmlDeviceGetSerial
NVML_DEVICE_VBIOS_VERSION_BUFFER_SIZE   EQU 32;     Buffer size guaranteed to be large enough for nvmlDeviceGetVbiosVersion
nvmlFlagDefault                         EQU 00h;    Generic flag used to specify the default behavior of some functions. See description of particular functions for details. 
nvmlFlagForce                           EQU 01h;    Generic flag used to force some behavior. See description of particular functions for details. 


;---------------------------------
; NVML Enumeration and Equates - http://docs.nvidia.com/deploy/nvml-api/group__nvmlDeviceEnumvs.html#group__nvmlDeviceEnumvs
;---------------------------------
;nvmlBrandType_t                        The Brand of the GPU
NVML_BRAND_UNKNOWN                      EQU 0
NVML_BRAND_QUADRO                       EQU 1
NVML_BRAND_TESLA                        EQU 2
NVML_BRAND_NVS                          EQU 3
NVML_BRAND_GRID                         EQU 4
NVML_BRAND_GEFORCE                      EQU 5
NVML_BRAND_COUNT                        EQU 6
;nvmlClockType_t                        Clock types. All speeds are in Mhz
NVML_CLOCK_GRAPHICS                     EQU 0;    Graphics clock domain. 
NVML_CLOCK_SM                           EQU 1;    SM clock domain. 
NVML_CLOCK_MEM                          EQU 2;    Memory clock domain. 
NVML_CLOCK_COUNT                        EQU 3
;nvmlComputeMode_t                      Compute mode. NVML_COMPUTEMODE_EXCLUSIVE_PROCESS was added in CUDA 4.0. Earlier CUDA versions supported a single exclusive mode, which is equivalent to NVML_COMPUTEMODE_EXCLUSIVE_THREAD in CUDA 4.0 and beyond.
NVML_COMPUTEMODE_DEFAULT                EQU 0;    Default compute mode -- multiple contexts per device. 
NVML_COMPUTEMODE_EXCLUSIVE_THREAD       EQU 1;    Compute-exclusive-thread mode -- only one context per device, usable from one thread at a time This mode has been deprecated and will be removed in future releases. 
NVML_COMPUTEMODE_PROHIBITED             EQU 2;    Compute-prohibited mode -- no contexts per device. 
NVML_COMPUTEMODE_EXCLUSIVE_PROCESS      EQU 3;    Compute-exclusive-process mode -- only one context per device, usable from multiple threads at a time. 
NVML_COMPUTEMODE_COUNT                  EQU 4
;nvmlDriverModel_t                      Driver models. Windows only.
NVML_DRIVER_WDDM                        EQU 0;    WDDM driver model -- GPU treated as a display device. 
NVML_DRIVER_WDM                         EQU 1;    WDM (TCC) model (recommended) -- GPU treated as a generic device. 
;nvmlEccCounterType_t                   ECC counter types. Note: Volatile counts are reset each time the driver loads. On Windows this is once per boot. On Linux this can be more frequent. On Linux the driver unloads when no active clients exist. If persistence mode is enabled or there is always a driver client active (e.g. X11), then Linux also sees per-boot behavior. If not, volatile counts are reset each time a compute app is run.
NVML_VOLATILE_ECC                       EQU 0;    Volatile counts are reset each time the driver loads. 
NVML_AGGREGATE_ECC                      EQU 1;    Aggregate counts persist across reboots (i.e. for the lifetime of the device). 
NVML_ECC_COUNTER_TYPE_COUNT             EQU 2;    Count of memory counter types. 
;nvmlEnableState_t                      Generic enable/disable enum.
NVML_FEATURE_DISABLED                   EQU 0;    Feature disabled. 
NVML_FEATURE_ENABLED                    EQU 1;    Feature enabled. 
;nvmlGpuOperationMode_t                 GPU Operation Mode. GOM allows to reduce power usage and optimize GPU throughput by disabling GPU features. Each GOM is designed to meet specific user needs.
NVML_GOM_ALL_ON                         EQU 0;    Everything is enabled and running at full speed. 
NVML_GOM_COMPUTE                        EQU 1;    Designed for running only compute tasks. Graphics operations are not allowed 
NVML_GOM_LOW_DP                         EQU 2;    Designed for running graphics applications that dont require high bandwidth double precision 
;nvmlInforomObject_t                    Available infoROM objects.
NVML_INFOROM_OEM                        EQU 0;    An object defined by OEM. 
NVML_INFOROM_ECC                        EQU 1;    The ECC object determining the level of ECC support. 
NVML_INFOROM_POWER                      EQU 2;    The power management object. 
NVML_INFOROM_COUNT                      EQU 3;    This counts the number of infoROM objects the driver knows about.
;nvmlMemoryErrorType_t                  Memory error types
NVML_MEMORY_ERROR_TYPE_CORRECTED        EQU 0;    A memory error that was correctedFor ECC errors, these are single bit errors For Texture memory, these are errors fixed by resend 
NVML_MEMORY_ERROR_TYPE_UNCORRECTED      EQU 1;    A memory error that was not correctedFor ECC errors, these are double bit errors For Texture memory, these are errors where the resend fails 
NVML_MEMORY_ERROR_TYPE_COUNT            EQU 2;    Count of memory error types.
;nvmlMemoryLocation_t                   Memory locations See nvmlDeviceGetMemoryErrorCounter
NVML_MEMORY_LOCATION_L1_CACHE           EQU 0;    GPU L1 Cache. 
NVML_MEMORY_LOCATION_L2_CACHE           EQU 1;    GPU L2 Cache. 
NVML_MEMORY_LOCATION_DEVICE_MEMORY      EQU 2;    GPU Device Memory. 
NVML_MEMORY_LOCATION_REGISTER_FILE      EQU 3;    GPU Register File. 
NVML_MEMORY_LOCATION_TEXTURE_MEMORY     EQU 4;    GPU Texture Memory. 
NVML_MEMORY_LOCATION_COUNT              EQU 5;    This counts the number of memory locations the driver knows about. 
;nvmlPageRetirementCause_t                                  Causes for page retirement    
NVML_PAGE_RETIREMENT_CAUSE_MULTIPLE_SINGLE_BIT_ECC_ERRORS   EQU 0;    Page was retired due to multiple single bit ECC error
NVML_PAGE_RETIREMENT_CAUSE_DOUBLE_BIT_ECC_ERROR             EQU 1;    Page was retired due to double bit ECC error. 
NVML_PAGE_RETIREMENT_CAUSE_COUNT                            EQU 2
;nvmlPstates_t                          Allowed PStates.
NVML_PSTATE_0                           EQU 0;    Performance state 0 -- Maximum Performance. 
NVML_PSTATE_1                           EQU 1;    Performance state 1. 
NVML_PSTATE_2                           EQU 2;    Performance state 2. 
NVML_PSTATE_3                           EQU 3;    Performance state 3. 
NVML_PSTATE_4                           EQU 4;    Performance state 4. 
NVML_PSTATE_5                           EQU 5;    Performance state 5. 
NVML_PSTATE_6                           EQU 6;    Performance state 6. 
NVML_PSTATE_7                           EQU 7;    Performance state 7. 
NVML_PSTATE_8                           EQU 8;    Performance state 8. 
NVML_PSTATE_9                           EQU 9;    Performance state 9. 
NVML_PSTATE_10                          EQU 10;   Performance state 10. 
NVML_PSTATE_11                          EQU 11;   Performance state 11. 
NVML_PSTATE_12                          EQU 12;   Performance state 12. 
NVML_PSTATE_13                          EQU 13;   Performance state 13. 
NVML_PSTATE_14                          EQU 14;   Performance state 14. 
NVML_PSTATE_15                          EQU 15;   Performance state 15 -- Minimum Performance. 
NVML_PSTATE_UNKNOWN                     EQU 32;   Unknown performance state. 
;nvmlRestrictedAPI_t                            API types that allow changes to default permission restrictions
NVML_RESTRICTED_API_SET_APPLICATION_CLOCKS      EQU 0;    APIs that change application clocks, see nvmlDeviceSetApplicationsClocks and see nvmlDeviceResetApplicationsClocks 
NVML_RESTRICTED_API_SET_AUTO_BOOSTED_CLOCKS     EQU 1;    APIs that enable/disable auto boosted clocks see nvmlDeviceSetAutoBoostedClocksEnabled 
NVML_RESTRICTED_API_COUNT                       EQU 2
;nvmlReturn_t                           Return values for NVML API calls.
NVML_SUCCESS                            EQU 0;    The operation was successful. 
NVML_ERROR_UNINITIALIZED                EQU 1;    NVML was not first initialized with nvmlInit(). 
NVML_ERROR_INVALID_ARGUMENT             EQU 2;    A supplied argument is invalid. 
NVML_ERROR_NOT_SUPPORTED                EQU 3;    The requested operation is not available on target device. 
NVML_ERROR_NO_PERMISSION                EQU 4;    The current user does not have permission for operation. 
NVML_ERROR_ALREADY_INITIALIZED          EQU 5;    Deprecated: Multiple initializations are now allowed through ref counting. 
NVML_ERROR_NOT_FOUND                    EQU 6;    A query to find an object was unsuccessful. 
NVML_ERROR_INSUFFICIENT_SIZE            EQU 7;    An input argument is not large enough. 
NVML_ERROR_INSUFFICIENT_POWER           EQU 8;    A device's external power cables are not properly attached. 
NVML_ERROR_DRIVER_NOT_LOADED            EQU 9;    NVIDIA driver is not loaded. 
NVML_ERROR_TIMEOUT                      EQU 10;   User provided timeout passed. 
NVML_ERROR_IRQ_ISSUE                    EQU 11;   NVIDIA Kernel detected an interrupt issue with a GPU. 
NVML_ERROR_LIBRARY_NOT_FOUND            EQU 12;   NVML Shared Library couldn't be found or loaded. 
NVML_ERROR_FUNCTION_NOT_FOUND           EQU 13;   Local version of NVML doesn't implement this function. 
NVML_ERROR_CORRUPTED_INFOROM            EQU 14;   infoROM is corrupted 
NVML_ERROR_GPU_IS_LOST                  EQU 15;   The GPU has fallen off the bus or has otherwise become inaccessible. 
NVML_ERROR_RESET_REQUIRED               EQU 16;   The GPU requires a reset before it can be used again. 
NVML_ERROR_OPERATING_SYSTEM             EQU 17;   The GPU control device has been blocked by the operating system/cgroups. 
NVML_ERROR_UNKNOWN                      EQU 999;  An internal driver error occurred. 
;nvmlTemperatureSensors_t               Temperature sensors.
NVML_TEMPERATURE_GPU                    EQU 0;    Temperature sensor for the GPU die. 
NVML_TEMPERATURE_COUNT                  EQU 1
;nvmlTemperatureThresholds_t            Temperature thresholds. 
NVML_TEMPERATURE_THRESHOLD_SHUTDOWN     EQU 0
NVML_TEMPERATURE_THRESHOLD_SLOWDOWN     EQU 1
NVML_TEMPERATURE_THRESHOLD_COUNT        EQU 2
;nvmlBridgeChipType_t                   Enum to represent type of bridge chip     
NVML_BRIDGE_CHIP_PLX                    EQU 0
NVML_BRIDGE_CHIP_BRO4                   EQU 1
;nvmlGpuTopologyLevel_t                 Represents level relationships within a system between two GPUs The enums are spaced to allow for future relationships 
NVML_TOPOLOGY_INTERNAL                  EQU 0
NVML_TOPOLOGY_SINGLE                    EQU 10
NVML_TOPOLOGY_MULTIPLE                  EQU 20
NVML_TOPOLOGY_HOSTBRIDGE                EQU 30
NVML_TOPOLOGY_CPU                       EQU 40
NVML_TOPOLOGY_SYSTEM                    EQU 50
;nvmlPcieUtilCounter_t                  Represents the queryable PCIe utilization counters 
NVML_PCIE_UTIL_TX_BYTES                 EQU 0
NVML_PCIE_UTIL_RX_BYTES                 EQU 1
NVML_PCIE_UTIL_COUNT                    EQU 2
;nvmlPerfPolicyType_t                   Represents type of perf policy for which violation times can be queried
NVML_PERF_POLICY_POWER                  EQU 0
NVML_PERF_POLICY_THERMAL                EQU 1
NVML_PERF_POLICY_COUNT                  EQU 2
;nvmlSamplingType_t                     Represents Type of Sampling Event
NVML_TOTAL_POWER_SAMPLES                EQU 0;    To represent total power drawn by GPU. 
NVML_GPU_UTILIZATION_SAMPLES            EQU 1;    To represent percent of time during which one or more kernels was executing on the GPU. 
NVML_MEMORY_UTILIZATION_SAMPLES         EQU 2;    To represent percent of time during which global (device) memory was being read or written. 
NVML_ENC_UTILIZATION_SAMPLES            EQU 3;    To represent percent of time during which NVENC remains busy. 
NVML_DEC_UTILIZATION_SAMPLES            EQU 4;    To represent percent of time during which NVDEC remains busy. 
NVML_PROCESSOR_CLK_SAMPLES              EQU 5;    To represent processor clock samples. 
NVML_MEMORY_CLK_SAMPLES                 EQU 6;    To represent memory clock samples. 
NVML_SAMPLINGTYPE_COUNT                 EQU 7
;nvmlValueType_t                        Represents the type for sample value returned
NVML_VALUE_TYPE_DOUBLE                  EQU 0
NVML_VALUE_TYPE_UNSIGNED_INT            EQU 1
NVML_VALUE_TYPE_UNSIGNED_LONG           EQU 2
NVML_VALUE_TYPE_UNSIGNED_LONG_LONG      EQU 3
NVML_VALUE_TYPE_COUNT                   EQU 4
;nvmlFanState_t                         Fan state enum.
NVML_FAN_NORMAL                         EQU 0;    Fan is working properly. 
NVML_FAN_FAILED                         EQU 1;    Fan has failed. 
;nvmlLedColor_t                         Led color enum.
NVML_LED_COLOR_GREEN                    EQU 0;    GREEN, indicates good health. 
NVML_LED_COLOR_AMBER                    EQU 1;    AMBER, indicates problem. 
;nvmlEventTypeAll
nvmlEventTypeClock                      EQU 0x0000000000000010LL;    Event about clock changes. 
nvmlEventTypeDoubleBitEccError          EQU 0x0000000000000002LL;    Event about double bit ECC errors. 
nvmlEventTypeNone                       EQU 0x0000000000000000LL;    Mask with no events. 
nvmlEventTypePState                     EQU 0x0000000000000004LL;    Event about PState changes. 
nvmlEventTypeSingleBitEccError          EQU 0x0000000000000001LL;    Event about single bit ECC errors. 
nvmlEventTypeXidCriticalError           EQU 0x0000000000000008LL;    Event that Xid critical error occurred. 
;nvmlClocksThrottleReasonAll
nvmlClocksThrottleReasonApplicationsClocksSetting   EQU 0x0000000000000002LL
nvmlClocksThrottleReasonGpuIdle                     EQU 0x0000000000000001LL
nvmlClocksThrottleReasonHwSlowdown                  EQU 0x0000000000000008LL
nvmlClocksThrottleReasonNone                        EQU 0x0000000000000000LL
nvmlClocksThrottleReasonSwPowerCap                  EQU 0x0000000000000004LL
nvmlClocksThrottleReasonUnknown                     EQU 0x8000000000000000LL
;nvmlNvLinkUtilizationCountUnits_enum
NVML_NVLINK_COUNTER_UNIT_CYCLES         EQU 0;    count by cycles
NVML_NVLINK_COUNTER_UNIT_PACKETS        EQU 1;    count by packets
NVML_NVLINK_COUNTER_UNIT_BYTES          EQU 2;    count by bytes
;nvmlNvLinkUtilizationCountPktTypes_enum
NVML_NVLINK_COUNTER_PKTFILTER_NOP       EQU 1h;   no operation packets
NVML_NVLINK_COUNTER_PKTFILTER_READ      EQU 2h;   read packets
NVML_NVLINK_COUNTER_PKTFILTER_WRITE     EQU 4h;   write packets
NVML_NVLINK_COUNTER_PKTFILTER_RATOM     EQU 8h;   reduction atomic requests
NVML_NVLINK_COUNTER_PKTFILTER_NRATOM    EQU 10h;  non-reduction atomic requests
NVML_NVLINK_COUNTER_PKTFILTER_FLUSH     EQU 20h;  flush requests
NVML_NVLINK_COUNTER_PKTFILTER_RESPDATA  EQU 40h;  responses with data
NVML_NVLINK_COUNTER_PKTFILTER_RESPNODATA EQU 80h; responses without data
NVML_NVLINK_COUNTER_PKTFILTER_ALL       EQU 0FFh; all packets
;nvmlNvLinkCapability_enum
NVML_NVLINK_CAP_P2P_SUPPORTED           EQU 0;    P2P over NVLink is supported
NVML_NVLINK_CAP_SYSMEM_ACCESS           EQU 1;    Access to system memory is supported
NVML_NVLINK_CAP_P2P_ATOMICS             EQU 2;    P2P atomics are supported
NVML_NVLINK_CAP_SYSMEM_ATOMICS          EQU 3;    System memory atomics are supported
NVML_NVLINK_CAP_SLI_BRIDGE              EQU 4;    SLI is supported over this link
NVML_NVLINK_CAP_VALID                   EQU 5;    Link is supported on this device
;nvmlNvLinkErrorCounter_enum
NVML_NVLINK_ERROR_DL_REPLAY             EQU 0;    Data link transmit replay error counter
NVML_NVLINK_ERROR_DL_RECOVERY           EQU 1;    Data link transmit recovery error counter
NVML_NVLINK_ERROR_DL_CRC_FLIT           EQU 2;    Data link receive flow control digit CRC error counter
NVML_NVLINK_ERROR_DL_CRC_DATA           EQU 3;    Data link receive data CRC error counter
;nvmlGpuP2PStatus_enum
NVML_P2P_STATUS_OK                      EQU 0;
NVML_P2P_STATUS_CHIPSET_NOT_SUPPORED    EQU 1
NVML_P2P_STATUS_GPU_NOT_SUPPORTED       EQU 2
NVML_P2P_STATUS_IOH_TOPOLOGY_NOT_SUPPORTED EQU 3 
NVML_P2P_STATUS_DISABLED_BY_REGKEY      EQU 4
NVML_P2P_STATUS_NOT_SUPPORTED           EQU 5
NVML_P2P_STATUS_UNKNOWN                 EQU 6 
;nvmlGpuP2PCapsIndex_enum
NVML_P2P_CAPS_INDEX_READ                EQU 0
NVML_P2P_CAPS_INDEX_WRITE               EQU 1
NVML_P2P_CAPS_INDEX_NVLINK              EQU 2
NVML_P2P_CAPS_INDEX_ATOMICS             EQU 3
NVML_P2P_CAPS_INDEX_PROP                EQU 4
NVML_P2P_CAPS_INDEX_UNKNOWN             EQU 5


;--------------------
; NVML DEVICE STRUCTS - https://docs.nvidia.com/deploy/nvml-api/group__nvmlDeviceStructs.html
;--------------------
nvmlBridgeChipInfo_t            STRUCT 8
    chiptype                    DD ?        ; nvmlBridgeChipType_t
    fwVersion                   DD ?
nvmlBridgeChipInfo_t            ENDS

nvmlBridgeChipHierarchy_t       STRUCT 8    ;This structure stores the complete Hierarchy of the Bridge Chip within the board. The immediate bridge is stored at index 0 of bridgeInfoList, parent to immediate bridge is at index 1 and so forth.
    bridgeCount                 DB ?
    bridgeChipInfo              nvmlBridgeChipInfo_t NVML_MAX_PHYSICAL_BRIDGE DUP (<>)
nvmlBridgeChipHierarchy_t       ENDS

nvmlPciInfo_t                   STRUCT 8
    busId                       DB NVML_DEVICE_PCI_BUS_ID_BUFFER_SIZE DUP (?) ;    The tuple domain:bus:device.function PCI identifier (& NULL terminator).
    domain                      DD ?;       The PCI domain on which the device's bus resides, 0 to 0xffff.
    bus                         DD ?;       The bus on which the device resides, 0 to 0xff. 
    device                      DD ?;       The device's id on the bus, 0 to 31. 
    pciDeviceId                 DD ?;       The combined 16-bit device id and 16-bit vendor id. 
    pciSubSystemId              DD ?;       The 32-bit Sub System Device ID. 
    pciSubVendorId              DD ?
    dwReserved1                 DD ?
    dwReserved2                 DD ?
    dwReserved3                 DD ?
nvmlPciInfo_t                   ENDS

nvmlEccErrorCounts_t            STRUCT 8
    l1Cache                     DQ ?;       L1 cache errors.
    l2Cache                     DQ ?;       L2 cache errors.
    deviceMemory                DQ ?;       Device memory errors.
    registerFile                DQ ?;       Register file errors
nvmlEccErrorCounts_t            ENDS

nvmlUtilization_t               STRUCT 8
    gpu                         DD ?;       Percent of time over the past sample period during which one or more kernels was executing on the GPU
    memory                      DD ?;       Percent of time over the past sample period during which global (device) memory was being read or written.
nvmlUtilization_t               ENDS

nvmlMemory_t                    STRUCT 8
    totalmemory                 DQ ?;       Total installed FB memory (in bytes).
    freememory                  DQ ?;       Unallocated FB memory (in bytes)
    usedmemory                  DQ ?;       Allocated FB memory (in bytes). Note that the driver/GPU always sets aside a small amount of memory for bookkeeping
nvmlMemory_t                    ENDS

nvmlBAR1Memory_t                STRUCT 8    ;BAR1 Memory allocation Information for a device
    bar1Free                    DQ ?
    bar1Total                   DQ ?
    bar1Used                    DQ ?
nvmlBAR1Memory_t                ENDS

nvmlProcessInfo_t               STRUCT 8
    pid                         DD ?;       Process ID
    usedGpuMemory               DQ ?;       Amount of used GPU memory in bytes.  Under WDDM, NVML_VALUE_NOT_AVAILABLE is always reported because Windows KMD manages all the memory and not the NVIDIA driver.
nvmlProcessInfo_t               ENDS

nvmlNvLinkUtilizationControl_t  STRUCT 8
    units                       DD ?;       nvmlNvLinkUtilizationCountUnits_enum
    pktfilter                   DD ?;       nvmlNvLinkUtilizationCountPktTypes_enum
nvmlNvLinkUtilizationControl_t  ENDS

nvmlValue_t                     STRUCT 8
    dVal                        REAL8 ?;   If the value is double
    uiVal                       DD ?;      If the value is unsigned int
    ulVal                       DD ?;      If the value is unsigned long
    ullVal                      DQ ?;      If the value is unsigned long long
nvmlValue_t                     ENDS

nvmlSample_t                    STRUCT 8
    timeStamp                   DQ ?;      CPU Timestamp in microseconds
    sampleValue                 nvmlValue_t <>;      nvmlValue_t Sample Value
nvmlSample_t                    ENDS

nvmlViolationTime_t             STRUCT 8
    referenceTime               DQ ?;       referenceTime represents CPU timestamp in microseconds
    violationTime               DQ ?;       violationTime in Nanoseconds
nvmlViolationTime_t             ENDS

nvmlHwbcEntry_t                 STRUCT 8
    hwbcId                      DD ?;
    firmwareVersion             DB 32 DUP (?);
nvmlHwbcEntry_t                 ENDS

nvmlLedState_t                  STRUCT 8
    cause                       DB 256 DUP (?);If amber, a text description of the cause
    color                       DD ?;          nvmlLedColor_t GREEN or AMBER
nvmlLedState_t                  ENDS

nvmlUnitInfo_t                  STRUCT 8
    unitname                    DB 96 DUP (?); Product name
    id                          DB 96 DUP (?); Product identifier
    serial                      DB 96 DUP (?); Product serial number
    firmwareVersion             DB 96 DUP (?); Firmware version
nvmlUnitInfo_t                  ENDS

nvmlPSUInfo_t                   STRUCT 8
    state                       DB 256 DUP (?); The power supply state
    current                     DD ?;           PSU current (A)
    voltage                     DD ?;           PSU voltage (V)
    power                       DD ?;           PSU power draw (W)
nvmlPSUInfo_t                   ENDS

nvmlUnitFanInfo_t               STRUCT 8
    speed                       DD ?;   Fan speed (RPM)
    state                       DD ?;   nvmlFanState_t Flag that indicates whether fan is working properly
nvmlUnitFanInfo_t               ENDS

nvmlUnitFanSpeeds_t             STRUCT 8
    fans                        nvmlUnitFanInfo_t 24 DUP (<>); Fan speed data for each fan
    count                       DD ?;                         Number of fans in unit
nvmlUnitFanSpeeds_t             ENDS

nvmlEventData_t                 STRUCT 8
    device                      DD ?;       nvmlDevice_t Specific device where the event occurred
    eventType                   DQ ?;       Information about what specific event occurred
    eventData                   DQ ?;       Stores last XID error for the device in the event of nvmlEventTypeXidCriticalError, eventData is 0 for any other event. eventData is set as 999 for unknown xid error.
nvmlEventData_t                 ENDS

nvmlAccountingStats_t           STRUCT 8  
    gpuUtilization              DD ?;       Percent of time over the process's lifetime during which one or more kernels was executing on the GPU.
                                    ;       Utilization stats just like returned by \ref nvmlDeviceGetUtilizationRates but for the life time of a
                                    ;       process (not just the last sample period).
                                    ;       Set to NVML_VALUE_NOT_AVAILABLE if nvmlDeviceGetUtilizationRates is not supported
    memoryUtilization           DD ?;       Percent of time over the process's lifetime during which global (device) memory was being read or written.
                                    ;       Set to NVML_VALUE_NOT_AVAILABLE if nvmlDeviceGetUtilizationRates is not supported
    maxMemoryUsage              DQ ?;       Maximum total memory in bytes that was ever allocated by the process.
                                    ;       Set to NVML_VALUE_NOT_AVAILABLE if nvmlProcessInfo_t->usedGpuMemory is not supported
    time                        DQ ?;       Amount of time in ms during which the compute context was active. The time is reported as 0 if 
                                    ;       the process is not terminated
    startTime                   DQ ?;       CPU Timestamp in usec representing start time for the process
    isRunning                   DD ?;       Flag to represent if the process is running (1 for running, 0 for terminated)
    reserved                    DD 5 DUP (?); Reserved for future use
nvmlAccountingStats_t           ENDS


nvmlDevice_t                    TYPEDEF QWORD
nvmlDevice                      TYPEDEF QWORD
