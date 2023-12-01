# Bzip3 x64

Bzip3 static libraries compiled for x64 uasm assembler 

BZip3: https://github.com/kspalaiologos/bzip3

> BZip3 - A spiritual successor to BZip2.

> A better, faster and stronger spiritual successor to BZip2. Features higher compression ratios and better performance thanks to a order-0 context mixing entropy coder, a fast Burrows-Wheeler transform code making use of suffix arrays and a RLE with Lempel Ziv+Prediction pass based on LZ77-style string matching and PPM-style context modeling.

## Usage

* Copy `BZip3_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `BZip3_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include BZip3_x64.inc
  includelib BZip3_x64.lib
  ```

**Note:** `BZip3_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `libbz3.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/BZip3_x64.zip?raw=true)