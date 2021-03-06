# cJSON - cjson x86

cjson v1.7.12 static library compiled for x86 masm assembler

cJSON: https://github.com/DaveGamble/cJSON

> Ultralightweight JSON parser in ANSI C

From a post on tuts4you.com: https://forum.tuts4you.com/topic/39996-how-to-read-json-correctly/

cjsontree - a demo program created to show the usage of the cjson (libcjson) library is now available here: https://github.com/mrfearless/cjsontree

## Usage

* Copy `cjson.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `cjson.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include cjson.inc
includelib cjson.lib
```


## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.