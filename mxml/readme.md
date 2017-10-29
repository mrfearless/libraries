# Mxml

mxml static library x86 masm port of https://github.com/michaelrsweet/mxml

> Tiny XML library
>

From a post on masm32.com: http://masm32.com/board/index.php?topic=5993.0

Includes mxmltree - a demo program was created to show the usage of the mxml library

## Usage

* Copy `mxml.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `mxml.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include mxml.inc
includelib mxml.lib
```
