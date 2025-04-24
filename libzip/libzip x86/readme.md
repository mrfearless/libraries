# libzip x86

libzip static libraries compiled for x86 assembler 

libzip: https://github.com/nih-at/libzip

> A C library for reading, creating, and modifying zip and zip64 archives. Files can be added from data buffers, files, or compressed data copied directly from other zip archives.

## Usage

* Copy `libzip_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `libzip_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include libzip_x86.inc
  includelib libzip_x86.lib
  ```

**Note:** `libzip_x86.lib` also requires the Windows C Universal Runtime

## Functions

See `libzip.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/libzip_x86.zip?raw=true)
