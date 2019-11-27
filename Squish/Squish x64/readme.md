# Squish x64

Squish static libraries compiled for x64 uasm assembler 

Squish: https://github.com/AxioDL/libSquish

> Squish is an open source DXT compression library.

## Usage

* Copy `Squish.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `Squish.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include Squish.inc
includelib Squish.lib
```
Note: `Squish.lib` was compiled with Visual Studio 2013 and also requires `vcruntime.lib` and `ucrt.lib`


## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Squish_x64.zip?raw=true)