# LZ4 x64

LZ4 static libraries compiled for x64 uasm assembler 

LZ4: https://github.com/lz4/lz4

> Extremely Fast Compression algorithm.

> LZ4 is lossless compression algorithm, providing compression speed > 500 MB/s per core, scalable with multi-cores CPU. It features an extremely fast decoder, with speed in multiple GB/s per core, typically reaching RAM speed limits on multi-core systems.

> Speed can be tuned dynamically, selecting an "acceleration" factor which trades compression ratio for faster speed. On the other end, a high compression derivative, LZ4_HC, is also provided, trading CPU time for improved compression ratio. All versions feature the same decompression speed.

## Usage

* Copy `lz4_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `lz4_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include lz4_x64.inc
  includelib lz4_x64.lib
  ```

**Note:** `lz4_x64.lib` also requires the Windows C Universal Runtime

## Functions

LZ4 api reference documentation is available on the LZ4 github wiki [here](https://github.com/lz4/lz4/wiki)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZ4_x64.zip?raw=true)