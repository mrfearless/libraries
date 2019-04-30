;-------------------------------------------------------------------------------------------
; OpenCL Constants, Structures & Prototypes
; https://www.khronos.org/registry/OpenCL/specs/opencl-2.2.html
;-------------------------------------------------------------------------------------------


;---------------------------------
; OpenCL Platform API Prototypes
;---------------------------------
clGetPlatformIDs                    PROTO :QWORD,:QWORD,:QWORD
clGetPlatformInfo                   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Device APIs Prototypes
;---------------------------------
clGetDeviceIDs                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetDeviceInfo                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateSubDevices                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clRetainDevice                      PROTO :QWORD
clReleaseDevice                     PROTO :QWORD
clSetDefaultDeviceCommandQueue      PROTO :QWORD,:QWORD,:QWORD
clGetDeviceAndHostTimer             PROTO :QWORD,:QWORD,:QWORD
clGetHostTimer                      PROTO :QWORD,:QWORD

;---------------------------------
; OpenCL Context APIs Prototypes
;---------------------------------
clCreateContext                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateContextFromType             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clRetainContext                     PROTO :QWORD
clReleaseContext                    PROTO :QWORD
clGetContextInfo                    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Command Queue APIs Prototypes
;---------------------------------
clCreateCommandQueueWithProperties  PROTO :QWORD,:QWORD,:QWORD,:QWORD
clRetainCommandQueue                PROTO :QWORD
clReleaseCommandQueue               PROTO :QWORD
clGetCommandQueueInfo               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Memory Object APIs Prototypes
;---------------------------------
clCreateBuffer                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateSubBuffer                   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateImage                       PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreatePipe                        PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clRetainMemObject                   PROTO :QWORD
clReleaseMemObject                  PROTO :QWORD
clGetSupportedImageFormats          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetMemObjectInfo                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetImageInfo                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetPipeInfo                       PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clSetMemObjectDestructorCallback    PROTO :QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL SVM Allocation APIs Prototypes
;---------------------------------
clSVMAlloc                          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clSVMFree                           PROTO :QWORD,:QWORD

;---------------------------------
; OpenCL Sampler APIs Prototypes
;---------------------------------
clCreateSamplerWithProperties       PROTO :QWORD,:QWORD,:QWORD
clRetainSampler                     PROTO :QWORD
clReleaseSampler                    PROTO :QWORD
clGetSamplerInfo                    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Program Object APIs Prototypes
;---------------------------------
clCreateProgramWithSource           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateProgramWithBinary           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateProgramWithBuiltInKernels   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateProgramWithIL               PROTO :QWORD,:QWORD,:QWORD,:QWORD
clRetainProgram                     PROTO :QWORD
clReleaseProgram                    PROTO :QWORD
clBuildProgram                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCompileProgram                    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clLinkProgram                       PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clUnloadPlatformCompiler            PROTO :QWORD
clGetProgramInfo                    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetProgramBuildInfo               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Kernel Object APIs Prototypes
;---------------------------------
clCreateKernel                      PROTO :QWORD,:QWORD,:QWORD
clCreateKernelsInProgram            PROTO :QWORD,:QWORD,:QWORD,:QWORD
clCloneKernel                       PROTO :QWORD,:QWORD
clRetainKernel                      PROTO :QWORD
clReleaseKernel                     PROTO :QWORD
clSetKernelArg                      PROTO :QWORD,:QWORD,:QWORD,:QWORD
clSetKernelArgSVMPointer            PROTO :QWORD,:QWORD,:QWORD
clSetKernelExecInfo                 PROTO :QWORD,:QWORD,:QWORD,:QWORD
clGetKernelInfo                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetKernelArgInfo                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetKernelWorkGroupInfo            PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetKernelSubGroupInfo             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Event Object APIs Prototypes
;---------------------------------
clWaitForEvents                     PROTO :QWORD,:QWORD
clGetEventInfo                      PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateUserEvent                   PROTO :QWORD,:QWORD
clRetainEvent                       PROTO :QWORD
clReleaseEvent                      PROTO :QWORD
clSetUserEventStatus                PROTO :QWORD,:QWORD
clSetEventCallback                  PROTO :QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Profiling APIs Prototypes
;---------------------------------
clGetEventProfilingInfo             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Flush and Finish APIs Prototypes
;---------------------------------
clFlush                             PROTO :QWORD
clFinish                            PROTO :QWORD

;---------------------------------
; OpenCL Enqueued Commands APIs Prototypes
;---------------------------------
clEnqueueReadBuffer                 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueReadBufferRect             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueWriteBuffer                PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueWriteBufferRect            PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueFillBuffer                 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueCopyBuffer                 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueCopyBufferRect             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueReadImage                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueWriteImage                 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueFillImage                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueCopyImage                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueCopyImageToBuffer          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueCopyBufferToImage          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueMapBuffer                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueMapImage                   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueUnmapMemObject             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueMigrateMemObjects          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueNDRangeKernel              PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueNativeKernel               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueMarkerWithWaitList         PROTO :QWORD,:QWORD,:QWORD,:QWORD
clEnqueueBarrierWithWaitList        PROTO :QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMFree                    PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMMemcpy                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMMemFill                 PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMMap                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMUnmap                   PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueSVMMigrateMem              PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL Extension function access Prototypes
;---------------------------------
clGetExtensionFunctionAddressForPlatform PROTO :QWORD,:QWORD

