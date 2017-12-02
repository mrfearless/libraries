# Mini-XML x86

Mini-XML static libraries compiled for x86 masm assembler 

Mini-XML: https://github.com/michaelrsweet/mxml

> Tiny XML library
>

From a post on masm32.com: http://masm32.com/board/index.php?topic=5993.0

Includes mxmltree (x86 version) - a demo program was created to show the usage of the mxml library

## Usage

* Copy `mxml.inc` to your `masm32\include` folder (or wherever your includes are located)
* Copy `mxml.lib` to your `masm32\lib` folder (or wherever your libraries are located)
* Add the following to your project:
```assembly
include mxml.inc
includelib mxml.lib
```

## RadASM Autocomplete
Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

Mini-XML Library reference documentation is available on the Mini-XML website: [http://michaelrsweet.github.io/mxml/mxml.html](http://michaelrsweet.github.io/mxml/mxml.html)

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Mini-XML_x86.zip?raw=true)