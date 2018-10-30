# LZ4 x86

LZ4 static libraries compiled for x86 assembler 

LZ4: https://github.com/lz4/lz4

> Extremely Fast Compression algorithm.
>

## Usage

* Copy `*.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include LZ4_x86.inc
includelib LZ4_x86.lib
```

## Functions

LZ4 api reference documentation is available on the LZ4 github wiki [here](https://github.com/lz4/lz4/wiki)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZ4_x86.zip?raw=true)
