# cJSON x64

libcjson static library x64 masm port of https://github.com/DaveGamble/cJSON

> Ultralightweight JSON parser in ANSI C

From a post on tuts4you.com: https://forum.tuts4you.com/topic/39996-how-to-read-json-correctly/

Includes cjsontree - a demo program was created to show the usage of the libcjson library

## Usage

* Copy `libcjson_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `libcjson_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include libcjson_x64.inc
includelib libcjson_x64.lib
```


