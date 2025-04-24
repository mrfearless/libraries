# Parson x86

Parson static libraries compiled for x86 masm assembler 

Parson: https://github.com/kgabis/parson

> Lightweight JSON library written in C by Krzysztof Gabis.

## Usage

* Copy `Parson_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Parson_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Parson_x86.inc
  includelib Parson_x86.lib
  ```

**Note:** `Parson_x86.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Refer to the header file: https://github.com/kgabis/parson/blob/master/parson.h

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Parson_x86.zip?raw=true)