# ![](../../assets/BearSSL.png) BearSSL x86

BearSSL static libraries compiled for x86 assembler 

BearSSL: https://www.bearssl.org/

> BearSSL is a smaller SSL/TLS library. It is an implementation of the SSL/TLS protocol (RFC 5246) written in C.
>

## Usage

* Copy `*.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include BearSSLs.inc
includelib BearSSLs.lib
```
Note: BearSSL libraries may also require a c library for a few functions.

## Functions

BearSSL api reference documentation is available on the BearSSL website [here](https://www.bearssl.org/apidoc/index.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/BearSSL_x86.zip?raw=true)
