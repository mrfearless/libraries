# OpenCL x64

An x64 assembler port of Khronos OpenCL SDK

## Usage
* Copy `OpenCL.inc` to your `uasm32\include` folder (or wherever your includes are located)
* Copy `OpenCL.lib` to your `uasm32\lib\x64` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include OpenCL.inc
includelib OpenCL.lib
```
* Ensure the OpenCL runtime dll file (`OpenCL.dll`) is located in your projects folder or in a folder found in the `%PATH%` environment variable.