;---------------------------------
; OpenCL Deprecated OpenCL 1.1 APIs Prototypes
;---------------------------------
clCreateImage2D                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateImage3D                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueMarker                     PROTO :QWORD,:QWORD
clEnqueueWaitForEvents              PROTO :QWORD,:QWORD,:QWORD
clEnqueueBarrier                    PROTO :QWORD
clUnloadCompiler                    PROTO 
clGetExtensionFunctionAddress       PROTO :QWORD

;---------------------------------
; OpenCL Deprecated OpenCL 2.0 APIs Prototypes
;---------------------------------
clCreateCommandQueue                PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateSampler                     PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueTask                       PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; OpenCL OpenCL GL APIs Prototypes
;---------------------------------
clCreateFromGLBuffer                PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateFromGLTexture               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateFromGLRenderbuffer          PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetGLObjectInfo                   PROTO :QWORD,:QWORD,:QWORD
clGetGLTextureInfo                  PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueAcquireGLObjects           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clEnqueueReleaseGLObjects           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD

;---------------------------------
; Deprecated OpenCL GL 1.1 APIs Prototypes
;---------------------------------
clCreateFromGLTexture2D             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clCreateFromGLTexture3D             PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD,:QWORD


;---------------------------------
; Misc OpenCL APIs Prototypes
;---------------------------------
clSetCommandQueueProperty           PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD
clGetGLContextInfoKHR               PROTO :QWORD,:QWORD,:QWORD,:QWORD,:QWORD









;---------------------------------
; OpenCL Defines
;---------------------------------

; Error Codes 
CL_SUCCESS                          EQU 0
CL_DEVICE_NOT_FOUND                 EQU -1
CL_DEVICE_NOT_AVAILABLE             EQU -2
CL_COMPILER_NOT_AVAILABLE           EQU -3
CL_MEM_OBJECT_ALLOCATION_FAILURE    EQU -4
CL_OUT_OF_RESOURCES                 EQU -5
CL_OUT_OF_HOST_MEMORY               EQU -6
CL_PROFILING_INFO_NOT_AVAILABLE     EQU -7
CL_MEM_COPY_OVERLAP                 EQU -8
CL_IMAGE_FORMAT_MISMATCH            EQU -9
CL_IMAGE_FORMAT_NOT_SUPPORTED       EQU -10
CL_BUILD_PROGRAM_FAILURE            EQU -11
CL_MAP_FAILURE                      EQU -12
CL_MISALIGNED_SUB_BUFFER_OFFSET     EQU -13
CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST EQU -14
CL_COMPILE_PROGRAM_FAILURE          EQU -15
CL_LINKER_NOT_AVAILABLE             EQU -16
CL_LINK_PROGRAM_FAILURE             EQU -17
CL_DEVICE_PARTITION_FAILED          EQU -18
CL_KERNEL_ARG_INFO_NOT_AVAILABLE    EQU -19

CL_INVALID_VALUE                    EQU -30
CL_INVALID_DEVICE_TYPE              EQU -31
CL_INVALID_PLATFORM                 EQU -32
CL_INVALID_DEVICE                   EQU -33
CL_INVALID_CONTEXT                  EQU -34
CL_INVALID_QUEUE_PROPERTIES         EQU -35
CL_INVALID_COMMAND_QUEUE            EQU -36
CL_INVALID_HOST_PTR                 EQU -37
CL_INVALID_MEM_OBJECT               EQU -38
CL_INVALID_IMAGE_FORMAT_DESCRIPTOR  EQU -39
CL_INVALID_IMAGE_SIZE               EQU -40
CL_INVALID_SAMPLER                  EQU -41
CL_INVALID_BINARY                   EQU -42
CL_INVALID_BUILD_OPTIONS            EQU -43
CL_INVALID_PROGRAM                  EQU -44
CL_INVALID_PROGRAM_EXECUTABLE       EQU -45
CL_INVALID_KERNEL_NAME              EQU -46
CL_INVALID_KERNEL_DEFINITION        EQU -47
CL_INVALID_KERNEL                   EQU -48
CL_INVALID_ARG_INDEX                EQU -49
CL_INVALID_ARG_VALUE                EQU -50
CL_INVALID_ARG_SIZE                 EQU -51
CL_INVALID_KERNEL_ARGS              EQU -52
CL_INVALID_WORK_DIMENSION           EQU -53
CL_INVALID_WORK_GROUP_SIZE          EQU -54
CL_INVALID_WORK_ITEM_SIZE           EQU -55
CL_INVALID_GLOBAL_OFFSET            EQU -56
CL_INVALID_EVENT_WAIT_LIST          EQU -57
CL_INVALID_EVENT                    EQU -58
CL_INVALID_OPERATION                EQU -59
CL_INVALID_GL_OBJECT                EQU -60
CL_INVALID_BUFFER_SIZE              EQU -61
CL_INVALID_MIP_LEVEL                EQU -62
CL_INVALID_GLOBAL_WORK_SIZE         EQU -63
CL_INVALID_PROPERTY                 EQU -64
CL_INVALID_IMAGE_DESCRIPTOR         EQU -65
CL_INVALID_COMPILER_OPTIONS         EQU -66
CL_INVALID_LINKER_OPTIONS           EQU -67
CL_INVALID_DEVICE_PARTITION_COUNT   EQU -68
CL_INVALID_PIPE_SIZE                EQU -69
CL_INVALID_DEVICE_QUEUE             EQU -70

