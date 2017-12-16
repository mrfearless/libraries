# ![](../../assets/OpenSSL.png) OpenSSL x86

OpenSSL static libraries compiled for x86 masm assembler 

OpenSSL: https://www.openssl.org/

> OpenSSL is a robust, commercial-grade, and full-featured toolkit for the Transport Layer Security (TLS) and Secure Sockets Layer (SSL) protocols. It is also a general-purpose cryptography library.
>

## Usage

* Copy `*.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `*.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include OpenSSL.inc ; has all includes and includelibs already in it
```
Note: OpenSSL libraries (`libssl.lib` and `libcrypto.lib`) where compiled with Visual Studio 2015 and also require `msvcrt.lib` (included as `msvcrt14.lib`)

## Functions

OpenSSL function reference documentation is available on the OpenSSL website: [libssl](https://www.openssl.org/docs/man1.1.0/ssl/)
[libcrypto](https://www.openssl.org/docs/man1.1.0/crypto/)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/OpenSSL_x86.zip?raw=true)
