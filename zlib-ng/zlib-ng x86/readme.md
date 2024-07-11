# Zlib-ng x86

Zlib-ng static library compiled for x86 masm assembler 

Zlib-ng: https://github.com/zlib-ng/zlib-ng

> zlib data compression library for the next generation systems. zlib replacement with optimizations for "next generation" systems.

## Usage

* Copy `zlibng_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `zlibng_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include zlibng_x86.inc
  includelib zlibng_x86.lib
  ```

**Note:** `zlibng_x86.lib` also requires the Windows C Universal Runtime

## Functions

See https://github.com/zlib-ng/zlib-ng for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Zlibng_x86.zip?raw=true)