; OpenCL Version 
CL_VERSION_1_0                      EQU 1
CL_VERSION_1_1                      EQU 1
CL_VERSION_1_2                      EQU 1
CL_VERSION_2_0                      EQU 1
CL_VERSION_2_1                      EQU 1

; cl_bool 
CL_FALSE                            EQU 0
CL_TRUE                             EQU 1
CL_BLOCKING                         EQU CL_TRUE
CL_NON_BLOCKING                     EQU CL_FALSE

; cl_platform_info 
CL_PLATFORM_PROFILE                 EQU 0x0900
CL_PLATFORM_VERSION                 EQU 0x0901
CL_PLATFORM_NAME                    EQU 0x0902
CL_PLATFORM_VENDOR                  EQU 0x0903
CL_PLATFORM_EXTENSIONS              EQU 0x0904
CL_PLATFORM_HOST_TIMER_RESOLUTION   EQU 0x0905

; cl_device_type - bitfield 
CL_DEVICE_TYPE_DEFAULT              EQU (1 << 0)
CL_DEVICE_TYPE_CPU                  EQU (1 << 1)
CL_DEVICE_TYPE_GPU                  EQU (1 << 2)
CL_DEVICE_TYPE_ACCELERATOR          EQU (1 << 3)
CL_DEVICE_TYPE_CUSTOM               EQU (1 << 4)
CL_DEVICE_TYPE_ALL                  EQU 0xFFFFFFFF

