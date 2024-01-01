# LZFSE x86

LZFSE static libraries compiled for x86 assembler 

LZFSE: https://github.com/lzfse/lzfse

> LZFSE by Apple is a Lempel-Ziv style data compression algorithm using Finite State Entropy coding. It targets similar compression rates at higher compression and decompression speed compared to deflate using zlib.

## Usage

* Copy `LZFSE_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `LZFSE_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZFSE_x86.inc
  includelib LZFSE_x86.lib
  ```

**Note:** `LZFSE_x86.lib` also requires the Windows C Universal Runtime

## Functions

See `https://github.com/lzfse/lzfse/blob/master/src/lzfse.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZFSE_x86.zip?raw=true)
