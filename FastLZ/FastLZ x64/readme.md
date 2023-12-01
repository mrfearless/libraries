# FastLZ x64

FastLZ static libraries compiled for x64 uasm assembler 

FastLZ: https://github.com/ariya/FastLZ

> Small & portable byte-aligned LZ77 compression.

> FastLZ (MIT license) is an ANSI C/C90 implementation of Lempel-Ziv 77 algorithm (LZ77) of lossless data compression. It is suitable to compress series of text/paragraphs, sequences of raw pixel data, or any other blocks of data with lots of repetition. It is not intended to be used on images, videos, and other formats of data typically already in an optimal compressed form.

> The focus for FastLZ is a very fast compression and decompression, doing that at the cost of the compression ratio.

## Usage

* Copy `FastLZ_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `FastLZ_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include FastLZ_x64.inc
  includelib FastLZ_x64.lib
  ```

**Note:** `FastLZ_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `fastlz.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/FastLZ_x64.zip?raw=true)