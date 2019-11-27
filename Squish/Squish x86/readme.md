# Squish x86

Squish static libraries compiled for x86 masm assembler 

Squish: https://github.com/AxioDL/libSquish

> Squish is an open source DXT compression library.
>

## Usage

* Copy `Squish.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `Squish.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include Squish.inc
includelib Squish.lib
```
Note: `Squish.lib` was compiled with Visual Studio and also requires `vcruntime.lib`and `ucrt.lib`


## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Squish_x86.zip?raw=true)
