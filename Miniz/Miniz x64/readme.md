# Miniz x64

Miniz static libraries compiled for x64 uasm assembler 

Miniz: https://github.com/richgel999/miniz

> Deflate/Inflate compression library with zlib-compatible API, ZIP archive reading/writing, PNG writing
>

## Usage

* Copy `Miniz_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `Miniz_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include Miniz_x64.inc
includelib Miniz_x64.lib
```

## Functions

Jansson API Library Reference documentation is available via the Miniz.h file:

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Miniz_x64.zip?raw=true)