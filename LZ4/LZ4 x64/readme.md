# LZ4 x64

LZ4 static libraries compiled for x64 uasm assembler 

LZ4: https://github.com/lz4/lz4

> Extremely Fast Compression algorithm.
>

## Usage

* Copy `*.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include LZ4_x64.inc
includelib LZ4_x64.lib
```

## Functions

LZ4 api reference documentation is available on the LZ4 github wiki [here](https://github.com/lz4/lz4/wiki)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZ4_x64.zip?raw=true)