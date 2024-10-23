# Plutosvg x86 & Plutovg x86

Plutosvg & Plutovg static libraries for x86 assembler 

Plutosvg: https://github.com/sammycage/plutosvg
Plutovg: https://github.com/sammycage/plutovg

> Tiny SVG rendering library in C.

> Tiny 2D vector graphics library in C.

## Usage

* Copy `Plutosvg_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Plutosvg_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Copy `Plutovg_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Plutovg_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Plutosvg_x86.inc
  includelib Plutosvg_x86.lib
  include Plutovg_x86.inc
  includelib Plutovg_x86.lib
  ```

**Note:** `Plutosvg_x86.lib` & `Plutovg_x86.lib` also requires the Windows C Universal Runtime

## RadASM Autocomplete

Additional RadASM autocomplete / intellisense type files are also included for ease of use. Each .api.txt file contains instructions as to where to paste their contents to add this feature to RadASM for using this library.

## Functions

See the github repositories for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Plutosvg_x86.zip?raw=true)