; cl_device_info 
CL_DEVICE_TYPE                      EQU 0x1000
CL_DEVICE_VENDOR_ID                 EQU 0x1001
CL_DEVICE_MAX_COMPUTE_UNITS         EQU 0x1002
CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS  EQU 0x1003
CL_DEVICE_MAX_WORK_GROUP_SIZE       EQU 0x1004
CL_DEVICE_MAX_WORK_ITEM_SIZES       EQU 0x1005
CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR EQU 0x1006
CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT EQU 0x1007
CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT EQU 0x1008
CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG EQU 0x1009
CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT EQU  0x100A
CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE EQU 0x100B
CL_DEVICE_MAX_CLOCK_FREQUENCY       EQU 0x100C
CL_DEVICE_ADDRESS_BITS              EQU 0x100D
CL_DEVICE_MAX_READ_IMAGE_ARGS       EQU 0x100E
CL_DEVICE_MAX_WRITE_IMAGE_ARGS      EQU 0x100F
CL_DEVICE_MAX_MEM_ALLOC_SIZE        EQU 0x1010
CL_DEVICE_IMAGE2D_MAX_WIDTH         EQU 0x1011
CL_DEVICE_IMAGE2D_MAX_HEIGHT        EQU 0x1012
CL_DEVICE_IMAGE3D_MAX_WIDTH         EQU 0x1013
CL_DEVICE_IMAGE3D_MAX_HEIGHT        EQU 0x1014
CL_DEVICE_IMAGE3D_MAX_DEPTH         EQU 0x1015
CL_DEVICE_IMAGE_SUPPORT             EQU 0x1016
CL_DEVICE_MAX_PARAMETER_SIZE        EQU 0x1017
CL_DEVICE_MAX_SAMPLERS              EQU 0x1018
CL_DEVICE_MEM_BASE_ADDR_ALIGN       EQU 0x1019
CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE  EQU 0x101A
CL_DEVICE_SINGLE_FP_CONFIG          EQU 0x101B
CL_DEVICE_GLOBAL_MEM_CACHE_TYPE     EQU 0x101C
CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE EQU 0x101D
CL_DEVICE_GLOBAL_MEM_CACHE_SIZE     EQU 0x101E
CL_DEVICE_GLOBAL_MEM_SIZE           EQU 0x101F
CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE  EQU 0x1020
CL_DEVICE_MAX_CONSTANT_ARGS         EQU 0x1021
CL_DEVICE_LOCAL_MEM_TYPE            EQU 0x1022
CL_DEVICE_LOCAL_MEM_SIZE            EQU 0x1023
CL_DEVICE_ERROR_CORRECTION_SUPPORT  EQU 0x1024
CL_DEVICE_PROFILING_TIMER_RESOLUTION EQU 0x1025
CL_DEVICE_ENDIAN_LITTLE             EQU 0x1026
CL_DEVICE_AVAILABLE                 EQU 0x1027
CL_DEVICE_COMPILER_AVAILABLE        EQU 0x1028
CL_DEVICE_EXECUTION_CAPABILITIES    EQU 0x1029
CL_DEVICE_QUEUE_PROPERTIES          EQU 0x102A    ; deprecated 
CL_DEVICE_QUEUE_ON_HOST_PROPERTIES  EQU 0x102A
CL_DEVICE_NAME                      EQU 0x102B
CL_DEVICE_VENDOR                    EQU 0x102C
CL_DRIVER_VERSION                   EQU 0x102D
CL_DEVICE_PROFILE                   EQU 0x102E
CL_DEVICE_VERSION                   EQU 0x102F
CL_DEVICE_EXTENSIONS                EQU 0x1030
CL_DEVICE_PLATFORM                  EQU 0x1031
CL_DEVICE_DOUBLE_FP_CONFIG          EQU 0x1032
; 0x1033 reserved for CL_DEVICE_HALF_FP_CONFIG 
CL_DEVICE_PREFERRED_VECTOR_WIDTH_HALF EQU  0x1034
CL_DEVICE_HOST_UNIFIED_MEMORY       EQU 0x1035   ; deprecated 
CL_DEVICE_NATIVE_VECTOR_WIDTH_CHAR  EQU 0x1036
CL_DEVICE_NATIVE_VECTOR_WIDTH_SHORT EQU 0x1037
CL_DEVICE_NATIVE_VECTOR_WIDTH_INT   EQU 0x1038
CL_DEVICE_NATIVE_VECTOR_WIDTH_LONG  EQU 0x1039
CL_DEVICE_NATIVE_VECTOR_WIDTH_FLOAT EQU 0x103A
CL_DEVICE_NATIVE_VECTOR_WIDTH_DOUBLE EQU 0x103B
CL_DEVICE_NATIVE_VECTOR_WIDTH_HALF  EQU 0x103C
CL_DEVICE_OPENCL_C_VERSION          EQU 0x103D
CL_DEVICE_LINKER_AVAILABLE          EQU 0x103E
CL_DEVICE_BUILT_IN_KERNELS          EQU 0x103F
CL_DEVICE_IMAGE_MAX_BUFFER_SIZE     EQU 0x1040
CL_DEVICE_IMAGE_MAX_ARRAY_SIZE      EQU 0x1041
CL_DEVICE_PARENT_DEVICE             EQU 0x1042
CL_DEVICE_PARTITION_MAX_SUB_DEVICES EQU 0x1043
CL_DEVICE_PARTITION_PROPERTIES      EQU 0x1044
CL_DEVICE_PARTITION_AFFINITY_DOMAIN EQU 0x1045
CL_DEVICE_PARTITION_TYPE            EQU 0x1046
CL_DEVICE_REFERENCE_COUNT           EQU 0x1047
CL_DEVICE_PREFERRED_INTEROP_USER_SYNC EQU 0x1048
CL_DEVICE_PRINTF_BUFFER_SIZE        EQU 0x1049
CL_DEVICE_IMAGE_PITCH_ALIGNMENT     EQU 0x104A
CL_DEVICE_IMAGE_BASE_ADDRESS_ALIGNMENT EQU 0x104B
CL_DEVICE_MAX_READ_WRITE_IMAGE_ARGS EQU 0x104C
CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE  EQU 0x104D
CL_DEVICE_QUEUE_ON_DEVICE_PROPERTIES EQU 0x104E
CL_DEVICE_QUEUE_ON_DEVICE_PREFERRED_SIZE EQU  0x104F
CL_DEVICE_QUEUE_ON_DEVICE_MAX_SIZE  EQU 0x1050
CL_DEVICE_MAX_ON_DEVICE_QUEUES      EQU 0x1051
CL_DEVICE_MAX_ON_DEVICE_EVENTS      EQU 0x1052
CL_DEVICE_SVM_CAPABILITIES          EQU 0x1053
CL_DEVICE_GLOBAL_VARIABLE_PREFERRED_TOTAL_SIZE EQU 0x1054
CL_DEVICE_MAX_PIPE_ARGS             EQU 0x1055
CL_DEVICE_PIPE_MAX_ACTIVE_RESERVATIONS EQU 0x1056
CL_DEVICE_PIPE_MAX_PACKET_SIZE      EQU 0x1057
CL_DEVICE_PREFERRED_PLATFORM_ATOMIC_ALIGNMENT EQU 0x1058
CL_DEVICE_PREFERRED_GLOBAL_ATOMIC_ALIGNMENT EQU 0x1059
CL_DEVICE_PREFERRED_LOCAL_ATOMIC_ALIGNMENT EQU 0x105A
CL_DEVICE_IL_VERSION                EQU 0x105B
CL_DEVICE_MAX_NUM_SUB_GROUPS        EQU 0x105C
CL_DEVICE_SUB_GROUP_INDEPENDENT_FORWARD_PROGRESS EQU 0x105D

; cl_device_fp_config - bitfield 
CL_FP_DENORM                        EQU (1 << 0)
CL_FP_INF_NAN                       EQU (1 << 1)
CL_FP_ROUND_TO_NEAREST              EQU (1 << 2)
CL_FP_ROUND_TO_ZERO                 EQU (1 << 3)
CL_FP_ROUND_TO_INF                  EQU (1 << 4)
CL_FP_FMA                           EQU (1 << 5)
CL_FP_SOFT_FLOAT                    EQU (1 << 6)
CL_FP_CORRECTLY_ROUNDED_DIVIDE_SQRT EQU (1 << 7)

