# LZFSE x64

LZFSE static libraries compiled for x64 uasm assembler 

LZFSE: https://github.com/lzfse/lzfse

> LZFSE by Apple is a Lempel-Ziv style data compression algorithm using Finite State Entropy coding. It targets similar compression rates at higher compression and decompression speed compared to deflate using zlib.

## Usage

* Copy `LZFSE_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `LZFSE_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZFSE_x64.inc
  includelib LZFSE_x64.lib
  ```

**Note:** `LZFSE_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `https://github.com/lzfse/lzfse/blob/master/src/lzfse.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZFSE_x64.zip?raw=true)