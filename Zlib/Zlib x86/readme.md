# Zlib x86

Zlib static library compiled for x86 masm assembler 

Zlib: https://zlib.net/ - https://github.com/madler/zlib

> A massively spiffy yet delicately unobtrusive compression library


## Usage

* Copy `zlib.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `zlib.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include zlib.inc
includelib zlib.lib
```
