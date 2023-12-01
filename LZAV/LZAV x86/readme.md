# LZAV x86

LZAV static libraries compiled for x86 assembler 

LZAV: https://github.com/avaneev/lzav

> Fast In-Memory Data Compression Algorithm

> LZAV is a fast general-purpose in-memory data compression algorithm based on now-classic LZ77 lossless data compression method. LZAV holds a good position on the Pareto landscape of factors, among many similar in-memory (non-streaming) compression algorithms.

## Usage

* Copy `LZAV_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `LZAV_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZAV_x86.inc
  includelib LZAV_x86.lib
  ```

**Note:** `LZAV_x86.lib` also requires the Windows C Universal Runtime

## Functions

See `lzav.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZAV_x86.zip?raw=true)
