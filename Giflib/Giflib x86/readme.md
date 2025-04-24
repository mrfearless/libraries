# Giflib x86

Giflib static libraries compiled for x86 assembler 

Giflib: https://giflib.sourceforge.net/

> GIFLIB is a package of portable tools and library routines for working with GIF images.

## Usage

* Copy `Giflib_x86.inc` to your `masm32\include` folder (or wherever your includes are located)

* Copy `Giflib_x86.lib` to your `masm32\lib` folder (or wherever your libraries are located)

* Add the following to your project:
  
  ```assembly
  include Giflib_x86.inc
  includelib Giflib_x86.lib
  ```

**Note:** `Giflib_x86.lib` also requires the Windows C Universal Runtime

## Functions

See the source repository for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Giflib_x86.zip?raw=true)
