# Lizard x86

Lizard static libraries compiled for x86 assembler 

Lizard: https://github.com/inikep/lizard

> Lizard (formerly LZ5) is an efficient compressor with very fast decompression. It achieves compression ratio that is comparable to zip/zlib and zstd/brotli

> Lizard library is based on frequently used LZ4 library by Yann Collet but the Lizard compression format is not compatible with LZ4.

## Usage

* Copy `Lizard_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Lizard_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Lizard_x86.inc
  includelib Lizard_x86.lib
  ```

**Note:** `Lizard_x86.lib` also requires the Windows C Universal Runtime

## Functions

See the include files for details: https://github.com/inikep/lizard/tree/lizard/lib

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Lizard_x86.zip?raw=true)
