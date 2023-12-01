# LZAV x64

LZAV static libraries compiled for x64 uasm assembler 

LZAV: https://github.com/avaneev/lzav

> Fast In-Memory Data Compression Algorithm

> LZAV is a fast general-purpose in-memory data compression algorithm based on now-classic LZ77 lossless data compression method. LZAV holds a good position on the Pareto landscape of factors, among many similar in-memory (non-streaming) compression algorithms.

## Usage

* Copy `LZAV_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `LZAV_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZAV_x64.inc
  includelib LZAV_x64.lib
  ```

**Note:** `LZAV_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `lzav.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZAV_x64.zip?raw=true)