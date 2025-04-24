# miniLZO x86

miniLZO static libraries compiled for x86 assembler 

miniLZO: https://www.oberhumer.com/opensource/lzo/#minilzo

> LZO is a portable lossless data compression library written in ANSI C by Markus F.X.J. Oberhumer.
> miniLZO is a very lightweight subset of the LZO library

## Usage

* Copy `miniLZO_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `miniLZO_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include miniLZO_x86.inc
  includelib miniLZO_x86.lib
  ```

**Note:** `miniLZO_x86.lib` also requires the Windows C Universal Runtime

## Functions

See https://www.oberhumer.com/opensource/lzo/#minilzo for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/miniLZO_x86.zip?raw=true)
