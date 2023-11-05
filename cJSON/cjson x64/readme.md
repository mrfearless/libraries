# cJSON - cjson x64

cjson libraries compiled for x64 uasm assembler

cJSON: https://github.com/DaveGamble/cJSON

> Ultralightweight JSON parser in ANSI C

## Usage

* Copy `cjson_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `cjson_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include cjson_x64.inc
  includelib cjson_x64.lib
  ```

**Note:** `cjson_x64.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Example

From a post on tuts4you.com: https://forum.tuts4you.com/topic/39996-how-to-read-json-correctly/

cjsontree - a demo program created to show the usage of the cjson library is now available here: https://github.com/mrfearless/cjsontree

## Functions

See `cjson.h` for details

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/cjson_x64.zip?raw=true)
