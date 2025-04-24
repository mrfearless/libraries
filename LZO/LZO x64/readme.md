# LZO x64

LZO static libraries compiled for x64 uasm assembler 

LZO: https://www.oberhumer.com/opensource/lzo/

> LZO is a portable lossless data compression library written in ANSI C by Markus F.X.J. Oberhumer.

## Usage

* Copy `LZO_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `LZO_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZO_x64.inc
  includelib LZO_x64.lib
  ```

**Note:** `LZO_x64.lib` also requires the Windows C Universal Runtime

## Functions

See https://www.oberhumer.com/opensource/lzo/ for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZO_x64.zip?raw=true)