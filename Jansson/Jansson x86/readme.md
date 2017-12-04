# Jansson x86

Jansson static libraries compiled for x86 masm assembler 

Jansson: http://www.digip.org/jansson/

> Jansson is a C library for encoding, decoding and manipulating JSON data
>

## Usage

* Copy `jansson_x86.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `jansson_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include jansson_x86.inc
includelib jansson_x86.lib
```

## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Jansson API Library Reference documentation is available on the Jansson website: [https://jansson.readthedocs.io/en/2.10/apiref.html](https://jansson.readthedocs.io/en/2.10/apiref.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Jansson_x86.zip?raw=true)