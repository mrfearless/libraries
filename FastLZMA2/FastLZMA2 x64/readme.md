# FastLZMA2 x64

FastLZMA2 static libraries compiled for x64 uasm assembler 

FastLZMA2: https://github.com/conor42/fast-lzma2

> The Fast LZMA2 Library is a lossless high-ratio data compression library based on Igor Pavlov's LZMA2 codec from 7-zip.

## Usage

* Copy `FastLZMA2_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `FastLZMA2_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include FastLZMA2_x64.inc
  includelib FastLZMA2_x64.lib
  ```

**Note:** `FastLZMA2_x64.lib` also requires the Windows C Universal Runtime

## Functions

See the source repository for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/FastLZMA2_x64.zip?raw=true)