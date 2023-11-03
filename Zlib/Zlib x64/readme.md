# Zlib x64

Zlib static library compiled for x64 uasm assembler 

Zlib: https://zlib.net/ - https://github.com/madler/zlib

> A massively spiffy yet delicately unobtrusive compression library

## Usage

* Copy `zlib_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `zlib_x64.lib` to your `uasm\lib\x64` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include zlib_x64.inc
  includelib zlib_x64.lib
  ```

**Note:** `zlib_x64.lib` also requires the Windows C Universal Runtime

## Functions

ZLib api reference documentation is available in the `zlib.h` file.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Zlib_x64.zip?raw=true)