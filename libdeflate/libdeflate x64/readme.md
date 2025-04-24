# Deflate x64 (libdeflate)

Libdeflate static libraries compiled for x64 uasm assembler 

Libdeflate: https://github.com/ebiggers/libdeflate

> libdeflate is a library for fast, whole-buffer DEFLATE-based compression and
>decompression.

## Usage

* Copy `deflate_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `deflate_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include deflate_x64.inc
includelib deflate_x64.lib
```

**Note:** `deflate_x64.lib` also requires the Windows C Universal Runtime

## Functions

Libdeflate api reference documentation is available in the `libdeflate.h` file [here](https://github.com/ebiggers/libdeflate/blob/master/libdeflate.h)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/deflate_x64.zip?raw=true)