; cl_device_mem_cache_type 
CL_NONE                             EQU 0x0
CL_READ_ONLY_CACHE                  EQU 0x1
CL_READ_WRITE_CACHE                 EQU 0x2

; cl_device_local_mem_type 
CL_LOCAL                            EQU 0x1
CL_GLOBAL                           EQU 0x2

; cl_device_exec_capabilities - bitfield 
CL_EXEC_KERNEL                      EQU (1 << 0)
CL_EXEC_NATIVE_KERNEL               EQU (1 << 1)

; cl_command_queue_properties - bitfield 
CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE EQU (1 << 0)
CL_QUEUE_PROFILING_ENABLE           EQU (1 << 1)
CL_QUEUE_ON_DEVICE                  EQU (1 << 2)
CL_QUEUE_ON_DEVICE_DEFAULT          EQU (1 << 3)

; cl_context_info  
CL_CONTEXT_REFERENCE_COUNT          EQU 0x1080
CL_CONTEXT_DEVICES                  EQU 0x1081
CL_CONTEXT_PROPERTIES               EQU 0x1082
CL_CONTEXT_NUM_DEVICES              EQU 0x1083

; cl_context_properties 
CL_CONTEXT_PLATFORM                 EQU 0x1084
CL_CONTEXT_INTEROP_USER_SYNC        EQU 0x1085
    
; cl_device_partition_property 
CL_DEVICE_PARTITION_EQUALLY         EQU 0x1086
CL_DEVICE_PARTITION_BY_COUNTS       EQU 0x1087
CL_DEVICE_PARTITION_BY_COUNTS_LIST_END EQU 0x0
CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN EQU 0x1088
    
; cl_device_affinity_domain 
CL_DEVICE_AFFINITY_DOMAIN_NUMA      EQU (1 << 0)
CL_DEVICE_AFFINITY_DOMAIN_L4_CACHE  EQU (1 << 1)
CL_DEVICE_AFFINITY_DOMAIN_L3_CACHE  EQU (1 << 2)
CL_DEVICE_AFFINITY_DOMAIN_L2_CACHE  EQU (1 << 3)
CL_DEVICE_AFFINITY_DOMAIN_L1_CACHE  EQU (1 << 4)
CL_DEVICE_AFFINITY_DOMAIN_NEXT_PARTITIONABLE EQU (1 << 5)
    
; cl_device_svm_capabilities 
CL_DEVICE_SVM_COARSE_GRAIN_BUFFER   EQU (1 << 0)
CL_DEVICE_SVM_FINE_GRAIN_BUFFER     EQU (1 << 1)
CL_DEVICE_SVM_FINE_GRAIN_SYSTEM     EQU (1 << 2)
CL_DEVICE_SVM_ATOMICS               EQU (1 << 3)

; cl_command_queue_info 
CL_QUEUE_CONTEXT                    EQU 0x1090
CL_QUEUE_DEVICE                     EQU 0x1091
CL_QUEUE_REFERENCE_COUNT            EQU 0x1092
CL_QUEUE_PROPERTIES                 EQU 0x1093
CL_QUEUE_SIZE                       EQU 0x1094
CL_QUEUE_DEVICE_DEFAULT             EQU 0x1095

; cl_mem_flags and cl_svm_mem_flags - bitfield 
CL_MEM_READ_WRITE                   EQU (1 << 0)
CL_MEM_WRITE_ONLY                           (1 << 1)
CL_MEM_READ_ONLY                            (1 << 2)
CL_MEM_USE_HOST_PTR                         (1 << 3)
CL_MEM_ALLOC_HOST_PTR                       (1 << 4)
CL_MEM_COPY_HOST_PTR                        (1 << 5)
; reserved                                         (1 << 6)    
CL_MEM_HOST_WRITE_ONLY                      (1 << 7)
CL_MEM_HOST_READ_ONLY                       (1 << 8)
CL_MEM_HOST_NO_ACCESS                       (1 << 9)
CL_MEM_SVM_FINE_GRAIN_BUFFER                (1 << 10)   ; used by cl_svm_mem_flags only 
CL_MEM_SVM_ATOMICS                          (1 << 11)   ; used by cl_svm_mem_flags only 
CL_MEM_KERNEL_READ_AND_WRITE        EQU (1 << 12)

; cl_mem_migration_flags - bitfield 
CL_MIGRATE_MEM_OBJECT_HOST          EQU (1 << 0)
CL_MIGRATE_MEM_OBJECT_CONTENT_UNDEFINED     (1 << 1)

; cl_channel_order 
CL_R                                EQU 0x10B0
CL_A                                EQU 0x10B1
CL_RG                               EQU 0x10B2
CL_RA                                       0x10B3
CL_RGB                                      0x10B4
CL_RGBA                                     0x10B5
CL_BGRA                                     0x10B6
CL_ARGB                                     0x10B7
CL_INTENSITY                                0x10B8
CL_LUMINANCE                                0x10B9
CL_Rx                                       0x10BA
CL_RGx                                      0x10BB
CL_RGBx                                     0x10BC
CL_DEPTH                                    0x10BD
CL_DEPTH_STENCIL                            0x10BE
CL_sRGB                                     0x10BF
CL_sRGBx                                    0x10C0
CL_sRGBA                                    0x10C1
CL_sBGRA                                    0x10C2
CL_ABGR                                     0x10C3

