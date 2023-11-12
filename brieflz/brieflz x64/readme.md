# BriefLZ x64

BriefLZ static libraries for x64 assembler 

BriefLZ: https://github.com/jibsen/brieflz

> BriefLZ is a small and fast open source implementation of a Lempel-Ziv style compression algorithm. The main focus is on speed and code footprint, but the ratios achieved are quite good compared to similar algorithms.

## Usage

* Copy `brieflz_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `brieflz_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include brieflz_x64.inc
  includelib brieflz_x64.lib
  ```

**Note:** `brieflz_x64.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See `brieflz.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/brieflz_x64.zip?raw=true)
