# Jansson x64

Jansson static libraries compiled for x64 uasm assembler 

Jansson: http://www.digip.org/jansson/ - https://github.com/akheron/jansson

> Jansson is a C library for encoding, decoding and manipulating JSON data

## Usage

* Copy `jansson_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `jansson_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
  
  ```assembly
  include jansson_x64.inc
  includelib jansson_x64.lib
  ```

**Note:** `jansson_x64.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Jansson API Library Reference documentation is available on the Jansson website: https://jansson.readthedocs.io/en/latest/

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Jansson_x64.zip?raw=true)