; cl_channel_type 
CL_SNORM_INT8                       EQU 0x10D0
CL_SNORM_INT16                              0x10D1
CL_UNORM_INT8                               0x10D2
CL_UNORM_INT16                              0x10D3
CL_UNORM_SHORT_565                          0x10D4
CL_UNORM_SHORT_555                          0x10D5
CL_UNORM_INT_101010                         0x10D6
CL_SIGNED_INT8                              0x10D7
CL_SIGNED_INT16                             0x10D8
CL_SIGNED_INT32                             0x10D9
CL_UNSIGNED_INT8                            0x10DA
CL_UNSIGNED_INT16                           0x10DB
CL_UNSIGNED_INT32                           0x10DC
CL_HALF_FLOAT                               0x10DD
CL_FLOAT                                    0x10DE
CL_UNORM_INT24                              0x10DF
CL_UNORM_INT_101010_2               EQU 0x10E0

; cl_mem_object_type 
CL_MEM_OBJECT_BUFFER                EQU 0x10F0
CL_MEM_OBJECT_IMAGE2D                       0x10F1
CL_MEM_OBJECT_IMAGE3D                       0x10F2
CL_MEM_OBJECT_IMAGE2D_ARRAY                 0x10F3
CL_MEM_OBJECT_IMAGE1D                       0x10F4
CL_MEM_OBJECT_IMAGE1D_ARRAY                 0x10F5
CL_MEM_OBJECT_IMAGE1D_BUFFER                0x10F6
CL_MEM_OBJECT_PIPE                  EQU 0x10F7

; cl_mem_info 
CL_MEM_TYPE                         EQU 0x1100
CL_MEM_FLAGS                                0x1101
CL_MEM_SIZE                                 0x1102
CL_MEM_HOST_PTR                             0x1103
CL_MEM_MAP_COUNT                            0x1104
CL_MEM_REFERENCE_COUNT                      0x1105
CL_MEM_CONTEXT                              0x1106
CL_MEM_ASSOCIATED_MEMOBJECT                 0x1107
CL_MEM_OFFSET                               0x1108
CL_MEM_USES_SVM_POINTER             EQU 0x1109

; cl_image_info 
CL_IMAGE_FORMAT                     EQU 0x1110
CL_IMAGE_ELEMENT_SIZE                       0x1111
CL_IMAGE_ROW_PITCH                          0x1112
CL_IMAGE_SLICE_PITCH                        0x1113
CL_IMAGE_WIDTH                              0x1114
CL_IMAGE_HEIGHT                             0x1115
CL_IMAGE_DEPTH                              0x1116
CL_IMAGE_ARRAY_SIZE                         0x1117
CL_IMAGE_BUFFER                             0x1118
CL_IMAGE_NUM_MIP_LEVELS                     0x1119
CL_IMAGE_NUM_SAMPLES                EQU 0x111A
    
; cl_pipe_info 
CL_PIPE_PACKET_SIZE                 EQU 0x1120
CL_PIPE_MAX_PACKETS                 EQU 0x1121

; cl_addressing_mode 
CL_ADDRESS_NONE                     EQU 0x1130
CL_ADDRESS_CLAMP_TO_EDGE            EQU 0x1131
CL_ADDRESS_CLAMP                    EQU 0x1132
CL_ADDRESS_REPEAT                   EQU 0x1133
CL_ADDRESS_MIRRORED_REPEAT          EQU 0x1134

; cl_filter_mode 
CL_FILTER_NEAREST                   EQU 0x1140
CL_FILTER_LINEAR                    EQU 0x1141

; cl_sampler_info 
CL_SAMPLER_REFERENCE_COUNT          EQU 0x1150
CL_SAMPLER_CONTEXT                          0x1151
CL_SAMPLER_NORMALIZED_COORDS                0x1152
CL_SAMPLER_ADDRESSING_MODE                  0x1153
CL_SAMPLER_FILTER_MODE                      0x1154
CL_SAMPLER_MIP_FILTER_MODE                  0x1155
CL_SAMPLER_LOD_MIN                          0x1156
CL_SAMPLER_LOD_MAX                  EQU 0x1157

; cl_map_flags - bitfield 
CL_MAP_READ                         EQU (1 << 0)
CL_MAP_WRITE                        EQU (1 << 1)
CL_MAP_WRITE_INVALIDATE_REGION      EQU (1 << 2)

; cl_program_info 
CL_PROGRAM_REFERENCE_COUNT          EQU 0x1160
CL_PROGRAM_CONTEXT                          0x1161
CL_PROGRAM_NUM_DEVICES                      0x1162
CL_PROGRAM_DEVICES                          0x1163
CL_PROGRAM_SOURCE                           0x1164
CL_PROGRAM_BINARY_SIZES                     0x1165
CL_PROGRAM_BINARIES                         0x1166
CL_PROGRAM_NUM_KERNELS                      0x1167
CL_PROGRAM_KERNEL_NAMES                     0x1168
CL_PROGRAM_IL                       EQU 0x1169

