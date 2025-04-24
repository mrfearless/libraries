# libzip x64

libzip static libraries compiled for x64 uasm assembler 

libzip: https://github.com/nih-at/libzip

> A C library for reading, creating, and modifying zip and zip64 archives. Files can be added from data buffers, files, or compressed data copied directly from other zip archives.

## Usage

* Copy `libzip_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `libzip_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include libzip_x64.inc
  includelib libzip_x64.lib
  ```

**Note:** `libzip_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `libzip.h` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/libzip_x64.zip?raw=true)