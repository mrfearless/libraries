# Zlib x64

Zlib static library compiled for x64 uasm assembler 

Zlib: https://zlib.net/ - https://github.com/madler/zlib

> A massively spiffy yet delicately unobtrusive compression library


## Usage

* Copy `zlib.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `zlib.lib` to your `uasm\lib\x64` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include zlib.inc
includelib zlib.lib
```