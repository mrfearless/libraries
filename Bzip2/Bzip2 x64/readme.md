# Bzip2 x64

Bzip2 static libraries compiled for x64 uasm assembler 

Bzip2: https://sourceware.org/bzip2/ - https://gitlab.com/bzip2/bzip2

> bzip2 is a freely available, patent free (see below), high-quality data compressor. It typically compresses files to within 10% to 15% of the best available techniques (the PPM family of statistical compressors), whilst being around twice as fast at compression and six times faster at decompression.

## Usage

* Copy `bz2_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `bz2_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include bz2_x64.inc
  includelib bz2_x64.lib
  ```

**Note:** `bz2_x64.lib` also requires the Windows C Universal Runtime

## Functions

Some Bzip2 api reference documentation and coding examples can be found [here](https://www.cs.cmu.edu/afs/cs/project/pscico-guyb/realworld/99/code/bzip2-0.9.5c/manual_toc.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/bz2_x64.zip?raw=true)