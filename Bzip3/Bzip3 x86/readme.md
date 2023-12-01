# Bzip3 x86

Bzip3 static libraries compiled for x86 assembler 

BZip3: https://github.com/kspalaiologos/bzip3

> BZip3 - A spiritual successor to BZip2.

> A better, faster and stronger spiritual successor to BZip2. Features higher compression ratios and better performance thanks to a order-0 context mixing entropy coder, a fast Burrows-Wheeler transform code making use of suffix arrays and a RLE with Lempel Ziv+Prediction pass based on LZ77-style string matching and PPM-style context modeling.

## Usage

* Copy `Bzip3_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Bzip3_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Bzip3_x86.inc
  includelib Bzip3_x86.lib
  ```

**Note:** `Bzip3_x86.lib` also requires the Windows C Universal Runtime

## Functions

See `libbz3.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Bzip3_x86.zip?raw=true)
