# ![](../../assets/Mini-XML.png) Mini-XML x64

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

## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Mini-XML Library reference documentation is available on the Mini-XML website: [http://michaelrsweet.github.io/mxml/mxml.html](http://michaelrsweet.github.io/mxml/mxml.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Mini-XML_x64.zip?raw=true)