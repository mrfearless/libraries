# cJSON

libcjson static library x86 masm port of https://github.com/DaveGamble/cJSON

> Ultralightweight JSON parser in ANSI C

From a post on tuts4you.com: https://forum.tuts4you.com/topic/39996-how-to-read-json-correctly/

Includes cjsontree - a demo program was created to show the usage of the libcjson library

## Usage

* Copy `libcjson.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `libcjson.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include libcjson.inc
includelib libcjson.lib
```


