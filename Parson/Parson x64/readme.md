# Parson x64

Parson static libraries compiled for x64 uasm assembler 

Parson: https://github.com/kgabis/parson

> Lightweight JSON library written in C by Krzysztof Gabis.

## Usage

* Copy `Parson_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `Parson_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include Parson_x64.inc
  includelib Parson_x64.lib
  ```

**Note:** `Parson_x64.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Refer to the header file: https://github.com/kgabis/parson/blob/master/parson.h

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Parson_x64.zip?raw=true)