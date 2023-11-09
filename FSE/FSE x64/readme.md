# FSE x64

FSE (Finite State Entropy) static libraries compiled for x64 uasm assembler 

FSE: https://github.com/Cyan4973/FiniteStateEntropy

> New generation entropy codecs : Finite State Entropy and Huff0

> This library proposes two high speed entropy coders :

> Huff0, a Huffman codec designed for modern CPU, featuring OoO (Out of Order) operations on multiple ALU (Arithmetic Logic Unit), achieving extremely fast compression and decompression speeds.

> FSE is a new kind of Entropy encoder, based on ANS theory, from Jarek Duda, achieving precise compression accuracy (like Arithmetic coding) at much higher speeds.

## Usage

* Copy `fse_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `fse_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include fse_x64.inc
  includelib fse_x64.lib
  ```

**Note:** `fse_x64.lib` also requires the Windows C Universal Runtime

## Functions

See `fse.h`, `huf.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/FSE_x64.zip?raw=true)