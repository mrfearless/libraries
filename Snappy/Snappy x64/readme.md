# ![](../../assets/Snappy.png) Snappy x64

Snappy static libraries compiled for x64 uasm assembler 

Snappy: https://google.github.io/snappy/

> A fast compressor/decompressor
>

Static libraries compiled using this source: https://bitbucket.org/robertvazan/snappy-visual-cpp

## Usage

* Copy `snappy_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `snappy_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include snappy_x64.inc
includelib snappy_x64.lib
```

## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See `snappy_x64.inc` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Snappy_x64.zip?raw=true)