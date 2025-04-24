# LZMA x64

LZMA static libraries compiled for x64 uasm assembler 

LZMA: https://www.7-zip.org/sdk.html

> Lempel–Ziv–Markov chain algorithm (LZMA) by Igor Pavlov is an algorithm used to perform lossless data compression. 
>
> LZMA is used in the 7z format of the 7-Zip archiver. This algorithm uses a dictionary compression scheme somewhat similar to the LZ77 algorithm published by Abraham Lempel and Jacob Ziv in 1977 and features a high compression ratio (generally higher than bzip2) and a variable compression-dictionary size (up to 4 GB), while still maintaining decompression speed similar to other commonly used compression algorithms.

## Usage

* Copy `LZMA_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `LZMA_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include LZMA_x64.inc
  includelib LZMA_x64.lib
  ```

**Note:** `LZMA_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `https://www.7-zip.org/sdk.html` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/LZMA_x64.zip?raw=true)