# ![](../../assets/zstd.png) Zstandard x86

Zstandard static libraries compiled for x86 masm assembler 

Zstandard: http://www.zstd.net

> Zstandard is a real-time compression algorithm, providing high compression ratios.
>

## Usage

* Copy `zstd_x86.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `zstd_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include zstd_x86.inc
includelib zstd_x86.lib
```

## Functions

Zstandard Library reference documentation is available on the Zstandard website: [http://facebook.github.io/zstd/zstd_manual.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/zstd_x86.zip?raw=true)