; cl_program_build_info 
CL_PROGRAM_BUILD_STATUS             EQU 0x1181
CL_PROGRAM_BUILD_OPTIONS            EQU 0x1182
CL_PROGRAM_BUILD_LOG                EQU 0x1183
CL_PROGRAM_BINARY_TYPE              EQU 0x1184
CL_PROGRAM_BUILD_GLOBAL_VARIABLE_TOTAL_SIZE EQU 0x1185
    
; cl_program_binary_type 
CL_PROGRAM_BINARY_TYPE_NONE         EQU 0x0
CL_PROGRAM_BINARY_TYPE_COMPILED_OBJECT EQU 0x1
CL_PROGRAM_BINARY_TYPE_LIBRARY      EQU 0x2
CL_PROGRAM_BINARY_TYPE_EXECUTABLE   EQU 0x4

; cl_build_status 
CL_BUILD_SUCCESS                    EQU 0
CL_BUILD_NONE                       EQU -1
CL_BUILD_ERROR                      EQU -2
CL_BUILD_IN_PROGRESS                EQU -3

; cl_kernel_info 
CL_KERNEL_FUNCTION_NAME             EQU 0x1190
CL_KERNEL_NUM_ARGS                          0x1191
CL_KERNEL_REFERENCE_COUNT                   0x1192
CL_KERNEL_CONTEXT                           0x1193
CL_KERNEL_PROGRAM                           0x1194
CL_KERNEL_ATTRIBUTES                        0x1195
CL_KERNEL_MAX_NUM_SUB_GROUPS                0x11B9
CL_KERNEL_COMPILE_NUM_SUB_GROUPS    EQU 0x11BA

; cl_kernel_arg_info 
CL_KERNEL_ARG_ADDRESS_QUALIFIER     EQU 0x1196
CL_KERNEL_ARG_ACCESS_QUALIFIER      EQU 0x1197
CL_KERNEL_ARG_TYPE_NAME             EQU 0x1198
CL_KERNEL_ARG_TYPE_QUALIFIER        EQU 0x1199
CL_KERNEL_ARG_NAME                  EQU 0x119A

; cl_kernel_arg_address_qualifier 
CL_KERNEL_ARG_ADDRESS_GLOBAL        EQU 0x119B
CL_KERNEL_ARG_ADDRESS_LOCAL         EQU 0x119C
CL_KERNEL_ARG_ADDRESS_CONSTANT      EQU 0x119D
CL_KERNEL_ARG_ADDRESS_PRIVATE       EQU 0x119E

; cl_kernel_arg_access_qualifier 
CL_KERNEL_ARG_ACCESS_READ_ONLY      EQU 0x11A0
CL_KERNEL_ARG_ACCESS_WRITE_ONLY     EQU 0x11A1
CL_KERNEL_ARG_ACCESS_READ_WRITE     EQU 0x11A2
CL_KERNEL_ARG_ACCESS_NONE           EQU 0x11A3
    
; cl_kernel_arg_type_qualifer 
CL_KERNEL_ARG_TYPE_NONE             EQU 0
CL_KERNEL_ARG_TYPE_CONST            EQU (1 << 0)
CL_KERNEL_ARG_TYPE_RESTRICT         EQU (1 << 1)
CL_KERNEL_ARG_TYPE_VOLATILE         EQU (1 << 2)
CL_KERNEL_ARG_TYPE_PIPE             EQU (1 << 3)

; cl_kernel_work_group_info 
CL_KERNEL_WORK_GROUP_SIZE           EQU 0x11B0
CL_KERNEL_COMPILE_WORK_GROUP_SIZE   EQU 0x11B1
CL_KERNEL_LOCAL_MEM_SIZE            EQU 0x11B2
CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE EQU 0x11B3
CL_KERNEL_PRIVATE_MEM_SIZE          EQU 0x11B4
CL_KERNEL_GLOBAL_WORK_SIZE          EQU 0x11B5

; cl_kernel_sub_group_info 
CL_KERNEL_MAX_SUB_GROUP_SIZE_FOR_NDRANGE    0x2033
CL_KERNEL_SUB_GROUP_COUNT_FOR_NDRANGE       0x2034
CL_KERNEL_LOCAL_SIZE_FOR_SUB_GROUP_COUNT    0x11B8
    
; cl_kernel_exec_info 
CL_KERNEL_EXEC_INFO_SVM_PTRS        EQU 0x11B6
CL_KERNEL_EXEC_INFO_SVM_FINE_GRAIN_SYSTEM   0x11B7

; cl_event_info  
CL_EVENT_COMMAND_QUEUE              EQU 0x11D0
CL_EVENT_COMMAND_TYPE                       0x11D1
CL_EVENT_REFERENCE_COUNT                    0x11D2
CL_EVENT_COMMAND_EXECUTION_STATUS           0x11D3
CL_EVENT_CONTEXT                            0x11D4

