# FastLZMA2 x86

FastLZMA2 static libraries compiled for x86 assembler 

FastLZMA2: https://github.com/conor42/fast-lzma2

> The Fast LZMA2 Library is a lossless high-ratio data compression library based on Igor Pavlov's LZMA2 codec from 7-zip.

## Usage

* Copy `FastLZMA2_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `FastLZMA2_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include FastLZMA2_x86.inc
  includelib FastLZMA2_x86.lib
  ```

**Note:** `FastLZMA2_x86.lib` also requires the Windows C Universal Runtime

## Functions

See the source repository for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/FastLZMA2_x86.zip?raw=true)
