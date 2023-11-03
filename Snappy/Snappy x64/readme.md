# Snappy x64

Snappy static libraries compiled for x64 uasm assembler 

Snappy: https://github.com/google/snappy

> A fast compressor/decompressor

> Snappy is a compression/decompression library. It does not aim for maximum compression, or compatibility with any other compression library; instead, it aims for very high speeds and reasonable compression. For instance, compared to the fastest mode of zlib, Snappy is an order of magnitude faster for most inputs, but the resulting compressed files are anywhere from 20% to 100% bigger.

## Usage

* Copy `snappy_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `snappy_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include snappy_x64.inc
  includelib snappy_x64.lib
  ```

**Note:** `snappy_x64.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See `snappy_x64.inc` for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Snappy_x64.zip?raw=true)