# cJSON - cjson x86

cjson libraries compiled for x86 masm assembler

cJSON: https://github.com/DaveGamble/cJSON

> Ultralightweight JSON parser in ANSI C

## Usage

* Copy `cjson_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `cjson_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include cjson_x86.inc
  includelib cjson_x86.lib
  ```

**Note:** `cjson_x86.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Example

From a post on tuts4you.com: https://forum.tuts4you.com/topic/39996-how-to-read-json-correctly/

cjsontree - a demo program created to show the usage of the cjson library is now available here: https://github.com/mrfearless/cjsontree

## Functions

See `cjson.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/cjson_x86.zip?raw=true)