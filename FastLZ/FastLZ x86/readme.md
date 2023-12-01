# FastLZ x86

FastLZ static libraries compiled for x86 assembler 

FastLZ: https://github.com/ariya/FastLZ

> Small & portable byte-aligned LZ77 compression.

> FastLZ (MIT license) is an ANSI C/C90 implementation of Lempel-Ziv 77 algorithm (LZ77) of lossless data compression. It is suitable to compress series of text/paragraphs, sequences of raw pixel data, or any other blocks of data with lots of repetition. It is not intended to be used on images, videos, and other formats of data typically already in an optimal compressed form.

> The focus for FastLZ is a very fast compression and decompression, doing that at the cost of the compression ratio.

## Usage

* Copy `FastLZ_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `FastLZ_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include FastLZ_x86.inc
  includelib FastLZ_x86.lib
  ```

**Note:** `FastLZ_x86.lib` also requires the Windows C Universal Runtime

## Functions

See `fastlz.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/FastLZ_x86.zip?raw=true)
