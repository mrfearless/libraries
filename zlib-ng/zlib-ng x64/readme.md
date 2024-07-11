# Zlib-ng x64

Zlib-ng static library compiled for x64 uasm assembler 

Zlib-ng: https://github.com/zlib-ng/zlib-ng

> zlib data compression library for the next generation systems. zlib replacement with optimizations for "next generation" systems.

## Usage

* Copy `zlibng_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `zlibng_x64.lib` to your `uasm\lib\x64` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include zlibng_x64.inc
  includelib zlibng_x64.lib
  ```

**Note:** `zlibng_x64.lib` also requires the Windows C Universal Runtime

## Functions

See https://github.com/zlib-ng/zlib-ng for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Zlibng_x64.zip?raw=true)