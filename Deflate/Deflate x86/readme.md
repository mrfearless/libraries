# Deflate x86 (libdeflate)

Libdeflate static libraries compiled for x86 assembler 

Libdeflate: https://github.com/ebiggers/libdeflate

> libdeflate is a library for fast, whole-buffer DEFLATE-based compression and
>decompression.

## Usage

* Copy `*.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include libdeflate_x86.inc
includelib libdeflate_x86.lib
```

## Functions

Libdeflate api reference documentation is available in the `libdeflate.h` file [here](https://github.com/ebiggers/libdeflate/blob/master/libdeflate.h)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/libdeflate_x86.zip?raw=true)
