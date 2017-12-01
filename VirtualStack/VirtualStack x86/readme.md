# ![](../assets/VirtualStack.png)VirtualStack x86

Static x86 assembler library for creating a virtual stack and manipulating it (push, pop, peek etc)

## Usage

* Copy `VirtualStack.inc` to your `masm\include` folder (or wherever your includes are located)
* Copy `VirtualStack.lib` to your `masm\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include VirtualStack.inc
includelib VirtualStack.lib
```

## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Basic documentation on the functions in this library are located on the wiki [here](https://github.com/mrfearless/libraries/wiki/VirtualStack-x86-Functions)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/VirtualStack_x86.zip?raw=true)