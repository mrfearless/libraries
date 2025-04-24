# Giflib x64

Giflib static libraries compiled for x64 uasm assembler 

Giflib: https://giflib.sourceforge.net/

> GIFLIB is a package of portable tools and library routines for working with GIF images.

## Usage

* Copy `Giflib_x64.inc` to your `uasm\include` folder (or wherever your includes are located)

* Copy `Giflib_x64.lib` to your `uasm\lib\x64` folder (or wherever your 64bit libraries are located)

* Add the following to your project:
  
  ```assembly
  include Giflib_x64.inc
  includelib Giflib_x64.lib
  ```

**Note:** `Giflib_x64.lib` also requires the Windows C Universal Runtime

## Functions

See the source repository for details.

## Download

The latest downloadable release is available [here](https://github.com/mrfearless/libraries/blob/master/releases/Giflib_x64.zip?raw=true)