# Mini-XML x64

Mini-XML static libraries compiled for x64 uasm assembler 

Mini-XML: https://github.com/michaelrsweet/mxml

> Tiny XML library
>

From a post on masm32.com: http://masm32.com/board/index.php?topic=5993.0

## Usage

* Copy `mxml_x64.inc` to your `uasm\include` folder (or wherever your includes are located)
* Copy `mxml_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)
* Add the following to your project:
```assembly
include mxml_x64.inc
includelib mxml_x64.lib
```
