# CUDA x64

An x64 assembler port of Nvidia's CUDA SDK and Nvidia's Management Library (NVML)

## Usage

* Copy `cudart.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `cudart.lib` to your `uasm\lib\x64` folder (or wherever your libraries are located)
* Copy `nvml.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `nvml.lib` to your `uasm\lib\x64` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include cudart.inc
includelib cudart.lib
include nvml.inc
includelib nvml.lib
```
* Ensure the Nvidia CUDA and NVML runtime dll files (`cudart64_80.dll` and `nvml.dll`) are located in your projects folder or in a folder found in the `%PATH%` environment variable.