; cl_command_type 
CL_COMMAND_NDRANGE_KERNEL           EQU 0x11F0
CL_COMMAND_TASK                             0x11F1
CL_COMMAND_NATIVE_KERNEL                    0x11F2
CL_COMMAND_READ_BUFFER                      0x11F3
CL_COMMAND_WRITE_BUFFER                     0x11F4
CL_COMMAND_COPY_BUFFER                      0x11F5
CL_COMMAND_READ_IMAGE               EQU 0x11F6
CL_COMMAND_WRITE_IMAGE                      0x11F7
CL_COMMAND_COPY_IMAGE                       0x11F8
CL_COMMAND_COPY_IMAGE_TO_BUFFER             0x11F9
CL_COMMAND_COPY_BUFFER_TO_IMAGE             0x11FA
CL_COMMAND_MAP_BUFFER                       0x11FB
CL_COMMAND_MAP_IMAGE                        0x11FC
CL_COMMAND_UNMAP_MEM_OBJECT         EQU 0x11FD
CL_COMMAND_MARKER                           0x11FE
CL_COMMAND_ACQUIRE_GL_OBJECTS               0x11FF
CL_COMMAND_RELEASE_GL_OBJECTS               0x1200
CL_COMMAND_READ_BUFFER_RECT                 0x1201
CL_COMMAND_WRITE_BUFFER_RECT                0x1202
CL_COMMAND_COPY_BUFFER_RECT         EQU 0x1203
CL_COMMAND_USER                             0x1204
CL_COMMAND_BARRIER                          0x1205
CL_COMMAND_MIGRATE_MEM_OBJECTS              0x1206
CL_COMMAND_FILL_BUFFER                      0x1207
CL_COMMAND_FILL_IMAGE               EQU 0x1208
CL_COMMAND_SVM_FREE                         0x1209
CL_COMMAND_SVM_MEMCPY                       0x120A
CL_COMMAND_SVM_MEMFILL                      0x120B
CL_COMMAND_SVM_MAP                  EQU 0x120C
CL_COMMAND_SVM_UNMAP                        0x120D
CL_COMMAND_MIGRATE_SVM_MEM_OBJECTS  EQU 0x120E

; command execution status 
CL_COMPLETE                         EQU 0x0
CL_RUNNING                          EQU 0x1
CL_SUBMITTED                        EQU 0x2
CL_QUEUED                           EQU 0x3

; cl_buffer_create_type  
CL_BUFFER_CREATE_TYPE_REGION        EQU 0x1220

; cl_profiling_info  
CL_PROFILING_COMMAND_QUEUED         EQU 0x1280
CL_PROFILING_COMMAND_SUBMIT         EQU 0x1281
CL_PROFILING_COMMAND_START          EQU 0x1282
CL_PROFILING_COMMAND_END            EQU 0x1283
CL_PROFILING_COMMAND_COMPLETE       EQU 0x1284


; cl_gl_object_type = 0x2000 - 0x200F enum values are currently taken
CL_GL_OBJECT_BUFFER                 EQU 0x2000
CL_GL_OBJECT_TEXTURE2D              EQU 0x2001
CL_GL_OBJECT_TEXTURE3D              EQU 0x2002
CL_GL_OBJECT_RENDERBUFFER           EQU 0x2003
CL_GL_OBJECT_TEXTURE2D_ARRAY        EQU 0x200E
CL_GL_OBJECT_TEXTURE1D              EQU 0x200F
CL_GL_OBJECT_TEXTURE1D_ARRAY        EQU 0x2010
CL_GL_OBJECT_TEXTURE_BUFFER         EQU 0x2011

; cl_gl_texture_info
CL_GL_TEXTURE_TARGET                EQU 0x2004
CL_GL_MIPMAP_LEVEL                  EQU 0x2005
CL_GL_NUM_SAMPLES                   EQU 0x2012

; Additional Error Codes
CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR EQU  -1000
    
; cl_gl_context_info
CL_CURRENT_DEVICE_FOR_GL_CONTEXT_KHR EQU 0x2006
CL_DEVICES_FOR_GL_CONTEXT_KHR       EQU 0x2007
    
; Additional cl_context_properties
CL_GL_CONTEXT_KHR                   EQU 0x2008
CL_EGL_DISPLAY_KHR                  EQU 0x2009
CL_GLX_DISPLAY_KHR                  EQU 0x200A
CL_WGL_HDC_KHR                      EQU 0x200B
CL_CGL_SHAREGROUP_KHR               EQU 0x200C


;---------------------------------
; OpenCL Structures
;---------------------------------

cl_image_format                         STRUCT 8
    image_channel_order                 DD ?; cl_channel_order        
    image_channel_data_type             DD ?; cl_channel_type         
cl_image_format                         ENDS

cl_image_desc                           STRUCT 8
    image_type                          DD ?; cl_mem_object_type      
    image_width                         DQ ?;
    image_height                        DQ ?;
    image_depth                         DQ ?;
    image_array_size                    DQ ?;
    image_row_pitch                     DQ ?;
    image_slice_pitch                   DQ ?;
    num_mip_levels                      DD ?;
    num_samples                         DD ?;
    buffer                              DD ?  cl_mem union? 
    mem_object                          DD ?  cl_mem union?
cl_image_desc                           ENDS

cl_buffer_region                        STRUCT 8
    origin                              DQ ?;
    regionsize                          DQ ?;
cl_buffer_region                        ENDS



















































