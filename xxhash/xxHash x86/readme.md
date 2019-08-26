# xxHash x86

xxHash static libraries compiled for x86 assembler 

xxHash: www.xxhash.com

> Extremely fast non-cryptographic hash algorithm.

## Usage

* Copy `xxHash.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `xxHash.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include xxHash.inc
includelib xxHash.lib
```

## Functions

Libdeflate api reference documentation is available in the `xxHash.h` file

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/xxHash_x86.zip?raw=true)
