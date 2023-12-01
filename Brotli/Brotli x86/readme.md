# Brotli x86

Brotli libraries compiled for x86 masm assembler 

Brotli: https://github.com/google/brotli

> Brotli is a generic-purpose lossless compression algorithm that compresses data using a combination of a modern variant of the LZ77 algorithm, Huffman coding and 2nd order context modeling, with a compression ratio comparable to the best currently available general-purpose compression methods. It is similar in speed with deflate but offers more dense compression.

## Usage

* Copy `Brotli_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Brotli_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Brotli_x86.inc
  includelib Brotli_x86.lib
  ```

**Note:** `Brotli_x86.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See `https://github.com/google/brotli/tree/master/c/include/brotli` include files for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Brotli_x86.zip?raw=true)