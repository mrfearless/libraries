# LZO x86

LZO static libraries compiled for x86 assembler 

LZO: https://www.oberhumer.com/opensource/lzo/

> LZO is a portable lossless data compression library written in ANSI C by Markus F.X.J. Oberhumer.

## Usage

* Copy `LZO_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `LZO_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZO_x86.inc
  includelib LZO_x86.lib
  ```

**Note:** `LZO_x86.lib` also requires the Windows C Universal Runtime

## Functions

See https://www.oberhumer.com/opensource/lzo/ for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZO_x86.zip?raw=true)
