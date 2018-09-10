
; Copyright (c) 2015-2018 The Khronos Group Inc.
;
; Licensed under the Apache License, Version 2.0 (the "License");
; you may not use this file except in compliance with the License.
; You may obtain a copy of the License at
;
; http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing, software
; distributed under the License is distributed on an "AS IS" BASIS,
; WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; See the License for the specific language governing permissions and
; limitations under the License.
;
; Conversion to x86 assembler format of vulkan_core.h, vulkan_win32.h from Vulkan SDK
; https://github.com/KhronosGroup/Vulkan-Docs/blob/master/src/vulkan
; https://vulkan.lunarg.com/sdk/home
;
; by fearless 2018 
;
; github.com/mrfearless
;



;-------------------------------------------------------------------------------------------
; Vulkan Constants, Structures & Prototypes
; https://vulkan.lunarg.com/doc/sdk/1.1.70.0/windows/vkspec.html
; https://vulkan.lunarg.com/doc/sdk/1.1.70.0/windows/apispec.html
;-------------------------------------------------------------------------------------------
BindBufferMemory2KHR PROTO :DWORD,:DWORD,:DWORD
BindImageMemory2KHR PROTO :DWORD,:DWORD,:DWORD
CmdBeginDebugUtilsLabelEXT PROTO :DWORD,:DWORD
CmdDebugMarkerBeginEXT PROTO :DWORD,:DWORD
CmdDebugMarkerEndEXT PROTO :DWORD
CmdDebugMarkerInsertEXT PROTO :DWORD,:DWORD
CmdDispatchBaseKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CmdDrawIndexedIndirectCountAMD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CmdDrawIndirectCountAMD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CmdEndDebugUtilsLabelEXT PROTO :DWORD
CmdInsertDebugUtilsLabelEXT PROTO :DWORD,:DWORD
CmdProcessCommandsNVX PROTO :DWORD,:DWORD
CmdPushDescriptorSetKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CmdPushDescriptorSetWithTemplateKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CmdReserveSpaceForCommandsNVX PROTO :DWORD,:DWORD
CmdSetDeviceMaskKHR PROTO :DWORD,:DWORD
CmdSetDiscardRectangleEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
CmdSetSampleLocationsEXT PROTO :DWORD,:DWORD
CmdSetViewportWScalingNV PROTO :DWORD,:DWORD,:DWORD,:DWORD
CmdWriteBufferMarkerAMD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateDescriptorUpdateTemplateKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateIndirectCommandsLayoutNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateObjectTableNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateSamplerYcbcrConversionKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreateValidationCacheEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
DEVPKEY_DeviceClass_Characteristics PROTO C :VARARG
DEVPKEY_DeviceClass_ClassCoInstallers PROTO C :VARARG
DEVPKEY_DeviceClass_ClassInstaller PROTO C :VARARG
DEVPKEY_DeviceClass_ClassName PROTO C :VARARG
DEVPKEY_DeviceClass_DHPRebalanceOptOut PROTO C :VARARG
DEVPKEY_DeviceClass_DefaultService PROTO C :VARARG
DEVPKEY_DeviceClass_DevType PROTO C :VARARG
DEVPKEY_DeviceClass_Exclusive PROTO C :VARARG
DEVPKEY_DeviceClass_Icon PROTO C :VARARG
DEVPKEY_DeviceClass_IconPath PROTO C :VARARG
DEVPKEY_DeviceClass_LowerFilters PROTO C :VARARG
DEVPKEY_DeviceClass_Name PROTO C :VARARG
DEVPKEY_DeviceClass_NoDisplayClass PROTO C :VARARG
DEVPKEY_DeviceClass_NoInstallClass PROTO C :VARARG
DEVPKEY_DeviceClass_NoUseClass PROTO C :VARARG
DEVPKEY_DeviceClass_PropPageProvider PROTO C :VARARG
DEVPKEY_DeviceClass_Security PROTO C :VARARG
DEVPKEY_DeviceClass_SecuritySDS PROTO C :VARARG
DEVPKEY_DeviceClass_SilentInstall PROTO C :VARARG
DEVPKEY_DeviceClass_UpperFilters PROTO C :VARARG
DEVPKEY_DeviceContainer_Address PROTO C :VARARG
DEVPKEY_DeviceContainer_AlwaysShowDeviceAsConnected PROTO C :VARARG
DEVPKEY_DeviceContainer_AssociationArray PROTO C :VARARG
DEVPKEY_DeviceContainer_BaselineExperienceId PROTO C :VARARG
DEVPKEY_DeviceContainer_Category PROTO C :VARARG
DEVPKEY_DeviceContainer_CategoryGroup_Desc PROTO C :VARARG
DEVPKEY_DeviceContainer_CategoryGroup_Icon PROTO C :VARARG
DEVPKEY_DeviceContainer_Category_Desc_Plural PROTO C :VARARG
DEVPKEY_DeviceContainer_Category_Desc_Singular PROTO C :VARARG
DEVPKEY_DeviceContainer_Category_Icon PROTO C :VARARG
DEVPKEY_DeviceContainer_ConfigFlags PROTO C :VARARG
DEVPKEY_DeviceContainer_CustomPrivilegedPackageFamilyNames PROTO C :VARARG
DEVPKEY_DeviceContainer_DeviceDescription1 PROTO C :VARARG
DEVPKEY_DeviceContainer_DeviceDescription2 PROTO C :VARARG
DEVPKEY_DeviceContainer_DeviceFunctionSubRank PROTO C :VARARG
DEVPKEY_DeviceContainer_DiscoveryMethod PROTO C :VARARG
DEVPKEY_DeviceContainer_ExperienceId PROTO C :VARARG
DEVPKEY_DeviceContainer_FriendlyName PROTO C :VARARG
DEVPKEY_DeviceContainer_HasProblem PROTO C :VARARG
DEVPKEY_DeviceContainer_Icon PROTO C :VARARG
DEVPKEY_DeviceContainer_InstallInProgress PROTO C :VARARG
DEVPKEY_DeviceContainer_IsAuthenticated PROTO C :VARARG
DEVPKEY_DeviceContainer_IsConnected PROTO C :VARARG
DEVPKEY_DeviceContainer_IsDefaultDevice PROTO C :VARARG
DEVPKEY_DeviceContainer_IsDeviceUniquelyIdentifiable PROTO C :VARARG
DEVPKEY_DeviceContainer_IsEncrypted PROTO C :VARARG
DEVPKEY_DeviceContainer_IsLocalMachine PROTO C :VARARG
DEVPKEY_DeviceContainer_IsMetadataSearchInProgress PROTO C :VARARG
DEVPKEY_DeviceContainer_IsNetworkDevice PROTO C :VARARG
DEVPKEY_DeviceContainer_IsNotInterestingForDisplay PROTO C :VARARG
DEVPKEY_DeviceContainer_IsPaired PROTO C :VARARG
DEVPKEY_DeviceContainer_IsRebootRequired PROTO C :VARARG
DEVPKEY_DeviceContainer_IsSharedDevice PROTO C :VARARG
DEVPKEY_DeviceContainer_IsShowInDisconnectedState PROTO C :VARARG
DEVPKEY_DeviceContainer_Last_Connected PROTO C :VARARG
DEVPKEY_DeviceContainer_Last_Seen PROTO C :VARARG
DEVPKEY_DeviceContainer_LaunchDeviceStageFromExplorer PROTO C :VARARG
DEVPKEY_DeviceContainer_LaunchDeviceStageOnDeviceConnect PROTO C :VARARG
DEVPKEY_DeviceContainer_Manufacturer PROTO C :VARARG
DEVPKEY_DeviceContainer_MetadataCabinet PROTO C :VARARG
DEVPKEY_DeviceContainer_MetadataChecksum PROTO C :VARARG
DEVPKEY_DeviceContainer_MetadataPath PROTO C :VARARG
DEVPKEY_DeviceContainer_ModelName PROTO C :VARARG
DEVPKEY_DeviceContainer_ModelNumber PROTO C :VARARG
DEVPKEY_DeviceContainer_PrimaryCategory PROTO C :VARARG
DEVPKEY_DeviceContainer_PrivilegedPackageFamilyNames PROTO C :VARARG
DEVPKEY_DeviceContainer_RequiresPairingElevation PROTO C :VARARG
DEVPKEY_DeviceContainer_RequiresUninstallElevation PROTO C :VARARG
DEVPKEY_DeviceContainer_UnpairUninstall PROTO C :VARARG
DEVPKEY_DeviceContainer_Version PROTO C :VARARG
DEVPKEY_DeviceInterfaceClass_DefaultInterface PROTO C :VARARG
DEVPKEY_DeviceInterfaceClass_Name PROTO C :VARARG
DEVPKEY_DeviceInterface_ClassGuid PROTO C :VARARG
DEVPKEY_DeviceInterface_Enabled PROTO C :VARARG
DEVPKEY_DeviceInterface_FriendlyName PROTO C :VARARG
DEVPKEY_DeviceInterface_ReferenceString PROTO C :VARARG
DEVPKEY_DeviceInterface_Restricted PROTO C :VARARG
DEVPKEY_Device_AdditionalSoftwareRequested PROTO C :VARARG
DEVPKEY_Device_Address PROTO C :VARARG
DEVPKEY_Device_BaseContainerId PROTO C :VARARG
DEVPKEY_Device_BiosDeviceName PROTO C :VARARG
DEVPKEY_Device_BusNumber PROTO C :VARARG
DEVPKEY_Device_BusRelations PROTO C :VARARG
DEVPKEY_Device_BusReportedDeviceDesc PROTO C :VARARG
DEVPKEY_Device_BusTypeGuid PROTO C :VARARG
DEVPKEY_Device_Capabilities PROTO C :VARARG
DEVPKEY_Device_Characteristics PROTO C :VARARG
DEVPKEY_Device_Children PROTO C :VARARG
DEVPKEY_Device_Class PROTO C :VARARG
DEVPKEY_Device_ClassGuid PROTO C :VARARG
DEVPKEY_Device_CompatibleIds PROTO C :VARARG
DEVPKEY_Device_ConfigFlags PROTO C :VARARG
DEVPKEY_Device_ConfigurationId PROTO C :VARARG
DEVPKEY_Device_ContainerId PROTO C :VARARG
DEVPKEY_Device_DHP_Rebalance_Policy PROTO C :VARARG
DEVPKEY_Device_DebuggerSafe PROTO C :VARARG
DEVPKEY_Device_DevNodeStatus PROTO C :VARARG
DEVPKEY_Device_DevType PROTO C :VARARG
DEVPKEY_Device_DeviceDesc PROTO C :VARARG
DEVPKEY_Device_Driver PROTO C :VARARG
DEVPKEY_Device_DriverCoInstallers PROTO C :VARARG
DEVPKEY_Device_DriverDate PROTO C :VARARG
DEVPKEY_Device_DriverDesc PROTO C :VARARG
DEVPKEY_Device_DriverInfPath PROTO C :VARARG
DEVPKEY_Device_DriverInfSection PROTO C :VARARG
DEVPKEY_Device_DriverInfSectionExt PROTO C :VARARG
DEVPKEY_Device_DriverLogoLevel PROTO C :VARARG
DEVPKEY_Device_DriverProblemDesc PROTO C :VARARG
DEVPKEY_Device_DriverPropPageProvider PROTO C :VARARG
DEVPKEY_Device_DriverProvider PROTO C :VARARG
DEVPKEY_Device_DriverRank PROTO C :VARARG
DEVPKEY_Device_DriverVersion PROTO C :VARARG
DEVPKEY_Device_EjectionRelations PROTO C :VARARG
DEVPKEY_Device_EnumeratorName PROTO C :VARARG
DEVPKEY_Device_Exclusive PROTO C :VARARG
DEVPKEY_Device_ExtendedConfigurationIds PROTO C :VARARG
DEVPKEY_Device_FirmwareDate PROTO C :VARARG
DEVPKEY_Device_FirmwareRevision PROTO C :VARARG
DEVPKEY_Device_FirmwareVersion PROTO C :VARARG
DEVPKEY_Device_FirstInstallDate PROTO C :VARARG
DEVPKEY_Device_FriendlyName PROTO C :VARARG
DEVPKEY_Device_FriendlyNameAttributes PROTO C :VARARG
DEVPKEY_Device_GenericDriverInstalled PROTO C :VARARG
DEVPKEY_Device_HardwareIds PROTO C :VARARG
DEVPKEY_Device_HasProblem PROTO C :VARARG
DEVPKEY_Device_InLocalMachineContainer PROTO C :VARARG
DEVPKEY_Device_InstallDate PROTO C :VARARG
DEVPKEY_Device_InstallState PROTO C :VARARG
DEVPKEY_Device_InstanceId PROTO C :VARARG
DEVPKEY_Device_IsAssociateableByUserAction PROTO C :VARARG
DEVPKEY_Device_IsPresent PROTO C :VARARG
DEVPKEY_Device_IsRebootRequired PROTO C :VARARG
DEVPKEY_Device_LastArrivalDate PROTO C :VARARG
DEVPKEY_Device_LastRemovalDate PROTO C :VARARG
DEVPKEY_Device_Legacy PROTO C :VARARG
DEVPKEY_Device_LegacyBusType PROTO C :VARARG
DEVPKEY_Device_LocationInfo PROTO C :VARARG
DEVPKEY_Device_LocationPaths PROTO C :VARARG
DEVPKEY_Device_LowerFilters PROTO C :VARARG
DEVPKEY_Device_Manufacturer PROTO C :VARARG
DEVPKEY_Device_ManufacturerAttributes PROTO C :VARARG
DEVPKEY_Device_MatchingDeviceId PROTO C :VARARG
DEVPKEY_Device_Model PROTO C :VARARG
DEVPKEY_Device_ModelId PROTO C :VARARG
DEVPKEY_Device_NoConnectSound PROTO C :VARARG
DEVPKEY_Device_Numa_Node PROTO C :VARARG
DEVPKEY_Device_Numa_Proximity_Domain PROTO C :VARARG
DEVPKEY_Device_PDOName PROTO C :VARARG
DEVPKEY_Device_Parent PROTO C :VARARG
DEVPKEY_Device_PhysicalDeviceLocation PROTO C :VARARG
DEVPKEY_Device_PostInstallInProgress PROTO C :VARARG
DEVPKEY_Device_PowerData PROTO C :VARARG
DEVPKEY_Device_PowerRelations PROTO C :VARARG
DEVPKEY_Device_PresenceNotForDevice PROTO C :VARARG
DEVPKEY_Device_ProblemCode PROTO C :VARARG
DEVPKEY_Device_ProblemStatus PROTO C :VARARG
DEVPKEY_Device_RemovalPolicy PROTO C :VARARG
DEVPKEY_Device_RemovalPolicyDefault PROTO C :VARARG
DEVPKEY_Device_RemovalPolicyOverride PROTO C :VARARG
DEVPKEY_Device_RemovalRelations PROTO C :VARARG
DEVPKEY_Device_Reported PROTO C :VARARG
DEVPKEY_Device_ReportedDeviceIdsHash PROTO C :VARARG
DEVPKEY_Device_ResourcePickerExceptions PROTO C :VARARG
DEVPKEY_Device_ResourcePickerTags PROTO C :VARARG
DEVPKEY_Device_SafeRemovalRequired PROTO C :VARARG
DEVPKEY_Device_SafeRemovalRequiredOverride PROTO C :VARARG
DEVPKEY_Device_Security PROTO C :VARARG
DEVPKEY_Device_SecuritySDS PROTO C :VARARG
DEVPKEY_Device_Service PROTO C :VARARG
DEVPKEY_Device_SessionId PROTO C :VARARG
DEVPKEY_Device_ShowInUninstallUI PROTO C :VARARG
DEVPKEY_Device_Siblings PROTO C :VARARG
DEVPKEY_Device_SignalStrength PROTO C :VARARG
DEVPKEY_Device_Stack PROTO C :VARARG
DEVPKEY_Device_TransportRelations PROTO C :VARARG
DEVPKEY_Device_UINumber PROTO C :VARARG
DEVPKEY_Device_UINumberDescFormat PROTO C :VARARG
DEVPKEY_Device_UpperFilters PROTO C :VARARG
DEVPKEY_DrvPkg_BrandingIcon PROTO C :VARARG
DEVPKEY_DrvPkg_DetailedDescription PROTO C :VARARG
DEVPKEY_DrvPkg_DocumentationLink PROTO C :VARARG
DEVPKEY_DrvPkg_Icon PROTO C :VARARG
DEVPKEY_DrvPkg_Model PROTO C :VARARG
DEVPKEY_DrvPkg_VendorWebSite PROTO C :VARARG
DEVPKEY_NAME PROTO C :VARARG
DebugMarkerSetObjectNameEXT PROTO :DWORD,:DWORD
DebugMarkerSetObjectTagEXT PROTO :DWORD,:DWORD
DestroyDescriptorUpdateTemplateKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
DestroyIndirectCommandsLayoutNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD
DestroyObjectTableNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD
DestroySamplerYcbcrConversionKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
DestroyValidationCacheEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
DisplayPowerControlEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetBufferMemoryRequirements2KHR PROTO :DWORD,:DWORD,:DWORD
GetDescriptorSetLayoutSupportKHR PROTO :DWORD,:DWORD,:DWORD
GetDeviceGroupPeerMemoryFeaturesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetFenceFdKHR PROTO :DWORD,:DWORD,:DWORD
GetFenceWin32HandleKHR PROTO :DWORD,:DWORD,:DWORD
GetImageMemoryRequirements2KHR PROTO :DWORD,:DWORD,:DWORD
GetImageSparseMemoryRequirements2KHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetMemoryFdKHR PROTO :DWORD,:DWORD,:DWORD
GetMemoryFdPropertiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetMemoryHostPointerPropertiesEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetMemoryWin32HandleKHR PROTO :DWORD,:DWORD,:DWORD
GetMemoryWin32HandleNV PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetMemoryWin32HandlePropertiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetPastPresentationTimingGOOGLE PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPhysicalDeviceExternalImageFormatPropertiesNV PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPhysicalDeviceGeneratedCommandsPropertiesNVX PROTO :DWORD,:DWORD,:DWORD
GetPhysicalDeviceMultisamplePropertiesEXT PROTO :DWORD,:DWORD,:DWORD
GetPhysicalDeviceSurfaceCapabilities2EXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetPhysicalDeviceSurfaceCapabilities2KHR PROTO :DWORD,:DWORD,:DWORD
GetPhysicalDeviceSurfaceFormats2KHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetRefreshCycleDurationGOOGLE PROTO :DWORD,:DWORD,:DWORD,:DWORD
GetSemaphoreFdKHR PROTO :DWORD,:DWORD,:DWORD
GetSemaphoreWin32HandleKHR PROTO :DWORD,:DWORD,:DWORD
GetShaderInfoAMD PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSwapchainCounterEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSwapchainStatusKHR PROTO :DWORD,:DWORD,:DWORD
GetValidationCacheDataEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ImportFenceFdKHR PROTO :DWORD,:DWORD
ImportFenceWin32HandleKHR PROTO :DWORD,:DWORD
ImportSemaphoreFdKHR PROTO :DWORD,:DWORD
ImportSemaphoreWin32HandleKHR PROTO :DWORD,:DWORD
LOADER_INSTANCE_EXTENSIONS PROTO C :VARARG
MergeValidationCachesEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueueBeginDebugUtilsLabelEXT PROTO :DWORD,:DWORD
QueueEndDebugUtilsLabelEXT PROTO :DWORD
QueueInsertDebugUtilsLabelEXT PROTO :DWORD,:DWORD
RegisterDeviceEventEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
RegisterDisplayEventEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegisterObjectsNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReleaseDisplayEXT PROTO :DWORD,:DWORD,:DWORD
SetDebugUtilsObjectNameEXT PROTO :DWORD,:DWORD
SetDebugUtilsObjectTagEXT PROTO :DWORD,:DWORD
SetHdrMetadataEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
TrimCommandPoolKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
UnregisterObjectsNVX PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
UpdateDescriptorSetWithTemplateKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
__local_stdio_printf_options PROTO C :VARARG
cJSON_AddItemReferenceToArray PROTO C :VARARG
cJSON_AddItemReferenceToObject PROTO C :VARARG
cJSON_AddItemToArray PROTO C :VARARG
cJSON_AddItemToObject PROTO C :VARARG
cJSON_AddItemToObjectCS PROTO C :VARARG
cJSON_CreateArray PROTO C :VARARG
cJSON_CreateBool PROTO C :VARARG
cJSON_CreateDoubleArray PROTO C :VARARG
cJSON_CreateFalse PROTO C :VARARG
cJSON_CreateFloatArray PROTO C :VARARG
cJSON_CreateIntArray PROTO C :VARARG
cJSON_CreateNull PROTO C :VARARG
cJSON_CreateNumber PROTO C :VARARG
cJSON_CreateObject PROTO C :VARARG
cJSON_CreateString PROTO C :VARARG
cJSON_CreateStringArray PROTO C :VARARG
cJSON_CreateTrue PROTO C :VARARG
cJSON_Delete PROTO C :VARARG
cJSON_DeleteItemFromArray PROTO C :VARARG
cJSON_DeleteItemFromObject PROTO C :VARARG
cJSON_DetachItemFromArray PROTO C :VARARG
cJSON_DetachItemFromObject PROTO C :VARARG
cJSON_Duplicate PROTO C :VARARG
cJSON_Free PROTO C :VARARG
cJSON_GetArrayItem PROTO C :VARARG
cJSON_GetArraySize PROTO C :VARARG
cJSON_GetErrorPtr PROTO C :VARARG
cJSON_GetObjectItem PROTO C :VARARG
cJSON_InitHooks PROTO C :VARARG
cJSON_InsertItemInArray PROTO C :VARARG
cJSON_Minify PROTO C :VARARG
cJSON_Parse PROTO C :VARARG
cJSON_ParseWithOpts PROTO C :VARARG
cJSON_Print PROTO C :VARARG
cJSON_PrintBuffered PROTO C :VARARG
cJSON_PrintUnformatted PROTO C :VARARG
cJSON_ReplaceItemInArray PROTO C :VARARG
cJSON_ReplaceItemInObject PROTO C :VARARG
closedir PROTO C :VARARG
compare_vk_extension_properties PROTO C :VARARG
debug_utils_AddInstanceExtensions PROTO C :VARARG
debug_utils_AnnotFlagsToReportFlags PROTO C :VARARG
debug_utils_AnnotObjectToDebugReportObject PROTO C :VARARG
debug_utils_CreateInstance PROTO C :VARARG
debug_utils_InstanceGpa PROTO C :VARARG
debug_utils_ReportFlagsToAnnotFlags PROTO C :VARARG
debug_utils_ReportObjectToAnnotObject PROTO C :VARARG
extension_instance_gpa PROTO C :VARARG
extensions_create_instance PROTO C :VARARG
g_loader_debug PROTO C :VARARG
g_loader_log_msgs PROTO C :VARARG
get_debug_report_enum PROTO C :VARARG
get_extension_device_proc_terminator PROTO C :VARARG
get_object_type_enum PROTO C :VARARG
has_layer_name PROTO C :VARARG
has_vk_dev_ext_property PROTO C :VARARG
has_vk_extension_property PROTO C :VARARG
has_vk_extension_property_array PROTO C :VARARG
has_vk_layer_property PROTO C :VARARG
instance_disp PROTO C :VARARG
loader PROTO C :VARARG
loaderGetDeviceRegistryEntry PROTO C :VARARG
loaderGetDeviceRegistryFiles PROTO C :VARARG
loaderGetRegistryFiles PROTO C :VARARG
loader_activate_instance_layer_extensions PROTO C :VARARG
loader_add_device_extensions PROTO C :VARARG
loader_add_logical_device PROTO C :VARARG
loader_add_meta_layer PROTO C :VARARG
loader_add_to_dev_ext_list PROTO C :VARARG
loader_add_to_ext_list PROTO C :VARARG
loader_add_to_layer_list PROTO C :VARARG
loader_copy_layer_properties PROTO C :VARARG
loader_create_device_chain PROTO C :VARARG
loader_create_instance_chain PROTO C :VARARG
loader_create_logical_device PROTO C :VARARG
loader_deactivate_layers PROTO C :VARARG
loader_delete_layer_properties PROTO C :VARARG
loader_destroy_generic_list PROTO C :VARARG
loader_destroy_icd_lib_list PROTO C :VARARG
loader_destroy_layer_list PROTO C :VARARG
loader_destroy_logical_device PROTO C :VARARG
loader_dev_ext_gpa PROTO C :VARARG
loader_device_heap_alloc PROTO C :VARARG
loader_device_heap_free PROTO C :VARARG
loader_device_heap_realloc PROTO C :VARARG
loader_enable_instance_layers PROTO C :VARARG
loader_find_layer_name_add_list PROTO C :VARARG
loader_find_layer_name_array PROTO C :VARARG
loader_get_dev_ext_trampoline PROTO C :VARARG
loader_get_icd_and_device PROTO C :VARARG
loader_get_icd_interface_version PROTO C :VARARG
loader_get_icd_loader_instance_extensions PROTO C :VARARG
loader_get_instance PROTO C :VARARG
loader_get_layer_interface_version PROTO C :VARARG
loader_get_phys_dev_ext_termin PROTO C :VARARG
loader_get_phys_dev_ext_tramp PROTO C :VARARG
loader_gpa_device_internal PROTO :DWORD,:DWORD
loader_icd_init_entries PROTO :DWORD,:DWORD,:DWORD
loader_icd_scan PROTO C :VARARG
loader_implicit_layer_scan PROTO C :VARARG
loader_init_device_dispatch_table PROTO :DWORD,:DWORD,:DWORD
loader_init_device_extension_dispatch_table PROTO :DWORD,:DWORD,:DWORD
loader_init_dispatch_dev_ext PROTO C :VARARG
loader_init_generic_list PROTO C :VARARG
loader_init_icd_lib_list PROTO C :VARARG
loader_init_instance_core_dispatch_table PROTO :DWORD,:DWORD,:DWORD
loader_init_instance_extension_dispatch_table PROTO :DWORD,:DWORD,:DWORD
loader_initialize PROTO C :VARARG
loader_instance_heap_alloc PROTO C :VARARG
loader_instance_heap_free PROTO C :VARARG
loader_instance_heap_realloc PROTO C :VARARG
loader_instance_tls_heap_alloc PROTO C :VARARG
loader_instance_tls_heap_free PROTO C :VARARG
loader_is_implicit_layer_enabled PROTO C :VARARG
loader_json_lock PROTO C :VARARG
loader_layer_scan PROTO C :VARARG
loader_lock PROTO C :VARARG
loader_log PROTO C :VARARG
loader_lookup_device_dispatch_table PROTO :DWORD,:DWORD
loader_lookup_instance_dispatch_table PROTO :DWORD,:DWORD,:DWORD
loader_major_version PROTO C :VARARG
loader_minor_version PROTO C :VARARG
loader_phys_dev_ext_gpa PROTO C :VARARG
loader_release PROTO C :VARARG
loader_remove_logical_device PROTO C :VARARG
loader_scanned_icd_clear PROTO C :VARARG
loader_validate_device_extensions PROTO C :VARARG
loader_validate_instance_extensions PROTO C :VARARG
loader_validate_layers PROTO C :VARARG
murmurhash PROTO C :VARARG
once_init PROTO C :VARARG
opendir PROTO C :VARARG
readdir PROTO C :VARARG
rewinddir PROTO C :VARARG
setupLoaderTermPhysDevGroups PROTO C :VARARG
setupLoaderTermPhysDevs PROTO C :VARARG
setupLoaderTrampPhysDevGroups PROTO C :VARARG
setupLoaderTrampPhysDevs PROTO C :VARARG
snprintf PROTO C :VARARG
sprintf PROTO C :VARARG
std_validation_str PROTO C :VARARG
terminator_CreateDebugReportCallbackEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateDebugUtilsMessengerEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateDevice PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateDisplayModeKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateDisplayPlaneSurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateInstance PROTO :DWORD,:DWORD,:DWORD
terminator_CreateSharedSwapchainsKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateSwapchainKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_CreateWin32SurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_DebugMarkerSetObjectNameEXT PROTO :DWORD,:DWORD
terminator_DebugMarkerSetObjectTagEXT PROTO :DWORD,:DWORD
terminator_DebugReportMessageEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_DestroyDebugReportCallbackEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_DestroyDebugUtilsMessengerEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_DestroyInstance PROTO :DWORD,:DWORD
terminator_DestroySurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_EnumerateDeviceExtensionProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_EnumerateDeviceLayerProperties PROTO :DWORD,:DWORD,:DWORD
terminator_EnumerateInstanceExtensionProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_EnumerateInstanceLayerProperties PROTO :DWORD,:DWORD,:DWORD
terminator_EnumerateInstanceVersion PROTO :DWORD,:DWORD
terminator_EnumeratePhysicalDeviceGroups PROTO :DWORD,:DWORD,:DWORD
terminator_EnumeratePhysicalDevices PROTO :DWORD,:DWORD,:DWORD
terminator_GetDeviceGroupSurfacePresentModesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetDisplayModePropertiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetDisplayPlaneCapabilitiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetDisplayPlaneSupportedDisplaysKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceDisplayPlanePropertiesKHR PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceDisplayPropertiesKHR PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceExternalBufferProperties PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceExternalFenceProperties PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceExternalImageFormatPropertiesNV PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceExternalSemaphoreProperties PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceFeatures2 PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceFeatures PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceFormatProperties2 PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceFormatProperties PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceGeneratedCommandsPropertiesNVX PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceImageFormatProperties2 PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceImageFormatProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceMemoryProperties2 PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceMemoryProperties PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceMultisamplePropertiesEXT PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDevicePresentRectanglesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceProperties2 PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceProperties PROTO :DWORD,:DWORD
terminator_GetPhysicalDeviceQueueFamilyProperties2 PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceQueueFamilyProperties PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSparseImageFormatProperties2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSparseImageFormatProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceCapabilities2EXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceCapabilities2KHR PROTO :DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceCapabilitiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceFormats2KHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceFormatsKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfacePresentModesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceSurfaceSupportKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
terminator_GetPhysicalDeviceWin32PresentationSupportKHR PROTO :DWORD,:DWORD
terminator_ReleaseDisplayEXT PROTO :DWORD,:DWORD,:DWORD
terminator_SetDebugUtilsObjectNameEXT PROTO :DWORD,:DWORD
terminator_SetDebugUtilsObjectTagEXT PROTO :DWORD,:DWORD
terminator_SubmitDebugUtilsMessageEXT PROTO :DWORD,:DWORD,:DWORD,:DWORD
tls_instance PROTO C :VARARG
util_CopyDebugReportCreateInfos PROTO C :VARARG
util_CopyDebugUtilsMessengerCreateInfos PROTO C :VARARG
util_CreateDebugReportCallback PROTO C :VARARG
util_CreateDebugReportCallbacks PROTO C :VARARG
util_CreateDebugUtilsMessenger PROTO C :VARARG
util_CreateDebugUtilsMessengers PROTO C :VARARG
util_DebugReportMessage PROTO C :VARARG
util_DestroyDebugReportCallback PROTO C :VARARG
util_DestroyDebugReportCallbacks PROTO C :VARARG
util_DestroyDebugUtilsMessenger PROTO C :VARARG
util_DestroyDebugUtilsMessengers PROTO C :VARARG
util_FreeDebugReportCreateInfos PROTO C :VARARG
util_FreeDebugUtilsMessengerCreateInfos PROTO C :VARARG
util_SubmitDebugUtilsMessageEXT PROTO C :VARARG



;---------------------------------
; Vulkan Commands (Prototypes)
; https://vulkan.lunarg.com/doc/view/1.1.70.0/windows/apispec.html#protos
;---------------------------------
vkAcquireNextImage2KHR PROTO :DWORD,:DWORD,:DWORD
vkAcquireNextImageKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkAllocateCommandBuffers PROTO :DWORD,:DWORD,:DWORD
vkAllocateDescriptorSets PROTO :DWORD,:DWORD,:DWORD
vkAllocateMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkBeginCommandBuffer PROTO :DWORD,:DWORD
vkBindBufferMemory2 PROTO :DWORD,:DWORD,:DWORD
vkBindBufferMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkBindImageMemory2 PROTO :DWORD,:DWORD,:DWORD
vkBindImageMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdBeginQuery PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdBeginRenderPass PROTO :DWORD,:DWORD,:DWORD
vkCmdBindDescriptorSets PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdBindIndexBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdBindPipeline PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdBindVertexBuffers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdBlitImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdClearAttachments PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdClearColorImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdClearDepthStencilImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdCopyBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdCopyBufferToImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdCopyImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdCopyImageToBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdCopyQueryPoolResults PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDispatch PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdDispatchBase PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDispatchIndirect PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDraw PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDrawIndexed PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDrawIndexedIndirect PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdDrawIndirect PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdEndQuery PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdEndRenderPass PROTO :DWORD
vkCmdExecuteCommands PROTO :DWORD,:DWORD,:DWORD
vkCmdFillBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdNextSubpass PROTO :DWORD,:DWORD
vkCmdPipelineBarrier PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdPushConstants PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdResetEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdResetQueryPool PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdResolveImage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdSetBlendConstants PROTO :DWORD,:DWORD
vkCmdSetDepthBias PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdSetDepthBounds PROTO :DWORD,:DWORD,:DWORD
vkCmdSetDeviceMask PROTO :DWORD,:DWORD
vkCmdSetEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdSetLineWidth PROTO :DWORD,:DWORD
vkCmdSetScissor PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdSetStencilCompareMask PROTO :DWORD,:DWORD,:DWORD
vkCmdSetStencilReference PROTO :DWORD,:DWORD,:DWORD
vkCmdSetStencilWriteMask PROTO :DWORD,:DWORD,:DWORD
vkCmdSetViewport PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCmdUpdateBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdWaitEvents PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCmdWriteTimestamp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCreateBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateBufferView PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateCommandPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateComputePipelines PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCreateDescriptorPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateDescriptorSetLayout PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateDevice PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateDisplayModeKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCreateDisplayPlaneSurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateFence PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateFramebuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateGraphicsPipelines PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCreateImage PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateImageView PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateInstance PROTO :DWORD,:DWORD,:DWORD
vkCreatePipelineCache PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreatePipelineLayout PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateQueryPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateRenderPass PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateSampler PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateSamplerYcbcrConversion PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateSemaphore PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateShaderModule PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateSharedSwapchainsKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkCreateSwapchainKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkCreateWin32SurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyBuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyBufferView PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyCommandPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyDescriptorPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyDescriptorSetLayout PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyDevice PROTO :DWORD,:DWORD
vkDestroyEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyFence PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyFramebuffer PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyImage PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyImageView PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyInstance PROTO :DWORD,:DWORD
vkDestroyPipeline PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyPipelineCache PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyPipelineLayout PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyQueryPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyRenderPass PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroySampler PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroySamplerYcbcrConversion PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroySemaphore PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroyShaderModule PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroySurfaceKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDestroySwapchainKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkDevExtError PROTO :DWORD
vkDeviceWaitIdle PROTO :DWORD
vkEndCommandBuffer PROTO :DWORD
vkEnumerateDeviceExtensionProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkEnumerateDeviceLayerProperties PROTO :DWORD,:DWORD,:DWORD
vkEnumerateInstanceExtensionProperties PROTO :DWORD,:DWORD,:DWORD
vkEnumerateInstanceLayerProperties PROTO :DWORD,:DWORD
vkEnumerateInstanceVersion PROTO :DWORD
vkEnumeratePhysicalDeviceGroups PROTO :DWORD,:DWORD,:DWORD
vkEnumeratePhysicalDevices PROTO :DWORD,:DWORD,:DWORD
vkFlushMappedMemoryRanges PROTO :DWORD,:DWORD,:DWORD
vkFreeCommandBuffers PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkFreeDescriptorSets PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkFreeMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetBufferMemoryRequirements2 PROTO :DWORD,:DWORD,:DWORD
vkGetBufferMemoryRequirements PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetDescriptorSetLayoutSupport PROTO :DWORD,:DWORD,:DWORD
vkGetDeviceGroupPeerMemoryFeatures PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetDeviceGroupPresentCapabilitiesKHR PROTO :DWORD,:DWORD
vkGetDeviceGroupSurfacePresentModesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetDeviceMemoryCommitment PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetDeviceProcAddr PROTO :DWORD,:DWORD
vkGetDeviceQueue2 PROTO :DWORD,:DWORD,:DWORD
vkGetDeviceQueue PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetDisplayModePropertiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetDisplayPlaneCapabilitiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetDisplayPlaneSupportedDisplaysKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetEventStatus PROTO :DWORD,:DWORD,:DWORD
vkGetFenceStatus PROTO :DWORD,:DWORD,:DWORD
vkGetImageMemoryRequirements2 PROTO :DWORD,:DWORD,:DWORD
vkGetImageMemoryRequirements PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetImageSparseMemoryRequirements2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetImageSparseMemoryRequirements PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetImageSubresourceLayout PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetInstanceProcAddr PROTO :DWORD,:DWORD
vkGetPhysicalDeviceDisplayPlanePropertiesKHR PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceDisplayPropertiesKHR PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceExternalBufferProperties PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceExternalFenceProperties PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceExternalSemaphoreProperties PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceFeatures2 PROTO :DWORD,:DWORD
vkGetPhysicalDeviceFeatures PROTO :DWORD,:DWORD
vkGetPhysicalDeviceFormatProperties2 PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceFormatProperties PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceImageFormatProperties2 PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceImageFormatProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceMemoryProperties2 PROTO :DWORD,:DWORD
vkGetPhysicalDeviceMemoryProperties PROTO :DWORD,:DWORD
vkGetPhysicalDevicePresentRectanglesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceProperties2 PROTO :DWORD,:DWORD
vkGetPhysicalDeviceProperties PROTO :DWORD,:DWORD
vkGetPhysicalDeviceQueueFamilyProperties2 PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceQueueFamilyProperties PROTO :DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSparseImageFormatProperties2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSparseImageFormatProperties PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSurfaceCapabilitiesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSurfaceFormatsKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSurfacePresentModesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceSurfaceSupportKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetPhysicalDeviceWin32PresentationSupportKHR PROTO :DWORD,:DWORD
vkGetPipelineCacheData PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetQueryPoolResults PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkGetRenderAreaGranularity PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkGetSwapchainImagesKHR PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkInvalidateMappedMemoryRanges PROTO :DWORD,:DWORD,:DWORD
vkMapMemory PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkMergePipelineCaches PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkPhysDevExtTermin0 PROTO :DWORD
vkPhysDevExtTermin100 PROTO :DWORD
vkPhysDevExtTermin101 PROTO :DWORD
vkPhysDevExtTermin102 PROTO :DWORD
vkPhysDevExtTermin103 PROTO :DWORD
vkPhysDevExtTermin104 PROTO :DWORD
vkPhysDevExtTermin105 PROTO :DWORD
vkPhysDevExtTermin106 PROTO :DWORD
vkPhysDevExtTermin107 PROTO :DWORD
vkPhysDevExtTermin108 PROTO :DWORD
vkPhysDevExtTermin109 PROTO :DWORD
vkPhysDevExtTermin10 PROTO :DWORD
vkPhysDevExtTermin110 PROTO :DWORD
vkPhysDevExtTermin111 PROTO :DWORD
vkPhysDevExtTermin112 PROTO :DWORD
vkPhysDevExtTermin113 PROTO :DWORD
vkPhysDevExtTermin114 PROTO :DWORD
vkPhysDevExtTermin115 PROTO :DWORD
vkPhysDevExtTermin116 PROTO :DWORD
vkPhysDevExtTermin117 PROTO :DWORD
vkPhysDevExtTermin118 PROTO :DWORD
vkPhysDevExtTermin119 PROTO :DWORD
vkPhysDevExtTermin11 PROTO :DWORD
vkPhysDevExtTermin120 PROTO :DWORD
vkPhysDevExtTermin121 PROTO :DWORD
vkPhysDevExtTermin122 PROTO :DWORD
vkPhysDevExtTermin123 PROTO :DWORD
vkPhysDevExtTermin124 PROTO :DWORD
vkPhysDevExtTermin125 PROTO :DWORD
vkPhysDevExtTermin126 PROTO :DWORD
vkPhysDevExtTermin127 PROTO :DWORD
vkPhysDevExtTermin128 PROTO :DWORD
vkPhysDevExtTermin129 PROTO :DWORD
vkPhysDevExtTermin12 PROTO :DWORD
vkPhysDevExtTermin130 PROTO :DWORD
vkPhysDevExtTermin131 PROTO :DWORD
vkPhysDevExtTermin132 PROTO :DWORD
vkPhysDevExtTermin133 PROTO :DWORD
vkPhysDevExtTermin134 PROTO :DWORD
vkPhysDevExtTermin135 PROTO :DWORD
vkPhysDevExtTermin136 PROTO :DWORD
vkPhysDevExtTermin137 PROTO :DWORD
vkPhysDevExtTermin138 PROTO :DWORD
vkPhysDevExtTermin139 PROTO :DWORD
vkPhysDevExtTermin13 PROTO :DWORD
vkPhysDevExtTermin140 PROTO :DWORD
vkPhysDevExtTermin141 PROTO :DWORD
vkPhysDevExtTermin142 PROTO :DWORD
vkPhysDevExtTermin143 PROTO :DWORD
vkPhysDevExtTermin144 PROTO :DWORD
vkPhysDevExtTermin145 PROTO :DWORD
vkPhysDevExtTermin146 PROTO :DWORD
vkPhysDevExtTermin147 PROTO :DWORD
vkPhysDevExtTermin148 PROTO :DWORD
vkPhysDevExtTermin149 PROTO :DWORD
vkPhysDevExtTermin14 PROTO :DWORD
vkPhysDevExtTermin150 PROTO :DWORD
vkPhysDevExtTermin151 PROTO :DWORD
vkPhysDevExtTermin152 PROTO :DWORD
vkPhysDevExtTermin153 PROTO :DWORD
vkPhysDevExtTermin154 PROTO :DWORD
vkPhysDevExtTermin155 PROTO :DWORD
vkPhysDevExtTermin156 PROTO :DWORD
vkPhysDevExtTermin157 PROTO :DWORD
vkPhysDevExtTermin158 PROTO :DWORD
vkPhysDevExtTermin159 PROTO :DWORD
vkPhysDevExtTermin15 PROTO :DWORD
vkPhysDevExtTermin160 PROTO :DWORD
vkPhysDevExtTermin161 PROTO :DWORD
vkPhysDevExtTermin162 PROTO :DWORD
vkPhysDevExtTermin163 PROTO :DWORD
vkPhysDevExtTermin164 PROTO :DWORD
vkPhysDevExtTermin165 PROTO :DWORD
vkPhysDevExtTermin166 PROTO :DWORD
vkPhysDevExtTermin167 PROTO :DWORD
vkPhysDevExtTermin168 PROTO :DWORD
vkPhysDevExtTermin169 PROTO :DWORD
vkPhysDevExtTermin16 PROTO :DWORD
vkPhysDevExtTermin170 PROTO :DWORD
vkPhysDevExtTermin171 PROTO :DWORD
vkPhysDevExtTermin172 PROTO :DWORD
vkPhysDevExtTermin173 PROTO :DWORD
vkPhysDevExtTermin174 PROTO :DWORD
vkPhysDevExtTermin175 PROTO :DWORD
vkPhysDevExtTermin176 PROTO :DWORD
vkPhysDevExtTermin177 PROTO :DWORD
vkPhysDevExtTermin178 PROTO :DWORD
vkPhysDevExtTermin179 PROTO :DWORD
vkPhysDevExtTermin17 PROTO :DWORD
vkPhysDevExtTermin180 PROTO :DWORD
vkPhysDevExtTermin181 PROTO :DWORD
vkPhysDevExtTermin182 PROTO :DWORD
vkPhysDevExtTermin183 PROTO :DWORD
vkPhysDevExtTermin184 PROTO :DWORD
vkPhysDevExtTermin185 PROTO :DWORD
vkPhysDevExtTermin186 PROTO :DWORD
vkPhysDevExtTermin187 PROTO :DWORD
vkPhysDevExtTermin188 PROTO :DWORD
vkPhysDevExtTermin189 PROTO :DWORD
vkPhysDevExtTermin18 PROTO :DWORD
vkPhysDevExtTermin190 PROTO :DWORD
vkPhysDevExtTermin191 PROTO :DWORD
vkPhysDevExtTermin192 PROTO :DWORD
vkPhysDevExtTermin193 PROTO :DWORD
vkPhysDevExtTermin194 PROTO :DWORD
vkPhysDevExtTermin195 PROTO :DWORD
vkPhysDevExtTermin196 PROTO :DWORD
vkPhysDevExtTermin197 PROTO :DWORD
vkPhysDevExtTermin198 PROTO :DWORD
vkPhysDevExtTermin199 PROTO :DWORD
vkPhysDevExtTermin19 PROTO :DWORD
vkPhysDevExtTermin1 PROTO :DWORD
vkPhysDevExtTermin200 PROTO :DWORD
vkPhysDevExtTermin201 PROTO :DWORD
vkPhysDevExtTermin202 PROTO :DWORD
vkPhysDevExtTermin203 PROTO :DWORD
vkPhysDevExtTermin204 PROTO :DWORD
vkPhysDevExtTermin205 PROTO :DWORD
vkPhysDevExtTermin206 PROTO :DWORD
vkPhysDevExtTermin207 PROTO :DWORD
vkPhysDevExtTermin208 PROTO :DWORD
vkPhysDevExtTermin209 PROTO :DWORD
vkPhysDevExtTermin20 PROTO :DWORD
vkPhysDevExtTermin210 PROTO :DWORD
vkPhysDevExtTermin211 PROTO :DWORD
vkPhysDevExtTermin212 PROTO :DWORD
vkPhysDevExtTermin213 PROTO :DWORD
vkPhysDevExtTermin214 PROTO :DWORD
vkPhysDevExtTermin215 PROTO :DWORD
vkPhysDevExtTermin216 PROTO :DWORD
vkPhysDevExtTermin217 PROTO :DWORD
vkPhysDevExtTermin218 PROTO :DWORD
vkPhysDevExtTermin219 PROTO :DWORD
vkPhysDevExtTermin21 PROTO :DWORD
vkPhysDevExtTermin220 PROTO :DWORD
vkPhysDevExtTermin221 PROTO :DWORD
vkPhysDevExtTermin222 PROTO :DWORD
vkPhysDevExtTermin223 PROTO :DWORD
vkPhysDevExtTermin224 PROTO :DWORD
vkPhysDevExtTermin225 PROTO :DWORD
vkPhysDevExtTermin226 PROTO :DWORD
vkPhysDevExtTermin227 PROTO :DWORD
vkPhysDevExtTermin228 PROTO :DWORD
vkPhysDevExtTermin229 PROTO :DWORD
vkPhysDevExtTermin22 PROTO :DWORD
vkPhysDevExtTermin230 PROTO :DWORD
vkPhysDevExtTermin231 PROTO :DWORD
vkPhysDevExtTermin232 PROTO :DWORD
vkPhysDevExtTermin233 PROTO :DWORD
vkPhysDevExtTermin234 PROTO :DWORD
vkPhysDevExtTermin235 PROTO :DWORD
vkPhysDevExtTermin236 PROTO :DWORD
vkPhysDevExtTermin237 PROTO :DWORD
vkPhysDevExtTermin238 PROTO :DWORD
vkPhysDevExtTermin239 PROTO :DWORD
vkPhysDevExtTermin23 PROTO :DWORD
vkPhysDevExtTermin240 PROTO :DWORD
vkPhysDevExtTermin241 PROTO :DWORD
vkPhysDevExtTermin242 PROTO :DWORD
vkPhysDevExtTermin243 PROTO :DWORD
vkPhysDevExtTermin244 PROTO :DWORD
vkPhysDevExtTermin245 PROTO :DWORD
vkPhysDevExtTermin246 PROTO :DWORD
vkPhysDevExtTermin247 PROTO :DWORD
vkPhysDevExtTermin248 PROTO :DWORD
vkPhysDevExtTermin249 PROTO :DWORD
vkPhysDevExtTermin24 PROTO :DWORD
vkPhysDevExtTermin25 PROTO :DWORD
vkPhysDevExtTermin26 PROTO :DWORD
vkPhysDevExtTermin27 PROTO :DWORD
vkPhysDevExtTermin28 PROTO :DWORD
vkPhysDevExtTermin29 PROTO :DWORD
vkPhysDevExtTermin2 PROTO :DWORD
vkPhysDevExtTermin30 PROTO :DWORD
vkPhysDevExtTermin31 PROTO :DWORD
vkPhysDevExtTermin32 PROTO :DWORD
vkPhysDevExtTermin33 PROTO :DWORD
vkPhysDevExtTermin34 PROTO :DWORD
vkPhysDevExtTermin35 PROTO :DWORD
vkPhysDevExtTermin36 PROTO :DWORD
vkPhysDevExtTermin37 PROTO :DWORD
vkPhysDevExtTermin38 PROTO :DWORD
vkPhysDevExtTermin39 PROTO :DWORD
vkPhysDevExtTermin3 PROTO :DWORD
vkPhysDevExtTermin40 PROTO :DWORD
vkPhysDevExtTermin41 PROTO :DWORD
vkPhysDevExtTermin42 PROTO :DWORD
vkPhysDevExtTermin43 PROTO :DWORD
vkPhysDevExtTermin44 PROTO :DWORD
vkPhysDevExtTermin45 PROTO :DWORD
vkPhysDevExtTermin46 PROTO :DWORD
vkPhysDevExtTermin47 PROTO :DWORD
vkPhysDevExtTermin48 PROTO :DWORD
vkPhysDevExtTermin49 PROTO :DWORD
vkPhysDevExtTermin4 PROTO :DWORD
vkPhysDevExtTermin50 PROTO :DWORD
vkPhysDevExtTermin51 PROTO :DWORD
vkPhysDevExtTermin52 PROTO :DWORD
vkPhysDevExtTermin53 PROTO :DWORD
vkPhysDevExtTermin54 PROTO :DWORD
vkPhysDevExtTermin55 PROTO :DWORD
vkPhysDevExtTermin56 PROTO :DWORD
vkPhysDevExtTermin57 PROTO :DWORD
vkPhysDevExtTermin58 PROTO :DWORD
vkPhysDevExtTermin59 PROTO :DWORD
vkPhysDevExtTermin5 PROTO :DWORD
vkPhysDevExtTermin60 PROTO :DWORD
vkPhysDevExtTermin61 PROTO :DWORD
vkPhysDevExtTermin62 PROTO :DWORD
vkPhysDevExtTermin63 PROTO :DWORD
vkPhysDevExtTermin64 PROTO :DWORD
vkPhysDevExtTermin65 PROTO :DWORD
vkPhysDevExtTermin66 PROTO :DWORD
vkPhysDevExtTermin67 PROTO :DWORD
vkPhysDevExtTermin68 PROTO :DWORD
vkPhysDevExtTermin69 PROTO :DWORD
vkPhysDevExtTermin6 PROTO :DWORD
vkPhysDevExtTermin70 PROTO :DWORD
vkPhysDevExtTermin71 PROTO :DWORD
vkPhysDevExtTermin72 PROTO :DWORD
vkPhysDevExtTermin73 PROTO :DWORD
vkPhysDevExtTermin74 PROTO :DWORD
vkPhysDevExtTermin75 PROTO :DWORD
vkPhysDevExtTermin76 PROTO :DWORD
vkPhysDevExtTermin77 PROTO :DWORD
vkPhysDevExtTermin78 PROTO :DWORD
vkPhysDevExtTermin79 PROTO :DWORD
vkPhysDevExtTermin7 PROTO :DWORD
vkPhysDevExtTermin80 PROTO :DWORD
vkPhysDevExtTermin81 PROTO :DWORD
vkPhysDevExtTermin82 PROTO :DWORD
vkPhysDevExtTermin83 PROTO :DWORD
vkPhysDevExtTermin84 PROTO :DWORD
vkPhysDevExtTermin85 PROTO :DWORD
vkPhysDevExtTermin86 PROTO :DWORD
vkPhysDevExtTermin87 PROTO :DWORD
vkPhysDevExtTermin88 PROTO :DWORD
vkPhysDevExtTermin89 PROTO :DWORD
vkPhysDevExtTermin8 PROTO :DWORD
vkPhysDevExtTermin90 PROTO :DWORD
vkPhysDevExtTermin91 PROTO :DWORD
vkPhysDevExtTermin92 PROTO :DWORD
vkPhysDevExtTermin93 PROTO :DWORD
vkPhysDevExtTermin94 PROTO :DWORD
vkPhysDevExtTermin95 PROTO :DWORD
vkPhysDevExtTermin96 PROTO :DWORD
vkPhysDevExtTermin97 PROTO :DWORD
vkPhysDevExtTermin98 PROTO :DWORD
vkPhysDevExtTermin99 PROTO :DWORD
vkPhysDevExtTermin9 PROTO :DWORD
vkPhysDevExtTramp0 PROTO :DWORD
vkPhysDevExtTramp100 PROTO :DWORD
vkPhysDevExtTramp101 PROTO :DWORD
vkPhysDevExtTramp102 PROTO :DWORD
vkPhysDevExtTramp103 PROTO :DWORD
vkPhysDevExtTramp104 PROTO :DWORD
vkPhysDevExtTramp105 PROTO :DWORD
vkPhysDevExtTramp106 PROTO :DWORD
vkPhysDevExtTramp107 PROTO :DWORD
vkPhysDevExtTramp108 PROTO :DWORD
vkPhysDevExtTramp109 PROTO :DWORD
vkPhysDevExtTramp10 PROTO :DWORD
vkPhysDevExtTramp110 PROTO :DWORD
vkPhysDevExtTramp111 PROTO :DWORD
vkPhysDevExtTramp112 PROTO :DWORD
vkPhysDevExtTramp113 PROTO :DWORD
vkPhysDevExtTramp114 PROTO :DWORD
vkPhysDevExtTramp115 PROTO :DWORD
vkPhysDevExtTramp116 PROTO :DWORD
vkPhysDevExtTramp117 PROTO :DWORD
vkPhysDevExtTramp118 PROTO :DWORD
vkPhysDevExtTramp119 PROTO :DWORD
vkPhysDevExtTramp11 PROTO :DWORD
vkPhysDevExtTramp120 PROTO :DWORD
vkPhysDevExtTramp121 PROTO :DWORD
vkPhysDevExtTramp122 PROTO :DWORD
vkPhysDevExtTramp123 PROTO :DWORD
vkPhysDevExtTramp124 PROTO :DWORD
vkPhysDevExtTramp125 PROTO :DWORD
vkPhysDevExtTramp126 PROTO :DWORD
vkPhysDevExtTramp127 PROTO :DWORD
vkPhysDevExtTramp128 PROTO :DWORD
vkPhysDevExtTramp129 PROTO :DWORD
vkPhysDevExtTramp12 PROTO :DWORD
vkPhysDevExtTramp130 PROTO :DWORD
vkPhysDevExtTramp131 PROTO :DWORD
vkPhysDevExtTramp132 PROTO :DWORD
vkPhysDevExtTramp133 PROTO :DWORD
vkPhysDevExtTramp134 PROTO :DWORD
vkPhysDevExtTramp135 PROTO :DWORD
vkPhysDevExtTramp136 PROTO :DWORD
vkPhysDevExtTramp137 PROTO :DWORD
vkPhysDevExtTramp138 PROTO :DWORD
vkPhysDevExtTramp139 PROTO :DWORD
vkPhysDevExtTramp13 PROTO :DWORD
vkPhysDevExtTramp140 PROTO :DWORD
vkPhysDevExtTramp141 PROTO :DWORD
vkPhysDevExtTramp142 PROTO :DWORD
vkPhysDevExtTramp143 PROTO :DWORD
vkPhysDevExtTramp144 PROTO :DWORD
vkPhysDevExtTramp145 PROTO :DWORD
vkPhysDevExtTramp146 PROTO :DWORD
vkPhysDevExtTramp147 PROTO :DWORD
vkPhysDevExtTramp148 PROTO :DWORD
vkPhysDevExtTramp149 PROTO :DWORD
vkPhysDevExtTramp14 PROTO :DWORD
vkPhysDevExtTramp150 PROTO :DWORD
vkPhysDevExtTramp151 PROTO :DWORD
vkPhysDevExtTramp152 PROTO :DWORD
vkPhysDevExtTramp153 PROTO :DWORD
vkPhysDevExtTramp154 PROTO :DWORD
vkPhysDevExtTramp155 PROTO :DWORD
vkPhysDevExtTramp156 PROTO :DWORD
vkPhysDevExtTramp157 PROTO :DWORD
vkPhysDevExtTramp158 PROTO :DWORD
vkPhysDevExtTramp159 PROTO :DWORD
vkPhysDevExtTramp15 PROTO :DWORD
vkPhysDevExtTramp160 PROTO :DWORD
vkPhysDevExtTramp161 PROTO :DWORD
vkPhysDevExtTramp162 PROTO :DWORD
vkPhysDevExtTramp163 PROTO :DWORD
vkPhysDevExtTramp164 PROTO :DWORD
vkPhysDevExtTramp165 PROTO :DWORD
vkPhysDevExtTramp166 PROTO :DWORD
vkPhysDevExtTramp167 PROTO :DWORD
vkPhysDevExtTramp168 PROTO :DWORD
vkPhysDevExtTramp169 PROTO :DWORD
vkPhysDevExtTramp16 PROTO :DWORD
vkPhysDevExtTramp170 PROTO :DWORD
vkPhysDevExtTramp171 PROTO :DWORD
vkPhysDevExtTramp172 PROTO :DWORD
vkPhysDevExtTramp173 PROTO :DWORD
vkPhysDevExtTramp174 PROTO :DWORD
vkPhysDevExtTramp175 PROTO :DWORD
vkPhysDevExtTramp176 PROTO :DWORD
vkPhysDevExtTramp177 PROTO :DWORD
vkPhysDevExtTramp178 PROTO :DWORD
vkPhysDevExtTramp179 PROTO :DWORD
vkPhysDevExtTramp17 PROTO :DWORD
vkPhysDevExtTramp180 PROTO :DWORD
vkPhysDevExtTramp181 PROTO :DWORD
vkPhysDevExtTramp182 PROTO :DWORD
vkPhysDevExtTramp183 PROTO :DWORD
vkPhysDevExtTramp184 PROTO :DWORD
vkPhysDevExtTramp185 PROTO :DWORD
vkPhysDevExtTramp186 PROTO :DWORD
vkPhysDevExtTramp187 PROTO :DWORD
vkPhysDevExtTramp188 PROTO :DWORD
vkPhysDevExtTramp189 PROTO :DWORD
vkPhysDevExtTramp18 PROTO :DWORD
vkPhysDevExtTramp190 PROTO :DWORD
vkPhysDevExtTramp191 PROTO :DWORD
vkPhysDevExtTramp192 PROTO :DWORD
vkPhysDevExtTramp193 PROTO :DWORD
vkPhysDevExtTramp194 PROTO :DWORD
vkPhysDevExtTramp195 PROTO :DWORD
vkPhysDevExtTramp196 PROTO :DWORD
vkPhysDevExtTramp197 PROTO :DWORD
vkPhysDevExtTramp198 PROTO :DWORD
vkPhysDevExtTramp199 PROTO :DWORD
vkPhysDevExtTramp19 PROTO :DWORD
vkPhysDevExtTramp1 PROTO :DWORD
vkPhysDevExtTramp200 PROTO :DWORD
vkPhysDevExtTramp201 PROTO :DWORD
vkPhysDevExtTramp202 PROTO :DWORD
vkPhysDevExtTramp203 PROTO :DWORD
vkPhysDevExtTramp204 PROTO :DWORD
vkPhysDevExtTramp205 PROTO :DWORD
vkPhysDevExtTramp206 PROTO :DWORD
vkPhysDevExtTramp207 PROTO :DWORD
vkPhysDevExtTramp208 PROTO :DWORD
vkPhysDevExtTramp209 PROTO :DWORD
vkPhysDevExtTramp20 PROTO :DWORD
vkPhysDevExtTramp210 PROTO :DWORD
vkPhysDevExtTramp211 PROTO :DWORD
vkPhysDevExtTramp212 PROTO :DWORD
vkPhysDevExtTramp213 PROTO :DWORD
vkPhysDevExtTramp214 PROTO :DWORD
vkPhysDevExtTramp215 PROTO :DWORD
vkPhysDevExtTramp216 PROTO :DWORD
vkPhysDevExtTramp217 PROTO :DWORD
vkPhysDevExtTramp218 PROTO :DWORD
vkPhysDevExtTramp219 PROTO :DWORD
vkPhysDevExtTramp21 PROTO :DWORD
vkPhysDevExtTramp220 PROTO :DWORD
vkPhysDevExtTramp221 PROTO :DWORD
vkPhysDevExtTramp222 PROTO :DWORD
vkPhysDevExtTramp223 PROTO :DWORD
vkPhysDevExtTramp224 PROTO :DWORD
vkPhysDevExtTramp225 PROTO :DWORD
vkPhysDevExtTramp226 PROTO :DWORD
vkPhysDevExtTramp227 PROTO :DWORD
vkPhysDevExtTramp228 PROTO :DWORD
vkPhysDevExtTramp229 PROTO :DWORD
vkPhysDevExtTramp22 PROTO :DWORD
vkPhysDevExtTramp230 PROTO :DWORD
vkPhysDevExtTramp231 PROTO :DWORD
vkPhysDevExtTramp232 PROTO :DWORD
vkPhysDevExtTramp233 PROTO :DWORD
vkPhysDevExtTramp234 PROTO :DWORD
vkPhysDevExtTramp235 PROTO :DWORD
vkPhysDevExtTramp236 PROTO :DWORD
vkPhysDevExtTramp237 PROTO :DWORD
vkPhysDevExtTramp238 PROTO :DWORD
vkPhysDevExtTramp239 PROTO :DWORD
vkPhysDevExtTramp23 PROTO :DWORD
vkPhysDevExtTramp240 PROTO :DWORD
vkPhysDevExtTramp241 PROTO :DWORD
vkPhysDevExtTramp242 PROTO :DWORD
vkPhysDevExtTramp243 PROTO :DWORD
vkPhysDevExtTramp244 PROTO :DWORD
vkPhysDevExtTramp245 PROTO :DWORD
vkPhysDevExtTramp246 PROTO :DWORD
vkPhysDevExtTramp247 PROTO :DWORD
vkPhysDevExtTramp248 PROTO :DWORD
vkPhysDevExtTramp249 PROTO :DWORD
vkPhysDevExtTramp24 PROTO :DWORD
vkPhysDevExtTramp25 PROTO :DWORD
vkPhysDevExtTramp26 PROTO :DWORD
vkPhysDevExtTramp27 PROTO :DWORD
vkPhysDevExtTramp28 PROTO :DWORD
vkPhysDevExtTramp29 PROTO :DWORD
vkPhysDevExtTramp2 PROTO :DWORD
vkPhysDevExtTramp30 PROTO :DWORD
vkPhysDevExtTramp31 PROTO :DWORD
vkPhysDevExtTramp32 PROTO :DWORD
vkPhysDevExtTramp33 PROTO :DWORD
vkPhysDevExtTramp34 PROTO :DWORD
vkPhysDevExtTramp35 PROTO :DWORD
vkPhysDevExtTramp36 PROTO :DWORD
vkPhysDevExtTramp37 PROTO :DWORD
vkPhysDevExtTramp38 PROTO :DWORD
vkPhysDevExtTramp39 PROTO :DWORD
vkPhysDevExtTramp3 PROTO :DWORD
vkPhysDevExtTramp40 PROTO :DWORD
vkPhysDevExtTramp41 PROTO :DWORD
vkPhysDevExtTramp42 PROTO :DWORD
vkPhysDevExtTramp43 PROTO :DWORD
vkPhysDevExtTramp44 PROTO :DWORD
vkPhysDevExtTramp45 PROTO :DWORD
vkPhysDevExtTramp46 PROTO :DWORD
vkPhysDevExtTramp47 PROTO :DWORD
vkPhysDevExtTramp48 PROTO :DWORD
vkPhysDevExtTramp49 PROTO :DWORD
vkPhysDevExtTramp4 PROTO :DWORD
vkPhysDevExtTramp50 PROTO :DWORD
vkPhysDevExtTramp51 PROTO :DWORD
vkPhysDevExtTramp52 PROTO :DWORD
vkPhysDevExtTramp53 PROTO :DWORD
vkPhysDevExtTramp54 PROTO :DWORD
vkPhysDevExtTramp55 PROTO :DWORD
vkPhysDevExtTramp56 PROTO :DWORD
vkPhysDevExtTramp57 PROTO :DWORD
vkPhysDevExtTramp58 PROTO :DWORD
vkPhysDevExtTramp59 PROTO :DWORD
vkPhysDevExtTramp5 PROTO :DWORD
vkPhysDevExtTramp60 PROTO :DWORD
vkPhysDevExtTramp61 PROTO :DWORD
vkPhysDevExtTramp62 PROTO :DWORD
vkPhysDevExtTramp63 PROTO :DWORD
vkPhysDevExtTramp64 PROTO :DWORD
vkPhysDevExtTramp65 PROTO :DWORD
vkPhysDevExtTramp66 PROTO :DWORD
vkPhysDevExtTramp67 PROTO :DWORD
vkPhysDevExtTramp68 PROTO :DWORD
vkPhysDevExtTramp69 PROTO :DWORD
vkPhysDevExtTramp6 PROTO :DWORD
vkPhysDevExtTramp70 PROTO :DWORD
vkPhysDevExtTramp71 PROTO :DWORD
vkPhysDevExtTramp72 PROTO :DWORD
vkPhysDevExtTramp73 PROTO :DWORD
vkPhysDevExtTramp74 PROTO :DWORD
vkPhysDevExtTramp75 PROTO :DWORD
vkPhysDevExtTramp76 PROTO :DWORD
vkPhysDevExtTramp77 PROTO :DWORD
vkPhysDevExtTramp78 PROTO :DWORD
vkPhysDevExtTramp79 PROTO :DWORD
vkPhysDevExtTramp7 PROTO :DWORD
vkPhysDevExtTramp80 PROTO :DWORD
vkPhysDevExtTramp81 PROTO :DWORD
vkPhysDevExtTramp82 PROTO :DWORD
vkPhysDevExtTramp83 PROTO :DWORD
vkPhysDevExtTramp84 PROTO :DWORD
vkPhysDevExtTramp85 PROTO :DWORD
vkPhysDevExtTramp86 PROTO :DWORD
vkPhysDevExtTramp87 PROTO :DWORD
vkPhysDevExtTramp88 PROTO :DWORD
vkPhysDevExtTramp89 PROTO :DWORD
vkPhysDevExtTramp8 PROTO :DWORD
vkPhysDevExtTramp90 PROTO :DWORD
vkPhysDevExtTramp91 PROTO :DWORD
vkPhysDevExtTramp92 PROTO :DWORD
vkPhysDevExtTramp93 PROTO :DWORD
vkPhysDevExtTramp94 PROTO :DWORD
vkPhysDevExtTramp95 PROTO :DWORD
vkPhysDevExtTramp96 PROTO :DWORD
vkPhysDevExtTramp97 PROTO :DWORD
vkPhysDevExtTramp98 PROTO :DWORD
vkPhysDevExtTramp99 PROTO :DWORD
vkPhysDevExtTramp9 PROTO :DWORD
vkQueueBindSparse PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkQueuePresentKHR PROTO :DWORD,:DWORD
vkQueueSubmit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkQueueWaitIdle PROTO :DWORD
vkResetCommandBuffer PROTO :DWORD,:DWORD
vkResetCommandPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkResetDescriptorPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkResetEvent PROTO :DWORD,:DWORD,:DWORD
vkResetFences PROTO :DWORD,:DWORD,:DWORD
vkSetDeviceDispatch PROTO :DWORD,:DWORD
vkSetEvent PROTO :DWORD,:DWORD,:DWORD
vkSetInstanceDispatch PROTO :DWORD,:DWORD
vkTrimCommandPool PROTO :DWORD,:DWORD,:DWORD,:DWORD
vkUnmapMemory PROTO :DWORD,:DWORD,:DWORD
vkUpdateDescriptorSets PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vkWaitForFences PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
vk_string_validate PROTO C :VARARG
vkdev_ext0 PROTO :DWORD
vkdev_ext100 PROTO :DWORD
vkdev_ext101 PROTO :DWORD
vkdev_ext102 PROTO :DWORD
vkdev_ext103 PROTO :DWORD
vkdev_ext104 PROTO :DWORD
vkdev_ext105 PROTO :DWORD
vkdev_ext106 PROTO :DWORD
vkdev_ext107 PROTO :DWORD
vkdev_ext108 PROTO :DWORD
vkdev_ext109 PROTO :DWORD
vkdev_ext10 PROTO :DWORD
vkdev_ext110 PROTO :DWORD
vkdev_ext111 PROTO :DWORD
vkdev_ext112 PROTO :DWORD
vkdev_ext113 PROTO :DWORD
vkdev_ext114 PROTO :DWORD
vkdev_ext115 PROTO :DWORD
vkdev_ext116 PROTO :DWORD
vkdev_ext117 PROTO :DWORD
vkdev_ext118 PROTO :DWORD
vkdev_ext119 PROTO :DWORD
vkdev_ext11 PROTO :DWORD
vkdev_ext120 PROTO :DWORD
vkdev_ext121 PROTO :DWORD
vkdev_ext122 PROTO :DWORD
vkdev_ext123 PROTO :DWORD
vkdev_ext124 PROTO :DWORD
vkdev_ext125 PROTO :DWORD
vkdev_ext126 PROTO :DWORD
vkdev_ext127 PROTO :DWORD
vkdev_ext128 PROTO :DWORD
vkdev_ext129 PROTO :DWORD
vkdev_ext12 PROTO :DWORD
vkdev_ext130 PROTO :DWORD
vkdev_ext131 PROTO :DWORD
vkdev_ext132 PROTO :DWORD
vkdev_ext133 PROTO :DWORD
vkdev_ext134 PROTO :DWORD
vkdev_ext135 PROTO :DWORD
vkdev_ext136 PROTO :DWORD
vkdev_ext137 PROTO :DWORD
vkdev_ext138 PROTO :DWORD
vkdev_ext139 PROTO :DWORD
vkdev_ext13 PROTO :DWORD
vkdev_ext140 PROTO :DWORD
vkdev_ext141 PROTO :DWORD
vkdev_ext142 PROTO :DWORD
vkdev_ext143 PROTO :DWORD
vkdev_ext144 PROTO :DWORD
vkdev_ext145 PROTO :DWORD
vkdev_ext146 PROTO :DWORD
vkdev_ext147 PROTO :DWORD
vkdev_ext148 PROTO :DWORD
vkdev_ext149 PROTO :DWORD
vkdev_ext14 PROTO :DWORD
vkdev_ext150 PROTO :DWORD
vkdev_ext151 PROTO :DWORD
vkdev_ext152 PROTO :DWORD
vkdev_ext153 PROTO :DWORD
vkdev_ext154 PROTO :DWORD
vkdev_ext155 PROTO :DWORD
vkdev_ext156 PROTO :DWORD
vkdev_ext157 PROTO :DWORD
vkdev_ext158 PROTO :DWORD
vkdev_ext159 PROTO :DWORD
vkdev_ext15 PROTO :DWORD
vkdev_ext160 PROTO :DWORD
vkdev_ext161 PROTO :DWORD
vkdev_ext162 PROTO :DWORD
vkdev_ext163 PROTO :DWORD
vkdev_ext164 PROTO :DWORD
vkdev_ext165 PROTO :DWORD
vkdev_ext166 PROTO :DWORD
vkdev_ext167 PROTO :DWORD
vkdev_ext168 PROTO :DWORD
vkdev_ext169 PROTO :DWORD
vkdev_ext16 PROTO :DWORD
vkdev_ext170 PROTO :DWORD
vkdev_ext171 PROTO :DWORD
vkdev_ext172 PROTO :DWORD
vkdev_ext173 PROTO :DWORD
vkdev_ext174 PROTO :DWORD
vkdev_ext175 PROTO :DWORD
vkdev_ext176 PROTO :DWORD
vkdev_ext177 PROTO :DWORD
vkdev_ext178 PROTO :DWORD
vkdev_ext179 PROTO :DWORD
vkdev_ext17 PROTO :DWORD
vkdev_ext180 PROTO :DWORD
vkdev_ext181 PROTO :DWORD
vkdev_ext182 PROTO :DWORD
vkdev_ext183 PROTO :DWORD
vkdev_ext184 PROTO :DWORD
vkdev_ext185 PROTO :DWORD
vkdev_ext186 PROTO :DWORD
vkdev_ext187 PROTO :DWORD
vkdev_ext188 PROTO :DWORD
vkdev_ext189 PROTO :DWORD
vkdev_ext18 PROTO :DWORD
vkdev_ext190 PROTO :DWORD
vkdev_ext191 PROTO :DWORD
vkdev_ext192 PROTO :DWORD
vkdev_ext193 PROTO :DWORD
vkdev_ext194 PROTO :DWORD
vkdev_ext195 PROTO :DWORD
vkdev_ext196 PROTO :DWORD
vkdev_ext197 PROTO :DWORD
vkdev_ext198 PROTO :DWORD
vkdev_ext199 PROTO :DWORD
vkdev_ext19 PROTO :DWORD
vkdev_ext1 PROTO :DWORD
vkdev_ext200 PROTO :DWORD
vkdev_ext201 PROTO :DWORD
vkdev_ext202 PROTO :DWORD
vkdev_ext203 PROTO :DWORD
vkdev_ext204 PROTO :DWORD
vkdev_ext205 PROTO :DWORD
vkdev_ext206 PROTO :DWORD
vkdev_ext207 PROTO :DWORD
vkdev_ext208 PROTO :DWORD
vkdev_ext209 PROTO :DWORD
vkdev_ext20 PROTO :DWORD
vkdev_ext210 PROTO :DWORD
vkdev_ext211 PROTO :DWORD
vkdev_ext212 PROTO :DWORD
vkdev_ext213 PROTO :DWORD
vkdev_ext214 PROTO :DWORD
vkdev_ext215 PROTO :DWORD
vkdev_ext216 PROTO :DWORD
vkdev_ext217 PROTO :DWORD
vkdev_ext218 PROTO :DWORD
vkdev_ext219 PROTO :DWORD
vkdev_ext21 PROTO :DWORD
vkdev_ext220 PROTO :DWORD
vkdev_ext221 PROTO :DWORD
vkdev_ext222 PROTO :DWORD
vkdev_ext223 PROTO :DWORD
vkdev_ext224 PROTO :DWORD
vkdev_ext225 PROTO :DWORD
vkdev_ext226 PROTO :DWORD
vkdev_ext227 PROTO :DWORD
vkdev_ext228 PROTO :DWORD
vkdev_ext229 PROTO :DWORD
vkdev_ext22 PROTO :DWORD
vkdev_ext230 PROTO :DWORD
vkdev_ext231 PROTO :DWORD
vkdev_ext232 PROTO :DWORD
vkdev_ext233 PROTO :DWORD
vkdev_ext234 PROTO :DWORD
vkdev_ext235 PROTO :DWORD
vkdev_ext236 PROTO :DWORD
vkdev_ext237 PROTO :DWORD
vkdev_ext238 PROTO :DWORD
vkdev_ext239 PROTO :DWORD
vkdev_ext23 PROTO :DWORD
vkdev_ext240 PROTO :DWORD
vkdev_ext241 PROTO :DWORD
vkdev_ext242 PROTO :DWORD
vkdev_ext243 PROTO :DWORD
vkdev_ext244 PROTO :DWORD
vkdev_ext245 PROTO :DWORD
vkdev_ext246 PROTO :DWORD
vkdev_ext247 PROTO :DWORD
vkdev_ext248 PROTO :DWORD
vkdev_ext249 PROTO :DWORD
vkdev_ext24 PROTO :DWORD
vkdev_ext25 PROTO :DWORD
vkdev_ext26 PROTO :DWORD
vkdev_ext27 PROTO :DWORD
vkdev_ext28 PROTO :DWORD
vkdev_ext29 PROTO :DWORD
vkdev_ext2 PROTO :DWORD
vkdev_ext30 PROTO :DWORD
vkdev_ext31 PROTO :DWORD
vkdev_ext32 PROTO :DWORD
vkdev_ext33 PROTO :DWORD
vkdev_ext34 PROTO :DWORD
vkdev_ext35 PROTO :DWORD
vkdev_ext36 PROTO :DWORD
vkdev_ext37 PROTO :DWORD
vkdev_ext38 PROTO :DWORD
vkdev_ext39 PROTO :DWORD
vkdev_ext3 PROTO :DWORD
vkdev_ext40 PROTO :DWORD
vkdev_ext41 PROTO :DWORD
vkdev_ext42 PROTO :DWORD
vkdev_ext43 PROTO :DWORD
vkdev_ext44 PROTO :DWORD
vkdev_ext45 PROTO :DWORD
vkdev_ext46 PROTO :DWORD
vkdev_ext47 PROTO :DWORD
vkdev_ext48 PROTO :DWORD
vkdev_ext49 PROTO :DWORD
vkdev_ext4 PROTO :DWORD
vkdev_ext50 PROTO :DWORD
vkdev_ext51 PROTO :DWORD
vkdev_ext52 PROTO :DWORD
vkdev_ext53 PROTO :DWORD
vkdev_ext54 PROTO :DWORD
vkdev_ext55 PROTO :DWORD
vkdev_ext56 PROTO :DWORD
vkdev_ext57 PROTO :DWORD
vkdev_ext58 PROTO :DWORD
vkdev_ext59 PROTO :DWORD
vkdev_ext5 PROTO :DWORD
vkdev_ext60 PROTO :DWORD
vkdev_ext61 PROTO :DWORD
vkdev_ext62 PROTO :DWORD
vkdev_ext63 PROTO :DWORD
vkdev_ext64 PROTO :DWORD
vkdev_ext65 PROTO :DWORD
vkdev_ext66 PROTO :DWORD
vkdev_ext67 PROTO :DWORD
vkdev_ext68 PROTO :DWORD
vkdev_ext69 PROTO :DWORD
vkdev_ext6 PROTO :DWORD
vkdev_ext70 PROTO :DWORD
vkdev_ext71 PROTO :DWORD
vkdev_ext72 PROTO :DWORD
vkdev_ext73 PROTO :DWORD
vkdev_ext74 PROTO :DWORD
vkdev_ext75 PROTO :DWORD
vkdev_ext76 PROTO :DWORD
vkdev_ext77 PROTO :DWORD
vkdev_ext78 PROTO :DWORD
vkdev_ext79 PROTO :DWORD
vkdev_ext7 PROTO :DWORD
vkdev_ext80 PROTO :DWORD
vkdev_ext81 PROTO :DWORD
vkdev_ext82 PROTO :DWORD
vkdev_ext83 PROTO :DWORD
vkdev_ext84 PROTO :DWORD
vkdev_ext85 PROTO :DWORD
vkdev_ext86 PROTO :DWORD
vkdev_ext87 PROTO :DWORD
vkdev_ext88 PROTO :DWORD
vkdev_ext89 PROTO :DWORD
vkdev_ext8 PROTO :DWORD
vkdev_ext90 PROTO :DWORD
vkdev_ext91 PROTO :DWORD
vkdev_ext92 PROTO :DWORD
vkdev_ext93 PROTO :DWORD
vkdev_ext94 PROTO :DWORD
vkdev_ext95 PROTO :DWORD
vkdev_ext96 PROTO :DWORD
vkdev_ext97 PROTO :DWORD
vkdev_ext98 PROTO :DWORD
vkdev_ext99 PROTO :DWORD
vkdev_ext9 PROTO :DWORD
wsi_create_instance PROTO C :VARARG
wsi_swapchain_instance_gpa PROTO C :VARARG
wsi_unsupported_instance_extension PROTO C :VARARG



;---------------------------------
; Vulkan C Macro Definitions
; https://vulkan.lunarg.com/doc/view/1.1.70.0/windows/apispec.html#defines
;---------------------------------
VK_VERSION_1_0                          EQU 1
VK_VERSION_1_1                          EQU 1
VK_MAKE_VERSION MACRO major, minor, patch
    EXITM < (((major) SHL 22) OR ((minor) SHL 12) OR (patch)) >
ENDM
VK_API_VERSION_1_0                      EQU VK_MAKE_VERSION(1, 0, 0) ; Patch version should always be set to 0
VK_API_VERSION_1_1                      EQU VK_MAKE_VERSION(1, 1, 0) ; Patch version should always be set to 0
VK_VERSION_MAJOR MACRO version
    EXITM < ((version) SHR 22) >
ENDM
VK_VERSION_MINOR MACRO version 
    EXITM < (((version) SHR 12) && 3ffh) >
ENDM
VK_VERSION_PATCH MACRO version
    EXITM < ((version) && 0fffh) >
ENDM
VK_HEADER_VERSION                       EQU 70
VK_NULL_HANDLE                          EQU 0


;---------------------------------
; Vulkan Typedefs
;---------------------------------
VkFlags                                 TYPEDEF DWORD
VkBool32                                TYPEDEF DWORD
VkDeviceSize                            TYPEDEF QWORD
VkSampleMask                            TYPEDEF DWORD
VkStructureType                         TYPEDEF DWORD
VkResult                                TYPEDEF DWORD

; HANDLE - size of pointer
VkInstance                              TYPEDEF DWORD
VkPhysicalDevice                        TYPEDEF DWORD
VkDevice                                TYPEDEF DWORD
VkQueue                                 TYPEDEF DWORD
VkCommandBuffer                         TYPEDEF DWORD

; NON_DISPATCHABLE_HANDLE - 64bit size - use DWORD PTR to pass in 32bit
VkSemaphore                             TYPEDEF QWORD
VkFence                                 TYPEDEF QWORD
VkDeviceMemory                          TYPEDEF QWORD
VkBuffer                                TYPEDEF QWORD
VkImage                                 TYPEDEF QWORD
VkEvent                                 TYPEDEF QWORD
VkQueryPool                             TYPEDEF QWORD
VkBufferView                            TYPEDEF QWORD
VkImageView                             TYPEDEF QWORD
VkShaderModule                          TYPEDEF QWORD
VkPipelineCache                         TYPEDEF QWORD
VkPipelineLayout                        TYPEDEF QWORD
VkRenderPass                            TYPEDEF QWORD
VkPipeline                              TYPEDEF QWORD
VkDescriptorSetLayout                   TYPEDEF QWORD
VkSampler                               TYPEDEF QWORD
VkDescriptorPool                        TYPEDEF QWORD
VkDescriptorSet                         TYPEDEF QWORD
VkFramebuffer                           TYPEDEF QWORD
VkCommandPool                           TYPEDEF QWORD
VkSamplerYcbcrConversion                TYPEDEF QWORD
VkDescriptorUpdateTemplate              TYPEDEF QWORD
VkSurfaceKHR                            TYPEDEF QWORD
VkSwapchainKHR                          TYPEDEF QWORD
VkDisplayKHR                            TYPEDEF QWORD
VkDisplayModeKHR                        TYPEDEF QWORD
VkDebugReportCallbackEXT                TYPEDEF QWORD
VkObjectTableNVX                        TYPEDEF QWORD
VkIndirectCommandsLayoutNVX             TYPEDEF QWORD
VkDebugUtilsMessengerEXT                TYPEDEF QWORD
VkValidationCacheEXT                    TYPEDEF QWORD




; VkFlags
VkInstanceCreateFlags                   TYPEDEF VkFlags
VkFormatFeatureFlags                    TYPEDEF VkFlags
VkImageUsageFlags                       TYPEDEF VkFlags
VkImageCreateFlags                      TYPEDEF VkFlags
VkSampleCountFlags                      TYPEDEF VkFlags
VkQueueFlags                            TYPEDEF VkFlags
VkMemoryPropertyFlags                   TYPEDEF VkFlags
VkMemoryHeapFlags                       TYPEDEF VkFlags
VkDeviceCreateFlags                     TYPEDEF VkFlags
VkDeviceQueueCreateFlags                TYPEDEF VkFlags
VkPipelineStageFlags                    TYPEDEF VkFlags
VkMemoryMapFlags                        TYPEDEF VkFlags
VkImageAspectFlags                      TYPEDEF VkFlags
VkSparseImageFormatFlags                TYPEDEF VkFlags  
VkSparseMemoryBindFlags                 TYPEDEF VkFlags
VkFenceCreateFlags                      TYPEDEF VkFlags
VkSemaphoreCreateFlags                  TYPEDEF VkFlags
VkEventCreateFlags                      TYPEDEF VkFlags
VkQueryPoolCreateFlags                  TYPEDEF VkFlags
VkQueryPipelineStatisticFlags           TYPEDEF VkFlags
VkQueryResultFlags                      TYPEDEF VkFlags
VkBufferCreateFlags                     TYPEDEF VkFlags
VkBufferUsageFlags                      TYPEDEF VkFlags
VkBufferViewCreateFlags                 TYPEDEF VkFlags
VkImageViewCreateFlags                  TYPEDEF VkFlags
VkShaderModuleCreateFlags               TYPEDEF VkFlags
VkPipelineCacheCreateFlags              TYPEDEF VkFlags
VkPipelineCreateFlags                   TYPEDEF VkFlags
VkPipelineShaderStageCreateFlags        TYPEDEF VkFlags
VkPipelineVertexInputStateCreateFlags   TYPEDEF VkFlags
VkPipelineInputAssemblyStateCreateFlags TYPEDEF VkFlags
VkPipelineTessellationStateCreateFlags  TYPEDEF VkFlags
VkPipelineViewportStateCreateFlags      TYPEDEF VkFlags
VkPipelineRasterizationStateCreateFlags TYPEDEF VkFlags
VkCullModeFlags                         TYPEDEF VkFlags
VkPipelineMultisampleStateCreateFlags   TYPEDEF VkFlags
VkPipelineDepthStencilStateCreateFlags  TYPEDEF VkFlags
VkPipelineColorBlendStateCreateFlags    TYPEDEF VkFlags
VkColorComponentFlags                   TYPEDEF VkFlags
VkPipelineDynamicStateCreateFlags       TYPEDEF VkFlags
VkPipelineLayoutCreateFlags             TYPEDEF VkFlags
VkShaderStageFlags                      TYPEDEF VkFlags
VkSamplerCreateFlags                    TYPEDEF VkFlags
VkDescriptorSetLayoutCreateFlags        TYPEDEF VkFlags
VkDescriptorPoolCreateFlags             TYPEDEF VkFlags
VkDescriptorPoolResetFlags              TYPEDEF VkFlags
VkFramebufferCreateFlags                TYPEDEF VkFlags
VkRenderPassCreateFlags                 TYPEDEF VkFlags
VkAttachmentDescriptionFlags            TYPEDEF VkFlags
VkSubpassDescriptionFlags               TYPEDEF VkFlags
VkAccessFlags                           TYPEDEF VkFlags
VkDependencyFlags                       TYPEDEF VkFlags
VkCommandPoolCreateFlags                TYPEDEF VkFlags
VkCommandPoolResetFlags                 TYPEDEF VkFlags
VkCommandBufferUsageFlags               TYPEDEF VkFlags
VkQueryControlFlags                     TYPEDEF VkFlags
VkCommandBufferResetFlags               TYPEDEF VkFlags
VkStencilFaceFlags                      TYPEDEF VkFlags
VkSubgroupFeatureFlags                  TYPEDEF VkFlags
VkPeerMemoryFeatureFlags                TYPEDEF VkFlags
VkMemoryAllocateFlags                   TYPEDEF VkFlags
VkCommandPoolTrimFlags                  TYPEDEF VkFlags
VkDescriptorUpdateTemplateCreateFlags   TYPEDEF VkFlags
VkExternalMemoryHandleTypeFlags         TYPEDEF VkFlags
VkExternalMemoryFeatureFlags            TYPEDEF VkFlags
VkExternalFenceHandleTypeFlags          TYPEDEF VkFlags
VkExternalFenceFeatureFlags             TYPEDEF VkFlags
VkFenceImportFlags                      TYPEDEF VkFlags
VkSemaphoreImportFlags                  TYPEDEF VkFlags
VkExternalSemaphoreHandleTypeFlags      TYPEDEF VkFlags
VkExternalSemaphoreFeatureFlags         TYPEDEF VkFlags
VkSurfaceTransformFlagsKHR              TYPEDEF VkFlags
VkCompositeAlphaFlagsKHR                TYPEDEF VkFlags
VkSwapchainCreateFlagsKHR               TYPEDEF VkFlags
VkDeviceGroupPresentModeFlagsKHR        TYPEDEF VkFlags
VkDisplayPlaneAlphaFlagsKHR             TYPEDEF VkFlags
VkDisplayModeCreateFlagsKHR             TYPEDEF VkFlags
VkDisplaySurfaceCreateFlagsKHR          TYPEDEF VkFlags
VkDebugReportFlagsEXT                   TYPEDEF VkFlags
VkExternalMemoryHandleTypeFlagsNV       TYPEDEF VkFlags
VkExternalMemoryFeatureFlagsNV          TYPEDEF VkFlags
VkIndirectCommandsLayoutUsageFlagsNVX   TYPEDEF VkFlags
VkObjectEntryUsageFlagsNVX              TYPEDEF VkFlags
VkSurfaceCounterFlagsEXT                TYPEDEF VkFlags
VkPipelineViewportSwizzleStateCreateFlagsNV TYPEDEF VkFlags
VkPipelineDiscardRectangleStateCreateFlagsEXT TYPEDEF VkFlags
VkPipelineRasterizationConservativeStateCreateFlagsEXT TYPEDEF VkFlags
VkDebugUtilsMessengerCallbackDataFlagsEXT TYPEDEF VkFlags
VkDebugUtilsMessengerCreateFlagsEXT     TYPEDEF VkFlags
VkDebugUtilsMessageSeverityFlagsEXT     TYPEDEF VkFlags
VkDebugUtilsMessageTypeFlagsEXT         TYPEDEF VkFlags
VkPipelineCoverageToColorStateCreateFlagsNV TYPEDEF VkFlags
VkPipelineCoverageModulationStateCreateFlagsNV TYPEDEF VkFlags
VkValidationCacheCreateFlagsEXT         TYPEDEF VkFlags
VkExternalSemaphoreHandleTypeFlagBits   TYPEDEF VkFlags
VkExternalMemoryHandleTypeFlagBits      TYPEDEF VkFlags
VkExternalFenceHandleTypeFlagBits       TYPEDEF VkFlags
VkWin32SurfaceCreateFlagsKHR            TYPEDEF VkFlags


; VkRenderPassMultiviewCreateInfo VkRenderPassMultiviewCreateInfoKHR;
; VkPhysicalDeviceMultiviewFeatures VkPhysicalDeviceMultiviewFeaturesKHR;
; VkPhysicalDeviceMultiviewProperties VkPhysicalDeviceMultiviewPropertiesKHR;
; VkPhysicalDeviceFeatures2 VkPhysicalDeviceFeatures2KHR;
; VkPhysicalDeviceProperties2 VkPhysicalDeviceProperties2KHR;
; VkFormatProperties2 VkFormatProperties2KHR;
; VkImageFormatProperties2 VkImageFormatProperties2KHR;
; VkPhysicalDeviceImageFormatInfo2 VkPhysicalDeviceImageFormatInfo2KHR;
; VkQueueFamilyProperties2 VkQueueFamilyProperties2KHR;
; VkPhysicalDeviceMemoryProperties2 VkPhysicalDeviceMemoryProperties2KHR;
; VkSparseImageFormatProperties2 VkSparseImageFormatProperties2KHR;
; VkPhysicalDeviceSparseImageFormatInfo2 VkPhysicalDeviceSparseImageFormatInfo2KHR;
; VkPeerMemoryFeatureFlags VkPeerMemoryFeatureFlagsKHR;
; VkPeerMemoryFeatureFlagBits VkPeerMemoryFeatureFlagBitsKHR;
; VkMemoryAllocateFlags VkMemoryAllocateFlagsKHR;
; VkMemoryAllocateFlagBits VkMemoryAllocateFlagBitsKHR;
; VkMemoryAllocateFlagsInfo VkMemoryAllocateFlagsInfoKHR;
; VkDeviceGroupRenderPassBeginInfo VkDeviceGroupRenderPassBeginInfoKHR;
; VkDeviceGroupCommandBufferBeginInfo VkDeviceGroupCommandBufferBeginInfoKHR;
; VkDeviceGroupSubmitInfo VkDeviceGroupSubmitInfoKHR;
; VkDeviceGroupBindSparseInfo VkDeviceGroupBindSparseInfoKHR;
; VkBindBufferMemoryDeviceGroupInfo VkBindBufferMemoryDeviceGroupInfoKHR;
; VkBindImageMemoryDeviceGroupInfo VkBindImageMemoryDeviceGroupInfoKHR;
; VkCommandPoolTrimFlags VkCommandPoolTrimFlagsKHR;
; VkPhysicalDeviceGroupProperties VkPhysicalDeviceGroupPropertiesKHR;
; VkDeviceGroupDeviceCreateInfo VkDeviceGroupDeviceCreateInfoKHR;
; VkExternalMemoryHandleTypeFlags VkExternalMemoryHandleTypeFlagsKHR;
; VkExternalMemoryHandleTypeFlagBits VkExternalMemoryHandleTypeFlagBitsKHR;
; VkExternalMemoryFeatureFlags VkExternalMemoryFeatureFlagsKHR;
; VkExternalMemoryFeatureFlagBits VkExternalMemoryFeatureFlagBitsKHR;
; VkExternalMemoryProperties VkExternalMemoryPropertiesKHR;
; VkPhysicalDeviceExternalImageFormatInfo VkPhysicalDeviceExternalImageFormatInfoKHR;
; VkExternalImageFormatProperties VkExternalImageFormatPropertiesKHR;
; VkPhysicalDeviceExternalBufferInfo VkPhysicalDeviceExternalBufferInfoKHR;
; VkExternalBufferProperties VkExternalBufferPropertiesKHR;
; VkPhysicalDeviceIDProperties VkPhysicalDeviceIDPropertiesKHR;
; VkExternalMemoryImageCreateInfo VkExternalMemoryImageCreateInfoKHR;
; VkExternalMemoryBufferCreateInfo VkExternalMemoryBufferCreateInfoKHR;
; VkExportMemoryAllocateInfo VkExportMemoryAllocateInfoKHR;
; VkExternalSemaphoreHandleTypeFlags VkExternalSemaphoreHandleTypeFlagsKHR;
; VkExternalSemaphoreHandleTypeFlagBits VkExternalSemaphoreHandleTypeFlagBitsKHR;
; VkExternalSemaphoreFeatureFlags VkExternalSemaphoreFeatureFlagsKHR;
; VkExternalSemaphoreFeatureFlagBits VkExternalSemaphoreFeatureFlagBitsKHR;
; VkPhysicalDeviceExternalSemaphoreInfo VkPhysicalDeviceExternalSemaphoreInfoKHR;
; VkExternalSemaphoreProperties VkExternalSemaphorePropertiesKHR;
; VkSemaphoreImportFlags VkSemaphoreImportFlagsKHR;
; VkSemaphoreImportFlagBits VkSemaphoreImportFlagBitsKHR;
; VkExportSemaphoreCreateInfo VkExportSemaphoreCreateInfoKHR;
; VkPhysicalDevice16BitStorageFeatures VkPhysicalDevice16BitStorageFeaturesKHR;
; VkDescriptorUpdateTemplate VkDescriptorUpdateTemplateKHR;
; VkDescriptorUpdateTemplateType VkDescriptorUpdateTemplateTypeKHR;
; VkDescriptorUpdateTemplateCreateFlags VkDescriptorUpdateTemplateCreateFlagsKHR;
; VkDescriptorUpdateTemplateEntry VkDescriptorUpdateTemplateEntryKHR;
; VkDescriptorUpdateTemplateCreateInfo VkDescriptorUpdateTemplateCreateInfoKHR;
; VkExternalFenceHandleTypeFlags VkExternalFenceHandleTypeFlagsKHR;
; VkExternalFenceHandleTypeFlagBits VkExternalFenceHandleTypeFlagBitsKHR;
; VkExternalFenceFeatureFlags VkExternalFenceFeatureFlagsKHR;
; VkExternalFenceFeatureFlagBits VkExternalFenceFeatureFlagBitsKHR;
; VkPhysicalDeviceExternalFenceInfo VkPhysicalDeviceExternalFenceInfoKHR;
; VkExternalFenceProperties VkExternalFencePropertiesKHR;
; VkFenceImportFlags VkFenceImportFlagsKHR;
; VkFenceImportFlagBits VkFenceImportFlagBitsKHR;
; VkExportFenceCreateInfo VkExportFenceCreateInfoKHR;
; VkPointClippingBehavior VkPointClippingBehaviorKHR;
; VkTessellationDomainOrigin VkTessellationDomainOriginKHR;
; VkPhysicalDevicePointClippingProperties VkPhysicalDevicePointClippingPropertiesKHR;
; VkRenderPassInputAttachmentAspectCreateInfo VkRenderPassInputAttachmentAspectCreateInfoKHR;
; VkInputAttachmentAspectReference VkInputAttachmentAspectReferenceKHR;
; VkImageViewUsageCreateInfo VkImageViewUsageCreateInfoKHR;
; VkPipelineTessellationDomainOriginStateCreateInfo VkPipelineTessellationDomainOriginStateCreateInfoKHR;
; VkPhysicalDeviceVariablePointerFeatures VkPhysicalDeviceVariablePointerFeaturesKHR;
; VkMemoryDedicatedRequirements VkMemoryDedicatedRequirementsKHR;
; VkMemoryDedicatedAllocateInfo VkMemoryDedicatedAllocateInfoKHR;
; VkBufferMemoryRequirementsInfo2 VkBufferMemoryRequirementsInfo2KHR;
; VkImageMemoryRequirementsInfo2 VkImageMemoryRequirementsInfo2KHR;
; VkImageSparseMemoryRequirementsInfo2 VkImageSparseMemoryRequirementsInfo2KHR;
; VkMemoryRequirements2 VkMemoryRequirements2KHR;
; VkSparseImageMemoryRequirements2 VkSparseImageMemoryRequirements2KHR;
; VkSamplerYcbcrConversion VkSamplerYcbcrConversionKHR;
; VkSamplerYcbcrModelConversion VkSamplerYcbcrModelConversionKHR;
; VkSamplerYcbcrRange VkSamplerYcbcrRangeKHR;
; VkChromaLocation VkChromaLocationKHR;
; VkSamplerYcbcrConversionCreateInfo VkSamplerYcbcrConversionCreateInfoKHR;
; VkSamplerYcbcrConversionInfo VkSamplerYcbcrConversionInfoKHR;
; VkBindImagePlaneMemoryInfo VkBindImagePlaneMemoryInfoKHR;
; VkImagePlaneMemoryRequirementsInfo VkImagePlaneMemoryRequirementsInfoKHR;
; VkPhysicalDeviceSamplerYcbcrConversionFeatures VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR;
; VkSamplerYcbcrConversionImageFormatProperties VkSamplerYcbcrConversionImageFormatPropertiesKHR;
; VkBindBufferMemoryInfo VkBindBufferMemoryInfoKHR;
; VkBindImageMemoryInfo VkBindImageMemoryInfoKHR;    
; VkPhysicalDeviceMaintenance3Properties VkPhysicalDeviceMaintenance3PropertiesKHR;
; VkDescriptorSetLayoutSupport VkDescriptorSetLayoutSupportKHR;
; VkFlags VkDebugReportFlagsEXT;






























  
;---------------------------------
; Vulkan Enumeration and Equates 
; https://vulkan.lunarg.com/doc/view/1.1.70.0/windows/apispec.html#enums
;---------------------------------

VK_LOD_CLAMP_NONE                       EQU 1000.0f
VK_REMAINING_MIP_LEVELS                 EQU 0
VK_REMAINING_ARRAY_LAYERS               EQU 0
VK_WHOLE_SIZE                           EQU 0
VK_ATTACHMENT_UNUSED                    EQU 0
VK_TRUE                                 EQU 1
VK_FALSE                                EQU 0
VK_QUEUE_FAMILY_IGNORED                 EQU 0
VK_SUBPASS_EXTERNAL                     EQU 0
VK_MAX_PHYSICAL_DEVICE_NAME_SIZE        EQU 256
VK_UUID_SIZE                            EQU 16
VK_MAX_MEMORY_TYPES                     EQU 32
VK_MAX_MEMORY_HEAPS                     EQU 16
VK_MAX_EXTENSION_NAME_SIZE              EQU 256
VK_MAX_DESCRIPTION_SIZE                 EQU 256
VK_MAX_DEVICE_GROUP_SIZE                EQU 32
VK_LUID_SIZE                            EQU 8
VK_QUEUE_FAMILY_EXTERNAL                EQU -1

VK_KHR_surface                          EQU 1
VK_KHR_SURFACE_SPEC_VERSION             EQU 25
VK_COLORSPACE_SRGB_NONLINEAR_KHR        EQU 0 ; VK_COLOR_SPACE_SRGB_NONLINEAR_KHR
VK_KHR_swapchain                        EQU 1
VK_KHR_SWAPCHAIN_SPEC_VERSION           EQU 70
VK_KHR_display                          EQU 1
VK_KHR_DISPLAY_SPEC_VERSION             EQU 21
VK_KHR_display_swapchain                EQU 1
VK_KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION   EQU 9
VK_KHR_sampler_mirror_clamp_to_edge     EQU 1
VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION EQU 1
VK_KHR_multiview                        EQU 1
VK_KHR_MULTIVIEW_SPEC_VERSION           EQU 1
VK_KHR_get_physical_device_properties2  EQU 1
VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION EQU 1
VK_KHR_device_group                     EQU 1
VK_KHR_DEVICE_GROUP_SPEC_VERSION        EQU 3
VK_KHR_shader_draw_parameters           EQU 1
VK_KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION EQU 1
VK_KHR_maintenance1                     EQU 1
VK_KHR_MAINTENANCE1_SPEC_VERSION        EQU 1
VK_KHR_device_group_creation            EQU 1
VK_KHR_DEVICE_GROUP_CREATION_SPEC_VERSION EQU 1
VK_MAX_DEVICE_GROUP_SIZE_KHR            EQU VK_MAX_DEVICE_GROUP_SIZE
VK_KHR_external_memory_capabilities     EQU 1
VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION EQU 1
VK_LUID_SIZE_KHR                        EQU VK_LUID_SIZE
VK_KHR_external_memory                  EQU 1
VK_KHR_EXTERNAL_MEMORY_SPEC_VERSION     EQU 1
VK_QUEUE_FAMILY_EXTERNAL_KHR            EQU VK_QUEUE_FAMILY_EXTERNAL
VK_KHR_external_memory_fd               EQU 1
VK_KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION  EQU 1
VK_KHR_external_semaphore_capabilities  EQU 1
VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION EQU 1
VK_KHR_external_semaphore               EQU 1
VK_KHR_EXTERNAL_SEMAPHORE_SPEC_VERSION  EQU 1
VK_KHR_external_semaphore_fd            EQU 1
VK_KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION EQU 1
VK_KHR_push_descriptor                  EQU 1
VK_KHR_PUSH_DESCRIPTOR_SPEC_VERSION     EQU 2
VK_KHR_16bit_storage                    EQU 1
VK_KHR_16BIT_STORAGE_SPEC_VERSION       EQU 1
VK_KHR_incremental_present              EQU 1
VK_KHR_INCREMENTAL_PRESENT_SPEC_VERSION EQU 1
VK_KHR_descriptor_update_template       EQU 1
VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_SPEC_VERSION EQU 1
VK_KHR_shared_presentable_image         EQU 1
VK_KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION EQU 1
VK_KHR_external_fence_capabilities      EQU 1
VK_KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION EQU 1
VK_KHR_external_fence                   EQU 1
VK_KHR_EXTERNAL_FENCE_SPEC_VERSION      EQU 1
VK_KHR_external_fence_fd                EQU 1
VK_KHR_EXTERNAL_FENCE_FD_SPEC_VERSION   EQU 1
VK_KHR_maintenance2                     EQU 1
VK_KHR_MAINTENANCE2_SPEC_VERSION        EQU 1
VK_KHR_get_surface_capabilities2        EQU 1
VK_KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION EQU 1
VK_KHR_variable_pointers                EQU 1
VK_KHR_VARIABLE_POINTERS_SPEC_VERSION   EQU 1
VK_KHR_dedicated_allocation             EQU 1
VK_KHR_DEDICATED_ALLOCATION_SPEC_VERSION EQU 3
VK_KHR_storage_buffer_storage_class     EQU 1
VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_SPEC_VERSION EQU 1
VK_KHR_relaxed_block_layout             EQU 1
VK_KHR_RELAXED_BLOCK_LAYOUT_SPEC_VERSION EQU 1
VK_KHR_get_memory_requirements2         EQU 1
VK_KHR_GET_MEMORY_REQUIREMENTS_2_SPEC_VERSION EQU 1
VK_KHR_image_format_list                EQU 1
VK_KHR_IMAGE_FORMAT_LIST_SPEC_VERSION   EQU 1
VK_KHR_sampler_ycbcr_conversion         EQU 1
VK_KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION EQU 1
VK_KHR_bind_memory2                     EQU 1
VK_KHR_BIND_MEMORY_2_SPEC_VERSION       EQU 1
VK_KHR_maintenance3                     EQU 1
VK_KHR_MAINTENANCE3_SPEC_VERSION        EQU 1
VK_EXT_debug_report                     EQU 1
VK_EXT_DEBUG_REPORT_SPEC_VERSION        EQU 9
VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT  EQU VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT
VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT    EQU VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT
VK_NV_glsl_shader                       EQU 1
VK_NV_GLSL_SHADER_SPEC_VERSION          EQU 1
VK_EXT_depth_range_unrestricted         EQU 1
VK_EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION EQU 1
VK_IMG_filter_cubic                     EQU 1
VK_IMG_FILTER_CUBIC_SPEC_VERSION        EQU 1
VK_AMD_rasterization_order              EQU 1
VK_AMD_RASTERIZATION_ORDER_SPEC_VERSION EQU 1
VK_AMD_shader_trinary_minmax            EQU 1
VK_AMD_SHADER_TRINARY_MINMAX_SPEC_VERSION EQU 1
VK_AMD_shader_explicit_vertex_parameter EQU 1
VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_SPEC_VERSION EQU 1
VK_EXT_debug_marker                     EQU 1
VK_EXT_DEBUG_MARKER_SPEC_VERSION        EQU 4
VK_AMD_gcn_shader                       EQU 1
VK_AMD_GCN_SHADER_SPEC_VERSION          EQU 1
VK_NV_dedicated_allocation              EQU 1
VK_NV_DEDICATED_ALLOCATION_SPEC_VERSION EQU 1
VK_AMD_draw_indirect_count              EQU 1
VK_AMD_DRAW_INDIRECT_COUNT_SPEC_VERSION EQU 1
VK_AMD_negative_viewport_height         EQU 1
VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_SPEC_VERSION EQU 1
VK_AMD_gpu_shader_half_float            EQU 1
VK_AMD_GPU_SHADER_HALF_FLOAT_SPEC_VERSION EQU 1
VK_AMD_shader_ballot                    EQU 1
VK_AMD_SHADER_BALLOT_SPEC_VERSION       EQU 1
VK_AMD_texture_gather_bias_lod          EQU 1
VK_AMD_TEXTURE_GATHER_BIAS_LOD_SPEC_VERSION EQU 1
VK_AMD_shader_info                      EQU 1
VK_AMD_SHADER_INFO_SPEC_VERSION         EQU 1
VK_AMD_shader_image_load_store_lod      EQU 1
VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_SPEC_VERSION EQU 1
VK_IMG_format_pvrtc                     EQU 1
VK_IMG_FORMAT_PVRTC_SPEC_VERSION        EQU 1
VK_NV_external_memory_capabilities      EQU 1
VK_NV_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION EQU 1
VK_NV_external_memory                   EQU 1
VK_NV_EXTERNAL_MEMORY_SPEC_VERSION      EQU 1
VK_EXT_validation_flags                 EQU 1
VK_EXT_VALIDATION_FLAGS_SPEC_VERSION    EQU 1
VK_EXT_shader_subgroup_ballot           EQU 1
VK_EXT_SHADER_SUBGROUP_BALLOT_SPEC_VERSION EQU 1
VK_EXT_shader_subgroup_vote             EQU 1
VK_EXT_SHADER_SUBGROUP_VOTE_SPEC_VERSION EQU 1
VK_NVX_device_generated_commands        EQU 1
VK_NVX_DEVICE_GENERATED_COMMANDS_SPEC_VERSION EQU 3
VK_NV_clip_space_w_scaling              EQU 1
VK_NV_CLIP_SPACE_W_SCALING_SPEC_VERSION EQU 1
VK_EXT_direct_mode_display              EQU 1
VK_EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION EQU 1
VK_EXT_display_surface_counter          EQU 1
VK_EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION EQU 1
VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT EQU VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT
VK_EXT_display_control                  EQU 1
VK_EXT_DISPLAY_CONTROL_SPEC_VERSION     EQU 1
VK_GOOGLE_display_timing                EQU 1
VK_GOOGLE_DISPLAY_TIMING_SPEC_VERSION   EQU 1
VK_NV_sample_mask_override_coverage     EQU 1
VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_SPEC_VERSION EQU 1
VK_NV_geometry_shader_passthrough       EQU 1
VK_NV_GEOMETRY_SHADER_PASSTHROUGH_SPEC_VERSION EQU 1
VK_NV_viewport_array2                   EQU 1
VK_NV_VIEWPORT_ARRAY2_SPEC_VERSION      EQU 1
VK_NVX_multiview_per_view_attributes    EQU 1
VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_SPEC_VERSION EQU 1
VK_NV_viewport_swizzle                  EQU 1
VK_NV_VIEWPORT_SWIZZLE_SPEC_VERSION     EQU 1
VK_EXT_discard_rectangles               EQU 1
VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION  EQU 1
VK_EXT_conservative_rasterization       EQU 1
VK_EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION EQU 1
VK_EXT_swapchain_colorspace             EQU 1
VK_EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION EQU 3
VK_EXT_hdr_metadata                     EQU 1
VK_EXT_HDR_METADATA_SPEC_VERSION        EQU 1
VK_EXT_external_memory_dma_buf          EQU 1
VK_EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION EQU 1
VK_EXT_queue_family_foreign             EQU 1
VK_EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION EQU 1
VK_QUEUE_FAMILY_FOREIGN_EXT             EQU -2
VK_EXT_debug_utils                      EQU 1
VK_EXT_DEBUG_UTILS_SPEC_VERSION         EQU 1
VK_EXT_sampler_filter_minmax            EQU 1
VK_EXT_SAMPLER_FILTER_MINMAX_SPEC_VERSION EQU 1
VK_AMD_gpu_shader_int16                 EQU 1
VK_AMD_GPU_SHADER_INT16_SPEC_VERSION    EQU 1
VK_AMD_mixed_attachment_samples         EQU 1
VK_AMD_MIXED_ATTACHMENT_SAMPLES_SPEC_VERSION EQU 1
VK_AMD_shader_fragment_mask             EQU 1
VK_AMD_SHADER_FRAGMENT_MASK_SPEC_VERSION EQU 1
VK_EXT_shader_stencil_export            EQU 1
VK_EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION EQU 1
VK_EXT_sample_locations                 EQU 1
VK_EXT_SAMPLE_LOCATIONS_SPEC_VERSION    EQU 1
VK_EXT_blend_operation_advanced         EQU 1
VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION EQU 2
VK_NV_fragment_coverage_to_color        EQU 1
VK_NV_FRAGMENT_COVERAGE_TO_COLOR_SPEC_VERSION EQU 1
VK_NV_framebuffer_mixed_samples         EQU 1
VK_NV_FRAMEBUFFER_MIXED_SAMPLES_SPEC_VERSION EQU 1
VK_NV_fill_rectangle                    EQU 1
VK_NV_FILL_RECTANGLE_SPEC_VERSION       EQU 1
VK_EXT_post_depth_coverage              EQU 1
VK_EXT_POST_DEPTH_COVERAGE_SPEC_VERSION EQU 1
VK_EXT_validation_cache                 EQU 1
VK_EXT_VALIDATION_CACHE_SPEC_VERSION    EQU 1
VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT EQU VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT
VK_EXT_shader_viewport_index_layer      EQU 1
VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_SPEC_VERSION EQU 1
VK_EXT_global_priority                  EQU 1
VK_EXT_GLOBAL_PRIORITY_SPEC_VERSION     EQU 2
VK_EXT_external_memory_host             EQU 1
VK_EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION EQU 1
VK_AMD_buffer_marker                    EQU 1
VK_AMD_BUFFER_MARKER_SPEC_VERSION       EQU 1
VK_EXT_vertex_attribute_divisor         EQU 1
VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION EQU 1
VK_KHR_win32_surface                    EQU 1
VK_KHR_WIN32_SURFACE_SPEC_VERSION       EQU 6
VK_KHR_external_memory_win32            EQU 1
VK_KHR_EXTERNAL_MEMORY_WIN32_SPEC_VERSION EQU 1
VK_KHR_win32_keyed_mutex                EQU 1
VK_KHR_WIN32_KEYED_MUTEX_SPEC_VERSION   EQU 1
VK_KHR_external_semaphore_win32         EQU 1
VK_KHR_EXTERNAL_SEMAPHORE_WIN32_SPEC_VERSION EQU 1
VK_KHR_external_fence_win32             EQU 1
VK_KHR_EXTERNAL_FENCE_WIN32_SPEC_VERSION EQU 1
VK_NV_external_memory_win32             EQU 1
VK_NV_EXTERNAL_MEMORY_WIN32_SPEC_VERSION EQU 1
VK_NV_win32_keyed_mutex                 EQU 1
VK_NV_WIN32_KEYED_MUTEX_SPEC_VERSION    EQU 1





; VkPipelineCacheHeaderVersion
VK_PIPELINE_CACHE_HEADER_VERSION_ONE    EQU 1
VK_PIPELINE_CACHE_HEADER_VERSION_BEGIN_RANGE EQU VK_PIPELINE_CACHE_HEADER_VERSION_ONE
VK_PIPELINE_CACHE_HEADER_VERSION_END_RANGE EQU VK_PIPELINE_CACHE_HEADER_VERSION_ONE,
VK_PIPELINE_CACHE_HEADER_VERSION_RANGE_SIZE EQU (VK_PIPELINE_CACHE_HEADER_VERSION_ONE - VK_PIPELINE_CACHE_HEADER_VERSION_ONE + 1)
VK_PIPELINE_CACHE_HEADER_VERSION_MAX_ENUM EQU 7FFFFFFFh

; VkResult
VK_SUCCESS                              EQU 0
VK_NOT_READY                            EQU 1
VK_TIMEOUT                              EQU 2
VK_EVENT_SET                            EQU 3
VK_EVENT_RESET                          EQU 4
VK_INCOMPLETE                           EQU 5
VK_ERROR_OUT_OF_HOST_MEMORY             EQU -1
VK_ERROR_OUT_OF_DEVICE_MEMORY           EQU -2
VK_ERROR_INITIALIZATION_FAILED          EQU -3
VK_ERROR_DEVICE_LOST                    EQU -4
VK_ERROR_MEMORY_MAP_FAILED              EQU -5
VK_ERROR_LAYER_NOT_PRESENT              EQU -6
VK_ERROR_EXTENSION_NOT_PRESENT          EQU -7
VK_ERROR_FEATURE_NOT_PRESENT            EQU -8
VK_ERROR_INCOMPATIBLE_DRIVER            EQU -9
VK_ERROR_TOO_MANY_OBJECTS               EQU -10
VK_ERROR_FORMAT_NOT_SUPPORTED           EQU -11
VK_ERROR_FRAGMENTED_POOL                EQU -12
VK_ERROR_OUT_OF_POOL_MEMORY             EQU -1000069000
VK_ERROR_INVALID_EXTERNAL_HANDLE        EQU -1000072003
VK_ERROR_SURFACE_LOST_KHR               EQU -1000000000
VK_ERROR_NATIVE_WINDOW_IN_USE_KHR       EQU -1000000001
VK_SUBOPTIMAL_KHR                       EQU 1000001003
VK_ERROR_OUT_OF_DATE_KHR                EQU -1000001004
VK_ERROR_INCOMPATIBLE_DISPLAY_KHR       EQU -1000003001
VK_ERROR_VALIDATION_FAILED_EXT          EQU -1000011001
VK_ERROR_INVALID_SHADER_NV              EQU -1000012000
VK_ERROR_NOT_PERMITTED_EXT              EQU -1000174001
VK_ERROR_OUT_OF_POOL_MEMORY_KHR         EQU VK_ERROR_OUT_OF_POOL_MEMORY
VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR    EQU VK_ERROR_INVALID_EXTERNAL_HANDLE
VK_RESULT_BEGIN_RANGE                   EQU VK_ERROR_FRAGMENTED_POOL
VK_RESULT_END_RANGE                     EQU VK_INCOMPLETE
VK_RESULT_RANGE_SIZE                    EQU (VK_INCOMPLETE - VK_ERROR_FRAGMENTED_POOL + 1)
VK_RESULT_MAX_ENUM                      EQU 7FFFFFFFh

; VkStructureType
VK_STRUCTURE_TYPE_APPLICATION_INFO      EQU 0
VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO  EQU 1
VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO EQU 2
VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO    EQU 3
VK_STRUCTURE_TYPE_SUBMIT_INFO           EQU 4
VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO  EQU 5
VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE   EQU 6
VK_STRUCTURE_TYPE_BIND_SPARSE_INFO      EQU 7
VK_STRUCTURE_TYPE_FENCE_CREATE_INFO     EQU 8
VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO EQU 9
VK_STRUCTURE_TYPE_EVENT_CREATE_INFO     EQU 10
VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO EQU 11
VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO    EQU 12
VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO EQU 13
VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO     EQU 14
VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO EQU 15
VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO EQU 16
VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO EQU 17
VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO EQU 18
VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO EQU 19
VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO EQU 20
VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO EQU 21
VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO EQU 22
VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO EQU 23
VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO EQU 24
VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO EQU 25
VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO EQU 26
VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO EQU 27
VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO EQU 28
VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO EQU 29
VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO EQU 30
VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO   EQU 31
VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO EQU 32
VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO EQU 33
VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO EQU 34
VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET  EQU 35
VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET   EQU 36
VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO EQU 37
VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO EQU 38
VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO EQU 39
VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO EQU 40
VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO EQU 41
VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO EQU 42
VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO EQU 43
VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER EQU 44
VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER  EQU 45
VK_STRUCTURE_TYPE_MEMORY_BARRIER        EQU 46
VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO EQU 47
VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO EQU 48
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES EQU 1000094000
VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO EQU 1000157000
VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO EQU 1000157001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES EQU 1000083000
VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS EQU 1000127000
VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO EQU 1000127001
VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO EQU 1000060000
VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO EQU 1000060003
VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO EQU 1000060004
VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO EQU 1000060005
VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO EQU 1000060006
VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO EQU 1000060013
VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO EQU 1000060014
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES EQU 1000070000
VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO EQU 1000070001
VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2 EQU 1000146000
VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2 EQU 1000146001
VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2 EQU 1000146002
VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 EQU 1000146003
VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2 EQU 1000146004
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 EQU 1000059000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 EQU 1000059001
VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2   EQU 1000059002
VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 EQU 1000059003
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2 EQU 1000059004
VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2 EQU 1000059005
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2 EQU 1000059006
VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2 EQU 1000059007
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2 EQU 1000059008
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES EQU 1000117000
VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO EQU 1000117001
VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO EQU 1000117002
VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO EQU 1000117003
VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO EQU 1000053000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES EQU 1000053001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES EQU 1000053002
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES EQU 1000120000
VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO EQU 1000145000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES EQU 1000145001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES EQU 1000145002
VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2   EQU 1000145003
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO EQU 1000156000
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO EQU 1000156001
VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO EQU 1000156002
VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO EQU 1000156003
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES EQU 1000156004
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES EQU 1000156005
VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO EQU 1000085000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO EQU 1000071000
VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES EQU 1000071001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO EQU 1000071002
VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES EQU 1000071003
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES EQU 1000071004
VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO EQU 1000072000
VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO EQU 1000072001
VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO EQU 1000072002
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO EQU 1000112000
VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES EQU 1000112001
VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO EQU 1000113000
VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO EQU 1000077000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO EQU 1000076000
VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES EQU 1000076001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES EQU 1000168000
VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT EQU 1000168001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES EQU 1000063000
VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR EQU 1000001000
VK_STRUCTURE_TYPE_PRESENT_INFO_KHR      EQU 1000001001
VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR EQU 1000060007
VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR EQU 1000060008
VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR EQU 1000060009
VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR EQU 1000060010
VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR EQU 1000060011
VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR EQU 1000060012
VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR EQU 1000002000
VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR EQU 1000002001
VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR EQU 1000003000
VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR EQU 1000004000
VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR EQU 1000005000
VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR EQU 1000006000
VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR EQU 1000007000
VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR EQU 1000008000
VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR EQU 1000009000
VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT EQU 1000011000
VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD EQU 1000018000
VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT EQU 1000022000
VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT EQU 1000022001
VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT EQU 1000022002
VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV EQU 1000026000
VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV EQU 1000026001
VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV EQU 1000026002
VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD EQU 1000041000
VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV EQU 1000056000
VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV EQU 1000056001
VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV EQU 1000057000
VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV EQU 1000057001
VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV EQU 1000058000
VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT EQU 1000061000
VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN EQU 1000062000
VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR EQU 1000073000
VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR EQU 1000073001
VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR EQU 1000073002
VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR EQU 1000073003
VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR EQU 1000074000
VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR EQU 1000074001
VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR EQU 1000074002
VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR EQU 1000075000
VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR EQU 1000078000
VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR EQU 1000078001
VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR EQU 1000078002
VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR EQU 1000078003
VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR EQU 1000079000
VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR EQU 1000079001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR EQU 1000080000
VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR   EQU 1000084000
VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX EQU 1000086000
VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX EQU 1000086001
VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX EQU 1000086002
VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX EQU 1000086003
VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX EQU 1000086004
VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX EQU 1000086005
VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV EQU 1000087000
VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT EQU 1000090000
VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT EQU 1000091000
VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT EQU 1000091001
VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT EQU 1000091002
VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT EQU 1000091003
VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE EQU 1000092000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX EQU 1000097000
VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV EQU 1000098000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT EQU 1000099000
VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT EQU 1000099001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT EQU 1000101000
VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT EQU 1000101001
VK_STRUCTURE_TYPE_HDR_METADATA_EXT      EQU 1000105000
VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR EQU 1000111000
VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR EQU 1000114000
VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR EQU 1000114001
VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR EQU 1000114002
VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR EQU 1000115000
VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR EQU 1000115001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR EQU 1000119000
VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR EQU 1000119001
VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR  EQU 1000119002
VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK EQU 1000122000
VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK EQU 1000123000
VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT EQU 1000128000
VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT EQU 1000128001
VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT EQU 1000128002
VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT EQU 1000128003
VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT EQU 1000128004
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT EQU 1000130000
VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT EQU 1000130001
VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT EQU 1000143000
VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT EQU 1000143001
VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT EQU 1000143002
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT EQU 1000143003
VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT EQU 1000143004
VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR EQU 1000147000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT EQU 1000148000
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT EQU 1000148001
VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT EQU 1000148002
VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV EQU 1000149000
VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV EQU 1000152000
VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT EQU 1000160000
VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT EQU 1000160001
VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT EQU 1000174000
VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT EQU 1000178000
VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT EQU 1000178001
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT EQU 1000178002
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT EQU 1000190000
VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT EQU 1000190001
VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2
VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2
VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2
VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2
VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR EQU VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2
VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR EQU VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO
VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR EQU VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO
VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR EQU VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO
VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR EQU VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO
VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR EQU VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO
VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR EQU VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO
VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR EQU VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES
VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO
VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO
VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES
VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO
VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO
VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR EQU VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO
VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES
VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES
VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO
VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES
VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES
VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO
VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO
VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES
VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR EQU VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS
VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR EQU VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO
VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR EQU VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2
VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR EQU VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2
VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR EQU VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2
VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR EQU VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2
VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR EQU VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR EQU VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR EQU VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO
VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR EQU VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO
VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR EQU VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES
VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES
VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR EQU VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO
VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR EQU VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO
VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR EQU VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES
VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR EQU VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT
VK_STRUCTURE_TYPE_BEGIN_RANGE           EQU VK_STRUCTURE_TYPE_APPLICATION_INFO
VK_STRUCTURE_TYPE_END_RANGE             EQU VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO
VK_STRUCTURE_TYPE_RANGE_SIZE            EQU (VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO - VK_STRUCTURE_TYPE_APPLICATION_INFO + 1)
VK_STRUCTURE_TYPE_MAX_ENUM              EQU 7FFFFFFFh

; VkSystemAllocationScope
VK_SYSTEM_ALLOCATION_SCOPE_COMMAND      EQU 0
VK_SYSTEM_ALLOCATION_SCOPE_OBJECT       EQU 1
VK_SYSTEM_ALLOCATION_SCOPE_CACHE        EQU 2
VK_SYSTEM_ALLOCATION_SCOPE_DEVICE       EQU 3
VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE     EQU 4
VK_SYSTEM_ALLOCATION_SCOPE_BEGIN_RANGE  EQU VK_SYSTEM_ALLOCATION_SCOPE_COMMAND
VK_SYSTEM_ALLOCATION_SCOPE_END_RANGE    EQU VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE
VK_SYSTEM_ALLOCATION_SCOPE_RANGE_SIZE   EQU (VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE - VK_SYSTEM_ALLOCATION_SCOPE_COMMAND + 1)
VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM     EQU 7FFFFFFFh


; VkInternalAllocationType
VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE  EQU 0
VK_INTERNAL_ALLOCATION_TYPE_BEGIN_RANGE EQU VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE
VK_INTERNAL_ALLOCATION_TYPE_END_RANGE   EQU VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE
VK_INTERNAL_ALLOCATION_TYPE_RANGE_SIZE  EQU (VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE - VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE + 1)
VK_INTERNAL_ALLOCATION_TYPE_MAX_ENUM    EQU 7FFFFFFFh


; VkFormat
VK_FORMAT_UNDEFINED                     EQU 0
VK_FORMAT_R4G4_UNORM_PACK8              EQU 1
VK_FORMAT_R4G4B4A4_UNORM_PACK16         EQU 2
VK_FORMAT_B4G4R4A4_UNORM_PACK16         EQU 3
VK_FORMAT_R5G6B5_UNORM_PACK16           EQU 4
VK_FORMAT_B5G6R5_UNORM_PACK16           EQU 5
VK_FORMAT_R5G5B5A1_UNORM_PACK16         EQU 6
VK_FORMAT_B5G5R5A1_UNORM_PACK16         EQU 7
VK_FORMAT_A1R5G5B5_UNORM_PACK16         EQU 8
VK_FORMAT_R8_UNORM                      EQU 9
VK_FORMAT_R8_SNORM                      EQU 10
VK_FORMAT_R8_USCALED                    EQU 11
VK_FORMAT_R8_SSCALED                    EQU 12
VK_FORMAT_R8_UINT                       EQU 13
VK_FORMAT_R8_SINT                       EQU 14
VK_FORMAT_R8_SRGB                       EQU 15
VK_FORMAT_R8G8_UNORM                    EQU 16
VK_FORMAT_R8G8_SNORM                    EQU 17
VK_FORMAT_R8G8_USCALED                  EQU 18
VK_FORMAT_R8G8_SSCALED                  EQU 19
VK_FORMAT_R8G8_UINT                     EQU 20
VK_FORMAT_R8G8_SINT                     EQU 21
VK_FORMAT_R8G8_SRGB                     EQU 22
VK_FORMAT_R8G8B8_UNORM                  EQU 23
VK_FORMAT_R8G8B8_SNORM                  EQU 24
VK_FORMAT_R8G8B8_USCALED                EQU 25
VK_FORMAT_R8G8B8_SSCALED                EQU 26
VK_FORMAT_R8G8B8_UINT                   EQU 27
VK_FORMAT_R8G8B8_SINT                   EQU 28
VK_FORMAT_R8G8B8_SRGB                   EQU 29
VK_FORMAT_B8G8R8_UNORM                  EQU 30
VK_FORMAT_B8G8R8_SNORM                  EQU 31
VK_FORMAT_B8G8R8_USCALED                EQU 32
VK_FORMAT_B8G8R8_SSCALED                EQU 33
VK_FORMAT_B8G8R8_UINT                   EQU 34
VK_FORMAT_B8G8R8_SINT                   EQU 35
VK_FORMAT_B8G8R8_SRGB                   EQU 36
VK_FORMAT_R8G8B8A8_UNORM                EQU 37
VK_FORMAT_R8G8B8A8_SNORM                EQU 38
VK_FORMAT_R8G8B8A8_USCALED              EQU 39
VK_FORMAT_R8G8B8A8_SSCALED              EQU 40
VK_FORMAT_R8G8B8A8_UINT                 EQU 41
VK_FORMAT_R8G8B8A8_SINT                 EQU 42
VK_FORMAT_R8G8B8A8_SRGB                 EQU 43
VK_FORMAT_B8G8R8A8_UNORM                EQU 44
VK_FORMAT_B8G8R8A8_SNORM                EQU 45
VK_FORMAT_B8G8R8A8_USCALED              EQU 46
VK_FORMAT_B8G8R8A8_SSCALED              EQU 47
VK_FORMAT_B8G8R8A8_UINT                 EQU 48
VK_FORMAT_B8G8R8A8_SINT                 EQU 49
VK_FORMAT_B8G8R8A8_SRGB                 EQU 50
VK_FORMAT_A8B8G8R8_UNORM_PACK32         EQU 51
VK_FORMAT_A8B8G8R8_SNORM_PACK32         EQU 52
VK_FORMAT_A8B8G8R8_USCALED_PACK32       EQU 53
VK_FORMAT_A8B8G8R8_SSCALED_PACK32       EQU 54
VK_FORMAT_A8B8G8R8_UINT_PACK32          EQU 55
VK_FORMAT_A8B8G8R8_SINT_PACK32          EQU 56
VK_FORMAT_A8B8G8R8_SRGB_PACK32          EQU 57
VK_FORMAT_A2R10G10B10_UNORM_PACK32      EQU 58
VK_FORMAT_A2R10G10B10_SNORM_PACK32      EQU 59
VK_FORMAT_A2R10G10B10_USCALED_PACK32    EQU 60
VK_FORMAT_A2R10G10B10_SSCALED_PACK32    EQU 61
VK_FORMAT_A2R10G10B10_UINT_PACK32       EQU 62
VK_FORMAT_A2R10G10B10_SINT_PACK32       EQU 63
VK_FORMAT_A2B10G10R10_UNORM_PACK32      EQU 64
VK_FORMAT_A2B10G10R10_SNORM_PACK32      EQU 65
VK_FORMAT_A2B10G10R10_USCALED_PACK32    EQU 66
VK_FORMAT_A2B10G10R10_SSCALED_PACK32    EQU 67
VK_FORMAT_A2B10G10R10_UINT_PACK32       EQU 68
VK_FORMAT_A2B10G10R10_SINT_PACK32       EQU 69
VK_FORMAT_R16_UNORM                     EQU 70
VK_FORMAT_R16_SNORM                     EQU 71
VK_FORMAT_R16_USCALED                   EQU 72
VK_FORMAT_R16_SSCALED                   EQU 73
VK_FORMAT_R16_UINT                      EQU 74
VK_FORMAT_R16_SINT                      EQU 75
VK_FORMAT_R16_SFLOAT                    EQU 76
VK_FORMAT_R16G16_UNORM                  EQU 77
VK_FORMAT_R16G16_SNORM                  EQU 78
VK_FORMAT_R16G16_USCALED                EQU 79
VK_FORMAT_R16G16_SSCALED                EQU 80
VK_FORMAT_R16G16_UINT                   EQU 81
VK_FORMAT_R16G16_SINT                   EQU 82
VK_FORMAT_R16G16_SFLOAT                 EQU 83
VK_FORMAT_R16G16B16_UNORM               EQU 84
VK_FORMAT_R16G16B16_SNORM               EQU 85
VK_FORMAT_R16G16B16_USCALED             EQU 86
VK_FORMAT_R16G16B16_SSCALED             EQU 87
VK_FORMAT_R16G16B16_UINT                EQU 88
VK_FORMAT_R16G16B16_SINT                EQU 89
VK_FORMAT_R16G16B16_SFLOAT              EQU 90
VK_FORMAT_R16G16B16A16_UNORM            EQU 91
VK_FORMAT_R16G16B16A16_SNORM            EQU 92
VK_FORMAT_R16G16B16A16_USCALED          EQU 93
VK_FORMAT_R16G16B16A16_SSCALED          EQU 94
VK_FORMAT_R16G16B16A16_UINT             EQU 95
VK_FORMAT_R16G16B16A16_SINT             EQU 96
VK_FORMAT_R16G16B16A16_SFLOAT           EQU 97
VK_FORMAT_R32_UINT                      EQU 98
VK_FORMAT_R32_SINT                      EQU 99
VK_FORMAT_R32_SFLOAT                    EQU 100
VK_FORMAT_R32G32_UINT                   EQU 101
VK_FORMAT_R32G32_SINT                   EQU 102
VK_FORMAT_R32G32_SFLOAT                 EQU 103
VK_FORMAT_R32G32B32_UINT                EQU 104
VK_FORMAT_R32G32B32_SINT                EQU 105
VK_FORMAT_R32G32B32_SFLOAT              EQU 106
VK_FORMAT_R32G32B32A32_UINT             EQU 107
VK_FORMAT_R32G32B32A32_SINT             EQU 108
VK_FORMAT_R32G32B32A32_SFLOAT           EQU 109
VK_FORMAT_R64_UINT                      EQU 110
VK_FORMAT_R64_SINT                      EQU 111
VK_FORMAT_R64_SFLOAT                    EQU 112
VK_FORMAT_R64G64_UINT                   EQU 113
VK_FORMAT_R64G64_SINT                   EQU 114
VK_FORMAT_R64G64_SFLOAT                 EQU 115
VK_FORMAT_R64G64B64_UINT                EQU 116
VK_FORMAT_R64G64B64_SINT                EQU 117
VK_FORMAT_R64G64B64_SFLOAT              EQU 118
VK_FORMAT_R64G64B64A64_UINT             EQU 119
VK_FORMAT_R64G64B64A64_SINT             EQU 120
VK_FORMAT_R64G64B64A64_SFLOAT           EQU 121
VK_FORMAT_B10G11R11_UFLOAT_PACK32       EQU 122
VK_FORMAT_E5B9G9R9_UFLOAT_PACK32        EQU 123
VK_FORMAT_D16_UNORM                     EQU 124
VK_FORMAT_X8_D24_UNORM_PACK32           EQU 125
VK_FORMAT_D32_SFLOAT                    EQU 126
VK_FORMAT_S8_UINT                       EQU 127
VK_FORMAT_D16_UNORM_S8_UINT             EQU 128
VK_FORMAT_D24_UNORM_S8_UINT             EQU 129
VK_FORMAT_D32_SFLOAT_S8_UINT            EQU 130
VK_FORMAT_BC1_RGB_UNORM_BLOCK           EQU 131
VK_FORMAT_BC1_RGB_SRGB_BLOCK            EQU 132
VK_FORMAT_BC1_RGBA_UNORM_BLOCK          EQU 133
VK_FORMAT_BC1_RGBA_SRGB_BLOCK           EQU 134
VK_FORMAT_BC2_UNORM_BLOCK               EQU 135
VK_FORMAT_BC2_SRGB_BLOCK                EQU 136
VK_FORMAT_BC3_UNORM_BLOCK               EQU 137
VK_FORMAT_BC3_SRGB_BLOCK                EQU 138
VK_FORMAT_BC4_UNORM_BLOCK               EQU 139
VK_FORMAT_BC4_SNORM_BLOCK               EQU 140
VK_FORMAT_BC5_UNORM_BLOCK               EQU 141
VK_FORMAT_BC5_SNORM_BLOCK               EQU 142
VK_FORMAT_BC6H_UFLOAT_BLOCK             EQU 143
VK_FORMAT_BC6H_SFLOAT_BLOCK             EQU 144
VK_FORMAT_BC7_UNORM_BLOCK               EQU 145
VK_FORMAT_BC7_SRGB_BLOCK                EQU 146
VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK       EQU 147
VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK        EQU 148
VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK     EQU 149
VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK      EQU 150
VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK     EQU 151
VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK      EQU 152
VK_FORMAT_EAC_R11_UNORM_BLOCK           EQU 153
VK_FORMAT_EAC_R11_SNORM_BLOCK           EQU 154
VK_FORMAT_EAC_R11G11_UNORM_BLOCK        EQU 155
VK_FORMAT_EAC_R11G11_SNORM_BLOCK        EQU 156
VK_FORMAT_ASTC_4x4_UNORM_BLOCK          EQU 157
VK_FORMAT_ASTC_4x4_SRGB_BLOCK           EQU 158
VK_FORMAT_ASTC_5x4_UNORM_BLOCK          EQU 159
VK_FORMAT_ASTC_5x4_SRGB_BLOCK           EQU 160
VK_FORMAT_ASTC_5x5_UNORM_BLOCK          EQU 161
VK_FORMAT_ASTC_5x5_SRGB_BLOCK           EQU 162
VK_FORMAT_ASTC_6x5_UNORM_BLOCK          EQU 163
VK_FORMAT_ASTC_6x5_SRGB_BLOCK           EQU 164
VK_FORMAT_ASTC_6x6_UNORM_BLOCK          EQU 165
VK_FORMAT_ASTC_6x6_SRGB_BLOCK           EQU 166
VK_FORMAT_ASTC_8x5_UNORM_BLOCK          EQU 167
VK_FORMAT_ASTC_8x5_SRGB_BLOCK           EQU 168
VK_FORMAT_ASTC_8x6_UNORM_BLOCK          EQU 169
VK_FORMAT_ASTC_8x6_SRGB_BLOCK           EQU 170
VK_FORMAT_ASTC_8x8_UNORM_BLOCK          EQU 171
VK_FORMAT_ASTC_8x8_SRGB_BLOCK           EQU 172
VK_FORMAT_ASTC_10x5_UNORM_BLOCK         EQU 173
VK_FORMAT_ASTC_10x5_SRGB_BLOCK          EQU 174
VK_FORMAT_ASTC_10x6_UNORM_BLOCK         EQU 175
VK_FORMAT_ASTC_10x6_SRGB_BLOCK          EQU 176
VK_FORMAT_ASTC_10x8_UNORM_BLOCK         EQU 177
VK_FORMAT_ASTC_10x8_SRGB_BLOCK          EQU 178
VK_FORMAT_ASTC_10x10_UNORM_BLOCK        EQU 179
VK_FORMAT_ASTC_10x10_SRGB_BLOCK         EQU 180
VK_FORMAT_ASTC_12x10_UNORM_BLOCK        EQU 181
VK_FORMAT_ASTC_12x10_SRGB_BLOCK         EQU 182
VK_FORMAT_ASTC_12x12_UNORM_BLOCK        EQU 183
VK_FORMAT_ASTC_12x12_SRGB_BLOCK         EQU 184
VK_FORMAT_G8B8G8R8_422_UNORM            EQU 1000156000
VK_FORMAT_B8G8R8G8_422_UNORM            EQU 1000156001
VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM     EQU 1000156002
VK_FORMAT_G8_B8R8_2PLANE_420_UNORM      EQU 1000156003
VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM     EQU 1000156004
VK_FORMAT_G8_B8R8_2PLANE_422_UNORM      EQU 1000156005
VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM     EQU 1000156006
VK_FORMAT_R10X6_UNORM_PACK16            EQU 1000156007
VK_FORMAT_R10X6G10X6_UNORM_2PACK16      EQU 1000156008
VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 EQU 1000156009
VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 EQU 1000156010
VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 EQU 1000156011
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 EQU 1000156012
VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 EQU 1000156013
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 EQU 1000156014
VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 EQU 1000156015
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 EQU 1000156016
VK_FORMAT_R12X4_UNORM_PACK16            EQU 1000156017
VK_FORMAT_R12X4G12X4_UNORM_2PACK16      EQU 1000156018
VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 EQU 1000156019
VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 EQU 1000156020
VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 EQU 1000156021
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 EQU 1000156022
VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 EQU 1000156023
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 EQU 1000156024
VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 EQU 1000156025
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 EQU 1000156026
VK_FORMAT_G16B16G16R16_422_UNORM        EQU 1000156027
VK_FORMAT_B16G16R16G16_422_UNORM        EQU 1000156028
VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM  EQU 1000156029
VK_FORMAT_G16_B16R16_2PLANE_420_UNORM   EQU 1000156030
VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM  EQU 1000156031
VK_FORMAT_G16_B16R16_2PLANE_422_UNORM   EQU 1000156032
VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM  EQU 1000156033
VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG   EQU 1000054000
VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG   EQU 1000054001
VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG   EQU 1000054002
VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG   EQU 1000054003
VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG    EQU 1000054004
VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG    EQU 1000054005
VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG    EQU 1000054006
VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG    EQU 1000054007
VK_FORMAT_G8B8G8R8_422_UNORM_KHR        EQU VK_FORMAT_G8B8G8R8_422_UNORM
VK_FORMAT_B8G8R8G8_422_UNORM_KHR        EQU VK_FORMAT_B8G8R8G8_422_UNORM
VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR EQU VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM
VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR  EQU VK_FORMAT_G8_B8R8_2PLANE_420_UNORM
VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR EQU VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM
VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR  EQU VK_FORMAT_G8_B8R8_2PLANE_422_UNORM
VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR EQU VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM
VK_FORMAT_R10X6_UNORM_PACK16_KHR        EQU VK_FORMAT_R10X6_UNORM_PACK16
VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR  EQU VK_FORMAT_R10X6G10X6_UNORM_2PACK16
VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR EQU VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16
VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR EQU VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16
VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR EQU VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR EQU VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16
VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR EQU VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR EQU VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16
VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR EQU VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16
VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR EQU VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16
VK_FORMAT_R12X4_UNORM_PACK16_KHR       EQU VK_FORMAT_R12X4_UNORM_PACK16
VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR EQU VK_FORMAT_R12X4G12X4_UNORM_2PACK16
VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR EQU VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16
VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR EQU VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16
VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR EQU VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR EQU VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16
VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR EQU VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR EQU VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16
VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR EQU VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16
VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR EQU VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16
VK_FORMAT_G16B16G16R16_422_UNORM_KHR    EQU VK_FORMAT_G16B16G16R16_422_UNORM
VK_FORMAT_B16G16R16G16_422_UNORM_KHR    EQU VK_FORMAT_B16G16R16G16_422_UNORM
VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR EQU VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM
VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR EQU VK_FORMAT_G16_B16R16_2PLANE_420_UNORM
VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR EQU VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM
VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR EQU VK_FORMAT_G16_B16R16_2PLANE_422_UNORM
VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR EQU VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM
VK_FORMAT_BEGIN_RANGE                   EQU VK_FORMAT_UNDEFINED
VK_FORMAT_END_RANGE                     EQU VK_FORMAT_ASTC_12x12_SRGB_BLOCK
VK_FORMAT_RANGE_SIZE                    EQU (VK_FORMAT_ASTC_12x12_SRGB_BLOCK - VK_FORMAT_UNDEFINED + 1)
VK_FORMAT_MAX_ENUM                      EQU 7FFFFFFFh


; VkImageType
VK_IMAGE_TYPE_1D                        EQU 0
VK_IMAGE_TYPE_2D                        EQU 1
VK_IMAGE_TYPE_3D                        EQU 2
VK_IMAGE_TYPE_BEGIN_RANGE               EQU VK_IMAGE_TYPE_1D
VK_IMAGE_TYPE_END_RANGE                 EQU VK_IMAGE_TYPE_3D
VK_IMAGE_TYPE_RANGE_SIZE                EQU (VK_IMAGE_TYPE_3D - VK_IMAGE_TYPE_1D + 1)
VK_IMAGE_TYPE_MAX_ENUM                  EQU 7FFFFFFFh

; VkImageTiling
VK_IMAGE_TILING_OPTIMAL                 EQU 0
VK_IMAGE_TILING_LINEAR                  EQU 1
VK_IMAGE_TILING_BEGIN_RANGE             EQU VK_IMAGE_TILING_OPTIMAL
VK_IMAGE_TILING_END_RANGE               EQU VK_IMAGE_TILING_LINEAR
VK_IMAGE_TILING_RANGE_SIZE              EQU (VK_IMAGE_TILING_LINEAR - VK_IMAGE_TILING_OPTIMAL + 1)
VK_IMAGE_TILING_MAX_ENUM                EQU 7FFFFFFFh

; VkPhysicalDeviceType
VK_PHYSICAL_DEVICE_TYPE_OTHER           EQU 0
VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU  EQU 1
VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU    EQU 2
VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU     EQU 3
VK_PHYSICAL_DEVICE_TYPE_CPU             EQU 4
VK_PHYSICAL_DEVICE_TYPE_BEGIN_RANGE     EQU VK_PHYSICAL_DEVICE_TYPE_OTHER
VK_PHYSICAL_DEVICE_TYPE_END_RANGE       EQU VK_PHYSICAL_DEVICE_TYPE_CPU
VK_PHYSICAL_DEVICE_TYPE_RANGE_SIZE      EQU (VK_PHYSICAL_DEVICE_TYPE_CPU - VK_PHYSICAL_DEVICE_TYPE_OTHER + 1)
VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM        EQU 7FFFFFFFh

; VkQueryType
VK_QUERY_TYPE_OCCLUSION                 EQU 0
VK_QUERY_TYPE_PIPELINE_STATISTICS       EQU 1
VK_QUERY_TYPE_TIMESTAMP                 EQU 2
VK_QUERY_TYPE_BEGIN_RANGE               EQU VK_QUERY_TYPE_OCCLUSION
VK_QUERY_TYPE_END_RANGE                 EQU VK_QUERY_TYPE_TIMESTAMP
VK_QUERY_TYPE_RANGE_SIZE                EQU (VK_QUERY_TYPE_TIMESTAMP - VK_QUERY_TYPE_OCCLUSION + 1)
VK_QUERY_TYPE_MAX_ENUM                  EQU 7FFFFFFFh

; VkSharingMode
VK_SHARING_MODE_EXCLUSIVE               EQU 0
VK_SHARING_MODE_CONCURRENT              EQU 1
VK_SHARING_MODE_BEGIN_RANGE             EQU VK_SHARING_MODE_EXCLUSIVE
VK_SHARING_MODE_END_RANGE               EQU VK_SHARING_MODE_CONCURRENT
VK_SHARING_MODE_RANGE_SIZE              EQU (VK_SHARING_MODE_CONCURRENT - VK_SHARING_MODE_EXCLUSIVE + 1)
VK_SHARING_MODE_MAX_ENUM                EQU 7FFFFFFFh
    
    
; VkImageLayout
VK_IMAGE_LAYOUT_UNDEFINED               EQU 0
VK_IMAGE_LAYOUT_GENERAL                 EQU 1
VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL EQU 2
VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL EQU 3
VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL EQU 4
VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL EQU 5
VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL    EQU 6
VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL    EQU 7
VK_IMAGE_LAYOUT_PREINITIALIZED          EQU 8
VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL EQU 1000117000
VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL EQU 1000117001
VK_IMAGE_LAYOUT_PRESENT_SRC_KHR         EQU 1000001002
VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR      EQU 1000111000
VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR EQU VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL
VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR EQU VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL
VK_IMAGE_LAYOUT_BEGIN_RANGE             EQU VK_IMAGE_LAYOUT_UNDEFINED
VK_IMAGE_LAYOUT_END_RANGE               EQU VK_IMAGE_LAYOUT_PREINITIALIZED
VK_IMAGE_LAYOUT_RANGE_SIZE              EQU (VK_IMAGE_LAYOUT_PREINITIALIZED - VK_IMAGE_LAYOUT_UNDEFINED + 1)
VK_IMAGE_LAYOUT_MAX_ENUM                EQU 7FFFFFFFh  
    
    
; VkImageViewType
VK_IMAGE_VIEW_TYPE_1D                   EQU 0
VK_IMAGE_VIEW_TYPE_2D                   EQU 1
VK_IMAGE_VIEW_TYPE_3D                   EQU 2
VK_IMAGE_VIEW_TYPE_CUBE                 EQU 3
VK_IMAGE_VIEW_TYPE_1D_ARRAY             EQU 4
VK_IMAGE_VIEW_TYPE_2D_ARRAY             EQU 5
VK_IMAGE_VIEW_TYPE_CUBE_ARRAY           EQU 6
VK_IMAGE_VIEW_TYPE_BEGIN_RANGE          EQU VK_IMAGE_VIEW_TYPE_1D
VK_IMAGE_VIEW_TYPE_END_RANGE            EQU VK_IMAGE_VIEW_TYPE_CUBE_ARRAY
VK_IMAGE_VIEW_TYPE_RANGE_SIZE           EQU (VK_IMAGE_VIEW_TYPE_CUBE_ARRAY - VK_IMAGE_VIEW_TYPE_1D + 1)
VK_IMAGE_VIEW_TYPE_MAX_ENUM             EQU 7FFFFFFFh    
    
; VkComponentSwizzle
VK_COMPONENT_SWIZZLE_IDENTITY           EQU 0
VK_COMPONENT_SWIZZLE_ZERO               EQU 1
VK_COMPONENT_SWIZZLE_ONE                EQU 2
VK_COMPONENT_SWIZZLE_R                  EQU 3
VK_COMPONENT_SWIZZLE_G                  EQU 4
VK_COMPONENT_SWIZZLE_B                  EQU 5
VK_COMPONENT_SWIZZLE_A                  EQU 6
VK_COMPONENT_SWIZZLE_BEGIN_RANGE        EQU VK_COMPONENT_SWIZZLE_IDENTITY
VK_COMPONENT_SWIZZLE_END_RANGE          EQU VK_COMPONENT_SWIZZLE_A
VK_COMPONENT_SWIZZLE_RANGE_SIZE         EQU (VK_COMPONENT_SWIZZLE_A - VK_COMPONENT_SWIZZLE_IDENTITY + 1)
VK_COMPONENT_SWIZZLE_MAX_ENUM           EQU 7FFFFFFFh  


; VkVertexInputRate
VK_VERTEX_INPUT_RATE_VERTEX             EQU 0
VK_VERTEX_INPUT_RATE_INSTANCE           EQU 1
VK_VERTEX_INPUT_RATE_BEGIN_RANGE        EQU VK_VERTEX_INPUT_RATE_VERTEX
VK_VERTEX_INPUT_RATE_END_RANGE          EQU VK_VERTEX_INPUT_RATE_INSTANCE
VK_VERTEX_INPUT_RATE_RANGE_SIZE         EQU (VK_VERTEX_INPUT_RATE_INSTANCE - VK_VERTEX_INPUT_RATE_VERTEX + 1)
VK_VERTEX_INPUT_RATE_MAX_ENUM           EQU 7FFFFFFFh 


; VkPrimitiveTopology
VK_PRIMITIVE_TOPOLOGY_POINT_LIST        EQU 0
VK_PRIMITIVE_TOPOLOGY_LINE_LIST         EQU 1
VK_PRIMITIVE_TOPOLOGY_LINE_STRIP        EQU 2
VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST     EQU 3
VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP    EQU 4
VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN      EQU 5
VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY EQU 6
VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY EQU 7
VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY EQU 8
VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY EQU 9
VK_PRIMITIVE_TOPOLOGY_PATCH_LIST        EQU 10
VK_PRIMITIVE_TOPOLOGY_BEGIN_RANGE       EQU VK_PRIMITIVE_TOPOLOGY_POINT_LIST
VK_PRIMITIVE_TOPOLOGY_END_RANGE         EQU VK_PRIMITIVE_TOPOLOGY_PATCH_LIST
VK_PRIMITIVE_TOPOLOGY_RANGE_SIZE        EQU (VK_PRIMITIVE_TOPOLOGY_PATCH_LIST - VK_PRIMITIVE_TOPOLOGY_POINT_LIST + 1)
VK_PRIMITIVE_TOPOLOGY_MAX_ENUM          EQU 7FFFFFFFh  

; VkPolygonMode
VK_POLYGON_MODE_FILL                    EQU 0
VK_POLYGON_MODE_LINE                    EQU 1
VK_POLYGON_MODE_POINT                   EQU 2
VK_POLYGON_MODE_FILL_RECTANGLE_NV       EQU 1000153000
VK_POLYGON_MODE_BEGIN_RANGE             EQU VK_POLYGON_MODE_FILL
VK_POLYGON_MODE_END_RANGE               EQU VK_POLYGON_MODE_POINT
VK_POLYGON_MODE_RANGE_SIZE              EQU (VK_POLYGON_MODE_POINT - VK_POLYGON_MODE_FILL + 1)
VK_POLYGON_MODE_MAX_ENUM                EQU 7FFFFFFFh  

; VkFrontFace
VK_FRONT_FACE_COUNTER_CLOCKWISE         EQU 0
VK_FRONT_FACE_CLOCKWISE                 EQU 1
VK_FRONT_FACE_BEGIN_RANGE               EQU VK_FRONT_FACE_COUNTER_CLOCKWISE
VK_FRONT_FACE_END_RANGE                 EQU VK_FRONT_FACE_CLOCKWISE
VK_FRONT_FACE_RANGE_SIZE                EQU (VK_FRONT_FACE_CLOCKWISE - VK_FRONT_FACE_COUNTER_CLOCKWISE + 1)
VK_FRONT_FACE_MAX_ENUM                  EQU 7FFFFFFFh 

; VkCompareOp
VK_COMPARE_OP_NEVER                     EQU 0
VK_COMPARE_OP_LESS                      EQU 1
VK_COMPARE_OP_EQUAL                     EQU 2
VK_COMPARE_OP_LESS_OR_EQUAL             EQU 3
VK_COMPARE_OP_GREATER                   EQU 4
VK_COMPARE_OP_NOT_EQUAL                 EQU 5
VK_COMPARE_OP_GREATER_OR_EQUAL          EQU 6
VK_COMPARE_OP_ALWAYS                    EQU 7
VK_COMPARE_OP_BEGIN_RANGE               EQU VK_COMPARE_OP_NEVER
VK_COMPARE_OP_END_RANGE                 EQU VK_COMPARE_OP_ALWAYS
VK_COMPARE_OP_RANGE_SIZE                EQU (VK_COMPARE_OP_ALWAYS - VK_COMPARE_OP_NEVER + 1)
VK_COMPARE_OP_MAX_ENUM                  EQU 7FFFFFFFh   

; VkStencilOp
VK_STENCIL_OP_KEEP                      EQU 0
VK_STENCIL_OP_ZERO                      EQU 1
VK_STENCIL_OP_REPLACE                   EQU 2
VK_STENCIL_OP_INCREMENT_AND_CLAMP       EQU 3
VK_STENCIL_OP_DECREMENT_AND_CLAMP       EQU 4
VK_STENCIL_OP_INVERT                    EQU 5
VK_STENCIL_OP_INCREMENT_AND_WRAP        EQU 6
VK_STENCIL_OP_DECREMENT_AND_WRAP        EQU 7
VK_STENCIL_OP_BEGIN_RANGE               EQU VK_STENCIL_OP_KEEP
VK_STENCIL_OP_END_RANGE                 EQU VK_STENCIL_OP_DECREMENT_AND_WRAP
VK_STENCIL_OP_RANGE_SIZE                EQU (VK_STENCIL_OP_DECREMENT_AND_WRAP - VK_STENCIL_OP_KEEP + 1)
VK_STENCIL_OP_MAX_ENUM                  EQU 7FFFFFFFh  

; VkLogicOp
VK_LOGIC_OP_CLEAR                       EQU 0
VK_LOGIC_OP_AND                         EQU 1
VK_LOGIC_OP_AND_REVERSE                 EQU 2
VK_LOGIC_OP_COPY                        EQU 3
VK_LOGIC_OP_AND_INVERTED                EQU 4
VK_LOGIC_OP_NO_OP                       EQU 5
VK_LOGIC_OP_XOR                         EQU 6
VK_LOGIC_OP_OR                          EQU 7
VK_LOGIC_OP_NOR                         EQU 8
VK_LOGIC_OP_EQUIVALENT                  EQU 9
VK_LOGIC_OP_INVERT                      EQU 10
VK_LOGIC_OP_OR_REVERSE                  EQU 11
VK_LOGIC_OP_COPY_INVERTED               EQU 12
VK_LOGIC_OP_OR_INVERTED                 EQU 13
VK_LOGIC_OP_NAND                        EQU 14
VK_LOGIC_OP_SET                         EQU 15
VK_LOGIC_OP_BEGIN_RANGE                 EQU VK_LOGIC_OP_CLEAR
VK_LOGIC_OP_END_RANGE                   EQU VK_LOGIC_OP_SET
VK_LOGIC_OP_RANGE_SIZE                  EQU (VK_LOGIC_OP_SET - VK_LOGIC_OP_CLEAR + 1)
VK_LOGIC_OP_MAX_ENUM                    EQU 7FFFFFFFh   

; VkBlendFactor
VK_BLEND_FACTOR_ZERO                    EQU 0
VK_BLEND_FACTOR_ONE                     EQU 1
VK_BLEND_FACTOR_SRC_COLOR               EQU 2
VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR     EQU 3
VK_BLEND_FACTOR_DST_COLOR               EQU 4
VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR     EQU 5
VK_BLEND_FACTOR_SRC_ALPHA               EQU 6
VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA     EQU 7
VK_BLEND_FACTOR_DST_ALPHA               EQU 8
VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA     EQU 9
VK_BLEND_FACTOR_CONSTANT_COLOR          EQU 10
VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR EQU 11
VK_BLEND_FACTOR_CONSTANT_ALPHA          EQU 12
VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA EQU 13
VK_BLEND_FACTOR_SRC_ALPHA_SATURATE      EQU 14
VK_BLEND_FACTOR_SRC1_COLOR              EQU 15
VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR    EQU 16
VK_BLEND_FACTOR_SRC1_ALPHA              EQU 17
VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA    EQU 18
VK_BLEND_FACTOR_BEGIN_RANGE             EQU VK_BLEND_FACTOR_ZERO
VK_BLEND_FACTOR_END_RANGE               EQU VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA
VK_BLEND_FACTOR_RANGE_SIZE              EQU (VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA - VK_BLEND_FACTOR_ZERO + 1)
VK_BLEND_FACTOR_MAX_ENUM                EQU 7FFFFFFFh  

; VkBlendOp
VK_BLEND_OP_ADD                         EQU 0
VK_BLEND_OP_SUBTRACT                    EQU 1
VK_BLEND_OP_REVERSE_SUBTRACT            EQU 2
VK_BLEND_OP_MIN                         EQU 3
VK_BLEND_OP_MAX                         EQU 4
VK_BLEND_OP_ZERO_EXT                    EQU 1000148000
VK_BLEND_OP_SRC_EXT                     EQU 1000148001
VK_BLEND_OP_DST_EXT                     EQU 1000148002
VK_BLEND_OP_SRC_OVER_EXT                EQU 1000148003
VK_BLEND_OP_DST_OVER_EXT                EQU 1000148004
VK_BLEND_OP_SRC_IN_EXT                  EQU 1000148005
VK_BLEND_OP_DST_IN_EXT                  EQU 1000148006
VK_BLEND_OP_SRC_OUT_EXT                 EQU 1000148007
VK_BLEND_OP_DST_OUT_EXT                 EQU 1000148008
VK_BLEND_OP_SRC_ATOP_EXT                EQU 1000148009
VK_BLEND_OP_DST_ATOP_EXT                EQU 1000148010
VK_BLEND_OP_XOR_EXT                     EQU 1000148011
VK_BLEND_OP_MULTIPLY_EXT                EQU 1000148012
VK_BLEND_OP_SCREEN_EXT                  EQU 1000148013
VK_BLEND_OP_OVERLAY_EXT                 EQU 1000148014
VK_BLEND_OP_DARKEN_EXT                  EQU 1000148015
VK_BLEND_OP_LIGHTEN_EXT                 EQU 1000148016
VK_BLEND_OP_COLORDODGE_EXT              EQU 1000148017
VK_BLEND_OP_COLORBURN_EXT               EQU 1000148018
VK_BLEND_OP_HARDLIGHT_EXT               EQU 1000148019
VK_BLEND_OP_SOFTLIGHT_EXT               EQU 1000148020
VK_BLEND_OP_DIFFERENCE_EXT              EQU 1000148021
VK_BLEND_OP_EXCLUSION_EXT               EQU 1000148022
VK_BLEND_OP_INVERT_EXT                  EQU 1000148023
VK_BLEND_OP_INVERT_RGB_EXT              EQU 1000148024
VK_BLEND_OP_LINEARDODGE_EXT             EQU 1000148025
VK_BLEND_OP_LINEARBURN_EXT              EQU 1000148026
VK_BLEND_OP_VIVIDLIGHT_EXT              EQU 1000148027
VK_BLEND_OP_LINEARLIGHT_EXT             EQU 1000148028
VK_BLEND_OP_PINLIGHT_EXT                EQU 1000148029
VK_BLEND_OP_HARDMIX_EXT                 EQU 1000148030
VK_BLEND_OP_HSL_HUE_EXT                 EQU 1000148031
VK_BLEND_OP_HSL_SATURATION_EXT          EQU 1000148032
VK_BLEND_OP_HSL_COLOR_EXT               EQU 1000148033
VK_BLEND_OP_HSL_LUMINOSITY_EXT          EQU 1000148034
VK_BLEND_OP_PLUS_EXT                    EQU 1000148035
VK_BLEND_OP_PLUS_CLAMPED_EXT            EQU 1000148036
VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT      EQU 1000148037
VK_BLEND_OP_PLUS_DARKER_EXT             EQU 1000148038
VK_BLEND_OP_MINUS_EXT                   EQU 1000148039
VK_BLEND_OP_MINUS_CLAMPED_EXT           EQU 1000148040
VK_BLEND_OP_CONTRAST_EXT                EQU 1000148041
VK_BLEND_OP_INVERT_OVG_EXT              EQU 1000148042
VK_BLEND_OP_RED_EXT                     EQU 1000148043
VK_BLEND_OP_GREEN_EXT                   EQU 1000148044
VK_BLEND_OP_BLUE_EXT                    EQU 1000148045
VK_BLEND_OP_BEGIN_RANGE                 EQU VK_BLEND_OP_ADD
VK_BLEND_OP_END_RANGE                   EQU VK_BLEND_OP_MAX
VK_BLEND_OP_RANGE_SIZE                  EQU (VK_BLEND_OP_MAX - VK_BLEND_OP_ADD + 1)
VK_BLEND_OP_MAX_ENUM                    EQU 7FFFFFFFh 

; VkDynamicState
VK_DYNAMIC_STATE_VIEWPORT               EQU 0
VK_DYNAMIC_STATE_SCISSOR                EQU 1
VK_DYNAMIC_STATE_LINE_WIDTH             EQU 2
VK_DYNAMIC_STATE_DEPTH_BIAS             EQU 3
VK_DYNAMIC_STATE_BLEND_CONSTANTS        EQU 4
VK_DYNAMIC_STATE_DEPTH_BOUNDS           EQU 5
VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK   EQU 6
VK_DYNAMIC_STATE_STENCIL_WRITE_MASK     EQU 7
VK_DYNAMIC_STATE_STENCIL_REFERENCE      EQU 8
VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV  EQU 1000087000
VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT  EQU 1000099000
VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT   EQU 1000143000
VK_DYNAMIC_STATE_BEGIN_RANGE            EQU VK_DYNAMIC_STATE_VIEWPORT
VK_DYNAMIC_STATE_END_RANGE              EQU VK_DYNAMIC_STATE_STENCIL_REFERENCE
VK_DYNAMIC_STATE_RANGE_SIZE             EQU (VK_DYNAMIC_STATE_STENCIL_REFERENCE - VK_DYNAMIC_STATE_VIEWPORT + 1)
VK_DYNAMIC_STATE_MAX_ENUM               EQU 7FFFFFFFh

; VkFilter
VK_FILTER_NEAREST                       EQU 0
VK_FILTER_LINEAR                        EQU 1
VK_FILTER_CUBIC_IMG                     EQU 1000015000
VK_FILTER_BEGIN_RANGE                   EQU VK_FILTER_NEAREST
VK_FILTER_END_RANGE                     EQU VK_FILTER_LINEAR
VK_FILTER_RANGE_SIZE                    EQU (VK_FILTER_LINEAR - VK_FILTER_NEAREST + 1)
VK_FILTER_MAX_ENUM                      EQU 7FFFFFFFh

; VkSamplerMipmapMode
VK_SAMPLER_MIPMAP_MODE_NEAREST          EQU 0
VK_SAMPLER_MIPMAP_MODE_LINEAR           EQU 1
VK_SAMPLER_MIPMAP_MODE_BEGIN_RANGE      EQU VK_SAMPLER_MIPMAP_MODE_NEAREST
VK_SAMPLER_MIPMAP_MODE_END_RANGE        EQU VK_SAMPLER_MIPMAP_MODE_LINEAR
VK_SAMPLER_MIPMAP_MODE_RANGE_SIZE       EQU (VK_SAMPLER_MIPMAP_MODE_LINEAR - VK_SAMPLER_MIPMAP_MODE_NEAREST + 1)
VK_SAMPLER_MIPMAP_MODE_MAX_ENUM         EQU 7FFFFFFFh


; VkSamplerAddressMode
VK_SAMPLER_ADDRESS_MODE_REPEAT          EQU 0
VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT EQU 1
VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE   EQU 2
VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER EQU 3
VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE EQU 4
VK_SAMPLER_ADDRESS_MODE_BEGIN_RANGE     EQU VK_SAMPLER_ADDRESS_MODE_REPEAT
VK_SAMPLER_ADDRESS_MODE_END_RANGE       EQU VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER
VK_SAMPLER_ADDRESS_MODE_RANGE_SIZE      EQU (VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER - VK_SAMPLER_ADDRESS_MODE_REPEAT + 1)
VK_SAMPLER_ADDRESS_MODE_MAX_ENUM        EQU 7FFFFFFFh

; VkBorderColor
VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK EQU 0
VK_BORDER_COLOR_INT_TRANSPARENT_BLACK   EQU 1
VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK      EQU 2
VK_BORDER_COLOR_INT_OPAQUE_BLACK        EQU 3
VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE      EQU 4
VK_BORDER_COLOR_INT_OPAQUE_WHITE        EQU 5
VK_BORDER_COLOR_BEGIN_RANGE             EQU VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK
VK_BORDER_COLOR_END_RANGE               EQU VK_BORDER_COLOR_INT_OPAQUE_WHITE
VK_BORDER_COLOR_RANGE_SIZE              EQU (VK_BORDER_COLOR_INT_OPAQUE_WHITE - VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK + 1)
VK_BORDER_COLOR_MAX_ENUM                EQU 7FFFFFFFh

; VkDescriptorType
VK_DESCRIPTOR_TYPE_SAMPLER              EQU 0
VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER EQU 1
VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE        EQU 2
VK_DESCRIPTOR_TYPE_STORAGE_IMAGE        EQU 3
VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER EQU 4
VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER EQU 5
VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER       EQU 6
VK_DESCRIPTOR_TYPE_STORAGE_BUFFER       EQU 7
VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC EQU 8
VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC EQU 9
VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT     EQU 10
VK_DESCRIPTOR_TYPE_BEGIN_RANGE          EQU VK_DESCRIPTOR_TYPE_SAMPLER
VK_DESCRIPTOR_TYPE_END_RANGE            EQU VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT
VK_DESCRIPTOR_TYPE_RANGE_SIZE           EQU (VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT - VK_DESCRIPTOR_TYPE_SAMPLER + 1)
VK_DESCRIPTOR_TYPE_MAX_ENUM             EQU 7FFFFFFFh

; VkAttachmentLoadOp
VK_ATTACHMENT_LOAD_OP_LOAD              EQU 0
VK_ATTACHMENT_LOAD_OP_CLEAR             EQU 1
VK_ATTACHMENT_LOAD_OP_DONT_CARE         EQU 2
VK_ATTACHMENT_LOAD_OP_BEGIN_RANGE       EQU VK_ATTACHMENT_LOAD_OP_LOAD
VK_ATTACHMENT_LOAD_OP_END_RANGE         EQU VK_ATTACHMENT_LOAD_OP_DONT_CARE
VK_ATTACHMENT_LOAD_OP_RANGE_SIZE        EQU (VK_ATTACHMENT_LOAD_OP_DONT_CARE - VK_ATTACHMENT_LOAD_OP_LOAD + 1)
VK_ATTACHMENT_LOAD_OP_MAX_ENUM          EQU 7FFFFFFFh

; VkAttachmentStoreOp
VK_ATTACHMENT_STORE_OP_STORE            EQU 0
VK_ATTACHMENT_STORE_OP_DONT_CARE        EQU 1
VK_ATTACHMENT_STORE_OP_BEGIN_RANGE      EQU VK_ATTACHMENT_STORE_OP_STORE
VK_ATTACHMENT_STORE_OP_END_RANGE        EQU VK_ATTACHMENT_STORE_OP_DONT_CARE
VK_ATTACHMENT_STORE_OP_RANGE_SIZE       EQU (VK_ATTACHMENT_STORE_OP_DONT_CARE - VK_ATTACHMENT_STORE_OP_STORE + 1)
VK_ATTACHMENT_STORE_OP_MAX_ENUM         EQU 7FFFFFFFh

; VkPipelineBindPoint
VK_PIPELINE_BIND_POINT_GRAPHICS         EQU 0
VK_PIPELINE_BIND_POINT_COMPUTE          EQU 1
VK_PIPELINE_BIND_POINT_BEGIN_RANGE      EQU VK_PIPELINE_BIND_POINT_GRAPHICS
VK_PIPELINE_BIND_POINT_END_RANGE        EQU VK_PIPELINE_BIND_POINT_COMPUTE
VK_PIPELINE_BIND_POINT_RANGE_SIZE       EQU (VK_PIPELINE_BIND_POINT_COMPUTE - VK_PIPELINE_BIND_POINT_GRAPHICS + 1)
VK_PIPELINE_BIND_POINT_MAX_ENUM         EQU 7FFFFFFFh

; VkCommandBufferLevel
VK_COMMAND_BUFFER_LEVEL_PRIMARY         EQU 0
VK_COMMAND_BUFFER_LEVEL_SECONDARY       EQU 1
VK_COMMAND_BUFFER_LEVEL_BEGIN_RANGE     EQU VK_COMMAND_BUFFER_LEVEL_PRIMARY
VK_COMMAND_BUFFER_LEVEL_END_RANGE       EQU VK_COMMAND_BUFFER_LEVEL_SECONDARY
VK_COMMAND_BUFFER_LEVEL_RANGE_SIZE      EQU (VK_COMMAND_BUFFER_LEVEL_SECONDARY - VK_COMMAND_BUFFER_LEVEL_PRIMARY + 1)
VK_COMMAND_BUFFER_LEVEL_MAX_ENUM        EQU 7FFFFFFFh


; VkIndexType
VK_INDEX_TYPE_UINT16                    EQU 0
VK_INDEX_TYPE_UINT32                    EQU 1
VK_INDEX_TYPE_BEGIN_RANGE               EQU VK_INDEX_TYPE_UINT16
VK_INDEX_TYPE_END_RANGE                 EQU VK_INDEX_TYPE_UINT32
VK_INDEX_TYPE_RANGE_SIZE                EQU (VK_INDEX_TYPE_UINT32 - VK_INDEX_TYPE_UINT16 + 1)
VK_INDEX_TYPE_MAX_ENUM                  EQU 7FFFFFFFh

; VkSubpassContents
VK_SUBPASS_CONTENTS_INLINE              EQU 0
VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS EQU 1
VK_SUBPASS_CONTENTS_BEGIN_RANGE         EQU VK_SUBPASS_CONTENTS_INLINE
VK_SUBPASS_CONTENTS_END_RANGE           EQU VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS
VK_SUBPASS_CONTENTS_RANGE_SIZE          EQU (VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS - VK_SUBPASS_CONTENTS_INLINE + 1)
VK_SUBPASS_CONTENTS_MAX_ENUM            EQU 7FFFFFFFh

; VkObjectType
VK_OBJECT_TYPE_UNKNOWN                  EQU 0
VK_OBJECT_TYPE_INSTANCE                 EQU 1
VK_OBJECT_TYPE_PHYSICAL_DEVICE          EQU 2
VK_OBJECT_TYPE_DEVICE                   EQU 3
VK_OBJECT_TYPE_QUEUE                    EQU 4
VK_OBJECT_TYPE_SEMAPHORE                EQU 5
VK_OBJECT_TYPE_COMMAND_BUFFER           EQU 6
VK_OBJECT_TYPE_FENCE                    EQU 7
VK_OBJECT_TYPE_DEVICE_MEMORY            EQU 8
VK_OBJECT_TYPE_BUFFER                   EQU 9
VK_OBJECT_TYPE_IMAGE                    EQU 10
VK_OBJECT_TYPE_EVENT                    EQU 11
VK_OBJECT_TYPE_QUERY_POOL               EQU 12
VK_OBJECT_TYPE_BUFFER_VIEW              EQU 13
VK_OBJECT_TYPE_IMAGE_VIEW               EQU 14
VK_OBJECT_TYPE_SHADER_MODULE            EQU 15
VK_OBJECT_TYPE_PIPELINE_CACHE           EQU 16
VK_OBJECT_TYPE_PIPELINE_LAYOUT          EQU 17
VK_OBJECT_TYPE_RENDER_PASS              EQU 18
VK_OBJECT_TYPE_PIPELINE                 EQU 19
VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT    EQU 20
VK_OBJECT_TYPE_SAMPLER                  EQU 21
VK_OBJECT_TYPE_DESCRIPTOR_POOL          EQU 22
VK_OBJECT_TYPE_DESCRIPTOR_SET           EQU 23
VK_OBJECT_TYPE_FRAMEBUFFER              EQU 24
VK_OBJECT_TYPE_COMMAND_POOL             EQU 25
VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION EQU 1000156000
VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE EQU 1000085000
VK_OBJECT_TYPE_SURFACE_KHR              EQU 1000000000
VK_OBJECT_TYPE_SWAPCHAIN_KHR            EQU 1000001000
VK_OBJECT_TYPE_DISPLAY_KHR              EQU 1000002000
VK_OBJECT_TYPE_DISPLAY_MODE_KHR         EQU 1000002001
VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT EQU 1000011000
VK_OBJECT_TYPE_OBJECT_TABLE_NVX         EQU 1000086000
VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NVX EQU 1000086001
VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT EQU 1000128000
VK_OBJECT_TYPE_VALIDATION_CACHE_EXT     EQU 1000160000
VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR EQU VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE
VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR EQU VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION
VK_OBJECT_TYPE_BEGIN_RANGE              EQU VK_OBJECT_TYPE_UNKNOWN
VK_OBJECT_TYPE_END_RANGE                EQU VK_OBJECT_TYPE_COMMAND_POOL
VK_OBJECT_TYPE_RANGE_SIZE               EQU (VK_OBJECT_TYPE_COMMAND_POOL - VK_OBJECT_TYPE_UNKNOWN + 1)
VK_OBJECT_TYPE_MAX_ENUM                 EQU 7FFFFFFFh

; VkFormatFeatureFlagBits
VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT     EQU 00000001h
VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT     EQU 00000002h
VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT EQU 00000004h
VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT EQU 00000008h
VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT EQU 00000010h
VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT EQU 00000020h
VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT     EQU 00000040h
VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT  EQU 00000080h
VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT EQU 00000100h
VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT EQU 00000200h
VK_FORMAT_FEATURE_BLIT_SRC_BIT          EQU 00000400h
VK_FORMAT_FEATURE_BLIT_DST_BIT          EQU 00000800h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT EQU 00001000h
VK_FORMAT_FEATURE_TRANSFER_SRC_BIT      EQU 00004000h
VK_FORMAT_FEATURE_TRANSFER_DST_BIT      EQU 00008000h
VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT EQU 00020000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT EQU 00040000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT EQU 00080000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT EQU 00100000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT EQU 00200000h
VK_FORMAT_FEATURE_DISJOINT_BIT          EQU 00400000h
VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT EQU 00800000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG EQU 00002000h
VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT EQU 00010000h
VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR  EQU VK_FORMAT_FEATURE_TRANSFER_SRC_BIT
VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR  EQU VK_FORMAT_FEATURE_TRANSFER_DST_BIT
VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR EQU VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR EQU VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR EQU VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR EQU VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT
VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR EQU VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT
VK_FORMAT_FEATURE_DISJOINT_BIT_KHR      EQU VK_FORMAT_FEATURE_DISJOINT_BIT
VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR EQU VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT
VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM    EQU 7FFFFFFFh

; VkImageUsageFlagBits
VK_IMAGE_USAGE_TRANSFER_SRC_BIT         EQU 00000001h
VK_IMAGE_USAGE_TRANSFER_DST_BIT         EQU 00000002h
VK_IMAGE_USAGE_SAMPLED_BIT              EQU 00000004h
VK_IMAGE_USAGE_STORAGE_BIT              EQU 00000008h
VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT     EQU 00000010h
VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT EQU 00000020h
VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT EQU 00000040h
VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT     EQU 00000080h
VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM       EQU 7FFFFFFFh

; VkImageCreateFlagBits
VK_IMAGE_CREATE_SPARSE_BINDING_BIT      EQU 00000001h
VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT    EQU 00000002h
VK_IMAGE_CREATE_SPARSE_ALIASED_BIT      EQU 00000004h
VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT      EQU 00000008h
VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT     EQU 00000010h
VK_IMAGE_CREATE_ALIAS_BIT               EQU 00000400h
VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT EQU 00000040h
VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT EQU 00000020h
VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT EQU 00000080h
VK_IMAGE_CREATE_EXTENDED_USAGE_BIT      EQU 00000100h
VK_IMAGE_CREATE_PROTECTED_BIT           EQU 00000800h
VK_IMAGE_CREATE_DISJOINT_BIT            EQU 00000200h
VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT EQU 00001000h
VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR EQU VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT
VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR EQU VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT
VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR EQU VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT
VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR  EQU VK_IMAGE_CREATE_EXTENDED_USAGE_BIT
VK_IMAGE_CREATE_DISJOINT_BIT_KHR        EQU VK_IMAGE_CREATE_DISJOINT_BIT
VK_IMAGE_CREATE_ALIAS_BIT_KHR           EQU VK_IMAGE_CREATE_ALIAS_BIT
VK_IMAGE_CREATE_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkSampleCountFlagBits
VK_SAMPLE_COUNT_1_BIT                   EQU 00000001h
VK_SAMPLE_COUNT_2_BIT                   EQU 00000002h
VK_SAMPLE_COUNT_4_BIT                   EQU 00000004h
VK_SAMPLE_COUNT_8_BIT                   EQU 00000008h
VK_SAMPLE_COUNT_16_BIT                  EQU 00000010h
VK_SAMPLE_COUNT_32_BIT                  EQU 00000020h
VK_SAMPLE_COUNT_64_BIT                  EQU 00000040h
VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkQueueFlagBits
VK_QUEUE_GRAPHICS_BIT                   EQU 00000001h
VK_QUEUE_COMPUTE_BIT                    EQU 00000002h
VK_QUEUE_TRANSFER_BIT                   EQU 00000004h
VK_QUEUE_SPARSE_BINDING_BIT             EQU 00000008h
VK_QUEUE_PROTECTED_BIT                  EQU 00000010h
VK_QUEUE_FLAG_BITS_MAX_ENUM             EQU 7FFFFFFFh

; VkMemoryPropertyFlagBits
VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT     EQU 00000001h
VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT     EQU 00000002h
VK_MEMORY_PROPERTY_HOST_COHERENT_BIT    EQU 00000004h
VK_MEMORY_PROPERTY_HOST_CACHED_BIT      EQU 00000008h
VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT EQU 00000010h
VK_MEMORY_PROPERTY_PROTECTED_BIT        EQU 00000020h
VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM   EQU 7FFFFFFFh

; VkMemoryHeapFlagBits
VK_MEMORY_HEAP_DEVICE_LOCAL_BIT         EQU 00000001h
VK_MEMORY_HEAP_MULTI_INSTANCE_BIT       EQU 00000002h
VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR   EQU VK_MEMORY_HEAP_MULTI_INSTANCE_BIT
VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM       EQU 7FFFFFFFh

; VkDeviceQueueCreateFlagBits
VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT    EQU 00000001h
VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkPipelineStageFlagBits
VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT       EQU 00000001h
VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT     EQU 00000002h
VK_PIPELINE_STAGE_VERTEX_INPUT_BIT      EQU 00000004h
VK_PIPELINE_STAGE_VERTEX_SHADER_BIT     EQU 00000008h
VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT EQU 00000010h
VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT EQU 00000020h
VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT   EQU 00000040h
VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT   EQU 00000080h
VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT EQU 00000100h
VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT EQU 00000200h
VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT EQU 00000400h
VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT    EQU 00000800h
VK_PIPELINE_STAGE_TRANSFER_BIT          EQU 00001000h
VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT    EQU 00002000h
VK_PIPELINE_STAGE_HOST_BIT              EQU 00004000h
VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT      EQU 00008000h
VK_PIPELINE_STAGE_ALL_COMMANDS_BIT      EQU 00010000h
VK_PIPELINE_STAGE_COMMAND_PROCESS_BIT_NVX EQU 00020000h
VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM    EQU 7FFFFFFFh

; VkImageAspectFlagBits
VK_IMAGE_ASPECT_COLOR_BIT               EQU 00000001h
VK_IMAGE_ASPECT_DEPTH_BIT               EQU 00000002h
VK_IMAGE_ASPECT_STENCIL_BIT             EQU 00000004h
VK_IMAGE_ASPECT_METADATA_BIT            EQU 00000008h
VK_IMAGE_ASPECT_PLANE_0_BIT             EQU 00000010h
VK_IMAGE_ASPECT_PLANE_1_BIT             EQU 00000020h
VK_IMAGE_ASPECT_PLANE_2_BIT             EQU 00000040h
VK_IMAGE_ASPECT_PLANE_0_BIT_KHR         EQU VK_IMAGE_ASPECT_PLANE_0_BIT
VK_IMAGE_ASPECT_PLANE_1_BIT_KHR         EQU VK_IMAGE_ASPECT_PLANE_1_BIT
VK_IMAGE_ASPECT_PLANE_2_BIT_KHR         EQU VK_IMAGE_ASPECT_PLANE_2_BIT
VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkSparseImageFormatFlagBits
VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT EQU 00000001h
VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT EQU 00000002h
VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT EQU 00000004h
VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkSparseMemoryBindFlagBits
VK_SPARSE_MEMORY_BIND_METADATA_BIT      EQU 00000001h
VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkFenceCreateFlagBits
VK_FENCE_CREATE_SIGNALED_BIT            EQU 00000001h
VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkQueryPipelineStatisticFlagBits
VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT EQU 00000001h
VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT EQU 00000002h
VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT EQU 00000004h
VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT EQU 00000008h
VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT EQU 00000010h
VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT EQU 00000020h
VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT EQU 00000040h
VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT EQU 00000080h
VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT EQU 00000100h
VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT EQU 00000200h
VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT EQU 00000400
VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkQueryResultFlagBits
VK_QUERY_RESULT_64_BIT                  EQU 00000001h
VK_QUERY_RESULT_WAIT_BIT                EQU 00000002h
VK_QUERY_RESULT_WITH_AVAILABILITY_BIT   EQU 00000004h
VK_QUERY_RESULT_PARTIAL_BIT             EQU 00000008h
VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkBufferCreateFlagBits
VK_BUFFER_CREATE_SPARSE_BINDING_BIT     EQU 00000001h
VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT   EQU 00000002h
VK_BUFFER_CREATE_SPARSE_ALIASED_BIT     EQU 00000004h
VK_BUFFER_CREATE_PROTECTED_BIT          EQU 00000008h
VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM     EQU 7FFFFFFFh

; VkBufferUsageFlagBits
VK_BUFFER_USAGE_TRANSFER_SRC_BIT        EQU 00000001h
VK_BUFFER_USAGE_TRANSFER_DST_BIT        EQU 00000002h
VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT EQU 00000004h
VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT EQU 00000008h
VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT      EQU 00000010h
VK_BUFFER_USAGE_STORAGE_BUFFER_BIT      EQU 00000020h
VK_BUFFER_USAGE_INDEX_BUFFER_BIT        EQU 00000040h
VK_BUFFER_USAGE_VERTEX_BUFFER_BIT       EQU 00000080h
VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT     EQU 00000100h
VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkPipelineCreateFlagBits
VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT EQU 00000001h
VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT EQU 00000002h
VK_PIPELINE_CREATE_DERIVATIVE_BIT       EQU 00000004h
VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT EQU 00000008h
VK_PIPELINE_CREATE_DISPATCH_BASE        EQU 00000010h
VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR EQU VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT
VK_PIPELINE_CREATE_DISPATCH_BASE_KHR    EQU VK_PIPELINE_CREATE_DISPATCH_BASE
VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM   EQU 7FFFFFFFh

; VkShaderStageFlagBits
VK_SHADER_STAGE_VERTEX_BIT              EQU 00000001h
VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT EQU 00000002h
VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT EQU 00000004h
VK_SHADER_STAGE_GEOMETRY_BIT            EQU 00000008h
VK_SHADER_STAGE_FRAGMENT_BIT            EQU 00000010h
VK_SHADER_STAGE_COMPUTE_BIT             EQU 00000020h
VK_SHADER_STAGE_ALL_GRAPHICS            EQU 0000001Fh
VK_SHADER_STAGE_ALL                     EQU 7FFFFFFFh
VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkCullModeFlagBits
VK_CULL_MODE_NONE                       EQU 0
VK_CULL_MODE_FRONT_BIT                  EQU 00000001h
VK_CULL_MODE_BACK_BIT                   EQU 00000002h
VK_CULL_MODE_FRONT_AND_BACK             EQU 00000003h
VK_CULL_MODE_FLAG_BITS_MAX_ENUM         EQU 7FFFFFFFh

; VkColorComponentFlagBits
VK_COLOR_COMPONENT_R_BIT                EQU 00000001h
VK_COLOR_COMPONENT_G_BIT                EQU 00000002h
VK_COLOR_COMPONENT_B_BIT                EQU 00000004h
VK_COLOR_COMPONENT_A_BIT                EQU 00000008h
VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM   EQU 7FFFFFFFh

; VkDescriptorSetLayoutCreateFlagBits
VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR EQU 00000001h
VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkDescriptorPoolCreateFlagBits
VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT EQU 00000001h
VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkAttachmentDescriptionFlagBits
VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT EQU 00000001h
VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkSubpassDescriptionFlagBits
VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX EQU 00000001h
VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX EQU 00000002h
VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkAccessFlagBits
VK_ACCESS_INDIRECT_COMMAND_READ_BIT     EQU 00000001h
VK_ACCESS_INDEX_READ_BIT                EQU 00000002h
VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT     EQU 00000004h
VK_ACCESS_UNIFORM_READ_BIT              EQU 00000008h
VK_ACCESS_INPUT_ATTACHMENT_READ_BIT     EQU 00000010h
VK_ACCESS_SHADER_READ_BIT               EQU 00000020h
VK_ACCESS_SHADER_WRITE_BIT              EQU 00000040h
VK_ACCESS_COLOR_ATTACHMENT_READ_BIT     EQU 00000080h
VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT    EQU 00000100h
VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT EQU 00000200h
VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT EQU 00000400h
VK_ACCESS_TRANSFER_READ_BIT             EQU 00000800h
VK_ACCESS_TRANSFER_WRITE_BIT            EQU 00001000h
VK_ACCESS_HOST_READ_BIT                 EQU 00002000h
VK_ACCESS_HOST_WRITE_BIT                EQU 00004000h
VK_ACCESS_MEMORY_READ_BIT               EQU 00008000h
VK_ACCESS_MEMORY_WRITE_BIT              EQU 00010000h
VK_ACCESS_COMMAND_PROCESS_READ_BIT_NVX  EQU 00020000h
VK_ACCESS_COMMAND_PROCESS_WRITE_BIT_NVX EQU 00040000h
VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT EQU 00080000h
VK_ACCESS_FLAG_BITS_MAX_ENUM            EQU 7FFFFFFFh

; VkDependencyFlagBits
VK_DEPENDENCY_BY_REGION_BIT             EQU 00000001h
VK_DEPENDENCY_DEVICE_GROUP_BIT          EQU 00000004h
VK_DEPENDENCY_VIEW_LOCAL_BIT            EQU 00000002h
VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR        EQU VK_DEPENDENCY_VIEW_LOCAL_BIT
VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR      EQU VK_DEPENDENCY_DEVICE_GROUP_BIT
VK_DEPENDENCY_FLAG_BITS_MAX_ENUM        EQU 7FFFFFFFh

; VkCommandPoolCreateFlagBits
VK_COMMAND_POOL_CREATE_TRANSIENT_BIT    EQU 00000001h
VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT EQU 00000002h
VK_COMMAND_POOL_CREATE_PROTECTED_BIT    EQU 00000004h
VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkCommandPoolResetFlagBits
VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT EQU 00000001h
VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkCommandBufferUsageFlagBits
VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT EQU 00000001h
VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT EQU 00000002h
VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT EQU 00000004h
VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkQueryControlFlagBits
VK_QUERY_CONTROL_PRECISE_BIT            EQU 00000001h
VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM     EQU 7FFFFFFFh

; VkCommandBufferResetFlagBits
VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT EQU 00000001h
VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkStencilFaceFlagBits
VK_STENCIL_FACE_FRONT_BIT               EQU 00000001h
VK_STENCIL_FACE_BACK_BIT                EQU 00000002h
VK_STENCIL_FRONT_AND_BACK               EQU 00000003h
VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkPointClippingBehavior
VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES EQU 0
VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY EQU 1
VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR EQU VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES
VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR EQU VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY
VK_POINT_CLIPPING_BEHAVIOR_BEGIN_RANGE  EQU VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES
VK_POINT_CLIPPING_BEHAVIOR_END_RANGE    EQU VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY
VK_POINT_CLIPPING_BEHAVIOR_RANGE_SIZE   EQU (VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY - VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES + 1)
VK_POINT_CLIPPING_BEHAVIOR_MAX_ENUM     EQU 7FFFFFFFh

; VkTessellationDomainOrigin
VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT EQU 0
VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT EQU 1
VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT_KHR EQU VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT
VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT_KHR EQU VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT
VK_TESSELLATION_DOMAIN_ORIGIN_BEGIN_RANGE EQU VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT
VK_TESSELLATION_DOMAIN_ORIGIN_END_RANGE EQU VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT
VK_TESSELLATION_DOMAIN_ORIGIN_RANGE_SIZE EQU (VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT - VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT + 1)
VK_TESSELLATION_DOMAIN_ORIGIN_MAX_ENUM  EQU 7FFFFFFFh

; VkSamplerYcbcrModelConversion
VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY EQU 0
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY EQU 1
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709 EQU 2
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601 EQU 3
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020 EQU 4
VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY_KHR EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY_KHR EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709_KHR EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601_KHR EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601
VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020_KHR EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020
VK_SAMPLER_YCBCR_MODEL_CONVERSION_BEGIN_RANGE EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY
VK_SAMPLER_YCBCR_MODEL_CONVERSION_END_RANGE EQU VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020
VK_SAMPLER_YCBCR_MODEL_CONVERSION_RANGE_SIZE EQU (VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020 - VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY + 1)
VK_SAMPLER_YCBCR_MODEL_CONVERSION_MAX_ENUM EQU 7FFFFFFFh

; VkSamplerYcbcrRange
VK_SAMPLER_YCBCR_RANGE_ITU_FULL         EQU 0
VK_SAMPLER_YCBCR_RANGE_ITU_NARROW       EQU 1
VK_SAMPLER_YCBCR_RANGE_ITU_FULL_KHR     EQU VK_SAMPLER_YCBCR_RANGE_ITU_FULL
VK_SAMPLER_YCBCR_RANGE_ITU_NARROW_KHR   EQU VK_SAMPLER_YCBCR_RANGE_ITU_NARROW
VK_SAMPLER_YCBCR_RANGE_BEGIN_RANGE      EQU VK_SAMPLER_YCBCR_RANGE_ITU_FULL
VK_SAMPLER_YCBCR_RANGE_END_RANGE        EQU VK_SAMPLER_YCBCR_RANGE_ITU_NARROW
VK_SAMPLER_YCBCR_RANGE_RANGE_SIZE       EQU (VK_SAMPLER_YCBCR_RANGE_ITU_NARROW - VK_SAMPLER_YCBCR_RANGE_ITU_FULL + 1)
VK_SAMPLER_YCBCR_RANGE_MAX_ENUM         EQU 7FFFFFFFh

; VkChromaLocation
VK_CHROMA_LOCATION_COSITED_EVEN         EQU 0
VK_CHROMA_LOCATION_MIDPOINT             EQU 1
VK_CHROMA_LOCATION_COSITED_EVEN_KHR     EQU VK_CHROMA_LOCATION_COSITED_EVEN
VK_CHROMA_LOCATION_MIDPOINT_KHR         EQU VK_CHROMA_LOCATION_MIDPOINT
VK_CHROMA_LOCATION_BEGIN_RANGE          EQU VK_CHROMA_LOCATION_COSITED_EVEN
VK_CHROMA_LOCATION_END_RANGE            EQU VK_CHROMA_LOCATION_MIDPOINT
VK_CHROMA_LOCATION_RANGE_SIZE           EQU (VK_CHROMA_LOCATION_MIDPOINT - VK_CHROMA_LOCATION_COSITED_EVEN + 1)
VK_CHROMA_LOCATION_MAX_ENUM             EQU 7FFFFFFFh

; VkDescriptorUpdateTemplateType
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET EQU 0
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR EQU 1
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET_KHR EQU VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_BEGIN_RANGE EQU VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_END_RANGE EQU VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_RANGE_SIZE EQU (VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET - VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET + 1)
VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_MAX_ENUM EQU 7FFFFFFFh

; VkSubgroupFeatureFlagBits
VK_SUBGROUP_FEATURE_BASIC_BIT           EQU 00000001h
VK_SUBGROUP_FEATURE_VOTE_BIT            EQU 00000002h
VK_SUBGROUP_FEATURE_ARITHMETIC_BIT      EQU 00000004h
VK_SUBGROUP_FEATURE_BALLOT_BIT          EQU 00000008h
VK_SUBGROUP_FEATURE_SHUFFLE_BIT         EQU 00000010h
VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT EQU 00000020h
VK_SUBGROUP_FEATURE_CLUSTERED_BIT       EQU 00000040h
VK_SUBGROUP_FEATURE_QUAD_BIT            EQU 00000080h
VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM  EQU 7FFFFFFFh

; VkPeerMemoryFeatureFlagBits
VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT     EQU 00000001h
VK_PEER_MEMORY_FEATURE_COPY_DST_BIT     EQU 00000002h
VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT  EQU 00000004h
VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT  EQU 00000008h
VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT_KHR EQU VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT
VK_PEER_MEMORY_FEATURE_COPY_DST_BIT_KHR EQU VK_PEER_MEMORY_FEATURE_COPY_DST_BIT
VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT_KHR EQU VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT
VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT_KHR EQU VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT
VK_PEER_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkMemoryAllocateFlagBits
VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT      EQU 00000001h
VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT_KHR  EQU VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT
VK_MEMORY_ALLOCATE_FLAG_BITS_MAX_ENUM   EQU 7FFFFFFFh

; VkExternalMemoryHandleTypeFlagBits
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT EQU 00000001h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT EQU 00000002h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT EQU 00000004h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT EQU 00000008h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT EQU 00000010h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT EQU 00000020h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT EQU 00000040h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT EQU 00000200h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT EQU 00000080h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT EQU 00000100h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT_KHR EQU VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT
VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkExternalMemoryFeatureFlagBits
VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT EQU 00000001h
VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT EQU 00000002h
VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT EQU 00000004h
VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_KHR EQU VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT
VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_KHR EQU VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT
VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_KHR EQU VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT
VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkExternalFenceHandleTypeFlagBits
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT EQU 00000001h
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT EQU 00000002h
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT EQU 00000004h
VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT EQU 00000008h
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR EQU VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR EQU VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT
VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR EQU VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR EQU VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT
VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkExternalFenceFeatureFlagBits
VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT EQU 00000001h
VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT EQU 00000002h
VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT_KHR EQU VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT
VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT_KHR EQU VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT
VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkFenceImportFlagBits
VK_FENCE_IMPORT_TEMPORARY_BIT           EQU 00000001h
VK_FENCE_IMPORT_TEMPORARY_BIT_KHR       EQU VK_FENCE_IMPORT_TEMPORARY_BIT
VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM      EQU 7FFFFFFFh

; VkSemaphoreImportFlagBits
VK_SEMAPHORE_IMPORT_TEMPORARY_BIT       EQU 00000001h
VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR   EQU VK_SEMAPHORE_IMPORT_TEMPORARY_BIT
VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM  EQU 7FFFFFFFh

; VkExternalSemaphoreHandleTypeFlagBits
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT EQU 00000001h
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT EQU 00000002h
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT EQU 00000004h
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT EQU 00000008h
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT EQU 00000010h
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT
VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkExternalSemaphoreFeatureFlagBits
VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT EQU 00000001h
VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT EQU 00000002h
VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT
VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT_KHR EQU VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT
VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM EQU 7FFFFFFFh

; VkColorSpaceKHR
VK_COLOR_SPACE_SRGB_NONLINEAR_KHR       EQU 0
VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT EQU 1000104001
VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT EQU 1000104002
VK_COLOR_SPACE_DCI_P3_LINEAR_EXT        EQU 1000104003
VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT     EQU 1000104004
VK_COLOR_SPACE_BT709_LINEAR_EXT         EQU 1000104005
VK_COLOR_SPACE_BT709_NONLINEAR_EXT      EQU 1000104006
VK_COLOR_SPACE_BT2020_LINEAR_EXT        EQU 1000104007
VK_COLOR_SPACE_HDR10_ST2084_EXT         EQU 1000104008
VK_COLOR_SPACE_DOLBYVISION_EXT          EQU 1000104009
VK_COLOR_SPACE_HDR10_HLG_EXT            EQU 1000104010
VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT      EQU 1000104011
VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT   EQU 1000104012
VK_COLOR_SPACE_PASS_THROUGH_EXT         EQU 1000104013
VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT EQU 1000104014
VK_COLOR_SPACE_BEGIN_RANGE_KHR          EQU VK_COLOR_SPACE_SRGB_NONLINEAR_KHR
VK_COLOR_SPACE_END_RANGE_KHR            EQU VK_COLOR_SPACE_SRGB_NONLINEAR_KHR
VK_COLOR_SPACE_RANGE_SIZE_KHR           EQU (VK_COLOR_SPACE_SRGB_NONLINEAR_KHR - VK_COLOR_SPACE_SRGB_NONLINEAR_KHR + 1)
VK_COLOR_SPACE_MAX_ENUM_KHR             EQU 7FFFFFFFh

; VkPresentModeKHR
VK_PRESENT_MODE_IMMEDIATE_KHR           EQU 0
VK_PRESENT_MODE_MAILBOX_KHR             EQU 1
VK_PRESENT_MODE_FIFO_KHR                EQU 2
VK_PRESENT_MODE_FIFO_RELAXED_KHR        EQU 3
VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR EQU 1000111000
VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR EQU 1000111001
VK_PRESENT_MODE_BEGIN_RANGE_KHR         EQU VK_PRESENT_MODE_IMMEDIATE_KHR
VK_PRESENT_MODE_END_RANGE_KHR           EQU VK_PRESENT_MODE_FIFO_RELAXED_KHR
VK_PRESENT_MODE_RANGE_SIZE_KHR          EQU (VK_PRESENT_MODE_FIFO_RELAXED_KHR - VK_PRESENT_MODE_IMMEDIATE_KHR + 1)
VK_PRESENT_MODE_MAX_ENUM_KHR            EQU 7FFFFFFFh

; VkSurfaceTransformFlagBitsKHR
VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR   EQU 00000001h
VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR  EQU 00000002h
VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR EQU 00000004h
VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR EQU 00000008h
VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR EQU 00000010h
VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR EQU 00000020h
VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR EQU 00000040h
VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR EQU 00000080h
VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR    EQU 00000100h
VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR EQU 7FFFFFFFh

; VkCompositeAlphaFlagBitsKHR
VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR       EQU 00000001h
VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR EQU 00000002h
VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR EQU 00000004h
VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR      EQU 00000008h
VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR EQU 7FFFFFFFh

; VkSwapchainCreateFlagBitsKHR
VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR EQU 00000001h
VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR   EQU 00000002h
VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR EQU 7FFFFFFFh

; VkDeviceGroupPresentModeFlagBitsKHR
VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR EQU 00000001h
VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR EQU 00000002h
VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR EQU 00000004h
VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR EQU 00000008h
VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR EQU 7FFFFFFFh

; VkDisplayPlaneAlphaFlagBitsKHR
VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR   EQU 00000001h
VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR   EQU 00000002h
VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR EQU 00000004h
VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR EQU 00000008h
VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR EQU 7FFFFFFFh

; VkDebugReportObjectTypeEXT
VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT EQU 0
VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT EQU 1
VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT EQU 2
VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT  EQU 3
VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT   EQU 4
VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT EQU 5
VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT EQU 6
VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT   EQU 7
VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT EQU 8
VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT  EQU 9
VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT   EQU 10
VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT   EQU 11
VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT EQU 12
VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT EQU 13
VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT EQU 14
VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT EQU 15
VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT EQU 16
VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT EQU 17
VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT EQU 18
VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT EQU 19
VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT EQU 20
VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT EQU 21
VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT EQU 22
VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT EQU 23
VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT EQU 24
VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT EQU 25
VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT EQU 26
VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT EQU 27
VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT EQU 28
VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT EQU 29
VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT EQU 30
VK_DEBUG_REPORT_OBJECT_TYPE_OBJECT_TABLE_NVX_EXT EQU 31
VK_DEBUG_REPORT_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NVX_EXT EQU 32
VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT EQU 33
VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT EQU 1000156000
VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT EQU 1000085000
VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT EQU VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT
VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT EQU VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT
VK_DEBUG_REPORT_OBJECT_TYPE_BEGIN_RANGE_EXT EQU VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT
VK_DEBUG_REPORT_OBJECT_TYPE_END_RANGE_EXT EQU VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT
VK_DEBUG_REPORT_OBJECT_TYPE_RANGE_SIZE_EXT EQU (VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT - VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT + 1)
VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT EQU 7FFFFFFFh



; VkDebugReportFlagBitsEXT
VK_DEBUG_REPORT_INFORMATION_BIT_EXT     EQU 00000001h
VK_DEBUG_REPORT_WARNING_BIT_EXT         EQU 00000002h
VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT EQU 00000004h
VK_DEBUG_REPORT_ERROR_BIT_EXT           EQU 00000008h
VK_DEBUG_REPORT_DEBUG_BIT_EXT           EQU 00000010h
VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT  EQU 7FFFFFFFh

; VkRasterizationOrderAMD
VK_RASTERIZATION_ORDER_STRICT_AMD       EQU 0
VK_RASTERIZATION_ORDER_RELAXED_AMD      EQU 1
VK_RASTERIZATION_ORDER_BEGIN_RANGE_AMD  EQU VK_RASTERIZATION_ORDER_STRICT_AMD
VK_RASTERIZATION_ORDER_END_RANGE_AMD    EQU VK_RASTERIZATION_ORDER_RELAXED_AMD
VK_RASTERIZATION_ORDER_RANGE_SIZE_AMD   EQU (VK_RASTERIZATION_ORDER_RELAXED_AMD - VK_RASTERIZATION_ORDER_STRICT_AMD + 1)
VK_RASTERIZATION_ORDER_MAX_ENUM_AMD     EQU 7FFFFFFFh

; VkShaderInfoTypeAMD
VK_SHADER_INFO_TYPE_STATISTICS_AMD      EQU 0
VK_SHADER_INFO_TYPE_BINARY_AMD          EQU 1
VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD     EQU 2
VK_SHADER_INFO_TYPE_BEGIN_RANGE_AMD     EQU VK_SHADER_INFO_TYPE_STATISTICS_AMD
VK_SHADER_INFO_TYPE_END_RANGE_AMD       EQU VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD
VK_SHADER_INFO_TYPE_RANGE_SIZE_AMD      EQU (VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD - VK_SHADER_INFO_TYPE_STATISTICS_AMD + 1)
VK_SHADER_INFO_TYPE_MAX_ENUM_AMD        EQU 7FFFFFFFh

; VkExternalMemoryHandleTypeFlagBitsNV
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV EQU 00000001h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV EQU 00000002h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV EQU 00000004h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV EQU 00000008h
VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV EQU 7FFFFFFFh


; VkExternalMemoryFeatureFlagBitsNV
VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV EQU 00000001h
VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV EQU 00000002h
VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV EQU 00000004h
VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV EQU 7FFFFFFFh

; VkValidationCheckEXT
VK_VALIDATION_CHECK_ALL_EXT             EQU 0
VK_VALIDATION_CHECK_SHADERS_EXT         EQU 1
VK_VALIDATION_CHECK_BEGIN_RANGE_EXT     EQU VK_VALIDATION_CHECK_ALL_EXT
VK_VALIDATION_CHECK_END_RANGE_EXT       EQU VK_VALIDATION_CHECK_SHADERS_EXT
VK_VALIDATION_CHECK_RANGE_SIZE_EXT      EQU (VK_VALIDATION_CHECK_SHADERS_EXT - VK_VALIDATION_CHECK_ALL_EXT + 1)
VK_VALIDATION_CHECK_MAX_ENUM_EXT        EQU 7FFFFFFFh

; VkIndirectCommandsTokenTypeNVX
VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NVX EQU 0
VK_INDIRECT_COMMANDS_TOKEN_TYPE_DESCRIPTOR_SET_NVX EQU 1
VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NVX EQU 2
VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NVX EQU 3
VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NVX EQU 4
VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NVX EQU 5
VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NVX EQU 6
VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NVX EQU 7
VK_INDIRECT_COMMANDS_TOKEN_TYPE_BEGIN_RANGE_NVX EQU VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NVX
VK_INDIRECT_COMMANDS_TOKEN_TYPE_END_RANGE_NVX EQU VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NVX
VK_INDIRECT_COMMANDS_TOKEN_TYPE_RANGE_SIZE_NVX EQU (VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NVX - VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NVX + 1)
VK_INDIRECT_COMMANDS_TOKEN_TYPE_MAX_ENUM_NVX EQU 7FFFFFFFh


; VkObjectEntryTypeNVX
VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX EQU 0
VK_OBJECT_ENTRY_TYPE_PIPELINE_NVX       EQU 1
VK_OBJECT_ENTRY_TYPE_INDEX_BUFFER_NVX   EQU 2
VK_OBJECT_ENTRY_TYPE_VERTEX_BUFFER_NVX  EQU 3
VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX  EQU 4
VK_OBJECT_ENTRY_TYPE_BEGIN_RANGE_NVX    EQU VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX
VK_OBJECT_ENTRY_TYPE_END_RANGE_NVX      EQU VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX
VK_OBJECT_ENTRY_TYPE_RANGE_SIZE_NVX     EQU (VK_OBJECT_ENTRY_TYPE_PUSH_CONSTANT_NVX - VK_OBJECT_ENTRY_TYPE_DESCRIPTOR_SET_NVX + 1)
VK_OBJECT_ENTRY_TYPE_MAX_ENUM_NVX       EQU 7FFFFFFFh



; VkIndirectCommandsLayoutUsageFlagBitsNVX
VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NVX EQU 00000001h
VK_INDIRECT_COMMANDS_LAYOUT_USAGE_SPARSE_SEQUENCES_BIT_NVX EQU 00000002h
VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EMPTY_EXECUTIONS_BIT_NVX EQU 00000004h
VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NVX EQU 00000008h
VK_INDIRECT_COMMANDS_LAYOUT_USAGE_FLAG_BITS_MAX_ENUM_NVX EQU 7FFFFFFFh


; VkObjectEntryUsageFlagBitsNVX
VK_OBJECT_ENTRY_USAGE_GRAPHICS_BIT_NVX  EQU 00000001h
VK_OBJECT_ENTRY_USAGE_COMPUTE_BIT_NVX   EQU 00000002h
VK_OBJECT_ENTRY_USAGE_FLAG_BITS_MAX_ENUM_NVX EQU 7FFFFFFFh

; VkSurfaceCounterFlagBitsEXT
VK_SURFACE_COUNTER_VBLANK_EXT           EQU 00000001h
VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT EQU 7FFFFFFFh

; VkDisplayPowerStateEXT
VK_DISPLAY_POWER_STATE_OFF_EXT          EQU 0
VK_DISPLAY_POWER_STATE_SUSPEND_EXT      EQU 1
VK_DISPLAY_POWER_STATE_ON_EXT           EQU 2
VK_DISPLAY_POWER_STATE_BEGIN_RANGE_EXT  EQU VK_DISPLAY_POWER_STATE_OFF_EXT
VK_DISPLAY_POWER_STATE_END_RANGE_EXT    EQU VK_DISPLAY_POWER_STATE_ON_EXT
VK_DISPLAY_POWER_STATE_RANGE_SIZE_EXT   EQU (VK_DISPLAY_POWER_STATE_ON_EXT - VK_DISPLAY_POWER_STATE_OFF_EXT + 1)
VK_DISPLAY_POWER_STATE_MAX_ENUM_EXT     EQU 7FFFFFFFh

; VkDeviceEventTypeEXT
VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT EQU 0
VK_DEVICE_EVENT_TYPE_BEGIN_RANGE_EXT    EQU VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT
VK_DEVICE_EVENT_TYPE_END_RANGE_EXT      EQU VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT
VK_DEVICE_EVENT_TYPE_RANGE_SIZE_EXT     EQU (VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT - VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT + 1)
VK_DEVICE_EVENT_TYPE_MAX_ENUM_EXT       EQU 7FFFFFFFh

; VkDisplayEventTypeEXT
VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT EQU 0
VK_DISPLAY_EVENT_TYPE_BEGIN_RANGE_EXT   EQU VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT
VK_DISPLAY_EVENT_TYPE_END_RANGE_EXT     EQU VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT
VK_DISPLAY_EVENT_TYPE_RANGE_SIZE_EXT    EQU (VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT - VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT + 1)
VK_DISPLAY_EVENT_TYPE_MAX_ENUM_EXT      EQU 7FFFFFFFh

; VkViewportCoordinateSwizzleNV
VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV EQU 0
VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV EQU 1
VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV EQU 2
VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV EQU 3
VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV EQU 4
VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV EQU 5
VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV EQU 6
VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV EQU 7
VK_VIEWPORT_COORDINATE_SWIZZLE_BEGIN_RANGE_NV EQU VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV
VK_VIEWPORT_COORDINATE_SWIZZLE_END_RANGE_NV EQU VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV
VK_VIEWPORT_COORDINATE_SWIZZLE_RANGE_SIZE_NV EQU (VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV - VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV + 1)
VK_VIEWPORT_COORDINATE_SWIZZLE_MAX_ENUM_NV EQU 7FFFFFFFh

; VkDiscardRectangleModeEXT
VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT EQU 0
VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT EQU 1
VK_DISCARD_RECTANGLE_MODE_BEGIN_RANGE_EXT EQU VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT
VK_DISCARD_RECTANGLE_MODE_END_RANGE_EXT EQU VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT
VK_DISCARD_RECTANGLE_MODE_RANGE_SIZE_EXT EQU (VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT - VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT + 1)
VK_DISCARD_RECTANGLE_MODE_MAX_ENUM_EXT  EQU 7FFFFFFFh

; VkConservativeRasterizationModeEXT
VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT EQU 0
VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT EQU 1
VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT EQU 2
VK_CONSERVATIVE_RASTERIZATION_MODE_BEGIN_RANGE_EXT EQU VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT
VK_CONSERVATIVE_RASTERIZATION_MODE_END_RANGE_EXT EQU VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT
VK_CONSERVATIVE_RASTERIZATION_MODE_RANGE_SIZE_EXT EQU (VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT - VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT + 1)
VK_CONSERVATIVE_RASTERIZATION_MODE_MAX_ENUM_EXT EQU 7FFFFFFFh

; VkDebugUtilsMessageSeverityFlagBitsEXT
VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT EQU 00000001h
VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT EQU 00000010h
VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT EQU 00000100h
VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT EQU 00001000h
VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT EQU 7FFFFFFFh


; VkDebugUtilsMessageTypeFlagBitsEXT
VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT EQU 00000001h
VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT EQU 00000002h
VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT EQU 00000004h
VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT EQU 7FFFFFFFh

; VkSamplerReductionModeEXT
VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT EQU 0
VK_SAMPLER_REDUCTION_MODE_MIN_EXT       EQU 1
VK_SAMPLER_REDUCTION_MODE_MAX_EXT       EQU 2
VK_SAMPLER_REDUCTION_MODE_BEGIN_RANGE_EXT EQU VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT
VK_SAMPLER_REDUCTION_MODE_END_RANGE_EXT EQU VK_SAMPLER_REDUCTION_MODE_MAX_EXT
VK_SAMPLER_REDUCTION_MODE_RANGE_SIZE_EXT EQU (VK_SAMPLER_REDUCTION_MODE_MAX_EXT - VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT + 1)
VK_SAMPLER_REDUCTION_MODE_MAX_ENUM_EXT  EQU 7FFFFFFFh

; VkBlendOverlapEXT
VK_BLEND_OVERLAP_UNCORRELATED_EXT       EQU 0
VK_BLEND_OVERLAP_DISJOINT_EXT           EQU 1
VK_BLEND_OVERLAP_CONJOINT_EXT           EQU 2
VK_BLEND_OVERLAP_BEGIN_RANGE_EXT        EQU VK_BLEND_OVERLAP_UNCORRELATED_EXT
VK_BLEND_OVERLAP_END_RANGE_EXT          EQU VK_BLEND_OVERLAP_CONJOINT_EXT
VK_BLEND_OVERLAP_RANGE_SIZE_EXT         EQU (VK_BLEND_OVERLAP_CONJOINT_EXT - VK_BLEND_OVERLAP_UNCORRELATED_EXT + 1)
VK_BLEND_OVERLAP_MAX_ENUM_EXT           EQU 7FFFFFFFh

; VkCoverageModulationModeNV
VK_COVERAGE_MODULATION_MODE_NONE_NV     EQU 0
VK_COVERAGE_MODULATION_MODE_RGB_NV      EQU 1
VK_COVERAGE_MODULATION_MODE_ALPHA_NV    EQU 2
VK_COVERAGE_MODULATION_MODE_RGBA_NV     EQU 3
VK_COVERAGE_MODULATION_MODE_BEGIN_RANGE_NV EQU VK_COVERAGE_MODULATION_MODE_NONE_NV
VK_COVERAGE_MODULATION_MODE_END_RANGE_NV EQU VK_COVERAGE_MODULATION_MODE_RGBA_NV
VK_COVERAGE_MODULATION_MODE_RANGE_SIZE_NV EQU (VK_COVERAGE_MODULATION_MODE_RGBA_NV - VK_COVERAGE_MODULATION_MODE_NONE_NV + 1)
VK_COVERAGE_MODULATION_MODE_MAX_ENUM_NV EQU 7FFFFFFFh

; VkValidationCacheHeaderVersionEXT
VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT EQU 1
VK_VALIDATION_CACHE_HEADER_VERSION_BEGIN_RANGE_EXT EQU VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT
VK_VALIDATION_CACHE_HEADER_VERSION_END_RANGE_EXT EQU VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT
VK_VALIDATION_CACHE_HEADER_VERSION_RANGE_SIZE_EXT EQU (VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT - VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT + 1)
VK_VALIDATION_CACHE_HEADER_VERSION_MAX_ENUM_EXT EQU 7FFFFFFFh

; VkQueueGlobalPriorityEXT
VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT        EQU 128
VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT     EQU 256
VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT       EQU 512
VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT   EQU 1024
VK_QUEUE_GLOBAL_PRIORITY_BEGIN_RANGE_EXT EQU VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT
VK_QUEUE_GLOBAL_PRIORITY_END_RANGE_EXT  EQU VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT
VK_QUEUE_GLOBAL_PRIORITY_RANGE_SIZE_EXT EQU (VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT - VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT + 1)
VK_QUEUE_GLOBAL_PRIORITY_MAX_ENUM_EXT   EQU 7FFFFFFFh



;---------------------------------
; Vulkan Structures
; https://vulkan.lunarg.com/doc/view/1.1.70.0/windows/apispec.html#structs
;---------------------------------
VkApplicationInfo                       STRUCT
    sType                               VkStructureType ?
    pNext                               DWORD ? ; *
    pApplicationName                    DWORD ? ; *
    applicationVersion                  DWORD ? ; uint32_t
    pEngineName                         DWORD ? ; *
    engineVersion                       DWORD ? ; uint32_t
    apiVersion                          DWORD ? ; uint32_t
VkApplicationInfo                       ENDS

VkInstanceCreateInfo                    STRUCT
    sType                               VkStructureType ?
    pNext                               DWORD ? ; *
    flags                               VkInstanceCreateFlags ?
    pApplicationInfo                    DWORD ? ; VkApplicationInfo*
    enabledLayerCount                   DWORD ? ; uint32_t
    ppEnabledLayerNames                 DWORD ? ; **
    enabledExtensionCount               DWORD ? ; uint32_t
    ppEnabledExtensionNames             DWORD ? ; **
VkInstanceCreateInfo                    ENDS

VkAllocationCallbacks                   STRUCT
    pUserData                           DWORD ? ; 
    pfnAllocation                       DWORD ? ; PFN_vkAllocationFunction
    pfnReallocation                     DWORD ? ; PFN_vkReallocationFunction
    pfnFree                             DWORD ? ; PFN_vkFreeFunction
    pfnInternalAllocation               DWORD ? ; PFN_vkInternalAllocationNotification
    pfnInternalFree                     DWORD ? ; PFN_vkInternalFreeNotification
VkAllocationCallbacks                   ENDS

VkPhysicalDeviceFeatures                STRUCT
    robustBufferAccess                  VkBool32 ?
    fullDrawIndexUint32                 VkBool32 ?
    imageCubeArray                      VkBool32 ?
    independentBlend                    VkBool32 ?
    geometryShader                      VkBool32 ?
    tessellationShader                  VkBool32 ?
    sampleRateShading                   VkBool32 ?
    dualSrcBlend                        VkBool32 ?
    logicOp                             VkBool32 ?
    multiDrawIndirect                   VkBool32 ?
    drawIndirectFirstInstance           VkBool32 ?
    depthClamp                          VkBool32 ?
    depthBiasClamp                      VkBool32 ?
    fillModeNonSolid                    VkBool32 ?
    depthBounds                         VkBool32 ?
    wideLines                           VkBool32 ?
    largePoints                         VkBool32 ?
    alphaToOne                          VkBool32 ?
    multiViewport                       VkBool32 ?
    samplerAnisotropy                   VkBool32 ?
    textureCompressionETC2              VkBool32 ?
    textureCompressionASTC_LDR          VkBool32 ?
    textureCompressionBC                VkBool32 ?
    occlusionQueryPrecise               VkBool32 ?
    pipelineStatisticsQuery             VkBool32 ?
    vertexPipelineStoresAndAtomics      VkBool32 ?
    fragmentStoresAndAtomics            VkBool32 ?
    shaderTessellationAndGeometryPointSize VkBool32 ?
    shaderImageGatherExtended           VkBool32 ?
    shaderStorageImageExtendedFormats   VkBool32 ?
    shaderStorageImageMultisample       VkBool32 ?
    shaderStorageImageReadWithoutFormat VkBool32 ?
    shaderStorageImageWriteWithoutFormat VkBool32 ?
    shaderUniformBufferArrayDynamicIndexing VkBool32 ?
    shaderSampledImageArrayDynamicIndexing VkBool32 ?
    shaderStorageBufferArrayDynamicIndexing VkBool32 ?
    shaderStorageImageArrayDynamicIndexing VkBool32 ?
    shaderClipDistance                  VkBool32 ?
    shaderCullDistance                  VkBool32 ?
    shaderFloat64                       VkBool32 ?
    shaderInt64                         VkBool32 ?
    shaderInt16                         VkBool32 ?
    shaderResourceResidency             VkBool32 ?
    shaderResourceMinLod                VkBool32 ?
    sparseBinding                       VkBool32 ?
    sparseResidencyBuffer               VkBool32 ?
    sparseResidencyImage2D              VkBool32 ?
    sparseResidencyImage3D              VkBool32 ?
    sparseResidency2Samples             VkBool32 ?
    sparseResidency4Samples             VkBool32 ?
    sparseResidency8Samples             VkBool32 ?
    sparseResidency16Samples            VkBool32 ?
    sparseResidencyAliased              VkBool32 ?
    variableMultisampleRate             VkBool32 ?
    inheritedQueries                    VkBool32 ?
VkPhysicalDeviceFeatures                ENDS

VkFormatProperties                      STRUCT
    linearTilingFeatures                VkFormatFeatureFlags ?
    optimalTilingFeatures               VkFormatFeatureFlags ?
    bufferFeatures                      VkFormatFeatureFlags ?
VkFormatProperties                      ENDS

VkExtent3D                              STRUCT
    width_                              DWORD ? ; uint32_t
    height                              DWORD ? ; uint32_t
    depth                               DWORD ? ; uint32_t
VkExtent3D                              ENDS

VkImageFormatProperties                 STRUCT
    maxExtent                           VkExtent3D <>
    maxMipLevels                        DWORD ? ; uint32_t              
    maxArrayLayers                      DWORD ? ; uint32_t               
    sampleCounts                        VkSampleCountFlags ?
    maxResourceSize                     VkDeviceSize ? ; qword
VkImageFormatProperties                 ENDS

VkPhysicalDeviceLimits                  STRUCT
    maxImageDimension1D                 DWORD ? ; uint32_t
    maxImageDimension2D                 DWORD ? ; uint32_t
    maxImageDimension3D                 DWORD ? ; uint32_t
    maxImageDimensionCube               DWORD ? ; uint32_t
    maxImageArrayLayers                 DWORD ? ; uint32_t
    maxTexelBufferElements              DWORD ? ; uint32_t
    maxUniformBufferRange               DWORD ? ; uint32_t
    maxStorageBufferRange               DWORD ? ; uint32_t
    maxPushConstantsSize                DWORD ? ; uint32_t
    maxMemoryAllocationCount            DWORD ? ; uint32_t
    maxSamplerAllocationCount           DWORD ? ; uint32_t
    bufferImageGranularity              VkDeviceSize ? ; qword
    sparseAddressSpaceSize              VkDeviceSize ? ; qword
    maxBoundDescriptorSets              DWORD ? ; uint32_t
    maxPerStageDescriptorSamplers       DWORD ? ; uint32_t
    maxPerStageDescriptorUniformBuffers DWORD ? ; uint32_t
    maxPerStageDescriptorStorageBuffers DWORD ? ; uint32_t
    maxPerStageDescriptorSampledImages  DWORD ? ; uint32_t
    maxPerStageDescriptorStorageImages  DWORD ? ; uint32_t
    maxPerStageDescriptorInputAttachments DWORD ? ; uint32_t
    maxPerStageResources                DWORD ? ; uint32_t;
    maxDescriptorSetSamplers            DWORD ? ; uint32_t
    maxDescriptorSetUniformBuffers      DWORD ? ; uint32_t
    maxDescriptorSetUniformBuffersDynamic DWORD ? ; uint32_t
    maxDescriptorSetStorageBuffers      DWORD ? ; uint32_t
    maxDescriptorSetStorageBuffersDynamic DWORD ? ; uint32_t
    maxDescriptorSetSampledImages       DWORD ? ; uint32_t
    maxDescriptorSetStorageImages       DWORD ? ; uint32_t
    maxDescriptorSetInputAttachments    DWORD ? ; uint32_t
    maxVertexInputAttributes            DWORD ? ; uint32_t
    maxVertexInputBindings              DWORD ? ; uint32_t
    maxVertexInputAttributeOffset       DWORD ? ; uint32_t
    maxVertexInputBindingStride         DWORD ? ; uint32_t
    maxVertexOutputComponents           DWORD ? ; uint32_t
    maxTessellationGenerationLevel      DWORD ? ; uint32_t
    maxTessellationPatchSize            DWORD ? ; uint32_t
    maxTessellationControlPerVertexInputComponents DWORD ? ; uint32_t
    maxTessellationControlPerVertexOutputComponents DWORD ? ; uint32_t
    maxTessellationControlPerPatchOutputComponents DWORD ? ; uint32_t
    maxTessellationControlTotalOutputComponents DWORD ? ; uint32_t
    maxTessellationEvaluationInputComponents DWORD ? ; uint32_t
    maxTessellationEvaluationOutputComponents DWORD ? ; uint32_t
    maxGeometryShaderInvocations        DWORD ? ; uint32_t
    maxGeometryInputComponents          DWORD ? ; uint32_t
    maxGeometryOutputComponents         DWORD ? ; uint32_t
    maxGeometryOutputVertices           DWORD ? ; uint32_t
    maxGeometryTotalOutputComponents    DWORD ? ; uint32_t
    maxFragmentInputComponents          DWORD ? ; uint32_t
    maxFragmentOutputAttachments        DWORD ? ; uint32_t
    maxFragmentDualSrcAttachments       DWORD ? ; uint32_t
    maxFragmentCombinedOutputResources  DWORD ? ; uint32_t
    maxComputeSharedMemorySize          DWORD ? ; uint32_t
    maxComputeWorkGroupCount            DD 3 DUP (?) ; uint32_t
    maxComputeWorkGroupInvocations      DWORD ? ; uint32_t
    maxComputeWorkGroupSize             DD 3 DUP (?) ; uint32_t
    subPixelPrecisionBits               DWORD ? ; uint32_t
    subTexelPrecisionBits               DWORD ? ; uint32_t
    mipmapPrecisionBits                 DWORD ? ; uint32_t
    maxDrawIndexedIndexValue            DWORD ? ; uint32_t
    maxDrawIndirectCount                DWORD ? ; uint32_t
    maxSamplerLodBias                   REAL4 ? ; float
    maxSamplerAnisotropy                REAL4 ? ; float
    maxViewports                        DWORD ? ; uint32_t
    maxViewportDimensions               DD 2 DUP (?) ; uint32_t
    viewportBoundsRange                 REAL4 2 DUP (?) ; float[2];
    viewportSubPixelBits                DWORD ? ; uint32_t
    minMemoryMapAlignment               DWORD ? ; size_t
    minTexelBufferOffsetAlignment       VkDeviceSize ? ; qword
    minUniformBufferOffsetAlignment     VkDeviceSize ? ; qword
    minStorageBufferOffsetAlignment     VkDeviceSize ? ; qword
    minTexelOffset                      DWORD ? ; int32_t
    maxTexelOffset                      DWORD ? ; uint32_t
    minTexelGatherOffset                DWORD ? ; int32_t
    maxTexelGatherOffset                DWORD ? ; uint32_t
    minInterpolationOffset              REAL4 ? ; float
    maxInterpolationOffset              REAL4 ? ; float
    subPixelInterpolationOffsetBits     DWORD ? ; uint32_t
    maxFramebufferWidth                 DWORD ? ; uint32_t
    maxFramebufferHeight                DWORD ? ; uint32_t
    maxFramebufferLayers                DWORD ? ; uint32_t
    framebufferColorSampleCounts        VkSampleCountFlags ?
    framebufferDepthSampleCounts        VkSampleCountFlags ?
    framebufferStencilSampleCounts      VkSampleCountFlags ?
    framebufferNoAttachmentsSampleCounts VkSampleCountFlags ?
    maxColorAttachments                 DWORD ? ; uint32_t
    sampledImageColorSampleCounts       VkSampleCountFlags ?
    sampledImageIntegerSampleCounts     VkSampleCountFlags ?
    sampledImageDepthSampleCounts       VkSampleCountFlags ?
    sampledImageStencilSampleCounts     VkSampleCountFlags ?
    storageImageSampleCounts            VkSampleCountFlags ?
    maxSampleMaskWords                  DWORD ? ; uint32_t
    timestampComputeAndGraphics         VkBool32 ?
    timestampPeriod                     REAL4 ? ; float
    maxClipDistances                    DWORD ? ; uint32_t
    maxCullDistances                    DWORD ? ; uint32_t
    maxCombinedClipAndCullDistances     DWORD ? ; uint32_t
    discreteQueuePriorities             DWORD ? ; uint32_t
    pointSizeRange                      REAL4 2 DUP (?) ; float[2];
    lineWidthRange                      REAL4 2 DUP (?) ; float[2];
    pointSizeGranularity                REAL4 ? ; float
    lineWidthGranularity                REAL4 ? ; float    
    strictLines                         VkBool32 ?
    standardSampleLocations             VkBool32 ?
    optimalBufferCopyOffsetAlignment    VkDeviceSize ? ; qword
    optimalBufferCopyRowPitchAlignment  VkDeviceSize ? ; qword
    nonCoherentAtomSize                 VkDeviceSize ? ; qword
VkPhysicalDeviceLimits                  ENDS

VkPhysicalDeviceSparseProperties        STRUCT
    residencyStandard2DBlockShape       VkBool32 ?
    residencyStandard2DMultisampleBlockShape VkBool32 ?
    residencyStandard3DBlockShape       VkBool32 ?
    residencyAlignedMipSize             VkBool32 ?
    residencyNonResidentStrict          VkBool32 ?
VkPhysicalDeviceSparseProperties        ENDS

VkPhysicalDeviceProperties              STRUCT
    apiVersion                          DWORD ? ; uint32_t
    driverVersion                       DWORD ? ; uint32_t
    vendorID                            DWORD ? ; uint32_t
    deviceID                            DWORD ? ; uint32_t
    deviceType                          DWORD ? ; VkPhysicalDeviceType enum value
    deviceName                          DB VK_MAX_PHYSICAL_DEVICE_NAME_SIZE DUP (?) ; char
    pipelineCacheUUID                   DB VK_UUID_SIZE DUP (?) ; uint8_t
    limits                              VkPhysicalDeviceLimits <>
    sparseProperties                    VkPhysicalDeviceSparseProperties <>
VkPhysicalDeviceProperties              ENDS

VkQueueFamilyProperties                 STRUCT
    queueFlags                          VkQueueFlags ?
    queueCount                          DWORD ? ; uint32_t
    timestampValidBits                  DWORD ? ; uint32_t
    minImageTransferGranularity         VkExtent3D <>
VkQueueFamilyProperties                 ENDS

VkMemoryType                            STRUCT
    propertyFlags                       VkMemoryPropertyFlags ?
    heapIndex                           DWORD ? ; uint32_t
VkMemoryType                            ENDS

VkMemoryHeap                            STRUCT
    heapsize                            VkDeviceSize ? ; qword
    flags                               VkMemoryHeapFlags ?
VkMemoryHeap                            ENDS

VkPhysicalDeviceMemoryProperties        STRUCT
    memoryTypeCount                     DWORD ? ; uint32_t
    memoryTypes                         VkMemoryType VK_MAX_MEMORY_TYPES DUP (<>)
    memoryHeapCount                     DWORD ? ; uint32_t
    memoryHeaps                         VkMemoryHeap VK_MAX_MEMORY_HEAPS DUP (<>)
VkPhysicalDeviceMemoryProperties        ENDS

VkDeviceQueueCreateInfo                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDeviceQueueCreateFlags ?
    queueFamilyIndex                    DWORD ? ; uint32_t
    queueCount                          DWORD ? ; uint32_t
    pQueuePriorities                    DWORD ? ; * const float*                
VkDeviceQueueCreateInfo                 ENDS

VkDeviceCreateInfo                      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDeviceCreateFlags ?
    queueCreateInfoCount                DWORD ? ; uint32_t
    pQueueCreateInfos                   DWORD ? ; * VkDeviceQueueCreateInfo*
    enabledLayerCount                   DWORD ? ; uint32_t
    ppEnabledLayerNames                 DWORD ? ; * const char* const*
    enabledExtensionCount               DWORD ? ; uint32_t
    ppEnabledExtensionNames             DWORD ? ; * const char* const*
    pEnabledFeatures                    DWORD ? ; * VkPhysicalDeviceFeatures*    
VkDeviceCreateInfo                      ENDS

VkExtensionProperties                   STRUCT
    extensionName                       DB VK_MAX_EXTENSION_NAME_SIZE DUP (?) ; char
    specVersion                         DWORD ? ; uint32_t
VkExtensionProperties                   ENDS

VkLayerProperties                       STRUCT
    layerName                           DB VK_MAX_EXTENSION_NAME_SIZE (?) ; char
    specVersion                         DWORD ? ; uint32_t
    implementationVersion               DWORD ? ; uint32_t
    description                         DB VK_MAX_DESCRIPTION_SIZE (?) ; char
VkLayerProperties                       ENDS

VkSubmitInfo                            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    waitSemaphoreCount                  DWORD ? ; uint32_t
    pWaitSemaphores                     DWORD ? ; * VkSemaphore*
    pWaitDstStageMask                   DWORD ? ; * VkPipelineStageFlags*
    commandBufferCount                  DWORD ? ; uint32_t
    pCommandBuffers                     DWORD ? ; * VkCommandBuffer*
    signalSemaphoreCount                DWORD ? ; uint32_t
    pSignalSemaphores                   DWORD ? ; * VkSemaphore*
VkSubmitInfo                            ENDS

VkMemoryAllocateInfo                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    allocationSize                      VkDeviceSize ? ; qword
    memoryTypeIndex                     DWORD ? ; uint32_t
VkMemoryAllocateInfo                    ENDS

VkMappedMemoryRange                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memory                              VkDeviceMemory ?
    memoffset                           VkDeviceSize ? ; qword
    memsize                             VkDeviceSize ? ; qword
VkMappedMemoryRange                     ENDS

VkMemoryRequirements                    STRUCT
    memsize                             VkDeviceSize ? ; qword
    alignment                           VkDeviceSize ? ; qword
    memoryTypeBits                      DWORD ? ; uint32_t
VkMemoryRequirements                    ENDS

VkSparseImageFormatProperties           STRUCT
    aspectMask                          VkImageAspectFlags ?
    imageGranularity                    VkExtent3D <>
    flags                               VkSparseImageFormatFlags ?
VkSparseImageFormatProperties           ENDS

VkSparseImageMemoryRequirements         STRUCT
    formatProperties                    VkSparseImageFormatProperties <>
    imageMipTailFirstLod                DWORD ? ; uint32_t
    imageMipTailSize                    VkDeviceSize ? ; qword
    imageMipTailOffset                  VkDeviceSize ? ; qword
    imageMipTailStride                  VkDeviceSize ? ; qword
VkSparseImageMemoryRequirements         ENDS

VkSparseMemoryBind                      STRUCT
    resourceOffset                      VkDeviceSize ? ; qword
    memsize                             VkDeviceSize ? ; qword
    memory                              VkDeviceMemory ?
    memoryOffset                        VkDeviceSize ? ; qword
    flags                               VkSparseMemoryBindFlags ?
VkSparseMemoryBind                      ENDS

VkSparseBufferMemoryBindInfo            STRUCT
    buffer                              VkBuffer ?
    bindCount                           DWORD ? ; uint32_t
    pBinds                              DWORD ? ; * VkSparseMemoryBind*
VkSparseBufferMemoryBindInfo            ENDS

VkSparseImageOpaqueMemoryBindInfo       STRUCT
    image                               VkImage ?
    bindCount                           DWORD ? ; uint32_t
    pBinds                              DWORD ? ; * VkSparseMemoryBind*
VkSparseImageOpaqueMemoryBindInfo       ENDS

VkImageSubresource                      STRUCT
    aspectMask                          VkImageAspectFlags ?
    mipLevel                            DWORD ? ; uint32_t
    arrayLayer                          DWORD ? ; uint32_t
VkImageSubresource                      ENDS

VkOffset3D                              STRUCT
    x                                   DWORD ? ; int32_t
    y                                   DWORD ? ; int32_t
    z                                   DWORD ? ; int32_t
VkOffset3D                              ENDS

VkSparseImageMemoryBind                 STRUCT
    subresource                         VkImageSubresource <>
    memoffset                           VkOffset3D <>
    extent                              VkExtent3D <>
    memory                              VkDeviceMemory ?
    memoryOffset                        VkDeviceSize ? ; qword
    flags                               VkSparseMemoryBindFlags ?
VkSparseImageMemoryBind                 ENDS

VkSparseImageMemoryBindInfo             STRUCT
    image                               VkImage ?
    bindCount                           DWORD ? ; uint32_t
    pBinds                              DWORD ? ; * VkSparseImageMemoryBind*
VkSparseImageMemoryBindInfo             ENDS

VkBindSparseInfo                        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    waitSemaphoreCount                  DWORD ? ; uint32_t
    pWaitSemaphores                     DWORD ? ; * VkSemaphore*
    bufferBindCount                     DWORD ? ; uint32_t
    pBufferBinds                        DWORD ? ; * VkSparseBufferMemoryBindInfo*
    imageOpaqueBindCount                DWORD ? ; uint32_t
    pImageOpaqueBinds                   DWORD ? ; * VkSparseImageOpaqueMemoryBindInfo*
    imageBindCount                      DWORD ? ; uint32_t
    pImageBinds                         DWORD ? ; * VkSparseImageMemoryBindInfo*
    signalSemaphoreCount                DWORD ? ; uint32_t
    pSignalSemaphores                   DWORD ? ; * VkSemaphore*
VkBindSparseInfo                        ENDS

VkFenceCreateInfo                       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkFenceCreateFlags ?
VkFenceCreateInfo                       ENDS

VkSemaphoreCreateInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkSemaphoreCreateFlags ?
VkSemaphoreCreateInfo                   ENDS

VkEventCreateInfo                       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkEventCreateFlags ?
VkEventCreateInfo                       ENDS

VkQueryPoolCreateInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkQueryPoolCreateFlags ?
    queryType                           DWORD ? ; VkQueryType enum value
    queryCount                          DWORD ? ; uint32_t
    pipelineStatistics                  VkQueryPipelineStatisticFlags ?
VkQueryPoolCreateInfo                   ENDS

VkBufferCreateInfo                      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkBufferCreateFlags ?
    memsize                             VkDeviceSize ? ; qword
    usage                               VkBufferUsageFlags ?
    sharingMode                         DWORD ? ; VkSharingMode enum value
    queueFamilyIndexCount               DWORD ? ; uint32_t
    pQueueFamilyIndices                 DWORD ? ; * uint32_t*        
VkBufferCreateInfo                      ENDS

VkBufferViewCreateInfo                  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkBufferViewCreateFlags ?
    buffer                              VkBuffer ?
    format                              DWORD ? ; VkFormat enum value
    memoffset                           VkDeviceSize ? ; qword
    range                               VkDeviceSize ? ; qword
VkBufferViewCreateInfo                  ENDS

VkImageCreateInfo                       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkImageCreateFlags ?
    imageType                           DWORD ? ; VkImageType enum value
    format                              DWORD ? ; VkFormat enum value
    extent                              VkExtent3D <>
    mipLevels                           DWORD ? ; uint32_t
    arrayLayers                         DWORD ? ; uint32_t
    samples                             DWORD ? ; VkSampleCountFlagBits enum value
    tiling                              DWORD ? ; VkImageTiling enum value
    usage                               VkImageUsageFlags ?
    sharingMode                         DWORD ? ; VkSharingMode enum value
    queueFamilyIndexCount               DWORD ? ; uint32_t
    pQueueFamilyIndices                 DWORD ? ; * uint32_t*
    initialLayout                       DWORD ? ; VkImageLayout enum value
VkImageCreateInfo                       ENDS

VkSubresourceLayout                     STRUCT
    memoffset                           VkDeviceSize ? ; qword
    memsize                             VkDeviceSize ? ; qword
    rowPitch                            VkDeviceSize ? ; qword
    arrayPitch                          VkDeviceSize ? ; qword
    depthPitch                          VkDeviceSize ? ; qword
VkSubresourceLayout                     ENDS

VkComponentMapping                      STRUCT
    r                                   DWORD ? ; VkComponentSwizzle enum value
    g                                   DWORD ? ; VkComponentSwizzle enum value
    b                                   DWORD ? ; VkComponentSwizzle enum value
    a                                   DWORD ? ; VkComponentSwizzle enum value
VkComponentMapping                      ENDS

VkImageSubresourceRange                 STRUCT
    aspectMask                          VkImageAspectFlags ?
    baseMipLevel                        DWORD ? ; uint32_t
    levelCount                          DWORD ? ; uint32_t
    baseArrayLayer                      DWORD ? ; uint32_t
    layerCount                          DWORD ? ; uint32_t
VkImageSubresourceRange                 ENDS

VkImageViewCreateInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkImageViewCreateFlags ?
    image                               VkImage ?
    viewType                            DWORD ? ; VkImageViewType enum value
    format                              DWORD ? ; VkFormat enum value
    components                          VkComponentMapping <>
    subresourceRange                    VkImageSubresourceRange <>
VkImageViewCreateInfo                   ENDS

VkShaderModuleCreateInfo                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkShaderModuleCreateFlags ?
    codeSize                            DWORD ? ; size_t
    pCode                               DWORD ? ; * uint32_t*
VkShaderModuleCreateInfo                ENDS

VkPipelineCacheCreateInfo               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineCacheCreateFlags ?
    initialDataSize                     DWORD ? ; size_t
    pInitialData                        DWORD ? ; void*                   
VkPipelineCacheCreateInfo               ENDS

VkSpecializationMapEntry                STRUCT
    constantID                          DWORD ? ; uint32_t
    memoffset                           DWORD ? ; uint32_t
    memsize                             DWORD ? ; size_t
VkSpecializationMapEntry                ENDS

VkSpecializationInfo                    STRUCT
    mapEntryCount                       DWORD ? ; uint32_t
    pMapEntries                         DWORD ? ; * VkSpecializationMapEntry*
    dataSize                            DWORD ? ; size_t
    pData                               DWORD ? ; void* 
VkSpecializationInfo                    ENDS

VkPipelineShaderStageCreateInfo         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineShaderStageCreateFlags ?
    stage                               DWORD ? ; VkShaderStageFlagBits enum value
    module                              VkShaderModule ?
    pName                               DWORD ? ; * char*
    pSpecializationInfo                 DWORD ? ; * VkSpecializationInfo* 
VkPipelineShaderStageCreateInfo         ENDS

VkVertexInputBindingDescription         STRUCT
    binding                             DWORD ? ; uint32_t
    stride                              DWORD ? ; uint32_t
    inputRate                           DWORD ? ; VkVertexInputRate enum value
VkVertexInputBindingDescription         ENDS

VkVertexInputAttributeDescription       STRUCT
    location                            DWORD ? ; uint32_t
    binding                             DWORD ? ; uint32_t
    format                              DWORD ? ; VkFormat enum value
    memoffset                           DWORD ? ; uint32_t
VkVertexInputAttributeDescription       ENDS

VkPipelineVertexInputStateCreateInfo    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineVertexInputStateCreateFlags ?
    vertexBindingDescriptionCount       DWORD ? ; uint32_t
    pVertexBindingDescriptions          DWORD ? ; * VkVertexInputBindingDescription*
    vertexAttributeDescriptionCount     DWORD ? ; uint32_t
    pVertexAttributeDescriptions        DWORD ? ; * VkVertexInputAttributeDescription*
VkPipelineVertexInputStateCreateInfo    ENDS

VkPipelineInputAssemblyStateCreateInfo  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineInputAssemblyStateCreateFlags ?
    topology                            DWORD ? ; VkPrimitiveTopology enum value
    primitiveRestartEnable              VkBool32 ?
VkPipelineInputAssemblyStateCreateInfo  ENDS

VkPipelineTessellationStateCreateInfo   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineTessellationStateCreateFlags ?
    patchControlPoints                  DWORD ? ; uint32_t
VkPipelineTessellationStateCreateInfo   ENDS

VkViewport                              STRUCT
    x                                   REAL4 ? ; float
    y                                   REAL4 ? ; float
    width_                              REAL4 ? ; float
    height                              REAL4 ? ; float
    minDepth                            REAL4 ? ; float
    maxDepth                            REAL4 ? ; float
VkViewport                              ENDS

VkOffset2D                              STRUCT
    x                                   DWORD ? ; int32_t
    y                                   DWORD ? ; int32_t
VkOffset2D                              ENDS

VkExtent2D                              STRUCT
    width_                              DWORD ? ; uint32_t
    height                              DWORD ? ; uint32_t
VkExtent2D                              ENDS

VkRect2D                                STRUCT
    offset_                             VkOffset2D <>
    extent                              VkExtent2D <>
VkRect2D                                ENDS

VkPipelineViewportStateCreateInfo       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineViewportStateCreateFlags ?
    viewportCount                       DWORD ? ; uint32_t
    pViewports                          DWORD ? ; * VkViewport*
    scissorCount                        DWORD ? ; uint32_t
    pScissors                           DWORD ? ; * VkRect2D*
VkPipelineViewportStateCreateInfo       ENDS

VkPipelineRasterizationStateCreateInfo  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineRasterizationStateCreateFlags ?
    depthClampEnable                    VkBool32 ?
    rasterizerDiscardEnable             VkBool32 ?
    polygonMode                         DWORD ? ; VkPolygonMode enum value
    cullMode                            VkCullModeFlags ?
    frontFace                           DWORD ? ; VkFrontFace enum value
    depthBiasEnable                     VkBool32 ?
    depthBiasConstantFactor             REAL4 ? ; float
    depthBiasClamp                      REAL4 ? ; float
    depthBiasSlopeFactor                REAL4 ? ; float
    lineWidth                           REAL4 ? ; float
VkPipelineRasterizationStateCreateInfo  ENDS

VkPipelineMultisampleStateCreateInfo    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineMultisampleStateCreateFlags ?
    rasterizationSamples                DWORD ? ; VkSampleCountFlagBits enum value
    sampleShadingEnable                 VkBool32 ?
    minSampleShading                    REAL4 ? ; float
    pSampleMask                         DWORD ? ; * VkSampleMask*
    alphaToCoverageEnable               VkBool32 ?
    alphaToOneEnable                    VkBool32 ?
VkPipelineMultisampleStateCreateInfo    ENDS

VkStencilOpState                        STRUCT
    failOp                              DWORD ? ; VkStencilOp enum value
    passOp                              DWORD ? ; VkStencilOp enum value
    depthFailOp                         DWORD ? ; VkStencilOp enum value
    compareOp                           DWORD ? ; VkCompareOp enum value
    compareMask                         DWORD ? ; uint32_t
    writeMask                           DWORD ? ; uint32_t
    reference                           DWORD ? ; uint32_t
VkStencilOpState                        ENDS

VkPipelineDepthStencilStateCreateInfo   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineDepthStencilStateCreateFlags ?
    depthTestEnable                     VkBool32 ?
    depthWriteEnable                    VkBool32 ?
    depthCompareOp                      DWORD ? ; VkCompareOp enum value
    depthBoundsTestEnable               VkBool32 ?
    stencilTestEnable                   VkBool32 ?
    front                               DWORD ? ; VkStencilOp enum value
    back                                DWORD ? ; VkStencilOp enum value
    minDepthBounds                      REAL4 ? ; float
    maxDepthBounds                      REAL4 ? ; float
VkPipelineDepthStencilStateCreateInfo   ENDS

VkPipelineColorBlendAttachmentState     STRUCT
    blendEnable                         VkBool32 ?
    srcColorBlendFactor                 DWORD ? ; VkBlendFactor enum value
    dstColorBlendFactor                 DWORD ? ; VkBlendFactor enum value
    colorBlendOp                        DWORD ? ; VkBlendOp enum value
    srcAlphaBlendFactor                 DWORD ? ; VkBlendFactor enum value
    dstAlphaBlendFactor                 DWORD ? ; VkBlendFactor enum value
    alphaBlendOp                        DWORD ? ; VkBlendOp enum value
    colorWriteMask                      VkColorComponentFlags ?
VkPipelineColorBlendAttachmentState     ENDS

VkPipelineColorBlendStateCreateInfo     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineColorBlendStateCreateFlags ?
    logicOpEnable                       VkBool32 ?
    logicOp                             DWORD ? ; VkLogicOp enum value
    attachmentCount                     DWORD ? ; uint32_t
    pAttachments                        DWORD ? ; * VkPipelineColorBlendAttachmentState*
    blendConstants                      REAL4 4 DUP (?) ; float[4];
VkPipelineColorBlendStateCreateInfo     ENDS

VkPipelineDynamicStateCreateInfo        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineDynamicStateCreateFlags ?
    dynamicStateCount                   DWORD ? ; uint32_t
    pDynamicStates                      DWORD ? ; * VkDynamicState*
VkPipelineDynamicStateCreateInfo        ENDS

VkGraphicsPipelineCreateInfo            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineCreateFlags ?
    stageCount                          DWORD ? ; uint32_t
    pStages                             DWORD ? ; VkPipelineShaderStageCreateInfo*
    pVertexInputState                   DWORD ? ; VkPipelineVertexInputStateCreateInfo*
    pInputAssemblyState                 DWORD ? ; VkPipelineInputAssemblyStateCreateInfo*
    pTessellationState                  DWORD ? ; VkPipelineTessellationStateCreateInfo*
    pViewportState                      DWORD ? ; VkPipelineViewportStateCreateInfo*
    pRasterizationState                 DWORD ? ; VkPipelineRasterizationStateCreateInfo*
    pMultisampleState                   DWORD ? ; VkPipelineMultisampleStateCreateInfo*
    pDepthStencilState                  DWORD ? ; VkPipelineDepthStencilStateCreateInfo*
    pColorBlendState                    DWORD ? ; VkPipelineColorBlendStateCreateInfo*
    pDynamicState                       DWORD ? ; VkPipelineDynamicStateCreateInfo*
    layout                              VkPipelineLayout ?
    renderPass                          VkRenderPass ?
    subpass                             DWORD ? ; uint32_t
    basePipelineHandle                  VkPipeline ?
    basePipelineIndex                   DWORD ? ; int32_t
VkGraphicsPipelineCreateInfo            ENDS

VkComputePipelineCreateInfo             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineCreateFlags ?
    stage                               VkPipelineShaderStageCreateInfo <>
    layout                              VkPipelineLayout ?
    basePipelineHandle                  VkPipeline ?
    basePipelineIndex                   DWORD ? ; int32_t
VkComputePipelineCreateInfo             ENDS

VkPushConstantRange                     STRUCT
    stageFlags                          VkShaderStageFlags ?
    _offset                             DWORD ? ; uint32_t
    _size                               DWORD ? ; uint32_t
VkPushConstantRange                     ENDS

VkPipelineLayoutCreateInfo              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineLayoutCreateFlags ?
    setLayoutCount                      DWORD ? ; uint32_t
    pSetLayouts                         DWORD ? ; VkDescriptorSetLayout*
    pushConstantRangeCount              DWORD ? ; uint32_t
    pPushConstantRanges                 DWORD ? ; VkPushConstantRange*
VkPipelineLayoutCreateInfo              ENDS

VkSamplerCreateInfo                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkSamplerCreateFlags ?
    magFilter                           DWORD ? ; VkFilter enum value
    minFilter                           DWORD ? ; VkFilter enum value
    mipmapMode                          DWORD ? ; VkSamplerMipmapMode enum value
    addressModeU                        DWORD ? ; VkSamplerAddressMode enum value
    addressModeV                        DWORD ? ; VkSamplerAddressMode enum value
    addressModeW                        DWORD ? ; VkSamplerAddressMode enum value
    mipLodBias                          REAL4 ? ; float
    anisotropyEnable                    VkBool32 ?
    maxAnisotropy                       REAL4 ? ; float
    compareEnable                       VkBool32 ?
    compareOp                           DWORD ? ; VkCompareOp enum value
    minLod                              REAL4 ? ; float
    maxLod                              REAL4 ? ; float
    borderColor                         DWORD ? ; VkBorderColor enum value
    unnormalizedCoordinates             VkBool32 ?
VkSamplerCreateInfo                     ENDS

VkDescriptorSetLayoutBinding            STRUCT
    binding                             DWORD ? ; uint32_t
    descriptorType                      DWORD ? ; VkDescriptorType enum value
    descriptorCount                     DWORD ? ; uint32_t
    stageFlags                          VkShaderStageFlags ?
    pImmutableSamplers                  DWORD ? ; * VkSampler*
VkDescriptorSetLayoutBinding            ENDS

VkDescriptorSetLayoutCreateInfo         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDescriptorSetLayoutCreateFlags ?
    bindingCount                        DWORD ? ; uint32_t
    pBindings                           DWORD ? ; * VkDescriptorSetLayoutBinding*
VkDescriptorSetLayoutCreateInfo         ENDS

VkDescriptorPoolSize                    STRUCT
    _type                               DWORD ? ; VkDescriptorType enum value
    descriptorCount                     DWORD ? ; uint32_t
VkDescriptorPoolSize                    ENDS

VkDescriptorPoolCreateInfo              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDescriptorPoolCreateFlags ?
    maxSets                             DWORD ? ; uint32_t
    poolSizeCount                       DWORD ? ; uint32_t
    pPoolSizes                          DWORD ? ; * VkDescriptorPoolSize*
VkDescriptorPoolCreateInfo              ENDS

VkDescriptorSetAllocateInfo             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    descriptorPool                      VkDescriptorPool ?
    descriptorSetCount                  DWORD ? ; uint32_t
    pSetLayouts                         DWORD ? ; * VkDescriptorSetLayout*
VkDescriptorSetAllocateInfo             ENDS

VkDescriptorImageInfo                   STRUCT
    sampler                             VkSampler ?
    imageView                           VkImageView ?
    imageLayout                         DWORD ? ; VkImageLayout enum value
VkDescriptorImageInfo                   ENDS

VkDescriptorBufferInfo                  STRUCT
    buffer                              VkBuffer ?
    _offset                             VkDeviceSize ? ; qword
    range                               VkDeviceSize ? ; qword
VkDescriptorBufferInfo                  ENDS

VkWriteDescriptorSet                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    dstSet                              VkDescriptorSet ?
    dstBinding                          DWORD ? ; uint32_t
    dstArrayElement                     DWORD ? ; uint32_t
    descriptorCount                     DWORD ? ; uint32_t
    descriptorType                      DWORD ? ; VkDescriptorType enum value
    pImageInfo                          DWORD ? ; VkDescriptorImageInfo*
    pBufferInfo                         DWORD ? ; VkDescriptorBufferInfo*
    pTexelBufferView                    DWORD ? ; VkBufferView*
VkWriteDescriptorSet                    ENDS

VkCopyDescriptorSet                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcSet                              VkDescriptorSet ?
    srcBinding                          DWORD ? ; uint32_t
    srcArrayElement                     DWORD ? ; uint32_t
    dstSet                              VkDescriptorSet ?
    dstBinding                          DWORD ? ; uint32_t
    dstArrayElement                     DWORD ? ; uint32_t
    descriptorCount                     DWORD ? ; uint32_t
VkCopyDescriptorSet                     ENDS

VkFramebufferCreateInfo                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkFramebufferCreateFlags ?
    renderPass                          VkRenderPass ?
    attachmentCount                     DWORD ? ; uint32_t
    pAttachments                        DWORD ? ; * VkImageView*
    width_                              DWORD ? ; uint32_t
    height                              DWORD ? ; uint32_t
    layers                              DWORD ? ; uint32_t
VkFramebufferCreateInfo                 ENDS

VkAttachmentDescription                 STRUCT
    flags                               VkAttachmentDescriptionFlags ?
    format                              DWORD ? ; VkFormat enum value
    samples                             DWORD ? ; VkSampleCountFlagBits enum value
    loadOp                              DWORD ? ; VkAttachmentLoadOp enum value
    storeOp                             DWORD ? ; VkAttachmentStoreOp  enum value
    stencilLoadOp                       DWORD ? ; VkAttachmentLoadOp enum value
    stencilStoreOp                      DWORD ? ; VkAttachmentStoreOp  enum value
    initialLayout                       DWORD ? ; VkImageLayout enum value
    finalLayout                         DWORD ? ; VkImageLayout enum value
VkAttachmentDescription                 ENDS

VkAttachmentReference                   STRUCT
    attachment                          DWORD ? ; uint32_t
    layout                              DWORD ? ; VkImageLayout enum value
VkAttachmentReference                   ENDS

VkSubpassDescription                    STRUCT
    flags                               VkSubpassDescriptionFlags ?
    pipelineBindPoint                   DWORD ? ; VkPipelineBindPoint enum value
    inputAttachmentCount                DWORD ? ; uint32_t
    pInputAttachments                   DWORD ? ; * VkAttachmentReference*
    colorAttachmentCount                DWORD ? ; uint32_t
    pColorAttachments                   DWORD ? ; * VkAttachmentReference*
    pResolveAttachments                 DWORD ? ; * VkAttachmentReference*
    pDepthStencilAttachment             DWORD ? ; * VkAttachmentReference*
    preserveAttachmentCount             DWORD ? ; uint32_t
    pPreserveAttachments                DWORD ? ; * uint32_t*
VkSubpassDescription                    ENDS


VkSubpassDependency                     STRUCT
    srcSubpass                          DWORD ? ; uint32_t
    dstSubpass                          DWORD ? ; uint32_t
    srcStageMask                        VkPipelineStageFlags ?
    dstStageMask                        VkPipelineStageFlags ?
    srcAccessMask                       VkAccessFlags ?
    dstAccessMask                       VkAccessFlags ?
    dependencyFlags                     VkDependencyFlags ?
VkSubpassDependency                     ENDS

VkRenderPassCreateInfo                  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkRenderPassCreateFlags ?
    attachmentCount                     DWORD ? ; uint32_t
    pAttachments                        DWORD ? ; * VkAttachmentDescription*
    subpassCount                        DWORD ? ; uint32_t
    pSubpasses                          DWORD ? ; * VkSubpassDescription*
    dependencyCount                     DWORD ? ; uint32_t
    pDependencies                       DWORD ? ; * VkSubpassDependency*
VkRenderPassCreateInfo                  ENDS

VkCommandPoolCreateInfo                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkCommandPoolCreateFlags ?
    queueFamilyIndex                    DWORD ? ; uint32_t
VkCommandPoolCreateInfo                 ENDS

VkCommandBufferAllocateInfo             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    commandPool                         VkCommandPool ?
    level                               DWORD ? ; VkCommandBufferLevel enum value
    commandBufferCount                  DWORD ? ; uint32_t
VkCommandBufferAllocateInfo             ENDS

VkCommandBufferInheritanceInfo          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    renderPass                          VkRenderPass ?
    subpass                             DWORD ? ; uint32_t
    framebuffer                         VkFramebuffer ?
    occlusionQueryEnable                VkBool32 ?
    queryFlags                          VkQueryControlFlags ?
    pipelineStatistics                  VkQueryPipelineStatisticFlags ?
VkCommandBufferInheritanceInfo          ENDS

VkCommandBufferBeginInfo                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkCommandBufferUsageFlags ?
    pInheritanceInfo                    DWORD ? ; * VkCommandBufferInheritanceInfo*
VkCommandBufferBeginInfo                ENDS

VkBufferCopy                            STRUCT
    srcOffset                           VkDeviceSize ? ; qword
    dstOffset                           VkDeviceSize ? ; qword
    memsize                             VkDeviceSize ? ; qword
VkBufferCopy                            ENDS

VkImageSubresourceLayers                STRUCT
    aspectMask                          VkImageAspectFlags ?
    mipLevel                            DWORD ? ; uint32_t
    baseArrayLayer                      DWORD ? ; uint32_t
    layerCount                          DWORD ? ; uint32_t
VkImageSubresourceLayers                ENDS

VkImageCopy                             STRUCT
    srcSubresource                      VkImageSubresourceLayers <>
    srcOffset                           VkOffset3D <>
    dstSubresource                      VkImageSubresourceLayers <>
    dstOffset                           VkOffset3D <>
    extent                              VkExtent3D <>
VkImageCopy                             ENDS

VkImageBlit                             STRUCT
    srcSubresource                      VkImageSubresourceLayers <>
    srcOffsets                          VkOffset3D 2 DUP (<>)
    dstSubresource                      VkImageSubresourceLayers <>
    dstOffsets                          VkOffset3D 2 DUP (<>)
VkImageBlit                             ENDS

VkBufferImageCopy                       STRUCT
    bufferOffset                        VkDeviceSize ? ; qword
    bufferRowLength                     DWORD ? ; uint32_t
    bufferImageHeight                   DWORD ? ; uint32_t
    imageSubresource                    VkImageSubresourceLayers <>
    imageOffset                         VkOffset3D <>
    imageExtent                         VkExtent3D <>
VkBufferImageCopy                       ENDS


VkClearColorValue                       STRUCT
    float32                             REAL4 4 DUP (?) ; float[4];
    int32                               DD 4 DUP (?) ; int32_t
    uint32                              DD 4 DUP (?) ; uint32_t
VkClearColorValue                       ENDS

VkClearDepthStencilValue                STRUCT
    depth                               REAL4 ? ; float
    stencil                             DWORD ? ; uint32_t
VkClearDepthStencilValue                ENDS

VkClearValue                            STRUCT
    color                               VkClearColorValue <>
    depthStencil                        VkClearDepthStencilValue <>
VkClearValue                            ENDS

VkClearAttachment                       STRUCT
    aspectMask                          VkImageAspectFlags ?
    colorAttachment                     DWORD ? ; uint32_t
    clearValue                          VkClearValue <>
VkClearAttachment                       ENDS

VkClearRect                             STRUCT
    rect                                VkRect2D <>
    baseArrayLayer                      DWORD ? ; uint32_t
    layerCount                          DWORD ? ; uint32_t
VkClearRect                             ENDS

VkImageResolve                          STRUCT
    srcSubresource                      VkImageSubresourceLayers <>
    srcOffset                           VkOffset3D <>
    dstSubresource                      VkImageSubresourceLayers <>
    dstOffset                           VkOffset3D <>
    extent                              VkExtent3D <>
VkImageResolve                          ENDS

VkMemoryBarrier                         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcAccessMask                       VkAccessFlags ?
    dstAccessMask                       VkAccessFlags ?
VkMemoryBarrier                         ENDS

VkBufferMemoryBarrier                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcAccessMask                       VkAccessFlags ?
    dstAccessMask                       VkAccessFlags ?
    srcQueueFamilyIndex                 DWORD ? ; uint32_t
    dstQueueFamilyIndex                 DWORD ? ; uint32_t
    buffer                              VkBuffer ?
    memoffset                           VkDeviceSize ? ; qword
    memsize                             VkDeviceSize ? ; qword
VkBufferMemoryBarrier                   ENDS

VkImageMemoryBarrier                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcAccessMask                       VkAccessFlags ?
    dstAccessMask                       VkAccessFlags ?
    oldLayout                           DWORD ? ; VkImageLayout enum value
    newLayout                           DWORD ? ; VkImageLayout enum value
    srcQueueFamilyIndex                 DWORD ? ; uint32_t
    dstQueueFamilyIndex                 DWORD ? ; uint32_t
    image                               VkImage ?
    subresourceRange                    VkImageSubresourceRange <>
VkImageMemoryBarrier                    ENDS

VkRenderPassBeginInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    renderPass                          VkRenderPass ?
    framebuffer                         VkFramebuffer ?
    renderArea                          VkRect2D <>
    clearValueCount                     DWORD ? ; uint32_t
    pClearValues                        DWORD ? ; * VkClearValue*
VkRenderPassBeginInfo                   ENDS

VkDispatchIndirectCommand               STRUCT
    x                                   DWORD ? ; uint32_t
    y                                   DWORD ? ; uint32_t
    z                                   DWORD ? ; uint32_t
VkDispatchIndirectCommand               ENDS

VkDrawIndexedIndirectCommand            STRUCT
    indexCount                          DWORD ? ; uint32_t
    instanceCount                       DWORD ? ; uint32_t
    firstIndex                          DWORD ? ; uint32_t
    vertexOffset                        DWORD ? ; int32_t
    firstInstance                       DWORD ? ; uint32_t
VkDrawIndexedIndirectCommand            ENDS

VkDrawIndirectCommand                   STRUCT
    vertexCount                         DWORD ? ; uint32_t
    instanceCount                       DWORD ? ; uint32_t
    firstVertex                         DWORD ? ; uint32_t
    firstInstance                       DWORD ? ; uint32_t
VkDrawIndirectCommand                   ENDS


VkPhysicalDeviceSubgroupProperties      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    subgroupSize                        DWORD ? ; uint32_t
    supportedStages                     VkShaderStageFlags ?
    supportedOperations                 VkSubgroupFeatureFlags ?
    quadOperationsInAllStages           VkBool32 ?
VkPhysicalDeviceSubgroupProperties      ENDS

VkBindBufferMemoryInfo                  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    buffer                              VkBuffer ?
    memory                              VkDeviceMemory ?
    memoryOffset                        VkDeviceSize ? ; qword
VkBindBufferMemoryInfo                  ENDS

VkBindImageMemoryInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    image                               VkImage ?
    memory                              VkDeviceMemory ?
    memoryOffset                        VkDeviceSize ? ; qword
VkBindImageMemoryInfo                   ENDS

VkPhysicalDevice16BitStorageFeatures    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    storageBuffer16BitAccess            VkBool32 ?
    uniformAndStorageBuffer16BitAccess  VkBool32 ?
    storagePushConstant16               VkBool32 ?
    storageInputOutput16                VkBool32 ?
VkPhysicalDevice16BitStorageFeatures    ENDS

VkMemoryDedicatedRequirements           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    prefersDedicatedAllocation          VkBool32 ?
    requiresDedicatedAllocation         VkBool32 ?
VkMemoryDedicatedRequirements           ENDS

VkMemoryDedicatedAllocateInfo           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    image                               VkImage ?
    buffer                              VkBuffer ?
VkMemoryDedicatedAllocateInfo           ENDS

VkMemoryAllocateFlagsInfo               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkMemoryAllocateFlags ?
    deviceMask                          DWORD ? ; uint32_t
VkMemoryAllocateFlagsInfo               ENDS

VkDeviceGroupRenderPassBeginInfo        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceMask                          DWORD ? ; uint32_t
    deviceRenderAreaCount               DWORD ? ; uint32_t
    pDeviceRenderAreas                  DWORD ? ; * const VkRect2D*
VkDeviceGroupRenderPassBeginInfo        ENDS

VkDeviceGroupCommandBufferBeginInfo     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceMask                          DWORD ? ; uint32_t
VkDeviceGroupCommandBufferBeginInfo     ENDS

VkDeviceGroupSubmitInfo                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    waitSemaphoreCount                  DWORD ? ; uint32_t
    pWaitSemaphoreDeviceIndices         DWORD ? ; * const uint32_t*
    commandBufferCount                  DWORD ? ; uint32_t
    pCommandBufferDeviceMasks           DWORD ? ; * const uint32_t*
    signalSemaphoreCount                DWORD ? ; uint32_t
    pSignalSemaphoreDeviceIndices       DWORD ? ; * const uint32_t*
VkDeviceGroupSubmitInfo                 ENDS

VkDeviceGroupBindSparseInfo             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    resourceDeviceIndex                 DWORD ? ; uint32_t
    memoryDeviceIndex                   DWORD ? ; uint32_t
VkDeviceGroupBindSparseInfo             ENDS

VkBindBufferMemoryDeviceGroupInfo       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceIndexCount                    DWORD ? ; uint32_t
    pDeviceIndices                      DWORD ? ; * const uint32_t*
VkBindBufferMemoryDeviceGroupInfo       ENDS

VkBindImageMemoryDeviceGroupInfo        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceIndexCount                    DWORD ? ; uint32_t
    pDeviceIndices                      DWORD ? ; * const uint32_t*
    splitInstanceBindRegionCount        DWORD ? ; uint32_t
    pSplitInstanceBindRegions           DWORD ? ; * const VkRect2D*
VkBindImageMemoryDeviceGroupInfo        ENDS

VkPhysicalDeviceGroupProperties         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    physicalDeviceCount                 DWORD ? ; uint32_t
    physicalDevices                     VkPhysicalDevice VK_MAX_DEVICE_GROUP_SIZE DUP (?)
    subsetAllocation                    VkBool32 ?
VkPhysicalDeviceGroupProperties         ENDS

VkDeviceGroupDeviceCreateInfo           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    physicalDeviceCount                 DWORD ? ; uint32_t
    pPhysicalDevices                    DWORD ? ; * const VkPhysicalDevice*
VkDeviceGroupDeviceCreateInfo           ENDS

VkBufferMemoryRequirementsInfo2         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    buffer                              VkBuffer ?
VkBufferMemoryRequirementsInfo2         ENDS

VkImageMemoryRequirementsInfo2          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    image                               VkImage ?
VkImageMemoryRequirementsInfo2          ENDS

VkImageSparseMemoryRequirementsInfo2    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    image                               VkImage ?
VkImageSparseMemoryRequirementsInfo2    ENDS

VkMemoryRequirements2                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryRequirements                  VkMemoryRequirements <>
VkMemoryRequirements2                   ENDS

VkSparseImageMemoryRequirements2        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryRequirements                  VkSparseImageMemoryRequirements <>
VkSparseImageMemoryRequirements2        ENDS

VkPhysicalDeviceFeatures2               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    features                            VkPhysicalDeviceFeatures <>
VkPhysicalDeviceFeatures2               ENDS

VkPhysicalDeviceProperties2             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    properties                          VkPhysicalDeviceProperties <>
VkPhysicalDeviceProperties2             ENDS

VkFormatProperties2                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    formatProperties                    VkFormatProperties <>
VkFormatProperties2                     ENDS

VkImageFormatProperties2                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    imageFormatProperties               VkImageFormatProperties <>
VkImageFormatProperties2                ENDS

VkPhysicalDeviceImageFormatInfo2        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    format                              DWORD ? ; VkFormat enum value
    type_                               DWORD ? ; VkImageType enum value
    tiling                              DWORD ? ; VkImageTiling enum value
    usage                               VkImageUsageFlags ?
    flags                               VkImageCreateFlags ?
VkPhysicalDeviceImageFormatInfo2        ENDS

VkQueueFamilyProperties2                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    queueFamilyProperties               VkQueueFamilyProperties <>
VkQueueFamilyProperties2                ENDS

VkPhysicalDeviceMemoryProperties2       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryProperties                    VkPhysicalDeviceMemoryProperties <>
VkPhysicalDeviceMemoryProperties2       ENDS

VkSparseImageFormatProperties2          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    properties                          VkSparseImageFormatProperties <>
VkSparseImageFormatProperties2          ENDS

VkPhysicalDeviceSparseImageFormatInfo2  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    format                              DWORD ? ; VkFormat enum value
    type_                               DWORD ? ; VkImageType enum value
    samples                             DWORD ? ; VkSampleCountFlagBits enum value
    usage                               VkImageUsageFlags ?
    tiling                              DWORD ? ; VkImageTiling enum value
VkPhysicalDeviceSparseImageFormatInfo2  ENDS

VkPhysicalDevicePointClippingProperties STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pointClippingBehavior               DWORD ? ; VkPointClippingBehavior enum value
VkPhysicalDevicePointClippingProperties ENDS

VkInputAttachmentAspectReference        STRUCT
    subpass                             DWORD ? ; uint32_t
    inputAttachmentIndex                DWORD ? ; uint32_t
    aspectMask                          VkImageAspectFlags ?
VkInputAttachmentAspectReference        ENDS

VkRenderPassInputAttachmentAspectCreateInfo STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    aspectReferenceCount                DWORD ? ; uint32_t
    pAspectReferences                   DWORD ? ; * const VkInputAttachmentAspectReference*
VkRenderPassInputAttachmentAspectCreateInfo ENDS

VkImageViewUsageCreateInfo              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    usage                               VkImageUsageFlags ?
VkImageViewUsageCreateInfo              ENDS

VkPipelineTessellationDomainOriginStateCreateInfo STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    domainOrigin                        DWORD ? ; VkTessellationDomainOrigin enum value
VkPipelineTessellationDomainOriginStateCreateInfo ENDS

VkRenderPassMultiviewCreateInfo         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    subpassCount                        DWORD ? ; uint32_t
    pViewMasks                          DWORD ? ; * const uint32_t*
    dependencyCount                     DWORD ? ; uint32_t
    pViewOffsets                        DWORD ? ; * const int32_t*
    correlationMaskCount                DWORD ? ; uint32_t
    pCorrelationMasks                   DWORD ? ; * const uint32_t*
VkRenderPassMultiviewCreateInfo         ENDS

VkPhysicalDeviceMultiviewFeatures       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    multiview                           VkBool32 ?
    multiviewGeometryShader             VkBool32 ?
    multiviewTessellationShader         VkBool32 ?
VkPhysicalDeviceMultiviewFeatures       ENDS

VkPhysicalDeviceMultiviewProperties     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxMultiviewViewCount               DWORD ? ; uint32_t
    maxMultiviewInstanceIndex           DWORD ? ; uint32_t
VkPhysicalDeviceMultiviewProperties     ENDS

VkPhysicalDeviceVariablePointerFeatures STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    variablePointersStorageBuffer       VkBool32 ?
    variablePointers                    VkBool32 ?
VkPhysicalDeviceVariablePointerFeatures ENDS

VkPhysicalDeviceProtectedMemoryFeatures STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    protectedMemory                     VkBool32 ?
VkPhysicalDeviceProtectedMemoryFeatures ENDS

VkPhysicalDeviceProtectedMemoryProperties STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    protectedNoFault                    VkBool32 ?
VkPhysicalDeviceProtectedMemoryProperties ENDS

VkDeviceQueueInfo2                      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDeviceQueueCreateFlags ?
    queueFamilyIndex                    DWORD ? ; uint32_t
    queueIndex                          DWORD ? ; uint32_t
VkDeviceQueueInfo2                      ENDS

VkProtectedSubmitInfo                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    protectedSubmit                     VkBool32 ?
VkProtectedSubmitInfo                   ENDS

VkSamplerYcbcrConversionCreateInfo      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    format                              DWORD ? ; VkFormat enum value
    ycbcrModel                          DWORD ? ; VkSamplerYcbcrModelConversion enum value
    ycbcrRange                          DWORD ? ; VkSamplerYcbcrRange enum value
    components                          VkComponentMapping <>
    xChromaOffset                       DWORD ? ; VkChromaLocation enum value
    yChromaOffset                       DWORD ? ; VkChromaLocation enum value
    chromaFilter                        DWORD ? ; VkFilter enum value
    forceExplicitReconstruction         VkBool32 ?
VkSamplerYcbcrConversionCreateInfo      ENDS

VkSamplerYcbcrConversionInfo            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    conversion                          VkSamplerYcbcrConversion ?
VkSamplerYcbcrConversionInfo            ENDS

VkBindImagePlaneMemoryInfo              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    planeAspect                         DWORD ? ; VkImageAspectFlagBits enum value
VkBindImagePlaneMemoryInfo              ENDS

VkImagePlaneMemoryRequirementsInfo      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    planeAspect                         DWORD ? ; VkImageAspectFlagBits enum value
VkImagePlaneMemoryRequirementsInfo      ENDS

VkPhysicalDeviceSamplerYcbcrConversionFeatures STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    samplerYcbcrConversion              VkBool32 ?
VkPhysicalDeviceSamplerYcbcrConversionFeatures ENDS

VkSamplerYcbcrConversionImageFormatProperties STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    combinedImageSamplerDescriptorCount DWORD ? ; uint32_t
VkSamplerYcbcrConversionImageFormatProperties ENDS

VkDescriptorUpdateTemplateEntry         STRUCT
    dstBinding                          DWORD ? ; uint32_t
    dstArrayElement                     DWORD ? ; uint32_t
    descriptorCount                     DWORD ? ; uint32_t
    descriptorType                      DWORD ? ; VkDescriptorType enum value
    offset_                             DWORD ? ; size_t
    stride                              DWORD ? ; size_t
VkDescriptorUpdateTemplateEntry         ENDS

VkDescriptorUpdateTemplateCreateInfo    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDescriptorUpdateTemplateCreateFlags ?
    descriptorUpdateEntryCount          DWORD ? ; uint32_t
    pDescriptorUpdateEntries            DWORD ? ; * const VkDescriptorUpdateTemplateEntry*
    templateType                        DWORD ? ; VkDescriptorUpdateTemplateType enum value
    descriptorSetLayout                 VkDescriptorSetLayout ?
    pipelineBindPoint                   DWORD ? ; VkPipelineBindPoint enum value
    pipelineLayout                      VkPipelineLayout ?
    set                                 DWORD ? ; uint32_t
VkDescriptorUpdateTemplateCreateInfo    ENDS

VkExternalMemoryProperties              STRUCT
    externalMemoryFeatures              VkExternalMemoryFeatureFlags ?
    exportFromImportedHandleTypes       VkExternalMemoryHandleTypeFlags ?
    compatibleHandleTypes               VkExternalMemoryHandleTypeFlags ?
VkExternalMemoryProperties              ENDS

VkPhysicalDeviceExternalImageFormatInfo STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
VkPhysicalDeviceExternalImageFormatInfo ENDS

VkExternalImageFormatProperties         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    externalMemoryProperties            VkExternalMemoryProperties <>
VkExternalImageFormatProperties         ENDS

VkPhysicalDeviceExternalBufferInfo      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkBufferCreateFlags ?
    usage                               VkBufferUsageFlags ?
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
VkPhysicalDeviceExternalBufferInfo      ENDS

VkExternalBufferProperties              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    externalMemoryProperties            VkExternalMemoryProperties <>
VkExternalBufferProperties              ENDS

VkPhysicalDeviceIDProperties            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceUUID                          DB VK_UUID_SIZE DUP (?) ; uint8_t
    driverUUID                          DB VK_UUID_SIZE DUP (?) ; uint8_t
    deviceLUID                          DB VK_LUID_SIZE DUP (?) ; uint8_t
    deviceNodeMask                      DWORD ? ; uint32_t
    deviceLUIDValid                     VkBool32 ?
VkPhysicalDeviceIDProperties            ENDS

VkExternalMemoryImageCreateInfo         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalMemoryHandleTypeFlags ?
VkExternalMemoryImageCreateInfo         ENDS

VkExternalMemoryBufferCreateInfo        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalMemoryHandleTypeFlags ?
VkExternalMemoryBufferCreateInfo        ENDS

VkExportMemoryAllocateInfo              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalMemoryHandleTypeFlags ?
VkExportMemoryAllocateInfo              ENDS

VkPhysicalDeviceExternalFenceInfo       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalFenceHandleTypeFlagBits ?
VkPhysicalDeviceExternalFenceInfo       ENDS

VkExternalFenceProperties               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    exportFromImportedHandleTypes       VkExternalFenceHandleTypeFlags ?
    compatibleHandleTypes               VkExternalFenceHandleTypeFlags ?
    externalFenceFeatures               VkExternalFenceFeatureFlags ?
VkExternalFenceProperties               ENDS

VkExportFenceCreateInfo                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalFenceHandleTypeFlags ?
VkExportFenceCreateInfo                 ENDS

VkExportSemaphoreCreateInfo             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalSemaphoreHandleTypeFlags ?
VkExportSemaphoreCreateInfo             ENDS

VkPhysicalDeviceExternalSemaphoreInfo   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalSemaphoreHandleTypeFlagBits ?
VkPhysicalDeviceExternalSemaphoreInfo   ENDS

VkExternalSemaphoreProperties           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    exportFromImportedHandleTypes       VkExternalSemaphoreHandleTypeFlags ?
    compatibleHandleTypes               VkExternalSemaphoreHandleTypeFlags ?
    externalSemaphoreFeatures           VkExternalSemaphoreFeatureFlags ?
VkExternalSemaphoreProperties           ENDS

VkPhysicalDeviceMaintenance3Properties  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxPerSetDescriptors                DWORD ? ; uint32_t
    maxMemoryAllocationSize             VkDeviceSize ? ; qword
VkPhysicalDeviceMaintenance3Properties  ENDS

VkDescriptorSetLayoutSupport            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    supported                           VkBool32 ?
VkDescriptorSetLayoutSupport            ENDS

VkPhysicalDeviceShaderDrawParameterFeatures STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    shaderDrawParameters                VkBool32 ?
VkPhysicalDeviceShaderDrawParameterFeatures ENDS


VkSurfaceCapabilitiesKHR                STRUCT
    minImageCount                       DWORD ? ; uint32_t
    maxImageCount                       DWORD ? ; uint32_t
    currentExtent                       VkExtent2D <>
    minImageExtent                      VkExtent2D <>
    maxImageExtent                      VkExtent2D <>
    maxImageArrayLayers                 DWORD ? ; uint32_t
    supportedTransforms                 VkSurfaceTransformFlagsKHR ?
    currentTransform                    DWORD ? ; VkSurfaceTransformFlagBitsKHR enum value
    supportedCompositeAlpha             VkCompositeAlphaFlagsKHR ?
    supportedUsageFlags                 VkImageUsageFlags ?
VkSurfaceCapabilitiesKHR                ENDS

VkSurfaceFormatKHR                      STRUCT
    format                              DWORD ? ; VkFormat enum value
    colorSpace                          DWORD ? ; VkColorSpaceKHR enum value
VkSurfaceFormatKHR                      ENDS

VkSwapchainCreateInfoKHR                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkSwapchainCreateFlagsKHR ?
    surface                             VkSurfaceKHR ?
    minImageCount                       DWORD ? ; uint32_t
    imageFormat                         DWORD ? ; VkFormat enum value
    imageColorSpace                     DWORD ? ; VkColorSpaceKHR enum value
    imageExtent                         VkExtent2D <>
    imageArrayLayers                    DWORD ? ; uint32_t
    imageUsage                          VkImageUsageFlags ?
    imageSharingMode                    DWORD ? ; VkSharingMode enum value
    queueFamilyIndexCount               DWORD ? ; uint32_t
    pQueueFamilyIndices                 DWORD ? ; * uint32_t* 
    preTransform                        DWORD ? ; VkSurfaceTransformFlagBitsKHR enum value
    compositeAlpha                      DWORD ? ; VkCompositeAlphaFlagBitsKHR enum value
    presentMode                         DWORD ? ; VkPresentModeKHR enum value
    clipped                             VkBool32 ?
    oldSwapchain                        VkSwapchainKHR ?
VkSwapchainCreateInfoKHR                ENDS

VkPresentInfoKHR                        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    waitSemaphoreCount                  DWORD ? ; uint32_t
    pWaitSemaphores                     DWORD ? ; * VkSemaphore*
    swapchainCount                      DWORD ? ; uint32_t
    pSwapchains                         DWORD ? ; * VkSwapchainKHR*
    pImageIndices                       DWORD ? ; * uint32_t*
    pResults                            DWORD ? ; * VkResult*
VkPresentInfoKHR                        ENDS

VkImageSwapchainCreateInfoKHR           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchain                           VkSwapchainKHR ?
VkImageSwapchainCreateInfoKHR           ENDS

VkBindImageMemorySwapchainInfoKHR       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchain                           VkSwapchainKHR ?
    imageIndex                          DWORD ? ; uint32_t
VkBindImageMemorySwapchainInfoKHR       ENDS

VkAcquireNextImageInfoKHR               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchain                           VkSwapchainKHR ?
    timeout                             QWORD ? ; uint64_t
    semaphore                           VkSemaphore ?
    fence                               VkFence ?
    deviceMask                          DWORD ? ; uint32_t
VkAcquireNextImageInfoKHR               ENDS

VkDeviceGroupPresentCapabilitiesKHR     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    presentMask                         DWORD VK_MAX_DEVICE_GROUP_SIZE DUP (?) ; uint32_t
    modes                               VkDeviceGroupPresentModeFlagsKHR ?
VkDeviceGroupPresentCapabilitiesKHR     ENDS

VkDeviceGroupPresentInfoKHR             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchainCount                      DWORD ? ; uint32_t
    pDeviceMasks                        DWORD ? ; * const uint32_t*
    mode                                DWORD ? ; VkDeviceGroupPresentModeFlagBitsKHR enum value
VkDeviceGroupPresentInfoKHR             ENDS

VkDeviceGroupSwapchainCreateInfoKHR     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    modes                               VkDeviceGroupPresentModeFlagsKHR ?
VkDeviceGroupSwapchainCreateInfoKHR     ENDS

VkDisplayPropertiesKHR                  STRUCT
    display                             VkDisplayKHR ?
    displayName                         DWORD ? ; * const char*
    physicalDimensions                  VkExtent2D <>
    physicalResolution                  VkExtent2D <>
    supportedTransforms                 VkSurfaceTransformFlagsKHR ?
    planeReorderPossible                VkBool32 ?
    persistentContent                   VkBool32 ?
VkDisplayPropertiesKHR                  ENDS

VkDisplayModeParametersKHR              STRUCT
    visibleRegion                       VkExtent2D <>
    refreshRate                         DWORD ? ; uint32_t
VkDisplayModeParametersKHR              ENDS

VkDisplayModePropertiesKHR              STRUCT
    displayMode                         VkDisplayModeKHR ?
    parameters                          VkDisplayModeParametersKHR <>
VkDisplayModePropertiesKHR              ENDS

VkDisplayModeCreateInfoKHR              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; * const void*
    flags                               VkDisplayModeCreateFlagsKHR ?
    parameters                          VkDisplayModeParametersKHR <>
VkDisplayModeCreateInfoKHR              ENDS

VkDisplayPlaneCapabilitiesKHR           STRUCT
    supportedAlpha                      VkDisplayPlaneAlphaFlagsKHR ?
    minSrcPosition                      VkOffset2D <>
    maxSrcPosition                      VkOffset2D <>
    minSrcExtent                        VkExtent2D <>
    maxSrcExtent                        VkExtent2D <>
    minDstPosition                      VkOffset2D <>
    maxDstPosition                      VkOffset2D <>
    minDstExtent                        VkExtent2D <>
    maxDstExtent                        VkExtent2D <>
VkDisplayPlaneCapabilitiesKHR           ENDS

VkDisplayPlanePropertiesKHR             STRUCT
    currentDisplay                      VkDisplayKHR ?
    currentStackIndex                   DWORD ? ; uint32_t
VkDisplayPlanePropertiesKHR             ENDS

VkDisplaySurfaceCreateInfoKHR           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDisplaySurfaceCreateFlagsKHR ?
    displayMode                         VkDisplayModeKHR ?
    planeIndex                          DWORD ? ; uint32_t
    planeStackIndex                     DWORD ? ; uint32_t
    transform                           DWORD ? ; VkSurfaceTransformFlagBitsKHR enum value
    globalAlpha                         REAL4 ? ; float
    alphaMode                           DWORD ? ; VkDisplayPlaneAlphaFlagBitsKHR enum value
    imageExtent                         VkExtent2D <>
VkDisplaySurfaceCreateInfoKHR           ENDS

VkDisplayPresentInfoKHR                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcRect                             VkRect2D <>
    dstRect                             VkRect2D <>
    persistent                          VkBool32 ?
VkDisplayPresentInfoKHR                 ENDS

VkImportMemoryFdInfoKHR                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
    fd                                  DWORD ? ; int                                   
VkImportMemoryFdInfoKHR                 ENDS

VkMemoryFdPropertiesKHR                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryTypeBits                      DWORD ? ; uint32_t
VkMemoryFdPropertiesKHR                 ENDS

VkMemoryGetFdInfoKHR                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memory                              VkDeviceMemory ?
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
VkMemoryGetFdInfoKHR                    ENDS

VkImportSemaphoreFdInfoKHR              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    semaphore                           VkSemaphore ?
    flags                               VkSemaphoreImportFlags ?
    handleType                          VkExternalSemaphoreHandleTypeFlagBits ?
    fd                                  DWORD ? ; int  
VkImportSemaphoreFdInfoKHR              ENDS

VkSemaphoreGetFdInfoKHR                 STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    semaphore                           VkSemaphore ?
    handleType                          VkExternalSemaphoreHandleTypeFlagBits ?
VkSemaphoreGetFdInfoKHR                 ENDS

VkPhysicalDevicePushDescriptorPropertiesKHR STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxPushDescriptors                  DWORD ? ; uint32_t
VkPhysicalDevicePushDescriptorPropertiesKHR ENDS

VkRectLayerKHR                          STRUCT
    offset_                             VkOffset2D <>
    extent                              VkExtent2D <>
    layer                               DWORD ? ; uint32_t
VkRectLayerKHR                          ENDS

VkPresentRegionKHR                      STRUCT
    rectangleCount                      DWORD ? ; uint32_t
    pRectangles                         DWORD ? ; * const VkRectLayerKHR*
VkPresentRegionKHR                      ENDS

VkPresentRegionsKHR                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchainCount                      DWORD ? ; uint32_t
    pRegions                            DWORD ? ; * const VkPresentRegionKHR*
VkPresentRegionsKHR                     ENDS

VkSharedPresentSurfaceCapabilitiesKHR   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    sharedPresentSupportedUsageFlags    VkImageUsageFlags ?
VkSharedPresentSurfaceCapabilitiesKHR   ENDS

VkImportFenceFdInfoKHR                  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    fence                               VkFence ?
    flags                               VkFenceImportFlags ?
    handleType                          VkExternalFenceHandleTypeFlagBits ?
    fd                                  DWORD ? ; int 
VkImportFenceFdInfoKHR                  ENDS

VkFenceGetFdInfoKHR                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    fence                               VkFence ?
    handleType                          VkExternalFenceHandleTypeFlagBits ?
VkFenceGetFdInfoKHR                     ENDS

VkPhysicalDeviceSurfaceInfo2KHR         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    surface                             VkSurfaceKHR ?
VkPhysicalDeviceSurfaceInfo2KHR         ENDS

VkSurfaceCapabilities2KHR               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    surfaceCapabilities                 VkSurfaceCapabilitiesKHR <>
VkSurfaceCapabilities2KHR               ENDS

VkSurfaceFormat2KHR                     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    surfaceFormat                       VkSurfaceFormatKHR <>
VkSurfaceFormat2KHR                     ENDS

VkImageFormatListCreateInfoKHR          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    viewFormatCount                     DWORD ? ; uint32_t
    pViewFormats                        DWORD ? ; * VkFormat*
VkImageFormatListCreateInfoKHR          ENDS

VkDebugReportCallbackCreateInfoEXT      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDebugReportFlagsEXT ?
    pfnCallback                         DWORD ? ; * PFN_vkDebugReportCallbackEXT
    pUserData                           DWORD ? ; * void*
VkDebugReportCallbackCreateInfoEXT      ENDS

VkPipelineRasterizationStateRasterizationOrderAMD STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    rasterizationOrder                  DWORD ? ; VkRasterizationOrderAMD enum value
VkPipelineRasterizationStateRasterizationOrderAMD ENDS

VkDebugMarkerObjectNameInfoEXT          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectType                          DWORD ? ; VkDebugReportObjectTypeEXT enum value
    object                              QWORD ? ; uint64_t
    pObjectName                         DWORD ? ; * const char*
VkDebugMarkerObjectNameInfoEXT          ENDS

VkDebugMarkerObjectTagInfoEXT           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectType                          DWORD ? ; VkDebugReportObjectTypeEXT enum value
    object                              QWORD ? ; uint64_t
    tagName                             QWORD ? ; uint64_t
    tagSize                             DWORD ? ; size_t
    pTag                                DWORD ? ; * const void*
VkDebugMarkerObjectTagInfoEXT           ENDS

VkDebugMarkerMarkerInfoEXT              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pMarkerName                         DWORD ? ; * const char*
    color                               REAL4 4 DUP (?) ; float
VkDebugMarkerMarkerInfoEXT              ENDS

VkDedicatedAllocationImageCreateInfoNV  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    dedicatedAllocation                 VkBool32 ?
VkDedicatedAllocationImageCreateInfoNV  ENDS

VkDedicatedAllocationBufferCreateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    dedicatedAllocation                 VkBool32 ?
VkDedicatedAllocationBufferCreateInfoNV ENDS

VkDedicatedAllocationMemoryAllocateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    image                               VkImage ?
    buffer                              VkBuffer ?
VkDedicatedAllocationMemoryAllocateInfoNV ENDS

VkTextureLODGatherFormatPropertiesAMD   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    supportsTextureGatherLODBiasAMD     VkBool32 ?
VkTextureLODGatherFormatPropertiesAMD   ENDS

VkShaderResourceUsageAMD                STRUCT
    numUsedVgprs                        DWORD ? ; uint32_t
    numUsedSgprs                        DWORD ? ; uint32_t
    ldsSizePerLocalWorkGroup            DWORD ? ; uint32_t
    ldsUsageSizeInBytes                 DWORD ? ; size_t
    scratchMemUsageInBytes              DWORD ? ; size_t
VkShaderResourceUsageAMD                ENDS

VkShaderStatisticsInfoAMD               STRUCT
    shaderStageMask                     VkShaderStageFlags ?
    resourceUsage                       VkShaderResourceUsageAMD <>
    numPhysicalVgprs                    DWORD ? ; uint32_t
    numPhysicalSgprs                    DWORD ? ; uint32_t
    numAvailableVgprs                   DWORD ? ; uint32_t
    numAvailableSgprs                   DWORD ? ; uint32_t
    computeWorkGroupSize                DWORD 3 DUP (?) ; uint32_t
VkShaderStatisticsInfoAMD               ENDS

VkExternalImageFormatPropertiesNV       STRUCT
    imageFormatProperties               VkImageFormatProperties <>
    externalMemoryFeatures              VkExternalMemoryFeatureFlagsNV ?
    exportFromImportedHandleTypes       VkExternalMemoryHandleTypeFlagsNV ?
    compatibleHandleTypes               VkExternalMemoryHandleTypeFlagsNV ?
VkExternalImageFormatPropertiesNV       ENDS

VkExternalMemoryImageCreateInfoNV       STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalMemoryHandleTypeFlagsNV ?
VkExternalMemoryImageCreateInfoNV       ENDS

VkExportMemoryAllocateInfoNV            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleTypes                         VkExternalMemoryHandleTypeFlagsNV ?
VkExportMemoryAllocateInfoNV            ENDS

VkValidationFlagsEXT                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    disabledValidationCheckCount        DWORD ? ; uint32_t
    pDisabledValidationChecks           DWORD ? ; * VkValidationCheckEXT*
VkValidationFlagsEXT                    ENDS

VkDeviceGeneratedCommandsFeaturesNVX    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    computeBindingPointSupport          VkBool32 ?
VkDeviceGeneratedCommandsFeaturesNVX    ENDS

VkDeviceGeneratedCommandsLimitsNVX      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxIndirectCommandsLayoutTokenCount DWORD ? ; uint32_t
    maxObjectEntryCounts                DWORD ? ; uint32_t
    minSequenceCountBufferOffsetAlignment DWORD ? ; uint32_t
    minSequenceIndexBufferOffsetAlignment DWORD ? ; uint32_t
    minCommandsTokenBufferOffsetAlignment DWORD ? ; uint32_t
VkDeviceGeneratedCommandsLimitsNVX      ENDS

VkIndirectCommandsTokenNVX              STRUCT
    tokenType                           DWORD ? ; VkIndirectCommandsTokenTypeNVX enum value
    buffer                              VkBuffer ?
    offset_                             VkDeviceSize ? ; qword
VkIndirectCommandsTokenNVX              ENDS

VkIndirectCommandsLayoutTokenNVX        STRUCT
    tokenType                           DWORD ? ; VkIndirectCommandsTokenTypeNVX enum value
    bindingUnit                         DWORD ? ; uint32_t
    dynamicCount                        DWORD ? ; uint32_t
    divisor                             DWORD ? ; uint32_t
VkIndirectCommandsLayoutTokenNVX        ENDS

VkIndirectCommandsLayoutCreateInfoNVX   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pipelineBindPoint                   DWORD ? ; VkPipelineBindPoint enum value
    flags                               VkIndirectCommandsLayoutUsageFlagsNVX ?
    tokenCount                          DWORD ? ; uint32_t
    pTokens                             DWORD ? ; * const VkIndirectCommandsLayoutTokenNVX*
VkIndirectCommandsLayoutCreateInfoNVX   ENDS

VkCmdProcessCommandsInfoNVX             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectTable                         VkObjectTableNVX ?
    indirectCommandsLayout              VkIndirectCommandsLayoutNVX ?
    indirectCommandsTokenCount          DWORD ? ; uint32_t
    pIndirectCommandsTokens             DWORD ? ; * const VkIndirectCommandsTokenNVX*
    maxSequencesCount                   DWORD ? ; uint32_t
    targetCommandBuffer                 VkCommandBuffer ?
    sequencesCountBuffer                VkBuffer ?
    sequencesCountOffset                VkDeviceSize ? ; qword
    sequencesIndexBuffer                VkBuffer ?
    sequencesIndexOffset                VkDeviceSize ? ; qword
VkCmdProcessCommandsInfoNVX             ENDS

VkCmdReserveSpaceForCommandsInfoNVX     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectTable                         VkObjectTableNVX ?
    indirectCommandsLayout              VkIndirectCommandsLayoutNVX ?
    maxSequencesCount                   DWORD ? ; uint32_t
VkCmdReserveSpaceForCommandsInfoNVX     ENDS

VkObjectTableCreateInfoNVX              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectCount                         DWORD ? ; uint32_t
    pObjectEntryTypes                   DWORD ? ; * const VkObjectEntryTypeNVX*
    pObjectEntryCounts                  DWORD ? ; * const uint32_t*
    pObjectEntryUsageFlags              DWORD ? ; * const VkObjectEntryUsageFlagsNVX*
    maxUniformBuffersPerDescriptor      DWORD ? ; uint32_t
    maxStorageBuffersPerDescriptor      DWORD ? ; uint32_t
    maxStorageImagesPerDescriptor       DWORD ? ; uint32_t
    maxSampledImagesPerDescriptor       DWORD ? ; uint32_t
    maxPipelineLayouts                  DWORD ? ; uint32_t
VkObjectTableCreateInfoNVX              ENDS

VkObjectTableEntryNVX                   STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
VkObjectTableEntryNVX                   ENDS

VkObjectTablePipelineEntryNVX           STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
    pipeline                            VkPipeline ?
VkObjectTablePipelineEntryNVX           ENDS

VkObjectTableDescriptorSetEntryNVX      STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
    pipelineLayout                      VkPipelineLayout ?
    descriptorSet                       VkDescriptorSet ?
VkObjectTableDescriptorSetEntryNVX      ENDS

VkObjectTableVertexBufferEntryNVX       STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
    buffer                              VkBuffer ?
VkObjectTableVertexBufferEntryNVX       ENDS

VkObjectTableIndexBufferEntryNVX        STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
    buffer                              VkBuffer ?
    indexType                           DWORD ? ; VkIndexType enum value
VkObjectTableIndexBufferEntryNVX        ENDS

VkObjectTablePushConstantEntryNVX       STRUCT
    type_                               DWORD ? ; VkObjectEntryTypeNVX enum value
    flags                               VkObjectEntryUsageFlagsNVX ?
    pipelineLayout                      VkPipelineLayout ?
    stageFlags                          VkShaderStageFlags ?
VkObjectTablePushConstantEntryNVX       ENDS

VkViewportWScalingNV                    STRUCT
    xcoeff                              REAL4 ? ; float
    ycoeff                              REAL4 ? ; float
VkViewportWScalingNV                    ENDS

VkPipelineViewportWScalingStateCreateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    viewportWScalingEnable              VkBool32 ?
    viewportCount                       DWORD ? ; uint32_t
    pViewportWScalings                  DWORD ? ; * const VkViewportWScalingNV*
VkPipelineViewportWScalingStateCreateInfoNV ENDS

VkSurfaceCapabilities2EXT               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    minImageCount                       DWORD ? ; uint32_t
    maxImageCount                       DWORD ? ; uint32_t
    currentExtent                       VkExtent2D <>
    minImageExtent                      VkExtent2D <>
    maxImageExtent                      VkExtent2D <>
    maxImageArrayLayers                 DWORD ? ; uint32_t
    supportedTransforms                 VkSurfaceTransformFlagsKHR ?
    currentTransform                    DWORD ? ; VkSurfaceTransformFlagBitsKHR enum value
    supportedCompositeAlpha             VkCompositeAlphaFlagsKHR ?
    supportedUsageFlags                 VkImageUsageFlags ?
    supportedSurfaceCounters            VkSurfaceCounterFlagsEXT ?
VkSurfaceCapabilities2EXT               ENDS

VkDisplayPowerInfoEXT                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    powerState                          DWORD ? ; VkDisplayPowerStateEXT enum value
VkDisplayPowerInfoEXT                   ENDS

VkDeviceEventInfoEXT                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    deviceEvent                         DWORD ? ; VkDeviceEventTypeEXT enum value
VkDeviceEventInfoEXT                    ENDS

VkDisplayEventInfoEXT                   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    displayEvent                        DWORD ? ; VkDisplayEventTypeEXT enum value
VkDisplayEventInfoEXT                   ENDS

VkSwapchainCounterCreateInfoEXT         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    surfaceCounters                     VkSurfaceCounterFlagsEXT ?
VkSwapchainCounterCreateInfoEXT         ENDS

VkRefreshCycleDurationGOOGLE            STRUCT
    refreshDuration                     QWORD ? ; uint64_t
VkRefreshCycleDurationGOOGLE            ENDS

VkPastPresentationTimingGOOGLE          STRUCT
    presentID                           DWORD ? ; uint32_t
    desiredPresentTime                  QWORD ? ; uint64_t
    actualPresentTime                   QWORD ? ; uint64_t
    earliestPresentTime                 QWORD ? ; uint64_t
    presentMargin                       QWORD ? ; uint64_t
VkPastPresentationTimingGOOGLE          ENDS

VkPresentTimeGOOGLE                     STRUCT
    presentID                           DWORD ? ; uint32_t
    desiredPresentTime                  QWORD ? ; uint64_t
VkPresentTimeGOOGLE                     ENDS

VkPresentTimesInfoGOOGLE                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    swapchainCount                      DWORD ? ; uint32_t
    pTimes                              DWORD ? ; * const VkPresentTimeGOOGLE*
VkPresentTimesInfoGOOGLE                ENDS

VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    perViewPositionAllComponents        VkBool32 ?
VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX ENDS

VkViewportSwizzleNV                     STRUCT
    x                                   DWORD ? ; VkViewportCoordinateSwizzleNV enum value
    y                                   DWORD ? ; VkViewportCoordinateSwizzleNV enum value
    z                                   DWORD ? ; VkViewportCoordinateSwizzleNV enum value
    w                                   DWORD ? ; VkViewportCoordinateSwizzleNV enum value
VkViewportSwizzleNV                     ENDS

VkPipelineViewportSwizzleStateCreateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineViewportSwizzleStateCreateFlagsNV ?
    viewportCount                       DWORD ? ; uint32_t
    pViewportSwizzles                   DWORD ? ; * const VkViewportSwizzleNV*
VkPipelineViewportSwizzleStateCreateInfoNV ENDS

VkPhysicalDeviceDiscardRectanglePropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxDiscardRectangles                DWORD ? ; uint32_t
VkPhysicalDeviceDiscardRectanglePropertiesEXT ENDS

VkPipelineDiscardRectangleStateCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineDiscardRectangleStateCreateFlagsEXT ?
    discardRectangleMode                DWORD ? ; VkDiscardRectangleModeEXT enum value
    discardRectangleCount               DWORD ? ; uint32_t
    pDiscardRectangles                  DWORD ? ; * const VkRect2D*
VkPipelineDiscardRectangleStateCreateInfoEXT ENDS

VkPhysicalDeviceConservativeRasterizationPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    primitiveOverestimationSize         REAL4 ? ; float
    maxExtraPrimitiveOverestimationSize REAL4 ? ; float
    extraPrimitiveOverestimationSizeGranularity REAL4 ? ; float
    primitiveUnderestimation            VkBool32 ?
    conservativePointAndLineRasterization VkBool32 ?
    degenerateTrianglesRasterized       VkBool32 ?
    degenerateLinesRasterized           VkBool32 ?
    fullyCoveredFragmentShaderInputVariable VkBool32 ?
    conservativeRasterizationPostDepthCoverage VkBool32 ?
VkPhysicalDeviceConservativeRasterizationPropertiesEXT ENDS

VkPipelineRasterizationConservativeStateCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineRasterizationConservativeStateCreateFlagsEXT ?
    conservativeRasterizationMode       DWORD ? ; VkConservativeRasterizationModeEXT enum value
    extraPrimitiveOverestimationSize    REAL4 ? ; float
VkPipelineRasterizationConservativeStateCreateInfoEXT ENDS

VkXYColorEXT                            STRUCT
    x                                   REAL4 ? ; float
    y                                   REAL4 ? ; float
VkXYColorEXT                            ENDS

VkHdrMetadataEXT                        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    displayPrimaryRed                   VkXYColorEXT <>
    displayPrimaryGreen                 VkXYColorEXT <>
    displayPrimaryBlue                  VkXYColorEXT <>
    whitePoint                          VkXYColorEXT <>
    maxLuminance                        REAL4 ? ; float
    minLuminance                        REAL4 ? ; float
    maxContentLightLevel                REAL4 ? ; float
    maxFrameAverageLightLevel           REAL4 ? ; float
VkHdrMetadataEXT                        ENDS

VkDebugUtilsObjectNameInfoEXT           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectType                          DWORD ? ; VkObjectType enum value
    objectHandle                        QWORD ? ; uint64_t
    pObjectName                         DWORD ? ; * const char*
VkDebugUtilsObjectNameInfoEXT           ENDS

VkDebugUtilsObjectTagInfoEXT            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    objectType                          DWORD ? ; VkObjectType enum value
    objectHandle                        QWORD ? ; uint64_t
    tagName                             QWORD ? ; uint64_t
    tagSize                             DWORD ? ; size_t
    pTag                                DWORD ? ; * const void*
VkDebugUtilsObjectTagInfoEXT            ENDS

VkDebugUtilsLabelEXT                    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pLabelName                          DWORD ? ; * const char*
    color                               REAL4 4 DUP (?) ; float[4];
VkDebugUtilsLabelEXT                    ENDS

VkDebugUtilsMessengerCallbackDataEXT    STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDebugUtilsMessengerCallbackDataFlagsEXT ?
    pMessageIdName                      DWORD ? ; * const char*
    messageIdNumber                     DWORD ? ; int32_t
    pMessage                            DWORD ? ; * const char*
    queueLabelCount                     DWORD ? ; uint32_t
    pQueueLabels                        DWORD ? ; * VkDebugUtilsLabelEXT*
    cmdBufLabelCount                    DWORD ? ; uint32_t
    pCmdBufLabels                       DWORD ? ; * VkDebugUtilsLabelEXT*
    objectCount                         DWORD ? ; uint32_t
    pObjects                            DWORD ? ; * VkDebugUtilsObjectNameInfoEXT*
VkDebugUtilsMessengerCallbackDataEXT    ENDS

VkDebugUtilsMessengerCreateInfoEXT      STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkDebugUtilsMessengerCreateFlagsEXT ?
    messageSeverity                     VkDebugUtilsMessageSeverityFlagsEXT ?
    messageType                         VkDebugUtilsMessageTypeFlagsEXT ?
    pfnUserCallback                     DWORD ? ; * PFN_vkDebugUtilsMessengerCallbackEXT
    pUserData                           DWORD ? ; * void*
VkDebugUtilsMessengerCreateInfoEXT      ENDS

VkSamplerReductionModeCreateInfoEXT     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    reductionMode                       DWORD ? ; VkSamplerReductionModeEXT enum value
VkSamplerReductionModeCreateInfoEXT     ENDS

VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    filterMinmaxSingleComponentFormats  VkBool32 ?
    filterMinmaxImageComponentMapping   VkBool32 ?
VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT ENDS

VkSampleLocationEXT                     STRUCT
    x                                   REAL4 ? ; float
    y                                   REAL4 ? ; float
VkSampleLocationEXT                     ENDS

VkSampleLocationsInfoEXT                STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    sampleLocationsPerPixel             DWORD ? ; VkSampleCountFlagBits enum value
    sampleLocationGridSize              VkExtent2D <>
    sampleLocationsCount                DWORD ? ; uint32_t
    pSampleLocations                    DWORD ? ; * const VkSampleLocationEXT*
VkSampleLocationsInfoEXT                ENDS

VkAttachmentSampleLocationsEXT          STRUCT
    attachmentIndex                     DWORD ? ; uint32_t
    sampleLocationsInfo                 VkSampleLocationsInfoEXT <>
VkAttachmentSampleLocationsEXT          ENDS

VkSubpassSampleLocationsEXT             STRUCT
    subpassIndex                        DWORD ? ; uint32_t
    sampleLocationsInfo                 VkSampleLocationsInfoEXT <>
VkSubpassSampleLocationsEXT             ENDS

VkRenderPassSampleLocationsBeginInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    attachmentInitialSampleLocationsCount DWORD ? ; uint32_t
    pAttachmentInitialSampleLocations   DWORD ? ; * const VkAttachmentSampleLocationsEXT*
    postSubpassSampleLocationsCount     DWORD ? ; uint32_t
    pPostSubpassSampleLocations         DWORD ? ; * const VkSubpassSampleLocationsEXT*
VkRenderPassSampleLocationsBeginInfoEXT ENDS

VkPipelineSampleLocationsStateCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    sampleLocationsEnable               VkBool32 ?
    sampleLocationsInfo                 VkSampleLocationsInfoEXT <>
VkPipelineSampleLocationsStateCreateInfoEXT ENDS

VkPhysicalDeviceSampleLocationsPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    sampleLocationSampleCounts          VkSampleCountFlags ?
    maxSampleLocationGridSize           VkExtent2D <>
    sampleLocationCoordinateRange       REAL4 2 DUP (?) ; float[2];
    sampleLocationSubPixelBits          DWORD ? ; uint32_t
    variableSampleLocations             VkBool32 ?
VkPhysicalDeviceSampleLocationsPropertiesEXT ENDS

VkMultisamplePropertiesEXT              STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxSampleLocationGridSize           VkExtent2D <>
VkMultisamplePropertiesEXT              ENDS

VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    advancedBlendCoherentOperations     VkBool32 ?
VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT ENDS

VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    advancedBlendMaxColorAttachments    DWORD ? ; uint32_t
    advancedBlendIndependentBlend       VkBool32 ?
    advancedBlendNonPremultipliedSrcColor VkBool32 ?
    advancedBlendNonPremultipliedDstColor VkBool32 ?
    advancedBlendCorrelatedOverlap      VkBool32 ?
    advancedBlendAllOperations          VkBool32 ?
VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT ENDS

VkPipelineColorBlendAdvancedStateCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    srcPremultiplied                    VkBool32 ?
    dstPremultiplied                    VkBool32 ?
    blendOverlap                        DWORD ? ; VkBlendOverlapEXT enum value
VkPipelineColorBlendAdvancedStateCreateInfoEXT ENDS

VkPipelineCoverageToColorStateCreateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineCoverageToColorStateCreateFlagsNV ?
    coverageToColorEnable               VkBool32 ?
    coverageToColorLocation             DWORD ? ; uint32_t
VkPipelineCoverageToColorStateCreateInfoNV ENDS

VkPipelineCoverageModulationStateCreateInfoNV STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkPipelineCoverageModulationStateCreateFlagsNV ?
    coverageModulationMode              DWORD ? ; VkCoverageModulationModeNV enum value
    coverageModulationTableEnable       VkBool32 ?
    coverageModulationTableCount        DWORD ? ; uint32_t
    pCoverageModulationTable            DWORD ? ; * const float*
VkPipelineCoverageModulationStateCreateInfoNV ENDS

VkValidationCacheCreateInfoEXT          STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkValidationCacheCreateFlagsEXT ?
    initialDataSize                     DWORD ? ; size_t
    pInitialData                        DWORD ? ; * const void*
VkValidationCacheCreateInfoEXT          ENDS

VkShaderModuleValidationCacheCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    validationCache                     VkValidationCacheEXT ?
VkShaderModuleValidationCacheCreateInfoEXT ENDS

VkDeviceQueueGlobalPriorityCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    globalPriority                      DWORD ? ; VkQueueGlobalPriorityEXT enum value
VkDeviceQueueGlobalPriorityCreateInfoEXT ENDS

VkImportMemoryHostPointerInfoEXT        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
    pHostPointer                        DWORD ? ; * void*
VkImportMemoryHostPointerInfoEXT        ENDS

VkMemoryHostPointerPropertiesEXT        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryTypeBits                      DWORD ? ; uint32_t
VkMemoryHostPointerPropertiesEXT        ENDS

VkPhysicalDeviceExternalMemoryHostPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    minImportedHostPointerAlignment     VkDeviceSize ? ; qword
VkPhysicalDeviceExternalMemoryHostPropertiesEXT ENDS

VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    maxVertexAttribDivisor              DWORD ? ; uint32_t
VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT ENDS

VkVertexInputBindingDivisorDescriptionEXT STRUCT
    binding                               DWORD ? ; uint32_t
    divisor                               DWORD ? ; uint32_t
VkVertexInputBindingDivisorDescriptionEXT ENDS

VkPipelineVertexInputDivisorStateCreateInfoEXT STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    vertexBindingDivisorCount           DWORD ? ; uint32_t
    pVertexBindingDivisors              DWORD ? ; * const VkVertexInputBindingDivisorDescriptionEXT*
VkPipelineVertexInputDivisorStateCreateInfoEXT ENDS


VkWin32SurfaceCreateInfoKHR             STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    flags                               VkWin32SurfaceCreateFlagsKHR ?
    hinstance                           HINSTANCE ?
    hwnd                                HWND ?
VkWin32SurfaceCreateInfoKHR             ENDS

VkImportMemoryWin32HandleInfoKHR        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
    handle                              HANDLE ?
    name_                               LPCWSTR ?
VkImportMemoryWin32HandleInfoKHR        ENDS

VkExportMemoryWin32HandleInfoKHR        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pAttributes                         DWORD ? ; * const SECURITY_ATTRIBUTES*
    dwAccess                            DWORD ?
    name_                               LPCWSTR ?
VkExportMemoryWin32HandleInfoKHR        ENDS

VkMemoryWin32HandlePropertiesKHR        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memoryTypeBits                      DWORD ? ; uint32_t
VkMemoryWin32HandlePropertiesKHR        ENDS

VkMemoryGetWin32HandleInfoKHR           STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    memory                              VkDeviceMemory ?
    handleType                          VkExternalMemoryHandleTypeFlagBits ?
VkMemoryGetWin32HandleInfoKHR           ENDS

VkWin32KeyedMutexAcquireReleaseInfoKHR  STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    acquireCount                        DWORD ? ; uint32_t
    pAcquireSyncs                       DWORD ? ; * VkDeviceMemory*
    pAcquireKeys                        DWORD ? ; * const uint64_t*
    pAcquireTimeouts                    DWORD ? ; * const uint32_t*
    releaseCount                        DWORD ? ; uint32_t
    pReleaseSyncs                       DWORD ? ; * VkDeviceMemory*
    pReleaseKeys                        DWORD ? ; * const uint64_t*
VkWin32KeyedMutexAcquireReleaseInfoKHR  ENDS

VkImportSemaphoreWin32HandleInfoKHR     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    semaphore                           VkSemaphore ?
    flags                               VkSemaphoreImportFlags ?
    handleType                          VkExternalSemaphoreHandleTypeFlagBits ?
    handle                              HANDLE ?
    name_                               LPCWSTR ?
VkImportSemaphoreWin32HandleInfoKHR     ENDS

VkExportSemaphoreWin32HandleInfoKHR     STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pAttributes                         DWORD ? ; * const SECURITY_ATTRIBUTES*
    dwAccess                            DWORD ?
    name_                               LPCWSTR ?
VkExportSemaphoreWin32HandleInfoKHR     ENDS

VkD3D12FenceSubmitInfoKHR               STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    waitSemaphoreValuesCount            DWORD ? ; uint32_t
    pWaitSemaphoreValues                DWORD ? ; * const uint64_t*
    signalSemaphoreValuesCount          DWORD ? ; uint32_t
    pSignalSemaphoreValues              DWORD ? ; * const uint64_t*
VkD3D12FenceSubmitInfoKHR               ENDS

VkSemaphoreGetWin32HandleInfoKHR        STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    semaphore                           VkSemaphore ?
    handleType                          VkExternalSemaphoreHandleTypeFlagBits ?
VkSemaphoreGetWin32HandleInfoKHR        ENDS

VkImportFenceWin32HandleInfoKHR         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    fence                               VkFence ?
    flags                               VkFenceImportFlags ?
    handleType                          VkExternalFenceHandleTypeFlagBits ?
    handle                              HANDLE ?
    name_                               LPCWSTR ?
VkImportFenceWin32HandleInfoKHR         ENDS

VkExportFenceWin32HandleInfoKHR         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pAttributes                         DWORD ? ; * const SECURITY_ATTRIBUTES*
    dwAccess                            DWORD ?
    name_                               LPCWSTR ?
VkExportFenceWin32HandleInfoKHR         ENDS

VkFenceGetWin32HandleInfoKHR            STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    fence                               VkFence ?
    handleType                          VkExternalFenceHandleTypeFlagBits ?
VkFenceGetWin32HandleInfoKHR            ENDS

VkImportMemoryWin32HandleInfoNV         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    handleType                          VkExternalMemoryHandleTypeFlagsNV ?
    handle                              HANDLE ?
VkImportMemoryWin32HandleInfoNV         ENDS

VkExportMemoryWin32HandleInfoNV         STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    pAttributes                         DWORD ? ; * const SECURITY_ATTRIBUTES*
    dwAccess                            DWORD ?
VkExportMemoryWin32HandleInfoNV         ENDS

VkWin32KeyedMutexAcquireReleaseInfoNV   STRUCT
    sType                               DWORD ? ; VkStructureType enum value
    pNext                               DWORD ? ; *
    acquireCount                        DWORD ? ; uint32_t
    pAcquireSyncs                       DWORD ? ; * VkDeviceMemory*
    pAcquireKeys                        DWORD ? ; * const uint64_t*
    pAcquireTimeoutMilliseconds         DWORD ? ; * const uint32_t*
    releaseCount                        DWORD ? ; uint32_t
    pReleaseSyncs                       DWORD ? ; * VkDeviceMemory*
    pReleaseKeys                        DWORD ? ; * const uint64_t*
VkWin32KeyedMutexAcquireReleaseInfoNV   ENDS





.DATA
VK_KHR_SURFACE_EXTENSION_NAME                            DB "VK_KHR_surface",0
VK_KHR_SWAPCHAIN_EXTENSION_NAME                          DB "VK_KHR_swapchain",0
VK_KHR_DISPLAY_EXTENSION_NAME                            DB "VK_KHR_display",0
VK_KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME                  DB "VK_KHR_display_swapchain",0
VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME       DB "VK_KHR_sampler_mirror_clamp_to_edge",0
VK_KHR_MULTIVIEW_EXTENSION_NAME                          DB "VK_KHR_multiview",0
VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME   DB "VK_KHR_get_physical_device_properties2",0
VK_KHR_DEVICE_GROUP_EXTENSION_NAME                       DB "VK_KHR_device_group",0
VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME             DB "VK_KHR_shader_draw_parameters",0
VK_KHR_MAINTENANCE1_EXTENSION_NAME                       DB "VK_KHR_maintenance1",0
VK_KHR_DEVICE_GROUP_CREATION_EXTENSION_NAME              DB "VK_KHR_device_group_creation",0
VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME       DB "VK_KHR_external_memory_capabilities",0
VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME                    DB "VK_KHR_external_memory",0
VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME                 DB "VK_KHR_external_memory_fd",0
VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME    DB "VK_KHR_external_semaphore_capabilities",0
VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME                 DB "VK_KHR_external_semaphore",0
VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME              DB "VK_KHR_external_semaphore_fd",0
VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME                    DB "VK_KHR_push_descriptor",0
VK_KHR_16BIT_STORAGE_EXTENSION_NAME                      DB "VK_KHR_16bit_storage",0
VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME                DB "VK_KHR_incremental_present",0
VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME         DB "VK_KHR_descriptor_update_template",0
VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME           DB "VK_KHR_shared_presentable_image",0
VK_KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME        DB "VK_KHR_external_fence_capabilities",0
VK_KHR_EXTERNAL_FENCE_EXTENSION_NAME                     DB "VK_KHR_external_fence",0
VK_KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME                  DB "VK_KHR_external_fence_fd",0
VK_KHR_MAINTENANCE2_EXTENSION_NAME                       DB "VK_KHR_maintenance2",0
VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME         DB "VK_KHR_get_surface_capabilities2",0
VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME                  DB "VK_KHR_variable_pointers",0
VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME               DB "VK_KHR_dedicated_allocation",0
VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME       DB "VK_KHR_storage_buffer_storage_class",0
VK_KHR_RELAXED_BLOCK_LAYOUT_EXTENSION_NAME               DB "VK_KHR_relaxed_block_layout",0
VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME          DB "VK_KHR_get_memory_requirements2",0
VK_KHR_IMAGE_FORMAT_LIST_EXTENSION_NAME                  DB "VK_KHR_image_format_list",0
VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME           DB "VK_KHR_sampler_ycbcr_conversion",0
VK_KHR_BIND_MEMORY_2_EXTENSION_NAME                      DB "VK_KHR_bind_memory2",0
VK_KHR_MAINTENANCE3_EXTENSION_NAME                       DB "VK_KHR_maintenance3",0
VK_EXT_DEBUG_REPORT_EXTENSION_NAME                       DB "VK_EXT_debug_report",0
VK_NV_GLSL_SHADER_EXTENSION_NAME                         DB "VK_NV_glsl_shader",0
VK_EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME           DB "VK_EXT_depth_range_unrestricted",0
VK_IMG_FILTER_CUBIC_EXTENSION_NAME                       DB "VK_IMG_filter_cubic",0
VK_AMD_RASTERIZATION_ORDER_EXTENSION_NAME                DB "VK_AMD_rasterization_order",0
VK_AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME              DB "VK_AMD_shader_trinary_minmax",0
VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME   DB "VK_AMD_shader_explicit_vertex_parameter",0
VK_EXT_DEBUG_MARKER_EXTENSION_NAME                       DB "VK_EXT_debug_marker",0
VK_AMD_GCN_SHADER_EXTENSION_NAME                         DB "VK_AMD_gcn_shader",0
VK_NV_DEDICATED_ALLOCATION_EXTENSION_NAME                DB "VK_NV_dedicated_allocation",0
VK_AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME                DB "VK_AMD_draw_indirect_count",0
VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME           DB "VK_AMD_negative_viewport_height",0
VK_AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME              DB "VK_AMD_gpu_shader_half_float",0
VK_AMD_SHADER_BALLOT_EXTENSION_NAME                      DB "VK_AMD_shader_ballot",0
VK_AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME            DB "VK_AMD_texture_gather_bias_lod",0
VK_AMD_SHADER_INFO_EXTENSION_NAME                        DB "VK_AMD_shader_info",0
VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME        DB "VK_AMD_shader_image_load_store_lod",0
VK_IMG_FORMAT_PVRTC_EXTENSION_NAME                       DB "VK_IMG_format_pvrtc",0
VK_NV_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME        DB "VK_NV_external_memory_capabilities",0
VK_NV_EXTERNAL_MEMORY_EXTENSION_NAME                     DB "VK_NV_external_memory",0
VK_EXT_VALIDATION_FLAGS_EXTENSION_NAME                   DB "VK_EXT_validation_flags",0
VK_EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME             DB "VK_EXT_shader_subgroup_ballot",0
VK_EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME               DB "VK_EXT_shader_subgroup_vote",0
VK_NVX_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME          DB "VK_NVX_device_generated_commands",0
VK_NV_CLIP_SPACE_W_SCALING_EXTENSION_NAME                DB "VK_NV_clip_space_w_scaling",0
VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME                DB "VK_EXT_direct_mode_display",0
VK_EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME            DB "VK_EXT_display_surface_counter",0
VK_EXT_DISPLAY_CONTROL_EXTENSION_NAME                    DB "VK_EXT_display_control",0
VK_GOOGLE_DISPLAY_TIMING_EXTENSION_NAME                  DB "VK_GOOGLE_display_timing",0
VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_EXTENSION_NAME       DB "VK_NV_sample_mask_override_coverage",0
VK_NV_GEOMETRY_SHADER_PASSTHROUGH_EXTENSION_NAME         DB "VK_NV_geometry_shader_passthrough",0
VK_NV_VIEWPORT_ARRAY2_EXTENSION_NAME                     DB "VK_NV_viewport_array2",0
VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME      DB "VK_NVX_multiview_per_view_attributes",0
VK_NV_VIEWPORT_SWIZZLE_EXTENSION_NAME                    DB "VK_NV_viewport_swizzle",0
VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME                 DB "VK_EXT_discard_rectangles",0
VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME         DB "VK_EXT_conservative_rasterization",0
VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME              DB "VK_EXT_swapchain_colorspace",0
VK_EXT_HDR_METADATA_EXTENSION_NAME                       DB "VK_EXT_hdr_metadata",0
VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME            DB "VK_EXT_external_memory_dma_buf",0
VK_EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME               DB "VK_EXT_queue_family_foreign",0
VK_EXT_DEBUG_UTILS_EXTENSION_NAME                        DB "VK_EXT_debug_utils",0
VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME              DB "VK_EXT_sampler_filter_minmax",0
VK_AMD_GPU_SHADER_INT16_EXTENSION_NAME                   DB "VK_AMD_gpu_shader_int16",0
VK_AMD_MIXED_ATTACHMENT_SAMPLES_EXTENSION_NAME           DB "VK_AMD_mixed_attachment_samples",0
VK_AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME               DB "VK_AMD_shader_fragment_mask",0
VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME              DB "VK_EXT_shader_stencil_export",0
VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME                   DB "VK_EXT_sample_locations",0
VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME           DB "VK_EXT_blend_operation_advanced",0
VK_NV_FRAGMENT_COVERAGE_TO_COLOR_EXTENSION_NAME          DB "VK_NV_fragment_coverage_to_color",0
VK_NV_FRAMEBUFFER_MIXED_SAMPLES_EXTENSION_NAME           DB "VK_NV_framebuffer_mixed_samples",0
VK_NV_FILL_RECTANGLE_EXTENSION_NAME                      DB "VK_NV_fill_rectangle",0
VK_EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME                DB "VK_EXT_post_depth_coverage",0
VK_EXT_VALIDATION_CACHE_EXTENSION_NAME                   DB "VK_EXT_validation_cache",0
VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_EXTENSION_NAME        DB "VK_EXT_shader_viewport_index_layer",0
VK_EXT_GLOBAL_PRIORITY_EXTENSION_NAME                    DB "VK_EXT_global_priority",0
VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME               DB "VK_EXT_external_memory_host",0
VK_AMD_BUFFER_MARKER_EXTENSION_NAME                      DB "VK_AMD_buffer_marker",0
VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME           DB "VK_EXT_vertex_attribute_divisor",0
VK_KHR_WIN32_SURFACE_EXTENSION_NAME                      DB "VK_KHR_win32_surface",0
VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME              DB "VK_KHR_external_memory_win32",0
VK_KHR_WIN32_KEYED_MUTEX_EXTENSION_NAME                  DB "VK_KHR_win32_keyed_mutex",0
VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME           DB "VK_KHR_external_semaphore_win32",0
VK_KHR_EXTERNAL_FENCE_WIN32_EXTENSION_NAME               DB "VK_KHR_external_fence_win32",0
VK_NV_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME               DB "VK_NV_external_memory_win32",0
VK_NV_WIN32_KEYED_MUTEX_EXTENSION_NAME                   DB "VK_NV_win32_keyed_mutex",0

















