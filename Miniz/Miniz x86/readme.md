# Miniz x86

Miniz static libraries compiled for x86 masm assembler 

Miniz: https://github.com/richgel999/miniz

> Deflate/Inflate compression library with zlib-compatible API, ZIP archive reading/writing, PNG writing
>

## Usage

* Copy `Miniz_x86.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `Miniz_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include Miniz_x86.inc
includelib Miniz_x86.lib
```

## Functions

Miniz_x86 API Library Reference documentation is available via the Miniz.h file.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Miniz_x86.zip?raw=true)