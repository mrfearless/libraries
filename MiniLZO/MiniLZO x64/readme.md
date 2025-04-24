# miniLZO x64

miniLZO static libraries compiled for x64 uasm assembler 

miniLZO: https://www.oberhumer.com/opensource/lzo/#minilzo

> LZO is a portable lossless data compression library written in ANSI C by Markus F.X.J. Oberhumer.
> miniLZO is a very lightweight subset of the LZO library

## Usage

* Copy `miniLZO_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `miniLZO_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include miniLZO_x64.inc
  includelib miniLZO_x64.lib
  ```

**Note:** `miniLZO_x64.lib` also requires the Windows C Universal Runtime

## Functions

See https://www.oberhumer.com/opensource/lzo/#minilzo for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/miniLZO_x64.zip?raw=true)